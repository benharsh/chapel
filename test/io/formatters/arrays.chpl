
use IO;
use Json;
use FormatHelper;

proc makeND(param rank : int) {
  var dims : rank*range;
  for d in dims do d = 1..3;
  var dom = {(...dims)};
  var A : [dom] int;
  var count = 0;
  for a in A {
    a = count;
    count += 1;
  }
  return A;
}

// TODO: reading
proc main() {
  for param i in 1..5 {
    writeln("----- ", i:string, "D -----");
    var A = makeND(i);
    stdout.withFormatter(FormatWriter).writeln(A);
  }
}
