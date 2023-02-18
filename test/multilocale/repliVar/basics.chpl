
use IO;
use RepliVar;
use CommDiagnostics;

var global : replicated(int);
var str : replicated(string) = "hello";

record R {
  var x : int;

  proc print() {
    writeln("x = ", x);
  }
}

proc main() {
  writeln(str);
  for loc in Locales do on loc {
    writeln(str, " :: ", str.size);
  }

  [g in global.replicands()] g = here.id;
  for loc in Locales do on loc {
    writeln(global);
  }
  global.printAll();
  global.printAll(true);

  global = 42;
  global.printAll();

  var rec : replicated(R);
  [r in rec.replicands()] r.x = here.id;
  rec.print();
  rec.replicands().print();
}
