/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 1

/* Pull parsers.  */
#define YYPULL 0




/* Copy the first part of user declarations.  */

#line 67 "bison-chapel.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "bison-chapel.h".  */
#ifndef YY_YY_INCLUDE_BISON_CHAPEL_H_INCLUDED
# define YY_YY_INCLUDE_BISON_CHAPEL_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 32 "chapel.ypp" /* yacc.c:355  */

  #include <string>
  extern int         captureTokens;
  extern std::string captureString;
#line 45 "chapel.ypp" /* yacc.c:355  */

  #ifndef _BISON_CHAPEL_DEFINES_0_
  #define _BISON_CHAPEL_DEFINES_0_

  #define YYLEX_NEWLINE                  -1
  #define YYLEX_SINGLE_LINE_COMMENT      -2
  #define YYLEX_BLOCK_COMMENT            -3

  typedef void* yyscan_t;

  int processNewline(yyscan_t scanner);
  void stringBufferInit();

  #endif
#line 65 "chapel.ypp" /* yacc.c:355  */

  #ifndef _BISON_CHAPEL_DEFINES_1_
  #define _BISON_CHAPEL_DEFINES_1_

  #include "symbol.h"

  #include <cstdio>
  #include <utility>
  #include <vector>

  class ArgSymbol;
  class BlockStmt;
  class CallExpr;
  class DefExpr;
  class EnumType;
  class Expr;
  class FnSymbol;
  class Type;

  enum   ProcIter {
    ProcIter_PROC,
    ProcIter_ITER
  };

  struct OnlyRename {
    enum{SINGLE, DOUBLE} tag;

    union {
      Expr*  elem;
      std::pair<Expr*, Expr*>* renamed;
    };
  };

  struct WhereAndLifetime {
    Expr* where;
    Expr* lifetime;
  };
  static inline
  WhereAndLifetime makeWhereAndLifetime(Expr* w, Expr* lt) {
    WhereAndLifetime ret;
    ret.where = w;
    ret.lifetime = lt;
    return ret;
  }

  // The lexer only uses pch.
  // The remaining types are for parser productions
  union  YYSTYPE {
    const char*               pch;

    Vec<const char*>*         vpch;
    RetTag                    retTag;
    AggregateTag              aggrTag;
    bool                      b;
    IntentTag                 pt;
    Expr*                     pexpr;
    DefExpr*                  pdefexpr;
    CallExpr*                 pcallexpr;
    BlockStmt*                pblockstmt;
    Type*                     ptype;
    EnumType*                 penumtype;
    std::vector<DefExpr*>*    pvecOfDefs;
    FnSymbol*                 pfnsymbol;
    ModuleSymbol*             pmodsymbol;
    ProcIter                  procIter;
    FlagSet*                  flagSet;
    ShadowVarSymbol*          pShadowVar;
    ShadowVarPrefix           pShadowVarPref;
    std::vector<OnlyRename*>* ponlylist;
    std::set<Flag>*           pflagset;
    WhereAndLifetime          lifetimeAndWhere;
  };

  #endif
#line 145 "chapel.ypp" /* yacc.c:355  */

  #ifndef _BISON_CHAPEL_DEFINES_2_
  #define _BISON_CHAPEL_DEFINES_2_

  struct YYLTYPE {
    int         first_line;
    int         first_column;
    int         last_line;
    int         last_column;
    const char* comment;
    const char* prevModule;
  };

  #define YYLTYPE_IS_DECLARED 1
  #define YYLTYPE_IS_TRIVIAL  1

  #endif
#line 168 "chapel.ypp" /* yacc.c:355  */

  #ifndef _BISON_CHAPEL_DEFINES_3_
  #define _BISON_CHAPEL_DEFINES_3_

  class ParserContext {
  public:
    ParserContext()
    {
      scanner       = 0;
      latestComment = 0;
      generatedStmt = 0;
    }

    ParserContext(yyscan_t scannerIn)
    {
      scanner       = scannerIn;
      latestComment = 0;
      generatedStmt = 0;
    }

    yyscan_t    scanner;
    const char* latestComment;
    BaseAST*    generatedStmt;
  };

  #endif

#line 238 "bison-chapel.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TIDENT = 258,
    INTLITERAL = 259,
    REALLITERAL = 260,
    IMAGLITERAL = 261,
    STRINGLITERAL = 262,
    CSTRINGLITERAL = 263,
    EXTERNCODE = 264,
    TALIGN = 265,
    TAS = 266,
    TATOMIC = 267,
    TBEGIN = 268,
    TBREAK = 269,
    TBOOL = 270,
    TBORROWED = 271,
    TBY = 272,
    TCATCH = 273,
    TCLASS = 274,
    TCOBEGIN = 275,
    TCOFORALL = 276,
    TCOMPLEX = 277,
    TCONFIG = 278,
    TCONST = 279,
    TCONTINUE = 280,
    TDEFER = 281,
    TDELETE = 282,
    TDMAPPED = 283,
    TDO = 284,
    TDOMAIN = 285,
    TELSE = 286,
    TENUM = 287,
    TEXCEPT = 288,
    TEXPORT = 289,
    TEXTERN = 290,
    TFALSE = 291,
    TFOR = 292,
    TFORALL = 293,
    TFORWARDING = 294,
    TIF = 295,
    TIMAG = 296,
    TIN = 297,
    TINDEX = 298,
    TINLINE = 299,
    TINOUT = 300,
    TINT = 301,
    TITER = 302,
    TLABEL = 303,
    TLAMBDA = 304,
    TLET = 305,
    TLIFETIME = 306,
    TLOCAL = 307,
    TLOCALE = 308,
    TMINUSMINUS = 309,
    TMODULE = 310,
    TNEW = 311,
    TNIL = 312,
    TNOINIT = 313,
    TON = 314,
    TONLY = 315,
    TOTHERWISE = 316,
    TOUT = 317,
    TOVERRIDE = 318,
    TOWNED = 319,
    TPARAM = 320,
    TPLUSPLUS = 321,
    TPRAGMA = 322,
    TPRIMITIVE = 323,
    TPRIVATE = 324,
    TPROC = 325,
    TPROTOTYPE = 326,
    TPUBLIC = 327,
    TREAL = 328,
    TRECORD = 329,
    TREDUCE = 330,
    TREF = 331,
    TREQUIRE = 332,
    TRETURN = 333,
    TSCAN = 334,
    TSELECT = 335,
    TSERIAL = 336,
    TSHARED = 337,
    TSINGLE = 338,
    TSPARSE = 339,
    TSTRING = 340,
    TSUBDOMAIN = 341,
    TSYNC = 342,
    TTHEN = 343,
    TTHIS = 344,
    TTHROW = 345,
    TTHROWS = 346,
    TTRUE = 347,
    TTRY = 348,
    TTRYBANG = 349,
    TTYPE = 350,
    TUINT = 351,
    TUNDERSCORE = 352,
    TUNION = 353,
    TUNMANAGED = 354,
    TUSE = 355,
    TVAR = 356,
    TWHEN = 357,
    TWHERE = 358,
    TWHILE = 359,
    TWITH = 360,
    TYIELD = 361,
    TZIP = 362,
    TALIAS = 363,
    TAND = 364,
    TASSIGN = 365,
    TASSIGNBAND = 366,
    TASSIGNBOR = 367,
    TASSIGNBXOR = 368,
    TASSIGNDIVIDE = 369,
    TASSIGNEXP = 370,
    TASSIGNLAND = 371,
    TASSIGNLOR = 372,
    TASSIGNMINUS = 373,
    TASSIGNMOD = 374,
    TASSIGNMULTIPLY = 375,
    TASSIGNPLUS = 376,
    TASSIGNREDUCE = 377,
    TASSIGNSL = 378,
    TASSIGNSR = 379,
    TBAND = 380,
    TBNOT = 381,
    TBOR = 382,
    TBXOR = 383,
    TCOLON = 384,
    TCOMMA = 385,
    TDIVIDE = 386,
    TDOT = 387,
    TDOTDOT = 388,
    TDOTDOTDOT = 389,
    TEQUAL = 390,
    TEXP = 391,
    TGREATER = 392,
    TGREATEREQUAL = 393,
    THASH = 394,
    TINITEQUALS = 395,
    TIO = 396,
    TLESS = 397,
    TLESSEQUAL = 398,
    TMINUS = 399,
    TMOD = 400,
    TNOT = 401,
    TNOTEQUAL = 402,
    TOR = 403,
    TPLUS = 404,
    TQUESTION = 405,
    TSEMI = 406,
    TSHIFTLEFT = 407,
    TSHIFTRIGHT = 408,
    TSTAR = 409,
    TSWAP = 410,
    TLCBR = 411,
    TRCBR = 412,
    TLP = 413,
    TRP = 414,
    TLSBR = 415,
    TRSBR = 416,
    TNOELSE = 417,
    TUPLUS = 418,
    TUMINUS = 419
  };
#endif

/* Value type.  */

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



#ifndef YYPUSH_MORE_DEFINED
# define YYPUSH_MORE_DEFINED
enum { YYPUSH_MORE = 4 };
#endif

typedef struct yypstate yypstate;

int yypush_parse (yypstate *ps, int pushed_char, YYSTYPE const *pushed_val, YYLTYPE *pushed_loc, ParserContext* context);

yypstate * yypstate_new (void);
void yypstate_delete (yypstate *ps);
/* "%code provides" blocks.  */
#line 199 "chapel.ypp" /* yacc.c:355  */

  extern int yydebug;

  void yyerror(YYLTYPE*       ignored,
               ParserContext* context,
               const char*    str);

#line 448 "bison-chapel.cpp" /* yacc.c:355  */

#endif /* !YY_YY_INCLUDE_BISON_CHAPEL_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 454 "bison-chapel.cpp" /* yacc.c:358  */
/* Unqualified %code blocks.  */
#line 38 "chapel.ypp" /* yacc.c:359  */

  #include <string>
  int         captureTokens;
  std::string captureString;
#line 207 "chapel.ypp" /* yacc.c:359  */

  #include "build.h"
  #include "CatchStmt.h"
  #include "DeferStmt.h"
  #include "DoWhileStmt.h"
  #include "driver.h"
  #include "flex-chapel.h"
  #include "ForallStmt.h"
  #include "ForLoop.h"
  #include "IfExpr.h"
  #include "misc.h"
  #include "parser.h"
  #include "stmt.h"
  #include "stringutil.h"
  #include "TryStmt.h"
  #include "vec.h"
  #include "WhileDoStmt.h"

  #include <cstdio>
  #include <cstdlib>
  #include <cstring>
  #include <stdint.h>

  static int query_uid = 1;

  #define YYLLOC_DEFAULT(Current, Rhs, N)                                 \
    if (N) {                                                              \
      (Current).first_line   = (Rhs)[1].first_line;                       \
      (Current).first_column = (Rhs)[1].first_column;                     \
      (Current).last_line    = (Rhs)[N].last_line;                        \
      (Current).last_column  = (Rhs)[N].last_column;                      \
      (Current).comment      = NULL;                                      \
                                                                          \
      if ((Current).first_line)                                           \
        yystartlineno = (Current).first_line;                             \
                                                                          \
    } else  {                                                             \
      (Current) = yylloc;                                                 \
    }

  void yyerror(YYLTYPE*       ignored,
               ParserContext* context,
               const char*    str) {

    // like USR_FATAL_CONT
    setupError("parser", __FILE__, __LINE__, 3);

    // TODO -- should this begin with error:
    if (!chplParseString) {
      const char* yyText = yyget_text(context->scanner);
      fprintf(stderr, "%s:%d: %s", yyfilename, chplLineno, str);

      if (strlen(yyText) > 0) {
        fprintf(stderr, ": near '%s'", yyText);
      }
    } else {
      fprintf(stderr, "%s: %s", yyfilename, str);

      if (chplParseStringMsg && (strlen(chplParseStringMsg) > 0)) {
        fprintf(stderr, " %s", chplParseStringMsg);
      }
    }

    fprintf(stderr, "\n");
  }

#line 528 "bison-chapel.cpp" /* yacc.c:359  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   16351

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  165
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  138
/* YYNRULES -- Number of rules.  */
#define YYNRULES  580
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1039

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   419

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   488,   488,   493,   494,   500,   501,   506,   507,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   545,
     558,   563,   568,   576,   577,   578,   582,   583,   596,   597,
     598,   603,   604,   609,   614,   619,   623,   630,   635,   639,
     644,   648,   649,   650,   654,   658,   660,   662,   664,   666,
     673,   674,   678,   679,   680,   681,   682,   685,   686,   687,
     688,   689,   701,   702,   713,   714,   715,   716,   717,   718,
     719,   720,   721,   722,   723,   724,   725,   726,   727,   728,
     732,   733,   734,   735,   736,   737,   738,   739,   746,   747,
     748,   749,   750,   751,   752,   753,   758,   759,   763,   764,
     768,   769,   773,   774,   775,   776,   777,   778,   779,   780,
     784,   785,   789,   790,   791,   792,   796,   803,   804,   805,
     806,   807,   808,   809,   810,   811,   812,   813,   814,   815,
     816,   817,   818,   819,   820,   821,   827,   833,   839,   845,
     852,   859,   863,   870,   874,   875,   876,   877,   878,   880,
     882,   884,   889,   892,   893,   894,   895,   896,   897,   901,
     902,   906,   907,   908,   912,   913,   917,   920,   922,   927,
     928,   932,   934,   936,   943,   953,   963,   973,   986,   991,
     996,  1004,  1005,  1010,  1011,  1013,  1018,  1034,  1041,  1050,
    1058,  1062,  1069,  1070,  1075,  1080,  1074,  1107,  1113,  1120,
    1126,  1132,  1143,  1149,  1142,  1181,  1185,  1190,  1194,  1199,
    1206,  1207,  1211,  1212,  1213,  1214,  1215,  1216,  1217,  1218,
    1219,  1220,  1221,  1222,  1223,  1224,  1225,  1226,  1227,  1228,
    1229,  1230,  1231,  1232,  1233,  1234,  1235,  1236,  1237,  1241,
    1242,  1243,  1244,  1245,  1246,  1247,  1248,  1249,  1250,  1251,
    1252,  1256,  1257,  1261,  1265,  1266,  1267,  1271,  1273,  1275,
    1277,  1279,  1284,  1285,  1289,  1290,  1291,  1292,  1293,  1294,
    1295,  1296,  1297,  1301,  1302,  1303,  1304,  1305,  1306,  1310,
    1311,  1315,  1316,  1317,  1318,  1319,  1320,  1324,  1325,  1328,
    1329,  1333,  1334,  1338,  1340,  1345,  1346,  1350,  1351,  1355,
    1356,  1358,  1360,  1362,  1367,  1368,  1371,  1372,  1373,  1374,
    1375,  1376,  1377,  1380,  1381,  1384,  1386,  1388,  1393,  1406,
    1423,  1424,  1426,  1431,  1432,  1433,  1434,  1435,  1439,  1445,
    1451,  1459,  1460,  1468,  1470,  1475,  1477,  1479,  1484,  1486,
    1488,  1495,  1496,  1497,  1502,  1504,  1506,  1510,  1514,  1516,
    1520,  1528,  1529,  1530,  1531,  1532,  1537,  1538,  1539,  1540,
    1541,  1561,  1565,  1569,  1577,  1584,  1585,  1586,  1590,  1592,
    1598,  1600,  1602,  1607,  1608,  1609,  1610,  1611,  1617,  1618,
    1619,  1620,  1624,  1625,  1629,  1630,  1631,  1635,  1636,  1640,
    1641,  1645,  1646,  1650,  1651,  1652,  1653,  1657,  1658,  1669,
    1670,  1671,  1672,  1673,  1674,  1676,  1678,  1680,  1682,  1684,
    1686,  1688,  1690,  1692,  1694,  1699,  1701,  1703,  1705,  1707,
    1709,  1711,  1713,  1715,  1717,  1719,  1721,  1723,  1730,  1736,
    1742,  1748,  1757,  1767,  1775,  1776,  1777,  1778,  1779,  1780,
    1781,  1782,  1787,  1788,  1792,  1796,  1797,  1801,  1805,  1806,
    1810,  1814,  1818,  1825,  1826,  1827,  1828,  1829,  1830,  1834,
    1835,  1840,  1845,  1853,  1854,  1855,  1856,  1857,  1858,  1859,
    1860,  1861,  1863,  1865,  1867,  1869,  1871,  1873,  1875,  1880,
    1881,  1884,  1885,  1886,  1889,  1890,  1891,  1892,  1903,  1904,
    1908,  1909,  1910,  1914,  1915,  1916,  1917,  1925,  1926,  1927,
    1928,  1932,  1933,  1937,  1938,  1939,  1940,  1941,  1942,  1943,
    1944,  1945,  1946,  1947,  1951,  1959,  1960,  1964,  1965,  1966,
    1967,  1968,  1969,  1970,  1971,  1972,  1973,  1974,  1975,  1976,
    1977,  1978,  1979,  1980,  1981,  1982,  1983,  1984,  1985,  1986,
    1990,  1991,  1992,  1993,  1994,  1995,  1999,  2000,  2001,  2002,
    2006,  2007,  2008,  2009,  2014,  2015,  2016,  2017,  2018,  2019,
    2020
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TIDENT", "INTLITERAL", "REALLITERAL",
  "IMAGLITERAL", "STRINGLITERAL", "CSTRINGLITERAL", "EXTERNCODE", "TALIGN",
  "TAS", "TATOMIC", "TBEGIN", "TBREAK", "TBOOL", "TBORROWED", "TBY",
  "TCATCH", "TCLASS", "TCOBEGIN", "TCOFORALL", "TCOMPLEX", "TCONFIG",
  "TCONST", "TCONTINUE", "TDEFER", "TDELETE", "TDMAPPED", "TDO", "TDOMAIN",
  "TELSE", "TENUM", "TEXCEPT", "TEXPORT", "TEXTERN", "TFALSE", "TFOR",
  "TFORALL", "TFORWARDING", "TIF", "TIMAG", "TIN", "TINDEX", "TINLINE",
  "TINOUT", "TINT", "TITER", "TLABEL", "TLAMBDA", "TLET", "TLIFETIME",
  "TLOCAL", "TLOCALE", "TMINUSMINUS", "TMODULE", "TNEW", "TNIL", "TNOINIT",
  "TON", "TONLY", "TOTHERWISE", "TOUT", "TOVERRIDE", "TOWNED", "TPARAM",
  "TPLUSPLUS", "TPRAGMA", "TPRIMITIVE", "TPRIVATE", "TPROC", "TPROTOTYPE",
  "TPUBLIC", "TREAL", "TRECORD", "TREDUCE", "TREF", "TREQUIRE", "TRETURN",
  "TSCAN", "TSELECT", "TSERIAL", "TSHARED", "TSINGLE", "TSPARSE",
  "TSTRING", "TSUBDOMAIN", "TSYNC", "TTHEN", "TTHIS", "TTHROW", "TTHROWS",
  "TTRUE", "TTRY", "TTRYBANG", "TTYPE", "TUINT", "TUNDERSCORE", "TUNION",
  "TUNMANAGED", "TUSE", "TVAR", "TWHEN", "TWHERE", "TWHILE", "TWITH",
  "TYIELD", "TZIP", "TALIAS", "TAND", "TASSIGN", "TASSIGNBAND",
  "TASSIGNBOR", "TASSIGNBXOR", "TASSIGNDIVIDE", "TASSIGNEXP",
  "TASSIGNLAND", "TASSIGNLOR", "TASSIGNMINUS", "TASSIGNMOD",
  "TASSIGNMULTIPLY", "TASSIGNPLUS", "TASSIGNREDUCE", "TASSIGNSL",
  "TASSIGNSR", "TBAND", "TBNOT", "TBOR", "TBXOR", "TCOLON", "TCOMMA",
  "TDIVIDE", "TDOT", "TDOTDOT", "TDOTDOTDOT", "TEQUAL", "TEXP", "TGREATER",
  "TGREATEREQUAL", "THASH", "TINITEQUALS", "TIO", "TLESS", "TLESSEQUAL",
  "TMINUS", "TMOD", "TNOT", "TNOTEQUAL", "TOR", "TPLUS", "TQUESTION",
  "TSEMI", "TSHIFTLEFT", "TSHIFTRIGHT", "TSTAR", "TSWAP", "TLCBR", "TRCBR",
  "TLP", "TRP", "TLSBR", "TRSBR", "TNOELSE", "TUPLUS", "TUMINUS",
  "$accept", "program", "toplevel_stmt_ls", "toplevel_stmt", "pragma_ls",
  "stmt", "module_decl_start", "module_decl_stmt", "access_control",
  "opt_prototype", "block_stmt", "stmt_ls", "only_ls", "opt_only_ls",
  "except_ls", "use_stmt", "require_stmt", "assignment_stmt",
  "opt_label_ident", "ident_fn_def", "ident_def", "ident_use",
  "internal_type_ident_def", "scalar_type", "reserved_type_ident_use",
  "opt_string", "do_stmt", "return_stmt", "class_level_stmt",
  "private_decl", "forwarding_stmt", "extern_block_stmt", "loop_stmt",
  "zippered_iterator", "if_stmt", "defer_stmt", "try_stmt",
  "catch_stmt_ls", "catch_stmt", "catch_expr", "throw_stmt", "select_stmt",
  "when_stmt_ls", "when_stmt", "class_decl_stmt", "class_tag",
  "opt_inherit", "class_level_stmt_ls", "enum_decl_stmt", "enum_header",
  "enum_ls", "enum_item", "lambda_decl_expr", "$@1", "$@2", "linkage_spec",
  "fn_decl_stmt", "$@3", "$@4", "fn_decl_stmt_inner",
  "fn_decl_receiver_expr", "fn_ident", "assignop_ident", "opt_formal_ls",
  "req_formal_ls", "formal_ls", "formal", "opt_intent_tag",
  "required_intent_tag", "opt_this_intent_tag", "proc_or_iter",
  "opt_ret_tag", "opt_throws_error", "opt_function_body_stmt",
  "function_body_stmt", "query_expr", "opt_query_expr", "var_arg_expr",
  "opt_lifetime_where", "lifetime_components_expr", "lifetime_expr",
  "lifetime_ident", "type_alias_decl_stmt", "type_alias_decl_stmt_inner",
  "opt_init_type", "var_decl_type", "var_decl_stmt",
  "var_decl_stmt_inner_ls", "var_decl_stmt_inner",
  "tuple_var_decl_component", "tuple_var_decl_stmt_inner_ls",
  "opt_init_expr", "ret_array_type", "opt_ret_type", "opt_type",
  "array_type", "opt_formal_array_elt_type", "formal_array_type",
  "opt_formal_type", "expr_ls", "simple_expr_ls", "tuple_component",
  "tuple_expr_ls", "opt_actual_ls", "actual_ls", "actual_expr",
  "ident_expr", "type_level_expr", "for_expr", "cond_expr", "nil_expr",
  "stmt_level_expr", "opt_task_intent_ls", "task_intent_clause",
  "task_intent_ls", "forall_intent_clause", "forall_intent_ls",
  "intent_expr", "shadow_var_prefix", "io_expr", "new_expr", "let_expr",
  "expr", "opt_expr", "opt_try_expr", "lhs_expr", "fun_expr", "call_expr",
  "dot_expr", "parenthesized_expr", "bool_literal", "literal_expr",
  "assoc_expr_ls", "binary_op_expr", "unary_op_expr", "reduce_expr",
  "scan_expr", "reduce_scan_op_expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419
};
# endif

#define YYPACT_NINF -917

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-917)))

#define YYTABLE_NINF -532

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -917,   139,  3043,  -917,    -7,  -917,  -917,  -917,  -917,  -917,
    -917,  4307,    13,   244,  -917,  9639,  -917,    13,  9639,  -917,
     276,   161,   244,  4307,  9639,  4307,    99,  -917,  9639,  6798,
    -917,  8151,  8737,  6640,  9639,  -917,   181,  -917,  -917, 16252,
    -917,  2651,  8872,  -917,  9639,  9639,  -917,  9639,  -917,  9639,
    -917,  9639,   363,   195,  1320,  1320,  -917,  -917,  -917,  9007,
    7700,  9639,  8872,  9639,  9639,   289,  -917,   247,  4307,  -917,
    9639,  -917,  9774,  9774, 16252,  -917,  -917,  9639,  9007,  -917,
    9639,  9639,  -917,  -917,  9639,  -917,  -917, 11799,  9639,  9639,
    -917,  9639,  -917,  -917,  3359,  6933,  8286,  -917,  4149,  -917,
     258,  -917,   344,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917, 16252,  -917, 16252,   -44,   288,  -917,  -917,  2651,  -917,
     271,  -917,  -917,  -917,   278,   279,   304,   297,   302, 15910,
    2316,   136,   313,   325,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,   170,  -917,  -917, 15910,   323,  4307,  -917,  -917,   333,
    9639,  9639,  9639,  9639,  9639,  9007,  9007,   252,  -917,  -917,
    -917,  -917,   355,   345,  -917,  -917,   341, 14062, 16252,  2651,
    -917,   351,  -917,   112, 15910,   402,  7858, 15910,  -917,   186,
    -917, 16252,   264,   342, 16252,   360,    10, 13572,    35, 13501,
     342,  9639,  -917, 14021, 12805,  7858,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  4307,  -917,   372,   182,
      85,    49,  -917,  4307,  -917,  -917, 13719,   541,   355, 13719,
     355,   541,  -917,  7858,  9639,  -917,  -917, 16252,  -917,   203,
   15910,  9639,  9639,  -917, 15910,   380, 13908,  -917, 13719,   355,
   15910,   374,  7858,  -917, 15910, 14363,  -917,  -917, 14404, 12060,
    -917,  -917, 14445,   405,   391,   355,   204, 14175, 13719, 14551,
     346,   627,   541,   346,   541,   222,  -917,  -917,  3517,   113,
    -917,  9639,  -917,   -33,   -31,  -917,    -2,    58, 14606,   -37,
     543,  -917,  3675,  -917,   497,   425,   399,  -917,  -917,  -917,
     273,  -917,  9639,  9639,  9639,  9639,  8737,  8737,  9639,  9639,
    9639,  9639,  9909,  9639,   131, 11799,  9639,  9639,  9639,  9639,
    9639,  9639,  9639,  9639,  9639,  9639,  9639,  9639,  9639,  9639,
    9639,  -917,  -917,  -917,  -917,  -917,  -917,  8444,  8444,  -917,
    -917,  -917,  -917,  8444,  -917,  -917,  8444,  8444,  7858,  7858,
    8737,  8737,  7407,  -917,  -917, 14216, 14257, 14637,    12,  3833,
    -917,  8737,    10,   407,   310,  -917,  9639,  -917,  9639,   454,
    -917,   412,   442,  -917,  -917,   422, 16252,  2651,   532,  9007,
    -917,  4465,  8737,  -917,   420,  -917,    10,  4623,  8737,  -917,
      10,   342, 10044,  9639,  -917,  4307,   550,  9639,   423,  -917,
     446,  -917,  -917,   182,  -917,   462,   435,  -917, 10179,   474,
    9639,  2651,  -917,  -917,  -917,   437,  -917,  9007,  -917, 15910,
   15910,  -917,    29,  -917,  7858,   438,  -917,   581,  -917,   581,
    -917, 10314,   471,  -917,  -917, 10044,  9639,  -917,  -917,  -917,
    -917,  -917,  8579,  -917, 12658,  7091,  -917,  7249,  -917,  4307,
     441,  8737,  6045,  3201,   448,  9639,  6363,  -917,  -917,   320,
    -917,  3991, 16252,  9007,   452, 16230,   307,  -917, 14719,  6407,
    6407,   385,  -917,   385,  -917,   385, 16085,  1294,  1579,   761,
   12191, 12191,   355,   346,  -917,  -917,  -917,  -917,   627, 12698,
     385,  1090,  1090,  6407,  1090,  1090,  1457,   346, 12698, 16043,
    1457,   541,   541,   346,   466,   468,   470,   482,   484,   478,
     477,  -917,   385,  -917,   385,    56,  -917,  -917,  -917,   -24,
    -917,   628, 15941,   175, 10449,  8737, 10584,  8737,  9639,  8737,
   12387,    13, 14790,  -917,  -917,  -917, 15910, 14821,  7858,  -917,
    7858,  -917,   425,   335,  9639,   -22,  9639, 15910,    46, 13795,
    7407,  -917,  9639, 15910,    66, 13648,  -917,   490,   483,   493,
   14876,   483,   494,   615, 14961,  4307, 13866,  -917,   185,  -917,
    -917,  -917,  -917,  -917,  -917,   900,   123,  -917,  2789,  -917,
     352,   488,   182,    85,  9639,    99,   181,  9639,  9639,  9639,
    9639,  9639,  5887,  -917,  -917,   353,  8016,  -917, 15910,  -917,
    -917,  -917, 15910,   492,     7,   501,  -917,  2317,  -917,  -917,
     338, 16252,   500,   502,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  4307,   116,  2827,  -917,  -917, 15910,  4307, 15910,  -917,
   15016,  -917,  -917,  -917,   526,  1505,   507,   555,   118,  -917,
     591,  -917,  -917,  -917,  -917,  6484,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  7407,  -917,    28,  8737,  8737,
    9639,   639, 15047,  9639,   646, 15102,   518,  2869,    10,    10,
    -917,  -917,  -917,  -917,   520,  -917, 13719,  -917, 12881,  4781,
    -917,  4939,  -917,   129,  -917, 12957,  5097,  -917,    10,  5255,
    -917,    10,  9639,  -917,  9639,  -917,  4307,  9639,  -917,  4307,
     651,  -917,  -917, 16252,  1040,  -917,   182,   554,   608,  -917,
    -917,  -917,    45,  -917,  -917,   474,   528,    63,  -917,  -917,
    -917,  5413,  9007,  -917,  -917,  -917, 16252,  -917,   558,   341,
    -917,  -917,  -917,  -917,  5571,   529,  5729,   533,  -917,  9639,
     546,  1258,  -917,  9639, 16252,  -917,  -917,   352,   539,   567,
    -917,   568,  -917,   572,  -917,   573,   575,   578,   579,   580,
     582,  -917,   583,  -917, 16252,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  9639,  -917,  -917,   584,
     539,   539,  -917,  -917,   474,   229,   268, 15187, 10719, 10854,
   15263, 10989, 11124, 11259, 11394,  -917,  -917,  2013,  -917,  4307,
    9639, 15910,  9639, 15910,  7407,  -917,  4307,  9639, 15910,  -917,
    9639, 15910,  -917, 15300, 15910,  -917, 15910,   688,  4307,   554,
    -917,   561,  9165,   134,  -917,    38,  -917,  -917,  8737, 12289,
    4307,  -917,    16,   563,  9639,  -917,  9639,  -917, 15910,  4307,
    9639,  -917, 15910,  4307, 15910,  -917,  7565,  1276,  1276,  -917,
    1057,  -917, 15910,  -917,    78,   446,  -917,  -917, 12729, 12475,
    -917,  -917,  -917,  9639,  9639,  9639,  9639,  9639,  9639,  9639,
    9639,   566, 16068, 14961, 13033, 13109,  -917, 14961, 13185, 13261,
    9639,  4307,  -917,   474,   554,  6204,  -917,  -917,  -917,   128,
    9007,  -917,  -917,   208,  9639,    24, 12556,  -917,   753,   402,
    -917,   341, 15910, 13337,  -917, 13413,  -917,  -917,  -917, 11529,
     635,   283,  -917,  -917,  -917,   539,   539, 15376, 15452, 15528,
   15604, 15680, 15756,  -917,  -917,  4307,  4307,  4307,  4307, 15910,
    -917,  -917,   134,  9323,    69,  -917,  -917, 15910,  -917,   107,
    -917,   163,  -917,   357, 15839,  -917,  -917,  -917, 11394,  -917,
    4307,  4307,  2502,  -917,  -917,   382,  -917,    38,  -917,  -917,
    -917,  9639,  9639,  9639,  9639,  9639,  9639, 14961, 14961, 14961,
   14961,  -917,  -917,  -917,  -917,  -917,   234,  8737, 11934,  -917,
    9639,   208,   107,   107,   107,   107,   107,   107,   208,   904,
   14961, 14961,   569, 11664,    70,     9, 12627,  -917,  -917, 15910,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,   599,  -917,  -917,
     456, 12066,  -917,  -917,  -917,  9481,  -917,   515,  -917
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       3,     0,     0,     1,     0,    82,   524,   525,   526,   527,
     528,     0,   462,    70,   100,     0,   198,   462,     0,   105,
       0,   344,    70,     0,     0,     0,     0,   208,   499,   499,
     521,     0,     0,     0,     0,   104,     0,   218,   101,     0,
     214,     0,     0,   107,     0,     0,   453,     0,   221,     0,
     343,     0,     0,     0,    45,    44,   103,   199,   345,     0,
       0,     0,     0,     0,     0,     0,   106,     0,     0,    83,
       0,   522,     0,     0,     0,   102,   200,     0,     0,   347,
       0,     0,   576,   578,     0,   579,   580,   498,     0,     0,
     577,   574,   122,   575,     0,     0,     0,     4,     0,     5,
       0,     9,    46,    10,    11,    12,    14,   417,   418,    22,
      13,   123,   129,    15,    17,    16,    19,    20,    21,    18,
     128,     0,   126,     0,   488,     0,   130,   127,     0,   131,
     504,   484,   485,   421,   419,     0,     0,   489,   490,     0,
     420,     0,   505,   506,   507,   523,   483,   423,   422,   486,
     487,     0,    38,    24,   429,     0,     0,   463,    71,     0,
       0,     0,     0,     0,     0,     0,     0,   488,   504,   419,
     489,   490,   431,   420,   505,   506,     0,   462,     0,     0,
     346,     0,   172,     0,   402,     0,   409,   500,   219,   527,
     136,     0,     0,   220,     0,     0,     0,     0,     0,     0,
       0,   499,   135,     0,     0,   409,    77,    84,    95,    89,
      97,    79,    88,    98,    85,    99,    93,    87,    94,    92,
      90,    91,    78,    80,    86,    96,     0,    81,     0,     0,
       0,     0,   351,     0,   119,    32,     0,   562,   481,     0,
     432,   563,     7,   409,   499,   125,   124,   314,   399,     0,
     398,     0,     0,   120,   503,     0,     0,    35,     0,   434,
     424,     0,   409,    36,   430,     0,   179,   175,     0,   420,
     179,   176,     0,   340,     0,   433,     0,   398,     0,     0,
     565,   497,   561,   564,   560,     0,    48,    51,     0,     0,
     404,     0,   406,     0,     0,   405,     0,     0,   398,     0,
       0,     6,     0,    47,     0,   201,     0,   300,   299,   222,
       0,    23,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   496,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   259,   266,   267,   268,   263,   265,     0,     0,   261,
     264,   262,   260,     0,   270,   269,     0,     0,   409,   409,
       0,     0,     0,    25,    26,     0,     0,     0,     0,     0,
      27,     0,     0,     0,     0,    28,     0,    29,     0,   417,
     415,     0,   410,   411,   416,     0,     0,     0,     0,     0,
     145,     0,     0,   144,     0,   153,     0,     0,     0,   151,
       0,     0,     0,    57,   132,     0,   165,     0,     0,    30,
     282,   215,   355,     0,   356,   358,     0,   380,     0,   361,
       0,     0,   118,    31,    33,     0,   313,     0,    64,   501,
     502,   121,     0,    34,   409,     0,   186,   177,   173,   178,
     174,     0,   338,   335,    61,     0,    57,   138,    37,    50,
      49,    52,     0,   529,     0,     0,   517,     0,   519,     0,
       0,     0,     0,     0,     0,     0,     0,   533,     8,     0,
      40,     0,     0,     0,     0,     0,   293,   350,   461,   557,
     556,   559,   567,   566,   571,   570,   553,   550,   551,   552,
     493,   494,   492,   540,   515,   516,   514,   513,   495,   544,
     555,   549,   547,   558,   548,   546,   538,   543,   545,   554,
     537,   541,   542,   539,     0,     0,     0,     0,     0,     0,
       0,   569,   568,   573,   572,   473,   474,   476,   478,     0,
     465,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     531,   462,   462,   141,   336,   348,   403,     0,     0,   426,
       0,   337,   201,     0,     0,     0,     0,   437,     0,     0,
       0,   154,     0,   443,     0,     0,   152,   575,    60,     0,
      53,    58,     0,   164,     0,     0,     0,   425,   287,   284,
     285,   286,   290,   291,   292,   282,     0,   275,     0,   283,
     301,     0,   359,     0,   112,   114,   115,   110,   111,   109,
     108,   113,     0,   379,   378,   484,     0,   353,   482,   352,
     512,   401,   400,     0,     0,     0,   427,     0,   180,   342,
     484,     0,     0,     0,   530,   491,   518,   407,   520,   408,
     161,     0,     0,     0,   532,   159,   447,     0,   535,   534,
       0,    42,    41,    39,   202,     0,     0,   212,     0,   209,
     297,   294,   295,   298,   223,     0,    68,    69,    67,    66,
      65,   510,   511,   475,   477,     0,   464,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     137,   413,   414,   412,     0,   349,     0,   163,     0,     0,
     143,     0,   142,     0,   468,     0,     0,   149,     0,     0,
     147,     0,     0,   133,     0,   134,     0,     0,   167,     0,
     169,   288,   289,     0,   282,   273,     0,   393,   302,   305,
     304,   306,     0,   357,   360,   361,     0,     0,   362,   363,
     188,     0,     0,   187,   190,   428,     0,   181,   184,     0,
     339,    62,    63,   162,     0,     0,     0,     0,   160,     0,
       0,   217,   207,     0,   210,   206,   296,   301,   271,    72,
     255,    84,   253,    89,    74,    88,    85,    99,    87,    90,
      73,    75,    86,   234,   237,   235,   236,   247,   238,   251,
     243,   241,   254,   258,   257,   242,   240,   245,   250,   252,
     239,   244,   248,   249,   246,   256,     0,   232,    76,     0,
     271,   271,   230,   466,   361,   504,   504,     0,     0,     0,
       0,     0,     0,     0,     0,   140,   139,     0,   146,     0,
       0,   436,     0,   435,     0,   467,     0,     0,   442,   150,
       0,   441,   148,    55,    54,   166,   452,   168,     0,   393,
     276,     0,     0,   361,   303,   319,   354,   384,     0,   531,
       0,   192,     0,     0,     0,   182,     0,   157,   449,     0,
       0,   155,   448,     0,   536,   196,   499,   217,   217,   194,
     217,   204,   213,   211,     0,   282,   229,   233,     0,     0,
     225,   226,   470,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   217,   440,     0,     0,   469,   446,     0,     0,
       0,     0,   171,   361,   393,     0,   396,   395,   397,   484,
     315,   279,   277,     0,     0,     0,     0,   382,   484,   193,
     191,     0,   185,     0,   158,     0,   156,   205,   375,     0,
     307,     0,   231,    72,    73,   271,   271,     0,     0,     0,
       0,     0,     0,   197,   195,     0,     0,     0,     0,    56,
     170,   278,   361,   385,     0,   316,   318,   317,   333,     0,
     334,   321,   324,     0,   320,   311,   312,   216,     0,   183,
       0,     0,     0,   374,   373,   484,   308,   319,   272,   227,
     228,     0,     0,     0,     0,     0,     0,   439,   438,   445,
     444,   281,   280,   387,   388,   390,   484,     0,   531,   332,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   484,
     451,   450,     0,   365,     0,     0,     0,   389,   391,   323,
     325,   326,   329,   330,   331,   327,   328,   322,   370,   368,
     484,   531,   309,   224,   310,   385,   369,   484,   392
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -917,  -917,  -917,     3,  -382,  1523,  -917,  -917,  -917,  -917,
     364,   430,  -190,   291,   294,  -917,  -917,   447,   719,  -917,
     540,  -142,  -640,  -917,  -761,  -917,   630,  -868,  -725,   -46,
    -917,  -917,  -917,    40,  -917,  -917,  -917,   473,  -917,     8,
    -917,  -917,  -917,  -917,  -917,   553,   194,   -70,  -917,  -917,
    -917,    -6,  1045,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -130,  -139,  -758,  -917,  -125,    37,   168,  -917,  -917,
    -917,     0,  -917,  -917,  -254,   177,  -917,  -187,  -215,  -242,
    -234,  -379,  -917,  -172,  -917,   -17,   737,  -114,   356,  -917,
    -386,  -700,  -670,  -917,  -552,  -430,  -916,  -865,  -779,    -4,
    -917,    41,  -917,  -149,  -917,   223,   542,  -383,  -917,  -917,
    1072,  -917,    15,  -917,  -917,  -175,  -917,  -548,  -917,  -917,
    1397,  1496,   -11,   -12,   -58,   981,  -917,  1913,  2090,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -352
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,   287,    98,   573,   100,   101,   102,   304,
     103,   288,   568,   572,   569,   104,   105,   106,   159,   797,
     230,   107,   227,   108,   603,   192,   235,   109,   110,   111,
     112,   113,   114,   676,   115,   116,   117,   437,   618,   739,
     118,   119,   614,   734,   120,   121,   474,   751,   122,   123,
     648,   649,   167,   228,   590,   125,   126,   476,   757,   654,
     799,   800,   407,   876,   411,   586,   587,   588,   589,   655,
     309,   722,   977,  1033,   967,   248,   956,   911,   915,   961,
     962,   963,   127,   274,   442,   128,   129,   231,   232,   415,
     416,   607,   974,   930,   419,   604,   994,   908,   843,   289,
     183,   293,   294,   381,   382,   383,   168,   131,   132,   133,
     169,   135,   156,   157,   529,   396,   693,   530,   531,   136,
     170,   171,   139,   193,   384,   173,   141,   174,   175,   144,
     145,   146,   299,   147,   148,   149,   150,   151
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     154,   357,   255,   179,   172,    97,   373,   177,   245,   246,
     533,   619,   694,   184,   310,   798,   188,   187,   187,   385,
     197,   199,   203,   204,   400,   846,   871,   591,   585,   417,
     613,   236,   176,   237,   238,   605,   239,   295,   240,   233,
     241,   725,   880,   881,   379,   233,   417,   966,   250,   254,
     256,   258,   259,   260,   539,   249,   408,   264,   620,   265,
     903,   268,   272,   379,   233,   374,   275,   277,   731,   278,
     279,   196,   198,   280,   276,   689,   281,   282,   283,   928,
     284,   906,  1017,   250,   254,   298,   417,    60,   995,   913,
    -189,   420,   297,   466,   425,   696,  -376,   455,   663,   457,
     461,   379,    60,   394,   882,   848,   665,  -458,   427,   732,
     958,   997,   539,   435,  -509,   804,  -509,   803,   155,  1038,
     379,   460,   464,  -376,   467,   952,   456,  -376,   458,  -371,
     357,  -189,   664,  1018,     5,   666,   296,   687,  -376,     3,
     394,   914,   462,   912,   152,   927,   427,   966,  -376,   154,
     365,   366,   367,   264,   250,   298,  -371,   418,  -376,   459,
    1032,   494,   368,   394,   733,   369,   369,   871,   973,  -371,
     845,   394,   369,   540,   418,   254,   387,   979,   980,   421,
     369,  -371,   497,   179,   495,   206,  -189,  -376,   462,   401,
     187,   369,   372,   462,   254,  -376,   960,   207,   208,   462,
     462,  -376,   369,   951,   209,  -117,   724,   929,   533,   519,
     520,   958,   210,   571,   418,  -376,   379,   379,   211,   463,
      69,   394,   369,   212,   849,   213,   496,   711,   214,  -371,
     998,  1031,   254,   187,  -371,   215,  -376,   180,  -394,   798,
     429,   430,   376,   452,   606,   360,   216,   158,   754,   361,
     669,   254,   992,   714,   361,   217,   571,   186,  -394,   824,
    -117,   712,  -394,   377,   218,   219,  1000,   220,   910,   221,
     453,   222,   292,   553,   223,   755,   896,   744,   224,   412,
     454,   225,   715,    16,  -117,   615,   959,  -394,   825,   514,
     515,   451,   379,  1001,   358,   516,   359,   960,   517,   518,
      21,   478,   479,   480,   481,   483,   485,   486,   487,   488,
     489,   492,   493,   533,   498,   499,   500,   501,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     841,   650,   585,   427,   427,   307,   254,   254,    57,   205,
     413,    50,   254,  1029,  -386,   254,   254,   254,   254,   522,
     524,   532,    58,   243,   428,   444,   482,   484,   308,  -472,
     542,  1036,    76,   380,  -386,   546,    21,   547,  -386,   870,
     242,   178,   651,   152,   315,   261,   718,    79,   250,   449,
     557,   559,   380,   652,   387,   555,   563,   565,  -472,   698,
     701,   570,   570,  -386,   574,  -377,   576,   295,  -471,   295,
     521,   523,   653,   421,  -377,   262,   234,    50,   379,   608,
    -509,   541,  -509,   714,   302,   303,   612,   719,    58,   917,
     380,   316,  -455,   254,   477,   317,   234,  -471,   720,  -454,
     311,  -377,   558,  -372,   570,   570,   266,   270,   564,   380,
     421,   612,   978,    79,   254,   312,   254,   721,  -459,   740,
     633,   612,   636,  -460,   638,   640,  -377,   745,   747,   909,
    -372,   545,   250,  -377,  -457,   421,   918,  1002,  -341,   644,
     578,   152,   533,  -372,   451,   322,  -456,   641,   324,   172,
     275,   362,   327,  -377,   364,  -372,   685,   324,   579,  -341,
     682,   580,  1003,   585,  1004,  1005,   627,   369,   629,  1006,
    1007,   632,   375,  -508,  -377,  -508,   378,  -364,   581,  -377,
     870,   582,  -377,    52,   322,   441,   801,   324,   389,   267,
     271,   327,   583,   557,   672,   563,   675,   574,   677,   636,
     410,   431,   434,  -372,  -364,   380,   380,   254,  -372,   254,
     370,   584,   443,   686,   130,   688,   975,  -364,   729,   532,
     468,   695,   472,   130,   473,   475,   678,   679,   544,  -364,
     234,   234,   234,   234,   548,   130,  -366,   130,   406,   315,
     996,   549,   550,   551,   554,   671,  -274,   674,   560,   226,
     999,   575,   577,   172,   606,  1009,   240,   259,   260,   264,
     275,   298,   592,  -366,   593,   254,   610,   616,   727,   617,
     234,   621,   631,   234,   611,  -274,  -366,  -364,   645,   637,
     130,   380,  -364,   702,   273,   996,   316,   656,  -366,   657,
     317,   658,   234,  1021,  1022,  1023,  1024,  1025,  1026,   611,
    1030,     5,   292,   659,   292,   660,   130,   661,   662,   611,
     130,   -59,   234,    14,   703,   705,   706,   723,  1037,   730,
      19,   741,   996,   742,   532,   315,   427,   483,   522,   807,
     735,   305,   810,   306,   752,   753,  -366,   756,   808,    35,
     322,  -366,   323,   324,    38,   811,   817,   327,   821,   813,
     823,    43,   838,   842,   844,   828,   334,   854,   831,   847,
     859,   833,   257,   834,   863,   340,   836,   875,   130,   -82,
    -100,    56,   316,   865,  -105,  -104,   317,  -101,   482,   521,
    -107,  -103,  -106,    66,   -83,  -102,   879,    69,   273,   901,
     904,   250,   921,   943,    75,   681,   976,   380,   852,  1001,
    1028,   273,   471,   858,   388,   862,   234,   623,   864,   622,
     936,   181,   872,   439,   853,   386,   684,   892,   873,   935,
     931,   840,   319,   713,   320,   321,   322,   874,   323,   324,
     234,  1034,  1015,   327,   234,   991,  1027,  1020,   130,   414,
     202,   333,   334,   683,     0,   130,   337,   609,     0,   338,
     339,   340,     0,     0,     0,   878,     0,   426,     0,   315,
       0,     0,     0,     0,     0,  -381,     0,   821,   823,     0,
     828,   831,   858,   862,  -381,     0,     0,     0,   893,   894,
       0,   895,     0,   532,     0,   897,   898,     0,     0,   899,
       0,   245,   246,     0,     0,     0,   390,   393,   395,   399,
     130,  -381,     0,     0,     0,     0,   316,   916,   636,     0,
     317,     0,     0,   922,   130,   923,     0,     0,     0,   925,
       0,     0,     0,     0,     0,   187,  -381,     0,     0,     0,
       0,     0,     0,  -381,     0,     0,   423,     0,     0,   424,
       0,     0,   893,   937,   938,   897,   939,   940,   941,   942,
       0,     0,     0,  -381,     0,     0,   319,     0,   433,   949,
     322,     0,   323,   324,   298,     0,     0,   327,     0,   957,
       0,   954,     0,   964,  -381,     0,   334,     0,   447,  -381,
       0,   130,  -381,   338,   339,   340,     0,     0,     0,     0,
       0,     0,   234,   234,   578,     0,   552,     0,   234,   234,
       0,     0,     0,   130,   987,   988,   989,   990,     0,   130,
     710,     0,   579,     0,     0,   580,  -383,   130,     0,     0,
       0,     0,     0,   414,     0,  -383,     0,   862,     0,  1010,
    1011,   298,   581,     0,     0,   582,     0,   300,  1014,     0,
     987,   988,   989,   990,  1010,  1011,   583,     0,     0,     0,
       0,   737,  -383,   140,     0,     0,  1016,   636,     0,  1019,
       0,     0,   140,     0,     0,   584,     0,     0,     0,     0,
       0,   130,   543,     0,   140,   130,   140,  -383,     0,     0,
       0,     0,   643,   130,  -383,   647,     0,     0,     0,   907,
     636,     0,     0,     0,   862,     0,   561,     0,     0,     0,
     566,     0,     0,     0,  -383,     0,     0,     0,     0,     0,
       0,     0,   234,   234,     0,     0,     0,   124,     0,   140,
     234,     0,   406,   269,   269,  -383,   124,     0,     0,   406,
    -383,     0,   234,  -383,   578,   234,     0,     0,   124,     0,
     124,     0,     0,   667,   134,   140,    16,     0,     0,   140,
      20,    21,   579,   134,     0,   580,     0,   955,     0,    27,
       0,    28,   866,     0,     0,   134,    33,   134,     0,     0,
       0,    37,   581,   855,     0,   582,     0,    52,     0,     0,
       0,     0,     0,   124,     0,     0,   583,   130,   315,     0,
      48,     0,    50,     0,   300,     0,   867,     0,   717,   868,
     993,    57,   414,    58,     0,   584,     0,   140,     0,   124,
     134,     0,     0,   124,     0,     0,     0,     0,     0,     0,
       0,     0,    74,     0,     0,    76,     0,   738,    79,     0,
       0,   273,     0,     0,     0,   316,   134,     0,     0,   317,
     134,     0,     0,   130,     0,   993,     0,     0,     0,   130,
       0,     0,     0,     0,     0,     0,     0,     0,   690,   692,
       0,     0,     0,     0,   697,   700,     0,   802,     0,     0,
       0,   124,     0,     0,     0,     0,     0,   140,    92,     0,
     805,   806,   993,     0,   140,   319,   234,   320,   321,   322,
       0,   323,   324,   325,     0,     0,   327,     0,   134,     0,
       0,   130,     0,   130,   333,   334,     0,     0,   130,   337,
       0,   130,   338,   339,   340,     0,     0,     0,   130,     0,
       0,   130,     0,   839,     0,     0,   414,     0,   406,   406,
       0,     0,   406,   406,     0,     0,     0,     0,     0,   140,
       0,   124,     0,   130,     0,     0,   738,    16,   124,   965,
       0,    20,    21,   140,     0,   969,   130,   406,   130,   406,
      27,     0,    28,   866,   647,     0,     0,    33,   134,   200,
      21,     0,    37,     0,     0,   134,     0,     0,   815,   816,
      28,   244,     0,     0,   877,     0,   818,     0,     0,     0,
      37,    48,   315,    50,     0,    52,     0,   867,   829,     0,
     868,   832,    57,   124,    58,     0,     0,     0,     0,    48,
       0,    50,     0,   200,    21,     0,     0,   124,     0,     0,
     140,     0,    58,    74,    28,   244,    76,     0,     0,    79,
     134,   130,     0,     0,    37,     0,     0,  -217,   130,   316,
       0,     0,   140,   317,   134,     0,     0,    79,   140,   965,
     130,     0,     0,    48,     0,    50,   140,     0,     0,     0,
    -217,     0,   130,     0,     0,     0,    58,     0,     0,   137,
       0,   130,     0,     0,     0,   130,     0,     0,   137,    92,
       0,     0,     0,     0,   124,   869,     0,     0,     0,     0,
     137,    79,   137,   322,     0,   323,   324,     0,     0,     0,
     327,     0,     0,     0,     0,     0,   124,     0,     0,   334,
     140,   134,   124,   130,   140,     0,   338,   339,   340,     0,
     124,     0,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   134,     0,   137,     0,     0,     0,   134,
       0,     0,     0,     0,     0,     0,     0,   134,     0,     0,
       0,     0,   920,     0,     0,   315,     0,   130,   130,   130,
     130,   137,     0,     0,     0,   137,     0,     0,   138,     0,
       0,     0,     0,     0,   124,     0,   750,   138,   124,     0,
       0,     0,   130,   130,     0,     0,   124,     0,     0,   138,
       0,   138,     0,     0,  -203,    99,     0,     0,  -203,  -203,
       0,   134,   316,     0,   153,   134,   317,  -203,     0,  -203,
    -203,     0,     0,   134,  -203,     0,   182,     0,   185,  -203,
       0,     0,  -203,   137,     0,     0,   140,     0,     0,     0,
       0,     0,     0,     0,   138,     0,     0,     0,  -203,     0,
    -203,     0,  -203,     0,  -203,  -203,     0,  -203,     0,  -203,
       0,  -203,   319,     0,   320,   321,   322,     0,   323,   324,
     138,   263,     0,   327,   138,     0,     0,     0,     0,     0,
    -203,     0,   334,  -203,     0,     0,  -203,   315,     0,   338,
     339,   340,   140,     0,     0,     0,     0,    99,   140,     0,
     124,   301,     0,   137,     0,     0,     0,     0,     0,     0,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,     0,     0,
       0,     0,   138,     0,   316,     0,  -203,     0,   317,     0,
       0,     0,  -203,     0,     0,     0,     0,     0,     0,     0,
     140,     0,   140,     0,     0,     0,   124,   140,     0,   363,
     140,     0,   124,     0,     0,   137,     0,   140,     0,     0,
     140,     0,     0,     0,     0,     0,     0,     0,     0,   137,
       0,     0,     0,   134,   319,     0,     0,   321,   322,   134,
     323,   324,   140,     0,     0,   327,     0,     0,     0,     0,
       0,     0,   138,     0,   334,   140,     0,   140,     0,   138,
       0,   338,   339,   340,   124,     0,   124,     0,     0,     0,
       0,   124,     0,     0,   124,     0,     0,     0,     0,   409,
       0,   124,     0,     0,   124,     0,   422,     0,     0,     0,
       0,   134,     0,   134,     0,     0,   137,     0,   134,     0,
       0,   134,     0,     0,     0,     0,   124,     0,   134,     0,
       0,   134,     0,     0,   138,     0,     0,     0,   137,   124,
       0,   124,     0,     0,   137,     0,     0,     0,   138,     0,
     140,     0,   137,   134,     0,     0,     0,   140,     0,     0,
       0,    99,     0,     0,     0,     0,   134,     0,   134,   140,
       0,     0,     0,     0,     0,    99,     0,     0,     0,     0,
       0,   140,     0,     0,     0,     0,     0,     0,     0,     0,
     140,     0,     0,     0,   140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   137,     0,     0,     0,
     137,     0,     0,     0,   124,   138,     0,     0,   137,     0,
       0,   124,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   140,   124,     0,     0,     0,   138,     0,     0,
       0,   134,    99,   138,     0,   124,     0,     0,   134,     0,
       0,   138,     0,     0,   124,     0,     0,     0,   124,     0,
     134,     0,     0,     0,   422,   142,     0,     0,     0,     0,
     422,     0,   134,     0,   142,     0,   140,   140,   140,   140,
       0,   134,     0,     0,     0,   134,   142,     0,   142,     0,
       0,     0,     0,     0,     0,     0,   124,     0,     0,     0,
       0,   140,   140,     0,     0,   138,     0,     0,     0,   138,
       0,     0,     0,     0,     0,     0,     0,   138,     0,     0,
       0,     0,   137,   134,     0,     0,     0,     0,     0,     0,
       0,   142,   630,     0,     0,     0,   635,     0,     0,     0,
     124,   124,   124,   124,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   142,     0,     0,
       0,   142,     0,     0,   891,   124,   124,   134,   134,   134,
     134,     0,     0,     0,     0,     0,     0,     0,   137,     0,
       0,     0,  -203,     0,   137,     0,  -203,  -203,     0,     0,
       0,     0,   134,   134,     0,  -203,     0,  -203,  -203,     0,
       0,     0,  -203,     0,     0,     0,     0,  -203,     0,     0,
    -203,     0,     0,     0,     0,     0,     0,     0,     0,   142,
       0,   138,     0,     0,     0,     0,  -203,     0,  -203,     0,
    -203,     0,  -203,  -203,     0,  -203,   137,  -203,   137,  -203,
       0,     0,   143,   137,     0,     0,   137,     0,   708,     0,
       0,   143,     0,   137,     0,     0,   137,     0,  -203,     0,
       0,  -203,     0,   143,  -203,   143,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138,   137,     0,
       0,     0,     0,   138,     0,     0,     0,     0,     0,   142,
       0,   137,     0,   137,     0,     0,   142,     0,     0,     0,
       0,     0,     0,     0,   743,     0,     0,     0,   143,     0,
     748,     0,     0,     0,  -203,     0,     0,     0,     0,     0,
    -203,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   143,   138,     0,   138,   143,     0,
       0,     0,   138,     0,     0,   138,     0,     0,     0,     0,
       0,   142,   138,     0,     0,   138,     0,     0,     0,     0,
       0,     0,   422,     0,   422,   142,   137,     0,     0,   422,
       0,     0,   422,   137,     0,     0,     0,   138,     0,   835,
       0,     0,   837,     0,     0,   137,     0,     0,     0,     0,
     138,     0,   138,     0,     0,     0,   143,   137,     0,     0,
       0,     0,     0,     0,   851,     0,   137,     0,     0,     0,
     137,     0,     0,     0,     0,     0,     0,   857,     0,   861,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   142,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   137,     0,
       0,     0,     0,     0,   142,     0,     0,     0,     0,     0,
     142,     0,     0,     0,     0,   138,   143,     0,   142,     0,
     206,     0,   138,   143,     0,     0,     0,     0,     0,     0,
       0,     0,   207,   208,   138,     0,     0,     0,     0,   209,
       0,     0,   137,   137,   137,   137,   138,   210,     0,     0,
       0,     0,     0,   211,     0,   138,     0,     0,   212,   138,
     213,   902,     0,   214,     0,     0,     0,   137,   137,     0,
     215,     0,   142,   919,     0,     0,   142,     0,   143,     0,
       0,   216,   924,     0,   142,     0,   926,     0,     0,     0,
     217,     0,   143,     0,     0,     0,     0,   138,     0,   218,
     219,     0,   220,     0,   221,     0,   222,     0,     0,   223,
       0,     0,     0,   224,     0,     0,   225,     0,     0,     0,
       0,     0,     0,     0,   950,     0,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   138,   138,   138,   138,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -479,     0,   143,
       0,     0,     0,     0,     0,     0,   138,   138,     0,     0,
       0,   356,     0,   369,  -508,   736,  -508,     0,     0,     0,
       0,   143,     0,     0,     0,     0,     0,   143,   142,     0,
       0,     0,     0,     0,     0,   143,     0,     0,     0,     0,
       0,     0,     0,  1012,     0,     5,     6,     7,     8,     9,
      10,     0,     0,     0,   160,     0,     0,    14,    15,     0,
       0,     0,     0,     0,    19,     0,     0,     0,     0,     0,
       0,     0,    26,     0,     0,     0,     0,     0,    30,   161,
     162,     0,   163,    35,   142,    36,     0,     0,    38,   143,
     142,    40,    41,   143,     0,    43,    44,     0,    45,    46,
       0,   143,     0,     0,     0,     0,    49,     0,    51,     0,
      53,     0,     0,     0,     0,    56,     0,     0,     0,     0,
       0,     0,     0,     0,    63,    64,    65,    66,    67,   164,
       0,    69,     0,     0,    71,     0,     0,     0,    75,     0,
       0,    77,   142,     0,   142,     0,     0,     0,     0,   142,
       0,    82,   142,     0,     0,     0,     0,     0,     0,   142,
       0,     0,   142,     0,     0,     0,     0,    83,    84,    85,
      86,     0,     0,     0,     0,    87,     0,     0,     0,     0,
       0,     0,     0,     0,   142,     0,    88,     0,    89,     0,
      90,    91,   247,     0,   206,     0,    93,   142,   165,   142,
      95,     0,   166,  1013,     0,   143,   207,   208,     0,     0,
       0,     0,     0,   209,     0,     0,     0,     0,     0,     0,
       0,   210,     0,     0,     0,     0,     0,   211,     0,     0,
       0,     0,   212,     0,   213,     0,     0,   214,     0,     0,
       0,     0,     0,     0,   215,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   216,     0,     0,     0,     0,
       0,   143,     0,     0,   217,     0,     0,   143,     0,     0,
       0,     0,   142,   218,   219,     0,   220,     0,   221,   142,
     222,     0,     0,   223,     0,     0,     0,   224,     0,     0,
     225,   142,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   142,     0,     0,     0,     0,     0,     0,
       0,     0,   142,     0,     0,     0,   142,     0,     0,   143,
       0,   143,     0,     0,     0,     0,   143,     0,     0,   143,
       0,     0,   206,     0,     0,     0,   143,     0,     0,   143,
       0,     0,     0,     0,   207,   208,     0,     0,     0,   229,
       0,   209,     0,     0,   142,     0,     0,     0,     0,   210,
       0,   143,     0,     0,     0,   211,     0,     0,     0,     0,
     212,     0,   213,     0,   143,   214,   143,   313,     0,     0,
       0,     0,   215,     0,   314,     0,     0,     0,     0,     0,
       0,     0,     0,   216,     0,   315,     0,     0,   142,   142,
     142,   142,   217,     0,     0,     0,     0,     0,     0,     0,
       0,   218,   219,     0,   220,     0,   221,     0,   222,   313,
       0,   223,     0,   142,   142,   224,   314,     0,   225,     0,
       0,     0,     0,     0,     0,     0,     0,   315,     0,     0,
       0,     0,   316,     0,     0,     0,   317,     0,     0,   143,
       0,     0,     0,     0,     0,     0,   143,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   143,     0,
       0,     0,   394,     0,     0,     0,   318,     0,     0,     0,
     143,     0,     0,     0,   316,     0,     0,   716,   317,   143,
       0,     0,   319,   143,   320,   321,   322,     0,   323,   324,
     325,     0,   326,   327,   328,   329,   330,     0,     0,   331,
     332,   333,   334,     0,   335,   336,   337,     0,   318,   338,
     339,   340,     0,     0,     0,     0,     0,     0,   746,     0,
       0,   143,     0,     0,   319,     0,   320,   321,   322,     0,
     323,   324,   325,     0,   326,   327,   328,   329,   330,     0,
       0,   331,   332,   333,   334,     0,   335,   336,   337,     0,
       0,   338,   339,   340,     0,     0,     0,     0,     0,     0,
     814,     0,     0,     0,     0,   143,   143,   143,   143,     0,
       0,     0,     0,    -2,     4,     0,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    11,    12,    13,    14,    15,
     143,   143,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     0,    25,    26,     0,    27,     0,    28,    29,    30,
      31,    32,    33,    34,    35,     0,    36,    37,     0,    38,
    -217,    39,    40,    41,     0,    42,    43,    44,   -43,    45,
      46,     0,    47,     0,     0,     0,    48,    49,    50,    51,
      52,    53,    54,  -217,   -43,    55,    56,    57,     0,    58,
      59,    60,     0,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,     0,    71,    72,    73,    74,    75,
       0,    76,    77,    78,    79,     0,     0,    80,     0,    81,
       0,     0,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,    84,
      85,    86,     0,     0,     0,     0,    87,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    88,     0,    89,
       0,    90,    91,     0,    92,     0,     0,    93,     0,    94,
       0,    95,     4,    96,     5,     6,     7,     8,     9,    10,
       0,  -531,     0,    11,    12,    13,    14,    15,  -531,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,  -531,
      25,    26,  -531,    27,     0,    28,    29,    30,    31,    32,
      33,    34,    35,     0,    36,    37,     0,    38,  -217,    39,
      40,    41,     0,    42,    43,    44,   -43,    45,    46,     0,
      47,     0,     0,     0,    48,    49,    50,    51,     0,    53,
      54,  -217,   -43,    55,    56,    57,  -531,    58,    59,    60,
    -531,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,     0,    71,    72,    73,    74,    75,     0,    76,
      77,    78,    79,     0,     0,    80,     0,    81,     0,     0,
    -531,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -531,    84,  -531,  -531,
    -531,  -531,  -531,  -531,  -531,     0,  -531,  -531,  -531,  -531,
    -531,     0,     0,  -531,  -531,  -531,  -531,    89,  -531,  -531,
    -531,     0,    92,  -531,  -531,  -531,     0,    94,  -531,    95,
     285,    96,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    11,    12,    13,    14,    15,     0,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,     0,    25,    26,
       0,    27,     0,    28,    29,    30,    31,    32,    33,    34,
      35,     0,    36,    37,     0,    38,  -217,    39,    40,    41,
       0,    42,    43,    44,   -43,    45,    46,     0,    47,     0,
       0,     0,    48,    49,    50,    51,    52,    53,    54,  -217,
     -43,    55,    56,    57,     0,    58,    59,    60,     0,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
       0,    71,    72,    73,    74,    75,     0,    76,    77,    78,
      79,     0,     0,    80,     0,    81,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,    84,    85,    86,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,     0,    89,     0,    90,    91,   247,
      92,     0,     0,    93,     0,    94,   286,    95,     4,    96,
       5,     6,     7,     8,     9,    10,     0,     0,     0,    11,
      12,    13,    14,    15,     0,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     0,    25,    26,     0,    27,
       0,    28,    29,    30,    31,    32,    33,    34,    35,     0,
      36,    37,     0,    38,  -217,    39,    40,    41,     0,    42,
      43,    44,   -43,    45,    46,     0,    47,     0,     0,     0,
      48,    49,    50,    51,    52,    53,    54,  -217,   -43,    55,
      56,    57,     0,    58,    59,    60,     0,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,     0,    71,
      72,    73,    74,    75,     0,    76,    77,    78,    79,     0,
       0,    80,     0,    81,     0,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,    84,    85,    86,     0,     0,     0,     0,
      87,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,     0,    89,     0,    90,    91,     0,    92,     0,
       0,    93,     0,    94,   450,    95,   469,    96,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    11,    12,    13,
      14,    15,     0,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     0,    25,    26,     0,    27,     0,    28,
      29,    30,    31,    32,    33,    34,    35,     0,    36,    37,
       0,    38,  -217,    39,    40,    41,     0,    42,    43,    44,
     -43,    45,    46,     0,    47,     0,     0,     0,    48,    49,
      50,    51,    52,    53,    54,  -217,   -43,    55,    56,    57,
       0,    58,    59,    60,     0,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,     0,    71,    72,    73,
      74,    75,     0,    76,    77,    78,    79,     0,     0,    80,
       0,    81,     0,     0,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,    84,    85,    86,     0,     0,     0,     0,    87,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88,
       0,    89,     0,    90,    91,     0,    92,     0,     0,    93,
       0,    94,   470,    95,   285,    96,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    11,    12,    13,    14,    15,
       0,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     0,    25,    26,     0,    27,     0,    28,    29,    30,
      31,    32,    33,    34,    35,     0,    36,    37,     0,    38,
    -217,    39,    40,    41,     0,    42,    43,    44,   -43,    45,
      46,     0,    47,     0,     0,     0,    48,    49,    50,    51,
      52,    53,    54,  -217,   -43,    55,    56,    57,     0,    58,
      59,    60,     0,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,     0,    71,    72,    73,    74,    75,
       0,    76,    77,    78,    79,     0,     0,    80,     0,    81,
       0,     0,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,    84,
      85,    86,     0,     0,     0,     0,    87,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    88,     0,    89,
       0,    90,    91,     0,    92,     0,     0,    93,     0,    94,
     286,    95,     4,    96,     5,     6,     7,     8,     9,    10,
       0,     0,     0,    11,    12,    13,    14,    15,     0,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     0,
      25,    26,     0,    27,     0,    28,    29,    30,    31,    32,
      33,    34,    35,     0,    36,    37,     0,    38,  -217,    39,
      40,    41,     0,    42,    43,    44,   -43,    45,    46,     0,
      47,     0,     0,     0,    48,    49,    50,    51,    52,    53,
      54,  -217,   -43,    55,    56,    57,     0,    58,    59,    60,
       0,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,     0,    71,    72,    73,    74,    75,     0,    76,
      77,    78,    79,     0,     0,    80,     0,    81,     0,     0,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,    84,    85,    86,
       0,     0,     0,     0,    87,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    88,     0,    89,     0,    90,
      91,     0,    92,     0,     0,    93,     0,    94,   642,    95,
       4,    96,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    11,    12,    13,    14,    15,     0,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,     0,    25,    26,
       0,    27,     0,    28,    29,    30,    31,    32,    33,    34,
      35,     0,    36,    37,     0,    38,  -217,    39,    40,    41,
       0,    42,    43,    44,   -43,    45,    46,     0,    47,     0,
       0,     0,    48,    49,    50,    51,   300,    53,    54,  -217,
     -43,    55,    56,    57,     0,    58,    59,    60,     0,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
       0,    71,    72,    73,    74,    75,     0,    76,    77,    78,
      79,     0,     0,    80,     0,    81,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,    84,    85,    86,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,     0,    89,     0,    90,    91,     0,
      92,     0,     0,    93,     0,    94,     0,    95,     4,    96,
       5,     6,     7,     8,     9,    10,     0,     0,     0,    11,
      12,    13,    14,    15,     0,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     0,    25,    26,     0,    27,
       0,    28,    29,    30,    31,    32,    33,    34,    35,     0,
      36,    37,     0,    38,  -217,    39,    40,    41,     0,    42,
      43,    44,   -43,    45,    46,     0,    47,     0,     0,     0,
      48,    49,    50,    51,     0,    53,    54,  -217,   -43,    55,
      56,    57,     0,    58,    59,    60,     0,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,     0,    71,
      72,    73,    74,    75,     0,    76,    77,    78,    79,     0,
       0,    80,     0,    81,     0,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,    84,    85,    86,     0,     0,     0,     0,
      87,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,     0,    89,     0,    90,    91,     0,    92,     0,
       0,    93,     0,    94,     0,    95,     4,    96,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    11,    12,    13,
      14,    15,     0,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     0,    25,    26,     0,    27,     0,    28,
      29,    30,    31,    32,    33,   556,    35,     0,    36,    37,
       0,    38,  -217,    39,    40,    41,     0,    42,    43,    44,
     -43,    45,    46,     0,    47,     0,     0,     0,    48,    49,
      50,    51,     0,    53,    54,  -217,   -43,    55,    56,    57,
       0,    58,    59,    60,     0,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,     0,    71,    72,    73,
      74,    75,     0,    76,    77,    78,    79,     0,     0,    80,
       0,    81,     0,     0,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,    84,    85,    86,     0,     0,     0,     0,    87,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88,
       0,    89,     0,    90,    91,     0,    92,     0,     0,    93,
       0,    94,     0,    95,     4,    96,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    11,    12,    13,    14,    15,
       0,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     0,    25,    26,     0,    27,     0,    28,    29,    30,
      31,    32,    33,   562,    35,     0,    36,    37,     0,    38,
    -217,    39,    40,    41,     0,    42,    43,    44,   -43,    45,
      46,     0,    47,     0,     0,     0,    48,    49,    50,    51,
       0,    53,    54,  -217,   -43,    55,    56,    57,     0,    58,
      59,    60,     0,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,     0,    71,    72,    73,    74,    75,
       0,    76,    77,    78,    79,     0,     0,    80,     0,    81,
       0,     0,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,    84,
      85,    86,     0,     0,     0,     0,    87,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    88,     0,    89,
       0,    90,    91,     0,    92,     0,     0,    93,     0,    94,
       0,    95,     4,    96,     5,     6,     7,     8,     9,    10,
       0,     0,     0,    11,    12,    13,    14,    15,     0,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     0,
      25,    26,     0,    27,     0,    28,    29,    30,    31,    32,
      33,   820,    35,     0,    36,    37,     0,    38,  -217,    39,
      40,    41,     0,    42,    43,    44,   -43,    45,    46,     0,
      47,     0,     0,     0,    48,    49,    50,    51,     0,    53,
      54,  -217,   -43,    55,    56,    57,     0,    58,    59,    60,
       0,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,     0,    71,    72,    73,    74,    75,     0,    76,
      77,    78,    79,     0,     0,    80,     0,    81,     0,     0,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,    84,    85,    86,
       0,     0,     0,     0,    87,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    88,     0,    89,     0,    90,
      91,     0,    92,     0,     0,    93,     0,    94,     0,    95,
       4,    96,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    11,    12,    13,    14,    15,     0,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,     0,    25,    26,
       0,    27,     0,    28,    29,    30,    31,    32,    33,   822,
      35,     0,    36,    37,     0,    38,  -217,    39,    40,    41,
       0,    42,    43,    44,   -43,    45,    46,     0,    47,     0,
       0,     0,    48,    49,    50,    51,     0,    53,    54,  -217,
     -43,    55,    56,    57,     0,    58,    59,    60,     0,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
       0,    71,    72,    73,    74,    75,     0,    76,    77,    78,
      79,     0,     0,    80,     0,    81,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,    84,    85,    86,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,     0,    89,     0,    90,    91,     0,
      92,     0,     0,    93,     0,    94,     0,    95,     4,    96,
       5,     6,     7,     8,     9,    10,     0,     0,     0,    11,
      12,    13,    14,    15,     0,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     0,    25,    26,     0,    27,
       0,    28,    29,    30,    31,    32,    33,   827,    35,     0,
      36,    37,     0,    38,  -217,    39,    40,    41,     0,    42,
      43,    44,   -43,    45,    46,     0,    47,     0,     0,     0,
      48,    49,    50,    51,     0,    53,    54,  -217,   -43,    55,
      56,    57,     0,    58,    59,    60,     0,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,     0,    71,
      72,    73,    74,    75,     0,    76,    77,    78,    79,     0,
       0,    80,     0,    81,     0,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,    84,    85,    86,     0,     0,     0,     0,
      87,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,     0,    89,     0,    90,    91,     0,    92,     0,
       0,    93,     0,    94,     0,    95,     4,    96,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    11,    12,    13,
      14,    15,     0,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     0,    25,    26,     0,    27,     0,    28,
      29,    30,    31,    32,    33,   830,    35,     0,    36,    37,
       0,    38,  -217,    39,    40,    41,     0,    42,    43,    44,
     -43,    45,    46,     0,    47,     0,     0,     0,    48,    49,
      50,    51,     0,    53,    54,  -217,   -43,    55,    56,    57,
       0,    58,    59,    60,     0,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,     0,    71,    72,    73,
      74,    75,     0,    76,    77,    78,    79,     0,     0,    80,
       0,    81,     0,     0,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,    84,    85,    86,     0,     0,     0,     0,    87,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88,
       0,    89,     0,    90,    91,     0,    92,     0,     0,    93,
       0,    94,     0,    95,     4,    96,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    11,    12,    13,    14,    15,
       0,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     0,   850,    26,     0,    27,     0,    28,    29,    30,
      31,    32,    33,    34,    35,     0,    36,    37,     0,    38,
    -217,    39,    40,    41,     0,    42,    43,    44,   -43,    45,
      46,     0,    47,     0,     0,     0,    48,    49,    50,    51,
       0,    53,    54,  -217,   -43,    55,    56,    57,     0,    58,
      59,    60,     0,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,     0,    71,    72,    73,    74,    75,
       0,    76,    77,    78,    79,     0,     0,    80,     0,    81,
       0,     0,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,    84,
      85,    86,     0,     0,     0,     0,    87,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    88,     0,    89,
       0,    90,    91,     0,    92,     0,     0,    93,     0,    94,
       0,    95,     4,    96,     5,     6,     7,     8,     9,    10,
       0,     0,     0,    11,    12,    13,    14,    15,     0,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     0,
      25,    26,     0,    27,     0,    28,    29,    30,    31,    32,
      33,   856,    35,     0,    36,    37,     0,    38,  -217,    39,
      40,    41,     0,    42,    43,    44,   -43,    45,    46,     0,
      47,     0,     0,     0,    48,    49,    50,    51,     0,    53,
      54,  -217,   -43,    55,    56,    57,     0,    58,    59,    60,
       0,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,     0,    71,    72,    73,    74,    75,     0,    76,
      77,    78,    79,     0,     0,    80,     0,    81,     0,     0,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,    84,    85,    86,
       0,     0,     0,     0,    87,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    88,     0,    89,     0,    90,
      91,     0,    92,     0,     0,    93,     0,    94,     0,    95,
       4,    96,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    11,    12,    13,    14,    15,     0,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,     0,    25,    26,
       0,    27,     0,    28,    29,    30,    31,    32,    33,   860,
      35,     0,    36,    37,     0,    38,  -217,    39,    40,    41,
       0,    42,    43,    44,   -43,    45,    46,     0,    47,     0,
       0,     0,    48,    49,    50,    51,     0,    53,    54,  -217,
     -43,    55,    56,    57,     0,    58,    59,    60,     0,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
       0,    71,    72,    73,    74,    75,     0,    76,    77,    78,
      79,     0,     0,    80,     0,    81,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,    84,    85,    86,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,     0,    89,     0,    90,    91,     0,
      92,     0,     0,    93,     0,    94,     0,    95,   726,    96,
       5,     6,     7,     8,     9,    10,     0,     0,     0,   160,
       0,     0,    14,    15,     0,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,     0,     0,    26,     0,     0,
       0,     0,     0,    30,   161,   162,     0,   163,    35,     0,
      36,     0,     0,    38,     0,     0,    40,    41,     0,     0,
      43,    44,     0,    45,    46,     0,     0,     0,     0,     0,
       0,    49,     0,    51,     0,    53,     0,     0,     0,     0,
      56,     0,     0,     0,     0,     0,     0,     0,     0,    63,
      64,    65,    66,    67,   164,     0,    69,     0,     0,    71,
       0,     0,     0,    75,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,    84,    85,    86,     0,     0,     0,     0,
      87,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,     0,    89,     0,    90,    91,   247,     0,     0,
       0,    93,     0,   165,     0,    95,     0,   166,     5,     6,
       7,     8,     9,    10,     0,     0,     0,   160,     0,     0,
      14,    15,     0,     0,     0,     0,     0,    19,     0,     0,
       0,     0,     0,     0,     0,    26,     0,     0,     0,     0,
       0,    30,   161,   162,     0,   163,    35,     0,    36,     0,
       0,    38,     0,     0,    40,    41,     0,     0,    43,    44,
       0,    45,    46,     0,     0,     0,     0,     0,     0,    49,
       0,    51,     0,    53,     0,     0,     0,     0,    56,     0,
       0,     0,     0,     0,     0,     0,     0,    63,    64,    65,
      66,    67,   164,     0,    69,     0,     0,    71,     0,     0,
       0,    75,     0,     0,    77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,    84,    85,    86,     0,     0,     0,     0,    87,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88,
       0,    89,     0,    90,    91,   247,     0,     0,     0,    93,
       0,   165,     0,    95,     0,   166,   634,     5,     6,     7,
       8,     9,    10,     0,     0,     0,   160,     0,     0,    14,
      15,     0,     0,     0,     0,     0,    19,     0,     0,     0,
       0,     0,     0,     0,    26,     0,     0,     0,     0,     0,
      30,   161,   162,     0,   163,    35,     0,    36,     0,     0,
      38,     0,     0,    40,    41,     0,     0,    43,    44,     0,
      45,    46,     0,     0,     0,     0,     0,     0,    49,     0,
      51,     0,    53,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,   164,     0,    69,     0,     0,    71,     0,     0,     0,
      75,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
      84,    85,    86,     0,     0,     0,     0,    87,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    88,     0,
      89,     0,    90,    91,   247,     0,     0,     0,    93,     0,
     165,     0,    95,     0,   166,   953,     5,     6,     7,     8,
       9,    10,     0,     0,     0,   160,     0,     0,    14,    15,
       0,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,     0,     0,    26,     0,     0,     0,     0,     0,    30,
     161,   162,     0,   163,    35,     0,    36,     0,     0,    38,
       0,     0,    40,    41,     0,     0,    43,    44,     0,    45,
      46,     0,     0,     0,     0,     0,     0,    49,     0,    51,
       0,    53,     0,     0,     0,   315,    56,     0,     0,     0,
       0,     0,     0,     0,     0,    63,    64,    65,    66,    67,
     164,     0,    69,     0,     0,    71,     0,     0,     0,    75,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   316,     0,     0,   758,   317,   759,    83,    84,
      85,    86,     0,     0,   760,     0,    87,     0,     0,   761,
     208,   762,     0,     0,     0,     0,   763,    88,     0,    89,
       0,    90,    91,     0,   210,     0,   318,    93,     0,   165,
     764,    95,     0,   166,   639,   765,     0,   213,     0,     0,
     766,     0,   319,     0,   320,   321,   322,   767,   323,   324,
     325,     0,   326,   327,   328,   329,     0,     0,   216,   331,
     332,   333,   334,     0,   335,   336,   337,   768,     0,   338,
     339,   340,     0,     0,     0,     0,   218,   219,     0,   769,
       0,   221,     0,   770,     0,     0,   771,     0,     0,     0,
     772,     0,     0,   225,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   341,   342,   343,   344,   345,   346,
       0,     0,   349,   350,   351,   352,     0,   354,   355,   773,
     774,   775,   776,     0,     0,   777,     0,     0,     0,   778,
     779,   780,   781,   782,   783,   784,   785,   786,   787,   788,
     789,   790,     0,   791,     0,     0,   792,   793,   794,   795,
       0,     0,   796,     5,     6,     7,     8,     9,    10,     0,
       0,     0,   160,     0,     0,    14,    15,     0,     0,     0,
       0,     0,    19,   200,    21,     0,     0,     0,     0,     0,
      26,     0,     0,     0,     0,   201,    30,   161,   162,     0,
     163,    35,     0,    36,     0,     0,    38,     0,     0,    40,
      41,     0,     0,    43,    44,     0,    45,    46,     0,     0,
       0,     0,     0,     0,    49,    50,    51,     0,    53,     0,
       0,     0,     0,    56,     0,     0,    58,     0,     0,     0,
       0,     0,    63,    64,    65,    66,    67,   164,     0,    69,
       0,     0,    71,     0,     0,     0,    75,     0,     0,    77,
       0,    79,     0,     0,     0,     0,     0,     0,     0,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    83,    84,    85,    86,     0,
       0,     0,     0,    87,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    88,     0,    89,     0,    90,    91,
       0,     0,     0,     0,    93,     0,   165,     0,    95,     0,
     166,     5,     6,     7,     8,   189,    10,   190,     0,     0,
     160,     0,     0,    14,    15,     0,     0,  -116,     0,     0,
      19,     0,     0,     0,     0,     0,     0,     0,    26,     0,
       0,     0,     0,     0,    30,   161,   162,     0,   163,    35,
       0,    36,     0,     0,    38,     0,     0,    40,    41,     0,
       0,    43,    44,     0,    45,    46,     0,     0,     0,     0,
       0,     0,    49,     0,    51,     0,    53,     0,     0,     0,
       0,    56,  -116,     0,     0,     0,     0,     0,     0,     0,
      63,    64,    65,    66,    67,   164,     0,    69,     0,     0,
      71,     0,     0,   191,    75,     0,  -116,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    83,    84,    85,    86,     0,     0,     0,
       0,    87,     0,     0,     0,     0,     5,     6,     7,     8,
       9,    10,    88,     0,    89,   160,    90,    91,    14,    15,
       0,     0,    93,     0,   165,    19,    95,     0,   166,     0,
       0,     0,     0,    26,     0,     0,     0,     0,     0,    30,
     161,   162,     0,   163,    35,     0,    36,     0,     0,    38,
       0,     0,    40,    41,     0,     0,    43,    44,     0,    45,
      46,     0,     0,     0,     0,     0,     0,    49,     0,    51,
       0,    53,     0,     0,     0,     0,    56,     0,     0,     0,
       0,     0,     0,     0,     0,    63,    64,    65,    66,    67,
     164,     0,    69,     0,     0,    71,   251,   252,     0,    75,
     290,     0,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,    84,
      85,    86,     0,     0,     0,     0,    87,   291,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    88,     0,    89,
       0,    90,    91,   247,     0,     0,     0,    93,     0,   165,
       0,    95,     0,   166,     5,     6,     7,     8,     9,    10,
       0,     0,     0,   160,     0,     0,    14,    15,     0,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,    26,     0,     0,     0,     0,     0,    30,   161,   162,
       0,   163,    35,     0,    36,     0,     0,    38,     0,     0,
      40,    41,     0,     0,    43,    44,     0,    45,    46,     0,
       0,     0,     0,     0,     0,    49,     0,    51,     0,    53,
       0,     0,     0,     0,    56,     0,     0,     0,     0,     0,
       0,     0,     0,    63,    64,    65,    66,    67,   164,     0,
      69,     0,     0,    71,   251,   252,     0,    75,   290,     0,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,    84,    85,    86,
       0,     0,     0,     0,    87,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    88,     0,    89,     0,    90,
      91,   247,     0,     0,     0,    93,     0,   165,     0,    95,
     626,   166,     5,     6,     7,     8,     9,    10,     0,     0,
       0,   160,     0,     0,    14,    15,     0,     0,     0,     0,
       0,    19,     0,     0,     0,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,    30,   161,   162,     0,   163,
      35,     0,    36,     0,     0,    38,     0,     0,    40,    41,
       0,     0,    43,    44,     0,    45,    46,     0,     0,     0,
       0,     0,     0,    49,     0,    51,     0,    53,     0,     0,
       0,     0,    56,     0,     0,     0,     0,     0,     0,     0,
       0,    63,    64,    65,    66,    67,   164,     0,    69,     0,
       0,    71,   251,   252,     0,    75,   290,     0,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,    84,    85,    86,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,     0,    89,     0,    90,    91,   247,
       0,     0,     0,    93,     0,   165,     0,    95,   628,   166,
       5,     6,     7,     8,     9,    10,     0,     0,     0,   160,
       0,     0,    14,    15,     0,     0,     0,     0,     0,    19,
       0,   525,     0,     0,     0,     0,     0,    26,     0,     0,
       0,     0,     0,    30,   161,   162,     0,   163,    35,   526,
      36,     0,     0,    38,     0,     0,    40,    41,     0,     0,
      43,    44,     0,    45,    46,     0,     0,     0,     0,     0,
       0,    49,     0,    51,     0,    53,     0,     0,     0,     0,
      56,     0,     0,   527,     0,     0,     0,     0,     0,    63,
      64,    65,    66,    67,   164,     0,    69,     0,     0,    71,
       0,     0,     0,    75,     0,     0,    77,     0,   528,     0,
       0,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,    84,    85,    86,     0,     0,     0,     0,
      87,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,     0,    89,     0,    90,    91,     0,     0,     0,
       0,    93,     0,   165,     0,    95,     0,   166,     5,     6,
       7,     8,   189,    10,     0,     0,     0,   160,     0,     0,
      14,    15,     0,     0,  -116,     0,     0,    19,     0,     0,
       0,     0,     0,     0,     0,    26,     0,     0,     0,     0,
       0,    30,   161,   162,     0,   163,    35,     0,    36,     0,
       0,    38,     0,     0,    40,    41,     0,     0,    43,    44,
       0,    45,    46,     0,     0,     0,     0,     0,     0,    49,
       0,    51,     0,    53,     0,     0,     0,     0,    56,  -116,
       0,     0,     0,     0,     0,     0,     0,    63,    64,    65,
      66,    67,   164,     0,    69,     0,     0,    71,     0,     0,
     191,    75,     0,  -116,    77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,    84,    85,    86,     0,     0,     0,     0,    87,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,    88,
       0,    89,   160,    90,    91,    14,    15,     0,     0,    93,
       0,   165,    19,    95,     0,   166,     0,     0,     0,     0,
      26,     0,     0,     0,     0,     0,    30,   161,   162,     0,
     163,    35,     0,    36,     0,     0,    38,     0,     0,    40,
      41,     0,     0,    43,    44,     0,    45,    46,     0,     0,
       0,     0,     0,     0,    49,     0,    51,     0,    53,     0,
       0,     0,     0,    56,     0,     0,     0,     0,     0,     0,
       0,     0,    63,    64,    65,    66,    67,   164,     0,    69,
       0,     0,    71,   251,   252,     0,    75,     0,     0,    77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    83,    84,    85,    86,     0,
       0,     0,     0,    87,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    88,     0,    89,     0,    90,    91,
       0,   253,     0,     0,    93,     0,   165,     0,    95,     0,
     166,     5,     6,     7,     8,     9,    10,     0,     0,     0,
     160,     0,     0,    14,    15,     0,     0,     0,     0,     0,
      19,     0,     0,     0,     0,     0,     0,     0,    26,     0,
       0,     0,     0,     0,    30,   161,   162,     0,   163,    35,
       0,    36,     0,     0,    38,     0,     0,    40,    41,     0,
       0,    43,    44,     0,    45,    46,     0,     0,     0,     0,
       0,     0,    49,     0,    51,     0,    53,     0,     0,     0,
       0,    56,     0,     0,     0,     0,     0,     0,     0,     0,
      63,    64,    65,    66,    67,   164,     0,    69,     0,     0,
      71,   251,   252,     0,    75,     0,     0,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    83,    84,    85,    86,     0,     0,     0,
       0,    87,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    88,     0,    89,     0,    90,    91,   247,     0,
       0,     0,    93,     0,   165,     0,    95,     0,   166,     5,
       6,     7,     8,     9,    10,     0,     0,     0,   160,     0,
       0,    14,    15,     0,     0,     0,     0,     0,    19,     0,
       0,     0,     0,     0,     0,     0,    26,     0,     0,     0,
       0,     0,    30,   161,   162,     0,   163,    35,     0,    36,
       0,     0,    38,     0,     0,    40,    41,     0,     0,    43,
      44,     0,    45,    46,   728,     0,     0,     0,     0,     0,
      49,     0,    51,     0,    53,     0,     0,     0,     0,    56,
       0,     0,     0,     0,     0,     0,     0,     0,    63,    64,
      65,    66,    67,   164,     0,    69,     0,     0,    71,   251,
     252,     0,    75,     0,     0,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83,    84,    85,    86,     0,     0,     0,     0,    87,
       0,     0,     0,     0,     5,     6,     7,     8,     9,    10,
      88,     0,    89,   160,    90,    91,    14,    15,     0,     0,
      93,     0,   165,    19,    95,     0,   166,     0,     0,     0,
       0,    26,     0,     0,     0,     0,     0,    30,   161,   162,
       0,   163,    35,     0,    36,     0,     0,    38,     0,     0,
      40,    41,     0,     0,    43,    44,     0,    45,    46,     0,
       0,     0,     0,     0,     0,    49,   194,    51,     0,    53,
       0,     0,     0,     0,    56,     0,     0,     0,     0,     0,
       0,     0,     0,    63,    64,    65,    66,    67,   164,     0,
      69,     0,     0,    71,     0,     0,     0,    75,     0,     0,
      77,     0,     0,     0,     0,     0,     0,     0,   195,     0,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,    84,    85,    86,
       0,     0,     0,     0,    87,     0,     0,     0,     0,     5,
       6,     7,     8,     9,    10,    88,     0,    89,   160,    90,
      91,    14,    15,     0,     0,    93,     0,   165,    19,    95,
       0,   166,     0,     0,     0,     0,    26,     0,     0,     0,
       0,     0,    30,   161,   162,     0,   163,    35,     0,    36,
       0,     0,    38,     0,     0,    40,    41,     0,     0,    43,
      44,     0,    45,    46,     0,     0,     0,     0,     0,     0,
      49,     0,    51,     0,    53,     0,     0,     0,     0,    56,
       0,     0,     0,     0,     0,     0,     0,     0,    63,    64,
      65,    66,    67,   164,     0,    69,     0,     0,    71,     0,
       0,     0,    75,     0,     0,    77,     0,     0,     0,     0,
       0,     0,     0,   195,     0,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83,    84,    85,    86,     0,     0,     0,     0,    87,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      88,     0,    89,     0,    90,    91,   247,     0,     0,     0,
      93,     0,   165,     0,    95,     0,   166,     5,     6,     7,
       8,     9,    10,     0,     0,     0,   160,     0,     0,    14,
      15,     0,     0,     0,     0,     0,    19,     0,     0,     0,
       0,     0,     0,     0,    26,     0,     0,     0,     0,     0,
      30,   161,   162,     0,   163,    35,     0,    36,     0,     0,
      38,     0,     0,    40,    41,     0,     0,    43,    44,     0,
      45,    46,     0,     0,     0,     0,     0,     0,    49,     0,
      51,     0,    53,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,   164,     0,    69,     0,     0,    71,   251,   252,     0,
      75,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
      84,    85,    86,     0,     0,     0,     0,    87,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    88,     0,
      89,   160,    90,    91,    14,    15,     0,     0,    93,     0,
     165,    19,    95,     0,   166,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,    30,   161,   162,     0,   163,
      35,     0,    36,     0,     0,    38,     0,     0,    40,    41,
       0,     0,    43,    44,     0,    45,    46,     0,     0,     0,
       0,     0,     0,    49,     0,    51,     0,    53,     0,     0,
       0,     0,    56,     0,     0,     0,     0,     0,     0,     0,
       0,    63,    64,    65,    66,    67,   164,     0,    69,     0,
       0,    71,     0,     0,     0,    75,     0,     0,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,    84,    85,    86,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,     0,    89,     0,    90,    91,   247,
       0,     0,     0,    93,     0,   165,   624,    95,     0,   166,
       5,     6,     7,     8,     9,    10,     0,     0,     0,   160,
       0,     0,    14,    15,     0,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,     0,     0,    26,     0,     0,
       0,     0,     0,    30,   161,   162,     0,   163,    35,     0,
      36,     0,     0,    38,     0,     0,    40,    41,     0,     0,
      43,    44,     0,    45,    46,     0,     0,     0,     0,     0,
       0,    49,     0,    51,     0,    53,     0,     0,     0,     0,
      56,     0,     0,     0,     0,     0,     0,     0,     0,    63,
      64,    65,    66,    67,   164,     0,    69,     0,     0,    71,
       0,     0,     0,    75,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,   195,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,    84,    85,    86,     0,     0,     0,     0,
      87,     0,     0,     0,     0,     5,     6,     7,     8,     9,
      10,    88,     0,    89,   160,    90,    91,    14,    15,     0,
       0,    93,     0,   165,    19,    95,     0,   166,     0,     0,
       0,   233,    26,     0,     0,     0,     0,     0,    30,   161,
     162,     0,   163,    35,     0,    36,     0,     0,    38,     0,
       0,    40,    41,     0,     0,    43,    44,     0,    45,    46,
       0,     0,     0,     0,     0,     0,    49,     0,    51,     0,
      53,     0,     0,     0,     0,    56,     0,     0,     0,     0,
       0,     0,     0,     0,    63,    64,    65,    66,    67,   164,
       0,    69,     0,     0,    71,     0,     0,     0,    75,     0,
       0,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    83,    84,    85,
      86,     0,     0,     0,     0,    87,     0,     0,     0,     0,
       5,     6,     7,     8,     9,    10,    88,     0,    89,   160,
      90,    91,    14,    15,     0,     0,    93,     0,    94,    19,
      95,     0,   166,     0,     0,     0,     0,    26,     0,     0,
       0,     0,     0,    30,   161,   162,     0,   163,    35,     0,
      36,     0,     0,    38,     0,     0,    40,    41,     0,     0,
      43,    44,     0,    45,    46,     0,     0,     0,     0,     0,
       0,    49,     0,    51,     0,    53,     0,     0,     0,     0,
      56,     0,     0,     0,     0,     0,     0,     0,     0,    63,
      64,    65,    66,    67,   164,     0,    69,     0,     0,    71,
       0,     0,     0,    75,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,    84,    85,    86,     0,     0,     0,     0,
      87,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,     0,    89,     0,    90,    91,   247,     0,     0,
       0,    93,     0,   165,     0,    95,     0,   166,     5,     6,
       7,     8,     9,    10,     0,     0,     0,   160,     0,     0,
      14,   594,     0,     0,     0,     0,     0,    19,     0,     0,
       0,     0,     0,     0,     0,   595,     0,     0,     0,     0,
       0,    30,   161,   162,     0,   163,    35,     0,   596,     0,
       0,    38,     0,     0,    40,    41,     0,     0,    43,    44,
       0,    45,    46,     0,     0,     0,     0,     0,     0,   597,
       0,    51,     0,    53,     0,     0,     0,     0,    56,     0,
       0,     0,     0,     0,     0,     0,     0,   598,   599,    65,
      66,    67,   600,     0,    69,     0,     0,    71,     0,     0,
       0,    75,     0,     0,   601,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,    84,    85,    86,     0,     0,     0,     0,    87,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88,
       0,    89,     0,    90,    91,   247,     0,     0,     0,    93,
       0,   165,     0,    95,     0,   905,     5,     6,     7,     8,
       9,    10,     0,     0,     0,   160,     0,     0,    14,    15,
       0,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,     0,     0,    26,     0,     0,     0,     0,     0,    30,
     161,   162,     0,   163,    35,     0,    36,     0,     0,    38,
       0,     0,    40,    41,     0,     0,    43,    44,     0,    45,
      46,     0,     0,     0,     0,     0,     0,    49,     0,    51,
       0,    53,     0,     0,     0,     0,    56,     0,     0,     0,
       0,     0,     0,     0,     0,    63,    64,    65,    66,    67,
     164,     0,    69,     0,     0,    71,     0,     0,     0,    75,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,    84,
      85,    86,     0,     0,     0,     0,    87,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    88,     0,    89,
       0,    90,    91,   247,     0,     0,     0,    93,     0,   165,
       0,    95,     0,   905,     5,     6,     7,     8,     9,    10,
       0,     0,     0,   160,     0,     0,    14,    15,     0,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,    26,     0,     0,     0,     0,     0,    30,   161,   162,
       0,   890,    35,     0,    36,     0,     0,    38,     0,     0,
      40,    41,     0,     0,    43,    44,     0,    45,    46,     0,
       0,     0,     0,     0,     0,    49,     0,    51,     0,    53,
       0,     0,     0,     0,    56,     0,     0,     0,     0,     0,
       0,     0,     0,    63,    64,    65,    66,    67,   164,     0,
      69,     0,     0,    71,     0,     0,     0,    75,     0,     0,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,    84,    85,    86,
       0,     0,     0,     0,    87,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    88,     0,    89,     0,    90,
      91,   247,     0,     0,     0,    93,     0,   165,     0,    95,
       0,   166,     5,     6,     7,     8,     9,    10,     0,     0,
       0,   160,     0,     0,    14,    15,     0,     0,     0,     0,
       0,    19,     0,     0,     0,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,    30,   161,   162,     0,   163,
      35,     0,    36,     0,     0,    38,     0,     0,    40,    41,
       0,     0,    43,    44,     0,    45,    46,     0,     0,     0,
       0,     0,     0,    49,     0,    51,     0,    53,     0,     0,
       0,     0,    56,     0,     0,     0,     0,     0,     0,     0,
       0,    63,    64,    65,    66,    67,   164,     0,    69,     0,
       0,    71,     0,     0,     0,    75,     0,     0,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,    84,    85,    86,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    88,     0,    89,   160,    90,    91,    14,
      15,     0,     0,    93,     0,   165,    19,    95,     0,   166,
       0,     0,     0,     0,    26,     0,     0,     0,     0,     0,
      30,   161,   162,     0,   163,    35,     0,    36,     0,     0,
      38,     0,     0,    40,    41,     0,     0,    43,    44,     0,
      45,    46,     0,     0,     0,     0,     0,     0,    49,     0,
      51,     0,    53,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,   164,     0,    69,     0,     0,    71,     0,     0,     0,
      75,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
      84,    85,    86,     0,     0,     0,     0,    87,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    88,     0,
      89,   160,    90,    91,    14,   490,     0,     0,    93,     0,
      94,    19,    95,     0,   166,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,    30,   161,   162,     0,   163,
      35,     0,    36,     0,     0,    38,     0,     0,    40,    41,
       0,     0,    43,    44,     0,    45,    46,     0,     0,     0,
       0,     0,     0,    49,     0,    51,     0,    53,     0,     0,
       0,     0,    56,     0,     0,     0,     0,     0,     0,     0,
       0,    63,    64,    65,    66,    67,   164,     0,    69,     0,
       0,    71,     0,     0,     0,    75,     0,     0,   491,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,    84,    85,    86,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    88,     0,    89,   160,    90,    91,    14,
      15,     0,     0,    93,     0,   165,    19,    95,     0,   166,
       0,     0,     0,     0,    26,     0,     0,     0,     0,     0,
      30,   161,   162,     0,   163,    35,     0,    36,     0,     0,
      38,     0,     0,    40,    41,     0,     0,    43,    44,     0,
      45,    46,     0,     0,     0,     0,     0,     0,    49,     0,
      51,     0,    53,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,   164,     0,    69,     0,     0,    71,     0,     0,     0,
      75,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
      84,    85,    86,     0,     0,     0,     0,    87,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    88,     0,
      89,   160,    90,    91,    14,   594,     0,     0,   567,     0,
     165,    19,    95,     0,   166,     0,     0,     0,     0,   595,
       0,     0,     0,     0,     0,    30,   161,   162,     0,   163,
      35,     0,   596,     0,     0,    38,     0,     0,    40,    41,
       0,     0,    43,    44,     0,    45,    46,     0,     0,     0,
       0,     0,     0,   597,     0,    51,     0,    53,     0,     0,
       0,     0,    56,     0,     0,     0,     0,     0,     0,     0,
       0,   598,   599,    65,    66,    67,   600,     0,    69,     0,
       0,    71,     0,     0,     0,    75,     0,     0,   601,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,    84,    85,    86,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    88,     0,    89,   160,    90,    91,    14,
      15,     0,     0,    93,     0,   165,    19,    95,     0,   602,
       0,     0,     0,     0,    26,     0,     0,     0,     0,     0,
      30,   161,   162,     0,   163,    35,     0,    36,     0,     0,
      38,     0,     0,    40,    41,     0,     0,    43,    44,     0,
      45,    46,     0,     0,     0,     0,     0,     0,    49,     0,
      51,     0,    53,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,   164,     0,    69,     0,     0,    71,     0,     0,     0,
      75,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
      84,    85,    86,     0,     0,     0,     0,    87,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    88,     0,
      89,   160,    90,    91,    14,    15,     0,     0,    93,     0,
     165,    19,    95,     0,   602,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,    30,   161,   162,     0,   670,
      35,     0,    36,     0,     0,    38,     0,     0,    40,    41,
       0,     0,    43,    44,     0,    45,    46,     0,     0,     0,
       0,     0,     0,    49,     0,    51,     0,    53,     0,     0,
       0,     0,    56,     0,     0,     0,     0,     0,     0,     0,
       0,    63,    64,    65,    66,    67,   164,     0,    69,     0,
       0,    71,     0,     0,     0,    75,     0,     0,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,    84,    85,    86,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    88,     0,    89,   160,    90,    91,    14,
      15,     0,     0,    93,     0,   165,    19,    95,     0,   166,
       0,     0,     0,     0,    26,     0,     0,     0,     0,     0,
      30,   161,   162,     0,   673,    35,     0,    36,     0,     0,
      38,     0,     0,    40,    41,     0,     0,    43,    44,     0,
      45,    46,     0,     0,     0,     0,     0,     0,    49,     0,
      51,     0,    53,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,   164,     0,    69,     0,     0,    71,     0,     0,     0,
      75,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
      84,    85,    86,     0,     0,     0,     0,    87,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    88,     0,
      89,   160,    90,    91,    14,    15,     0,     0,    93,     0,
     165,    19,    95,     0,   166,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,    30,   161,   162,     0,   884,
      35,     0,    36,     0,     0,    38,     0,     0,    40,    41,
       0,     0,    43,    44,     0,    45,    46,     0,     0,     0,
       0,     0,     0,    49,     0,    51,     0,    53,     0,     0,
       0,     0,    56,     0,     0,     0,     0,     0,     0,     0,
       0,    63,    64,    65,    66,    67,   164,     0,    69,     0,
       0,    71,     0,     0,     0,    75,     0,     0,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,    84,    85,    86,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    88,     0,    89,   160,    90,    91,    14,
      15,     0,     0,    93,     0,   165,    19,    95,     0,   166,
       0,     0,     0,     0,    26,     0,     0,     0,     0,     0,
      30,   161,   162,     0,   885,    35,     0,    36,     0,     0,
      38,     0,     0,    40,    41,     0,     0,    43,    44,     0,
      45,    46,     0,     0,     0,     0,     0,     0,    49,     0,
      51,     0,    53,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,   164,     0,    69,     0,     0,    71,     0,     0,     0,
      75,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
      84,    85,    86,     0,     0,     0,     0,    87,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    88,     0,
      89,   160,    90,    91,    14,    15,     0,     0,    93,     0,
     165,    19,    95,     0,   166,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,    30,   161,   162,     0,   887,
      35,     0,    36,     0,     0,    38,     0,     0,    40,    41,
       0,     0,    43,    44,     0,    45,    46,     0,     0,     0,
       0,     0,     0,    49,     0,    51,     0,    53,     0,     0,
       0,     0,    56,     0,     0,     0,     0,     0,     0,     0,
       0,    63,    64,    65,    66,    67,   164,     0,    69,     0,
       0,    71,     0,     0,     0,    75,     0,     0,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,    84,    85,    86,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    88,     0,    89,   160,    90,    91,    14,
      15,     0,     0,    93,     0,   165,    19,    95,     0,   166,
       0,     0,     0,     0,    26,     0,     0,     0,     0,     0,
      30,   161,   162,     0,   888,    35,     0,    36,     0,     0,
      38,     0,     0,    40,    41,     0,     0,    43,    44,     0,
      45,    46,     0,     0,     0,     0,     0,     0,    49,     0,
      51,     0,    53,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,   164,     0,    69,     0,     0,    71,     0,     0,     0,
      75,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
      84,    85,    86,     0,     0,     0,     0,    87,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    88,     0,
      89,   160,    90,    91,    14,    15,     0,     0,    93,     0,
     165,    19,    95,     0,   166,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,    30,   161,   162,     0,   889,
      35,     0,    36,     0,     0,    38,     0,     0,    40,    41,
       0,     0,    43,    44,     0,    45,    46,     0,     0,     0,
       0,     0,     0,    49,     0,    51,     0,    53,     0,     0,
       0,     0,    56,     0,     0,     0,     0,     0,     0,     0,
       0,    63,    64,    65,    66,    67,   164,     0,    69,     0,
       0,    71,     0,     0,     0,    75,     0,     0,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,    84,    85,    86,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    88,     0,    89,   160,    90,    91,    14,
      15,     0,     0,    93,     0,   165,    19,    95,     0,   166,
       0,     0,     0,     0,    26,     0,     0,     0,     0,     0,
      30,   161,   162,     0,   890,    35,     0,    36,     0,     0,
      38,     0,     0,    40,    41,     0,     0,    43,    44,     0,
      45,    46,     0,     0,     0,     0,     0,     0,    49,     0,
      51,     0,    53,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,   164,     0,    69,     0,     0,    71,     0,     0,     0,
      75,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
      84,    85,    86,     0,     0,     0,     0,    87,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    88,     0,
      89,   160,    90,    91,    14,   594,     0,     0,    93,     0,
     165,    19,    95,     0,   166,     0,     0,     0,     0,   595,
       0,     0,     0,     0,     0,    30,   161,   162,     0,   163,
      35,     0,   596,     0,     0,    38,     0,     0,    40,    41,
       0,     0,    43,    44,     0,    45,    46,     0,     0,     0,
       0,     0,     0,   597,     0,    51,     0,    53,     0,     0,
       0,     0,    56,     0,     0,     0,     0,     0,     0,     0,
       0,   598,   599,    65,    66,    67,   600,     0,    69,     0,
       0,    71,     0,     0,     0,    75,     0,     0,   601,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,    84,    85,    86,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    88,     0,    89,   160,    90,    91,    14,
      15,     0,     0,    93,     0,   165,    19,    95,     0,   972,
       0,     0,     0,     0,    26,     0,     0,     0,     0,     0,
      30,   161,   162,     0,   163,    35,     0,    36,     0,     0,
      38,     0,     0,    40,    41,     0,     0,    43,    44,     0,
      45,    46,     0,     0,     0,     0,     0,     0,    49,     0,
      51,     0,    53,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,   164,     0,    69,     0,     0,    71,     0,     0,     0,
      75,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
      84,    85,    86,     0,     0,     0,     0,    87,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    88,     0,
      89,   160,    90,    91,    14,    15,     0,     0,    93,     0,
       0,    19,    95,     0,   972,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,    30,   161,   162,     0,   163,
      35,     0,    36,     0,     0,    38,     0,     0,    40,    41,
       0,     0,    43,    44,     0,    45,    46,     0,     0,     0,
       0,     0,     0,    49,     0,    51,     0,    53,     0,     0,
       0,     0,    56,     0,     0,     0,     0,     0,     0,     0,
       0,    63,    64,    65,    66,    67,   164,     0,    69,     0,
       0,    71,     0,     0,     0,    75,     0,     0,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,    84,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    88,     0,    89,   160,     0,    91,    14,
      15,     0,     0,    93,     0,   165,    19,    95,     0,   166,
       0,     0,     0,     0,    26,     0,     0,     0,     0,     0,
      30,   161,   162,     0,   163,    35,     0,    36,     0,     0,
      38,     0,     0,    40,    41,     0,     0,    43,    44,     0,
      45,    46,     0,     0,     0,     0,     0,     0,    49,     0,
      51,     0,    53,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,   164,     0,    69,     0,     0,    71,     0,     0,     0,
      75,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -385,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,     0,     0,     0,  -385,     0,     0,     0,  -385,     5,
       6,     7,     8,     9,    10,     0,     0,     0,   160,     0,
      89,    14,    15,     0,   247,     0,     0,     0,    19,     0,
     165,     0,    95,  -385,   905,     0,    26,     0,     0,     0,
       0,     0,    30,   161,   162,     0,   163,    35,     0,    36,
       0,     0,    38,     0,     0,    40,    41,  -367,     0,    43,
      44,     0,    45,    46,     0,     0,     0,     0,     0,     0,
      49,     0,    51,     0,    53,     0,     0,     0,     0,    56,
       0,     0,     0,     0,  -367,     0,     0,     0,    63,    64,
      65,    66,    67,   164,     0,    69,     0,  -367,    71,     0,
       0,     0,    75,     0,     0,    77,     0,     0,     0,  -367,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,     0,     0,     0,     0,     0,
       0,     0,    84,     0,     5,     6,     7,     8,     9,    10,
       0,     0,     0,   160,     0,     0,    14,    15,     0,     0,
       0,     0,    89,    19,     0,   356,     0,  -367,  -508,     0,
    -508,    26,  -367,     0,    95,     0,   972,    30,   161,   162,
       0,   163,    35,     0,    36,     0,     0,    38,     0,     0,
      40,    41,     0,     0,    43,    44,     0,    45,    46,     0,
       0,     0,     0,     0,     0,    49,     0,    51,     0,    53,
       0,     0,     0,     0,    56,     0,     0,     0,     0,     0,
       0,     0,     0,    63,    64,    65,    66,    67,   164,     0,
      69,     0,     0,    71,     0,     0,     0,    75,     0,     0,
      77,     0,     5,     6,     7,     8,     9,    10,     0,     0,
       0,   160,     0,     0,    14,    15,     0,     0,     0,     0,
       0,    19,     0,     0,     0,     0,     0,    84,     0,    26,
       0,     0,     0,     0,     0,    30,   161,   162,     0,   163,
      35,     0,    36,     0,     0,    38,     0,    89,    40,    41,
       0,     0,    43,    44,     0,    45,    46,   165,     0,    95,
       0,   166,     0,    49,     0,    51,     0,    53,     0,     0,
       0,     0,    56,     0,     0,     0,     0,     0,     0,     0,
       0,    63,    64,    65,    66,    67,   164,     0,    69,     0,
       0,    71,     0,     0,     0,    75,     0,     0,    77,     0,
       5,     6,     7,     8,     9,    10,     0,     0,     0,   160,
       0,     0,    14,    15,     0,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,    84,     0,    26,     0,     0,
       0,     0,     0,    30,   161,   162,     0,   163,    35,     0,
      36,     0,     0,    38,     0,    89,    40,    41,     0,     0,
      43,    44,     0,    45,    46,   165,     0,    95,     0,   602,
       0,    49,     0,    51,     0,    53,     0,     0,     0,     0,
      56,     0,     0,     0,     0,     0,     0,     0,     0,    63,
      64,    65,    66,    67,   164,     0,    69,     0,   933,    71,
       0,     0,     0,    75,     0,   760,    77,     0,     0,     0,
     207,   208,   762,     0,     0,     0,     0,   209,     0,     0,
       0,     0,     0,     0,     0,   210,     0,     0,     0,     0,
       0,   764,     0,    84,     0,     0,   212,     0,   213,     0,
       0,   214,     0,     0,     0,     0,     0,     0,   215,     0,
       0,     0,     0,    89,     0,     0,     0,     0,     0,   216,
       0,     0,     0,     0,     0,    95,     0,   166,   217,     0,
       0,     0,     0,     0,     0,     0,     0,   218,   219,     0,
     220,     0,   221,     0,   934,     0,   313,   771,     0,     0,
       0,   224,     0,   314,   225,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   315,   341,   342,   343,   344,   345,
     346,     0,     0,   349,   350,   351,   352,     0,   354,   355,
     773,   774,   775,   776,     0,     0,   777,     0,     0,     0,
     778,   779,   780,   781,   782,   783,   784,   785,   786,   787,
     788,   789,   790,     0,   791,     0,     0,   792,   793,   794,
     795,   316,     0,     0,     0,   317,     0,   313,     0,     0,
       0,     0,     0,     0,   314,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   315,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   318,     0,     0,   313,     0,
       0,     0,     0,     0,     0,   314,     0,     0,     0,     0,
       0,   319,     0,   320,   321,   322,   315,   323,   324,   325,
       0,   326,   327,   328,   329,   330,     0,     0,   331,   332,
     333,   334,   316,   335,   336,   337,   317,     0,   338,   339,
     340,     0,     0,     0,     0,     0,     0,   968,     0,     0,
       0,     0,     0,     0,     0,     0,   315,     0,     0,     0,
       0,     0,     0,   316,     0,     0,   318,   317,     0,   313,
       0,     0,     0,     0,     0,     0,   314,     0,     0,     0,
       0,     0,   319,     0,   320,   321,   322,   315,   323,   324,
     325,     0,   326,   327,   328,   329,   330,   318,     0,   331,
     332,   333,   334,   316,   335,   336,   337,   317,     0,   338,
     339,   340,     0,   319,     0,   320,   321,   322,  1035,   323,
     324,   325,     0,   326,   327,   328,   329,   330,     0,     0,
     331,   332,   333,   334,   316,   335,   336,   337,   317,     0,
     338,   339,   340,     0,     0,   313,     0,   625,     0,     0,
       0,     0,   314,   319,     0,   320,   321,   322,     0,   323,
     324,   325,     0,   315,   327,   328,   329,     0,   318,     0,
     331,   332,   333,   334,     0,     0,     0,   337,     0,     0,
     338,   339,   340,     0,   319,     0,   320,   321,   322,     0,
     323,   324,   325,     0,   326,   327,   328,   329,   330,     0,
       0,   331,   332,   333,   334,     0,   335,   336,   337,     0,
     316,   338,   339,   340,   317,     0,     0,     0,   932,     0,
       0,   313,     0,   405,     0,     0,     0,     0,   314,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   315,
       0,     0,     0,     0,   318,   341,   342,   343,   344,   345,
     346,     0,     0,   349,   350,   351,   352,     0,   354,   355,
     319,     0,   320,   321,   322,     0,   323,   324,   325,     0,
     326,   327,   328,   329,   330,     0,     0,   331,   332,   333,
     334,     0,   335,   336,   337,     0,   316,   338,   339,   340,
     317,   369,     0,     0,     0,     0,     0,   313,     0,   819,
       0,     0,     0,     0,   314,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   315,     0,     0,     0,     0,
     318,   341,   342,   343,   344,   345,   346,     0,     0,   349,
     350,   351,   352,     0,   354,   355,   319,     0,   320,   321,
     322,     0,   323,   324,   325,     0,   326,   327,   328,   329,
     330,     0,     0,   331,   332,   333,   334,     0,   335,   336,
     337,     0,   316,   338,   339,   340,   317,   369,     0,     0,
       0,     0,     0,   313,     0,   826,     0,     0,     0,     0,
     314,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   315,     0,     0,     0,     0,   318,   341,   342,   343,
     344,   345,   346,     0,     0,   349,   350,   351,   352,     0,
     354,   355,   319,     0,   320,   321,   322,     0,   323,   324,
     325,     0,   326,   327,   328,   329,   330,     0,     0,   331,
     332,   333,   334,     0,   335,   336,   337,     0,   316,   338,
     339,   340,   317,   369,     0,     0,     0,     0,     0,   313,
       0,   945,     0,     0,     0,     0,   314,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   315,     0,     0,
       0,     0,   318,   341,   342,   343,   344,   345,   346,     0,
       0,   349,   350,   351,   352,     0,   354,   355,   319,     0,
     320,   321,   322,     0,   323,   324,   325,     0,   326,   327,
     328,   329,   330,     0,     0,   331,   332,   333,   334,     0,
     335,   336,   337,     0,   316,   338,   339,   340,   317,   369,
       0,     0,     0,     0,     0,   313,     0,   946,     0,     0,
       0,     0,   314,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   315,     0,     0,     0,     0,   318,   341,
     342,   343,   344,   345,   346,     0,     0,   349,   350,   351,
     352,     0,   354,   355,   319,     0,   320,   321,   322,     0,
     323,   324,   325,     0,   326,   327,   328,   329,   330,     0,
       0,   331,   332,   333,   334,     0,   335,   336,   337,     0,
     316,   338,   339,   340,   317,   369,     0,     0,     0,     0,
       0,   313,     0,   947,     0,     0,     0,     0,   314,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   315,
       0,     0,     0,     0,   318,   341,   342,   343,   344,   345,
     346,     0,     0,   349,   350,   351,   352,     0,   354,   355,
     319,     0,   320,   321,   322,     0,   323,   324,   325,     0,
     326,   327,   328,   329,   330,     0,     0,   331,   332,   333,
     334,     0,   335,   336,   337,     0,   316,   338,   339,   340,
     317,   369,     0,     0,     0,     0,     0,   313,     0,   948,
       0,     0,     0,     0,   314,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   315,     0,     0,     0,     0,
     318,   341,   342,   343,   344,   345,   346,     0,     0,   349,
     350,   351,   352,     0,   354,   355,   319,     0,   320,   321,
     322,     0,   323,   324,   325,     0,   326,   327,   328,   329,
     330,     0,     0,   331,   332,   333,   334,     0,   335,   336,
     337,     0,   316,   338,   339,   340,   317,   369,     0,     0,
       0,     0,     0,   313,     0,   970,     0,     0,     0,     0,
     314,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   315,     0,     0,     0,     0,   318,   341,   342,   343,
     344,   345,   346,     0,     0,   349,   350,   351,   352,     0,
     354,   355,   319,     0,   320,   321,   322,     0,   323,   324,
     325,     0,   326,   327,   328,   329,   330,     0,     0,   331,
     332,   333,   334,     0,   335,   336,   337,     0,   316,   338,
     339,   340,   317,   369,     0,     0,     0,     0,     0,     0,
       0,   971,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   313,     0,     0,     0,     0,     0,     0,   314,     0,
       0,     0,   318,   341,   342,   343,   344,   345,   346,   315,
     397,   349,   350,   351,   352,     0,   354,   355,   319,     0,
     320,   321,   322,   398,   323,   324,   325,     0,   326,   327,
     328,   329,   330,     0,     0,   331,   332,   333,   334,     0,
     335,   336,   337,     0,     0,   338,   339,   340,     0,   369,
       0,     0,     0,     0,     0,     0,   316,     0,     0,     0,
     317,     0,   313,     0,     0,     0,     0,     0,     0,   314,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     315,   391,     0,     0,     0,     0,   394,     0,     0,     0,
     318,     0,     0,     0,   392,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   319,     0,   320,   321,
     322,     0,   323,   324,   325,     0,   326,   327,   328,   329,
     330,     0,     0,   331,   332,   333,   334,   316,   335,   336,
     337,   317,     0,   338,   339,   340,     0,   369,   313,     0,
       0,     0,     0,     0,     0,   314,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   315,   699,     0,     0,
       0,   318,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   319,     0,   320,
     321,   322,     0,   323,   324,   325,     0,   326,   327,   328,
     329,   330,     0,     0,   331,   332,   333,   334,     0,   335,
     336,   337,     0,   316,   338,   339,   340,   317,   369,   313,
       0,     0,     0,     0,     0,     0,   314,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   315,   233,     0,
       0,     0,     0,   394,     0,     0,     0,   318,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   319,     0,   320,   321,   322,     0,   323,
     324,   325,     0,   326,   327,   328,   329,   330,     0,     0,
     331,   332,   333,   334,   316,   335,   336,   337,   317,     0,
     338,   339,   340,     0,   369,   313,     0,     0,     0,     0,
       0,     0,   314,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   315,   691,     0,     0,     0,   318,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   319,     0,   320,   321,   322,     0,
     323,   324,   325,     0,   326,   327,   328,   329,   330,     0,
       0,   331,   332,   333,   334,     0,   335,   336,   337,     0,
     316,   338,   339,   340,   317,   369,   313,     0,     0,     0,
       0,     0,     0,   314,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   315,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   318,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   313,     0,
     319,     0,   320,   321,   322,   314,   323,   324,   325,     0,
     326,   327,   328,   329,   330,     0,   315,   331,   332,   333,
     334,   316,   335,   336,   337,   317,     0,   338,   339,   340,
       0,   369,     0,     0,   709,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   318,     0,     0,     0,     0,
       0,     0,     0,   316,     0,     0,     0,   317,     0,     0,
       0,   319,     0,   320,   321,   322,     0,   323,   324,   325,
       0,   326,   327,   328,   329,   330,     0,     0,   331,   332,
     333,   334,     0,   335,   336,   337,     0,   318,   338,   339,
     340,     0,   369,     0,     0,     0,     0,     0,     0,     0,
       0,   313,     0,   319,     0,   320,   321,   322,   314,   323,
     324,   325,     0,   326,   327,   328,   329,   330,     0,   315,
     331,   332,   333,   334,   402,   335,   336,   337,     0,     0,
     338,   339,   340,     0,   432,     0,     0,     0,     0,     0,
       0,     0,   313,     0,     0,     0,     0,     0,     0,   314,
       0,   403,     0,     0,     0,     0,     0,     0,     0,     0,
     315,     0,     0,     0,     0,     0,   316,     0,     0,     0,
     317,     0,     0,     0,   371,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     318,     0,     0,     0,     0,     0,     0,   316,     0,     0,
       0,   317,     0,     0,     0,     0,   319,     0,   320,   321,
     322,     0,   323,   324,   325,     0,   326,   327,   328,   329,
     330,     0,     0,   331,   332,   333,   334,   155,   335,   336,
     337,   318,   404,   338,   339,   340,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   313,     0,   319,     0,   320,
     321,   322,   314,   323,   324,   325,     0,   326,   327,   328,
     329,   330,     0,   315,   331,   332,   333,   334,   445,   335,
     336,   337,     0,     0,   338,   339,   340,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   313,     0,     0,     0,
       0,     0,     0,   314,     0,   446,     0,     0,     0,     0,
       0,     0,     0,     0,   315,   534,     0,     0,     0,     0,
     316,     0,     0,     0,   317,     0,     0,     0,   535,     0,
       0,     0,     0,     0,     0,     0,     0,   313,     0,     0,
       0,     0,     0,     0,   314,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   318,   315,   536,     0,     0,     0,
       0,   316,     0,     0,     0,   317,     0,     0,     0,   537,
     319,     0,   320,   321,   322,     0,   323,   324,   325,     0,
     326,   327,   328,   329,   330,     0,     0,   331,   332,   333,
     334,     0,   335,   336,   337,   318,     0,   338,   339,   340,
       0,     0,   316,     0,     0,     0,   317,     0,     0,     0,
       0,   319,     0,   320,   321,   322,     0,   323,   324,   325,
       0,   326,   327,   328,   329,   330,     0,     0,   331,   332,
     333,   334,     0,   335,   336,   337,   318,     0,   338,   339,
     340,     0,     0,   313,     0,     0,     0,     0,     0,     0,
     314,     0,   319,     0,   320,   321,   322,     0,   323,   324,
     325,   315,   326,   327,   328,   329,   330,     0,     0,   331,
     332,   333,   334,     0,   335,   336,   337,     0,     0,   338,
     339,   340,     0,     0,   313,     0,     0,     0,     0,     0,
       0,   314,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   315,     0,     0,     0,     0,     0,   316,     0,
       0,     0,   317,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   313,     0,     0,     0,     0,
       0,     0,   314,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   318,   315,     0,     0,     0,     0,     0,   316,
       0,     0,     0,   317,     0,     0,     0,     0,   319,     0,
     320,   321,   322,     0,   323,   324,   325,     0,   326,   327,
     328,   329,   330,     0,     0,   331,   332,   333,   334,     0,
     335,   336,   337,   318,   436,   338,   339,   340,     0,     0,
     316,     0,     0,     0,   317,     0,     0,     0,     0,   319,
       0,   320,   321,   322,     0,   323,   324,   325,     0,   326,
     327,   328,   329,   330,     0,     0,   331,   332,   333,   334,
       0,   335,   336,   337,   318,   438,   338,   339,   340,     0,
       0,   313,     0,     0,     0,     0,     0,     0,   314,     0,
     319,     0,   320,   321,   322,     0,   323,   324,   325,   315,
     326,   327,   328,   329,   330,     0,     0,   331,   332,   333,
     334,     0,   335,   336,   337,     0,   440,   338,   339,   340,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   313,     0,     0,     0,
       0,     0,     0,   314,     0,     0,   316,     0,     0,     0,
     317,     0,     0,     0,   315,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   313,     0,     0,
       0,     0,     0,     0,   314,     0,     0,     0,     0,     0,
     318,     0,     0,     0,     0,   315,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   319,     0,   320,   321,
     322,   316,   323,   324,   325,   317,   326,   327,   328,   329,
     330,     0,     0,   331,   332,   333,   334,     0,   335,   336,
     337,     0,   448,   338,   339,   340,     0,     0,     0,     0,
       0,     0,   316,     0,   465,   318,   317,     0,     0,     0,
       0,     0,     0,     0,     0,   538,     0,     0,     0,   313,
       0,   319,     0,   320,   321,   322,   314,   323,   324,   325,
       0,   326,   327,   328,   329,   330,   318,   315,   331,   332,
     333,   334,     0,   335,   336,   337,     0,     0,   338,   339,
     340,     0,   319,     0,   320,   321,   322,     0,   323,   324,
     325,     0,   326,   327,   328,   329,   330,     0,     0,   331,
     332,   333,   334,     0,   335,   336,   337,     0,     0,   338,
     339,   340,     0,     0,   316,     0,     0,     0,   317,     0,
     313,     0,     0,     0,     0,     0,     0,   314,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   315,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   318,     0,
       0,   313,     0,     0,     0,     0,     0,     0,   314,     0,
       0,     0,     0,     0,   319,     0,   320,   321,   322,   315,
     323,   324,   325,     0,   326,   327,   328,   329,   330,     0,
    -480,   331,   332,   333,   334,   316,   335,   336,   337,   317,
       0,   338,   339,   340,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   313,   704,     0,     0,
       0,     0,     0,   314,     0,   155,   316,     0,     0,   318,
     317,     0,     0,     0,   315,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   319,     0,   320,   321,   322,
       0,   323,   324,   325,     0,   326,   327,   328,   329,   330,
     318,     0,   331,   332,   333,   334,     0,   335,   336,   337,
       0,     0,   338,   339,   340,     0,   319,     0,   320,   321,
     322,   316,   323,   324,   325,   317,   326,   327,   328,   329,
     330,     0,     0,   331,   332,   333,   334,     0,   335,   336,
     337,   313,   680,   338,   339,   340,     0,     0,   314,     0,
       0,     0,     0,     0,     0,   318,     0,     0,     0,   315,
       0,     0,   707,     0,     0,     0,     0,     0,     0,     0,
       0,   319,     0,   320,   321,   322,     0,   323,   324,   325,
       0,   326,   327,   328,   329,   330,     0,     0,   331,   332,
     333,   334,     0,   335,   336,   337,   313,     0,   338,   339,
     340,     0,     0,   314,     0,     0,   316,     0,     0,     0,
     317,     0,     0,     0,   315,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   313,     0,     0,
       0,     0,     0,     0,   314,     0,     0,     0,     0,     0,
     318,     0,     0,     0,     0,   315,   809,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   319,     0,   320,   321,
     322,   316,   323,   324,   325,   317,   326,   327,   328,   329,
     330,     0,     0,   331,   332,   333,   334,     0,   335,   336,
     337,     0,   313,   338,   339,   340,     0,     0,     0,   314,
       0,     0,   316,     0,   749,   318,   317,     0,     0,     0,
     315,   812,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   319,     0,   320,   321,   322,     0,   323,   324,   325,
       0,   326,   327,   328,   329,   330,   318,     0,   331,   332,
     333,   334,     0,   335,   336,   337,     0,     0,   338,   339,
     340,     0,   319,     0,   320,   321,   322,   316,   323,   324,
     325,   317,   326,   327,   328,   329,   330,     0,     0,   331,
     332,   333,   334,     0,   335,   336,   337,   313,     0,   338,
     339,   340,     0,     0,   314,     0,     0,     0,     0,     0,
       0,   318,     0,     0,     0,   315,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   319,     0,   320,
     321,   322,     0,   323,   324,   325,     0,   326,   327,   328,
     329,   330,     0,     0,   331,   332,   333,   334,     0,   335,
     336,   337,     0,     0,   338,   339,   340,     0,     0,     0,
       0,     0,   316,     0,     0,     0,   317,     0,     0,     0,
       0,     0,     0,   313,     0,   883,     0,     0,     0,     0,
     314,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   315,     0,     0,     0,     0,   318,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     313,   900,   319,     0,   320,   321,   322,   314,   323,   324,
     325,     0,   326,   327,   328,   329,   330,     0,   315,   331,
     332,   333,   334,     0,   335,   336,   337,     0,   316,   338,
     339,   340,   317,     0,     0,     0,     0,     0,     0,     0,
       0,   886,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   318,     0,     0,   316,     0,     0,     0,   317,
       0,     0,     0,     0,     0,     0,   313,     0,   319,     0,
     320,   321,   322,   314,   323,   324,   325,     0,   326,   327,
     328,   329,   330,     0,   315,   331,   332,   333,   334,   318,
     335,   336,   337,     0,     0,   338,   339,   340,     0,     0,
       0,     0,     0,     0,     0,   319,     0,   320,   321,   322,
       0,   323,   324,   325,     0,   326,   327,   328,   329,   330,
       0,     0,   331,   332,   333,   334,     0,   335,   336,   337,
       0,   316,   338,   339,   340,   317,     0,     0,     0,     0,
       0,     0,   313,     0,   981,     0,     0,     0,     0,   314,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     315,     0,     0,     0,     0,   318,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   319,     0,   320,   321,   322,     0,   323,   324,   325,
       0,   326,   327,   328,   329,   330,     0,     0,   331,   332,
     333,   334,     0,   335,   336,   337,     0,   316,   338,   339,
     340,   317,     0,     0,     0,     0,     0,     0,   313,     0,
     982,     0,     0,     0,     0,   314,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   315,     0,     0,     0,
       0,   318,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   319,     0,   320,
     321,   322,     0,   323,   324,   325,     0,   326,   327,   328,
     329,   330,     0,     0,   331,   332,   333,   334,     0,   335,
     336,   337,     0,   316,   338,   339,   340,   317,     0,     0,
       0,     0,     0,     0,   313,     0,   983,     0,     0,     0,
       0,   314,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   315,     0,     0,     0,     0,   318,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   319,     0,   320,   321,   322,     0,   323,
     324,   325,     0,   326,   327,   328,   329,   330,     0,     0,
     331,   332,   333,   334,     0,   335,   336,   337,     0,   316,
     338,   339,   340,   317,     0,     0,     0,     0,     0,     0,
     313,     0,   984,     0,     0,     0,     0,   314,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   315,     0,
       0,     0,     0,   318,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   319,
       0,   320,   321,   322,     0,   323,   324,   325,     0,   326,
     327,   328,   329,   330,     0,     0,   331,   332,   333,   334,
       0,   335,   336,   337,     0,   316,   338,   339,   340,   317,
       0,     0,     0,     0,     0,     0,   313,     0,   985,     0,
       0,     0,     0,   314,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   315,     0,     0,     0,     0,   318,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   319,     0,   320,   321,   322,
       0,   323,   324,   325,     0,   326,   327,   328,   329,   330,
       0,     0,   331,   332,   333,   334,     0,   335,   336,   337,
       0,   316,   338,   339,   340,   317,     0,     0,     0,     0,
       0,     0,     0,     0,   986,     0,     0,     0,     0,   313,
       0,     0,     0,     0,     0,     0,   314,     0,     0,     0,
       0,     0,     0,     0,     0,   318,     0,   315,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   319,     0,   320,   321,   322,     0,   323,   324,   325,
    1008,   326,   327,   328,   329,   330,     0,     0,   331,   332,
     333,   334,     0,   335,   336,   337,     0,     0,   338,   339,
     340,     0,     0,     0,   316,     0,     0,     0,   317,     0,
     313,     0,     0,     0,     0,     0,     0,   314,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   315,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   318,     0,
       0,   313,     0,     0,     0,     0,     0,     0,   314,     0,
       0,     0,     0,     0,   319,     0,   320,   321,   322,   315,
     323,   324,   325,     0,   326,   327,   328,   329,   330,     0,
       0,   331,   332,   333,   334,   316,   335,   336,   337,   317,
       0,   338,   339,   340,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   668,     0,     0,   318,
     317,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   319,     0,   320,   321,   322,
       0,   323,   324,   325,     0,   326,   327,   328,   329,   330,
     318,     0,   331,   332,   333,   334,     0,   335,   336,   337,
       0,     0,   338,   339,   340,     0,   319,     0,   320,   321,
     322,   315,   323,   324,   325,     0,   326,   327,   328,   329,
     330,     0,     0,   331,   332,   333,   334,    16,   335,   336,
     337,    20,    21,   338,   339,   340,     0,     0,     0,     0,
      27,     0,    28,   866,     0,     0,     0,    33,     0,     0,
       0,     0,    37,   315,     0,     0,     0,     0,   316,     0,
       0,     0,   317,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,    50,     0,    52,     0,   867,     0,     0,
     868,     0,    57,     0,    58,     0,     0,     0,     0,     0,
       0,     0,   318,     0,     0,     0,     0,     0,     0,     0,
     316,     0,     0,    74,   317,     0,    76,     0,   319,    79,
     320,   321,   322,     0,   323,   324,   325,     0,   326,   327,
     328,   329,     0,     0,     0,   331,   332,   333,   334,     0,
     335,     0,   337,     0,     0,   338,   339,   340,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     319,     0,   320,   321,   322,     0,   323,   324,   325,    92,
     326,   327,   328,   329,     0,   944,     0,   331,   332,   333,
     334,   646,   335,   206,   337,     0,     0,   338,   339,   340,
       0,     0,     0,     0,     0,   207,   208,     0,     0,     0,
       0,     0,   209,     0,     0,   206,     0,     0,     0,     0,
     210,     0,     0,     0,     0,     0,   211,   207,   208,     0,
       0,   212,     0,   213,   209,     0,   214,     0,     0,     0,
       0,     0,   210,   215,     0,     0,     0,     0,   211,     0,
       0,     0,     0,   212,   216,   213,     0,     0,   214,     0,
       0,     0,     0,   217,     0,   215,     0,     0,     0,     0,
       0,     0,   218,   219,     0,   220,   216,   221,     0,   222,
       0,     0,   223,     0,     0,   217,   224,     0,     0,   225,
       0,     0,     0,     0,   218,   219,     0,   220,     0,   221,
       0,   222,     0,     0,   223,     0,     0,     0,   224,     0,
       0,   225
};

static const yytype_int16 yycheck[] =
{
      11,   140,    60,    20,    15,     2,   178,    18,    54,    55,
     362,   441,   560,    24,   128,   655,    28,    28,    29,   191,
      31,    32,    33,    34,   199,   725,   751,   413,   410,     1,
       1,    42,    17,    44,    45,   418,    47,    95,    49,    29,
      51,   593,   800,   801,   186,    29,     1,   915,    59,    60,
      61,    62,    63,    64,    42,    59,   205,    68,   441,    70,
     839,    72,    73,   205,    29,   179,    77,    78,    61,    80,
      81,    31,    32,    84,    78,    29,    87,    88,    89,     1,
      91,   842,   998,    94,    95,    96,     1,    78,   953,    51,
      61,    42,    96,   130,   243,    29,    51,   130,    42,   130,
      42,   243,    78,   105,   804,    42,   130,   151,   130,   102,
       3,    42,    42,   262,   158,   667,   160,   665,   105,  1035,
     262,   296,   297,    78,   161,   904,   159,    42,   159,    51,
     269,   102,    76,   998,     3,   159,    96,   159,   110,     0,
     105,   103,   130,   843,   151,   870,   130,  1015,   103,   160,
     161,   162,   163,   164,   165,   166,    78,   129,   130,   161,
     151,    30,   166,   105,   157,   156,   156,   892,   929,    91,
     722,   105,   156,   161,   129,   186,   193,   935,   936,   130,
     156,   103,   324,   200,    53,     3,   157,   159,   130,   201,
     201,   156,   177,   130,   205,   110,    89,    15,    16,   130,
     130,   156,   156,   903,    22,    19,   592,   129,   560,   358,
     359,     3,    30,   403,   129,   130,   358,   359,    36,   161,
      89,   105,   156,    41,   161,    43,    95,    42,    46,   151,
     161,   161,   243,   244,   156,    53,   151,    76,   110,   879,
     251,   252,   130,   130,   110,    75,    64,     3,   130,    79,
      75,   262,   952,   130,    79,    73,   446,   158,   130,   130,
      74,    76,   134,   151,    82,    83,   103,    85,   134,    87,
     157,    89,    95,   387,    92,   157,   824,   161,    96,    97,
     291,    99,   159,    19,    98,   434,    78,   159,   159,   347,
     348,   288,   434,   130,   158,   353,   160,    89,   356,   357,
      24,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   665,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     716,    24,   714,   130,   130,    47,   347,   348,    74,   158,
     158,    65,   353,  1013,   110,   356,   357,   358,   359,   360,
     361,   362,    76,   158,   151,   151,   316,   317,    70,   130,
     371,  1031,    98,   186,   130,   376,    24,   378,   134,   751,
       7,    95,    65,   151,    28,    86,    24,   101,   389,   157,
     391,   392,   205,    76,   401,   389,   397,   398,   159,   564,
     565,   402,   403,   159,   405,    42,   407,   455,   130,   457,
     360,   361,    95,   130,    51,   158,    42,    65,   550,   420,
     158,   371,   160,   130,   156,    71,   427,    65,    76,   849,
     243,    75,   151,   434,   151,    79,    62,   159,    76,   151,
     151,    78,   392,    51,   445,   446,    72,    73,   398,   262,
     130,   452,   159,   101,   455,   141,   457,    95,   151,   621,
     461,   462,   463,   151,   465,   466,   103,   632,   633,   842,
      78,   151,   473,   110,   151,   130,   849,   110,   130,   473,
      24,   151,   824,    91,   471,   129,   151,   157,   132,   490,
     491,   158,   136,   130,   151,   103,   151,   132,    42,   151,
     548,    45,   135,   875,   137,   138,   455,   156,   457,   142,
     143,   461,   151,   158,   151,   160,   104,    51,    62,   156,
     892,    65,   159,    67,   129,   110,   655,   132,   158,    72,
      73,   136,    76,   534,   535,   536,   537,   538,   539,   540,
     158,   151,   158,   151,    78,   358,   359,   548,   156,   550,
     176,    95,   151,   554,     2,   556,   929,    91,   606,   560,
       7,   562,    55,    11,   129,   156,   541,   542,   151,   103,
     196,   197,   198,   199,   110,    23,    51,    25,   204,    28,
     953,   159,   130,   151,    42,   535,   130,   537,   158,    39,
     959,    31,   159,   594,   110,   968,   597,   598,   599,   600,
     601,   602,   130,    78,   159,   606,   159,   159,   602,    18,
     236,   130,   161,   239,   427,   159,    91,   151,   156,   161,
      68,   434,   156,   130,    74,   998,    75,   151,   103,   151,
      79,   151,   258,  1002,  1003,  1004,  1005,  1006,  1007,   452,
    1013,     3,   455,   151,   457,   151,    94,   159,   161,   462,
      98,   151,   278,    15,   151,   151,    31,   159,  1031,   157,
      22,   151,  1035,   151,   665,    28,   130,   668,   669,   670,
     159,   121,   673,   123,   157,   110,   151,    76,    29,    41,
     129,   156,   131,   132,    46,    29,   156,   136,   689,   161,
     691,    53,    31,   129,    76,   696,   145,   129,   699,   161,
     161,   702,    62,   704,   161,   154,   707,   158,   156,   132,
     132,    73,    75,   157,   132,   132,    79,   132,   668,   669,
     132,   132,   132,    85,   132,   132,   132,    89,   178,    31,
     159,   732,   159,   157,    96,   548,    91,   550,   732,   130,
     161,   191,   302,   744,   194,   746,   372,   446,   749,   445,
     879,    22,   753,   270,   736,   192,   552,   817,   754,   879,
     875,   714,   125,   585,   127,   128,   129,   757,   131,   132,
     396,  1015,   977,   136,   400,   952,  1008,  1001,   226,   229,
      33,   144,   145,   550,    -1,   233,   149,   421,    -1,   152,
     153,   154,    -1,    -1,    -1,   796,    -1,   247,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    42,    -1,   808,   809,    -1,
     811,   812,   813,   814,    51,    -1,    -1,    -1,   819,   820,
      -1,   822,    -1,   824,    -1,   826,   827,    -1,    -1,   830,
      -1,   867,   868,    -1,    -1,    -1,   196,   197,   198,   199,
     288,    78,    -1,    -1,    -1,    -1,    75,   848,   849,    -1,
      79,    -1,    -1,   854,   302,   856,    -1,    -1,    -1,   860,
      -1,    -1,    -1,    -1,    -1,   866,   103,    -1,    -1,    -1,
      -1,    -1,    -1,   110,    -1,    -1,   236,    -1,    -1,   239,
      -1,    -1,   883,   884,   885,   886,   887,   888,   889,   890,
      -1,    -1,    -1,   130,    -1,    -1,   125,    -1,   258,   900,
     129,    -1,   131,   132,   905,    -1,    -1,   136,    -1,   910,
      -1,   905,    -1,   914,   151,    -1,   145,    -1,   278,   156,
      -1,   369,   159,   152,   153,   154,    -1,    -1,    -1,    -1,
      -1,    -1,   558,   559,    24,    -1,   386,    -1,   564,   565,
      -1,    -1,    -1,   391,   945,   946,   947,   948,    -1,   397,
     576,    -1,    42,    -1,    -1,    45,    42,   405,    -1,    -1,
      -1,    -1,    -1,   413,    -1,    51,    -1,   968,    -1,   970,
     971,   972,    62,    -1,    -1,    65,    -1,    67,   972,    -1,
     981,   982,   983,   984,   985,   986,    76,    -1,    -1,    -1,
      -1,   617,    78,     2,    -1,    -1,   997,   998,    -1,  1000,
      -1,    -1,    11,    -1,    -1,    95,    -1,    -1,    -1,    -1,
      -1,   459,   372,    -1,    23,   463,    25,   103,    -1,    -1,
      -1,    -1,   472,   471,   110,   475,    -1,    -1,    -1,   842,
    1031,    -1,    -1,    -1,  1035,    -1,   396,    -1,    -1,    -1,
     400,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   678,   679,    -1,    -1,    -1,     2,    -1,    68,
     686,    -1,   688,    72,    73,   151,    11,    -1,    -1,   695,
     156,    -1,   698,   159,    24,   701,    -1,    -1,    23,    -1,
      25,    -1,    -1,   531,     2,    94,    19,    -1,    -1,    98,
      23,    24,    42,    11,    -1,    45,    -1,   910,    -1,    32,
      -1,    34,    35,    -1,    -1,    23,    39,    25,    -1,    -1,
      -1,    44,    62,   739,    -1,    65,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    -1,    76,   575,    28,    -1,
      63,    -1,    65,    -1,    67,    -1,    69,    -1,   588,    72,
     953,    74,   592,    76,    -1,    95,    -1,   156,    -1,    94,
      68,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    -1,    -1,    98,    -1,   617,   101,    -1,
      -1,   621,    -1,    -1,    -1,    75,    94,    -1,    -1,    79,
      98,    -1,    -1,   631,    -1,   998,    -1,    -1,    -1,   637,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   558,   559,
      -1,    -1,    -1,    -1,   564,   565,    -1,   655,    -1,    -1,
      -1,   156,    -1,    -1,    -1,    -1,    -1,   226,   151,    -1,
     668,   669,  1035,    -1,   233,   125,   852,   127,   128,   129,
      -1,   131,   132,   133,    -1,    -1,   136,    -1,   156,    -1,
      -1,   689,    -1,   691,   144,   145,    -1,    -1,   696,   149,
      -1,   699,   152,   153,   154,    -1,    -1,    -1,   706,    -1,
      -1,   709,    -1,   713,    -1,    -1,   716,    -1,   894,   895,
      -1,    -1,   898,   899,    -1,    -1,    -1,    -1,    -1,   288,
      -1,   226,    -1,   731,    -1,    -1,   736,    19,   233,   915,
      -1,    23,    24,   302,    -1,   921,   744,   923,   746,   925,
      32,    -1,    34,    35,   754,    -1,    -1,    39,   226,    23,
      24,    -1,    44,    -1,    -1,   233,    -1,    -1,   678,   679,
      34,    35,    -1,    -1,   774,    -1,   686,    -1,    -1,    -1,
      44,    63,    28,    65,    -1,    67,    -1,    69,   698,    -1,
      72,   701,    74,   288,    76,    -1,    -1,    -1,    -1,    63,
      -1,    65,    -1,    23,    24,    -1,    -1,   302,    -1,    -1,
     369,    -1,    76,    95,    34,    35,    98,    -1,    -1,   101,
     288,   819,    -1,    -1,    44,    -1,    -1,    47,   826,    75,
      -1,    -1,   391,    79,   302,    -1,    -1,   101,   397,  1015,
     838,    -1,    -1,    63,    -1,    65,   405,    -1,    -1,    -1,
      70,    -1,   850,    -1,    -1,    -1,    76,    -1,    -1,     2,
      -1,   859,    -1,    -1,    -1,   863,    -1,    -1,    11,   151,
      -1,    -1,    -1,    -1,   369,   157,    -1,    -1,    -1,    -1,
      23,   101,    25,   129,    -1,   131,   132,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    -1,    -1,   391,    -1,    -1,   145,
     459,   369,   397,   901,   463,    -1,   152,   153,   154,    -1,
     405,    -1,   471,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   391,    -1,    68,    -1,    -1,    -1,   397,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   405,    -1,    -1,
      -1,    -1,   852,    -1,    -1,    28,    -1,   945,   946,   947,
     948,    94,    -1,    -1,    -1,    98,    -1,    -1,     2,    -1,
      -1,    -1,    -1,    -1,   459,    -1,     1,    11,   463,    -1,
      -1,    -1,   970,   971,    -1,    -1,   471,    -1,    -1,    23,
      -1,    25,    -1,    -1,    19,     2,    -1,    -1,    23,    24,
      -1,   459,    75,    -1,    11,   463,    79,    32,    -1,    34,
      35,    -1,    -1,   471,    39,    -1,    23,    -1,    25,    44,
      -1,    -1,    47,   156,    -1,    -1,   575,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    63,    -1,
      65,    -1,    67,    -1,    69,    70,    -1,    72,    -1,    74,
      -1,    76,   125,    -1,   127,   128,   129,    -1,   131,   132,
      94,    68,    -1,   136,    98,    -1,    -1,    -1,    -1,    -1,
      95,    -1,   145,    98,    -1,    -1,   101,    28,    -1,   152,
     153,   154,   631,    -1,    -1,    -1,    -1,    94,   637,    -1,
     575,    98,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,
     233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   575,    -1,    -1,
      -1,    -1,   156,    -1,    75,    -1,   151,    -1,    79,    -1,
      -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     689,    -1,   691,    -1,    -1,    -1,   631,   696,    -1,   156,
     699,    -1,   637,    -1,    -1,   288,    -1,   706,    -1,    -1,
     709,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   302,
      -1,    -1,    -1,   631,   125,    -1,    -1,   128,   129,   637,
     131,   132,   731,    -1,    -1,   136,    -1,    -1,    -1,    -1,
      -1,    -1,   226,    -1,   145,   744,    -1,   746,    -1,   233,
      -1,   152,   153,   154,   689,    -1,   691,    -1,    -1,    -1,
      -1,   696,    -1,    -1,   699,    -1,    -1,    -1,    -1,   226,
      -1,   706,    -1,    -1,   709,    -1,   233,    -1,    -1,    -1,
      -1,   689,    -1,   691,    -1,    -1,   369,    -1,   696,    -1,
      -1,   699,    -1,    -1,    -1,    -1,   731,    -1,   706,    -1,
      -1,   709,    -1,    -1,   288,    -1,    -1,    -1,   391,   744,
      -1,   746,    -1,    -1,   397,    -1,    -1,    -1,   302,    -1,
     819,    -1,   405,   731,    -1,    -1,    -1,   826,    -1,    -1,
      -1,   288,    -1,    -1,    -1,    -1,   744,    -1,   746,   838,
      -1,    -1,    -1,    -1,    -1,   302,    -1,    -1,    -1,    -1,
      -1,   850,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     859,    -1,    -1,    -1,   863,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   459,    -1,    -1,    -1,
     463,    -1,    -1,    -1,   819,   369,    -1,    -1,   471,    -1,
      -1,   826,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   901,   838,    -1,    -1,    -1,   391,    -1,    -1,
      -1,   819,   369,   397,    -1,   850,    -1,    -1,   826,    -1,
      -1,   405,    -1,    -1,   859,    -1,    -1,    -1,   863,    -1,
     838,    -1,    -1,    -1,   391,     2,    -1,    -1,    -1,    -1,
     397,    -1,   850,    -1,    11,    -1,   945,   946,   947,   948,
      -1,   859,    -1,    -1,    -1,   863,    23,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   901,    -1,    -1,    -1,
      -1,   970,   971,    -1,    -1,   459,    -1,    -1,    -1,   463,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   471,    -1,    -1,
      -1,    -1,   575,   901,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,   459,    -1,    -1,    -1,   463,    -1,    -1,    -1,
     945,   946,   947,   948,   471,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,
      -1,    98,    -1,    -1,     1,   970,   971,   945,   946,   947,
     948,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   631,    -1,
      -1,    -1,    19,    -1,   637,    -1,    23,    24,    -1,    -1,
      -1,    -1,   970,   971,    -1,    32,    -1,    34,    35,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,   575,    -1,    -1,    -1,    -1,    63,    -1,    65,    -1,
      67,    -1,    69,    70,    -1,    72,   689,    74,   691,    76,
      -1,    -1,     2,   696,    -1,    -1,   699,    -1,   575,    -1,
      -1,    11,    -1,   706,    -1,    -1,   709,    -1,    95,    -1,
      -1,    98,    -1,    23,   101,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   631,   731,    -1,
      -1,    -1,    -1,   637,    -1,    -1,    -1,    -1,    -1,   226,
      -1,   744,    -1,   746,    -1,    -1,   233,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   631,    -1,    -1,    -1,    68,    -1,
     637,    -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,
     157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,   689,    -1,   691,    98,    -1,
      -1,    -1,   696,    -1,    -1,   699,    -1,    -1,    -1,    -1,
      -1,   288,   706,    -1,    -1,   709,    -1,    -1,    -1,    -1,
      -1,    -1,   689,    -1,   691,   302,   819,    -1,    -1,   696,
      -1,    -1,   699,   826,    -1,    -1,    -1,   731,    -1,   706,
      -1,    -1,   709,    -1,    -1,   838,    -1,    -1,    -1,    -1,
     744,    -1,   746,    -1,    -1,    -1,   156,   850,    -1,    -1,
      -1,    -1,    -1,    -1,   731,    -1,   859,    -1,    -1,    -1,
     863,    -1,    -1,    -1,    -1,    -1,    -1,   744,    -1,   746,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   369,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   901,    -1,
      -1,    -1,    -1,    -1,   391,    -1,    -1,    -1,    -1,    -1,
     397,    -1,    -1,    -1,    -1,   819,   226,    -1,   405,    -1,
       3,    -1,   826,   233,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,   838,    -1,    -1,    -1,    -1,    22,
      -1,    -1,   945,   946,   947,   948,   850,    30,    -1,    -1,
      -1,    -1,    -1,    36,    -1,   859,    -1,    -1,    41,   863,
      43,   838,    -1,    46,    -1,    -1,    -1,   970,   971,    -1,
      53,    -1,   459,   850,    -1,    -1,   463,    -1,   288,    -1,
      -1,    64,   859,    -1,   471,    -1,   863,    -1,    -1,    -1,
      73,    -1,   302,    -1,    -1,    -1,    -1,   901,    -1,    82,
      83,    -1,    85,    -1,    87,    -1,    89,    -1,    -1,    92,
      -1,    -1,    -1,    96,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   901,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   945,   946,   947,   948,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,    -1,   369,
      -1,    -1,    -1,    -1,    -1,    -1,   970,   971,    -1,    -1,
      -1,   155,    -1,   156,   158,   158,   160,    -1,    -1,    -1,
      -1,   391,    -1,    -1,    -1,    -1,    -1,   397,   575,    -1,
      -1,    -1,    -1,    -1,    -1,   405,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    12,    -1,    -1,    15,    16,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    -1,    40,    41,   631,    43,    -1,    -1,    46,   459,
     637,    49,    50,   463,    -1,    53,    54,    -1,    56,    57,
      -1,   471,    -1,    -1,    -1,    -1,    64,    -1,    66,    -1,
      68,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    83,    84,    85,    86,    87,
      -1,    89,    -1,    -1,    92,    -1,    -1,    -1,    96,    -1,
      -1,    99,   689,    -1,   691,    -1,    -1,    -1,    -1,   696,
      -1,   109,   699,    -1,    -1,    -1,    -1,    -1,    -1,   706,
      -1,    -1,   709,    -1,    -1,    -1,    -1,   125,   126,   127,
     128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   731,    -1,   144,    -1,   146,    -1,
     148,   149,   150,    -1,     3,    -1,   154,   744,   156,   746,
     158,    -1,   160,   161,    -1,   575,    15,    16,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,
      -1,    -1,    41,    -1,    43,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,
      -1,   631,    -1,    -1,    73,    -1,    -1,   637,    -1,    -1,
      -1,    -1,   819,    82,    83,    -1,    85,    -1,    87,   826,
      89,    -1,    -1,    92,    -1,    -1,    -1,    96,    -1,    -1,
      99,   838,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   850,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   859,    -1,    -1,    -1,   863,    -1,    -1,   689,
      -1,   691,    -1,    -1,    -1,    -1,   696,    -1,    -1,   699,
      -1,    -1,     3,    -1,    -1,    -1,   706,    -1,    -1,   709,
      -1,    -1,    -1,    -1,    15,    16,    -1,    -1,    -1,   158,
      -1,    22,    -1,    -1,   901,    -1,    -1,    -1,    -1,    30,
      -1,   731,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      41,    -1,    43,    -1,   744,    46,   746,    10,    -1,    -1,
      -1,    -1,    53,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    -1,    28,    -1,    -1,   945,   946,
     947,   948,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    83,    -1,    85,    -1,    87,    -1,    89,    10,
      -1,    92,    -1,   970,   971,    96,    17,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    -1,    75,    -1,    -1,    -1,    79,    -1,    -1,   819,
      -1,    -1,    -1,    -1,    -1,    -1,   826,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   838,    -1,
      -1,    -1,   105,    -1,    -1,    -1,   109,    -1,    -1,    -1,
     850,    -1,    -1,    -1,    75,    -1,    -1,   158,    79,   859,
      -1,    -1,   125,   863,   127,   128,   129,    -1,   131,   132,
     133,    -1,   135,   136,   137,   138,   139,    -1,    -1,   142,
     143,   144,   145,    -1,   147,   148,   149,    -1,   109,   152,
     153,   154,    -1,    -1,    -1,    -1,    -1,    -1,   161,    -1,
      -1,   901,    -1,    -1,   125,    -1,   127,   128,   129,    -1,
     131,   132,   133,    -1,   135,   136,   137,   138,   139,    -1,
      -1,   142,   143,   144,   145,    -1,   147,   148,   149,    -1,
      -1,   152,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,
     161,    -1,    -1,    -1,    -1,   945,   946,   947,   948,    -1,
      -1,    -1,    -1,     0,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    13,    14,    15,    16,
     970,   971,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    30,    -1,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    43,    44,    -1,    46,
      47,    48,    49,    50,    -1,    52,    53,    54,    55,    56,
      57,    -1,    59,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    -1,    76,
      77,    78,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    -1,    89,    90,    -1,    92,    93,    94,    95,    96,
      -1,    98,    99,   100,   101,    -1,    -1,   104,    -1,   106,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,   146,
      -1,   148,   149,    -1,   151,    -1,    -1,   154,    -1,   156,
      -1,   158,     1,   160,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    12,    13,    14,    15,    16,    17,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    43,    44,    -1,    46,    47,    48,
      49,    50,    -1,    52,    53,    54,    55,    56,    57,    -1,
      59,    -1,    -1,    -1,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    -1,
      89,    90,    -1,    92,    93,    94,    95,    96,    -1,    98,
      99,   100,   101,    -1,    -1,   104,    -1,   106,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,   135,   136,   137,   138,
     139,    -1,    -1,   142,   143,   144,   145,   146,   147,   148,
     149,    -1,   151,   152,   153,   154,    -1,   156,   157,   158,
       1,   160,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    13,    14,    15,    16,    -1,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    30,
      -1,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    44,    -1,    46,    47,    48,    49,    50,
      -1,    52,    53,    54,    55,    56,    57,    -1,    59,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    76,    77,    78,    -1,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    89,    90,
      -1,    92,    93,    94,    95,    96,    -1,    98,    99,   100,
     101,    -1,    -1,   104,    -1,   106,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,    -1,   146,    -1,   148,   149,   150,
     151,    -1,    -1,   154,    -1,   156,   157,   158,     1,   160,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      13,    14,    15,    16,    -1,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    30,    -1,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      43,    44,    -1,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    55,    56,    57,    -1,    59,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    76,    77,    78,    -1,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,    89,    90,    -1,    92,
      93,    94,    95,    96,    -1,    98,    99,   100,   101,    -1,
      -1,   104,    -1,   106,    -1,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,    -1,   146,    -1,   148,   149,    -1,   151,    -1,
      -1,   154,    -1,   156,   157,   158,     1,   160,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    -1,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    30,    -1,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    43,    44,
      -1,    46,    47,    48,    49,    50,    -1,    52,    53,    54,
      55,    56,    57,    -1,    59,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    76,    77,    78,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    -1,    89,    90,    -1,    92,    93,    94,
      95,    96,    -1,    98,    99,   100,   101,    -1,    -1,   104,
      -1,   106,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,
      -1,   146,    -1,   148,   149,    -1,   151,    -1,    -1,   154,
      -1,   156,   157,   158,     1,   160,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    13,    14,    15,    16,
      -1,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    30,    -1,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    43,    44,    -1,    46,
      47,    48,    49,    50,    -1,    52,    53,    54,    55,    56,
      57,    -1,    59,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    -1,    76,
      77,    78,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    -1,    89,    90,    -1,    92,    93,    94,    95,    96,
      -1,    98,    99,   100,   101,    -1,    -1,   104,    -1,   106,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,   146,
      -1,   148,   149,    -1,   151,    -1,    -1,   154,    -1,   156,
     157,   158,     1,   160,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    13,    14,    15,    16,    -1,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      29,    30,    -1,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    43,    44,    -1,    46,    47,    48,
      49,    50,    -1,    52,    53,    54,    55,    56,    57,    -1,
      59,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    76,    77,    78,
      -1,    80,    81,    82,    83,    84,    85,    86,    87,    -1,
      89,    90,    -1,    92,    93,    94,    95,    96,    -1,    98,
      99,   100,   101,    -1,    -1,   104,    -1,   106,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   144,    -1,   146,    -1,   148,
     149,    -1,   151,    -1,    -1,   154,    -1,   156,   157,   158,
       1,   160,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    13,    14,    15,    16,    -1,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    30,
      -1,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    44,    -1,    46,    47,    48,    49,    50,
      -1,    52,    53,    54,    55,    56,    57,    -1,    59,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    76,    77,    78,    -1,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    89,    90,
      -1,    92,    93,    94,    95,    96,    -1,    98,    99,   100,
     101,    -1,    -1,   104,    -1,   106,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,    -1,   146,    -1,   148,   149,    -1,
     151,    -1,    -1,   154,    -1,   156,    -1,   158,     1,   160,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      13,    14,    15,    16,    -1,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    30,    -1,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      43,    44,    -1,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    55,    56,    57,    -1,    59,    -1,    -1,    -1,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    -1,    76,    77,    78,    -1,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,    89,    90,    -1,    92,
      93,    94,    95,    96,    -1,    98,    99,   100,   101,    -1,
      -1,   104,    -1,   106,    -1,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,    -1,   146,    -1,   148,   149,    -1,   151,    -1,
      -1,   154,    -1,   156,    -1,   158,     1,   160,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    -1,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    30,    -1,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    43,    44,
      -1,    46,    47,    48,    49,    50,    -1,    52,    53,    54,
      55,    56,    57,    -1,    59,    -1,    -1,    -1,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      -1,    76,    77,    78,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    -1,    89,    90,    -1,    92,    93,    94,
      95,    96,    -1,    98,    99,   100,   101,    -1,    -1,   104,
      -1,   106,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,
      -1,   146,    -1,   148,   149,    -1,   151,    -1,    -1,   154,
      -1,   156,    -1,   158,     1,   160,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    13,    14,    15,    16,
      -1,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    30,    -1,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    43,    44,    -1,    46,
      47,    48,    49,    50,    -1,    52,    53,    54,    55,    56,
      57,    -1,    59,    -1,    -1,    -1,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    -1,    76,
      77,    78,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    -1,    89,    90,    -1,    92,    93,    94,    95,    96,
      -1,    98,    99,   100,   101,    -1,    -1,   104,    -1,   106,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,   146,
      -1,   148,   149,    -1,   151,    -1,    -1,   154,    -1,   156,
      -1,   158,     1,   160,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    13,    14,    15,    16,    -1,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      29,    30,    -1,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    43,    44,    -1,    46,    47,    48,
      49,    50,    -1,    52,    53,    54,    55,    56,    57,    -1,
      59,    -1,    -1,    -1,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    -1,    76,    77,    78,
      -1,    80,    81,    82,    83,    84,    85,    86,    87,    -1,
      89,    90,    -1,    92,    93,    94,    95,    96,    -1,    98,
      99,   100,   101,    -1,    -1,   104,    -1,   106,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   144,    -1,   146,    -1,   148,
     149,    -1,   151,    -1,    -1,   154,    -1,   156,    -1,   158,
       1,   160,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    13,    14,    15,    16,    -1,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    30,
      -1,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    44,    -1,    46,    47,    48,    49,    50,
      -1,    52,    53,    54,    55,    56,    57,    -1,    59,    -1,
      -1,    -1,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    -1,    76,    77,    78,    -1,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    89,    90,
      -1,    92,    93,    94,    95,    96,    -1,    98,    99,   100,
     101,    -1,    -1,   104,    -1,   106,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,    -1,   146,    -1,   148,   149,    -1,
     151,    -1,    -1,   154,    -1,   156,    -1,   158,     1,   160,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      13,    14,    15,    16,    -1,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    30,    -1,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      43,    44,    -1,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    55,    56,    57,    -1,    59,    -1,    -1,    -1,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    -1,    76,    77,    78,    -1,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,    89,    90,    -1,    92,
      93,    94,    95,    96,    -1,    98,    99,   100,   101,    -1,
      -1,   104,    -1,   106,    -1,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,    -1,   146,    -1,   148,   149,    -1,   151,    -1,
      -1,   154,    -1,   156,    -1,   158,     1,   160,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    -1,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    30,    -1,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    43,    44,
      -1,    46,    47,    48,    49,    50,    -1,    52,    53,    54,
      55,    56,    57,    -1,    59,    -1,    -1,    -1,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      -1,    76,    77,    78,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    -1,    89,    90,    -1,    92,    93,    94,
      95,    96,    -1,    98,    99,   100,   101,    -1,    -1,   104,
      -1,   106,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,
      -1,   146,    -1,   148,   149,    -1,   151,    -1,    -1,   154,
      -1,   156,    -1,   158,     1,   160,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    13,    14,    15,    16,
      -1,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    30,    -1,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    43,    44,    -1,    46,
      47,    48,    49,    50,    -1,    52,    53,    54,    55,    56,
      57,    -1,    59,    -1,    -1,    -1,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    -1,    76,
      77,    78,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    -1,    89,    90,    -1,    92,    93,    94,    95,    96,
      -1,    98,    99,   100,   101,    -1,    -1,   104,    -1,   106,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,   146,
      -1,   148,   149,    -1,   151,    -1,    -1,   154,    -1,   156,
      -1,   158,     1,   160,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    13,    14,    15,    16,    -1,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      29,    30,    -1,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    43,    44,    -1,    46,    47,    48,
      49,    50,    -1,    52,    53,    54,    55,    56,    57,    -1,
      59,    -1,    -1,    -1,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    -1,    76,    77,    78,
      -1,    80,    81,    82,    83,    84,    85,    86,    87,    -1,
      89,    90,    -1,    92,    93,    94,    95,    96,    -1,    98,
      99,   100,   101,    -1,    -1,   104,    -1,   106,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   144,    -1,   146,    -1,   148,
     149,    -1,   151,    -1,    -1,   154,    -1,   156,    -1,   158,
       1,   160,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    13,    14,    15,    16,    -1,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    30,
      -1,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    44,    -1,    46,    47,    48,    49,    50,
      -1,    52,    53,    54,    55,    56,    57,    -1,    59,    -1,
      -1,    -1,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    -1,    76,    77,    78,    -1,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    89,    90,
      -1,    92,    93,    94,    95,    96,    -1,    98,    99,   100,
     101,    -1,    -1,   104,    -1,   106,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,    -1,   146,    -1,   148,   149,    -1,
     151,    -1,    -1,   154,    -1,   156,    -1,   158,     1,   160,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,    -1,
      43,    -1,    -1,    46,    -1,    -1,    49,    50,    -1,    -1,
      53,    54,    -1,    56,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    -1,    66,    -1,    68,    -1,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      83,    84,    85,    86,    87,    -1,    89,    -1,    -1,    92,
      -1,    -1,    -1,    96,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,    -1,   146,    -1,   148,   149,   150,    -1,    -1,
      -1,   154,    -1,   156,    -1,   158,    -1,   160,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,
      15,    16,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    -1,    40,    41,    -1,    43,    -1,
      -1,    46,    -1,    -1,    49,    50,    -1,    -1,    53,    54,
      -1,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      -1,    66,    -1,    68,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,
      85,    86,    87,    -1,    89,    -1,    -1,    92,    -1,    -1,
      -1,    96,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,
      -1,   146,    -1,   148,   149,   150,    -1,    -1,    -1,   154,
      -1,   156,    -1,   158,    -1,   160,   161,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,    15,
      16,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,
      46,    -1,    -1,    49,    50,    -1,    -1,    53,    54,    -1,
      56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,
      66,    -1,    68,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,    85,
      86,    87,    -1,    89,    -1,    -1,    92,    -1,    -1,    -1,
      96,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,
     146,    -1,   148,   149,   150,    -1,    -1,    -1,   154,    -1,
     156,    -1,   158,    -1,   160,   161,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    -1,    -1,    15,    16,
      -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,    46,
      -1,    -1,    49,    50,    -1,    -1,    53,    54,    -1,    56,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    66,
      -1,    68,    -1,    -1,    -1,    28,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    83,    84,    85,    86,
      87,    -1,    89,    -1,    -1,    92,    -1,    -1,    -1,    96,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    -1,    -1,     1,    79,     3,   125,   126,
     127,   128,    -1,    -1,    10,    -1,   133,    -1,    -1,    15,
      16,    17,    -1,    -1,    -1,    -1,    22,   144,    -1,   146,
      -1,   148,   149,    -1,    30,    -1,   109,   154,    -1,   156,
      36,   158,    -1,   160,   161,    41,    -1,    43,    -1,    -1,
      46,    -1,   125,    -1,   127,   128,   129,    53,   131,   132,
     133,    -1,   135,   136,   137,   138,    -1,    -1,    64,   142,
     143,   144,   145,    -1,   147,   148,   149,    73,    -1,   152,
     153,   154,    -1,    -1,    -1,    -1,    82,    83,    -1,    85,
      -1,    87,    -1,    89,    -1,    -1,    92,    -1,    -1,    -1,
      96,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
      -1,    -1,   118,   119,   120,   121,    -1,   123,   124,   125,
     126,   127,   128,    -1,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    -1,   149,    -1,    -1,   152,   153,   154,   155,
      -1,    -1,   158,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    12,    -1,    -1,    15,    16,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    35,    36,    37,    38,    -1,
      40,    41,    -1,    43,    -1,    -1,    46,    -1,    -1,    49,
      50,    -1,    -1,    53,    54,    -1,    56,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    -1,    68,    -1,
      -1,    -1,    -1,    73,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    82,    83,    84,    85,    86,    87,    -1,    89,
      -1,    -1,    92,    -1,    -1,    -1,    96,    -1,    -1,    99,
      -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,
      -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   144,    -1,   146,    -1,   148,   149,
      -1,    -1,    -1,    -1,   154,    -1,   156,    -1,   158,    -1,
     160,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    -1,    -1,    15,    16,    -1,    -1,    19,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,
      -1,    43,    -1,    -1,    46,    -1,    -1,    49,    50,    -1,
      -1,    53,    54,    -1,    56,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    -1,    66,    -1,    68,    -1,    -1,    -1,
      -1,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      82,    83,    84,    85,    86,    87,    -1,    89,    -1,    -1,
      92,    -1,    -1,    95,    96,    -1,    98,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   125,   126,   127,   128,    -1,    -1,    -1,
      -1,   133,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,   144,    -1,   146,    12,   148,   149,    15,    16,
      -1,    -1,   154,    -1,   156,    22,   158,    -1,   160,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,    46,
      -1,    -1,    49,    50,    -1,    -1,    53,    54,    -1,    56,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    66,
      -1,    68,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    83,    84,    85,    86,
      87,    -1,    89,    -1,    -1,    92,    93,    94,    -1,    96,
      97,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,   134,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,   146,
      -1,   148,   149,   150,    -1,    -1,    -1,   154,    -1,   156,
      -1,   158,    -1,   160,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    -1,    -1,    15,    16,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      -1,    40,    41,    -1,    43,    -1,    -1,    46,    -1,    -1,
      49,    50,    -1,    -1,    53,    54,    -1,    56,    57,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    -1,    66,    -1,    68,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    83,    84,    85,    86,    87,    -1,
      89,    -1,    -1,    92,    93,    94,    -1,    96,    97,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   144,    -1,   146,    -1,   148,
     149,   150,    -1,    -1,    -1,   154,    -1,   156,    -1,   158,
     159,   160,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,
      41,    -1,    43,    -1,    -1,    46,    -1,    -1,    49,    50,
      -1,    -1,    53,    54,    -1,    56,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    -1,    66,    -1,    68,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84,    85,    86,    87,    -1,    89,    -1,
      -1,    92,    93,    94,    -1,    96,    97,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,    -1,   146,    -1,   148,   149,   150,
      -1,    -1,    -1,   154,    -1,   156,    -1,   158,   159,   160,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,    42,
      43,    -1,    -1,    46,    -1,    -1,    49,    50,    -1,    -1,
      53,    54,    -1,    56,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    -1,    66,    -1,    68,    -1,    -1,    -1,    -1,
      73,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    82,
      83,    84,    85,    86,    87,    -1,    89,    -1,    -1,    92,
      -1,    -1,    -1,    96,    -1,    -1,    99,    -1,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,    -1,   146,    -1,   148,   149,    -1,    -1,    -1,
      -1,   154,    -1,   156,    -1,   158,    -1,   160,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,
      15,    16,    -1,    -1,    19,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    -1,    40,    41,    -1,    43,    -1,
      -1,    46,    -1,    -1,    49,    50,    -1,    -1,    53,    54,
      -1,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      -1,    66,    -1,    68,    -1,    -1,    -1,    -1,    73,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,
      85,    86,    87,    -1,    89,    -1,    -1,    92,    -1,    -1,
      95,    96,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,   144,
      -1,   146,    12,   148,   149,    15,    16,    -1,    -1,   154,
      -1,   156,    22,   158,    -1,   160,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,
      40,    41,    -1,    43,    -1,    -1,    46,    -1,    -1,    49,
      50,    -1,    -1,    53,    54,    -1,    56,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    -1,    66,    -1,    68,    -1,
      -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    83,    84,    85,    86,    87,    -1,    89,
      -1,    -1,    92,    93,    94,    -1,    96,    -1,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,
      -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   144,    -1,   146,    -1,   148,   149,
      -1,   151,    -1,    -1,   154,    -1,   156,    -1,   158,    -1,
     160,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      12,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,
      -1,    43,    -1,    -1,    46,    -1,    -1,    49,    50,    -1,
      -1,    53,    54,    -1,    56,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    -1,    66,    -1,    68,    -1,    -1,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      82,    83,    84,    85,    86,    87,    -1,    89,    -1,    -1,
      92,    93,    94,    -1,    96,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   125,   126,   127,   128,    -1,    -1,    -1,
      -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   144,    -1,   146,    -1,   148,   149,   150,    -1,
      -1,    -1,   154,    -1,   156,    -1,   158,    -1,   160,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    -1,    40,    41,    -1,    43,
      -1,    -1,    46,    -1,    -1,    49,    50,    -1,    -1,    53,
      54,    -1,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,
      64,    -1,    66,    -1,    68,    -1,    -1,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,
      84,    85,    86,    87,    -1,    89,    -1,    -1,    92,    93,
      94,    -1,    96,    -1,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
     144,    -1,   146,    12,   148,   149,    15,    16,    -1,    -1,
     154,    -1,   156,    22,   158,    -1,   160,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      -1,    40,    41,    -1,    43,    -1,    -1,    46,    -1,    -1,
      49,    50,    -1,    -1,    53,    54,    -1,    56,    57,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,    68,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    83,    84,    85,    86,    87,    -1,
      89,    -1,    -1,    92,    -1,    -1,    -1,    96,    -1,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,   144,    -1,   146,    12,   148,
     149,    15,    16,    -1,    -1,   154,    -1,   156,    22,   158,
      -1,   160,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    -1,    40,    41,    -1,    43,
      -1,    -1,    46,    -1,    -1,    49,    50,    -1,    -1,    53,
      54,    -1,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    -1,    66,    -1,    68,    -1,    -1,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,
      84,    85,    86,    87,    -1,    89,    -1,    -1,    92,    -1,
      -1,    -1,    96,    -1,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,    -1,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,    -1,   146,    -1,   148,   149,   150,    -1,    -1,    -1,
     154,    -1,   156,    -1,   158,    -1,   160,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,    15,
      16,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,
      46,    -1,    -1,    49,    50,    -1,    -1,    53,    54,    -1,
      56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,
      66,    -1,    68,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,    85,
      86,    87,    -1,    89,    -1,    -1,    92,    93,    94,    -1,
      96,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,   144,    -1,
     146,    12,   148,   149,    15,    16,    -1,    -1,   154,    -1,
     156,    22,   158,    -1,   160,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,
      41,    -1,    43,    -1,    -1,    46,    -1,    -1,    49,    50,
      -1,    -1,    53,    54,    -1,    56,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    -1,    66,    -1,    68,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84,    85,    86,    87,    -1,    89,    -1,
      -1,    92,    -1,    -1,    -1,    96,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,    -1,   146,    -1,   148,   149,   150,
      -1,    -1,    -1,   154,    -1,   156,   157,   158,    -1,   160,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,    -1,
      43,    -1,    -1,    46,    -1,    -1,    49,    50,    -1,    -1,
      53,    54,    -1,    56,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    -1,    66,    -1,    68,    -1,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      83,    84,    85,    86,    87,    -1,    89,    -1,    -1,    92,
      -1,    -1,    -1,    96,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,   144,    -1,   146,    12,   148,   149,    15,    16,    -1,
      -1,   154,    -1,   156,    22,   158,    -1,   160,    -1,    -1,
      -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    -1,    40,    41,    -1,    43,    -1,    -1,    46,    -1,
      -1,    49,    50,    -1,    -1,    53,    54,    -1,    56,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    66,    -1,
      68,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    83,    84,    85,    86,    87,
      -1,    89,    -1,    -1,    92,    -1,    -1,    -1,    96,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,
     128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,   144,    -1,   146,    12,
     148,   149,    15,    16,    -1,    -1,   154,    -1,   156,    22,
     158,    -1,   160,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,    -1,
      43,    -1,    -1,    46,    -1,    -1,    49,    50,    -1,    -1,
      53,    54,    -1,    56,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    -1,    66,    -1,    68,    -1,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      83,    84,    85,    86,    87,    -1,    89,    -1,    -1,    92,
      -1,    -1,    -1,    96,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,    -1,   146,    -1,   148,   149,   150,    -1,    -1,
      -1,   154,    -1,   156,    -1,   158,    -1,   160,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,
      15,    16,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    -1,    40,    41,    -1,    43,    -1,
      -1,    46,    -1,    -1,    49,    50,    -1,    -1,    53,    54,
      -1,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      -1,    66,    -1,    68,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,
      85,    86,    87,    -1,    89,    -1,    -1,    92,    -1,    -1,
      -1,    96,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,
      -1,   146,    -1,   148,   149,   150,    -1,    -1,    -1,   154,
      -1,   156,    -1,   158,    -1,   160,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    -1,    -1,    15,    16,
      -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,    46,
      -1,    -1,    49,    50,    -1,    -1,    53,    54,    -1,    56,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    66,
      -1,    68,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    83,    84,    85,    86,
      87,    -1,    89,    -1,    -1,    92,    -1,    -1,    -1,    96,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,   146,
      -1,   148,   149,   150,    -1,    -1,    -1,   154,    -1,   156,
      -1,   158,    -1,   160,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    -1,    -1,    15,    16,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      -1,    40,    41,    -1,    43,    -1,    -1,    46,    -1,    -1,
      49,    50,    -1,    -1,    53,    54,    -1,    56,    57,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    -1,    66,    -1,    68,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    83,    84,    85,    86,    87,    -1,
      89,    -1,    -1,    92,    -1,    -1,    -1,    96,    -1,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   144,    -1,   146,    -1,   148,
     149,   150,    -1,    -1,    -1,   154,    -1,   156,    -1,   158,
      -1,   160,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,
      41,    -1,    43,    -1,    -1,    46,    -1,    -1,    49,    50,
      -1,    -1,    53,    54,    -1,    56,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    -1,    66,    -1,    68,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84,    85,    86,    87,    -1,    89,    -1,
      -1,    92,    -1,    -1,    -1,    96,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,   144,    -1,   146,    12,   148,   149,    15,
      16,    -1,    -1,   154,    -1,   156,    22,   158,    -1,   160,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,
      46,    -1,    -1,    49,    50,    -1,    -1,    53,    54,    -1,
      56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,
      66,    -1,    68,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,    85,
      86,    87,    -1,    89,    -1,    -1,    92,    -1,    -1,    -1,
      96,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,   144,    -1,
     146,    12,   148,   149,    15,    16,    -1,    -1,   154,    -1,
     156,    22,   158,    -1,   160,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,
      41,    -1,    43,    -1,    -1,    46,    -1,    -1,    49,    50,
      -1,    -1,    53,    54,    -1,    56,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    -1,    66,    -1,    68,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84,    85,    86,    87,    -1,    89,    -1,
      -1,    92,    -1,    -1,    -1,    96,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,   144,    -1,   146,    12,   148,   149,    15,
      16,    -1,    -1,   154,    -1,   156,    22,   158,    -1,   160,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,
      46,    -1,    -1,    49,    50,    -1,    -1,    53,    54,    -1,
      56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,
      66,    -1,    68,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,    85,
      86,    87,    -1,    89,    -1,    -1,    92,    -1,    -1,    -1,
      96,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,   144,    -1,
     146,    12,   148,   149,    15,    16,    -1,    -1,   154,    -1,
     156,    22,   158,    -1,   160,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,
      41,    -1,    43,    -1,    -1,    46,    -1,    -1,    49,    50,
      -1,    -1,    53,    54,    -1,    56,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    -1,    66,    -1,    68,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84,    85,    86,    87,    -1,    89,    -1,
      -1,    92,    -1,    -1,    -1,    96,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,   144,    -1,   146,    12,   148,   149,    15,
      16,    -1,    -1,   154,    -1,   156,    22,   158,    -1,   160,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,
      46,    -1,    -1,    49,    50,    -1,    -1,    53,    54,    -1,
      56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,
      66,    -1,    68,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,    85,
      86,    87,    -1,    89,    -1,    -1,    92,    -1,    -1,    -1,
      96,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,   144,    -1,
     146,    12,   148,   149,    15,    16,    -1,    -1,   154,    -1,
     156,    22,   158,    -1,   160,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,
      41,    -1,    43,    -1,    -1,    46,    -1,    -1,    49,    50,
      -1,    -1,    53,    54,    -1,    56,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    -1,    66,    -1,    68,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84,    85,    86,    87,    -1,    89,    -1,
      -1,    92,    -1,    -1,    -1,    96,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,   144,    -1,   146,    12,   148,   149,    15,
      16,    -1,    -1,   154,    -1,   156,    22,   158,    -1,   160,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,
      46,    -1,    -1,    49,    50,    -1,    -1,    53,    54,    -1,
      56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,
      66,    -1,    68,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,    85,
      86,    87,    -1,    89,    -1,    -1,    92,    -1,    -1,    -1,
      96,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,   144,    -1,
     146,    12,   148,   149,    15,    16,    -1,    -1,   154,    -1,
     156,    22,   158,    -1,   160,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,
      41,    -1,    43,    -1,    -1,    46,    -1,    -1,    49,    50,
      -1,    -1,    53,    54,    -1,    56,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    -1,    66,    -1,    68,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84,    85,    86,    87,    -1,    89,    -1,
      -1,    92,    -1,    -1,    -1,    96,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,   144,    -1,   146,    12,   148,   149,    15,
      16,    -1,    -1,   154,    -1,   156,    22,   158,    -1,   160,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,
      46,    -1,    -1,    49,    50,    -1,    -1,    53,    54,    -1,
      56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,
      66,    -1,    68,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,    85,
      86,    87,    -1,    89,    -1,    -1,    92,    -1,    -1,    -1,
      96,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,   144,    -1,
     146,    12,   148,   149,    15,    16,    -1,    -1,   154,    -1,
     156,    22,   158,    -1,   160,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,
      41,    -1,    43,    -1,    -1,    46,    -1,    -1,    49,    50,
      -1,    -1,    53,    54,    -1,    56,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    -1,    66,    -1,    68,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84,    85,    86,    87,    -1,    89,    -1,
      -1,    92,    -1,    -1,    -1,    96,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,   144,    -1,   146,    12,   148,   149,    15,
      16,    -1,    -1,   154,    -1,   156,    22,   158,    -1,   160,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,
      46,    -1,    -1,    49,    50,    -1,    -1,    53,    54,    -1,
      56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,
      66,    -1,    68,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,    85,
      86,    87,    -1,    89,    -1,    -1,    92,    -1,    -1,    -1,
      96,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,   144,    -1,
     146,    12,   148,   149,    15,    16,    -1,    -1,   154,    -1,
     156,    22,   158,    -1,   160,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,
      41,    -1,    43,    -1,    -1,    46,    -1,    -1,    49,    50,
      -1,    -1,    53,    54,    -1,    56,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    -1,    66,    -1,    68,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84,    85,    86,    87,    -1,    89,    -1,
      -1,    92,    -1,    -1,    -1,    96,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,   144,    -1,   146,    12,   148,   149,    15,
      16,    -1,    -1,   154,    -1,   156,    22,   158,    -1,   160,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,
      46,    -1,    -1,    49,    50,    -1,    -1,    53,    54,    -1,
      56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,
      66,    -1,    68,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,    85,
      86,    87,    -1,    89,    -1,    -1,    92,    -1,    -1,    -1,
      96,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,   144,    -1,
     146,    12,   148,   149,    15,    16,    -1,    -1,   154,    -1,
     156,    22,   158,    -1,   160,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,
      41,    -1,    43,    -1,    -1,    46,    -1,    -1,    49,    50,
      -1,    -1,    53,    54,    -1,    56,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    -1,    66,    -1,    68,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84,    85,    86,    87,    -1,    89,    -1,
      -1,    92,    -1,    -1,    -1,    96,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,   144,    -1,   146,    12,   148,   149,    15,
      16,    -1,    -1,   154,    -1,   156,    22,   158,    -1,   160,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,
      46,    -1,    -1,    49,    50,    -1,    -1,    53,    54,    -1,
      56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,
      66,    -1,    68,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,    85,
      86,    87,    -1,    89,    -1,    -1,    92,    -1,    -1,    -1,
      96,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,   144,    -1,
     146,    12,   148,   149,    15,    16,    -1,    -1,   154,    -1,
      -1,    22,   158,    -1,   160,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,
      41,    -1,    43,    -1,    -1,    46,    -1,    -1,    49,    50,
      -1,    -1,    53,    54,    -1,    56,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    -1,    66,    -1,    68,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84,    85,    86,    87,    -1,    89,    -1,
      -1,    92,    -1,    -1,    -1,    96,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,   144,    -1,   146,    12,    -1,   149,    15,
      16,    -1,    -1,   154,    -1,   156,    22,   158,    -1,   160,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,
      46,    -1,    -1,    49,    50,    -1,    -1,    53,    54,    -1,
      56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,
      66,    -1,    68,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,    85,
      86,    87,    -1,    89,    -1,    -1,    92,    -1,    -1,    -1,
      96,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,    -1,    -1,    -1,   130,    -1,    -1,    -1,   134,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,
     146,    15,    16,    -1,   150,    -1,    -1,    -1,    22,    -1,
     156,    -1,   158,   159,   160,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    -1,    40,    41,    -1,    43,
      -1,    -1,    46,    -1,    -1,    49,    50,    51,    -1,    53,
      54,    -1,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    -1,    66,    -1,    68,    -1,    -1,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    82,    83,
      84,    85,    86,    87,    -1,    89,    -1,    91,    92,    -1,
      -1,    -1,    96,    -1,    -1,    99,    -1,    -1,    -1,   103,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,    -1,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    -1,    -1,    15,    16,    -1,    -1,
      -1,    -1,   146,    22,    -1,   155,    -1,   151,   158,    -1,
     160,    30,   156,    -1,   158,    -1,   160,    36,    37,    38,
      -1,    40,    41,    -1,    43,    -1,    -1,    46,    -1,    -1,
      49,    50,    -1,    -1,    53,    54,    -1,    56,    57,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    -1,    66,    -1,    68,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    83,    84,    85,    86,    87,    -1,
      89,    -1,    -1,    92,    -1,    -1,    -1,    96,    -1,    -1,
      99,    -1,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,   126,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,
      41,    -1,    43,    -1,    -1,    46,    -1,   146,    49,    50,
      -1,    -1,    53,    54,    -1,    56,    57,   156,    -1,   158,
      -1,   160,    -1,    64,    -1,    66,    -1,    68,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84,    85,    86,    87,    -1,    89,    -1,
      -1,    92,    -1,    -1,    -1,    96,    -1,    -1,    99,    -1,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,   126,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,    -1,
      43,    -1,    -1,    46,    -1,   146,    49,    50,    -1,    -1,
      53,    54,    -1,    56,    57,   156,    -1,   158,    -1,   160,
      -1,    64,    -1,    66,    -1,    68,    -1,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      83,    84,    85,    86,    87,    -1,    89,    -1,     3,    92,
      -1,    -1,    -1,    96,    -1,    10,    99,    -1,    -1,    -1,
      15,    16,    17,    -1,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    36,    -1,   126,    -1,    -1,    41,    -1,    43,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,   146,    -1,    -1,    -1,    -1,    -1,    64,
      -1,    -1,    -1,    -1,    -1,   158,    -1,   160,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    -1,
      85,    -1,    87,    -1,    89,    -1,    10,    92,    -1,    -1,
      -1,    96,    -1,    17,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,   110,   111,   112,   113,   114,
     115,    -1,    -1,   118,   119,   120,   121,    -1,   123,   124,
     125,   126,   127,   128,    -1,    -1,   131,    -1,    -1,    -1,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,    -1,   149,    -1,    -1,   152,   153,   154,
     155,    75,    -1,    -1,    -1,    79,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      -1,   125,    -1,   127,   128,   129,    28,   131,   132,   133,
      -1,   135,   136,   137,   138,   139,    -1,    -1,   142,   143,
     144,   145,    75,   147,   148,   149,    79,    -1,   152,   153,
     154,    -1,    -1,    -1,    -1,    -1,    -1,   161,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    -1,    -1,   109,    79,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,    28,   131,   132,
     133,    -1,   135,   136,   137,   138,   139,   109,    -1,   142,
     143,   144,   145,    75,   147,   148,   149,    79,    -1,   152,
     153,   154,    -1,   125,    -1,   127,   128,   129,   161,   131,
     132,   133,    -1,   135,   136,   137,   138,   139,    -1,    -1,
     142,   143,   144,   145,    75,   147,   148,   149,    79,    -1,
     152,   153,   154,    -1,    -1,    10,    -1,   159,    -1,    -1,
      -1,    -1,    17,   125,    -1,   127,   128,   129,    -1,   131,
     132,   133,    -1,    28,   136,   137,   138,    -1,   109,    -1,
     142,   143,   144,   145,    -1,    -1,    -1,   149,    -1,    -1,
     152,   153,   154,    -1,   125,    -1,   127,   128,   129,    -1,
     131,   132,   133,    -1,   135,   136,   137,   138,   139,    -1,
      -1,   142,   143,   144,   145,    -1,   147,   148,   149,    -1,
      75,   152,   153,   154,    79,    -1,    -1,    -1,   159,    -1,
      -1,    10,    -1,    88,    -1,    -1,    -1,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,   109,   110,   111,   112,   113,   114,
     115,    -1,    -1,   118,   119,   120,   121,    -1,   123,   124,
     125,    -1,   127,   128,   129,    -1,   131,   132,   133,    -1,
     135,   136,   137,   138,   139,    -1,    -1,   142,   143,   144,
     145,    -1,   147,   148,   149,    -1,    75,   152,   153,   154,
      79,   156,    -1,    -1,    -1,    -1,    -1,    10,    -1,    88,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,    -1,    -1,   118,
     119,   120,   121,    -1,   123,   124,   125,    -1,   127,   128,
     129,    -1,   131,   132,   133,    -1,   135,   136,   137,   138,
     139,    -1,    -1,   142,   143,   144,   145,    -1,   147,   148,
     149,    -1,    75,   152,   153,   154,    79,   156,    -1,    -1,
      -1,    -1,    -1,    10,    -1,    88,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    -1,   109,   110,   111,   112,
     113,   114,   115,    -1,    -1,   118,   119,   120,   121,    -1,
     123,   124,   125,    -1,   127,   128,   129,    -1,   131,   132,
     133,    -1,   135,   136,   137,   138,   139,    -1,    -1,   142,
     143,   144,   145,    -1,   147,   148,   149,    -1,    75,   152,
     153,   154,    79,   156,    -1,    -1,    -1,    -1,    -1,    10,
      -1,    88,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    -1,   109,   110,   111,   112,   113,   114,   115,    -1,
      -1,   118,   119,   120,   121,    -1,   123,   124,   125,    -1,
     127,   128,   129,    -1,   131,   132,   133,    -1,   135,   136,
     137,   138,   139,    -1,    -1,   142,   143,   144,   145,    -1,
     147,   148,   149,    -1,    75,   152,   153,   154,    79,   156,
      -1,    -1,    -1,    -1,    -1,    10,    -1,    88,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,   109,   110,
     111,   112,   113,   114,   115,    -1,    -1,   118,   119,   120,
     121,    -1,   123,   124,   125,    -1,   127,   128,   129,    -1,
     131,   132,   133,    -1,   135,   136,   137,   138,   139,    -1,
      -1,   142,   143,   144,   145,    -1,   147,   148,   149,    -1,
      75,   152,   153,   154,    79,   156,    -1,    -1,    -1,    -1,
      -1,    10,    -1,    88,    -1,    -1,    -1,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,   109,   110,   111,   112,   113,   114,
     115,    -1,    -1,   118,   119,   120,   121,    -1,   123,   124,
     125,    -1,   127,   128,   129,    -1,   131,   132,   133,    -1,
     135,   136,   137,   138,   139,    -1,    -1,   142,   143,   144,
     145,    -1,   147,   148,   149,    -1,    75,   152,   153,   154,
      79,   156,    -1,    -1,    -1,    -1,    -1,    10,    -1,    88,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,    -1,    -1,   118,
     119,   120,   121,    -1,   123,   124,   125,    -1,   127,   128,
     129,    -1,   131,   132,   133,    -1,   135,   136,   137,   138,
     139,    -1,    -1,   142,   143,   144,   145,    -1,   147,   148,
     149,    -1,    75,   152,   153,   154,    79,   156,    -1,    -1,
      -1,    -1,    -1,    10,    -1,    88,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    -1,   109,   110,   111,   112,
     113,   114,   115,    -1,    -1,   118,   119,   120,   121,    -1,
     123,   124,   125,    -1,   127,   128,   129,    -1,   131,   132,
     133,    -1,   135,   136,   137,   138,   139,    -1,    -1,   142,
     143,   144,   145,    -1,   147,   148,   149,    -1,    75,   152,
     153,   154,    79,   156,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      -1,    -1,   109,   110,   111,   112,   113,   114,   115,    28,
      29,   118,   119,   120,   121,    -1,   123,   124,   125,    -1,
     127,   128,   129,    42,   131,   132,   133,    -1,   135,   136,
     137,   138,   139,    -1,    -1,   142,   143,   144,   145,    -1,
     147,   148,   149,    -1,    -1,   152,   153,   154,    -1,   156,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,
      79,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
     109,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,   127,   128,
     129,    -1,   131,   132,   133,    -1,   135,   136,   137,   138,
     139,    -1,    -1,   142,   143,   144,   145,    75,   147,   148,
     149,    79,    -1,   152,   153,   154,    -1,   156,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,   127,
     128,   129,    -1,   131,   132,   133,    -1,   135,   136,   137,
     138,   139,    -1,    -1,   142,   143,   144,   145,    -1,   147,
     148,   149,    -1,    75,   152,   153,   154,    79,   156,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
      -1,    -1,    -1,   105,    -1,    -1,    -1,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,    -1,   131,
     132,   133,    -1,   135,   136,   137,   138,   139,    -1,    -1,
     142,   143,   144,   145,    75,   147,   148,   149,    79,    -1,
     152,   153,   154,    -1,   156,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,    -1,   127,   128,   129,    -1,
     131,   132,   133,    -1,   135,   136,   137,   138,   139,    -1,
      -1,   142,   143,   144,   145,    -1,   147,   148,   149,    -1,
      75,   152,   153,   154,    79,   156,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,
     125,    -1,   127,   128,   129,    17,   131,   132,   133,    -1,
     135,   136,   137,   138,   139,    -1,    28,   142,   143,   144,
     145,    75,   147,   148,   149,    79,    -1,   152,   153,   154,
      -1,   156,    -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    -1,    -1,    -1,    79,    -1,    -1,
      -1,   125,    -1,   127,   128,   129,    -1,   131,   132,   133,
      -1,   135,   136,   137,   138,   139,    -1,    -1,   142,   143,
     144,   145,    -1,   147,   148,   149,    -1,   109,   152,   153,
     154,    -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    10,    -1,   125,    -1,   127,   128,   129,    17,   131,
     132,   133,    -1,   135,   136,   137,   138,   139,    -1,    28,
     142,   143,   144,   145,    33,   147,   148,   149,    -1,    -1,
     152,   153,   154,    -1,   156,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,
      79,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,
      -1,    79,    -1,    -1,    -1,    -1,   125,    -1,   127,   128,
     129,    -1,   131,   132,   133,    -1,   135,   136,   137,   138,
     139,    -1,    -1,   142,   143,   144,   145,   105,   147,   148,
     149,   109,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    -1,   125,    -1,   127,
     128,   129,    17,   131,   132,   133,    -1,   135,   136,   137,
     138,   139,    -1,    28,   142,   143,   144,   145,    33,   147,
     148,   149,    -1,    -1,   152,   153,   154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    -1,    79,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,    28,    29,    -1,    -1,    -1,
      -1,    75,    -1,    -1,    -1,    79,    -1,    -1,    -1,    42,
     125,    -1,   127,   128,   129,    -1,   131,   132,   133,    -1,
     135,   136,   137,   138,   139,    -1,    -1,   142,   143,   144,
     145,    -1,   147,   148,   149,   109,    -1,   152,   153,   154,
      -1,    -1,    75,    -1,    -1,    -1,    79,    -1,    -1,    -1,
      -1,   125,    -1,   127,   128,   129,    -1,   131,   132,   133,
      -1,   135,   136,   137,   138,   139,    -1,    -1,   142,   143,
     144,   145,    -1,   147,   148,   149,   109,    -1,   152,   153,
     154,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    -1,   125,    -1,   127,   128,   129,    -1,   131,   132,
     133,    28,   135,   136,   137,   138,   139,    -1,    -1,   142,
     143,   144,   145,    -1,   147,   148,   149,    -1,    -1,   152,
     153,   154,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   109,    28,    -1,    -1,    -1,    -1,    -1,    75,
      -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,   125,    -1,
     127,   128,   129,    -1,   131,   132,   133,    -1,   135,   136,
     137,   138,   139,    -1,    -1,   142,   143,   144,   145,    -1,
     147,   148,   149,   109,   151,   152,   153,   154,    -1,    -1,
      75,    -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,   125,
      -1,   127,   128,   129,    -1,   131,   132,   133,    -1,   135,
     136,   137,   138,   139,    -1,    -1,   142,   143,   144,   145,
      -1,   147,   148,   149,   109,   151,   152,   153,   154,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,
     125,    -1,   127,   128,   129,    -1,   131,   132,   133,    28,
     135,   136,   137,   138,   139,    -1,    -1,   142,   143,   144,
     145,    -1,   147,   148,   149,    -1,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    -1,    -1,    75,    -1,    -1,    -1,
      79,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,   127,   128,
     129,    75,   131,   132,   133,    79,   135,   136,   137,   138,
     139,    -1,    -1,   142,   143,   144,   145,    -1,   147,   148,
     149,    -1,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    -1,   108,   109,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    -1,    10,
      -1,   125,    -1,   127,   128,   129,    17,   131,   132,   133,
      -1,   135,   136,   137,   138,   139,   109,    28,   142,   143,
     144,   145,    -1,   147,   148,   149,    -1,    -1,   152,   153,
     154,    -1,   125,    -1,   127,   128,   129,    -1,   131,   132,
     133,    -1,   135,   136,   137,   138,   139,    -1,    -1,   142,
     143,   144,   145,    -1,   147,   148,   149,    -1,    -1,   152,
     153,   154,    -1,    -1,    75,    -1,    -1,    -1,    79,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      -1,    -1,    -1,    -1,   125,    -1,   127,   128,   129,    28,
     131,   132,   133,    -1,   135,   136,   137,   138,   139,    -1,
     141,   142,   143,   144,   145,    75,   147,   148,   149,    79,
      -1,   152,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    17,    -1,   105,    75,    -1,    -1,   109,
      79,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   125,    -1,   127,   128,   129,
      -1,   131,   132,   133,    -1,   135,   136,   137,   138,   139,
     109,    -1,   142,   143,   144,   145,    -1,   147,   148,   149,
      -1,    -1,   152,   153,   154,    -1,   125,    -1,   127,   128,
     129,    75,   131,   132,   133,    79,   135,   136,   137,   138,
     139,    -1,    -1,   142,   143,   144,   145,    -1,   147,   148,
     149,    10,   151,   152,   153,   154,    -1,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,    28,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   125,    -1,   127,   128,   129,    -1,   131,   132,   133,
      -1,   135,   136,   137,   138,   139,    -1,    -1,   142,   143,
     144,   145,    -1,   147,   148,   149,    10,    -1,   152,   153,
     154,    -1,    -1,    17,    -1,    -1,    75,    -1,    -1,    -1,
      79,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,   127,   128,
     129,    75,   131,   132,   133,    79,   135,   136,   137,   138,
     139,    -1,    -1,   142,   143,   144,   145,    -1,   147,   148,
     149,    -1,    10,   152,   153,   154,    -1,    -1,    -1,    17,
      -1,    -1,    75,    -1,   108,   109,    79,    -1,    -1,    -1,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   125,    -1,   127,   128,   129,    -1,   131,   132,   133,
      -1,   135,   136,   137,   138,   139,   109,    -1,   142,   143,
     144,   145,    -1,   147,   148,   149,    -1,    -1,   152,   153,
     154,    -1,   125,    -1,   127,   128,   129,    75,   131,   132,
     133,    79,   135,   136,   137,   138,   139,    -1,    -1,   142,
     143,   144,   145,    -1,   147,   148,   149,    10,    -1,   152,
     153,   154,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,   109,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,   127,
     128,   129,    -1,   131,   132,   133,    -1,   135,   136,   137,
     138,   139,    -1,    -1,   142,   143,   144,   145,    -1,   147,
     148,   149,    -1,    -1,   152,   153,   154,    -1,    -1,    -1,
      -1,    -1,    75,    -1,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    -1,    88,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      10,    11,   125,    -1,   127,   128,   129,    17,   131,   132,
     133,    -1,   135,   136,   137,   138,   139,    -1,    28,   142,
     143,   144,   145,    -1,   147,   148,   149,    -1,    75,   152,
     153,   154,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   109,    -1,    -1,    75,    -1,    -1,    -1,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,   125,    -1,
     127,   128,   129,    17,   131,   132,   133,    -1,   135,   136,
     137,   138,   139,    -1,    28,   142,   143,   144,   145,   109,
     147,   148,   149,    -1,    -1,   152,   153,   154,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   125,    -1,   127,   128,   129,
      -1,   131,   132,   133,    -1,   135,   136,   137,   138,   139,
      -1,    -1,   142,   143,   144,   145,    -1,   147,   148,   149,
      -1,    75,   152,   153,   154,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    10,    -1,    88,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   125,    -1,   127,   128,   129,    -1,   131,   132,   133,
      -1,   135,   136,   137,   138,   139,    -1,    -1,   142,   143,
     144,   145,    -1,   147,   148,   149,    -1,    75,   152,   153,
     154,    79,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,
      88,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,   127,
     128,   129,    -1,   131,   132,   133,    -1,   135,   136,   137,
     138,   139,    -1,    -1,   142,   143,   144,   145,    -1,   147,
     148,   149,    -1,    75,   152,   153,   154,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    10,    -1,    88,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    -1,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,    -1,   131,
     132,   133,    -1,   135,   136,   137,   138,   139,    -1,    -1,
     142,   143,   144,   145,    -1,   147,   148,   149,    -1,    75,
     152,   153,   154,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      10,    -1,    88,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
      -1,   127,   128,   129,    -1,   131,   132,   133,    -1,   135,
     136,   137,   138,   139,    -1,    -1,   142,   143,   144,   145,
      -1,   147,   148,   149,    -1,    75,   152,   153,   154,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,    88,    -1,
      -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   125,    -1,   127,   128,   129,
      -1,   131,   132,   133,    -1,   135,   136,   137,   138,   139,
      -1,    -1,   142,   143,   144,   145,    -1,   147,   148,   149,
      -1,    75,   152,   153,   154,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    -1,    -1,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   109,    -1,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   125,    -1,   127,   128,   129,    -1,   131,   132,   133,
      51,   135,   136,   137,   138,   139,    -1,    -1,   142,   143,
     144,   145,    -1,   147,   148,   149,    -1,    -1,   152,   153,
     154,    -1,    -1,    -1,    75,    -1,    -1,    -1,    79,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      -1,    -1,    -1,    -1,   125,    -1,   127,   128,   129,    28,
     131,   132,   133,    -1,   135,   136,   137,   138,   139,    -1,
      -1,   142,   143,   144,   145,    75,   147,   148,   149,    79,
      -1,   152,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,   109,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   125,    -1,   127,   128,   129,
      -1,   131,   132,   133,    -1,   135,   136,   137,   138,   139,
     109,    -1,   142,   143,   144,   145,    -1,   147,   148,   149,
      -1,    -1,   152,   153,   154,    -1,   125,    -1,   127,   128,
     129,    28,   131,   132,   133,    -1,   135,   136,   137,   138,
     139,    -1,    -1,   142,   143,   144,   145,    19,   147,   148,
     149,    23,    24,   152,   153,   154,    -1,    -1,    -1,    -1,
      32,    -1,    34,    35,    -1,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    44,    28,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    65,    -1,    67,    -1,    69,    -1,    -1,
      72,    -1,    74,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    95,    79,    -1,    98,    -1,   125,   101,
     127,   128,   129,    -1,   131,   132,   133,    -1,   135,   136,
     137,   138,    -1,    -1,    -1,   142,   143,   144,   145,    -1,
     147,    -1,   149,    -1,    -1,   152,   153,   154,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,    -1,   131,   132,   133,   151,
     135,   136,   137,   138,    -1,   157,    -1,   142,   143,   144,
     145,     1,   147,     3,   149,    -1,    -1,   152,   153,   154,
      -1,    -1,    -1,    -1,    -1,    15,    16,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    -1,     3,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    36,    15,    16,    -1,
      -1,    41,    -1,    43,    22,    -1,    46,    -1,    -1,    -1,
      -1,    -1,    30,    53,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    -1,    -1,    41,    64,    43,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    73,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    83,    -1,    85,    64,    87,    -1,    89,
      -1,    -1,    92,    -1,    -1,    73,    96,    -1,    -1,    99,
      -1,    -1,    -1,    -1,    82,    83,    -1,    85,    -1,    87,
      -1,    89,    -1,    -1,    92,    -1,    -1,    -1,    96,    -1,
      -1,    99
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   166,   167,     0,     1,     3,     4,     5,     6,     7,
       8,    12,    13,    14,    15,    16,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    29,    30,    32,    34,    35,
      36,    37,    38,    39,    40,    41,    43,    44,    46,    48,
      49,    50,    52,    53,    54,    56,    57,    59,    63,    64,
      65,    66,    67,    68,    69,    72,    73,    74,    76,    77,
      78,    80,    81,    82,    83,    84,    85,    86,    87,    89,
      90,    92,    93,    94,    95,    96,    98,    99,   100,   101,
     104,   106,   109,   125,   126,   127,   128,   133,   144,   146,
     148,   149,   151,   154,   156,   158,   160,   168,   169,   170,
     171,   172,   173,   175,   180,   181,   182,   186,   188,   192,
     193,   194,   195,   196,   197,   199,   200,   201,   205,   206,
     209,   210,   213,   214,   217,   220,   221,   247,   250,   251,
     271,   272,   273,   274,   275,   276,   284,   285,   286,   287,
     290,   291,   292,   293,   294,   295,   296,   298,   299,   300,
     301,   302,   151,   170,   287,   105,   277,   278,     3,   183,
      12,    37,    38,    40,    87,   156,   160,   217,   271,   275,
     285,   286,   287,   290,   292,   293,   277,   287,    95,   250,
      76,   183,   170,   265,   287,   170,   158,   287,   288,     7,
       9,    95,   190,   288,    65,   107,   198,   287,   198,   287,
      23,    35,   251,   287,   287,   158,     3,    15,    16,    22,
      30,    36,    41,    43,    46,    53,    64,    73,    82,    83,
      85,    87,    89,    92,    96,    99,   185,   187,   218,   158,
     185,   252,   253,    29,   175,   191,   287,   287,   287,   287,
     287,   287,     7,   158,    35,   194,   194,   150,   240,   264,
     287,    93,    94,   151,   287,   289,   287,   191,   287,   287,
     287,    86,   158,   170,   287,   287,   175,   182,   287,   290,
     175,   182,   287,   185,   248,   287,   264,   287,   287,   287,
     287,   287,   287,   287,   287,     1,   157,   168,   176,   264,
      97,   134,   240,   266,   267,   289,   198,   264,   287,   297,
      67,   170,   156,    71,   174,   185,   185,    47,    70,   235,
     252,   151,   141,    10,    17,    28,    75,    79,   109,   125,
     127,   128,   129,   131,   132,   133,   135,   136,   137,   138,
     139,   142,   143,   144,   145,   147,   148,   149,   152,   153,
     154,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   155,   227,   158,   160,
      75,    79,   158,   170,   151,   287,   287,   287,   264,   156,
     175,    42,   277,   248,   252,   151,   130,   151,   104,   186,
     240,   268,   269,   270,   289,   248,   210,   250,   185,   158,
     191,    29,    42,   191,   105,   191,   280,    29,    42,   191,
     280,   288,    33,    60,   151,    88,   175,   227,   268,   170,
     158,   229,    97,   158,   185,   254,   255,     1,   129,   259,
      42,   130,   170,   191,   191,   268,   185,   130,   151,   287,
     287,   151,   156,   191,   158,   268,   151,   202,   151,   202,
     151,   110,   249,   151,   151,    33,    60,   191,   151,   157,
     157,   168,   130,   157,   287,   130,   159,   130,   159,   161,
     280,    42,   130,   161,   280,   108,   130,   161,     7,     1,
     157,   176,    55,   129,   211,   156,   222,   151,   287,   287,
     287,   287,   198,   287,   198,   287,   287,   287,   287,   287,
      16,    99,   287,   287,    30,    53,    95,   186,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   289,   289,   289,   289,   289,   268,
     268,   198,   287,   198,   287,    24,    42,    76,   101,   279,
     282,   283,   287,   302,    29,    42,    29,    42,    88,    42,
     161,   198,   287,   191,   151,   151,   287,   287,   110,   159,
     130,   151,   185,   252,    42,   264,    40,   287,   198,   287,
     158,   191,    40,   287,   198,   287,   191,   154,   177,   179,
     287,   177,   178,   170,   287,    31,   287,   159,    24,    42,
      45,    62,    65,    76,    95,   169,   230,   231,   232,   233,
     219,   255,   130,   159,    16,    30,    43,    64,    82,    83,
      87,    99,   160,   189,   260,   272,   110,   256,   287,   253,
     159,   240,   287,     1,   207,   268,   159,    18,   203,   260,
     272,   130,   179,   178,   157,   159,   159,   266,   159,   266,
     170,   161,   198,   287,   161,   170,   287,   161,   287,   161,
     287,   157,   157,   185,   264,   156,     1,   185,   215,   216,
      24,    65,    76,    95,   224,   234,   151,   151,   151,   151,
     151,   159,   161,    42,    76,   130,   159,   271,    75,    75,
      40,   198,   287,    40,   198,   287,   198,   287,   277,   277,
     151,   240,   289,   270,   211,   151,   287,   159,   287,    29,
     191,    29,   191,   281,   282,   287,    29,   191,   280,    29,
     191,   280,   130,   151,    11,   151,    31,    31,   170,    88,
     175,    42,    76,   232,   130,   159,   158,   185,    24,    65,
      76,    95,   236,   159,   255,   259,     1,   264,    58,   289,
     157,    61,   102,   157,   208,   159,   158,   175,   185,   204,
     248,   151,   151,   170,   161,   280,   161,   280,   170,   108,
       1,   212,   157,   110,   130,   157,    76,   223,     1,     3,
      10,    15,    17,    22,    36,    41,    46,    53,    73,    85,
      89,    92,    96,   125,   126,   127,   128,   131,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   149,   152,   153,   154,   155,   158,   184,   187,   225,
     226,   227,   271,   282,   259,   271,   271,   287,    29,    29,
     287,    29,    29,   161,   161,   191,   191,   156,   191,    88,
      40,   287,    40,   287,   130,   159,    88,    40,   287,   191,
      40,   287,   191,   287,   287,   170,   287,   170,    31,   185,
     231,   255,   129,   263,    76,   259,   256,   161,    42,   161,
      29,   170,   264,   204,   129,   175,    40,   170,   287,   161,
      40,   170,   287,   161,   287,   157,    35,    69,    72,   157,
     169,   193,   287,   216,   236,   158,   228,   185,   287,   132,
     228,   228,   256,    88,    40,    40,    88,    40,    40,    40,
      40,     1,   212,   287,   287,   287,   282,   287,   287,   287,
      11,    31,   170,   263,   159,   160,   189,   240,   262,   272,
     134,   242,   256,    51,   103,   243,   287,   260,   272,   170,
     191,   159,   287,   287,   170,   287,   170,   193,     1,   129,
     258,   230,   159,     3,    89,   226,   227,   287,   287,   287,
     287,   287,   287,   157,   157,    88,    88,    88,    88,   287,
     170,   256,   263,   161,   264,   240,   241,   287,     3,    78,
      89,   244,   245,   246,   287,   175,   192,   239,   161,   175,
      88,    88,   160,   189,   257,   272,    91,   237,   159,   228,
     228,    88,    88,    88,    88,    88,    88,   287,   287,   287,
     287,   242,   256,   240,   261,   262,   272,    42,   161,   246,
     103,   130,   110,   135,   137,   138,   142,   143,    51,   272,
     287,   287,     1,   161,   264,   243,   287,   261,   262,   287,
     245,   246,   246,   246,   246,   246,   246,   244,   161,   257,
     272,   161,   151,   238,   239,   161,   257,   272,   261
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   165,   166,   167,   167,   168,   168,   169,   169,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   171,
     172,   172,   172,   173,   173,   173,   174,   174,   175,   175,
     175,   176,   176,   177,   177,   177,   177,   178,   178,   179,
     179,   180,   180,   180,   181,   182,   182,   182,   182,   182,
     183,   183,   184,   184,   184,   184,   184,   185,   185,   185,
     185,   185,   186,   186,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     188,   188,   188,   188,   188,   188,   188,   188,   189,   189,
     189,   189,   189,   189,   189,   189,   190,   190,   191,   191,
     192,   192,   193,   193,   193,   193,   193,   193,   193,   193,
     194,   194,   195,   195,   195,   195,   196,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   198,   199,   199,   199,   199,   199,   199,
     199,   199,   200,   201,   201,   201,   201,   201,   201,   202,
     202,   203,   203,   203,   204,   204,   205,   206,   206,   207,
     207,   208,   208,   208,   209,   209,   209,   209,   210,   210,
     210,   211,   211,   212,   212,   212,   213,   213,   214,   215,
     215,   215,   216,   216,   218,   219,   217,   220,   220,   220,
     220,   220,   222,   223,   221,   224,   224,   224,   224,   224,
     225,   225,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   228,   228,   229,   230,   230,   230,   231,   231,   231,
     231,   231,   232,   232,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   234,   234,   234,   234,   234,   234,   235,
     235,   236,   236,   236,   236,   236,   236,   237,   237,   238,
     238,   239,   239,   240,   240,   241,   241,   242,   242,   243,
     243,   243,   243,   243,   244,   244,   245,   245,   245,   245,
     245,   245,   245,   246,   246,   247,   247,   247,   248,   248,
     249,   249,   249,   250,   250,   250,   250,   250,   251,   251,
     251,   252,   252,   253,   253,   254,   254,   254,   255,   255,
     255,   256,   256,   256,   257,   257,   257,   257,   257,   257,
     257,   258,   258,   258,   258,   258,   259,   259,   259,   259,
     259,   260,   260,   260,   260,   261,   261,   261,   262,   262,
     262,   262,   262,   263,   263,   263,   263,   263,   264,   264,
     264,   264,   265,   265,   266,   266,   266,   267,   267,   268,
     268,   269,   269,   270,   270,   270,   270,   271,   271,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   274,   275,   276,   276,   276,   276,   276,   276,
     276,   276,   277,   277,   278,   279,   279,   280,   281,   281,
     282,   282,   282,   283,   283,   283,   283,   283,   283,   284,
     284,   285,   286,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   288,
     288,   289,   289,   289,   290,   290,   290,   290,   291,   291,
     292,   292,   292,   293,   293,   293,   293,   294,   294,   294,
     294,   295,   295,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   297,   297,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     299,   299,   299,   299,   299,   299,   300,   300,   300,   300,
     301,   301,   301,   301,   302,   302,   302,   302,   302,   302,
     302
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     2,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     2,     2,     3,     2,     4,
       3,     4,     4,     0,     1,     1,     0,     1,     2,     3,
       3,     1,     2,     1,     3,     3,     5,     0,     1,     1,
       1,     3,     5,     5,     3,     4,     4,     4,     4,     4,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     2,     1,
       2,     3,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     3,     5,     5,     2,     2,     5,     3,     6,
       6,     4,     5,     5,     3,     3,     6,     5,     6,     5,
       6,     3,     4,     3,     4,     6,     7,     6,     7,     4,
       5,     4,     5,     4,     4,     3,     6,     5,     6,     5,
       8,     7,     2,     3,     3,     2,     2,     3,     3,     0,
       2,     2,     3,     5,     1,     3,     3,     5,     5,     0,
       2,     3,     2,     3,     6,     8,     6,     8,     1,     1,
       1,     0,     2,     0,     2,     3,     5,     5,     1,     1,
       2,     3,     1,     3,     0,     0,     8,     0,     1,     2,
       2,     1,     0,     0,    10,     3,     3,     5,     5,     3,
       1,     3,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     3,     3,     0,     1,     3,     4,     5,     4,
       6,     6,     0,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     0,     1,     1,     2,     1,     1,     1,
       1,     0,     1,     2,     1,     1,     1,     0,     1,     1,
       1,     1,     1,     2,     1,     0,     1,     2,     2,     0,
       2,     2,     4,     4,     1,     3,     3,     3,     3,     3,
       3,     3,     2,     1,     1,     3,     4,     4,     2,     4,
       0,     2,     2,     1,     1,     1,     2,     1,     4,     5,
       3,     1,     3,     3,     5,     1,     1,     3,     1,     2,
       3,     0,     2,     2,     3,     2,     4,     3,     3,     4,
       3,     0,     2,     2,     2,     1,     0,     2,     2,     2,
       1,     4,     4,     6,     3,     0,     1,     1,     3,     4,
       3,     4,     6,     0,     2,     2,     2,     2,     1,     1,
       3,     3,     1,     3,     1,     1,     1,     3,     3,     0,
       1,     1,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     4,     4,     5,     2,
       2,     2,     2,     2,     2,     6,     6,     4,     9,     9,
       7,     6,     6,     4,     9,     9,     7,     4,     6,     6,
       9,     9,     6,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     0,     1,     4,     1,     3,     4,     1,     3,
       4,     3,     3,     1,     1,     2,     1,     2,     1,     1,
       3,     2,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     3,     3,     3,     3,     2,     2,     1,     0,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     3,     3,     3,     3,     3,     4,     3,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     4,     3,     4,     3,     5,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (&yylloc, context, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, context); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, ParserContext* context)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (context);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, ParserContext* context)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, context);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, ParserContext* context)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , context);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, context); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, ParserContext* context)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (context);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}



struct yypstate
  {
    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;
    /* Used to determine if this is the first time this instance has
       been used.  */
    int yynew;
  };

/* Initialize the parser data structure.  */
yypstate *
yypstate_new (void)
{
  yypstate *yyps;
  yyps = (yypstate *) malloc (sizeof *yyps);
  if (!yyps)
    return YY_NULLPTR;
  yyps->yynew = 1;
  return yyps;
}

void
yypstate_delete (yypstate *yyps)
{
#ifndef yyoverflow
  /* If the stack was reallocated but the parse did not complete, then the
     stack still needs to be freed.  */
  if (!yyps->yynew && yyps->yyss != yyps->yyssa)
    YYSTACK_FREE (yyps->yyss);
#endif
  free (yyps);
}

#define yynerrs yyps->yynerrs
#define yystate yyps->yystate
#define yyerrstatus yyps->yyerrstatus
#define yyssa yyps->yyssa
#define yyss yyps->yyss
#define yyssp yyps->yyssp
#define yyvsa yyps->yyvsa
#define yyvs yyps->yyvs
#define yyvsp yyps->yyvsp
#define yylsa yyps->yylsa
#define yyls yyps->yyls
#define yylsp yyps->yylsp
#define yyerror_range yyps->yyerror_range
#define yystacksize yyps->yystacksize


/*---------------.
| yypush_parse.  |
`---------------*/

int
yypush_parse (yypstate *yyps, int yypushed_char, YYSTYPE const *yypushed_val, YYLTYPE *yypushed_loc, ParserContext* context)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  if (!yyps->yynew)
    {
      yyn = yypact[yystate];
      goto yyread_pushed_token;
    }

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = *yypushed_loc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      if (!yyps->yynew)
        {
          YYDPRINTF ((stderr, "Return for a new token:\n"));
          yyresult = YYPUSH_MORE;
          goto yypushreturn;
        }
      yyps->yynew = 0;
yyread_pushed_token:
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yypushed_char;
      if (yypushed_val)
        yylval = *yypushed_val;
      if (yypushed_loc)
        yylloc = *yypushed_loc;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 488 "chapel.ypp" /* yacc.c:1661  */
    { yyblock = (yyval.pblockstmt); }
#line 5606 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 3:
#line 493 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = new BlockStmt(); resetTempID(); }
#line 5612 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 4:
#line 494 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-1].pblockstmt)->appendChapelStmt((yyvsp[0].pblockstmt)); context->generatedStmt = (yyvsp[-1].pblockstmt); resetTempID(); }
#line 5618 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 6:
#line 501 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildPragmaStmt( (yyvsp[-1].vpch), (yyvsp[0].pblockstmt) ); }
#line 5624 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 7:
#line 506 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.vpch) = new Vec<const char*>(); (yyval.vpch)->add(astr((yyvsp[0].pch))); }
#line 5630 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 8:
#line 507 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-2].vpch)->add(astr((yyvsp[0].pch))); }
#line 5636 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 23:
#line 526 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt((yyvsp[-1].pexpr)); }
#line 5642 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 24:
#line 527 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAtomicStmt((yyvsp[0].pblockstmt)); }
#line 5648 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 25:
#line 528 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildBeginStmt((yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt)); }
#line 5654 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 26:
#line 529 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildGotoStmt(GOTO_BREAK, (yyvsp[-1].pch)); }
#line 5660 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 27:
#line 530 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildCobeginStmt((yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt));  }
#line 5666 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 28:
#line 531 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildGotoStmt(GOTO_CONTINUE, (yyvsp[-1].pch)); }
#line 5672 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 29:
#line 532 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildDeleteStmt((yyvsp[-1].pcallexpr)); }
#line 5678 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 30:
#line 533 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildLabelStmt((yyvsp[-1].pch), (yyvsp[0].pblockstmt)); }
#line 5684 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 31:
#line 534 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildLocalStmt((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 5690 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 32:
#line 535 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildLocalStmt((yyvsp[0].pblockstmt)); }
#line 5696 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 33:
#line 536 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildOnStmt((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 5702 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 34:
#line 537 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildSerialStmt((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 5708 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 35:
#line 538 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildSerialStmt(new SymExpr(gTrue), (yyvsp[0].pblockstmt)); }
#line 5714 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 36:
#line 539 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildSyncStmt((yyvsp[0].pblockstmt)); }
#line 5720 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 37:
#line 540 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_YIELD, (yyvsp[-1].pexpr)); }
#line 5726 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 38:
#line 541 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildErrorStandin(); }
#line 5732 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 39:
#line 546 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pmodsymbol) = buildModule((yyvsp[0].pch), currentModuleType, NULL, yyfilename, (yyvsp[-3].b), (yyvsp[-2].b), (yylsp[-3]).comment);
      // store previous module name in order to restore it once we're
      // done with this module in module_decl_stmt below.  Ultimately,
      // we will need to store a stack of module names in order to
      // support full module path resolution of -s config flags.
      (yyloc).prevModule = currentModuleName;
      currentModuleName = (yyvsp[0].pch);
    }
#line 5746 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 40:
#line 559 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-2].pmodsymbol)->block = new BlockStmt();
      (yyval.pblockstmt) = buildChapelStmt(new DefExpr((yyvsp[-2].pmodsymbol)));
      currentModuleName = (yylsp[-2]).prevModule;  // restore previous module name
    }
#line 5755 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 41:
#line 564 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-3].pmodsymbol)->block = (yyvsp[-1].pblockstmt);
      (yyval.pblockstmt) = buildChapelStmt(new DefExpr((yyvsp[-3].pmodsymbol)));
      currentModuleName = (yylsp[-3]).prevModule;  // restore previous module name
    }
#line 5764 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 42:
#line 569 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-3].pmodsymbol)->block = buildErrorStandin();
      (yyval.pblockstmt) = buildChapelStmt(new DefExpr((yyvsp[-3].pmodsymbol)));
      currentModuleName = (yylsp[-3]).prevModule;  // restore previous module name
    }
#line 5773 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 43:
#line 576 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.b) = false; (yyloc).comment = context->latestComment; context->latestComment = NULL; }
#line 5779 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 44:
#line 577 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.b) = false; (yyloc).comment = context->latestComment; context->latestComment = NULL; }
#line 5785 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 45:
#line 578 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.b) = true; (yyloc).comment = context->latestComment; context->latestComment = NULL; }
#line 5791 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 46:
#line 582 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.b) = false; }
#line 5797 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 47:
#line 583 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.b) = true;  }
#line 5803 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 48:
#line 596 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = new BlockStmt(); }
#line 5809 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 49:
#line 597 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = (yyvsp[-1].pblockstmt);              }
#line 5815 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 50:
#line 598 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildErrorStandin(); }
#line 5821 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 51:
#line 603 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = new BlockStmt(); (yyval.pblockstmt)->appendChapelStmt((yyvsp[0].pblockstmt)); }
#line 5827 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 52:
#line 604 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-1].pblockstmt)->appendChapelStmt((yyvsp[0].pblockstmt)); }
#line 5833 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 53:
#line 609 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.ponlylist) = new std::vector<OnlyRename*>();
                                         OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::SINGLE;
                                         cur->elem = (yyvsp[0].pexpr);
                                         (yyval.ponlylist)->push_back(cur); }
#line 5843 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 54:
#line 614 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.ponlylist) = new std::vector<OnlyRename*>();
                                         OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::DOUBLE;
                                         cur->renamed = new std::pair<Expr*, Expr*>((yyvsp[-2].pexpr), (yyvsp[0].pexpr));
                                         (yyval.ponlylist)->push_back(cur); }
#line 5853 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 55:
#line 619 "chapel.ypp" /* yacc.c:1661  */
    { OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::SINGLE;
                                         cur->elem = (yyvsp[0].pexpr);
                                         (yyvsp[-2].ponlylist)->push_back(cur); }
#line 5862 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 56:
#line 623 "chapel.ypp" /* yacc.c:1661  */
    { OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::DOUBLE;
                                         cur->renamed = new std::pair<Expr*, Expr*>((yyvsp[-2].pexpr), (yyvsp[0].pexpr));
                                         (yyvsp[-4].ponlylist)->push_back(cur); }
#line 5871 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 57:
#line 630 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.ponlylist) = new std::vector<OnlyRename*>();
                                         OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::SINGLE;
                                         cur->elem = new UnresolvedSymExpr("");
                                         (yyval.ponlylist)->push_back(cur); }
#line 5881 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 59:
#line 639 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.ponlylist) = new std::vector<OnlyRename*>();
                                         OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::SINGLE;
                                         cur->elem = new UnresolvedSymExpr("");
                                         (yyval.ponlylist)->push_back(cur); }
#line 5891 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 61:
#line 648 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildUseStmt((yyvsp[-1].pcallexpr)); }
#line 5897 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 62:
#line 649 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildUseStmt((yyvsp[-3].pexpr), (yyvsp[-1].ponlylist), true); }
#line 5903 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 63:
#line 650 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildUseStmt((yyvsp[-3].pexpr), (yyvsp[-1].ponlylist), false); }
#line 5909 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 64:
#line 654 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildRequireStmt((yyvsp[-1].pcallexpr)); }
#line 5915 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 65:
#line 659 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), (yyvsp[-2].pch));   }
#line 5921 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 66:
#line 661 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), "<=>"); }
#line 5927 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 67:
#line 663 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), PRIM_REDUCE_ASSIGN); }
#line 5933 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 68:
#line 665 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildLAndAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr));    }
#line 5939 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 69:
#line 667 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildLOrAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr));     }
#line 5945 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 70:
#line 673 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = NULL; }
#line 5951 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 71:
#line 674 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 5957 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 72:
#line 678 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 5963 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 73:
#line 679 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "this"; }
#line 5969 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 74:
#line 680 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "false"; redefiningReservedWordError((yyval.pch)); }
#line 5975 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 75:
#line 681 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "true"; redefiningReservedWordError((yyval.pch)); }
#line 5981 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 76:
#line 682 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = (yyvsp[0].pch); redefiningReservedTypeError((yyvsp[0].pch)); }
#line 5987 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 77:
#line 685 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 5993 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 78:
#line 686 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "this"; redefiningReservedWordError((yyval.pch)); }
#line 5999 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 79:
#line 687 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "false"; redefiningReservedWordError((yyval.pch)); }
#line 6005 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 80:
#line 688 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "true"; redefiningReservedWordError((yyval.pch)); }
#line 6011 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 81:
#line 689 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = (yyvsp[0].pch); redefiningReservedTypeError((yyvsp[0].pch)); }
#line 6017 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 82:
#line 701 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 6023 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 83:
#line 702 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "this"; }
#line 6029 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 84:
#line 713 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "bool"; }
#line 6035 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 85:
#line 714 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "int"; }
#line 6041 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 86:
#line 715 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "uint"; }
#line 6047 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 87:
#line 716 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "real"; }
#line 6053 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 88:
#line 717 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "imag"; }
#line 6059 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 89:
#line 718 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "complex"; }
#line 6065 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 90:
#line 719 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "string"; }
#line 6071 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 91:
#line 720 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "sync"; }
#line 6077 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 92:
#line 721 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "single"; }
#line 6083 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 93:
#line 722 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "owned"; }
#line 6089 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 94:
#line 723 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "shared"; }
#line 6095 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 95:
#line 724 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "borrowed"; }
#line 6101 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 96:
#line 725 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "unmanaged"; }
#line 6107 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 97:
#line 726 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "domain"; }
#line 6113 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 98:
#line 727 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "index"; }
#line 6119 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 99:
#line 728 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "locale"; }
#line 6125 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 100:
#line 732 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new SymExpr(dtBools[BOOL_SIZE_DEFAULT]->symbol); }
#line 6131 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 101:
#line 733 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new SymExpr(dtInt[INT_SIZE_DEFAULT]->symbol); }
#line 6137 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 102:
#line 734 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new SymExpr(dtUInt[INT_SIZE_DEFAULT]->symbol); }
#line 6143 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 103:
#line 735 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new SymExpr(dtReal[FLOAT_SIZE_DEFAULT]->symbol); }
#line 6149 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 104:
#line 736 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new SymExpr(dtImag[FLOAT_SIZE_DEFAULT]->symbol); }
#line 6155 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 105:
#line 737 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new SymExpr(dtComplex[COMPLEX_SIZE_DEFAULT]->symbol); }
#line 6161 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 106:
#line 738 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new SymExpr(dtString->symbol); }
#line 6167 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 107:
#line 739 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new SymExpr(dtLocale->symbol); }
#line 6173 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 108:
#line 746 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "_syncvar"; }
#line 6179 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 109:
#line 747 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "_singlevar"; }
#line 6185 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 110:
#line 748 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "_owned"; }
#line 6191 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 111:
#line 749 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "_shared"; }
#line 6197 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 112:
#line 750 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "_borrowed"; }
#line 6203 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 113:
#line 751 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "_unmanaged"; }
#line 6209 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 114:
#line 752 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "_domain"; }
#line 6215 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 115:
#line 753 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "_index"; }
#line 6221 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 116:
#line 758 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = NULL; }
#line 6227 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 117:
#line 759 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 6233 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 118:
#line 763 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = (yyvsp[0].pblockstmt); }
#line 6239 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 119:
#line 764 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = (yyvsp[0].pblockstmt); }
#line 6245 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 120:
#line 768 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_RETURN); }
#line 6251 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 121:
#line 769 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_RETURN, (yyvsp[-1].pexpr)); }
#line 6257 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 122:
#line 773 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt(new BlockStmt()); }
#line 6263 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 124:
#line 775 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = (yyvsp[0].pblockstmt); }
#line 6269 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 125:
#line 776 "chapel.ypp" /* yacc.c:1661  */
    { applyPrivateToBlock((yyvsp[0].pblockstmt)); (yyval.pblockstmt) = (yyvsp[0].pblockstmt); }
#line 6275 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 132:
#line 789 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildForwardingStmt((yyvsp[-1].pexpr)); }
#line 6281 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 133:
#line 790 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildForwardingStmt((yyvsp[-3].pexpr), (yyvsp[-1].ponlylist), true); }
#line 6287 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 134:
#line 791 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildForwardingStmt((yyvsp[-3].pexpr), (yyvsp[-1].ponlylist), false); }
#line 6293 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 135:
#line 792 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildForwardingDeclStmt((yyvsp[0].pblockstmt)); }
#line 6299 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 136:
#line 797 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pblockstmt) = buildExternBlockStmt(astr((yyvsp[0].pch)));
    }
#line 6307 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 137:
#line 803 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = DoWhileStmt::build((yyvsp[-1].pexpr), (yyvsp[-3].pblockstmt)); }
#line 6313 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 138:
#line 804 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = WhileDoStmt::build((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 6319 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 139:
#line 805 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildCoforallLoopStmt((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt));       }
#line 6325 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 140:
#line 806 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildCoforallLoopStmt((yyvsp[-4].pexpr), (yyvsp[-2].pcallexpr), (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt), true); }
#line 6331 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 141:
#line 807 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildCoforallLoopStmt(NULL, (yyvsp[-2].pexpr), (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt));     }
#line 6337 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 142:
#line 808 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForLoop::buildForLoop(  (yyvsp[-3].pexpr), (yyvsp[-1].pexpr), (yyvsp[0].pblockstmt), false, false); }
#line 6343 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 143:
#line 809 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForLoop::buildForLoop(  (yyvsp[-3].pexpr), (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt), false,  true); }
#line 6349 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 144:
#line 810 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForLoop::buildForLoop(NULL, (yyvsp[-1].pexpr), (yyvsp[0].pblockstmt), false, false); }
#line 6355 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 145:
#line 811 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForLoop::buildForLoop(NULL, (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt), false,  true); }
#line 6361 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 146:
#line 812 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildParamForLoopStmt((yyvsp[-3].pch), (yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 6367 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 147:
#line 813 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForallStmt::build((yyvsp[-3].pexpr),   (yyvsp[-1].pexpr), NULL, (yyvsp[0].pblockstmt), false, false); }
#line 6373 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 148:
#line 814 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForallStmt::build((yyvsp[-4].pexpr),   (yyvsp[-2].pexpr), (yyvsp[-1].pcallexpr),   (yyvsp[0].pblockstmt), false, false); }
#line 6379 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 149:
#line 815 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForallStmt::build((yyvsp[-3].pexpr),   (yyvsp[-1].pcallexpr), NULL, (yyvsp[0].pblockstmt), true,  false); }
#line 6385 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 150:
#line 816 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForallStmt::build((yyvsp[-4].pexpr),   (yyvsp[-2].pcallexpr), (yyvsp[-1].pcallexpr),   (yyvsp[0].pblockstmt), true,  false); }
#line 6391 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 151:
#line 817 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-1].pexpr), NULL, (yyvsp[0].pblockstmt), false, false); }
#line 6397 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 152:
#line 818 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-2].pexpr), (yyvsp[-1].pcallexpr),   (yyvsp[0].pblockstmt), false, false); }
#line 6403 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 153:
#line 819 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-1].pcallexpr), NULL, (yyvsp[0].pblockstmt), true,  false); }
#line 6409 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 154:
#line 820 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-2].pcallexpr), (yyvsp[-1].pcallexpr),   (yyvsp[0].pblockstmt), true,  false); }
#line 6415 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 155:
#line 822 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pexpr), "invalid index expression");
      (yyval.pblockstmt) = ForallStmt::build((yyvsp[-4].pcallexpr)->get(1)->remove(), (yyvsp[-2].pexpr), NULL, new BlockStmt((yyvsp[0].pblockstmt)), false, true);
    }
#line 6425 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 156:
#line 828 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-5].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-3].pexpr), "invalid index expression");
      (yyval.pblockstmt) = ForallStmt::build((yyvsp[-5].pcallexpr)->get(1)->remove(), (yyvsp[-3].pexpr), (yyvsp[-2].pcallexpr),   new BlockStmt((yyvsp[0].pblockstmt)), false, true);
    }
#line 6435 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 157:
#line 834 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pcallexpr), "invalid index expression");
      (yyval.pblockstmt) = ForallStmt::build((yyvsp[-4].pcallexpr)->get(1)->remove(), (yyvsp[-2].pcallexpr), NULL, new BlockStmt((yyvsp[0].pblockstmt)), true,  true);
    }
#line 6445 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 158:
#line 840 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-5].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-3].pcallexpr), "invalid index expression");
      (yyval.pblockstmt) = ForallStmt::build((yyvsp[-5].pcallexpr)->get(1)->remove(), (yyvsp[-3].pcallexpr), (yyvsp[-2].pcallexpr),   new BlockStmt((yyvsp[0].pblockstmt)), true,  true);
    }
#line 6455 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 159:
#line 846 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-2].pcallexpr)->argList.length > 1)
        (yyval.pblockstmt) = ForallStmt::build(NULL, new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), NULL, new BlockStmt((yyvsp[0].pblockstmt)), false, true);
      else
        (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-2].pcallexpr)->get(1)->remove(),                       NULL, new BlockStmt((yyvsp[0].pblockstmt)), false, true);
    }
#line 6466 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 160:
#line 853 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-3].pcallexpr)->argList.length > 1)
        (yyval.pblockstmt) = ForallStmt::build(NULL, new CallExpr("chpl__ensureDomainExpr", (yyvsp[-3].pcallexpr)), (yyvsp[-2].pcallexpr), new BlockStmt((yyvsp[0].pblockstmt)), false, true);
      else
        (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-3].pcallexpr)->get(1)->remove(),                       (yyvsp[-2].pcallexpr), new BlockStmt((yyvsp[0].pblockstmt)), false, true);
    }
#line 6477 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 161:
#line 860 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-2].pcallexpr), NULL, new BlockStmt((yyvsp[0].pblockstmt)), true,  true);
    }
#line 6485 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 162:
#line 864 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-3].pcallexpr), (yyvsp[-2].pcallexpr),   new BlockStmt((yyvsp[0].pblockstmt)), true,  true);
    }
#line 6493 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 163:
#line 870 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ZIP, (yyvsp[-1].pcallexpr)); }
#line 6499 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 164:
#line 874 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[-2].pexpr), (yyvsp[0].pblockstmt)); }
#line 6505 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 165:
#line 875 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 6511 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 166:
#line 876 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[-4].pexpr), (yyvsp[-2].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 6517 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 167:
#line 877 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[-3].pexpr), (yyvsp[-2].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 6523 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 168:
#line 878 "chapel.ypp" /* yacc.c:1661  */
    {
(yyval.pblockstmt) = buildIfStmt(convertAssignmentAndWarn((yyvsp[-4].pexpr),(yyvsp[-3].pch),(yyvsp[-2].pexpr)), (yyvsp[0].pblockstmt)); }
#line 6530 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 169:
#line 880 "chapel.ypp" /* yacc.c:1661  */
    {
(yyval.pblockstmt) = buildIfStmt(convertAssignmentAndWarn((yyvsp[-3].pexpr),(yyvsp[-2].pch),(yyvsp[-1].pexpr)), (yyvsp[0].pblockstmt)); }
#line 6537 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 170:
#line 882 "chapel.ypp" /* yacc.c:1661  */
    {
(yyval.pblockstmt) = buildIfStmt(convertAssignmentAndWarn((yyvsp[-6].pexpr),(yyvsp[-5].pch),(yyvsp[-4].pexpr)), (yyvsp[-2].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 6544 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 171:
#line 884 "chapel.ypp" /* yacc.c:1661  */
    {
(yyval.pblockstmt) = buildIfStmt(convertAssignmentAndWarn((yyvsp[-5].pexpr),(yyvsp[-4].pch),(yyvsp[-3].pexpr)), (yyvsp[-2].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 6551 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 172:
#line 889 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = DeferStmt::build((yyvsp[0].pblockstmt)); }
#line 6557 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 173:
#line 892 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = TryStmt::build(false, (yyvsp[-1].pexpr)); }
#line 6563 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 174:
#line 893 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = TryStmt::build(true,  (yyvsp[-1].pexpr)); }
#line 6569 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 175:
#line 894 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = TryStmt::build(false, (yyvsp[0].pblockstmt)); }
#line 6575 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 176:
#line 895 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = TryStmt::build(true,  (yyvsp[0].pblockstmt)); }
#line 6581 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 177:
#line 896 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = TryStmt::build(false, (yyvsp[-1].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 6587 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 178:
#line 897 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = TryStmt::build(true,  (yyvsp[-1].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 6593 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 179:
#line 901 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt(); }
#line 6599 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 180:
#line 902 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-1].pblockstmt)->insertAtTail((yyvsp[0].pexpr)); }
#line 6605 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 181:
#line 906 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = CatchStmt::build((yyvsp[0].pblockstmt)); }
#line 6611 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 182:
#line 907 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = CatchStmt::build((yyvsp[-1].pdefexpr), (yyvsp[0].pblockstmt)); }
#line 6617 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 183:
#line 908 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = CatchStmt::build((yyvsp[-2].pdefexpr), (yyvsp[0].pblockstmt)); }
#line 6623 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 184:
#line 912 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = new DefExpr(new VarSymbol((yyvsp[0].pch)), NULL, new UnresolvedSymExpr("Error")); }
#line 6629 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 185:
#line 913 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = new DefExpr(new VarSymbol((yyvsp[-2].pch)), NULL, (yyvsp[0].pexpr));   }
#line 6635 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 186:
#line 917 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_THROW, (yyvsp[-1].pexpr)); }
#line 6641 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 187:
#line 921 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt(buildSelectStmt((yyvsp[-3].pexpr), (yyvsp[-1].pblockstmt))); }
#line 6647 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 188:
#line 923 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildErrorStandin(); }
#line 6653 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 189:
#line 927 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt(); }
#line 6659 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 190:
#line 928 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-1].pblockstmt)->insertAtTail((yyvsp[0].pexpr)); }
#line 6665 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 191:
#line 933 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CondStmt(new CallExpr(PRIM_WHEN, (yyvsp[-1].pcallexpr)), (yyvsp[0].pblockstmt)); }
#line 6671 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 192:
#line 935 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CondStmt(new CallExpr(PRIM_WHEN), (yyvsp[0].pblockstmt)); }
#line 6677 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 193:
#line 937 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CondStmt(new CallExpr(PRIM_WHEN), (yyvsp[0].pblockstmt)); }
#line 6683 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 194:
#line 944 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pblockstmt) = buildChapelStmt(buildClassDefExpr((yyvsp[-4].pch),
                                             NULL,
                                             (yyvsp[-5].aggrTag),
                                             (yyvsp[-3].pcallexpr),
                                             (yyvsp[-1].pblockstmt),
                                             FLAG_UNKNOWN,
                                             (yylsp[-5]).comment));
    }
#line 6697 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 195:
#line 954 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pblockstmt) = buildChapelStmt(buildClassDefExpr((yyvsp[-4].pch),
                                             (yyvsp[-6].pch),
                                             (yyvsp[-5].aggrTag),
                                             (yyvsp[-3].pcallexpr),
                                             (yyvsp[-1].pblockstmt),
                                             FLAG_EXTERN,
                                             (yylsp[-5]).comment));
    }
#line 6711 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 196:
#line 964 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pblockstmt) = buildChapelStmt(buildClassDefExpr((yyvsp[-4].pch),
                                             NULL,
                                             (yyvsp[-5].aggrTag),
                                             (yyvsp[-3].pcallexpr),
                                             new BlockStmt(),
                                             FLAG_UNKNOWN,
                                             (yylsp[-5]).comment));
    }
#line 6725 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 197:
#line 974 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pblockstmt) = buildChapelStmt(buildClassDefExpr((yyvsp[-4].pch),
                                             (yyvsp[-6].pch),
                                             (yyvsp[-5].aggrTag),
                                             (yyvsp[-3].pcallexpr),
                                             new BlockStmt(),
                                             FLAG_EXTERN,
                                             (yylsp[-5]).comment));
    }
#line 6739 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 198:
#line 986 "chapel.ypp" /* yacc.c:1661  */
    {
             (yyval.aggrTag)                     = AGGREGATE_CLASS;
             (yyloc).comment             = context->latestComment;
             context->latestComment = NULL;
           }
#line 6749 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 199:
#line 991 "chapel.ypp" /* yacc.c:1661  */
    {
             (yyval.aggrTag)                     = AGGREGATE_RECORD;
             (yyloc).comment             = context->latestComment;
             context->latestComment = NULL;
           }
#line 6759 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 200:
#line 996 "chapel.ypp" /* yacc.c:1661  */
    {
             (yyval.aggrTag)                     = AGGREGATE_UNION;
             (yyloc).comment             = context->latestComment;
             context->latestComment = NULL;
           }
#line 6769 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 201:
#line 1004 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = NULL; }
#line 6775 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 202:
#line 1005 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = (yyvsp[0].pcallexpr); }
#line 6781 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 203:
#line 1010 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = new BlockStmt(); }
#line 6787 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 204:
#line 1012 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-1].pblockstmt)->insertAtTail((yyvsp[0].pblockstmt)); }
#line 6793 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 205:
#line 1014 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-2].pblockstmt)->insertAtTail(buildPragmaStmt((yyvsp[-1].vpch), (yyvsp[0].pblockstmt))); }
#line 6799 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 206:
#line 1019 "chapel.ypp" /* yacc.c:1661  */
    {
      EnumType* pdt = (yyvsp[-4].penumtype);
      for_vector(DefExpr, ec, *(yyvsp[-1].pvecOfDefs)) {
        ec->sym->type = pdt;
        pdt->constants.insertAtTail(ec);
        if (pdt->defaultValue == NULL) {
          pdt->defaultValue = ec->sym;
        }
      }
      delete (yyvsp[-1].pvecOfDefs);
      pdt->doc = (yylsp[-4]).comment;
      TypeSymbol* pst = new TypeSymbol((yyvsp[-3].pch), pdt);
      (yyvsp[-4].penumtype)->symbol = pst;
      (yyval.pblockstmt) = buildChapelStmt(new DefExpr(pst));
    }
#line 6819 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 207:
#line 1035 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pblockstmt) = buildErrorStandin();
    }
#line 6827 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 208:
#line 1042 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.penumtype) = new EnumType();
      (yyloc).comment = context->latestComment;
      context->latestComment = NULL;
    }
#line 6837 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 209:
#line 1051 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pvecOfDefs) = new std::vector<DefExpr*>();
      (yyval.pvecOfDefs)->push_back((yyvsp[0].pdefexpr));
      //$$->doc = context->latestComment;
      // start here for enabling documentation of enum constants
      //context->latestComment = NULL;
    }
#line 6849 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 210:
#line 1059 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pvecOfDefs) = (yyvsp[-1].pvecOfDefs);
    }
#line 6857 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 211:
#line 1063 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyvsp[-2].pvecOfDefs)->push_back((yyvsp[0].pdefexpr));
    }
#line 6865 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 212:
#line 1069 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = new DefExpr(new EnumSymbol((yyvsp[0].pch))); }
#line 6871 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 213:
#line 1070 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = new DefExpr(new EnumSymbol((yyvsp[-2].pch)), (yyvsp[0].pexpr)); }
#line 6877 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 214:
#line 1075 "chapel.ypp" /* yacc.c:1661  */
    {
      captureTokens = 1;
      captureString.clear();
    }
#line 6886 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 215:
#line 1080 "chapel.ypp" /* yacc.c:1661  */
    {
      captureTokens = 0;
      (yyvsp[0].pfnsymbol)->userString = astr(captureString);
    }
#line 6895 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 216:
#line 1085 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyvsp[-5].pfnsymbol)->retTag = (yyvsp[-3].retTag);
      if ((yyvsp[-3].retTag) == RET_REF || (yyvsp[-3].retTag) == RET_CONST_REF)
        USR_FATAL("'ref' return types are not allowed in lambdas");
      if ((yyvsp[-3].retTag) == RET_PARAM)
        USR_FATAL("'param' return types are not allowed in lambdas");
      if ((yyvsp[-3].retTag) == RET_TYPE)
        USR_FATAL("'type' return types are not allowed in lambdas");
      if ((yyvsp[-2].pexpr))
        (yyvsp[-5].pfnsymbol)->retExprType = new BlockStmt((yyvsp[-2].pexpr), BLOCK_SCOPELESS);
      if ((yyvsp[-1].lifetimeAndWhere).where)
        (yyvsp[-5].pfnsymbol)->where = new BlockStmt((yyvsp[-1].lifetimeAndWhere).where);
      if ((yyvsp[-1].lifetimeAndWhere).lifetime)
        (yyvsp[-5].pfnsymbol)->lifetimeConstraints = new BlockStmt((yyvsp[-1].lifetimeAndWhere).lifetime);
      (yyvsp[-5].pfnsymbol)->insertAtTail((yyvsp[0].pblockstmt));
      (yyval.pexpr) = new DefExpr(buildLambda((yyvsp[-5].pfnsymbol)));
    }
#line 6917 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 217:
#line 1107 "chapel.ypp" /* yacc.c:1661  */
    {
                  (yyval.pfnsymbol) = new FnSymbol("");

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 6928 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 218:
#line 1113 "chapel.ypp" /* yacc.c:1661  */
    {
                  (yyval.pfnsymbol) = new FnSymbol("");
                  (yyval.pfnsymbol)->addFlag(FLAG_INLINE);

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 6940 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 219:
#line 1120 "chapel.ypp" /* yacc.c:1661  */
    {
                  (yyval.pfnsymbol) = buildLinkageFn(FLAG_EXPORT, (yyvsp[0].pexpr));

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 6951 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 220:
#line 1126 "chapel.ypp" /* yacc.c:1661  */
    {
                  (yyval.pfnsymbol) = buildLinkageFn(FLAG_EXTERN, (yyvsp[0].pexpr));

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 6962 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 221:
#line 1132 "chapel.ypp" /* yacc.c:1661  */
    {
                  (yyval.pfnsymbol) = new FnSymbol("");
                  (yyval.pfnsymbol)->addFlag(FLAG_OVERRIDE);

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 6974 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 222:
#line 1143 "chapel.ypp" /* yacc.c:1661  */
    {
      // Sets up to capture tokens while parsing the next grammar nonterminal.
      captureTokens = 1;
      captureString.clear();
    }
#line 6984 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 223:
#line 1149 "chapel.ypp" /* yacc.c:1661  */
    {
      // Stop capturing and save the result.
      captureTokens = 0;

      (yyvsp[0].pfnsymbol)->userString = astr(captureString);
    }
#line 6995 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 224:
#line 1156 "chapel.ypp" /* yacc.c:1661  */
    {
      FnSymbol* fn = (yyvsp[-6].pfnsymbol);
      FnSymbol* linkageFn = (yyvsp[-9].pfnsymbol);

      fn->copyFlags((yyvsp[-9].pfnsymbol));
      if (*linkageFn->name)
        // The user explicitly named this function (controls mangling).
        fn->cname = linkageFn->name;
      else if (linkageFn->numFormals() == 1)
        // cname should be set based upon param
        fn->insertFormalAtTail(linkageFn->getFormal(1));

      if ((yyvsp[-8].procIter) == ProcIter_ITER)
      {
        if (fn->hasFlag(FLAG_EXTERN))
          USR_FATAL_CONT(fn, "'iter' is not legal with 'extern'");
        fn->addFlag(FLAG_ITERATOR_FN);
      }

      (yyval.pblockstmt) = buildFunctionDecl((yyvsp[-6].pfnsymbol), (yyvsp[-4].retTag), (yyvsp[-3].pexpr), (yyvsp[-2].b), (yyvsp[-1].lifetimeAndWhere).where, (yyvsp[-1].lifetimeAndWhere).lifetime, (yyvsp[0].pblockstmt), (yylsp[-9]).comment);
      context->latestComment = NULL;
    }
#line 7022 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 225:
#line 1182 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), (yyvsp[-1].pch), (yyvsp[-2].pt), NULL);
    }
#line 7030 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 226:
#line 1186 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), (yyvsp[-1].pch), (yyvsp[-2].pt), NULL);
      (yyval.pfnsymbol)->addFlag(FLAG_ASSIGNOP);
    }
#line 7039 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 227:
#line 1191 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), (yyvsp[-1].pch), (yyvsp[-4].pt), (yyvsp[-3].pexpr));
    }
#line 7047 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 228:
#line 1195 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), (yyvsp[-1].pch), (yyvsp[-4].pt), (yyvsp[-3].pexpr));
      (yyval.pfnsymbol)->addFlag(FLAG_ASSIGNOP);
    }
#line 7056 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 229:
#line 1200 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), "dummy", INTENT_BLANK, NULL);
    }
#line 7064 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 231:
#line 1207 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[-1].pexpr); }
#line 7070 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 232:
#line 1211 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 7076 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 233:
#line 1212 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = astr("~", (yyvsp[0].pch)); }
#line 7082 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 234:
#line 1213 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "&"; }
#line 7088 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 235:
#line 1214 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "|"; }
#line 7094 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 236:
#line 1215 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "^"; }
#line 7100 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 237:
#line 1216 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "~"; }
#line 7106 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 238:
#line 1217 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "=="; }
#line 7112 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 239:
#line 1218 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "!="; }
#line 7118 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 240:
#line 1219 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "<="; }
#line 7124 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 241:
#line 1220 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = ">="; }
#line 7130 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 242:
#line 1221 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "<"; }
#line 7136 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 243:
#line 1222 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = ">"; }
#line 7142 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 244:
#line 1223 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "+"; }
#line 7148 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 245:
#line 1224 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "-"; }
#line 7154 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 246:
#line 1225 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "*"; }
#line 7160 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 247:
#line 1226 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "/"; }
#line 7166 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 248:
#line 1227 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "<<"; }
#line 7172 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 249:
#line 1228 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = ">>"; }
#line 7178 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 250:
#line 1229 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "%"; }
#line 7184 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 251:
#line 1230 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "**"; }
#line 7190 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 252:
#line 1231 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "!"; }
#line 7196 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 253:
#line 1232 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "chpl_by"; }
#line 7202 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 254:
#line 1233 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "#"; }
#line 7208 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 255:
#line 1234 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "chpl_align"; }
#line 7214 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 256:
#line 1235 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "<=>"; }
#line 7220 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 257:
#line 1236 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "<~>"; }
#line 7226 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 258:
#line 1237 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "init="; }
#line 7232 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 259:
#line 1241 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "="; }
#line 7238 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 260:
#line 1242 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "+="; }
#line 7244 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 261:
#line 1243 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "-="; }
#line 7250 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 262:
#line 1244 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "*="; }
#line 7256 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 263:
#line 1245 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "/="; }
#line 7262 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 264:
#line 1246 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "%="; }
#line 7268 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 265:
#line 1247 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "**="; }
#line 7274 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 266:
#line 1248 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "&="; }
#line 7280 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 267:
#line 1249 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "|="; }
#line 7286 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 268:
#line 1250 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "^="; }
#line 7292 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 269:
#line 1251 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = ">>="; }
#line 7298 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 270:
#line 1252 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "<<="; }
#line 7304 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 271:
#line 1256 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pfnsymbol) = new FnSymbol("_"); (yyval.pfnsymbol)->addFlag(FLAG_NO_PARENS); }
#line 7310 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 272:
#line 1257 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pfnsymbol) = (yyvsp[-1].pfnsymbol); }
#line 7316 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 273:
#line 1261 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pfnsymbol) = (yyvsp[-1].pfnsymbol); }
#line 7322 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 274:
#line 1265 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pfnsymbol) = buildFunctionFormal(NULL, NULL); }
#line 7328 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 275:
#line 1266 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pfnsymbol) = buildFunctionFormal(NULL, (yyvsp[0].pdefexpr)); }
#line 7334 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 276:
#line 1267 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pfnsymbol) = buildFunctionFormal((yyvsp[-2].pfnsymbol), (yyvsp[0].pdefexpr)); }
#line 7340 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 277:
#line 1272 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = buildArgDefExpr((yyvsp[-3].pt), (yyvsp[-2].pch), (yyvsp[-1].pexpr), (yyvsp[0].pexpr), NULL); }
#line 7346 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 278:
#line 1274 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = buildPragmaDefExpr((yyvsp[-4].vpch), buildArgDefExpr((yyvsp[-3].pt), (yyvsp[-2].pch), (yyvsp[-1].pexpr), (yyvsp[0].pexpr), NULL)); }
#line 7352 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 279:
#line 1276 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = buildArgDefExpr((yyvsp[-3].pt), (yyvsp[-2].pch), (yyvsp[-1].pexpr), NULL, (yyvsp[0].pexpr)); }
#line 7358 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 280:
#line 1278 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = buildTupleArgDefExpr((yyvsp[-5].pt), (yyvsp[-3].pblockstmt), (yyvsp[-1].pexpr), (yyvsp[0].pexpr)); }
#line 7364 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 281:
#line 1280 "chapel.ypp" /* yacc.c:1661  */
    { USR_FATAL("variable-length argument may not be grouped in a tuple"); }
#line 7370 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 282:
#line 1284 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_BLANK; }
#line 7376 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 283:
#line 1285 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = (yyvsp[0].pt); }
#line 7382 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 284:
#line 1289 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_IN; }
#line 7388 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 285:
#line 1290 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_INOUT; }
#line 7394 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 286:
#line 1291 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_OUT; }
#line 7400 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 287:
#line 1292 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_CONST; }
#line 7406 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 288:
#line 1293 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_CONST_IN; }
#line 7412 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 289:
#line 1294 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_CONST_REF; }
#line 7418 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 290:
#line 1295 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_PARAM; }
#line 7424 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 291:
#line 1296 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_REF; }
#line 7430 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 292:
#line 1297 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_TYPE; }
#line 7436 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 293:
#line 1301 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_BLANK; }
#line 7442 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 294:
#line 1302 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_PARAM; }
#line 7448 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 295:
#line 1303 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_REF;   }
#line 7454 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 296:
#line 1304 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_CONST_REF;   }
#line 7460 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 297:
#line 1305 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_CONST;   }
#line 7466 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 298:
#line 1306 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_TYPE;  }
#line 7472 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 299:
#line 1310 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.procIter) = ProcIter_PROC; }
#line 7478 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 300:
#line 1311 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.procIter) = ProcIter_ITER; }
#line 7484 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 301:
#line 1315 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.retTag) = RET_VALUE; }
#line 7490 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 302:
#line 1316 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.retTag) = RET_VALUE; }
#line 7496 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 303:
#line 1317 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.retTag) = RET_CONST_REF; }
#line 7502 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 304:
#line 1318 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.retTag) = RET_REF; }
#line 7508 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 305:
#line 1319 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.retTag) = RET_PARAM; }
#line 7514 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 306:
#line 1320 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.retTag) = RET_TYPE; }
#line 7520 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 307:
#line 1324 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.b) = false; }
#line 7526 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 308:
#line 1325 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.b) = true;  }
#line 7532 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 309:
#line 1328 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = NULL; }
#line 7538 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 312:
#line 1334 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = new BlockStmt((yyvsp[0].pblockstmt)); }
#line 7544 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 313:
#line 1339 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = new DefExpr(new VarSymbol((yyvsp[0].pch))); }
#line 7550 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 314:
#line 1341 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = new DefExpr(new VarSymbol(astr("chpl__query", istr(query_uid++)))); }
#line 7556 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 315:
#line 1345 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = new DefExpr(new VarSymbol(astr("chpl__query", istr(query_uid++)))); }
#line 7562 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 317:
#line 1350 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 7568 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 318:
#line 1351 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[0].pdefexpr)->sym->addFlag(FLAG_PARAM); (yyval.pexpr) = (yyvsp[0].pdefexpr); }
#line 7574 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 319:
#line 1355 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.lifetimeAndWhere) = makeWhereAndLifetime(NULL, NULL); }
#line 7580 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 320:
#line 1357 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.lifetimeAndWhere) = makeWhereAndLifetime((yyvsp[0].pexpr), NULL); }
#line 7586 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 321:
#line 1359 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.lifetimeAndWhere) = makeWhereAndLifetime(NULL, (yyvsp[0].pexpr)); }
#line 7592 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 322:
#line 1361 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.lifetimeAndWhere) = makeWhereAndLifetime((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7598 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 323:
#line 1363 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.lifetimeAndWhere) = makeWhereAndLifetime((yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 7604 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 324:
#line 1367 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 7610 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 325:
#line 1368 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(",", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7616 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 326:
#line 1371 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7622 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 327:
#line 1372 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("<", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7628 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 328:
#line 1373 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("<=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7634 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 329:
#line 1374 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("==", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7640 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 330:
#line 1375 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(">", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7646 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 331:
#line 1376 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(">=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7652 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 332:
#line 1377 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(PRIM_RETURN, (yyvsp[0].pexpr)); }
#line 7658 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 333:
#line 1380 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(PRIM_LIFETIME_OF, new UnresolvedSymExpr((yyvsp[0].pch))); }
#line 7664 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 334:
#line 1381 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(PRIM_LIFETIME_OF, new UnresolvedSymExpr("this")); }
#line 7670 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 335:
#line 1385 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = (yyvsp[-1].pblockstmt); }
#line 7676 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 336:
#line 1387 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = handleConfigTypes((yyvsp[-1].pblockstmt)); }
#line 7682 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 337:
#line 1389 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = convertTypesToExtern((yyvsp[-1].pblockstmt)); }
#line 7688 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 338:
#line 1394 "chapel.ypp" /* yacc.c:1661  */
    {
      VarSymbol* var = new VarSymbol((yyvsp[-1].pch));

      var->addFlag(FLAG_TYPE_VARIABLE);

      var->doc               = context->latestComment;
      context->latestComment = NULL;

      DefExpr* def = new DefExpr(var, (yyvsp[0].pexpr));

      (yyval.pblockstmt) = buildChapelStmt(def);
    }
#line 7705 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 339:
#line 1407 "chapel.ypp" /* yacc.c:1661  */
    {
      VarSymbol* var = new VarSymbol((yyvsp[-3].pch));

      var->addFlag(FLAG_TYPE_VARIABLE);

      var->doc               = context->latestComment;
      context->latestComment = NULL;

      DefExpr* def = new DefExpr(var, (yyvsp[-2].pexpr));

      (yyvsp[0].pblockstmt)->insertAtHead(def);
      (yyval.pblockstmt) = buildChapelStmt((yyvsp[0].pblockstmt));
    }
#line 7723 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 340:
#line 1423 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 7729 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 341:
#line 1425 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 7735 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 342:
#line 1427 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForallLoopExprFromArrayType((yyvsp[0].pcallexpr)); }
#line 7741 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 343:
#line 1431 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pflagset) = buildVarDeclFlags(FLAG_PARAM); }
#line 7747 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 344:
#line 1432 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pflagset) = buildVarDeclFlags(FLAG_CONST); }
#line 7753 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 345:
#line 1433 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pflagset) = buildVarDeclFlags(FLAG_REF_VAR); }
#line 7759 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 346:
#line 1434 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pflagset) = buildVarDeclFlags(FLAG_CONST, FLAG_REF_VAR); }
#line 7765 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 347:
#line 1435 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pflagset) = buildVarDeclFlags(); }
#line 7771 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 348:
#line 1440 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyvsp[-2].pflagset)->insert(FLAG_CONFIG);
      (yyval.pblockstmt) = buildVarDecls((yyvsp[-1].pblockstmt), context->latestComment, (yyvsp[-2].pflagset));
      context->latestComment = NULL;
    }
#line 7781 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 349:
#line 1446 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyvsp[-2].pflagset)->insert(FLAG_EXTERN);
      (yyval.pblockstmt) = buildVarDecls((yyvsp[-1].pblockstmt), context->latestComment, (yyvsp[-2].pflagset), (yyvsp[-3].pexpr));
      context->latestComment = NULL;
    }
#line 7791 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 350:
#line 1452 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pblockstmt) = buildVarDecls((yyvsp[-1].pblockstmt), context->latestComment, (yyvsp[-2].pflagset));
      context->latestComment = NULL;
    }
#line 7800 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 352:
#line 1461 "chapel.ypp" /* yacc.c:1661  */
    {
      for_alist(expr, (yyvsp[0].pblockstmt)->body)
        (yyvsp[-2].pblockstmt)->insertAtTail(expr->remove());
    }
#line 7809 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 353:
#line 1469 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt(new DefExpr(new VarSymbol((yyvsp[-2].pch)), (yyvsp[0].pexpr), (yyvsp[-1].pexpr))); }
#line 7815 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 354:
#line 1471 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildTupleVarDeclStmt((yyvsp[-3].pblockstmt), (yyvsp[-1].pexpr), (yyvsp[0].pexpr)); }
#line 7821 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 355:
#line 1476 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new DefExpr(new VarSymbol("chpl__tuple_blank")); }
#line 7827 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 356:
#line 1478 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new DefExpr(new VarSymbol((yyvsp[0].pch))); }
#line 7833 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 357:
#line 1480 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[-1].pblockstmt); }
#line 7839 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 358:
#line 1485 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt((yyvsp[0].pexpr)); }
#line 7845 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 359:
#line 1487 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt((yyvsp[-1].pexpr)); }
#line 7851 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 360:
#line 1489 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ((yyvsp[0].pblockstmt)->insertAtHead((yyvsp[-2].pexpr)), (yyvsp[0].pblockstmt)); }
#line 7857 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 361:
#line 1495 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 7863 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 362:
#line 1496 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new SymExpr(gNoInit); }
#line 7869 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 363:
#line 1497 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 7875 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 364:
#line 1503 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, (yyvsp[0].pexpr)); }
#line 7881 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 365:
#line 1505 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, NULL); }
#line 7887 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 366:
#line 1507 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pexpr));
    }
#line 7895 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 367:
#line 1511 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-1].pcallexpr)), NULL);
    }
#line 7903 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 368:
#line 1515 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, (yyvsp[0].pexpr)); }
#line 7909 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 369:
#line 1517 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pexpr));
    }
#line 7917 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 370:
#line 1521 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pexpr) = new CallExpr(PRIM_ERROR);
    }
#line 7925 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 371:
#line 1528 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 7931 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 372:
#line 1529 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 7937 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 373:
#line 1530 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 7943 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 374:
#line 1531 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr((yyvsp[0].pch)); }
#line 7949 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 375:
#line 1532 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 7955 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 376:
#line 1537 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 7961 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 377:
#line 1538 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 7967 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 378:
#line 1539 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pcallexpr); }
#line 7973 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 379:
#line 1540 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr((yyvsp[0].pch)); }
#line 7979 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 380:
#line 1541 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 7985 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 381:
#line 1562 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pexpr));
    }
#line 7993 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 382:
#line 1566 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pcallexpr));
    }
#line 8001 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 383:
#line 1570 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pexpr), "invalid index expression");
      (yyval.pcallexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pexpr)), (yyvsp[0].pexpr), (yyvsp[-4].pcallexpr)->get(1)->remove(),
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pexpr)->copy()));
    }
#line 8013 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 384:
#line 1578 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pcallexpr) = new CallExpr(PRIM_ERROR);
    }
#line 8021 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 385:
#line 1584 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 8027 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 386:
#line 1585 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8033 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 387:
#line 1586 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pdefexpr); }
#line 8039 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 388:
#line 1591 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, (yyvsp[0].pexpr)); }
#line 8045 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 389:
#line 1593 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildFormalArrayType((yyvsp[-2].pcallexpr), (yyvsp[0].pexpr)); }
#line 8051 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 390:
#line 1599 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, (yyvsp[0].pexpr)); }
#line 8057 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 391:
#line 1601 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildFormalArrayType((yyvsp[-2].pcallexpr), (yyvsp[0].pexpr)); }
#line 8063 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 392:
#line 1603 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildFormalArrayType((yyvsp[-2].pexpr), (yyvsp[0].pexpr), (yyvsp[-4].pcallexpr)); }
#line 8069 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 393:
#line 1607 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 8075 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 394:
#line 1608 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8081 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 395:
#line 1609 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pdefexpr); }
#line 8087 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 396:
#line 1610 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr((yyvsp[0].pch)); }
#line 8093 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 397:
#line 1611 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8099 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 398:
#line 1617 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[0].pexpr)); }
#line 8105 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 399:
#line 1618 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[0].pdefexpr)); }
#line 8111 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 400:
#line 1619 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 8117 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 401:
#line 1620 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pdefexpr)); }
#line 8123 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 402:
#line 1624 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[0].pexpr));}
#line 8129 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 403:
#line 1625 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 8135 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 404:
#line 1629 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("chpl__tuple_blank"); }
#line 8141 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 405:
#line 1630 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8147 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 406:
#line 1631 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pdefexpr); }
#line 8153 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 407:
#line 1635 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8159 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 408:
#line 1636 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 8165 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 409:
#line 1640 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST); }
#line 8171 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 411:
#line 1645 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[0].pexpr)); }
#line 8177 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 412:
#line 1646 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 8183 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 413:
#line 1650 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildNamedActual((yyvsp[-2].pch), (yyvsp[0].pdefexpr)); }
#line 8189 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 414:
#line 1651 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildNamedActual((yyvsp[-2].pch), (yyvsp[0].pexpr)); }
#line 8195 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 415:
#line 1652 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pdefexpr); }
#line 8201 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 416:
#line 1653 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8207 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 417:
#line 1657 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr((yyvsp[0].pch)); }
#line 8213 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 418:
#line 1658 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8219 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 424:
#line 1675 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr( "_singlevar", (yyvsp[0].pexpr)); }
#line 8225 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 425:
#line 1677 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildIndexType", (yyvsp[-1].pcallexpr)); }
#line 8231 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 426:
#line 1679 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildDomainRuntimeType", new UnresolvedSymExpr("defaultDist"), (yyvsp[-1].pcallexpr)); }
#line 8237 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 427:
#line 1681 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildSubDomainType", (yyvsp[-1].pcallexpr)); }
#line 8243 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 428:
#line 1683 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildSparseDomainRuntimeType", buildDotExpr((yyvsp[-1].pcallexpr)->copy(), "defaultSparseDist"), (yyvsp[-1].pcallexpr)); }
#line 8249 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 429:
#line 1685 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__atomicType", (yyvsp[0].pexpr)); }
#line 8255 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 430:
#line 1687 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr( "_syncvar", (yyvsp[0].pexpr)); }
#line 8261 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 431:
#line 1689 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr( PRIM_TO_BORROWED_CLASS, (yyvsp[0].pexpr)); }
#line 8267 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 432:
#line 1691 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr( "_owned", (yyvsp[0].pexpr)); }
#line 8273 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 433:
#line 1693 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr( PRIM_TO_UNMANAGED_CLASS, (yyvsp[0].pexpr)); }
#line 8279 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 434:
#line 1695 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr( "_shared", (yyvsp[0].pexpr)); }
#line 8285 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 435:
#line 1700 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8291 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 436:
#line 1702 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[-4].pexpr), (yyvsp[-2].pcallexpr), (yyvsp[0].pexpr), NULL, false, true); }
#line 8297 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 437:
#line 1704 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForLoopExpr(NULL, (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8303 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 438:
#line 1706 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[-7].pexpr), (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 8309 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 439:
#line 1708 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[-7].pexpr), (yyvsp[-5].pcallexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr), false, true); }
#line 8315 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 440:
#line 1710 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForLoopExpr(NULL, (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 8321 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 441:
#line 1712 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8327 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 442:
#line 1714 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[-4].pexpr), (yyvsp[-2].pcallexpr), (yyvsp[0].pexpr), NULL, false, true); }
#line 8333 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 443:
#line 1716 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForallLoopExpr(NULL, (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8339 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 444:
#line 1718 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[-7].pexpr), (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 8345 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 445:
#line 1720 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[-7].pexpr), (yyvsp[-5].pcallexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr), false, true); }
#line 8351 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 446:
#line 1722 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForallLoopExpr(NULL, (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 8357 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 447:
#line 1724 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-2].pcallexpr)->argList.length > 1)
        (yyval.pexpr) = buildForallLoopExpr(NULL, new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pexpr), NULL, true);
      else
        (yyval.pexpr) = buildForallLoopExpr(NULL, (yyvsp[-2].pcallexpr)->get(1)->remove(), (yyvsp[0].pexpr), NULL, true);
    }
#line 8368 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 448:
#line 1731 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[-4].pcallexpr)->get(1)->remove(), (yyvsp[-2].pexpr), (yyvsp[0].pexpr), NULL, true);
    }
#line 8378 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 449:
#line 1737 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pcallexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[-4].pcallexpr)->get(1)->remove(), (yyvsp[-2].pcallexpr), (yyvsp[0].pexpr), NULL, false, true);
    }
#line 8388 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 450:
#line 1743 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-7].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-5].pexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[-7].pcallexpr)->get(1)->remove(), (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr));
    }
#line 8398 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 451:
#line 1749 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-7].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-5].pcallexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[-7].pcallexpr)->get(1)->remove(), (yyvsp[-5].pcallexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr), false, true);
    }
#line 8408 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 452:
#line 1758 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new IfExpr((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8414 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 453:
#line 1767 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new SymExpr(gNil); }
#line 8420 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 461:
#line 1783 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("<~>", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8426 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 462:
#line 1787 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = NULL; }
#line 8432 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 464:
#line 1792 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = (yyvsp[-1].pcallexpr); }
#line 8438 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 465:
#line 1796 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST); addTaskIntent((yyval.pcallexpr), (yyvsp[0].pShadowVar)); }
#line 8444 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 466:
#line 1797 "chapel.ypp" /* yacc.c:1661  */
    { addTaskIntent((yyvsp[-2].pcallexpr), (yyvsp[0].pShadowVar)); }
#line 8450 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 467:
#line 1801 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = (yyvsp[-1].pcallexpr); }
#line 8456 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 468:
#line 1805 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST); addForallIntent((yyval.pcallexpr), (yyvsp[0].pShadowVar)); }
#line 8462 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 469:
#line 1806 "chapel.ypp" /* yacc.c:1661  */
    { addForallIntent((yyvsp[-2].pcallexpr), (yyvsp[0].pShadowVar)); }
#line 8468 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 470:
#line 1811 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pShadowVar) = ShadowVarSymbol::buildForPrefix((yyvsp[-3].pShadowVarPref), (yyvsp[-2].pexpr), (yyvsp[-1].pexpr), (yyvsp[0].pexpr));
    }
#line 8476 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 471:
#line 1815 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pShadowVar) = ShadowVarSymbol::buildFromReduceIntent((yyvsp[0].pexpr), (yyvsp[-2].pexpr));
    }
#line 8484 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 472:
#line 1819 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pShadowVar) = ShadowVarSymbol::buildFromReduceIntent((yyvsp[0].pexpr), (yyvsp[-2].pexpr));
    }
#line 8492 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 473:
#line 1825 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pShadowVarPref) = SVP_CONST;     }
#line 8498 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 474:
#line 1826 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pShadowVarPref) = SVP_IN;        }
#line 8504 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 475:
#line 1827 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pShadowVarPref) = SVP_CONST_IN;  }
#line 8510 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 476:
#line 1828 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pShadowVarPref) = SVP_REF;       }
#line 8516 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 477:
#line 1829 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pShadowVarPref) = SVP_CONST_REF; }
#line 8522 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 478:
#line 1830 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pShadowVarPref) = SVP_VAR;       }
#line 8528 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 480:
#line 1836 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("<~>", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8534 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 481:
#line 1841 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(PRIM_NEW, (yyvsp[0].pexpr)); }
#line 8540 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 482:
#line 1846 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildLetExpr((yyvsp[-2].pblockstmt), (yyvsp[0].pexpr)); }
#line 8546 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 491:
#line 1862 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(PRIM_TUPLE_EXPAND, (yyvsp[-1].pexpr)); }
#line 8552 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 492:
#line 1864 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = createCast((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8558 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 493:
#line 1866 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("_to_borrowed", (yyvsp[-2].pexpr)); }
#line 8564 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 494:
#line 1868 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("_to_unmanaged", (yyvsp[-2].pexpr)); }
#line 8570 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 495:
#line 1870 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl_build_bounded_range", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8576 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 496:
#line 1872 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl_build_low_bounded_range", (yyvsp[-1].pexpr)); }
#line 8582 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 497:
#line 1874 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl_build_high_bounded_range", (yyvsp[0].pexpr)); }
#line 8588 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 498:
#line 1876 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl_build_unbounded_range"); }
#line 8594 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 499:
#line 1880 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 8600 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 500:
#line 1881 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8606 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 501:
#line 1884 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = tryExpr((yyvsp[0].pexpr)); }
#line 8612 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 502:
#line 1885 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = tryBangExpr((yyvsp[0].pexpr)); }
#line 8618 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 503:
#line 1886 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8624 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 510:
#line 1908 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr((yyvsp[-3].pexpr), (yyvsp[-1].pcallexpr)); }
#line 8630 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 511:
#line 1909 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildSquareCallExpr((yyvsp[-3].pexpr), (yyvsp[-1].pcallexpr)); }
#line 8636 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 512:
#line 1910 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildPrimitiveExpr((yyvsp[-1].pcallexpr)); }
#line 8642 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 513:
#line 1914 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildDotExpr((yyvsp[-2].pexpr), (yyvsp[0].pch)); }
#line 8648 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 514:
#line 1915 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(PRIM_TYPEOF, (yyvsp[-2].pexpr)); }
#line 8654 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 515:
#line 1916 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildDotExpr((yyvsp[-2].pexpr), "_dom"); }
#line 8660 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 516:
#line 1917 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildDotExpr((yyvsp[-2].pexpr), "locale"); }
#line 8666 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 517:
#line 1925 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[-1].pexpr); }
#line 8672 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 518:
#line 1926 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildOneTuple((yyvsp[-2].pexpr)); }
#line 8678 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 519:
#line 1927 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildTuple((yyvsp[-1].pcallexpr)); }
#line 8684 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 520:
#line 1928 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildTuple((yyvsp[-2].pcallexpr)); }
#line 8690 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 521:
#line 1932 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new SymExpr(gFalse); }
#line 8696 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 522:
#line 1933 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new SymExpr(gTrue); }
#line 8702 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 524:
#line 1938 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildIntLiteral((yyvsp[0].pch), yyfilename, chplLineno);    }
#line 8708 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 525:
#line 1939 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildRealLiteral((yyvsp[0].pch));   }
#line 8714 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 526:
#line 1940 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildImagLiteral((yyvsp[0].pch));   }
#line 8720 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 527:
#line 1941 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildStringLiteral((yyvsp[0].pch)); }
#line 8726 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 528:
#line 1942 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildCStringLiteral((yyvsp[0].pch)); }
#line 8732 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 529:
#line 1943 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildDomainExpr", (yyvsp[-1].pcallexpr)); }
#line 8738 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 530:
#line 1944 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildDomainExpr", (yyvsp[-2].pcallexpr)); }
#line 8744 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 531:
#line 1945 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayExpr",  (yyvsp[-1].pcallexpr)); }
#line 8750 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 532:
#line 1946 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayExpr",  (yyvsp[-2].pcallexpr)); }
#line 8756 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 533:
#line 1948 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pexpr) = new CallExpr("chpl__buildAssociativeArrayExpr", (yyvsp[-1].pcallexpr));
    }
#line 8764 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 534:
#line 1952 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pexpr) = new CallExpr("chpl__buildAssociativeArrayExpr", (yyvsp[-2].pcallexpr));
    }
#line 8772 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 535:
#line 1959 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8778 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 536:
#line 1960 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-4].pcallexpr)->insertAtTail((yyvsp[-2].pexpr)); (yyvsp[-4].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 8784 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 537:
#line 1964 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("+", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8790 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 538:
#line 1965 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("-", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8796 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 539:
#line 1966 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("*", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8802 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 540:
#line 1967 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("/", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8808 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 541:
#line 1968 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("<<", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8814 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 542:
#line 1969 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(">>", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8820 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 543:
#line 1970 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("%", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8826 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 544:
#line 1971 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("==", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8832 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 545:
#line 1972 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("!=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8838 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 546:
#line 1973 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("<=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8844 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 547:
#line 1974 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(">=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8850 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 548:
#line 1975 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("<", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8856 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 549:
#line 1976 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(">", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8862 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 550:
#line 1977 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("&", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8868 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 551:
#line 1978 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("|", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8874 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 552:
#line 1979 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("^", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8880 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 553:
#line 1980 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("&&", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8886 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 554:
#line 1981 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("||", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8892 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 555:
#line 1982 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("**", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8898 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 556:
#line 1983 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl_by", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8904 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 557:
#line 1984 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl_align", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8910 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 558:
#line 1985 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("#", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8916 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 559:
#line 1986 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__distributed", (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 8922 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 560:
#line 1990 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("+", (yyvsp[0].pexpr)); }
#line 8928 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 561:
#line 1991 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("-", (yyvsp[0].pexpr)); }
#line 8934 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 562:
#line 1992 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildPreDecIncWarning((yyvsp[0].pexpr), '-'); }
#line 8940 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 563:
#line 1993 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildPreDecIncWarning((yyvsp[0].pexpr), '+'); }
#line 8946 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 564:
#line 1994 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("!", (yyvsp[0].pexpr)); }
#line 8952 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 565:
#line 1995 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("~", (yyvsp[0].pexpr)); }
#line 8958 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 566:
#line 1999 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildReduceExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8964 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 567:
#line 2000 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildReduceExpr((yyvsp[-2].pexpr), (yyvsp[0].pcallexpr), true); }
#line 8970 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 568:
#line 2001 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildReduceExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8976 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 569:
#line 2002 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildReduceExpr((yyvsp[-2].pexpr), (yyvsp[0].pcallexpr), true); }
#line 8982 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 570:
#line 2006 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildScanExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8988 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 571:
#line 2007 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildScanExpr((yyvsp[-2].pexpr), (yyvsp[0].pcallexpr), true); }
#line 8994 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 572:
#line 2008 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildScanExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9000 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 573:
#line 2009 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildScanExpr((yyvsp[-2].pexpr), (yyvsp[0].pcallexpr), true); }
#line 9006 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 574:
#line 2014 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("SumReduceScanOp"); }
#line 9012 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 575:
#line 2015 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("ProductReduceScanOp"); }
#line 9018 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 576:
#line 2016 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("LogicalAndReduceScanOp"); }
#line 9024 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 577:
#line 2017 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("LogicalOrReduceScanOp"); }
#line 9030 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 578:
#line 2018 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("BitwiseAndReduceScanOp"); }
#line 9036 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 579:
#line 2019 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("BitwiseOrReduceScanOp"); }
#line 9042 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 580:
#line 2020 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("BitwiseXorReduceScanOp"); }
#line 9048 "bison-chapel.cpp" /* yacc.c:1661  */
    break;


#line 9052 "bison-chapel.cpp" /* yacc.c:1661  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, context, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (&yylloc, context, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, context);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, context);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, context, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, context);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, context);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  yyps->yynew = 1;

yypushreturn:
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
