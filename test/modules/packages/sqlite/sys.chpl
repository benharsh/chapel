// Generated with c2chapel version 0.1.0

// Header given to c2chapel:
require "/usr/local/Cellar/sqlite/3.18.0/include/sqlite3.h";

// Note: Generated with fake std headers

// #define'd integer literals:
// Note: some of these may have been defined with an ifdef
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
extern const SQLITE3_TEXT : int;
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
extern const NOT_WITHIN : int;
extern const PARTLY_WITHIN : int;
extern const FULLY_WITHIN : int;
extern const __SQLITESESSION_H_ : int;
extern const SQLITE_CHANGESET_DATA : int;
extern const SQLITE_CHANGESET_NOTFOUND : int;
extern const SQLITE_CHANGESET_CONFLICT : int;
extern const SQLITE_CHANGESET_CONSTRAINT : int;
extern const SQLITE_CHANGESET_FOREIGN_KEY : int;
extern const SQLITE_CHANGESET_OMIT : int;
extern const SQLITE_CHANGESET_REPLACE : int;
extern const SQLITE_CHANGESET_ABORT : int;

// End of #define'd integer literals

extern var sqlite3_version : c_ptr(c_char);

extern proc sqlite3_libversion() : c_string;

extern proc sqlite3_sourceid() : c_string;

extern proc sqlite3_libversion_number() : c_int;

extern proc sqlite3_compileoption_used(zOptName : c_string) : c_int;

extern proc sqlite3_compileoption_get(N : c_int) : c_string;

extern proc sqlite3_threadsafe() : c_int;

extern proc sqlite3_close(ref arg0 : sqlite3) : c_int;

extern proc sqlite3_close_v2(ref arg0 : sqlite3) : c_int;

extern proc sqlite3_exec(ref arg0 : sqlite3, sql : c_string, ref callback : c_fn_ptr, arg3 : c_void_ptr, ref errmsg : c_string) : c_int;

extern record sqlite3_file {
  var pMethods : c_ptr(sqlite3_io_methods);
}

extern record sqlite3_io_methods {
  var iVersion : c_int;
  var xClose : c_fn_ptr;
  var xRead : c_fn_ptr;
  var xWrite : c_fn_ptr;
  var xTruncate : c_fn_ptr;
  var xSync : c_fn_ptr;
  var xFileSize : c_fn_ptr;
  var xLock : c_fn_ptr;
  var xUnlock : c_fn_ptr;
  var xCheckReservedLock : c_fn_ptr;
  var xFileControl : c_fn_ptr;
  var xSectorSize : c_fn_ptr;
  var xDeviceCharacteristics : c_fn_ptr;
  var xShmMap : c_fn_ptr;
  var xShmLock : c_fn_ptr;
  var xShmBarrier : c_fn_ptr;
  var xShmUnmap : c_fn_ptr;
  var xFetch : c_fn_ptr;
  var xUnfetch : c_fn_ptr;
}

extern record sqlite3_vfs {
  var iVersion : c_int;
  var szOsFile : c_int;
  var mxPathname : c_int;
  var pNext : c_ptr(sqlite3_vfs);
  var zName : c_string;
  var pAppData : c_void_ptr;
  var xOpen : c_fn_ptr;
  var xDelete : c_fn_ptr;
  var xAccess : c_fn_ptr;
  var xFullPathname : c_fn_ptr;
  var xDlOpen : c_fn_ptr;
  var xDlError : c_fn_ptr;
  var xDlSym : c_fn_ptr;
  var xDlClose : c_fn_ptr;
  var xRandomness : c_fn_ptr;
  var xSleep : c_fn_ptr;
  var xCurrentTime : c_fn_ptr;
  var xGetLastError : c_fn_ptr;
  var xCurrentTimeInt64 : c_fn_ptr;
  var xSetSystemCall : c_fn_ptr;
  var xGetSystemCall : c_fn_ptr;
  var xNextSystemCall : c_fn_ptr;
}

extern proc sqlite3_initialize() : c_int;

extern proc sqlite3_shutdown() : c_int;

extern proc sqlite3_os_init() : c_int;

extern proc sqlite3_os_end() : c_int;

extern proc sqlite3_config(arg0 : c_int, c__varargs ...) : c_int;

// Overload for empty varargs
extern proc sqlite3_config(arg0 : c_int) : c_int;

extern proc sqlite3_db_config(ref arg0 : sqlite3, op : c_int, c__varargs ...) : c_int;

// Overload for empty varargs
extern proc sqlite3_db_config(ref arg0 : sqlite3,op : c_int) : c_int;

extern record sqlite3_mem_methods {
  var xMalloc : c_fn_ptr;
  var xFree : c_fn_ptr;
  var xRealloc : c_fn_ptr;
  var xSize : c_fn_ptr;
  var xRoundup : c_fn_ptr;
  var xInit : c_fn_ptr;
  var xShutdown : c_fn_ptr;
  var pAppData : c_void_ptr;
}

extern proc sqlite3_extended_result_codes(ref arg0 : sqlite3, onoff : c_int) : c_int;

extern proc sqlite3_last_insert_rowid(ref arg0 : sqlite3) : sqlite3_int64;

extern proc sqlite3_set_last_insert_rowid(ref arg0 : sqlite3, arg1 : sqlite3_int64) : void;

extern proc sqlite3_changes(ref arg0 : sqlite3) : c_int;

extern proc sqlite3_total_changes(ref arg0 : sqlite3) : c_int;

extern proc sqlite3_interrupt(ref arg0 : sqlite3) : void;

extern proc sqlite3_complete(sql : c_string) : c_int;

extern proc sqlite3_complete16(sql : c_void_ptr) : c_int;

extern proc sqlite3_busy_handler(ref arg0 : sqlite3, ref arg1 : c_fn_ptr, arg2 : c_void_ptr) : c_int;

extern proc sqlite3_busy_timeout(ref arg0 : sqlite3, ms : c_int) : c_int;

extern proc sqlite3_get_table(ref db : sqlite3, zSql : c_string, ref pazResult : c_ptr(c_string), ref pnRow : c_int, ref pnColumn : c_int, ref pzErrmsg : c_string) : c_int;

extern proc sqlite3_free_table(ref result : c_string) : void;

extern proc sqlite3_mprintf(arg0 : c_string, c__varargs ...) : c_string;

// Overload for empty varargs
extern proc sqlite3_mprintf(arg0 : c_string) : c_string;

// Unable to generate function 'sqlite3_vmprintf' due to va_list argument

extern proc sqlite3_snprintf(arg0 : c_int, arg1 : c_string, arg2 : c_string, c__varargs ...) : c_string;

// Overload for empty varargs
extern proc sqlite3_snprintf(arg0 : c_int,arg1 : c_string,arg2 : c_string) : c_string;

// Unable to generate function 'sqlite3_vsnprintf' due to va_list argument

extern proc sqlite3_malloc(arg0 : c_int) : c_void_ptr;

extern proc sqlite3_malloc64(arg0 : sqlite3_uint64) : c_void_ptr;

extern proc sqlite3_realloc(arg0 : c_void_ptr, arg1 : c_int) : c_void_ptr;

extern proc sqlite3_realloc64(arg0 : c_void_ptr, arg1 : sqlite3_uint64) : c_void_ptr;

extern proc sqlite3_free(arg0 : c_void_ptr) : void;

extern proc sqlite3_msize(arg0 : c_void_ptr) : sqlite3_uint64;

extern proc sqlite3_memory_used() : sqlite3_int64;

extern proc sqlite3_memory_highwater(resetFlag : c_int) : sqlite3_int64;

extern proc sqlite3_randomness(N : c_int, P : c_void_ptr) : void;

extern proc sqlite3_set_authorizer(ref arg0 : sqlite3, ref xAuth : c_fn_ptr, pUserData : c_void_ptr) : c_int;

extern proc sqlite3_trace(ref arg0 : sqlite3, ref xTrace : c_fn_ptr, arg2 : c_void_ptr) : c_void_ptr;

extern proc sqlite3_profile(ref arg0 : sqlite3, ref xProfile : c_fn_ptr, arg2 : c_void_ptr) : c_void_ptr;

extern proc sqlite3_trace_v2(ref arg0 : sqlite3, uMask : c_uint, ref xCallback : c_fn_ptr, pCtx : c_void_ptr) : c_int;

extern proc sqlite3_progress_handler(ref arg0 : sqlite3, arg1 : c_int, ref arg2 : c_fn_ptr, arg3 : c_void_ptr) : void;

extern proc sqlite3_open(filename : c_string, ref ppDb : c_ptr(sqlite3)) : c_int;

extern proc sqlite3_open16(filename : c_void_ptr, ref ppDb : c_ptr(sqlite3)) : c_int;

extern proc sqlite3_open_v2(filename : c_string, ref ppDb : c_ptr(sqlite3), flags : c_int, zVfs : c_string) : c_int;

extern proc sqlite3_uri_parameter(zFilename : c_string, zParam : c_string) : c_string;

extern proc sqlite3_uri_boolean(zFile : c_string, zParam : c_string, bDefault : c_int) : c_int;

extern proc sqlite3_uri_int64(arg0 : c_string, arg1 : c_string, arg2 : sqlite3_int64) : sqlite3_int64;

extern proc sqlite3_errcode(ref db : sqlite3) : c_int;

extern proc sqlite3_extended_errcode(ref db : sqlite3) : c_int;

extern proc sqlite3_errmsg(ref arg0 : sqlite3) : c_string;

extern proc sqlite3_errmsg16(ref arg0 : sqlite3) : c_void_ptr;

extern proc sqlite3_errstr(arg0 : c_int) : c_string;

extern proc sqlite3_limit(ref arg0 : sqlite3, id : c_int, newVal : c_int) : c_int;

extern proc sqlite3_prepare(ref db : sqlite3, zSql : c_string, nByte : c_int, ref ppStmt : c_ptr(sqlite3_stmt), ref pzTail : c_string) : c_int;

extern proc sqlite3_prepare_v2(ref db : sqlite3, zSql : c_string, nByte : c_int, ref ppStmt : c_ptr(sqlite3_stmt), ref pzTail : c_string) : c_int;

extern proc sqlite3_prepare16(ref db : sqlite3, zSql : c_void_ptr, nByte : c_int, ref ppStmt : c_ptr(sqlite3_stmt), ref pzTail : c_void_ptr) : c_int;

extern proc sqlite3_prepare16_v2(ref db : sqlite3, zSql : c_void_ptr, nByte : c_int, ref ppStmt : c_ptr(sqlite3_stmt), ref pzTail : c_void_ptr) : c_int;

extern proc sqlite3_sql(ref pStmt : sqlite3_stmt) : c_string;

extern proc sqlite3_expanded_sql(ref pStmt : sqlite3_stmt) : c_string;

extern proc sqlite3_stmt_readonly(ref pStmt : sqlite3_stmt) : c_int;

extern proc sqlite3_stmt_busy(ref arg0 : sqlite3_stmt) : c_int;

extern proc sqlite3_bind_blob(ref arg0 : sqlite3_stmt, arg1 : c_int, arg2 : c_void_ptr, n : c_int, ref arg4 : c_fn_ptr) : c_int;

extern proc sqlite3_bind_blob64(ref arg0 : sqlite3_stmt, arg1 : c_int, arg2 : c_void_ptr, arg3 : sqlite3_uint64, ref arg4 : c_fn_ptr) : c_int;

extern proc sqlite3_bind_double(ref arg0 : sqlite3_stmt, arg1 : c_int, arg2 : c_double) : c_int;

extern proc sqlite3_bind_int(ref arg0 : sqlite3_stmt, arg1 : c_int, arg2 : c_int) : c_int;

extern proc sqlite3_bind_int64(ref arg0 : sqlite3_stmt, arg1 : c_int, arg2 : sqlite3_int64) : c_int;

extern proc sqlite3_bind_null(ref arg0 : sqlite3_stmt, arg1 : c_int) : c_int;

extern proc sqlite3_bind_text(ref arg0 : sqlite3_stmt, arg1 : c_int, arg2 : c_string, arg3 : c_int, ref arg4 : c_fn_ptr) : c_int;

extern proc sqlite3_bind_text16(ref arg0 : sqlite3_stmt, arg1 : c_int, arg2 : c_void_ptr, arg3 : c_int, ref arg4 : c_fn_ptr) : c_int;

extern proc sqlite3_bind_text64(ref arg0 : sqlite3_stmt, arg1 : c_int, arg2 : c_string, arg3 : sqlite3_uint64, ref arg4 : c_fn_ptr, encoding : c_uchar) : c_int;

extern proc sqlite3_bind_value(ref arg0 : sqlite3_stmt, arg1 : c_int, ref arg2 : sqlite3_value) : c_int;

extern proc sqlite3_bind_zeroblob(ref arg0 : sqlite3_stmt, arg1 : c_int, n : c_int) : c_int;

extern proc sqlite3_bind_zeroblob64(ref arg0 : sqlite3_stmt, arg1 : c_int, arg2 : sqlite3_uint64) : c_int;

extern proc sqlite3_bind_parameter_count(ref arg0 : sqlite3_stmt) : c_int;

extern proc sqlite3_bind_parameter_name(ref arg0 : sqlite3_stmt, arg1 : c_int) : c_string;

extern proc sqlite3_bind_parameter_index(ref arg0 : sqlite3_stmt, zName : c_string) : c_int;

extern proc sqlite3_clear_bindings(ref arg0 : sqlite3_stmt) : c_int;

extern proc sqlite3_column_count(ref pStmt : sqlite3_stmt) : c_int;

extern proc sqlite3_column_name(ref arg0 : sqlite3_stmt, N : c_int) : c_string;

extern proc sqlite3_column_name16(ref arg0 : sqlite3_stmt, N : c_int) : c_void_ptr;

extern proc sqlite3_column_database_name(ref arg0 : sqlite3_stmt, arg1 : c_int) : c_string;

extern proc sqlite3_column_database_name16(ref arg0 : sqlite3_stmt, arg1 : c_int) : c_void_ptr;

extern proc sqlite3_column_table_name(ref arg0 : sqlite3_stmt, arg1 : c_int) : c_string;

extern proc sqlite3_column_table_name16(ref arg0 : sqlite3_stmt, arg1 : c_int) : c_void_ptr;

extern proc sqlite3_column_origin_name(ref arg0 : sqlite3_stmt, arg1 : c_int) : c_string;

extern proc sqlite3_column_origin_name16(ref arg0 : sqlite3_stmt, arg1 : c_int) : c_void_ptr;

extern proc sqlite3_column_decltype(ref arg0 : sqlite3_stmt, arg1 : c_int) : c_string;

extern proc sqlite3_column_decltype16(ref arg0 : sqlite3_stmt, arg1 : c_int) : c_void_ptr;

extern proc sqlite3_step(ref arg0 : sqlite3_stmt) : c_int;

extern proc sqlite3_data_count(ref pStmt : sqlite3_stmt) : c_int;

extern proc sqlite3_column_blob(ref arg0 : sqlite3_stmt, iCol : c_int) : c_void_ptr;

extern proc sqlite3_column_bytes(ref arg0 : sqlite3_stmt, iCol : c_int) : c_int;

extern proc sqlite3_column_bytes16(ref arg0 : sqlite3_stmt, iCol : c_int) : c_int;

extern proc sqlite3_column_double(ref arg0 : sqlite3_stmt, iCol : c_int) : c_double;

extern proc sqlite3_column_int(ref arg0 : sqlite3_stmt, iCol : c_int) : c_int;

extern proc sqlite3_column_int64(ref arg0 : sqlite3_stmt, iCol : c_int) : sqlite3_int64;

extern proc sqlite3_column_text(ref arg0 : sqlite3_stmt, iCol : c_int) : c_ptr(c_uchar);

extern proc sqlite3_column_text16(ref arg0 : sqlite3_stmt, iCol : c_int) : c_void_ptr;

extern proc sqlite3_column_type(ref arg0 : sqlite3_stmt, iCol : c_int) : c_int;

extern proc sqlite3_column_value(ref arg0 : sqlite3_stmt, iCol : c_int) : c_ptr(sqlite3_value);

extern proc sqlite3_finalize(ref pStmt : sqlite3_stmt) : c_int;

extern proc sqlite3_reset(ref pStmt : sqlite3_stmt) : c_int;

extern proc sqlite3_create_function(ref db : sqlite3, zFunctionName : c_string, nArg : c_int, eTextRep : c_int, pApp : c_void_ptr, ref xFunc : c_fn_ptr, ref xStep : c_fn_ptr, ref xFinal : c_fn_ptr) : c_int;

extern proc sqlite3_create_function16(ref db : sqlite3, zFunctionName : c_void_ptr, nArg : c_int, eTextRep : c_int, pApp : c_void_ptr, ref xFunc : c_fn_ptr, ref xStep : c_fn_ptr, ref xFinal : c_fn_ptr) : c_int;

extern proc sqlite3_create_function_v2(ref db : sqlite3, zFunctionName : c_string, nArg : c_int, eTextRep : c_int, pApp : c_void_ptr, ref xFunc : c_fn_ptr, ref xStep : c_fn_ptr, ref xFinal : c_fn_ptr, ref xDestroy : c_fn_ptr) : c_int;

extern proc sqlite3_aggregate_count(ref arg0 : sqlite3_context) : c_int;

extern proc sqlite3_expired(ref arg0 : sqlite3_stmt) : c_int;

extern proc sqlite3_transfer_bindings(ref arg0 : sqlite3_stmt, ref arg1 : sqlite3_stmt) : c_int;

extern proc sqlite3_global_recover() : c_int;

extern proc sqlite3_thread_cleanup() : void;

extern proc sqlite3_memory_alarm(ref arg0 : c_fn_ptr, arg1 : c_void_ptr, arg2 : sqlite3_int64) : c_int;

extern proc sqlite3_value_blob(ref arg0 : sqlite3_value) : c_void_ptr;

extern proc sqlite3_value_bytes(ref arg0 : sqlite3_value) : c_int;

extern proc sqlite3_value_bytes16(ref arg0 : sqlite3_value) : c_int;

extern proc sqlite3_value_double(ref arg0 : sqlite3_value) : c_double;

extern proc sqlite3_value_int(ref arg0 : sqlite3_value) : c_int;

extern proc sqlite3_value_int64(ref arg0 : sqlite3_value) : sqlite3_int64;

extern proc sqlite3_value_text(ref arg0 : sqlite3_value) : c_ptr(c_uchar);

extern proc sqlite3_value_text16(ref arg0 : sqlite3_value) : c_void_ptr;

extern proc sqlite3_value_text16le(ref arg0 : sqlite3_value) : c_void_ptr;

extern proc sqlite3_value_text16be(ref arg0 : sqlite3_value) : c_void_ptr;

extern proc sqlite3_value_type(ref arg0 : sqlite3_value) : c_int;

extern proc sqlite3_value_numeric_type(ref arg0 : sqlite3_value) : c_int;

extern proc sqlite3_value_subtype(ref arg0 : sqlite3_value) : c_uint;

extern proc sqlite3_value_dup(ref arg0 : sqlite3_value) : c_ptr(sqlite3_value);

extern proc sqlite3_value_free(ref arg0 : sqlite3_value) : void;

extern proc sqlite3_aggregate_context(ref arg0 : sqlite3_context, nBytes : c_int) : c_void_ptr;

extern proc sqlite3_user_data(ref arg0 : sqlite3_context) : c_void_ptr;

extern proc sqlite3_context_db_handle(ref arg0 : sqlite3_context) : c_ptr(sqlite3);

extern proc sqlite3_get_auxdata(ref arg0 : sqlite3_context, N : c_int) : c_void_ptr;

extern proc sqlite3_set_auxdata(ref arg0 : sqlite3_context, N : c_int, arg2 : c_void_ptr, ref arg3 : c_fn_ptr) : void;

extern proc sqlite3_result_blob(ref arg0 : sqlite3_context, arg1 : c_void_ptr, arg2 : c_int, ref arg3 : c_fn_ptr) : void;

extern proc sqlite3_result_blob64(ref arg0 : sqlite3_context, arg1 : c_void_ptr, arg2 : sqlite3_uint64, ref arg3 : c_fn_ptr) : void;

extern proc sqlite3_result_double(ref arg0 : sqlite3_context, arg1 : c_double) : void;

extern proc sqlite3_result_error(ref arg0 : sqlite3_context, arg1 : c_string, arg2 : c_int) : void;

extern proc sqlite3_result_error16(ref arg0 : sqlite3_context, arg1 : c_void_ptr, arg2 : c_int) : void;

extern proc sqlite3_result_error_toobig(ref arg0 : sqlite3_context) : void;

extern proc sqlite3_result_error_nomem(ref arg0 : sqlite3_context) : void;

extern proc sqlite3_result_error_code(ref arg0 : sqlite3_context, arg1 : c_int) : void;

extern proc sqlite3_result_int(ref arg0 : sqlite3_context, arg1 : c_int) : void;

extern proc sqlite3_result_int64(ref arg0 : sqlite3_context, arg1 : sqlite3_int64) : void;

extern proc sqlite3_result_null(ref arg0 : sqlite3_context) : void;

extern proc sqlite3_result_text(ref arg0 : sqlite3_context, arg1 : c_string, arg2 : c_int, ref arg3 : c_fn_ptr) : void;

extern proc sqlite3_result_text64(ref arg0 : sqlite3_context, arg1 : c_string, arg2 : sqlite3_uint64, ref arg3 : c_fn_ptr, encoding : c_uchar) : void;

extern proc sqlite3_result_text16(ref arg0 : sqlite3_context, arg1 : c_void_ptr, arg2 : c_int, ref arg3 : c_fn_ptr) : void;

extern proc sqlite3_result_text16le(ref arg0 : sqlite3_context, arg1 : c_void_ptr, arg2 : c_int, ref arg3 : c_fn_ptr) : void;

extern proc sqlite3_result_text16be(ref arg0 : sqlite3_context, arg1 : c_void_ptr, arg2 : c_int, ref arg3 : c_fn_ptr) : void;

extern proc sqlite3_result_value(ref arg0 : sqlite3_context, ref arg1 : sqlite3_value) : void;

extern proc sqlite3_result_zeroblob(ref arg0 : sqlite3_context, n : c_int) : void;

extern proc sqlite3_result_zeroblob64(ref arg0 : sqlite3_context, n : sqlite3_uint64) : c_int;

extern proc sqlite3_result_subtype(ref arg0 : sqlite3_context, arg1 : c_uint) : void;

extern proc sqlite3_create_collation(ref arg0 : sqlite3, zName : c_string, eTextRep : c_int, pArg : c_void_ptr, ref xCompare : c_fn_ptr) : c_int;

extern proc sqlite3_create_collation_v2(ref arg0 : sqlite3, zName : c_string, eTextRep : c_int, pArg : c_void_ptr, ref xCompare : c_fn_ptr, ref xDestroy : c_fn_ptr) : c_int;

extern proc sqlite3_create_collation16(ref arg0 : sqlite3, zName : c_void_ptr, eTextRep : c_int, pArg : c_void_ptr, ref xCompare : c_fn_ptr) : c_int;

extern proc sqlite3_collation_needed(ref arg0 : sqlite3, arg1 : c_void_ptr, ref arg2 : c_fn_ptr) : c_int;

extern proc sqlite3_collation_needed16(ref arg0 : sqlite3, arg1 : c_void_ptr, ref arg2 : c_fn_ptr) : c_int;

extern proc sqlite3_sleep(arg0 : c_int) : c_int;

extern var sqlite3_temp_directory : c_string;

extern var sqlite3_data_directory : c_string;

extern proc sqlite3_get_autocommit(ref arg0 : sqlite3) : c_int;

extern proc sqlite3_db_handle(ref arg0 : sqlite3_stmt) : c_ptr(sqlite3);

extern proc sqlite3_db_filename(ref db : sqlite3, zDbName : c_string) : c_string;

extern proc sqlite3_db_readonly(ref db : sqlite3, zDbName : c_string) : c_int;

extern proc sqlite3_next_stmt(ref pDb : sqlite3, ref pStmt : sqlite3_stmt) : c_ptr(sqlite3_stmt);

extern proc sqlite3_commit_hook(ref arg0 : sqlite3, ref arg1 : c_fn_ptr, arg2 : c_void_ptr) : c_void_ptr;

extern proc sqlite3_rollback_hook(ref arg0 : sqlite3, ref arg1 : c_fn_ptr, arg2 : c_void_ptr) : c_void_ptr;

extern proc sqlite3_update_hook(ref arg0 : sqlite3, ref arg1 : c_fn_ptr, arg2 : c_void_ptr) : c_void_ptr;

extern proc sqlite3_enable_shared_cache(arg0 : c_int) : c_int;

extern proc sqlite3_release_memory(arg0 : c_int) : c_int;

extern proc sqlite3_db_release_memory(ref arg0 : sqlite3) : c_int;

extern proc sqlite3_soft_heap_limit64(N : sqlite3_int64) : sqlite3_int64;

extern proc sqlite3_soft_heap_limit(N : c_int) : void;

extern proc sqlite3_table_column_metadata(ref db : sqlite3, zDbName : c_string, zTableName : c_string, zColumnName : c_string, ref pzDataType : c_string, ref pzCollSeq : c_string, ref pNotNull : c_int, ref pPrimaryKey : c_int, ref pAutoinc : c_int) : c_int;

extern proc sqlite3_load_extension(ref db : sqlite3, zFile : c_string, zProc : c_string, ref pzErrMsg : c_string) : c_int;

extern proc sqlite3_enable_load_extension(ref db : sqlite3, onoff : c_int) : c_int;

extern proc sqlite3_auto_extension(ref xEntryPoint : c_fn_ptr) : c_int;

extern proc sqlite3_cancel_auto_extension(ref xEntryPoint : c_fn_ptr) : c_int;

extern proc sqlite3_reset_auto_extension() : void;

extern record sqlite3_module {
  var iVersion : c_int;
  var xCreate : c_fn_ptr;
  var xConnect : c_fn_ptr;
  var xBestIndex : c_fn_ptr;
  var xDisconnect : c_fn_ptr;
  var xDestroy : c_fn_ptr;
  var xOpen : c_fn_ptr;
  var xClose : c_fn_ptr;
  var xFilter : c_fn_ptr;
  var xNext : c_fn_ptr;
  var xEof : c_fn_ptr;
  var xColumn : c_fn_ptr;
  var xRowid : c_fn_ptr;
  var xUpdate : c_fn_ptr;
  var xBegin : c_fn_ptr;
  var xSync : c_fn_ptr;
  var xCommit : c_fn_ptr;
  var xRollback : c_fn_ptr;
  var xFindFunction : c_fn_ptr;
  var xRename : c_fn_ptr;
  var xSavepoint : c_fn_ptr;
  var xRelease : c_fn_ptr;
  var xRollbackTo : c_fn_ptr;
}

extern record sqlite3_index_constraint {
  var iColumn : c_int;
  var op : c_uchar;
  var usable : c_uchar;
  var iTermOffset : c_int;
}

extern record sqlite3_index_orderby {
  var iColumn : c_int;
  var desc : c_uchar;
}

extern record sqlite3_index_constraint_usage {
  var argvIndex : c_int;
  var omit : c_uchar;
}

extern record sqlite3_index_info {
  var nConstraint : c_int;
  var aConstraint : c_ptr(sqlite3_index_constraint);
  var nOrderBy : c_int;
  var aOrderBy : c_ptr(sqlite3_index_orderby);
  var aConstraintUsage : c_ptr(sqlite3_index_constraint_usage);
  var idxNum : c_int;
  var idxStr : c_string;
  var needToFreeIdxStr : c_int;
  var orderByConsumed : c_int;
  var estimatedCost : c_double;
  var estimatedRows : sqlite3_int64;
  var idxFlags : c_int;
  var colUsed : sqlite3_uint64;
}

extern proc sqlite3_create_module(ref db : sqlite3, zName : c_string, ref p : sqlite3_module, pClientData : c_void_ptr) : c_int;

extern proc sqlite3_create_module_v2(ref db : sqlite3, zName : c_string, ref p : sqlite3_module, pClientData : c_void_ptr, ref xDestroy : c_fn_ptr) : c_int;

extern record sqlite3_vtab {
  var pModule : c_ptr(sqlite3_module);
  var nRef : c_int;
  var zErrMsg : c_string;
}

extern record sqlite3_vtab_cursor {
  var pVtab : c_ptr(sqlite3_vtab);
}

extern proc sqlite3_declare_vtab(ref arg0 : sqlite3, zSQL : c_string) : c_int;

extern proc sqlite3_overload_function(ref arg0 : sqlite3, zFuncName : c_string, nArg : c_int) : c_int;

extern proc sqlite3_blob_open(ref arg0 : sqlite3, zDb : c_string, zTable : c_string, zColumn : c_string, iRow : sqlite3_int64, flags : c_int, ref ppBlob : c_ptr(sqlite3_blob)) : c_int;

extern proc sqlite3_blob_reopen(ref arg0 : sqlite3_blob, arg1 : sqlite3_int64) : c_int;

extern proc sqlite3_blob_close(ref arg0 : sqlite3_blob) : c_int;

extern proc sqlite3_blob_bytes(ref arg0 : sqlite3_blob) : c_int;

extern proc sqlite3_blob_read(ref arg0 : sqlite3_blob, Z : c_void_ptr, N : c_int, iOffset : c_int) : c_int;

extern proc sqlite3_blob_write(ref arg0 : sqlite3_blob, z : c_void_ptr, n : c_int, iOffset : c_int) : c_int;

extern proc sqlite3_vfs_find(zVfsName : c_string) : c_ptr(sqlite3_vfs);

extern proc sqlite3_vfs_register(ref arg0 : sqlite3_vfs, makeDflt : c_int) : c_int;

extern proc sqlite3_vfs_unregister(ref arg0 : sqlite3_vfs) : c_int;

extern proc sqlite3_mutex_alloc(arg0 : c_int) : c_ptr(sqlite3_mutex);

extern proc sqlite3_mutex_free(ref arg0 : sqlite3_mutex) : void;

extern proc sqlite3_mutex_enter(ref arg0 : sqlite3_mutex) : void;

extern proc sqlite3_mutex_try(ref arg0 : sqlite3_mutex) : c_int;

extern proc sqlite3_mutex_leave(ref arg0 : sqlite3_mutex) : void;

extern record sqlite3_mutex_methods {
  var xMutexInit : c_fn_ptr;
  var xMutexEnd : c_fn_ptr;
  var xMutexAlloc : c_fn_ptr;
  var xMutexFree : c_fn_ptr;
  var xMutexEnter : c_fn_ptr;
  var xMutexTry : c_fn_ptr;
  var xMutexLeave : c_fn_ptr;
  var xMutexHeld : c_fn_ptr;
  var xMutexNotheld : c_fn_ptr;
}

extern proc sqlite3_mutex_held(ref arg0 : sqlite3_mutex) : c_int;

extern proc sqlite3_mutex_notheld(ref arg0 : sqlite3_mutex) : c_int;

extern proc sqlite3_db_mutex(ref arg0 : sqlite3) : c_ptr(sqlite3_mutex);

extern proc sqlite3_file_control(ref arg0 : sqlite3, zDbName : c_string, op : c_int, arg3 : c_void_ptr) : c_int;

extern proc sqlite3_test_control(op : c_int, c__varargs ...) : c_int;

// Overload for empty varargs
extern proc sqlite3_test_control(op : c_int) : c_int;

extern proc sqlite3_status(op : c_int, ref pCurrent : c_int, ref pHighwater : c_int, resetFlag : c_int) : c_int;

extern proc sqlite3_status64(op : c_int, ref pCurrent : sqlite3_int64, ref pHighwater : sqlite3_int64, resetFlag : c_int) : c_int;

extern proc sqlite3_db_status(ref arg0 : sqlite3, op : c_int, ref pCur : c_int, ref pHiwtr : c_int, resetFlg : c_int) : c_int;

extern proc sqlite3_stmt_status(ref arg0 : sqlite3_stmt, op : c_int, resetFlg : c_int) : c_int;

extern record sqlite3_pcache_page {
  var pBuf : c_void_ptr;
  var pExtra : c_void_ptr;
}

extern record sqlite3_pcache_methods2 {
  var iVersion : c_int;
  var pArg : c_void_ptr;
  var xInit : c_fn_ptr;
  var xShutdown : c_fn_ptr;
  var xCreate : c_fn_ptr;
  var xCachesize : c_fn_ptr;
  var xPagecount : c_fn_ptr;
  var xFetch : c_fn_ptr;
  var xUnpin : c_fn_ptr;
  var xRekey : c_fn_ptr;
  var xTruncate : c_fn_ptr;
  var xDestroy : c_fn_ptr;
  var xShrink : c_fn_ptr;
}

extern record sqlite3_pcache_methods {
  var pArg : c_void_ptr;
  var xInit : c_fn_ptr;
  var xShutdown : c_fn_ptr;
  var xCreate : c_fn_ptr;
  var xCachesize : c_fn_ptr;
  var xPagecount : c_fn_ptr;
  var xFetch : c_fn_ptr;
  var xUnpin : c_fn_ptr;
  var xRekey : c_fn_ptr;
  var xTruncate : c_fn_ptr;
  var xDestroy : c_fn_ptr;
}

extern proc sqlite3_backup_init(ref pDest : sqlite3, zDestName : c_string, ref pSource : sqlite3, zSourceName : c_string) : c_ptr(sqlite3_backup);

extern proc sqlite3_backup_step(ref p : sqlite3_backup, nPage : c_int) : c_int;

extern proc sqlite3_backup_finish(ref p : sqlite3_backup) : c_int;

extern proc sqlite3_backup_remaining(ref p : sqlite3_backup) : c_int;

extern proc sqlite3_backup_pagecount(ref p : sqlite3_backup) : c_int;

extern proc sqlite3_unlock_notify(ref pBlocked : sqlite3, ref xNotify : c_fn_ptr, pNotifyArg : c_void_ptr) : c_int;

extern proc sqlite3_stricmp(arg0 : c_string, arg1 : c_string) : c_int;

extern proc sqlite3_strnicmp(arg0 : c_string, arg1 : c_string, arg2 : c_int) : c_int;

extern proc sqlite3_strglob(zGlob : c_string, zStr : c_string) : c_int;

extern proc sqlite3_strlike(zGlob : c_string, zStr : c_string, cEsc : c_uint) : c_int;

extern proc sqlite3_log(iErrCode : c_int, zFormat : c_string, c__varargs ...) : void;

// Overload for empty varargs
extern proc sqlite3_log(iErrCode : c_int,zFormat : c_string) : void;

extern proc sqlite3_wal_hook(ref arg0 : sqlite3, ref arg1 : c_fn_ptr, arg2 : c_void_ptr) : c_void_ptr;

extern proc sqlite3_wal_autocheckpoint(ref db : sqlite3, N : c_int) : c_int;

extern proc sqlite3_wal_checkpoint(ref db : sqlite3, zDb : c_string) : c_int;

extern proc sqlite3_wal_checkpoint_v2(ref db : sqlite3, zDb : c_string, eMode : c_int, ref pnLog : c_int, ref pnCkpt : c_int) : c_int;

extern proc sqlite3_vtab_config(ref arg0 : sqlite3, op : c_int, c__varargs ...) : c_int;

// Overload for empty varargs
extern proc sqlite3_vtab_config(ref arg0 : sqlite3,op : c_int) : c_int;

extern proc sqlite3_vtab_on_conflict(ref arg0 : sqlite3) : c_int;

extern proc sqlite3_stmt_scanstatus(ref pStmt : sqlite3_stmt, idx : c_int, iScanStatusOp : c_int, pOut : c_void_ptr) : c_int;

extern proc sqlite3_stmt_scanstatus_reset(ref arg0 : sqlite3_stmt) : void;

extern proc sqlite3_db_cacheflush(ref arg0 : sqlite3) : c_int;

extern proc sqlite3_system_errno(ref arg0 : sqlite3) : c_int;

extern proc sqlite3_snapshot_get(ref db : sqlite3, zSchema : c_string, ref ppSnapshot : c_ptr(sqlite3_snapshot)) : c_int;

extern proc sqlite3_snapshot_open(ref db : sqlite3, zSchema : c_string, ref pSnapshot : sqlite3_snapshot) : c_int;

extern proc sqlite3_snapshot_free(ref arg0 : sqlite3_snapshot) : void;

extern proc sqlite3_snapshot_cmp(ref p1 : sqlite3_snapshot, ref p2 : sqlite3_snapshot) : c_int;

extern proc sqlite3_snapshot_recover(ref db : sqlite3, zDb : c_string) : c_int;

extern proc sqlite3_rtree_geometry_callback(ref db : sqlite3, zGeom : c_string, ref xGeom : c_fn_ptr, pContext : c_void_ptr) : c_int;

extern record sqlite3_rtree_geometry {
  var pContext : c_void_ptr;
  var nParam : c_int;
  var aParam : c_ptr(sqlite3_rtree_dbl);
  var pUser : c_void_ptr;
  var xDelUser : c_fn_ptr;
}

extern proc sqlite3_rtree_query_callback(ref db : sqlite3, zQueryFunc : c_string, ref xQueryFunc : c_fn_ptr, pContext : c_void_ptr, ref xDestructor : c_fn_ptr) : c_int;

extern record sqlite3_rtree_query_info {
  var pContext : c_void_ptr;
  var nParam : c_int;
  var aParam : c_ptr(sqlite3_rtree_dbl);
  var pUser : c_void_ptr;
  var xDelUser : c_fn_ptr;
  var aCoord : c_ptr(sqlite3_rtree_dbl);
  var anQueue : c_ptr(c_uint);
  var nCoord : c_int;
  var iLevel : c_int;
  var mxLevel : c_int;
  var iRowid : sqlite3_int64;
  var rParentScore : sqlite3_rtree_dbl;
  var eParentWithin : c_int;
  var eWithin : c_int;
  var rScore : sqlite3_rtree_dbl;
  var apSqlParam : c_ptr(c_ptr(sqlite3_value));
}

extern record Fts5PhraseIter {
  var a : c_ptr(c_uchar);
  var b : c_ptr(c_uchar);
}

extern record Fts5ExtensionApi {
  var iVersion : c_int;
  var xUserData : c_fn_ptr;
  var xColumnCount : c_fn_ptr;
  var xRowCount : c_fn_ptr;
  var xColumnTotalSize : c_fn_ptr;
  var xTokenize : c_fn_ptr;
  var xPhraseCount : c_fn_ptr;
  var xPhraseSize : c_fn_ptr;
  var xInstCount : c_fn_ptr;
  var xInst : c_fn_ptr;
  var xRowid : c_fn_ptr;
  var xColumnText : c_fn_ptr;
  var xColumnSize : c_fn_ptr;
  var xQueryPhrase : c_fn_ptr;
  var xSetAuxdata : c_fn_ptr;
  var xGetAuxdata : c_fn_ptr;
  var xPhraseFirst : c_fn_ptr;
  var xPhraseNext : c_fn_ptr;
  var xPhraseFirstColumn : c_fn_ptr;
  var xPhraseNextColumn : c_fn_ptr;
}

extern record fts5_tokenizer {
  var xCreate : c_fn_ptr;
  var xDelete : c_fn_ptr;
  var xTokenize : c_fn_ptr;
}

extern record fts5_api {
  var iVersion : c_int;
  var xCreateTokenizer : c_fn_ptr;
  var xFindTokenizer : c_fn_ptr;
  var xCreateFunction : c_fn_ptr;
}

// ==== c2chapel typedefs ====

// Opaque struct?
extern record Fts5Context {};

// Opaque struct?
extern record Fts5Tokenizer {};

extern type fts5_extension_function = c_fn_ptr;

// Opaque struct?
extern record sqlite3 {};

// Opaque struct?
extern record sqlite3_api_routines {};

// Opaque struct?
extern record sqlite3_backup {};

// Opaque struct?
extern record sqlite3_blob {};

extern type sqlite3_callback = c_fn_ptr;

// Opaque struct?
extern record sqlite3_context {};

extern type sqlite3_destructor_type = c_fn_ptr;

extern type sqlite3_int64 = sqlite_int64;

// Opaque struct?
extern record sqlite3_mutex {};

// Opaque struct?
extern record sqlite3_pcache {};

extern type sqlite3_rtree_dbl = c_double;

extern record sqlite3_snapshot {
  var hidden : c_ptr(c_uchar);
}

// Opaque struct?
extern record sqlite3_stmt {};

extern type sqlite3_syscall_ptr = c_fn_ptr;

extern type sqlite3_uint64 = sqlite_uint64;

// Opaque struct?
extern record sqlite3_value {};

extern type sqlite_int64 = c_longlong;

extern type sqlite_uint64 = c_ulonglong;

// c2chapel thinks these typedefs are from the fake headers:
/*
extern type FILE = c_int;

extern type _LOCK_RECURSIVE_T = c_int;

extern type _LOCK_T = c_int;

extern type __FILE = c_int;

extern type __ULong = c_int;

extern type __builtin_va_list = c_int;

extern type __dev_t = c_int;

extern type __gid_t = c_int;

extern type __gnuc_va_list = c_int;

extern type __int16_t = c_int;

extern type __int32_t = c_int;

extern type __int64_t = c_int;

extern type __int8_t = c_int;

extern type __int_least16_t = c_int;

extern type __int_least32_t = c_int;

extern type __loff_t = c_int;

extern type __off_t = c_int;

extern type __pid_t = c_int;

extern type __s16 = c_int;

extern type __s32 = c_int;

extern type __s64 = c_int;

extern type __s8 = c_int;

extern type __sigset_t = c_int;

extern type __tzinfo_type = c_int;

extern type __tzrule_type = c_int;

extern type __u16 = c_int;

extern type __u32 = c_int;

extern type __u64 = c_int;

extern type __u8 = c_int;

extern type __uid_t = c_int;

extern type __uint16_t = c_int;

extern type __uint32_t = c_int;

extern type __uint64_t = c_int;

extern type __uint8_t = c_int;

extern type __uint_least16_t = c_int;

extern type __uint_least32_t = c_int;

extern type _flock_t = c_int;

extern type _fpos_t = c_int;

extern type _iconv_t = c_int;

extern type _mbstate_t = c_int;

extern type _off64_t = c_int;

extern type _off_t = c_int;

extern type _sig_func_ptr = c_int;

extern type _ssize_t = c_int;

extern type _types_fd_set = c_int;

extern type bool = _Bool;

extern type caddr_t = c_int;

extern type clock_t = c_int;

extern type clockid_t = c_int;

extern type cookie_close_function_t = c_int;

extern type cookie_io_functions_t = c_int;

extern type cookie_read_function_t = c_int;

extern type cookie_seek_function_t = c_int;

extern type cookie_write_function_t = c_int;

extern type daddr_t = c_int;

extern type dev_t = c_int;

extern type div_t = c_int;

extern type fd_mask = c_int;

extern type fpos_t = c_int;

extern type gid_t = c_int;

extern type ino_t = c_int;

extern type int16_t = c_int;

extern type int32_t = c_int;

extern type int64_t = c_int;

extern type int8_t = c_int;

extern type int_fast16_t = c_int;

extern type int_fast32_t = c_int;

extern type int_fast64_t = c_int;

extern type int_fast8_t = c_int;

extern type int_least16_t = c_int;

extern type int_least32_t = c_int;

extern type int_least64_t = c_int;

extern type int_least8_t = c_int;

extern type intmax_t = c_int;

extern type intptr_t = c_int;

extern type jmp_buf = c_int;

extern type key_t = c_int;

extern type ldiv_t = c_int;

extern type lldiv_t = c_int;

extern type mbstate_t = c_int;

extern type mode_t = c_int;

extern type nlink_t = c_int;

extern type off_t = c_int;

extern type pid_t = c_int;

extern type pthread_attr_t = c_int;

extern type pthread_barrier_t = c_int;

extern type pthread_barrierattr_t = c_int;

extern type pthread_cond_t = c_int;

extern type pthread_condattr_t = c_int;

extern type pthread_key_t = c_int;

extern type pthread_mutex_t = c_int;

extern type pthread_mutexattr_t = c_int;

extern type pthread_once_t = c_int;

extern type pthread_rwlock_t = c_int;

extern type pthread_rwlockattr_t = c_int;

extern type pthread_spinlock_t = c_int;

extern type pthread_t = c_int;

extern type ptrdiff_t = c_int;

extern type rlim_t = c_int;

extern type sa_family_t = c_int;

extern type sem_t = c_int;

extern type sig_atomic_t = c_int;

extern type siginfo_t = c_int;

extern type sigjmp_buf = c_int;

extern type sigset_t = c_int;

extern type size_t = c_int;

extern type ssize_t = c_int;

extern type stack_t = c_int;

extern type suseconds_t = c_int;

extern type time_t = c_int;

extern type timer_t = c_int;

extern type u_char = c_int;

extern type u_int = c_int;

extern type u_long = c_int;

extern type u_short = c_int;

extern type uid_t = c_int;

extern type uint = c_int;

extern type uint16_t = c_int;

extern type uint32_t = c_int;

extern type uint64_t = c_int;

extern type uint8_t = c_int;

extern type uint_fast16_t = c_int;

extern type uint_fast32_t = c_int;

extern type uint_fast64_t = c_int;

extern type uint_fast8_t = c_int;

extern type uint_least16_t = c_int;

extern type uint_least32_t = c_int;

extern type uint_least64_t = c_int;

extern type uint_least8_t = c_int;

extern type uintmax_t = c_int;

extern type uintptr_t = c_int;

extern type useconds_t = c_int;

extern type ushort = c_int;

extern type va_list = c_int;

extern type wchar_t = c_int;

extern type wint_t = c_int;

extern type z_stream = c_int;

*/
