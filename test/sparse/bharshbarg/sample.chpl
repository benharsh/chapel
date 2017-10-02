
use SparseIO;
use LinearAlgebra.Sparse;

config const inputFile  = "sparse.csv";
config const outputFile = "out.bin";

config const verify = false;

proc check(A : [], B : []) {
  assert(A.domain == B.domain, "Domains not equal.");

  forall i in A.domain {
    assert(A[i] == B[i], "Elements not equal");
  }
}

proc main() {
  // Result is a record with a sparse domain and array as fields.
  var R = readCSV(inputFile);

  ref A = R.getArray();

  var Squared = A.dot(A);

  writeBinary(outputFile, Squared);

  if verify {
    forall s in Squared.domain do assert(Squared.domain.member(s), "Result of A*A is corrupted");

    var BR = readBinary(outputFile);
    ref B = BR.getArray();

    check(Squared, B);
  }
}
