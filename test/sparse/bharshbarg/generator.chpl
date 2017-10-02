
use IO;
use Random.PCGRandom;

config const seed = 12345;

config const n = 500;

config const rowStart = 1,
             colStart = 1;

config const rows = n,
             cols = n;

config const sparsity = .01;

config const delim = ",";

const filename = "sparse.csv";

//
// File format:
//
// rowStart,numRows
// colStart,numCols
// numElements
//
// 'numElements' lines of the format:
// rowIdx,colIdx,value
//

proc main() {
  if sparsity > 1.0 then
    halt("sparsity must be within [0.0, 1.0]");

  writeln("Generating CSV for sparse array:");
  writeln("#rows    = ", rows);
  writeln("#cols    = ", cols);
  writeln("sparsity = ", sparsity * 100, "%");

  var stream = new RandomStream(eltType=int, parSafe=false, seed=seed);

  var fi  = open(filename, iomode.cw);
  var wrt = fi.writer(locking=false);

  const numElts   = (rows * cols * sparsity):int;
  const numCols   = (cols * sparsity):int;
  const colStride = cols / numCols;

  wrt.writeln(rowStart, delim, rows);
  wrt.writeln(colStart, delim, cols);
  wrt.writeln(numElts);
  wrt.writeln();

  var numWritten = 0;

  for r in rowStart..#rows {
    const stride = stream.getNext(1, colStride);

    for c in colStart.. by stride #numCols {
      const val = c:real / cols:real;

      wrt.writeln(r,delim,c,delim,val);
      numWritten += 1;
    }
  }

  wrt.close();
  fi.close();

  if numWritten != numElts {
    stderr.writeln("Wrote incorrect number of elements!");
    stderr.writeln("Expecting ", numElts, ", wrote ", numWritten);
    exit(1);
  }
}
