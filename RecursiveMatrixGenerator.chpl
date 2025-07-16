module RecursiveMatrixGenerator {
  use BlockDist;
  use Random;
  use CopyAggregation;

  proc assignQuadrant(iiBit:bool, jjBit:bool, bit:int):(int,int) {
    var start, end:int = 0;

    if !iiBit && !jjBit then; // do nothing;
    else if iiBit && !jjBit then start += 1; 
    else if !iiBit && jjBit then end += 1; 
    else { start = 1; end = 1; }

    return (bit*start, bit*end);
  }

  proc recursiveMatrixGenerator(a:real, b:real, c:real, d:real, SCALE:int, n:int, nnz:int) {
    const nRange = 0..<n,
          nnzRange = 0..<nnz;

    var randGen = new randomStream(real);
    var unifRandom = blockDist.createArray({nnzRange}, real);
    var idx = blockDist.createArray({nnzRange}, (int,int));
    idx = (1,1);

    // Calculate constants for bit-setting operations
    const cNorm = c / (1 - (a + b));
    const aNorm = a / (a + b);
    const ab = a + b;

    // For each bit, generate the indices of each quadrant that the idx will be in
    for s in 1..SCALE {
      randGen.fill(unifRandom);
      var iiBit = unifRandom > ab;

      randGen.fill(unifRandom);
      var jjBit = unifRandom > (cNorm * iiBit:real + aNorm * (!iiBit):real);
      
      idx += assignQuadrant(iiBit, jjBit, 2**(s-1));
    }

    // Transfer idx from array of tuples to row and col arrays
    var row = blockDist.createArray({nnzRange}, int);
    var col = blockDist.createArray({nnzRange}, int);
    forall (i,s,d) in zip(idx,row,col) { (s,d) = i; }

    // Create a random permutation of the indices
    var nRangeIndices = blockDist.createArray({nRange}, int);
    forall (o,i) in zip(nRangeIndices, nRangeIndices.domain) do o = i;
    var permutation = permute(nRangeIndices);

    // Change row and col to the new permutation of indices
    forall i in idx.domain with (var agg = new SrcAggregator(int)) {
      agg.copy(row[i], permutation[row[i]]);
      agg.copy(col[i], permutation[col[i]]);
    }

    return (row, col);
  }
}