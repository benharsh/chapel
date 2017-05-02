record R {
  var x : int;
}

var g : R;

proc test(args: R ...) {
  for a in args {
    writeln(a);
    g.x += 1;
    writeln(a); // what should this print? g's value?
    writeln("----");
  }
}

test(g,g,g);

