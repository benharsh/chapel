
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

proc test(A) {
  stdout.withFormatter(FormatWriter).writeln(A);
  var f = openMemFile();
  {
    f.writer().withFormatter(FormatWriter).write(A);
  }
  {
    var B = f.reader().withFormatter(FormatReader).read(A.type);

    var match = false;
    if isArray(A) {
      match = && reduce (A == B);
    } else {
      match = (A == B);
    }

    if !match then
      writeln("FAILURE: ", A.type:string);
    else
      writeln("SUCCESS: ", A.type:string);
  }
}

// TODO: sparse?
proc main() {
  for param i in 1..5 {
    writeln("----- ", i:string, "D -----");
    var A = makeND(i);
    test(A);
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
    test(li);
  }
}
