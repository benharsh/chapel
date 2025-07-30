use BlockDist;
use CompressedSparseLayout;
use CTypes;
use IO.FormattedIO;
use Sort;
use Time;

use CustomCopyAggregation;
use RecursiveMatrixGenerator;
use SortUtils;

// Sparse matrix creation toggles
config const A = 0.57;
config const B = 0.19;
config const C = 0.19;
config const D = 0.05;
config const SCALE = 10;
config const FACTOR = 16;
config const N = 2**SCALE;
config const NNZ = 2**SCALE * FACTOR;

// Experimental toggles
config const bufSize = 128;
config const trials = 5;
config const runAgg = true;
config const runNoAgg = true;

class DestinationHandler {
  var domVal;
  var arrVal;

  proc init(domVal, arrVal) {
    this.domVal = domVal;
    this.arrVal = arrVal;
  }

  inline proc flush(ref rBuffer, const ref remBufferPtr, const ref myBufferIdx) {
    const (_, locid) = this.domVal.dist.chpl__locToLocIdx(here);
    var locIdxBuf = this.domVal.locDoms[locid]!.mySparseBlock._value.createIndexBuffer(bufSize,true,true);
    for (dstAddr, srcVal) in rBuffer.localIter(remBufferPtr, myBufferIdx) {
      assert(dstAddr == nil);
      var (i,j,_) = srcVal;
      locIdxBuf.add((i, j));
    }
    locIdxBuf.commit();
    for (dstAddr, srcVal) in rBuffer.localIter(remBufferPtr, myBufferIdx) {
      assert(dstAddr == nil);
      var (i,j,v) = srcVal;
      var (_,loc) = this.domVal.locDoms[locid]!.mySparseBlock._value.find((i,j));
      this.arrVal.locArr[locid]!.myElems._value.data[loc] = v;
    }
  }
}

class SourceHandler {
  var domVal;
  var arrVal;
  type elemType = (int,int,int);

  proc init(D, A) {
    this.domVal = D._value;
    this.arrVal = A._value;
  }

  proc sourceCopy() {
    return new unmanaged DestinationHandler(domVal,arrVal);
  }

  proc getDestinationLocale(val: elemType) {
    // Since elemType is a tuple of (i,j,v) then we only need (i,j)
    var (i,j,_) = val;
    return domVal.dist.dsiIndexToLocale((i,j));
  }
}

proc getRandomSparseIndicesAndValues() {
  var (rowsOg, colsOg) = recursiveMatrixGenerator(A, B, C, D, SCALE, N, NNZ);
  var numIdx = rowsOg.size;
  
  // Symmetrize the indices
  var rows = blockDist.createArray({0..<2*numIdx}, int);
  var cols = blockDist.createArray({0..<2*numIdx}, int);
  rows[0..<numIdx] = rowsOg; rows[numIdx..] = colsOg;
  cols[0..<numIdx] = colsOg; cols[numIdx..] = rowsOg;

  // Parse out repeated indices
  var iv = coargsort(rows, cols);
  var sortedRow = rows[iv]; var sortedCol = cols[iv];
  var sortedIdx = blockDist.createArray(rows.domain, (int,int));
  forall (si, i) in zip(sortedIdx, sortedIdx.domain) do 
    si = (sortedRow[i], sortedCol[i]);
  var uniqueIdx = uniqueFromSorted(sortedIdx, needCounts=false);
  var rowsUnique = blockDist.createArray(uniqueIdx.domain, int);
  var colsUnique = blockDist.createArray(uniqueIdx.domain, int);

  // Move uniqueIdx values to two separate arrays
  forall (ui, r, c) in zip(uniqueIdx, rowsUnique, colsUnique) {
    r = ui[0];
    c = ui[1];
  }

  // Generate vals
  var vals = blockDist.createArray(uniqueIdx.domain, int);
  forall (i,v) in zip(vals.domain, vals) do v = i + 1;

  return (rowsUnique, colsUnique, vals);
}

proc runAggregatedSparseMatrixCreation(rows, cols, vals) {
  const Space = {1..N, 1..N};
  const DenseDom = Space dmapped new blockDist(Space, sparseLayoutType=csrLayout(parSafe=true));
  var SparseDom: sparse subdomain(DenseDom);
  var SparseArr: [SparseDom] int;
  
  forall (i,j,v) in zip(rows, cols, vals) 
    with (var agg = new CustomDstAggregator(new shared SourceHandler(SparseDom, SparseArr))) do 
	    agg.copy((i,j,v));
  
  return SparseArr.size;
}

proc runNonAggregatedSparseMatrixCreation(rows, cols, vals) {
  const Space = {1..N, 1..N};
  const DenseDom = Space dmapped new blockDist(Space, sparseLayoutType=csrLayout(parSafe=true));
  var SparseDom: sparse subdomain(DenseDom);
  var SparseArr: [SparseDom] int;

  forall (i,j) in zip(rows, cols) 
    with (var idxBuf = SparseDom.createIndexBuffer(bufSize)) do
      idxBuf.add((i,j));
  forall (i,j,v) in zip(rows, cols, vals) 
    with (ref SparseArr) do
      SparseArr[i,j] = v;

  return SparseArr.size;
}

proc computeStatistics(in data) {
  var n = data.size;
  var mean:real = + reduce data / n;
  var numerator:real = 0.0;
  
  for d in data do numerator += (d - mean)**2;
  var stdDev = sqrt(numerator/(n-1));
  sort(data);
  
  var minimum = data[1];
  var firstQuartile = (data[n/4] + data[(n+1)/4]) * 0.5;
  var median = (data[n/2] + data[(n+1)/2]) * 0.5;
  var thirdQuartile = (data[n-(n/4)] + data[n-((n+1)/4)]) * 0.5;
  var maximum = data[n];

  return (mean, stdDev, minimum, firstQuartile, median, thirdQuartile, maximum);
}

proc printStatistics((mean,stdDev,minimum,firstQuartile,median,thirdQuartile,maximum):7*real) {
  writef("%<40s %dr\n", "min_time:", minimum);
  writef("%<40s %dr\n", "firstquartile_time:", firstQuartile);
  writef("%<40s %dr\n", "median_time:", median);
  writef("%<40s %dr\n", "thirdquartile_time:", thirdQuartile);
  writef("%<40s %dr\n", "max_time:", maximum);
  writef("%<40s %dr\n", "mean_time:", mean);
  writef("%<40s %dr\n", "stddev_time:", stdDev);
  writeln();
}

proc main() {
  var timer:stopwatch;
  var result:int;

  timer.start();
  var (rows, cols, vals) = getRandomSparseIndicesAndValues();
  timer.stop();
  var elapsedTime = timer.elapsed(); timer.reset();
  writeln("Running Benchmark for Scale %i Matrix".format(SCALE));
  writeln("Generating random indices and values took: %r secs".format(elapsedTime));
  writeln();

  if runAgg {
    writeln("Running Aggregated Sparse Matrix Creation...");
    var times: [1..trials] real;
    for i in times.domain {
      timer.start();
      result = runAggregatedSparseMatrixCreation(rows, cols, vals);
      timer.stop();
      times[i] = timer.elapsed(); timer.reset();
    }

    var stats = computeStatistics(times);
    writef("%<40s %.2Er\n", "nnz:", result);
    printStatistics(stats);
  }
  
  if runNoAgg {
    writeln("Running Non-Aggregated Sparse Matrix Creation...");
    var times: [1..trials] real;
    for i in times.domain {
      timer.start();
      result = runNonAggregatedSparseMatrixCreation(rows, cols, vals);
      timer.stop();
      times[i] = timer.elapsed(); timer.reset();
    }

    var stats = computeStatistics(times);
    writef("%<40s %.2Er\n", "nnz:", result);
    printStatistics(stats);
  }
}
