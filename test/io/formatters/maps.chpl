
use IO;
use Map;
use FormatHelper;

record R {
  var x : int;
  var y : real;
}

proc test(m: map) {
  var f = openMemFile();
  {
    f.writer().withFormatter(FormatWriter).writeln(m);
  }
  {
    var x = f.reader().withFormatter(FormatReader).read(m.type);
    if m != x then
      writeln("FAILURE: ", m.type:string);
    else
      writeln("SUCCESS: ", m.type:string);
  }
}

proc main() {
  {
    var m : map(string, string);
    m.add("hello", "goodbye");
    m.add("day", "night");
    m.add("east", "west");
    m.add("north", "south");

    stdout.withFormatter(FormatWriter).writeln(m);
    test(m);
  }

  // Check what formatter does with non-string key
  {
    var m : map(int, string);
    m.add(206, "Seattle");
    m.add(212, "NYC");
    m.add(713, "Houston");
    
    stdout.withFormatter(FormatWriter).writeln(m);
    test(m);
  }

  {
    var m : map(string, R);
    m.add("Apple", new R(5, 42.0));
    m.add("Banana", new R(1, -10.0));
    m.add("Orange", new R(13, 106.7));

    stdout.withFormatter(FormatWriter).writeln(m);
    test(m);

    // TODO: need a good way to print out records as keys in json
    var r : map(R, string);
    for (k, v) in m.items() do
      r.add(v, k);

    stdout.withFormatter(FormatWriter).writeln(r);
    test(r);
  }
}
