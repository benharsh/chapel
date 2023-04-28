
module ChplFormat {
  private use IO;
  private use CTypes;
  private use Map;
  private use List;

  type _writeType = fileWriter(serializerType=ChplSerializer, ?);
  type _readerT = fileReader(deserializerType=ChplDeserializer, ?);

  record ChplSerializer {
    var firstField = true;
    var _inheritLevel = 0;
    var _arrayDim = 0;
    var _arrayMax = 0;
    var _arrayFirst : list(bool);
    var _typename : string;

    proc type isBinary() param : bool do return false;
    proc isBinary() param : bool do return false;

    // TODO: rewrite in terms of writef, or something
    proc _oldWrite(ch: _writeType, const val:?t) throws {
      var _def = new DefaultSerializer();
      var dc = ch.withSerializer(_def);
      var st = dc._styleInternal();
      var orig = st; defer { dc._set_styleInternal(orig); }
      st.realfmt = 2;
      st.string_format = iostringformat.chpl:uint(8);
      st.aggregate_style = QIO_AGGREGATE_FORMAT_CHPL:uint(8);
      st.array_style = QIO_ARRAY_FORMAT_CHPL:uint(8);
      st.tuple_style = QIO_TUPLE_FORMAT_CHPL:uint(8);
      st.pad_char = 0x20;
      dc._set_styleInternal(st);
      dc._writeOne(dc.kind, val, here);
    }

    proc serialize(writer: _writeType, const x:?t) throws {
      if t == string  || isEnumType(t) || t == bytes {
        _oldWrite(writer, x);
        //writer.writeLiteral('"');
        //writer.withSerializer(DefaultSerializer).write(x);
        //writer.writeLiteral('"');
      } else if isNumericType(t) || isBoolType(t) {
        _oldWrite(writer, x);
      } else if isClassType(t) {
        if x == nil {
          writer._writeLiteral("nil");
        } else {
          var alias = writer.withSerializer(new ChplSerializer(_typename=t:string));
          x!.serialize(writer=alias, serializer=alias.serializer);
        }
      } else {
        var alias = writer.withSerializer(new ChplSerializer(_typename=t:string));
        x.serialize(writer=alias, serializer=alias.serializer);
      }
    }

    proc serializeField(writer: _writeType, key: string, const val: ?T) throws {
      if !firstField then
        writer.writeLiteral(", ");

      if !key.isEmpty() {
        writer.writeLiteral(key);
        writer.writeLiteral(" = ");
      }

      writer.write(val);
      firstField = false;
    }

    // TODO: How should generic types be printed?
    proc startClass(writer: _writeType, size: int) throws {
      if _inheritLevel == 0 {
        writer._writeLiteral("new ");
        writer._writeLiteral(_typename);
        writer.writeLiteral("(");
      }

      _inheritLevel += 1;
    }
    proc endClass(writer: _writeType) throws {
      if _inheritLevel == 1 {
        writer.writeLiteral(")");
      }

      _inheritLevel -= 1;
    }

    proc startRecord(writer: _writeType, size: int) throws {
      writer._writeLiteral("new ");
      writer._writeLiteral(_typename);
      writer.writeLiteral("(");
    }
    proc endRecord(writer: _writeType) throws {
      writer.writeLiteral(")");
    }

    proc startTuple(writer: _writeType, size: int) throws {
      writer.writeLiteral("(");
    }
    proc endTuple(writer: _writeType) throws {
      writer.writeLiteral(")");
    }

    // TODO: I think we should just embed some kind of dimensionality into
    // this. If people want a 1D thing then that will be easy.
    proc writeArrayStart(w: _writeType, _size:uint = 0) throws {
      _arrayDim += 1;
      if _arrayFirst.size < _arrayDim {
        _arrayFirst.append(true);
      }

      if _arrayFirst[_arrayDim-1] {
        _arrayFirst[_arrayDim-1] = false;
      } else {
        w._writeLiteral(",");
      }

      _arrayMax = max(_arrayMax, _arrayDim);

      if _arrayDim > 1 {
        w.writeNewline();
        w.writeLiteral(" " * (_arrayDim-1));
      }
      w._writeLiteral("[");
    }

    // TODO: I sort of feel like we should print associative arrays/domains as
    // proper json maps, rather than an array of elements.....
    proc writeArrayElement(w: _writeType, const idx: ?, const val: ?) throws {
      if !firstField then
        w._writeLiteral(", ");
      else
        firstField = false;
      w.write(val);
    }

    proc writeArrayEnd(w: _writeType) throws {
      if _arrayDim < _arrayMax {
        w.writeNewline();
        w._writeLiteral(" " * (_arrayDim-1));
      }
      w._writeLiteral("]");

      if _arrayDim < _arrayFirst.size then
      _arrayFirst[_arrayDim] = true;

      _arrayDim -= 1;
      firstField = true;
    }

    proc writeMapStart(w: _writeType, _size:uint = 0) throws {
      w._writeLiteral("{");
    }

    proc writeMapPair(w: _writeType, const key: ?, const val: ?) throws {
      if !firstField {
        w._writeLiteral(", ");
        w.writeNewline();
        w._writeLiteral("  ");
      } else {
        w.writeNewline();
        w._writeLiteral("  ");
        firstField = false;
      }

      if key.type == string {
        w.write(key);
      } else {
        // Write the key as json, then turn it into a json string to use
        // it as a proper key for the map.
        var f = openMemFile();
        {
          f.writer().withSerializer(ChplSerializer).write(key);
        }
        var tmp : string;
        f.reader().readAll(tmp);
        w.write(tmp);
      }

      w._writeLiteral(": ");
      w.write(val);
    }

    proc writeMapEnd(w: _writeType) throws {
      w.writeNewline();
      w._writeLiteral("}");
    }
  }

  // TODO: out of order reading
  record ChplDeserializer {
    var _inheritLevel = 0;
    var _typename : string;

    var firstField = true;
    var _arrayDim = 0;
    var _arrayMax = 0;
    var _arrayFirst : list(bool);

    proc type isBinary() param : bool do return false;
    proc isBinary() param : bool do return false;

    // TODO: rewrite in terms of writef, or something
    proc _oldRead(ch: _readerT, ref val:?t) throws {
      var _def = new DefaultDeserializer();
      var dc = ch.withDeserializer(_def);
      var st = dc._styleInternal();
      var orig = st; defer { dc._set_styleInternal(orig); }
      st.realfmt = 2;
      st.string_format = iostringformat.chpl:uint(8);
      st.aggregate_style = QIO_AGGREGATE_FORMAT_CHPL:uint(8);
      st.array_style = QIO_ARRAY_FORMAT_CHPL:uint(8);
      st.tuple_style = QIO_TUPLE_FORMAT_CHPL:uint(8);
      st.pad_char = 0x20;
      dc._set_styleInternal(st);
      dc._readOne(dc.kind, val, here);
    }

    proc deserialize(reader:fileReader, type readType) : readType throws {
      if isNilableClassType(readType) && reader.matchLiteral("nil") {
        return nil:readType;
      }

      // TODO:
      // - escaped strings
      // - arrays/lists
      if isNumericType(readType) || isBoolType(readType) {
        var x : readType;
        reader._readOne(reader.kind, x, here);
        return x;
      } else if isStringType(readType) {
        var tmp : readType;
        //reader.readf("%{\"S\"}", tmp);
        _oldRead(reader, tmp);
        return tmp;
      } else if isEnumType(readType) {
        var ret = reader.withDeserializer(DefaultDeserializer).read(readType);
        return ret;
      } else if canResolveTypeMethod(readType, "deserializeFrom", reader) ||
                isArrayType(readType) {
        return readType.deserializeFrom(reader.withDeserializer(new ChplDeserializer(_typename=readType:string)));
      } else {
        var alias = reader.withDeserializer(new ChplDeserializer(_typename=readType:string));
        return new readType(reader=alias, deserializer=alias.deserializer);
      }
    }

    proc deserializeField(r: _readerT, key: string, type T) throws {
      if !firstField then
        r.readLiteral(",");
      firstField = false;

      if !key.isEmpty() {
        r.readLiteral(key);
        r.readLiteral("=");
      }
      return r.read(T);
    }

    proc startTuple(r: fileReader, size: int) throws {
      r.readLiteral("(");
    }
    proc endTuple(r: fileReader) throws {
      r.readLiteral(")");
    }

    proc startClass(r: fileReader, size: int) throws {
      _startComposite(r, size);
    }
    proc endClass(r: fileReader) throws {
      _endComposite(r);
    }

    proc startRecord(r: fileReader, size: int) throws {
      _startComposite(r, size);
    }
    proc endRecord(r: fileReader) throws {
      _endComposite(r);
    }

    proc _startComposite(r: fileReader, size: int) throws {
      if _inheritLevel == 0 {
        r.readLiteral("new " + _typename);
        r.readLiteral("(");
      }

      _inheritLevel += 1;
    }

    proc _endComposite(r: fileReader) throws {
      if _inheritLevel == 1 {
        r.readLiteral(")");
      }
      _inheritLevel -= 1;
    }

    proc readArrayStart(r: fileReader) throws {
      _arrayDim += 1;
      if _arrayFirst.size < _arrayDim {
        _arrayFirst.append(true);
      }

      if _arrayFirst[_arrayDim-1] {
        _arrayFirst[_arrayDim-1] = false;
      } else {
        r._readLiteral(",");
      }

      _arrayMax = max(_arrayMax, _arrayDim);

      // Don't need to read the newline and pretty-printed spaces, as JSON
      // arrays can come in other forms. Relies on 'readLiteral' ignoring
      // whitespace by default.
      r._readLiteral("[");
    }

    proc readArrayElement(r: fileReader, type idxType, type eltType) throws {
      if !firstField then
        r._readLiteral(", ");
      else
        firstField = false;
      return (none, r.read(eltType));
    }

    proc readArrayEnd(r: fileReader) throws {
      if _arrayDim < _arrayMax {
        r.readNewline();
        r._readLiteral(" " * (_arrayDim-1));
      }

      // Don't need to read the newline and pretty-printed spaces, as JSON
      // arrays can come in other forms. Relies on 'readLiteral' ignoring
      // whitespace by default.
      r._readLiteral("]");

      if _arrayDim < _arrayFirst.size then
        _arrayFirst[_arrayDim] = true;

      _arrayDim -= 1;
      firstField = true;
    }

    proc readMapStart(r: fileReader) throws {
      r._readLiteral("{");
    }

    // TODO: don't need to always read the spaces after commas...
    proc readMapPair(r: fileReader, type keyType, type valType) throws {
      if !firstField {
        r._readLiteral(",");
      } else {
        firstField = false;
      }

      if keyType == string {
        var k = r.read(string);
        r._readLiteral(":");
        return (k, r.read(valType));
      } else {
        var f = openMemFile();
        var s = r.read(string);
        {
          f.writer().withSerializer(DefaultSerializer).write(s);
        }
        var k = f.reader().withDeserializer(ChplDeserializer).read(keyType);
        r._readLiteral(":");
        return (k, r.read(valType));
      }
    }

    proc readMapEnd(r: fileReader) throws {
      r._readLiteral("}");
    }
  }
}
