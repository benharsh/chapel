
use IO, Json;

proc main() {
  var f = openMemFile();
  var x = "with, \"quotes\" !";
  {
    f.writer().withSerializer(JsonWriter).writeln(x);
  }
  {
    var got = f.reader().withDeserializer(JsonReader).read(string);
    assert(x == got);
  }
}
