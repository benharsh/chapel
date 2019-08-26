/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 1

/* Pull parsers.  */
#define YYPULL 0





# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
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
#line 32 "chapel.ypp" /* yacc.c:352  */

  #include <string>
  extern int         captureTokens;
  extern std::string captureString;
#line 45 "chapel.ypp" /* yacc.c:352  */

  #ifndef _BISON_CHAPEL_DEFINES_0_
  #define _BISON_CHAPEL_DEFINES_0_

  #define YYLEX_NEWLINE                  -1
  #define YYLEX_SINGLE_LINE_COMMENT      -2
  #define YYLEX_BLOCK_COMMENT            -3

  typedef void* yyscan_t;

  int processNewline(yyscan_t scanner);
  void stringBufferInit();

  #endif
#line 65 "chapel.ypp" /* yacc.c:352  */

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
#line 145 "chapel.ypp" /* yacc.c:352  */

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
#line 168 "chapel.ypp" /* yacc.c:352  */

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

#line 243 "bison-chapel.cpp" /* yacc.c:352  */

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
    TBYTES = 273,
    TCATCH = 274,
    TCLASS = 275,
    TCOBEGIN = 276,
    TCOFORALL = 277,
    TCOMPLEX = 278,
    TCONFIG = 279,
    TCONST = 280,
    TCONTINUE = 281,
    TDEFER = 282,
    TDELETE = 283,
    TDMAPPED = 284,
    TDO = 285,
    TDOMAIN = 286,
    TELSE = 287,
    TENUM = 288,
    TEXCEPT = 289,
    TEXPORT = 290,
    TEXTERN = 291,
    TFALSE = 292,
    TFOR = 293,
    TFORALL = 294,
    TFORWARDING = 295,
    TIF = 296,
    TIMAG = 297,
    TIN = 298,
    TINDEX = 299,
    TINLINE = 300,
    TINOUT = 301,
    TINT = 302,
    TITER = 303,
    TINITEQUALS = 304,
    TLABEL = 305,
    TLAMBDA = 306,
    TLET = 307,
    TLIFETIME = 308,
    TLOCAL = 309,
    TLOCALE = 310,
    TMINUSMINUS = 311,
    TMODULE = 312,
    TNEW = 313,
    TNIL = 314,
    TNOINIT = 315,
    TNONE = 316,
    TNOTHING = 317,
    TON = 318,
    TONLY = 319,
    TOTHERWISE = 320,
    TOUT = 321,
    TOVERRIDE = 322,
    TOWNED = 323,
    TPARAM = 324,
    TPLUSPLUS = 325,
    TPRAGMA = 326,
    TPRIMITIVE = 327,
    TPRIVATE = 328,
    TPROC = 329,
    TPROTOTYPE = 330,
    TPUBLIC = 331,
    TREAL = 332,
    TRECORD = 333,
    TREDUCE = 334,
    TREF = 335,
    TREQUIRE = 336,
    TRETURN = 337,
    TSCAN = 338,
    TSELECT = 339,
    TSERIAL = 340,
    TSHARED = 341,
    TSINGLE = 342,
    TSPARSE = 343,
    TSTRING = 344,
    TSUBDOMAIN = 345,
    TSYNC = 346,
    TTHEN = 347,
    TTHIS = 348,
    TTHROW = 349,
    TTHROWS = 350,
    TTRUE = 351,
    TTRY = 352,
    TTRYBANG = 353,
    TTYPE = 354,
    TUINT = 355,
    TUNDERSCORE = 356,
    TUNION = 357,
    TUNMANAGED = 358,
    TUSE = 359,
    TVAR = 360,
    TVOID = 361,
    TWHEN = 362,
    TWHERE = 363,
    TWHILE = 364,
    TWITH = 365,
    TYIELD = 366,
    TZIP = 367,
    TALIAS = 368,
    TAND = 369,
    TASSIGN = 370,
    TASSIGNBAND = 371,
    TASSIGNBOR = 372,
    TASSIGNBXOR = 373,
    TASSIGNDIVIDE = 374,
    TASSIGNEXP = 375,
    TASSIGNLAND = 376,
    TASSIGNLOR = 377,
    TASSIGNMINUS = 378,
    TASSIGNMOD = 379,
    TASSIGNMULTIPLY = 380,
    TASSIGNPLUS = 381,
    TASSIGNREDUCE = 382,
    TASSIGNSL = 383,
    TASSIGNSR = 384,
    TBANG = 385,
    TBAND = 386,
    TBNOT = 387,
    TBOR = 388,
    TBXOR = 389,
    TCOLON = 390,
    TCOMMA = 391,
    TDIVIDE = 392,
    TDOT = 393,
    TDOTDOT = 394,
    TDOTDOTDOT = 395,
    TEQUAL = 396,
    TEXP = 397,
    TGREATER = 398,
    TGREATEREQUAL = 399,
    THASH = 400,
    TIO = 401,
    TLESS = 402,
    TLESSEQUAL = 403,
    TMINUS = 404,
    TMOD = 405,
    TNOTEQUAL = 406,
    TOR = 407,
    TPLUS = 408,
    TQUESTION = 409,
    TSEMI = 410,
    TSHIFTLEFT = 411,
    TSHIFTRIGHT = 412,
    TSTAR = 413,
    TSWAP = 414,
    TLCBR = 415,
    TRCBR = 416,
    TLP = 417,
    TRP = 418,
    TLSBR = 419,
    TRSBR = 420,
    TNOELSE = 421,
    TUPLUS = 422,
    TUMINUS = 423
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
#line 199 "chapel.ypp" /* yacc.c:352  */

  extern int yydebug;

  void yyerror(YYLTYPE*       ignored,
               ParserContext* context,
               const char*    str);

#line 457 "bison-chapel.cpp" /* yacc.c:352  */

#endif /* !YY_YY_INCLUDE_BISON_CHAPEL_H_INCLUDED  */


/* Unqualified %code blocks.  */
#line 38 "chapel.ypp" /* yacc.c:355  */

  #include <string>
  int         captureTokens;
  std::string captureString;
#line 207 "chapel.ypp" /* yacc.c:355  */

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

#line 533 "bison-chapel.cpp" /* yacc.c:355  */

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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYLAST   18049

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  169
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  140
/* YYNRULES -- Number of rules.  */
#define YYNRULES  603
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1081

#define YYUNDEFTOK  2
#define YYMAXUTOK   423

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
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
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   490,   490,   495,   496,   502,   503,   508,   509,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   547,
     560,   565,   570,   578,   579,   580,   584,   585,   598,   599,
     600,   605,   606,   611,   616,   621,   625,   632,   637,   641,
     646,   650,   651,   652,   656,   657,   658,   662,   666,   668,
     670,   672,   674,   681,   682,   686,   687,   688,   689,   690,
     691,   694,   695,   696,   697,   698,   699,   711,   712,   723,
     724,   725,   726,   727,   728,   729,   730,   731,   732,   733,
     734,   735,   736,   737,   738,   739,   740,   741,   745,   746,
     747,   748,   749,   750,   751,   752,   753,   754,   755,   762,
     763,   764,   765,   775,   776,   780,   781,   785,   786,   787,
     788,   792,   793,   794,   795,   796,   797,   798,   802,   803,
     804,   805,   809,   819,   829,   839,   850,   854,   859,   865,
     874,   881,   882,   883,   884,   885,   886,   887,   888,   889,
     890,   891,   892,   893,   894,   895,   896,   897,   898,   899,
     905,   911,   917,   923,   930,   937,   941,   948,   952,   953,
     954,   955,   956,   958,   960,   962,   967,   970,   971,   972,
     973,   974,   975,   979,   980,   984,   985,   986,   990,   991,
     995,   998,  1000,  1005,  1006,  1010,  1012,  1014,  1021,  1031,
    1045,  1050,  1055,  1063,  1064,  1069,  1070,  1072,  1077,  1093,
    1100,  1109,  1117,  1121,  1128,  1129,  1134,  1139,  1133,  1166,
    1172,  1179,  1190,  1196,  1189,  1228,  1232,  1237,  1241,  1246,
    1253,  1254,  1258,  1259,  1260,  1261,  1262,  1263,  1264,  1265,
    1266,  1267,  1268,  1269,  1270,  1271,  1272,  1273,  1274,  1275,
    1276,  1277,  1278,  1279,  1280,  1281,  1282,  1283,  1284,  1285,
    1289,  1290,  1291,  1292,  1293,  1294,  1295,  1296,  1297,  1298,
    1299,  1300,  1304,  1305,  1309,  1313,  1314,  1315,  1319,  1321,
    1323,  1325,  1327,  1332,  1333,  1337,  1338,  1339,  1340,  1341,
    1342,  1343,  1344,  1345,  1349,  1350,  1351,  1352,  1353,  1354,
    1358,  1359,  1363,  1364,  1365,  1366,  1367,  1368,  1372,  1373,
    1376,  1377,  1381,  1382,  1386,  1388,  1393,  1394,  1398,  1399,
    1407,  1408,  1410,  1412,  1414,  1419,  1420,  1423,  1424,  1425,
    1426,  1427,  1428,  1429,  1432,  1433,  1436,  1438,  1440,  1445,
    1458,  1475,  1476,  1478,  1483,  1484,  1485,  1486,  1487,  1491,
    1497,  1505,  1506,  1514,  1516,  1521,  1523,  1525,  1530,  1532,
    1534,  1541,  1542,  1543,  1548,  1550,  1552,  1556,  1560,  1562,
    1566,  1574,  1575,  1576,  1577,  1578,  1583,  1584,  1585,  1586,
    1587,  1607,  1611,  1615,  1623,  1630,  1631,  1632,  1636,  1638,
    1644,  1646,  1648,  1653,  1654,  1655,  1656,  1657,  1663,  1664,
    1665,  1666,  1670,  1671,  1675,  1676,  1677,  1681,  1682,  1686,
    1687,  1691,  1692,  1696,  1697,  1698,  1699,  1703,  1704,  1715,
    1717,  1725,  1726,  1727,  1728,  1729,  1730,  1732,  1734,  1736,
    1738,  1740,  1742,  1745,  1747,  1749,  1751,  1753,  1755,  1757,
    1759,  1762,  1764,  1766,  1772,  1774,  1776,  1778,  1780,  1782,
    1784,  1786,  1788,  1790,  1792,  1794,  1796,  1803,  1809,  1815,
    1821,  1830,  1840,  1848,  1849,  1850,  1851,  1852,  1853,  1854,
    1855,  1860,  1861,  1865,  1869,  1870,  1874,  1878,  1879,  1883,
    1887,  1891,  1898,  1899,  1900,  1901,  1902,  1903,  1907,  1908,
    1913,  1918,  1926,  1927,  1928,  1929,  1930,  1931,  1932,  1933,
    1934,  1936,  1938,  1940,  1942,  1944,  1949,  1950,  1953,  1954,
    1955,  1958,  1959,  1960,  1961,  1972,  1973,  1974,  1978,  1979,
    1980,  1984,  1985,  1986,  1987,  1988,  1996,  1997,  1998,  1999,
    2003,  2004,  2008,  2009,  2010,  2011,  2012,  2013,  2014,  2015,
    2016,  2017,  2018,  2019,  2023,  2031,  2032,  2036,  2037,  2038,
    2039,  2040,  2041,  2042,  2043,  2044,  2045,  2046,  2047,  2048,
    2049,  2050,  2051,  2052,  2053,  2054,  2055,  2056,  2057,  2058,
    2059,  2060,  2064,  2065,  2066,  2067,  2068,  2069,  2070,  2074,
    2075,  2076,  2077,  2081,  2082,  2083,  2084,  2089,  2090,  2091,
    2092,  2093,  2094,  2095
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
  "TBYTES", "TCATCH", "TCLASS", "TCOBEGIN", "TCOFORALL", "TCOMPLEX",
  "TCONFIG", "TCONST", "TCONTINUE", "TDEFER", "TDELETE", "TDMAPPED", "TDO",
  "TDOMAIN", "TELSE", "TENUM", "TEXCEPT", "TEXPORT", "TEXTERN", "TFALSE",
  "TFOR", "TFORALL", "TFORWARDING", "TIF", "TIMAG", "TIN", "TINDEX",
  "TINLINE", "TINOUT", "TINT", "TITER", "TINITEQUALS", "TLABEL", "TLAMBDA",
  "TLET", "TLIFETIME", "TLOCAL", "TLOCALE", "TMINUSMINUS", "TMODULE",
  "TNEW", "TNIL", "TNOINIT", "TNONE", "TNOTHING", "TON", "TONLY",
  "TOTHERWISE", "TOUT", "TOVERRIDE", "TOWNED", "TPARAM", "TPLUSPLUS",
  "TPRAGMA", "TPRIMITIVE", "TPRIVATE", "TPROC", "TPROTOTYPE", "TPUBLIC",
  "TREAL", "TRECORD", "TREDUCE", "TREF", "TREQUIRE", "TRETURN", "TSCAN",
  "TSELECT", "TSERIAL", "TSHARED", "TSINGLE", "TSPARSE", "TSTRING",
  "TSUBDOMAIN", "TSYNC", "TTHEN", "TTHIS", "TTHROW", "TTHROWS", "TTRUE",
  "TTRY", "TTRYBANG", "TTYPE", "TUINT", "TUNDERSCORE", "TUNION",
  "TUNMANAGED", "TUSE", "TVAR", "TVOID", "TWHEN", "TWHERE", "TWHILE",
  "TWITH", "TYIELD", "TZIP", "TALIAS", "TAND", "TASSIGN", "TASSIGNBAND",
  "TASSIGNBOR", "TASSIGNBXOR", "TASSIGNDIVIDE", "TASSIGNEXP",
  "TASSIGNLAND", "TASSIGNLOR", "TASSIGNMINUS", "TASSIGNMOD",
  "TASSIGNMULTIPLY", "TASSIGNPLUS", "TASSIGNREDUCE", "TASSIGNSL",
  "TASSIGNSR", "TBANG", "TBAND", "TBNOT", "TBOR", "TBXOR", "TCOLON",
  "TCOMMA", "TDIVIDE", "TDOT", "TDOTDOT", "TDOTDOTDOT", "TEQUAL", "TEXP",
  "TGREATER", "TGREATEREQUAL", "THASH", "TIO", "TLESS", "TLESSEQUAL",
  "TMINUS", "TMOD", "TNOTEQUAL", "TOR", "TPLUS", "TQUESTION", "TSEMI",
  "TSHIFTLEFT", "TSHIFTRIGHT", "TSTAR", "TSWAP", "TLCBR", "TRCBR", "TLP",
  "TRP", "TLSBR", "TRSBR", "TNOELSE", "TUPLUS", "TUMINUS", "$accept",
  "program", "toplevel_stmt_ls", "toplevel_stmt", "pragma_ls", "stmt",
  "module_decl_start", "module_decl_stmt", "access_control",
  "opt_prototype", "block_stmt", "stmt_ls", "only_ls", "opt_only_ls",
  "except_ls", "use_access_control", "use_stmt", "require_stmt",
  "assignment_stmt", "opt_label_ident", "ident_fn_def", "ident_def",
  "ident_use", "internal_type_ident_def", "scalar_type",
  "reserved_type_ident_use", "do_stmt", "return_stmt", "class_level_stmt",
  "private_decl", "forwarding_stmt", "extern_export_decl_stmt",
  "extern_block_stmt", "loop_stmt", "zippered_iterator", "if_stmt",
  "defer_stmt", "try_stmt", "catch_stmt_ls", "catch_stmt", "catch_expr",
  "throw_stmt", "select_stmt", "when_stmt_ls", "when_stmt",
  "class_decl_stmt", "class_tag", "opt_inherit", "class_level_stmt_ls",
  "enum_decl_stmt", "enum_header", "enum_ls", "enum_item",
  "lambda_decl_expr", "$@1", "$@2", "linkage_spec", "fn_decl_stmt", "$@3",
  "$@4", "fn_decl_stmt_inner", "fn_decl_receiver_expr", "fn_ident",
  "assignop_ident", "opt_formal_ls", "req_formal_ls", "formal_ls",
  "formal", "opt_intent_tag", "required_intent_tag", "opt_this_intent_tag",
  "proc_or_iter", "opt_ret_tag", "opt_throws_error",
  "opt_function_body_stmt", "function_body_stmt", "query_expr",
  "opt_query_expr", "var_arg_expr", "opt_lifetime_where",
  "lifetime_components_expr", "lifetime_expr", "lifetime_ident",
  "type_alias_decl_stmt", "type_alias_decl_stmt_inner", "opt_init_type",
  "var_decl_type", "var_decl_stmt", "var_decl_stmt_inner_ls",
  "var_decl_stmt_inner", "tuple_var_decl_component",
  "tuple_var_decl_stmt_inner_ls", "opt_init_expr", "ret_array_type",
  "opt_ret_type", "opt_type", "array_type", "opt_formal_array_elt_type",
  "formal_array_type", "opt_formal_type", "expr_ls", "simple_expr_ls",
  "tuple_component", "tuple_expr_ls", "opt_actual_ls", "actual_ls",
  "actual_expr", "ident_expr", "type_level_expr", "sub_type_level_expr",
  "for_expr", "cond_expr", "nil_expr", "stmt_level_expr",
  "opt_task_intent_ls", "task_intent_clause", "task_intent_ls",
  "forall_intent_clause", "forall_intent_ls", "intent_expr",
  "shadow_var_prefix", "io_expr", "new_expr", "let_expr", "expr",
  "opt_expr", "opt_try_expr", "lhs_expr", "fun_expr", "call_expr",
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
     415,   416,   417,   418,   419,   420,   421,   422,   423
};
# endif

#define YYPACT_NINF -941

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-941)))

#define YYTABLE_NINF -552

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -941,   103,  2716,  -941,   -92,  -941,  -941,  -941,  -941,  -941,
    -941,  4177,    16,   132,  -941, 13179,  -941, 15355,    16, 10163,
    -941,   167,    93,   132,  4177, 10163,  4177,    57, 16587, 10325,
    7895,  -941,  8057,  8705,  6448, 10163,  -941,    86,  -941,  -941,
   16763,  -941, 13597,  8867,  -941, 10163, 10163,  -941,  -941,  -941,
   10163,  -941, 13179,  -941, 10163,   252,   123,  1378,  2444,  -941,
   17943,  -941,  9029,  7409, 10163,  8867, 13179, 10163,   211,  -941,
     152,  4177,  -941, 10163,  -941, 10487, 10487, 16763,  -941,  -941,
   13179,  -941,  -941, 10163, 10163,  -941, 10163,  -941, 10163,  -941,
    -941, 12755, 10163,  -941, 10163,  -941,  -941,  3205,  6610,  8219,
    -941,  4015,  -941,   238,  -941,   355,  -941,   318,  -941,  -941,
    -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,
    -941,  -941,  -941,  -941,  -941,  -941, 16763,  -941, 16763,   347,
      63,  -941,  -941, 13597,  -941,   281,  -941,   288,  -941,  -941,
     294,   295,   313,   322,   327, 17455, 12750,   143,   330,   331,
    -941,  -941,  -941,  -941,  -941,  -941,  -941,   182,  -941,  -941,
   17455,   311,  4177,  -941,  -941,   338, 10163,  -941,  -941, 10163,
   10163, 10163,  -941, 10163,  9029,  9029,   210,  -941,  -941,  -941,
    -941,   367,   228,  -941,  -941,   348, 15428, 16763, 13597,  -941,
     364,  -941,    80, 17455,   412,  7571,   432, 16763, 17455,   378,
     444,  -941, 16763, 16763,   378, 16763,   369,    52, 14962,    28,
   14930,   184,  -941, 15371, 14178,  7571,  -941,  -941,  -941,  -941,
    -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,
    -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,
    4177,  -941,   371,  2571,    46,     6,  -941,  4177,  -941,  -941,
   15106,   662,   367, 15106,   367,   662,  -941,  7571,  -941,  -941,
    9191,  -941,  -941,  -941, 16763,  -941,    97, 17455, 10163, 10163,
    -941, 17455,   374, 15339,  -941, 15106,   367, 17455,   373,  7571,
    -941, 17455, 15515,  -941,  -941, 15780, 13044,  -941,  -941, 15829,
     426,   389,   367, 15106, 15924,   365,   365,  2123,   662,   662,
     -36,  -941,  -941,  3367,   248,  -941, 10163,  -941,   104,   106,
    -941,   -42,   -12, 15973,   -52,   538,  -941,  3529,  -941,   497,
    9029,   420,   404,  -941,  -941,  -941,   147,  -941,  -941, 10163,
   10163, 10163, 10163,  8705,  8705, 10163,   314, 10163, 10163, 10163,
   10163, 10163,   358, 12755,  9353, 10163, 10163, 10163, 10163, 10163,
   10163, 10163, 10163,  9515, 10163, 10163, 10163, 10163, 10163,  -941,
    -941,  -941,  -941,  -941,  -941,  8381,  8381,  -941,  -941,  -941,
    -941,  8381,  -941,  -941,  8381,  8381,  7571,  7571,  8705,  8705,
    7096,  -941,  -941, 15572, 15604, 16005,    18,  3691,  -941,  8705,
      52,   406,   158,  -941, 10163,  -941, 10163,   450,  -941,   408,
     431,  -941,  -941, 16763,   420,  -941, 13597, 16763,   420,   414,
    -941, 13597,   530,  9029,  -941,  4339,  8705,  -941,   415,  -941,
      52,  4501,  8705,  -941,    52, 10649, 10163,  -941,  4177,   542,
   10163,   417,  -941,   709,  -941,  -941,  2571,  -941,   447,   421,
    -941, 10811,   470, 10163, 13597,  -941,  -941,  -941,   423,  -941,
    9029,  -941, 17455, 17455,  -941,    25,  -941,  7571,   427,  -941,
     575,  -941,   575,  -941, 10973,   461,  -941,  -941,  -941,  -941,
    -941,  -941,  8543,  -941, 14034,  6772,  -941,  6934,  -941,  4177,
     433,  8705,  5959,  3043,   436, 10163,  6285,  -941,  -941,    90,
    -941,  3853, 16763,   160, 15748,  9029,   449, 17886,   193,  -941,
   16149, 17695, 17695,   401,  -941,   401,  -941,   401, 13844,   684,
    1231,   496,   367,   365,   446,  -941,  -941,  -941,  -941,  2123,
    -941, 16968,   401,  1970,  1970, 17695,  1970,  1970,  1151,   365,
    -941, 16968, 17735,  1151,   662,   662,   365,   452,   455,   456,
     460,   462,   453,   454,  -941,   401,  -941,   401,    96,  -941,
    -941,  -941,   162,  -941,   945, 17531,   220, 11135,  8705, 11297,
    8705, 10163,  8705, 13439,    16, 16194,  -941,  -941,  -941, 17455,
   16235,  7571,  -941,  7571,   420,   463,   265,   420,   464,  -941,
     272, 10163,   195, 10163, 17455,    64, 15163,  7096,  -941, 10163,
   17455,    65, 15019,  -941,   465,   486,   473, 16346,   486,   474,
     593, 16386,  4177, 15195,  -941,   194,  -941,  -941,  -941,  -941,
    -941,  -941,   859,   212,  -941, 13654,  -941,   207,   469,  2571,
      46,    57,    86, 10163, 10163,  5797,  -941,  -941,   708,  7733,
    -941, 17455,  -941,  -941,  -941, 17455,   476,    50,   472,  -941,
   13518,  -941,  -941,   285, 16763,  -941,  -941,  -941,  -941,  -941,
    -941,  -941,  4177,   -34, 13802,  -941,  -941, 17455,  4177, 17455,
    -941, 16427,  -941,  -941,  -941,  -941, 10649, 10163,   503,  1541,
     479,   527,   270,  -941,   564,  -941,  -941,  -941,  -941,  7249,
     484,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,
    7096,  -941,    35,  8705,  8705, 10163,   618, 16571, 10163,   619,
   16603,   492, 13890,    52,    52,  -941,  -941,  -941,  -941,   498,
    -941,  -941,   502,  -941,  -941, 15106,  -941, 14254,  4663,  -941,
    4825,  -941,   216,  -941, 14330,  4987,  -941,    52,  5149,  -941,
      52, 10163,  -941, 10163,  -941,  4177, 10163,  -941,  4177,   632,
    -941,  -941, 16763,   981,  -941,  2571,   531,   587,  -941,  -941,
    -941,    39,  -941,  -941,   470,   504,    31,  -941,  -941,  -941,
    5311,  9029,  -941,  -941,  -941, 16763,  -941,   533,   348,  -941,
    -941,  5473,   505,  5635,   506,  -941, 10163,   517,   518,   513,
    1849,  -941, 10163, 16763,  -941,  -941,   207,   514,   -33,  -941,
     537,  -941,   539,   540,   550,   551,   554,  -941,   555,   565,
     559,   561,   562,   -26,   571,   570,   573,  -941,  -941, 16763,
    -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,
    -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941, 10163,
    -941,   572,   582,   577,   514,   514,  -941,  -941,  -941,   470,
     217,   223, 16747, 11459, 11621, 16779, 11783, 11945, 12107, 12269,
    -941,  -941,  -941,  2339,  -941, 16160,  -941,  4177, 10163, 17455,
   10163, 17455,  7096,  -941,  4177, 10163, 17455,  -941, 10163, 17455,
    -941, 16836, 17455,  -941, 17455,   671,  4177,   531,  -941,   553,
    9677,   341,  -941,    43,  -941,  -941,  8705, 13309,  4177,  -941,
      69,   556, 10163,  -941, 10163,  -941, 17455,  4177, 10163,  -941,
   17455,  4177, 17455,  -941,  -941,  -941,  7254,  7254,  -941,  1752,
    -941, 17455,  -941,   115,   709,  -941,  -941, 14091,  -941, 13746,
    -941,  -941,  -941, 10163, 10163, 10163, 10163, 10163, 10163, 10163,
   10163, 17666,  -941, 17680,  -941, 16386, 14406, 14482,  -941, 16386,
   14558, 14634, 10163,  4177,  -941,   470,   531,  6122,  -941,  -941,
    -941,   255,  9029,  -941,  -941,    47, 10163,    70, 13947,  -941,
     929,   412,  -941,   348, 17455, 14710,  -941, 14786,  -941,  -941,
    -941, 12431,   623,   237,  -941,   591,   594,   514,   514, 16923,
   16999, 17075, 17151, 17227, 17303,  -941,  -941,  4177,  4177,  4177,
    4177, 17455,  -941,  -941,   341,  9839,    66,  -941,  -941, 17455,
    -941,    56,  -941,    58,  -941,   448, 17379,  -941,  -941,  -941,
   12269,  -941,  4177,  4177,  2878,  -941,  -941,   202,  -941,    43,
    -941,  -941,  -941, 10163, 10163, 10163, 10163, 10163, 10163, 16386,
   16386, 16386, 16386,  -941,  -941,  -941,  -941,  -941,   297,  8705,
   12887,  -941, 10163,    47,    56,    56,    56,    56,    56,    56,
      47,   989, 16386, 16386,   563, 12593,    79,    83, 13988,  -941,
    -941, 17455,  -941,  -941,  -941,  -941,  -941,  -941,  -941,   595,
    -941,  -941,   346, 13049,  -941,  -941,  -941, 10001,  -941,   445,
    -941
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       3,     0,     0,     1,     0,    87,   543,   544,   545,   546,
     547,     0,   481,    73,   108,   449,   114,   451,   481,     0,
     113,     0,   355,    73,     0,     0,     0,     0,   453,   516,
     516,   540,     0,     0,     0,     0,   112,     0,   230,   109,
       0,   226,     0,     0,   116,     0,     0,   472,   548,   117,
       0,   231,   443,   354,     0,     0,     0,    45,    44,   111,
     452,   356,     0,     0,     0,     0,   447,     0,     0,   115,
       0,     0,    88,     0,   541,     0,     0,     0,   110,   212,
     445,   358,   118,     0,     0,   599,     0,   601,     0,   602,
     603,   515,     0,   600,   597,   127,   598,     0,     0,     0,
       4,     0,     5,     0,     9,    46,    10,     0,    11,    12,
      14,   427,   428,    22,    13,   128,   136,   137,    15,    17,
      16,    19,    20,    21,    18,   135,     0,   133,     0,   507,
       0,   131,   134,     0,   132,   521,   503,   429,   504,   433,
     431,     0,     0,   508,   509,     0,   432,     0,   522,   523,
     524,   542,   502,   435,   434,   505,   506,     0,    38,    24,
     441,     0,     0,   482,    74,     0,     0,   451,   453,     0,
       0,     0,   452,     0,     0,     0,   507,   521,   431,   508,
     509,   450,   432,   522,   523,     0,   481,     0,     0,   357,
       0,   186,     0,   412,     0,   419,   546,   452,   517,   229,
     546,   150,   452,     0,   229,     0,     0,     0,     0,     0,
       0,     0,   141,     0,     0,   419,    81,    89,   101,    95,
      94,   103,    84,    93,   104,    90,   105,    82,   106,    99,
      92,   100,    98,    96,    97,    83,    85,    91,   102,   107,
       0,    86,     0,     0,     0,     0,   361,     0,   124,    32,
       0,   584,   500,     0,   444,   585,     7,   419,   210,   220,
     516,   211,   130,   129,   325,   409,     0,   408,     0,     0,
     125,   520,     0,     0,    35,     0,   448,   436,     0,   419,
      36,   442,     0,   193,   189,     0,   432,   193,   190,     0,
     351,     0,   446,     0,     0,   586,   588,   514,   583,   582,
       0,    48,    51,     0,     0,   414,     0,   416,     0,     0,
     415,     0,     0,   408,     0,     0,     6,     0,    47,     0,
       0,   213,     0,   311,   310,   232,     0,   430,    23,     0,
       0,     0,     0,     0,     0,     0,   587,     0,     0,     0,
       0,     0,     0,   513,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   270,
     277,   278,   279,   274,   276,     0,     0,   272,   275,   273,
     271,     0,   281,   280,     0,     0,   419,   419,     0,     0,
       0,    25,    26,     0,     0,     0,     0,     0,    27,     0,
       0,     0,     0,    28,     0,    29,     0,   427,   425,     0,
     420,   421,   426,     0,   213,   147,     0,     0,   213,     0,
     146,     0,     0,     0,   159,     0,     0,   158,     0,   167,
       0,     0,     0,   165,     0,     0,    57,   138,     0,   179,
       0,     0,    30,   293,   227,   365,     0,   366,   368,     0,
     390,     0,   371,     0,     0,   123,    31,    33,     0,   324,
       0,    67,   518,   519,   126,     0,    34,   419,     0,   200,
     191,   187,   192,   188,     0,   349,   346,   152,    37,    50,
      49,    52,     0,   549,     0,     0,   536,     0,   538,     0,
       0,     0,     0,     0,     0,     0,     0,   553,     8,     0,
      40,     0,     0,     0,   408,     0,     0,     0,   304,   360,
     480,   579,   578,   581,   590,   589,   594,   593,   575,   572,
     573,   574,   511,   560,     0,   533,   534,   532,   531,   512,
     565,   564,   577,   571,   569,   580,   570,   568,   558,   563,
     567,   566,   576,   557,   561,   562,   559,     0,     0,     0,
       0,     0,     0,     0,   592,   591,   596,   595,   492,   493,
     495,   497,     0,   484,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   551,   481,   481,   155,   347,   359,   413,
       0,     0,   438,     0,   213,     0,     0,   213,     0,   348,
       0,     0,     0,     0,   456,     0,     0,     0,   168,     0,
     462,     0,     0,   166,   598,    60,     0,    53,    58,     0,
     178,     0,     0,     0,   437,   298,   295,   296,   297,   301,
     302,   303,   293,     0,   286,     0,   294,   312,     0,   369,
       0,   121,   122,   120,   119,     0,   389,   388,   503,     0,
     363,   501,   362,   530,   411,   410,     0,     0,     0,   439,
       0,   194,   353,   503,     0,   550,   510,   537,   417,   539,
     418,   175,     0,     0,     0,   552,   173,   466,     0,   555,
     554,     0,    42,    41,    39,    64,     0,    57,   214,     0,
       0,   224,     0,   221,   308,   305,   306,   309,   233,     0,
       0,    71,    72,    70,    69,    68,   528,   529,   494,   496,
       0,   483,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   151,   423,   424,   422,     0,
     215,   149,     0,   215,   148,     0,   177,     0,     0,   157,
       0,   156,     0,   487,     0,     0,   163,     0,     0,   161,
       0,     0,   139,     0,   140,     0,     0,   181,     0,   183,
     299,   300,     0,   293,   284,     0,   403,   313,   316,   315,
     317,     0,   367,   370,   371,     0,     0,   372,   373,   202,
       0,     0,   201,   204,   440,     0,   195,   198,     0,   350,
     176,     0,     0,     0,     0,   174,     0,     0,     0,     0,
     229,   219,     0,   222,   218,   307,   312,   282,    75,   265,
      89,   263,    95,    94,    78,    93,    90,   268,   105,    76,
     106,    92,    96,    77,    79,    91,   107,   262,   244,   247,
     245,   246,   257,   248,   261,   253,   251,   264,   267,   252,
     250,   255,   260,   249,   254,   258,   259,   256,   266,     0,
     242,     0,    80,     0,   282,   282,   240,   535,   485,   371,
     521,   521,     0,     0,     0,     0,     0,     0,     0,     0,
     154,   153,   215,   229,   215,   229,   160,     0,     0,   455,
       0,   454,     0,   486,     0,     0,   461,   164,     0,   460,
     162,    55,    54,   180,   471,   182,     0,   403,   287,     0,
       0,   371,   314,   330,   364,   394,     0,   551,     0,   206,
       0,     0,     0,   196,     0,   171,   468,     0,     0,   169,
     467,     0,   556,    65,    66,   209,   229,   229,   208,   229,
     216,   225,   223,     0,   293,   239,   243,     0,   269,     0,
     235,   236,   489,     0,     0,     0,     0,     0,     0,     0,
       0,   229,   144,   229,   142,   459,     0,     0,   488,   465,
       0,     0,     0,     0,   185,   371,   403,     0,   406,   405,
     407,   503,   326,   290,   288,     0,     0,     0,     0,   392,
     503,   207,   205,     0,   199,     0,   172,     0,   170,   217,
     385,     0,   318,     0,   241,    75,    77,   282,   282,     0,
       0,     0,     0,     0,     0,   145,   143,     0,     0,     0,
       0,    56,   184,   289,   371,   395,     0,   327,   329,   328,
     344,     0,   345,   332,   335,     0,   331,   322,   323,   228,
       0,   197,     0,     0,     0,   384,   383,   503,   319,   330,
     283,   237,   238,     0,     0,     0,     0,     0,     0,   458,
     457,   464,   463,   292,   291,   397,   398,   400,   503,     0,
     551,   343,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   503,   470,   469,     0,   375,     0,     0,     0,   399,
     401,   334,   336,   337,   340,   341,   342,   338,   339,   333,
     380,   378,   503,   551,   320,   234,   321,   395,   379,   503,
     402
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -941,  -941,  -941,     1,  -327,  1807,  -941,  -941,  -941,  -941,
     306,   416,  -413,    62,    71,  -941,  -941,  -941,   275,   712,
    -941,  1506,  -149,  -659,  -941,  -823,   932,  -940,  -753,   -48,
    -941,  -941,  -941,  -941,   101,  -941,  -941,  -941,   451,  -941,
     -23,  -941,  -941,  -941,  -941,  -941,  -941,  -371,  -665,  -941,
    -941,  -941,   -51,   639,  -941,  -941,  -941,   264,  -941,  -941,
    -941,  -941,  -180,  -145,  -756,  -941,  -171,     3,   135,  -941,
    -941,  -941,   -38,  -941,  -941,  -308,   309,  -941,  -241,  -265,
    -294,  -286,  -767,  -941,  -175,  -941,     9,   730,  -118,   324,
    -941,  -434,  -738,  -878,  -941,  -582,  -458,  -933,  -868,  -810,
     -57,  -941,    19,  -941,  -186,  -941,   196,   441,  -350,  -941,
    -941,  -941,  1076,  -941,    -7,  -941,  -941,  -166,  -941,  -562,
    -941,  -941,  1254,  1440,   -11,   741,    22,   215,  -941,  1594,
    1653,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -373
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,   302,   101,   600,   103,   104,   105,   319,
     106,   303,   595,   599,   596,   107,   108,   109,   110,   165,
     830,   244,   111,   241,   112,   626,   249,   113,   114,   115,
     116,   117,   118,   119,   701,   120,   121,   122,   460,   641,
     768,   123,   124,   637,   763,   125,   126,   496,   780,   127,
     128,   672,   673,   176,   242,   617,   130,   131,   498,   786,
     678,   833,   834,   430,   915,   434,   613,   614,   615,   616,
     679,   325,   751,  1019,  1075,  1009,   265,   998,   953,   957,
    1003,  1004,  1005,   132,   291,   465,   133,   134,   245,   246,
     438,   439,   630,  1016,   972,   442,   627,  1036,   950,   881,
     304,   192,   308,   309,   399,   400,   401,   177,   136,   137,
     138,   139,   178,   141,   162,   163,   552,   420,   722,   553,
     554,   142,   179,   180,   145,   204,   402,   182,   147,   183,
     184,   150,   151,   152,   314,   153,   154,   155,   156,   157
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     160,   375,   618,   100,   181,   266,   642,   556,   186,   262,
     263,   185,   391,   598,   193,   326,   884,  1008,   198,   198,
     832,   208,   210,   213,   214,   723,   636,   910,   409,   431,
     188,   481,   250,   575,   251,   252,   440,   578,   754,   253,
     440,   254,   312,   255,   424,   853,   397,   440,   855,   443,
    1000,   267,   271,   273,   275,   276,   277,   948,   247,  1000,
     281,   562,   282,   158,   285,   289,   397,   945,   418,   292,
     392,   448,   293,   294,   886,   295,   418,   296,   920,   921,
     297,   298,   247,   299,   486,   272,   267,   271,   313,  -386,
    -203,   628,  -386,   458,   718,   725,   955,   -81,   418,   247,
     910,   922,   910,     3,   -83,   -87,   612,  1059,   397,  1039,
     839,   323,   -88,   487,   643,   760,   970,  1008,   386,   158,
     310,  -386,   562,   479,   482,   469,   161,  1037,   838,  1001,
     397,   771,  -203,   207,   209,   164,   994,   324,   418,   688,
    1002,   375,   444,   954,  1080,   480,   484,  -386,  1015,  1002,
    -386,   956,    63,   483,   482,   160,   969,   761,   383,   384,
     385,  -386,   281,   267,   313,    63,  1042,   482,  -381,   883,
     441,  -386,  1060,   189,   441,   418,   689,  1071,   910,   390,
     910,   441,  -386,   563,   271,   753,  -203,   931,   387,   933,
     542,   543,    22,   518,  1043,  1078,   887,  -381,  -386,  -386,
     311,  -386,   482,   709,   271,   450,   712,   993,   406,    22,
    -381,   762,   387,   411,   556,   482,   394,   146,   674,   195,
     188,  1021,  1022,  -381,   387,   387,   146,   397,   397,   387,
     387,  1040,   747,   450,  1041,   395,    53,   740,  1074,   146,
     475,   146,   477,   387,  1073,   158,   271,    61,   215,   198,
     971,   662,   451,    53,   598,  -382,  1034,   452,   453,   256,
     832,   378,   675,   493,    61,   379,   187,   476,   271,   478,
    -381,   638,    81,   676,   741,  -381,   748,  1063,  1064,  1065,
    1066,  1067,  1068,   444,  -382,   257,   146,   749,   576,    81,
     286,   286,   677,   580,   444,   474,   450,  -382,   690,   694,
     938,   278,   499,   379,   471,   376,   750,   377,   397,   494,
    -382,   879,   146,   568,   279,   665,   146,   556,   500,   501,
     502,   503,   505,   507,   508,   691,   509,   510,   511,   512,
     513,   450,   519,   521,   522,   523,   524,   525,   526,   527,
     528,   529,   531,   532,   533,   534,   535,   536,   743,   248,
     284,   288,   862,  -491,   271,   271,   582,  -382,   716,  -490,
     271,     5,  -382,   271,   271,   271,   271,   545,   547,   555,
    -404,   248,  -527,   743,  -527,   744,   514,   146,   565,   863,
    -491,   283,   287,   569,   472,   570,  -490,   537,   538,   515,
    -525,  -404,  -525,   539,   332,  -404,   540,   541,   317,  -374,
    1020,   444,   267,    22,   584,   586,   783,   307,   444,   473,
     590,   592,  -396,   516,   597,   597,   612,   601,  -404,   603,
     711,  -352,   320,    38,   397,   727,   730,   714,  -374,   959,
     318,   784,   631,  -396,   504,   506,  -474,  -396,   668,   635,
    -352,  -374,   327,   135,   333,    51,   271,    53,   334,  -473,
     328,    72,   135,   909,  -374,   146,   629,   517,    61,   329,
    -396,   635,   146,   405,   271,   135,   271,   135,   410,   769,
     654,   635,   657,   380,   659,   661,  -526,  -478,  -526,   544,
     546,   952,  -479,    81,   267,  -476,  -475,   772,   774,   556,
     564,   388,   471,   382,   648,   336,   650,   310,  -376,   310,
     340,  -374,  -477,   342,   398,   342,  -374,   345,   387,  -527,
     403,  -527,   135,   248,   248,   248,   248,   585,   146,   393,
     429,   396,   407,   591,   398,   332,   909,  -376,   909,   454,
     951,   413,   146,   433,   835,   457,   340,   960,   135,   342,
    -376,   464,   135,   345,   466,   488,   584,   697,   590,   700,
     601,   702,   657,  -376,   492,   495,   248,   703,   704,   248,
     271,   567,   271,  1044,   497,   571,   398,   573,   756,   579,
     715,   572,   717,   581,   602,   333,   555,   587,   724,   334,
     604,   248,   653,   619,   620,   629,   633,   612,   398,  1045,
     639,  1046,  1047,   707,   640,  1048,  1049,   644,   652,   248,
    -376,   658,   146,   135,   909,  -376,   909,   681,   680,   669,
     682,   683,   277,   281,   313,   684,   686,   685,   271,   687,
     -59,  1017,   731,   710,   713,   735,   336,   337,   732,   734,
     146,   340,   752,   341,   342,   764,   146,   759,   345,   450,
     781,   129,   782,   146,   785,  1038,   352,   837,   843,   846,
     129,   758,   356,   357,   358,   597,   597,   848,   852,   696,
    1051,   699,   854,   129,   876,   129,   880,   882,   892,   885,
     897,   901,   903,   904,   905,  -108,   914,  -114,  -113,   555,
     -84,   135,   505,   545,   842,   398,   398,   845,   135,  -112,
    1038,   332,  -109,  -116,   146,   -82,   248,  -117,   146,  -111,
    -115,   -85,   918,   943,   890,  1072,   146,   859,  -110,   861,
     129,  -118,   -86,   332,   866,   919,   946,   869,  1018,   963,
     871,   -81,   872,  1079,   -83,   874,   248,  1038,  1070,   778,
     248,  1043,   912,   491,   605,   190,   129,   777,   462,   977,
     129,   333,   891,   973,   135,   334,   878,   742,   913,  1076,
     267,  -387,   606,  1033,  1057,   607,  1069,  1062,   135,   634,
     896,  -387,   900,   333,   212,   902,   398,   334,   632,   708,
     199,   911,     0,     0,   978,   608,     0,     0,   609,     0,
      55,   634,     0,     0,   307,     0,   307,     0,     0,   610,
    -387,   634,   336,     0,   504,   544,     0,   340,     0,   341,
     342,   129,     0,     0,   345,     0,     0,     0,   611,     0,
       0,     0,   352,     0,   336,     0,  -387,   146,   917,   340,
     358,   341,   342,  -387,     0,     0,   345,     0,   135,     0,
       0,     0,   859,   861,   352,   866,   869,   896,   900,     0,
     356,   357,   358,     0,  -387,  -285,   935,   936,     0,   937,
       0,   555,     0,   939,   940,     0,   135,   941,   262,   263,
       0,     0,   135,  -387,     0,     0,     0,   146,  -387,   135,
       0,  -387,  -285,   146,     0,   958,   657,     0,     0,   129,
     706,   964,   398,   965,   605,     0,   129,   967,     0,     0,
     996,   248,   248,     0,     0,     0,     0,   248,   248,     0,
       0,     0,   606,     0,     0,   607,     0,     0,     0,   739,
       0,     0,   935,   979,   980,   939,   981,   982,   983,   984,
     135,     0,     0,     0,   135,   608,     0,     0,   609,     0,
     315,   991,   135,   146,     0,   146,   313,     0,     0,   610,
     146,   999,   129,   146,     0,  1006,   766,     0,     5,     0,
     146,     0,     0,   146,     0,     0,   129,  1056,   611,     0,
      14,     0,     0,    16,     0,     0,     0,     0,    20,     0,
       0,     0,  -391,     0,     0,   146,  1029,  1030,  1031,  1032,
       0,     0,  -391,     0,     0,     0,   146,    36,   146,     0,
       0,     0,    39,     0,     0,   692,     0,   274,     0,   900,
      44,  1052,  1053,   313,     0,     0,   605,    49,     0,   248,
     248,  -391,  1029,  1030,  1031,  1032,  1052,  1053,     0,     0,
       0,   248,    59,   429,   606,     0,   129,   607,  1058,   657,
     429,  1061,  -393,   248,    69,     0,   248,  -391,    72,     0,
       0,     0,  -393,   135,  -391,    78,     0,   608,     0,     0,
     609,    82,    55,     0,   129,     0,     0,     0,     0,     0,
     129,   610,   657,     0,     0,  -391,   900,   129,     0,     0,
       0,  -393,   146,     0,   893,     0,     0,     0,   140,   146,
     611,     0,     0,     0,  -391,     0,     0,   140,     0,  -391,
       0,   146,  -391,   135,     0,     0,     0,  -393,     0,   135,
     140,     0,   140,   146,  -393,     0,     0,     0,     0,     0,
       0,     0,   146,     0,     0,     0,   146,     0,   129,     0,
     836,     0,   129,     0,     0,  -393,     0,     0,     0,     0,
     129,     0,     0,     0,   840,   841,     0,     0,     0,   414,
     417,   419,   423,     0,  -393,     0,     0,   140,     0,  -393,
       0,     0,  -393,     0,     0,     0,     0,     0,   146,   135,
       0,   135,     0,     0,     0,     0,   135,     0,     0,   135,
       0,     0,     0,   140,     0,     0,   135,   140,     0,   135,
     332,     0,   446,     0,     0,   447,     0,     0,     0,   949,
       0,     0,     0,     0,     0,     0,   248,     0,     0,     0,
       0,   135,   146,   146,   146,   146,     0,   456,     0,     0,
       0,     0,   135,     0,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   467,     0,   146,   146,     0,
     333,     0,     0,     0,   334,     0,     0,     0,   140,     0,
       0,   129,   429,   429,     0,     0,   429,   429,     0,     0,
       0,     0,     0,     0,     0,     0,   143,     0,     0,     0,
     332,   997,     0,  1007,     0,   143,     0,     0,     0,  1011,
       0,   429,     0,   429,     0,     0,     0,     0,   143,     0,
     143,   336,   337,     0,   338,   339,   340,     0,   341,   342,
       0,   129,     0,   345,     0,     0,     0,   129,   135,     0,
       0,   352,     0,     0,  1035,   135,     0,   356,   357,   358,
     333,     0,     0,     0,   334,     0,   140,   135,     0,     0,
       0,     0,   566,   140,     0,   143,     0,     0,     0,   135,
       0,     0,     0,     0,     0,     0,     0,     0,   135,     0,
       0,     0,   135,     0,     0,     0,     0,     0,     0,  1035,
       0,   143,   588,     0,     0,   143,   593,   129,     0,   129,
       0,   336,   337,  1007,   129,   339,   340,   129,   341,   342,
       0,     0,     0,   345,   129,     0,     0,   129,     0,   140,
       0,   352,     0,     0,   135,     0,  1035,   356,   357,   358,
       0,     0,     0,   140,     0,     0,     0,     0,   258,   129,
       0,     0,    21,    22,     0,     0,     0,     0,     0,     0,
     129,   259,   129,    29,   260,     0,   143,     0,    34,     0,
       0,     0,     0,    38,     0,     0,  -229,     0,   135,   135,
     135,   135,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   144,     0,     0,    51,     0,    53,     0,     0,
       0,   144,  -229,   135,   135,     0,   261,     0,    61,     0,
       0,     0,     0,   140,   144,     0,   144,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77,     0,     0,
      79,     0,   -63,    81,     0,     0,     0,     0,     0,     0,
       0,   140,     0,     0,   143,     0,   129,   140,     0,     0,
       0,   143,     0,   129,   140,     0,     0,     0,     0,     0,
       0,   144,     0,     0,     0,   129,     0,   719,   721,     0,
       0,     0,     0,   726,   729,     0,     0,   129,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   144,     0,     0,
     129,   144,   779,     0,     0,     0,   240,     0,     0,     0,
       0,     0,     0,     0,     0,   140,     0,   143,     0,   140,
       0,  -215,     0,     0,     0,  -215,  -215,   140,     0,     0,
       0,   143,     0,     0,  -215,     0,  -215,  -215,     0,     0,
       0,  -215,   129,   290,     0,     0,  -215,     0,     0,  -215,
       0,     0,     0,     0,     0,     0,   148,     0,     0,     0,
       0,     0,   144,     0,     0,   148,     0,     0,  -215,     0,
    -215,     0,  -215,     0,  -215,  -215,     0,  -215,   148,  -215,
     148,  -215,     0,     0,     0,     0,   129,   129,   129,   129,
       0,     0,   321,     0,   322,   850,   851,     0,     0,     0,
    -215,   143,     0,  -215,     0,     0,  -215,   856,     0,     0,
       0,   129,   129,     0,     0,   149,     0,     0,     0,   867,
       0,     0,   870,     0,   149,   148,     0,     0,     0,   143,
       0,     0,     0,     0,     0,   143,     0,   149,   140,   149,
     144,     0,   143,     0,     0,     0,     0,   144,     0,     0,
       0,   148,     0,   290,     0,   148,  -215,     0,     0,     0,
       0,     0,  -215,   404,     0,     0,     0,     0,   408,   290,
       0,   412,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   149,     0,     0,     0,   140,     0,
       0,     0,     0,   143,   140,     0,     0,   143,     0,     0,
       0,     0,     0,   144,     0,   143,     0,     0,     0,   437,
     149,     0,     0,     0,   149,     0,   148,   144,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     449,     0,   258,     0,     0,     0,    21,    22,     0,     0,
       0,     0,     0,     0,     0,   259,     0,    29,   260,     0,
       0,     0,    34,     0,   140,     0,   140,    38,     0,     0,
       0,   140,     0,     0,   140,     0,     0,     0,     0,   102,
       0,   140,     0,     0,   140,   149,     0,     0,   159,    51,
       0,    53,   962,   315,     0,   906,     0,   144,   907,     0,
     261,   191,    61,   194,   148,     0,   140,     0,     0,     0,
       0,   148,     0,     0,     0,     0,     0,   140,     0,   140,
       0,    77,     0,     0,    79,   144,   143,    81,     0,     0,
       0,   144,     0,     0,     0,     0,     0,     0,   144,   258,
       0,     0,     0,    21,    22,     0,     0,     0,   280,     0,
       0,     0,   259,     0,    29,   260,     0,     0,     0,    34,
       0,     0,     0,   149,    38,     0,     0,   148,     0,     0,
     149,     0,     0,     0,   102,     0,   143,    95,   316,   574,
       0,   148,   143,   577,     0,     0,    51,     0,    53,   144,
      55,     0,   906,   144,     0,   907,     0,   261,     0,    61,
       0,   144,     0,   140,     0,     0,     0,     0,     0,     0,
     140,     0,   437,     0,     0,     0,     0,     0,    77,     0,
       0,    79,   140,     0,    81,     0,   149,     0,     0,     0,
       0,     0,     0,     0,   140,     0,     0,     0,     0,   381,
     149,     0,   143,   140,   143,     0,     0,   140,     0,   143,
       0,   148,   143,     0,     0,     0,     0,     0,     0,   143,
       0,     0,   143,     0,     0,     0,     0,     0,   664,   332,
       0,     0,     0,   671,    95,     0,     0,     0,     0,   148,
     908,     0,     0,     0,   143,   148,     0,     0,     0,   140,
       0,     0,   148,     0,     0,   143,     0,   143,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     149,     0,   144,     0,     0,     0,     0,   432,     0,   333,
       0,     0,     0,   334,   445,     0,     0,     0,     0,     0,
       0,     0,     0,   140,   140,   140,   140,     0,   149,     0,
       0,     0,     0,   148,   149,     0,     0,   148,     0,     0,
       0,   149,     0,     0,     0,   148,     0,     0,   140,   140,
       0,     0,   144,     0,     0,     0,     0,     0,   144,     0,
     336,   337,     0,   338,   339,   340,     0,   341,   342,   343,
     102,   143,   345,     0,     0,     0,     0,     0,   143,   351,
     352,   746,     0,   355,   102,   437,   356,   357,   358,     0,
     143,     0,   149,     0,     0,     0,   149,     0,     0,     0,
       0,     0,   143,     0,   149,     0,   767,     0,     0,     0,
     290,   143,   332,     0,     0,   143,     0,     0,   144,     0,
     144,     0,     0,     0,     0,   144,     0,     0,   144,     0,
       0,     0,     0,     0,     0,   144,     0,     0,   144,     0,
       0,     0,     0,     0,     0,   831,     0,     0,     0,     0,
       0,     0,     0,     0,   102,     0,   148,   143,     0,     0,
     144,     0,   333,     0,     0,     0,   334,     0,     0,     0,
       0,   144,     0,   144,     0,     0,     0,     0,     0,     0,
       0,     0,   445,     0,     0,     0,     0,     0,   445,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   143,   143,   143,   143,     0,   148,     0,   877,     0,
       0,   437,   148,   336,   337,   149,   338,   339,   340,     0,
     341,   342,     0,     0,     0,   345,   143,   143,     0,     0,
       0,   767,   351,   352,     0,     0,   355,     0,     0,   356,
     357,   358,     0,     0,     0,     0,   651,     0,     0,   671,
     656,     0,     0,     0,     0,     0,     0,   144,   102,     0,
       0,     0,     0,     0,   144,   149,     0,     0,     0,     0,
       0,   149,   148,     0,   148,   916,   144,     0,     0,   148,
       0,     0,   148,     0,     0,     0,     0,     0,   144,   148,
       0,     0,   148,     0,     0,     0,     0,   144,     0,     0,
       0,   144,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   148,     0,     0,     0,     0,   258,
       0,     0,     0,    21,    22,   148,     0,   148,     0,     0,
       0,   149,   259,   149,    29,   260,     0,     0,   149,    34,
       0,   149,     0,   144,    38,     0,     0,     0,   149,     0,
       0,   149,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,     0,    53,   737,
      55,     0,   906,   149,     0,   907,     0,   261,     0,    61,
       0,     0,     0,     0,   149,   831,   149,   144,   144,   144,
     144,     0,     0,     0,     0,     0,     0,     0,    77,     0,
       0,    79,     0,     0,    81,     0,     0,     0,     0,     0,
       0,   148,   144,   144,     0,     0,     0,     0,   148,   770,
       0,     0,     0,     0,   258,   775,     0,     0,    21,    22,
     148,     0,     0,     0,     0,     0,     0,   259,     0,    29,
     260,     0,   148,     0,    34,     0,     0,     0,     0,    38,
       0,   148,  -229,     0,    95,   148,     0,     0,     0,     0,
     932,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     149,    51,     0,    53,     0,     0,     0,   149,  -229,     0,
       0,     0,   261,     0,    61,   445,     0,   445,     0,   149,
       0,     0,   445,     0,     0,   445,     0,   148,     0,     0,
       0,   149,   873,    77,     0,   875,    79,     0,   -62,    81,
     149,     0,     0,     0,   149,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   889,     0,     0,
       0,     0,     0,     0,   216,     0,     0,     0,   895,     0,
     899,   148,   148,   148,   148,     0,   217,   218,     0,   219,
       0,     0,     0,     0,   220,     0,   149,     0,     0,     0,
       0,     0,   221,     0,     0,     0,   148,   148,   222,     0,
       0,     0,     0,   223,     0,   224,     0,     0,   225,     0,
       0,     0,     0,     0,     0,     0,   226,     0,     0,     0,
       0,     0,   227,   228,     0,     0,     0,     0,     0,   229,
     149,   149,   149,   149,     0,     0,     0,     0,   230,     0,
       0,     0,     0,     0,     0,     0,     0,   231,   232,     0,
     233,     0,   234,     0,   235,   149,   149,   236,     0,     0,
       0,   237,   435,     0,   238,     0,     0,   239,     0,     0,
       0,     0,     0,   944,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   961,     0,     0,     0,     0,
       0,     0,     0,     0,   966,     0,     0,     0,   968,     0,
       0,     0,     0,     0,     0,     0,    -2,     4,     0,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    11,    12,
      13,    14,    15,   436,    16,     0,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,    26,    27,     0,    28,
     992,    29,    30,    31,    32,    33,    34,    35,    36,     0,
      37,    38,     0,    39,  -229,     0,    40,    41,    42,     0,
      43,    44,    45,   -43,    46,    47,     0,    48,    49,    50,
       0,     0,     0,    51,    52,    53,    54,    55,    56,    57,
    -229,   -43,    58,    59,    60,     0,    61,    62,    63,     0,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,     0,    74,    75,    76,    77,    78,     0,    79,    80,
     -61,    81,    82,     0,     0,    83,     0,    84,     0,     0,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,     0,     0,     0,     0,    91,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,     0,     0,    93,    94,
       0,    95,     0,     0,    96,     0,    97,     0,    98,  1054,
      99,     5,     6,     7,     8,     9,    10,     0,     0,     0,
     166,     0,     0,    14,    15,     0,    16,     0,   167,     0,
       0,    20,     0,     0,     0,     0,     0,     0,     0,    27,
       0,   168,     0,     0,     0,    31,   169,   170,     0,   171,
      36,     0,    37,     0,     0,    39,     0,     0,     0,    41,
      42,     0,     0,    44,    45,     0,    46,    47,     0,    48,
      49,     0,     0,     0,     0,     0,    52,     0,    54,     0,
      56,     0,     0,     0,     0,    59,   172,     0,     0,     0,
       0,     0,     0,     0,    66,    67,    68,    69,    70,   173,
       0,    72,     0,     0,    74,     0,     0,     0,    78,     0,
       0,    80,     0,     0,    82,     0,     0,     0,     0,     0,
       0,     0,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,    90,     0,     0,     0,     0,    91,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    92,     0,     0,
      93,    94,   264,     0,     0,     0,    96,     0,   174,     0,
      98,     0,   175,  1055,     4,     0,     5,     6,     7,     8,
       9,    10,     0,  -551,     0,    11,    12,    13,    14,    15,
    -551,    16,     0,    17,    18,    19,    20,    21,    22,    23,
      24,    25,  -551,    26,    27,  -551,    28,     0,    29,    30,
      31,    32,    33,    34,    35,    36,     0,    37,    38,     0,
      39,  -229,     0,    40,    41,    42,     0,    43,    44,    45,
     -43,    46,    47,     0,    48,    49,    50,     0,     0,     0,
      51,    52,    53,    54,     0,    56,    57,  -229,   -43,    58,
      59,    60,  -551,    61,    62,    63,  -551,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,     0,    74,
      75,    76,    77,    78,     0,    79,    80,   -61,    81,    82,
       0,     0,    83,     0,    84,     0,     0,  -551,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -551,  -551,    88,  -551,  -551,  -551,  -551,
    -551,  -551,  -551,     0,  -551,  -551,  -551,  -551,  -551,     0,
    -551,  -551,  -551,  -551,  -551,  -551,  -551,  -551,    95,  -551,
    -551,  -551,     0,    97,  -551,    98,   300,    99,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    11,    12,    13,
      14,    15,     0,    16,     0,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,     0,    28,     0,
      29,    30,    31,    32,    33,    34,    35,    36,     0,    37,
      38,     0,    39,  -229,     0,    40,    41,    42,     0,    43,
      44,    45,   -43,    46,    47,     0,    48,    49,    50,     0,
       0,     0,    51,    52,    53,    54,    55,    56,    57,  -229,
     -43,    58,    59,    60,     0,    61,    62,    63,     0,    64,
      65,    66,    67,    68,    69,    70,    71,     0,    72,    73,
       0,    74,    75,    76,    77,    78,     0,    79,    80,   -61,
      81,    82,     0,     0,    83,     0,    84,     0,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,     0,     0,    93,    94,   264,
      95,     0,     0,    96,     0,    97,   301,    98,     4,    99,
       5,     6,     7,     8,     9,    10,     0,     0,     0,    11,
      12,    13,    14,    15,     0,    16,     0,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,    26,    27,     0,
      28,     0,    29,    30,    31,    32,    33,    34,    35,    36,
       0,    37,    38,     0,    39,  -229,     0,    40,    41,    42,
       0,    43,    44,    45,   -43,    46,    47,     0,    48,    49,
      50,     0,     0,     0,    51,    52,    53,    54,    55,    56,
      57,  -229,   -43,    58,    59,    60,     0,    61,    62,    63,
       0,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,     0,    74,    75,    76,    77,    78,     0,    79,
      80,   -61,    81,    82,     0,     0,    83,     0,    84,     0,
       0,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,     0,     0,    93,
      94,     0,    95,     0,     0,    96,     0,    97,   470,    98,
     489,    99,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    11,    12,    13,    14,    15,     0,    16,     0,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,    26,
      27,     0,    28,     0,    29,    30,    31,    32,    33,    34,
      35,    36,     0,    37,    38,     0,    39,  -229,     0,    40,
      41,    42,     0,    43,    44,    45,   -43,    46,    47,     0,
      48,    49,    50,     0,     0,     0,    51,    52,    53,    54,
      55,    56,    57,  -229,   -43,    58,    59,    60,     0,    61,
      62,    63,     0,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,     0,    74,    75,    76,    77,    78,
       0,    79,    80,   -61,    81,    82,     0,     0,    83,     0,
      84,     0,     0,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,     0,
       0,    93,    94,     0,    95,     0,     0,    96,     0,    97,
     490,    98,   300,    99,     5,     6,     7,     8,     9,    10,
       0,     0,     0,    11,    12,    13,    14,    15,     0,    16,
       0,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,    26,    27,     0,    28,     0,    29,    30,    31,    32,
      33,    34,    35,    36,     0,    37,    38,     0,    39,  -229,
       0,    40,    41,    42,     0,    43,    44,    45,   -43,    46,
      47,     0,    48,    49,    50,     0,     0,     0,    51,    52,
      53,    54,    55,    56,    57,  -229,   -43,    58,    59,    60,
       0,    61,    62,    63,     0,    64,    65,    66,    67,    68,
      69,    70,    71,     0,    72,    73,     0,    74,    75,    76,
      77,    78,     0,    79,    80,   -61,    81,    82,     0,     0,
      83,     0,    84,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,     0,     0,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,     0,     0,    93,    94,     0,    95,     0,     0,    96,
       0,    97,   301,    98,     4,    99,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    11,    12,    13,    14,    15,
       0,    16,     0,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,    26,    27,     0,    28,     0,    29,    30,
      31,    32,    33,    34,    35,    36,     0,    37,    38,     0,
      39,  -229,     0,    40,    41,    42,     0,    43,    44,    45,
     -43,    46,    47,     0,    48,    49,    50,     0,     0,     0,
      51,    52,    53,    54,    55,    56,    57,  -229,   -43,    58,
      59,    60,     0,    61,    62,    63,     0,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,     0,    74,
      75,    76,    77,    78,     0,    79,    80,   -61,    81,    82,
       0,     0,    83,     0,    84,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,    90,     0,     0,
       0,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,     0,     0,    93,    94,     0,    95,     0,
       0,    96,     0,    97,   663,    98,     4,    99,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    11,    12,    13,
      14,    15,     0,    16,     0,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,     0,    28,     0,
      29,    30,    31,    32,    33,    34,    35,    36,     0,    37,
      38,     0,    39,  -229,     0,    40,    41,    42,     0,    43,
      44,    45,   -43,    46,    47,     0,    48,    49,    50,     0,
       0,     0,    51,    52,    53,    54,   315,    56,    57,  -229,
     -43,    58,    59,    60,     0,    61,    62,    63,     0,    64,
      65,    66,    67,    68,    69,    70,    71,     0,    72,    73,
       0,    74,    75,    76,    77,    78,     0,    79,    80,   -61,
      81,    82,     0,     0,    83,     0,    84,     0,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,     0,     0,    93,    94,     0,
      95,     0,     0,    96,     0,    97,     0,    98,     4,    99,
       5,     6,     7,     8,     9,    10,     0,     0,     0,    11,
      12,    13,    14,    15,     0,    16,     0,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,    26,    27,     0,
      28,     0,    29,    30,    31,    32,    33,    34,    35,    36,
       0,    37,    38,     0,    39,  -229,     0,    40,    41,    42,
       0,    43,    44,    45,   -43,    46,    47,     0,    48,    49,
      50,     0,     0,     0,    51,    52,    53,    54,     0,    56,
      57,  -229,   -43,    58,    59,    60,     0,    61,    62,    63,
       0,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,     0,    74,    75,    76,    77,    78,     0,    79,
      80,   -61,    81,    82,     0,     0,    83,     0,    84,     0,
       0,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,     0,     0,    93,
      94,     0,    95,     0,     0,    96,     0,    97,     0,    98,
       4,    99,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    11,    12,    13,    14,    15,     0,    16,     0,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,    26,
      27,     0,    28,     0,    29,    30,    31,    32,    33,    34,
     583,    36,     0,    37,    38,     0,    39,  -229,     0,    40,
      41,    42,     0,    43,    44,    45,   -43,    46,    47,     0,
      48,    49,    50,     0,     0,     0,    51,    52,    53,    54,
       0,    56,    57,  -229,   -43,    58,    59,    60,     0,    61,
      62,    63,     0,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,     0,    74,    75,    76,    77,    78,
       0,    79,    80,   -61,    81,    82,     0,     0,    83,     0,
      84,     0,     0,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,     0,
       0,    93,    94,     0,    95,     0,     0,    96,     0,    97,
       0,    98,     4,    99,     5,     6,     7,     8,     9,    10,
       0,     0,     0,    11,    12,    13,    14,    15,     0,    16,
       0,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,    26,    27,     0,    28,     0,    29,    30,    31,    32,
      33,    34,   589,    36,     0,    37,    38,     0,    39,  -229,
       0,    40,    41,    42,     0,    43,    44,    45,   -43,    46,
      47,     0,    48,    49,    50,     0,     0,     0,    51,    52,
      53,    54,     0,    56,    57,  -229,   -43,    58,    59,    60,
       0,    61,    62,    63,     0,    64,    65,    66,    67,    68,
      69,    70,    71,     0,    72,    73,     0,    74,    75,    76,
      77,    78,     0,    79,    80,   -61,    81,    82,     0,     0,
      83,     0,    84,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,     0,     0,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,     0,     0,    93,    94,     0,    95,     0,     0,    96,
       0,    97,     0,    98,     4,    99,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    11,    12,    13,    14,    15,
       0,    16,     0,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,    26,    27,     0,    28,     0,    29,    30,
      31,    32,    33,    34,   858,    36,     0,    37,    38,     0,
      39,  -229,     0,    40,    41,    42,     0,    43,    44,    45,
     -43,    46,    47,     0,    48,    49,    50,     0,     0,     0,
      51,    52,    53,    54,     0,    56,    57,  -229,   -43,    58,
      59,    60,     0,    61,    62,    63,     0,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,     0,    74,
      75,    76,    77,    78,     0,    79,    80,   -61,    81,    82,
       0,     0,    83,     0,    84,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,    90,     0,     0,
       0,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,     0,     0,    93,    94,     0,    95,     0,
       0,    96,     0,    97,     0,    98,     4,    99,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    11,    12,    13,
      14,    15,     0,    16,     0,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,     0,    28,     0,
      29,    30,    31,    32,    33,    34,   860,    36,     0,    37,
      38,     0,    39,  -229,     0,    40,    41,    42,     0,    43,
      44,    45,   -43,    46,    47,     0,    48,    49,    50,     0,
       0,     0,    51,    52,    53,    54,     0,    56,    57,  -229,
     -43,    58,    59,    60,     0,    61,    62,    63,     0,    64,
      65,    66,    67,    68,    69,    70,    71,     0,    72,    73,
       0,    74,    75,    76,    77,    78,     0,    79,    80,   -61,
      81,    82,     0,     0,    83,     0,    84,     0,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,     0,     0,    93,    94,     0,
      95,     0,     0,    96,     0,    97,     0,    98,     4,    99,
       5,     6,     7,     8,     9,    10,     0,     0,     0,    11,
      12,    13,    14,    15,     0,    16,     0,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,    26,    27,     0,
      28,     0,    29,    30,    31,    32,    33,    34,   865,    36,
       0,    37,    38,     0,    39,  -229,     0,    40,    41,    42,
       0,    43,    44,    45,   -43,    46,    47,     0,    48,    49,
      50,     0,     0,     0,    51,    52,    53,    54,     0,    56,
      57,  -229,   -43,    58,    59,    60,     0,    61,    62,    63,
       0,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,     0,    74,    75,    76,    77,    78,     0,    79,
      80,   -61,    81,    82,     0,     0,    83,     0,    84,     0,
       0,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,     0,     0,    93,
      94,     0,    95,     0,     0,    96,     0,    97,     0,    98,
       4,    99,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    11,    12,    13,    14,    15,     0,    16,     0,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,    26,
      27,     0,    28,     0,    29,    30,    31,    32,    33,    34,
     868,    36,     0,    37,    38,     0,    39,  -229,     0,    40,
      41,    42,     0,    43,    44,    45,   -43,    46,    47,     0,
      48,    49,    50,     0,     0,     0,    51,    52,    53,    54,
       0,    56,    57,  -229,   -43,    58,    59,    60,     0,    61,
      62,    63,     0,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,     0,    74,    75,    76,    77,    78,
       0,    79,    80,   -61,    81,    82,     0,     0,    83,     0,
      84,     0,     0,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,     0,
       0,    93,    94,     0,    95,     0,     0,    96,     0,    97,
       0,    98,     4,    99,     5,     6,     7,     8,     9,    10,
       0,     0,     0,    11,    12,    13,    14,    15,     0,    16,
       0,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,   888,    27,     0,    28,     0,    29,    30,    31,    32,
      33,    34,    35,    36,     0,    37,    38,     0,    39,  -229,
       0,    40,    41,    42,     0,    43,    44,    45,   -43,    46,
      47,     0,    48,    49,    50,     0,     0,     0,    51,    52,
      53,    54,     0,    56,    57,  -229,   -43,    58,    59,    60,
       0,    61,    62,    63,     0,    64,    65,    66,    67,    68,
      69,    70,    71,     0,    72,    73,     0,    74,    75,    76,
      77,    78,     0,    79,    80,   -61,    81,    82,     0,     0,
      83,     0,    84,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,     0,     0,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,     0,     0,    93,    94,     0,    95,     0,     0,    96,
       0,    97,     0,    98,     4,    99,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    11,    12,    13,    14,    15,
       0,    16,     0,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,    26,    27,     0,    28,     0,    29,    30,
      31,    32,    33,    34,   894,    36,     0,    37,    38,     0,
      39,  -229,     0,    40,    41,    42,     0,    43,    44,    45,
     -43,    46,    47,     0,    48,    49,    50,     0,     0,     0,
      51,    52,    53,    54,     0,    56,    57,  -229,   -43,    58,
      59,    60,     0,    61,    62,    63,     0,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,     0,    74,
      75,    76,    77,    78,     0,    79,    80,   -61,    81,    82,
       0,     0,    83,     0,    84,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,    90,     0,     0,
       0,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,     0,     0,    93,    94,     0,    95,     0,
       0,    96,     0,    97,     0,    98,     4,    99,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    11,    12,    13,
      14,    15,     0,    16,     0,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,     0,    28,     0,
      29,    30,    31,    32,    33,    34,   898,    36,     0,    37,
      38,     0,    39,  -229,     0,    40,    41,    42,     0,    43,
      44,    45,   -43,    46,    47,     0,    48,    49,    50,     0,
       0,     0,    51,    52,    53,    54,     0,    56,    57,  -229,
     -43,    58,    59,    60,     0,    61,    62,    63,     0,    64,
      65,    66,    67,    68,    69,    70,    71,     0,    72,    73,
       0,    74,    75,    76,    77,    78,     0,    79,    80,   -61,
      81,    82,     0,     0,    83,     0,    84,     0,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,     0,     0,    93,    94,     0,
      95,     0,     0,    96,     0,    97,     0,    98,   755,    99,
       5,     6,     7,     8,     9,    10,     0,     0,     0,   166,
       0,     0,    14,    15,     0,    16,     0,   167,     0,     0,
      20,     0,     0,     0,     0,     0,     0,     0,    27,     0,
     168,     0,     0,     0,    31,   169,   170,     0,   171,    36,
       0,    37,     0,     0,    39,     0,     0,     0,    41,    42,
       0,     0,    44,    45,     0,    46,    47,     0,    48,    49,
       0,     0,     0,     0,     0,    52,     0,    54,     0,    56,
       0,     0,     0,     0,    59,   172,     0,     0,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,   173,     0,
      72,     0,     0,    74,     0,     0,     0,    78,     0,     0,
      80,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,     0,     0,    93,
      94,   264,     0,     0,     0,    96,     0,   174,     0,    98,
       0,   175,     5,     6,     7,     8,     9,    10,     0,     0,
       0,   166,     0,     0,    14,    15,     0,    16,     0,   167,
       0,     0,    20,     0,     0,     0,     0,     0,     0,     0,
      27,     0,   168,     0,     0,     0,    31,   169,   170,     0,
     171,    36,     0,    37,     0,     0,    39,     0,     0,     0,
      41,    42,     0,     0,    44,    45,     0,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,    52,     0,    54,
       0,    56,     0,     0,     0,     0,    59,   172,     0,     0,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
     173,     0,    72,     0,     0,    74,     0,     0,     0,    78,
       0,     0,    80,     0,     0,    82,     0,     0,     0,     0,
       0,     0,     0,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,     0,
       0,    93,    94,   264,     0,     0,     0,    96,     0,   174,
       0,    98,     0,   175,   655,     5,     6,     7,     8,     9,
      10,     0,     0,     0,   166,     0,     0,    14,    15,     0,
      16,     0,   167,     0,     0,    20,     0,     0,     0,     0,
       0,     0,     0,    27,     0,   168,     0,     0,     0,    31,
     169,   170,     0,   171,    36,     0,    37,     0,     0,    39,
       0,     0,     0,    41,    42,     0,     0,    44,    45,     0,
      46,    47,     0,    48,    49,     0,     0,     0,     0,     0,
      52,     0,    54,     0,    56,     0,     0,     0,     0,    59,
     172,     0,     0,     0,     0,     0,     0,     0,    66,    67,
      68,    69,    70,   173,     0,    72,     0,     0,    74,     0,
       0,     0,    78,     0,     0,    80,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,    90,     0,     0,     0,
       0,    91,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,     0,     0,    93,    94,   264,     0,     0,     0,
      96,     0,   174,     0,    98,     0,   175,   995,     5,     6,
       7,     8,     9,    10,     0,     0,     0,   166,     0,     0,
      14,    15,     0,    16,     0,   167,     0,     0,    20,     0,
       0,     0,     0,     0,     0,     0,    27,     0,   168,     0,
       0,     0,    31,   169,   170,     0,   171,    36,     0,    37,
       0,     0,    39,     0,     0,     0,    41,    42,     0,     0,
      44,    45,     0,    46,    47,     0,    48,    49,     0,     0,
       0,     0,     0,    52,     0,    54,     0,    56,     0,     0,
       0,     0,    59,   172,     0,     0,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,   173,     0,    72,     0,
       0,    74,     0,     0,     0,    78,     0,     0,    80,     0,
       0,    82,     0,     0,     0,     0,     0,     0,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,     0,     0,    93,    94,     0,
       0,     0,     0,    96,     0,   174,     0,    98,     0,   175,
     660,     5,     6,     7,     8,     9,    10,     0,     0,     0,
     166,     0,     0,    14,    15,     0,    16,     0,   167,     0,
       0,    20,   211,    22,     0,     0,     0,     0,     0,    27,
       0,   168,     0,     0,     0,    31,   169,   170,     0,   171,
      36,     0,    37,     0,     0,    39,     0,     0,     0,    41,
      42,     0,     0,    44,    45,     0,    46,    47,     0,    48,
      49,     0,     0,     0,     0,     0,    52,    53,    54,     0,
      56,     0,     0,     0,     0,    59,   172,     0,    61,     0,
       0,     0,     0,     0,    66,    67,    68,    69,    70,   173,
       0,    72,     0,     0,    74,     0,     0,     0,    78,     0,
       0,    80,     0,    81,    82,     0,     0,     0,     0,     0,
       0,     0,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,    90,     0,     0,     0,     0,    91,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    92,     0,     0,
      93,    94,     0,     0,     0,     0,    96,     0,   174,     0,
      98,     0,   175,     5,     6,     7,     8,     9,    10,     0,
       0,     0,   166,     0,     0,    14,    15,     0,    16,     0,
     167,     0,     0,    20,     0,     0,     0,     0,     0,     0,
       0,    27,     0,   168,     0,     0,     0,    31,   169,   170,
       0,   171,    36,     0,    37,     0,     0,    39,     0,     0,
       0,    41,    42,     0,     0,    44,    45,     0,    46,    47,
       0,    48,    49,     0,     0,     0,     0,     0,    52,     0,
      54,     0,    56,     0,     0,     0,     0,    59,   172,     0,
       0,     0,     0,     0,     0,     0,    66,    67,    68,    69,
      70,   173,     0,    72,     0,     0,    74,   268,   269,     0,
      78,   305,     0,    80,     0,     0,    82,     0,     0,     0,
       0,     0,     0,     0,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,    90,     0,     0,     0,     0,    91,
     306,     0,     0,     0,     0,     0,     0,     0,     0,    92,
       0,     0,    93,    94,   264,     0,     0,     0,    96,     0,
     174,     0,    98,     0,   175,     5,     6,     7,     8,     9,
      10,     0,     0,     0,   166,     0,     0,    14,    15,     0,
      16,     0,   167,     0,     0,    20,     0,     0,     0,     0,
       0,     0,     0,    27,     0,   168,     0,     0,     0,    31,
     169,   170,     0,   171,    36,     0,    37,     0,     0,    39,
       0,     0,     0,    41,    42,     0,     0,    44,    45,     0,
      46,    47,     0,    48,    49,     0,     0,     0,     0,     0,
      52,     0,    54,     0,    56,     0,     0,     0,     0,    59,
     172,     0,     0,     0,     0,     0,     0,     0,    66,    67,
      68,    69,    70,   173,     0,    72,     0,     0,    74,   268,
     269,     0,    78,   305,     0,    80,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,    90,     0,     0,     0,
       0,    91,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,     0,     0,    93,    94,   264,     0,     0,     0,
      96,     0,   174,     0,    98,   647,   175,     5,     6,     7,
       8,     9,    10,     0,     0,     0,   166,     0,     0,    14,
      15,     0,    16,     0,   167,     0,     0,    20,     0,     0,
       0,     0,     0,     0,     0,    27,     0,   168,     0,     0,
       0,    31,   169,   170,     0,   171,    36,     0,    37,     0,
       0,    39,     0,     0,     0,    41,    42,     0,     0,    44,
      45,     0,    46,    47,     0,    48,    49,     0,     0,     0,
       0,     0,    52,     0,    54,     0,    56,     0,     0,     0,
       0,    59,   172,     0,     0,     0,     0,     0,     0,     0,
      66,    67,    68,    69,    70,   173,     0,    72,     0,     0,
      74,   268,   269,     0,    78,   305,     0,    80,     0,     0,
      82,     0,     0,     0,     0,     0,     0,     0,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,    90,     0,
       0,     0,     0,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,     0,     0,    93,    94,   264,     0,
       0,     0,    96,     0,   174,     0,    98,   649,   175,     5,
       6,     7,     8,     9,    10,     0,     0,     0,   166,     0,
       0,    14,    15,     0,    16,     0,   167,     0,     0,    20,
       0,   548,     0,     0,     0,     0,     0,    27,     0,   168,
       0,     0,     0,    31,   169,   170,     0,   171,    36,   549,
      37,     0,     0,    39,     0,     0,     0,    41,    42,     0,
       0,    44,    45,     0,    46,    47,     0,    48,    49,     0,
       0,     0,     0,     0,    52,     0,    54,     0,    56,     0,
       0,     0,     0,    59,   172,     0,   550,     0,     0,     0,
       0,     0,    66,    67,    68,    69,    70,   173,     0,    72,
       0,     0,    74,     0,     0,     0,    78,     0,     0,    80,
       0,   551,    82,     0,     0,     0,     0,     0,     0,     0,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,     0,     0,     0,     0,    91,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,     0,     0,    93,    94,
     787,     0,   788,     0,    96,     0,   174,     0,    98,   789,
     175,     0,     0,     0,   790,   218,   791,   792,     0,     0,
       0,     0,   793,     0,   258,     0,     0,     0,    21,    22,
     221,     0,     0,     0,     0,     0,   794,   259,     0,    29,
     260,   795,     0,   224,    34,     0,   796,     0,   797,    38,
       0,     0,     0,     0,   798,     0,     0,     0,     0,     0,
     799,   800,     0,     0,     0,     0,     0,   229,     0,     0,
       0,    51,     0,    53,     0,     0,   801,     0,     0,     0,
       0,     0,   261,     0,    61,   231,   232,     0,   802,     0,
     234,     0,   803,     0,     0,   804,     0,     0,     0,   805,
       0,     0,   238,    77,     0,   806,    79,     0,     0,    81,
       0,     0,     0,     0,   359,   360,   361,   362,   363,   364,
       0,     0,   367,   368,   369,   370,     0,   372,   373,   807,
     808,   809,   810,   811,     0,     0,   812,     0,     0,     0,
     813,   814,   815,   816,   817,   818,   819,   820,   821,   822,
     823,     0,   824,     0,     0,   825,   826,   827,   828,     0,
       0,   829,     5,     6,     7,     8,     9,    10,     0,     0,
       0,   166,     0,     0,    14,    15,     0,    16,     0,   167,
       0,     0,    20,     0,     0,     0,     0,     0,     0,     0,
      27,     0,   168,     0,     0,     0,    31,   169,   170,     0,
     171,    36,     0,    37,     0,     0,    39,     0,     0,     0,
      41,    42,     0,     0,    44,    45,     0,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,    52,     0,    54,
       0,    56,     0,     0,     0,     0,    59,   172,     0,     0,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
     173,     0,    72,     0,     0,    74,   268,   269,     0,    78,
       0,     0,    80,     0,     0,    82,     0,     0,     0,     0,
       0,     0,     0,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,     0,
       0,    93,    94,     0,   270,     0,     0,    96,     0,   174,
       0,    98,     0,   175,     5,     6,     7,     8,     9,    10,
       0,     0,     0,   166,     0,     0,    14,    15,     0,    16,
       0,   167,     0,     0,    20,     0,     0,     0,     0,     0,
       0,     0,    27,     0,   168,     0,     0,     0,    31,   169,
     170,     0,   171,    36,     0,    37,     0,     0,    39,     0,
       0,     0,    41,    42,     0,     0,    44,    45,     0,    46,
      47,     0,    48,    49,     0,     0,     0,     0,     0,    52,
       0,    54,     0,    56,     0,     0,     0,     0,    59,   172,
       0,     0,     0,     0,     0,     0,     0,    66,    67,    68,
      69,    70,   173,     0,    72,     0,     0,    74,   268,   269,
       0,    78,     0,     0,    80,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,     0,     0,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,     0,     0,    93,    94,   264,     0,     0,     0,    96,
       0,   174,     0,    98,     0,   175,     5,     6,     7,     8,
       9,    10,     0,     0,     0,   166,     0,     0,    14,    15,
       0,    16,     0,   167,     0,     0,    20,     0,     0,     0,
       0,     0,     0,     0,    27,     0,   168,     0,     0,     0,
      31,   169,   170,     0,   171,    36,     0,    37,     0,     0,
      39,     0,     0,     0,    41,    42,     0,     0,    44,    45,
       0,    46,    47,   757,    48,    49,     0,     0,     0,     0,
       0,    52,     0,    54,     0,    56,     0,     0,     0,     0,
      59,   172,     0,     0,     0,     0,     0,     0,     0,    66,
      67,    68,    69,    70,   173,     0,    72,     0,     0,    74,
     268,   269,     0,    78,     0,     0,    80,     0,     0,    82,
       0,     0,     0,     0,     0,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,    90,     0,     0,
       0,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,     0,     0,    93,    94,     0,     0,     0,
       0,    96,     0,   174,     0,    98,     0,   175,     5,     6,
       7,     8,   200,    10,   201,     0,     0,   166,     0,     0,
      14,    15,     0,    16,     0,   167,     0,     0,    20,     0,
       0,     0,     0,     0,     0,     0,    27,     0,   168,     0,
       0,     0,    31,   169,   170,     0,   171,    36,     0,    37,
       0,     0,    39,     0,     0,     0,    41,    42,     0,     0,
      44,    45,     0,    46,    47,     0,    48,    49,     0,     0,
       0,     0,     0,    52,     0,    54,     0,    56,     0,     0,
       0,     0,    59,   202,     0,     0,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,   173,     0,    72,     0,
       0,    74,     0,     0,   203,    78,     0,     0,    80,     0,
       0,    82,     0,     0,     0,     0,     0,     0,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,     0,     0,    93,    94,     0,
       0,     0,     0,    96,     0,   174,     0,    98,     0,   175,
       5,     6,     7,     8,     9,    10,     0,     0,     0,   166,
       0,     0,    14,    15,     0,    16,     0,   167,     0,     0,
      20,     0,     0,     0,     0,     0,     0,     0,    27,     0,
     168,     0,     0,     0,    31,   169,   170,     0,   171,    36,
       0,    37,     0,     0,    39,     0,     0,     0,    41,    42,
       0,     0,    44,    45,     0,    46,    47,     0,    48,    49,
       0,     0,     0,     0,     0,    52,   205,    54,     0,    56,
       0,     0,     0,     0,    59,   172,     0,     0,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,   173,     0,
      72,     0,     0,    74,     0,     0,     0,    78,     0,     0,
      80,     0,     0,    82,     0,     0,     0,     0,     0,   206,
       0,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,     0,     0,    93,
      94,     0,     0,     0,     0,    96,     0,   174,     0,    98,
       0,   175,     5,     6,     7,     8,     9,    10,     0,     0,
       0,   166,     0,     0,    14,    15,     0,    16,     0,   167,
       0,     0,    20,     0,     0,     0,     0,     0,     0,     0,
      27,     0,   168,     0,     0,     0,    31,   169,   170,     0,
     171,    36,     0,    37,     0,     0,    39,     0,     0,     0,
      41,    42,     0,     0,    44,    45,     0,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,    52,     0,    54,
       0,    56,     0,     0,     0,     0,    59,   172,     0,     0,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
     173,     0,    72,     0,     0,    74,     0,     0,     0,    78,
       0,     0,    80,     0,     0,    82,     0,     0,     0,     0,
       0,   206,     0,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,     0,
       0,    93,    94,   264,     0,     0,     0,    96,     0,   174,
       0,    98,     0,   175,     5,     6,     7,     8,     9,    10,
       0,     0,     0,   166,     0,     0,    14,    15,     0,    16,
       0,   167,     0,     0,    20,     0,     0,     0,     0,     0,
       0,     0,    27,     0,   168,     0,     0,     0,    31,   169,
     170,     0,   171,    36,     0,    37,     0,     0,    39,     0,
       0,     0,    41,    42,     0,     0,    44,    45,     0,    46,
      47,     0,    48,    49,     0,     0,     0,     0,     0,    52,
       0,    54,     0,    56,     0,     0,     0,     0,    59,   172,
       0,     0,     0,     0,     0,     0,     0,    66,    67,    68,
      69,    70,   173,     0,    72,     0,     0,    74,   268,   269,
       0,    78,     0,     0,    80,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,     0,     0,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,     0,     0,    93,    94,     0,     0,     0,     0,    96,
       0,   174,     0,    98,     0,   175,     5,     6,     7,     8,
       9,    10,     0,     0,     0,   166,     0,     0,    14,    15,
       0,    16,     0,   167,     0,     0,    20,     0,     0,     0,
       0,     0,     0,     0,    27,     0,   168,     0,     0,     0,
      31,   169,   170,     0,   171,    36,     0,    37,     0,     0,
      39,     0,     0,     0,    41,    42,     0,     0,    44,    45,
       0,    46,    47,     0,    48,    49,     0,     0,     0,     0,
       0,    52,     0,    54,     0,    56,     0,     0,     0,     0,
      59,   172,     0,     0,     0,     0,     0,     0,     0,    66,
      67,    68,    69,    70,   173,     0,    72,     0,     0,    74,
       0,     0,     0,    78,     0,     0,    80,     0,     0,    82,
       0,     0,     0,     0,     0,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,    90,     0,     0,
       0,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,     0,     0,    93,    94,   264,     0,     0,
       0,    96,     0,   174,   645,    98,     0,   175,     5,     6,
       7,     8,     9,    10,     0,     0,     0,   166,     0,     0,
      14,    15,     0,    16,     0,   167,     0,     0,    20,     0,
       0,     0,     0,     0,     0,     0,    27,     0,   168,     0,
       0,     0,    31,   169,   170,     0,   171,    36,     0,    37,
       0,     0,    39,     0,     0,     0,    41,    42,     0,     0,
      44,    45,     0,    46,    47,     0,    48,    49,     0,     0,
       0,     0,     0,    52,     0,    54,     0,    56,     0,     0,
       0,     0,    59,   172,     0,     0,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,   173,     0,    72,     0,
       0,    74,     0,     0,     0,    78,     0,     0,    80,     0,
       0,    82,     0,     0,     0,     0,     0,   206,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,     0,     0,    93,    94,     0,
       0,     0,     0,    96,     0,   174,     0,    98,     0,   175,
       5,     6,     7,     8,     9,    10,     0,     0,     0,   166,
       0,     0,    14,    15,     0,    16,     0,   167,     0,     0,
      20,     0,     0,     0,     0,     0,     0,   247,    27,     0,
     168,     0,     0,     0,    31,   169,   170,     0,   171,    36,
       0,    37,     0,     0,    39,     0,     0,     0,    41,    42,
       0,     0,    44,    45,     0,    46,    47,     0,    48,    49,
       0,     0,     0,     0,     0,    52,     0,    54,     0,    56,
       0,     0,     0,     0,    59,   172,     0,     0,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,   173,     0,
      72,     0,     0,    74,     0,     0,     0,    78,     0,     0,
      80,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,     0,     0,    93,
      94,     0,     0,     0,     0,    96,     0,    97,     0,    98,
       0,   175,     5,     6,     7,     8,     9,    10,     0,     0,
       0,   166,     0,     0,    14,    15,     0,    16,     0,   167,
       0,     0,    20,     0,     0,     0,     0,     0,     0,     0,
      27,     0,   168,     0,     0,     0,    31,   169,   170,     0,
     171,    36,     0,    37,     0,     0,    39,     0,     0,     0,
      41,    42,     0,     0,    44,    45,     0,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,    52,     0,    54,
       0,    56,     0,     0,     0,     0,    59,   172,     0,     0,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
     173,     0,    72,     0,     0,    74,     0,     0,     0,    78,
       0,     0,    80,     0,     0,    82,     0,     0,     0,     0,
       0,     0,     0,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,     0,
       0,    93,    94,   264,     0,     0,     0,    96,     0,   174,
       0,    98,     0,   175,     5,     6,     7,     8,   200,    10,
       0,     0,     0,   166,     0,     0,    14,    15,     0,    16,
       0,   167,     0,     0,    20,     0,     0,     0,     0,     0,
       0,     0,    27,     0,   168,     0,     0,     0,    31,   169,
     170,     0,   171,    36,     0,    37,     0,     0,    39,     0,
       0,     0,    41,    42,     0,     0,    44,    45,     0,    46,
      47,     0,    48,    49,     0,     0,     0,     0,     0,    52,
       0,    54,     0,    56,     0,     0,     0,     0,    59,   202,
       0,     0,     0,     0,     0,     0,     0,    66,    67,    68,
      69,    70,   173,     0,    72,     0,     0,    74,     0,     0,
     203,    78,     0,     0,    80,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,     0,     0,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,     0,     0,    93,    94,     0,     0,     0,     0,    96,
       0,   174,     0,    98,     0,   175,     5,     6,     7,     8,
       9,    10,     0,     0,     0,   166,     0,     0,    14,    15,
       0,    16,     0,   167,     0,     0,    20,     0,     0,     0,
       0,     0,     0,     0,    27,     0,   168,     0,     0,     0,
      31,   169,   170,     0,   171,    36,     0,    37,     0,     0,
      39,     0,     0,     0,    41,    42,     0,     0,    44,    45,
       0,    46,    47,     0,    48,    49,     0,     0,     0,     0,
       0,    52,     0,    54,     0,    56,     0,     0,     0,     0,
      59,   172,     0,     0,     0,     0,     0,     0,     0,    66,
      67,    68,    69,    70,   173,     0,    72,     0,     0,    74,
       0,     0,     0,    78,     0,     0,    80,     0,     0,    82,
       0,     0,     0,     0,     0,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,    90,     0,     0,
       0,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,     0,     0,    93,    94,   520,     0,     0,
       0,    96,     0,   174,     0,    98,     0,   175,     5,     6,
       7,     8,     9,    10,     0,     0,     0,   166,     0,     0,
      14,    15,     0,    16,     0,   167,     0,     0,    20,     0,
       0,     0,     0,     0,     0,     0,    27,     0,   168,     0,
       0,     0,    31,   169,   170,     0,   171,    36,     0,    37,
       0,     0,    39,     0,     0,     0,    41,    42,     0,     0,
      44,    45,     0,    46,    47,     0,    48,    49,     0,     0,
       0,     0,     0,    52,     0,    54,     0,    56,     0,     0,
       0,     0,    59,   172,     0,     0,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,   173,     0,    72,     0,
       0,    74,     0,     0,     0,    78,     0,     0,    80,     0,
       0,    82,     0,     0,     0,     0,     0,     0,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,     0,     0,    93,    94,   530,
       0,     0,     0,    96,     0,   174,     0,    98,     0,   175,
       5,     6,     7,     8,     9,    10,     0,     0,     0,   166,
       0,     0,    14,    15,     0,    16,     0,   167,     0,     0,
      20,     0,     0,     0,     0,     0,     0,     0,   621,     0,
     168,     0,     0,     0,    31,   169,   170,     0,   171,    36,
       0,   622,     0,     0,    39,     0,     0,     0,    41,    42,
       0,     0,    44,    45,     0,    46,    47,     0,    48,    49,
       0,     0,     0,     0,     0,    52,     0,    54,     0,    56,
       0,     0,     0,     0,    59,   172,     0,     0,     0,     0,
       0,     0,     0,    66,   623,    68,    69,    70,   624,     0,
      72,     0,     0,    74,     0,     0,     0,    78,     0,     0,
      80,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,     0,     0,    93,
      94,   264,     0,     0,     0,    96,     0,   174,     0,    98,
       0,   947,     5,     6,     7,     8,     9,    10,     0,     0,
       0,   166,     0,     0,    14,    15,     0,    16,     0,   167,
       0,     0,    20,     0,     0,     0,     0,     0,     0,     0,
      27,     0,   168,     0,     0,     0,    31,   169,   170,     0,
     171,    36,     0,    37,     0,     0,    39,     0,     0,     0,
      41,    42,     0,     0,    44,    45,     0,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,    52,     0,    54,
       0,    56,     0,     0,     0,     0,    59,   172,     0,     0,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
     173,     0,    72,     0,     0,    74,     0,     0,     0,    78,
       0,     0,    80,     0,     0,    82,     0,     0,     0,     0,
       0,     0,     0,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,     0,
       0,    93,    94,   264,     0,     0,     0,    96,     0,   174,
       0,    98,     0,   947,     5,     6,     7,     8,     9,    10,
       0,     0,     0,   166,     0,     0,    14,    15,     0,    16,
       0,   167,     0,     0,    20,     0,     0,     0,     0,     0,
       0,     0,    27,     0,   168,     0,     0,     0,    31,   169,
     170,     0,   930,    36,     0,    37,     0,     0,    39,     0,
       0,     0,    41,    42,     0,     0,    44,    45,     0,    46,
      47,     0,    48,    49,     0,     0,     0,     0,     0,    52,
       0,    54,     0,    56,     0,     0,     0,     0,    59,   172,
       0,     0,     0,     0,     0,     0,     0,    66,    67,    68,
      69,    70,   173,     0,    72,     0,     0,    74,     0,     0,
       0,    78,     0,     0,    80,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,     0,     0,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,     0,     0,    93,    94,   264,     0,     0,     0,    96,
       0,   174,     0,    98,     0,   175,     5,     6,     7,     8,
       9,    10,     0,     0,     0,   166,     0,     0,    14,    15,
       0,    16,     0,   167,     0,     0,    20,     0,     0,     0,
       0,     0,     0,     0,    27,     0,   168,     0,     0,     0,
      31,   169,   170,     0,   171,    36,     0,    37,     0,     0,
      39,     0,     0,     0,    41,    42,     0,     0,    44,    45,
       0,    46,    47,     0,    48,    49,     0,     0,     0,     0,
       0,    52,     0,    54,     0,    56,     0,     0,     0,     0,
      59,   172,     0,     0,     0,     0,     0,     0,     0,    66,
      67,    68,    69,    70,   173,     0,    72,     0,     0,    74,
       0,     0,     0,    78,     0,     0,    80,     0,     0,    82,
       0,     0,     0,     0,     0,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,    90,     0,     0,
       0,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,     0,     0,    93,    94,     0,     0,     0,
       0,    96,     0,   174,     0,    98,     0,   175,     5,     6,
       7,     8,   196,    10,     0,     0,     0,   166,     0,     0,
      14,    15,     0,    16,     0,   167,     0,     0,    20,     0,
       0,     0,     0,     0,     0,     0,    27,     0,   168,     0,
       0,     0,    31,   169,   170,     0,   171,    36,     0,    37,
       0,     0,    39,     0,     0,     0,    41,    42,     0,     0,
      44,    45,     0,    46,    47,     0,    48,    49,     0,     0,
       0,     0,     0,    52,     0,    54,     0,    56,     0,     0,
       0,     0,    59,   197,     0,     0,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,   173,     0,    72,     0,
       0,    74,     0,     0,     0,    78,     0,     0,    80,     0,
       0,    82,     0,     0,     0,     0,     0,     0,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,     0,     0,    93,    94,     0,
       0,     0,     0,    96,     0,   174,     0,    98,     0,   175,
       5,     6,     7,     8,     9,    10,     0,     0,     0,   166,
       0,     0,    14,    15,     0,    16,     0,   167,     0,     0,
      20,     0,     0,     0,     0,     0,     0,     0,    27,     0,
     168,     0,     0,     0,    31,   169,   170,     0,   171,    36,
       0,    37,     0,     0,    39,     0,     0,     0,    41,    42,
       0,     0,    44,    45,     0,    46,    47,     0,    48,    49,
       0,     0,     0,     0,     0,    52,     0,    54,     0,    56,
       0,     0,     0,     0,    59,   172,     0,     0,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,   173,     0,
      72,     0,     0,    74,     0,     0,     0,    78,     0,     0,
      80,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,     0,     0,    93,
      94,     0,     0,     0,     0,    96,     0,    97,     0,    98,
       0,   175,     5,     6,     7,     8,     9,    10,     0,     0,
       0,   166,     0,     0,    14,    15,     0,    16,     0,   167,
       0,     0,    20,     0,     0,     0,     0,     0,     0,     0,
      27,     0,   168,     0,     0,     0,    31,   169,   170,     0,
     171,    36,     0,    37,     0,     0,    39,     0,     0,     0,
      41,    42,     0,     0,    44,    45,     0,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,    52,     0,    54,
       0,    56,     0,     0,     0,     0,    59,   172,     0,     0,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
     173,     0,    72,     0,     0,    74,     0,     0,     0,    78,
       0,     0,    80,     0,     0,    82,     0,     0,     0,     0,
       0,     0,     0,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,     0,
       0,    93,    94,     0,     0,     0,     0,   594,     0,   174,
       0,    98,     0,   175,     5,     6,     7,     8,     9,    10,
       0,     0,     0,   166,     0,     0,    14,    15,     0,    16,
       0,   167,     0,     0,    20,     0,     0,     0,     0,     0,
       0,     0,   621,     0,   168,     0,     0,     0,    31,   169,
     170,     0,   171,    36,     0,   622,     0,     0,    39,     0,
       0,     0,    41,    42,     0,     0,    44,    45,     0,    46,
      47,     0,    48,    49,     0,     0,     0,     0,     0,    52,
       0,    54,     0,    56,     0,     0,     0,     0,    59,   172,
       0,     0,     0,     0,     0,     0,     0,    66,   623,    68,
      69,    70,   624,     0,    72,     0,     0,    74,     0,     0,
       0,    78,     0,     0,    80,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,     0,     0,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,     0,     0,    93,    94,     0,     0,     0,     0,    96,
       0,   174,     0,    98,     0,   625,     5,     6,     7,     8,
       9,    10,     0,     0,     0,   166,     0,     0,    14,    15,
       0,    16,     0,   167,     0,     0,    20,     0,     0,     0,
       0,     0,     0,     0,    27,     0,   168,     0,     0,     0,
      31,   169,   170,     0,   171,    36,     0,    37,     0,     0,
      39,     0,     0,     0,    41,    42,     0,     0,    44,    45,
       0,    46,    47,     0,    48,    49,     0,     0,     0,     0,
       0,    52,     0,    54,     0,    56,     0,     0,     0,     0,
      59,   172,     0,     0,     0,     0,     0,     0,     0,    66,
      67,    68,    69,    70,   173,     0,    72,     0,     0,    74,
       0,     0,     0,    78,     0,     0,    80,     0,     0,    82,
       0,     0,     0,     0,     0,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,    90,     0,     0,
       0,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,     0,     0,    93,    94,     0,     0,     0,
       0,    96,     0,   174,     0,    98,     0,   625,     5,     6,
       7,     8,     9,    10,     0,     0,     0,   166,     0,     0,
      14,    15,     0,    16,     0,   167,     0,     0,    20,     0,
       0,     0,     0,     0,     0,     0,    27,     0,   168,     0,
       0,     0,    31,   169,   170,     0,   695,    36,     0,    37,
       0,     0,    39,     0,     0,     0,    41,    42,     0,     0,
      44,    45,     0,    46,    47,     0,    48,    49,     0,     0,
       0,     0,     0,    52,     0,    54,     0,    56,     0,     0,
       0,     0,    59,   172,     0,     0,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,   173,     0,    72,     0,
       0,    74,     0,     0,     0,    78,     0,     0,    80,     0,
       0,    82,     0,     0,     0,     0,     0,     0,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,     0,     0,    93,    94,     0,
       0,     0,     0,    96,     0,   174,     0,    98,     0,   175,
       5,     6,     7,     8,     9,    10,     0,     0,     0,   166,
       0,     0,    14,    15,     0,    16,     0,   167,     0,     0,
      20,     0,     0,     0,     0,     0,     0,     0,    27,     0,
     168,     0,     0,     0,    31,   169,   170,     0,   698,    36,
       0,    37,     0,     0,    39,     0,     0,     0,    41,    42,
       0,     0,    44,    45,     0,    46,    47,     0,    48,    49,
       0,     0,     0,     0,     0,    52,     0,    54,     0,    56,
       0,     0,     0,     0,    59,   172,     0,     0,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,   173,     0,
      72,     0,     0,    74,     0,     0,     0,    78,     0,     0,
      80,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,     0,     0,    93,
      94,     0,     0,     0,     0,    96,     0,   174,     0,    98,
       0,   175,     5,     6,     7,     8,     9,    10,     0,     0,
       0,   166,     0,     0,    14,    15,     0,    16,     0,   167,
       0,     0,    20,     0,     0,     0,     0,     0,     0,     0,
      27,     0,   168,     0,     0,     0,    31,   169,   170,     0,
     924,    36,     0,    37,     0,     0,    39,     0,     0,     0,
      41,    42,     0,     0,    44,    45,     0,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,    52,     0,    54,
       0,    56,     0,     0,     0,     0,    59,   172,     0,     0,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
     173,     0,    72,     0,     0,    74,     0,     0,     0,    78,
       0,     0,    80,     0,     0,    82,     0,     0,     0,     0,
       0,     0,     0,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,     0,
       0,    93,    94,     0,     0,     0,     0,    96,     0,   174,
       0,    98,     0,   175,     5,     6,     7,     8,     9,    10,
       0,     0,     0,   166,     0,     0,    14,    15,     0,    16,
       0,   167,     0,     0,    20,     0,     0,     0,     0,     0,
       0,     0,    27,     0,   168,     0,     0,     0,    31,   169,
     170,     0,   925,    36,     0,    37,     0,     0,    39,     0,
       0,     0,    41,    42,     0,     0,    44,    45,     0,    46,
      47,     0,    48,    49,     0,     0,     0,     0,     0,    52,
       0,    54,     0,    56,     0,     0,     0,     0,    59,   172,
       0,     0,     0,     0,     0,     0,     0,    66,    67,    68,
      69,    70,   173,     0,    72,     0,     0,    74,     0,     0,
       0,    78,     0,     0,    80,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,     0,     0,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,     0,     0,    93,    94,     0,     0,     0,     0,    96,
       0,   174,     0,    98,     0,   175,     5,     6,     7,     8,
       9,    10,     0,     0,     0,   166,     0,     0,    14,    15,
       0,    16,     0,   167,     0,     0,    20,     0,     0,     0,
       0,     0,     0,     0,    27,     0,   168,     0,     0,     0,
      31,   169,   170,     0,   927,    36,     0,    37,     0,     0,
      39,     0,     0,     0,    41,    42,     0,     0,    44,    45,
       0,    46,    47,     0,    48,    49,     0,     0,     0,     0,
       0,    52,     0,    54,     0,    56,     0,     0,     0,     0,
      59,   172,     0,     0,     0,     0,     0,     0,     0,    66,
      67,    68,    69,    70,   173,     0,    72,     0,     0,    74,
       0,     0,     0,    78,     0,     0,    80,     0,     0,    82,
       0,     0,     0,     0,     0,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,    90,     0,     0,
       0,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,     0,     0,    93,    94,     0,     0,     0,
       0,    96,     0,   174,     0,    98,     0,   175,     5,     6,
       7,     8,     9,    10,     0,     0,     0,   166,     0,     0,
      14,    15,     0,    16,     0,   167,     0,     0,    20,     0,
       0,     0,     0,     0,     0,     0,    27,     0,   168,     0,
       0,     0,    31,   169,   170,     0,   928,    36,     0,    37,
       0,     0,    39,     0,     0,     0,    41,    42,     0,     0,
      44,    45,     0,    46,    47,     0,    48,    49,     0,     0,
       0,     0,     0,    52,     0,    54,     0,    56,     0,     0,
       0,     0,    59,   172,     0,     0,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,   173,     0,    72,     0,
       0,    74,     0,     0,     0,    78,     0,     0,    80,     0,
       0,    82,     0,     0,     0,     0,     0,     0,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,     0,     0,    93,    94,     0,
       0,     0,     0,    96,     0,   174,     0,    98,     0,   175,
       5,     6,     7,     8,     9,    10,     0,     0,     0,   166,
       0,     0,    14,    15,     0,    16,     0,   167,     0,     0,
      20,     0,     0,     0,     0,     0,     0,     0,    27,     0,
     168,     0,     0,     0,    31,   169,   170,     0,   929,    36,
       0,    37,     0,     0,    39,     0,     0,     0,    41,    42,
       0,     0,    44,    45,     0,    46,    47,     0,    48,    49,
       0,     0,     0,     0,     0,    52,     0,    54,     0,    56,
       0,     0,     0,     0,    59,   172,     0,     0,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,   173,     0,
      72,     0,     0,    74,     0,     0,     0,    78,     0,     0,
      80,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,     0,     0,    93,
      94,     0,     0,     0,     0,    96,     0,   174,     0,    98,
       0,   175,     5,     6,     7,     8,     9,    10,     0,     0,
       0,   166,     0,     0,    14,    15,     0,    16,     0,   167,
       0,     0,    20,     0,     0,     0,     0,     0,     0,     0,
      27,     0,   168,     0,     0,     0,    31,   169,   170,     0,
     930,    36,     0,    37,     0,     0,    39,     0,     0,     0,
      41,    42,     0,     0,    44,    45,     0,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,    52,     0,    54,
       0,    56,     0,     0,     0,     0,    59,   172,     0,     0,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
     173,     0,    72,     0,     0,    74,     0,     0,     0,    78,
       0,     0,    80,     0,     0,    82,     0,     0,     0,     0,
       0,     0,     0,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,     0,
       0,    93,    94,     0,     0,     0,     0,    96,     0,   174,
       0,    98,     0,   175,     5,     6,     7,     8,     9,    10,
       0,     0,     0,   166,     0,     0,    14,    15,     0,    16,
       0,   167,     0,     0,    20,     0,     0,     0,     0,     0,
       0,     0,   621,     0,   168,     0,     0,     0,    31,   169,
     170,     0,   171,    36,     0,   622,     0,     0,    39,     0,
       0,     0,    41,    42,     0,     0,    44,    45,     0,    46,
      47,     0,    48,    49,     0,     0,     0,     0,     0,    52,
       0,    54,     0,    56,     0,     0,     0,     0,    59,   172,
       0,     0,     0,     0,     0,     0,     0,    66,   623,    68,
      69,    70,   624,     0,    72,     0,     0,    74,     0,     0,
       0,    78,     0,     0,    80,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,     0,     0,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,     0,     0,    93,    94,     0,     0,     0,     0,    96,
       0,   174,     0,    98,     0,  1014,     5,     6,     7,     8,
       9,    10,     0,     0,     0,   166,     0,     0,    14,    15,
       0,    16,     0,   167,     0,     0,    20,     0,     0,     0,
       0,     0,     0,     0,    27,     0,   168,     0,     0,     0,
      31,   169,   170,     0,   171,    36,     0,    37,     0,     0,
      39,     0,     0,     0,    41,    42,     0,     0,    44,    45,
       0,    46,    47,     0,    48,    49,     0,     0,     0,     0,
       0,    52,     0,    54,     0,    56,     0,     0,     0,     0,
      59,   172,     0,     0,     0,     0,     0,     0,     0,    66,
      67,    68,    69,    70,   173,     0,    72,     0,     0,    74,
       0,     0,     0,    78,     0,     0,    80,     0,     0,    82,
       0,     0,     0,     0,     0,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,    90,     0,     0,
       0,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,     0,     0,    93,    94,     0,     0,     0,
       0,    96,     0,     0,     0,    98,     0,  1014,     5,     6,
       7,     8,     9,    10,     0,     0,     0,   166,     0,     0,
      14,    15,     0,    16,     0,   167,     0,     0,    20,     0,
       0,     0,     0,     0,     0,     0,    27,     0,   168,     0,
       0,     0,    31,   169,   170,     0,   171,    36,     0,    37,
       0,     0,    39,     0,     0,     0,    41,    42,     0,     0,
      44,    45,     0,    46,    47,     0,    48,    49,     0,     0,
       0,     0,     0,    52,     0,    54,     0,    56,     0,     0,
       0,     0,    59,   172,     0,     0,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,   173,     0,    72,     0,
       0,    74,     0,     0,     0,    78,     0,     0,    80,     0,
       0,    82,     0,     0,     0,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
       5,     6,     7,     8,     9,    10,  -498,     0,     0,   166,
       0,     0,    14,    15,    92,    16,     0,   167,    94,   374,
      20,     0,  -525,    96,  -525,   174,     0,    98,    27,   175,
     168,     0,     0,     0,    31,   169,   170,     0,   171,    36,
       0,    37,     0,     0,    39,     0,     0,     0,    41,    42,
       0,     0,    44,    45,     0,    46,    47,     0,    48,    49,
       0,     0,     0,     0,     0,    52,     0,    54,     0,    56,
       0,     0,     0,     0,    59,   172,     0,     0,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,   173,     0,
      72,     0,     0,    74,     0,     0,     0,    78,     0,     0,
      80,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,     0,  -395,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88,
       0,     0,     0,  -395,     0,     0,     0,  -395,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   264,     0,     0,     0,     0,     0,   174,     0,    98,
    -395,   947,     5,     6,     7,     8,     9,    10,     0,     0,
       0,   166,     0,     0,    14,    15,     0,    16,     0,   167,
       0,     0,    20,     0,     0,     0,     0,     0,     0,     0,
      27,     0,   168,     0,     0,     0,    31,   169,   170,     0,
     171,    36,     0,    37,     0,     0,    39,     0,     0,     0,
      41,    42,  -377,     0,    44,    45,     0,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,    52,     0,    54,
       0,    56,     0,     0,     0,     0,    59,   172,     0,     0,
       0,  -377,     0,     0,     0,    66,    67,    68,    69,    70,
     173,     0,    72,     0,  -377,    74,     0,     0,     0,    78,
       0,     0,    80,     0,     0,    82,     0,  -377,     0,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,     0,     0,     0,     0,     0,     0,
       0,    88,     5,     6,     7,     8,     9,    10,     0,     0,
       0,   166,     0,     0,    14,    15,     0,    16,     0,   167,
       0,     0,    20,   374,  -377,     0,  -525,     0,  -525,  -377,
      27,    98,   168,  1014,     0,     0,    31,   169,   170,     0,
     171,    36,     0,    37,     0,     0,    39,     0,     0,     0,
      41,    42,     0,     0,    44,    45,     0,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,    52,     0,    54,
       0,    56,     0,     0,     0,     0,    59,   172,     0,     0,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
     173,     0,    72,     0,     0,    74,     0,     0,     0,    78,
       0,     0,    80,     0,     0,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,     5,     6,     7,     8,     9,    10,     0,     0,
       0,   166,     0,     0,    14,    15,     0,    16,     0,   167,
       0,     0,    20,     0,     0,     0,     0,     0,     0,   174,
      27,    98,   168,   175,     0,     0,    31,   169,   170,     0,
     171,    36,     0,    37,     0,     0,    39,     0,     0,     0,
      41,    42,     0,     0,    44,    45,     0,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,    52,     0,    54,
       0,    56,     0,     0,     0,     0,    59,   172,     0,     0,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
     173,     0,    72,     0,     0,    74,     0,     0,     0,    78,
       0,     0,    80,     0,     0,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,     5,     6,     7,     8,     9,    10,     0,     0,
       0,   166,     0,     0,    14,    15,     0,    16,     0,   167,
       0,     0,    20,     0,     0,     0,     0,     0,     0,   174,
      27,    98,   168,   625,     0,     0,    31,   169,   170,     0,
     171,    36,     0,    37,     0,     0,    39,     0,     0,     0,
      41,    42,     0,     0,    44,    45,     0,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,    52,     0,    54,
       0,    56,     0,     0,     0,     0,    59,   172,     0,     0,
       0,   216,     0,     0,     0,    66,    67,    68,    69,    70,
     173,     0,    72,   217,   218,    74,   219,     0,     0,    78,
       0,   220,    80,     0,     0,    82,     0,     0,     0,   221,
       0,     0,     0,     0,     0,   222,     0,     0,     0,     0,
     223,     0,   224,     0,     0,   225,     0,     0,     0,     0,
       0,    88,     0,   226,     0,     0,     0,     0,     0,   227,
     228,     0,     0,     0,     0,     0,   229,     0,     0,     0,
       0,     0,     0,     0,     0,   230,     0,     0,     0,     0,
     216,    98,     0,   175,   231,   232,     0,   233,     0,   234,
       0,   235,   217,   218,   236,   219,     0,     0,   237,     0,
     220,   238,     0,     0,   239,     0,     0,     0,   221,     0,
       0,     0,     0,     0,   222,     0,     0,     0,     0,   223,
       0,   224,     0,     0,   225,     0,     0,     0,     0,     0,
       0,     0,   226,     0,     0,     0,     0,   216,   227,   228,
       0,     0,     0,     0,     0,   229,     0,     0,     0,   217,
     218,     0,   219,     0,   230,     0,     0,   220,   387,     0,
     765,     0,     0,   231,   232,   221,   233,     0,   234,     0,
     235,   222,     0,   236,     0,     0,   223,   237,   224,     0,
     238,   225,     0,   239,     0,     0,     0,     0,     0,   226,
       0,     0,     0,     0,     0,   227,   228,     0,     0,     0,
       0,     0,   229,     0,     0,     0,     0,     0,     0,     0,
       0,   230,     0,     0,     0,     0,     0,     0,     0,     0,
     231,   232,     0,   233,     0,   234,     0,   235,     0,   975,
     236,     0,     0,     0,   237,     0,   789,   238,     0,   243,
     239,   217,   218,   791,   219,     0,     0,     0,     0,   220,
       0,     0,     0,     0,     0,     0,     0,   221,     0,     0,
       0,     0,     0,   794,     0,     0,     0,     0,   223,     0,
     224,     0,     0,   225,     0,   797,     0,     0,     0,     0,
       0,   226,     0,     0,     0,     0,     0,   799,   228,     0,
       0,     0,   330,     0,   229,     0,   745,     0,     0,   331,
       0,     0,     0,   230,     0,     0,     0,     0,     0,     0,
       0,   332,   231,   232,     0,   233,     0,   234,     0,   976,
       0,     0,   804,     0,     0,     0,   237,     0,     0,   238,
       0,     0,   239,     0,     0,     0,     0,     0,     0,     0,
       0,   359,   360,   361,   362,   363,   364,     0,     0,   367,
     368,   369,   370,   332,   372,   373,   807,   808,   809,   810,
     811,   333,     0,   812,     0,   334,     0,   813,   814,   815,
     816,   817,   818,   819,   820,   821,   822,   823,     0,   824,
     330,     0,   825,   826,   827,   828,     0,   331,     0,     0,
       0,     0,   418,     0,     0,     0,   335,     0,     0,   332,
       0,     0,     0,   333,     0,     0,     0,   334,     0,     0,
       0,     0,   336,   337,     0,   338,   339,   340,     0,   341,
     342,   343,     0,   344,   345,   346,   347,   348,     0,   349,
     350,   351,   352,   353,   354,   355,     0,   330,   356,   357,
     358,     0,     0,     0,   331,     0,     0,   773,     0,   333,
       0,     0,     0,   334,   336,   337,   332,   338,   339,   340,
       0,   341,   342,   343,     0,   344,   345,   346,   347,     0,
       0,   349,   350,   351,   352,   353,     0,   355,   330,     0,
     356,   357,   358,     0,   335,   331,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   332,     0,     0,
     336,   337,     0,   338,   339,   340,   333,   341,   342,   343,
     334,   344,   345,   346,   347,   348,     0,   349,   350,   351,
     352,   353,   354,   355,   330,     0,   356,   357,   358,     0,
       0,   331,     0,     0,     0,   849,     0,     0,     0,     0,
       0,   335,     0,   332,     0,     0,     0,   333,     0,     0,
       0,   334,     0,     0,     0,     0,     0,   336,   337,     0,
     338,   339,   340,     0,   341,   342,   343,     0,   344,   345,
     346,   347,   348,     0,   349,   350,   351,   352,   353,   354,
     355,   330,   335,   356,   357,   358,     0,     0,   331,     0,
       0,     0,  1010,   333,     0,     0,     0,   334,   336,   337,
     332,   338,   339,   340,     0,   341,   342,   343,     0,   344,
     345,   346,   347,   348,     0,   349,   350,   351,   352,   353,
     354,   355,     0,     0,   356,   357,   358,     0,   335,     0,
       0,     0,     0,  1077,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   336,   337,     0,   338,   339,   340,
     333,   341,   342,   343,   334,   344,   345,   346,   347,   348,
       0,   349,   350,   351,   352,   353,   354,   355,   330,     0,
     356,   357,   358,     0,     0,   331,     0,   646,     0,     0,
       0,     0,     0,     0,     0,   335,     0,   332,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   336,   337,     0,   338,   339,   340,     0,   341,   342,
     343,     0,   344,   345,   346,   347,   348,     0,   349,   350,
     351,   352,   353,   354,   355,     0,     0,   356,   357,   358,
       0,     0,     0,     0,   974,     0,     0,   333,     0,     0,
       0,   334,     0,     0,   330,     0,     0,     0,     0,     0,
     428,   331,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   332,     0,     0,     0,     0,     0,     0,
       0,     0,   335,   359,   360,   361,   362,   363,   364,     0,
       0,   367,   368,   369,   370,     0,   372,   373,   336,   337,
       0,   338,   339,   340,     0,   341,   342,   343,     0,   344,
     345,   346,   347,   348,     0,   349,   350,   351,   352,   353,
     354,   355,     0,   333,   356,   357,   358,   334,   387,     0,
     330,     0,     0,     0,     0,     0,   857,   331,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   332,
       0,     0,     0,     0,     0,     0,     0,     0,   335,   359,
     360,   361,   362,   363,   364,     0,     0,   367,   368,   369,
     370,     0,   372,   373,   336,   337,     0,   338,   339,   340,
       0,   341,   342,   343,     0,   344,   345,   346,   347,   348,
       0,   349,   350,   351,   352,   353,   354,   355,     0,   333,
     356,   357,   358,   334,   387,     0,   330,     0,     0,     0,
       0,     0,   864,   331,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   332,     0,     0,     0,     0,
       0,     0,     0,     0,   335,   359,   360,   361,   362,   363,
     364,     0,     0,   367,   368,   369,   370,     0,   372,   373,
     336,   337,     0,   338,   339,   340,     0,   341,   342,   343,
       0,   344,   345,   346,   347,   348,     0,   349,   350,   351,
     352,   353,   354,   355,     0,   333,   356,   357,   358,   334,
     387,     0,   330,     0,     0,     0,     0,     0,   987,   331,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   332,     0,     0,     0,     0,     0,     0,     0,     0,
     335,   359,   360,   361,   362,   363,   364,     0,     0,   367,
     368,   369,   370,     0,   372,   373,   336,   337,     0,   338,
     339,   340,     0,   341,   342,   343,     0,   344,   345,   346,
     347,   348,     0,   349,   350,   351,   352,   353,   354,   355,
       0,   333,   356,   357,   358,   334,   387,     0,   330,     0,
       0,     0,     0,     0,   988,   331,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   332,     0,     0,
       0,     0,     0,     0,     0,     0,   335,   359,   360,   361,
     362,   363,   364,     0,     0,   367,   368,   369,   370,     0,
     372,   373,   336,   337,     0,   338,   339,   340,     0,   341,
     342,   343,     0,   344,   345,   346,   347,   348,     0,   349,
     350,   351,   352,   353,   354,   355,     0,   333,   356,   357,
     358,   334,   387,     0,   330,     0,     0,     0,     0,     0,
     989,   331,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   332,     0,     0,     0,     0,     0,     0,
       0,     0,   335,   359,   360,   361,   362,   363,   364,     0,
       0,   367,   368,   369,   370,     0,   372,   373,   336,   337,
       0,   338,   339,   340,     0,   341,   342,   343,     0,   344,
     345,   346,   347,   348,     0,   349,   350,   351,   352,   353,
     354,   355,     0,   333,   356,   357,   358,   334,   387,     0,
     330,     0,     0,     0,     0,     0,   990,   331,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   332,
       0,     0,     0,     0,     0,     0,     0,     0,   335,   359,
     360,   361,   362,   363,   364,     0,     0,   367,   368,   369,
     370,     0,   372,   373,   336,   337,     0,   338,   339,   340,
       0,   341,   342,   343,     0,   344,   345,   346,   347,   348,
       0,   349,   350,   351,   352,   353,   354,   355,     0,   333,
     356,   357,   358,   334,   387,     0,   330,     0,     0,     0,
       0,     0,  1012,   331,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   332,     0,     0,     0,     0,
       0,     0,     0,     0,   335,   359,   360,   361,   362,   363,
     364,     0,     0,   367,   368,   369,   370,     0,   372,   373,
     336,   337,     0,   338,   339,   340,     0,   341,   342,   343,
       0,   344,   345,   346,   347,   348,     0,   349,   350,   351,
     352,   353,   354,   355,     0,   333,   356,   357,   358,   334,
     387,     0,     0,     0,     0,     0,     0,     0,  1013,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     335,   359,   360,   361,   362,   363,   364,     0,     0,   367,
     368,   369,   370,     0,   372,   373,   336,   337,     0,   338,
     339,   340,     0,   341,   342,   343,     0,   344,   345,   346,
     347,   348,     0,   349,   350,   351,   352,   353,   354,   355,
     330,     0,   356,   357,   358,     0,   387,   331,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   332,
     421,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   330,   422,     0,     0,     0,     0,     0,   331,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   332,   415,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   416,     0,     0,     0,   333,
       0,     0,     0,   334,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   330,
       0,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     418,   333,     0,     0,   335,   334,     0,     0,   332,   728,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     336,   337,     0,   338,   339,   340,     0,   341,   342,   343,
       0,   344,   345,   346,   347,   348,   335,   349,   350,   351,
     352,   353,   354,   355,     0,     0,   356,   357,   358,     0,
     387,     0,   336,   337,     0,   338,   339,   340,   333,   341,
     342,   343,   334,   344,   345,   346,   347,   348,     0,   349,
     350,   351,   352,   353,   354,   355,   330,     0,   356,   357,
     358,     0,   387,   331,     0,     0,     0,     0,     0,   418,
       0,     0,     0,   335,     0,   332,   247,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   336,
     337,     0,   338,   339,   340,     0,   341,   342,   343,     0,
     344,   345,   346,   347,   348,     0,   349,   350,   351,   352,
     353,   354,   355,   330,     0,   356,   357,   358,     0,   387,
     331,     0,     0,     0,     0,   333,     0,     0,     0,   334,
       0,     0,   332,   720,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   330,     0,     0,     0,     0,
       0,     0,   331,     0,     0,     0,     0,     0,     0,     0,
     335,     0,     0,     0,   332,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   336,   337,     0,   338,
     339,   340,   333,   341,   342,   343,   334,   344,   345,   346,
     347,   348,     0,   349,   350,   351,   352,   353,   354,   355,
       0,     0,   356,   357,   358,     0,   387,     0,     0,     0,
       0,     0,     0,     0,   333,     0,     0,   335,   334,     0,
       0,     0,     0,     0,     0,     0,     0,   738,     0,     0,
       0,     0,     0,   336,   337,     0,   338,   339,   340,     0,
     341,   342,   343,     0,   344,   345,   346,   347,   348,   335,
     349,   350,   351,   352,   353,   354,   355,     0,     0,   356,
     357,   358,     0,   387,     0,   336,   337,     0,   338,   339,
     340,     0,   341,   342,   343,     0,   344,   345,   346,   347,
     348,     0,   349,   350,   351,   352,   353,   354,   355,   330,
       0,   356,   357,   358,     0,   387,   331,     0,  -210,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   332,     0,
    -210,  -210,     0,  -210,     0,     0,     0,     0,  -210,     0,
       0,   330,     0,     0,     0,     0,  -210,     0,   331,     0,
       0,     0,  -210,     0,     0,     0,     0,  -210,     0,  -210,
     332,     0,  -210,     0,     0,   425,     0,     0,     0,     0,
    -210,     0,     0,     0,     0,     0,  -210,  -210,   333,     0,
       0,     0,   334,  -210,     0,     0,     0,     0,     0,     0,
       0,     0,  -210,     0,     0,   426,     0,     0,   330,     0,
       0,  -210,  -210,     0,  -210,   331,  -210,     0,  -210,     0,
     333,  -210,     0,   335,   334,  -210,     0,   332,  -210,     0,
       0,  -210,     0,     0,     0,     0,     0,     0,     0,   336,
     337,   389,   338,   339,   340,     0,   341,   342,   343,     0,
     344,   345,   346,   347,   348,   335,   349,   350,   351,   352,
     353,   354,   355,     0,     0,   356,   357,   358,     0,   455,
       0,   336,   337,     0,   338,   339,   340,   333,   341,   342,
     343,   334,   344,   345,   346,   347,   348,     0,   349,   350,
     351,   352,   353,   354,   355,   330,   427,   356,   357,   358,
       0,     0,   331,     0,     0,     0,     0,     0,   161,     0,
       0,     0,   335,     0,   332,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   336,   337,
       0,   338,   339,   340,     0,   341,   342,   343,     0,   344,
     345,   346,   347,   348,     0,   349,   350,   351,   352,   353,
     354,   355,   330,     0,   356,   357,   358,     0,     0,   331,
       0,     0,     0,     0,   333,     0,     0,     0,   334,     0,
       0,   332,   557,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   330,   558,     0,     0,     0,     0,
       0,   331,     0,     0,     0,     0,     0,     0,     0,   335,
       0,     0,     0,   332,   559,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   336,   337,   560,   338,   339,
     340,   333,   341,   342,   343,   334,   344,   345,   346,   347,
     348,     0,   349,   350,   351,   352,   353,   354,   355,     0,
     459,   356,   357,   358,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   333,     0,     0,   335,   334,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   336,   337,     0,   338,   339,   340,     0,   341,
     342,   343,     0,   344,   345,   346,   347,   348,   335,   349,
     350,   351,   352,   353,   354,   355,     0,     0,   356,   357,
     358,     0,     0,     0,   336,   337,     0,   338,   339,   340,
       0,   341,   342,   343,     0,   344,   345,   346,   347,   348,
       0,   349,   350,   351,   352,   353,   354,   355,   330,     0,
     356,   357,   358,     0,     0,   331,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   332,     0,     0,
       0,     0,   666,     0,     0,     0,     0,     0,     0,     0,
     330,     0,     0,     0,     0,     0,     0,   331,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   332,
       0,     0,   667,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   333,     0,     0,
       0,   334,     0,     0,     0,     0,     0,     0,     0,   330,
       0,     0,     0,     0,     0,     0,   331,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   332,   333,
       0,     0,   335,   334,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   336,   337,
       0,   338,   339,   340,     0,   341,   342,   343,     0,   344,
     345,   346,   347,   348,   335,   349,   350,   351,   352,   353,
     354,   355,     0,     0,   356,   357,   358,     0,   333,     0,
     336,   337,   334,   338,   339,   340,     0,   341,   342,   343,
       0,   344,   345,   346,   347,   348,     0,   349,   350,   351,
     352,   353,   354,   355,   330,   461,   356,   357,   358,     0,
       0,   331,     0,   335,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   332,     0,     0,     0,     0,     0,   336,
     337,     0,   338,   339,   340,     0,   341,   342,   343,     0,
     344,   345,   346,   347,   348,     0,   349,   350,   351,   352,
     353,   354,   355,   330,   463,   356,   357,   358,     0,     0,
     331,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   332,   333,     0,     0,     0,   334,     0,     0,
       0,     0,     0,     0,     0,   330,     0,     0,     0,     0,
       0,     0,   331,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   332,     0,     0,     0,   335,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   333,     0,   336,   337,   334,   338,   339,   340,
       0,   341,   342,   343,     0,   344,   345,   346,   347,   348,
       0,   349,   350,   351,   352,   353,   354,   355,     0,   468,
     356,   357,   358,     0,   333,     0,   485,   335,   334,     0,
       0,     0,     0,     0,     0,     0,     0,   561,     0,     0,
       0,     0,     0,   336,   337,     0,   338,   339,   340,     0,
     341,   342,   343,     0,   344,   345,   346,   347,   348,   335,
     349,   350,   351,   352,   353,   354,   355,     0,     0,   356,
     357,   358,     0,     0,     0,   336,   337,     0,   338,   339,
     340,     0,   341,   342,   343,     0,   344,   345,   346,   347,
     348,     0,   349,   350,   351,   352,   353,   354,   355,   330,
       0,   356,   357,   358,     0,     0,   331,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   332,     0,
     258,     0,     0,     0,    21,    22,     0,     0,     0,     0,
       0,     0,     0,   259,     0,    29,   260,     0,     0,     0,
      34,     0,     0,     0,   330,    38,     0,     0,     0,     0,
       0,   331,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   332,     0,     0,     0,    51,   333,    53,
       0,    55,   334,   906,     0,     0,   907,     0,   261,     0,
      61,     0,     0,     0,     0,   330,     0,     0,     0,     0,
       0,     0,   331,     0,     0,     0,     0,     0,     0,    77,
       0,     0,    79,   335,   332,    81,     0,     0,     0,     0,
       0,     0,     0,   333,     0,     0,     0,   334,     0,   336,
     337,     0,   338,   339,   340,     0,   341,   342,   343,     0,
     344,   345,   346,   347,   348,  -499,   349,   350,   351,   352,
     353,   354,   355,     0,   161,   356,   357,   358,   335,     0,
       0,     0,     0,     0,   333,    95,     0,     0,   334,     0,
       0,   934,     0,     0,   336,   337,     0,   338,   339,   340,
       0,   341,   342,   343,     0,   344,   345,   346,   347,   348,
       0,   349,   350,   351,   352,   353,   354,   355,     0,   335,
     356,   357,   358,     0,     0,     0,   330,   733,     0,     0,
       0,     0,     0,   331,     0,   336,   337,     0,   338,   339,
     340,     0,   341,   342,   343,   332,   344,   345,   346,   347,
     348,     0,   349,   350,   351,   352,   353,   354,   355,     0,
     705,   356,   357,   358,     0,     0,   330,     0,     0,     0,
       0,     0,     0,   331,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   332,     0,     0,   736,     0,
       0,     0,     0,     0,     0,   333,     0,     0,     0,   334,
       0,     0,     0,     0,     0,     0,     0,   330,     0,     0,
       0,     0,     0,     0,   331,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   332,     0,     0,     0,
     335,     0,     0,     0,     0,   333,     0,     0,     0,   334,
       0,     0,     0,     0,     0,     0,   336,   337,     0,   338,
     339,   340,     0,   341,   342,   343,     0,   344,   345,   346,
     347,   348,     0,   349,   350,   351,   352,   353,   354,   355,
     335,     0,   356,   357,   358,     0,   333,     0,     0,     0,
     334,     0,     0,     0,     0,     0,   336,   337,     0,   338,
     339,   340,     0,   341,   342,   343,     0,   344,   345,   346,
     347,   348,     0,   349,   350,   351,   352,   353,   354,   355,
     776,   335,   356,   357,   358,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   336,   337,     0,
     338,   339,   340,     0,   341,   342,   343,     0,   344,   345,
     346,   347,   348,     0,   349,   350,   351,   352,   353,   354,
     355,   330,     0,   356,   357,   358,     0,     0,   331,     0,
    -220,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     332,   844,  -220,  -220,     0,  -220,     0,     0,     0,     0,
    -220,     0,     0,   330,     0,     0,     0,     0,  -220,     0,
     331,     0,     0,     0,  -220,     0,     0,     0,     0,  -220,
       0,  -220,   332,   847,  -220,     0,     0,     0,     0,     0,
       0,     0,  -220,     0,     0,     0,     0,     0,  -220,  -220,
     333,     0,     0,     0,   334,  -220,     0,     0,     0,     0,
       0,     0,     0,     0,  -220,     0,     0,     0,     0,     0,
       0,     0,     0,  -220,  -220,     0,  -220,     0,  -220,     0,
    -220,     0,   333,  -220,     0,   335,   334,  -220,     0,     0,
    -220,     0,     0,  -220,     0,     0,     0,     0,     0,     0,
       0,   336,   337,     0,   338,   339,   340,     0,   341,   342,
     343,     0,   344,   345,   346,   347,   348,   335,   349,   350,
     351,   352,   353,   354,   355,     0,     0,   356,   357,   358,
       0,     0,     0,   336,   337,     0,   338,   339,   340,     0,
     341,   342,   343,     0,   344,   345,   346,   347,   348,     0,
     349,   350,   351,   352,   353,   354,   355,   330,     0,   356,
     357,   358,     0,     0,   331,     0,   216,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   332,     0,   217,   218,
       0,   219,     0,     0,     0,     0,   220,     0,     0,   330,
       0,     0,     0,     0,   221,     0,   331,     0,     0,     0,
     222,     0,     0,     0,     0,   223,     0,   224,   332,     0,
     225,     0,     0,     0,     0,     0,     0,     0,   226,     0,
       0,     0,     0,     0,   227,   228,   333,     0,     0,     0,
     334,   229,     0,     0,     0,     0,     0,     0,     0,   923,
     230,     0,     0,     0,     0,     0,   330,   942,     0,   231,
     232,     0,   233,   331,   234,     0,   235,     0,   333,   236,
       0,   335,   334,   237,     0,   332,   238,     0,     0,   239,
       0,   926,     0,     0,     0,     0,     0,   336,   337,     0,
     338,   339,   340,     0,   341,   342,   343,     0,   344,   345,
     346,   347,   348,   335,   349,   350,   351,   352,   353,   354,
     355,     0,     0,   356,   357,   358,     0,     0,     0,   336,
     337,     0,   338,   339,   340,   333,   341,   342,   343,   334,
     344,   345,   346,   347,   348,     0,   349,   350,   351,   352,
     353,   354,   355,   330,     0,   356,   357,   358,     0,     0,
     331,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     335,     0,   332,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   336,   337,     0,   338,
     339,   340,     0,   341,   342,   343,     0,   344,   345,   346,
     347,   348,     0,   349,   350,   351,   352,   353,   354,   355,
       0,     0,   356,   357,   358,     0,     0,   332,     0,     0,
       0,     0,   333,     0,     0,     0,   334,     0,     0,   330,
       0,     0,     0,     0,     0,  1023,   331,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   332,     0,
       0,     0,     0,     0,     0,     0,     0,   335,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   333,     0,     0,
       0,   334,     0,   336,   337,     0,   338,   339,   340,     0,
     341,   342,   343,     0,   344,   345,   346,   347,   348,     0,
     349,   350,   351,   352,   353,   354,   355,     0,   333,   356,
     357,   358,   334,     0,     0,   330,     0,     0,     0,     0,
       0,  1024,   331,     0,     0,     0,     0,     0,   336,   337,
       0,   338,   339,   340,   332,   341,   342,   343,     0,     0,
     345,   346,   347,   335,     0,   349,   350,   351,   352,     0,
       0,   355,     0,     0,   356,   357,   358,     0,     0,   336,
     337,     0,   338,   339,   340,     0,   341,   342,   343,     0,
     344,   345,   346,   347,   348,     0,   349,   350,   351,   352,
     353,   354,   355,     0,   333,   356,   357,   358,   334,     0,
       0,   330,     0,     0,     0,     0,     0,  1025,   331,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     332,     0,     0,     0,     0,     0,     0,     0,     0,   335,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   336,   337,     0,   338,   339,
     340,     0,   341,   342,   343,     0,   344,   345,   346,   347,
     348,     0,   349,   350,   351,   352,   353,   354,   355,     0,
     333,   356,   357,   358,   334,     0,     0,   330,     0,     0,
       0,     0,     0,  1026,   331,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   332,     0,     0,     0,
       0,     0,     0,     0,     0,   335,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   336,   337,     0,   338,   339,   340,     0,   341,   342,
     343,     0,   344,   345,   346,   347,   348,     0,   349,   350,
     351,   352,   353,   354,   355,     0,   333,   356,   357,   358,
     334,     0,     0,   330,     0,     0,     0,     0,     0,  1027,
     331,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   332,     0,     0,     0,     0,     0,     0,     0,
       0,   335,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   336,   337,     0,
     338,   339,   340,     0,   341,   342,   343,     0,   344,   345,
     346,   347,   348,     0,   349,   350,   351,   352,   353,   354,
     355,     0,   333,   356,   357,   358,   334,     0,     0,   330,
       0,     0,     0,     0,     0,  1028,   331,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   332,     0,
       0,     0,     0,     0,     0,     0,     0,   335,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1050,   336,   337,     0,   338,   339,   340,     0,
     341,   342,   343,     0,   344,   345,   346,   347,   348,     0,
     349,   350,   351,   352,   353,   354,   355,     0,   333,   356,
     357,   358,   334,     0,     0,   330,     0,     0,     0,     0,
       0,     0,   331,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   332,     0,     0,     0,     0,     0,
       0,     0,     0,   335,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   336,
     337,     0,   338,   339,   340,     0,   341,   342,   343,     0,
     344,   345,   346,   347,   348,     0,   349,   350,   351,   352,
     353,   354,   355,     0,   333,   356,   357,   358,   334,     0,
       0,   330,     0,     0,     0,     0,     0,     0,   331,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     332,     0,     0,     0,     0,     0,     0,     0,     0,   335,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   336,   337,     0,   338,   339,
     340,     0,   341,   342,   343,     0,   344,   345,   346,   347,
     348,     0,   349,   350,   351,   352,   353,   354,   355,     0,
     693,   356,   357,   358,   334,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   335,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   336,   337,     0,   338,   339,   340,     0,   341,   342,
     343,     0,   344,   345,   346,   347,   348,     0,   349,   350,
     351,   352,   353,   354,   355,     0,   258,   356,   357,   358,
      21,    22,     0,     0,     0,     0,     0,     0,     0,   259,
     258,    29,   260,     0,    21,    22,    34,     0,     0,     0,
       0,    38,     0,   259,     0,    29,   260,     0,     0,     0,
      34,     0,     0,     0,   332,    38,     0,     0,     0,     0,
       0,     0,     0,    51,     0,    53,     0,    55,     0,   906,
       0,     0,   907,     0,   261,     0,    61,    51,     0,    53,
       0,    55,     0,   906,     0,     0,   907,     0,   261,     0,
      61,     0,     0,     0,   332,    77,     0,     0,    79,     0,
       0,    81,     0,     0,   333,     0,     0,     0,   334,    77,
       0,     0,    79,     0,     0,    81,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   335,
       0,     0,     0,     0,   333,     0,     0,     0,   334,     0,
       0,    95,     0,     0,     0,   336,   337,   985,   338,   339,
     340,     0,   341,   342,   343,    95,   344,   345,   346,   347,
       0,   986,   349,   350,   351,   352,   353,   354,   355,   335,
       0,   356,   357,   358,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   336,   337,     0,   338,   339,
     340,     0,   341,   342,   343,     0,   344,   345,   346,   347,
       0,     0,   349,   350,   351,   352,   353,   670,   355,   216,
       0,   356,   357,   358,     0,     0,     0,     0,     0,     0,
       0,   217,   218,     0,   219,     0,     0,     0,     0,   220,
       0,     0,     0,     0,     0,     0,     0,   221,     0,     0,
       0,     0,     0,   222,     0,     0,     0,     0,   223,     0,
     224,     0,     0,   225,     0,     0,     0,     0,     0,     0,
       0,   226,     0,     0,     0,     0,  -211,   227,   228,     0,
       0,     0,     0,     0,   229,     0,     0,     0,  -211,  -211,
       0,  -211,     0,   230,     0,     0,  -211,     0,     0,     0,
       0,     0,   231,   232,  -211,   233,     0,   234,     0,   235,
    -211,     0,   236,     0,     0,  -211,   237,  -211,     0,   238,
    -211,     0,   239,     0,     0,     0,     0,     0,  -211,     0,
       0,     0,     0,     0,  -211,  -211,     0,     0,     0,     0,
       0,  -211,     0,     0,     0,     0,     0,     0,     0,     0,
    -211,     0,     0,     0,     0,     0,     0,     0,     0,  -211,
    -211,     0,  -211,     0,  -211,     0,  -211,     0,     0,  -211,
       0,     0,     0,  -211,     0,     0,  -211,     0,     0,  -211
};

static const yytype_int16 yycheck[] =
{
      11,   146,   436,     2,    15,    62,   464,   380,    19,    57,
      58,    18,   187,   426,    25,   133,   754,   957,    29,    30,
     679,    32,    33,    34,    35,   587,     1,   780,   203,   215,
      21,    43,    43,   404,    45,    46,     1,   408,   620,    50,
       1,    52,    99,    54,   210,   710,   195,     1,   713,    43,
       3,    62,    63,    64,    65,    66,    67,   880,    30,     3,
      71,    43,    73,   155,    75,    76,   215,   877,   110,    80,
     188,   257,    83,    84,    43,    86,   110,    88,   834,   835,
      91,    92,    30,    94,   136,    63,    97,    98,    99,    43,
      65,   441,    53,   279,    30,    30,    53,   130,   110,    30,
     853,   839,   855,     0,   130,   138,   433,  1040,   257,    43,
     692,    48,   138,   165,   464,    65,     1,  1057,   175,   155,
      98,    82,    43,   165,   136,   161,   110,   995,   690,    82,
     279,   165,   107,    32,    33,     3,   946,    74,   110,    43,
      93,   286,   136,   881,  1077,   311,   312,   108,   971,    93,
     115,   108,    82,   165,   136,   166,   909,   107,   169,   170,
     171,   115,   173,   174,   175,    82,   108,   136,    53,   751,
     135,   136,  1040,    80,   135,   110,    80,  1055,   931,   186,
     933,   135,   136,   165,   195,   619,   161,   852,   160,   854,
     376,   377,    25,   342,   136,  1073,   165,    82,   163,   160,
      99,   155,   136,   574,   215,   136,   577,   945,   199,    25,
      95,   161,   160,   204,   587,   136,   136,     2,    25,   162,
     211,   977,   978,   108,   160,   160,    11,   376,   377,   160,
     160,   165,    25,   136,  1001,   155,    69,    43,   155,    24,
     136,    26,   136,   160,   165,   155,   257,    80,   162,   260,
     135,   161,   155,    69,   667,    53,   994,   268,   269,     7,
     919,    79,    69,   320,    80,    83,    99,   163,   279,   163,
     155,   457,   105,    80,    80,   160,    69,  1044,  1045,  1046,
    1047,  1048,  1049,   136,    82,   162,    71,    80,   406,   105,
      75,    76,    99,   411,   136,   306,   136,    95,   136,    79,
     862,    90,   155,    83,   303,   162,    99,   164,   457,   320,
     108,   745,    97,   155,   162,   155,   101,   690,   329,   330,
     331,   332,   333,   334,   335,   163,   337,   338,   339,   340,
     341,   136,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   136,    43,
      75,    76,   136,   136,   365,   366,   413,   155,   163,   136,
     371,     3,   160,   374,   375,   376,   377,   378,   379,   380,
     115,    65,   162,   136,   164,   163,    18,   162,   389,   163,
     163,    75,    76,   394,   136,   396,   163,   365,   366,    31,
     162,   136,   164,   371,    29,   140,   374,   375,   160,    53,
     163,   136,   413,    25,   415,   416,   136,    98,   136,   161,
     421,   422,   115,    55,   425,   426,   743,   428,   163,   430,
     155,   136,   104,    45,   573,   591,   592,   155,    82,   887,
      75,   161,   443,   136,   333,   334,   155,   140,   495,   450,
     155,    95,   154,     2,    79,    67,   457,    69,    83,   155,
     155,    93,    11,   780,   108,   240,   115,    99,    80,   146,
     163,   472,   247,   199,   475,    24,   477,    26,   204,   644,
     481,   482,   483,   162,   485,   486,   162,   155,   164,   378,
     379,   140,   155,   105,   495,   155,   155,   653,   654,   862,
     389,   185,   491,   155,   475,   130,   477,   475,    53,   477,
     135,   155,   155,   138,   195,   138,   160,   142,   160,   162,
      78,   164,    71,   207,   208,   209,   210,   416,   303,   155,
     214,   109,    78,   422,   215,    29,   853,    82,   855,   155,
     880,   162,   317,   162,   679,   162,   135,   887,    97,   138,
      95,   115,   101,   142,   155,     7,   557,   558,   559,   560,
     561,   562,   563,   108,    57,   135,   250,   564,   565,   253,
     571,   155,   573,   115,   160,   115,   257,   136,   625,   155,
     581,   163,   583,    43,    32,    79,   587,   162,   589,    83,
     163,   275,   481,   136,   163,   115,   163,   914,   279,   141,
     163,   143,   144,   571,    19,   147,   148,   136,   165,   293,
     155,   165,   387,   162,   931,   160,   933,   155,   162,   160,
     155,   155,   623,   624,   625,   155,   163,   155,   629,   165,
     155,   971,   136,   160,   160,    32,   130,   131,   155,   155,
     415,   135,   163,   137,   138,   163,   421,   161,   142,   136,
     161,     2,   115,   428,    80,   995,   150,   163,    30,    30,
      11,   629,   156,   157,   158,   666,   667,   165,   160,   558,
    1010,   560,   160,    24,    32,    26,   135,    80,   135,   165,
     165,   165,   155,   155,   161,   138,   162,   138,   138,   690,
     130,   240,   693,   694,   695,   376,   377,   698,   247,   138,
    1040,    29,   138,   138,   479,   130,   390,   138,   483,   138,
     138,   130,   130,    32,   761,  1055,   491,   718,   138,   720,
      71,   138,   130,    29,   725,   138,   163,   728,    95,   163,
     731,   130,   733,  1073,   130,   736,   420,  1077,   165,   667,
     424,   136,   783,   317,    25,    23,    97,   666,   287,   919,
     101,    79,   765,   914,   303,    83,   743,   612,   786,  1057,
     761,    43,    43,   994,  1019,    46,  1050,  1043,   317,   450,
     771,    53,   773,    79,    34,   776,   457,    83,   444,   573,
      29,   782,    -1,    -1,   919,    66,    -1,    -1,    69,    -1,
      71,   472,    -1,    -1,   475,    -1,   477,    -1,    -1,    80,
      82,   482,   130,    -1,   693,   694,    -1,   135,    -1,   137,
     138,   162,    -1,    -1,   142,    -1,    -1,    -1,    99,    -1,
      -1,    -1,   150,    -1,   130,    -1,   108,   602,   829,   135,
     158,   137,   138,   115,    -1,    -1,   142,    -1,   387,    -1,
      -1,    -1,   843,   844,   150,   846,   847,   848,   849,    -1,
     156,   157,   158,    -1,   136,   136,   857,   858,    -1,   860,
      -1,   862,    -1,   864,   865,    -1,   415,   868,   906,   907,
      -1,    -1,   421,   155,    -1,    -1,    -1,   652,   160,   428,
      -1,   163,   163,   658,    -1,   886,   887,    -1,    -1,   240,
     571,   892,   573,   894,    25,    -1,   247,   898,    -1,    -1,
     947,   585,   586,    -1,    -1,    -1,    -1,   591,   592,    -1,
      -1,    -1,    43,    -1,    -1,    46,    -1,    -1,    -1,   603,
      -1,    -1,   923,   924,   925,   926,   927,   928,   929,   930,
     479,    -1,    -1,    -1,   483,    66,    -1,    -1,    69,    -1,
      71,   942,   491,   718,    -1,   720,   947,    -1,    -1,    80,
     725,   952,   303,   728,    -1,   956,   640,    -1,     3,    -1,
     735,    -1,    -1,   738,    -1,    -1,   317,  1014,    99,    -1,
      15,    -1,    -1,    18,    -1,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    43,    -1,    -1,   760,   987,   988,   989,   990,
      -1,    -1,    53,    -1,    -1,    -1,   771,    42,   773,    -1,
      -1,    -1,    47,    -1,    -1,   554,    -1,    65,    -1,  1010,
      55,  1012,  1013,  1014,    -1,    -1,    25,    62,    -1,   703,
     704,    82,  1023,  1024,  1025,  1026,  1027,  1028,    -1,    -1,
      -1,   715,    77,   717,    43,    -1,   387,    46,  1039,  1040,
     724,  1042,    43,   727,    89,    -1,   730,   108,    93,    -1,
      -1,    -1,    53,   602,   115,   100,    -1,    66,    -1,    -1,
      69,   106,    71,    -1,   415,    -1,    -1,    -1,    -1,    -1,
     421,    80,  1073,    -1,    -1,   136,  1077,   428,    -1,    -1,
      -1,    82,   857,    -1,   768,    -1,    -1,    -1,     2,   864,
      99,    -1,    -1,    -1,   155,    -1,    -1,    11,    -1,   160,
      -1,   876,   163,   652,    -1,    -1,    -1,   108,    -1,   658,
      24,    -1,    26,   888,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   897,    -1,    -1,    -1,   901,    -1,   479,    -1,
     679,    -1,   483,    -1,    -1,   136,    -1,    -1,    -1,    -1,
     491,    -1,    -1,    -1,   693,   694,    -1,    -1,    -1,   207,
     208,   209,   210,    -1,   155,    -1,    -1,    71,    -1,   160,
      -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,   943,   718,
      -1,   720,    -1,    -1,    -1,    -1,   725,    -1,    -1,   728,
      -1,    -1,    -1,    97,    -1,    -1,   735,   101,    -1,   738,
      29,    -1,   250,    -1,    -1,   253,    -1,    -1,    -1,   880,
      -1,    -1,    -1,    -1,    -1,    -1,   890,    -1,    -1,    -1,
      -1,   760,   987,   988,   989,   990,    -1,   275,    -1,    -1,
      -1,    -1,   771,    -1,   773,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   293,    -1,  1012,  1013,    -1,
      79,    -1,    -1,    -1,    83,    -1,    -1,    -1,   162,    -1,
      -1,   602,   936,   937,    -1,    -1,   940,   941,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     2,    -1,    -1,    -1,
      29,   952,    -1,   957,    -1,    11,    -1,    -1,    -1,   963,
      -1,   965,    -1,   967,    -1,    -1,    -1,    -1,    24,    -1,
      26,   130,   131,    -1,   133,   134,   135,    -1,   137,   138,
      -1,   652,    -1,   142,    -1,    -1,    -1,   658,   857,    -1,
      -1,   150,    -1,    -1,   995,   864,    -1,   156,   157,   158,
      79,    -1,    -1,    -1,    83,    -1,   240,   876,    -1,    -1,
      -1,    -1,   390,   247,    -1,    71,    -1,    -1,    -1,   888,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   897,    -1,
      -1,    -1,   901,    -1,    -1,    -1,    -1,    -1,    -1,  1040,
      -1,    97,   420,    -1,    -1,   101,   424,   718,    -1,   720,
      -1,   130,   131,  1057,   725,   134,   135,   728,   137,   138,
      -1,    -1,    -1,   142,   735,    -1,    -1,   738,    -1,   303,
      -1,   150,    -1,    -1,   943,    -1,  1077,   156,   157,   158,
      -1,    -1,    -1,   317,    -1,    -1,    -1,    -1,    20,   760,
      -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
     771,    33,   773,    35,    36,    -1,   162,    -1,    40,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    48,    -1,   987,   988,
     989,   990,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     2,    -1,    -1,    67,    -1,    69,    -1,    -1,
      -1,    11,    74,  1012,  1013,    -1,    78,    -1,    80,    -1,
      -1,    -1,    -1,   387,    24,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
     102,    -1,   104,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   415,    -1,    -1,   240,    -1,   857,   421,    -1,    -1,
      -1,   247,    -1,   864,   428,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    -1,   876,    -1,   585,   586,    -1,
      -1,    -1,    -1,   591,   592,    -1,    -1,   888,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   897,    97,    -1,    -1,
     901,   101,     1,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   479,    -1,   303,    -1,   483,
      -1,    20,    -1,    -1,    -1,    24,    25,   491,    -1,    -1,
      -1,   317,    -1,    -1,    33,    -1,    35,    36,    -1,    -1,
      -1,    40,   943,    77,    -1,    -1,    45,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    -1,    -1,     2,    -1,    -1,    -1,
      -1,    -1,   162,    -1,    -1,    11,    -1,    -1,    67,    -1,
      69,    -1,    71,    -1,    73,    74,    -1,    76,    24,    78,
      26,    80,    -1,    -1,    -1,    -1,   987,   988,   989,   990,
      -1,    -1,   126,    -1,   128,   703,   704,    -1,    -1,    -1,
      99,   387,    -1,   102,    -1,    -1,   105,   715,    -1,    -1,
      -1,  1012,  1013,    -1,    -1,     2,    -1,    -1,    -1,   727,
      -1,    -1,   730,    -1,    11,    71,    -1,    -1,    -1,   415,
      -1,    -1,    -1,    -1,    -1,   421,    -1,    24,   602,    26,
     240,    -1,   428,    -1,    -1,    -1,    -1,   247,    -1,    -1,
      -1,    97,    -1,   187,    -1,   101,   155,    -1,    -1,    -1,
      -1,    -1,   161,   197,    -1,    -1,    -1,    -1,   202,   203,
      -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,   652,    -1,
      -1,    -1,    -1,   479,   658,    -1,    -1,   483,    -1,    -1,
      -1,    -1,    -1,   303,    -1,   491,    -1,    -1,    -1,   243,
      97,    -1,    -1,    -1,   101,    -1,   162,   317,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     264,    -1,    20,    -1,    -1,    -1,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    -1,    35,    36,    -1,
      -1,    -1,    40,    -1,   718,    -1,   720,    45,    -1,    -1,
      -1,   725,    -1,    -1,   728,    -1,    -1,    -1,    -1,     2,
      -1,   735,    -1,    -1,   738,   162,    -1,    -1,    11,    67,
      -1,    69,   890,    71,    -1,    73,    -1,   387,    76,    -1,
      78,    24,    80,    26,   240,    -1,   760,    -1,    -1,    -1,
      -1,   247,    -1,    -1,    -1,    -1,    -1,   771,    -1,   773,
      -1,    99,    -1,    -1,   102,   415,   602,   105,    -1,    -1,
      -1,   421,    -1,    -1,    -1,    -1,    -1,    -1,   428,    20,
      -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    71,    -1,
      -1,    -1,    33,    -1,    35,    36,    -1,    -1,    -1,    40,
      -1,    -1,    -1,   240,    45,    -1,    -1,   303,    -1,    -1,
     247,    -1,    -1,    -1,    97,    -1,   652,   155,   101,   403,
      -1,   317,   658,   407,    -1,    -1,    67,    -1,    69,   479,
      71,    -1,    73,   483,    -1,    76,    -1,    78,    -1,    80,
      -1,   491,    -1,   857,    -1,    -1,    -1,    -1,    -1,    -1,
     864,    -1,   436,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      -1,   102,   876,    -1,   105,    -1,   303,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   888,    -1,    -1,    -1,    -1,   162,
     317,    -1,   718,   897,   720,    -1,    -1,   901,    -1,   725,
      -1,   387,   728,    -1,    -1,    -1,    -1,    -1,    -1,   735,
      -1,    -1,   738,    -1,    -1,    -1,    -1,    -1,   492,    29,
      -1,    -1,    -1,   497,   155,    -1,    -1,    -1,    -1,   415,
     161,    -1,    -1,    -1,   760,   421,    -1,    -1,    -1,   943,
      -1,    -1,   428,    -1,    -1,   771,    -1,   773,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     387,    -1,   602,    -1,    -1,    -1,    -1,   240,    -1,    79,
      -1,    -1,    -1,    83,   247,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   987,   988,   989,   990,    -1,   415,    -1,
      -1,    -1,    -1,   479,   421,    -1,    -1,   483,    -1,    -1,
      -1,   428,    -1,    -1,    -1,   491,    -1,    -1,  1012,  1013,
      -1,    -1,   652,    -1,    -1,    -1,    -1,    -1,   658,    -1,
     130,   131,    -1,   133,   134,   135,    -1,   137,   138,   139,
     303,   857,   142,    -1,    -1,    -1,    -1,    -1,   864,   149,
     150,   615,    -1,   153,   317,   619,   156,   157,   158,    -1,
     876,    -1,   479,    -1,    -1,    -1,   483,    -1,    -1,    -1,
      -1,    -1,   888,    -1,   491,    -1,   640,    -1,    -1,    -1,
     644,   897,    29,    -1,    -1,   901,    -1,    -1,   718,    -1,
     720,    -1,    -1,    -1,    -1,   725,    -1,    -1,   728,    -1,
      -1,    -1,    -1,    -1,    -1,   735,    -1,    -1,   738,    -1,
      -1,    -1,    -1,    -1,    -1,   679,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   387,    -1,   602,   943,    -1,    -1,
     760,    -1,    79,    -1,    -1,    -1,    83,    -1,    -1,    -1,
      -1,   771,    -1,   773,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   415,    -1,    -1,    -1,    -1,    -1,   421,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   987,   988,   989,   990,    -1,   652,    -1,   742,    -1,
      -1,   745,   658,   130,   131,   602,   133,   134,   135,    -1,
     137,   138,    -1,    -1,    -1,   142,  1012,  1013,    -1,    -1,
      -1,   765,   149,   150,    -1,    -1,   153,    -1,    -1,   156,
     157,   158,    -1,    -1,    -1,    -1,   479,    -1,    -1,   783,
     483,    -1,    -1,    -1,    -1,    -1,    -1,   857,   491,    -1,
      -1,    -1,    -1,    -1,   864,   652,    -1,    -1,    -1,    -1,
      -1,   658,   718,    -1,   720,   809,   876,    -1,    -1,   725,
      -1,    -1,   728,    -1,    -1,    -1,    -1,    -1,   888,   735,
      -1,    -1,   738,    -1,    -1,    -1,    -1,   897,    -1,    -1,
      -1,   901,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   760,    -1,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    24,    25,   771,    -1,   773,    -1,    -1,
      -1,   718,    33,   720,    35,    36,    -1,    -1,   725,    40,
      -1,   728,    -1,   943,    45,    -1,    -1,    -1,   735,    -1,
      -1,   738,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    69,   602,
      71,    -1,    73,   760,    -1,    76,    -1,    78,    -1,    80,
      -1,    -1,    -1,    -1,   771,   919,   773,   987,   988,   989,
     990,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      -1,   102,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,
      -1,   857,  1012,  1013,    -1,    -1,    -1,    -1,   864,   652,
      -1,    -1,    -1,    -1,    20,   658,    -1,    -1,    24,    25,
     876,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    35,
      36,    -1,   888,    -1,    40,    -1,    -1,    -1,    -1,    45,
      -1,   897,    48,    -1,   155,   901,    -1,    -1,    -1,    -1,
     161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     857,    67,    -1,    69,    -1,    -1,    -1,   864,    74,    -1,
      -1,    -1,    78,    -1,    80,   718,    -1,   720,    -1,   876,
      -1,    -1,   725,    -1,    -1,   728,    -1,   943,    -1,    -1,
      -1,   888,   735,    99,    -1,   738,   102,    -1,   104,   105,
     897,    -1,    -1,    -1,   901,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   760,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,   771,    -1,
     773,   987,   988,   989,   990,    -1,    15,    16,    -1,    18,
      -1,    -1,    -1,    -1,    23,    -1,   943,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,  1012,  1013,    37,    -1,
      -1,    -1,    -1,    42,    -1,    44,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
     987,   988,   989,   990,    -1,    -1,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,
      89,    -1,    91,    -1,    93,  1012,  1013,    96,    -1,    -1,
      -1,   100,   101,    -1,   103,    -1,    -1,   106,    -1,    -1,
      -1,    -1,    -1,   876,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   888,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   897,    -1,    -1,    -1,   901,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    12,    13,
      14,    15,    16,   162,    18,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    31,    -1,    33,
     943,    35,    36,    37,    38,    39,    40,    41,    42,    -1,
      44,    45,    -1,    47,    48,    -1,    50,    51,    52,    -1,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    -1,    80,    81,    82,    -1,
      84,    85,    86,    87,    88,    89,    90,    91,    -1,    93,
      94,    -1,    96,    97,    98,    99,   100,    -1,   102,   103,
     104,   105,   106,    -1,    -1,   109,    -1,   111,    -1,    -1,
     114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,   152,   153,
      -1,   155,    -1,    -1,   158,    -1,   160,    -1,   162,     1,
     164,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      12,    -1,    -1,    15,    16,    -1,    18,    -1,    20,    -1,
      -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    33,    -1,    -1,    -1,    37,    38,    39,    -1,    41,
      42,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    51,
      52,    -1,    -1,    55,    56,    -1,    58,    59,    -1,    61,
      62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,    -1,
      72,    -1,    -1,    -1,    -1,    77,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,    91,
      -1,    93,    -1,    -1,    96,    -1,    -1,    -1,   100,    -1,
      -1,   103,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,
     152,   153,   154,    -1,    -1,    -1,   158,    -1,   160,    -1,
     162,    -1,   164,   165,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    12,    13,    14,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    44,    45,    -1,
      47,    48,    -1,    50,    51,    52,    -1,    54,    55,    56,
      57,    58,    59,    -1,    61,    62,    63,    -1,    -1,    -1,
      67,    68,    69,    70,    -1,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    -1,    96,
      97,    98,    99,   100,    -1,   102,   103,   104,   105,   106,
      -1,    -1,   109,    -1,   111,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,    -1,   141,   142,   143,   144,   145,    -1,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,    -1,   160,   161,   162,     1,   164,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    -1,    18,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    31,    -1,    33,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    44,
      45,    -1,    47,    48,    -1,    50,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    -1,    61,    62,    63,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    -1,    80,    81,    82,    -1,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      -1,    96,    97,    98,    99,   100,    -1,   102,   103,   104,
     105,   106,    -1,    -1,   109,    -1,   111,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,    -1,    -1,   152,   153,   154,
     155,    -1,    -1,   158,    -1,   160,   161,   162,     1,   164,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      13,    14,    15,    16,    -1,    18,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    31,    -1,
      33,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    44,    45,    -1,    47,    48,    -1,    50,    51,    52,
      -1,    54,    55,    56,    57,    58,    59,    -1,    61,    62,
      63,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    -1,    80,    81,    82,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    94,    -1,    96,    97,    98,    99,   100,    -1,   102,
     103,   104,   105,   106,    -1,    -1,   109,    -1,   111,    -1,
      -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,   152,
     153,    -1,   155,    -1,    -1,   158,    -1,   160,   161,   162,
       1,   164,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    13,    14,    15,    16,    -1,    18,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      31,    -1,    33,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    44,    45,    -1,    47,    48,    -1,    50,
      51,    52,    -1,    54,    55,    56,    57,    58,    59,    -1,
      61,    62,    63,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    -1,    80,
      81,    82,    -1,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    93,    94,    -1,    96,    97,    98,    99,   100,
      -1,   102,   103,   104,   105,   106,    -1,    -1,   109,    -1,
     111,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,
      -1,   152,   153,    -1,   155,    -1,    -1,   158,    -1,   160,
     161,   162,     1,   164,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    13,    14,    15,    16,    -1,    18,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    31,    -1,    33,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    44,    45,    -1,    47,    48,
      -1,    50,    51,    52,    -1,    54,    55,    56,    57,    58,
      59,    -1,    61,    62,    63,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      -1,    80,    81,    82,    -1,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,    94,    -1,    96,    97,    98,
      99,   100,    -1,   102,   103,   104,   105,   106,    -1,    -1,
     109,    -1,   111,    -1,    -1,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,
     139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,    -1,    -1,   152,   153,    -1,   155,    -1,    -1,   158,
      -1,   160,   161,   162,     1,   164,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    13,    14,    15,    16,
      -1,    18,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    31,    -1,    33,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    44,    45,    -1,
      47,    48,    -1,    50,    51,    52,    -1,    54,    55,    56,
      57,    58,    59,    -1,    61,    62,    63,    -1,    -1,    -1,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    -1,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    -1,    96,
      97,    98,    99,   100,    -1,   102,   103,   104,   105,   106,
      -1,    -1,   109,    -1,   111,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,    -1,    -1,   152,   153,    -1,   155,    -1,
      -1,   158,    -1,   160,   161,   162,     1,   164,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    -1,    18,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    31,    -1,    33,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    44,
      45,    -1,    47,    48,    -1,    50,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    -1,    61,    62,    63,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    -1,    80,    81,    82,    -1,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      -1,    96,    97,    98,    99,   100,    -1,   102,   103,   104,
     105,   106,    -1,    -1,   109,    -1,   111,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,    -1,    -1,   152,   153,    -1,
     155,    -1,    -1,   158,    -1,   160,    -1,   162,     1,   164,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      13,    14,    15,    16,    -1,    18,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    31,    -1,
      33,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    44,    45,    -1,    47,    48,    -1,    50,    51,    52,
      -1,    54,    55,    56,    57,    58,    59,    -1,    61,    62,
      63,    -1,    -1,    -1,    67,    68,    69,    70,    -1,    72,
      73,    74,    75,    76,    77,    78,    -1,    80,    81,    82,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    94,    -1,    96,    97,    98,    99,   100,    -1,   102,
     103,   104,   105,   106,    -1,    -1,   109,    -1,   111,    -1,
      -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,   152,
     153,    -1,   155,    -1,    -1,   158,    -1,   160,    -1,   162,
       1,   164,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    13,    14,    15,    16,    -1,    18,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      31,    -1,    33,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    44,    45,    -1,    47,    48,    -1,    50,
      51,    52,    -1,    54,    55,    56,    57,    58,    59,    -1,
      61,    62,    63,    -1,    -1,    -1,    67,    68,    69,    70,
      -1,    72,    73,    74,    75,    76,    77,    78,    -1,    80,
      81,    82,    -1,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    93,    94,    -1,    96,    97,    98,    99,   100,
      -1,   102,   103,   104,   105,   106,    -1,    -1,   109,    -1,
     111,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,
      -1,   152,   153,    -1,   155,    -1,    -1,   158,    -1,   160,
      -1,   162,     1,   164,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    13,    14,    15,    16,    -1,    18,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    31,    -1,    33,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    44,    45,    -1,    47,    48,
      -1,    50,    51,    52,    -1,    54,    55,    56,    57,    58,
      59,    -1,    61,    62,    63,    -1,    -1,    -1,    67,    68,
      69,    70,    -1,    72,    73,    74,    75,    76,    77,    78,
      -1,    80,    81,    82,    -1,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,    94,    -1,    96,    97,    98,
      99,   100,    -1,   102,   103,   104,   105,   106,    -1,    -1,
     109,    -1,   111,    -1,    -1,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,
     139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,    -1,    -1,   152,   153,    -1,   155,    -1,    -1,   158,
      -1,   160,    -1,   162,     1,   164,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    13,    14,    15,    16,
      -1,    18,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    31,    -1,    33,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    44,    45,    -1,
      47,    48,    -1,    50,    51,    52,    -1,    54,    55,    56,
      57,    58,    59,    -1,    61,    62,    63,    -1,    -1,    -1,
      67,    68,    69,    70,    -1,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    -1,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    -1,    96,
      97,    98,    99,   100,    -1,   102,   103,   104,   105,   106,
      -1,    -1,   109,    -1,   111,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,    -1,    -1,   152,   153,    -1,   155,    -1,
      -1,   158,    -1,   160,    -1,   162,     1,   164,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    -1,    18,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    31,    -1,    33,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    44,
      45,    -1,    47,    48,    -1,    50,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    -1,    61,    62,    63,    -1,
      -1,    -1,    67,    68,    69,    70,    -1,    72,    73,    74,
      75,    76,    77,    78,    -1,    80,    81,    82,    -1,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      -1,    96,    97,    98,    99,   100,    -1,   102,   103,   104,
     105,   106,    -1,    -1,   109,    -1,   111,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,    -1,    -1,   152,   153,    -1,
     155,    -1,    -1,   158,    -1,   160,    -1,   162,     1,   164,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      13,    14,    15,    16,    -1,    18,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    31,    -1,
      33,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    44,    45,    -1,    47,    48,    -1,    50,    51,    52,
      -1,    54,    55,    56,    57,    58,    59,    -1,    61,    62,
      63,    -1,    -1,    -1,    67,    68,    69,    70,    -1,    72,
      73,    74,    75,    76,    77,    78,    -1,    80,    81,    82,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    94,    -1,    96,    97,    98,    99,   100,    -1,   102,
     103,   104,   105,   106,    -1,    -1,   109,    -1,   111,    -1,
      -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,   152,
     153,    -1,   155,    -1,    -1,   158,    -1,   160,    -1,   162,
       1,   164,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    13,    14,    15,    16,    -1,    18,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      31,    -1,    33,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    44,    45,    -1,    47,    48,    -1,    50,
      51,    52,    -1,    54,    55,    56,    57,    58,    59,    -1,
      61,    62,    63,    -1,    -1,    -1,    67,    68,    69,    70,
      -1,    72,    73,    74,    75,    76,    77,    78,    -1,    80,
      81,    82,    -1,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    93,    94,    -1,    96,    97,    98,    99,   100,
      -1,   102,   103,   104,   105,   106,    -1,    -1,   109,    -1,
     111,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,
      -1,   152,   153,    -1,   155,    -1,    -1,   158,    -1,   160,
      -1,   162,     1,   164,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    13,    14,    15,    16,    -1,    18,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    31,    -1,    33,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    44,    45,    -1,    47,    48,
      -1,    50,    51,    52,    -1,    54,    55,    56,    57,    58,
      59,    -1,    61,    62,    63,    -1,    -1,    -1,    67,    68,
      69,    70,    -1,    72,    73,    74,    75,    76,    77,    78,
      -1,    80,    81,    82,    -1,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,    94,    -1,    96,    97,    98,
      99,   100,    -1,   102,   103,   104,   105,   106,    -1,    -1,
     109,    -1,   111,    -1,    -1,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,
     139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,    -1,    -1,   152,   153,    -1,   155,    -1,    -1,   158,
      -1,   160,    -1,   162,     1,   164,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    13,    14,    15,    16,
      -1,    18,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    31,    -1,    33,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    44,    45,    -1,
      47,    48,    -1,    50,    51,    52,    -1,    54,    55,    56,
      57,    58,    59,    -1,    61,    62,    63,    -1,    -1,    -1,
      67,    68,    69,    70,    -1,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    -1,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    -1,    96,
      97,    98,    99,   100,    -1,   102,   103,   104,   105,   106,
      -1,    -1,   109,    -1,   111,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,    -1,    -1,   152,   153,    -1,   155,    -1,
      -1,   158,    -1,   160,    -1,   162,     1,   164,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    -1,    18,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    31,    -1,    33,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    44,
      45,    -1,    47,    48,    -1,    50,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    -1,    61,    62,    63,    -1,
      -1,    -1,    67,    68,    69,    70,    -1,    72,    73,    74,
      75,    76,    77,    78,    -1,    80,    81,    82,    -1,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      -1,    96,    97,    98,    99,   100,    -1,   102,   103,   104,
     105,   106,    -1,    -1,   109,    -1,   111,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,    -1,    -1,   152,   153,    -1,
     155,    -1,    -1,   158,    -1,   160,    -1,   162,     1,   164,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      -1,    -1,    15,    16,    -1,    18,    -1,    20,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      33,    -1,    -1,    -1,    37,    38,    39,    -1,    41,    42,
      -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    51,    52,
      -1,    -1,    55,    56,    -1,    58,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    70,    -1,    72,
      -1,    -1,    -1,    -1,    77,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    88,    89,    90,    91,    -1,
      93,    -1,    -1,    96,    -1,    -1,    -1,   100,    -1,    -1,
     103,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,   152,
     153,   154,    -1,    -1,    -1,   158,    -1,   160,    -1,   162,
      -1,   164,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    18,    -1,    20,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    33,    -1,    -1,    -1,    37,    38,    39,    -1,
      41,    42,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,
      51,    52,    -1,    -1,    55,    56,    -1,    58,    59,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,
      -1,    72,    -1,    -1,    -1,    -1,    77,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,
      91,    -1,    93,    -1,    -1,    96,    -1,    -1,    -1,   100,
      -1,    -1,   103,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,
      -1,   152,   153,   154,    -1,    -1,    -1,   158,    -1,   160,
      -1,   162,    -1,   164,   165,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    12,    -1,    -1,    15,    16,    -1,
      18,    -1,    20,    -1,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    33,    -1,    -1,    -1,    37,
      38,    39,    -1,    41,    42,    -1,    44,    -1,    -1,    47,
      -1,    -1,    -1,    51,    52,    -1,    -1,    55,    56,    -1,
      58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    77,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      88,    89,    90,    91,    -1,    93,    -1,    -1,    96,    -1,
      -1,    -1,   100,    -1,    -1,   103,    -1,    -1,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,    -1,    -1,   152,   153,   154,    -1,    -1,    -1,
     158,    -1,   160,    -1,   162,    -1,   164,   165,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,
      15,    16,    -1,    18,    -1,    20,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    33,    -1,
      -1,    -1,    37,    38,    39,    -1,    41,    42,    -1,    44,
      -1,    -1,    47,    -1,    -1,    -1,    51,    52,    -1,    -1,
      55,    56,    -1,    58,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,    -1,    72,    -1,    -1,
      -1,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    90,    91,    -1,    93,    -1,
      -1,    96,    -1,    -1,    -1,   100,    -1,    -1,   103,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,    -1,    -1,   152,   153,    -1,
      -1,    -1,    -1,   158,    -1,   160,    -1,   162,    -1,   164,
     165,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      12,    -1,    -1,    15,    16,    -1,    18,    -1,    20,    -1,
      -1,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    33,    -1,    -1,    -1,    37,    38,    39,    -1,    41,
      42,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    51,
      52,    -1,    -1,    55,    56,    -1,    58,    59,    -1,    61,
      62,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,    -1,
      72,    -1,    -1,    -1,    -1,    77,    78,    -1,    80,    -1,
      -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,    91,
      -1,    93,    -1,    -1,    96,    -1,    -1,    -1,   100,    -1,
      -1,   103,    -1,   105,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,
     152,   153,    -1,    -1,    -1,    -1,   158,    -1,   160,    -1,
     162,    -1,   164,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    12,    -1,    -1,    15,    16,    -1,    18,    -1,
      20,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    33,    -1,    -1,    -1,    37,    38,    39,
      -1,    41,    42,    -1,    44,    -1,    -1,    47,    -1,    -1,
      -1,    51,    52,    -1,    -1,    55,    56,    -1,    58,    59,
      -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      70,    -1,    72,    -1,    -1,    -1,    -1,    77,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,
      90,    91,    -1,    93,    -1,    -1,    96,    97,    98,    -1,
     100,   101,    -1,   103,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,
      -1,    -1,   152,   153,   154,    -1,    -1,    -1,   158,    -1,
     160,    -1,   162,    -1,   164,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    12,    -1,    -1,    15,    16,    -1,
      18,    -1,    20,    -1,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    33,    -1,    -1,    -1,    37,
      38,    39,    -1,    41,    42,    -1,    44,    -1,    -1,    47,
      -1,    -1,    -1,    51,    52,    -1,    -1,    55,    56,    -1,
      58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    77,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      88,    89,    90,    91,    -1,    93,    -1,    -1,    96,    97,
      98,    -1,   100,   101,    -1,   103,    -1,    -1,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,    -1,    -1,   152,   153,   154,    -1,    -1,    -1,
     158,    -1,   160,    -1,   162,   163,   164,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,    15,
      16,    -1,    18,    -1,    20,    -1,    -1,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    33,    -1,    -1,
      -1,    37,    38,    39,    -1,    41,    42,    -1,    44,    -1,
      -1,    47,    -1,    -1,    -1,    51,    52,    -1,    -1,    55,
      56,    -1,    58,    59,    -1,    61,    62,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    70,    -1,    72,    -1,    -1,    -1,
      -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    88,    89,    90,    91,    -1,    93,    -1,    -1,
      96,    97,    98,    -1,   100,   101,    -1,   103,    -1,    -1,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   149,    -1,    -1,   152,   153,   154,    -1,
      -1,    -1,   158,    -1,   160,    -1,   162,   163,   164,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,
      -1,    15,    16,    -1,    18,    -1,    20,    -1,    -1,    23,
      -1,    25,    -1,    -1,    -1,    -1,    -1,    31,    -1,    33,
      -1,    -1,    -1,    37,    38,    39,    -1,    41,    42,    43,
      44,    -1,    -1,    47,    -1,    -1,    -1,    51,    52,    -1,
      -1,    55,    56,    -1,    58,    59,    -1,    61,    62,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    70,    -1,    72,    -1,
      -1,    -1,    -1,    77,    78,    -1,    80,    -1,    -1,    -1,
      -1,    -1,    86,    87,    88,    89,    90,    91,    -1,    93,
      -1,    -1,    96,    -1,    -1,    -1,   100,    -1,    -1,   103,
      -1,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,   152,   153,
       1,    -1,     3,    -1,   158,    -1,   160,    -1,   162,    10,
     164,    -1,    -1,    -1,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    23,    -1,    20,    -1,    -1,    -1,    24,    25,
      31,    -1,    -1,    -1,    -1,    -1,    37,    33,    -1,    35,
      36,    42,    -1,    44,    40,    -1,    47,    -1,    49,    45,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,
      -1,    67,    -1,    69,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    78,    -1,    80,    86,    87,    -1,    89,    -1,
      91,    -1,    93,    -1,    -1,    96,    -1,    -1,    -1,   100,
      -1,    -1,   103,    99,    -1,   106,   102,    -1,    -1,   105,
      -1,    -1,    -1,    -1,   115,   116,   117,   118,   119,   120,
      -1,    -1,   123,   124,   125,   126,    -1,   128,   129,   130,
     131,   132,   133,   134,    -1,    -1,   137,    -1,    -1,    -1,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,   153,    -1,    -1,   156,   157,   158,   159,    -1,
      -1,   162,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    18,    -1,    20,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    33,    -1,    -1,    -1,    37,    38,    39,    -1,
      41,    42,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,
      51,    52,    -1,    -1,    55,    56,    -1,    58,    59,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,
      -1,    72,    -1,    -1,    -1,    -1,    77,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,
      91,    -1,    93,    -1,    -1,    96,    97,    98,    -1,   100,
      -1,    -1,   103,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,
      -1,   152,   153,    -1,   155,    -1,    -1,   158,    -1,   160,
      -1,   162,    -1,   164,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    -1,    -1,    15,    16,    -1,    18,
      -1,    20,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    33,    -1,    -1,    -1,    37,    38,
      39,    -1,    41,    42,    -1,    44,    -1,    -1,    47,    -1,
      -1,    -1,    51,    52,    -1,    -1,    55,    56,    -1,    58,
      59,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    77,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,
      89,    90,    91,    -1,    93,    -1,    -1,    96,    97,    98,
      -1,   100,    -1,    -1,   103,    -1,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,
     139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,    -1,    -1,   152,   153,   154,    -1,    -1,    -1,   158,
      -1,   160,    -1,   162,    -1,   164,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    -1,    -1,    15,    16,
      -1,    18,    -1,    20,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    33,    -1,    -1,    -1,
      37,    38,    39,    -1,    41,    42,    -1,    44,    -1,    -1,
      47,    -1,    -1,    -1,    51,    52,    -1,    -1,    55,    56,
      -1,    58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    88,    89,    90,    91,    -1,    93,    -1,    -1,    96,
      97,    98,    -1,   100,    -1,    -1,   103,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,    -1,    -1,   152,   153,    -1,    -1,    -1,
      -1,   158,    -1,   160,    -1,   162,    -1,   164,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    12,    -1,    -1,
      15,    16,    -1,    18,    -1,    20,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    33,    -1,
      -1,    -1,    37,    38,    39,    -1,    41,    42,    -1,    44,
      -1,    -1,    47,    -1,    -1,    -1,    51,    52,    -1,    -1,
      55,    56,    -1,    58,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,    -1,    72,    -1,    -1,
      -1,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    90,    91,    -1,    93,    -1,
      -1,    96,    -1,    -1,    99,   100,    -1,    -1,   103,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,    -1,    -1,   152,   153,    -1,
      -1,    -1,    -1,   158,    -1,   160,    -1,   162,    -1,   164,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      -1,    -1,    15,    16,    -1,    18,    -1,    20,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      33,    -1,    -1,    -1,    37,    38,    39,    -1,    41,    42,
      -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    51,    52,
      -1,    -1,    55,    56,    -1,    58,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    69,    70,    -1,    72,
      -1,    -1,    -1,    -1,    77,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    88,    89,    90,    91,    -1,
      93,    -1,    -1,    96,    -1,    -1,    -1,   100,    -1,    -1,
     103,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,   112,
      -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,   160,    -1,   162,
      -1,   164,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    18,    -1,    20,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    33,    -1,    -1,    -1,    37,    38,    39,    -1,
      41,    42,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,
      51,    52,    -1,    -1,    55,    56,    -1,    58,    59,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,
      -1,    72,    -1,    -1,    -1,    -1,    77,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,
      91,    -1,    93,    -1,    -1,    96,    -1,    -1,    -1,   100,
      -1,    -1,   103,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,   112,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,
      -1,   152,   153,   154,    -1,    -1,    -1,   158,    -1,   160,
      -1,   162,    -1,   164,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    -1,    -1,    15,    16,    -1,    18,
      -1,    20,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    33,    -1,    -1,    -1,    37,    38,
      39,    -1,    41,    42,    -1,    44,    -1,    -1,    47,    -1,
      -1,    -1,    51,    52,    -1,    -1,    55,    56,    -1,    58,
      59,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    77,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,
      89,    90,    91,    -1,    93,    -1,    -1,    96,    97,    98,
      -1,   100,    -1,    -1,   103,    -1,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,
     139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,    -1,    -1,   152,   153,    -1,    -1,    -1,    -1,   158,
      -1,   160,    -1,   162,    -1,   164,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    -1,    -1,    15,    16,
      -1,    18,    -1,    20,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    33,    -1,    -1,    -1,
      37,    38,    39,    -1,    41,    42,    -1,    44,    -1,    -1,
      47,    -1,    -1,    -1,    51,    52,    -1,    -1,    55,    56,
      -1,    58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    88,    89,    90,    91,    -1,    93,    -1,    -1,    96,
      -1,    -1,    -1,   100,    -1,    -1,   103,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,    -1,    -1,   152,   153,   154,    -1,    -1,
      -1,   158,    -1,   160,   161,   162,    -1,   164,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,
      15,    16,    -1,    18,    -1,    20,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    33,    -1,
      -1,    -1,    37,    38,    39,    -1,    41,    42,    -1,    44,
      -1,    -1,    47,    -1,    -1,    -1,    51,    52,    -1,    -1,
      55,    56,    -1,    58,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,    -1,    72,    -1,    -1,
      -1,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    90,    91,    -1,    93,    -1,
      -1,    96,    -1,    -1,    -1,   100,    -1,    -1,   103,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,   112,    -1,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,    -1,    -1,   152,   153,    -1,
      -1,    -1,    -1,   158,    -1,   160,    -1,   162,    -1,   164,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      -1,    -1,    15,    16,    -1,    18,    -1,    20,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      33,    -1,    -1,    -1,    37,    38,    39,    -1,    41,    42,
      -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    51,    52,
      -1,    -1,    55,    56,    -1,    58,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    70,    -1,    72,
      -1,    -1,    -1,    -1,    77,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    88,    89,    90,    91,    -1,
      93,    -1,    -1,    96,    -1,    -1,    -1,   100,    -1,    -1,
     103,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,   160,    -1,   162,
      -1,   164,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    18,    -1,    20,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    33,    -1,    -1,    -1,    37,    38,    39,    -1,
      41,    42,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,
      51,    52,    -1,    -1,    55,    56,    -1,    58,    59,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,
      -1,    72,    -1,    -1,    -1,    -1,    77,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,
      91,    -1,    93,    -1,    -1,    96,    -1,    -1,    -1,   100,
      -1,    -1,   103,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,
      -1,   152,   153,   154,    -1,    -1,    -1,   158,    -1,   160,
      -1,   162,    -1,   164,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    -1,    -1,    15,    16,    -1,    18,
      -1,    20,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    33,    -1,    -1,    -1,    37,    38,
      39,    -1,    41,    42,    -1,    44,    -1,    -1,    47,    -1,
      -1,    -1,    51,    52,    -1,    -1,    55,    56,    -1,    58,
      59,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    77,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,
      89,    90,    91,    -1,    93,    -1,    -1,    96,    -1,    -1,
      99,   100,    -1,    -1,   103,    -1,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,
     139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,    -1,    -1,   152,   153,    -1,    -1,    -1,    -1,   158,
      -1,   160,    -1,   162,    -1,   164,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    -1,    -1,    15,    16,
      -1,    18,    -1,    20,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    33,    -1,    -1,    -1,
      37,    38,    39,    -1,    41,    42,    -1,    44,    -1,    -1,
      47,    -1,    -1,    -1,    51,    52,    -1,    -1,    55,    56,
      -1,    58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    88,    89,    90,    91,    -1,    93,    -1,    -1,    96,
      -1,    -1,    -1,   100,    -1,    -1,   103,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,    -1,    -1,   152,   153,   154,    -1,    -1,
      -1,   158,    -1,   160,    -1,   162,    -1,   164,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,
      15,    16,    -1,    18,    -1,    20,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    33,    -1,
      -1,    -1,    37,    38,    39,    -1,    41,    42,    -1,    44,
      -1,    -1,    47,    -1,    -1,    -1,    51,    52,    -1,    -1,
      55,    56,    -1,    58,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,    -1,    72,    -1,    -1,
      -1,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    90,    91,    -1,    93,    -1,
      -1,    96,    -1,    -1,    -1,   100,    -1,    -1,   103,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,    -1,    -1,   152,   153,   154,
      -1,    -1,    -1,   158,    -1,   160,    -1,   162,    -1,   164,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      -1,    -1,    15,    16,    -1,    18,    -1,    20,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      33,    -1,    -1,    -1,    37,    38,    39,    -1,    41,    42,
      -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    51,    52,
      -1,    -1,    55,    56,    -1,    58,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    70,    -1,    72,
      -1,    -1,    -1,    -1,    77,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    88,    89,    90,    91,    -1,
      93,    -1,    -1,    96,    -1,    -1,    -1,   100,    -1,    -1,
     103,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,   152,
     153,   154,    -1,    -1,    -1,   158,    -1,   160,    -1,   162,
      -1,   164,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    18,    -1,    20,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    33,    -1,    -1,    -1,    37,    38,    39,    -1,
      41,    42,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,
      51,    52,    -1,    -1,    55,    56,    -1,    58,    59,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,
      -1,    72,    -1,    -1,    -1,    -1,    77,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,
      91,    -1,    93,    -1,    -1,    96,    -1,    -1,    -1,   100,
      -1,    -1,   103,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,
      -1,   152,   153,   154,    -1,    -1,    -1,   158,    -1,   160,
      -1,   162,    -1,   164,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    -1,    -1,    15,    16,    -1,    18,
      -1,    20,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    33,    -1,    -1,    -1,    37,    38,
      39,    -1,    41,    42,    -1,    44,    -1,    -1,    47,    -1,
      -1,    -1,    51,    52,    -1,    -1,    55,    56,    -1,    58,
      59,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    77,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,
      89,    90,    91,    -1,    93,    -1,    -1,    96,    -1,    -1,
      -1,   100,    -1,    -1,   103,    -1,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,
     139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,    -1,    -1,   152,   153,   154,    -1,    -1,    -1,   158,
      -1,   160,    -1,   162,    -1,   164,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    -1,    -1,    15,    16,
      -1,    18,    -1,    20,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    33,    -1,    -1,    -1,
      37,    38,    39,    -1,    41,    42,    -1,    44,    -1,    -1,
      47,    -1,    -1,    -1,    51,    52,    -1,    -1,    55,    56,
      -1,    58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    88,    89,    90,    91,    -1,    93,    -1,    -1,    96,
      -1,    -1,    -1,   100,    -1,    -1,   103,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,    -1,    -1,   152,   153,    -1,    -1,    -1,
      -1,   158,    -1,   160,    -1,   162,    -1,   164,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,
      15,    16,    -1,    18,    -1,    20,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    33,    -1,
      -1,    -1,    37,    38,    39,    -1,    41,    42,    -1,    44,
      -1,    -1,    47,    -1,    -1,    -1,    51,    52,    -1,    -1,
      55,    56,    -1,    58,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,    -1,    72,    -1,    -1,
      -1,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    90,    91,    -1,    93,    -1,
      -1,    96,    -1,    -1,    -1,   100,    -1,    -1,   103,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,    -1,    -1,   152,   153,    -1,
      -1,    -1,    -1,   158,    -1,   160,    -1,   162,    -1,   164,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      -1,    -1,    15,    16,    -1,    18,    -1,    20,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      33,    -1,    -1,    -1,    37,    38,    39,    -1,    41,    42,
      -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    51,    52,
      -1,    -1,    55,    56,    -1,    58,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    70,    -1,    72,
      -1,    -1,    -1,    -1,    77,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    88,    89,    90,    91,    -1,
      93,    -1,    -1,    96,    -1,    -1,    -1,   100,    -1,    -1,
     103,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,   160,    -1,   162,
      -1,   164,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    18,    -1,    20,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    33,    -1,    -1,    -1,    37,    38,    39,    -1,
      41,    42,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,
      51,    52,    -1,    -1,    55,    56,    -1,    58,    59,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,
      -1,    72,    -1,    -1,    -1,    -1,    77,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,
      91,    -1,    93,    -1,    -1,    96,    -1,    -1,    -1,   100,
      -1,    -1,   103,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,
      -1,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,   160,
      -1,   162,    -1,   164,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    -1,    -1,    15,    16,    -1,    18,
      -1,    20,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    33,    -1,    -1,    -1,    37,    38,
      39,    -1,    41,    42,    -1,    44,    -1,    -1,    47,    -1,
      -1,    -1,    51,    52,    -1,    -1,    55,    56,    -1,    58,
      59,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    77,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,
      89,    90,    91,    -1,    93,    -1,    -1,    96,    -1,    -1,
      -1,   100,    -1,    -1,   103,    -1,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,
     139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,    -1,    -1,   152,   153,    -1,    -1,    -1,    -1,   158,
      -1,   160,    -1,   162,    -1,   164,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    -1,    -1,    15,    16,
      -1,    18,    -1,    20,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    33,    -1,    -1,    -1,
      37,    38,    39,    -1,    41,    42,    -1,    44,    -1,    -1,
      47,    -1,    -1,    -1,    51,    52,    -1,    -1,    55,    56,
      -1,    58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    88,    89,    90,    91,    -1,    93,    -1,    -1,    96,
      -1,    -1,    -1,   100,    -1,    -1,   103,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,    -1,    -1,   152,   153,    -1,    -1,    -1,
      -1,   158,    -1,   160,    -1,   162,    -1,   164,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,
      15,    16,    -1,    18,    -1,    20,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    33,    -1,
      -1,    -1,    37,    38,    39,    -1,    41,    42,    -1,    44,
      -1,    -1,    47,    -1,    -1,    -1,    51,    52,    -1,    -1,
      55,    56,    -1,    58,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,    -1,    72,    -1,    -1,
      -1,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    90,    91,    -1,    93,    -1,
      -1,    96,    -1,    -1,    -1,   100,    -1,    -1,   103,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,    -1,    -1,   152,   153,    -1,
      -1,    -1,    -1,   158,    -1,   160,    -1,   162,    -1,   164,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      -1,    -1,    15,    16,    -1,    18,    -1,    20,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      33,    -1,    -1,    -1,    37,    38,    39,    -1,    41,    42,
      -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    51,    52,
      -1,    -1,    55,    56,    -1,    58,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    70,    -1,    72,
      -1,    -1,    -1,    -1,    77,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    88,    89,    90,    91,    -1,
      93,    -1,    -1,    96,    -1,    -1,    -1,   100,    -1,    -1,
     103,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,   160,    -1,   162,
      -1,   164,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    18,    -1,    20,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    33,    -1,    -1,    -1,    37,    38,    39,    -1,
      41,    42,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,
      51,    52,    -1,    -1,    55,    56,    -1,    58,    59,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,
      -1,    72,    -1,    -1,    -1,    -1,    77,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,
      91,    -1,    93,    -1,    -1,    96,    -1,    -1,    -1,   100,
      -1,    -1,   103,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,
      -1,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,   160,
      -1,   162,    -1,   164,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    -1,    -1,    15,    16,    -1,    18,
      -1,    20,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    33,    -1,    -1,    -1,    37,    38,
      39,    -1,    41,    42,    -1,    44,    -1,    -1,    47,    -1,
      -1,    -1,    51,    52,    -1,    -1,    55,    56,    -1,    58,
      59,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    77,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,
      89,    90,    91,    -1,    93,    -1,    -1,    96,    -1,    -1,
      -1,   100,    -1,    -1,   103,    -1,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,
     139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,    -1,    -1,   152,   153,    -1,    -1,    -1,    -1,   158,
      -1,   160,    -1,   162,    -1,   164,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    -1,    -1,    15,    16,
      -1,    18,    -1,    20,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    33,    -1,    -1,    -1,
      37,    38,    39,    -1,    41,    42,    -1,    44,    -1,    -1,
      47,    -1,    -1,    -1,    51,    52,    -1,    -1,    55,    56,
      -1,    58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    88,    89,    90,    91,    -1,    93,    -1,    -1,    96,
      -1,    -1,    -1,   100,    -1,    -1,   103,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,    -1,    -1,   152,   153,    -1,    -1,    -1,
      -1,   158,    -1,   160,    -1,   162,    -1,   164,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,
      15,    16,    -1,    18,    -1,    20,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    33,    -1,
      -1,    -1,    37,    38,    39,    -1,    41,    42,    -1,    44,
      -1,    -1,    47,    -1,    -1,    -1,    51,    52,    -1,    -1,
      55,    56,    -1,    58,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,    -1,    72,    -1,    -1,
      -1,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    90,    91,    -1,    93,    -1,
      -1,    96,    -1,    -1,    -1,   100,    -1,    -1,   103,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,    -1,    -1,   152,   153,    -1,
      -1,    -1,    -1,   158,    -1,   160,    -1,   162,    -1,   164,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      -1,    -1,    15,    16,    -1,    18,    -1,    20,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      33,    -1,    -1,    -1,    37,    38,    39,    -1,    41,    42,
      -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    51,    52,
      -1,    -1,    55,    56,    -1,    58,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    70,    -1,    72,
      -1,    -1,    -1,    -1,    77,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    88,    89,    90,    91,    -1,
      93,    -1,    -1,    96,    -1,    -1,    -1,   100,    -1,    -1,
     103,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,   160,    -1,   162,
      -1,   164,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    18,    -1,    20,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    33,    -1,    -1,    -1,    37,    38,    39,    -1,
      41,    42,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,
      51,    52,    -1,    -1,    55,    56,    -1,    58,    59,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,
      -1,    72,    -1,    -1,    -1,    -1,    77,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,
      91,    -1,    93,    -1,    -1,    96,    -1,    -1,    -1,   100,
      -1,    -1,   103,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,
      -1,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,   160,
      -1,   162,    -1,   164,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    -1,    -1,    15,    16,    -1,    18,
      -1,    20,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    33,    -1,    -1,    -1,    37,    38,
      39,    -1,    41,    42,    -1,    44,    -1,    -1,    47,    -1,
      -1,    -1,    51,    52,    -1,    -1,    55,    56,    -1,    58,
      59,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    77,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,
      89,    90,    91,    -1,    93,    -1,    -1,    96,    -1,    -1,
      -1,   100,    -1,    -1,   103,    -1,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,
     139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,    -1,    -1,   152,   153,    -1,    -1,    -1,    -1,   158,
      -1,   160,    -1,   162,    -1,   164,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    -1,    -1,    15,    16,
      -1,    18,    -1,    20,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    33,    -1,    -1,    -1,
      37,    38,    39,    -1,    41,    42,    -1,    44,    -1,    -1,
      47,    -1,    -1,    -1,    51,    52,    -1,    -1,    55,    56,
      -1,    58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    88,    89,    90,    91,    -1,    93,    -1,    -1,    96,
      -1,    -1,    -1,   100,    -1,    -1,   103,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,    -1,    -1,   152,   153,    -1,    -1,    -1,
      -1,   158,    -1,    -1,    -1,   162,    -1,   164,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,
      15,    16,    -1,    18,    -1,    20,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    33,    -1,
      -1,    -1,    37,    38,    39,    -1,    41,    42,    -1,    44,
      -1,    -1,    47,    -1,    -1,    -1,    51,    52,    -1,    -1,
      55,    56,    -1,    58,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,    -1,    72,    -1,    -1,
      -1,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    90,    91,    -1,    93,    -1,
      -1,    96,    -1,    -1,    -1,   100,    -1,    -1,   103,    -1,
      -1,   106,    -1,    -1,    -1,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
       3,     4,     5,     6,     7,     8,   146,    -1,    -1,    12,
      -1,    -1,    15,    16,   149,    18,    -1,    20,   153,   159,
      23,    -1,   162,   158,   164,   160,    -1,   162,    31,   164,
      33,    -1,    -1,    -1,    37,    38,    39,    -1,    41,    42,
      -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    51,    52,
      -1,    -1,    55,    56,    -1,    58,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    70,    -1,    72,
      -1,    -1,    -1,    -1,    77,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    88,    89,    90,    91,    -1,
      93,    -1,    -1,    96,    -1,    -1,    -1,   100,    -1,    -1,
     103,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,
      -1,    -1,    -1,   136,    -1,    -1,    -1,   140,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   154,    -1,    -1,    -1,    -1,    -1,   160,    -1,   162,
     163,   164,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    18,    -1,    20,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    33,    -1,    -1,    -1,    37,    38,    39,    -1,
      41,    42,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,
      51,    52,    53,    -1,    55,    56,    -1,    58,    59,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,
      -1,    72,    -1,    -1,    -1,    -1,    77,    78,    -1,    -1,
      -1,    82,    -1,    -1,    -1,    86,    87,    88,    89,    90,
      91,    -1,    93,    -1,    95,    96,    -1,    -1,    -1,   100,
      -1,    -1,   103,    -1,    -1,   106,    -1,   108,    -1,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   132,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    18,    -1,    20,
      -1,    -1,    23,   159,   155,    -1,   162,    -1,   164,   160,
      31,   162,    33,   164,    -1,    -1,    37,    38,    39,    -1,
      41,    42,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,
      51,    52,    -1,    -1,    55,    56,    -1,    58,    59,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,
      -1,    72,    -1,    -1,    -1,    -1,    77,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,
      91,    -1,    93,    -1,    -1,    96,    -1,    -1,    -1,   100,
      -1,    -1,   103,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   132,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    18,    -1,    20,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,   160,
      31,   162,    33,   164,    -1,    -1,    37,    38,    39,    -1,
      41,    42,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,
      51,    52,    -1,    -1,    55,    56,    -1,    58,    59,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,
      -1,    72,    -1,    -1,    -1,    -1,    77,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,
      91,    -1,    93,    -1,    -1,    96,    -1,    -1,    -1,   100,
      -1,    -1,   103,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   132,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    18,    -1,    20,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,   160,
      31,   162,    33,   164,    -1,    -1,    37,    38,    39,    -1,
      41,    42,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,
      51,    52,    -1,    -1,    55,    56,    -1,    58,    59,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,
      -1,    72,    -1,    -1,    -1,    -1,    77,    78,    -1,    -1,
      -1,     3,    -1,    -1,    -1,    86,    87,    88,    89,    90,
      91,    -1,    93,    15,    16,    96,    18,    -1,    -1,   100,
      -1,    23,   103,    -1,    -1,   106,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,
      42,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      -1,   132,    -1,    55,    -1,    -1,    -1,    -1,    -1,    61,
      62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,
       3,   162,    -1,   164,    86,    87,    -1,    89,    -1,    91,
      -1,    93,    15,    16,    96,    18,    -1,    -1,   100,    -1,
      23,   103,    -1,    -1,   106,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    42,
      -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    -1,     3,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    15,
      16,    -1,    18,    -1,    77,    -1,    -1,    23,   160,    -1,
     162,    -1,    -1,    86,    87,    31,    89,    -1,    91,    -1,
      93,    37,    -1,    96,    -1,    -1,    42,   100,    44,    -1,
     103,    47,    -1,   106,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    -1,    89,    -1,    91,    -1,    93,    -1,     3,
      96,    -1,    -1,    -1,   100,    -1,    10,   103,    -1,   162,
     106,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    42,    -1,
      44,    -1,    -1,    47,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    61,    62,    -1,
      -1,    -1,    10,    -1,    68,    -1,   162,    -1,    -1,    17,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    86,    87,    -1,    89,    -1,    91,    -1,    93,
      -1,    -1,    96,    -1,    -1,    -1,   100,    -1,    -1,   103,
      -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   115,   116,   117,   118,   119,   120,    -1,    -1,   123,
     124,   125,   126,    29,   128,   129,   130,   131,   132,   133,
     134,    79,    -1,   137,    -1,    83,    -1,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,    -1,   153,
      10,    -1,   156,   157,   158,   159,    -1,    17,    -1,    -1,
      -1,    -1,   110,    -1,    -1,    -1,   114,    -1,    -1,    29,
      -1,    -1,    -1,    79,    -1,    -1,    -1,    83,    -1,    -1,
      -1,    -1,   130,   131,    -1,   133,   134,   135,    -1,   137,
     138,   139,    -1,   141,   142,   143,   144,   145,    -1,   147,
     148,   149,   150,   151,   152,   153,    -1,    10,   156,   157,
     158,    -1,    -1,    -1,    17,    -1,    -1,   165,    -1,    79,
      -1,    -1,    -1,    83,   130,   131,    29,   133,   134,   135,
      -1,   137,   138,   139,    -1,   141,   142,   143,   144,    -1,
      -1,   147,   148,   149,   150,   151,    -1,   153,    10,    -1,
     156,   157,   158,    -1,   114,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
     130,   131,    -1,   133,   134,   135,    79,   137,   138,   139,
      83,   141,   142,   143,   144,   145,    -1,   147,   148,   149,
     150,   151,   152,   153,    10,    -1,   156,   157,   158,    -1,
      -1,    17,    -1,    -1,    -1,   165,    -1,    -1,    -1,    -1,
      -1,   114,    -1,    29,    -1,    -1,    -1,    79,    -1,    -1,
      -1,    83,    -1,    -1,    -1,    -1,    -1,   130,   131,    -1,
     133,   134,   135,    -1,   137,   138,   139,    -1,   141,   142,
     143,   144,   145,    -1,   147,   148,   149,   150,   151,   152,
     153,    10,   114,   156,   157,   158,    -1,    -1,    17,    -1,
      -1,    -1,   165,    79,    -1,    -1,    -1,    83,   130,   131,
      29,   133,   134,   135,    -1,   137,   138,   139,    -1,   141,
     142,   143,   144,   145,    -1,   147,   148,   149,   150,   151,
     152,   153,    -1,    -1,   156,   157,   158,    -1,   114,    -1,
      -1,    -1,    -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,    -1,   133,   134,   135,
      79,   137,   138,   139,    83,   141,   142,   143,   144,   145,
      -1,   147,   148,   149,   150,   151,   152,   153,    10,    -1,
     156,   157,   158,    -1,    -1,    17,    -1,   163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,    -1,   133,   134,   135,    -1,   137,   138,
     139,    -1,   141,   142,   143,   144,   145,    -1,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,   156,   157,   158,
      -1,    -1,    -1,    -1,   163,    -1,    -1,    79,    -1,    -1,
      -1,    83,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      92,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,   123,   124,   125,   126,    -1,   128,   129,   130,   131,
      -1,   133,   134,   135,    -1,   137,   138,   139,    -1,   141,
     142,   143,   144,   145,    -1,   147,   148,   149,   150,   151,
     152,   153,    -1,    79,   156,   157,   158,    83,   160,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    92,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,   123,   124,   125,
     126,    -1,   128,   129,   130,   131,    -1,   133,   134,   135,
      -1,   137,   138,   139,    -1,   141,   142,   143,   144,   145,
      -1,   147,   148,   149,   150,   151,   152,   153,    -1,    79,
     156,   157,   158,    83,   160,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    92,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,   115,   116,   117,   118,   119,
     120,    -1,    -1,   123,   124,   125,   126,    -1,   128,   129,
     130,   131,    -1,   133,   134,   135,    -1,   137,   138,   139,
      -1,   141,   142,   143,   144,   145,    -1,   147,   148,   149,
     150,   151,   152,   153,    -1,    79,   156,   157,   158,    83,
     160,    -1,    10,    -1,    -1,    -1,    -1,    -1,    92,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,   115,   116,   117,   118,   119,   120,    -1,    -1,   123,
     124,   125,   126,    -1,   128,   129,   130,   131,    -1,   133,
     134,   135,    -1,   137,   138,   139,    -1,   141,   142,   143,
     144,   145,    -1,   147,   148,   149,   150,   151,   152,   153,
      -1,    79,   156,   157,   158,    83,   160,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    92,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,   115,   116,   117,
     118,   119,   120,    -1,    -1,   123,   124,   125,   126,    -1,
     128,   129,   130,   131,    -1,   133,   134,   135,    -1,   137,
     138,   139,    -1,   141,   142,   143,   144,   145,    -1,   147,
     148,   149,   150,   151,   152,   153,    -1,    79,   156,   157,
     158,    83,   160,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      92,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,   123,   124,   125,   126,    -1,   128,   129,   130,   131,
      -1,   133,   134,   135,    -1,   137,   138,   139,    -1,   141,
     142,   143,   144,   145,    -1,   147,   148,   149,   150,   151,
     152,   153,    -1,    79,   156,   157,   158,    83,   160,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    92,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,   123,   124,   125,
     126,    -1,   128,   129,   130,   131,    -1,   133,   134,   135,
      -1,   137,   138,   139,    -1,   141,   142,   143,   144,   145,
      -1,   147,   148,   149,   150,   151,   152,   153,    -1,    79,
     156,   157,   158,    83,   160,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    92,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,   115,   116,   117,   118,   119,
     120,    -1,    -1,   123,   124,   125,   126,    -1,   128,   129,
     130,   131,    -1,   133,   134,   135,    -1,   137,   138,   139,
      -1,   141,   142,   143,   144,   145,    -1,   147,   148,   149,
     150,   151,   152,   153,    -1,    79,   156,   157,   158,    83,
     160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,   115,   116,   117,   118,   119,   120,    -1,    -1,   123,
     124,   125,   126,    -1,   128,   129,   130,   131,    -1,   133,
     134,   135,    -1,   137,   138,   139,    -1,   141,   142,   143,
     144,   145,    -1,   147,   148,   149,   150,   151,   152,   153,
      10,    -1,   156,   157,   158,    -1,   160,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    10,    43,    -1,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    79,
      -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,
     110,    79,    -1,    -1,   114,    83,    -1,    -1,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,    -1,   133,   134,   135,    -1,   137,   138,   139,
      -1,   141,   142,   143,   144,   145,   114,   147,   148,   149,
     150,   151,   152,   153,    -1,    -1,   156,   157,   158,    -1,
     160,    -1,   130,   131,    -1,   133,   134,   135,    79,   137,
     138,   139,    83,   141,   142,   143,   144,   145,    -1,   147,
     148,   149,   150,   151,   152,   153,    10,    -1,   156,   157,
     158,    -1,   160,    17,    -1,    -1,    -1,    -1,    -1,   110,
      -1,    -1,    -1,   114,    -1,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,    -1,   133,   134,   135,    -1,   137,   138,   139,    -1,
     141,   142,   143,   144,   145,    -1,   147,   148,   149,   150,
     151,   152,   153,    10,    -1,   156,   157,   158,    -1,   160,
      17,    -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    83,
      -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   130,   131,    -1,   133,
     134,   135,    79,   137,   138,   139,    83,   141,   142,   143,
     144,   145,    -1,   147,   148,   149,   150,   151,   152,   153,
      -1,    -1,   156,   157,   158,    -1,   160,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    -1,   114,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      -1,    -1,    -1,   130,   131,    -1,   133,   134,   135,    -1,
     137,   138,   139,    -1,   141,   142,   143,   144,   145,   114,
     147,   148,   149,   150,   151,   152,   153,    -1,    -1,   156,
     157,   158,    -1,   160,    -1,   130,   131,    -1,   133,   134,
     135,    -1,   137,   138,   139,    -1,   141,   142,   143,   144,
     145,    -1,   147,   148,   149,   150,   151,   152,   153,    10,
      -1,   156,   157,   158,    -1,   160,    17,    -1,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      15,    16,    -1,    18,    -1,    -1,    -1,    -1,    23,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    31,    -1,    17,    -1,
      -1,    -1,    37,    -1,    -1,    -1,    -1,    42,    -1,    44,
      29,    -1,    47,    -1,    -1,    34,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    61,    62,    79,    -1,
      -1,    -1,    83,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    -1,    -1,    64,    -1,    -1,    10,    -1,
      -1,    86,    87,    -1,    89,    17,    91,    -1,    93,    -1,
      79,    96,    -1,   114,    83,   100,    -1,    29,   103,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,    43,   133,   134,   135,    -1,   137,   138,   139,    -1,
     141,   142,   143,   144,   145,   114,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,   156,   157,   158,    -1,   160,
      -1,   130,   131,    -1,   133,   134,   135,    79,   137,   138,
     139,    83,   141,   142,   143,   144,   145,    -1,   147,   148,
     149,   150,   151,   152,   153,    10,   155,   156,   157,   158,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,   110,    -1,
      -1,    -1,   114,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
      -1,   133,   134,   135,    -1,   137,   138,   139,    -1,   141,
     142,   143,   144,   145,    -1,   147,   148,   149,   150,   151,
     152,   153,    10,    -1,   156,   157,   158,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    83,    -1,
      -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    10,    43,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,    43,   133,   134,
     135,    79,   137,   138,   139,    83,   141,   142,   143,   144,
     145,    -1,   147,   148,   149,   150,   151,   152,   153,    -1,
     155,   156,   157,   158,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    79,    -1,    -1,   114,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   130,   131,    -1,   133,   134,   135,    -1,   137,
     138,   139,    -1,   141,   142,   143,   144,   145,   114,   147,
     148,   149,   150,   151,   152,   153,    -1,    -1,   156,   157,
     158,    -1,    -1,    -1,   130,   131,    -1,   133,   134,   135,
      -1,   137,   138,   139,    -1,   141,   142,   143,   144,   145,
      -1,   147,   148,   149,   150,   151,   152,   153,    10,    -1,
     156,   157,   158,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,
      -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    79,
      -1,    -1,   114,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
      -1,   133,   134,   135,    -1,   137,   138,   139,    -1,   141,
     142,   143,   144,   145,   114,   147,   148,   149,   150,   151,
     152,   153,    -1,    -1,   156,   157,   158,    -1,    79,    -1,
     130,   131,    83,   133,   134,   135,    -1,   137,   138,   139,
      -1,   141,   142,   143,   144,   145,    -1,   147,   148,   149,
     150,   151,   152,   153,    10,   155,   156,   157,   158,    -1,
      -1,    17,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,   130,
     131,    -1,   133,   134,   135,    -1,   137,   138,   139,    -1,
     141,   142,   143,   144,   145,    -1,   147,   148,   149,   150,
     151,   152,   153,    10,   155,   156,   157,   158,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    79,    -1,    -1,    -1,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,   114,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    79,    -1,   130,   131,    83,   133,   134,   135,
      -1,   137,   138,   139,    -1,   141,   142,   143,   144,   145,
      -1,   147,   148,   149,   150,   151,   152,   153,    -1,   155,
     156,   157,   158,    -1,    79,    -1,   113,   114,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      -1,    -1,    -1,   130,   131,    -1,   133,   134,   135,    -1,
     137,   138,   139,    -1,   141,   142,   143,   144,   145,   114,
     147,   148,   149,   150,   151,   152,   153,    -1,    -1,   156,
     157,   158,    -1,    -1,    -1,   130,   131,    -1,   133,   134,
     135,    -1,   137,   138,   139,    -1,   141,   142,   143,   144,
     145,    -1,   147,   148,   149,   150,   151,   152,   153,    10,
      -1,   156,   157,   158,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      20,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    -1,    35,    36,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    10,    45,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    67,    79,    69,
      -1,    71,    83,    73,    -1,    -1,    76,    -1,    78,    -1,
      80,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,    -1,   102,   114,    29,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    79,    -1,    -1,    -1,    83,    -1,   130,
     131,    -1,   133,   134,   135,    -1,   137,   138,   139,    -1,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,   110,   156,   157,   158,   114,    -1,
      -1,    -1,    -1,    -1,    79,   155,    -1,    -1,    83,    -1,
      -1,   161,    -1,    -1,   130,   131,    -1,   133,   134,   135,
      -1,   137,   138,   139,    -1,   141,   142,   143,   144,   145,
      -1,   147,   148,   149,   150,   151,   152,   153,    -1,   114,
     156,   157,   158,    -1,    -1,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    17,    -1,   130,   131,    -1,   133,   134,
     135,    -1,   137,   138,   139,    29,   141,   142,   143,   144,
     145,    -1,   147,   148,   149,   150,   151,   152,   153,    -1,
     155,   156,   157,   158,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
     114,    -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    83,
      -1,    -1,    -1,    -1,    -1,    -1,   130,   131,    -1,   133,
     134,   135,    -1,   137,   138,   139,    -1,   141,   142,   143,
     144,   145,    -1,   147,   148,   149,   150,   151,   152,   153,
     114,    -1,   156,   157,   158,    -1,    79,    -1,    -1,    -1,
      83,    -1,    -1,    -1,    -1,    -1,   130,   131,    -1,   133,
     134,   135,    -1,   137,   138,   139,    -1,   141,   142,   143,
     144,   145,    -1,   147,   148,   149,   150,   151,   152,   153,
     113,   114,   156,   157,   158,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,    -1,
     133,   134,   135,    -1,   137,   138,   139,    -1,   141,   142,
     143,   144,   145,    -1,   147,   148,   149,   150,   151,   152,
     153,    10,    -1,   156,   157,   158,    -1,    -1,    17,    -1,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    15,    16,    -1,    18,    -1,    -1,    -1,    -1,
      23,    -1,    -1,    10,    -1,    -1,    -1,    -1,    31,    -1,
      17,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    42,
      -1,    44,    29,    30,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    61,    62,
      79,    -1,    -1,    -1,    83,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    -1,    89,    -1,    91,    -1,
      93,    -1,    79,    96,    -1,   114,    83,   100,    -1,    -1,
     103,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,    -1,   133,   134,   135,    -1,   137,   138,
     139,    -1,   141,   142,   143,   144,   145,   114,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,   156,   157,   158,
      -1,    -1,    -1,   130,   131,    -1,   133,   134,   135,    -1,
     137,   138,   139,    -1,   141,   142,   143,   144,   145,    -1,
     147,   148,   149,   150,   151,   152,   153,    10,    -1,   156,
     157,   158,    -1,    -1,    17,    -1,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    15,    16,
      -1,    18,    -1,    -1,    -1,    -1,    23,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    31,    -1,    17,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    -1,    42,    -1,    44,    29,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    61,    62,    79,    -1,    -1,    -1,
      83,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      77,    -1,    -1,    -1,    -1,    -1,    10,    11,    -1,    86,
      87,    -1,    89,    17,    91,    -1,    93,    -1,    79,    96,
      -1,   114,    83,   100,    -1,    29,   103,    -1,    -1,   106,
      -1,    92,    -1,    -1,    -1,    -1,    -1,   130,   131,    -1,
     133,   134,   135,    -1,   137,   138,   139,    -1,   141,   142,
     143,   144,   145,   114,   147,   148,   149,   150,   151,   152,
     153,    -1,    -1,   156,   157,   158,    -1,    -1,    -1,   130,
     131,    -1,   133,   134,   135,    79,   137,   138,   139,    83,
     141,   142,   143,   144,   145,    -1,   147,   148,   149,   150,
     151,   152,   153,    10,    -1,   156,   157,   158,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   130,   131,    -1,   133,
     134,   135,    -1,   137,   138,   139,    -1,   141,   142,   143,
     144,   145,    -1,   147,   148,   149,   150,   151,   152,   153,
      -1,    -1,   156,   157,   158,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    79,    -1,    -1,    -1,    83,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    92,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,
      -1,    83,    -1,   130,   131,    -1,   133,   134,   135,    -1,
     137,   138,   139,    -1,   141,   142,   143,   144,   145,    -1,
     147,   148,   149,   150,   151,   152,   153,    -1,    79,   156,
     157,   158,    83,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    92,    17,    -1,    -1,    -1,    -1,    -1,   130,   131,
      -1,   133,   134,   135,    29,   137,   138,   139,    -1,    -1,
     142,   143,   144,   114,    -1,   147,   148,   149,   150,    -1,
      -1,   153,    -1,    -1,   156,   157,   158,    -1,    -1,   130,
     131,    -1,   133,   134,   135,    -1,   137,   138,   139,    -1,
     141,   142,   143,   144,   145,    -1,   147,   148,   149,   150,
     151,   152,   153,    -1,    79,   156,   157,   158,    83,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    92,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,    -1,   133,   134,
     135,    -1,   137,   138,   139,    -1,   141,   142,   143,   144,
     145,    -1,   147,   148,   149,   150,   151,   152,   153,    -1,
      79,   156,   157,   158,    83,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    92,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,    -1,   133,   134,   135,    -1,   137,   138,
     139,    -1,   141,   142,   143,   144,   145,    -1,   147,   148,
     149,   150,   151,   152,   153,    -1,    79,   156,   157,   158,
      83,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    92,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,    -1,
     133,   134,   135,    -1,   137,   138,   139,    -1,   141,   142,
     143,   144,   145,    -1,   147,   148,   149,   150,   151,   152,
     153,    -1,    79,   156,   157,   158,    83,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    92,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,   130,   131,    -1,   133,   134,   135,    -1,
     137,   138,   139,    -1,   141,   142,   143,   144,   145,    -1,
     147,   148,   149,   150,   151,   152,   153,    -1,    79,   156,
     157,   158,    83,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,    -1,   133,   134,   135,    -1,   137,   138,   139,    -1,
     141,   142,   143,   144,   145,    -1,   147,   148,   149,   150,
     151,   152,   153,    -1,    79,   156,   157,   158,    83,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,    -1,   133,   134,
     135,    -1,   137,   138,   139,    -1,   141,   142,   143,   144,
     145,    -1,   147,   148,   149,   150,   151,   152,   153,    -1,
      79,   156,   157,   158,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,    -1,   133,   134,   135,    -1,   137,   138,
     139,    -1,   141,   142,   143,   144,   145,    -1,   147,   148,
     149,   150,   151,   152,   153,    -1,    20,   156,   157,   158,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      20,    35,    36,    -1,    24,    25,    40,    -1,    -1,    -1,
      -1,    45,    -1,    33,    -1,    35,    36,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    29,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    69,    -1,    71,    -1,    73,
      -1,    -1,    76,    -1,    78,    -1,    80,    67,    -1,    69,
      -1,    71,    -1,    73,    -1,    -1,    76,    -1,    78,    -1,
      80,    -1,    -1,    -1,    29,    99,    -1,    -1,   102,    -1,
      -1,   105,    -1,    -1,    79,    -1,    -1,    -1,    83,    99,
      -1,    -1,   102,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    83,    -1,
      -1,   155,    -1,    -1,    -1,   130,   131,   161,   133,   134,
     135,    -1,   137,   138,   139,   155,   141,   142,   143,   144,
      -1,   161,   147,   148,   149,   150,   151,   152,   153,   114,
      -1,   156,   157,   158,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,    -1,   133,   134,
     135,    -1,   137,   138,   139,    -1,   141,   142,   143,   144,
      -1,    -1,   147,   148,   149,   150,   151,     1,   153,     3,
      -1,   156,   157,   158,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    -1,    18,    -1,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    42,    -1,
      44,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    -1,     3,    61,    62,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    15,    16,
      -1,    18,    -1,    77,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    86,    87,    31,    89,    -1,    91,    -1,    93,
      37,    -1,    96,    -1,    -1,    42,   100,    44,    -1,   103,
      47,    -1,   106,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    -1,    89,    -1,    91,    -1,    93,    -1,    -1,    96,
      -1,    -1,    -1,   100,    -1,    -1,   103,    -1,    -1,   106
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   170,   171,     0,     1,     3,     4,     5,     6,     7,
       8,    12,    13,    14,    15,    16,    18,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    30,    31,    33,    35,
      36,    37,    38,    39,    40,    41,    42,    44,    45,    47,
      50,    51,    52,    54,    55,    56,    58,    59,    61,    62,
      63,    67,    68,    69,    70,    71,    72,    73,    76,    77,
      78,    80,    81,    82,    84,    85,    86,    87,    88,    89,
      90,    91,    93,    94,    96,    97,    98,    99,   100,   102,
     103,   105,   106,   109,   111,   114,   130,   131,   132,   133,
     134,   139,   149,   152,   153,   155,   158,   160,   162,   164,
     172,   173,   174,   175,   176,   177,   179,   184,   185,   186,
     187,   191,   193,   196,   197,   198,   199,   200,   201,   202,
     204,   205,   206,   210,   211,   214,   215,   218,   219,   222,
     225,   226,   252,   255,   256,   276,   277,   278,   279,   280,
     281,   282,   290,   291,   292,   293,   296,   297,   298,   299,
     300,   301,   302,   304,   305,   306,   307,   308,   155,   174,
     293,   110,   283,   284,     3,   188,    12,    20,    33,    38,
      39,    41,    78,    91,   160,   164,   222,   276,   281,   291,
     292,   293,   296,   298,   299,   283,   293,    99,   255,    80,
     188,   174,   270,   293,   174,   162,     7,    78,   293,   294,
       7,     9,    78,    99,   294,    69,   112,   203,   293,   203,
     293,    24,   256,   293,   293,   162,     3,    15,    16,    18,
      23,    31,    37,    42,    44,    47,    55,    61,    62,    68,
      77,    86,    87,    89,    91,    93,    96,   100,   103,   106,
     190,   192,   223,   162,   190,   257,   258,    30,   179,   195,
     293,   293,   293,   293,   293,   293,     7,   162,    20,    33,
      36,    78,   198,   198,   154,   245,   269,   293,    97,    98,
     155,   293,   295,   293,   195,   293,   293,   293,    90,   162,
     174,   293,   293,   179,   187,   293,   296,   179,   187,   293,
     190,   253,   293,   293,   293,   293,   293,   293,   293,   293,
       1,   161,   172,   180,   269,   101,   140,   245,   271,   272,
     295,   203,   269,   293,   303,    71,   174,   160,    75,   178,
     104,   190,   190,    48,    74,   240,   257,   154,   155,   146,
      10,    17,    29,    79,    83,   114,   130,   131,   133,   134,
     135,   137,   138,   139,   141,   142,   143,   144,   145,   147,
     148,   149,   150,   151,   152,   153,   156,   157,   158,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   159,   232,   162,   164,    79,    83,
     162,   174,   155,   293,   293,   293,   269,   160,   179,    43,
     283,   253,   257,   155,   136,   155,   109,   191,   245,   273,
     274,   275,   295,    78,   190,   226,   255,    78,   190,   253,
     226,   255,   190,   162,   195,    30,    43,   195,   110,   195,
     286,    30,    43,   195,   286,    34,    64,   155,    92,   179,
     232,   273,   174,   162,   234,   101,   162,   190,   259,   260,
       1,   135,   264,    43,   136,   174,   195,   195,   273,   190,
     136,   155,   293,   293,   155,   160,   195,   162,   273,   155,
     207,   155,   207,   155,   115,   254,   155,   195,   155,   161,
     161,   172,   136,   161,   293,   136,   163,   136,   163,   165,
     286,    43,   136,   165,   286,   113,   136,   165,     7,     1,
     161,   180,    57,   269,   293,   135,   216,   160,   227,   155,
     293,   293,   293,   293,   203,   293,   203,   293,   293,   293,
     293,   293,   293,   293,    18,    31,    55,    99,   191,   293,
     154,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     154,   293,   293,   293,   293,   293,   293,   295,   295,   295,
     295,   295,   273,   273,   203,   293,   203,   293,    25,    43,
      80,   105,   285,   288,   289,   293,   308,    30,    43,    30,
      43,    92,    43,   165,   203,   293,   195,   155,   155,   293,
     293,   115,   163,   136,   190,   216,   257,   190,   216,   155,
     257,    43,   269,    41,   293,   203,   293,   162,   195,    41,
     293,   203,   293,   195,   158,   181,   183,   293,   181,   182,
     174,   293,    32,   293,   163,    25,    43,    46,    66,    69,
      80,    99,   173,   235,   236,   237,   238,   224,   260,   136,
     163,    31,    44,    87,    91,   164,   194,   265,   277,   115,
     261,   293,   258,   163,   245,   293,     1,   212,   273,   163,
      19,   208,   265,   277,   136,   161,   163,   163,   271,   163,
     271,   174,   165,   203,   293,   165,   174,   293,   165,   293,
     165,   293,   161,   161,   190,   155,    34,    64,   269,   160,
       1,   190,   220,   221,    25,    69,    80,    99,   229,   239,
     162,   155,   155,   155,   155,   155,   163,   165,    43,    80,
     136,   163,   276,    79,    79,    41,   203,   293,    41,   203,
     293,   203,   293,   283,   283,   155,   245,   295,   275,   216,
     160,   155,   216,   160,   155,   293,   163,   293,    30,   195,
      30,   195,   287,   288,   293,    30,   195,   286,    30,   195,
     286,   136,   155,    11,   155,    32,    32,   174,    92,   179,
      43,    80,   237,   136,   163,   162,   190,    25,    69,    80,
      99,   241,   163,   260,   264,     1,   269,    60,   295,   161,
      65,   107,   161,   213,   163,   162,   179,   190,   209,   253,
     174,   165,   286,   165,   286,   174,   113,   183,   182,     1,
     217,   161,   115,   136,   161,    80,   228,     1,     3,    10,
      15,    17,    18,    23,    37,    42,    47,    49,    55,    61,
      62,    77,    89,    93,    96,   100,   106,   130,   131,   132,
     133,   134,   137,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   153,   156,   157,   158,   159,   162,
     189,   190,   192,   230,   231,   232,   276,   163,   288,   264,
     276,   276,   293,    30,    30,   293,    30,    30,   165,   165,
     195,   195,   160,   217,   160,   217,   195,    92,    41,   293,
      41,   293,   136,   163,    92,    41,   293,   195,    41,   293,
     195,   293,   293,   174,   293,   174,    32,   190,   236,   260,
     135,   268,    80,   264,   261,   165,    43,   165,    30,   174,
     269,   209,   135,   179,    41,   174,   293,   165,    41,   174,
     293,   165,   293,   155,   155,   161,    73,    76,   161,   173,
     197,   293,   221,   241,   162,   233,   190,   293,   130,   138,
     233,   233,   261,    92,    41,    41,    92,    41,    41,    41,
      41,   217,   161,   217,   161,   293,   293,   293,   288,   293,
     293,   293,    11,    32,   174,   268,   163,   164,   194,   245,
     267,   277,   140,   247,   261,    53,   108,   248,   293,   265,
     277,   174,   195,   163,   293,   293,   174,   293,   174,   197,
       1,   135,   263,   235,   163,     3,    93,   231,   232,   293,
     293,   293,   293,   293,   293,   161,   161,    92,    92,    92,
      92,   293,   174,   261,   268,   165,   269,   245,   246,   293,
       3,    82,    93,   249,   250,   251,   293,   179,   196,   244,
     165,   179,    92,    92,   164,   194,   262,   277,    95,   242,
     163,   233,   233,    92,    92,    92,    92,    92,    92,   293,
     293,   293,   293,   247,   261,   245,   266,   267,   277,    43,
     165,   251,   108,   136,   115,   141,   143,   144,   147,   148,
      53,   277,   293,   293,     1,   165,   269,   248,   293,   266,
     267,   293,   250,   251,   251,   251,   251,   251,   251,   249,
     165,   262,   277,   165,   155,   243,   244,   165,   262,   277,
     266
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   169,   170,   171,   171,   172,   172,   173,   173,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   175,
     176,   176,   176,   177,   177,   177,   178,   178,   179,   179,
     179,   180,   180,   181,   181,   181,   181,   182,   182,   183,
     183,   184,   184,   184,   185,   185,   185,   186,   187,   187,
     187,   187,   187,   188,   188,   189,   189,   189,   189,   189,
     189,   190,   190,   190,   190,   190,   190,   191,   191,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   194,
     194,   194,   194,   195,   195,   196,   196,   197,   197,   197,
     197,   198,   198,   198,   198,   198,   198,   198,   199,   199,
     199,   199,   200,   200,   200,   200,   200,   200,   200,   200,
     201,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   203,   204,   204,
     204,   204,   204,   204,   204,   204,   205,   206,   206,   206,
     206,   206,   206,   207,   207,   208,   208,   208,   209,   209,
     210,   211,   211,   212,   212,   213,   213,   213,   214,   214,
     215,   215,   215,   216,   216,   217,   217,   217,   218,   218,
     219,   220,   220,   220,   221,   221,   223,   224,   222,   225,
     225,   225,   227,   228,   226,   229,   229,   229,   229,   229,
     230,   230,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   233,   233,   234,   235,   235,   235,   236,   236,
     236,   236,   236,   237,   237,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   239,   239,   239,   239,   239,   239,
     240,   240,   241,   241,   241,   241,   241,   241,   242,   242,
     243,   243,   244,   244,   245,   245,   246,   246,   247,   247,
     248,   248,   248,   248,   248,   249,   249,   250,   250,   250,
     250,   250,   250,   250,   251,   251,   252,   252,   252,   253,
     253,   254,   254,   254,   255,   255,   255,   255,   255,   256,
     256,   257,   257,   258,   258,   259,   259,   259,   260,   260,
     260,   261,   261,   261,   262,   262,   262,   262,   262,   262,
     262,   263,   263,   263,   263,   263,   264,   264,   264,   264,
     264,   265,   265,   265,   265,   266,   266,   266,   267,   267,
     267,   267,   267,   268,   268,   268,   268,   268,   269,   269,
     269,   269,   270,   270,   271,   271,   271,   272,   272,   273,
     273,   274,   274,   275,   275,   275,   275,   276,   276,   277,
     277,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   280,   281,   282,   282,   282,   282,   282,   282,   282,
     282,   283,   283,   284,   285,   285,   286,   287,   287,   288,
     288,   288,   289,   289,   289,   289,   289,   289,   290,   290,
     291,   292,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   294,   294,   295,   295,
     295,   296,   296,   296,   296,   297,   297,   297,   298,   298,
     298,   299,   299,   299,   299,   299,   300,   300,   300,   300,
     301,   301,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   303,   303,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   305,   305,   305,   305,   305,   305,   305,   306,
     306,   306,   306,   307,   307,   307,   307,   308,   308,   308,
     308,   308,   308,   308
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
       1,     0,     1,     1,     4,     6,     6,     3,     4,     4,
       4,     4,     4,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     3,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     3,     5,
       5,     2,     7,     8,     7,     8,     3,     3,     5,     5,
       2,     5,     3,     6,     6,     4,     5,     5,     3,     3,
       6,     5,     6,     5,     6,     3,     4,     3,     4,     6,
       7,     6,     7,     4,     5,     4,     5,     4,     4,     3,
       6,     5,     6,     5,     8,     7,     2,     3,     3,     2,
       2,     3,     3,     0,     2,     2,     3,     5,     1,     3,
       3,     5,     5,     0,     2,     3,     2,     3,     6,     6,
       1,     1,     1,     0,     2,     0,     2,     3,     5,     5,
       1,     1,     2,     3,     1,     3,     0,     0,     8,     0,
       1,     1,     0,     0,    10,     3,     3,     5,     5,     3,
       1,     3,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     3,     3,     0,     1,     3,     4,     5,
       4,     6,     6,     0,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     0,     1,     1,     2,     1,     1,
       1,     1,     0,     1,     2,     1,     1,     1,     0,     1,
       1,     1,     1,     1,     2,     1,     0,     1,     2,     2,
       0,     2,     2,     4,     4,     1,     3,     3,     3,     3,
       3,     3,     3,     2,     1,     1,     3,     4,     4,     2,
       4,     0,     2,     2,     1,     1,     1,     2,     1,     4,
       3,     1,     3,     3,     5,     1,     1,     3,     1,     2,
       3,     0,     2,     2,     3,     2,     4,     3,     3,     4,
       3,     0,     2,     2,     2,     1,     0,     2,     2,     2,
       1,     4,     4,     6,     3,     0,     1,     1,     3,     4,
       3,     4,     6,     0,     2,     2,     2,     2,     1,     1,
       3,     3,     1,     3,     1,     1,     1,     3,     3,     0,
       1,     1,     3,     3,     3,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     2,     4,     4,     4,
       5,     2,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     1,     1,     6,     6,     4,     9,     9,     7,
       6,     6,     4,     9,     9,     7,     4,     6,     6,     9,
       9,     6,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     0,     1,     4,     1,     3,     4,     1,     3,     4,
       3,     3,     1,     1,     2,     1,     2,     1,     1,     3,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     3,     3,     2,     2,     1,     0,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     2,     1,     4,     4,
       4,     3,     3,     3,     3,     5,     3,     4,     3,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     4,     3,     4,     3,     5,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     2,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, ParserContext* context)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  YYUSE (context);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, ParserContext* context)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp, context);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
  if (yyps)
    {
#ifndef yyoverflow
      /* If the stack was reallocated but the parse did not complete, then the
         stack still needs to be freed.  */
      if (!yyps->yynew && yyps->yyss != yyps->yyssa)
        YYSTACK_FREE (yyps->yyss);
#endif
      free (yyps);
    }
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
| yyreduce -- do a reduction.  |
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 490 "chapel.ypp" /* yacc.c:1667  */
    { yyblock = (yyval.pblockstmt); }
#line 5977 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 3:
#line 495 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = new BlockStmt(); resetTempID(); }
#line 5983 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 4:
#line 496 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-1].pblockstmt)->appendChapelStmt((yyvsp[0].pblockstmt)); context->generatedStmt = (yyvsp[-1].pblockstmt); resetTempID(); }
#line 5989 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 6:
#line 503 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildPragmaStmt( (yyvsp[-1].vpch), (yyvsp[0].pblockstmt) ); }
#line 5995 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 7:
#line 508 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.vpch) = new Vec<const char*>(); (yyval.vpch)->add(astr((yyvsp[0].pch))); }
#line 6001 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 8:
#line 509 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-2].vpch)->add(astr((yyvsp[0].pch))); }
#line 6007 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 23:
#line 528 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildChapelStmt((yyvsp[-1].pexpr)); }
#line 6013 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 24:
#line 529 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildAtomicStmt((yyvsp[0].pblockstmt)); }
#line 6019 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 25:
#line 530 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildBeginStmt((yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt)); }
#line 6025 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 26:
#line 531 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildGotoStmt(GOTO_BREAK, (yyvsp[-1].pch)); }
#line 6031 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 27:
#line 532 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildCobeginStmt((yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt));  }
#line 6037 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 28:
#line 533 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildGotoStmt(GOTO_CONTINUE, (yyvsp[-1].pch)); }
#line 6043 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 29:
#line 534 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildDeleteStmt((yyvsp[-1].pcallexpr)); }
#line 6049 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 30:
#line 535 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildLabelStmt((yyvsp[-1].pch), (yyvsp[0].pblockstmt)); }
#line 6055 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 31:
#line 536 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildLocalStmt((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 6061 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 32:
#line 537 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildLocalStmt((yyvsp[0].pblockstmt)); }
#line 6067 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 33:
#line 538 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildOnStmt((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 6073 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 34:
#line 539 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildSerialStmt((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 6079 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 35:
#line 540 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildSerialStmt(new SymExpr(gTrue), (yyvsp[0].pblockstmt)); }
#line 6085 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 36:
#line 541 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildSyncStmt((yyvsp[0].pblockstmt)); }
#line 6091 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 37:
#line 542 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_YIELD, (yyvsp[-1].pexpr)); }
#line 6097 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 38:
#line 543 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildErrorStandin(); }
#line 6103 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 39:
#line 548 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pmodsymbol) = buildModule((yyvsp[0].pch), currentModuleType, NULL, yyfilename, (yyvsp[-3].b), (yyvsp[-2].b), (yylsp[-3]).comment);
      // store previous module name in order to restore it once we're
      // done with this module in module_decl_stmt below.  Ultimately,
      // we will need to store a stack of module names in order to
      // support full module path resolution of -s config flags.
      (yyloc).prevModule = currentModuleName;
      currentModuleName = (yyvsp[0].pch);
    }
#line 6117 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 40:
#line 561 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-2].pmodsymbol)->block = new BlockStmt();
      (yyval.pblockstmt) = buildChapelStmt(new DefExpr((yyvsp[-2].pmodsymbol)));
      currentModuleName = (yylsp[-2]).prevModule;  // restore previous module name
    }
#line 6126 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 41:
#line 566 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-3].pmodsymbol)->block = (yyvsp[-1].pblockstmt);
      (yyval.pblockstmt) = buildChapelStmt(new DefExpr((yyvsp[-3].pmodsymbol)));
      currentModuleName = (yylsp[-3]).prevModule;  // restore previous module name
    }
#line 6135 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 42:
#line 571 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-3].pmodsymbol)->block = buildErrorStandin();
      (yyval.pblockstmt) = buildChapelStmt(new DefExpr((yyvsp[-3].pmodsymbol)));
      currentModuleName = (yylsp[-3]).prevModule;  // restore previous module name
    }
#line 6144 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 43:
#line 578 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.b) = false; (yyloc).comment = context->latestComment; context->latestComment = NULL; }
#line 6150 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 44:
#line 579 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.b) = false; (yyloc).comment = context->latestComment; context->latestComment = NULL; }
#line 6156 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 45:
#line 580 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.b) = true; (yyloc).comment = context->latestComment; context->latestComment = NULL; }
#line 6162 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 46:
#line 584 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.b) = false; }
#line 6168 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 47:
#line 585 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.b) = true;  }
#line 6174 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 48:
#line 598 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = new BlockStmt(); }
#line 6180 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 49:
#line 599 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = (yyvsp[-1].pblockstmt);              }
#line 6186 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 50:
#line 600 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildErrorStandin(); }
#line 6192 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 51:
#line 605 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = new BlockStmt(); (yyval.pblockstmt)->appendChapelStmt((yyvsp[0].pblockstmt)); }
#line 6198 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 52:
#line 606 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-1].pblockstmt)->appendChapelStmt((yyvsp[0].pblockstmt)); }
#line 6204 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 53:
#line 611 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.ponlylist) = new std::vector<OnlyRename*>();
                                         OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::SINGLE;
                                         cur->elem = (yyvsp[0].pexpr);
                                         (yyval.ponlylist)->push_back(cur); }
#line 6214 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 54:
#line 616 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.ponlylist) = new std::vector<OnlyRename*>();
                                         OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::DOUBLE;
                                         cur->renamed = new std::pair<Expr*, Expr*>((yyvsp[-2].pexpr), (yyvsp[0].pexpr));
                                         (yyval.ponlylist)->push_back(cur); }
#line 6224 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 55:
#line 621 "chapel.ypp" /* yacc.c:1667  */
    { OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::SINGLE;
                                         cur->elem = (yyvsp[0].pexpr);
                                         (yyvsp[-2].ponlylist)->push_back(cur); }
#line 6233 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 56:
#line 625 "chapel.ypp" /* yacc.c:1667  */
    { OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::DOUBLE;
                                         cur->renamed = new std::pair<Expr*, Expr*>((yyvsp[-2].pexpr), (yyvsp[0].pexpr));
                                         (yyvsp[-4].ponlylist)->push_back(cur); }
#line 6242 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 57:
#line 632 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.ponlylist) = new std::vector<OnlyRename*>();
                                         OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::SINGLE;
                                         cur->elem = new UnresolvedSymExpr("");
                                         (yyval.ponlylist)->push_back(cur); }
#line 6252 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 59:
#line 641 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.ponlylist) = new std::vector<OnlyRename*>();
                                         OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::SINGLE;
                                         cur->elem = new UnresolvedSymExpr("");
                                         (yyval.ponlylist)->push_back(cur); }
#line 6262 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 61:
#line 650 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.b) = false; }
#line 6268 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 62:
#line 651 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.b) = false; }
#line 6274 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 63:
#line 652 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.b) = true; }
#line 6280 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 64:
#line 656 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildUseStmt((yyvsp[-1].pcallexpr), (yyvsp[-3].b)); }
#line 6286 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 65:
#line 657 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildUseStmt((yyvsp[-3].pexpr), (yyvsp[-1].ponlylist), true, (yyvsp[-5].b)); }
#line 6292 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 66:
#line 658 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildUseStmt((yyvsp[-3].pexpr), (yyvsp[-1].ponlylist), false, (yyvsp[-5].b)); }
#line 6298 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 67:
#line 662 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildRequireStmt((yyvsp[-1].pcallexpr)); }
#line 6304 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 68:
#line 667 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), (yyvsp[-2].pch));   }
#line 6310 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 69:
#line 669 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), "<=>"); }
#line 6316 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 70:
#line 671 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), PRIM_REDUCE_ASSIGN); }
#line 6322 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 71:
#line 673 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildLAndAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr));    }
#line 6328 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 72:
#line 675 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildLOrAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr));     }
#line 6334 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 73:
#line 681 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = NULL; }
#line 6340 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 74:
#line 682 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 6346 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 75:
#line 686 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 6352 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 76:
#line 687 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "none"; redefiningReservedWordError((yyval.pch)); }
#line 6358 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 77:
#line 688 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "this"; }
#line 6364 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 78:
#line 689 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "false"; redefiningReservedWordError((yyval.pch)); }
#line 6370 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 79:
#line 690 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "true"; redefiningReservedWordError((yyval.pch)); }
#line 6376 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 80:
#line 691 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = (yyvsp[0].pch); redefiningReservedTypeError((yyvsp[0].pch)); }
#line 6382 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 81:
#line 694 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 6388 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 82:
#line 695 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "none"; redefiningReservedWordError((yyval.pch)); }
#line 6394 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 83:
#line 696 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "this"; redefiningReservedWordError((yyval.pch)); }
#line 6400 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 84:
#line 697 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "false"; redefiningReservedWordError((yyval.pch)); }
#line 6406 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 85:
#line 698 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "true"; redefiningReservedWordError((yyval.pch)); }
#line 6412 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 86:
#line 699 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = (yyvsp[0].pch); redefiningReservedTypeError((yyvsp[0].pch)); }
#line 6418 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 87:
#line 711 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 6424 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 88:
#line 712 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "this"; }
#line 6430 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 89:
#line 723 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "bool"; }
#line 6436 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 90:
#line 724 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "int"; }
#line 6442 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 91:
#line 725 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "uint"; }
#line 6448 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 92:
#line 726 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "real"; }
#line 6454 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 93:
#line 727 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "imag"; }
#line 6460 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 94:
#line 728 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "complex"; }
#line 6466 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 95:
#line 729 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "bytes"; }
#line 6472 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 96:
#line 730 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "string"; }
#line 6478 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 97:
#line 731 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "sync"; }
#line 6484 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 98:
#line 732 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "single"; }
#line 6490 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 99:
#line 733 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "owned"; }
#line 6496 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 100:
#line 734 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "shared"; }
#line 6502 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 101:
#line 735 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "borrowed"; }
#line 6508 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 102:
#line 736 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "unmanaged"; }
#line 6514 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 103:
#line 737 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "domain"; }
#line 6520 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 104:
#line 738 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "index"; }
#line 6526 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 105:
#line 739 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "locale"; }
#line 6532 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 106:
#line 740 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "nothing"; }
#line 6538 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 107:
#line 741 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "void"; }
#line 6544 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 108:
#line 745 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtBools[BOOL_SIZE_DEFAULT]->symbol); }
#line 6550 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 109:
#line 746 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtInt[INT_SIZE_DEFAULT]->symbol); }
#line 6556 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 110:
#line 747 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtUInt[INT_SIZE_DEFAULT]->symbol); }
#line 6562 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 111:
#line 748 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtReal[FLOAT_SIZE_DEFAULT]->symbol); }
#line 6568 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 112:
#line 749 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtImag[FLOAT_SIZE_DEFAULT]->symbol); }
#line 6574 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 113:
#line 750 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtComplex[COMPLEX_SIZE_DEFAULT]->symbol); }
#line 6580 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 114:
#line 751 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtBytes->symbol); }
#line 6586 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 115:
#line 752 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtString->symbol); }
#line 6592 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 116:
#line 753 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtLocale->symbol); }
#line 6598 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 117:
#line 754 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtNothing->symbol); }
#line 6604 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 118:
#line 755 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtVoid->symbol); }
#line 6610 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 119:
#line 762 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "_syncvar"; }
#line 6616 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 120:
#line 763 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "_singlevar"; }
#line 6622 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 121:
#line 764 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "_domain"; }
#line 6628 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 122:
#line 765 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "_index"; }
#line 6634 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 123:
#line 775 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = (yyvsp[0].pblockstmt); }
#line 6640 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 124:
#line 776 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = (yyvsp[0].pblockstmt); }
#line 6646 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 125:
#line 780 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_RETURN); }
#line 6652 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 126:
#line 781 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_RETURN, (yyvsp[-1].pexpr)); }
#line 6658 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 127:
#line 785 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildChapelStmt(new BlockStmt()); }
#line 6664 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 129:
#line 787 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = (yyvsp[0].pblockstmt); }
#line 6670 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 130:
#line 788 "chapel.ypp" /* yacc.c:1667  */
    { applyPrivateToBlock((yyvsp[0].pblockstmt)); (yyval.pblockstmt) = (yyvsp[0].pblockstmt); }
#line 6676 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 138:
#line 802 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildForwardingStmt((yyvsp[-1].pexpr)); }
#line 6682 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 139:
#line 803 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildForwardingStmt((yyvsp[-3].pexpr), (yyvsp[-1].ponlylist), true); }
#line 6688 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 140:
#line 804 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildForwardingStmt((yyvsp[-3].pexpr), (yyvsp[-1].ponlylist), false); }
#line 6694 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 141:
#line 805 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildForwardingDeclStmt((yyvsp[0].pblockstmt)); }
#line 6700 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 142:
#line 810 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = buildChapelStmt(buildClassDefExpr((yyvsp[-4].pch),
                                             NULL,
                                             AGGREGATE_RECORD,
                                             (yyvsp[-3].pcallexpr),
                                             (yyvsp[-1].pblockstmt),
                                             FLAG_EXTERN,
                                             (yylsp[-5]).comment));
    }
#line 6714 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 143:
#line 820 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = buildChapelStmt(buildClassDefExpr((yyvsp[-4].pch),
                                             (yyvsp[-6].pch),
                                             AGGREGATE_RECORD,
                                             (yyvsp[-3].pcallexpr),
                                             (yyvsp[-1].pblockstmt),
                                             FLAG_EXTERN,
                                             (yylsp[-5]).comment));
    }
#line 6728 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 144:
#line 830 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = buildChapelStmt(buildClassDefExpr((yyvsp[-4].pch),
                                             NULL,
                                             AGGREGATE_RECORD,
                                             (yyvsp[-3].pcallexpr),
                                             (yyvsp[-1].pblockstmt),
                                             FLAG_EXPORT,
                                             (yylsp[-5]).comment));
    }
#line 6742 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 145:
#line 840 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = buildChapelStmt(buildClassDefExpr((yyvsp[-4].pch),
                                             (yyvsp[-6].pch),
                                             AGGREGATE_RECORD,
                                             (yyvsp[-3].pcallexpr),
                                             (yyvsp[-1].pblockstmt),
                                             FLAG_EXPORT,
                                             (yylsp[-5]).comment));
    }
#line 6756 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 146:
#line 851 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = buildExternExportFunctionDecl(FLAG_EXTERN, (yyvsp[-1].pexpr), (yyvsp[0].pblockstmt));
    }
#line 6764 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 147:
#line 855 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = buildExternExportFunctionDecl(FLAG_EXPORT, (yyvsp[-1].pexpr), (yyvsp[0].pblockstmt));
    }
#line 6772 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 148:
#line 860 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyvsp[-2].pflagset)->insert(FLAG_EXTERN);
      (yyval.pblockstmt) = buildVarDecls((yyvsp[-1].pblockstmt), context->latestComment, (yyvsp[-2].pflagset), (yyvsp[-3].pexpr));
      context->latestComment = NULL;
    }
#line 6782 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 149:
#line 866 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyvsp[-2].pflagset)->insert(FLAG_EXPORT);
      (yyval.pblockstmt) = buildVarDecls((yyvsp[-1].pblockstmt), context->latestComment, (yyvsp[-2].pflagset), (yyvsp[-3].pexpr));
      context->latestComment = NULL;
    }
#line 6792 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 150:
#line 875 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = buildExternBlockStmt(astr((yyvsp[0].pch)));
    }
#line 6800 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 151:
#line 881 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = DoWhileStmt::build((yyvsp[-1].pexpr), (yyvsp[-3].pblockstmt)); }
#line 6806 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 152:
#line 882 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = WhileDoStmt::build((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 6812 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 153:
#line 883 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildCoforallLoopStmt((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt));       }
#line 6818 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 154:
#line 884 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildCoforallLoopStmt((yyvsp[-4].pexpr), (yyvsp[-2].pcallexpr), (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt), true); }
#line 6824 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 155:
#line 885 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildCoforallLoopStmt(NULL, (yyvsp[-2].pexpr), (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt));     }
#line 6830 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 156:
#line 886 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForLoop::buildForLoop(  (yyvsp[-3].pexpr), (yyvsp[-1].pexpr), (yyvsp[0].pblockstmt), false, false); }
#line 6836 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 157:
#line 887 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForLoop::buildForLoop(  (yyvsp[-3].pexpr), (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt), false,  true); }
#line 6842 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 158:
#line 888 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForLoop::buildForLoop(NULL, (yyvsp[-1].pexpr), (yyvsp[0].pblockstmt), false, false); }
#line 6848 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 159:
#line 889 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForLoop::buildForLoop(NULL, (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt), false,  true); }
#line 6854 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 160:
#line 890 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildParamForLoopStmt((yyvsp[-3].pch), (yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 6860 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 161:
#line 891 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForallStmt::build((yyvsp[-3].pexpr),   (yyvsp[-1].pexpr), NULL, (yyvsp[0].pblockstmt), false, false); }
#line 6866 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 162:
#line 892 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForallStmt::build((yyvsp[-4].pexpr),   (yyvsp[-2].pexpr), (yyvsp[-1].pcallexpr),   (yyvsp[0].pblockstmt), false, false); }
#line 6872 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 163:
#line 893 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForallStmt::build((yyvsp[-3].pexpr),   (yyvsp[-1].pcallexpr), NULL, (yyvsp[0].pblockstmt), true,  false); }
#line 6878 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 164:
#line 894 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForallStmt::build((yyvsp[-4].pexpr),   (yyvsp[-2].pcallexpr), (yyvsp[-1].pcallexpr),   (yyvsp[0].pblockstmt), true,  false); }
#line 6884 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 165:
#line 895 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-1].pexpr), NULL, (yyvsp[0].pblockstmt), false, false); }
#line 6890 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 166:
#line 896 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-2].pexpr), (yyvsp[-1].pcallexpr),   (yyvsp[0].pblockstmt), false, false); }
#line 6896 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 167:
#line 897 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-1].pcallexpr), NULL, (yyvsp[0].pblockstmt), true,  false); }
#line 6902 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 168:
#line 898 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-2].pcallexpr), (yyvsp[-1].pcallexpr),   (yyvsp[0].pblockstmt), true,  false); }
#line 6908 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 169:
#line 900 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pexpr), "invalid index expression");
      (yyval.pblockstmt) = ForallStmt::build((yyvsp[-4].pcallexpr)->get(1)->remove(), (yyvsp[-2].pexpr), NULL, new BlockStmt((yyvsp[0].pblockstmt)), false, true);
    }
#line 6918 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 170:
#line 906 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-5].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-3].pexpr), "invalid index expression");
      (yyval.pblockstmt) = ForallStmt::build((yyvsp[-5].pcallexpr)->get(1)->remove(), (yyvsp[-3].pexpr), (yyvsp[-2].pcallexpr),   new BlockStmt((yyvsp[0].pblockstmt)), false, true);
    }
#line 6928 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 171:
#line 912 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pcallexpr), "invalid index expression");
      (yyval.pblockstmt) = ForallStmt::build((yyvsp[-4].pcallexpr)->get(1)->remove(), (yyvsp[-2].pcallexpr), NULL, new BlockStmt((yyvsp[0].pblockstmt)), true,  true);
    }
#line 6938 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 172:
#line 918 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-5].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-3].pcallexpr), "invalid index expression");
      (yyval.pblockstmt) = ForallStmt::build((yyvsp[-5].pcallexpr)->get(1)->remove(), (yyvsp[-3].pcallexpr), (yyvsp[-2].pcallexpr),   new BlockStmt((yyvsp[0].pblockstmt)), true,  true);
    }
#line 6948 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 173:
#line 924 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-2].pcallexpr)->argList.length > 1)
        (yyval.pblockstmt) = ForallStmt::build(NULL, new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), NULL, new BlockStmt((yyvsp[0].pblockstmt)), false, true);
      else
        (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-2].pcallexpr)->get(1)->remove(),                       NULL, new BlockStmt((yyvsp[0].pblockstmt)), false, true);
    }
#line 6959 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 174:
#line 931 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-3].pcallexpr)->argList.length > 1)
        (yyval.pblockstmt) = ForallStmt::build(NULL, new CallExpr("chpl__ensureDomainExpr", (yyvsp[-3].pcallexpr)), (yyvsp[-2].pcallexpr), new BlockStmt((yyvsp[0].pblockstmt)), false, true);
      else
        (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-3].pcallexpr)->get(1)->remove(),                       (yyvsp[-2].pcallexpr), new BlockStmt((yyvsp[0].pblockstmt)), false, true);
    }
#line 6970 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 175:
#line 938 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-2].pcallexpr), NULL, new BlockStmt((yyvsp[0].pblockstmt)), true,  true);
    }
#line 6978 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 176:
#line 942 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-3].pcallexpr), (yyvsp[-2].pcallexpr),   new BlockStmt((yyvsp[0].pblockstmt)), true,  true);
    }
#line 6986 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 177:
#line 948 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ZIP, (yyvsp[-1].pcallexpr)); }
#line 6992 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 178:
#line 952 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[-2].pexpr), (yyvsp[0].pblockstmt)); }
#line 6998 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 179:
#line 953 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 7004 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 180:
#line 954 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[-4].pexpr), (yyvsp[-2].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 7010 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 181:
#line 955 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[-3].pexpr), (yyvsp[-2].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 7016 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 182:
#line 956 "chapel.ypp" /* yacc.c:1667  */
    {
(yyval.pblockstmt) = buildIfStmt(convertAssignmentAndWarn((yyvsp[-4].pexpr),(yyvsp[-3].pch),(yyvsp[-2].pexpr)), (yyvsp[0].pblockstmt)); }
#line 7023 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 183:
#line 958 "chapel.ypp" /* yacc.c:1667  */
    {
(yyval.pblockstmt) = buildIfStmt(convertAssignmentAndWarn((yyvsp[-3].pexpr),(yyvsp[-2].pch),(yyvsp[-1].pexpr)), (yyvsp[0].pblockstmt)); }
#line 7030 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 184:
#line 960 "chapel.ypp" /* yacc.c:1667  */
    {
(yyval.pblockstmt) = buildIfStmt(convertAssignmentAndWarn((yyvsp[-6].pexpr),(yyvsp[-5].pch),(yyvsp[-4].pexpr)), (yyvsp[-2].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 7037 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 185:
#line 962 "chapel.ypp" /* yacc.c:1667  */
    {
(yyval.pblockstmt) = buildIfStmt(convertAssignmentAndWarn((yyvsp[-5].pexpr),(yyvsp[-4].pch),(yyvsp[-3].pexpr)), (yyvsp[-2].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 7044 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 186:
#line 967 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = DeferStmt::build((yyvsp[0].pblockstmt)); }
#line 7050 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 187:
#line 970 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = TryStmt::build(false, (yyvsp[-1].pexpr)); }
#line 7056 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 188:
#line 971 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = TryStmt::build(true,  (yyvsp[-1].pexpr)); }
#line 7062 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 189:
#line 972 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = TryStmt::build(false, (yyvsp[0].pblockstmt)); }
#line 7068 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 190:
#line 973 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = TryStmt::build(true,  (yyvsp[0].pblockstmt)); }
#line 7074 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 191:
#line 974 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = TryStmt::build(false, (yyvsp[-1].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 7080 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 192:
#line 975 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = TryStmt::build(true,  (yyvsp[-1].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 7086 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 193:
#line 979 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildChapelStmt(); }
#line 7092 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 194:
#line 980 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-1].pblockstmt)->insertAtTail((yyvsp[0].pexpr)); }
#line 7098 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 195:
#line 984 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = CatchStmt::build((yyvsp[0].pblockstmt)); }
#line 7104 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 196:
#line 985 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = CatchStmt::build((yyvsp[-1].pdefexpr), (yyvsp[0].pblockstmt)); }
#line 7110 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 197:
#line 986 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = CatchStmt::build((yyvsp[-2].pdefexpr), (yyvsp[0].pblockstmt)); }
#line 7116 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 198:
#line 990 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pdefexpr) = new DefExpr(new VarSymbol((yyvsp[0].pch)), NULL, new UnresolvedSymExpr("Error")); }
#line 7122 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 199:
#line 991 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pdefexpr) = new DefExpr(new VarSymbol((yyvsp[-2].pch)), NULL, (yyvsp[0].pexpr));   }
#line 7128 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 200:
#line 995 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_THROW, (yyvsp[-1].pexpr)); }
#line 7134 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 201:
#line 999 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildChapelStmt(buildSelectStmt((yyvsp[-3].pexpr), (yyvsp[-1].pblockstmt))); }
#line 7140 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 202:
#line 1001 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildErrorStandin(); }
#line 7146 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 203:
#line 1005 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildChapelStmt(); }
#line 7152 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 204:
#line 1006 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-1].pblockstmt)->insertAtTail((yyvsp[0].pexpr)); }
#line 7158 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 205:
#line 1011 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CondStmt(new CallExpr(PRIM_WHEN, (yyvsp[-1].pcallexpr)), (yyvsp[0].pblockstmt)); }
#line 7164 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 206:
#line 1013 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CondStmt(new CallExpr(PRIM_WHEN), (yyvsp[0].pblockstmt)); }
#line 7170 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 207:
#line 1015 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CondStmt(new CallExpr(PRIM_WHEN), (yyvsp[0].pblockstmt)); }
#line 7176 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 208:
#line 1022 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = buildChapelStmt(buildClassDefExpr((yyvsp[-4].pch),
                                             NULL,
                                             (yyvsp[-5].aggrTag),
                                             (yyvsp[-3].pcallexpr),
                                             (yyvsp[-1].pblockstmt),
                                             FLAG_UNKNOWN,
                                             (yylsp[-5]).comment));
    }
#line 7190 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 209:
#line 1032 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = buildChapelStmt(buildClassDefExpr((yyvsp[-4].pch),
                                             NULL,
                                             (yyvsp[-5].aggrTag),
                                             (yyvsp[-3].pcallexpr),
                                             new BlockStmt(),
                                             FLAG_UNKNOWN,
                                             (yylsp[-5]).comment));
    }
#line 7204 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 210:
#line 1045 "chapel.ypp" /* yacc.c:1667  */
    {
             (yyval.aggrTag)                     = AGGREGATE_CLASS;
             (yyloc).comment             = context->latestComment;
             context->latestComment = NULL;
           }
#line 7214 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 211:
#line 1050 "chapel.ypp" /* yacc.c:1667  */
    {
             (yyval.aggrTag)                     = AGGREGATE_RECORD;
             (yyloc).comment             = context->latestComment;
             context->latestComment = NULL;
           }
#line 7224 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 212:
#line 1055 "chapel.ypp" /* yacc.c:1667  */
    {
             (yyval.aggrTag)                     = AGGREGATE_UNION;
             (yyloc).comment             = context->latestComment;
             context->latestComment = NULL;
           }
#line 7234 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 213:
#line 1063 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = NULL; }
#line 7240 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 214:
#line 1064 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = (yyvsp[0].pcallexpr); }
#line 7246 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 215:
#line 1069 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = new BlockStmt(); }
#line 7252 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 216:
#line 1071 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-1].pblockstmt)->insertAtTail((yyvsp[0].pblockstmt)); }
#line 7258 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 217:
#line 1073 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-2].pblockstmt)->insertAtTail(buildPragmaStmt((yyvsp[-1].vpch), (yyvsp[0].pblockstmt))); }
#line 7264 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 218:
#line 1078 "chapel.ypp" /* yacc.c:1667  */
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
#line 7284 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 219:
#line 1094 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = buildErrorStandin();
    }
#line 7292 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 220:
#line 1101 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.penumtype) = new EnumType();
      (yyloc).comment = context->latestComment;
      context->latestComment = NULL;
    }
#line 7302 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 221:
#line 1110 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pvecOfDefs) = new std::vector<DefExpr*>();
      (yyval.pvecOfDefs)->push_back((yyvsp[0].pdefexpr));
      //$$->doc = context->latestComment;
      // start here for enabling documentation of enum constants
      //context->latestComment = NULL;
    }
#line 7314 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 222:
#line 1118 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pvecOfDefs) = (yyvsp[-1].pvecOfDefs);
    }
#line 7322 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 223:
#line 1122 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyvsp[-2].pvecOfDefs)->push_back((yyvsp[0].pdefexpr));
    }
#line 7330 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 224:
#line 1128 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pdefexpr) = new DefExpr(new EnumSymbol((yyvsp[0].pch))); }
#line 7336 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 225:
#line 1129 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pdefexpr) = new DefExpr(new EnumSymbol((yyvsp[-2].pch)), (yyvsp[0].pexpr)); }
#line 7342 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 226:
#line 1134 "chapel.ypp" /* yacc.c:1667  */
    {
      captureTokens = 1;
      captureString.clear();
    }
#line 7351 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 227:
#line 1139 "chapel.ypp" /* yacc.c:1667  */
    {
      captureTokens = 0;
      (yyvsp[0].pfnsymbol)->userString = astr(captureString);
    }
#line 7360 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 228:
#line 1144 "chapel.ypp" /* yacc.c:1667  */
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
#line 7382 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 229:
#line 1166 "chapel.ypp" /* yacc.c:1667  */
    {
                  (yyval.pfnsymbol) = new FnSymbol("");

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 7393 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 230:
#line 1172 "chapel.ypp" /* yacc.c:1667  */
    {
                  (yyval.pfnsymbol) = new FnSymbol("");
                  (yyval.pfnsymbol)->addFlag(FLAG_INLINE);

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 7405 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 231:
#line 1179 "chapel.ypp" /* yacc.c:1667  */
    {
                  (yyval.pfnsymbol) = new FnSymbol("");
                  (yyval.pfnsymbol)->addFlag(FLAG_OVERRIDE);

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 7417 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 232:
#line 1190 "chapel.ypp" /* yacc.c:1667  */
    {
      // Sets up to capture tokens while parsing the next grammar nonterminal.
      captureTokens = 1;
      captureString.clear();
    }
#line 7427 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 233:
#line 1196 "chapel.ypp" /* yacc.c:1667  */
    {
      // Stop capturing and save the result.
      captureTokens = 0;

      (yyvsp[0].pfnsymbol)->userString = astr(captureString);
    }
#line 7438 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 234:
#line 1203 "chapel.ypp" /* yacc.c:1667  */
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
#line 7465 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 235:
#line 1229 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), (yyvsp[-1].pch), (yyvsp[-2].pt), NULL);
    }
#line 7473 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 236:
#line 1233 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), (yyvsp[-1].pch), (yyvsp[-2].pt), NULL);
      (yyval.pfnsymbol)->addFlag(FLAG_ASSIGNOP);
    }
#line 7482 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 237:
#line 1238 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), (yyvsp[-1].pch), (yyvsp[-4].pt), (yyvsp[-3].pexpr));
    }
#line 7490 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 238:
#line 1242 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), (yyvsp[-1].pch), (yyvsp[-4].pt), (yyvsp[-3].pexpr));
      (yyval.pfnsymbol)->addFlag(FLAG_ASSIGNOP);
    }
#line 7499 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 239:
#line 1247 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), "dummy", INTENT_BLANK, NULL);
    }
#line 7507 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 241:
#line 1254 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[-1].pexpr); }
#line 7513 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 242:
#line 1258 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 7519 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 243:
#line 1259 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = astr("~", (yyvsp[0].pch)); }
#line 7525 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 244:
#line 1260 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "&"; }
#line 7531 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 245:
#line 1261 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "|"; }
#line 7537 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 246:
#line 1262 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "^"; }
#line 7543 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 247:
#line 1263 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "~"; }
#line 7549 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 248:
#line 1264 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "=="; }
#line 7555 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 249:
#line 1265 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "!="; }
#line 7561 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 250:
#line 1266 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "<="; }
#line 7567 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 251:
#line 1267 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = ">="; }
#line 7573 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 252:
#line 1268 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "<"; }
#line 7579 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 253:
#line 1269 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = ">"; }
#line 7585 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 254:
#line 1270 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "+"; }
#line 7591 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 255:
#line 1271 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "-"; }
#line 7597 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 256:
#line 1272 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "*"; }
#line 7603 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 257:
#line 1273 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "/"; }
#line 7609 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 258:
#line 1274 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "<<"; }
#line 7615 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 259:
#line 1275 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = ">>"; }
#line 7621 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 260:
#line 1276 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "%"; }
#line 7627 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 261:
#line 1277 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "**"; }
#line 7633 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 262:
#line 1278 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "!"; }
#line 7639 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 263:
#line 1279 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "chpl_by"; }
#line 7645 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 264:
#line 1280 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "#"; }
#line 7651 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 265:
#line 1281 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "chpl_align"; }
#line 7657 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 266:
#line 1282 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "<=>"; }
#line 7663 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 267:
#line 1283 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "<~>"; }
#line 7669 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 268:
#line 1284 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "init="; }
#line 7675 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 269:
#line 1285 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = astr((yyvsp[-1].pch), "!"); }
#line 7681 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 270:
#line 1289 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "="; }
#line 7687 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 271:
#line 1290 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "+="; }
#line 7693 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 272:
#line 1291 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "-="; }
#line 7699 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 273:
#line 1292 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "*="; }
#line 7705 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 274:
#line 1293 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "/="; }
#line 7711 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 275:
#line 1294 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "%="; }
#line 7717 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 276:
#line 1295 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "**="; }
#line 7723 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 277:
#line 1296 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "&="; }
#line 7729 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 278:
#line 1297 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "|="; }
#line 7735 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 279:
#line 1298 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "^="; }
#line 7741 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 280:
#line 1299 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = ">>="; }
#line 7747 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 281:
#line 1300 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "<<="; }
#line 7753 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 282:
#line 1304 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pfnsymbol) = new FnSymbol("_"); (yyval.pfnsymbol)->addFlag(FLAG_NO_PARENS); }
#line 7759 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 283:
#line 1305 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pfnsymbol) = (yyvsp[-1].pfnsymbol); }
#line 7765 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 284:
#line 1309 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pfnsymbol) = (yyvsp[-1].pfnsymbol); }
#line 7771 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 285:
#line 1313 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pfnsymbol) = buildFunctionFormal(NULL, NULL); }
#line 7777 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 286:
#line 1314 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pfnsymbol) = buildFunctionFormal(NULL, (yyvsp[0].pdefexpr)); }
#line 7783 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 287:
#line 1315 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pfnsymbol) = buildFunctionFormal((yyvsp[-2].pfnsymbol), (yyvsp[0].pdefexpr)); }
#line 7789 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 288:
#line 1320 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pdefexpr) = buildArgDefExpr((yyvsp[-3].pt), (yyvsp[-2].pch), (yyvsp[-1].pexpr), (yyvsp[0].pexpr), NULL); }
#line 7795 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 289:
#line 1322 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pdefexpr) = buildPragmaDefExpr((yyvsp[-4].vpch), buildArgDefExpr((yyvsp[-3].pt), (yyvsp[-2].pch), (yyvsp[-1].pexpr), (yyvsp[0].pexpr), NULL)); }
#line 7801 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 290:
#line 1324 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pdefexpr) = buildArgDefExpr((yyvsp[-3].pt), (yyvsp[-2].pch), (yyvsp[-1].pexpr), NULL, (yyvsp[0].pexpr)); }
#line 7807 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 291:
#line 1326 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pdefexpr) = buildTupleArgDefExpr((yyvsp[-5].pt), (yyvsp[-3].pblockstmt), (yyvsp[-1].pexpr), (yyvsp[0].pexpr)); }
#line 7813 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 292:
#line 1328 "chapel.ypp" /* yacc.c:1667  */
    { USR_FATAL("variable-length argument may not be grouped in a tuple"); }
#line 7819 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 293:
#line 1332 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_BLANK; }
#line 7825 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 294:
#line 1333 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = (yyvsp[0].pt); }
#line 7831 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 295:
#line 1337 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_IN; }
#line 7837 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 296:
#line 1338 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_INOUT; }
#line 7843 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 297:
#line 1339 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_OUT; }
#line 7849 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 298:
#line 1340 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_CONST; }
#line 7855 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 299:
#line 1341 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_CONST_IN; }
#line 7861 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 300:
#line 1342 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_CONST_REF; }
#line 7867 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 301:
#line 1343 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_PARAM; }
#line 7873 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 302:
#line 1344 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_REF; }
#line 7879 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 303:
#line 1345 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_TYPE; }
#line 7885 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 304:
#line 1349 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_BLANK; }
#line 7891 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 305:
#line 1350 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_PARAM; }
#line 7897 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 306:
#line 1351 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_REF;   }
#line 7903 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 307:
#line 1352 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_CONST_REF;   }
#line 7909 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 308:
#line 1353 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_CONST;   }
#line 7915 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 309:
#line 1354 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_TYPE;  }
#line 7921 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 310:
#line 1358 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.procIter) = ProcIter_PROC; }
#line 7927 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 311:
#line 1359 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.procIter) = ProcIter_ITER; }
#line 7933 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 312:
#line 1363 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.retTag) = RET_VALUE; }
#line 7939 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 313:
#line 1364 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.retTag) = RET_VALUE; }
#line 7945 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 314:
#line 1365 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.retTag) = RET_CONST_REF; }
#line 7951 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 315:
#line 1366 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.retTag) = RET_REF; }
#line 7957 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 316:
#line 1367 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.retTag) = RET_PARAM; }
#line 7963 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 317:
#line 1368 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.retTag) = RET_TYPE; }
#line 7969 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 318:
#line 1372 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.b) = false; }
#line 7975 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 319:
#line 1373 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.b) = true;  }
#line 7981 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 320:
#line 1376 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = NULL; }
#line 7987 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 323:
#line 1382 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = new BlockStmt((yyvsp[0].pblockstmt)); }
#line 7993 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 324:
#line 1387 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new DefExpr(new VarSymbol((yyvsp[0].pch))); }
#line 7999 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 325:
#line 1389 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(gUninstantiated); }
#line 8005 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 326:
#line 1393 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(gUninstantiated); }
#line 8011 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 328:
#line 1398 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8017 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 329:
#line 1399 "chapel.ypp" /* yacc.c:1667  */
    { if (DefExpr* def = toDefExpr((yyvsp[0].pexpr))) {
                                 def->sym->addFlag(FLAG_PARAM);
                               }
                               (yyval.pexpr) = (yyvsp[0].pexpr);
                             }
#line 8027 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 330:
#line 1407 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.lifetimeAndWhere) = makeWhereAndLifetime(NULL, NULL); }
#line 8033 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 331:
#line 1409 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.lifetimeAndWhere) = makeWhereAndLifetime((yyvsp[0].pexpr), NULL); }
#line 8039 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 332:
#line 1411 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.lifetimeAndWhere) = makeWhereAndLifetime(NULL, (yyvsp[0].pexpr)); }
#line 8045 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 333:
#line 1413 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.lifetimeAndWhere) = makeWhereAndLifetime((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8051 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 334:
#line 1415 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.lifetimeAndWhere) = makeWhereAndLifetime((yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 8057 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 335:
#line 1419 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8063 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 336:
#line 1420 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(",", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8069 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 337:
#line 1423 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8075 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 338:
#line 1424 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("<", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8081 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 339:
#line 1425 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("<=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8087 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 340:
#line 1426 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("==", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8093 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 341:
#line 1427 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(">", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8099 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 342:
#line 1428 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(">=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8105 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 343:
#line 1429 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(PRIM_RETURN, (yyvsp[0].pexpr)); }
#line 8111 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 344:
#line 1432 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(PRIM_LIFETIME_OF, new UnresolvedSymExpr((yyvsp[0].pch))); }
#line 8117 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 345:
#line 1433 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(PRIM_LIFETIME_OF, new UnresolvedSymExpr("this")); }
#line 8123 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 346:
#line 1437 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = (yyvsp[-1].pblockstmt); }
#line 8129 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 347:
#line 1439 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = handleConfigTypes((yyvsp[-1].pblockstmt)); }
#line 8135 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 348:
#line 1441 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = convertTypesToExtern((yyvsp[-1].pblockstmt)); }
#line 8141 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 349:
#line 1446 "chapel.ypp" /* yacc.c:1667  */
    {
      VarSymbol* var = new VarSymbol((yyvsp[-1].pch));

      var->addFlag(FLAG_TYPE_VARIABLE);

      var->doc               = context->latestComment;
      context->latestComment = NULL;

      DefExpr* def = new DefExpr(var, (yyvsp[0].pexpr));

      (yyval.pblockstmt) = buildChapelStmt(def);
    }
#line 8158 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 350:
#line 1459 "chapel.ypp" /* yacc.c:1667  */
    {
      VarSymbol* var = new VarSymbol((yyvsp[-3].pch));

      var->addFlag(FLAG_TYPE_VARIABLE);

      var->doc               = context->latestComment;
      context->latestComment = NULL;

      DefExpr* def = new DefExpr(var, (yyvsp[-2].pexpr));

      (yyvsp[0].pblockstmt)->insertAtHead(def);
      (yyval.pblockstmt) = buildChapelStmt((yyvsp[0].pblockstmt));
    }
#line 8176 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 351:
#line 1475 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = NULL; }
#line 8182 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 352:
#line 1477 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8188 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 353:
#line 1479 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForallLoopExprFromArrayType((yyvsp[0].pcallexpr)); }
#line 8194 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 354:
#line 1483 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pflagset) = buildVarDeclFlags(FLAG_PARAM); }
#line 8200 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 355:
#line 1484 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pflagset) = buildVarDeclFlags(FLAG_CONST); }
#line 8206 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 356:
#line 1485 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pflagset) = buildVarDeclFlags(FLAG_REF_VAR); }
#line 8212 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 357:
#line 1486 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pflagset) = buildVarDeclFlags(FLAG_CONST, FLAG_REF_VAR); }
#line 8218 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 358:
#line 1487 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pflagset) = buildVarDeclFlags(); }
#line 8224 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 359:
#line 1492 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyvsp[-2].pflagset)->insert(FLAG_CONFIG);
      (yyval.pblockstmt) = buildVarDecls((yyvsp[-1].pblockstmt), context->latestComment, (yyvsp[-2].pflagset));
      context->latestComment = NULL;
    }
#line 8234 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 360:
#line 1498 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = buildVarDecls((yyvsp[-1].pblockstmt), context->latestComment, (yyvsp[-2].pflagset));
      context->latestComment = NULL;
    }
#line 8243 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 362:
#line 1507 "chapel.ypp" /* yacc.c:1667  */
    {
      for_alist(expr, (yyvsp[0].pblockstmt)->body)
        (yyvsp[-2].pblockstmt)->insertAtTail(expr->remove());
    }
#line 8252 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 363:
#line 1515 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildChapelStmt(new DefExpr(new VarSymbol((yyvsp[-2].pch)), (yyvsp[0].pexpr), (yyvsp[-1].pexpr))); }
#line 8258 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 364:
#line 1517 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildTupleVarDeclStmt((yyvsp[-3].pblockstmt), (yyvsp[-1].pexpr), (yyvsp[0].pexpr)); }
#line 8264 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 365:
#line 1522 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new DefExpr(new VarSymbol("chpl__tuple_blank")); }
#line 8270 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 366:
#line 1524 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new DefExpr(new VarSymbol((yyvsp[0].pch))); }
#line 8276 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 367:
#line 1526 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[-1].pblockstmt); }
#line 8282 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 368:
#line 1531 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildChapelStmt((yyvsp[0].pexpr)); }
#line 8288 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 369:
#line 1533 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildChapelStmt((yyvsp[-1].pexpr)); }
#line 8294 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 370:
#line 1535 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ((yyvsp[0].pblockstmt)->insertAtHead((yyvsp[-2].pexpr)), (yyvsp[0].pblockstmt)); }
#line 8300 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 371:
#line 1541 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = NULL; }
#line 8306 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 372:
#line 1542 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(gNoInit); }
#line 8312 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 373:
#line 1543 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8318 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 374:
#line 1549 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, (yyvsp[0].pexpr)); }
#line 8324 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 375:
#line 1551 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, NULL); }
#line 8330 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 376:
#line 1553 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pexpr));
    }
#line 8338 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 377:
#line 1557 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-1].pcallexpr)), NULL);
    }
#line 8346 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 378:
#line 1561 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, (yyvsp[0].pexpr)); }
#line 8352 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 379:
#line 1563 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pexpr));
    }
#line 8360 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 380:
#line 1567 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pexpr) = new CallExpr(PRIM_ERROR);
    }
#line 8368 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 381:
#line 1574 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = NULL; }
#line 8374 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 382:
#line 1575 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8380 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 383:
#line 1576 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8386 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 384:
#line 1577 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr((yyvsp[0].pch)); }
#line 8392 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 385:
#line 1578 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = NULL; }
#line 8398 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 386:
#line 1583 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = NULL; }
#line 8404 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 387:
#line 1584 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8410 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 388:
#line 1585 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pcallexpr); }
#line 8416 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 389:
#line 1586 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr((yyvsp[0].pch)); }
#line 8422 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 390:
#line 1587 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = NULL; }
#line 8428 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 391:
#line 1608 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pexpr));
    }
#line 8436 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 392:
#line 1612 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pcallexpr));
    }
#line 8444 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 393:
#line 1616 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pexpr), "invalid index expression");
      (yyval.pcallexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pexpr)), (yyvsp[0].pexpr), (yyvsp[-4].pcallexpr)->get(1)->remove(),
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pexpr)->copy()));
    }
#line 8456 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 394:
#line 1624 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pcallexpr) = new CallExpr(PRIM_ERROR);
    }
#line 8464 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 395:
#line 1630 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = NULL; }
#line 8470 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 396:
#line 1631 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8476 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 397:
#line 1632 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8482 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 398:
#line 1637 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, (yyvsp[0].pexpr)); }
#line 8488 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 399:
#line 1639 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildFormalArrayType((yyvsp[-2].pcallexpr), (yyvsp[0].pexpr)); }
#line 8494 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 400:
#line 1645 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, (yyvsp[0].pexpr)); }
#line 8500 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 401:
#line 1647 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildFormalArrayType((yyvsp[-2].pcallexpr), (yyvsp[0].pexpr)); }
#line 8506 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 402:
#line 1649 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildFormalArrayType((yyvsp[-2].pexpr), (yyvsp[0].pexpr), (yyvsp[-4].pcallexpr)); }
#line 8512 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 403:
#line 1653 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = NULL; }
#line 8518 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 404:
#line 1654 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8524 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 405:
#line 1655 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8530 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 406:
#line 1656 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr((yyvsp[0].pch)); }
#line 8536 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 407:
#line 1657 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8542 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 408:
#line 1663 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[0].pexpr)); }
#line 8548 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 409:
#line 1664 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[0].pexpr)); }
#line 8554 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 410:
#line 1665 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 8560 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 411:
#line 1666 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 8566 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 412:
#line 1670 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[0].pexpr));}
#line 8572 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 413:
#line 1671 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 8578 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 414:
#line 1675 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("chpl__tuple_blank"); }
#line 8584 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 415:
#line 1676 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8590 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 416:
#line 1677 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8596 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 417:
#line 1681 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8602 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 418:
#line 1682 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 8608 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 419:
#line 1686 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST); }
#line 8614 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 421:
#line 1691 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[0].pexpr)); }
#line 8620 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 422:
#line 1692 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 8626 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 423:
#line 1696 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildNamedActual((yyvsp[-2].pch), (yyvsp[0].pexpr)); }
#line 8632 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 424:
#line 1697 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildNamedActual((yyvsp[-2].pch), (yyvsp[0].pexpr)); }
#line 8638 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 425:
#line 1698 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8644 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 426:
#line 1699 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8650 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 427:
#line 1703 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr((yyvsp[0].pch)); }
#line 8656 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 428:
#line 1704 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8662 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 429:
#line 1716 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8668 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 430:
#line 1718 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr( PRIM_TO_NILABLE_CLASS, (yyvsp[-1].pexpr)); }
#line 8674 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 436:
#line 1731 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr( "_singlevar", (yyvsp[0].pexpr)); }
#line 8680 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 437:
#line 1733 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildIndexType", (yyvsp[-1].pcallexpr)); }
#line 8686 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 438:
#line 1735 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildDomainRuntimeType", new UnresolvedSymExpr("defaultDist"), (yyvsp[-1].pcallexpr)); }
#line 8692 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 439:
#line 1737 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildSubDomainType", (yyvsp[-1].pcallexpr)); }
#line 8698 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 440:
#line 1739 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildSparseDomainRuntimeType", buildDotExpr((yyvsp[-1].pcallexpr)->copy(), "defaultSparseDist"), (yyvsp[-1].pcallexpr)); }
#line 8704 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 441:
#line 1741 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__atomicType", (yyvsp[0].pexpr)); }
#line 8710 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 442:
#line 1743 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr( "_syncvar", (yyvsp[0].pexpr)); }
#line 8716 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 443:
#line 1746 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("_owned"); }
#line 8722 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 444:
#line 1748 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr( "_owned", (yyvsp[0].pexpr)); }
#line 8728 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 445:
#line 1750 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtUnmanaged->symbol); }
#line 8734 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 446:
#line 1752 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr( PRIM_TO_UNMANAGED_CLASS, (yyvsp[0].pexpr)); }
#line 8740 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 447:
#line 1754 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("_shared"); }
#line 8746 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 448:
#line 1756 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr( "_shared", (yyvsp[0].pexpr)); }
#line 8752 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 449:
#line 1758 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtBorrowed->symbol); }
#line 8758 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 450:
#line 1760 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr( PRIM_TO_BORROWED_CLASS, (yyvsp[0].pexpr)); }
#line 8764 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 451:
#line 1763 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtAnyManagementNonNilable->symbol); }
#line 8770 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 452:
#line 1765 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtAnyRecord->symbol); }
#line 8776 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 453:
#line 1767 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtAnyEnumerated->symbol); }
#line 8782 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 454:
#line 1773 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8788 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 455:
#line 1775 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[-4].pexpr), (yyvsp[-2].pcallexpr), (yyvsp[0].pexpr), NULL, false, true); }
#line 8794 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 456:
#line 1777 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForLoopExpr(NULL, (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8800 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 457:
#line 1779 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[-7].pexpr), (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 8806 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 458:
#line 1781 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[-7].pexpr), (yyvsp[-5].pcallexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr), false, true); }
#line 8812 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 459:
#line 1783 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForLoopExpr(NULL, (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 8818 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 460:
#line 1785 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8824 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 461:
#line 1787 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[-4].pexpr), (yyvsp[-2].pcallexpr), (yyvsp[0].pexpr), NULL, false, true); }
#line 8830 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 462:
#line 1789 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForallLoopExpr(NULL, (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8836 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 463:
#line 1791 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[-7].pexpr), (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 8842 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 464:
#line 1793 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[-7].pexpr), (yyvsp[-5].pcallexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr), false, true); }
#line 8848 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 465:
#line 1795 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForallLoopExpr(NULL, (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 8854 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 466:
#line 1797 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-2].pcallexpr)->argList.length > 1)
        (yyval.pexpr) = buildForallLoopExpr(NULL, new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pexpr), NULL, true);
      else
        (yyval.pexpr) = buildForallLoopExpr(NULL, (yyvsp[-2].pcallexpr)->get(1)->remove(), (yyvsp[0].pexpr), NULL, true);
    }
#line 8865 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 467:
#line 1804 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[-4].pcallexpr)->get(1)->remove(), (yyvsp[-2].pexpr), (yyvsp[0].pexpr), NULL, true);
    }
#line 8875 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 468:
#line 1810 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pcallexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[-4].pcallexpr)->get(1)->remove(), (yyvsp[-2].pcallexpr), (yyvsp[0].pexpr), NULL, false, true);
    }
#line 8885 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 469:
#line 1816 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-7].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-5].pexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[-7].pcallexpr)->get(1)->remove(), (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr));
    }
#line 8895 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 470:
#line 1822 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-7].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-5].pcallexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[-7].pcallexpr)->get(1)->remove(), (yyvsp[-5].pcallexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr), false, true);
    }
#line 8905 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 471:
#line 1831 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new IfExpr((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8911 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 472:
#line 1840 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(gNil); }
#line 8917 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 480:
#line 1856 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("<~>", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8923 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 481:
#line 1860 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = NULL; }
#line 8929 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 483:
#line 1865 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = (yyvsp[-1].pcallexpr); }
#line 8935 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 484:
#line 1869 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST); addTaskIntent((yyval.pcallexpr), (yyvsp[0].pShadowVar)); }
#line 8941 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 485:
#line 1870 "chapel.ypp" /* yacc.c:1667  */
    { addTaskIntent((yyvsp[-2].pcallexpr), (yyvsp[0].pShadowVar)); }
#line 8947 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 486:
#line 1874 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = (yyvsp[-1].pcallexpr); }
#line 8953 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 487:
#line 1878 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST); addForallIntent((yyval.pcallexpr), (yyvsp[0].pShadowVar)); }
#line 8959 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 488:
#line 1879 "chapel.ypp" /* yacc.c:1667  */
    { addForallIntent((yyvsp[-2].pcallexpr), (yyvsp[0].pShadowVar)); }
#line 8965 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 489:
#line 1884 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pShadowVar) = ShadowVarSymbol::buildForPrefix((yyvsp[-3].pShadowVarPref), (yyvsp[-2].pexpr), (yyvsp[-1].pexpr), (yyvsp[0].pexpr));
    }
#line 8973 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 490:
#line 1888 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pShadowVar) = ShadowVarSymbol::buildFromReduceIntent((yyvsp[0].pexpr), (yyvsp[-2].pexpr));
    }
#line 8981 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 491:
#line 1892 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pShadowVar) = ShadowVarSymbol::buildFromReduceIntent((yyvsp[0].pexpr), (yyvsp[-2].pexpr));
    }
#line 8989 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 492:
#line 1898 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pShadowVarPref) = SVP_CONST;     }
#line 8995 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 493:
#line 1899 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pShadowVarPref) = SVP_IN;        }
#line 9001 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 494:
#line 1900 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pShadowVarPref) = SVP_CONST_IN;  }
#line 9007 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 495:
#line 1901 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pShadowVarPref) = SVP_REF;       }
#line 9013 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 496:
#line 1902 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pShadowVarPref) = SVP_CONST_REF; }
#line 9019 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 497:
#line 1903 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pShadowVarPref) = SVP_VAR;       }
#line 9025 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 499:
#line 1909 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("<~>", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9031 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 500:
#line 1914 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(PRIM_NEW, (yyvsp[0].pexpr)); }
#line 9037 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 501:
#line 1919 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildLetExpr((yyvsp[-2].pblockstmt), (yyvsp[0].pexpr)); }
#line 9043 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 510:
#line 1935 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(PRIM_TUPLE_EXPAND, (yyvsp[-1].pexpr)); }
#line 9049 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 511:
#line 1937 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = createCast((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9055 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 512:
#line 1939 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl_build_bounded_range", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9061 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 513:
#line 1941 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl_build_low_bounded_range", (yyvsp[-1].pexpr)); }
#line 9067 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 514:
#line 1943 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl_build_high_bounded_range", (yyvsp[0].pexpr)); }
#line 9073 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 515:
#line 1945 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl_build_unbounded_range"); }
#line 9079 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 516:
#line 1949 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = NULL; }
#line 9085 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 517:
#line 1950 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 9091 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 518:
#line 1953 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = tryExpr((yyvsp[0].pexpr)); }
#line 9097 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 519:
#line 1954 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = tryBangExpr((yyvsp[0].pexpr)); }
#line 9103 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 520:
#line 1955 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 9109 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 525:
#line 1972 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 9115 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 526:
#line 1973 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("postfix!", (yyvsp[-1].pexpr)); }
#line 9121 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 527:
#line 1974 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 9127 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 528:
#line 1978 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr((yyvsp[-3].pexpr), (yyvsp[-1].pcallexpr)); }
#line 9133 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 529:
#line 1979 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildSquareCallExpr((yyvsp[-3].pexpr), (yyvsp[-1].pcallexpr)); }
#line 9139 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 530:
#line 1980 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildPrimitiveExpr((yyvsp[-1].pcallexpr)); }
#line 9145 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 531:
#line 1984 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildDotExpr((yyvsp[-2].pexpr), (yyvsp[0].pch)); }
#line 9151 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 532:
#line 1985 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(PRIM_TYPEOF, (yyvsp[-2].pexpr)); }
#line 9157 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 533:
#line 1986 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildDotExpr((yyvsp[-2].pexpr), "_dom"); }
#line 9163 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 534:
#line 1987 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildDotExpr((yyvsp[-2].pexpr), "locale"); }
#line 9169 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 535:
#line 1988 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(buildDotExpr((yyvsp[-4].pexpr), "chpl_bytes")); }
#line 9175 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 536:
#line 1996 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[-1].pexpr); }
#line 9181 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 537:
#line 1997 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildOneTuple((yyvsp[-2].pexpr)); }
#line 9187 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 538:
#line 1998 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildTuple((yyvsp[-1].pcallexpr)); }
#line 9193 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 539:
#line 1999 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildTuple((yyvsp[-2].pcallexpr)); }
#line 9199 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 540:
#line 2003 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(gFalse); }
#line 9205 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 541:
#line 2004 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(gTrue); }
#line 9211 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 543:
#line 2009 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildIntLiteral((yyvsp[0].pch), yyfilename, chplLineno);    }
#line 9217 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 544:
#line 2010 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildRealLiteral((yyvsp[0].pch));   }
#line 9223 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 545:
#line 2011 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildImagLiteral((yyvsp[0].pch));   }
#line 9229 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 546:
#line 2012 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildStringLiteral((yyvsp[0].pch)); }
#line 9235 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 547:
#line 2013 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildCStringLiteral((yyvsp[0].pch)); }
#line 9241 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 548:
#line 2014 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(gNone); }
#line 9247 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 549:
#line 2015 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildDomainExpr", (yyvsp[-1].pcallexpr)); }
#line 9253 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 550:
#line 2016 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildDomainExpr", (yyvsp[-2].pcallexpr)); }
#line 9259 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 551:
#line 2017 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayExpr",  (yyvsp[-1].pcallexpr)); }
#line 9265 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 552:
#line 2018 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayExpr",  (yyvsp[-2].pcallexpr)); }
#line 9271 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 553:
#line 2020 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pexpr) = new CallExpr("chpl__buildAssociativeArrayExpr", (yyvsp[-1].pcallexpr));
    }
#line 9279 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 554:
#line 2024 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pexpr) = new CallExpr("chpl__buildAssociativeArrayExpr", (yyvsp[-2].pcallexpr));
    }
#line 9287 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 555:
#line 2031 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9293 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 556:
#line 2032 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-4].pcallexpr)->insertAtTail((yyvsp[-2].pexpr)); (yyvsp[-4].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 9299 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 557:
#line 2036 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("+", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9305 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 558:
#line 2037 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("-", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9311 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 559:
#line 2038 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("*", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9317 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 560:
#line 2039 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("/", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9323 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 561:
#line 2040 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("<<", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9329 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 562:
#line 2041 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(">>", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9335 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 563:
#line 2042 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("%", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9341 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 564:
#line 2043 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("==", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9347 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 565:
#line 2044 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("==", (yyvsp[-2].pexpr), gUninstantiated); }
#line 9353 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 566:
#line 2045 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("!=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9359 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 567:
#line 2046 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("!=", (yyvsp[-2].pexpr), gUninstantiated); }
#line 9365 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 568:
#line 2047 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("<=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9371 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 569:
#line 2048 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(">=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9377 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 570:
#line 2049 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("<", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9383 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 571:
#line 2050 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(">", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9389 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 572:
#line 2051 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("&", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9395 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 573:
#line 2052 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("|", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9401 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 574:
#line 2053 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("^", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9407 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 575:
#line 2054 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("&&", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9413 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 576:
#line 2055 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("||", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9419 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 577:
#line 2056 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("**", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9425 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 578:
#line 2057 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl_by", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9431 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 579:
#line 2058 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl_align", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9437 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 580:
#line 2059 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("#", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9443 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 581:
#line 2060 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__distributed", (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 9449 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 582:
#line 2064 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("+", (yyvsp[0].pexpr)); }
#line 9455 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 583:
#line 2065 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("-", (yyvsp[0].pexpr)); }
#line 9461 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 584:
#line 2066 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildPreDecIncWarning((yyvsp[0].pexpr), '-'); }
#line 9467 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 585:
#line 2067 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildPreDecIncWarning((yyvsp[0].pexpr), '+'); }
#line 9473 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 586:
#line 2068 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("!", (yyvsp[0].pexpr)); }
#line 9479 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 587:
#line 2069 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("postfix!", (yyvsp[-1].pexpr)); }
#line 9485 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 588:
#line 2070 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("~", (yyvsp[0].pexpr)); }
#line 9491 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 589:
#line 2074 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildReduceExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9497 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 590:
#line 2075 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildReduceExpr((yyvsp[-2].pexpr), (yyvsp[0].pcallexpr), true); }
#line 9503 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 591:
#line 2076 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildReduceExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9509 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 592:
#line 2077 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildReduceExpr((yyvsp[-2].pexpr), (yyvsp[0].pcallexpr), true); }
#line 9515 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 593:
#line 2081 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildScanExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9521 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 594:
#line 2082 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildScanExpr((yyvsp[-2].pexpr), (yyvsp[0].pcallexpr), true); }
#line 9527 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 595:
#line 2083 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildScanExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9533 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 596:
#line 2084 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildScanExpr((yyvsp[-2].pexpr), (yyvsp[0].pcallexpr), true); }
#line 9539 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 597:
#line 2089 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("SumReduceScanOp"); }
#line 9545 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 598:
#line 2090 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("ProductReduceScanOp"); }
#line 9551 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 599:
#line 2091 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("LogicalAndReduceScanOp"); }
#line 9557 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 600:
#line 2092 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("LogicalOrReduceScanOp"); }
#line 9563 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 601:
#line 2093 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("BitwiseAndReduceScanOp"); }
#line 9569 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 602:
#line 2094 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("BitwiseOrReduceScanOp"); }
#line 9575 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 603:
#line 2095 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("BitwiseXorReduceScanOp"); }
#line 9581 "bison-chapel.cpp" /* yacc.c:1667  */
    break;


#line 9585 "bison-chapel.cpp" /* yacc.c:1667  */
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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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


/*-----------------------------------------.
| yypushreturn -- ask for the next token.  |
`-----------------------------------------*/
yypushreturn:
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
