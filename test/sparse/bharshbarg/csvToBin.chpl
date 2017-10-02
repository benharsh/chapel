
use Time;
use SparseIO;

config const inputFile = "sparse.csv";
config const outputCSV = "out.csv";
config const outputBin = "out.bin";
config const delim     = ",";
config const verify    = false;

proc check(A : [], B: []) {
  writeln("Verifying...");
  assert(A.domain == B.domain);

  forall i in A.domain {
    assert(A[i] == B[i]);
  }
  writeln("SUCCESS");
}

proc checkCSV(A: [], fname : string, delim=",") {
  var R = readCSV(fname, delim=delim);
  ref B = R.getArray();

  check(A, B);
}

proc checkBinary(A: [], fname : string) {
  var R = readBinary(fname);
  ref B = R.getArray();

  check(A, B);
}

proc main() {
  // Result is a record with a sparse domain and array as fields.
  var R = readCSV(inputFile, delim=delim);

  ref D = R.getDomain();
  ref A = R.getArray();
  const sparsity = (A.size:real / (* reduce A.shape)) * 100;
  writeln("Loaded ", A.shape, " sparse array with ", sparsity, "% sparsity from file '", inputFile, "'");

  writeCSV(outputCSV, A, delim=":");

  if verify then checkCSV(A, outputCSV, delim=":");

  writeBinary(outputBin, A);

  if verify then checkBinary(A, outputBin);
}
