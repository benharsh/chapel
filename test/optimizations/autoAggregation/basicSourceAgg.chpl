writeln();

use BlockDist;

var a = blockDist.createArray(0..10, int);
var b = blockDist.createArray(0..10, int);

for i in b.domain {
  b[i] = i;
}

writeln("Loop 1");
forall i in a.domain with (ref a) {
  a[i] = b[10-i];
}
writeln("End Loop 1");

writeln(a);
writeln();

b = 0;

writeln("Loop 2");
forall i in a.domain with (ref a, ref b) {
  a[i] = b[10-i];
  b[10-i] += 5; // should thwart the optimization
}
writeln("End Loop 2");

writeln(a);
writeln();

writeln("Loop 3");
forall (aElem,i) in zip(a, 0..10) {
  aElem = b[10-i];  // expect two confirmations: fast follower, slow follower
}
writeln("End Loop 3");

writeln(a);
writeln();
