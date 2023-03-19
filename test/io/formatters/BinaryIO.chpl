
module BinaryIO {
  private use IO;
  private use CTypes;
  private use Map;
  private use List;

  // Question:
  // - should we implement these things in a single type for brevity?

  // TODO: would it be possible to handle the weird nested inheritance stuff
  // if we returned a type from 'startType' ?
  // Also important to recognize that the current mechanism would break
  // down if used afterward...

  // TODO: how to allow for optimized bulk-reads or writes of arrays?
  // - pass in a ref to something that can be memcpy'd ?
  //   - guarded by a config param method on the (de)serializer?
  //   - defined to do the same thing as a series of readArrayElements?
  // - or should this be handled by the particular format?

  // TODO: Should endianness be param? Or did Michael just want to know if
  // something was a kind of binary format at compile-time?

  // TODO: use IO.ioendian

  // TODO: Right now this is a very homebrew format, but we should switch to
  // something more standard...

  type _writeType = fileWriter(serializerType=BinarySerializer, ?);
  type _readerT = fileReader(deserializerType=BinaryDeserializer, ?);

  record BinarySerializer {
    const endian : IO.ioendian = IO.ioendian.native;

    // TODO: rewrite in terms of writef, or something
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

    proc encode(writer: _writeType, const x:?t) throws {
      if t == string  || isEnumType(t) || t == bytes || isNumericType(t) ||
         isBoolType(t) {
        _oldWrite(writer, x);
      } else if isClassType(t) {
        if x == nil {
          writer.writeByte(0);
        } else {
          writer.writeByte(1);
          x!.encodeTo(writer.withSerializer(new BinarySerializer()));
        }
      } else {
        x.encodeTo(writer.withSerializer(new BinarySerializer()));
      }
    }

    proc writeField(writer: _writeType, key: string, const val: ?T) throws {
      writer.write(val);
    }

    proc writeTypeStart(writer: _writeType, type T) throws {
    }

    proc writeTypeEnd(writer: _writeType, type T) throws {
    }

    // TODO: I think we should just embed some kind of dimensionality into
    // this. If people want a 1D thing then that will be easy.
    proc writeArrayStart(w: _writeType) throws {
    }

    // TODO: I sort of feel like we should print associative arrays/domains as
    // proper json maps, rather than an array of elements.....
    proc writeArrayElement(w: _writeType, const idx: ?, const val: ?) throws {
      w.write(idx);
      w.write(val);
    }

    proc writeArrayEnd(w: _writeType) throws {
    }

    proc writeMapStart(w: _writeType) throws {
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

    proc decode(reader:fileReader, type readType) : readType throws {
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
      } else if canResolveTypeMethod(readType, "decodeFrom", reader) ||
                isArrayType(readType) {
        return readType.decodeFrom(reader.withDeserializer(new BinaryDeserializer()));
      } else {
        return new readType(reader.withDeserializer(new BinaryDeserializer()));
      }
    }

    proc readField(r: _readerT, key: string, type T) throws {
      return r.read(T);
    }

    proc readTypeStart(r: fileReader, type T) throws {
    }

    proc readTypeEnd(r: fileReader, type T) throws {
    }

    proc readArrayStart(r: fileReader) throws {
    }

    proc readArrayElement(r: fileReader, type idxType, type eltType) throws {
      return (r.read(idxType), r.read(eltType));
    }

    proc readArrayEnd(r: fileReader) throws {
    }

    proc readMapStart(r: fileReader) throws {
    }

    proc readMapPair(r: fileReader, type keyType, type valType) throws {
      return (r.read(keyType), r.read(valType));
    }
  }
}
