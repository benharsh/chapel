
use IO;
use List;

use StrictBinary;

// IDEA: wrapper around other format, write to memfile, then dump
// - Type keeps track if it's the top-level 'serialize' call, so that it knows
//   to dump the output when it's done
// - ... either that, or require manually calling a method, `w.serializer.dump()`

// How to deal with unknown types?
// - at some point, we'll try to read the expected static type
// - that entry in the file will point to an ID of some kind
// - that ID should be a key in a map that points to some part of the file?

// ---------------------------

// OR:
// write objects as you encounter them with a preceeding ID. If you encounter
// the same ID again, then just write a dummy entry and not the ID itself

class Node {
  var x : int;

  var neighbors : list(shared Node);

  proc add(n : shared Node...) {
    for param i in 0..<n.size do
      neighbors.pushBack(n(i));
  }

  proc equals(other: borrowed Node) : bool {
    if x != other.x then return false;

    if neighbors.size != other.neighbors.size then return false;

    for (a, b) in zip(neighbors, other.neighbors) do
      if a.equals(b) == false then return false;

    return true;
  }
}

proc printDebugFmt(val) throws {
  writeln("===== writing: =====");
  stdout.writeln(val);
  writeln("--------------------");

  var f = openMemFile();
  {
    var w = f.writer();
    w.withSerializer(StrictBinarySerializer).write(val);
  }
  var r = f.reader();
  try {
    while true {
      stdout.writef("%02xu", r.readByte());
    }
  } catch { }
  stdout.writeln();

  writeln("====================");
}

proc main() {
  var nodes : list(shared Node);
  for i in 0..<10 do nodes.pushBack(new shared Node(i));
  var root = nodes[0];

  root.add(nodes[1], nodes[2]);

  nodes[1].add(nodes[3], nodes[4], nodes[5]);
  nodes[2].add(nodes[4], nodes[5], nodes[6]);

  nodes[3].add(nodes[7], nodes[8]);
  nodes[4].add(nodes[8]);

  nodes[5].add(nodes[9]);
  nodes[6].add(nodes[9]);

  var cc = new StrictBinarySerializer();
  printDebugFmt(root);
  var f = openMemFile();
  { f.writer(serializer=cc).writeln(root); }
  {
    var x = f.reader(deserializer=new StrictBinaryDeserializer()).read(shared Node);
    writeln(x);
    writeln(x.equals(root));
  }
}
