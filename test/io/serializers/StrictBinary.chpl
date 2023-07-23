
module StrictBinary {
  private use IO;
  private use CTypes;
  private use Map;
  private use List;
  private use Types;

  // TODO: Document format

  @chpldoc.nodoc
  type _writeType = fileWriter(serializerType=StrictBinarySerializer, ?);
  @chpldoc.nodoc
  type _readerType = fileReader(deserializerType=StrictBinaryDeserializer, ?);

  class _WriteTable {
    var table : map(unmanaged RootClass?, int);
    var curid : int = 0;

    proc seen(obj) : bool {
      var ptr = _to_unmanaged(obj);
      return table.contains(ptr);
    }

    proc getId(obj) : int {
      var ptr = _to_unmanaged(obj);
      var ret = try! table[ptr];
      return ret;
    }

    proc add(obj) {
      var ptr = _to_unmanaged(obj);
      table.add(ptr, curid);
      curid += 1;
    }
  }

  record StrictBinarySerializer {
    const endian : IO.ioendian = IO.ioendian.native;
    var table : shared _WriteTable = new shared _WriteTable();

    // TODO: We could store a 'size' field internally to track the expected
    // number of fields or elements, and throw errors if that expectation is
    // violated.

    @chpldoc.nodoc
    proc _fork() {
      var ret = new StrictBinarySerializer(endian=endian);
      ret.table = table;
      return ret;
    }

    // TODO: rewrite to use correct IO methods (e.g. writeBinary)
    // For now, this is just a helper to mirror the old behavior for basic
    // types
    @chpldoc.nodoc
    proc _oldWrite(ch: _writeType, const val:?t) throws {
      var _def = new DefaultSerializer();
      var dc = ch.withSerializer(_def);
      var st = dc._styleInternal();
      var orig = st; defer { dc._set_styleInternal(orig); }

      st.binary = 1;
      st.byteorder = 1 + endian:uint(8);
      st.str_style = stringStyleWithVariableLength():int(64);

      dc._set_styleInternal(st);
      dc._writeOne(dc.kind, val, here);
    }

    proc serializeValue(writer: _writeType, const val:?t) throws {
      if isNumericType(t) {
        select endian {
          when ioendian.native do writer.writeBinary(val, ioendian.native);
          when ioendian.little do writer.writeBinary(val, ioendian.little);
          when ioendian.big do writer.writeBinary(val, ioendian.big);
        }
      } else if t == string  || isEnumType(t) || t == bytes ||
                isBoolType(t) {
        _oldWrite(writer, val);
      } else if t == nothing {

      } else if isClassType(t) {
        // Classes always prefixed with a bit indicating nil-ness
        if val == nil {
          writer.writeByte(0);
        } else {
          writer.writeByte(1);

          if table.seen(val) {
            writer.writeByte(1);
            writer.write(table.getId(val));
          } else {
            writer.writeByte(0);
            table.add(val);
            writer.write(table.getId(val));

            var alias = writer.withSerializer(_fork());
            val!.serialize(writer=alias, serializer=alias.serializer);
          }
        }
      } else {
        var alias = writer.withSerializer(_fork());
        val.serialize(writer=alias, serializer=alias.serializer);
      }
    }

    @chpldoc.nodoc
    proc serializeField(writer: _writeType, name: string, const val: ?T) throws {
      writer.write(val);
    }

    // Class helpers
    @chpldoc.nodoc
    proc startClass(writer: _writeType, name: string, size: int) throws {
    }
    @chpldoc.nodoc
    proc endClass(writer: _writeType) throws {
    }

    // Record helpers
    @chpldoc.nodoc
    proc startRecord(writer: _writeType, name: string, size: int) throws {
    }
    @chpldoc.nodoc
    proc endRecord(writer: _writeType) throws {
    }

    // Tuple helpers
    @chpldoc.nodoc
    proc startTuple(writer: _writeType, size: int) throws {
    }
    @chpldoc.nodoc
    proc endTuple(writer: _writeType) throws {
    }

    // List helpers
    // TODO: Support for unknown sizes
    @chpldoc.nodoc
    proc startList(writer: _writeType, size: uint) throws {
      writer.write(size);
    }
    @chpldoc.nodoc
    proc writeListElement(writer: _writeType, const val: ?) throws {
      writer.write(val);
    }
    @chpldoc.nodoc
    proc endList(writer: _writeType) throws {
    }

    // Array helpers
    @chpldoc.nodoc
    proc startArray(writer: _writeType, size: uint) throws {
    }
    @chpldoc.nodoc
    proc startArrayDim(writer: _writeType, size: uint) throws {
    }
    @chpldoc.nodoc
    proc endArrayDim(writer: _writeType) throws {
    }

    @chpldoc.nodoc
    proc writeArrayElement(writer: _writeType, const val: ?) throws {
      writer.write(val);
    }

    @chpldoc.nodoc
    proc writeBulkElements(writer: _writeType, data: c_ptr(?eltType), numElements: uint) throws
    where isNumericType(eltType) {
      const n = c_sizeof(eltType)*numElements;
      writer.writeBinary(data, n.safeCast(int));
    }

    @chpldoc.nodoc
    proc endArray(writer: _writeType) throws {
    }

    // Map helpers
    @chpldoc.nodoc
    proc startMap(writer: _writeType, size: uint) throws {
      writer.write(size);
    }

    @chpldoc.nodoc
    proc writeKey(writer: _writeType, const key: ?) throws {
      writer.write(key);
    }

    @chpldoc.nodoc
    proc writeValue(writer: _writeType, const val: ?) throws {
      writer.write(val);
    }

    @chpldoc.nodoc
    proc endMap(writer: _writeType) throws {
    }
  }

  class _ReadTable {
    var table : map(int, unmanaged RootClass?);

    proc seen(id) : bool {
      return table.contains(id);
    }

    proc add(id, obj) {
      table.add(id, obj);
    }

    proc get(id) {
      var ret = try! table[id];
      return ret;
    }
  }

  record StrictBinaryDeserializer {
    const endian : IO.ioendian = IO.ioendian.native;
    var table : shared _ReadTable = new shared _ReadTable();

    @chpldoc.nodoc
    var _numElements : uint;

    proc init(endian: IO.ioendian = IO.ioendian.native) {
      this.endian = endian;
      this.complete();
    }

    @chpldoc.nodoc
    proc _fork() {
      var ret = new StrictBinaryDeserializer(endian=endian);
      ret.table = table;
      return ret;
    }

    // TODO: rewrite in terms of writef, or something
    @chpldoc.nodoc
    proc _oldRead(ch: _readerType, ref val:?t) throws {
      var _def = new DefaultDeserializer();
      var dc = ch.withDeserializer(_def);
      var st = dc._styleInternal();
      var orig = st; defer { dc._set_styleInternal(orig); }

      st.binary = 1;
      st.byteorder = 1 + endian:uint(8);
      st.str_style = stringStyleWithVariableLength():int(64);

      dc._set_styleInternal(st);
      dc._readOne(dc.kind, val, here);
    }

    proc deserializeType(reader:_readerType, type readType) : readType throws {
      if isClassType(readType) {
        const notNil = reader.readByte();
        if notNil == 0 {
          if isNilableClassType(readType) then
            return nil:readType;
          else
            throw new BadFormatError("cannot read nil class into non-nilable class");
        } else if notNil != 1 {
          throw new BadFormatError("invalid binary format found for class nilability");
        }
        // else: not nil, proceed to try initializing
      }

      if isNumericType(readType) {
        var x : readType;
        var ret : bool;
        select endian {
          when ioendian.native do ret = reader.readBinary(x, ioendian.native);
          when ioendian.little do ret = reader.readBinary(x, ioendian.little);
          when ioendian.big    do ret = reader.readBinary(x, ioendian.big);
        }
        if !ret then
          throw new EofError();
        else
          return x;
      } else if isBoolType(readType) ||
                isEnumType(readType) || isStringType(readType) ||
                isBytesType(readType) {
        var x : readType;
        _oldRead(reader, x);
        return x;
      } else if readType == nothing {
        // nothing...
      } else if canResolveTypeMethod(readType, "deserializeFrom", reader, this) ||
                isArrayType(readType) {
        var alias = reader.withDeserializer(_fork());
        return readType.deserializeFrom(reader=alias, deserializer=alias.deserializer);
      } else {
        var idOnly = false;
        var id : int;
        if isClassType(readType) {
          idOnly = reader.readByte() == 1;
          id = reader.read(int);
          if idOnly {
            writeln("cached!");
            var unm = table.get[id];
            return new _shared(unm!):readType;
          }
        }

        var alias = reader.withDeserializer(_fork());
        var ret = new readType(reader=alias, deserializer=alias.deserializer);

        if isClassType(readType) && !idOnly {
          table.add(id, _to_unmanaged(ret));
        }

        return ret;
      }
    }

    proc deserializeValue(reader: _readerType, ref val: ?readType) : void throws {
      if canResolveMethod(val, "deserialize", reader, this) {
        var alias = reader.withDeserializer(_fork());
        val.deserialize(reader=alias, deserializer=alias.deserializer);
      } else {
        val = deserializeType(reader, readType);
      }
    }

    @chpldoc.nodoc
    proc deserializeField(reader: _readerType, name: string, type T) throws {
      return reader.read(T);
    }

    // Class helpers
    @chpldoc.nodoc
    proc startClass(reader: _readerType, name: string) throws {
    }
    @chpldoc.nodoc
    proc endClass(reader: _readerType) throws {
    }

    // Record helpers
    @chpldoc.nodoc
    proc startRecord(reader: _readerType, name: string) throws {
    }
    @chpldoc.nodoc
    proc endRecord(reader: _readerType) throws {
    }

    // Tuple helpers
    @chpldoc.nodoc
    proc startTuple(reader: _readerType) throws {
    }
    @chpldoc.nodoc
    proc endTuple(reader: _readerType) throws {
    }

    // List helpers
    @chpldoc.nodoc
    proc startList(reader: _readerType) throws {
      _numElements = reader.read(uint);
    }
    @chpldoc.nodoc
    proc readListElement(reader: _readerType, type eltType) throws {
      if _numElements <= 0 then
        throw new BadFormatError("no more list elements remain");

      _numElements -= 1;

      return reader.read(eltType);
    }
    @chpldoc.nodoc
    proc endList(reader: _readerType) throws {
      if _numElements != 0 then
        throw new BadFormatError("read too few elements for list");
    }

    // Array helpers
    @chpldoc.nodoc
    proc startArray(reader: _readerType) throws {
    }

    @chpldoc.nodoc
    proc startArrayDim(reader: _readerType) throws {
    }
    @chpldoc.nodoc
    proc endArrayDim(reader: _readerType) throws {
    }

    @chpldoc.nodoc
    proc readArrayElement(reader: _readerType, type eltType) throws {
      _numElements -= 1;
      return reader.read(eltType);
    }

    @chpldoc.nodoc
    proc readBulkElements(reader: _readerType, data: c_ptr(?eltType), numElements: uint) throws
    where isNumericType(eltType) {
      const n = c_sizeof(eltType)*numElements;
      const got = reader.readBinary(data, n.safeCast(int));
      if got < n then throw new EofError();
      else _numElements -= numElements;
    }

    @chpldoc.nodoc
    proc endArray(reader: _readerType) throws {
    }

    // Map helpers
    @chpldoc.nodoc
    proc startMap(reader: _readerType) throws {
      _numElements = reader.read(uint);
    }

    @chpldoc.nodoc
    proc readKey(reader: _readerType, type keyType) throws {
      if _numElements <= 0 then
        throw new BadFormatError("no more map elements remain!");

      _numElements -= 1;

      return reader.read(keyType);
    }

    @chpldoc.nodoc
    proc readValue(reader: _readerType, type valType) throws {
      return reader.read(valType);
    }

    @chpldoc.nodoc
    proc endMap(reader: _readerType) throws {
      if _numElements != 0 then
        throw new BadFormatError("failed to read all expected elements in map");
    }
  }
}
