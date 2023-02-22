
module Json {
  private use IO;
  private use CTypes;
  private use Map;
  private use List;

  type _writeType = fileWriter(fmtType=JsonWriter, ?);
  type _readerT = fileReader(fmtType=JsonReader, ?);
  record JsonWriter {
    var firstField = true;
    var _inheritLevel = 0;
    var _arrayDim = 0;
    var _arrayMax = 0;
    var _arrayFirst : list(bool);

    // TODO: rewrite in terms of writef, or something
    proc _oldWrite(ch: _writeType, const val:?t) throws {
      var _def = new DefaultWriter();
      var dc = ch.withFormatter(_def);
      var st = dc._styleInternal();
      var orig = st; defer { dc._set_styleInternal(orig); }
      st.realfmt = 2;
      st.string_format = iostringformat.json:uint(8);
      st.aggregate_style = QIO_AGGREGATE_FORMAT_JSON:uint(8);
      st.array_style = QIO_ARRAY_FORMAT_JSON:uint(8);
      st.tuple_style = QIO_TUPLE_FORMAT_JSON:uint(8);
      dc._set_styleInternal(st);
      dc._writeOne(dc.kind, val, here);
    }

    proc encode(writer: _writeType, const x:?t) throws {
      if t == string  || isEnumType(t) || t == bytes {
        writer.writeLiteral('"');
        writer.withFormatter(DefaultWriter).write(x);
        writer.writeLiteral('"');
      } else if isNumericType(t) || isBoolType(t) {
        _oldWrite(writer, x);
      } else if t == ioLiteral {
        writer._writeLiteral(x.val);
      } else if t == ioNewline {
        // TODO: Need to account for 'skipWhitespaceOnly' somehow...
        writer._writeOne(writer.kind, x, writer.getLocaleOfIoRequest());
      } else if isClassType(t) {
        if x == nil {
          writer._writeLiteral("null");
        } else {
          x!.encodeTo(writer.withFormatter(new JsonWriter()));
        }
      } else {
        x.encodeTo(writer.withFormatter(new JsonWriter()));
      }
    }

    proc writeField(writer: _writeType, key: string, const val: ?T) throws {
      if !firstField then
        writer.writeLiteral(", ");

      if !key.isEmpty() {
        writer.write(key);
        writer.writeLiteral(":");
      }

      writer.write(val);
      firstField = false;
    }

    proc writeTypeStart(writer: _writeType, type T) throws {
      if _inheritLevel == 0 {
        if isClassType(T) || isRecordType(T) {
          writer.writeLiteral("{");
        } else if isTupleType(T) {
          writer.writeLiteral("[");
        }
      }

      _inheritLevel += 1;
    }

    proc writeTypeEnd(writer: _writeType, type T) throws {
      if _inheritLevel == 1 {
        if isClassType(T) || isRecordType(T) {
          writer.writeLiteral("}");
        } else if isTupleType(T) {
          writer.writeLiteral("]");
        }
      }

      _inheritLevel -= 1;
    }

    // TODO: I think we should just embed some kind of dimensionality into
    // this. If people want a 1D thing then that will be easy.
    proc writeArrayStart(w: _writeType) throws {
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

    proc writeMapStart(w: _writeType) throws {
      w._writeLiteral("{");
    }

    // Alternative
    proc writeMapPair(w: _writeType, const key: ?, const val: ?) throws {
      if !firstField then
        w._writeLiteral(", ");
      else
        firstField = false;

      // Need a way to tell json to escape the following strings quotes...
      if key.type == string {
        w.write(key);
      } else {
        w._writeLiteral('"');
        w.write(key);
        w._writeLiteral('"');
      }
      w._writeLiteral(": ");
      w.write(val);
    }

    proc writeMapEnd(w: _writeType) throws {
      w._writeLiteral("}");
    }
  }

  private extern proc qio_channel_skip_json_field(threadsafe:c_int, ch:qio_channel_ptr_t):errorCode;

  private proc helper(reader: _readerT) throws {
    var m : map(string, int);
    reader.mark();

    reader.readLiteral("{");
    var done = false;
    var lastPos = -1;
    while !done {
      if reader.matchLiteral("}") {
        lastPos = reader.offset() - 1;
        done = true;
        break;
      }

      reader.mark();
      const name = reader.read(string);
      reader.readLiteral(":");
      m.add(name, reader.offset());
      reader.revert();

      qio_channel_skip_json_field(false, reader._channel_internal);
      reader.matchLiteral(",");
    }

    reader.revert();

    return (m, lastPos);
  }

  record JsonReader {
    var outOfOrder = false;
    var _inheritLevel = 0;
    var _names : domain(string);
    var _offsets : [_names] int;
    var _lastPos = -1;

    proc init() {
      this.complete();
    }

    proc decode(reader:fileReader, type readType) : readType throws {
      if isNilableClassType(readType) && reader.matchLiteral("null") {
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
        reader.readf("%{\"S\"}", tmp);
        return tmp;
      } else if isEnumType(readType) {
        reader.readLiteral('"');
        var ret = reader.withFormatter(DefaultReader).read(readType);
        reader.readLiteral('"');
        return ret;
      } else if canResolveTypeMethod(readType, "decodeFrom", reader) {
        return readType.decodeFrom(reader.withFormatter(new JsonReader()));
      } else {
        return new readType(reader.withFormatter(new JsonReader()));
      }
    }

    proc _readFieldName(r: _readerT, key: string) throws {
      try {
        r._readLiteral('"');
        r._readLiteral(key);
        r._readLiteral('"');
        r._readLiteral(":");
      } catch e: BadFormatError {
        return false;
      }

      return true;
    }


    proc readField(r: _readerT, key: string, type T) throws {
      if _names.contains(key) {
        r.seek(_offsets[key]..);
      } else if !key.isEmpty() {
        throw new Error("field not found...");
      }

      var ret = r.read(T);

      // note: trailing commas not allowed in json
      r.matchLiteral(",");

      return ret;
    }

    proc readTypeStart(r: fileReader, type T) throws {
      if _inheritLevel == 0 {
        if isClassType(T) || isRecordType(T) {
          //
          // TODO: When should we try to do this? Use of 'readTypeStart'
          // likely indicates "buying in" to the JSON format, but in a way
          // it might be cleaner or more efficient to do when creating the
          // new temporary JsonReader for the given type. But if we do the
          // JSON parsing at that point, it ignores the user-defined
          // initializer. So, we do it here in 'readTypeStart'.
          //
          // TODO: Should we only compute the mapping if the fields are being
          // read out of order?
          //
          var (m, last) = helper(r);
          for (k, v) in zip(m.keys(), m.values()) {
            _names.add(k);
            _offsets[k] = v;
          }
          _lastPos = last;
          r.readLiteral("{");
        } else if isTupleType(T) {
          r.readLiteral("[");
        }
      }

      _inheritLevel += 1;
    }

    proc readTypeEnd(r: fileReader, type T) throws {
      if _inheritLevel == 1 {
        if isClassType(T) || isRecordType(T) {
          r.seek(_lastPos..);
          r.readLiteral("}");
        } else if isTupleType(T) {
          r.readLiteral("]");
        }
      }
    }
  }
}
