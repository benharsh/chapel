use BlockDist;
use CommDiagnostics;

config const printArray = true;

proc main() {
  const D = {1..10, 1..10} dmapped blockDist({1..10, 1..10});
  var A: [D] real;

  forall a in A do
    a = here.id;

  writeln();
  writeln("Creating B (a normal slice)");
  writeln("---------------------------");

  startTrial();
  ref B = A[3..8, 3..8];
  stopTrial();


  writeln();
  writeln("Incrementing B via access");
  writeln("-------------------------");

  startTrial();
  forall ij in B.domain with (ref B) do
    B[ij] += 0.1;
  stopTrial();


  writeln();
  writeln("Incrementing B via iteration");
  writeln("----------------------------");

  startTrial();
  forall b in B do
    b += 0.1;
  stopTrial();


  writeln();
  writeln("Incrementing B via routine:");
  increment(B, B.domain);

  writeln();
  writeln("Incrementing B via routine:");
  increment(B);


  inline proc startTrial() {
    resetCommDiagnostics();
    startCommDiagnostics();
  }

  inline proc stopTrial() {
    stopCommDiagnostics();
    // retrieve the counts and report the results
    writeln(getCommDiagnostics());
    if printArray then
      writeln("\nA is:\n", A);
  }

  proc increment(ref X, D) {
    writeln("Incrementing in routine by access");
    writeln("---------------------------------");

    startTrial();
    forall ij in D with (ref X) do
      X[ij] += 0.1;
    stopTrial();
  }

  proc increment(ref X) {
    writeln("Incrementing in routine by iteration");
    writeln("------------------------------------");

    startTrial();
    forall x in X do
      x += 0.1;
    stopTrial();
  }
}
