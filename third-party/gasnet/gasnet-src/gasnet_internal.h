/*   $Source: bitbucket.org:berkeleylab/gasnet.git/gasnet_internal.h $
 * Description: GASNet header for internal definitions used in GASNet implementation
 * Copyright 2002, Dan Bonachea <bonachea@cs.berkeley.edu>
 * Terms of use are as specified in license.txt
 */

#ifndef _GASNET_INTERNAL_H
#define _GASNET_INTERNAL_H
#define _IN_GASNET_INTERNAL_H
#define _INCLUDED_GASNET_INTERNAL_H
#ifdef _INCLUDED_GASNETEX_H
  #error Internal GASNet code should not directly include gasnetex.h, just gasnet_internal.h
#endif

#include <gasnetex.h> /* MUST come first to ensure correct inttypes behavior */
#include <gasnet_tools.h>

#if GASNETI_NEED_GASNET_VIS_H
#include <gasnet_vis.h>
#endif

#if GASNETI_NEED_GASNET_COLL_H
#include <coll/gasnet_coll.h>
#endif

#if GASNETI_NEED_GASNET_RATOMIC_H
#include <gasnet_ratomic.h>
#endif

#if GASNETI_NEED_GASNET_MK_H
#include <gasnet_mk.h>
#endif

#if GASNETI_COMPILER_IS_UNKNOWN
  #error "Invalid attempt to build GASNet with a compiler other than the one probed at configure time"
#endif

GASNETI_BEGIN_EXTERNC
GASNETI_BEGIN_NOWARN

#include <gasnet_syncops.h>

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#if defined(HAVE_MALLOC_H) && !PLATFORM_OS_OPENBSD /* OpenBSD warns that malloc.h is obsolete */
#include <malloc.h> /* prevent problems with redefinition of malloc on solaris */
#endif

#if PLATFORM_COMPILER_SUN_C
  /* disable warnings triggerred by some macro idioms we use */
  #pragma error_messages(off, E_END_OF_LOOP_CODE_NOT_REACHED)
  #pragma error_messages(off, E_STATEMENT_NOT_REACHED)
#endif

extern int gasneti_init_done; /*  true after init */
extern int gasneti_attach_done; /*  true after attach */

/* conduit-independent sanity checks */
extern void gasneti_check_config_preinit(void);
extern void gasneti_check_config_postattach(void);

extern int gasneti_malloc_munmap_disabled;

/* decode the command-line arguments */
extern void gasneti_decode_args(int *argc, char ***argv);

/* extract exit coordination timeout from environment vars (with defaults) */
extern double gasneti_get_exittimeout(double dflt_max, double dflt_min, double dflt_factor, double lower_bound);

// Used in some conduits to coordinate user-provided exit code across layers
extern gasneti_atomic_t gasneti_exit_code;

/* Safe memory allocation/deallocation 
   Beware - in debug mode, gasneti_malloc/gasneti_calloc/gasneti_free are NOT
   compatible with malloc/calloc/free
   (freeing memory allocated from one using the other is likely to crash)
 */
#define gasneti_malloc(sz)           _gasneti_malloc((sz) GASNETI_CURLOCAARG)
#define gasneti_malloc_allowfail(sz) _gasneti_malloc_allowfail((sz) GASNETI_CURLOCAARG)
#define gasneti_calloc(N,S)          _gasneti_calloc(N,S GASNETI_CURLOCAARG)
#define gasneti_realloc(ptr,sz)      _gasneti_realloc((ptr),(sz) GASNETI_CURLOCAARG)
#define gasneti_free(ptr)	     _gasneti_free((ptr) GASNETI_CURLOCAARG)
#define gasneti_leak(ptr)	     _gasneti_leak((ptr) GASNETI_CURLOCAARG)
#define gasneti_strdup(ptr)	     _gasneti_strdup((ptr) GASNETI_CURLOCAARG)
#define gasneti_strndup(ptr,sz)      _gasneti_strndup((ptr),(sz) GASNETI_CURLOCAARG)
/* corresponding gasneti_memcheck fns are in gasnet_help.h */

// String append with safe-memory dynamic allocation
GASNETI_FORMAT_PRINTF(gasneti_sappendf,2,3,
extern char *gasneti_sappendf(char *s, const char *fmt, ...));

// Version of str[n]casecmp() available even w/o POSIX.1-2001
extern int gasneti_strcasecmp(const char *s1, const char *s2);
extern int gasneti_strncasecmp(const char *s1, const char *s2, size_t n);

#if GASNET_DEBUGMALLOC
  extern void *_gasneti_malloc(size_t nbytes, const char *curloc) GASNETI_MALLOC;
  extern void *_gasneti_malloc_allowfail(size_t nbytes, const char *curloc) GASNETI_MALLOC;
  extern void _gasneti_free(void *ptr, const char *curloc);
  extern void _gasneti_leak(void *ptr, const char *curloc);
  extern void *_gasneti_realloc(void *ptr, size_t sz, const char *curloc);
  extern void *_gasneti_calloc(size_t N, size_t S, const char *curloc) GASNETI_MALLOC;
  extern size_t _gasneti_memcheck(void *ptr, const char *curloc, int checktype);
  extern void gasneti_malloc_dump_liveobjects(FILE *fp);
#else
  GASNETI_INLINE(_gasneti_malloc) GASNETI_MALLOC
  void *_gasneti_malloc(size_t nbytes) {
    void *ret = NULL;
    GASNETI_STAT_EVENT_VAL(I, GASNET_MALLOC, nbytes);
    ret = malloc(nbytes);
    if_pf (ret == NULL && nbytes > 0) 
      gasneti_fatalerror("gasneti_malloc(%" PRIuSZ ") failed", nbytes);
    return ret;
  }
  GASNETI_INLINE(_gasneti_malloc_allowfail) GASNETI_MALLOC
  void *_gasneti_malloc_allowfail(size_t nbytes) {
    void *ret = NULL;
    GASNETI_STAT_EVENT_VAL(I, GASNET_MALLOC, nbytes);
    ret = malloc(nbytes);
    if_pf (ret == NULL && nbytes > 0) { /* allow a NULL return for out-of-memory */
      GASNETI_TRACE_PRINTF(I,("Warning: returning NULL for a failed gasneti_malloc(%" PRIuSZ ")",nbytes));
    }
    return ret;
  }
  GASNETI_INLINE(_gasneti_calloc) GASNETI_MALLOC
  void *_gasneti_calloc(size_t N, size_t S) {
    void *ret = NULL;
    GASNETI_STAT_EVENT_VAL(I, GASNET_MALLOC, (N*S));
    ret = calloc(N,S);
    if_pf (ret == NULL && N*S > 0) 
      gasneti_fatalerror("gasneti_calloc(%" PRIuSZ ",%" PRIuSZ ") failed", N, S);
    return ret;
  }
  GASNETI_INLINE(_gasneti_realloc)
  void *_gasneti_realloc(void *ptr, size_t nbytes) {
    void *ret = NULL;
    GASNETI_STAT_EVENT_VAL(I, GASNET_MALLOC, nbytes);
    ret = realloc(ptr, nbytes);
    if_pf (ret == NULL && nbytes > 0) 
      gasneti_fatalerror("gasneti_realloc(%" PRIuSZ ") failed", nbytes);
    return ret;
  }
  GASNETI_INLINE(_gasneti_free)
  void _gasneti_free(void *ptr) {
    GASNETI_STAT_EVENT_VAL(I, GASNET_FREE, 0); /* don't track free size in ndebug mode */
    if_pf (ptr == NULL) return;
    free(ptr);
  }
  /* the following allows "gasneti_leak(p = gasneti_malloc(sz));" */
  #define _gasneti_leak(_expr) ((void)(_expr))
#endif
GASNETI_MALLOCP(_gasneti_malloc)
GASNETI_MALLOCP(_gasneti_malloc_allowfail)
GASNETI_MALLOCP(_gasneti_calloc)

/* ------------------------------------------------------------------------------------ */
/* Enforce some of the GASNet conduit coding practices - see README */

#ifdef malloc
#undef malloc
#endif
#define gasneti_malloc_error  ERROR__GASNet_conduit_code_must_use_gasneti_malloc
#define malloc(n)             gasneti_malloc_error
#ifdef calloc
#undef calloc
#endif
#define gasneti_calloc_error  ERROR__GASNet_conduit_code_must_use_gasneti_calloc
#define calloc(n,s)           gasneti_calloc_error
#ifdef realloc
#undef realloc
#endif
#define gasneti_realloc_error ERROR__GASNet_conduit_code_must_use_gasneti_realloc
#define realloc(p,n)          gasneti_realloc_error
#ifdef strdup
#undef strdup
#endif
#define gasneti_strdup_error  ERROR__GASNet_conduit_code_must_use_gasneti_strdup
#define strdup(p)             gasneti_strdup_error
#ifdef strndup
#undef strndup
#endif
#define gasneti_strndup_error ERROR__GASNet_conduit_code_must_use_gasneti_strndup
#define strndup(p,n)          gasneti_strndup_error
#ifdef free
#undef free
#endif
#define gasneti_free_error    ERROR__GASNet_conduit_code_must_use_gasneti_free
#define free(p)               gasneti_free_error

#ifdef strcasecmp
#undef strcasecmp
#endif
#define gasneti_strcasecmp_error     ERROR__GASNet_conduit_code_must_use_gasneti_strcasecmp
#define strcasecmp(s1,s2)            gasneti_strcasecmp_error
#ifdef strncasecmp
#undef strncasecmp
#endif
#define gasneti_strncasecmp_error    ERROR__GASNet_conduit_code_must_use_gasneti_strncasecmp
#define strncasecmp(s1,s2,n)         gasneti_strncasecmp_error

#include <assert.h>
#undef assert
#define gasneti_assert_error  ERROR__GASNet_conduit_code_should_use_gasneti_assert
#define assert(x)             gasneti_assert_error

#if GASNETI_NO_FORK
  #ifdef fork
    #undef fork
  #endif
  #define gasneti_fork_error  ERROR__GASNet_conduit_code_calling_fork_while_GASNETI_NO_FORK
  #define fork()	      gasneti_fork_error
  #ifdef vfork
    #undef vfork
  #endif
  #define gasneti_vfork_error ERROR__GASNet_conduit_code_calling_vfork_while_GASNETI_NO_FORK
  #define vfork()	      gasneti_vfork_error
  #ifdef popen
    #undef popen
  #endif
  #define gasneti_popen_error ERROR__GASNet_conduit_code_calling_popen_while_GASNETI_NO_FORK
  #define popen(c,t)	      gasneti_popen_error
  #ifdef system
    #undef system
  #endif
  #define gasneti_system_error ERROR__GASNet_conduit_code_calling_system_while_GASNETI_NO_FORK
  #define system(s)            gasneti_system_error
#endif

#define gasneti_thunk_error    ERROR__GASNet_conduit_code_must_not_use_gasneti_thunk_variables
#ifdef gasneti_thunk_client
#undef gasneti_thunk_client
#endif
#define gasneti_thunk_client   gasneti_thunk_error
#ifdef gasneti_thunk_endpoint
#undef gasneti_thunk_endpoint
#endif
#define gasneti_thunk_endpoint gasneti_thunk_error
#ifdef gasneti_thunk_tm
#undef gasneti_thunk_tm
#endif
#define gasneti_thunk_tm       gasneti_thunk_error
#ifdef gasneti_thunk_segment
#undef gasneti_thunk_segment
#endif
#define gasneti_thunk_segment  gasneti_thunk_error

/* ------------------------------------------------------------------------------------ */
/* Version of strdup() which is compatible w/ gasneti_free(), instead of plain free() */
GASNETI_INLINE(_gasneti_strdup) GASNETI_MALLOC
char *_gasneti_strdup(const char *s GASNETI_CURLOCFARG) {
  char *retval;
  if_pf (s == NULL) {
    /* special case to avoid strlen(NULL) */
    retval = (char *)_gasneti_malloc(1 GASNETI_CURLOCPARG);
    retval[0] = '\0';
  } else {
    size_t sz = strlen(s) + 1;
    retval = (char *)memcpy((char *)_gasneti_malloc(sz GASNETI_CURLOCPARG), s, sz);
  }
  return retval;
}
GASNETI_MALLOCP(_gasneti_strdup)
/* Like gasneti_strdup, but copy is limited to at most n characters.
 * Note allocation is upto n+1 bytes, due to the '\0' termination.
 */
GASNETI_INLINE(_gasneti_strndup) GASNETI_MALLOC
char *_gasneti_strndup(const char *s, size_t n GASNETI_CURLOCFARG) {
  char *retval;
  if_pf (s == NULL) {
    retval = (char *)_gasneti_malloc(1 GASNETI_CURLOCPARG);
    retval[0] = '\0';
  } else {
    size_t len;
    for (len = 0; len < n && s[len]; len++) ;
    retval = _gasneti_malloc(len + 1 GASNETI_CURLOCPARG);
    memcpy(retval, s, len);
    retval[len] = '\0';
  }
  return retval;
}
GASNETI_MALLOCP(_gasneti_strndup)

/* Version of glibc's getline compatible w/ gasneti_free() */
#if defined(__GLIBC__) && !defined(GASNET_DEBUGMALLOC)
  #define gasneti_getline getline
#else
  extern ssize_t gasneti_getline(char **buf_p, size_t *n_p, FILE *fp);
#endif
/* ------------------------------------------------------------------------------------ */

extern void gasneti_freezeForDebugger(void);

#if PLATFORM_OS_LINUX
  // dynamic check for Linux flavor, to detect binary porting
  // return non-zero iff this Linux system is actually Microsoft Windows Subsystem for Linux
  extern int gasneti_platform_isWSL(void);
#endif

/* GASNET_DEBUG_VERBOSE is set by configure to request job startup and general 
   status messages on stderr 
*/
#ifndef GASNET_DEBUG_VERBOSE
  #define GASNET_DEBUG_VERBOSE               0
#endif

/* ------------------------------------------------------------------------------------ */
/* Apply a reversible xform to obfuscate pointers exposed to clients in DEBUG builds
 *
 * NDEBUG:
 *   EXPORT: cast to the public type
 *   IMPORT: cast to the internal type
 * DEBUG:
 *   EXPORT: apply obfuscation to an internal pointer and cast
 *   IMPORT: remove obfuscation to reproduce the internal pointer and cast
 */
#if defined(GASNETI_EXPORT_POINTER) && defined(GASNETI_IMPORT_POINTER)
  /* Preserve existing definitions */
  /* When overriding:
   * Keep in mind that code is permitted call these macros in a GASNET_NDEBUG build.
   */
#elif !defined(GASNETI_EXPORT_POINTER) && !defined(GASNETI_IMPORT_POINTER)
  #if GASNETI_VALGRIND && !defined(GASNETI_SWIZZLE)
    #define GASNETI_SWIZZLE 0 // swizzling leads to "possible leaks" in valgrind
  #endif
  #if GASNETI_SWIZZLE || (GASNET_DEBUG && !defined(GASNETI_SWIZZLE))
    #undef GASNETI_SWIZZLE
    #define GASNETI_SWIZZLE 1
    /* Default xform is to invert all bits, except that NULL is preserved */
    GASNETI_INLINE(_gasneti_swizzle_pointer)
    uintptr_t _gasneti_swizzle_pointer(uintptr_t _p) { return _p ? ~_p : _p; }
    #define GASNETI_EXPORT_POINTER(type,ptr) ((type)_gasneti_swizzle_pointer((uintptr_t)(ptr)))
    #define GASNETI_IMPORT_POINTER(type,ptr) ((type)_gasneti_swizzle_pointer((uintptr_t)(ptr)))
  #else
    #undef GASNETI_SWIZZLE
    #define GASNETI_EXPORT_POINTER(type,ptr) ((type)(ptr))
    #define GASNETI_IMPORT_POINTER(type,ptr) ((type)(ptr))
  #endif
#elif defined(GASNETI_EXPORT_POINTER) || defined(GASNETI_IMPORT_POINTER)
  #error Must define both or neither of GASNETI_EXPORT_POINTER and GASNETI_IMPORT_POINTER
#endif

/* ------------------------------------------------------------------------------------ */
// Common handing of the basic object types

#define GASNETI_CLIENT_MAGIC       GASNETI_MAKE_MAGIC('C','L','I','t')
#define GASNETI_CLIENT_BAD_MAGIC   GASNETI_MAKE_BAD_MAGIC('C','L','I','t')

extern gasneti_Client_t gasneti_alloc_client(
                       const char *name, 
                       gex_Flags_t flags);
void gasneti_free_client(gasneti_Client_t client);

#define GASNETI_SEGMENT_MAGIC      GASNETI_MAKE_MAGIC('S','E','G','t')
#define GASNETI_SEGMENT_BAD_MAGIC  GASNETI_MAKE_BAD_MAGIC('S','E','G','t')

extern gasneti_Segment_t gasneti_alloc_segment(
                       gasneti_Client_t client,
                       void *addr,
                       uintptr_t len,
                       gex_MK_t kind,
                       int client_allocated,
                       gex_Flags_t flags);
void gasneti_free_segment(gasneti_Segment_t segment);

#define GASNETI_EP_MAGIC           GASNETI_MAKE_MAGIC('E','P','_','t')
#define GASNETI_EP_BAD_MAGIC       GASNETI_MAKE_BAD_MAGIC('E','P','_','t')

#define GASNETI_TM_MAGIC           GASNETI_MAKE_MAGIC('T','M','_','t')
#define GASNETI_TM_BAD_MAGIC       GASNETI_MAKE_BAD_MAGIC('T','M','_','t')

extern gasneti_TM_t gasneti_alloc_tm(
                       gasneti_EP_t ep,
                       gex_Rank_t rank,
                       gex_Rank_t size,
                       gex_Flags_t flags);
void gasneti_free_tm(gasneti_TM_t tm);

/* ------------------------------------------------------------------------------------ */
/* Return a pointer to a handler table containing the handlers of
    the core (gasnetc_) or extended (gasnete_) API, which will be
    automatically registered upon endpoint creation.
   Tables are terminated with an entry where fnptr == NULL.
   Core API handlers are restricted to indices in the range
      [GASNETC_HANDLER_BASE, GASNETE_HANDLER_BASE)
   Extended API handlers are restricted to indices in the range
      [GASNETE_HANDLER_BASE, GASNETI_CLIENT_HANDLER_BASE)
*/
extern gex_AM_Entry_t const *gasnetc_get_handlertable(void);
extern gex_AM_Entry_t const *gasnete_get_handlertable(void);

/* ------------------------------------------------------------------------------------ */
// TODO-EX: Please remove this!
//
// These macros are a "necessary evil" until all internal interfaces have been
// updated to propogate Client, TM, EP and Segment arguments.
// For the time being there is at most one of each of those objects.
//
// Results are undefined prior to return from gex_Client_Init() or gasnet_init().
//
extern gasneti_TM_t gasneti_thing_that_goes_thunk_in_the_dark;
#define gasneti_THUNK_TM      gasneti_export_tm(gasneti_thing_that_goes_thunk_in_the_dark)
#define gasneti_THUNK_EP      gasneti_export_ep(gasneti_thing_that_goes_thunk_in_the_dark->_ep)
#define gasneti_THUNK_CLIENT  gasneti_export_client(gasneti_thing_that_goes_thunk_in_the_dark->_ep->_client)
#define gasneti_THUNK_SEGMENT gasneti_export_segment(gasneti_thing_that_goes_thunk_in_the_dark->_ep->_segment)

/* ------------------------------------------------------------------------------------ */
// EP management

GASNETI_INLINE(gasneti_i_tm_to_i_ep)
gasneti_EP_t gasneti_i_tm_to_i_ep(gasneti_TM_t i_tm) {
  gasneti_assert(i_tm);
  if (gasneti_i_tm_is_pair(i_tm)) {
    // Lookup EP in per-client table
    gex_EP_Index_t ep_idx = gasneti_tm_pair_loc_idx(gasneti_i_tm_to_pair(i_tm));
    gasneti_Client_t i_client = gasneti_import_client(gasneti_THUNK_CLIENT); // TODO: multi-client
    gasneti_assert_int(ep_idx ,<, GASNET_MAXEPS);
    gasneti_assert_int(ep_idx ,<, gasneti_weakatomic32_read(&i_client->_next_ep_index, 0));
    gasneti_EP_t i_ep = i_client->_ep_tbl[ep_idx];
    gasneti_assert(i_ep);
    return i_ep;
  } else {
    return i_tm->_ep;
  }
}
#define gasneti_e_tm_to_i_ep(e_tm) gasneti_i_tm_to_i_ep(gasneti_import_tm(e_tm))

/* ------------------------------------------------------------------------------------ */
// Internal conduit interface to spawner
//
// NOTE: Though NbrhdBroadcast and HostBroadcast have semantics which require only
// local data movement, implementations are peritted to use global communication
// (such as via AM{MPI,UDP}_SPMDBroadcast()).  Consequently, calls must be
// collective across *all* ranks, not just across ranks in the same neighborhood
// or host.  The `len` argument must be single-valued across every rank in the
// job.  The `root` arguent need only be single-valued within the {nbrhd, host}
// scope of the broadcast, but must identify a root process in the caller's
// {nbrhd, host}.

typedef void (*gasneti_bootstrapExchangefn_t)(void *src, size_t len, void *dest);
typedef void (*gasneti_bootstrapBroadcastfn_t)(void *src, size_t len, void *dest, int rootnode);
typedef void (*gasneti_bootstrapBarrierfn_t)(void);

typedef struct {
  gasneti_bootstrapBarrierfn_t Barrier;
  gasneti_bootstrapExchangefn_t Exchange;
  gasneti_bootstrapBroadcastfn_t Broadcast;
  gasneti_bootstrapBroadcastfn_t NbrhdBroadcast;
  gasneti_bootstrapBroadcastfn_t HostBroadcast;
  void (*Alltoall)(void *src, size_t len, void *dest);
  void (*Abort)(int exitcode);
  void (*Cleanup)(void);
  void (*Fini)(void);
} gasneti_spawnerfn_t;

extern gasneti_spawnerfn_t const *gasneti_spawnerInit(int *argc_p, char ***argv_p,
                                  const char *force_spawner,
                                  gex_Rank_t *nodes_p, gex_Rank_t *mynode_p);

extern int gasneti_spawn_verbose;

/* ------------------------------------------------------------------------------------ */
/* memory segment registration and management */

GASNETI_COLD
extern void gasneti_defaultSignalHandler(int sig);

/* gasneti_max_segsize() is the user-selected limit for the max mmap size, as gleaned from several sources */
uintptr_t gasneti_max_segsize(void);
#if defined(HAVE_MMAP) || GASNET_PSHM
  #define GASNETI_MMAP_OR_PSHM 1
  extern gasnet_seginfo_t gasneti_mmap_segment_search(uintptr_t maxsz);
 #if defined(HAVE_MMAP)
  extern void *gasneti_mmap_fixed(void *segbase, uintptr_t segsize, int mayfail);
  extern void *gasneti_mmap(uintptr_t segsize);
  extern void gasneti_munmap(void *segbase, uintptr_t segsize);
 #endif
 #if defined(GASNETI_USE_HUGETLBFS)
  extern size_t gasneti_hugepagesize(void);
  extern void *gasneti_huge_mmap(void *addr, uintptr_t size);
  extern void gasneti_huge_munmap(void *addr, uintptr_t size);
 #endif
  #define GASNETI_MMAP_LIMIT gasneti_max_segsize()
  #ifndef GASNETI_MMAP_GRANULARITY
    /* GASNETI_MMAP_GRANULARITY is the minimum increment used by the mmap binary search */
    #define GASNETI_MMAP_GRANULARITY  (((size_t)2)<<21)  /* 4 MB */
  #endif
#endif

#if GASNET_PSHM
  extern int gasneti_use_shared_allocator;
#endif

// Allocate/map memory intended for use as segment.
// May be called non-collectively, as from gex_Segment_Create().
// Also called collectively, as from gex_Segment_Attach() and aux seg creation.
// Boolean 'pshm_compat' requests allocation of memory which is compatible with
// cross-mapping by PSHM (only fully implemented for the collective cases of
// gex_Segment_Attach() and aux seg creation).
int gasneti_segment_map(gasnet_seginfo_t *segment_p,
                        uintptr_t segsize,
                        int pshm_compat,
                        gex_Flags_t flags);
// Undo gasneti_segment_map()
int gasneti_segment_unmap(
                        gasnet_seginfo_t *segment_p,
                        int pshm_compat);

#ifndef GASNETI_USE_HIGHSEGMENT
#define GASNETI_USE_HIGHSEGMENT 1  /* use the high end of mmap segments */
#endif

uint64_t gasneti_sharedLimit(void);
#ifdef GASNETI_MMAP_OR_PSHM
uintptr_t gasneti_segmentLimit(uintptr_t localLimit, uint64_t sharedLimit,
                            gasneti_bootstrapExchangefn_t exchangefn,
                            gasneti_bootstrapBarrierfn_t barrierfn);
#endif /* GASNETI_MMAP_OR_PSHM */

void gasneti_segmentInit(uintptr_t localSegmentLimit,
                         gasneti_bootstrapExchangefn_t exchangefn,
                         gex_Flags_t flags);
int gasneti_segmentAttach(
                gex_Segment_t                 *segment_p,
                gex_TM_t                      tm,
                uintptr_t                     segsize,
                gex_Flags_t                   flags);
int gasneti_segmentCreate(
                gex_Segment_t           *segment_t,
                gasneti_Client_t        client,
                gex_Addr_t              address,
                uintptr_t               length,
                gex_MK_t                kind,
                gex_Flags_t             flags);
int gasneti_segmentDestroy(
                gasneti_Segment_t       i_segment,
                int                     create_hook_succeeded);

int gasneti_EP_PublishBoundSegment(
            gex_TM_t       tm,
            gex_EP_t       *eps,
            size_t         num_eps,
            gex_Flags_t    flags);

extern void gasneti_legacy_segment_attach_hook(gasneti_EP_t ep);
extern void gasneti_legacy_alloc_tm_hook(gasneti_TM_t _tm);

void gasneti_setupGlobalEnvironment(gex_Rank_t numnodes, gex_Rank_t mynode,
                                     gasneti_bootstrapExchangefn_t exchangefn,
                                     gasneti_bootstrapBroadcastfn_t broadcastfn);

#define GASNETI_PROPAGATE_ENV_NAME   0
#define GASNETI_PROPAGATE_ENV_PREFIX 1
extern void (*gasneti_propagate_env_hook)(const char *, int); // spawner- or conduit-specific hook
extern void gasneti_propagate_env_helper(const char *environ, const char * keyname, int flags);
extern void gasneti_propagate_env(const char *keyname, int flags);

/* signature for internally-registered functions that need auxseg space -
   space in the gasnet-registered heap which is hidden from the client.
   The callback is registered by adding the function pointer to GASNET*_AUXSEG_FNS()
   Each registered function is called twice by the GASNet framework at startup:
   * first callback is a "how much space do you want" query
    it occurs between init/attach with auxseg_info == NULL, 
    function should return the absolute minimum and desired auxseg space
    currently, all nodes MUST return the same value (may be relaxed in the future)
   * second callback is "ok, here's what you got"
    it happens after attach and before gasnete_init, with auxseg_info
    set to the array (gasneti_nodes elements) of auxseg components on each node
    indicating the space assigned to this auxseg consumer.
    callee must copy the array of metadata if it wants to keep it 
    (the seg space it references is permanent)
 */
typedef struct {
  uintptr_t minsz;
  uintptr_t optimalsz;
} gasneti_auxseg_request_t;

typedef gasneti_auxseg_request_t (*gasneti_auxsegregfn_t)(gasnet_seginfo_t *auxseg_info);

// collect and return optimal auxseg size sum, padded to page size
// may be called multiple times, subsequent calls return cached value
uintptr_t gasneti_auxseg_preinit(void);

/* provide auxseg to GASNet components and init secondary segment arrays 
   requires input auxseg_info has been initialized to the correct values
 */
void gasneti_auxseg_attach(gasnet_seginfo_t *auxseg_info);

/* common case use of gasneti_auxseg_{preinit,attach} for conduits using gasneti_segmentAttach() */
gasnet_seginfo_t gasneti_auxsegAttach(uint64_t maxsize, gasneti_bootstrapExchangefn_t exchangefn);

/* ------------------------------------------------------------------------------------ */
// Hooks to invoke conduit-specific functionality from common conduit-independent code.
// Conduits requiring use of one or more of these should define the
// corresponding preprocessor identifier in their gasnet_core_fwd.h.

#if GASNETC_SEGMENT_CREATE_HOOK
// Called after all conduit-independent segment creation steps in
// gex_Segment_Create().  Typical use of this hook includes (purely local)
// memory registration.
//
// All relevant options to the Create call (such as addr, len, and flags) are
// accessible as fields of the sole argument (of type gex_Segment_t).
//
// On success, returns GASNET_OK and the infrastructure will call the
// matching destroy hook (if any), when the segment is destroyed.
// On failure, returns any other value and the infrastructure will NOT call
// any matching destroy hook, leaving this hook responsible for cleanup of
// any conduit-specific state prior to such an error return.
extern int gasnetc_segment_create_hook(gex_Segment_t e_segment);
#endif

#if GASNETC_SEGMENT_DESTROY_HOOK
// Called prior to any conduit-independent segment destruction steps, for
// instance in gex_Segment_Destroy().  Typical use of this hook includes
// (purely local) memory deregistration.
//
// The hook may assume that a prior gasnetc_segment_create_hook() (if any)
// has returned GASNET_OK.
extern void gasnetc_segment_destroy_hook(gasneti_Segment_t i_segment);
#endif

#if GASNETC_EP_BINDSEGMENT_HOOK
// Called by gex_EP_BindSegment() after argument checking, but before any
// conduit-independent segment binding steps.
// Use of this hook may include per-EP memory registration.
//
// Arguments provided to gex_EP_BindSegment() are also provided to this
// hook, but with their internal types.
extern int gasnetc_ep_bindsegment_hook(
                gasneti_EP_t        i_ep,
                gasneti_Segment_t   i_segment,
                gex_Flags_t         flags);
#endif

#if GASNETC_EP_PUBLISHBOUNDSEGMENT_HOOK
// Called after all conduit-independent segment creation steps in
// gex_EP_PublishBoundSegment().  Typical use of this hook includes
// communication of memory registration keys.
//
// All arguments provided to gex_EP_PublishBoundSegment() are also
// provided to this hook.
// Calls to this hook are collective over the given team.
//
// NOTE: subject to replacement by a pack/unpack pair of hooks when
// gex_EP_PublishBoundSegment() is enhanced to merge conduit-specific
// and conduit-independent communications.
extern int gasnetc_ep_publishboundsegment_hook(
                gex_TM_t               tm,
                gex_EP_t               *eps,
                size_t                 num_eps,
                gex_Flags_t            flags);
#endif

#if GASNETC_SEGMENT_ATTACH_HOOK
// Called after all conduit-independent segment attach steps in
// gex_Segment_Attach() and gasnet_attach().  Typical use of this hook
// includes memory registration and propagation of the registration keys.
//
// Arguments are the segment and the (currently always primordial) team.
// Other relevant options (addr, len, flags) are accessible as fields
// in the argument of type gex_Segment_t.
// Calls to this hook are collective over the given team.
//
// NOTE: subject to removal if/when the "attach" calls are reimplemented
// in terms of gex_Segment_Create() and gex_EP_PublishBoundSegment().
extern int gasnetc_segment_attach_hook(gex_Segment_t e_segment, gex_TM_t e_tm);
#endif

// Conduit-specific "primary attach" logic for use in the conduit-independent
// implementation of `gasnet_attach()`.
extern int gasnetc_attach_primary(gex_Flags_t);

/* ------------------------------------------------------------------------------------ */
/* GASNET-Internal OP Interface - provides a mechanism for conduit-independent services (like VIS)
   to expose non-blocking operations that utilize the regular GASNet op sync mechanisms
   Conduits provide three opaque scalar types: gasneti_eop_t, gasneti_iop_t and gasneti_aop_t
   and the following manipulator functions
 */

// TODO-EX: EOP_INTERFACE
//   Must generalize these interfaces beyond just put/get
//   At a minimum:
//     IOP interfaces must support all the counters
//     EOP interfaces must support LC
//   However, EOP will likely need to support more subevents in the future

#ifndef _GASNETI_EOP_T
#define _GASNETI_EOP_T
struct _gasneti_eop_S;
typedef const struct _gasneti_eop_S gasneti_eop_t;
#endif

#ifndef _GASNETI_IOP_T
#define _GASNETI_IOP_T
struct _gasneti_iop_S;
typedef const struct _gasneti_iop_S gasneti_iop_t;
#endif

#ifndef _GASNETI_AOP_T
#define _GASNETI_AOP_T
struct _gasneti_aop_S;
typedef const struct _gasneti_aop_S gasneti_aop_t;
#endif

/* create a new explicit-event NB operation
   represented with abstract type gasneti_eop_t
   and mark it in-flight */
gasneti_eop_t *gasneti_eop_create(GASNETI_THREAD_FARG_ALONE);

/* convert an gasneti_eop_t* created by an earlier call from this
   thread to gasneti_new_eop(), into a gex_Event_t suitable
   for this thread to later pass to gex_Event_Wait & friends */
#if GASNETI_EOP_IS_HANDLE
  #define gasneti_eop_to_event(eop) ((gex_Event_t)(eop))
#else
  gex_Event_t gasneti_eop_to_event(gasneti_eop_t *eop);
#endif

/* register noperations in-flight operations on the currently selected 
   implicit-event (NBI) context represented with abstract type gasneti_iop_t, 
   and return a pointer to that context
   if isput is non-zero, the registered operations are puts, otherwise they are gets */
gasneti_iop_t *gasneti_iop_register(unsigned int noperations, int isget GASNETI_THREAD_FARG);

/* given a valid (gasneti_eop_t*) or (gasneti_iop_t*) returned by an earlier call from any thread
 * to gasneti_new_eop() or gasneti_iop_register(), return non-zero iff it is the former (an eop)
   AMSAFE: must be safe to call in AM context */
int gasneti_op_is_eop(void *op);

/* given an gasneti_eop_t* returned by an earlier call from any thread
   to gasneti_new_eop(), mark that explicit-event NB operation complete
   such that a subsequent sync call on the relevant operation by the initiating
   thread may return success
   Caller is responsible for calling gasneti_sync_writes before calling this fn, if necessary
   AMSAFE: must be safe to call in AM context */
void gasneti_eop_markdone(gasneti_eop_t *eop);

/* given an gasneti_iop_t* returned by an earlier call from any thread
   to gasneti_iop_register(), increment that implicit-event (NBI) context
   to indicate that noperations have completed.
   if isput is non-zero, the operations are puts, otherwise they are gets
   noperations must not exceed the number of isput-type operations initiated
   on the given gasneti_iop_t by earlier calls to gasneti_iop_register
   Caller is responsible for calling gasneti_sync_writes before calling this fn, if necessary
   AMSAFE: must be safe to call in AM context */
void gasneti_iop_markdone(gasneti_iop_t *iop, unsigned int noperations, int isget);

// "aop" interfaces for manipulating implicit-event (NBI) contexts
//
// The abstract type gasneti_aop_t allows replacement of the currently selected
// implicit-event (NBI) context.
//
// An aop is thread-specific, and thus can only be operated on by the creating
// thread.  This may be relaxed in the future.
//
// Use of push and pop must be properly nested. To help detect violations, it is
// recommended to assert that the value returned by pop is the one your code
// pushed.
//
// The lifetime of an internal-use aop begins with a call to
// gasneti_aop_create() and ends with conversion to an event by a call to
// gasneti_aop_to_event().  It is invalid to pass an aop to any gasneti_aop_*
// functions after its conversion to an event.

// Create an aop.
// This call returns an gasneti_aop_t* which can be made current for this
// thread by calling gasneti_aop_push().
gasneti_aop_t *gasneti_aop_create(GASNETI_THREAD_FARG_ALONE);

// Convert an aop to an event.
// This call converts an aop allocated using gasneti_aop_create() to an
// gex_Event_t suitable to later pass to gex_Event_Wait and friends.
// The aop will be reaped when the event is synced in the normal manner.
// It is invalid to use an aop after conversion to an event.
// The aop must not be on the thread's stack of implicit-event (NBI) contexts.
gex_Event_t gasneti_aop_to_event(gasneti_aop_t *aop);

// Push an aop.
// The aop argument becomes the calling thread's active implicit-event (NBI)
// context, pushing it on a stack of such contexts to be subsequently removed
// from the top of that stack using gasneti_aop_pop().
void gasneti_aop_push(gasneti_aop_t *aop GASNETI_THREAD_FARG);

// Pop the current aop.
// The calling thread's active implicit-event (NBI) context is removed from its
// stack of such contexts and returned.  This context must have been created via
// gasneti_aop_create().
// It is erroneous to pop the implicit iop, or one created by the client's
// calls to gex_NBI_BeginAccessRegion().
// The only valid operations on a popped (paused) aop are to call
// gasneti_aop_push() or gasneti_aop_to_event().
gasneti_aop_t *gasneti_aop_pop(GASNETI_THREAD_FARG_ALONE);


// TODO-EX: EOP_INTERFACE
//   These next two are a stop-gap measure pending proper generalization.

/* registers in-flight remote atomic operation(s) ... */
gasneti_iop_t *gasneti_iop_register_rmw(unsigned int noperations GASNETI_THREAD_FARG);

/* marks in-flight remote atomic operation(s) as complete ... */
void gasneti_iop_markdone_rmw(gasneti_iop_t *iop, unsigned int noperations);

/* ------------------------------------------------------------------------------------ */
// memory kinds hooks

int gasneti_MK_Segment_Create(
            gasneti_Segment_t *i_segment_p,
            gasneti_Client_t  i_client,
            void              *address,
            uintptr_t         length,
            gex_MK_t          e_kind,
            gex_Flags_t       flags);
void gasneti_MK_Segment_Destroy(
            gasneti_Segment_t i_segment);

/* ------------------------------------------------------------------------------------ */
/* macros for returning errors that allow verbose error tracking */
extern int gasneti_VerboseErrors;
#define GASNETI_RETURN_ERR(type) do {                                        \
  if (gasneti_VerboseErrors) {                                               \
    gasneti_console_message("WARNING",                                       \
      "GASNet %s returning an error code: GASNET_ERR_%s (%s)\n"              \
      "  at %s:%i\n"                                                         \
      ,GASNETI_CURRENT_FUNCTION                                              \
      , #type, gasnet_ErrorDesc(GASNET_ERR_##type), __FILE__, __LINE__);     \
    }                                                                        \
  gasnett_freezeForDebuggerErr(); /* allow freeze */                         \
  return GASNET_ERR_ ## type;                                                \
  } while (0)
#define GASNETI_RETURN_ERRF(type, fromfn) do {                                     \
  if (gasneti_VerboseErrors) {                                                     \
    gasneti_console_message("WARNING",                                             \
      "GASNet %s returning an error code: GASNET_ERR_%s (%s)\n"                    \
      "  from function %s\n"                                                       \
      "  at %s:%i\n"                                                               \
      ,GASNETI_CURRENT_FUNCTION                                                    \
      , #type, gasnet_ErrorDesc(GASNET_ERR_##type), #fromfn, __FILE__, __LINE__);  \
    }                                                                              \
  gasnett_freezeForDebuggerErr(); /* allow freeze */                               \
  return GASNET_ERR_ ## type;                                                      \
  } while (0)
#define GASNETI_RETURN_ERRR(type, reason) do {                                             \
  if (gasneti_VerboseErrors) {                                                             \
    gasneti_console_message("WARNING",                                                     \
      "GASNet %s returning an error code: GASNET_ERR_%s (%s)\n"                            \
      "  at %s:%i\n"                                                                       \
      "  reason: %s\n"                                                                     \
      ,GASNETI_CURRENT_FUNCTION                                                            \
      , #type, gasnet_ErrorDesc(GASNET_ERR_##type), __FILE__, __LINE__, reason);           \
    }                                                                                      \
  gasnett_freezeForDebuggerErr(); /* allow freeze */                                       \
  return GASNET_ERR_ ## type;                                                              \
  } while (0)
#define GASNETI_RETURN_ERRFR(type, fromfn, reason) do {                                    \
  if (gasneti_VerboseErrors) {                                                             \
    gasneti_console_message("WARNING",                                                     \
      "GASNet %s returning an error code: GASNET_ERR_%s (%s)\n"                            \
      "  from function %s\n"                                                               \
      "  at %s:%i\n"                                                                       \
      "  reason: %s\n"                                                                     \
      ,GASNETI_CURRENT_FUNCTION                                                            \
      , #type, gasnet_ErrorDesc(GASNET_ERR_##type), #fromfn, __FILE__, __LINE__, reason);  \
    }                                                                                      \
  gasnett_freezeForDebuggerErr(); /* allow freeze */                                       \
  return GASNET_ERR_ ## type;                                                              \
  } while (0)

#ifndef GASNETI_ENABLE_ERRCHECKS
#define GASNETI_ENABLE_ERRCHECKS 0
#endif

#if GASNET_DEBUG || GASNETI_ENABLE_ERRCHECKS
  #define GASNETI_CHECK_ERR(errcond, type) \
    if_pf (errcond) GASNETI_RETURN_ERR(type)
  #define GASNETI_CHECK_ERRF(errcond, type, fromfn) \
    if_pf (errcond) GASNETI_RETURN_ERRF(type, fromfn)
  #define GASNETI_CHECK_ERRR(errcond, type, reason) \
    if_pf (errcond) GASNETI_RETURN_ERRR(type, reason)
  #define GASNETI_CHECK_ERRFR(errcond, type, fromfn, reason) \
    if_pf (errcond) GASNETI_RETURN_ERRFR(type, fromfn, reason)
#else
  #define GASNETI_CHECK_ERR(errcond, type)                    ((void)0)
  #define GASNETI_CHECK_ERRF(errcond, type, fromfn)           ((void)0)
  #define GASNETI_CHECK_ERRR(errcond, type, reason)           ((void)0)
  #define GASNETI_CHECK_ERRFR(errcond, type, fromfn, reason)  ((void)0)
#endif

/* return a possible error */
#define GASNETI_RETURN(expr) do {                                            \
  int _val = (expr);                                                         \
  if_pf (_val != GASNET_OK && gasneti_VerboseErrors) {                       \
    gasneti_console_message("WARNING",                                       \
      "GASNet %s returning an error code: %s (%s)\n"                         \
      "  at %s:%i\n"                                                         \
      ,GASNETI_CURRENT_FUNCTION                                              \
      , gasnet_ErrorName(_val), gasnet_ErrorDesc(_val), __FILE__, __LINE__); \
    }                                                                        \
  return _val;                                                               \
  } while (0)

/* make a GASNet call - if it fails, print error message and return error */
#define GASNETI_SAFE_PROPAGATE(fncall) do {                  \
   int retcode = (fncall);                                   \
   if_pf (retcode != GASNET_OK) {                            \
     char msg[80] = { 0 };                                   \
     if (gasneti_VerboseErrors) {                            \
       snprintf(msg, sizeof(msg),                            \
        "GASNet encountered an error: %s(%i)",               \
        gasnet_ErrorName(retcode), retcode);                 \
       msg[sizeof(msg)-1] = '\0';                            \
     }                                                       \
     GASNETI_RETURN_ERRFR(RESOURCE, fncall, msg);            \
   }                                                         \
 } while (0)

/* ------------------------------------------------------------------------------------ */
/* Trivial handling of defered-start progress threads */

extern int gasneti_query_progress_threads(
            gex_Client_t                     e_client,
            unsigned int                    *count_p,
            const gex_ProgressThreadInfo_t **info_p,
            gex_Flags_t                      flags);

/* ------------------------------------------------------------------------------------ */
/* nodemap data and functions */

extern const char *gasneti_format_host_detect(void);

extern uint64_t gasneti_hosthash(void);
extern uint32_t gasneti_gethostid(void);

extern gex_Rank_t *gasneti_nodemap;

typedef struct gasneti_nodegrp_s {
  /* List of member nodes in ascending order */
  gex_Rank_t *nodes;
  /* Number of nodes in group and my rank within them */
  gex_Rank_t node_count;
  gex_Rank_t node_rank;
  /* Number of peers (groups of same class) and this group's rank */
  gex_Rank_t grp_count;
  gex_Rank_t grp_rank;
} gasneti_nodegrp_t;

extern gasneti_nodegrp_t gasneti_myhost;

extern gasneti_nodegrp_t gasneti_mysupernode;
#define gasneti_nodemap_local         gasneti_mysupernode.nodes
#define gasneti_nodemap_local_count   gasneti_mysupernode.node_count
#define gasneti_nodemap_local_rank    gasneti_mysupernode.node_rank
#define gasneti_nodemap_global_count  gasneti_mysupernode.grp_count
#define gasneti_nodemap_global_rank   gasneti_mysupernode.grp_rank

extern void gasneti_nodemapInit(gasneti_bootstrapExchangefn_t exchangefn,
                                const void *ids, size_t sz, size_t stride);
extern void gasneti_nodemapParse(void);
extern void gasneti_nodemapFini(void);

#if GASNET_CONDUIT_SMP
  #define gasneti_node2supernode(n) 0
#else
  #define gasneti_node2supernode(n) \
    (gasneti_assert(gasneti_nodeinfo), gasneti_nodeinfo[(n)].supernode)
#endif

/* ------------------------------------------------------------------------------------ */
// Collective comms helpers

// Convience wrapper for a blocking gather-to-all of elements of size 'len' bytes.
// In-place (src == (uint8_t*)dst + len*myrank) is permitted.
// Currently wraps legacy gasnet_coll_* but should use gex_Coll_* eventually.
void gasneti_blockingExchange(gex_TM_t tm, void *src, size_t len, void *dst);

// Blocking "Rotated" ExchangeV utility function
// Takes only local data and length, and then discovers (and returns) the total length.
// Writes malloc()ed data pointer to *dst_p.
// Writes optional malloc()ed lengths-array pointer to *len_p, if non-NULL.
//
// "Rotated" because it does NOT generate the data in normal rank order.
// See comments in extended-ref/coll/gasnet_team.c for details.
#if PLATFORM_COMPILER_GNU && PLATFORM_COMPILER_VERSION_GE(11,0,0)
#define GASNETI_BUG4227_CONST /*const*/
#else 
#define GASNETI_BUG4227_CONST const
#endif
size_t gasneti_blockingRotatedExchangeV(gex_TM_t tm, GASNETI_BUG4227_CONST void *src, size_t len, void **dst_p, size_t **len_p);

// An AM-based host-scoped barrier
extern void gasneti_host_barrier(void);
extern void gasnetc_hbarr_reqh(gex_Token_t token, gex_AM_Arg_t arg0);

// An AM-based host-scoped sum of uint64_t
extern uint64_t gasneti_host_sumu64(uint64_t);
extern void gasnetc_hsumu64_reqh(gex_Token_t token, gex_AM_Arg_t arg0, gex_AM_Arg_t arg1);

// AM-based bootstrap (job-scoped) collectives
extern void gasneti_bootstrapBarrier_am(void);
extern void gasnetc_am_barrier_reqh(gex_Token_t token, gex_AM_Arg_t arg0);
extern void gasneti_bootstrapExchange_am(void *src, size_t len, void *dest);
extern void gasnetc_am_exchange_reqh(gex_Token_t token, void *buf, size_t nbytes,
                                     uint32_t arg0, uint32_t arg1);

#define GASNETC_COMMON_HANDLERS() \
    gasneti_handler_tableentry_no_bits(gasnetc_am_exchange_reqh,2,REQUEST,MEDIUM,0), \
    gasneti_handler_tableentry_no_bits(gasnetc_am_barrier_reqh,1,REQUEST,SHORT,0), \
    gasneti_handler_tableentry_no_bits(gasnetc_hbarr_reqh,1,REQUEST,SHORT,0), \
    gasneti_handler_tableentry_no_bits(gasnetc_hsumu64_reqh,2,REQUEST,SHORT,0)
#define _hidx_gasnetc_hbarr_reqh              (GASNETE_HANDLER_BASE-1)
#define _hidx_gasnetc_hsumu64_reqh            (GASNETE_HANDLER_BASE-2)
#define _hidx_gasnetc_am_barrier_reqh         (GASNETE_HANDLER_BASE-3)
#define _hidx_gasnetc_am_exchange_reqh        (GASNETE_HANDLER_BASE-4)

extern gex_Rank_t gasneti_get_dissem_peers(const gex_Rank_t **out_p);
#if GASNET_PSHM
extern gex_Rank_t gasneti_get_dissem_peers_pshm(const gex_Rank_t **out_p);
#endif

/* ------------------------------------------------------------------------------------ */
// Helpers for debug checks

#if GASNET_DEBUG
void gasneti_checknpam(int for_reply GASNETI_THREAD_FARG);
void gasneti_checknpam_disarm(void);
#endif

/* ------------------------------------------------------------------------------------ */

#include <gasnet_handler_internal.h>

#if GASNET_PSHM
#include <gasnet_pshm.h>
#endif

/* ------------------------------------------------------------------------------------ */
// Thread-local data

// Subsystems and conduits should use gasnet_*_fwd.h files to provide type definitions.
// However, some don't have any better home:
typedef struct _gasnete_eop_t gasnete_eop_t;
typedef struct _gasnete_iop_t gasnete_iop_t;

typedef struct _gasneti_threaddata_t {
  //
  // Fixed fields that should appear first in the threaddata struct for all conduits
  // NOTE: it is critical that these not change postition or order
  // TODO: eventually these might be replaced with inlined fields
  //
  void *gasnetc_threaddata;     /* ptr reserved for use by the core */
  gasnete_coll_threaddata_t
       *gasnete_coll_threaddata;// Owned by gasnet_coll_{fwd,internal}.h
  void *gasnete_vis_threaddata; /* ptr reserved for use by the VIS */

  //
  // Thread mangement fields
  // Owned by gasnet_extended_help.h
  //
  gasnete_threadidx_t threadidx;

  gasnete_thread_cleanup_t *thread_cleanup; /* thread cleanup function LIFO */
  int thread_cleanup_delay;
  int is_undead; // marks leaked threaddata for a thread which has exited

  //
  // Active Message fields
  // Owned by gasnet_am.[ch]
  //
#if GASNET_DEBUG || GASNETI_THREADINFO_OPT
  #define GASNETI_NEED_INIT_SRCDESC 1
  int sd_is_init;
#endif
#if GASNET_DEBUG
  int request_handler_active, reply_handler_active;
#endif
  struct gasneti_AM_SrcDesc request_sd, reply_sd;
  // Buffers, sized to max-medium, used by loopback AM and reference NPAM
  void *requestBuf, *replyBuf;
#if GASNET_DEBUG
  int requestBuf_live, replyBuf_live;
#endif

  //
  // Event data
  // Owned by gasnet_event_internal.h
  //
  void *eop_bufs;               /*  linked list of eop chunk buffers */
  int eop_num_bufs;             /*  number of valid buffer entries */
  gasnete_eop_t *eop_free;      /*  free list of eops */

  /*  stack of iops - head is active iop servicing new implicit ops */
  gasnete_iop_t *current_iop;  
  int iop_num;                  /*  number of allocated iops */
  gasnete_iop_t *iop_free;      /*  free list of iops */

  /*  lists of eops and iops freed by other threads */
  // TODO-EX: lock-free queues
  gasneti_mutex_t foreign_lock;
  gasnete_eop_t *foreign_eops;
  gasnete_iop_t *foreign_iops;

  // For use by conduit-independent logic desiring fire-and-forget implict ops.
  // This includes, at least, the RDMADISSEM barrier.
  gasneti_aop_t *nbi_ff_aop;
  unsigned int nbi_ff_depth;

  //
  // Conduit-specific data
  // Owned by [CONDUIT]-conduie/gasnet_extended_fwd.h
  //
  #ifdef GASNETE_CONDUIT_THREADDATA_FIELDS
  GASNETE_CONDUIT_THREADDATA_FIELDS
  #endif
} gasneti_threaddata_t;

/* ------------------------------------------------------------------------------------ */
// A "NBI fire-and-forget" facility using aops is provided for convenience of
// conduit-independent logic with no need to test or wait for completions.
// As long as this aop remains the current iop, nesting of gasneti_begin_nbi_ff() is
// supported.  One can use gasneti_nbi_ff_ok() to determine if a subsequent call
// to gasneti_begin_nbi_ff() is permitted.

GASNETI_INLINE(gasneti_begin_nbi_ff)
void gasneti_begin_nbi_ff(GASNETI_THREAD_FARG_ALONE)
{
  gasneti_threaddata_t * const mythread = GASNETI_MYTHREAD;
  if (mythread->nbi_ff_depth++) { // already active
    gasneti_assert(mythread->current_iop == (gasnete_iop_t*)mythread->nbi_ff_aop);
    return;
  }
  gasneti_aop_t *aop = mythread->nbi_ff_aop;
  if_pf (aop == NULL) {
    aop = gasneti_aop_create(GASNETI_THREAD_PASS_ALONE);
    mythread->nbi_ff_aop = aop;
  }
  gasneti_aop_push(aop GASNETI_THREAD_PASS);
}
GASNETI_INLINE(gasneti_end_nbi_ff)
void gasneti_end_nbi_ff(GASNETI_THREAD_FARG_ALONE)
{
  gasneti_threaddata_t * const mythread = GASNETI_MYTHREAD;
  gasneti_assert(mythread->nbi_ff_depth > 0);
  if (--mythread->nbi_ff_depth) { // still active
    gasneti_assert(mythread->current_iop == (gasnete_iop_t*)mythread->nbi_ff_aop);
    return;
  }
  gasneti_aop_t *aop = gasneti_aop_pop(GASNETI_THREAD_PASS_ALONE);
  gasneti_assert(aop == mythread->nbi_ff_aop);
}
// Non-zero if the nbi_ff aop is either
// + not on iop stack (thus safe to push)
// + or is at the top of the iop stack (thus safe to increment its depth)
GASNETI_INLINE(gasneti_nbi_ff_ok)
int gasneti_nbi_ff_ok(GASNETI_THREAD_FARG_ALONE)
{
  gasneti_threaddata_t * const mythread = GASNETI_MYTHREAD;
  return !mythread->nbi_ff_depth ||
         (mythread->current_iop == (gasnete_iop_t*)mythread->nbi_ff_aop);
}


// Sets the nbi_ff_aop of all threads to NULL and returns (via reference
// arguments) an array of events and its length.  This array, contains all of
// the aops which were found to be non-NULL.  The array and count are suitable
// for calls to gex_Event_{Try,Wait}{All,Some}().
//
// The caller is responsible for freeing the array, which may be non-NULL
// even when the count is zero.
//
// NOTE: this does NOT adjust `iop_num` in other threads when stealing their
// nbi_ff_aop.  This may force the threaddata to leak.  However, this should
// not be a real issue at process exit (the main intended use of this call).
extern void gasneti_finalize_all_nbi_ff(gex_Event_t **events_p, size_t *count_p GASNETI_THREAD_FARG);

// DO NOT USE THIS!
// This exists only to permit "safe" testing in gasnet_diagnostic.c.
extern void gasneti_nbi_ff_drain_(GASNETI_THREAD_FARG_ALONE);

/* ------------------------------------------------------------------------------------ */
/* Simple container of segments
 */

// Hidden state
extern gasneti_mutex_t _gasneti_segtbl_lock;
extern gasneti_Segment_t *_gasneti_segtbl;
extern int _gasneti_segtbl_count;

// Public access to the lock
#define GASNETI_SEGTBL_LOCK()   gasneti_mutex_lock(&_gasneti_segtbl_lock)
#define GASNETI_SEGTBL_UNLOCK() gasneti_mutex_unlock(&_gasneti_segtbl_lock)

// Simple iterator.
// Caller must hold lock and must not call add or del (which acquire the lock).
// This macro provides a loop header and the caller provides the iteration
// variable and the loop body:
//   gasneti_Segment_t p;
//   GASNETI_SEGTBL_FOR_EACH(p) { visit(p); }
#define GASNETI_SEGTBL_FOR_EACH(segvar) \
  for (int _gasneti_segtbl_iter = 0;                       \
       (gasneti_mutex_assertlocked(&_gasneti_segtbl_lock), \
        (_gasneti_segtbl_iter < _gasneti_segtbl_count) &&  \
        (segvar = _gasneti_segtbl[_gasneti_segtbl_iter])); \
       ++_gasneti_segtbl_iter)

// Add and Del
extern void gasneti_segtbl_add(gasneti_Segment_t seg);
extern void gasneti_segtbl_del(gasneti_Segment_t seg);

/* ------------------------------------------------------------------------------------ */
GASNETI_END_NOWARN
GASNETI_END_EXTERNC

#undef _IN_GASNET_INTERNAL_H
#endif
