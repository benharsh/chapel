
use IO, Json;

proc main() {
  var f = openMemFile();
  var x = "with, \"quotes\" !";
  {
    f.writer().withFormatter(JsonWriter).writeln(x);
  }
  {
    var got = f.reader().withFormatter(JsonReader).read(string);
    assert(x == got);
  }
}
