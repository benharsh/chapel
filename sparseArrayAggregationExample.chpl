use BlockDist;
use CTypes;
use IO.FormattedIO;
use Time;

use RecursiveMatrixGenerator;
use SparseArrayAggregator;
use SortUtils;

config const A = 0.57;
config const B = 0.19;
config const C = 0.19;
config const D = 0.05;
config const SCALE = 10;
config const FACTOR = 16;
config const N = 2**SCALE;
config const NNZ = 2**SCALE * FACTOR;
config const verboseArrayPrint = false;
config const idxBufSize = SCALE;
var timer:stopwatch;

// The dense space
const Space = {1..N, 1..N};
const DenseDom = Space dmapped new blockDist(Space);

// Creating sparse domains and arrays for two use cases
var SparseDomNoAgg: sparse subdomain(DenseDom);
var SparseDomAgg: sparse subdomain(DenseDom);

var SparseArrNoAgg: [SparseDomNoAgg] int;
var SparseArrAgg: [SparseDomAgg] int;

// Recursively generate sparse indices
var (row,col) = recursiveMatrixGenerator(A, B, C, D, SCALE, N, NNZ);

// Parse out repeated indices
var iv = coargsort(row,col);
var sortedRow = row[iv]; var sortedCol = col[iv];
var sortedIdx = blockDist.createArray(row.domain, (int,int));
forall (si, i) in zip(sortedIdx, sortedIdx.domain) do 
  si = (sortedRow[i], sortedCol[i]);
var uniqueIdx = uniqueFromSorted(sortedIdx, needCounts=false);
var rowIdx = blockDist.createArray(uniqueIdx.domain, int);
var colIdx = blockDist.createArray(uniqueIdx.domain, int);

// Add one to row and column values to account for 0-based index creation that
// `recursiveMatrixGenerator` carries out
forall (ui, r, c) in zip(uniqueIdx, rowIdx, colIdx) {
  r = ui[0] + 1;
  c = ui[1] + 1;
}

var vals = blockDist.createArray({1..rowIdx.size}, int);
forall (i,v) in zip(vals.domain, vals) do v = i;

/***************************** NO AGGREGATION *********************************/
timer.start();
// NOTE: this code block was throwing the following error:
//
//       error: halt reached - attempting to assign a 'zero' value in a sparse array at index (i, j)
//
//       I assume there is some race donition where `v` was getting assigned before `(i,j)` was 
//       being finished added to the domain. However, this does not make sense since the program was
//       being run with `CHPL_RT_NUM_THREADS_PER_LOCALE=1` and should have been behaving like the
//       "fixed" `for` loop version below.
//
forall (i,j) in zip(rowIdx,colIdx) with (var idxBuf = SparseDomNoAgg.createIndexBuffer(idxBufSize)) do
	idxBuf.add((i,j));
forall (i,j,v) in zip(rowIdx,colIdx,vals) with (ref SparseArrNoAgg) do
	SparseArrNoAgg[i,j] = v;

// for loc in Locales do on loc {
//   var lo = rowIdx.domain.localSubdomain().low;
//   var hi = rowIdx.domain.localSubdomain().high;
//   ref localRowIdx = rowIdx[lo..hi];
//   ref localColIdx = colIdx[lo..hi];
//   ref localVals = vals[lo..hi];
//   var idxBuf = SparseDomNoAgg.createIndexBuffer(idxBufSize);
//   for (i,j,v) in zip(localRowIdx,localColIdx,localVals) do idxBuf.add((i,j));
//   idxBuf.commit();
//   for (i,j,v) in zip(localRowIdx,localColIdx,localVals) do SparseArrNoAgg[i,j] = v;
// }
writeln("SparseDomNoAgg time: %r".format(timer.elapsed()));
writeln("SparseDomNoAgg size: %i".format(SparseDomNoAgg.size));
writeln("SparseArrNoAgg size: %i".format(SparseArrNoAgg.size));

/******************************** AGGREGATION *********************************/
class DestinationHandler {
  var domVal;
  var arrVal;

  proc init(domVal, arrVal) {
    this.domVal = domVal;
    this.arrVal = arrVal;
  }

  inline proc flush(ref rBuffer, const ref remBufferPtr, const ref myBufferIdx) {
    const (found, locid) = domVal.dist.chpl__locToLocIdx(here);
    var locIdxBuf = domVal.locDoms[locid]!.mySparseBlock.createIndexBuffer(idxBufSize);
    for (dstAddr, srcVal) in rBuffer.localIter(remBufferPtr, myBufferIdx) {
       assert(dstAddr == nil);
      var (i,j,v) = srcVal;
      locIdxBuf.add((i, j));
    }
    locIdxBuf.commit();
    for (dstAddr, srcVal) in rBuffer.localIter(remBufferPtr, myBufferIdx) {
      assert(dstAddr == nil);
      var (i,j,v) = srcVal;
      const (found, locid) = domVal.dist.chpl__locToLocIdx(here);
      this.arrVal.locArr[locid]!.myElems[i,j] = v;
    }
  }
}

class SourceHandler {
  var domVal;
  var arrVal;

  // NOTE: This type will most likely not be the same type as the data structure
  //       you are aggregating into. In our case, D is of type (int,int) BUT we
  //       need to also pass v so the elemType of the handler has to be (int,int,int).
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
timer.restart();
// "Parallel" version, will only work with CHPL_RT_NUM_THREADS_PER_LOCALE=1 since sparse domains do not support parallel
// index additions. 
forall (i,j,v) in zip(rowIdx,colIdx,vals) with (var agg = new CustomDstAggregator(new shared SourceHandler(SparseDomAgg, SparseArrAgg))) do 
	agg.copy((i,j,v));

// Sequential buffered version to not have to run with CHPL_RT_NUM_THREADS_PER_LOCALE=1.
// for loc in Locales do on loc {
//   var lo = rowIdx.domain.localSubdomain().low;
//   var hi = rowIdx.domain.localSubdomain().high;
//   ref localRowIdx = rowIdx[lo..hi];
//   ref localColIdx = colIdx[lo..hi];
//   ref localVals = vals[lo..hi];
//   var agg = new CustomDstAggregator(new shared SourceHandler(SparseDomAgg, SparseArrAgg));
//   for (i,j,v) in zip(localRowIdx,localColIdx,localVals) do 
//     agg.copy((i,j,v));
//   agg.flush(true);
// }

writeln("  SparseDomAgg time: %r".format(timer.elapsed()));
writeln("  SparseDomAgg size: %i".format(SparseDomAgg.size));
writeln("  SparseArrAgg size: %i".format(SparseArrAgg.size));

if verboseArrayPrint {
	writeln();
	for (r,c) in SparseDomNoAgg do write(SparseArrNoAgg[r,c], " ");
	writeln();
	for (r,c) in SparseDomAgg do write(SparseArrAgg[r,c], " ");
	writeln();
}
