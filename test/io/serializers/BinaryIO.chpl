
module BinaryIO {
  private use IO;
  private use CTypes;
  private use Map;
  private use List;
  private use Types;

  // TODO: should we implement these things in a single type for brevity?
  // TODO: Should endianness be param?
  // TODO: Right now this is a very homebrew format, but we should switch to
  //       something more standard...

  type _writeType = fileWriter(serializerType=BinarySerializer, ?);
  type _readerT = fileReader(deserializerType=BinaryDeserializer, ?);

  record BinarySerializer {
    const endian : IO.ioendian = IO.ioendian.native;
    var _size: uint;

    proc _fork() {
      return new BinarySerializer(endian=endian);
    }

    // TODO: rewrite in terms of writef, or something
    // Uses old 'iostyle' for now so that I don't have to think about 'writef'
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

    proc serialize(writer: _writeType, const x:?t) throws {
      if t == string  || isEnumType(t) || t == bytes || isNumericType(t) ||
         isBoolType(t) {
        _oldWrite(writer, x);
      } else if t == nothing {
        // nothing...
      } else if isClassType(t) {
        if x == nil {
          writer.writeByte(0);
        } else {
          writer.writeByte(1);
          var alias = writer.withSerializer(_fork());
          x!.serialize(writer=alias, serializer=alias.serializer);
        }
      } else {
        var alias = writer.withSerializer(_fork());
        x.serialize(writer=alias, serializer=alias.serializer);
      }
    }

    proc serializeField(writer: _writeType, key: string, const val: ?T) throws {
      writer.write(val);
    }

    // TODO: what if this returned a new 'Serializer' instead?
    // var sw = writer.serializer.startClass(writer, 4);
    // super.serialize(sw, sw.serializer);
    // ref ser = sw.serializer;
    // ser.serializeField(...);
    // ser.endType(writer, T);
    proc startClass(writer: _writeType, size: int) throws {
    }
    proc endClass(writer: _writeType) throws {
    }

    proc startRecord(writer: _writeType, size: int) throws {
    }
    proc endRecord(writer: _writeType) throws {
    }

    proc startTuple(writer: _writeType, size: int) throws {
    }
    proc endTuple(writer: _writeType) throws {
    }

    proc writeArrayStart(w: _writeType) throws {
      throw new Error("arrays of unknown size are not yet supported by BinarySerializer");
    }

    proc writeArrayStart(w: _writeType, size: uint) throws {
      w.write(size);
      _size = size;
    }

    proc writeArrayElement(w: _writeType, const idx: ?, const val: ?) throws {
      // TODO: validate number of elements being written...
      w.write(idx);
      w.write(val);
    }

    proc writeBulkElements(w: _writeType, data: c_ptr(?eltType), numElements: uint) throws
    where isNumericType(eltType) {
      if numElements > _size then throw new IllegalArgumentError("len", "Cannot write more elements than specified in 'writeArrayStart'");
      const n = c_sizeof(eltType)*numElements;
      w.writeBinary(data, n.safeCast(int));
    }

    proc writeArrayEnd(w: _writeType) throws {
    }

    proc writeMapStart(w: _writeType) throws {
      throw new Error("maps of unknown size are not yet supported by BinarySerializer");
    }

    proc writeMapStart(w: _writeType, size: uint) throws {
      w.write(size);
      _size = size;
    }

    proc writeMapPair(w: _writeType, const key: ?, const val: ?) throws {
      w.write(key);
      w.write(val);
    }

    proc writeMapEnd(w: _writeType) throws {
    }
  }

  record BinaryDeserializer {
    const endian : IO.ioendian = IO.ioendian.native;

    var _sizeKnown : bool = false;
    var _numElements : uint;

    proc init(endian: IO.ioendian = IO.ioendian.native) {
      this.endian = endian;
      this.complete();
    }

    proc _fork() {
      return new BinaryDeserializer(endian=endian);
    }

    // TODO: rewrite in terms of writef, or something
    proc _oldRead(ch: _readerT, ref val:?t) throws {
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

    proc deserialize(reader:fileReader, type readType) : readType throws {
      if isClassType(readType) {
        const notNil = reader.readByte();
        if notNil == 0 {
          if isNilableClassType(readType) then
            return nil:readType;
          else
            throw new Error("cannot read nil class into non-nilable class");
        } else if notNil != 1 {
          throw new BadFormatError("invalid binary format for class nilability");
        }
        // else: not nil, proceed to try initializing
      }

      if isNumericType(readType) || isBoolType(readType) ||
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
        var alias = reader.withDeserializer(_fork());
        return new readType(reader=alias, deserializer=alias.deserializer);
      }
    }

    proc deserializeField(r: _readerT, key: string, type T) throws {
      return r.read(T);
    }

    proc startClass(r: fileReader, size: int) throws {
    }
    proc endClass(r: fileReader) throws {
    }

    proc startRecord(r: fileReader, size: int) throws {
    }
    proc endRecord(r: fileReader) throws {
    }

    proc startTuple(r: fileReader, size: int) throws {
    }
    proc endTuple(r: fileReader) throws {
    }

    // TODO: add stuff for known sizes, size 'hints'
    // TODO: add support for 'hasNext' kind of thing
    //
    // LATER:
    // - TODO: support for unknown size
    //   - idea: serialize into internal buffer, count calls, then actually write things
    // - TODO: check size mismatches
    proc readArrayStart(r: fileReader) throws {
      _numElements = r.read(uint);
      _sizeKnown = _numElements != 0;
    }

    proc readArrayElement(r: fileReader, type idxType, type eltType) throws {
      if _sizeKnown && _numElements <= 0 then
        throw new BadFormatError("no more array elements remain!");

      if _sizeKnown then _numElements -= 1;
      return (r.read(idxType), r.read(eltType));
    }

    proc readBulkElements(r: fileReader, data: c_ptr(?eltType), numElements: uint) throws
    where isNumericType(eltType) {
      const n = c_sizeof(eltType)*numElements;
      const got = r.readBinary(data, n.safeCast(int));
      if got < n then throw new UnexpectedEofError();
      else _numElements -= numElements;
    }

    proc readArrayEnd(r: fileReader) throws {
      if _sizeKnown && _numElements != 0 then
        throw new Error("failed to read all expected elements in array!");
    }

    proc readMapStart(r: fileReader) throws {
      _sizeKnown = true;
      _numElements = r.read(uint);
    }

    proc readMapPair(r: fileReader, type keyType, type valType) throws {
      if _numElements <= 0 then
        throw new BadFormatError("no more map elements remain!");

      _numElements -= 1;
      return (r.read(keyType), r.read(valType));
    }

    proc readMapEnd(r: fileReader) throws {
      if _numElements != 0 then
        throw new Error("failed to read all expected elements in map!");
    }
  }
}
