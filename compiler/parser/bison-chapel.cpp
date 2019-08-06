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
#define YYLAST   17688

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  169
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  140
/* YYNRULES -- Number of rules.  */
#define YYNRULES  598
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1056

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
       0,   486,   486,   491,   492,   498,   499,   504,   505,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   543,
     556,   561,   566,   574,   575,   576,   580,   581,   594,   595,
     596,   601,   602,   607,   612,   617,   621,   628,   633,   637,
     642,   646,   647,   648,   652,   653,   654,   658,   662,   664,
     666,   668,   670,   677,   678,   682,   683,   684,   685,   686,
     687,   690,   691,   692,   693,   694,   695,   707,   708,   719,
     720,   721,   722,   723,   724,   725,   726,   727,   728,   729,
     730,   731,   732,   733,   734,   735,   736,   737,   741,   742,
     743,   744,   745,   746,   747,   748,   749,   750,   751,   758,
     759,   764,   765,   770,   771,   775,   776,   780,   781,   785,
     786,   787,   788,   789,   790,   791,   792,   796,   797,   801,
     802,   803,   804,   808,   815,   816,   817,   818,   819,   820,
     821,   822,   823,   824,   825,   826,   827,   828,   829,   830,
     831,   832,   833,   839,   845,   851,   857,   864,   871,   875,
     882,   886,   887,   888,   889,   890,   892,   894,   896,   901,
     904,   905,   906,   907,   908,   909,   913,   914,   918,   919,
     920,   924,   925,   929,   932,   934,   939,   940,   944,   946,
     948,   955,   965,   975,   985,   998,  1003,  1008,  1016,  1017,
    1022,  1023,  1025,  1030,  1046,  1053,  1062,  1070,  1074,  1081,
    1082,  1087,  1092,  1086,  1119,  1125,  1132,  1138,  1144,  1155,
    1161,  1154,  1193,  1197,  1202,  1206,  1211,  1218,  1219,  1223,
    1224,  1225,  1226,  1227,  1228,  1229,  1230,  1231,  1232,  1233,
    1234,  1235,  1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,
    1244,  1245,  1246,  1247,  1248,  1249,  1250,  1254,  1255,  1256,
    1257,  1258,  1259,  1260,  1261,  1262,  1263,  1264,  1265,  1269,
    1270,  1274,  1278,  1279,  1280,  1284,  1286,  1288,  1290,  1292,
    1297,  1298,  1302,  1303,  1304,  1305,  1306,  1307,  1308,  1309,
    1310,  1314,  1315,  1316,  1317,  1318,  1319,  1323,  1324,  1328,
    1329,  1330,  1331,  1332,  1333,  1337,  1338,  1341,  1342,  1346,
    1347,  1351,  1353,  1358,  1359,  1363,  1364,  1372,  1373,  1375,
    1377,  1379,  1384,  1385,  1388,  1389,  1390,  1391,  1392,  1393,
    1394,  1397,  1398,  1401,  1403,  1405,  1410,  1423,  1440,  1441,
    1443,  1448,  1449,  1450,  1451,  1452,  1456,  1462,  1468,  1476,
    1477,  1485,  1487,  1492,  1494,  1496,  1501,  1503,  1505,  1512,
    1513,  1514,  1519,  1521,  1523,  1527,  1531,  1533,  1537,  1545,
    1546,  1547,  1548,  1549,  1554,  1555,  1556,  1557,  1558,  1578,
    1582,  1586,  1594,  1601,  1602,  1603,  1607,  1609,  1615,  1617,
    1619,  1624,  1625,  1626,  1627,  1628,  1634,  1635,  1636,  1637,
    1641,  1642,  1646,  1647,  1648,  1652,  1653,  1657,  1658,  1662,
    1663,  1667,  1668,  1669,  1670,  1674,  1675,  1686,  1688,  1696,
    1697,  1698,  1699,  1700,  1701,  1703,  1705,  1707,  1709,  1711,
    1713,  1716,  1718,  1720,  1722,  1724,  1726,  1728,  1730,  1735,
    1737,  1739,  1741,  1743,  1745,  1747,  1749,  1751,  1753,  1755,
    1757,  1759,  1766,  1772,  1778,  1784,  1793,  1803,  1811,  1812,
    1813,  1814,  1815,  1816,  1817,  1818,  1823,  1824,  1828,  1832,
    1833,  1837,  1841,  1842,  1846,  1850,  1854,  1861,  1862,  1863,
    1864,  1865,  1866,  1870,  1871,  1876,  1881,  1889,  1890,  1891,
    1892,  1893,  1894,  1895,  1896,  1897,  1899,  1901,  1903,  1905,
    1907,  1912,  1913,  1916,  1917,  1918,  1921,  1922,  1923,  1924,
    1935,  1936,  1937,  1941,  1942,  1943,  1947,  1948,  1949,  1950,
    1951,  1959,  1960,  1961,  1962,  1966,  1967,  1971,  1972,  1973,
    1974,  1975,  1976,  1977,  1978,  1979,  1980,  1981,  1982,  1986,
    1994,  1995,  1999,  2000,  2001,  2002,  2003,  2004,  2005,  2006,
    2007,  2008,  2009,  2010,  2011,  2012,  2013,  2014,  2015,  2016,
    2017,  2018,  2019,  2020,  2021,  2022,  2023,  2027,  2028,  2029,
    2030,  2031,  2032,  2033,  2037,  2038,  2039,  2040,  2044,  2045,
    2046,  2047,  2052,  2053,  2054,  2055,  2056,  2057,  2058
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
  "reserved_type_ident_use", "opt_string", "do_stmt", "return_stmt",
  "class_level_stmt", "private_decl", "forwarding_stmt",
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

#define YYPACT_NINF -927

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-927)))

#define YYTABLE_NINF -547

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -927,    49,  3019,  -927,   -53,  -927,  -927,  -927,  -927,  -927,
    -927,  4480,    -3,   120,  -927, 13300,  -927,  -927,    -3, 10465,
    -927,   342,    67,   120,  4480, 10465,  4480,    51,  -927, 10465,
    7063,  -927,  8521,  9169,  6901, 10465,  -927,    62,  -927,  -927,
   15174,  -927,  2129,  9331,  -927, 10465, 10465,  -927,  -927,  -927,
   10465,  -927, 13300,  -927, 10465,   223,    71,  1775,  2082,  -927,
    -927,  -927,  9493,  8035, 10465,  9331, 13300, 10465,   158,  -927,
     106,  4480,  -927, 10465,  -927, 10627, 10627, 15174,  -927,  -927,
   13300,  -927,  -927, 10465, 10465,  -927, 10465,  -927, 10465,  -927,
    -927, 12895, 10465,  -927, 10465,  -927,  -927,  3508,  7225,  8683,
    -927,  4318,  -927,   202,  -927,   215,  -927,   241,  -927,  -927,
    -927,  -927,  -927,  -927,  -927,  -927,  -927,  -927,  -927,  -927,
    -927,  -927,  -927,  -927,  -927, 15174,  -927, 15174,   362,    64,
    -927,  -927,  2129,  -927,   217,  -927,   229,  -927,  -927,   244,
     261,   291,   294,   299, 17274, 12890,   265,   309,   312,  -927,
    -927,  -927,  -927,  -927,  -927,  -927,   290,  -927,  -927, 17274,
     222,  4480,  -927,  -927,   334, 10465, 10465, 10465, 10465, 10465,
    9493,  9493,   363,  -927,  -927,  -927,  -927,   361,   366,  -927,
    -927,   344, 15247, 15174,  2129,  -927,   352,  -927,   142, 17274,
     402,  8197, 17274,  -927,   129,  -927, 15174,   201,   271, 15174,
     369,    52, 14781,    18, 14749,   271, 10465,  -927, 15190, 13997,
    8197,  -927,  -927,  -927,  -927,  -927,  -927,  -927,  -927,  -927,
    -927,  -927,  -927,  -927,  -927,  -927,  -927,  -927,  -927,  -927,
    -927,  -927,  -927,  -927,  -927,  4480,  -927,   379,  1677,   119,
      25,  -927,  4480,  -927,  -927, 14925,   704,   361, 14925,   361,
     704,  -927,  8197, 10465,  -927,  -927, 15174,  -927,   232, 17274,
   10465, 10465,  -927, 17274,   359, 15158,  -927, 14925,   361, 17274,
     383,  8197,  -927, 17274, 15334,  -927,  -927, 15599, 13165,  -927,
    -927, 15648,   417,   393,   361, 14925, 15743,   153,   153,   970,
     704,   704,   311,  -927,  -927,  3670,   -20,  -927, 10465,  -927,
      89,   122,  -927,   -72,    75, 15792,   -60,   547,  -927,  3832,
    -927,   499,  9493,   422,   398,  -927,  -927,  -927,   238,  -927,
    -927, 10465, 10465, 10465, 10465,  9169,  9169, 10465,   382, 10465,
   10465, 10465, 10465, 10465,   485, 12895,  9655, 10465, 10465, 10465,
   10465, 10465, 10465, 10465, 10465,  9817, 10465, 10465, 10465, 10465,
   10465,  -927,  -927,  -927,  -927,  -927,  -927,  8845,  8845,  -927,
    -927,  -927,  -927,  8845,  -927,  -927,  8845,  8845,  8197,  8197,
    9169,  9169,  7711,  -927,  -927, 15391, 15423, 15824,    35,  3994,
    -927,  9169,    52,   405,   243,  -927, 10465,  -927, 10465,   447,
    -927,   401,   427,  -927,  -927,   410, 15174,  2129,   524,  9493,
    -927,  4642,  9169,  -927,   406,  -927,    52,  4804,  9169,  -927,
      52,   271, 10789, 10465,  -927,  4480,   537, 10465,   407,  -927,
      99,  -927,  -927,  1677,  -927,   440,   414,  -927, 10951,   465,
   10465,  2129,  -927,  -927,  -927,   418,  -927,  9493,  -927, 17274,
   17274,  -927,    41,  -927,  8197,   419,  -927,   564,  -927,   564,
    -927, 11113,   450,  -927,  -927,  -927,  -927,  -927,  -927,  9007,
    -927, 13853,  7387,  -927,  7549,  -927,  4480,   423,  9169,  6262,
    3346,   424, 10465,  6588,  -927,  -927,   368,  -927,  4156, 15174,
     281, 15567,  9493,   430, 17582,   340,  -927, 15968, 17391, 17391,
     296,  -927,   296,  -927,   296,  1858,  1472,  1104,  1263,   361,
     153,   425,  -927,  -927,  -927,  -927,   970,  -927,  1945,   296,
     651,   651, 17391,   651,   651,   791,   153,  -927,  1945, 17431,
     791,   704,   704,   153,   436,   438,   439,   443,   444,   437,
     442,  -927,   296,  -927,   296,   185,  -927,  -927,  -927,   123,
    -927,  1178, 17350,   349, 11275,  9169, 11437,  9169, 10465,  9169,
   13560,    -3, 16013,  -927,  -927,  -927, 17274, 16054,  8197,  -927,
    8197,  -927,   422,   308, 10465,   130, 10465, 17274,    60, 14982,
    7711,  -927, 10465, 17274,    29, 14838,  -927,   453,   466,   456,
   16165,   466,   457,   578, 16205,  4480, 15014,  -927,   195,  -927,
    -927,  -927,  -927,  -927,  -927,   778,   136,  -927,  2760,  -927,
     341,   458,  1677,   119,    51,    62, 10465, 10465,  6100,  -927,
    -927,   532,  8359,  -927, 17274,  -927,  -927,  -927, 17274,   452,
     116,   459,  -927,  1471,  -927,  -927,   346, 15174,  -927,  -927,
    -927,  -927,  -927,  -927,  -927,  4480,   -64,  2554,  -927,  -927,
   17274,  4480, 17274,  -927, 16246,  -927,  -927,  -927,  -927, 10789,
   10465,   487,  1089,   463,   511,   145,  -927,   548,  -927,  -927,
    -927,  -927,  6741,   464,  -927,  -927,  -927,  -927,  -927,  -927,
    -927,  -927,  -927,  7711,  -927,    28,  9169,  9169, 10465,   602,
   16390, 10465,   603, 16422,   471,  2844,    52,    52,  -927,  -927,
    -927,  -927,   481,  -927, 14925,  -927, 14073,  4966,  -927,  5128,
    -927,   137,  -927, 14149,  5290,  -927,    52,  5452,  -927,    52,
   10465,  -927, 10465,  -927,  4480, 10465,  -927,  4480,   614,  -927,
    -927, 15174,  1152,  -927,  1677,   513,   569,  -927,  -927,  -927,
      69,  -927,  -927,   465,   486,    74,  -927,  -927,  -927,  5614,
    9493,  -927,  -927,  -927, 15174,  -927,   515,   344,  -927,  -927,
    5776,   488,  5938,   489,  -927, 10465,   497,   505,   502,  1436,
    -927, 10465, 15174,  -927,  -927,   341,   509,   -35,  -927,   534,
    -927,   535,   536,   545,   539,   540,  -927,   541,   551,   544,
     546,   553,   248,   555,   567,   568,  -927,  -927, 15174,  -927,
    -927,  -927,  -927,  -927,  -927,  -927,  -927,  -927,  -927,  -927,
    -927,  -927,  -927,  -927,  -927,  -927,  -927,  -927, 10465,  -927,
     572,   577,   570,   509,   509,  -927,  -927,  -927,   465,   146,
     187, 16566, 11599, 11761, 16598, 11923, 12085, 12247, 12409,  -927,
    -927,  1304,  -927,  4480, 10465, 17274, 10465, 17274,  7711,  -927,
    4480, 10465, 17274,  -927, 10465, 17274,  -927, 16655, 17274,  -927,
   17274,   677,  4480,   513,  -927,   520,  9979,    10,  -927,    38,
    -927,  -927,  9169, 13430,  4480,  -927,    36,   549, 10465,  -927,
   10465,  -927, 17274,  4480, 10465,  -927, 17274,  4480, 17274,  -927,
    -927,  -927,  7873,  1554,  1554,  -927,  2438,  -927, 17274,  -927,
      32,    99,  -927,  -927, 13894,  -927, 13652,  -927,  -927,  -927,
   10465, 10465, 10465, 10465, 10465, 10465, 10465, 10465,   550,  2300,
   16205, 14225, 14301,  -927, 16205, 14377, 14453, 10465,  4480,  -927,
     465,   513,  6425,  -927,  -927,  -927,   131,  9493,  -927,  -927,
      93, 10465,   -45, 13708,  -927,   582,   402,  -927,   344, 17274,
   14529,  -927, 14605,  -927,  -927,  -927, 12571,   615,   208,  -927,
     584,   586,   509,   509, 16742, 16818, 16894, 16970, 17046, 17122,
    -927,  -927,  4480,  4480,  4480,  4480, 17274,  -927,  -927,    10,
   10141,    78,  -927,  -927, 17274,  -927,    76,  -927,   -37,  -927,
     337, 17198,  -927,  -927,  -927, 12409,  -927,  4480,  4480,  3181,
    -927,  -927,   194,  -927,    38,  -927,  -927,  -927, 10465, 10465,
   10465, 10465, 10465, 10465, 16205, 16205, 16205, 16205,  -927,  -927,
    -927,  -927,  -927,   249,  9169, 13027,  -927, 10465,    93,    76,
      76,    76,    76,    76,    76,    93,   720, 16205, 16205,   552,
   12733,    86,   188, 13796,  -927,  -927, 17274,  -927,  -927,  -927,
    -927,  -927,  -927,  -927,   585,  -927,  -927,   300, 13170,  -927,
    -927,  -927, 10303,  -927,   310,  -927
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       3,     0,     0,     1,     0,    87,   538,   539,   540,   541,
     542,     0,   476,    73,   108,   447,   114,   205,   476,     0,
     113,     0,   352,    73,     0,     0,     0,     0,   215,   511,
     511,   535,     0,     0,     0,     0,   112,     0,   225,   109,
       0,   221,     0,     0,   116,     0,     0,   467,   543,   117,
       0,   228,   441,   351,     0,     0,     0,    45,    44,   111,
     206,   353,     0,     0,     0,     0,   445,     0,     0,   115,
       0,     0,    88,     0,   536,     0,     0,     0,   110,   207,
     443,   355,   118,     0,     0,   594,     0,   596,     0,   597,
     598,   510,     0,   595,   592,   129,   593,     0,     0,     0,
       4,     0,     5,     0,     9,    46,    10,     0,    11,    12,
      14,   425,   426,    22,    13,   130,   136,    15,    17,    16,
      19,    20,    21,    18,   135,     0,   133,     0,   502,     0,
     137,   134,     0,   138,   516,   498,   427,   499,   431,   429,
       0,     0,   503,   504,     0,   430,     0,   517,   518,   519,
     537,   497,   433,   432,   500,   501,     0,    38,    24,   439,
       0,     0,   477,    74,     0,     0,     0,     0,     0,     0,
       0,     0,   502,   516,   429,   503,   504,   448,   430,   517,
     518,     0,   476,     0,     0,   354,     0,   179,     0,   410,
       0,   417,   512,   226,   541,   143,     0,     0,   227,     0,
       0,     0,     0,     0,     0,     0,   511,   142,     0,     0,
     417,    81,    89,   101,    95,    94,   103,    84,    93,   104,
      90,   105,    82,   106,    99,    92,   100,    98,    96,    97,
      83,    85,    91,   102,   107,     0,    86,     0,     0,     0,
       0,   359,     0,   126,    32,     0,   579,   495,     0,   442,
     580,     7,   417,   511,   132,   131,   322,   407,     0,   406,
       0,     0,   127,   515,     0,     0,    35,     0,   446,   434,
       0,   417,    36,   440,     0,   186,   182,     0,   430,   186,
     183,     0,   348,     0,   444,     0,     0,   581,   583,   509,
     578,   577,     0,    48,    51,     0,     0,   412,     0,   414,
       0,     0,   413,     0,     0,   406,     0,     0,     6,     0,
      47,     0,     0,   208,     0,   308,   307,   229,     0,   428,
      23,     0,     0,     0,     0,     0,     0,     0,   582,     0,
       0,     0,     0,     0,     0,   508,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   267,   274,   275,   276,   271,   273,     0,     0,   269,
     272,   270,   268,     0,   278,   277,     0,     0,   417,   417,
       0,     0,     0,    25,    26,     0,     0,     0,     0,     0,
      27,     0,     0,     0,     0,    28,     0,    29,     0,   425,
     423,     0,   418,   419,   424,     0,     0,     0,     0,     0,
     152,     0,     0,   151,     0,   160,     0,     0,     0,   158,
       0,     0,     0,    57,   139,     0,   172,     0,     0,    30,
     290,   222,   363,     0,   364,   366,     0,   388,     0,   369,
       0,     0,   125,    31,    33,     0,   321,     0,    67,   513,
     514,   128,     0,    34,   417,     0,   193,   184,   180,   185,
     181,     0,   346,   343,   145,    37,    50,    49,    52,     0,
     544,     0,     0,   531,     0,   533,     0,     0,     0,     0,
       0,     0,     0,     0,   548,     8,     0,    40,     0,     0,
       0,   406,     0,     0,     0,   301,   358,   475,   574,   573,
     576,   585,   584,   589,   588,   570,   567,   568,   569,   506,
     555,     0,   528,   529,   527,   526,   507,   560,   559,   572,
     566,   564,   575,   565,   563,   553,   558,   562,   561,   571,
     552,   556,   557,   554,     0,     0,     0,     0,     0,     0,
       0,   587,   586,   591,   590,   487,   488,   490,   492,     0,
     479,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     546,   476,   476,   148,   344,   356,   411,     0,     0,   436,
       0,   345,   208,     0,     0,     0,     0,   451,     0,     0,
       0,   161,     0,   457,     0,     0,   159,   593,    60,     0,
      53,    58,     0,   171,     0,     0,     0,   435,   295,   292,
     293,   294,   298,   299,   300,   290,     0,   283,     0,   291,
     309,     0,   367,     0,   121,   122,   120,   119,     0,   387,
     386,   498,     0,   361,   496,   360,   525,   409,   408,     0,
       0,     0,   437,     0,   187,   350,   498,     0,   545,   505,
     532,   415,   534,   416,   168,     0,     0,     0,   547,   166,
     461,     0,   550,   549,     0,    42,    41,    39,    64,     0,
      57,   209,     0,     0,   219,     0,   216,   305,   302,   303,
     306,   230,     0,     0,    71,    72,    70,    69,    68,   523,
     524,   489,   491,     0,   478,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   144,   421,
     422,   420,     0,   357,     0,   170,     0,     0,   150,     0,
     149,     0,   482,     0,     0,   156,     0,     0,   154,     0,
       0,   140,     0,   141,     0,     0,   174,     0,   176,   296,
     297,     0,   290,   281,     0,   401,   310,   313,   312,   314,
       0,   365,   368,   369,     0,     0,   370,   371,   195,     0,
       0,   194,   197,   438,     0,   188,   191,     0,   347,   169,
       0,     0,     0,     0,   167,     0,     0,     0,     0,   224,
     214,     0,   217,   213,   304,   309,   279,    75,   262,    89,
     260,    95,    94,    78,    93,    90,   265,   105,    76,   106,
      92,    96,    77,    79,    91,   107,   259,   241,   244,   242,
     243,   254,   245,   258,   250,   248,   261,   264,   249,   247,
     252,   257,   246,   251,   255,   256,   253,   263,     0,   239,
       0,    80,     0,   279,   279,   237,   530,   480,   369,   516,
     516,     0,     0,     0,     0,     0,     0,     0,     0,   147,
     146,     0,   153,     0,     0,   450,     0,   449,     0,   481,
       0,     0,   456,   157,     0,   455,   155,    55,    54,   173,
     466,   175,     0,   401,   284,     0,     0,   369,   311,   327,
     362,   392,     0,   546,     0,   199,     0,     0,     0,   189,
       0,   164,   463,     0,     0,   162,   462,     0,   551,    65,
      66,   203,   511,   224,   224,   201,   224,   211,   220,   218,
       0,   290,   236,   240,     0,   266,     0,   232,   233,   484,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   224,
     454,     0,     0,   483,   460,     0,     0,     0,     0,   178,
     369,   401,     0,   404,   403,   405,   498,   323,   287,   285,
       0,     0,     0,     0,   390,   498,   200,   198,     0,   192,
       0,   165,     0,   163,   212,   383,     0,   315,     0,   238,
      75,    77,   279,   279,     0,     0,     0,     0,     0,     0,
     204,   202,     0,     0,     0,     0,    56,   177,   286,   369,
     393,     0,   324,   326,   325,   341,     0,   342,   329,   332,
       0,   328,   319,   320,   223,     0,   190,     0,     0,     0,
     382,   381,   498,   316,   327,   280,   234,   235,     0,     0,
       0,     0,     0,     0,   453,   452,   459,   458,   289,   288,
     395,   396,   398,   498,     0,   546,   340,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   498,   465,   464,     0,
     373,     0,     0,     0,   397,   399,   331,   333,   334,   337,
     338,   339,   335,   336,   330,   378,   376,   498,   546,   317,
     231,   318,   393,   377,   498,   400
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -927,  -927,  -927,     9,  -417,  2019,  -927,  -927,  -927,  -927,
     370,   411,  -393,    73,    77,  -927,  -927,  -927,   400,   701,
    -927,     7,  -160,  -635,  -927,  -719,  -927,   455,  -896,  -733,
     -52,  -927,  -927,  -927,    98,  -927,  -927,  -927,   446,  -927,
     -17,  -927,  -927,  -927,  -927,  -927,   557,   170,   -95,  -927,
    -927,  -927,   -24,   957,  -927,  -927,  -927,  -927,  -927,  -927,
    -927,  -927,  -153,  -143,  -769,  -927,  -145,    26,   152,  -927,
    -927,  -927,   -16,  -927,  -927,  -277,    46,  -927,  -213,  -237,
    -267,  -259,  -526,  -927,  -171,  -927,    -4,   726,  -117,   330,
    -927,  -383,  -705,  -804,  -927,  -542,  -438,  -926,  -907,  -823,
      -5,  -927,    88,  -927,  -152,  -927,   204,   618,  -354,  -927,
    -927,  -927,  1146,  -927,    -9,  -927,  -927,  -194,  -927,  -569,
    -927,  -927,  1561,  1658,   -11,   -13,   155,   984,  -927,  1880,
    2042,  -927,  -927,  -927,  -927,  -927,  -927,  -927,  -927,  -365
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,   294,   101,   583,   103,   104,   105,   311,
     106,   295,   578,   582,   579,   107,   108,   109,   110,   164,
     809,   239,   111,   236,   112,   609,   197,   244,   113,   114,
     115,   116,   117,   118,   684,   119,   120,   121,   447,   624,
     747,   122,   123,   620,   742,   124,   125,   483,   759,   126,
     127,   655,   656,   172,   237,   600,   129,   130,   485,   765,
     661,   812,   813,   417,   892,   421,   596,   597,   598,   599,
     662,   317,   730,   994,  1050,   984,   257,   973,   928,   932,
     978,   979,   980,   131,   283,   452,   132,   133,   240,   241,
     425,   426,   613,   991,   947,   429,   610,  1011,   925,   857,
     296,   188,   300,   301,   391,   392,   393,   173,   135,   136,
     137,   138,   174,   140,   161,   162,   539,   406,   701,   540,
     541,   141,   175,   176,   144,   198,   394,   178,   146,   179,
     180,   149,   150,   151,   306,   152,   153,   154,   155,   156
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     159,   702,   367,   595,   177,   254,   255,   543,   182,   181,
     410,   100,   383,   625,   189,   318,   193,   184,   192,   192,
     581,   202,   204,   208,   209,   395,   887,   811,   860,   427,
     920,   389,   245,   945,   246,   247,   983,    63,   404,   248,
     601,   249,   619,   250,   897,   898,   404,   235,   242,     3,
     389,   259,   263,   265,   267,   268,   269,   258,   418,   704,
     273,   733,   274,  1012,   277,   281,   242,   384,   430,   284,
     427,  1017,   285,   286,   611,   287,   473,   288,   549,   975,
     289,   290,   242,   291,   282,  -379,   259,   263,   305,  1034,
     697,   930,   389,   466,   304,   -81,   975,   626,   969,  1018,
     435,   750,   157,   -87,   817,   474,  -196,   160,  1035,   467,
     471,   389,   315,   899,  -379,   379,   459,   862,   468,   445,
     427,  1014,  -384,   163,   588,   612,  1055,  -379,   404,   549,
     201,   203,   313,   818,   314,   367,   983,   923,   316,   404,
    -379,   460,   589,  -384,   299,   590,   931,   185,  -196,  -124,
     927,  -384,   929,   944,   159,   375,   376,   377,   273,   259,
     305,   431,  -384,   428,  -384,   591,   378,   946,   592,   977,
      55,   469,   437,   382,   505,   976,   887,  -384,   379,   593,
     263,   739,   324,   996,   997,   404,   977,  -379,   859,   379,
     282,  -384,  -379,   411,   397,   192,   379,   303,   594,   263,
     550,   184,  -196,   282,   428,   543,   398,  -124,   389,   389,
     469,   469,   379,   191,   469,   968,   529,   530,   264,   732,
     379,    17,   469,   740,   210,   462,  1046,   990,   671,  -384,
     251,  -124,   325,   252,  -384,  -282,   326,   390,   719,   863,
     470,   263,   192,  1015,  1053,   424,  -402,  -380,   270,   439,
     440,  1048,   463,   302,   428,  -384,   390,   581,   464,   673,
     263,   811,  -282,   436,  1009,   672,   437,  -402,   271,   913,
      63,  -402,   722,   838,  -384,   720,  -380,   741,   386,    60,
     563,   762,  -486,   328,   389,   465,   674,   461,   332,  -380,
     310,   334,   621,   695,  -402,   337,    22,   387,   390,   723,
     839,   481,  -380,    79,   458,   595,   763,   480,   543,  -486,
     487,   488,   489,   490,   492,   494,   495,   390,   496,   497,
     498,   499,   500,  -485,   506,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   518,   519,   520,   521,   522,   523,
      53,   855,   886,  1049,   722,   312,   263,   263,   379,  -380,
    -485,    61,   263,  -372,  -380,   263,   263,   263,   263,   532,
     534,   542,   309,  -374,  -394,   657,   726,    22,   437,   370,
     552,   995,  -469,   371,   431,   556,    81,   557,   -83,   431,
     706,   709,  -372,   319,   372,  -394,   -88,   438,   259,  -394,
     567,   569,  -374,   486,   565,  -372,   573,   575,   555,  -468,
     389,   580,   580,   562,   584,  -374,   586,   397,  -372,   658,
     727,    53,  -394,   243,   390,   390,   320,   437,  -374,   614,
     659,   728,    61,   491,   493,   934,   618,   368,   677,   369,
     424,   332,   371,   263,   334,   243,   648,   321,   337,   660,
     729,   183,   751,   753,   431,   275,   279,    81,   618,  -473,
    1016,   263,  1019,   263,  -474,  -372,   748,   637,   618,   640,
    -372,   642,   644,   693,  -471,  -374,   157,  -470,   531,   533,
    -374,   259,   456,   543,   595,   276,   280,   651,  1020,   551,
    1021,  1022,  -349,   617,  1023,  1024,   647,   458,     5,   374,
     390,   654,   886,  1038,  1039,  1040,  1041,  1042,  1043,   334,
     568,  -349,   926,   501,   379,   617,   574,   385,   299,   935,
     299,   388,   524,   525,   441,   617,   502,  -472,   526,   814,
     266,   527,   528,   157,  -522,  -522,  -522,  -522,  -520,   645,
    -520,   399,   451,   567,   680,   573,   683,   584,   685,   640,
     503,   420,   686,   687,  -521,   444,  -521,   263,   453,   263,
     631,   380,   633,   694,   475,   696,   479,   482,   484,   542,
     554,   703,   558,   560,   559,   561,   636,   564,   570,   585,
     587,   243,   243,   243,   243,  -385,   602,   603,    72,   416,
     612,   616,   622,   623,   504,  -385,   627,   663,   635,   641,
     652,   664,   992,   665,   666,   269,   273,   305,   667,   668,
     669,   263,   710,   735,   689,   725,   390,   670,   -59,   424,
     714,   711,   713,   738,  -385,   243,  1013,   302,   243,   302,
     134,   731,   743,   437,   760,  -389,   761,   816,   764,   134,
     746,  1026,   822,   825,   282,  -389,   827,   243,   580,   580,
    -385,   831,   134,   679,   134,   682,   852,  -385,   856,   858,
     868,   861,   879,   873,   877,   243,   400,   403,   405,   409,
     880,  1013,   542,   881,  -389,   492,   532,   821,  -385,   810,
     824,   891,  -108,  -114,  -113,   -84,  1047,  -112,  -109,  -116,
     324,   -82,  -117,   921,  -111,   -85,   835,  -385,   837,   134,
    -389,  -115,  -385,   842,  1054,  -385,   845,  -389,  1013,   847,
     433,   848,   895,   434,   850,  -110,  -118,   -86,   896,   918,
     993,   960,   938,   690,   -81,   134,   -83,  1045,  -389,   134,
     478,  1018,   443,   757,   186,   449,   756,   867,   853,   259,
     325,   424,   692,   324,   326,   866,   909,  -389,   889,   872,
     454,   876,  -389,   952,   878,  -389,   948,   721,   854,   890,
     888,   746,   243,   953,   396,  1051,  1008,  1032,  1044,  1037,
     207,   615,     0,  -391,   691,     0,     0,   737,     0,   654,
       0,     0,     0,  -391,   491,   531,   243,     0,     0,   134,
     243,   328,   329,   325,   330,   331,   332,   326,   333,   334,
     335,     0,     0,   337,     0,   893,     0,   894,     0,     0,
     343,   344,  -391,   588,   347,     0,     0,   348,   349,   350,
       0,   835,   837,     0,   842,   845,   872,   876,     0,     0,
     324,   589,   910,   911,   590,   912,     0,   542,  -391,   914,
     915,   254,   255,   916,   328,  -391,     0,   553,     0,   332,
       0,   333,   334,     0,   591,     0,   337,   592,     0,   307,
       0,   933,   640,   134,   344,     0,  -391,   939,   593,   940,
     134,   571,   350,   942,     0,   576,     0,     0,     0,     0,
     325,   192,     0,     0,   326,  -391,     0,   594,     0,     0,
    -391,     0,     0,  -391,     0,     0,     0,     0,     0,   910,
     954,   955,   914,   956,   957,   958,   959,     0,     0,     0,
       0,     0,   924,   810,     0,     0,   966,     0,     0,     0,
       0,   305,     0,   134,     0,     0,   974,   971,     0,     0,
     981,   328,   329,     0,   330,   331,   332,   134,   333,   334,
       0,     0,     0,   337,     0,     0,     0,     0,   243,   243,
       0,   344,     0,     0,   243,   243,     0,   348,   349,   350,
       0,  1004,  1005,  1006,  1007,     0,   718,     0,     0,   128,
       0,     0,     0,     0,     0,     0,     0,     0,   128,     0,
       0,     0,     0,   972,   876,     0,  1027,  1028,   305,     0,
       0,   128,     0,   128,  1031,     0,   145,  1004,  1005,  1006,
    1007,  1027,  1028,   745,     0,   145,     0,   134,     0,   324,
       0,     0,     0,  1033,   640,     0,  1036,     0,   145,     0,
     145,     0,     0,     0,     0,     0,  1010,     0,     0,   134,
       0,     0,     0,   698,   700,   134,     0,     0,   128,   705,
     708,     0,     0,   134,     0,     0,     0,   640,     0,     0,
       0,   876,     0,     0,     0,     0,     0,     0,     0,   325,
       0,     0,     0,   326,   128,   145,   243,   243,   128,   278,
     278,  1010,     0,     0,   243,     0,   416,     0,     0,     0,
       0,     0,     0,   416,     0,     0,   243,     0,     0,   243,
       0,   145,     0,     0,   134,   145,     0,     0,   134,     0,
     758,     0,     0,     0,     0,     0,   134,     0,  1010,     0,
     328,   329,     0,   330,   331,   332,     0,   333,   334,  -210,
       0,     0,   337,  -210,  -210,     0,     0,   869,   128,   343,
     344,     0,  -210,   347,  -210,  -210,   348,   349,   350,  -210,
       0,     0,     0,   324,  -210,     0,     0,  -210,     0,     0,
       0,   829,   830,     0,     0,   145,     0,     0,   139,   832,
       0,     0,     0,     0,     0,     0,  -210,   139,  -210,   675,
    -210,   843,  -210,  -210,   846,  -210,     0,  -210,     0,  -210,
     139,     0,   139,     0,     0,     0,     0,   588,     0,     0,
       0,     5,     0,   325,     0,     0,     0,   326,  -210,     0,
       0,  -210,   128,    14,  -210,   589,    16,     0,   590,   128,
       0,    20,     0,   134,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   139,   591,   145,
      36,   592,     0,    55,     0,    39,   145,     0,     0,     0,
       0,     0,   593,    44,   328,   329,   243,     0,   331,   332,
      49,   333,   334,   139,  -210,     0,   337,   139,     0,     0,
    -210,   594,   128,   134,   344,    59,     0,     0,     0,   134,
     348,   349,   350,     0,     0,     0,   128,    69,     0,     0,
       0,    72,     0,     0,     0,     0,     0,     0,    78,   145,
     815,   416,   416,     0,    82,   416,   416,     0,     0,     0,
       0,     0,   324,   145,   819,   820,     0,     0,     0,     0,
       0,     0,   982,     0,     0,   908,     0,   139,   986,     0,
     416,     0,   416,     0,     0,   134,     0,   134,     0,     0,
       0,   937,   134,     0,  -210,   134,     0,     0,  -210,  -210,
       0,     0,   134,     0,     0,   134,   128,  -210,     0,  -210,
    -210,     0,   325,     0,  -210,     0,   326,     0,     0,  -210,
       0,     0,  -210,     0,     0,     0,     0,   134,   128,     0,
       0,     0,     0,   145,   128,     0,     0,     0,   134,     0,
     134,  -210,   128,  -210,     0,  -210,     0,  -210,  -210,     0,
    -210,   139,  -210,     0,  -210,   145,     0,     0,   139,     0,
       0,   145,     0,   328,   329,     0,     0,     0,   332,   145,
     333,   334,   982,  -210,     0,   337,  -210,     0,     0,  -210,
       0,     0,     0,   344,     0,     0,     0,     0,     0,   348,
     349,   350,     0,   128,     0,     0,     0,   128,     0,     0,
       0,     0,     0,     0,     0,   128,     0,     0,     0,     0,
       0,   139,     0,     0,     0,     0,     0,     0,     0,     0,
     145,   134,     0,     0,   145,   139,    17,     0,   134,  -210,
      21,    22,   145,     0,     0,  -210,     0,     0,     0,    28,
     134,    29,   882,     0,   211,     0,    34,     0,     0,     0,
       0,    38,   134,     0,     0,     0,   212,   213,     0,   214,
       0,   134,     0,     0,   215,   134,     0,     0,     0,     0,
       0,   324,   216,    51,     0,    53,     0,    55,   217,   883,
       0,     0,   884,   218,    60,   219,    61,     0,   220,     0,
       0,     0,     0,     0,     0,   139,   221,     0,     0,     0,
       0,     0,   222,   223,     0,    77,   134,     0,    79,   224,
       0,    81,   128,     0,     0,     0,     0,   139,   225,     0,
       0,   325,     0,   139,     0,   326,     0,   226,   227,     0,
     228,   139,   229,   142,   230,     0,     0,   231,     0,   145,
       0,   232,   142,     0,   233,     0,     0,   234,   205,    22,
     134,   134,   134,   134,     0,   142,     0,   142,     0,    29,
     253,    95,   128,     0,     0,     0,     0,   885,   128,    38,
       0,     0,   328,     0,     0,   134,   134,   332,     0,   333,
     334,     0,   139,     0,   337,     0,   139,     0,     0,   145,
       0,    51,   344,    53,   139,   145,     0,     0,   348,   349,
     350,   379,   142,   744,    61,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   128,     0,   128,     0,   142,    81,
     143,   128,   142,     0,   128,     0,     0,     0,     0,   143,
       0,   128,     0,     0,   128,     0,     0,     0,     0,     0,
     211,   145,   143,   145,   143,     0,     0,     0,   145,     0,
       0,   145,   212,   213,     0,   214,   128,     0,   145,     0,
     215,   145,     0,     0,     0,     0,     0,   128,   216,   128,
       0,     0,     0,     0,   217,     0,     0,     0,     0,   218,
       0,   219,   142,   145,   220,     0,     0,     0,     0,   143,
       0,   139,   221,     0,   145,     0,   145,     0,   222,   223,
       0,     0,     0,     0,     0,   224,     0,     0,     0,     0,
       0,     0,     0,     0,   225,   143,     0,     0,     0,   143,
       0,     0,     0,   226,   227,     0,   228,     0,   229,     0,
     230,     0,     0,   231,     0,     0,     0,   232,   422,     0,
     233,   139,     0,   234,     0,     0,     0,   139,     0,     0,
     128,     0,     0,     0,     0,     0,   142,   128,     0,   205,
      22,     0,     0,   142,     0,     0,     0,     0,     0,   128,
      29,   253,     0,     0,     0,     0,     0,   145,     0,   143,
      38,   128,     0,  -224,   145,     0,     0,     0,     0,     0,
     128,     0,     0,     0,   128,     0,   145,     0,     0,   423,
       0,     0,    51,   139,    53,   139,     0,     0,   145,  -224,
     139,     0,     0,   139,     0,    61,   142,   145,     0,     0,
     139,   145,     0,   139,     0,     0,     0,     0,     0,     0,
     142,     0,     0,     0,     0,   128,     0,     0,     0,   -63,
      81,     0,   147,     0,     0,   139,     0,   324,     0,     0,
       0,   147,     0,   143,     0,     0,   139,     0,   139,     0,
     143,     0,   145,     0,   147,     0,   147,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   128,
     128,   128,   128,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   325,     0,     0,
     142,   326,     0,     0,   128,   128,   145,   145,   145,   145,
       0,   147,     0,   143,     0,     0,     0,     0,     0,     0,
       0,     0,   142,     0,     0,     0,     0,   143,   142,     0,
       0,   145,   145,     0,   324,     0,   142,   147,     0,   139,
       0,   147,     0,     0,     0,     0,   139,     0,   328,   329,
       0,   330,   331,   332,     0,   333,   334,   335,   139,   336,
     337,   338,   339,     0,     0,   341,   342,   343,   344,   345,
     139,   347,     0,     0,   348,   349,   350,     0,     0,   139,
       0,   102,     0,   139,   325,     0,     0,   142,   326,     0,
     158,   142,     0,     0,     0,     0,     0,   143,     0,   142,
       0,   147,     0,   187,   148,   190,     0,     0,     0,     0,
       0,     0,     0,   148,     0,     0,     0,     0,     0,   143,
       0,     0,     0,     0,   139,   143,   148,     0,   148,     0,
       0,     0,     0,   143,     0,   328,   329,     0,   330,   331,
     332,     0,   333,   334,   335,     0,     0,   337,   338,   339,
     272,     0,   341,   342,   343,   344,     0,     0,   347,     0,
       0,   348,   349,   350,     0,     0,   205,    22,   139,   139,
     139,   139,     0,   148,     0,   147,   102,    29,   253,     0,
     308,     0,   147,     0,   143,     0,     0,    38,   143,     0,
    -224,     0,   211,   139,   139,     0,   143,     0,     0,   148,
       0,     0,     0,   148,   212,   213,   142,   214,     0,    51,
       0,    53,   215,     0,     0,     0,  -224,     0,     0,     0,
     216,     0,    61,     0,     0,     0,   217,     0,     0,     0,
       0,   218,     0,   219,     0,   147,   220,     0,     0,     0,
     373,     0,     0,     0,   221,     0,   -62,    81,     0,   147,
     222,   223,     0,     0,     0,     0,   142,   224,     0,     0,
       0,     0,   142,   148,     0,     0,   225,     0,     0,     0,
       0,     0,     0,     0,     0,   226,   227,     0,   228,     0,
     229,     0,   230,     0,     0,   231,     0,     0,     0,   232,
       0,     0,   233,     0,     0,   234,     0,     0,     0,     0,
       0,     0,     0,   143,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   419,     0,     0,     0,   142,   147,
     142,   432,     0,     0,     0,   142,     0,     0,   142,     0,
       0,     0,     0,     0,     0,   142,     0,   148,   142,     0,
       0,   147,     0,     0,   148,     0,     0,   147,     0,     0,
       0,   238,     0,   143,     0,   147,     0,     0,     0,   143,
     142,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   142,     0,   142,   102,     0,     0,     0,     0,     0,
      17,     0,     0,     0,    21,    22,     0,     0,   102,     0,
       0,     0,     0,    28,     0,    29,   882,   148,     0,     0,
      34,     0,     0,     0,     0,    38,   147,     0,     0,     0,
     147,   148,     0,     0,     0,   143,     0,   143,   147,     0,
       0,     0,   143,     0,     0,   143,     0,    51,     0,    53,
       0,    55,   143,   883,     0,   143,   884,     0,    60,     0,
      61,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   142,     0,     0,   143,   102,    77,
       0,   142,    79,     0,     0,    81,     0,     0,   143,     0,
     143,     0,     0,   142,     0,     0,     0,     0,     0,     0,
     432,   148,     0,     0,     0,   142,   432,     0,     0,     0,
       0,     0,     0,     0,   142,     0,     0,     0,   142,     0,
       0,     0,     0,   148,     0,     0,     0,     0,     0,   148,
       0,     0,     0,     0,     0,    95,     0,   148,    17,     0,
       0,   961,    21,    22,     0,   147,     0,     0,     0,     0,
       0,    28,     0,    29,   882,     0,     0,     0,    34,   142,
       0,     0,     0,    38,     0,   634,     0,     0,     0,   639,
       0,   143,     0,     0,     0,     0,     0,   102,   143,     0,
       0,     0,     0,     0,     0,    51,     0,    53,   148,   307,
     143,   883,   148,     0,   884,   147,    60,     0,    61,     0,
     148,   147,   143,   142,   142,   142,   142,     0,     0,     0,
       0,   143,     0,     0,     0,   143,     0,    77,     0,     0,
      79,     0,     0,    81,     0,     0,     0,     0,   142,   142,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   322,     0,     0,     0,     0,     0,
       0,   323,     0,     0,     0,     0,   143,   147,     0,   147,
       0,     0,     0,   324,   147,     0,     0,   147,     0,     0,
       0,     0,     0,    95,   147,     0,     0,   147,     0,     0,
       0,     0,     0,     0,   716,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   147,
     143,   143,   143,   143,     0,     0,     0,   148,     0,     0,
     147,     0,   147,   325,     0,     0,     0,   326,     0,     0,
       0,     0,     0,     0,     0,   143,   143,     0,     0,     0,
       0,     0,     0,     0,   749,     0,     0,     0,     0,     0,
     754,     0,     0,     0,   404,     0,     0,     0,   327,     0,
       0,     0,     0,     0,     0,     0,     0,   148,     0,     0,
       0,     0,     0,   148,   328,   329,     0,   330,   331,   332,
       0,   333,   334,   335,     0,   336,   337,   338,   339,   340,
       0,   341,   342,   343,   344,   345,   346,   347,     0,     0,
     348,   349,   350,   147,     0,     0,   432,     0,   432,   752,
     147,     0,     0,   432,     0,     0,   432,     0,     0,     0,
       0,     0,   147,   849,     0,     0,   851,     0,     0,   148,
       0,   148,     0,     0,   147,     0,   148,     0,     0,   148,
       0,     0,     0,   147,     0,     0,   148,   147,   865,   148,
       0,     0,     0,   211,     0,     0,     0,     0,     0,   871,
       0,   875,     0,     0,     0,   212,   213,     0,   214,     0,
       0,   148,     0,   215,     0,     0,     0,     0,     0,     0,
       0,   216,   148,     0,   148,     0,     0,   217,   147,     0,
       0,     0,   218,     0,   219,     0,     0,   220,     0,     0,
       0,     0,     0,     0,     0,   221,     0,     0,     0,     0,
       0,   222,   223,     0,     0,     0,     0,     0,   224,     0,
       0,     0,     0,     0,     0,     0,     0,   225,     0,     0,
       0,     0,   147,   147,   147,   147,   226,   227,     0,   228,
       0,   229,     0,   230,   322,     0,   231,     0,     0,     0,
     232,   323,     0,   233,     0,     0,   234,   147,   147,     0,
       0,   919,     0,   324,     0,   148,     0,     0,     0,     0,
       0,     0,   148,   936,     0,     0,     0,     0,     0,     0,
       0,     0,   941,     0,   148,     0,   943,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,     0,     0,     0,
       0,     0,     0,     0,     0,   148,     0,     0,     0,   148,
       0,     0,   724,   325,     0,     0,     0,   326,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   967,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   327,     0,
     148,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   328,   329,     0,   330,   331,   332,
       0,   333,   334,   335,     0,   336,   337,   338,   339,   340,
       0,   341,   342,   343,   344,   345,   346,   347,     0,     0,
     348,   349,   350,     0,   148,   148,   148,   148,     0,   828,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    -2,
       4,     0,     5,     6,     7,     8,     9,    10,     0,   148,
     148,    11,    12,    13,    14,    15,     0,    16,     0,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,    26,
      27,     0,    28,     0,    29,    30,    31,    32,    33,    34,
      35,    36,     0,    37,    38,     0,    39,  -224,     0,    40,
      41,    42,     0,    43,    44,    45,   -43,    46,    47,     0,
      48,    49,    50,     0,     0,     0,    51,    52,    53,    54,
      55,    56,    57,  -224,   -43,    58,    59,    60,     0,    61,
      62,    63,     0,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,     0,    74,    75,    76,    77,    78,
       0,    79,    80,   -61,    81,    82,     0,     0,    83,     0,
      84,     0,     0,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,     0,
       0,    93,    94,     0,    95,     0,     0,    96,     0,    97,
       0,    98,  1029,    99,     5,     6,     7,     8,     9,    10,
       0,     0,     0,   165,     0,     0,    14,    15,     0,    16,
       0,     0,     0,     0,    20,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,     0,     0,     0,    31,   166,
     167,     0,   168,    36,     0,    37,     0,     0,    39,     0,
       0,     0,    41,    42,     0,     0,    44,    45,     0,    46,
      47,     0,    48,    49,     0,     0,     0,     0,     0,    52,
       0,    54,     0,    56,     0,     0,     0,     0,    59,     0,
       0,     0,     0,     0,     0,     0,     0,    66,    67,    68,
      69,    70,   169,     0,    72,     0,     0,    74,     0,     0,
       0,    78,     0,     0,    80,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,     0,     0,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,     0,     0,    93,    94,   256,     0,     0,     0,    96,
       0,   170,     0,    98,     0,   171,  1030,     4,     0,     5,
       6,     7,     8,     9,    10,     0,  -546,     0,    11,    12,
      13,    14,    15,  -546,    16,     0,    17,    18,    19,    20,
      21,    22,    23,    24,    25,  -546,    26,    27,  -546,    28,
       0,    29,    30,    31,    32,    33,    34,    35,    36,     0,
      37,    38,     0,    39,  -224,     0,    40,    41,    42,     0,
      43,    44,    45,   -43,    46,    47,     0,    48,    49,    50,
       0,     0,     0,    51,    52,    53,    54,     0,    56,    57,
    -224,   -43,    58,    59,    60,  -546,    61,    62,    63,  -546,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,     0,    74,    75,    76,    77,    78,     0,    79,    80,
     -61,    81,    82,     0,     0,    83,     0,    84,     0,     0,
    -546,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -546,  -546,    88,  -546,
    -546,  -546,  -546,  -546,  -546,  -546,     0,  -546,  -546,  -546,
    -546,  -546,     0,  -546,  -546,  -546,  -546,  -546,  -546,  -546,
    -546,    95,  -546,  -546,  -546,     0,    97,  -546,    98,   292,
      99,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      11,    12,    13,    14,    15,     0,    16,     0,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,    26,    27,
       0,    28,     0,    29,    30,    31,    32,    33,    34,    35,
      36,     0,    37,    38,     0,    39,  -224,     0,    40,    41,
      42,     0,    43,    44,    45,   -43,    46,    47,     0,    48,
      49,    50,     0,     0,     0,    51,    52,    53,    54,    55,
      56,    57,  -224,   -43,    58,    59,    60,     0,    61,    62,
      63,     0,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,     0,    74,    75,    76,    77,    78,     0,
      79,    80,   -61,    81,    82,     0,     0,    83,     0,    84,
       0,     0,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,    90,     0,     0,     0,     0,    91,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    92,     0,     0,
      93,    94,   256,    95,     0,     0,    96,     0,    97,   293,
      98,     4,    99,     5,     6,     7,     8,     9,    10,     0,
       0,     0,    11,    12,    13,    14,    15,     0,    16,     0,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
      26,    27,     0,    28,     0,    29,    30,    31,    32,    33,
      34,    35,    36,     0,    37,    38,     0,    39,  -224,     0,
      40,    41,    42,     0,    43,    44,    45,   -43,    46,    47,
       0,    48,    49,    50,     0,     0,     0,    51,    52,    53,
      54,    55,    56,    57,  -224,   -43,    58,    59,    60,     0,
      61,    62,    63,     0,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,     0,    74,    75,    76,    77,
      78,     0,    79,    80,   -61,    81,    82,     0,     0,    83,
       0,    84,     0,     0,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,    90,     0,     0,     0,     0,    91,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    92,
       0,     0,    93,    94,     0,    95,     0,     0,    96,     0,
      97,   457,    98,   476,    99,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    11,    12,    13,    14,    15,     0,
      16,     0,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,    26,    27,     0,    28,     0,    29,    30,    31,
      32,    33,    34,    35,    36,     0,    37,    38,     0,    39,
    -224,     0,    40,    41,    42,     0,    43,    44,    45,   -43,
      46,    47,     0,    48,    49,    50,     0,     0,     0,    51,
      52,    53,    54,    55,    56,    57,  -224,   -43,    58,    59,
      60,     0,    61,    62,    63,     0,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,     0,    74,    75,
      76,    77,    78,     0,    79,    80,   -61,    81,    82,     0,
       0,    83,     0,    84,     0,     0,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,    90,     0,     0,     0,
       0,    91,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,     0,     0,    93,    94,     0,    95,     0,     0,
      96,     0,    97,   477,    98,   292,    99,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    11,    12,    13,    14,
      15,     0,    16,     0,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,    26,    27,     0,    28,     0,    29,
      30,    31,    32,    33,    34,    35,    36,     0,    37,    38,
       0,    39,  -224,     0,    40,    41,    42,     0,    43,    44,
      45,   -43,    46,    47,     0,    48,    49,    50,     0,     0,
       0,    51,    52,    53,    54,    55,    56,    57,  -224,   -43,
      58,    59,    60,     0,    61,    62,    63,     0,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,    73,     0,
      74,    75,    76,    77,    78,     0,    79,    80,   -61,    81,
      82,     0,     0,    83,     0,    84,     0,     0,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,    90,     0,
       0,     0,     0,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,     0,     0,    93,    94,     0,    95,
       0,     0,    96,     0,    97,   293,    98,     4,    99,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    11,    12,
      13,    14,    15,     0,    16,     0,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,    26,    27,     0,    28,
       0,    29,    30,    31,    32,    33,    34,    35,    36,     0,
      37,    38,     0,    39,  -224,     0,    40,    41,    42,     0,
      43,    44,    45,   -43,    46,    47,     0,    48,    49,    50,
       0,     0,     0,    51,    52,    53,    54,    55,    56,    57,
    -224,   -43,    58,    59,    60,     0,    61,    62,    63,     0,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,     0,    74,    75,    76,    77,    78,     0,    79,    80,
     -61,    81,    82,     0,     0,    83,     0,    84,     0,     0,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,     0,     0,     0,     0,    91,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,     0,     0,    93,    94,
       0,    95,     0,     0,    96,     0,    97,   646,    98,     4,
      99,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      11,    12,    13,    14,    15,     0,    16,     0,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,    26,    27,
       0,    28,     0,    29,    30,    31,    32,    33,    34,    35,
      36,     0,    37,    38,     0,    39,  -224,     0,    40,    41,
      42,     0,    43,    44,    45,   -43,    46,    47,     0,    48,
      49,    50,     0,     0,     0,    51,    52,    53,    54,   307,
      56,    57,  -224,   -43,    58,    59,    60,     0,    61,    62,
      63,     0,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,     0,    74,    75,    76,    77,    78,     0,
      79,    80,   -61,    81,    82,     0,     0,    83,     0,    84,
       0,     0,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,    90,     0,     0,     0,     0,    91,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    92,     0,     0,
      93,    94,     0,    95,     0,     0,    96,     0,    97,     0,
      98,     4,    99,     5,     6,     7,     8,     9,    10,     0,
       0,     0,    11,    12,    13,    14,    15,     0,    16,     0,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
      26,    27,     0,    28,     0,    29,    30,    31,    32,    33,
      34,    35,    36,     0,    37,    38,     0,    39,  -224,     0,
      40,    41,    42,     0,    43,    44,    45,   -43,    46,    47,
       0,    48,    49,    50,     0,     0,     0,    51,    52,    53,
      54,     0,    56,    57,  -224,   -43,    58,    59,    60,     0,
      61,    62,    63,     0,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,     0,    74,    75,    76,    77,
      78,     0,    79,    80,   -61,    81,    82,     0,     0,    83,
       0,    84,     0,     0,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,    90,     0,     0,     0,     0,    91,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    92,
       0,     0,    93,    94,     0,    95,     0,     0,    96,     0,
      97,     0,    98,     4,    99,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    11,    12,    13,    14,    15,     0,
      16,     0,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,    26,    27,     0,    28,     0,    29,    30,    31,
      32,    33,    34,   566,    36,     0,    37,    38,     0,    39,
    -224,     0,    40,    41,    42,     0,    43,    44,    45,   -43,
      46,    47,     0,    48,    49,    50,     0,     0,     0,    51,
      52,    53,    54,     0,    56,    57,  -224,   -43,    58,    59,
      60,     0,    61,    62,    63,     0,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,     0,    74,    75,
      76,    77,    78,     0,    79,    80,   -61,    81,    82,     0,
       0,    83,     0,    84,     0,     0,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,    90,     0,     0,     0,
       0,    91,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,     0,     0,    93,    94,     0,    95,     0,     0,
      96,     0,    97,     0,    98,     4,    99,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    11,    12,    13,    14,
      15,     0,    16,     0,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,    26,    27,     0,    28,     0,    29,
      30,    31,    32,    33,    34,   572,    36,     0,    37,    38,
       0,    39,  -224,     0,    40,    41,    42,     0,    43,    44,
      45,   -43,    46,    47,     0,    48,    49,    50,     0,     0,
       0,    51,    52,    53,    54,     0,    56,    57,  -224,   -43,
      58,    59,    60,     0,    61,    62,    63,     0,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,    73,     0,
      74,    75,    76,    77,    78,     0,    79,    80,   -61,    81,
      82,     0,     0,    83,     0,    84,     0,     0,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,    90,     0,
       0,     0,     0,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,     0,     0,    93,    94,     0,    95,
       0,     0,    96,     0,    97,     0,    98,     4,    99,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    11,    12,
      13,    14,    15,     0,    16,     0,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,    26,    27,     0,    28,
       0,    29,    30,    31,    32,    33,    34,   834,    36,     0,
      37,    38,     0,    39,  -224,     0,    40,    41,    42,     0,
      43,    44,    45,   -43,    46,    47,     0,    48,    49,    50,
       0,     0,     0,    51,    52,    53,    54,     0,    56,    57,
    -224,   -43,    58,    59,    60,     0,    61,    62,    63,     0,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,     0,    74,    75,    76,    77,    78,     0,    79,    80,
     -61,    81,    82,     0,     0,    83,     0,    84,     0,     0,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,     0,     0,     0,     0,    91,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,     0,     0,    93,    94,
       0,    95,     0,     0,    96,     0,    97,     0,    98,     4,
      99,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      11,    12,    13,    14,    15,     0,    16,     0,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,    26,    27,
       0,    28,     0,    29,    30,    31,    32,    33,    34,   836,
      36,     0,    37,    38,     0,    39,  -224,     0,    40,    41,
      42,     0,    43,    44,    45,   -43,    46,    47,     0,    48,
      49,    50,     0,     0,     0,    51,    52,    53,    54,     0,
      56,    57,  -224,   -43,    58,    59,    60,     0,    61,    62,
      63,     0,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,     0,    74,    75,    76,    77,    78,     0,
      79,    80,   -61,    81,    82,     0,     0,    83,     0,    84,
       0,     0,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,    90,     0,     0,     0,     0,    91,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    92,     0,     0,
      93,    94,     0,    95,     0,     0,    96,     0,    97,     0,
      98,     4,    99,     5,     6,     7,     8,     9,    10,     0,
       0,     0,    11,    12,    13,    14,    15,     0,    16,     0,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
      26,    27,     0,    28,     0,    29,    30,    31,    32,    33,
      34,   841,    36,     0,    37,    38,     0,    39,  -224,     0,
      40,    41,    42,     0,    43,    44,    45,   -43,    46,    47,
       0,    48,    49,    50,     0,     0,     0,    51,    52,    53,
      54,     0,    56,    57,  -224,   -43,    58,    59,    60,     0,
      61,    62,    63,     0,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,     0,    74,    75,    76,    77,
      78,     0,    79,    80,   -61,    81,    82,     0,     0,    83,
       0,    84,     0,     0,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,    90,     0,     0,     0,     0,    91,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    92,
       0,     0,    93,    94,     0,    95,     0,     0,    96,     0,
      97,     0,    98,     4,    99,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    11,    12,    13,    14,    15,     0,
      16,     0,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,    26,    27,     0,    28,     0,    29,    30,    31,
      32,    33,    34,   844,    36,     0,    37,    38,     0,    39,
    -224,     0,    40,    41,    42,     0,    43,    44,    45,   -43,
      46,    47,     0,    48,    49,    50,     0,     0,     0,    51,
      52,    53,    54,     0,    56,    57,  -224,   -43,    58,    59,
      60,     0,    61,    62,    63,     0,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,     0,    74,    75,
      76,    77,    78,     0,    79,    80,   -61,    81,    82,     0,
       0,    83,     0,    84,     0,     0,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,    90,     0,     0,     0,
       0,    91,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,     0,     0,    93,    94,     0,    95,     0,     0,
      96,     0,    97,     0,    98,     4,    99,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    11,    12,    13,    14,
      15,     0,    16,     0,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,   864,    27,     0,    28,     0,    29,
      30,    31,    32,    33,    34,    35,    36,     0,    37,    38,
       0,    39,  -224,     0,    40,    41,    42,     0,    43,    44,
      45,   -43,    46,    47,     0,    48,    49,    50,     0,     0,
       0,    51,    52,    53,    54,     0,    56,    57,  -224,   -43,
      58,    59,    60,     0,    61,    62,    63,     0,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,    73,     0,
      74,    75,    76,    77,    78,     0,    79,    80,   -61,    81,
      82,     0,     0,    83,     0,    84,     0,     0,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,    90,     0,
       0,     0,     0,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,     0,     0,    93,    94,     0,    95,
       0,     0,    96,     0,    97,     0,    98,     4,    99,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    11,    12,
      13,    14,    15,     0,    16,     0,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,    26,    27,     0,    28,
       0,    29,    30,    31,    32,    33,    34,   870,    36,     0,
      37,    38,     0,    39,  -224,     0,    40,    41,    42,     0,
      43,    44,    45,   -43,    46,    47,     0,    48,    49,    50,
       0,     0,     0,    51,    52,    53,    54,     0,    56,    57,
    -224,   -43,    58,    59,    60,     0,    61,    62,    63,     0,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,     0,    74,    75,    76,    77,    78,     0,    79,    80,
     -61,    81,    82,     0,     0,    83,     0,    84,     0,     0,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,     0,     0,     0,     0,    91,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,     0,     0,    93,    94,
       0,    95,     0,     0,    96,     0,    97,     0,    98,     4,
      99,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      11,    12,    13,    14,    15,     0,    16,     0,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,    26,    27,
       0,    28,     0,    29,    30,    31,    32,    33,    34,   874,
      36,     0,    37,    38,     0,    39,  -224,     0,    40,    41,
      42,     0,    43,    44,    45,   -43,    46,    47,     0,    48,
      49,    50,     0,     0,     0,    51,    52,    53,    54,     0,
      56,    57,  -224,   -43,    58,    59,    60,     0,    61,    62,
      63,     0,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,     0,    74,    75,    76,    77,    78,     0,
      79,    80,   -61,    81,    82,     0,     0,    83,     0,    84,
       0,     0,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,    90,     0,     0,     0,     0,    91,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    92,     0,     0,
      93,    94,     0,    95,     0,     0,    96,     0,    97,     0,
      98,   734,    99,     5,     6,     7,     8,     9,    10,     0,
       0,     0,   165,     0,     0,    14,    15,     0,    16,     0,
       0,     0,     0,    20,     0,     0,     0,     0,     0,     0,
       0,    27,     0,     0,     0,     0,     0,    31,   166,   167,
       0,   168,    36,     0,    37,     0,     0,    39,     0,     0,
       0,    41,    42,     0,     0,    44,    45,     0,    46,    47,
       0,    48,    49,     0,     0,     0,     0,     0,    52,     0,
      54,     0,    56,     0,     0,     0,     0,    59,     0,     0,
       0,     0,     0,     0,     0,     0,    66,    67,    68,    69,
      70,   169,     0,    72,     0,     0,    74,     0,     0,     0,
      78,     0,     0,    80,     0,     0,    82,     0,     0,     0,
       0,     0,     0,     0,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,    90,     0,     0,     0,     0,    91,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    92,
       0,     0,    93,    94,   256,     0,     0,     0,    96,     0,
     170,     0,    98,     0,   171,     5,     6,     7,     8,     9,
      10,     0,     0,     0,   165,     0,     0,    14,    15,     0,
      16,     0,     0,     0,     0,    20,     0,     0,     0,     0,
       0,     0,     0,    27,     0,     0,     0,     0,     0,    31,
     166,   167,     0,   168,    36,     0,    37,     0,     0,    39,
       0,     0,     0,    41,    42,     0,     0,    44,    45,     0,
      46,    47,     0,    48,    49,     0,     0,     0,     0,     0,
      52,     0,    54,     0,    56,     0,     0,     0,     0,    59,
       0,     0,     0,     0,     0,     0,     0,     0,    66,    67,
      68,    69,    70,   169,     0,    72,     0,     0,    74,     0,
       0,     0,    78,     0,     0,    80,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,    90,     0,     0,     0,
       0,    91,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,     0,     0,    93,    94,   256,     0,     0,     0,
      96,     0,   170,     0,    98,     0,   171,   638,     5,     6,
       7,     8,     9,    10,     0,     0,     0,   165,     0,     0,
      14,    15,     0,    16,     0,     0,     0,     0,    20,     0,
       0,     0,     0,     0,     0,     0,    27,     0,     0,     0,
       0,     0,    31,   166,   167,     0,   168,    36,     0,    37,
       0,     0,    39,     0,     0,     0,    41,    42,     0,     0,
      44,    45,     0,    46,    47,     0,    48,    49,     0,     0,
       0,     0,     0,    52,     0,    54,     0,    56,     0,     0,
       0,     0,    59,     0,     0,     0,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,   169,     0,    72,     0,
       0,    74,     0,     0,     0,    78,     0,     0,    80,     0,
       0,    82,     0,     0,     0,     0,     0,     0,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,     0,     0,    93,    94,   256,
       0,     0,     0,    96,     0,   170,     0,    98,     0,   171,
     970,     5,     6,     7,     8,     9,    10,     0,     0,     0,
     165,     0,     0,    14,    15,     0,    16,     0,     0,     0,
       0,    20,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,     0,     0,     0,    31,   166,   167,     0,   168,
      36,     0,    37,     0,     0,    39,     0,     0,     0,    41,
      42,     0,     0,    44,    45,     0,    46,    47,     0,    48,
      49,     0,     0,     0,     0,     0,    52,     0,    54,     0,
      56,     0,     0,     0,     0,    59,     0,     0,     0,     0,
       0,     0,     0,     0,    66,    67,    68,    69,    70,   169,
       0,    72,     0,     0,    74,     0,     0,     0,    78,     0,
       0,    80,     0,     0,    82,     0,     0,     0,     0,     0,
       0,     0,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,    90,     0,     0,     0,     0,    91,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    92,     0,     0,
      93,    94,   766,     0,   767,     0,    96,     0,   170,     0,
      98,   768,   171,   643,     0,     0,   769,   213,   770,   771,
       0,     0,     0,     0,   772,     0,     0,     0,     0,     0,
       0,     0,   216,     0,     0,     0,     0,     0,   773,     0,
       0,     0,     0,   774,     0,   219,     0,     0,   775,     0,
     776,     0,     0,     0,     0,     0,   777,     0,     0,     0,
       0,     0,   778,   779,     0,     0,     0,     0,     0,   224,
       0,     0,     0,     0,     0,     0,     0,     0,   780,     0,
       0,     0,     0,     0,     0,     0,     0,   226,   227,     0,
     781,     0,   229,     0,   782,     0,     0,   783,     0,     0,
       0,   784,     0,     0,   233,     0,     0,   785,     0,     0,
       0,     0,     0,     0,     0,     0,   351,   352,   353,   354,
     355,   356,     0,     0,   359,   360,   361,   362,     0,   364,
     365,   786,   787,   788,   789,   790,     0,     0,   791,     0,
       0,     0,   792,   793,   794,   795,   796,   797,   798,   799,
     800,   801,   802,     0,   803,     0,     0,   804,   805,   806,
     807,     0,     0,   808,     5,     6,     7,     8,     9,    10,
       0,     0,     0,   165,     0,     0,    14,    15,     0,    16,
       0,     0,     0,     0,    20,   205,    22,     0,     0,     0,
       0,     0,    27,     0,     0,     0,     0,   206,    31,   166,
     167,     0,   168,    36,     0,    37,     0,     0,    39,     0,
       0,     0,    41,    42,     0,     0,    44,    45,     0,    46,
      47,     0,    48,    49,     0,     0,     0,     0,     0,    52,
      53,    54,     0,    56,     0,     0,     0,     0,    59,     0,
       0,    61,     0,     0,     0,     0,     0,    66,    67,    68,
      69,    70,   169,     0,    72,     0,     0,    74,     0,     0,
       0,    78,     0,     0,    80,     0,    81,    82,     0,     0,
       0,     0,     0,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,     0,     0,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,     0,     0,    93,    94,     0,     0,     0,     0,    96,
       0,   170,     0,    98,     0,   171,     5,     6,     7,     8,
     194,    10,   195,     0,     0,   165,     0,     0,    14,    15,
       0,    16,     0,  -123,     0,     0,    20,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     0,     0,     0,     0,
      31,   166,   167,     0,   168,    36,     0,    37,     0,     0,
      39,     0,     0,     0,    41,    42,     0,     0,    44,    45,
       0,    46,    47,     0,    48,    49,     0,     0,     0,     0,
       0,    52,     0,    54,     0,    56,     0,     0,     0,     0,
      59,  -123,     0,     0,     0,     0,     0,     0,     0,    66,
      67,    68,    69,    70,   169,     0,    72,     0,     0,    74,
       0,     0,   196,    78,     0,  -123,    80,     0,     0,    82,
       0,     0,     0,     0,     0,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,    90,     0,     0,
       0,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,     0,     0,    93,    94,     0,     0,     0,
       0,    96,     0,   170,     0,    98,     0,   171,     5,     6,
       7,     8,     9,    10,     0,     0,     0,   165,     0,     0,
      14,    15,     0,    16,     0,     0,     0,     0,    20,     0,
       0,     0,     0,     0,     0,     0,    27,     0,     0,     0,
       0,     0,    31,   166,   167,     0,   168,    36,     0,    37,
       0,     0,    39,     0,     0,     0,    41,    42,     0,     0,
      44,    45,     0,    46,    47,     0,    48,    49,     0,     0,
       0,     0,     0,    52,     0,    54,     0,    56,     0,     0,
       0,     0,    59,     0,     0,     0,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,   169,     0,    72,     0,
       0,    74,   260,   261,     0,    78,   297,     0,    80,     0,
       0,    82,     0,     0,     0,     0,     0,     0,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
       0,     0,     0,     0,    91,   298,     0,     0,     0,     0,
       0,     0,     0,     0,    92,     0,     0,    93,    94,   256,
       0,     0,     0,    96,     0,   170,     0,    98,     0,   171,
       5,     6,     7,     8,     9,    10,     0,     0,     0,   165,
       0,     0,    14,    15,     0,    16,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     0,     0,     0,    31,   166,   167,     0,   168,    36,
       0,    37,     0,     0,    39,     0,     0,     0,    41,    42,
       0,     0,    44,    45,     0,    46,    47,     0,    48,    49,
       0,     0,     0,     0,     0,    52,     0,    54,     0,    56,
       0,     0,     0,     0,    59,     0,     0,     0,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,   169,     0,
      72,     0,     0,    74,   260,   261,     0,    78,   297,     0,
      80,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,     0,     0,    93,
      94,   256,     0,     0,     0,    96,     0,   170,     0,    98,
     630,   171,     5,     6,     7,     8,     9,    10,     0,     0,
       0,   165,     0,     0,    14,    15,     0,    16,     0,     0,
       0,     0,    20,     0,     0,     0,     0,     0,     0,     0,
      27,     0,     0,     0,     0,     0,    31,   166,   167,     0,
     168,    36,     0,    37,     0,     0,    39,     0,     0,     0,
      41,    42,     0,     0,    44,    45,     0,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,    52,     0,    54,
       0,    56,     0,     0,     0,     0,    59,     0,     0,     0,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
     169,     0,    72,     0,     0,    74,   260,   261,     0,    78,
     297,     0,    80,     0,     0,    82,     0,     0,     0,     0,
       0,     0,     0,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,     0,
       0,    93,    94,   256,     0,     0,     0,    96,     0,   170,
       0,    98,   632,   171,     5,     6,     7,     8,     9,    10,
       0,     0,     0,   165,     0,     0,    14,    15,     0,    16,
       0,     0,     0,     0,    20,     0,   535,     0,     0,     0,
       0,     0,    27,     0,     0,     0,     0,     0,    31,   166,
     167,     0,   168,    36,   536,    37,     0,     0,    39,     0,
       0,     0,    41,    42,     0,     0,    44,    45,     0,    46,
      47,     0,    48,    49,     0,     0,     0,     0,     0,    52,
       0,    54,     0,    56,     0,     0,     0,     0,    59,     0,
       0,   537,     0,     0,     0,     0,     0,    66,    67,    68,
      69,    70,   169,     0,    72,     0,     0,    74,     0,     0,
       0,    78,     0,     0,    80,     0,   538,    82,     0,     0,
       0,     0,     0,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,     0,     0,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,     0,     0,    93,    94,     0,     0,     0,     0,    96,
       0,   170,     0,    98,     0,   171,     5,     6,     7,     8,
     194,    10,     0,     0,     0,   165,     0,     0,    14,    15,
       0,    16,     0,  -123,     0,     0,    20,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     0,     0,     0,     0,
      31,   166,   167,     0,   168,    36,     0,    37,     0,     0,
      39,     0,     0,     0,    41,    42,     0,     0,    44,    45,
       0,    46,    47,     0,    48,    49,     0,     0,     0,     0,
       0,    52,     0,    54,     0,    56,     0,     0,     0,     0,
      59,  -123,     0,     0,     0,     0,     0,     0,     0,    66,
      67,    68,    69,    70,   169,     0,    72,     0,     0,    74,
       0,     0,   196,    78,     0,  -123,    80,     0,     0,    82,
       0,     0,     0,     0,     0,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,    90,     0,     0,
       0,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,     0,     0,    93,    94,     0,     0,     0,
       0,    96,     0,   170,     0,    98,     0,   171,     5,     6,
       7,     8,     9,    10,     0,     0,     0,   165,     0,     0,
      14,    15,     0,    16,     0,     0,     0,     0,    20,     0,
       0,     0,     0,     0,     0,     0,    27,     0,     0,     0,
       0,     0,    31,   166,   167,     0,   168,    36,     0,    37,
       0,     0,    39,     0,     0,     0,    41,    42,     0,     0,
      44,    45,     0,    46,    47,     0,    48,    49,     0,     0,
       0,     0,     0,    52,     0,    54,     0,    56,     0,     0,
       0,     0,    59,     0,     0,     0,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,   169,     0,    72,     0,
       0,    74,   260,   261,     0,    78,     0,     0,    80,     0,
       0,    82,     0,     0,     0,     0,     0,     0,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,     0,     0,    93,    94,     0,
     262,     0,     0,    96,     0,   170,     0,    98,     0,   171,
       5,     6,     7,     8,     9,    10,     0,     0,     0,   165,
       0,     0,    14,    15,     0,    16,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     0,     0,     0,    31,   166,   167,     0,   168,    36,
       0,    37,     0,     0,    39,     0,     0,     0,    41,    42,
       0,     0,    44,    45,     0,    46,    47,     0,    48,    49,
       0,     0,     0,     0,     0,    52,     0,    54,     0,    56,
       0,     0,     0,     0,    59,     0,     0,     0,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,   169,     0,
      72,     0,     0,    74,   260,   261,     0,    78,     0,     0,
      80,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,     0,     0,    93,
      94,   256,     0,     0,     0,    96,     0,   170,     0,    98,
       0,   171,     5,     6,     7,     8,     9,    10,     0,     0,
       0,   165,     0,     0,    14,    15,     0,    16,     0,     0,
       0,     0,    20,     0,     0,     0,     0,     0,     0,     0,
      27,     0,     0,     0,     0,     0,    31,   166,   167,     0,
     168,    36,     0,    37,     0,     0,    39,     0,     0,     0,
      41,    42,     0,     0,    44,    45,     0,    46,    47,   736,
      48,    49,     0,     0,     0,     0,     0,    52,     0,    54,
       0,    56,     0,     0,     0,     0,    59,     0,     0,     0,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
     169,     0,    72,     0,     0,    74,   260,   261,     0,    78,
       0,     0,    80,     0,     0,    82,     0,     0,     0,     0,
       0,     0,     0,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,     0,
       0,    93,    94,     0,     0,     0,     0,    96,     0,   170,
       0,    98,     0,   171,     5,     6,     7,     8,     9,    10,
       0,     0,     0,   165,     0,     0,    14,    15,     0,    16,
       0,     0,     0,     0,    20,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,     0,     0,     0,    31,   166,
     167,     0,   168,    36,     0,    37,     0,     0,    39,     0,
       0,     0,    41,    42,     0,     0,    44,    45,     0,    46,
      47,     0,    48,    49,     0,     0,     0,     0,     0,    52,
     199,    54,     0,    56,     0,     0,     0,     0,    59,     0,
       0,     0,     0,     0,     0,     0,     0,    66,    67,    68,
      69,    70,   169,     0,    72,     0,     0,    74,     0,     0,
       0,    78,     0,     0,    80,     0,     0,    82,     0,     0,
       0,     0,     0,   200,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,     0,     0,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,     0,     0,    93,    94,     0,     0,     0,     0,    96,
       0,   170,     0,    98,     0,   171,     5,     6,     7,     8,
       9,    10,     0,     0,     0,   165,     0,     0,    14,    15,
       0,    16,     0,     0,     0,     0,    20,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     0,     0,     0,     0,
      31,   166,   167,     0,   168,    36,     0,    37,     0,     0,
      39,     0,     0,     0,    41,    42,     0,     0,    44,    45,
       0,    46,    47,     0,    48,    49,     0,     0,     0,     0,
       0,    52,     0,    54,     0,    56,     0,     0,     0,     0,
      59,     0,     0,     0,     0,     0,     0,     0,     0,    66,
      67,    68,    69,    70,   169,     0,    72,     0,     0,    74,
       0,     0,     0,    78,     0,     0,    80,     0,     0,    82,
       0,     0,     0,     0,     0,   200,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,    90,     0,     0,
       0,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,     0,     0,    93,    94,   256,     0,     0,
       0,    96,     0,   170,     0,    98,     0,   171,     5,     6,
       7,     8,     9,    10,     0,     0,     0,   165,     0,     0,
      14,    15,     0,    16,     0,     0,     0,     0,    20,     0,
       0,     0,     0,     0,     0,     0,    27,     0,     0,     0,
       0,     0,    31,   166,   167,     0,   168,    36,     0,    37,
       0,     0,    39,     0,     0,     0,    41,    42,     0,     0,
      44,    45,     0,    46,    47,     0,    48,    49,     0,     0,
       0,     0,     0,    52,     0,    54,     0,    56,     0,     0,
       0,     0,    59,     0,     0,     0,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,   169,     0,    72,     0,
       0,    74,   260,   261,     0,    78,     0,     0,    80,     0,
       0,    82,     0,     0,     0,     0,     0,     0,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,     0,     0,    93,    94,     0,
       0,     0,     0,    96,     0,   170,     0,    98,     0,   171,
       5,     6,     7,     8,     9,    10,     0,     0,     0,   165,
       0,     0,    14,    15,     0,    16,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     0,     0,     0,    31,   166,   167,     0,   168,    36,
       0,    37,     0,     0,    39,     0,     0,     0,    41,    42,
       0,     0,    44,    45,     0,    46,    47,     0,    48,    49,
       0,     0,     0,     0,     0,    52,     0,    54,     0,    56,
       0,     0,     0,     0,    59,     0,     0,     0,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,   169,     0,
      72,     0,     0,    74,     0,     0,     0,    78,     0,     0,
      80,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,     0,     0,    93,
      94,   256,     0,     0,     0,    96,     0,   170,   628,    98,
       0,   171,     5,     6,     7,     8,     9,    10,     0,     0,
       0,   165,     0,     0,    14,    15,     0,    16,     0,     0,
       0,     0,    20,     0,     0,     0,     0,     0,     0,     0,
      27,     0,     0,     0,     0,     0,    31,   166,   167,     0,
     168,    36,     0,    37,     0,     0,    39,     0,     0,     0,
      41,    42,     0,     0,    44,    45,     0,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,    52,     0,    54,
       0,    56,     0,     0,     0,     0,    59,     0,     0,     0,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
     169,     0,    72,     0,     0,    74,     0,     0,     0,    78,
       0,     0,    80,     0,     0,    82,     0,     0,     0,     0,
       0,   200,     0,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,     0,
       0,    93,    94,     0,     0,     0,     0,    96,     0,   170,
       0,    98,     0,   171,     5,     6,     7,     8,     9,    10,
       0,     0,     0,   165,     0,     0,    14,    15,     0,    16,
       0,     0,     0,     0,    20,     0,     0,     0,     0,     0,
       0,   242,    27,     0,     0,     0,     0,     0,    31,   166,
     167,     0,   168,    36,     0,    37,     0,     0,    39,     0,
       0,     0,    41,    42,     0,     0,    44,    45,     0,    46,
      47,     0,    48,    49,     0,     0,     0,     0,     0,    52,
       0,    54,     0,    56,     0,     0,     0,     0,    59,     0,
       0,     0,     0,     0,     0,     0,     0,    66,    67,    68,
      69,    70,   169,     0,    72,     0,     0,    74,     0,     0,
       0,    78,     0,     0,    80,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,     0,     0,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,     0,     0,    93,    94,     0,     0,     0,     0,    96,
       0,    97,     0,    98,     0,   171,     5,     6,     7,     8,
       9,    10,     0,     0,     0,   165,     0,     0,    14,    15,
       0,    16,     0,     0,     0,     0,    20,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     0,     0,     0,     0,
      31,   166,   167,     0,   168,    36,     0,    37,     0,     0,
      39,     0,     0,     0,    41,    42,     0,     0,    44,    45,
       0,    46,    47,     0,    48,    49,     0,     0,     0,     0,
       0,    52,     0,    54,     0,    56,     0,     0,     0,     0,
      59,     0,     0,     0,     0,     0,     0,     0,     0,    66,
      67,    68,    69,    70,   169,     0,    72,     0,     0,    74,
       0,     0,     0,    78,     0,     0,    80,     0,     0,    82,
       0,     0,     0,     0,     0,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,    90,     0,     0,
       0,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,     0,     0,    93,    94,   256,     0,     0,
       0,    96,     0,   170,     0,    98,     0,   171,     5,     6,
       7,     8,     9,    10,     0,     0,     0,   165,     0,     0,
      14,    15,     0,    16,     0,     0,     0,     0,    20,     0,
       0,     0,     0,     0,     0,     0,    27,     0,     0,     0,
       0,     0,    31,   166,   167,     0,   168,    36,     0,    37,
       0,     0,    39,     0,     0,     0,    41,    42,     0,     0,
      44,    45,     0,    46,    47,     0,    48,    49,     0,     0,
       0,     0,     0,    52,     0,    54,     0,    56,     0,     0,
       0,     0,    59,     0,     0,     0,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,   169,     0,    72,     0,
       0,    74,     0,     0,     0,    78,     0,     0,    80,     0,
       0,    82,     0,     0,     0,     0,     0,     0,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,     0,     0,    93,    94,   507,
       0,     0,     0,    96,     0,   170,     0,    98,     0,   171,
       5,     6,     7,     8,     9,    10,     0,     0,     0,   165,
       0,     0,    14,    15,     0,    16,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     0,     0,     0,    31,   166,   167,     0,   168,    36,
       0,    37,     0,     0,    39,     0,     0,     0,    41,    42,
       0,     0,    44,    45,     0,    46,    47,     0,    48,    49,
       0,     0,     0,     0,     0,    52,     0,    54,     0,    56,
       0,     0,     0,     0,    59,     0,     0,     0,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,   169,     0,
      72,     0,     0,    74,     0,     0,     0,    78,     0,     0,
      80,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,     0,     0,    93,
      94,   517,     0,     0,     0,    96,     0,   170,     0,    98,
       0,   171,     5,     6,     7,     8,     9,    10,     0,     0,
       0,   165,     0,     0,    14,    15,     0,    16,     0,     0,
       0,     0,    20,     0,     0,     0,     0,     0,     0,     0,
     604,     0,     0,     0,     0,     0,    31,   166,   167,     0,
     168,    36,     0,   605,     0,     0,    39,     0,     0,     0,
      41,    42,     0,     0,    44,    45,     0,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,    52,     0,    54,
       0,    56,     0,     0,     0,     0,    59,     0,     0,     0,
       0,     0,     0,     0,     0,    66,   606,    68,    69,    70,
     607,     0,    72,     0,     0,    74,     0,     0,     0,    78,
       0,     0,    80,     0,     0,    82,     0,     0,     0,     0,
       0,     0,     0,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,     0,
       0,    93,    94,   256,     0,     0,     0,    96,     0,   170,
       0,    98,     0,   922,     5,     6,     7,     8,     9,    10,
       0,     0,     0,   165,     0,     0,    14,    15,     0,    16,
       0,     0,     0,     0,    20,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,     0,     0,     0,    31,   166,
     167,     0,   168,    36,     0,    37,     0,     0,    39,     0,
       0,     0,    41,    42,     0,     0,    44,    45,     0,    46,
      47,     0,    48,    49,     0,     0,     0,     0,     0,    52,
       0,    54,     0,    56,     0,     0,     0,     0,    59,     0,
       0,     0,     0,     0,     0,     0,     0,    66,    67,    68,
      69,    70,   169,     0,    72,     0,     0,    74,     0,     0,
       0,    78,     0,     0,    80,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,     0,     0,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,     0,     0,    93,    94,   256,     0,     0,     0,    96,
       0,   170,     0,    98,     0,   922,     5,     6,     7,     8,
       9,    10,     0,     0,     0,   165,     0,     0,    14,    15,
       0,    16,     0,     0,     0,     0,    20,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     0,     0,     0,     0,
      31,   166,   167,     0,   907,    36,     0,    37,     0,     0,
      39,     0,     0,     0,    41,    42,     0,     0,    44,    45,
       0,    46,    47,     0,    48,    49,     0,     0,     0,     0,
       0,    52,     0,    54,     0,    56,     0,     0,     0,     0,
      59,     0,     0,     0,     0,     0,     0,     0,     0,    66,
      67,    68,    69,    70,   169,     0,    72,     0,     0,    74,
       0,     0,     0,    78,     0,     0,    80,     0,     0,    82,
       0,     0,     0,     0,     0,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,    90,     0,     0,
       0,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,     0,     0,    93,    94,   256,     0,     0,
       0,    96,     0,   170,     0,    98,     0,   171,     5,     6,
       7,     8,     9,    10,     0,     0,     0,   165,     0,     0,
      14,    15,     0,    16,     0,     0,     0,     0,    20,     0,
       0,     0,     0,     0,     0,     0,    27,     0,     0,     0,
       0,     0,    31,   166,   167,     0,   168,    36,     0,    37,
       0,     0,    39,     0,     0,     0,    41,    42,     0,     0,
      44,    45,     0,    46,    47,     0,    48,    49,     0,     0,
       0,     0,     0,    52,     0,    54,     0,    56,     0,     0,
       0,     0,    59,     0,     0,     0,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,   169,     0,    72,     0,
       0,    74,     0,     0,     0,    78,     0,     0,    80,     0,
       0,    82,     0,     0,     0,     0,     0,     0,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,     0,     0,    93,    94,     0,
       0,     0,     0,    96,     0,   170,     0,    98,     0,   171,
       5,     6,     7,     8,     9,    10,     0,     0,     0,   165,
       0,     0,    14,    15,     0,    16,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     0,     0,     0,    31,   166,   167,     0,   168,    36,
       0,    37,     0,     0,    39,     0,     0,     0,    41,    42,
       0,     0,    44,    45,     0,    46,    47,     0,    48,    49,
       0,     0,     0,     0,     0,    52,     0,    54,     0,    56,
       0,     0,     0,     0,    59,     0,     0,     0,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,   169,     0,
      72,     0,     0,    74,     0,     0,     0,    78,     0,     0,
      80,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,     0,     0,    93,
      94,     0,     0,     0,     0,    96,     0,    97,     0,    98,
       0,   171,     5,     6,     7,     8,     9,    10,     0,     0,
       0,   165,     0,     0,    14,    15,     0,    16,     0,     0,
       0,     0,    20,     0,     0,     0,     0,     0,     0,     0,
      27,     0,     0,     0,     0,     0,    31,   166,   167,     0,
     168,    36,     0,    37,     0,     0,    39,     0,     0,     0,
      41,    42,     0,     0,    44,    45,     0,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,    52,     0,    54,
       0,    56,     0,     0,     0,     0,    59,     0,     0,     0,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
     169,     0,    72,     0,     0,    74,     0,     0,     0,    78,
       0,     0,    80,     0,     0,    82,     0,     0,     0,     0,
       0,     0,     0,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,     0,
       0,    93,    94,     0,     0,     0,     0,   577,     0,   170,
       0,    98,     0,   171,     5,     6,     7,     8,     9,    10,
       0,     0,     0,   165,     0,     0,    14,    15,     0,    16,
       0,     0,     0,     0,    20,     0,     0,     0,     0,     0,
       0,     0,   604,     0,     0,     0,     0,     0,    31,   166,
     167,     0,   168,    36,     0,   605,     0,     0,    39,     0,
       0,     0,    41,    42,     0,     0,    44,    45,     0,    46,
      47,     0,    48,    49,     0,     0,     0,     0,     0,    52,
       0,    54,     0,    56,     0,     0,     0,     0,    59,     0,
       0,     0,     0,     0,     0,     0,     0,    66,   606,    68,
      69,    70,   607,     0,    72,     0,     0,    74,     0,     0,
       0,    78,     0,     0,    80,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,     0,     0,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,     0,     0,    93,    94,     0,     0,     0,     0,    96,
       0,   170,     0,    98,     0,   608,     5,     6,     7,     8,
       9,    10,     0,     0,     0,   165,     0,     0,    14,    15,
       0,    16,     0,     0,     0,     0,    20,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     0,     0,     0,     0,
      31,   166,   167,     0,   168,    36,     0,    37,     0,     0,
      39,     0,     0,     0,    41,    42,     0,     0,    44,    45,
       0,    46,    47,     0,    48,    49,     0,     0,     0,     0,
       0,    52,     0,    54,     0,    56,     0,     0,     0,     0,
      59,     0,     0,     0,     0,     0,     0,     0,     0,    66,
      67,    68,    69,    70,   169,     0,    72,     0,     0,    74,
       0,     0,     0,    78,     0,     0,    80,     0,     0,    82,
       0,     0,     0,     0,     0,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,    90,     0,     0,
       0,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,     0,     0,    93,    94,     0,     0,     0,
       0,    96,     0,   170,     0,    98,     0,   608,     5,     6,
       7,     8,     9,    10,     0,     0,     0,   165,     0,     0,
      14,    15,     0,    16,     0,     0,     0,     0,    20,     0,
       0,     0,     0,     0,     0,     0,    27,     0,     0,     0,
       0,     0,    31,   166,   167,     0,   678,    36,     0,    37,
       0,     0,    39,     0,     0,     0,    41,    42,     0,     0,
      44,    45,     0,    46,    47,     0,    48,    49,     0,     0,
       0,     0,     0,    52,     0,    54,     0,    56,     0,     0,
       0,     0,    59,     0,     0,     0,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,   169,     0,    72,     0,
       0,    74,     0,     0,     0,    78,     0,     0,    80,     0,
       0,    82,     0,     0,     0,     0,     0,     0,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,     0,     0,    93,    94,     0,
       0,     0,     0,    96,     0,   170,     0,    98,     0,   171,
       5,     6,     7,     8,     9,    10,     0,     0,     0,   165,
       0,     0,    14,    15,     0,    16,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     0,     0,     0,    31,   166,   167,     0,   681,    36,
       0,    37,     0,     0,    39,     0,     0,     0,    41,    42,
       0,     0,    44,    45,     0,    46,    47,     0,    48,    49,
       0,     0,     0,     0,     0,    52,     0,    54,     0,    56,
       0,     0,     0,     0,    59,     0,     0,     0,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,   169,     0,
      72,     0,     0,    74,     0,     0,     0,    78,     0,     0,
      80,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,     0,     0,    93,
      94,     0,     0,     0,     0,    96,     0,   170,     0,    98,
       0,   171,     5,     6,     7,     8,     9,    10,     0,     0,
       0,   165,     0,     0,    14,    15,     0,    16,     0,     0,
       0,     0,    20,     0,     0,     0,     0,     0,     0,     0,
      27,     0,     0,     0,     0,     0,    31,   166,   167,     0,
     901,    36,     0,    37,     0,     0,    39,     0,     0,     0,
      41,    42,     0,     0,    44,    45,     0,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,    52,     0,    54,
       0,    56,     0,     0,     0,     0,    59,     0,     0,     0,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
     169,     0,    72,     0,     0,    74,     0,     0,     0,    78,
       0,     0,    80,     0,     0,    82,     0,     0,     0,     0,
       0,     0,     0,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,     0,
       0,    93,    94,     0,     0,     0,     0,    96,     0,   170,
       0,    98,     0,   171,     5,     6,     7,     8,     9,    10,
       0,     0,     0,   165,     0,     0,    14,    15,     0,    16,
       0,     0,     0,     0,    20,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,     0,     0,     0,    31,   166,
     167,     0,   902,    36,     0,    37,     0,     0,    39,     0,
       0,     0,    41,    42,     0,     0,    44,    45,     0,    46,
      47,     0,    48,    49,     0,     0,     0,     0,     0,    52,
       0,    54,     0,    56,     0,     0,     0,     0,    59,     0,
       0,     0,     0,     0,     0,     0,     0,    66,    67,    68,
      69,    70,   169,     0,    72,     0,     0,    74,     0,     0,
       0,    78,     0,     0,    80,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,     0,     0,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,     0,     0,    93,    94,     0,     0,     0,     0,    96,
       0,   170,     0,    98,     0,   171,     5,     6,     7,     8,
       9,    10,     0,     0,     0,   165,     0,     0,    14,    15,
       0,    16,     0,     0,     0,     0,    20,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     0,     0,     0,     0,
      31,   166,   167,     0,   904,    36,     0,    37,     0,     0,
      39,     0,     0,     0,    41,    42,     0,     0,    44,    45,
       0,    46,    47,     0,    48,    49,     0,     0,     0,     0,
       0,    52,     0,    54,     0,    56,     0,     0,     0,     0,
      59,     0,     0,     0,     0,     0,     0,     0,     0,    66,
      67,    68,    69,    70,   169,     0,    72,     0,     0,    74,
       0,     0,     0,    78,     0,     0,    80,     0,     0,    82,
       0,     0,     0,     0,     0,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,    90,     0,     0,
       0,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,     0,     0,    93,    94,     0,     0,     0,
       0,    96,     0,   170,     0,    98,     0,   171,     5,     6,
       7,     8,     9,    10,     0,     0,     0,   165,     0,     0,
      14,    15,     0,    16,     0,     0,     0,     0,    20,     0,
       0,     0,     0,     0,     0,     0,    27,     0,     0,     0,
       0,     0,    31,   166,   167,     0,   905,    36,     0,    37,
       0,     0,    39,     0,     0,     0,    41,    42,     0,     0,
      44,    45,     0,    46,    47,     0,    48,    49,     0,     0,
       0,     0,     0,    52,     0,    54,     0,    56,     0,     0,
       0,     0,    59,     0,     0,     0,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,   169,     0,    72,     0,
       0,    74,     0,     0,     0,    78,     0,     0,    80,     0,
       0,    82,     0,     0,     0,     0,     0,     0,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,     0,     0,    93,    94,     0,
       0,     0,     0,    96,     0,   170,     0,    98,     0,   171,
       5,     6,     7,     8,     9,    10,     0,     0,     0,   165,
       0,     0,    14,    15,     0,    16,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     0,     0,     0,    31,   166,   167,     0,   906,    36,
       0,    37,     0,     0,    39,     0,     0,     0,    41,    42,
       0,     0,    44,    45,     0,    46,    47,     0,    48,    49,
       0,     0,     0,     0,     0,    52,     0,    54,     0,    56,
       0,     0,     0,     0,    59,     0,     0,     0,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,   169,     0,
      72,     0,     0,    74,     0,     0,     0,    78,     0,     0,
      80,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,     0,     0,    93,
      94,     0,     0,     0,     0,    96,     0,   170,     0,    98,
       0,   171,     5,     6,     7,     8,     9,    10,     0,     0,
       0,   165,     0,     0,    14,    15,     0,    16,     0,     0,
       0,     0,    20,     0,     0,     0,     0,     0,     0,     0,
      27,     0,     0,     0,     0,     0,    31,   166,   167,     0,
     907,    36,     0,    37,     0,     0,    39,     0,     0,     0,
      41,    42,     0,     0,    44,    45,     0,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,    52,     0,    54,
       0,    56,     0,     0,     0,     0,    59,     0,     0,     0,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
     169,     0,    72,     0,     0,    74,     0,     0,     0,    78,
       0,     0,    80,     0,     0,    82,     0,     0,     0,     0,
       0,     0,     0,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,     0,
       0,    93,    94,     0,     0,     0,     0,    96,     0,   170,
       0,    98,     0,   171,     5,     6,     7,     8,     9,    10,
       0,     0,     0,   165,     0,     0,    14,    15,     0,    16,
       0,     0,     0,     0,    20,     0,     0,     0,     0,     0,
       0,     0,   604,     0,     0,     0,     0,     0,    31,   166,
     167,     0,   168,    36,     0,   605,     0,     0,    39,     0,
       0,     0,    41,    42,     0,     0,    44,    45,     0,    46,
      47,     0,    48,    49,     0,     0,     0,     0,     0,    52,
       0,    54,     0,    56,     0,     0,     0,     0,    59,     0,
       0,     0,     0,     0,     0,     0,     0,    66,   606,    68,
      69,    70,   607,     0,    72,     0,     0,    74,     0,     0,
       0,    78,     0,     0,    80,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,     0,     0,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,     0,     0,    93,    94,     0,     0,     0,     0,    96,
       0,   170,     0,    98,     0,   989,     5,     6,     7,     8,
       9,    10,     0,     0,     0,   165,     0,     0,    14,    15,
       0,    16,     0,     0,     0,     0,    20,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     0,     0,     0,     0,
      31,   166,   167,     0,   168,    36,     0,    37,     0,     0,
      39,     0,     0,     0,    41,    42,     0,     0,    44,    45,
       0,    46,    47,     0,    48,    49,     0,     0,     0,     0,
       0,    52,     0,    54,     0,    56,     0,     0,     0,     0,
      59,     0,     0,     0,     0,     0,     0,     0,     0,    66,
      67,    68,    69,    70,   169,     0,    72,     0,     0,    74,
       0,     0,     0,    78,     0,     0,    80,     0,     0,    82,
       0,     0,     0,     0,     0,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,    90,     0,     0,
       0,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,     0,     0,    93,    94,     0,     0,     0,
       0,    96,     0,     0,     0,    98,     0,   989,     5,     6,
       7,     8,     9,    10,     0,     0,     0,   165,     0,     0,
      14,    15,     0,    16,     0,     0,     0,     0,    20,     0,
       0,     0,     0,     0,     0,     0,    27,     0,     0,     0,
       0,     0,    31,   166,   167,     0,   168,    36,     0,    37,
       0,     0,    39,     0,     0,     0,    41,    42,     0,     0,
      44,    45,     0,    46,    47,     0,    48,    49,     0,     0,
       0,     0,     0,    52,     0,    54,     0,    56,     0,     0,
       0,     0,    59,     0,     0,     0,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,   169,     0,    72,     0,
       0,    74,     0,     0,     0,    78,     0,     0,    80,     0,
       0,    82,     0,     0,     0,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
       5,     6,     7,     8,     9,    10,  -493,     0,     0,   165,
       0,     0,    14,    15,    92,    16,     0,     0,    94,   366,
      20,     0,  -520,    96,  -520,   170,     0,    98,    27,   171,
       0,     0,     0,     0,    31,   166,   167,     0,   168,    36,
       0,    37,     0,     0,    39,     0,     0,     0,    41,    42,
       0,     0,    44,    45,     0,    46,    47,     0,    48,    49,
       0,     0,     0,     0,     0,    52,     0,    54,     0,    56,
       0,     0,     0,     0,    59,     0,     0,     0,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,   169,     0,
      72,     0,     0,    74,     0,     0,     0,    78,     0,     0,
      80,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,     0,  -393,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88,
       0,     0,     0,  -393,     0,     0,     0,  -393,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,     0,
       0,   256,   165,     0,     0,    14,    15,   170,    16,    98,
    -393,   922,     0,    20,     0,     0,     0,     0,     0,     0,
       0,    27,     0,     0,     0,     0,     0,    31,   166,   167,
       0,   168,    36,     0,    37,     0,     0,    39,     0,     0,
       0,    41,    42,  -375,     0,    44,    45,     0,    46,    47,
       0,    48,    49,     0,     0,     0,     0,     0,    52,     0,
      54,     0,    56,     0,     0,     0,     0,    59,     0,     0,
       0,     0,  -375,     0,     0,     0,    66,    67,    68,    69,
      70,   169,     0,    72,     0,  -375,    74,     0,     0,     0,
      78,     0,     0,    80,     0,     0,    82,     0,  -375,     0,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,     0,     0,     0,     0,     0,
       0,     0,    88,     5,     6,     7,     8,     9,    10,     0,
       0,     0,   165,     0,     0,    14,    15,     0,    16,     0,
       0,     0,     0,    20,   366,  -375,     0,  -520,     0,  -520,
    -375,    27,    98,     0,   989,     0,     0,    31,   166,   167,
       0,   168,    36,     0,    37,     0,     0,    39,     0,     0,
       0,    41,    42,     0,     0,    44,    45,     0,    46,    47,
       0,    48,    49,     0,     0,     0,     0,     0,    52,     0,
      54,     0,    56,     0,     0,     0,     0,    59,     0,     0,
       0,     0,     0,     0,     0,     0,    66,    67,    68,    69,
      70,   169,     0,    72,     0,     0,    74,     0,     0,     0,
      78,     0,     0,    80,     0,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    88,     5,     6,     7,     8,     9,    10,     0,
       0,     0,   165,     0,     0,    14,    15,     0,    16,     0,
       0,     0,     0,    20,     0,     0,     0,     0,     0,     0,
     170,    27,    98,     0,   171,     0,     0,    31,   166,   167,
       0,   168,    36,     0,    37,     0,     0,    39,     0,     0,
       0,    41,    42,     0,     0,    44,    45,     0,    46,    47,
       0,    48,    49,     0,     0,     0,     0,     0,    52,     0,
      54,     0,    56,     0,     0,     0,     0,    59,     0,     0,
       0,     0,     0,     0,     0,     0,    66,    67,    68,    69,
      70,   169,     0,    72,     0,     0,    74,     0,     0,     0,
      78,     0,     0,    80,     0,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    88,     5,     6,     7,     8,     9,    10,     0,
       0,     0,   165,     0,     0,    14,    15,     0,    16,     0,
       0,     0,     0,    20,     0,     0,     0,     0,     0,     0,
     170,    27,    98,     0,   608,     0,     0,    31,   166,   167,
       0,   168,    36,     0,    37,     0,     0,    39,     0,     0,
       0,    41,    42,     0,     0,    44,    45,     0,    46,    47,
       0,    48,    49,     0,     0,     0,     0,     0,    52,     0,
      54,     0,    56,     0,     0,     0,     0,    59,     0,     0,
       0,     0,     0,     0,     0,     0,    66,    67,    68,    69,
      70,   169,     0,    72,     0,   950,    74,     0,     0,     0,
      78,     0,   768,    80,     0,     0,    82,   212,   213,   770,
     214,     0,     0,     0,     0,   215,     0,     0,     0,     0,
       0,     0,     0,   216,     0,     0,     0,     0,     0,   773,
       0,     0,    88,     0,   218,     0,   219,     0,     0,   220,
       0,   776,     0,     0,     0,     0,     0,   221,     0,     0,
       0,     0,     0,   778,   223,     0,     0,     0,   322,     0,
     224,     0,    98,     0,   171,   323,     0,     0,     0,   225,
       0,     0,     0,     0,     0,     0,     0,   324,   226,   227,
       0,   228,     0,   229,     0,   951,     0,     0,   783,     0,
       0,     0,   232,     0,     0,   233,     0,     0,   234,     0,
       0,     0,     0,     0,     0,     0,     0,   351,   352,   353,
     354,   355,   356,     0,     0,   359,   360,   361,   362,     0,
     364,   365,   786,   787,   788,   789,   790,   325,     0,   791,
       0,   326,     0,   792,   793,   794,   795,   796,   797,   798,
     799,   800,   801,   802,     0,   803,   322,     0,   804,   805,
     806,   807,     0,   323,     0,     0,     0,     0,     0,     0,
       0,     0,   327,     0,     0,   324,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   328,   329,
       0,   330,   331,   332,     0,   333,   334,   335,     0,   336,
     337,   338,   339,   340,     0,   341,   342,   343,   344,   345,
     346,   347,     0,   322,   348,   349,   350,     0,     0,     0,
     323,     0,     0,   985,     0,   325,     0,     0,     0,   326,
       0,     0,   324,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   322,     0,     0,     0,     0,     0,
     327,   323,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   324,     0,     0,   328,   329,     0,   330,
     331,   332,   325,   333,   334,   335,   326,   336,   337,   338,
     339,   340,     0,   341,   342,   343,   344,   345,   346,   347,
       0,     0,   348,   349,   350,     0,     0,     0,     0,     0,
       0,  1052,     0,     0,     0,     0,     0,   327,     0,     0,
       0,     0,     0,   325,     0,     0,     0,   326,     0,     0,
       0,     0,     0,   328,   329,     0,   330,   331,   332,     0,
     333,   334,   335,     0,   336,   337,   338,   339,   340,     0,
     341,   342,   343,   344,   345,   346,   347,   322,   327,   348,
     349,   350,     0,     0,   323,     0,   629,     0,     0,     0,
       0,     0,     0,     0,   328,   329,   324,   330,   331,   332,
       0,   333,   334,   335,     0,   336,   337,   338,   339,   340,
       0,   341,   342,   343,   344,   345,   346,   347,     0,     0,
     348,   349,   350,     0,     0,     0,     0,   949,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   325,     0,     0,     0,
     326,     0,     0,   322,     0,     0,     0,     0,     0,   415,
     323,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   324,     0,     0,     0,     0,     0,     0,     0,
       0,   327,   351,   352,   353,   354,   355,   356,     0,     0,
     359,   360,   361,   362,     0,   364,   365,   328,   329,     0,
     330,   331,   332,     0,   333,   334,   335,     0,   336,   337,
     338,   339,   340,     0,   341,   342,   343,   344,   345,   346,
     347,     0,   325,   348,   349,   350,   326,   379,     0,   322,
       0,     0,     0,     0,     0,   833,   323,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   324,     0,
       0,     0,     0,     0,     0,     0,     0,   327,   351,   352,
     353,   354,   355,   356,     0,     0,   359,   360,   361,   362,
       0,   364,   365,   328,   329,     0,   330,   331,   332,     0,
     333,   334,   335,     0,   336,   337,   338,   339,   340,     0,
     341,   342,   343,   344,   345,   346,   347,     0,   325,   348,
     349,   350,   326,   379,     0,   322,     0,     0,     0,     0,
       0,   840,   323,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   324,     0,     0,     0,     0,     0,
       0,     0,     0,   327,   351,   352,   353,   354,   355,   356,
       0,     0,   359,   360,   361,   362,     0,   364,   365,   328,
     329,     0,   330,   331,   332,     0,   333,   334,   335,     0,
     336,   337,   338,   339,   340,     0,   341,   342,   343,   344,
     345,   346,   347,     0,   325,   348,   349,   350,   326,   379,
       0,   322,     0,     0,     0,     0,     0,   962,   323,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     324,     0,     0,     0,     0,     0,     0,     0,     0,   327,
     351,   352,   353,   354,   355,   356,     0,     0,   359,   360,
     361,   362,     0,   364,   365,   328,   329,     0,   330,   331,
     332,     0,   333,   334,   335,     0,   336,   337,   338,   339,
     340,     0,   341,   342,   343,   344,   345,   346,   347,     0,
     325,   348,   349,   350,   326,   379,     0,   322,     0,     0,
       0,     0,     0,   963,   323,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   324,     0,     0,     0,
       0,     0,     0,     0,     0,   327,   351,   352,   353,   354,
     355,   356,     0,     0,   359,   360,   361,   362,     0,   364,
     365,   328,   329,     0,   330,   331,   332,     0,   333,   334,
     335,     0,   336,   337,   338,   339,   340,     0,   341,   342,
     343,   344,   345,   346,   347,     0,   325,   348,   349,   350,
     326,   379,     0,   322,     0,     0,     0,     0,     0,   964,
     323,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   324,     0,     0,     0,     0,     0,     0,     0,
       0,   327,   351,   352,   353,   354,   355,   356,     0,     0,
     359,   360,   361,   362,     0,   364,   365,   328,   329,     0,
     330,   331,   332,     0,   333,   334,   335,     0,   336,   337,
     338,   339,   340,     0,   341,   342,   343,   344,   345,   346,
     347,     0,   325,   348,   349,   350,   326,   379,     0,   322,
       0,     0,     0,     0,     0,   965,   323,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   324,     0,
       0,     0,     0,     0,     0,     0,     0,   327,   351,   352,
     353,   354,   355,   356,     0,     0,   359,   360,   361,   362,
       0,   364,   365,   328,   329,     0,   330,   331,   332,     0,
     333,   334,   335,     0,   336,   337,   338,   339,   340,     0,
     341,   342,   343,   344,   345,   346,   347,     0,   325,   348,
     349,   350,   326,   379,     0,   322,     0,     0,     0,     0,
       0,   987,   323,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   324,     0,     0,     0,     0,     0,
       0,     0,     0,   327,   351,   352,   353,   354,   355,   356,
       0,     0,   359,   360,   361,   362,     0,   364,   365,   328,
     329,     0,   330,   331,   332,     0,   333,   334,   335,     0,
     336,   337,   338,   339,   340,     0,   341,   342,   343,   344,
     345,   346,   347,     0,   325,   348,   349,   350,   326,   379,
       0,     0,     0,     0,     0,     0,     0,   988,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   327,
     351,   352,   353,   354,   355,   356,     0,     0,   359,   360,
     361,   362,     0,   364,   365,   328,   329,     0,   330,   331,
     332,     0,   333,   334,   335,     0,   336,   337,   338,   339,
     340,     0,   341,   342,   343,   344,   345,   346,   347,   322,
       0,   348,   349,   350,     0,   379,   323,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   324,   407,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   322,   408,     0,     0,     0,     0,     0,   323,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     324,   401,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   402,     0,     0,     0,   325,     0,
       0,     0,   326,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   322,     0,
       0,     0,     0,     0,     0,   323,     0,     0,     0,   404,
     325,     0,     0,   327,   326,     0,     0,   324,   707,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   328,
     329,     0,   330,   331,   332,     0,   333,   334,   335,     0,
     336,   337,   338,   339,   340,   327,   341,   342,   343,   344,
     345,   346,   347,     0,     0,   348,   349,   350,     0,   379,
       0,   328,   329,     0,   330,   331,   332,   325,   333,   334,
     335,   326,   336,   337,   338,   339,   340,     0,   341,   342,
     343,   344,   345,   346,   347,   322,     0,   348,   349,   350,
       0,   379,   323,     0,     0,     0,     0,     0,   404,     0,
       0,     0,   327,     0,   324,   242,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   328,   329,
       0,   330,   331,   332,     0,   333,   334,   335,     0,   336,
     337,   338,   339,   340,     0,   341,   342,   343,   344,   345,
     346,   347,   322,     0,   348,   349,   350,     0,   379,   323,
       0,     0,     0,     0,   325,     0,     0,     0,   326,     0,
       0,   324,   699,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   322,     0,     0,     0,     0,     0,
       0,   323,     0,     0,     0,     0,     0,     0,     0,   327,
       0,     0,     0,   324,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   328,   329,     0,   330,   331,
     332,   325,   333,   334,   335,   326,   336,   337,   338,   339,
     340,     0,   341,   342,   343,   344,   345,   346,   347,     0,
       0,   348,   349,   350,     0,   379,     0,     0,     0,     0,
       0,     0,     0,   325,     0,     0,   327,   326,     0,     0,
       0,     0,     0,     0,     0,     0,   717,     0,     0,     0,
       0,     0,   328,   329,     0,   330,   331,   332,     0,   333,
     334,   335,     0,   336,   337,   338,   339,   340,   327,   341,
     342,   343,   344,   345,   346,   347,     0,     0,   348,   349,
     350,     0,   379,     0,   328,   329,     0,   330,   331,   332,
       0,   333,   334,   335,     0,   336,   337,   338,   339,   340,
       0,   341,   342,   343,   344,   345,   346,   347,   322,     0,
     348,   349,   350,     0,   379,   323,     0,   211,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   324,     0,   212,
     213,     0,   214,     0,     0,     0,     0,   215,     0,     0,
     322,     0,     0,     0,     0,   216,     0,   323,     0,     0,
       0,   217,     0,     0,     0,     0,   218,     0,   219,   324,
       0,   220,     0,     0,   412,     0,     0,     0,     0,   221,
       0,     0,     0,     0,     0,   222,   223,   325,     0,     0,
       0,   326,   224,     0,     0,     0,     0,     0,     0,     0,
       0,   225,     0,     0,   413,     0,     0,   322,     0,     0,
     226,   227,     0,   228,   323,   229,     0,   230,     0,   325,
     231,     0,   327,   326,   232,     0,   324,   233,     0,     0,
     234,     0,     0,     0,     0,     0,     0,     0,   328,   329,
     381,   330,   331,   332,     0,   333,   334,   335,     0,   336,
     337,   338,   339,   340,   327,   341,   342,   343,   344,   345,
     346,   347,     0,     0,   348,   349,   350,     0,   442,     0,
     328,   329,     0,   330,   331,   332,   325,   333,   334,   335,
     326,   336,   337,   338,   339,   340,     0,   341,   342,   343,
     344,   345,   346,   347,   322,   414,   348,   349,   350,     0,
       0,   323,     0,     0,     0,     0,     0,   160,     0,     0,
       0,   327,     0,   324,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   328,   329,     0,
     330,   331,   332,     0,   333,   334,   335,     0,   336,   337,
     338,   339,   340,     0,   341,   342,   343,   344,   345,   346,
     347,   322,     0,   348,   349,   350,     0,     0,   323,     0,
       0,     0,     0,   325,     0,     0,     0,   326,     0,     0,
     324,   544,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   322,   545,     0,     0,     0,     0,     0,
     323,     0,     0,     0,     0,     0,     0,     0,   327,     0,
       0,     0,   324,   546,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   328,   329,   547,   330,   331,   332,
     325,   333,   334,   335,   326,   336,   337,   338,   339,   340,
       0,   341,   342,   343,   344,   345,   346,   347,     0,   446,
     348,   349,   350,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   325,     0,     0,   327,   326,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   328,   329,     0,   330,   331,   332,     0,   333,   334,
     335,     0,   336,   337,   338,   339,   340,   327,   341,   342,
     343,   344,   345,   346,   347,     0,     0,   348,   349,   350,
       0,     0,     0,   328,   329,     0,   330,   331,   332,     0,
     333,   334,   335,     0,   336,   337,   338,   339,   340,     0,
     341,   342,   343,   344,   345,   346,   347,   322,     0,   348,
     349,   350,     0,     0,   323,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   324,     0,     0,     0,
       0,   649,     0,     0,     0,     0,     0,     0,     0,   322,
       0,     0,     0,     0,     0,     0,   323,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   324,     0,
       0,   650,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   325,     0,     0,     0,
     326,     0,     0,     0,     0,     0,     0,     0,   322,     0,
       0,     0,     0,     0,     0,   323,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   324,   325,     0,
       0,   327,   326,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   328,   329,     0,
     330,   331,   332,     0,   333,   334,   335,     0,   336,   337,
     338,   339,   340,   327,   341,   342,   343,   344,   345,   346,
     347,     0,     0,   348,   349,   350,     0,   325,     0,   328,
     329,   326,   330,   331,   332,     0,   333,   334,   335,     0,
     336,   337,   338,   339,   340,     0,   341,   342,   343,   344,
     345,   346,   347,   322,   448,   348,   349,   350,     0,     0,
     323,     0,   327,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   324,     0,     0,     0,     0,     0,   328,   329,
       0,   330,   331,   332,     0,   333,   334,   335,     0,   336,
     337,   338,   339,   340,     0,   341,   342,   343,   344,   345,
     346,   347,   322,   450,   348,   349,   350,     0,     0,   323,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   324,   325,     0,     0,     0,   326,     0,     0,     0,
       0,     0,     0,     0,   322,     0,     0,     0,     0,     0,
       0,   323,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   324,     0,     0,     0,   327,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   325,     0,   328,   329,   326,   330,   331,   332,     0,
     333,   334,   335,     0,   336,   337,   338,   339,   340,     0,
     341,   342,   343,   344,   345,   346,   347,     0,   455,   348,
     349,   350,     0,   325,     0,   472,   327,   326,     0,     0,
       0,     0,     0,     0,     0,     0,   548,     0,     0,     0,
       0,     0,   328,   329,     0,   330,   331,   332,     0,   333,
     334,   335,     0,   336,   337,   338,   339,   340,   327,   341,
     342,   343,   344,   345,   346,   347,     0,     0,   348,   349,
     350,     0,     0,     0,   328,   329,     0,   330,   331,   332,
       0,   333,   334,   335,     0,   336,   337,   338,   339,   340,
       0,   341,   342,   343,   344,   345,   346,   347,   322,     0,
     348,   349,   350,     0,     0,   323,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   324,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   322,     0,     0,     0,     0,     0,     0,
     323,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   324,     0,     0,     0,     0,   325,     0,     0,
       0,   326,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   322,     0,     0,     0,     0,     0,
       0,   323,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   327,   324,     0,     0,     0,     0,     0,     0,
       0,     0,   325,     0,     0,     0,   326,     0,   328,   329,
       0,   330,   331,   332,     0,   333,   334,   335,     0,   336,
     337,   338,   339,   340,  -494,   341,   342,   343,   344,   345,
     346,   347,     0,   160,   348,   349,   350,   327,     0,     0,
       0,     0,     0,   325,     0,     0,     0,   326,     0,     0,
       0,     0,     0,   328,   329,     0,   330,   331,   332,     0,
     333,   334,   335,     0,   336,   337,   338,   339,   340,     0,
     341,   342,   343,   344,   345,   346,   347,     0,   327,   348,
     349,   350,     0,     0,     0,   322,   712,     0,     0,     0,
       0,     0,   323,     0,   328,   329,     0,   330,   331,   332,
       0,   333,   334,   335,   324,   336,   337,   338,   339,   340,
       0,   341,   342,   343,   344,   345,   346,   347,     0,   688,
     348,   349,   350,     0,     0,   322,     0,     0,     0,     0,
       0,     0,   323,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   324,     0,     0,   715,     0,     0,
       0,     0,     0,     0,   325,     0,     0,     0,   326,     0,
       0,     0,     0,     0,     0,     0,   322,     0,     0,     0,
       0,     0,     0,   323,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   324,     0,     0,     0,   327,
       0,     0,     0,     0,   325,     0,     0,     0,   326,     0,
       0,     0,     0,     0,     0,   328,   329,     0,   330,   331,
     332,     0,   333,   334,   335,     0,   336,   337,   338,   339,
     340,     0,   341,   342,   343,   344,   345,   346,   347,   327,
       0,   348,   349,   350,     0,   325,     0,     0,     0,   326,
       0,     0,     0,     0,     0,   328,   329,     0,   330,   331,
     332,     0,   333,   334,   335,     0,   336,   337,   338,   339,
     340,     0,   341,   342,   343,   344,   345,   346,   347,   755,
     327,   348,   349,   350,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   328,   329,     0,   330,
     331,   332,     0,   333,   334,   335,     0,   336,   337,   338,
     339,   340,     0,   341,   342,   343,   344,   345,   346,   347,
     322,     0,   348,   349,   350,     0,     0,   323,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   324,
     823,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   322,     0,     0,     0,     0,     0,     0,   323,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   324,   826,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   325,
       0,     0,     0,   326,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   325,     0,     0,   327,   326,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     328,   329,     0,   330,   331,   332,     0,   333,   334,   335,
       0,   336,   337,   338,   339,   340,   327,   341,   342,   343,
     344,   345,   346,   347,     0,     0,   348,   349,   350,     0,
       0,     0,   328,   329,     0,   330,   331,   332,     0,   333,
     334,   335,     0,   336,   337,   338,   339,   340,     0,   341,
     342,   343,   344,   345,   346,   347,   322,     0,   348,   349,
     350,     0,     0,   323,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   324,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   322,     0,
       0,     0,     0,     0,     0,   323,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   324,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   325,     0,     0,     0,   326,
       0,     0,     0,     0,     0,     0,     0,     0,   900,     0,
       0,     0,     0,     0,     0,   322,   917,     0,     0,     0,
       0,     0,   323,     0,     0,     0,     0,   325,     0,     0,
     327,   326,     0,     0,   324,     0,     0,     0,     0,     0,
     903,     0,     0,     0,     0,     0,   328,   329,     0,   330,
     331,   332,     0,   333,   334,   335,     0,   336,   337,   338,
     339,   340,   327,   341,   342,   343,   344,   345,   346,   347,
       0,     0,   348,   349,   350,     0,     0,     0,   328,   329,
       0,   330,   331,   332,   325,   333,   334,   335,   326,   336,
     337,   338,   339,   340,     0,   341,   342,   343,   344,   345,
     346,   347,   322,     0,   348,   349,   350,     0,     0,   323,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   327,
       0,   324,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   328,   329,     0,   330,   331,
     332,     0,   333,   334,   335,     0,   336,   337,   338,   339,
     340,     0,   341,   342,   343,   344,   345,   346,   347,     0,
       0,   348,   349,   350,     0,     0,     0,     0,     0,     0,
       0,   325,     0,     0,     0,   326,     0,     0,   322,     0,
       0,     0,     0,     0,   998,   323,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   324,     0,     0,
       0,     0,     0,     0,     0,     0,   327,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   328,   329,     0,   330,   331,   332,     0,   333,
     334,   335,     0,   336,   337,   338,   339,   340,     0,   341,
     342,   343,   344,   345,   346,   347,     0,   325,   348,   349,
     350,   326,     0,     0,   322,     0,     0,     0,     0,     0,
     999,   323,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   324,     0,     0,     0,     0,     0,     0,
       0,     0,   327,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   328,   329,
       0,   330,   331,   332,     0,   333,   334,   335,     0,   336,
     337,   338,   339,   340,     0,   341,   342,   343,   344,   345,
     346,   347,     0,   325,   348,   349,   350,   326,     0,     0,
     322,     0,     0,     0,     0,     0,  1000,   323,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   324,
       0,     0,     0,     0,     0,     0,     0,     0,   327,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   328,   329,     0,   330,   331,   332,
       0,   333,   334,   335,     0,   336,   337,   338,   339,   340,
       0,   341,   342,   343,   344,   345,   346,   347,     0,   325,
     348,   349,   350,   326,     0,     0,   322,     0,     0,     0,
       0,     0,  1001,   323,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   324,     0,     0,     0,     0,
       0,     0,     0,     0,   327,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     328,   329,     0,   330,   331,   332,     0,   333,   334,   335,
       0,   336,   337,   338,   339,   340,     0,   341,   342,   343,
     344,   345,   346,   347,     0,   325,   348,   349,   350,   326,
       0,     0,   322,     0,     0,     0,     0,     0,  1002,   323,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   324,     0,     0,     0,     0,     0,     0,     0,     0,
     327,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   328,   329,     0,   330,
     331,   332,     0,   333,   334,   335,     0,   336,   337,   338,
     339,   340,     0,   341,   342,   343,   344,   345,   346,   347,
       0,   325,   348,   349,   350,   326,     0,     0,   322,     0,
       0,     0,     0,     0,  1003,   323,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   324,     0,     0,
       0,     0,     0,     0,     0,     0,   327,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1025,   328,   329,     0,   330,   331,   332,     0,   333,
     334,   335,     0,   336,   337,   338,   339,   340,     0,   341,
     342,   343,   344,   345,   346,   347,     0,   325,   348,   349,
     350,   326,     0,     0,   322,     0,     0,     0,     0,     0,
       0,   323,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   324,     0,     0,     0,     0,     0,     0,
       0,     0,   327,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   328,   329,
       0,   330,   331,   332,     0,   333,   334,   335,     0,   336,
     337,   338,   339,   340,     0,   341,   342,   343,   344,   345,
     346,   347,     0,   325,   348,   349,   350,   326,     0,     0,
     322,     0,     0,     0,     0,     0,     0,   323,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   324,
       0,     0,     0,     0,     0,     0,     0,     0,   327,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   328,   329,     0,   330,   331,   332,
       0,   333,   334,   335,     0,   336,   337,   338,   339,   340,
     324,   341,   342,   343,   344,   345,   346,   347,     0,   676,
     348,   349,   350,   326,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     324,     0,     0,     0,   327,     0,     0,     0,     0,     0,
     325,     0,     0,     0,   326,     0,     0,     0,     0,     0,
     328,   329,     0,   330,   331,   332,     0,   333,   334,   335,
       0,   336,   337,   338,   339,   340,     0,   341,   342,   343,
     344,   345,   346,   347,     0,   327,   348,   349,   350,     0,
     325,     0,     0,     0,   326,     0,     0,     0,     0,     0,
       0,   328,   329,     0,   330,   331,   332,     0,   333,   334,
     335,     0,   336,   337,   338,   339,     0,     0,   341,   342,
     343,   344,   345,   346,   347,   327,     0,   348,   349,   350,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   328,   329,     0,   330,   331,   332,     0,   333,   334,
     335,     0,   336,   337,   338,   339,     0,     0,   341,   342,
     343,   344,   345,   653,   347,   211,     0,   348,   349,   350,
       0,     0,     0,     0,     0,     0,     0,   212,   213,     0,
     214,     0,     0,     0,     0,   215,     0,     0,     0,     0,
       0,     0,     0,   216,     0,     0,     0,     0,     0,   217,
       0,     0,     0,     0,   218,     0,   219,     0,     0,   220,
       0,     0,     0,     0,     0,     0,     0,   221,     0,     0,
       0,     0,     0,   222,   223,     0,     0,     0,     0,     0,
     224,     0,     0,     0,     0,     0,     0,     0,     0,   225,
       0,     0,     0,     0,     0,     0,     0,     0,   226,   227,
       0,   228,     0,   229,     0,   230,     0,     0,   231,     0,
       0,     0,   232,     0,     0,   233,     0,     0,   234
};

static const yytype_int16 yycheck[] =
{
      11,   570,   145,   420,    15,    57,    58,   372,    19,    18,
     204,     2,   183,   451,    25,   132,    29,    21,    29,    30,
     413,    32,    33,    34,    35,   196,   759,   662,   733,     1,
     853,   191,    43,     1,    45,    46,   932,    82,   110,    50,
     423,    52,     1,    54,   813,   814,   110,    40,    30,     0,
     210,    62,    63,    64,    65,    66,    67,    62,   210,    30,
      71,   603,    73,   970,    75,    76,    30,   184,    43,    80,
       1,   108,    83,    84,   428,    86,   136,    88,    43,     3,
      91,    92,    30,    94,    77,    53,    97,    98,    99,  1015,
      30,    53,   252,   165,    99,   130,     3,   451,   921,   136,
     252,   165,   155,   138,   673,   165,    65,   110,  1015,   303,
     304,   271,    48,   818,    82,   160,   136,    43,    43,   271,
       1,    43,    53,     3,    25,   115,  1052,    95,   110,    43,
      32,    33,   125,   675,   127,   278,  1032,   856,    74,   110,
     108,   161,    43,   115,    98,    46,   108,    80,   107,    20,
     140,    82,   857,   886,   165,   166,   167,   168,   169,   170,
     171,   136,    43,   135,   136,    66,   171,   135,    69,    93,
      71,   136,   136,   182,   334,    82,   909,   108,   160,    80,
     191,    65,    29,   952,   953,   110,    93,   155,   730,   160,
     183,   163,   160,   206,   198,   206,   160,    99,    99,   210,
     165,   205,   161,   196,   135,   570,   199,    78,   368,   369,
     136,   136,   160,   162,   136,   920,   368,   369,    63,   602,
     160,    20,   136,   107,   162,   136,  1030,   946,    43,   160,
       7,   102,    79,   162,   115,   136,    83,   191,    43,   165,
     165,   252,   253,   165,  1048,   238,   115,    53,    90,   260,
     261,   165,   163,    98,   135,   136,   210,   650,   136,   136,
     271,   896,   163,   256,   969,    80,   136,   136,   162,   838,
      82,   140,   136,   136,   155,    80,    82,   161,   136,    78,
     397,   136,   136,   130,   444,   163,   163,   298,   135,    95,
      75,   138,   444,   163,   163,   142,    25,   155,   252,   163,
     163,   312,   108,   102,   295,   722,   161,   312,   673,   163,
     321,   322,   323,   324,   325,   326,   327,   271,   329,   330,
     331,   332,   333,   136,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
      69,   724,   759,   155,   136,   104,   357,   358,   160,   155,
     163,    80,   363,    53,   160,   366,   367,   368,   369,   370,
     371,   372,   160,    53,   115,    25,    25,    25,   136,    79,
     381,   163,   155,    83,   136,   386,   105,   388,   130,   136,
     574,   575,    82,   154,   162,   136,   138,   155,   399,   140,
     401,   402,    82,   155,   399,    95,   407,   408,   155,   155,
     560,   412,   413,   396,   415,    95,   417,   411,   108,    69,
      69,    69,   163,    43,   368,   369,   155,   136,   108,   430,
      80,    80,    80,   325,   326,   863,   437,   162,    79,   164,
     423,   135,    83,   444,   138,    65,   155,   146,   142,    99,
      99,    99,   636,   637,   136,    75,    76,   105,   459,   155,
     976,   462,   115,   464,   155,   155,   627,   468,   469,   470,
     160,   472,   473,   155,   155,   155,   155,   155,   370,   371,
     160,   482,   161,   838,   891,    75,    76,   482,   141,   381,
     143,   144,   136,   437,   147,   148,   479,   478,     3,   155,
     444,   484,   909,  1019,  1020,  1021,  1022,  1023,  1024,   138,
     402,   155,   856,    18,   160,   459,   408,   155,   462,   863,
     464,   109,   357,   358,   155,   469,    31,   155,   363,   662,
      65,   366,   367,   155,   162,   162,   164,   164,   162,   161,
     164,   162,   115,   544,   545,   546,   547,   548,   549,   550,
      55,   162,   551,   552,   162,   162,   164,   558,   155,   560,
     462,   181,   464,   564,     7,   566,    57,   135,   160,   570,
     155,   572,   115,   136,   163,   155,   468,    43,   162,    32,
     163,   201,   202,   203,   204,    43,   136,   163,    93,   209,
     115,   163,   163,    19,    99,    53,   136,   162,   165,   165,
     160,   155,   946,   155,   155,   606,   607,   608,   155,   155,
     163,   612,   136,   608,   558,   598,   560,   165,   155,   602,
      32,   155,   155,   161,    82,   245,   970,   462,   248,   464,
       2,   163,   163,   136,   161,    43,   115,   163,    80,    11,
     623,   985,    30,    30,   627,    53,   165,   267,   649,   650,
     108,   160,    24,   545,    26,   547,    32,   115,   135,    80,
     135,   165,   155,   165,   165,   285,   201,   202,   203,   204,
     155,  1015,   673,   161,    82,   676,   677,   678,   136,   662,
     681,   162,   138,   138,   138,   130,  1030,   138,   138,   138,
      29,   130,   138,   163,   138,   130,   697,   155,   699,    71,
     108,   138,   160,   704,  1048,   163,   707,   115,  1052,   710,
     245,   712,   130,   248,   715,   138,   138,   130,   138,    32,
      95,   161,   163,   558,   130,    97,   130,   165,   136,   101,
     309,   136,   267,   650,    23,   279,   649,   744,   721,   740,
      79,   724,   562,    29,    83,   740,   831,   155,   762,   750,
     285,   752,   160,   896,   755,   163,   891,   595,   722,   765,
     761,   744,   382,   896,   197,  1032,   969,   994,  1025,  1018,
      34,   431,    -1,    43,   560,    -1,    -1,   612,    -1,   762,
      -1,    -1,    -1,    53,   676,   677,   406,    -1,    -1,   161,
     410,   130,   131,    79,   133,   134,   135,    83,   137,   138,
     139,    -1,    -1,   142,    -1,   788,    -1,   808,    -1,    -1,
     149,   150,    82,    25,   153,    -1,    -1,   156,   157,   158,
      -1,   822,   823,    -1,   825,   826,   827,   828,    -1,    -1,
      29,    43,   833,   834,    46,   836,    -1,   838,   108,   840,
     841,   883,   884,   844,   130,   115,    -1,   382,    -1,   135,
      -1,   137,   138,    -1,    66,    -1,   142,    69,    -1,    71,
      -1,   862,   863,   235,   150,    -1,   136,   868,    80,   870,
     242,   406,   158,   874,    -1,   410,    -1,    -1,    -1,    -1,
      79,   882,    -1,    -1,    83,   155,    -1,    99,    -1,    -1,
     160,    -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,   900,
     901,   902,   903,   904,   905,   906,   907,    -1,    -1,    -1,
      -1,    -1,   856,   896,    -1,    -1,   917,    -1,    -1,    -1,
      -1,   922,    -1,   295,    -1,    -1,   927,   922,    -1,    -1,
     931,   130,   131,    -1,   133,   134,   135,   309,   137,   138,
      -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,   568,   569,
      -1,   150,    -1,    -1,   574,   575,    -1,   156,   157,   158,
      -1,   962,   963,   964,   965,    -1,   586,    -1,    -1,     2,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,    -1,
      -1,    -1,    -1,   927,   985,    -1,   987,   988,   989,    -1,
      -1,    24,    -1,    26,   989,    -1,     2,   998,   999,  1000,
    1001,  1002,  1003,   623,    -1,    11,    -1,   379,    -1,    29,
      -1,    -1,    -1,  1014,  1015,    -1,  1017,    -1,    24,    -1,
      26,    -1,    -1,    -1,    -1,    -1,   970,    -1,    -1,   401,
      -1,    -1,    -1,   568,   569,   407,    -1,    -1,    71,   574,
     575,    -1,    -1,   415,    -1,    -1,    -1,  1048,    -1,    -1,
      -1,  1052,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,
      -1,    -1,    -1,    83,    97,    71,   686,   687,   101,    75,
      76,  1015,    -1,    -1,   694,    -1,   696,    -1,    -1,    -1,
      -1,    -1,    -1,   703,    -1,    -1,   706,    -1,    -1,   709,
      -1,    97,    -1,    -1,   466,   101,    -1,    -1,   470,    -1,
       1,    -1,    -1,    -1,    -1,    -1,   478,    -1,  1052,    -1,
     130,   131,    -1,   133,   134,   135,    -1,   137,   138,    20,
      -1,    -1,   142,    24,    25,    -1,    -1,   747,   161,   149,
     150,    -1,    33,   153,    35,    36,   156,   157,   158,    40,
      -1,    -1,    -1,    29,    45,    -1,    -1,    48,    -1,    -1,
      -1,   686,   687,    -1,    -1,   161,    -1,    -1,     2,   694,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    11,    69,   541,
      71,   706,    73,    74,   709,    76,    -1,    78,    -1,    80,
      24,    -1,    26,    -1,    -1,    -1,    -1,    25,    -1,    -1,
      -1,     3,    -1,    79,    -1,    -1,    -1,    83,    99,    -1,
      -1,   102,   235,    15,   105,    43,    18,    -1,    46,   242,
      -1,    23,    -1,   585,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    66,   235,
      42,    69,    -1,    71,    -1,    47,   242,    -1,    -1,    -1,
      -1,    -1,    80,    55,   130,   131,   866,    -1,   134,   135,
      62,   137,   138,    97,   155,    -1,   142,   101,    -1,    -1,
     161,    99,   295,   635,   150,    77,    -1,    -1,    -1,   641,
     156,   157,   158,    -1,    -1,    -1,   309,    89,    -1,    -1,
      -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,   100,   295,
     662,   911,   912,    -1,   106,   915,   916,    -1,    -1,    -1,
      -1,    -1,    29,   309,   676,   677,    -1,    -1,    -1,    -1,
      -1,    -1,   932,    -1,    -1,     1,    -1,   161,   938,    -1,
     940,    -1,   942,    -1,    -1,   697,    -1,   699,    -1,    -1,
      -1,   866,   704,    -1,    20,   707,    -1,    -1,    24,    25,
      -1,    -1,   714,    -1,    -1,   717,   379,    33,    -1,    35,
      36,    -1,    79,    -1,    40,    -1,    83,    -1,    -1,    45,
      -1,    -1,    48,    -1,    -1,    -1,    -1,   739,   401,    -1,
      -1,    -1,    -1,   379,   407,    -1,    -1,    -1,   750,    -1,
     752,    67,   415,    69,    -1,    71,    -1,    73,    74,    -1,
      76,   235,    78,    -1,    80,   401,    -1,    -1,   242,    -1,
      -1,   407,    -1,   130,   131,    -1,    -1,    -1,   135,   415,
     137,   138,  1032,    99,    -1,   142,   102,    -1,    -1,   105,
      -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,   156,
     157,   158,    -1,   466,    -1,    -1,    -1,   470,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   478,    -1,    -1,    -1,    -1,
      -1,   295,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     466,   833,    -1,    -1,   470,   309,    20,    -1,   840,   155,
      24,    25,   478,    -1,    -1,   161,    -1,    -1,    -1,    33,
     852,    35,    36,    -1,     3,    -1,    40,    -1,    -1,    -1,
      -1,    45,   864,    -1,    -1,    -1,    15,    16,    -1,    18,
      -1,   873,    -1,    -1,    23,   877,    -1,    -1,    -1,    -1,
      -1,    29,    31,    67,    -1,    69,    -1,    71,    37,    73,
      -1,    -1,    76,    42,    78,    44,    80,    -1,    47,    -1,
      -1,    -1,    -1,    -1,    -1,   379,    55,    -1,    -1,    -1,
      -1,    -1,    61,    62,    -1,    99,   918,    -1,   102,    68,
      -1,   105,   585,    -1,    -1,    -1,    -1,   401,    77,    -1,
      -1,    79,    -1,   407,    -1,    83,    -1,    86,    87,    -1,
      89,   415,    91,     2,    93,    -1,    -1,    96,    -1,   585,
      -1,   100,    11,    -1,   103,    -1,    -1,   106,    24,    25,
     962,   963,   964,   965,    -1,    24,    -1,    26,    -1,    35,
      36,   155,   635,    -1,    -1,    -1,    -1,   161,   641,    45,
      -1,    -1,   130,    -1,    -1,   987,   988,   135,    -1,   137,
     138,    -1,   466,    -1,   142,    -1,   470,    -1,    -1,   635,
      -1,    67,   150,    69,   478,   641,    -1,    -1,   156,   157,
     158,   160,    71,   162,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   697,    -1,   699,    -1,    97,   105,
       2,   704,   101,    -1,   707,    -1,    -1,    -1,    -1,    11,
      -1,   714,    -1,    -1,   717,    -1,    -1,    -1,    -1,    -1,
       3,   697,    24,   699,    26,    -1,    -1,    -1,   704,    -1,
      -1,   707,    15,    16,    -1,    18,   739,    -1,   714,    -1,
      23,   717,    -1,    -1,    -1,    -1,    -1,   750,    31,   752,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    42,
      -1,    44,   161,   739,    47,    -1,    -1,    -1,    -1,    71,
      -1,   585,    55,    -1,   750,    -1,   752,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    97,    -1,    -1,    -1,   101,
      -1,    -1,    -1,    86,    87,    -1,    89,    -1,    91,    -1,
      93,    -1,    -1,    96,    -1,    -1,    -1,   100,   101,    -1,
     103,   635,    -1,   106,    -1,    -1,    -1,   641,    -1,    -1,
     833,    -1,    -1,    -1,    -1,    -1,   235,   840,    -1,    24,
      25,    -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,   852,
      35,    36,    -1,    -1,    -1,    -1,    -1,   833,    -1,   161,
      45,   864,    -1,    48,   840,    -1,    -1,    -1,    -1,    -1,
     873,    -1,    -1,    -1,   877,    -1,   852,    -1,    -1,   162,
      -1,    -1,    67,   697,    69,   699,    -1,    -1,   864,    74,
     704,    -1,    -1,   707,    -1,    80,   295,   873,    -1,    -1,
     714,   877,    -1,   717,    -1,    -1,    -1,    -1,    -1,    -1,
     309,    -1,    -1,    -1,    -1,   918,    -1,    -1,    -1,   104,
     105,    -1,     2,    -1,    -1,   739,    -1,    29,    -1,    -1,
      -1,    11,    -1,   235,    -1,    -1,   750,    -1,   752,    -1,
     242,    -1,   918,    -1,    24,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   962,
     963,   964,   965,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,
     379,    83,    -1,    -1,   987,   988,   962,   963,   964,   965,
      -1,    71,    -1,   295,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   401,    -1,    -1,    -1,    -1,   309,   407,    -1,
      -1,   987,   988,    -1,    29,    -1,   415,    97,    -1,   833,
      -1,   101,    -1,    -1,    -1,    -1,   840,    -1,   130,   131,
      -1,   133,   134,   135,    -1,   137,   138,   139,   852,   141,
     142,   143,   144,    -1,    -1,   147,   148,   149,   150,   151,
     864,   153,    -1,    -1,   156,   157,   158,    -1,    -1,   873,
      -1,     2,    -1,   877,    79,    -1,    -1,   466,    83,    -1,
      11,   470,    -1,    -1,    -1,    -1,    -1,   379,    -1,   478,
      -1,   161,    -1,    24,     2,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,   401,
      -1,    -1,    -1,    -1,   918,   407,    24,    -1,    26,    -1,
      -1,    -1,    -1,   415,    -1,   130,   131,    -1,   133,   134,
     135,    -1,   137,   138,   139,    -1,    -1,   142,   143,   144,
      71,    -1,   147,   148,   149,   150,    -1,    -1,   153,    -1,
      -1,   156,   157,   158,    -1,    -1,    24,    25,   962,   963,
     964,   965,    -1,    71,    -1,   235,    97,    35,    36,    -1,
     101,    -1,   242,    -1,   466,    -1,    -1,    45,   470,    -1,
      48,    -1,     3,   987,   988,    -1,   478,    -1,    -1,    97,
      -1,    -1,    -1,   101,    15,    16,   585,    18,    -1,    67,
      -1,    69,    23,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      31,    -1,    80,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    42,    -1,    44,    -1,   295,    47,    -1,    -1,    -1,
     161,    -1,    -1,    -1,    55,    -1,   104,   105,    -1,   309,
      61,    62,    -1,    -1,    -1,    -1,   635,    68,    -1,    -1,
      -1,    -1,   641,   161,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    89,    -1,
      91,    -1,    93,    -1,    -1,    96,    -1,    -1,    -1,   100,
      -1,    -1,   103,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   585,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,   697,   379,
     699,   242,    -1,    -1,    -1,   704,    -1,    -1,   707,    -1,
      -1,    -1,    -1,    -1,    -1,   714,    -1,   235,   717,    -1,
      -1,   401,    -1,    -1,   242,    -1,    -1,   407,    -1,    -1,
      -1,   162,    -1,   635,    -1,   415,    -1,    -1,    -1,   641,
     739,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   750,    -1,   752,   295,    -1,    -1,    -1,    -1,    -1,
      20,    -1,    -1,    -1,    24,    25,    -1,    -1,   309,    -1,
      -1,    -1,    -1,    33,    -1,    35,    36,   295,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    45,   466,    -1,    -1,    -1,
     470,   309,    -1,    -1,    -1,   697,    -1,   699,   478,    -1,
      -1,    -1,   704,    -1,    -1,   707,    -1,    67,    -1,    69,
      -1,    71,   714,    73,    -1,   717,    76,    -1,    78,    -1,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   833,    -1,    -1,   739,   379,    99,
      -1,   840,   102,    -1,    -1,   105,    -1,    -1,   750,    -1,
     752,    -1,    -1,   852,    -1,    -1,    -1,    -1,    -1,    -1,
     401,   379,    -1,    -1,    -1,   864,   407,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   873,    -1,    -1,    -1,   877,    -1,
      -1,    -1,    -1,   401,    -1,    -1,    -1,    -1,    -1,   407,
      -1,    -1,    -1,    -1,    -1,   155,    -1,   415,    20,    -1,
      -1,   161,    24,    25,    -1,   585,    -1,    -1,    -1,    -1,
      -1,    33,    -1,    35,    36,    -1,    -1,    -1,    40,   918,
      -1,    -1,    -1,    45,    -1,   466,    -1,    -1,    -1,   470,
      -1,   833,    -1,    -1,    -1,    -1,    -1,   478,   840,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    69,   466,    71,
     852,    73,   470,    -1,    76,   635,    78,    -1,    80,    -1,
     478,   641,   864,   962,   963,   964,   965,    -1,    -1,    -1,
      -1,   873,    -1,    -1,    -1,   877,    -1,    99,    -1,    -1,
     102,    -1,    -1,   105,    -1,    -1,    -1,    -1,   987,   988,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,   918,   697,    -1,   699,
      -1,    -1,    -1,    29,   704,    -1,    -1,   707,    -1,    -1,
      -1,    -1,    -1,   155,   714,    -1,    -1,   717,    -1,    -1,
      -1,    -1,    -1,    -1,   585,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   739,
     962,   963,   964,   965,    -1,    -1,    -1,   585,    -1,    -1,
     750,    -1,   752,    79,    -1,    -1,    -1,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   987,   988,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   635,    -1,    -1,    -1,    -1,    -1,
     641,    -1,    -1,    -1,   110,    -1,    -1,    -1,   114,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   635,    -1,    -1,
      -1,    -1,    -1,   641,   130,   131,    -1,   133,   134,   135,
      -1,   137,   138,   139,    -1,   141,   142,   143,   144,   145,
      -1,   147,   148,   149,   150,   151,   152,   153,    -1,    -1,
     156,   157,   158,   833,    -1,    -1,   697,    -1,   699,   165,
     840,    -1,    -1,   704,    -1,    -1,   707,    -1,    -1,    -1,
      -1,    -1,   852,   714,    -1,    -1,   717,    -1,    -1,   697,
      -1,   699,    -1,    -1,   864,    -1,   704,    -1,    -1,   707,
      -1,    -1,    -1,   873,    -1,    -1,   714,   877,   739,   717,
      -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,   750,
      -1,   752,    -1,    -1,    -1,    15,    16,    -1,    18,    -1,
      -1,   739,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,   750,    -1,   752,    -1,    -1,    37,   918,    -1,
      -1,    -1,    42,    -1,    44,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,
      -1,    -1,   962,   963,   964,   965,    86,    87,    -1,    89,
      -1,    91,    -1,    93,    10,    -1,    96,    -1,    -1,    -1,
     100,    17,    -1,   103,    -1,    -1,   106,   987,   988,    -1,
      -1,   852,    -1,    29,    -1,   833,    -1,    -1,    -1,    -1,
      -1,    -1,   840,   864,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   873,    -1,   852,    -1,   877,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   864,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   873,    -1,    -1,    -1,   877,
      -1,    -1,   162,    79,    -1,    -1,    -1,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   918,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,
     918,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,    -1,   133,   134,   135,
      -1,   137,   138,   139,    -1,   141,   142,   143,   144,   145,
      -1,   147,   148,   149,   150,   151,   152,   153,    -1,    -1,
     156,   157,   158,    -1,   962,   963,   964,   965,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,   987,
     988,    12,    13,    14,    15,    16,    -1,    18,    -1,    20,
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
      -1,   162,     1,   164,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    -1,    -1,    15,    16,    -1,    18,
      -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    -1,    41,    42,    -1,    44,    -1,    -1,    47,    -1,
      -1,    -1,    51,    52,    -1,    -1,    55,    56,    -1,    58,
      59,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,
      89,    90,    91,    -1,    93,    -1,    -1,    96,    -1,    -1,
      -1,   100,    -1,    -1,   103,    -1,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,
     139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,    -1,    -1,   152,   153,   154,    -1,    -1,    -1,   158,
      -1,   160,    -1,   162,    -1,   164,   165,     1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    12,    13,
      14,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    -1,
      44,    45,    -1,    47,    48,    -1,    50,    51,    52,    -1,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    -1,    -1,    67,    68,    69,    70,    -1,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    -1,    93,
      94,    -1,    96,    97,    98,    99,   100,    -1,   102,   103,
     104,   105,   106,    -1,    -1,   109,    -1,   111,    -1,    -1,
     114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,    -1,   141,   142,   143,
     144,   145,    -1,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,   160,   161,   162,     1,
     164,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      12,    13,    14,    15,    16,    -1,    18,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    31,
      -1,    33,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    -1,    44,    45,    -1,    47,    48,    -1,    50,    51,
      52,    -1,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    -1,    84,    85,    86,    87,    88,    89,    90,    91,
      -1,    93,    94,    -1,    96,    97,    98,    99,   100,    -1,
     102,   103,   104,   105,   106,    -1,    -1,   109,    -1,   111,
      -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,
     152,   153,   154,   155,    -1,    -1,   158,    -1,   160,   161,
     162,     1,   164,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    12,    13,    14,    15,    16,    -1,    18,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,    31,    -1,    33,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    -1,    44,    45,    -1,    47,    48,    -1,
      50,    51,    52,    -1,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    -1,    -1,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    -1,
      80,    81,    82,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    -1,    93,    94,    -1,    96,    97,    98,    99,
     100,    -1,   102,   103,   104,   105,   106,    -1,    -1,   109,
      -1,   111,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,
      -1,    -1,   152,   153,    -1,   155,    -1,    -1,   158,    -1,
     160,   161,   162,     1,   164,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    12,    13,    14,    15,    16,    -1,
      18,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    31,    -1,    33,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    -1,    44,    45,    -1,    47,
      48,    -1,    50,    51,    52,    -1,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    -1,    80,    81,    82,    -1,    84,    85,    86,    87,
      88,    89,    90,    91,    -1,    93,    94,    -1,    96,    97,
      98,    99,   100,    -1,   102,   103,   104,   105,   106,    -1,
      -1,   109,    -1,   111,    -1,    -1,   114,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,    -1,    -1,   152,   153,    -1,   155,    -1,    -1,
     158,    -1,   160,   161,   162,     1,   164,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    12,    13,    14,    15,
      16,    -1,    18,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,    31,    -1,    33,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    -1,    44,    45,
      -1,    47,    48,    -1,    50,    51,    52,    -1,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    -1,    -1,
      -1,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    -1,    80,    81,    82,    -1,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    -1,
      96,    97,    98,    99,   100,    -1,   102,   103,   104,   105,
     106,    -1,    -1,   109,    -1,   111,    -1,    -1,   114,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   149,    -1,    -1,   152,   153,    -1,   155,
      -1,    -1,   158,    -1,   160,   161,   162,     1,   164,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    12,    13,
      14,    15,    16,    -1,    18,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    31,    -1,    33,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    -1,
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
      -1,   155,    -1,    -1,   158,    -1,   160,   161,   162,     1,
     164,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      12,    13,    14,    15,    16,    -1,    18,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    31,
      -1,    33,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    -1,    44,    45,    -1,    47,    48,    -1,    50,    51,
      52,    -1,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    -1,    84,    85,    86,    87,    88,    89,    90,    91,
      -1,    93,    94,    -1,    96,    97,    98,    99,   100,    -1,
     102,   103,   104,   105,   106,    -1,    -1,   109,    -1,   111,
      -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,
     152,   153,    -1,   155,    -1,    -1,   158,    -1,   160,    -1,
     162,     1,   164,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    12,    13,    14,    15,    16,    -1,    18,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,    31,    -1,    33,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    -1,    44,    45,    -1,    47,    48,    -1,
      50,    51,    52,    -1,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    -1,    -1,    -1,    67,    68,    69,
      70,    -1,    72,    73,    74,    75,    76,    77,    78,    -1,
      80,    81,    82,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    -1,    93,    94,    -1,    96,    97,    98,    99,
     100,    -1,   102,   103,   104,   105,   106,    -1,    -1,   109,
      -1,   111,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,
      -1,    -1,   152,   153,    -1,   155,    -1,    -1,   158,    -1,
     160,    -1,   162,     1,   164,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    12,    13,    14,    15,    16,    -1,
      18,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    31,    -1,    33,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    -1,    44,    45,    -1,    47,
      48,    -1,    50,    51,    52,    -1,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    -1,    -1,    67,
      68,    69,    70,    -1,    72,    73,    74,    75,    76,    77,
      78,    -1,    80,    81,    82,    -1,    84,    85,    86,    87,
      88,    89,    90,    91,    -1,    93,    94,    -1,    96,    97,
      98,    99,   100,    -1,   102,   103,   104,   105,   106,    -1,
      -1,   109,    -1,   111,    -1,    -1,   114,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,    -1,    -1,   152,   153,    -1,   155,    -1,    -1,
     158,    -1,   160,    -1,   162,     1,   164,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    12,    13,    14,    15,
      16,    -1,    18,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,    31,    -1,    33,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    -1,    44,    45,
      -1,    47,    48,    -1,    50,    51,    52,    -1,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    -1,    -1,
      -1,    67,    68,    69,    70,    -1,    72,    73,    74,    75,
      76,    77,    78,    -1,    80,    81,    82,    -1,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    -1,
      96,    97,    98,    99,   100,    -1,   102,   103,   104,   105,
     106,    -1,    -1,   109,    -1,   111,    -1,    -1,   114,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   149,    -1,    -1,   152,   153,    -1,   155,
      -1,    -1,   158,    -1,   160,    -1,   162,     1,   164,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    12,    13,
      14,    15,    16,    -1,    18,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    31,    -1,    33,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    -1,
      44,    45,    -1,    47,    48,    -1,    50,    51,    52,    -1,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    -1,    -1,    67,    68,    69,    70,    -1,    72,    73,
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
      12,    13,    14,    15,    16,    -1,    18,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    31,
      -1,    33,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    -1,    44,    45,    -1,    47,    48,    -1,    50,    51,
      52,    -1,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    -1,    -1,    -1,    67,    68,    69,    70,    -1,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    -1,    84,    85,    86,    87,    88,    89,    90,    91,
      -1,    93,    94,    -1,    96,    97,    98,    99,   100,    -1,
     102,   103,   104,   105,   106,    -1,    -1,   109,    -1,   111,
      -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,
     152,   153,    -1,   155,    -1,    -1,   158,    -1,   160,    -1,
     162,     1,   164,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    12,    13,    14,    15,    16,    -1,    18,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,    31,    -1,    33,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    -1,    44,    45,    -1,    47,    48,    -1,
      50,    51,    52,    -1,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    -1,    -1,    -1,    67,    68,    69,
      70,    -1,    72,    73,    74,    75,    76,    77,    78,    -1,
      80,    81,    82,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    -1,    93,    94,    -1,    96,    97,    98,    99,
     100,    -1,   102,   103,   104,   105,   106,    -1,    -1,   109,
      -1,   111,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,
      -1,    -1,   152,   153,    -1,   155,    -1,    -1,   158,    -1,
     160,    -1,   162,     1,   164,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    12,    13,    14,    15,    16,    -1,
      18,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    31,    -1,    33,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    -1,    44,    45,    -1,    47,
      48,    -1,    50,    51,    52,    -1,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    -1,    -1,    67,
      68,    69,    70,    -1,    72,    73,    74,    75,    76,    77,
      78,    -1,    80,    81,    82,    -1,    84,    85,    86,    87,
      88,    89,    90,    91,    -1,    93,    94,    -1,    96,    97,
      98,    99,   100,    -1,   102,   103,   104,   105,   106,    -1,
      -1,   109,    -1,   111,    -1,    -1,   114,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,    -1,    -1,   152,   153,    -1,   155,    -1,    -1,
     158,    -1,   160,    -1,   162,     1,   164,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    12,    13,    14,    15,
      16,    -1,    18,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,    31,    -1,    33,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    -1,    44,    45,
      -1,    47,    48,    -1,    50,    51,    52,    -1,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    -1,    -1,
      -1,    67,    68,    69,    70,    -1,    72,    73,    74,    75,
      76,    77,    78,    -1,    80,    81,    82,    -1,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    -1,
      96,    97,    98,    99,   100,    -1,   102,   103,   104,   105,
     106,    -1,    -1,   109,    -1,   111,    -1,    -1,   114,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   149,    -1,    -1,   152,   153,    -1,   155,
      -1,    -1,   158,    -1,   160,    -1,   162,     1,   164,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    12,    13,
      14,    15,    16,    -1,    18,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    31,    -1,    33,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    -1,
      44,    45,    -1,    47,    48,    -1,    50,    51,    52,    -1,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    -1,    -1,    67,    68,    69,    70,    -1,    72,    73,
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
      12,    13,    14,    15,    16,    -1,    18,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    31,
      -1,    33,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    -1,    44,    45,    -1,    47,    48,    -1,    50,    51,
      52,    -1,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    -1,    -1,    -1,    67,    68,    69,    70,    -1,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    -1,    84,    85,    86,    87,    88,    89,    90,    91,
      -1,    93,    94,    -1,    96,    97,    98,    99,   100,    -1,
     102,   103,   104,   105,   106,    -1,    -1,   109,    -1,   111,
      -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,
     152,   153,    -1,   155,    -1,    -1,   158,    -1,   160,    -1,
     162,     1,   164,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    12,    -1,    -1,    15,    16,    -1,    18,    -1,
      -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,
      -1,    41,    42,    -1,    44,    -1,    -1,    47,    -1,    -1,
      -1,    51,    52,    -1,    -1,    55,    56,    -1,    58,    59,
      -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      70,    -1,    72,    -1,    -1,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,
      90,    91,    -1,    93,    -1,    -1,    96,    -1,    -1,    -1,
     100,    -1,    -1,   103,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,
      -1,    -1,   152,   153,   154,    -1,    -1,    -1,   158,    -1,
     160,    -1,   162,    -1,   164,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    12,    -1,    -1,    15,    16,    -1,
      18,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    37,
      38,    39,    -1,    41,    42,    -1,    44,    -1,    -1,    47,
      -1,    -1,    -1,    51,    52,    -1,    -1,    55,    56,    -1,
      58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      88,    89,    90,    91,    -1,    93,    -1,    -1,    96,    -1,
      -1,    -1,   100,    -1,    -1,   103,    -1,    -1,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,    -1,    -1,   152,   153,   154,    -1,    -1,    -1,
     158,    -1,   160,    -1,   162,    -1,   164,   165,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,
      15,    16,    -1,    18,    -1,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    -1,    41,    42,    -1,    44,
      -1,    -1,    47,    -1,    -1,    -1,    51,    52,    -1,    -1,
      55,    56,    -1,    58,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,    -1,    72,    -1,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    90,    91,    -1,    93,    -1,
      -1,    96,    -1,    -1,    -1,   100,    -1,    -1,   103,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,    -1,    -1,   152,   153,   154,
      -1,    -1,    -1,   158,    -1,   160,    -1,   162,    -1,   164,
     165,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      12,    -1,    -1,    15,    16,    -1,    18,    -1,    -1,    -1,
      -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    37,    38,    39,    -1,    41,
      42,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    51,
      52,    -1,    -1,    55,    56,    -1,    58,    59,    -1,    61,
      62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,    -1,
      72,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,    91,
      -1,    93,    -1,    -1,    96,    -1,    -1,    -1,   100,    -1,
      -1,   103,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,
     152,   153,     1,    -1,     3,    -1,   158,    -1,   160,    -1,
     162,    10,   164,   165,    -1,    -1,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    37,    -1,
      -1,    -1,    -1,    42,    -1,    44,    -1,    -1,    47,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,
      89,    -1,    91,    -1,    93,    -1,    -1,    96,    -1,    -1,
      -1,   100,    -1,    -1,   103,    -1,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   115,   116,   117,   118,
     119,   120,    -1,    -1,   123,   124,   125,   126,    -1,   128,
     129,   130,   131,   132,   133,   134,    -1,    -1,   137,    -1,
      -1,    -1,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,    -1,   153,    -1,    -1,   156,   157,   158,
     159,    -1,    -1,   162,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    -1,    -1,    15,    16,    -1,    18,
      -1,    -1,    -1,    -1,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    -1,    41,    42,    -1,    44,    -1,    -1,    47,    -1,
      -1,    -1,    51,    52,    -1,    -1,    55,    56,    -1,    58,
      59,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    -1,    72,    -1,    -1,    -1,    -1,    77,    -1,
      -1,    80,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,
      89,    90,    91,    -1,    93,    -1,    -1,    96,    -1,    -1,
      -1,   100,    -1,    -1,   103,    -1,   105,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,
     139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,    -1,    -1,   152,   153,    -1,    -1,    -1,    -1,   158,
      -1,   160,    -1,   162,    -1,   164,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    -1,    -1,    15,    16,
      -1,    18,    -1,    20,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      37,    38,    39,    -1,    41,    42,    -1,    44,    -1,    -1,
      47,    -1,    -1,    -1,    51,    52,    -1,    -1,    55,    56,
      -1,    58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    88,    89,    90,    91,    -1,    93,    -1,    -1,    96,
      -1,    -1,    99,   100,    -1,   102,   103,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,    -1,    -1,   152,   153,    -1,    -1,    -1,
      -1,   158,    -1,   160,    -1,   162,    -1,   164,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,
      15,    16,    -1,    18,    -1,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    -1,    41,    42,    -1,    44,
      -1,    -1,    47,    -1,    -1,    -1,    51,    52,    -1,    -1,
      55,    56,    -1,    58,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,    -1,    72,    -1,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    90,    91,    -1,    93,    -1,
      -1,    96,    97,    98,    -1,   100,   101,    -1,   103,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,    -1,    -1,   152,   153,   154,
      -1,    -1,    -1,   158,    -1,   160,    -1,   162,    -1,   164,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      -1,    -1,    15,    16,    -1,    18,    -1,    -1,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    37,    38,    39,    -1,    41,    42,
      -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    51,    52,
      -1,    -1,    55,    56,    -1,    58,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    70,    -1,    72,
      -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    88,    89,    90,    91,    -1,
      93,    -1,    -1,    96,    97,    98,    -1,   100,   101,    -1,
     103,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,   152,
     153,   154,    -1,    -1,    -1,   158,    -1,   160,    -1,   162,
     163,   164,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    18,    -1,    -1,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    -1,
      41,    42,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,
      51,    52,    -1,    -1,    55,    56,    -1,    58,    59,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,
      -1,    72,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,
      91,    -1,    93,    -1,    -1,    96,    97,    98,    -1,   100,
     101,    -1,   103,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,
      -1,   152,   153,   154,    -1,    -1,    -1,   158,    -1,   160,
      -1,   162,   163,   164,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    -1,    -1,    15,    16,    -1,    18,
      -1,    -1,    -1,    -1,    23,    -1,    25,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    -1,    41,    42,    43,    44,    -1,    -1,    47,    -1,
      -1,    -1,    51,    52,    -1,    -1,    55,    56,    -1,    58,
      59,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    77,    -1,
      -1,    80,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,
      89,    90,    91,    -1,    93,    -1,    -1,    96,    -1,    -1,
      -1,   100,    -1,    -1,   103,    -1,   105,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,
     139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,    -1,    -1,   152,   153,    -1,    -1,    -1,    -1,   158,
      -1,   160,    -1,   162,    -1,   164,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    -1,    -1,    15,    16,
      -1,    18,    -1,    20,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      37,    38,    39,    -1,    41,    42,    -1,    44,    -1,    -1,
      47,    -1,    -1,    -1,    51,    52,    -1,    -1,    55,    56,
      -1,    58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    88,    89,    90,    91,    -1,    93,    -1,    -1,    96,
      -1,    -1,    99,   100,    -1,   102,   103,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,    -1,    -1,   152,   153,    -1,    -1,    -1,
      -1,   158,    -1,   160,    -1,   162,    -1,   164,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,
      15,    16,    -1,    18,    -1,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    -1,    41,    42,    -1,    44,
      -1,    -1,    47,    -1,    -1,    -1,    51,    52,    -1,    -1,
      55,    56,    -1,    58,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,    -1,    72,    -1,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    90,    91,    -1,    93,    -1,
      -1,    96,    97,    98,    -1,   100,    -1,    -1,   103,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,    -1,    -1,   152,   153,    -1,
     155,    -1,    -1,   158,    -1,   160,    -1,   162,    -1,   164,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      -1,    -1,    15,    16,    -1,    18,    -1,    -1,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    37,    38,    39,    -1,    41,    42,
      -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    51,    52,
      -1,    -1,    55,    56,    -1,    58,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    70,    -1,    72,
      -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    88,    89,    90,    91,    -1,
      93,    -1,    -1,    96,    97,    98,    -1,   100,    -1,    -1,
     103,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,   152,
     153,   154,    -1,    -1,    -1,   158,    -1,   160,    -1,   162,
      -1,   164,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    18,    -1,    -1,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    -1,
      41,    42,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,
      51,    52,    -1,    -1,    55,    56,    -1,    58,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,
      -1,    72,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,
      91,    -1,    93,    -1,    -1,    96,    97,    98,    -1,   100,
      -1,    -1,   103,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,
      -1,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,   160,
      -1,   162,    -1,   164,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    -1,    -1,    15,    16,    -1,    18,
      -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    -1,    41,    42,    -1,    44,    -1,    -1,    47,    -1,
      -1,    -1,    51,    52,    -1,    -1,    55,    56,    -1,    58,
      59,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    -1,    72,    -1,    -1,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,
      89,    90,    91,    -1,    93,    -1,    -1,    96,    -1,    -1,
      -1,   100,    -1,    -1,   103,    -1,    -1,   106,    -1,    -1,
      -1,    -1,    -1,   112,    -1,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,
     139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,    -1,    -1,   152,   153,    -1,    -1,    -1,    -1,   158,
      -1,   160,    -1,   162,    -1,   164,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    -1,    -1,    15,    16,
      -1,    18,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      37,    38,    39,    -1,    41,    42,    -1,    44,    -1,    -1,
      47,    -1,    -1,    -1,    51,    52,    -1,    -1,    55,    56,
      -1,    58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    88,    89,    90,    91,    -1,    93,    -1,    -1,    96,
      -1,    -1,    -1,   100,    -1,    -1,   103,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,   112,    -1,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,    -1,    -1,   152,   153,   154,    -1,    -1,
      -1,   158,    -1,   160,    -1,   162,    -1,   164,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,
      15,    16,    -1,    18,    -1,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    -1,    41,    42,    -1,    44,
      -1,    -1,    47,    -1,    -1,    -1,    51,    52,    -1,    -1,
      55,    56,    -1,    58,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,    -1,    72,    -1,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    90,    91,    -1,    93,    -1,
      -1,    96,    97,    98,    -1,   100,    -1,    -1,   103,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,    -1,    -1,   152,   153,    -1,
      -1,    -1,    -1,   158,    -1,   160,    -1,   162,    -1,   164,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      -1,    -1,    15,    16,    -1,    18,    -1,    -1,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    37,    38,    39,    -1,    41,    42,
      -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    51,    52,
      -1,    -1,    55,    56,    -1,    58,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    70,    -1,    72,
      -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    88,    89,    90,    91,    -1,
      93,    -1,    -1,    96,    -1,    -1,    -1,   100,    -1,    -1,
     103,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,   152,
     153,   154,    -1,    -1,    -1,   158,    -1,   160,   161,   162,
      -1,   164,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    18,    -1,    -1,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    -1,
      41,    42,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,
      51,    52,    -1,    -1,    55,    56,    -1,    58,    59,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,
      -1,    72,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,
      91,    -1,    93,    -1,    -1,    96,    -1,    -1,    -1,   100,
      -1,    -1,   103,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,   112,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,   132,   133,   134,    -1,    -1,    -1,    -1,   139,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,
      -1,   152,   153,    -1,    -1,    -1,    -1,   158,    -1,   160,
      -1,   162,    -1,   164,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    -1,    -1,    15,    16,    -1,    18,
      -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    -1,    41,    42,    -1,    44,    -1,    -1,    47,    -1,
      -1,    -1,    51,    52,    -1,    -1,    55,    56,    -1,    58,
      59,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    77,    -1,
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
      -1,    18,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      37,    38,    39,    -1,    41,    42,    -1,    44,    -1,    -1,
      47,    -1,    -1,    -1,    51,    52,    -1,    -1,    55,    56,
      -1,    58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    88,    89,    90,    91,    -1,    93,    -1,    -1,    96,
      -1,    -1,    -1,   100,    -1,    -1,   103,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,    -1,    -1,   152,   153,   154,    -1,    -1,
      -1,   158,    -1,   160,    -1,   162,    -1,   164,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,
      15,    16,    -1,    18,    -1,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    -1,    41,    42,    -1,    44,
      -1,    -1,    47,    -1,    -1,    -1,    51,    52,    -1,    -1,
      55,    56,    -1,    58,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,    -1,    72,    -1,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    90,    91,    -1,    93,    -1,
      -1,    96,    -1,    -1,    -1,   100,    -1,    -1,   103,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,    -1,    -1,   152,   153,   154,
      -1,    -1,    -1,   158,    -1,   160,    -1,   162,    -1,   164,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      -1,    -1,    15,    16,    -1,    18,    -1,    -1,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    37,    38,    39,    -1,    41,    42,
      -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    51,    52,
      -1,    -1,    55,    56,    -1,    58,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    70,    -1,    72,
      -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    88,    89,    90,    91,    -1,
      93,    -1,    -1,    96,    -1,    -1,    -1,   100,    -1,    -1,
     103,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,   152,
     153,   154,    -1,    -1,    -1,   158,    -1,   160,    -1,   162,
      -1,   164,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    18,    -1,    -1,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    -1,
      41,    42,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,
      51,    52,    -1,    -1,    55,    56,    -1,    58,    59,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,
      -1,    72,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    -1,    41,    42,    -1,    44,    -1,    -1,    47,    -1,
      -1,    -1,    51,    52,    -1,    -1,    55,    56,    -1,    58,
      59,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    77,    -1,
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
      -1,    18,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      37,    38,    39,    -1,    41,    42,    -1,    44,    -1,    -1,
      47,    -1,    -1,    -1,    51,    52,    -1,    -1,    55,    56,
      -1,    58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    88,    89,    90,    91,    -1,    93,    -1,    -1,    96,
      -1,    -1,    -1,   100,    -1,    -1,   103,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,    -1,    -1,   152,   153,   154,    -1,    -1,
      -1,   158,    -1,   160,    -1,   162,    -1,   164,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,
      15,    16,    -1,    18,    -1,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    -1,    41,    42,    -1,    44,
      -1,    -1,    47,    -1,    -1,    -1,    51,    52,    -1,    -1,
      55,    56,    -1,    58,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,    -1,    72,    -1,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    90,    91,    -1,    93,    -1,
      -1,    96,    -1,    -1,    -1,   100,    -1,    -1,   103,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,    -1,    -1,   152,   153,    -1,
      -1,    -1,    -1,   158,    -1,   160,    -1,   162,    -1,   164,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      -1,    -1,    15,    16,    -1,    18,    -1,    -1,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    37,    38,    39,    -1,    41,    42,
      -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    51,    52,
      -1,    -1,    55,    56,    -1,    58,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    70,    -1,    72,
      -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    88,    89,    90,    91,    -1,
      93,    -1,    -1,    96,    -1,    -1,    -1,   100,    -1,    -1,
     103,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,   160,    -1,   162,
      -1,   164,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    18,    -1,    -1,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    -1,
      41,    42,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,
      51,    52,    -1,    -1,    55,    56,    -1,    58,    59,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,
      -1,    72,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    -1,    41,    42,    -1,    44,    -1,    -1,    47,    -1,
      -1,    -1,    51,    52,    -1,    -1,    55,    56,    -1,    58,
      59,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    77,    -1,
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
      -1,    18,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      37,    38,    39,    -1,    41,    42,    -1,    44,    -1,    -1,
      47,    -1,    -1,    -1,    51,    52,    -1,    -1,    55,    56,
      -1,    58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    88,    89,    90,    91,    -1,    93,    -1,    -1,    96,
      -1,    -1,    -1,   100,    -1,    -1,   103,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,    -1,    -1,   152,   153,    -1,    -1,    -1,
      -1,   158,    -1,   160,    -1,   162,    -1,   164,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,
      15,    16,    -1,    18,    -1,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    -1,    41,    42,    -1,    44,
      -1,    -1,    47,    -1,    -1,    -1,    51,    52,    -1,    -1,
      55,    56,    -1,    58,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,    -1,    72,    -1,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    90,    91,    -1,    93,    -1,
      -1,    96,    -1,    -1,    -1,   100,    -1,    -1,   103,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,    -1,    -1,   152,   153,    -1,
      -1,    -1,    -1,   158,    -1,   160,    -1,   162,    -1,   164,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      -1,    -1,    15,    16,    -1,    18,    -1,    -1,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    37,    38,    39,    -1,    41,    42,
      -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    51,    52,
      -1,    -1,    55,    56,    -1,    58,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    70,    -1,    72,
      -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    88,    89,    90,    91,    -1,
      93,    -1,    -1,    96,    -1,    -1,    -1,   100,    -1,    -1,
     103,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,   160,    -1,   162,
      -1,   164,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    18,    -1,    -1,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    -1,
      41,    42,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,
      51,    52,    -1,    -1,    55,    56,    -1,    58,    59,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,
      -1,    72,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    -1,    41,    42,    -1,    44,    -1,    -1,    47,    -1,
      -1,    -1,    51,    52,    -1,    -1,    55,    56,    -1,    58,
      59,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    77,    -1,
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
      -1,    18,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      37,    38,    39,    -1,    41,    42,    -1,    44,    -1,    -1,
      47,    -1,    -1,    -1,    51,    52,    -1,    -1,    55,    56,
      -1,    58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    88,    89,    90,    91,    -1,    93,    -1,    -1,    96,
      -1,    -1,    -1,   100,    -1,    -1,   103,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,    -1,    -1,   152,   153,    -1,    -1,    -1,
      -1,   158,    -1,   160,    -1,   162,    -1,   164,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,
      15,    16,    -1,    18,    -1,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    -1,    41,    42,    -1,    44,
      -1,    -1,    47,    -1,    -1,    -1,    51,    52,    -1,    -1,
      55,    56,    -1,    58,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,    -1,    72,    -1,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    90,    91,    -1,    93,    -1,
      -1,    96,    -1,    -1,    -1,   100,    -1,    -1,   103,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,    -1,    -1,   152,   153,    -1,
      -1,    -1,    -1,   158,    -1,   160,    -1,   162,    -1,   164,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      -1,    -1,    15,    16,    -1,    18,    -1,    -1,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    37,    38,    39,    -1,    41,    42,
      -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    51,    52,
      -1,    -1,    55,    56,    -1,    58,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    70,    -1,    72,
      -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    88,    89,    90,    91,    -1,
      93,    -1,    -1,    96,    -1,    -1,    -1,   100,    -1,    -1,
     103,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,   160,    -1,   162,
      -1,   164,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    18,    -1,    -1,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    -1,
      41,    42,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,
      51,    52,    -1,    -1,    55,    56,    -1,    58,    59,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,
      -1,    72,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    -1,    41,    42,    -1,    44,    -1,    -1,    47,    -1,
      -1,    -1,    51,    52,    -1,    -1,    55,    56,    -1,    58,
      59,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    77,    -1,
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
      -1,    18,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      37,    38,    39,    -1,    41,    42,    -1,    44,    -1,    -1,
      47,    -1,    -1,    -1,    51,    52,    -1,    -1,    55,    56,
      -1,    58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    88,    89,    90,    91,    -1,    93,    -1,    -1,    96,
      -1,    -1,    -1,   100,    -1,    -1,   103,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,    -1,    -1,   152,   153,    -1,    -1,    -1,
      -1,   158,    -1,    -1,    -1,   162,    -1,   164,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,
      15,    16,    -1,    18,    -1,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    -1,    41,    42,    -1,    44,
      -1,    -1,    47,    -1,    -1,    -1,    51,    52,    -1,    -1,
      55,    56,    -1,    58,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,    -1,    72,    -1,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    90,    91,    -1,    93,    -1,
      -1,    96,    -1,    -1,    -1,   100,    -1,    -1,   103,    -1,
      -1,   106,    -1,    -1,    -1,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
       3,     4,     5,     6,     7,     8,   146,    -1,    -1,    12,
      -1,    -1,    15,    16,   149,    18,    -1,    -1,   153,   159,
      23,    -1,   162,   158,   164,   160,    -1,   162,    31,   164,
      -1,    -1,    -1,    -1,    37,    38,    39,    -1,    41,    42,
      -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    51,    52,
      -1,    -1,    55,    56,    -1,    58,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    70,    -1,    72,
      -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    88,    89,    90,    91,    -1,
      93,    -1,    -1,    96,    -1,    -1,    -1,   100,    -1,    -1,
     103,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,
      -1,    -1,    -1,   136,    -1,    -1,    -1,   140,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      -1,   154,    12,    -1,    -1,    15,    16,   160,    18,   162,
     163,   164,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,
      -1,    41,    42,    -1,    44,    -1,    -1,    47,    -1,    -1,
      -1,    51,    52,    53,    -1,    55,    56,    -1,    58,    59,
      -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      70,    -1,    72,    -1,    -1,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    82,    -1,    -1,    -1,    86,    87,    88,    89,
      90,    91,    -1,    93,    -1,    95,    96,    -1,    -1,    -1,
     100,    -1,    -1,   103,    -1,    -1,   106,    -1,   108,    -1,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   132,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    12,    -1,    -1,    15,    16,    -1,    18,    -1,
      -1,    -1,    -1,    23,   159,   155,    -1,   162,    -1,   164,
     160,    31,   162,    -1,   164,    -1,    -1,    37,    38,    39,
      -1,    41,    42,    -1,    44,    -1,    -1,    47,    -1,    -1,
      -1,    51,    52,    -1,    -1,    55,    56,    -1,    58,    59,
      -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      70,    -1,    72,    -1,    -1,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,
      90,    91,    -1,    93,    -1,    -1,    96,    -1,    -1,    -1,
     100,    -1,    -1,   103,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   132,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    12,    -1,    -1,    15,    16,    -1,    18,    -1,
      -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,
     160,    31,   162,    -1,   164,    -1,    -1,    37,    38,    39,
      -1,    41,    42,    -1,    44,    -1,    -1,    47,    -1,    -1,
      -1,    51,    52,    -1,    -1,    55,    56,    -1,    58,    59,
      -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      70,    -1,    72,    -1,    -1,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,
      90,    91,    -1,    93,    -1,    -1,    96,    -1,    -1,    -1,
     100,    -1,    -1,   103,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   132,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    12,    -1,    -1,    15,    16,    -1,    18,    -1,
      -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,
     160,    31,   162,    -1,   164,    -1,    -1,    37,    38,    39,
      -1,    41,    42,    -1,    44,    -1,    -1,    47,    -1,    -1,
      -1,    51,    52,    -1,    -1,    55,    56,    -1,    58,    59,
      -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      70,    -1,    72,    -1,    -1,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,
      90,    91,    -1,    93,    -1,     3,    96,    -1,    -1,    -1,
     100,    -1,    10,   103,    -1,    -1,   106,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    -1,   132,    -1,    42,    -1,    44,    -1,    -1,    47,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    61,    62,    -1,    -1,    -1,    10,    -1,
      68,    -1,   162,    -1,   164,    17,    -1,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    86,    87,
      -1,    89,    -1,    91,    -1,    93,    -1,    -1,    96,    -1,
      -1,    -1,   100,    -1,    -1,   103,    -1,    -1,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,   116,   117,
     118,   119,   120,    -1,    -1,   123,   124,   125,   126,    -1,
     128,   129,   130,   131,   132,   133,   134,    79,    -1,   137,
      -1,    83,    -1,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,    -1,   153,    10,    -1,   156,   157,
     158,   159,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
      -1,   133,   134,   135,    -1,   137,   138,   139,    -1,   141,
     142,   143,   144,   145,    -1,   147,   148,   149,   150,   151,
     152,   153,    -1,    10,   156,   157,   158,    -1,    -1,    -1,
      17,    -1,    -1,   165,    -1,    79,    -1,    -1,    -1,    83,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,
     114,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,   130,   131,    -1,   133,
     134,   135,    79,   137,   138,   139,    83,   141,   142,   143,
     144,   145,    -1,   147,   148,   149,   150,   151,   152,   153,
      -1,    -1,   156,   157,   158,    -1,    -1,    -1,    -1,    -1,
      -1,   165,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,    79,    -1,    -1,    -1,    83,    -1,    -1,
      -1,    -1,    -1,   130,   131,    -1,   133,   134,   135,    -1,
     137,   138,   139,    -1,   141,   142,   143,   144,   145,    -1,
     147,   148,   149,   150,   151,   152,   153,    10,   114,   156,
     157,   158,    -1,    -1,    17,    -1,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,    29,   133,   134,   135,
      -1,   137,   138,   139,    -1,   141,   142,   143,   144,   145,
      -1,   147,   148,   149,   150,   151,   152,   153,    -1,    -1,
     156,   157,   158,    -1,    -1,    -1,    -1,   163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,
      83,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    92,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,   115,   116,   117,   118,   119,   120,    -1,    -1,
     123,   124,   125,   126,    -1,   128,   129,   130,   131,    -1,
     133,   134,   135,    -1,   137,   138,   139,    -1,   141,   142,
     143,   144,   145,    -1,   147,   148,   149,   150,   151,   152,
     153,    -1,    79,   156,   157,   158,    83,   160,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    92,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,   116,
     117,   118,   119,   120,    -1,    -1,   123,   124,   125,   126,
      -1,   128,   129,   130,   131,    -1,   133,   134,   135,    -1,
     137,   138,   139,    -1,   141,   142,   143,   144,   145,    -1,
     147,   148,   149,   150,   151,   152,   153,    -1,    79,   156,
     157,   158,    83,   160,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    92,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,   115,   116,   117,   118,   119,   120,
      -1,    -1,   123,   124,   125,   126,    -1,   128,   129,   130,
     131,    -1,   133,   134,   135,    -1,   137,   138,   139,    -1,
     141,   142,   143,   144,   145,    -1,   147,   148,   149,   150,
     151,   152,   153,    -1,    79,   156,   157,   158,    83,   160,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    92,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
     115,   116,   117,   118,   119,   120,    -1,    -1,   123,   124,
     125,   126,    -1,   128,   129,   130,   131,    -1,   133,   134,
     135,    -1,   137,   138,   139,    -1,   141,   142,   143,   144,
     145,    -1,   147,   148,   149,   150,   151,   152,   153,    -1,
      79,   156,   157,   158,    83,   160,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    92,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,   115,   116,   117,   118,
     119,   120,    -1,    -1,   123,   124,   125,   126,    -1,   128,
     129,   130,   131,    -1,   133,   134,   135,    -1,   137,   138,
     139,    -1,   141,   142,   143,   144,   145,    -1,   147,   148,
     149,   150,   151,   152,   153,    -1,    79,   156,   157,   158,
      83,   160,    -1,    10,    -1,    -1,    -1,    -1,    -1,    92,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,   115,   116,   117,   118,   119,   120,    -1,    -1,
     123,   124,   125,   126,    -1,   128,   129,   130,   131,    -1,
     133,   134,   135,    -1,   137,   138,   139,    -1,   141,   142,
     143,   144,   145,    -1,   147,   148,   149,   150,   151,   152,
     153,    -1,    79,   156,   157,   158,    83,   160,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    92,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,   116,
     117,   118,   119,   120,    -1,    -1,   123,   124,   125,   126,
      -1,   128,   129,   130,   131,    -1,   133,   134,   135,    -1,
     137,   138,   139,    -1,   141,   142,   143,   144,   145,    -1,
     147,   148,   149,   150,   151,   152,   153,    -1,    79,   156,
     157,   158,    83,   160,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    92,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,   115,   116,   117,   118,   119,   120,
      -1,    -1,   123,   124,   125,   126,    -1,   128,   129,   130,
     131,    -1,   133,   134,   135,    -1,   137,   138,   139,    -1,
     141,   142,   143,   144,   145,    -1,   147,   148,   149,   150,
     151,   152,   153,    -1,    79,   156,   157,   158,    83,   160,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
     115,   116,   117,   118,   119,   120,    -1,    -1,   123,   124,
     125,   126,    -1,   128,   129,   130,   131,    -1,   133,   134,
     135,    -1,   137,   138,   139,    -1,   141,   142,   143,   144,
     145,    -1,   147,   148,   149,   150,   151,   152,   153,    10,
      -1,   156,   157,   158,    -1,   160,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    10,    43,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    79,    -1,
      -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,   110,
      79,    -1,    -1,   114,    83,    -1,    -1,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,    -1,   133,   134,   135,    -1,   137,   138,   139,    -1,
     141,   142,   143,   144,   145,   114,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,   156,   157,   158,    -1,   160,
      -1,   130,   131,    -1,   133,   134,   135,    79,   137,   138,
     139,    83,   141,   142,   143,   144,   145,    -1,   147,   148,
     149,   150,   151,   152,   153,    10,    -1,   156,   157,   158,
      -1,   160,    17,    -1,    -1,    -1,    -1,    -1,   110,    -1,
      -1,    -1,   114,    -1,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
      -1,   133,   134,   135,    -1,   137,   138,   139,    -1,   141,
     142,   143,   144,   145,    -1,   147,   148,   149,   150,   151,
     152,   153,    10,    -1,   156,   157,   158,    -1,   160,    17,
      -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    83,    -1,
      -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,    -1,   133,   134,
     135,    79,   137,   138,   139,    83,   141,   142,   143,   144,
     145,    -1,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,   156,   157,   158,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    79,    -1,    -1,   114,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,
      -1,    -1,   130,   131,    -1,   133,   134,   135,    -1,   137,
     138,   139,    -1,   141,   142,   143,   144,   145,   114,   147,
     148,   149,   150,   151,   152,   153,    -1,    -1,   156,   157,
     158,    -1,   160,    -1,   130,   131,    -1,   133,   134,   135,
      -1,   137,   138,   139,    -1,   141,   142,   143,   144,   145,
      -1,   147,   148,   149,   150,   151,   152,   153,    10,    -1,
     156,   157,   158,    -1,   160,    17,    -1,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    15,
      16,    -1,    18,    -1,    -1,    -1,    -1,    23,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    31,    -1,    17,    -1,    -1,
      -1,    37,    -1,    -1,    -1,    -1,    42,    -1,    44,    29,
      -1,    47,    -1,    -1,    34,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    61,    62,    79,    -1,    -1,
      -1,    83,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    -1,    -1,    64,    -1,    -1,    10,    -1,    -1,
      86,    87,    -1,    89,    17,    91,    -1,    93,    -1,    79,
      96,    -1,   114,    83,   100,    -1,    29,   103,    -1,    -1,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
      43,   133,   134,   135,    -1,   137,   138,   139,    -1,   141,
     142,   143,   144,   145,   114,   147,   148,   149,   150,   151,
     152,   153,    -1,    -1,   156,   157,   158,    -1,   160,    -1,
     130,   131,    -1,   133,   134,   135,    79,   137,   138,   139,
      83,   141,   142,   143,   144,   145,    -1,   147,   148,   149,
     150,   151,   152,   153,    10,   155,   156,   157,   158,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,
      -1,   114,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,    -1,
     133,   134,   135,    -1,   137,   138,   139,    -1,   141,   142,
     143,   144,   145,    -1,   147,   148,   149,   150,   151,   152,
     153,    10,    -1,   156,   157,   158,    -1,    -1,    17,    -1,
      -1,    -1,    -1,    79,    -1,    -1,    -1,    83,    -1,    -1,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    43,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,
      -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,    43,   133,   134,   135,
      79,   137,   138,   139,    83,   141,   142,   143,   144,   145,
      -1,   147,   148,   149,   150,   151,   152,   153,    -1,   155,
     156,   157,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    79,    -1,    -1,   114,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,    -1,   133,   134,   135,    -1,   137,   138,
     139,    -1,   141,   142,   143,   144,   145,   114,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,   156,   157,   158,
      -1,    -1,    -1,   130,   131,    -1,   133,   134,   135,    -1,
     137,   138,   139,    -1,   141,   142,   143,   144,   145,    -1,
     147,   148,   149,   150,   151,   152,   153,    10,    -1,   156,
     157,   158,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    79,    -1,
      -1,   114,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,    -1,
     133,   134,   135,    -1,   137,   138,   139,    -1,   141,   142,
     143,   144,   145,   114,   147,   148,   149,   150,   151,   152,
     153,    -1,    -1,   156,   157,   158,    -1,    79,    -1,   130,
     131,    83,   133,   134,   135,    -1,   137,   138,   139,    -1,
     141,   142,   143,   144,   145,    -1,   147,   148,   149,   150,
     151,   152,   153,    10,   155,   156,   157,   158,    -1,    -1,
      17,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,   130,   131,
      -1,   133,   134,   135,    -1,   137,   138,   139,    -1,   141,
     142,   143,   144,   145,    -1,   147,   148,   149,   150,   151,
     152,   153,    10,   155,   156,   157,   158,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    79,    -1,    -1,    -1,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    79,    -1,   130,   131,    83,   133,   134,   135,    -1,
     137,   138,   139,    -1,   141,   142,   143,   144,   145,    -1,
     147,   148,   149,   150,   151,   152,   153,    -1,   155,   156,
     157,   158,    -1,    79,    -1,   113,   114,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,
      -1,    -1,   130,   131,    -1,   133,   134,   135,    -1,   137,
     138,   139,    -1,   141,   142,   143,   144,   145,   114,   147,
     148,   149,   150,   151,   152,   153,    -1,    -1,   156,   157,
     158,    -1,    -1,    -1,   130,   131,    -1,   133,   134,   135,
      -1,   137,   138,   139,    -1,   141,   142,   143,   144,   145,
      -1,   147,   148,   149,   150,   151,   152,   153,    10,    -1,
     156,   157,   158,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    79,    -1,    -1,
      -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    79,    -1,    -1,    -1,    83,    -1,   130,   131,
      -1,   133,   134,   135,    -1,   137,   138,   139,    -1,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    -1,   110,   156,   157,   158,   114,    -1,    -1,
      -1,    -1,    -1,    79,    -1,    -1,    -1,    83,    -1,    -1,
      -1,    -1,    -1,   130,   131,    -1,   133,   134,   135,    -1,
     137,   138,   139,    -1,   141,   142,   143,   144,   145,    -1,
     147,   148,   149,   150,   151,   152,   153,    -1,   114,   156,
     157,   158,    -1,    -1,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    17,    -1,   130,   131,    -1,   133,   134,   135,
      -1,   137,   138,   139,    29,   141,   142,   143,   144,   145,
      -1,   147,   148,   149,   150,   151,   152,   153,    -1,   155,
     156,   157,   158,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    83,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,    -1,   133,   134,
     135,    -1,   137,   138,   139,    -1,   141,   142,   143,   144,
     145,    -1,   147,   148,   149,   150,   151,   152,   153,   114,
      -1,   156,   157,   158,    -1,    79,    -1,    -1,    -1,    83,
      -1,    -1,    -1,    -1,    -1,   130,   131,    -1,   133,   134,
     135,    -1,   137,   138,   139,    -1,   141,   142,   143,   144,
     145,    -1,   147,   148,   149,   150,   151,   152,   153,   113,
     114,   156,   157,   158,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   130,   131,    -1,   133,
     134,   135,    -1,   137,   138,   139,    -1,   141,   142,   143,
     144,   145,    -1,   147,   148,   149,   150,   151,   152,   153,
      10,    -1,   156,   157,   158,    -1,    -1,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,
      -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    79,    -1,    -1,   114,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,    -1,   133,   134,   135,    -1,   137,   138,   139,
      -1,   141,   142,   143,   144,   145,   114,   147,   148,   149,
     150,   151,   152,   153,    -1,    -1,   156,   157,   158,    -1,
      -1,    -1,   130,   131,    -1,   133,   134,   135,    -1,   137,
     138,   139,    -1,   141,   142,   143,   144,   145,    -1,   147,
     148,   149,   150,   151,   152,   153,    10,    -1,   156,   157,
     158,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    79,    -1,    -1,
     114,    83,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    -1,    -1,    -1,   130,   131,    -1,   133,
     134,   135,    -1,   137,   138,   139,    -1,   141,   142,   143,
     144,   145,   114,   147,   148,   149,   150,   151,   152,   153,
      -1,    -1,   156,   157,   158,    -1,    -1,    -1,   130,   131,
      -1,   133,   134,   135,    79,   137,   138,   139,    83,   141,
     142,   143,   144,   145,    -1,   147,   148,   149,   150,   151,
     152,   153,    10,    -1,   156,   157,   158,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,    -1,   133,   134,
     135,    -1,   137,   138,   139,    -1,   141,   142,   143,   144,
     145,    -1,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,   156,   157,   158,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    79,    -1,    -1,    -1,    83,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    92,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   130,   131,    -1,   133,   134,   135,    -1,   137,
     138,   139,    -1,   141,   142,   143,   144,   145,    -1,   147,
     148,   149,   150,   151,   152,   153,    -1,    79,   156,   157,
     158,    83,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      92,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
      -1,   133,   134,   135,    -1,   137,   138,   139,    -1,   141,
     142,   143,   144,   145,    -1,   147,   148,   149,   150,   151,
     152,   153,    -1,    79,   156,   157,   158,    83,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    92,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,    -1,   133,   134,   135,
      -1,   137,   138,   139,    -1,   141,   142,   143,   144,   145,
      -1,   147,   148,   149,   150,   151,   152,   153,    -1,    79,
     156,   157,   158,    83,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    92,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,    -1,   133,   134,   135,    -1,   137,   138,   139,
      -1,   141,   142,   143,   144,   145,    -1,   147,   148,   149,
     150,   151,   152,   153,    -1,    79,   156,   157,   158,    83,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    92,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   130,   131,    -1,   133,
     134,   135,    -1,   137,   138,   139,    -1,   141,   142,   143,
     144,   145,    -1,   147,   148,   149,   150,   151,   152,   153,
      -1,    79,   156,   157,   158,    83,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    92,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,   130,   131,    -1,   133,   134,   135,    -1,   137,
     138,   139,    -1,   141,   142,   143,   144,   145,    -1,   147,
     148,   149,   150,   151,   152,   153,    -1,    79,   156,   157,
     158,    83,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
      -1,   133,   134,   135,    -1,   137,   138,   139,    -1,   141,
     142,   143,   144,   145,    -1,   147,   148,   149,   150,   151,
     152,   153,    -1,    79,   156,   157,   158,    83,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,    -1,   133,   134,   135,
      -1,   137,   138,   139,    -1,   141,   142,   143,   144,   145,
      29,   147,   148,   149,   150,   151,   152,   153,    -1,    79,
     156,   157,   158,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,
      79,    -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,
     130,   131,    -1,   133,   134,   135,    -1,   137,   138,   139,
      -1,   141,   142,   143,   144,   145,    -1,   147,   148,   149,
     150,   151,   152,   153,    -1,   114,   156,   157,   158,    -1,
      79,    -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,    -1,   133,   134,   135,    -1,   137,   138,
     139,    -1,   141,   142,   143,   144,    -1,    -1,   147,   148,
     149,   150,   151,   152,   153,   114,    -1,   156,   157,   158,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,    -1,   133,   134,   135,    -1,   137,   138,
     139,    -1,   141,   142,   143,   144,    -1,    -1,   147,   148,
     149,   150,   151,     1,   153,     3,    -1,   156,   157,   158,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    -1,
      18,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    -1,    -1,    -1,    42,    -1,    44,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      -1,    89,    -1,    91,    -1,    93,    -1,    -1,    96,    -1,
      -1,    -1,   100,    -1,    -1,   103,    -1,    -1,   106
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
     187,   191,   193,   197,   198,   199,   200,   201,   202,   204,
     205,   206,   210,   211,   214,   215,   218,   219,   222,   225,
     226,   252,   255,   256,   276,   277,   278,   279,   280,   281,
     282,   290,   291,   292,   293,   296,   297,   298,   299,   300,
     301,   302,   304,   305,   306,   307,   308,   155,   174,   293,
     110,   283,   284,     3,   188,    12,    38,    39,    41,    91,
     160,   164,   222,   276,   281,   291,   292,   293,   296,   298,
     299,   283,   293,    99,   255,    80,   188,   174,   270,   293,
     174,   162,   293,   294,     7,     9,    99,   195,   294,    69,
     112,   203,   293,   203,   293,    24,    36,   256,   293,   293,
     162,     3,    15,    16,    18,    23,    31,    37,    42,    44,
      47,    55,    61,    62,    68,    77,    86,    87,    89,    91,
      93,    96,   100,   103,   106,   190,   192,   223,   162,   190,
     257,   258,    30,   179,   196,   293,   293,   293,   293,   293,
     293,     7,   162,    36,   199,   199,   154,   245,   269,   293,
      97,    98,   155,   293,   295,   293,   196,   293,   293,   293,
      90,   162,   174,   293,   293,   179,   187,   293,   296,   179,
     187,   293,   190,   253,   293,   293,   293,   293,   293,   293,
     293,   293,     1,   161,   172,   180,   269,   101,   140,   245,
     271,   272,   295,   203,   269,   293,   303,    71,   174,   160,
      75,   178,   104,   190,   190,    48,    74,   240,   257,   154,
     155,   146,    10,    17,    29,    79,    83,   114,   130,   131,
     133,   134,   135,   137,   138,   139,   141,   142,   143,   144,
     145,   147,   148,   149,   150,   151,   152,   153,   156,   157,
     158,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   159,   232,   162,   164,
      79,    83,   162,   174,   155,   293,   293,   293,   269,   160,
     179,    43,   283,   253,   257,   155,   136,   155,   109,   191,
     245,   273,   274,   275,   295,   253,   215,   255,   190,   162,
     196,    30,    43,   196,   110,   196,   286,    30,    43,   196,
     286,   294,    34,    64,   155,    92,   179,   232,   273,   174,
     162,   234,   101,   162,   190,   259,   260,     1,   135,   264,
      43,   136,   174,   196,   196,   273,   190,   136,   155,   293,
     293,   155,   160,   196,   162,   273,   155,   207,   155,   207,
     155,   115,   254,   155,   196,   155,   161,   161,   172,   136,
     161,   293,   136,   163,   136,   163,   165,   286,    43,   136,
     165,   286,   113,   136,   165,     7,     1,   161,   180,    57,
     269,   293,   135,   216,   160,   227,   155,   293,   293,   293,
     293,   203,   293,   203,   293,   293,   293,   293,   293,   293,
     293,    18,    31,    55,    99,   191,   293,   154,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   154,   293,   293,
     293,   293,   293,   293,   295,   295,   295,   295,   295,   273,
     273,   203,   293,   203,   293,    25,    43,    80,   105,   285,
     288,   289,   293,   308,    30,    43,    30,    43,    92,    43,
     165,   203,   293,   196,   155,   155,   293,   293,   115,   163,
     136,   155,   190,   257,    43,   269,    41,   293,   203,   293,
     162,   196,    41,   293,   203,   293,   196,   158,   181,   183,
     293,   181,   182,   174,   293,    32,   293,   163,    25,    43,
      46,    66,    69,    80,    99,   173,   235,   236,   237,   238,
     224,   260,   136,   163,    31,    44,    87,    91,   164,   194,
     265,   277,   115,   261,   293,   258,   163,   245,   293,     1,
     212,   273,   163,    19,   208,   265,   277,   136,   161,   163,
     163,   271,   163,   271,   174,   165,   203,   293,   165,   174,
     293,   165,   293,   165,   293,   161,   161,   190,   155,    34,
      64,   269,   160,     1,   190,   220,   221,    25,    69,    80,
      99,   229,   239,   162,   155,   155,   155,   155,   155,   163,
     165,    43,    80,   136,   163,   276,    79,    79,    41,   203,
     293,    41,   203,   293,   203,   293,   283,   283,   155,   245,
     295,   275,   216,   155,   293,   163,   293,    30,   196,    30,
     196,   287,   288,   293,    30,   196,   286,    30,   196,   286,
     136,   155,    11,   155,    32,    32,   174,    92,   179,    43,
      80,   237,   136,   163,   162,   190,    25,    69,    80,    99,
     241,   163,   260,   264,     1,   269,    60,   295,   161,    65,
     107,   161,   213,   163,   162,   179,   190,   209,   253,   174,
     165,   286,   165,   286,   174,   113,   183,   182,     1,   217,
     161,   115,   136,   161,    80,   228,     1,     3,    10,    15,
      17,    18,    23,    37,    42,    47,    49,    55,    61,    62,
      77,    89,    93,    96,   100,   106,   130,   131,   132,   133,
     134,   137,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   153,   156,   157,   158,   159,   162,   189,
     190,   192,   230,   231,   232,   276,   163,   288,   264,   276,
     276,   293,    30,    30,   293,    30,    30,   165,   165,   196,
     196,   160,   196,    92,    41,   293,    41,   293,   136,   163,
      92,    41,   293,   196,    41,   293,   196,   293,   293,   174,
     293,   174,    32,   190,   236,   260,   135,   268,    80,   264,
     261,   165,    43,   165,    30,   174,   269,   209,   135,   179,
      41,   174,   293,   165,    41,   174,   293,   165,   293,   155,
     155,   161,    36,    73,    76,   161,   173,   198,   293,   221,
     241,   162,   233,   190,   293,   130,   138,   233,   233,   261,
      92,    41,    41,    92,    41,    41,    41,    41,     1,   217,
     293,   293,   293,   288,   293,   293,   293,    11,    32,   174,
     268,   163,   164,   194,   245,   267,   277,   140,   247,   261,
      53,   108,   248,   293,   265,   277,   174,   196,   163,   293,
     293,   174,   293,   174,   198,     1,   135,   263,   235,   163,
       3,    93,   231,   232,   293,   293,   293,   293,   293,   293,
     161,   161,    92,    92,    92,    92,   293,   174,   261,   268,
     165,   269,   245,   246,   293,     3,    82,    93,   249,   250,
     251,   293,   179,   197,   244,   165,   179,    92,    92,   164,
     194,   262,   277,    95,   242,   163,   233,   233,    92,    92,
      92,    92,    92,    92,   293,   293,   293,   293,   247,   261,
     245,   266,   267,   277,    43,   165,   251,   108,   136,   115,
     141,   143,   144,   147,   148,    53,   277,   293,   293,     1,
     165,   269,   248,   293,   266,   267,   293,   250,   251,   251,
     251,   251,   251,   251,   249,   165,   262,   277,   165,   155,
     243,   244,   165,   262,   277,   266
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
     194,   194,   194,   195,   195,   196,   196,   197,   197,   198,
     198,   198,   198,   198,   198,   198,   198,   199,   199,   200,
     200,   200,   200,   201,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     203,   204,   204,   204,   204,   204,   204,   204,   204,   205,
     206,   206,   206,   206,   206,   206,   207,   207,   208,   208,
     208,   209,   209,   210,   211,   211,   212,   212,   213,   213,
     213,   214,   214,   214,   214,   215,   215,   215,   216,   216,
     217,   217,   217,   218,   218,   219,   220,   220,   220,   221,
     221,   223,   224,   222,   225,   225,   225,   225,   225,   227,
     228,   226,   229,   229,   229,   229,   229,   230,   230,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   233,
     233,   234,   235,   235,   235,   236,   236,   236,   236,   236,
     237,   237,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   239,   239,   239,   239,   239,   239,   240,   240,   241,
     241,   241,   241,   241,   241,   242,   242,   243,   243,   244,
     244,   245,   245,   246,   246,   247,   247,   248,   248,   248,
     248,   248,   249,   249,   250,   250,   250,   250,   250,   250,
     250,   251,   251,   252,   252,   252,   253,   253,   254,   254,
     254,   255,   255,   255,   255,   255,   256,   256,   256,   257,
     257,   258,   258,   259,   259,   259,   260,   260,   260,   261,
     261,   261,   262,   262,   262,   262,   262,   262,   262,   263,
     263,   263,   263,   263,   264,   264,   264,   264,   264,   265,
     265,   265,   265,   266,   266,   266,   267,   267,   267,   267,
     267,   268,   268,   268,   268,   268,   269,   269,   269,   269,
     270,   270,   271,   271,   271,   272,   272,   273,   273,   274,
     274,   275,   275,   275,   275,   276,   276,   277,   277,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   280,   281,   282,   282,
     282,   282,   282,   282,   282,   282,   283,   283,   284,   285,
     285,   286,   287,   287,   288,   288,   288,   289,   289,   289,
     289,   289,   289,   290,   290,   291,   292,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   294,   294,   295,   295,   295,   296,   296,   296,   296,
     297,   297,   297,   298,   298,   298,   299,   299,   299,   299,
     299,   300,   300,   300,   300,   301,   301,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     303,   303,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   305,   305,   305,
     305,   305,   305,   305,   306,   306,   306,   306,   307,   307,
     307,   307,   308,   308,   308,   308,   308,   308,   308
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
       1,     1,     1,     0,     1,     2,     1,     2,     3,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     3,
       5,     5,     2,     2,     5,     3,     6,     6,     4,     5,
       5,     3,     3,     6,     5,     6,     5,     6,     3,     4,
       3,     4,     6,     7,     6,     7,     4,     5,     4,     5,
       4,     4,     3,     6,     5,     6,     5,     8,     7,     2,
       3,     3,     2,     2,     3,     3,     0,     2,     2,     3,
       5,     1,     3,     3,     5,     5,     0,     2,     3,     2,
       3,     6,     8,     6,     8,     1,     1,     1,     0,     2,
       0,     2,     3,     5,     5,     1,     1,     2,     3,     1,
       3,     0,     0,     8,     0,     1,     2,     2,     1,     0,
       0,    10,     3,     3,     5,     5,     3,     1,     3,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       3,     3,     0,     1,     3,     4,     5,     4,     6,     6,
       0,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       1,     0,     1,     1,     2,     1,     1,     1,     1,     0,
       1,     2,     1,     1,     1,     0,     1,     1,     1,     1,
       1,     2,     1,     0,     1,     2,     2,     0,     2,     2,
       4,     4,     1,     3,     3,     3,     3,     3,     3,     3,
       2,     1,     1,     3,     4,     4,     2,     4,     0,     2,
       2,     1,     1,     1,     2,     1,     4,     5,     3,     1,
       3,     3,     5,     1,     1,     3,     1,     2,     3,     0,
       2,     2,     3,     2,     4,     3,     3,     4,     3,     0,
       2,     2,     2,     1,     0,     2,     2,     2,     1,     4,
       4,     6,     3,     0,     1,     1,     3,     4,     3,     4,
       6,     0,     2,     2,     2,     2,     1,     1,     3,     3,
       1,     3,     1,     1,     1,     3,     3,     0,     1,     1,
       3,     3,     3,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     2,     4,     4,     4,     5,     2,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     6,
       6,     4,     9,     9,     7,     6,     6,     4,     9,     9,
       7,     4,     6,     6,     9,     9,     6,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     1,     4,     1,
       3,     4,     1,     3,     4,     3,     3,     1,     1,     2,
       1,     2,     1,     1,     3,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     3,     2,     2,
       1,     0,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     2,     1,     4,     4,     4,     3,     3,     3,     3,
       5,     3,     4,     3,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     4,     3,     4,     3,     4,
       3,     5,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1
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
#line 486 "chapel.ypp" /* yacc.c:1667  */
    { yyblock = (yyval.pblockstmt); }
#line 5893 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 3:
#line 491 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = new BlockStmt(); resetTempID(); }
#line 5899 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 4:
#line 492 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-1].pblockstmt)->appendChapelStmt((yyvsp[0].pblockstmt)); context->generatedStmt = (yyvsp[-1].pblockstmt); resetTempID(); }
#line 5905 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 6:
#line 499 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildPragmaStmt( (yyvsp[-1].vpch), (yyvsp[0].pblockstmt) ); }
#line 5911 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 7:
#line 504 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.vpch) = new Vec<const char*>(); (yyval.vpch)->add(astr((yyvsp[0].pch))); }
#line 5917 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 8:
#line 505 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-2].vpch)->add(astr((yyvsp[0].pch))); }
#line 5923 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 23:
#line 524 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildChapelStmt((yyvsp[-1].pexpr)); }
#line 5929 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 24:
#line 525 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildAtomicStmt((yyvsp[0].pblockstmt)); }
#line 5935 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 25:
#line 526 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildBeginStmt((yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt)); }
#line 5941 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 26:
#line 527 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildGotoStmt(GOTO_BREAK, (yyvsp[-1].pch)); }
#line 5947 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 27:
#line 528 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildCobeginStmt((yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt));  }
#line 5953 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 28:
#line 529 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildGotoStmt(GOTO_CONTINUE, (yyvsp[-1].pch)); }
#line 5959 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 29:
#line 530 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildDeleteStmt((yyvsp[-1].pcallexpr)); }
#line 5965 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 30:
#line 531 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildLabelStmt((yyvsp[-1].pch), (yyvsp[0].pblockstmt)); }
#line 5971 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 31:
#line 532 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildLocalStmt((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 5977 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 32:
#line 533 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildLocalStmt((yyvsp[0].pblockstmt)); }
#line 5983 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 33:
#line 534 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildOnStmt((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 5989 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 34:
#line 535 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildSerialStmt((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 5995 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 35:
#line 536 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildSerialStmt(new SymExpr(gTrue), (yyvsp[0].pblockstmt)); }
#line 6001 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 36:
#line 537 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildSyncStmt((yyvsp[0].pblockstmt)); }
#line 6007 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 37:
#line 538 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_YIELD, (yyvsp[-1].pexpr)); }
#line 6013 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 38:
#line 539 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildErrorStandin(); }
#line 6019 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 39:
#line 544 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pmodsymbol) = buildModule((yyvsp[0].pch), currentModuleType, NULL, yyfilename, (yyvsp[-3].b), (yyvsp[-2].b), (yylsp[-3]).comment);
      // store previous module name in order to restore it once we're
      // done with this module in module_decl_stmt below.  Ultimately,
      // we will need to store a stack of module names in order to
      // support full module path resolution of -s config flags.
      (yyloc).prevModule = currentModuleName;
      currentModuleName = (yyvsp[0].pch);
    }
#line 6033 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 40:
#line 557 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-2].pmodsymbol)->block = new BlockStmt();
      (yyval.pblockstmt) = buildChapelStmt(new DefExpr((yyvsp[-2].pmodsymbol)));
      currentModuleName = (yylsp[-2]).prevModule;  // restore previous module name
    }
#line 6042 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 41:
#line 562 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-3].pmodsymbol)->block = (yyvsp[-1].pblockstmt);
      (yyval.pblockstmt) = buildChapelStmt(new DefExpr((yyvsp[-3].pmodsymbol)));
      currentModuleName = (yylsp[-3]).prevModule;  // restore previous module name
    }
#line 6051 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 42:
#line 567 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-3].pmodsymbol)->block = buildErrorStandin();
      (yyval.pblockstmt) = buildChapelStmt(new DefExpr((yyvsp[-3].pmodsymbol)));
      currentModuleName = (yylsp[-3]).prevModule;  // restore previous module name
    }
#line 6060 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 43:
#line 574 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.b) = false; (yyloc).comment = context->latestComment; context->latestComment = NULL; }
#line 6066 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 44:
#line 575 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.b) = false; (yyloc).comment = context->latestComment; context->latestComment = NULL; }
#line 6072 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 45:
#line 576 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.b) = true; (yyloc).comment = context->latestComment; context->latestComment = NULL; }
#line 6078 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 46:
#line 580 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.b) = false; }
#line 6084 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 47:
#line 581 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.b) = true;  }
#line 6090 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 48:
#line 594 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = new BlockStmt(); }
#line 6096 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 49:
#line 595 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = (yyvsp[-1].pblockstmt);              }
#line 6102 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 50:
#line 596 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildErrorStandin(); }
#line 6108 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 51:
#line 601 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = new BlockStmt(); (yyval.pblockstmt)->appendChapelStmt((yyvsp[0].pblockstmt)); }
#line 6114 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 52:
#line 602 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-1].pblockstmt)->appendChapelStmt((yyvsp[0].pblockstmt)); }
#line 6120 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 53:
#line 607 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.ponlylist) = new std::vector<OnlyRename*>();
                                         OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::SINGLE;
                                         cur->elem = (yyvsp[0].pexpr);
                                         (yyval.ponlylist)->push_back(cur); }
#line 6130 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 54:
#line 612 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.ponlylist) = new std::vector<OnlyRename*>();
                                         OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::DOUBLE;
                                         cur->renamed = new std::pair<Expr*, Expr*>((yyvsp[-2].pexpr), (yyvsp[0].pexpr));
                                         (yyval.ponlylist)->push_back(cur); }
#line 6140 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 55:
#line 617 "chapel.ypp" /* yacc.c:1667  */
    { OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::SINGLE;
                                         cur->elem = (yyvsp[0].pexpr);
                                         (yyvsp[-2].ponlylist)->push_back(cur); }
#line 6149 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 56:
#line 621 "chapel.ypp" /* yacc.c:1667  */
    { OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::DOUBLE;
                                         cur->renamed = new std::pair<Expr*, Expr*>((yyvsp[-2].pexpr), (yyvsp[0].pexpr));
                                         (yyvsp[-4].ponlylist)->push_back(cur); }
#line 6158 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 57:
#line 628 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.ponlylist) = new std::vector<OnlyRename*>();
                                         OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::SINGLE;
                                         cur->elem = new UnresolvedSymExpr("");
                                         (yyval.ponlylist)->push_back(cur); }
#line 6168 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 59:
#line 637 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.ponlylist) = new std::vector<OnlyRename*>();
                                         OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::SINGLE;
                                         cur->elem = new UnresolvedSymExpr("");
                                         (yyval.ponlylist)->push_back(cur); }
#line 6178 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 61:
#line 646 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.b) = false; }
#line 6184 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 62:
#line 647 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.b) = false; }
#line 6190 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 63:
#line 648 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.b) = true; }
#line 6196 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 64:
#line 652 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildUseStmt((yyvsp[-1].pcallexpr), (yyvsp[-3].b)); }
#line 6202 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 65:
#line 653 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildUseStmt((yyvsp[-3].pexpr), (yyvsp[-1].ponlylist), true, (yyvsp[-5].b)); }
#line 6208 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 66:
#line 654 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildUseStmt((yyvsp[-3].pexpr), (yyvsp[-1].ponlylist), false, (yyvsp[-5].b)); }
#line 6214 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 67:
#line 658 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildRequireStmt((yyvsp[-1].pcallexpr)); }
#line 6220 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 68:
#line 663 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), (yyvsp[-2].pch));   }
#line 6226 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 69:
#line 665 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), "<=>"); }
#line 6232 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 70:
#line 667 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), PRIM_REDUCE_ASSIGN); }
#line 6238 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 71:
#line 669 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildLAndAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr));    }
#line 6244 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 72:
#line 671 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildLOrAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr));     }
#line 6250 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 73:
#line 677 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = NULL; }
#line 6256 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 74:
#line 678 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 6262 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 75:
#line 682 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 6268 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 76:
#line 683 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "none"; redefiningReservedWordError((yyval.pch)); }
#line 6274 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 77:
#line 684 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "this"; }
#line 6280 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 78:
#line 685 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "false"; redefiningReservedWordError((yyval.pch)); }
#line 6286 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 79:
#line 686 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "true"; redefiningReservedWordError((yyval.pch)); }
#line 6292 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 80:
#line 687 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = (yyvsp[0].pch); redefiningReservedTypeError((yyvsp[0].pch)); }
#line 6298 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 81:
#line 690 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 6304 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 82:
#line 691 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "none"; redefiningReservedWordError((yyval.pch)); }
#line 6310 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 83:
#line 692 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "this"; redefiningReservedWordError((yyval.pch)); }
#line 6316 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 84:
#line 693 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "false"; redefiningReservedWordError((yyval.pch)); }
#line 6322 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 85:
#line 694 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "true"; redefiningReservedWordError((yyval.pch)); }
#line 6328 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 86:
#line 695 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = (yyvsp[0].pch); redefiningReservedTypeError((yyvsp[0].pch)); }
#line 6334 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 87:
#line 707 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 6340 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 88:
#line 708 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "this"; }
#line 6346 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 89:
#line 719 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "bool"; }
#line 6352 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 90:
#line 720 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "int"; }
#line 6358 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 91:
#line 721 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "uint"; }
#line 6364 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 92:
#line 722 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "real"; }
#line 6370 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 93:
#line 723 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "imag"; }
#line 6376 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 94:
#line 724 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "complex"; }
#line 6382 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 95:
#line 725 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "bytes"; }
#line 6388 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 96:
#line 726 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "string"; }
#line 6394 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 97:
#line 727 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "sync"; }
#line 6400 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 98:
#line 728 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "single"; }
#line 6406 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 99:
#line 729 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "owned"; }
#line 6412 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 100:
#line 730 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "shared"; }
#line 6418 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 101:
#line 731 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "borrowed"; }
#line 6424 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 102:
#line 732 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "unmanaged"; }
#line 6430 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 103:
#line 733 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "domain"; }
#line 6436 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 104:
#line 734 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "index"; }
#line 6442 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 105:
#line 735 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "locale"; }
#line 6448 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 106:
#line 736 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "nothing"; }
#line 6454 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 107:
#line 737 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "void"; }
#line 6460 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 108:
#line 741 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtBools[BOOL_SIZE_DEFAULT]->symbol); }
#line 6466 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 109:
#line 742 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtInt[INT_SIZE_DEFAULT]->symbol); }
#line 6472 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 110:
#line 743 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtUInt[INT_SIZE_DEFAULT]->symbol); }
#line 6478 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 111:
#line 744 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtReal[FLOAT_SIZE_DEFAULT]->symbol); }
#line 6484 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 112:
#line 745 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtImag[FLOAT_SIZE_DEFAULT]->symbol); }
#line 6490 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 113:
#line 746 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtComplex[COMPLEX_SIZE_DEFAULT]->symbol); }
#line 6496 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 114:
#line 747 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtBytes->symbol); }
#line 6502 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 115:
#line 748 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtString->symbol); }
#line 6508 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 116:
#line 749 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtLocale->symbol); }
#line 6514 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 117:
#line 750 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtNothing->symbol); }
#line 6520 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 118:
#line 751 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtVoid->symbol); }
#line 6526 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 119:
#line 758 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "_syncvar"; }
#line 6532 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 120:
#line 759 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "_singlevar"; }
#line 6538 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 121:
#line 764 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "_domain"; }
#line 6544 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 122:
#line 765 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "_index"; }
#line 6550 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 123:
#line 770 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = NULL; }
#line 6556 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 124:
#line 771 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 6562 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 125:
#line 775 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = (yyvsp[0].pblockstmt); }
#line 6568 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 126:
#line 776 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = (yyvsp[0].pblockstmt); }
#line 6574 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 127:
#line 780 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_RETURN); }
#line 6580 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 128:
#line 781 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_RETURN, (yyvsp[-1].pexpr)); }
#line 6586 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 129:
#line 785 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildChapelStmt(new BlockStmt()); }
#line 6592 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 131:
#line 787 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = (yyvsp[0].pblockstmt); }
#line 6598 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 132:
#line 788 "chapel.ypp" /* yacc.c:1667  */
    { applyPrivateToBlock((yyvsp[0].pblockstmt)); (yyval.pblockstmt) = (yyvsp[0].pblockstmt); }
#line 6604 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 139:
#line 801 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildForwardingStmt((yyvsp[-1].pexpr)); }
#line 6610 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 140:
#line 802 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildForwardingStmt((yyvsp[-3].pexpr), (yyvsp[-1].ponlylist), true); }
#line 6616 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 141:
#line 803 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildForwardingStmt((yyvsp[-3].pexpr), (yyvsp[-1].ponlylist), false); }
#line 6622 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 142:
#line 804 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildForwardingDeclStmt((yyvsp[0].pblockstmt)); }
#line 6628 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 143:
#line 809 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = buildExternBlockStmt(astr((yyvsp[0].pch)));
    }
#line 6636 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 144:
#line 815 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = DoWhileStmt::build((yyvsp[-1].pexpr), (yyvsp[-3].pblockstmt)); }
#line 6642 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 145:
#line 816 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = WhileDoStmt::build((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 6648 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 146:
#line 817 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildCoforallLoopStmt((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt));       }
#line 6654 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 147:
#line 818 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildCoforallLoopStmt((yyvsp[-4].pexpr), (yyvsp[-2].pcallexpr), (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt), true); }
#line 6660 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 148:
#line 819 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildCoforallLoopStmt(NULL, (yyvsp[-2].pexpr), (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt));     }
#line 6666 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 149:
#line 820 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForLoop::buildForLoop(  (yyvsp[-3].pexpr), (yyvsp[-1].pexpr), (yyvsp[0].pblockstmt), false, false); }
#line 6672 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 150:
#line 821 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForLoop::buildForLoop(  (yyvsp[-3].pexpr), (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt), false,  true); }
#line 6678 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 151:
#line 822 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForLoop::buildForLoop(NULL, (yyvsp[-1].pexpr), (yyvsp[0].pblockstmt), false, false); }
#line 6684 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 152:
#line 823 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForLoop::buildForLoop(NULL, (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt), false,  true); }
#line 6690 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 153:
#line 824 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildParamForLoopStmt((yyvsp[-3].pch), (yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 6696 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 154:
#line 825 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForallStmt::build((yyvsp[-3].pexpr),   (yyvsp[-1].pexpr), NULL, (yyvsp[0].pblockstmt), false, false); }
#line 6702 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 155:
#line 826 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForallStmt::build((yyvsp[-4].pexpr),   (yyvsp[-2].pexpr), (yyvsp[-1].pcallexpr),   (yyvsp[0].pblockstmt), false, false); }
#line 6708 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 156:
#line 827 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForallStmt::build((yyvsp[-3].pexpr),   (yyvsp[-1].pcallexpr), NULL, (yyvsp[0].pblockstmt), true,  false); }
#line 6714 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 157:
#line 828 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForallStmt::build((yyvsp[-4].pexpr),   (yyvsp[-2].pcallexpr), (yyvsp[-1].pcallexpr),   (yyvsp[0].pblockstmt), true,  false); }
#line 6720 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 158:
#line 829 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-1].pexpr), NULL, (yyvsp[0].pblockstmt), false, false); }
#line 6726 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 159:
#line 830 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-2].pexpr), (yyvsp[-1].pcallexpr),   (yyvsp[0].pblockstmt), false, false); }
#line 6732 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 160:
#line 831 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-1].pcallexpr), NULL, (yyvsp[0].pblockstmt), true,  false); }
#line 6738 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 161:
#line 832 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-2].pcallexpr), (yyvsp[-1].pcallexpr),   (yyvsp[0].pblockstmt), true,  false); }
#line 6744 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 162:
#line 834 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pexpr), "invalid index expression");
      (yyval.pblockstmt) = ForallStmt::build((yyvsp[-4].pcallexpr)->get(1)->remove(), (yyvsp[-2].pexpr), NULL, new BlockStmt((yyvsp[0].pblockstmt)), false, true);
    }
#line 6754 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 163:
#line 840 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-5].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-3].pexpr), "invalid index expression");
      (yyval.pblockstmt) = ForallStmt::build((yyvsp[-5].pcallexpr)->get(1)->remove(), (yyvsp[-3].pexpr), (yyvsp[-2].pcallexpr),   new BlockStmt((yyvsp[0].pblockstmt)), false, true);
    }
#line 6764 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 164:
#line 846 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pcallexpr), "invalid index expression");
      (yyval.pblockstmt) = ForallStmt::build((yyvsp[-4].pcallexpr)->get(1)->remove(), (yyvsp[-2].pcallexpr), NULL, new BlockStmt((yyvsp[0].pblockstmt)), true,  true);
    }
#line 6774 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 165:
#line 852 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-5].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-3].pcallexpr), "invalid index expression");
      (yyval.pblockstmt) = ForallStmt::build((yyvsp[-5].pcallexpr)->get(1)->remove(), (yyvsp[-3].pcallexpr), (yyvsp[-2].pcallexpr),   new BlockStmt((yyvsp[0].pblockstmt)), true,  true);
    }
#line 6784 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 166:
#line 858 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-2].pcallexpr)->argList.length > 1)
        (yyval.pblockstmt) = ForallStmt::build(NULL, new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), NULL, new BlockStmt((yyvsp[0].pblockstmt)), false, true);
      else
        (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-2].pcallexpr)->get(1)->remove(),                       NULL, new BlockStmt((yyvsp[0].pblockstmt)), false, true);
    }
#line 6795 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 167:
#line 865 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-3].pcallexpr)->argList.length > 1)
        (yyval.pblockstmt) = ForallStmt::build(NULL, new CallExpr("chpl__ensureDomainExpr", (yyvsp[-3].pcallexpr)), (yyvsp[-2].pcallexpr), new BlockStmt((yyvsp[0].pblockstmt)), false, true);
      else
        (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-3].pcallexpr)->get(1)->remove(),                       (yyvsp[-2].pcallexpr), new BlockStmt((yyvsp[0].pblockstmt)), false, true);
    }
#line 6806 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 168:
#line 872 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-2].pcallexpr), NULL, new BlockStmt((yyvsp[0].pblockstmt)), true,  true);
    }
#line 6814 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 169:
#line 876 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-3].pcallexpr), (yyvsp[-2].pcallexpr),   new BlockStmt((yyvsp[0].pblockstmt)), true,  true);
    }
#line 6822 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 170:
#line 882 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ZIP, (yyvsp[-1].pcallexpr)); }
#line 6828 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 171:
#line 886 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[-2].pexpr), (yyvsp[0].pblockstmt)); }
#line 6834 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 172:
#line 887 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 6840 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 173:
#line 888 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[-4].pexpr), (yyvsp[-2].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 6846 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 174:
#line 889 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[-3].pexpr), (yyvsp[-2].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 6852 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 175:
#line 890 "chapel.ypp" /* yacc.c:1667  */
    {
(yyval.pblockstmt) = buildIfStmt(convertAssignmentAndWarn((yyvsp[-4].pexpr),(yyvsp[-3].pch),(yyvsp[-2].pexpr)), (yyvsp[0].pblockstmt)); }
#line 6859 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 176:
#line 892 "chapel.ypp" /* yacc.c:1667  */
    {
(yyval.pblockstmt) = buildIfStmt(convertAssignmentAndWarn((yyvsp[-3].pexpr),(yyvsp[-2].pch),(yyvsp[-1].pexpr)), (yyvsp[0].pblockstmt)); }
#line 6866 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 177:
#line 894 "chapel.ypp" /* yacc.c:1667  */
    {
(yyval.pblockstmt) = buildIfStmt(convertAssignmentAndWarn((yyvsp[-6].pexpr),(yyvsp[-5].pch),(yyvsp[-4].pexpr)), (yyvsp[-2].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 6873 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 178:
#line 896 "chapel.ypp" /* yacc.c:1667  */
    {
(yyval.pblockstmt) = buildIfStmt(convertAssignmentAndWarn((yyvsp[-5].pexpr),(yyvsp[-4].pch),(yyvsp[-3].pexpr)), (yyvsp[-2].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 6880 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 179:
#line 901 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = DeferStmt::build((yyvsp[0].pblockstmt)); }
#line 6886 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 180:
#line 904 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = TryStmt::build(false, (yyvsp[-1].pexpr)); }
#line 6892 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 181:
#line 905 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = TryStmt::build(true,  (yyvsp[-1].pexpr)); }
#line 6898 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 182:
#line 906 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = TryStmt::build(false, (yyvsp[0].pblockstmt)); }
#line 6904 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 183:
#line 907 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = TryStmt::build(true,  (yyvsp[0].pblockstmt)); }
#line 6910 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 184:
#line 908 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = TryStmt::build(false, (yyvsp[-1].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 6916 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 185:
#line 909 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = TryStmt::build(true,  (yyvsp[-1].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 6922 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 186:
#line 913 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildChapelStmt(); }
#line 6928 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 187:
#line 914 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-1].pblockstmt)->insertAtTail((yyvsp[0].pexpr)); }
#line 6934 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 188:
#line 918 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = CatchStmt::build((yyvsp[0].pblockstmt)); }
#line 6940 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 189:
#line 919 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = CatchStmt::build((yyvsp[-1].pdefexpr), (yyvsp[0].pblockstmt)); }
#line 6946 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 190:
#line 920 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = CatchStmt::build((yyvsp[-2].pdefexpr), (yyvsp[0].pblockstmt)); }
#line 6952 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 191:
#line 924 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pdefexpr) = new DefExpr(new VarSymbol((yyvsp[0].pch)), NULL, new UnresolvedSymExpr("Error")); }
#line 6958 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 192:
#line 925 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pdefexpr) = new DefExpr(new VarSymbol((yyvsp[-2].pch)), NULL, (yyvsp[0].pexpr));   }
#line 6964 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 193:
#line 929 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_THROW, (yyvsp[-1].pexpr)); }
#line 6970 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 194:
#line 933 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildChapelStmt(buildSelectStmt((yyvsp[-3].pexpr), (yyvsp[-1].pblockstmt))); }
#line 6976 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 195:
#line 935 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildErrorStandin(); }
#line 6982 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 196:
#line 939 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildChapelStmt(); }
#line 6988 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 197:
#line 940 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-1].pblockstmt)->insertAtTail((yyvsp[0].pexpr)); }
#line 6994 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 198:
#line 945 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CondStmt(new CallExpr(PRIM_WHEN, (yyvsp[-1].pcallexpr)), (yyvsp[0].pblockstmt)); }
#line 7000 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 199:
#line 947 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CondStmt(new CallExpr(PRIM_WHEN), (yyvsp[0].pblockstmt)); }
#line 7006 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 200:
#line 949 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CondStmt(new CallExpr(PRIM_WHEN), (yyvsp[0].pblockstmt)); }
#line 7012 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 201:
#line 956 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = buildChapelStmt(buildClassDefExpr((yyvsp[-4].pch),
                                             NULL,
                                             (yyvsp[-5].aggrTag),
                                             (yyvsp[-3].pcallexpr),
                                             (yyvsp[-1].pblockstmt),
                                             FLAG_UNKNOWN,
                                             (yylsp[-5]).comment));
    }
#line 7026 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 202:
#line 966 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = buildChapelStmt(buildClassDefExpr((yyvsp[-4].pch),
                                             (yyvsp[-6].pch),
                                             (yyvsp[-5].aggrTag),
                                             (yyvsp[-3].pcallexpr),
                                             (yyvsp[-1].pblockstmt),
                                             FLAG_EXTERN,
                                             (yylsp[-5]).comment));
    }
#line 7040 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 203:
#line 976 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = buildChapelStmt(buildClassDefExpr((yyvsp[-4].pch),
                                             NULL,
                                             (yyvsp[-5].aggrTag),
                                             (yyvsp[-3].pcallexpr),
                                             new BlockStmt(),
                                             FLAG_UNKNOWN,
                                             (yylsp[-5]).comment));
    }
#line 7054 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 204:
#line 986 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = buildChapelStmt(buildClassDefExpr((yyvsp[-4].pch),
                                             (yyvsp[-6].pch),
                                             (yyvsp[-5].aggrTag),
                                             (yyvsp[-3].pcallexpr),
                                             new BlockStmt(),
                                             FLAG_EXTERN,
                                             (yylsp[-5]).comment));
    }
#line 7068 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 205:
#line 998 "chapel.ypp" /* yacc.c:1667  */
    {
             (yyval.aggrTag)                     = AGGREGATE_CLASS;
             (yyloc).comment             = context->latestComment;
             context->latestComment = NULL;
           }
#line 7078 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 206:
#line 1003 "chapel.ypp" /* yacc.c:1667  */
    {
             (yyval.aggrTag)                     = AGGREGATE_RECORD;
             (yyloc).comment             = context->latestComment;
             context->latestComment = NULL;
           }
#line 7088 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 207:
#line 1008 "chapel.ypp" /* yacc.c:1667  */
    {
             (yyval.aggrTag)                     = AGGREGATE_UNION;
             (yyloc).comment             = context->latestComment;
             context->latestComment = NULL;
           }
#line 7098 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 208:
#line 1016 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = NULL; }
#line 7104 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 209:
#line 1017 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = (yyvsp[0].pcallexpr); }
#line 7110 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 210:
#line 1022 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = new BlockStmt(); }
#line 7116 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 211:
#line 1024 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-1].pblockstmt)->insertAtTail((yyvsp[0].pblockstmt)); }
#line 7122 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 212:
#line 1026 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-2].pblockstmt)->insertAtTail(buildPragmaStmt((yyvsp[-1].vpch), (yyvsp[0].pblockstmt))); }
#line 7128 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 213:
#line 1031 "chapel.ypp" /* yacc.c:1667  */
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
#line 7148 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 214:
#line 1047 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = buildErrorStandin();
    }
#line 7156 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 215:
#line 1054 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.penumtype) = new EnumType();
      (yyloc).comment = context->latestComment;
      context->latestComment = NULL;
    }
#line 7166 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 216:
#line 1063 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pvecOfDefs) = new std::vector<DefExpr*>();
      (yyval.pvecOfDefs)->push_back((yyvsp[0].pdefexpr));
      //$$->doc = context->latestComment;
      // start here for enabling documentation of enum constants
      //context->latestComment = NULL;
    }
#line 7178 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 217:
#line 1071 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pvecOfDefs) = (yyvsp[-1].pvecOfDefs);
    }
#line 7186 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 218:
#line 1075 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyvsp[-2].pvecOfDefs)->push_back((yyvsp[0].pdefexpr));
    }
#line 7194 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 219:
#line 1081 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pdefexpr) = new DefExpr(new EnumSymbol((yyvsp[0].pch))); }
#line 7200 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 220:
#line 1082 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pdefexpr) = new DefExpr(new EnumSymbol((yyvsp[-2].pch)), (yyvsp[0].pexpr)); }
#line 7206 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 221:
#line 1087 "chapel.ypp" /* yacc.c:1667  */
    {
      captureTokens = 1;
      captureString.clear();
    }
#line 7215 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 222:
#line 1092 "chapel.ypp" /* yacc.c:1667  */
    {
      captureTokens = 0;
      (yyvsp[0].pfnsymbol)->userString = astr(captureString);
    }
#line 7224 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 223:
#line 1097 "chapel.ypp" /* yacc.c:1667  */
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
#line 7246 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 224:
#line 1119 "chapel.ypp" /* yacc.c:1667  */
    {
                  (yyval.pfnsymbol) = new FnSymbol("");

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 7257 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 225:
#line 1125 "chapel.ypp" /* yacc.c:1667  */
    {
                  (yyval.pfnsymbol) = new FnSymbol("");
                  (yyval.pfnsymbol)->addFlag(FLAG_INLINE);

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 7269 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 226:
#line 1132 "chapel.ypp" /* yacc.c:1667  */
    {
                  (yyval.pfnsymbol) = buildLinkageFn(FLAG_EXPORT, (yyvsp[0].pexpr));

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 7280 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 227:
#line 1138 "chapel.ypp" /* yacc.c:1667  */
    {
                  (yyval.pfnsymbol) = buildLinkageFn(FLAG_EXTERN, (yyvsp[0].pexpr));

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 7291 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 228:
#line 1144 "chapel.ypp" /* yacc.c:1667  */
    {
                  (yyval.pfnsymbol) = new FnSymbol("");
                  (yyval.pfnsymbol)->addFlag(FLAG_OVERRIDE);

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 7303 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 229:
#line 1155 "chapel.ypp" /* yacc.c:1667  */
    {
      // Sets up to capture tokens while parsing the next grammar nonterminal.
      captureTokens = 1;
      captureString.clear();
    }
#line 7313 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 230:
#line 1161 "chapel.ypp" /* yacc.c:1667  */
    {
      // Stop capturing and save the result.
      captureTokens = 0;

      (yyvsp[0].pfnsymbol)->userString = astr(captureString);
    }
#line 7324 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 231:
#line 1168 "chapel.ypp" /* yacc.c:1667  */
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
#line 7351 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 232:
#line 1194 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), (yyvsp[-1].pch), (yyvsp[-2].pt), NULL);
    }
#line 7359 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 233:
#line 1198 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), (yyvsp[-1].pch), (yyvsp[-2].pt), NULL);
      (yyval.pfnsymbol)->addFlag(FLAG_ASSIGNOP);
    }
#line 7368 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 234:
#line 1203 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), (yyvsp[-1].pch), (yyvsp[-4].pt), (yyvsp[-3].pexpr));
    }
#line 7376 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 235:
#line 1207 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), (yyvsp[-1].pch), (yyvsp[-4].pt), (yyvsp[-3].pexpr));
      (yyval.pfnsymbol)->addFlag(FLAG_ASSIGNOP);
    }
#line 7385 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 236:
#line 1212 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), "dummy", INTENT_BLANK, NULL);
    }
#line 7393 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 238:
#line 1219 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[-1].pexpr); }
#line 7399 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 239:
#line 1223 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 7405 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 240:
#line 1224 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = astr("~", (yyvsp[0].pch)); }
#line 7411 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 241:
#line 1225 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "&"; }
#line 7417 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 242:
#line 1226 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "|"; }
#line 7423 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 243:
#line 1227 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "^"; }
#line 7429 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 244:
#line 1228 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "~"; }
#line 7435 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 245:
#line 1229 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "=="; }
#line 7441 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 246:
#line 1230 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "!="; }
#line 7447 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 247:
#line 1231 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "<="; }
#line 7453 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 248:
#line 1232 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = ">="; }
#line 7459 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 249:
#line 1233 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "<"; }
#line 7465 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 250:
#line 1234 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = ">"; }
#line 7471 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 251:
#line 1235 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "+"; }
#line 7477 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 252:
#line 1236 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "-"; }
#line 7483 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 253:
#line 1237 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "*"; }
#line 7489 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 254:
#line 1238 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "/"; }
#line 7495 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 255:
#line 1239 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "<<"; }
#line 7501 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 256:
#line 1240 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = ">>"; }
#line 7507 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 257:
#line 1241 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "%"; }
#line 7513 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 258:
#line 1242 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "**"; }
#line 7519 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 259:
#line 1243 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "!"; }
#line 7525 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 260:
#line 1244 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "chpl_by"; }
#line 7531 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 261:
#line 1245 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "#"; }
#line 7537 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 262:
#line 1246 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "chpl_align"; }
#line 7543 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 263:
#line 1247 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "<=>"; }
#line 7549 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 264:
#line 1248 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "<~>"; }
#line 7555 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 265:
#line 1249 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "init="; }
#line 7561 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 266:
#line 1250 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = astr((yyvsp[-1].pch), "!"); }
#line 7567 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 267:
#line 1254 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "="; }
#line 7573 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 268:
#line 1255 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "+="; }
#line 7579 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 269:
#line 1256 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "-="; }
#line 7585 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 270:
#line 1257 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "*="; }
#line 7591 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 271:
#line 1258 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "/="; }
#line 7597 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 272:
#line 1259 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "%="; }
#line 7603 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 273:
#line 1260 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "**="; }
#line 7609 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 274:
#line 1261 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "&="; }
#line 7615 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 275:
#line 1262 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "|="; }
#line 7621 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 276:
#line 1263 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "^="; }
#line 7627 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 277:
#line 1264 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = ">>="; }
#line 7633 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 278:
#line 1265 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "<<="; }
#line 7639 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 279:
#line 1269 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pfnsymbol) = new FnSymbol("_"); (yyval.pfnsymbol)->addFlag(FLAG_NO_PARENS); }
#line 7645 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 280:
#line 1270 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pfnsymbol) = (yyvsp[-1].pfnsymbol); }
#line 7651 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 281:
#line 1274 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pfnsymbol) = (yyvsp[-1].pfnsymbol); }
#line 7657 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 282:
#line 1278 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pfnsymbol) = buildFunctionFormal(NULL, NULL); }
#line 7663 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 283:
#line 1279 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pfnsymbol) = buildFunctionFormal(NULL, (yyvsp[0].pdefexpr)); }
#line 7669 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 284:
#line 1280 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pfnsymbol) = buildFunctionFormal((yyvsp[-2].pfnsymbol), (yyvsp[0].pdefexpr)); }
#line 7675 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 285:
#line 1285 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pdefexpr) = buildArgDefExpr((yyvsp[-3].pt), (yyvsp[-2].pch), (yyvsp[-1].pexpr), (yyvsp[0].pexpr), NULL); }
#line 7681 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 286:
#line 1287 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pdefexpr) = buildPragmaDefExpr((yyvsp[-4].vpch), buildArgDefExpr((yyvsp[-3].pt), (yyvsp[-2].pch), (yyvsp[-1].pexpr), (yyvsp[0].pexpr), NULL)); }
#line 7687 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 287:
#line 1289 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pdefexpr) = buildArgDefExpr((yyvsp[-3].pt), (yyvsp[-2].pch), (yyvsp[-1].pexpr), NULL, (yyvsp[0].pexpr)); }
#line 7693 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 288:
#line 1291 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pdefexpr) = buildTupleArgDefExpr((yyvsp[-5].pt), (yyvsp[-3].pblockstmt), (yyvsp[-1].pexpr), (yyvsp[0].pexpr)); }
#line 7699 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 289:
#line 1293 "chapel.ypp" /* yacc.c:1667  */
    { USR_FATAL("variable-length argument may not be grouped in a tuple"); }
#line 7705 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 290:
#line 1297 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_BLANK; }
#line 7711 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 291:
#line 1298 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = (yyvsp[0].pt); }
#line 7717 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 292:
#line 1302 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_IN; }
#line 7723 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 293:
#line 1303 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_INOUT; }
#line 7729 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 294:
#line 1304 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_OUT; }
#line 7735 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 295:
#line 1305 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_CONST; }
#line 7741 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 296:
#line 1306 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_CONST_IN; }
#line 7747 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 297:
#line 1307 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_CONST_REF; }
#line 7753 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 298:
#line 1308 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_PARAM; }
#line 7759 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 299:
#line 1309 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_REF; }
#line 7765 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 300:
#line 1310 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_TYPE; }
#line 7771 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 301:
#line 1314 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_BLANK; }
#line 7777 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 302:
#line 1315 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_PARAM; }
#line 7783 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 303:
#line 1316 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_REF;   }
#line 7789 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 304:
#line 1317 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_CONST_REF;   }
#line 7795 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 305:
#line 1318 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_CONST;   }
#line 7801 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 306:
#line 1319 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_TYPE;  }
#line 7807 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 307:
#line 1323 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.procIter) = ProcIter_PROC; }
#line 7813 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 308:
#line 1324 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.procIter) = ProcIter_ITER; }
#line 7819 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 309:
#line 1328 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.retTag) = RET_VALUE; }
#line 7825 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 310:
#line 1329 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.retTag) = RET_VALUE; }
#line 7831 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 311:
#line 1330 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.retTag) = RET_CONST_REF; }
#line 7837 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 312:
#line 1331 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.retTag) = RET_REF; }
#line 7843 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 313:
#line 1332 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.retTag) = RET_PARAM; }
#line 7849 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 314:
#line 1333 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.retTag) = RET_TYPE; }
#line 7855 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 315:
#line 1337 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.b) = false; }
#line 7861 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 316:
#line 1338 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.b) = true;  }
#line 7867 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 317:
#line 1341 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = NULL; }
#line 7873 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 320:
#line 1347 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = new BlockStmt((yyvsp[0].pblockstmt)); }
#line 7879 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 321:
#line 1352 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new DefExpr(new VarSymbol((yyvsp[0].pch))); }
#line 7885 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 322:
#line 1354 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(gUninstantiated); }
#line 7891 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 323:
#line 1358 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(gUninstantiated); }
#line 7897 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 325:
#line 1363 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 7903 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 326:
#line 1364 "chapel.ypp" /* yacc.c:1667  */
    { if (DefExpr* def = toDefExpr((yyvsp[0].pexpr))) {
                                 def->sym->addFlag(FLAG_PARAM);
                               }
                               (yyval.pexpr) = (yyvsp[0].pexpr);
                             }
#line 7913 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 327:
#line 1372 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.lifetimeAndWhere) = makeWhereAndLifetime(NULL, NULL); }
#line 7919 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 328:
#line 1374 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.lifetimeAndWhere) = makeWhereAndLifetime((yyvsp[0].pexpr), NULL); }
#line 7925 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 329:
#line 1376 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.lifetimeAndWhere) = makeWhereAndLifetime(NULL, (yyvsp[0].pexpr)); }
#line 7931 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 330:
#line 1378 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.lifetimeAndWhere) = makeWhereAndLifetime((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7937 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 331:
#line 1380 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.lifetimeAndWhere) = makeWhereAndLifetime((yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 7943 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 332:
#line 1384 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 7949 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 333:
#line 1385 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(",", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7955 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 334:
#line 1388 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7961 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 335:
#line 1389 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("<", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7967 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 336:
#line 1390 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("<=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7973 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 337:
#line 1391 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("==", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7979 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 338:
#line 1392 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(">", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7985 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 339:
#line 1393 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(">=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7991 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 340:
#line 1394 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(PRIM_RETURN, (yyvsp[0].pexpr)); }
#line 7997 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 341:
#line 1397 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(PRIM_LIFETIME_OF, new UnresolvedSymExpr((yyvsp[0].pch))); }
#line 8003 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 342:
#line 1398 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(PRIM_LIFETIME_OF, new UnresolvedSymExpr("this")); }
#line 8009 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 343:
#line 1402 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = (yyvsp[-1].pblockstmt); }
#line 8015 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 344:
#line 1404 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = handleConfigTypes((yyvsp[-1].pblockstmt)); }
#line 8021 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 345:
#line 1406 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = convertTypesToExtern((yyvsp[-1].pblockstmt)); }
#line 8027 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 346:
#line 1411 "chapel.ypp" /* yacc.c:1667  */
    {
      VarSymbol* var = new VarSymbol((yyvsp[-1].pch));

      var->addFlag(FLAG_TYPE_VARIABLE);

      var->doc               = context->latestComment;
      context->latestComment = NULL;

      DefExpr* def = new DefExpr(var, (yyvsp[0].pexpr));

      (yyval.pblockstmt) = buildChapelStmt(def);
    }
#line 8044 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 347:
#line 1424 "chapel.ypp" /* yacc.c:1667  */
    {
      VarSymbol* var = new VarSymbol((yyvsp[-3].pch));

      var->addFlag(FLAG_TYPE_VARIABLE);

      var->doc               = context->latestComment;
      context->latestComment = NULL;

      DefExpr* def = new DefExpr(var, (yyvsp[-2].pexpr));

      (yyvsp[0].pblockstmt)->insertAtHead(def);
      (yyval.pblockstmt) = buildChapelStmt((yyvsp[0].pblockstmt));
    }
#line 8062 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 348:
#line 1440 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = NULL; }
#line 8068 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 349:
#line 1442 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8074 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 350:
#line 1444 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForallLoopExprFromArrayType((yyvsp[0].pcallexpr)); }
#line 8080 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 351:
#line 1448 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pflagset) = buildVarDeclFlags(FLAG_PARAM); }
#line 8086 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 352:
#line 1449 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pflagset) = buildVarDeclFlags(FLAG_CONST); }
#line 8092 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 353:
#line 1450 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pflagset) = buildVarDeclFlags(FLAG_REF_VAR); }
#line 8098 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 354:
#line 1451 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pflagset) = buildVarDeclFlags(FLAG_CONST, FLAG_REF_VAR); }
#line 8104 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 355:
#line 1452 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pflagset) = buildVarDeclFlags(); }
#line 8110 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 356:
#line 1457 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyvsp[-2].pflagset)->insert(FLAG_CONFIG);
      (yyval.pblockstmt) = buildVarDecls((yyvsp[-1].pblockstmt), context->latestComment, (yyvsp[-2].pflagset));
      context->latestComment = NULL;
    }
#line 8120 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 357:
#line 1463 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyvsp[-2].pflagset)->insert(FLAG_EXTERN);
      (yyval.pblockstmt) = buildVarDecls((yyvsp[-1].pblockstmt), context->latestComment, (yyvsp[-2].pflagset), (yyvsp[-3].pexpr));
      context->latestComment = NULL;
    }
#line 8130 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 358:
#line 1469 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = buildVarDecls((yyvsp[-1].pblockstmt), context->latestComment, (yyvsp[-2].pflagset));
      context->latestComment = NULL;
    }
#line 8139 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 360:
#line 1478 "chapel.ypp" /* yacc.c:1667  */
    {
      for_alist(expr, (yyvsp[0].pblockstmt)->body)
        (yyvsp[-2].pblockstmt)->insertAtTail(expr->remove());
    }
#line 8148 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 361:
#line 1486 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildChapelStmt(new DefExpr(new VarSymbol((yyvsp[-2].pch)), (yyvsp[0].pexpr), (yyvsp[-1].pexpr))); }
#line 8154 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 362:
#line 1488 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildTupleVarDeclStmt((yyvsp[-3].pblockstmt), (yyvsp[-1].pexpr), (yyvsp[0].pexpr)); }
#line 8160 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 363:
#line 1493 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new DefExpr(new VarSymbol("chpl__tuple_blank")); }
#line 8166 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 364:
#line 1495 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new DefExpr(new VarSymbol((yyvsp[0].pch))); }
#line 8172 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 365:
#line 1497 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[-1].pblockstmt); }
#line 8178 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 366:
#line 1502 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildChapelStmt((yyvsp[0].pexpr)); }
#line 8184 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 367:
#line 1504 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildChapelStmt((yyvsp[-1].pexpr)); }
#line 8190 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 368:
#line 1506 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ((yyvsp[0].pblockstmt)->insertAtHead((yyvsp[-2].pexpr)), (yyvsp[0].pblockstmt)); }
#line 8196 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 369:
#line 1512 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = NULL; }
#line 8202 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 370:
#line 1513 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(gNoInit); }
#line 8208 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 371:
#line 1514 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8214 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 372:
#line 1520 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, (yyvsp[0].pexpr)); }
#line 8220 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 373:
#line 1522 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, NULL); }
#line 8226 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 374:
#line 1524 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pexpr));
    }
#line 8234 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 375:
#line 1528 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-1].pcallexpr)), NULL);
    }
#line 8242 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 376:
#line 1532 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, (yyvsp[0].pexpr)); }
#line 8248 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 377:
#line 1534 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pexpr));
    }
#line 8256 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 378:
#line 1538 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pexpr) = new CallExpr(PRIM_ERROR);
    }
#line 8264 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 379:
#line 1545 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = NULL; }
#line 8270 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 380:
#line 1546 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8276 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 381:
#line 1547 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8282 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 382:
#line 1548 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr((yyvsp[0].pch)); }
#line 8288 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 383:
#line 1549 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = NULL; }
#line 8294 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 384:
#line 1554 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = NULL; }
#line 8300 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 385:
#line 1555 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8306 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 386:
#line 1556 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pcallexpr); }
#line 8312 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 387:
#line 1557 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr((yyvsp[0].pch)); }
#line 8318 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 388:
#line 1558 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = NULL; }
#line 8324 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 389:
#line 1579 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pexpr));
    }
#line 8332 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 390:
#line 1583 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pcallexpr));
    }
#line 8340 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 391:
#line 1587 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pexpr), "invalid index expression");
      (yyval.pcallexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pexpr)), (yyvsp[0].pexpr), (yyvsp[-4].pcallexpr)->get(1)->remove(),
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pexpr)->copy()));
    }
#line 8352 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 392:
#line 1595 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pcallexpr) = new CallExpr(PRIM_ERROR);
    }
#line 8360 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 393:
#line 1601 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = NULL; }
#line 8366 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 394:
#line 1602 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8372 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 395:
#line 1603 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8378 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 396:
#line 1608 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, (yyvsp[0].pexpr)); }
#line 8384 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 397:
#line 1610 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildFormalArrayType((yyvsp[-2].pcallexpr), (yyvsp[0].pexpr)); }
#line 8390 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 398:
#line 1616 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, (yyvsp[0].pexpr)); }
#line 8396 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 399:
#line 1618 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildFormalArrayType((yyvsp[-2].pcallexpr), (yyvsp[0].pexpr)); }
#line 8402 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 400:
#line 1620 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildFormalArrayType((yyvsp[-2].pexpr), (yyvsp[0].pexpr), (yyvsp[-4].pcallexpr)); }
#line 8408 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 401:
#line 1624 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = NULL; }
#line 8414 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 402:
#line 1625 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8420 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 403:
#line 1626 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8426 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 404:
#line 1627 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr((yyvsp[0].pch)); }
#line 8432 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 405:
#line 1628 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8438 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 406:
#line 1634 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[0].pexpr)); }
#line 8444 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 407:
#line 1635 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[0].pexpr)); }
#line 8450 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 408:
#line 1636 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 8456 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 409:
#line 1637 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 8462 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 410:
#line 1641 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[0].pexpr));}
#line 8468 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 411:
#line 1642 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 8474 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 412:
#line 1646 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("chpl__tuple_blank"); }
#line 8480 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 413:
#line 1647 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8486 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 414:
#line 1648 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8492 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 415:
#line 1652 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8498 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 416:
#line 1653 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 8504 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 417:
#line 1657 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST); }
#line 8510 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 419:
#line 1662 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[0].pexpr)); }
#line 8516 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 420:
#line 1663 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 8522 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 421:
#line 1667 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildNamedActual((yyvsp[-2].pch), (yyvsp[0].pexpr)); }
#line 8528 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 422:
#line 1668 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildNamedActual((yyvsp[-2].pch), (yyvsp[0].pexpr)); }
#line 8534 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 423:
#line 1669 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8540 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 424:
#line 1670 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8546 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 425:
#line 1674 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr((yyvsp[0].pch)); }
#line 8552 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 426:
#line 1675 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8558 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 427:
#line 1687 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8564 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 428:
#line 1689 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr( PRIM_TO_NILABLE_CLASS, (yyvsp[-1].pexpr)); }
#line 8570 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 434:
#line 1702 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr( "_singlevar", (yyvsp[0].pexpr)); }
#line 8576 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 435:
#line 1704 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildIndexType", (yyvsp[-1].pcallexpr)); }
#line 8582 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 436:
#line 1706 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildDomainRuntimeType", new UnresolvedSymExpr("defaultDist"), (yyvsp[-1].pcallexpr)); }
#line 8588 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 437:
#line 1708 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildSubDomainType", (yyvsp[-1].pcallexpr)); }
#line 8594 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 438:
#line 1710 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildSparseDomainRuntimeType", buildDotExpr((yyvsp[-1].pcallexpr)->copy(), "defaultSparseDist"), (yyvsp[-1].pcallexpr)); }
#line 8600 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 439:
#line 1712 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__atomicType", (yyvsp[0].pexpr)); }
#line 8606 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 440:
#line 1714 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr( "_syncvar", (yyvsp[0].pexpr)); }
#line 8612 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 441:
#line 1717 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("_owned"); }
#line 8618 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 442:
#line 1719 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr( "_owned", (yyvsp[0].pexpr)); }
#line 8624 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 443:
#line 1721 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("_unmanaged"); }
#line 8630 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 444:
#line 1723 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr( PRIM_TO_UNMANAGED_CLASS, (yyvsp[0].pexpr)); }
#line 8636 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 445:
#line 1725 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("_shared"); }
#line 8642 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 446:
#line 1727 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr( "_shared", (yyvsp[0].pexpr)); }
#line 8648 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 447:
#line 1729 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("_borrowed"); }
#line 8654 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 448:
#line 1731 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr( PRIM_TO_BORROWED_CLASS, (yyvsp[0].pexpr)); }
#line 8660 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 449:
#line 1736 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8666 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 450:
#line 1738 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[-4].pexpr), (yyvsp[-2].pcallexpr), (yyvsp[0].pexpr), NULL, false, true); }
#line 8672 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 451:
#line 1740 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForLoopExpr(NULL, (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8678 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 452:
#line 1742 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[-7].pexpr), (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 8684 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 453:
#line 1744 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[-7].pexpr), (yyvsp[-5].pcallexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr), false, true); }
#line 8690 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 454:
#line 1746 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForLoopExpr(NULL, (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 8696 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 455:
#line 1748 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8702 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 456:
#line 1750 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[-4].pexpr), (yyvsp[-2].pcallexpr), (yyvsp[0].pexpr), NULL, false, true); }
#line 8708 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 457:
#line 1752 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForallLoopExpr(NULL, (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8714 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 458:
#line 1754 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[-7].pexpr), (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 8720 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 459:
#line 1756 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[-7].pexpr), (yyvsp[-5].pcallexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr), false, true); }
#line 8726 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 460:
#line 1758 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForallLoopExpr(NULL, (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 8732 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 461:
#line 1760 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-2].pcallexpr)->argList.length > 1)
        (yyval.pexpr) = buildForallLoopExpr(NULL, new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pexpr), NULL, true);
      else
        (yyval.pexpr) = buildForallLoopExpr(NULL, (yyvsp[-2].pcallexpr)->get(1)->remove(), (yyvsp[0].pexpr), NULL, true);
    }
#line 8743 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 462:
#line 1767 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[-4].pcallexpr)->get(1)->remove(), (yyvsp[-2].pexpr), (yyvsp[0].pexpr), NULL, true);
    }
#line 8753 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 463:
#line 1773 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pcallexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[-4].pcallexpr)->get(1)->remove(), (yyvsp[-2].pcallexpr), (yyvsp[0].pexpr), NULL, false, true);
    }
#line 8763 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 464:
#line 1779 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-7].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-5].pexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[-7].pcallexpr)->get(1)->remove(), (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr));
    }
#line 8773 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 465:
#line 1785 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-7].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-5].pcallexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[-7].pcallexpr)->get(1)->remove(), (yyvsp[-5].pcallexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr), false, true);
    }
#line 8783 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 466:
#line 1794 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new IfExpr((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8789 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 467:
#line 1803 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(gNil); }
#line 8795 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 475:
#line 1819 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("<~>", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8801 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 476:
#line 1823 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = NULL; }
#line 8807 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 478:
#line 1828 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = (yyvsp[-1].pcallexpr); }
#line 8813 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 479:
#line 1832 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST); addTaskIntent((yyval.pcallexpr), (yyvsp[0].pShadowVar)); }
#line 8819 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 480:
#line 1833 "chapel.ypp" /* yacc.c:1667  */
    { addTaskIntent((yyvsp[-2].pcallexpr), (yyvsp[0].pShadowVar)); }
#line 8825 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 481:
#line 1837 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = (yyvsp[-1].pcallexpr); }
#line 8831 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 482:
#line 1841 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST); addForallIntent((yyval.pcallexpr), (yyvsp[0].pShadowVar)); }
#line 8837 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 483:
#line 1842 "chapel.ypp" /* yacc.c:1667  */
    { addForallIntent((yyvsp[-2].pcallexpr), (yyvsp[0].pShadowVar)); }
#line 8843 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 484:
#line 1847 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pShadowVar) = ShadowVarSymbol::buildForPrefix((yyvsp[-3].pShadowVarPref), (yyvsp[-2].pexpr), (yyvsp[-1].pexpr), (yyvsp[0].pexpr));
    }
#line 8851 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 485:
#line 1851 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pShadowVar) = ShadowVarSymbol::buildFromReduceIntent((yyvsp[0].pexpr), (yyvsp[-2].pexpr));
    }
#line 8859 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 486:
#line 1855 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pShadowVar) = ShadowVarSymbol::buildFromReduceIntent((yyvsp[0].pexpr), (yyvsp[-2].pexpr));
    }
#line 8867 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 487:
#line 1861 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pShadowVarPref) = SVP_CONST;     }
#line 8873 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 488:
#line 1862 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pShadowVarPref) = SVP_IN;        }
#line 8879 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 489:
#line 1863 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pShadowVarPref) = SVP_CONST_IN;  }
#line 8885 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 490:
#line 1864 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pShadowVarPref) = SVP_REF;       }
#line 8891 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 491:
#line 1865 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pShadowVarPref) = SVP_CONST_REF; }
#line 8897 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 492:
#line 1866 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pShadowVarPref) = SVP_VAR;       }
#line 8903 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 494:
#line 1872 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("<~>", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8909 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 495:
#line 1877 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(PRIM_NEW, (yyvsp[0].pexpr)); }
#line 8915 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 496:
#line 1882 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildLetExpr((yyvsp[-2].pblockstmt), (yyvsp[0].pexpr)); }
#line 8921 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 505:
#line 1898 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(PRIM_TUPLE_EXPAND, (yyvsp[-1].pexpr)); }
#line 8927 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 506:
#line 1900 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = createCast((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8933 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 507:
#line 1902 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl_build_bounded_range", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8939 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 508:
#line 1904 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl_build_low_bounded_range", (yyvsp[-1].pexpr)); }
#line 8945 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 509:
#line 1906 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl_build_high_bounded_range", (yyvsp[0].pexpr)); }
#line 8951 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 510:
#line 1908 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl_build_unbounded_range"); }
#line 8957 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 511:
#line 1912 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = NULL; }
#line 8963 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 512:
#line 1913 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8969 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 513:
#line 1916 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = tryExpr((yyvsp[0].pexpr)); }
#line 8975 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 514:
#line 1917 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = tryBangExpr((yyvsp[0].pexpr)); }
#line 8981 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 515:
#line 1918 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8987 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 520:
#line 1935 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8993 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 521:
#line 1936 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("postfix!", (yyvsp[-1].pexpr)); }
#line 8999 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 522:
#line 1937 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 9005 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 523:
#line 1941 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr((yyvsp[-3].pexpr), (yyvsp[-1].pcallexpr)); }
#line 9011 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 524:
#line 1942 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildSquareCallExpr((yyvsp[-3].pexpr), (yyvsp[-1].pcallexpr)); }
#line 9017 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 525:
#line 1943 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildPrimitiveExpr((yyvsp[-1].pcallexpr)); }
#line 9023 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 526:
#line 1947 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildDotExpr((yyvsp[-2].pexpr), (yyvsp[0].pch)); }
#line 9029 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 527:
#line 1948 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(PRIM_TYPEOF, (yyvsp[-2].pexpr)); }
#line 9035 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 528:
#line 1949 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildDotExpr((yyvsp[-2].pexpr), "_dom"); }
#line 9041 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 529:
#line 1950 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildDotExpr((yyvsp[-2].pexpr), "locale"); }
#line 9047 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 530:
#line 1951 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(buildDotExpr((yyvsp[-4].pexpr), "chpl_bytes")); }
#line 9053 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 531:
#line 1959 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[-1].pexpr); }
#line 9059 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 532:
#line 1960 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildOneTuple((yyvsp[-2].pexpr)); }
#line 9065 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 533:
#line 1961 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildTuple((yyvsp[-1].pcallexpr)); }
#line 9071 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 534:
#line 1962 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildTuple((yyvsp[-2].pcallexpr)); }
#line 9077 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 535:
#line 1966 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(gFalse); }
#line 9083 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 536:
#line 1967 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(gTrue); }
#line 9089 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 538:
#line 1972 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildIntLiteral((yyvsp[0].pch), yyfilename, chplLineno);    }
#line 9095 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 539:
#line 1973 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildRealLiteral((yyvsp[0].pch));   }
#line 9101 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 540:
#line 1974 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildImagLiteral((yyvsp[0].pch));   }
#line 9107 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 541:
#line 1975 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildStringLiteral((yyvsp[0].pch)); }
#line 9113 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 542:
#line 1976 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildCStringLiteral((yyvsp[0].pch)); }
#line 9119 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 543:
#line 1977 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(gNone); }
#line 9125 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 544:
#line 1978 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildDomainExpr", (yyvsp[-1].pcallexpr)); }
#line 9131 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 545:
#line 1979 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildDomainExpr", (yyvsp[-2].pcallexpr)); }
#line 9137 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 546:
#line 1980 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayExpr",  (yyvsp[-1].pcallexpr)); }
#line 9143 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 547:
#line 1981 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayExpr",  (yyvsp[-2].pcallexpr)); }
#line 9149 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 548:
#line 1983 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pexpr) = new CallExpr("chpl__buildAssociativeArrayExpr", (yyvsp[-1].pcallexpr));
    }
#line 9157 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 549:
#line 1987 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pexpr) = new CallExpr("chpl__buildAssociativeArrayExpr", (yyvsp[-2].pcallexpr));
    }
#line 9165 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 550:
#line 1994 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9171 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 551:
#line 1995 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-4].pcallexpr)->insertAtTail((yyvsp[-2].pexpr)); (yyvsp[-4].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 9177 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 552:
#line 1999 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("+", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9183 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 553:
#line 2000 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("-", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9189 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 554:
#line 2001 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("*", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9195 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 555:
#line 2002 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("/", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9201 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 556:
#line 2003 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("<<", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9207 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 557:
#line 2004 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(">>", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9213 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 558:
#line 2005 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("%", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9219 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 559:
#line 2006 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("==", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9225 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 560:
#line 2007 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("==", (yyvsp[-2].pexpr), gUninstantiated); }
#line 9231 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 561:
#line 2008 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("!=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9237 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 562:
#line 2009 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("!=", (yyvsp[-2].pexpr), gUninstantiated); }
#line 9243 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 563:
#line 2010 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("<=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9249 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 564:
#line 2011 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(">=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9255 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 565:
#line 2012 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("<", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9261 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 566:
#line 2013 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(">", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9267 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 567:
#line 2014 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("&", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9273 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 568:
#line 2015 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("|", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9279 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 569:
#line 2016 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("^", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9285 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 570:
#line 2017 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("&&", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9291 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 571:
#line 2018 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("||", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9297 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 572:
#line 2019 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("**", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9303 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 573:
#line 2020 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl_by", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9309 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 574:
#line 2021 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl_align", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9315 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 575:
#line 2022 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("#", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9321 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 576:
#line 2023 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__distributed", (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 9327 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 577:
#line 2027 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("+", (yyvsp[0].pexpr)); }
#line 9333 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 578:
#line 2028 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("-", (yyvsp[0].pexpr)); }
#line 9339 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 579:
#line 2029 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildPreDecIncWarning((yyvsp[0].pexpr), '-'); }
#line 9345 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 580:
#line 2030 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildPreDecIncWarning((yyvsp[0].pexpr), '+'); }
#line 9351 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 581:
#line 2031 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("!", (yyvsp[0].pexpr)); }
#line 9357 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 582:
#line 2032 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("postfix!", (yyvsp[-1].pexpr)); }
#line 9363 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 583:
#line 2033 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("~", (yyvsp[0].pexpr)); }
#line 9369 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 584:
#line 2037 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildReduceExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9375 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 585:
#line 2038 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildReduceExpr((yyvsp[-2].pexpr), (yyvsp[0].pcallexpr), true); }
#line 9381 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 586:
#line 2039 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildReduceExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9387 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 587:
#line 2040 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildReduceExpr((yyvsp[-2].pexpr), (yyvsp[0].pcallexpr), true); }
#line 9393 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 588:
#line 2044 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildScanExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9399 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 589:
#line 2045 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildScanExpr((yyvsp[-2].pexpr), (yyvsp[0].pcallexpr), true); }
#line 9405 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 590:
#line 2046 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildScanExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9411 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 591:
#line 2047 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildScanExpr((yyvsp[-2].pexpr), (yyvsp[0].pcallexpr), true); }
#line 9417 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 592:
#line 2052 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("SumReduceScanOp"); }
#line 9423 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 593:
#line 2053 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("ProductReduceScanOp"); }
#line 9429 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 594:
#line 2054 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("LogicalAndReduceScanOp"); }
#line 9435 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 595:
#line 2055 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("LogicalOrReduceScanOp"); }
#line 9441 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 596:
#line 2056 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("BitwiseAndReduceScanOp"); }
#line 9447 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 597:
#line 2057 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("BitwiseOrReduceScanOp"); }
#line 9453 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 598:
#line 2058 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("BitwiseXorReduceScanOp"); }
#line 9459 "bison-chapel.cpp" /* yacc.c:1667  */
    break;


#line 9463 "bison-chapel.cpp" /* yacc.c:1667  */
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
