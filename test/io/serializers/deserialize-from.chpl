
use IO;

record R : writeSerializable, readDeserializable {
  var x : int;

  proc serialize(writer: fileWriter(?), ref serializer) {
    writer.write(x);
  }

  proc ref deserialize(reader, ref deserializer) throws {
    writeln("deserialize");
    this.x = reader.read(int);
  }

  proc type deserializeFrom(reader: fileReader(?), ref deserializer) {
    writeln("deserializeFrom");
    return new R(reader.read(int));
  }
}

record G : writeSerializable, readDeserializable {
  var x;

  proc serialize(writer: fileWriter(?), ref serializer) {
    writer.write(x);
  }

  proc ref deserialize(reader, ref deserializer) throws {
    writeln("deserialize");
    this.x = reader.read(int);
  }

  proc type deserializeFrom(reader: fileReader(?), ref deserializer) {
    writeln("deserializeFrom");
    type fieldType = __primitive("field by num", this, 1);
    return new G(reader.read(fieldType));
  }
}

class C : writeSerializable, readDeserializable {
  var x : int;

  override proc serialize(writer: fileWriter(?), ref serializer) {
    writer.writeLiteral("<");
    writer.write(x);
    writer.writeLiteral(">");
  }

  override proc deserialize(reader, ref deserializer) throws {
    writeln("deserialize");
    this.x = reader.read(int);
  }

  proc type deserializeFrom(reader: fileReader(?), ref deserializer) {
    writeln("deserializeFrom");
    type retType = this;
    reader.readLiteral("<");
    var ret = new retType(reader.read(int));
    reader.readLiteral(">");
    return ret;
  }

  proc equals(other: borrowed C) {
    return this.x == other.x;
  }
}

proc test(val, type T) {
  var f = openMemFile();
  {
    f.writer().write(val);
  }
  {
    var read = f.reader().read(T);

    if isClassType(T) {
      if isNilableClassType(T) {
        if val == nil then
          assert(read == nil);
        else assert(val!.equals(read!));
      } else {
        assert(val.equals(read));
      }
    } else {
      assert(read == val);
    }
  }
}

proc main() {
  test(new R(5), R);
  test(new G(42.0), G(real));

  // test 'nil' case to make sure serializers can still control the reading of
  // the 'nil' string (as compared to something like "null" for json).
  test(nil, unmanaged C?);
  test(new C(5), owned C);
  writeln("SUCCESS");
}
