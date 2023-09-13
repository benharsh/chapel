
use IO;

record JustTwo : writeSerializable, readDeserializable {
  var x : int;

  proc serialize(writer, ref serializer) throws {
    writer.write(x);
  }

  proc ref deserialize(reader, ref deserializer) throws {
    this.x = reader.read(int);
  }

  proc init(x = 0) {
    this.x = x;
  }

  proc init(reader, ref deserializer) {
    init this;
    this.x = reader.read(int);
  }
}

record Serializable : serializable {
  var x : int;

  proc serialize(writer, ref serializer) throws {
    writer.write(x);
  }

  proc ref deserialize(reader, ref deserializer) throws {
    this.x = reader.read(int);
  }

  proc init(x = 0) {
    this.x = x;
  }

  proc init(reader, ref deserializer) {
    init this;
    this.x = reader.read(int);
  }
}

record Default {
  var x : int;
}

record SerializeMissing {
  var x : int;

  proc serialize(writer, ref serializer) throws {
    writer.write(x);
  }
}

record SerializePresent : writeSerializable {
  var x : int;

  proc serialize(writer, ref serializer) throws {
    writer.write(x);
  }
}

record DeserializeMissing : writeSerializable {
  var x : int;

  proc serialize(writer, ref serializer) throws {
    writer.write(x);
  }

  proc ref deserialize(reader, ref deserializer) throws {
    this.x = reader.read(int);
  }
}

record DeserializePresent : writeSerializable, readDeserializable {
  var x : int;

  proc serialize(writer, ref serializer) throws {
    writer.write(x);
  }

  proc ref deserialize(reader, ref deserializer) throws {
    this.x = reader.read(int);
  }
}

record InitMissing : writeSerializable {
  var x : int;

  proc serialize(writer, ref serializer) throws {
    writer.write(x);
  }

  proc init(x = 0) { this.x = x; }

  proc init(reader, ref deserializer) throws {
    init this;
    this.x = reader.read(int);
  }
}

record InitPresent : writeSerializable, initDeserializable {
  var x : int;

  proc serialize(writer, ref serializer) throws {
    writer.write(x);
  }

  proc init(x = 0) { this.x = x; }

  proc init(reader, ref deserializer) throws {
    init this;
    this.x = reader.read(int);
  }
}

enum mode { no, readVal, readInit }
use mode;

proc test(type T, param read = mode.readVal) {
  writeln("----- ", T:string, " -----");
  var f = openMemFile();
  var val : T;
  val.x = 10;
  f.writer().write(val);

  if read == readVal {
    var newVal : T;
    f.reader().read(newVal);
    writeln("got: ", newVal);
    assert(newVal.x == 10);
  } else if read == readInit {
    var newVal : T = f.reader().read(T);;
    writeln("got: ", newVal);
    assert(newVal.x == 10);
  }
}

// TODO: CLASSES!
proc main() {
  test(JustTwo);
  test(Default);
  test(Serializable);
  test(SerializeMissing,read=no);
  test(SerializePresent,read=no);
  test(DeserializeMissing);
  test(DeserializePresent);
  test(InitMissing, read=readInit);
  test(InitPresent, read=readInit);
}
