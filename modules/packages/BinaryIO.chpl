/*
 * Copyright 2021-2023 Hewlett Packard Enterprise Development LP
 * Other additional copyright holders may be indicated within.
 *
 * The entirety of this work is licensed under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except
 * in compliance with the License.
 *
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 The BinaryIO module provides a BinarySerializer and BinaryDeserializer that
 implement a simple binary IO format.
 */
@unstable("BinaryIO module is considered unstable pending naming changes")
module BinaryIO {
  private use IO;
  private use CTypes;
  private use Map;
  private use List;
  private use Types;

  // TODO: Document format

  @chpldoc.nodoc
  type _writeType = fileWriter(serializerType=BinarySerializer, ?);
  @chpldoc.nodoc
  type _readerType = fileReader(deserializerType=BinaryDeserializer, ?);

  record BinarySerializer {
    const endian : IO.ioendian = IO.ioendian.native;

    // TODO: We could store a 'size' field internally to track the expected
    // number of fields or elements, and throw errors if that expectation is
    // violated.

    @chpldoc.nodoc
    proc _fork() {
      return new BinarySerializer(endian=endian);
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
        //
        // TODO: Should 'startClass' handle this case?
        if val == nil {
          writer.writeByte(0);
        } else {
          writer.writeByte(1);
          var alias = writer.withSerializer(_fork());
          val!.serialize(writer=alias, serializer=alias.serializer);
        }
      } else {
        var alias = writer.withSerializer(_fork());
        val.serialize(writer=alias, serializer=alias.serializer);
      }
    }

    record AggregateSerializer {
      var writer;

      @chpldoc.nodoc
      proc serializeField(name: string, const val: ?T) throws {
        writer.write(val);
      }
      @chpldoc.nodoc
      proc endClass() throws {
      }
      @chpldoc.nodoc
      proc endRecord() throws {
      }
    }

    // Class helpers
    @chpldoc.nodoc
    proc startClass(writer: _writeType, name: string, size: int) throws {
      return new AggregateSerializer(writer);
    }

    // Record helpers
    @chpldoc.nodoc
    proc startRecord(writer: _writeType, name: string, size: int) throws {
      return new AggregateSerializer(writer);
    }

    record TupleSerializer {
      var writer;

      proc writeElement(const val: ?T) throws {
        writer.write(val);
      }
      @chpldoc.nodoc
      proc endTuple() throws {
      }
    }

    // Tuple helpers
    @chpldoc.nodoc
    proc startTuple(writer: _writeType, size: int) throws {
      return new TupleSerializer(writer);
    }

    record ListSerializer {
      var writer;

      @chpldoc.nodoc
      proc writeElement(const val: ?) throws {
        writer.write(val);
      }
      @chpldoc.nodoc
      proc endList() throws {
      }
    }

    // List helpers
    // TODO: Support for unknown sizes
    @chpldoc.nodoc
    proc startList(writer: _writeType, size: uint) throws {
      writer.write(size);
      return new ListSerializer(writer);
    }

    record ArraySerializer {
      var writer;

      @chpldoc.nodoc
      proc startDim(size: uint) throws {
      }
      @chpldoc.nodoc
      proc endDim() throws {
      }

      @chpldoc.nodoc
      proc writeElement(const val: ?) throws {
        writer.write(val);
      }

      @chpldoc.nodoc
      proc writeBulkElements(data: c_ptr(?eltType), numElements: uint) throws
      where isNumericType(eltType) {
        const n = c_sizeof(eltType)*numElements;
        writer.writeBinary(data, n.safeCast(int));
      }

      @chpldoc.nodoc
      proc endArray() throws {
      }
    }

    // Array helpers
    @chpldoc.nodoc
    proc startArray(writer: _writeType, size: uint) throws {
      return new ArraySerializer(writer);
    }

    record MapSerializer {
      var writer;

      @chpldoc.nodoc
      proc writeKey(const key: ?) throws {
        writer.write(key);
      }

      @chpldoc.nodoc
      proc writeValue(const val: ?) throws {
        writer.write(val);
      }

      @chpldoc.nodoc
      proc endMap() throws {
      }
    }

    // Map helpers
    @chpldoc.nodoc
    proc startMap(writer: _writeType, size: uint) throws {
      writer.write(size);
      return new MapSerializer(writer);
    }
  }

  record BinaryDeserializer {
    const endian : IO.ioendian = IO.ioendian.native;

    @chpldoc.nodoc
    var _numElements : uint;

    proc init(endian: IO.ioendian = IO.ioendian.native) {
      this.endian = endian;
      this.complete();
    }

    @chpldoc.nodoc
    proc _fork() {
      return new BinaryDeserializer(endian=endian);
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
        var alias = reader.withDeserializer(_fork());
        return new readType(reader=alias, deserializer=alias.deserializer);
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

    record AggregateDeserializer {
      var reader;

      @chpldoc.nodoc
      proc deserializeField(name: string, type T) throws {
        return reader.read(T);
      }
      @chpldoc.nodoc
      proc endClass() throws {
      }
      @chpldoc.nodoc
      proc endRecord() throws {
      }
    }

    // Class helpers
    @chpldoc.nodoc
    proc startClass(reader: _readerType, name: string) throws {
      return new AggregateDeserializer(reader);
    }

    // Record helpers
    @chpldoc.nodoc
    proc startRecord(reader: _readerType, name: string) throws {
      return new AggregateDeserializer(reader);
    }

    record TupleDeserializer {
      var reader;

      proc readElement(type T) throws {
        return reader.read(T);
      }

      @chpldoc.nodoc
      proc endTuple() throws {
      }
    }

    // Tuple helpers
    @chpldoc.nodoc
    proc startTuple(reader: _readerType) throws {
      return new TupleDeserializer(reader);
    }

    record ListDeserializer {
      var reader;
      var _numElements : uint;

      @chpldoc.nodoc
      proc readElement(type eltType) throws {
        if _numElements <= 0 then
          throw new BadFormatError("no more list elements remain");

        _numElements -= 1;

        return reader.read(eltType);
      }
      @chpldoc.nodoc
      proc endList() throws {
        if _numElements != 0 then
          throw new BadFormatError("read too few elements for list");
      }
    }

    // List helpers
    @chpldoc.nodoc
    proc startList(reader: _readerType) throws {
      return new ListDeserializer(reader, reader.read(uint));
    }

    record ArrayDeserializer {
      var reader;

      @chpldoc.nodoc
      proc startDim() throws {
      }
      @chpldoc.nodoc
      proc endDim() throws {
      }

      @chpldoc.nodoc
      proc readElement(type eltType) throws {
        return reader.read(eltType);
      }

      @chpldoc.nodoc
      proc readBulkElements(data: c_ptr(?eltType), numElements: uint) throws
      where isNumericType(eltType) {
        const n = c_sizeof(eltType)*numElements;
        const got = reader.readBinary(data, n.safeCast(int));
        if got < n then throw new EofError();
      }

      @chpldoc.nodoc
      proc endArray() throws {
      }
    }

    // Array helpers
    @chpldoc.nodoc
    proc startArray(reader: _readerType) throws {
      return new ArrayDeserializer(reader);
    }

    record MapDeserializer {
      var reader;
      var _numElements : uint;

      @chpldoc.nodoc
      proc readKey(type keyType) throws {
        if _numElements <= 0 then
          throw new BadFormatError("no more map elements remain!");

        _numElements -= 1;

        return reader.read(keyType);
      }

      @chpldoc.nodoc
      proc readValue(type valType) throws {
        return reader.read(valType);
      }

      @chpldoc.nodoc
      proc endMap() throws {
        if _numElements != 0 then
          throw new BadFormatError("failed to read all expected elements in map");
      }
    }

    // Map helpers
    @chpldoc.nodoc
    proc startMap(reader: _readerType) throws {
      return new MapDeserializer(reader, reader.read(uint));
    }

  }
}
