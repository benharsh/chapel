
use IO;
use Json;
use FormatHelper;
use List;

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
// TODO: sparse?
proc main() {
  for param i in 1..5 {
    writeln("----- ", i:string, "D -----");
    var A = makeND(i);
    stdout.withFormatter(FormatWriter).writeln(A);
  }

  {
    var D : domain(int) = {1, 2, 3, 5, 6, 8, 10};
    var A : [D] int;
    [d in D] A[d] = d**2;
    stdout.withFormatter(FormatWriter).writeln(A);
  }

  {
    var li : list(int);
    for i in 1..10 do li.append(i**2);
    stdout.withFormatter(FormatWriter).writeln(li);
  }
}
