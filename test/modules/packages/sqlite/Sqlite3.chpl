
//
// Future work:
// - Should we support arbitrary records as return-types from Statement.step() ?
//   What should happen if the number of fields and columns don't match?
//   Should we match fields and columns by name?
// - are we copying strings too much?
// - private initializers? I want users to use "Connection.open"
// - For now, disallow "[:@$]VVV" named bindings. We don't really have a good
//   way of passing an associative array right now, and "?" and ":NNN" seem to
//   be sufficient.
// - FTS support
// - Request: support for two varargs: vals..., type t...
// - query-building functions, like diesel or sqlite.swift
// - meta-info: table names, column names/types
//
// TODO:
// - Owned doesn't seem to forward errors...
// - Consider disallowing type varargs, would make api easier
// - Should all these types have a 'Sqlite' prefix?
// - standard module request: isCPtr
// - should --no-checks disable column idx bounds checks?
// - what should happen if we re-assign a statement?
// - Row["colName"], Row["n", type]
// - URI and other open flags
//
// TESTING:
// - how can we check for memory leaks? valgrind?
// - parallel safety?
// - multilocale?
// - in-memory database
// - Test possible type constraints:
//   - single type
//   - tuple of types
//   - varargs of types
//   - single SqliteRow
//   - tuple/varargs of SqliteValue?
//

module Sqlite3 {
  use _Sys;
  use OwnedObject;

  private proc isCPtr(type x) param where x:c_ptr return true;
  private proc isCPtr(type x) param return false;

  proc isValidSQLiteType(type t) param : bool {
    if isIntegralType(t) {
      return true; // INT
    } else if isReal(t) {
      return true; // REAL
    } else if isString(t) {
      return true; // TEST
    } else if isCPtr(t) || t == c_void_ptr {
      return true; // BLOB, NULL?
    }

    return false;
  }

  private proc isValidTypeTuple(type t) param : bool {
    if isTuple(t) {
      var dummy : t;
      for param i in 1..dummy.size {
        if isValidSQLiteType(t(i)) == false then return false;
      }
      return true;
    } else {
      return false;
    }
  }

  class SqliteError : Error {
    var msg : string;
    proc SqliteError(m : string) {
      msg = m;
    }
    proc message() {
      return msg;
    }
  }

  private proc checkResult(err : c_int, chan : c_ptr(sqlite3), msg = "") {
    if err != SQLITE_OK then try! {
      if msg != "" then stderr.writeln(msg);
      stderr.writeln("Error: ", sqlite3_errmsg(chan):string);
      exit(1);
    }
  }

  private proc nilString {
    var temp : c_string = _nullString;
    return temp;
  }

  private proc getColumn(stmt : c_ptr(sqlite3_stmt), idx : int, type t) throws {
    return getColumn(stmt, idx).get(t);
  }

  private proc getColumn(stmt : c_ptr(sqlite3_stmt), idx : int) throws {
    const i = idx:c_int;
    const numCols = sqlite3_column_count(stmt);
    if idx < 0 || idx > numCols then
      halt("idx out of bounds: [0, ", numCols, "]");
    const colType = sqlite3_column_type(stmt, i);
    if colType == SQLITE_INTEGER {
      return new SqliteValue(sqlite3_column_int(stmt, i):int);
    } else if colType == SQLITE_FLOAT {
      return new SqliteValue(sqlite3_column_double(stmt, i):real);
    } else if colType == SQLITE_TEXT {
      const ptr = sqlite3_column_text(stmt, i);
      return new SqliteValue(new string(ptr));
    } else if colType == SQLITE_BLOB {
      // TODO: This sqlite3 function returns 'const void *'. The backend
      // compiler will complain that we can't assign to c_void_ptr (void*).
      //
      //return new SqliteValue(sqlite3_column_blob(stmt, i));
      throw new SqliteError("Cannot handle BLOBs");
      return new SqliteValue();
    } else if colType == SQLITE_NULL {
      return new SqliteValue();
    } else {
      throw new SqliteError("Unhandled result from sqlite3_column_type");
      return new SqliteValue();
    }
  }

  class Connection {
    var chan : c_ptr(sqlite3);
    var _closed = false;

    proc type open(db : string, flags = iomode.r) {
      return new Owned(new Connection(db, flags));
    }

    proc init(db : string, flags:iomode) {
      var c_flags : int;
      if flags == iomode.r then c_flags = SQLITE_OPEN_READONLY;
      else if flags == iomode.rw then c_flags = SQLITE_OPEN_READWRITE;
      else if flags == iomode.cw then c_flags = SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE;
      else if flags == iomode.cwr then c_flags = SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE;

      // No VFS support for now.
      const err = sqlite3_open_v2(db.c_str(), chan, c_flags:c_int, nilString);
      const msg = "Unable to open database '" + db + "'.";
      checkResult(err, chan, msg);
    }

    proc _verify() throws {
      if _closed then throw new SqliteError("Attempted operation on closed Connection");
    }

    proc close() {
      if _closed == false {
        _closed = true;
        // Check if all statements, handles, etc are finalized?
        const err = sqlite3_close_v2(chan);
        checkResult(err, chan, "Failed to close connection.");
        chan = nil;
      }
    }

    proc deinit() {
      close();
    }

    proc prepare(sql : string) throws {
      _verify();
      return new Owned(new Statement(chan, sql, SqliteRow));
    }
    proc prepare(sql : string, type tup) throws {
      _verify();
      return new Owned(new Statement(chan, sql, tup));
    }
    proc prepare(sql : string, type typeTuple ...?z) throws where z > 1 {
      _verify();
      return new Owned(new Statement(chan, sql, typeTuple));
    }

    // execute(string, optional-vals) // execute arbitrary statement, bind with vals
    proc exec(sql : string) throws {
      _verify();
      prepare(sql).run();
    }
    proc exec(sql : string, vals...) throws {
      _verify();
      var s = prepare(sql);
      s.bind(vals);
      s.run();
    }

    // TODO: binds?
    iter rows(sql : string) throws {
      _verify();
      for r in rows(sql, SqliteRow) do
        yield r;
    }
    iter rows(sql : string, type t ...) throws where t.size > 1 {
      _verify();
      for r in rows(sql, t) do
        yield r;
    }
    iter rows(sql : string, type t) throws {
      var s = prepare(sql, t);
      for r in s {
        yield r;
      }
    }
    iter rows(sql : string, vals...?z) throws where z > 1 {
      _verify();
      for r in rows(sql, vals, SqliteRow) do yield r;
    }
    iter rows(sql : string, vals...?z, type t) throws where z > 1 {
      _verify();
      for r in rows(sql, vals, t) do yield r;
    }
    iter rows(sql : string, val) throws {
      _verify();
      for r in rows(sql, val, SqliteRow) do yield r;
    }
    iter rows(sql : string, vals, type t) throws {
      _verify();
      var stmt = prepare(sql, t);
      stmt.bind(vals);
      for r in stmt do yield r;
    }
  } // Connection

  private proc _getRetType(type t) type {
    // For now, disallow records
    if isValidTypeTuple(t) || isValidSQLiteType(t) || t == SqliteRow {
      return t;
    } else {
      compilerError("Unsupported SQLite type: ", t:string);
    }
  }

  //
  // Usage of 'step' is kinda weird. Let's step() in the initializer and cache
  // the result and error. then during the next step we can check the error,
  // step again, and return the old result. this should allow for more natural
  // usage of Statement.done:
  // while !stmt.done do stmt.step();
  //
  // TODO: meta-information: #columns, column types, print header
  //
  class Statement {
    type retType;
    var db : c_ptr(sqlite3);
    var stmt : c_ptr(sqlite3_stmt);
    var sql : string;
    var _numCols:int;

    proc init(chan : c_ptr(sqlite3), sql : string, type tup) {
      retType = _getRetType(tup);

      super.init();

      _common(chan, sql);
    }
    proc init(chan : c_ptr(sqlite3), sql : string, type typeTuple ...?z) where z > 1 {
      retType = _getRetType(typeTuple);

      super.init();

      _common(chan, sql);
    }

    proc _common(chan : c_ptr(sqlite3), sql : string) {
      this.db = chan;
      this.sql = sql;
      this._numCols = -1;
      var err = sqlite3_prepare_v2(db, this.sql.c_str(), -1, this.stmt, nil);
      checkResult(err, db);

      const numBinds = sqlite3_bind_parameter_count(stmt):int;
      for i in 1..numBinds {
        var name = sqlite3_bind_parameter_name(stmt, i:c_int):string;
        if name != "" && name.startsWith("?") == false {
          halt("Named parameters are not supported: '", name, "'");
        }
      }
    }

    proc numColumns() {
      if _numCols == -1 then
        _numCols = sqlite3_column_count(stmt):int;
      return _numCols;
    }

    proc _checkBind(n : int) throws {
      const numBinds = sqlite3_bind_parameter_count(stmt):int;
      if n != numBinds {
        const msg = "Expecting " + numBinds + ", got " + n;
        if n < numBinds then
          throw new SqliteError("Too few arguments passed to bind. " + msg);
        else
          throw new SqliteError("Too many arguments passeed to bind. " + msg);
      }
    }

    proc _internal_bind(val, idx) where isValidSQLiteType(val.type) {
      const _idx = idx:c_int;
      var err : c_int;
      if isIntegralType(val.type) {
        err = sqlite3_bind_int64(stmt, _idx, val);
      } else if isString(val.type) {
        err = sqlite3_bind_text(stmt, _idx, val);
      } else if isReal(val.type) {
        err = sqlite3_bind_double(stmt, _idx, val);
      } else {
        compilerError("Unhandled type: ", val.type:string);
      }
      checkResult(err, db);
    }

    proc bind(val) throws where !isTuple(val) {
      _checkBind(1);
      _internal_bind(val, 1);
      return this;
    }

    proc bind(vals) throws where isTuple(vals) {
      // TODO: do we need this anymore?
      const actuals = if isTuple(vals(1)) then vals(1) else vals;
      if isValidTypeTuple(actuals.type) == false then
        compilerError("Invalid tuple passed to bind: ", actuals.type:string);

      _checkBind(actuals.size);

      for param i in 1..actuals.size {
        _internal_bind(actuals(i), i);
      }
      return this;
    }
    proc bind(vals ...?k) throws where k > 1 {
      return bind(vals);
    }

    proc _fillResult(ref ret) throws where isTuple(ret) {
      for param i in 1..ret.size {
        ret(i) = getColumn(stmt, i-1, ret(i).type);
      }
    }
    proc _fillResult(ref ret : SqliteRow) throws {
      ret.clear();
      for i in 1..numColumns() {
        ret.append(getColumn(stmt, i-1));
      }
    }
    proc _fillResult(ref ret) throws {
      compilerError("Sqlite.Statement: Cannot populate result for type '", ret.type:string, "'");
    }

    // Step until statement is complete
    proc run() throws {
      var done = false;
      while done == false {
        const err = sqlite3_step(stmt);
        if err == SQLITE_DONE {
          done = true;
        } else if err != SQLITE_ROW {
          checkResult(err, db);
        }
      }
      reset(false);
    }
    proc run(vals ...?k) throws {
      bind(vals);
      run();
    }

    // TODO: some compiler issue with these(vals...). What if 'bind' returned
    // a Statement? for r in stmt.bind(...) do ...

    // TODO: too much copying here?
    iter these() throws {
      var done = false;
      var ret : retType;
      while done == false {
        const err = sqlite3_step(stmt);
        if err == SQLITE_ROW {
          _fillResult(ret);
          yield ret;
        } else if err == SQLITE_DONE {
          done = true;
        } else {
          checkResult(err, db);
        }
      }
      reset(false);
    }

    proc clearBindings() {
      const err = sqlite3_clear_bindings(stmt);
      checkResult(err, db);
    }

    proc reset(bindings = false) {
      const err = sqlite3_reset(stmt);
      checkResult(err, db);
      if bindings then clearBindings();
    }

    proc deinit() {
      // TODO: error checking?
      sqlite3_finalize(stmt);
    }
  }

  // stores type-less data
  record SqliteRow {
    var _valDom : domain(1);
    var _values : [_valDom] SqliteValue;
    proc clear() {
      _values.clear();
    }
    proc append(s : SqliteValue) {
      _values.push_back(s);
    }
    proc this(i) {
      return _values[i];
    }
    proc this(i, type t) {
      return _values[i].get(t);
    }
    iter these() {
      for v in _values do yield v;
    }
    proc writeThis(f) {
      try! {
        if _values.size == 0 {
          f.write("(<empty row>)");
        } else {
          f.write("(");
          var first = true;
          for v in _values {
            if first then first = false;
            else f.write(", ");
            f.write(v);
          }
          f.write(")");
        }
      }
    }
  }
  proc =(ref A : SqliteRow, const ref B : SqliteRow) {
    serial {
      A._valDom = B._valDom;
      A._values = B._values;
    }
  }

  enum SqliteType {
    INT, FLOAT, TEXT, BLOB, NULL
  }

  // Tagged unions, please!
  record SqliteValue {
    var k : SqliteType;

    var val_int : int;
    var val_float : real;
    var val_text : string;
    var val_blob : c_void_ptr;

    proc getType() {
      return k;
    }

    proc is(type t) {
      if isIntegralType(t) then
        return k == SqliteType.INT;
      else if isRealType(t) then
        return k == SqliteType.FLOAT;
      else if isStringType(t) then
        return k == SqliteType.TEXT;
      else if isCPtr(t) || t == c_void_ptr then
        return k == SqliteType.BLOB; 
      else if isVoidType(t) then
        return k == SqliteType.NULL;
      else
        compilerError("Invalid type, expecting: integral, real, string, c_ptr, void");
    }

    proc get(type t) throws {
      if is(t) == false then
        throw new SqliteError("Requested incorrect type, '" + t:string + "', from " + k:string);

      var ret : t;
      if isIntegralType(t) then
        ret = val_int.safeCast(t);
      else if isRealType(t) then
        ret = val_float;
      else if isStringType(t) then
        ret = val_text;
      else if isCPtr(t) || t == c_void_ptr then
        ret = val_blob;
      // else: NULL/void

      return ret;
    }

    proc init() {
      k = SqliteType.NULL;
    }
    proc init(i : int) {
      k = SqliteType.INT;
      val_int = i;
    }
    proc init(r : real) {
      k = SqliteType.FLOAT;
      val_float = r;
    }
    proc init(s : string) {
      k = SqliteType.TEXT;
      val_text = s;
    }
    proc init(b : c_void_ptr) {
      k = SqliteType.BLOB;
      val_blob = b;
    }
    proc init(b : c_ptr) {
      k = SqliteType.BLOB;
      val_blob = b:c_void_ptr;
    }

    proc writeThis(f) {
      try! {
        if k == SqliteType.INT then
          f.write(val_int);
        else if k == SqliteType.FLOAT then
          f.write(val_float);
        else if k == SqliteType.TEXT then
          f.write(val_text);
        else if k == SqliteType.BLOB then
          f.write(val_blob);
        else if k == SqliteType.NULL then
          f.write("NULL");
      }
    }
  }

  private module _Sys {
    require "sqlite3.h", "-lsqlite3";

    extern const SQLITE_OPEN_READONLY : int;
    extern const SQLITE_OPEN_READWRITE : int;
    extern const SQLITE_OPEN_CREATE : int;
    extern const SQLITE_OPEN_NOMUTEX : int;
    extern const SQLITE_OPEN_FULLMUTEX : int;
    extern const SQLITE_OPEN_SHAREDCACHE : int;
    extern const SQLITE_OPEN_PRIVATECACHE : int;
    extern const SQLITE_OPEN_URI : int;

    extern const SQLITE_VERSION_NUMBER : int;
    extern const SQLITE_OK : int;
    extern const SQLITE_ERROR : int;
    extern const SQLITE_INTERNAL : int;
    extern const SQLITE_PERM : int;
    extern const SQLITE_ABORT : int;
    extern const SQLITE_BUSY : int;
    extern const SQLITE_LOCKED : int;
    extern const SQLITE_NOMEM : int;
    extern const SQLITE_READONLY : int;
    extern const SQLITE_INTERRUPT : int;
    extern const SQLITE_IOERR : int;
    extern const SQLITE_CORRUPT : int;
    extern const SQLITE_NOTFOUND : int;
    extern const SQLITE_FULL : int;
    extern const SQLITE_CANTOPEN : int;
    extern const SQLITE_PROTOCOL : int;
    extern const SQLITE_EMPTY : int;
    extern const SQLITE_SCHEMA : int;
    extern const SQLITE_TOOBIG : int;
    extern const SQLITE_CONSTRAINT : int;
    extern const SQLITE_MISMATCH : int;
    extern const SQLITE_MISUSE : int;
    extern const SQLITE_NOLFS : int;
    extern const SQLITE_AUTH : int;
    extern const SQLITE_FORMAT : int;
    extern const SQLITE_RANGE : int;
    extern const SQLITE_NOTADB : int;
    extern const SQLITE_NOTICE : int;
    extern const SQLITE_WARNING : int;
    extern const SQLITE_ROW : int;
    extern const SQLITE_DONE : int;
    extern const SQLITE_LOCK_NONE : int;
    extern const SQLITE_LOCK_SHARED : int;
    extern const SQLITE_LOCK_RESERVED : int;
    extern const SQLITE_LOCK_PENDING : int;
    extern const SQLITE_LOCK_EXCLUSIVE : int;
    extern const SQLITE_FCNTL_LOCKSTATE : int;
    extern const SQLITE_FCNTL_GET_LOCKPROXYFILE : int;
    extern const SQLITE_FCNTL_SET_LOCKPROXYFILE : int;
    extern const SQLITE_FCNTL_LAST_ERRNO : int;
    extern const SQLITE_FCNTL_SIZE_HINT : int;
    extern const SQLITE_FCNTL_CHUNK_SIZE : int;
    extern const SQLITE_FCNTL_FILE_POINTER : int;
    extern const SQLITE_FCNTL_SYNC_OMITTED : int;
    extern const SQLITE_FCNTL_WIN32_AV_RETRY : int;
    extern const SQLITE_FCNTL_PERSIST_WAL : int;
    extern const SQLITE_FCNTL_OVERWRITE : int;
    extern const SQLITE_FCNTL_VFSNAME : int;
    extern const SQLITE_FCNTL_POWERSAFE_OVERWRITE : int;
    extern const SQLITE_FCNTL_PRAGMA : int;
    extern const SQLITE_FCNTL_BUSYHANDLER : int;
    extern const SQLITE_FCNTL_TEMPFILENAME : int;
    extern const SQLITE_FCNTL_MMAP_SIZE : int;
    extern const SQLITE_FCNTL_TRACE : int;
    extern const SQLITE_FCNTL_HAS_MOVED : int;
    extern const SQLITE_FCNTL_SYNC : int;
    extern const SQLITE_FCNTL_COMMIT_PHASETWO : int;
    extern const SQLITE_FCNTL_WIN32_SET_HANDLE : int;
    extern const SQLITE_FCNTL_WAL_BLOCK : int;
    extern const SQLITE_FCNTL_ZIPVFS : int;
    extern const SQLITE_FCNTL_RBU : int;
    extern const SQLITE_FCNTL_VFS_POINTER : int;
    extern const SQLITE_FCNTL_JOURNAL_POINTER : int;
    extern const SQLITE_FCNTL_WIN32_GET_HANDLE : int;
    extern const SQLITE_FCNTL_PDB : int;
    extern const SQLITE_ACCESS_EXISTS : int;
    extern const SQLITE_ACCESS_READWRITE : int;
    extern const SQLITE_ACCESS_READ : int;
    extern const SQLITE_SHM_UNLOCK : int;
    extern const SQLITE_SHM_LOCK : int;
    extern const SQLITE_SHM_SHARED : int;
    extern const SQLITE_SHM_EXCLUSIVE : int;
    extern const SQLITE_SHM_NLOCK : int;
    extern const SQLITE_CONFIG_SINGLETHREAD : int;
    extern const SQLITE_CONFIG_MULTITHREAD : int;
    extern const SQLITE_CONFIG_SERIALIZED : int;
    extern const SQLITE_CONFIG_MALLOC : int;
    extern const SQLITE_CONFIG_GETMALLOC : int;
    extern const SQLITE_CONFIG_SCRATCH : int;
    extern const SQLITE_CONFIG_PAGECACHE : int;
    extern const SQLITE_CONFIG_HEAP : int;
    extern const SQLITE_CONFIG_MEMSTATUS : int;
    extern const SQLITE_CONFIG_MUTEX : int;
    extern const SQLITE_CONFIG_GETMUTEX : int;
    extern const SQLITE_CONFIG_LOOKASIDE : int;
    extern const SQLITE_CONFIG_PCACHE : int;
    extern const SQLITE_CONFIG_GETPCACHE : int;
    extern const SQLITE_CONFIG_LOG : int;
    extern const SQLITE_CONFIG_URI : int;
    extern const SQLITE_CONFIG_PCACHE2 : int;
    extern const SQLITE_CONFIG_GETPCACHE2 : int;
    extern const SQLITE_CONFIG_COVERING_INDEX_SCAN : int;
    extern const SQLITE_CONFIG_SQLLOG : int;
    extern const SQLITE_CONFIG_MMAP_SIZE : int;
    extern const SQLITE_CONFIG_WIN32_HEAPSIZE : int;
    extern const SQLITE_CONFIG_PCACHE_HDRSZ : int;
    extern const SQLITE_CONFIG_PMASZ : int;
    extern const SQLITE_CONFIG_STMTJRNL_SPILL : int;
    extern const SQLITE_DBCONFIG_MAINDBNAME : int;
    extern const SQLITE_DBCONFIG_LOOKASIDE : int;
    extern const SQLITE_DBCONFIG_ENABLE_FKEY : int;
    extern const SQLITE_DBCONFIG_ENABLE_TRIGGER : int;
    extern const SQLITE_DBCONFIG_ENABLE_FTS3_TOKENIZER : int;
    extern const SQLITE_DBCONFIG_ENABLE_LOAD_EXTENSION : int;
    extern const SQLITE_DBCONFIG_NO_CKPT_ON_CLOSE : int;
    extern const SQLITE_DENY : int;
    extern const SQLITE_IGNORE : int;
    extern const SQLITE_CREATE_INDEX : int;
    extern const SQLITE_CREATE_TABLE : int;
    extern const SQLITE_CREATE_TEMP_INDEX : int;
    extern const SQLITE_CREATE_TEMP_TABLE : int;
    extern const SQLITE_CREATE_TEMP_TRIGGER : int;
    extern const SQLITE_CREATE_TEMP_VIEW : int;
    extern const SQLITE_CREATE_TRIGGER : int;
    extern const SQLITE_CREATE_VIEW : int;
    extern const SQLITE_DELETE : int;
    extern const SQLITE_DROP_INDEX : int;
    extern const SQLITE_DROP_TABLE : int;
    extern const SQLITE_DROP_TEMP_INDEX : int;
    extern const SQLITE_DROP_TEMP_TABLE : int;
    extern const SQLITE_DROP_TEMP_TRIGGER : int;
    extern const SQLITE_DROP_TEMP_VIEW : int;
    extern const SQLITE_DROP_TRIGGER : int;
    extern const SQLITE_DROP_VIEW : int;
    extern const SQLITE_INSERT : int;
    extern const SQLITE_PRAGMA : int;
    extern const SQLITE_READ : int;
    extern const SQLITE_SELECT : int;
    extern const SQLITE_TRANSACTION : int;
    extern const SQLITE_UPDATE : int;
    extern const SQLITE_ATTACH : int;
    extern const SQLITE_DETACH : int;
    extern const SQLITE_ALTER_TABLE : int;
    extern const SQLITE_REINDEX : int;
    extern const SQLITE_ANALYZE : int;
    extern const SQLITE_CREATE_VTABLE : int;
    extern const SQLITE_DROP_VTABLE : int;
    extern const SQLITE_FUNCTION : int;
    extern const SQLITE_SAVEPOINT : int;
    extern const SQLITE_COPY : int;
    extern const SQLITE_RECURSIVE : int;
    extern const SQLITE_LIMIT_LENGTH : int;
    extern const SQLITE_LIMIT_SQL_LENGTH : int;
    extern const SQLITE_LIMIT_COLUMN : int;
    extern const SQLITE_LIMIT_EXPR_DEPTH : int;
    extern const SQLITE_LIMIT_COMPOUND_SELECT : int;
    extern const SQLITE_LIMIT_VDBE_OP : int;
    extern const SQLITE_LIMIT_FUNCTION_ARG : int;
    extern const SQLITE_LIMIT_ATTACHED : int;
    extern const SQLITE_LIMIT_LIKE_PATTERN_LENGTH : int;
    extern const SQLITE_LIMIT_VARIABLE_NUMBER : int;
    extern const SQLITE_LIMIT_TRIGGER_DEPTH : int;
    extern const SQLITE_LIMIT_WORKER_THREADS : int;
    extern const SQLITE_INTEGER : int;
    extern const SQLITE_FLOAT : int;
    extern const SQLITE_BLOB : int;
    extern const SQLITE_NULL : int;
    extern const SQLITE_TEXT : int;
    extern const SQLITE_UTF8 : int;
    extern const SQLITE_UTF16LE : int;
    extern const SQLITE_UTF16BE : int;
    extern const SQLITE_UTF16 : int;
    extern const SQLITE_ANY : int;
    extern const SQLITE_UTF16_ALIGNED : int;
    extern const SQLITE_INDEX_SCAN_UNIQUE : int;
    extern const SQLITE_INDEX_CONSTRAINT_EQ : int;
    extern const SQLITE_INDEX_CONSTRAINT_GT : int;
    extern const SQLITE_INDEX_CONSTRAINT_LE : int;
    extern const SQLITE_INDEX_CONSTRAINT_LT : int;
    extern const SQLITE_INDEX_CONSTRAINT_GE : int;
    extern const SQLITE_INDEX_CONSTRAINT_MATCH : int;
    extern const SQLITE_INDEX_CONSTRAINT_LIKE : int;
    extern const SQLITE_INDEX_CONSTRAINT_GLOB : int;
    extern const SQLITE_INDEX_CONSTRAINT_REGEXP : int;
    extern const SQLITE_MUTEX_FAST : int;
    extern const SQLITE_MUTEX_RECURSIVE : int;
    extern const SQLITE_MUTEX_STATIC_MASTER : int;
    extern const SQLITE_MUTEX_STATIC_MEM : int;
    extern const SQLITE_MUTEX_STATIC_MEM2 : int;
    extern const SQLITE_MUTEX_STATIC_OPEN : int;
    extern const SQLITE_MUTEX_STATIC_PRNG : int;
    extern const SQLITE_MUTEX_STATIC_LRU : int;
    extern const SQLITE_MUTEX_STATIC_LRU2 : int;
    extern const SQLITE_MUTEX_STATIC_PMEM : int;
    extern const SQLITE_MUTEX_STATIC_APP1 : int;
    extern const SQLITE_MUTEX_STATIC_APP2 : int;
    extern const SQLITE_MUTEX_STATIC_APP3 : int;
    extern const SQLITE_MUTEX_STATIC_VFS1 : int;
    extern const SQLITE_MUTEX_STATIC_VFS2 : int;
    extern const SQLITE_MUTEX_STATIC_VFS3 : int;
    extern const SQLITE_TESTCTRL_FIRST : int;
    extern const SQLITE_TESTCTRL_PRNG_SAVE : int;
    extern const SQLITE_TESTCTRL_PRNG_RESTORE : int;
    extern const SQLITE_TESTCTRL_PRNG_RESET : int;
    extern const SQLITE_TESTCTRL_BITVEC_TEST : int;
    extern const SQLITE_TESTCTRL_FAULT_INSTALL : int;
    extern const SQLITE_TESTCTRL_BENIGN_MALLOC_HOOKS : int;
    extern const SQLITE_TESTCTRL_PENDING_BYTE : int;
    extern const SQLITE_TESTCTRL_ASSERT : int;
    extern const SQLITE_TESTCTRL_ALWAYS : int;
    extern const SQLITE_TESTCTRL_RESERVE : int;
    extern const SQLITE_TESTCTRL_OPTIMIZATIONS : int;
    extern const SQLITE_TESTCTRL_ISKEYWORD : int;
    extern const SQLITE_TESTCTRL_SCRATCHMALLOC : int;
    extern const SQLITE_TESTCTRL_LOCALTIME_FAULT : int;
    extern const SQLITE_TESTCTRL_EXPLAIN_STMT : int;
    extern const SQLITE_TESTCTRL_ONCE_RESET_THRESHOLD : int;
    extern const SQLITE_TESTCTRL_NEVER_CORRUPT : int;
    extern const SQLITE_TESTCTRL_VDBE_COVERAGE : int;
    extern const SQLITE_TESTCTRL_BYTEORDER : int;
    extern const SQLITE_TESTCTRL_ISINIT : int;
    extern const SQLITE_TESTCTRL_SORTER_MMAP : int;
    extern const SQLITE_TESTCTRL_IMPOSTER : int;
    extern const SQLITE_TESTCTRL_LAST : int;
    extern const SQLITE_STATUS_MEMORY_USED : int;
    extern const SQLITE_STATUS_PAGECACHE_USED : int;
    extern const SQLITE_STATUS_PAGECACHE_OVERFLOW : int;
    extern const SQLITE_STATUS_SCRATCH_USED : int;
    extern const SQLITE_STATUS_SCRATCH_OVERFLOW : int;
    extern const SQLITE_STATUS_MALLOC_SIZE : int;
    extern const SQLITE_STATUS_PARSER_STACK : int;
    extern const SQLITE_STATUS_PAGECACHE_SIZE : int;
    extern const SQLITE_STATUS_SCRATCH_SIZE : int;
    extern const SQLITE_STATUS_MALLOC_COUNT : int;
    extern const SQLITE_DBSTATUS_LOOKASIDE_USED : int;
    extern const SQLITE_DBSTATUS_CACHE_USED : int;
    extern const SQLITE_DBSTATUS_SCHEMA_USED : int;
    extern const SQLITE_DBSTATUS_STMT_USED : int;
    extern const SQLITE_DBSTATUS_LOOKASIDE_HIT : int;
    extern const SQLITE_DBSTATUS_LOOKASIDE_MISS_SIZE : int;
    extern const SQLITE_DBSTATUS_LOOKASIDE_MISS_FULL : int;
    extern const SQLITE_DBSTATUS_CACHE_HIT : int;
    extern const SQLITE_DBSTATUS_CACHE_MISS : int;
    extern const SQLITE_DBSTATUS_CACHE_WRITE : int;
    extern const SQLITE_DBSTATUS_DEFERRED_FKS : int;
    extern const SQLITE_DBSTATUS_CACHE_USED_SHARED : int;
    extern const SQLITE_DBSTATUS_MAX : int;
    extern const SQLITE_STMTSTATUS_FULLSCAN_STEP : int;
    extern const SQLITE_STMTSTATUS_SORT : int;
    extern const SQLITE_STMTSTATUS_AUTOINDEX : int;
    extern const SQLITE_STMTSTATUS_VM_STEP : int;
    extern const SQLITE_CHECKPOINT_PASSIVE : int;
    extern const SQLITE_CHECKPOINT_FULL : int;
    extern const SQLITE_CHECKPOINT_RESTART : int;
    extern const SQLITE_CHECKPOINT_TRUNCATE : int;
    extern const SQLITE_VTAB_CONSTRAINT_SUPPORT : int;
    extern const SQLITE_ROLLBACK : int;
    extern const SQLITE_FAIL : int;
    extern const SQLITE_REPLACE : int;
    extern const SQLITE_SCANSTAT_NLOOP : int;
    extern const SQLITE_SCANSTAT_NVISIT : int;
    extern const SQLITE_SCANSTAT_EST : int;
    extern const SQLITE_SCANSTAT_NAME : int;
    extern const SQLITE_SCANSTAT_EXPLAIN : int;
    extern const SQLITE_SCANSTAT_SELECTID : int;
    extern const SQLITE_CHANGESET_DATA : int;
    extern const SQLITE_CHANGESET_NOTFOUND : int;
    extern const SQLITE_CHANGESET_CONFLICT : int;
    extern const SQLITE_CHANGESET_CONSTRAINT : int;
    extern const SQLITE_CHANGESET_FOREIGN_KEY : int;
    extern const SQLITE_CHANGESET_OMIT : int;
    extern const SQLITE_CHANGESET_REPLACE : int;
    extern const SQLITE_CHANGESET_ABORT : int;
    
    // huh?
    extern const NOT_WITHIN : int;
    extern const PARTLY_WITHIN : int;
    extern const FULLY_WITHIN : int;

    extern var sqlite3_version              : c_string;
    extern proc sqlite3_libversion()        : c_string;
    extern proc sqlite3_sourceid()          : c_string;
    extern proc sqlite3_libversion_number() : c_int;

    extern proc sqlite3_compileoption_used(zOptName : c_string) : c_int;
    extern proc sqlite3_compileoption_get(N : c_int) : c_string;

    extern proc sqlite3_threadsafe() : c_int;

    extern proc sqlite3_close(arg0 : c_ptr(sqlite3)) : c_int;
    extern proc sqlite3_close_v2(arg0 : c_ptr(sqlite3)) : c_int;

    extern proc sqlite3_exec(arg0 : c_ptr(sqlite3), sql : c_string, ref callback : c_fn_ptr, arg3 : c_void_ptr, ref errmsg : c_string) : c_int;

    extern proc sqlite3_config(arg0 : c_int, c__varargs ...) : c_int;
    extern proc sqlite3_config(arg0 : c_int) : c_int;
    extern proc sqlite3_db_config(arg0 : c_ptr(sqlite3), op : c_int, c__varargs ...) : c_int;
    extern proc sqlite3_db_config(arg0 : c_ptr(sqlite3), op : c_int) : c_int;

    extern proc sqlite3_last_insert_rowid(arg0 : c_ptr(sqlite3)) : int(64);
    extern proc sqlite3_set_last_insert_rowid(arg0 : c_ptr(sqlite3), arg1 : int(64)) : void;

    extern proc sqlite3_changes(arg0 : c_ptr(sqlite3)) : c_int;
    extern proc sqlite3_total_changes(arg0 : c_ptr(sqlite3)) : c_int;

    extern proc sqlite3_interrupt(arg0 : c_ptr(sqlite3)) : void;

    extern proc sqlite3_complete(sql : c_string) : c_int;
    extern proc sqlite3_complete16(sql : c_void_ptr) : c_int;

    extern proc sqlite3_busy_timeout(arg0 : c_ptr(sqlite3), ms : c_int) : c_int;

  //  extern proc sqlite3_open(filename : c_string, ref ppDb : c_ptr(sqlite3)) : c_int;
  //  extern proc sqlite3_open16(filename : c_void_ptr, ref ppDb : c_ptr(sqlite3)) : c_int;

    extern proc sqlite3_open_v2(filename : c_string,
                                ref ppDb : c_ptr(sqlite3),
                                flags : c_int,
                                zVfs : c_string) : c_int;

    extern proc sqlite3_prepare_v2(db : c_ptr(sqlite3), zSql : c_string, nByte : c_int, ref ppStmt : c_ptr(sqlite3_stmt), pzTail : c_ptr(c_string)) : c_int;

    // Destroy STMT
    extern proc sqlite3_finalize(pStmt : c_ptr(sqlite3_stmt)) : c_int;

    extern proc sqlite3_load_extension(db : c_ptr(sqlite3), zFile : c_string, zProc : c_string, ref pzErrMsg : c_string) : c_int;
    extern proc sqlite3_enable_load_extension(db : c_ptr(sqlite3), onoff : c_int) : c_int;

    extern record sqlite3 {};

    extern record sqlite3_stmt {};

    extern proc sqlite3_step(arg0 : c_ptr(sqlite3_stmt)) : c_int;
    extern proc sqlite3_reset(arg0 : c_ptr(sqlite3_stmt)) : c_int;

    extern proc sqlite3_data_count(pStmt : c_ptr(sqlite3_stmt)) : c_int;
    extern proc sqlite3_column_count(pStmt : c_ptr(sqlite3_stmt)) : c_int;

    extern proc sqlite3_column_name(arg0 : c_ptr(sqlite3_stmt), N : c_int) : c_string;
    extern proc sqlite3_column_database_name(arg0 : c_ptr(sqlite3_stmt), arg1 : c_int) : c_string;
    extern proc sqlite3_column_table_name(arg0 : c_ptr(sqlite3_stmt), arg1 : c_int) : c_string;
    extern proc sqlite3_column_origin_name(arg0 : c_ptr(sqlite3_stmt), arg1 : c_int) : c_string;
    extern proc sqlite3_column_decltype(arg0 : c_ptr(sqlite3_stmt), arg1 : c_int) : c_string;
    extern proc sqlite3_column_type(arg0 : c_ptr(sqlite3_stmt), iCol : c_int) : c_int;

    extern proc sqlite3_column_blob(arg0 : c_ptr(sqlite3_stmt), iCol : c_int) : c_void_ptr;
    extern proc sqlite3_column_bytes(arg0 : c_ptr(sqlite3_stmt), iCol : c_int) : c_int;
    extern proc sqlite3_column_double(arg0 : c_ptr(sqlite3_stmt), iCol : c_int) : c_double;
    extern proc sqlite3_column_int(arg0 : c_ptr(sqlite3_stmt), iCol : c_int) : c_int;
    extern proc sqlite3_column_int64(arg0 : c_ptr(sqlite3_stmt), iCol : c_int) : int(64);
    extern proc sqlite3_column_text(arg0 : c_ptr(sqlite3_stmt), iCol : c_int) : c_string;
    //extern proc sqlite3_column_value(arg0 : c_ptr(sqlite3_stmt), iCol : c_int) : c_ptr(sqlite3_value);

    extern proc sqlite3_bind_blob(arg0 : c_ptr(sqlite3_stmt), arg1 : c_int, arg2 : c_void_ptr, n : c_int, ref arg4 : c_fn_ptr) : c_int;
    //extern proc sqlite3_bind_blob64(arg0 : c_ptr(sqlite3_stmt), arg1 : c_int, arg2 : c_void_ptr, arg3 : sqlite3_uint64, ref arg4 : c_fn_ptr) : c_int;
    extern proc sqlite3_bind_double(arg0 : c_ptr(sqlite3_stmt), arg1 : c_int, arg2 : c_double) : c_int;
    extern proc sqlite3_bind_int(arg0 : c_ptr(sqlite3_stmt), arg1 : c_int, arg2 : c_int) : c_int;
    extern proc sqlite3_bind_int64(arg0 : c_ptr(sqlite3_stmt), arg1 : c_int, arg2 : int(64)) : c_int;
    extern proc sqlite3_bind_null(arg0 : c_ptr(sqlite3_stmt), arg1 : c_int) : c_int;
    extern proc sqlite3_bind_text(arg0 : c_ptr(sqlite3_stmt), arg1 : c_int, arg2 : c_string, arg3 : c_int, ref arg4 : c_fn_ptr) : c_int;
    extern proc sqlite3_bind_text16(arg0 : c_ptr(sqlite3_stmt), arg1 : c_int, arg2 : c_void_ptr, arg3 : c_int, ref arg4 : c_fn_ptr) : c_int;
    //extern proc sqlite3_bind_text64(arg0 : c_ptr(sqlite3_stmt), arg1 : c_int, arg2 : c_string, arg3 : sqlite3_uint64, ref arg4 : c_fn_ptr, encoding : c_uchar) : c_int;
    //extern proc sqlite3_bind_value(arg0 : c_ptr(sqlite3_stmt), arg1 : c_int, ref arg2 : sqlite3_value) : c_int;
    extern proc sqlite3_bind_zeroblob(arg0 : c_ptr(sqlite3_stmt), arg1 : c_int, n : c_int) : c_int;
    //extern proc sqlite3_bind_zeroblob64(arg0 : c_ptr(sqlite3_stmt), arg1 : c_int, arg2 : sqlite3_uint64) : c_int;
    extern proc sqlite3_bind_parameter_count(arg0 : c_ptr(sqlite3_stmt)) : c_int;
    extern proc sqlite3_bind_parameter_name(arg0 : c_ptr(sqlite3_stmt), arg1 : c_int) : c_string;
    extern proc sqlite3_bind_parameter_index(arg0 : c_ptr(sqlite3_stmt), zName : c_string) : c_int;
    extern proc sqlite3_clear_bindings(arg0 : c_ptr(sqlite3_stmt)) : c_int;

    extern proc sqlite3_errmsg(arg0 : c_ptr(sqlite3)) : c_string;
  }
}
