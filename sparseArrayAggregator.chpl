use AggregationPrimitives;
use BlockDist;
use ChplConfig;
use CTypes;
use CopyAggregation;
use IO.FormattedIO;
use Random;
use Time;

private config param verboseAggregation = false;

private param defaultBuffSize = if CHPL_TARGET_PLATFORM == "hpe-cray-ex" then 1024
																else if CHPL_COMM == "ugni" then 4096
																else 8192;

private const yieldFrequency = getEnvInt("CHPL_AGGREGATION_YIELD_FREQUENCY", 1024);
private const dstBuffSize = getEnvInt("CHPL_AGGREGATION_DST_BUFF_SIZE", defaultBuffSize);
private const srcBuffSize = getEnvInt("CHPL_AGGREGATION_SRC_BUFF_SIZE", defaultBuffSize);
private config param aggregate = CHPL_COMM != "none";

config const A = 0.57;
config const B = 0.19;
config const C = 0.19;
config const D = 0.05;
config const SCALE = 10;
config const FACTOR = 16;
config const N = 2**SCALE;
config const NNZ = 2**SCALE * FACTOR;
config const verboseArrayPrint = false;
var timer:stopwatch;

proc assignQuadrant(iiBit:bool, jjBit:bool, bit:int):(int,int) {
  var start, end:int = 0; 

  if !iiBit && !jjBit then; // do nothing;
  else if iiBit && !jjBit then start += 1; 
  else if !iiBit && jjBit then end += 1; 
  else { start = 1; end = 1; }

  return (bit*start, bit*end);
}

proc recursiveMatrixGenerator(a:real, b:real, c:real, d:real, SCALE:int, n:int, nnz:int) {
  const nRange = 1..n,
        nnzRange = 1..nnz;

  var randGen = new randomStream(real);
  var unifRandom = blockDist.createArray({nnzRange}, real);
  var val = blockDist.createArray({nnzRange}, (int,int));
  val = (1,1);

  // Calculate constants for bit-setting operations
  const cNorm = c / (1 - (a + b));
  const aNorm = a / (a + b);
  const ab = a + b;

  // For each bit, generate the indices of each quadrant that the val will be in
  for s in 1..SCALE {
    randGen.fill(unifRandom);
    var iiBit = unifRandom > ab;

    randGen.fill(unifRandom);
    var jjBit = unifRandom > (cNorm * iiBit:real + aNorm * (!iiBit):real);
    
    val += assignQuadrant(iiBit, jjBit, 2**(s-1));
  }

  // Transfer val from array of tuples to row and col arrays
  var row = blockDist.createArray({nnzRange}, int);
  var col = blockDist.createArray({nnzRange}, int);
  forall (v,s,d) in zip(val,row,col) { (s,d) = v; }

  // Create a random permutation of the vertex names
  var originalIndices = blockDist.createArray({nRange}, int);
  forall (o,i) in zip(originalIndices,originalIndices.domain) do o = i;
  var permutation = permute(originalIndices);

  // Change the val to the new permutation of vertex names
  forall i in val.domain with (var agg = new SrcAggregator(int)) {
    agg.copy(row[i], permutation[row[i]]);
    agg.copy(col[i], permutation[col[i]]);
  }

  return (row, col);
}

const Space = {1..N, 1..N};
const DenseDom = Space dmapped new blockDist(Space);

var SparseDomNoAgg: sparse subdomain(DenseDom);
var SparseDomAgg: sparse subdomain(DenseDom);

/* 
	Aggregates ``copy(ref dst, src)``. Optimized for when src is local.
	Not parallel safe and is expected to be created on a per-task basis.
	High memory usage since there are per-destination buffers. 
*/
record SparseDomainDstAggregator {
	type elemType;
	@chpldoc.nodoc
	var agg: if aggregate then SparseDomainDstAggregatorImpl(elemType) else nothing;
	
	/* 
		Sets ``dst = srcVal`` in a way that aggregates such updates
    to improve communication efficiency assuming that ``dst`` is remote
    and ``srcVal`` is local. 
	*/
	inline proc ref copy(const in loc: int, const in srcVal: elemType) {
    if aggregate then agg.copy(loc, srcVal);
    else SparseDomAgg.add(srcVal);
	}
	
	/* 
		Flushes the aggregator & completes the updates queued up from the
    :proc:`DstAggregator.copy` calls.

    :arg freeBuffers: if ``true``, deallocates buffers used by this
                      aggregator. If ``false``, the buffers will remain
                      allocated after this ``flush`` (to support further
                      :proc:`DstAggregator.copy` calls) and deallocated
                      when the aggregator variable is deinitialized.
  */
	inline proc ref flush(freeBuffers=false) {
    if aggregate then agg.flush(freeBuffers=freeBuffers);
	}
}

@chpldoc.nodoc
record SparseDomainDstAggregatorImpl {
	type elemType;
	type aggType = elemType;
	const bufferSize = dstBuffSize;
	const myLocaleSpace = 0..<numLocales;
	var lastLocale: int;
	var opsUntilYield = yieldFrequency;
	var lBuffers: c_ptr(c_ptr(aggType));
	var rBuffers: [myLocaleSpace] remoteBuffer(aggType);
	var bufferIdxs: c_ptr(int);

	proc ref postinit() {
		lBuffers = allocate(c_ptr(aggType), numLocales);
		bufferIdxs = bufferIdxAlloc();
		for loc in myLocaleSpace {
			lBuffers[loc] = allocate(aggType, bufferSize);
			bufferIdxs[loc] = 0;
			rBuffers[loc] = new remoteBuffer(aggType, bufferSize, loc);
		}
	}

	proc ref deinit() {
		flush(freeBuffers=true);
		for loc in myLocaleSpace {
			deallocate(lBuffers[loc]);
		}
		deallocate(lBuffers);
		deallocate(bufferIdxs);
	}

	proc ref flush(freeBuffers: bool) {
		for offsetLoc in myLocaleSpace + lastLocale {
			const loc = offsetLoc % numLocales;
			_flushBuffer(loc, bufferIdxs[loc], freeData=freeBuffers);
		}
	}

	inline proc ref copy(const in loc: int, const in srcVal: elemType) {
		if verboseAggregation {
			writeln("DstAggregator.copy is called");
		}
		// Get the locale of dst and the local address on that locale
		// const loc = dst.locale.id;
		lastLocale = loc;
		// const dstAddr = getAddr(dst);

		// Get our current index into the buffer for dst's locale
		ref bufferIdx = bufferIdxs[loc];

		// Buffer the address and desired value
		lBuffers[loc][bufferIdx] = srcVal;
		bufferIdx += 1;

		// Flush our buffer if it's full. If it's been a while since we've let
		// other tasks run, yield so that we're not blocking remote tasks from
		// flushing their buffers.
		if bufferIdx == bufferSize {
			_flushBuffer(loc, bufferIdx, freeData=false);
			opsUntilYield = yieldFrequency;
		} else if opsUntilYield == 0 {
			currentTask.yieldExecution();
			opsUntilYield = yieldFrequency;
		} else {
			opsUntilYield -= 1;
		}
	}

	proc ref _flushBuffer(loc: int, ref bufferIdx, freeData) {
		const myBufferIdx = bufferIdx;
		if myBufferIdx == 0 then return;

		// Allocate a remote buffer
		ref rBuffer = rBuffers[loc];
		const remBufferPtr = rBuffer.cachedAlloc();

		// Copy local buffer to remote buffer
		rBuffer.PUT(lBuffers[loc], myBufferIdx);

		// Process remote buffer
		on Locales[loc] {
			for srcVal in rBuffer.localIter(remBufferPtr, myBufferIdx) {
				SparseDomAgg.add(srcVal);
			}
			if freeData {
				rBuffer.localFree(remBufferPtr);
			}
		}
		if freeData {
			rBuffer.markFreed();
		}
		bufferIdx = 0;
	}
}

var (rowIdx, colIdx) = recursiveMatrixGenerator(A, B, C, D, SCALE, N, NNZ);
var vals = blockDist.createArray({1..rowIdx.size}, int);
forall (i,v) in zip(vals.domain, vals) do v = i;

// No aggregation case
timer.start();
forall (i,j) in zip(rowIdx,colIdx) with (ref SparseDomNoAgg) do 
	SparseDomNoAgg.add((i,j));
var SparseArrNoAgg: [SparseDomNoAgg] int;
for i in vals.domain do SparseArrNoAgg[rowIdx[i], colIdx[i]] = vals[i];
writeln("SparseDomNoAgg time: %r".format(timer.elapsed()));
writeln("SparseDomNoAgg size: %i".format(SparseDomNoAgg.size));

// Aggregation case
timer.restart();
forall (i,j) in zip(rowIdx,colIdx) with (var agg = new SparseDomainDstAggregator((int,int))) do 
	agg.copy(DenseDom.distribution.dsiIndexToLocale((i,j)).id, (i,j));
var SparseArrAgg: [SparseDomAgg] int;
for i in vals.domain do SparseArrAgg[rowIdx[i], colIdx[i]] = vals[i];
writeln("  SparseDomAgg time: %r".format(timer.elapsed()));
writeln("  SparseDomAgg size: %i".format(SparseDomAgg.size));

if verboseArrayPrint {
	writeln();
	for (r,c) in SparseDomNoAgg do write(SparseArrNoAgg[r,c], " ");
	writeln();
	for (r,c) in SparseDomAgg do write(SparseArrAgg[r,c], " ");
	writeln();
}
