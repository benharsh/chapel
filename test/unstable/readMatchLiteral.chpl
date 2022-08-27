
use IO;

proc main() {
  var f = openmem();
  {
    var w = f.writer();
    for 1..2 {
      w.write("$");
      w.write("$");
      w.write("\n");
    }
  }

  var r = f.reader();

  r.readLiteral("$");
  r.readLiteral(b"$");
  r.readNewline();

  assert(r.matchLiteral("$"));
  assert(r.matchLiteral(b"$"));
  assert(r.matchNewline());
}
