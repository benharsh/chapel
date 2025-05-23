// This version ran in...
//   618.233 with default arguments, linear search for sparse domain this()
//    62.169 with --cflags=-O3, linear search
//    25.4556 with --cflags=-O3, binary search
use CompressedSparseLayout, CGMakeA, Time;
use CSimpl; // user-space partial reductions

type elemType = real(64);

enum classVals {S, W, A, B, C, D};


const Class = {classVals.S..classVals.D};
const probSizes:   [Class] int = [ 1400, 7000, 14000, 75000, 150000, 150000 ],
      nonZeroes:   [Class] int = [ 7, 8, 11, 13, 15, 21 ],
      shifts:      [Class] int = [ 10, 12, 20, 60, 110, 500 ],
      numIters:    [Class] int = [ 15, 15, 15, 75, 75, 100 ],
      verifyZetas: [Class] elemType = [ 8.5971775078648, 10.362595087124,
                                        17.130235054029,  22.712745482631,
                                        28.973605592845,  52.5145321058 ];

config const probClass = classVals.S;

config const n = probSizes(probClass),
             nonzer = nonZeroes(probClass),
             shift = shifts(probClass),
             niter = numIters(probClass),
             zetaVerifyValue = verifyZetas(probClass);

config const numTrials = 1,
             verbose = true,
             debug = false,
             printTiming = true,
             printError = true;


proc main() {
  const DenseSpace = {1..n, 1..n};
  const MatrixSpace: sparse subdomain(DenseSpace) dmapped new csrLayout()
                   = genAIndsSorted(elemType, n, nonzer, shift);
  var A: [MatrixSpace] elemType;

  for (ind, v) in makea(elemType, n, nonzer, shift) {
    A(ind) += v;
  }

  const VectorSpace = {1..1,1..n};  // a dense row
  var X: [VectorSpace] elemType,
      zeta = 0.0;

  for trial in 1..numTrials {
    X = 1.0;

    const startTime = timeSinceEpoch().totalSeconds();

    for it in 1..niter {
      const (Z, rnorm) = conjGrad(A, X);

      zeta = shift + 1.0 / + reduce (X*Z);

      if verbose then writeln(it, " ", rnorm, " ", zeta);

      X = (1.0 / sqrt(+ reduce(Z*Z))) * Z;
    }

    const runtime = timeSinceEpoch().totalSeconds() - startTime;

    if printTiming then writeln("Execution time = ", runtime);

    if (zetaVerifyValue != 0.0) {
      const epsilon = 1.0e-10;
      if (abs(zeta - zetaVerifyValue) <= epsilon) {
        writeln("Verification successful");
        writeln("Zeta is: ", zeta);
        if printError then writeln("Error is: ", zeta - zetaVerifyValue);
      } else {
        writeln("Verification failed");
        writeln("Zeta is: ", zeta);
        writeln("The correct zeta is: ", zetaVerifyValue);
      }
    } else {
      writeln("No verification performed");
    }
  }
}


proc conjGrad(A: [?MatDom], X: [?VectDom]) {
  const cgitmax = 25;

  var Z: [VectDom] elemType = 0.0,
      Q: [VectDom] elemType = 0.0,
      R = X,
      P = R;
  var rho = + reduce R**2;

  var W: [1..n,1..1] elemType;  // helper dense column

  for cgit in 1..cgitmax {
    // WANT (a partial reduction):
    //    const Q = + reduce(dim=2) [(i,j) in MatDom] (A(i,j) * P(j));
    //
    inline proc ForallExpr1.this((i,j)) do return A(i,j) * P(1,j);
    plusPRinto(W, MatDom, new ForallExpr1());
    transpose(Q, W);

    const alpha = rho / + reduce (P*Q);
    Z += alpha*P;
    R -= alpha*Q;

    const rho0 = rho;
    rho = + reduce R**2;
    const beta = rho / rho0;
    P = R + beta*P;
  }

  // WANT (a partial reduction):
  //      R = + reduce(dim=2) [(i,j) in MatDom] (A(i,j) * Z(j));
  //
  inline proc ForallExpr2.this((i,j)) do return A(i,j) * Z(1,j);
  plusPRinto(W, MatDom, new ForallExpr2());
  transpose(R, W);

  const rnorm = sqrt(+ reduce ((X-R)**2));

  return (Z, rnorm);
}

// This is a workaround for the current limitations, see #9773.
// We may want to define the record type in the nested scope -
// where its 'this' method is currently defined - and not have to
// provide the 'init' method.
record ForallExpr1 { proc init(){} }
record ForallExpr2 { proc init(){} }

proc transpose(ref DestRow, SrcCol) {
  // a shared-memory version for now
  forall i in 1..n with (ref DestRow) do
    DestRow(1,i) = SrcCol(i,1);
}
