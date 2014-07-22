/*
TODO:
  - Make everything distributed
  - flux for 9 and 27 point stencils
  - IO checkpoints?
*/

use Time,
    Random,
    BlockDist;

enum st_opts { MG2D5PT, MG2D9PT, MG3D7PT, MG3D27PT}
config var stencilType : st_opts = st_opts.MG2D5PT;
const dimension : int = 
  if stencilType==st_opts.MG2D5PT || stencilType==st_opts.MG2D9PT then 2
  else 3;

const points : int = 
  if stencilType == st_opts.MG2D5PT then 5
  else if stencilType == st_opts.MG2D9PT then 9
  else if stencilType == st_opts.MG3D7PT then 7
  else 27;

const super2D = {-1..1, -1..1, 0..0};
const super3D = {-1..1, -1..1, -1..1};
const super = if dimension == 2 then super2D else super3D;

var Offsets : sparse subdomain(super);
select stencilType {
  when st_opts.MG2D5PT {
    Offsets +=(-1,0,0);
    Offsets +=(0,-1,0);
    Offsets +=(0,0,0);
    Offsets +=(0,1,0);
    Offsets +=(1,0,0);
  }
  when st_opts.MG3D7PT {
    Offsets += (-1,0,0);
    Offsets += (0,-1,0);
    Offsets += (0,0,-1);
    Offsets += (0,0,0);
    Offsets += (1,0,0);
    Offsets += (0,1,0);
    Offsets += (0,0,1);
  }
  when st_opts.MG2D9PT do Offsets += super2D;
  when st_opts.MG3D27PT do Offsets += super3D;
}

enum bc_opts { DIRICHLET }
config var bcOpt : bc_opts = bc_opts.DIRICHLET;

enum scale_opts { WEAK, STRONG }
config var scaling : scale_opts = scale_opts.WEAK;

config var commBulk = false;

config var errorTol = 1.0;

config var nspikes = 1;
config var nsteps = 100;
config var nvars = 5;

const allVars = 1..nvars;
const allSpikes = 1..nspikes;

config var nx = 100;
config var ny = 100;
config var nz = 100;
config var ndim = -1;

const reportEvery = 20;

config var percentToSum = 100; // 0..100
var gridsToSum : [allVars] bool;
if percentToSum == 0 then gridsToSum = false;
else if percentToSum == 100 then gridsToSum = true;
else {
  const realPercent = (percentToSum:real) / 100.0;
  var rand = new RandomStream(12345);
  for i in allVars {
    const r = rand.getNext();
    writeln(r, " < ", realPercent);
    if r < realPercent then gridsToSum[i] = true;
    else gridsToSum[i] = false;
  }
}

if ndim != -1 {
  nx = ndim;
  ny = ndim;
  nz = ndim;
}

const gd = 1; // ghost depth

const boxDim = (nx, ny, nz);

var flux : [allVars] real;
var sources : [allVars] real;

const Space = {1..nx, 1..ny, 1..nz};
const GhostSpace = Space.expand(gd); // grow the domain by 'gd' in all directions

const ProblemSpace = GhostSpace;

var spikes : [allVars, allSpikes] real;

var grids : [allVars] [ProblemSpace] real; // N distributed grids

type v3int = 3*int;
var spikeloc : [allSpikes] v3int;

var timer : Timer;
var totalTime : real;

writeln ( "\n\n =============================================================== \n" );
writeln ( "            Mantevo miniapp MiniGhost experiment \n" );

writeln ( " Problem dimension ", nx, " x ", ny, " x ", nz, "\n" );
writeln ( " Execution time/date : ", getCurrentTime(), ", ", getCurrentDate() );
writeln ( "\n =============================================================== \n" );

// init grid
const seed = 112345;
forall (g, s) in zip(grids, sources) {
  var rs = new RandomStream(seed);
  const r = rs.getNext();

  g[Space] = 1 + ((r * 100.0):int % (nx * ny * nz));
  s = + reduce g;
}

// init spikes
fillRandom(spikes, seed);
// TODO: global nx/y/z?
spikes = (spikes + 1) * nx * ny * nz;

spikes[1,1] = nx * ny * nz;

// insert first spike at center of grid
spikeloc[1] = ((nx + 1) / 2, (ny + 1) / 2, (nz + 1) / 2);

var rlocs : [1..3, allSpikes] real;
fillRandom(rlocs, seed);

forall i in 2..nspikes {
  spikeloc[i] = (((rlocs[1,i] * nx) + 1):int,
                 ((rlocs[2,i] * ny) + 1):int,
                 ((rlocs[3,i] * nz) + 1):int);
}

writeln("\n ** Begin time stepping **\n");

proc main() {
  timer.start();

  var restartFirstPass = false;

  for ispike in allSpikes {

    // insert spike
    if !restartFirstPass {
      forall (grid,spike,source) in zip(grids, spikes[allVars, ispike], sources) {
        grid[spikeloc[ispike]] += spike;
        source += spike;
      }
    }

    for tstep in 1..nsteps {
      for ivar in allVars {
        stencil(ivar); // all stencil types
        if gridsToSum[ivar] {
          const errorIter = check(ivar);
          if errorIter > errorTol then
            halt("errorIter exceeds tolerance: ", errorIter, " > ", errorTol);
          if tstep % reportEvery == 0 {
            writeln("Time step\t",tstep, " for spike\t", ispike, " for variable\t", ivar, " the error is\t", errorIter, "; error tolerance is\t", errorTol);
          }
        }
      }
    }
  }

  // final check
  var numErrors = 0;
  for i in allVars do {
    const errorIter = check(i);
    if errorIter > errorTol { 
      numErrors += 1;
      writeln("errorIter exceeds tolerance: ", errorIter, " > ", errorTol);
    }
  }

  if numErrors == 0 then writeln("\nComputation within error tolerance\n");

  // report performance

  writeln("\n ** miniGhost complete **\n");
}

proc stencil(ivar : int) {
  var work : [Space] real;

  bounds(ivar);

  var g => grids[ivar];
  forall i in Space {
    for o in Offsets do work[i] += g[i + o];
  }
  
  writef("+ reduce work = %30.dr\n", + reduce work);
  work /= points;
  grids[ivar][Space] = work;
}

proc check(ivar : int) {
  var gsum = + reduce grids[ivar];
  gsum += flux[ivar];
  const ret = abs(sources[ivar] - gsum) / sources[ivar];
  return ret;
}

proc bounds(ivar : int) {
  if points == 5 || points == 7 {
    flux[ivar] +=  + reduce grids[ivar][1, 1.., 1..] / points;
    flux[ivar] += + reduce grids[ivar][nx, 1.., 1..] / points;
    flux[ivar] += + reduce grids[ivar][1.., 1, 1..]  / points;
    flux[ivar] += + reduce grids[ivar][1.., ny, 1..] / points;
    if dimension == 3 {
      flux[ivar] += + reduce grids[ivar][1.., 1.., 1]/ points;
      flux[ivar] += + reduce grids[ivar][1.., 1.., nz]/points;
    }
  } else {
    // TODO: 9 or 27 point stencils
  }
}
