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
    TINITEQUALS = 303,
    TLABEL = 304,
    TLAMBDA = 305,
    TLET = 306,
    TLIFETIME = 307,
    TLOCAL = 308,
    TLOCALE = 309,
    TMINUSMINUS = 310,
    TMODULE = 311,
    TNEW = 312,
    TNIL = 313,
    TNOINIT = 314,
    TNONE = 315,
    TNOTHING = 316,
    TON = 317,
    TONLY = 318,
    TOTHERWISE = 319,
    TOUT = 320,
    TOVERRIDE = 321,
    TOWNED = 322,
    TPARAM = 323,
    TPLUSPLUS = 324,
    TPRAGMA = 325,
    TPRIMITIVE = 326,
    TPRIVATE = 327,
    TPROC = 328,
    TPROTOTYPE = 329,
    TPUBLIC = 330,
    TREAL = 331,
    TRECORD = 332,
    TREDUCE = 333,
    TREF = 334,
    TREQUIRE = 335,
    TRETURN = 336,
    TSCAN = 337,
    TSELECT = 338,
    TSERIAL = 339,
    TSHARED = 340,
    TSINGLE = 341,
    TSPARSE = 342,
    TSTRING = 343,
    TSUBDOMAIN = 344,
    TSYNC = 345,
    TTHEN = 346,
    TTHIS = 347,
    TTHROW = 348,
    TTHROWS = 349,
    TTRUE = 350,
    TTRY = 351,
    TTRYBANG = 352,
    TTYPE = 353,
    TUINT = 354,
    TUNDERSCORE = 355,
    TUNION = 356,
    TUNMANAGED = 357,
    TUSE = 358,
    TVAR = 359,
    TVOID = 360,
    TWHEN = 361,
    TWHERE = 362,
    TWHILE = 363,
    TWITH = 364,
    TYIELD = 365,
    TZIP = 366,
    TALIAS = 367,
    TAND = 368,
    TASSIGN = 369,
    TASSIGNBAND = 370,
    TASSIGNBOR = 371,
    TASSIGNBXOR = 372,
    TASSIGNDIVIDE = 373,
    TASSIGNEXP = 374,
    TASSIGNLAND = 375,
    TASSIGNLOR = 376,
    TASSIGNMINUS = 377,
    TASSIGNMOD = 378,
    TASSIGNMULTIPLY = 379,
    TASSIGNPLUS = 380,
    TASSIGNREDUCE = 381,
    TASSIGNSL = 382,
    TASSIGNSR = 383,
    TBANG = 384,
    TBAND = 385,
    TBNOT = 386,
    TBOR = 387,
    TBXOR = 388,
    TCOLON = 389,
    TCOMMA = 390,
    TDIVIDE = 391,
    TDOT = 392,
    TDOTDOT = 393,
    TDOTDOTDOT = 394,
    TEQUAL = 395,
    TEXP = 396,
    TGREATER = 397,
    TGREATEREQUAL = 398,
    THASH = 399,
    TIO = 400,
    TLESS = 401,
    TLESSEQUAL = 402,
    TMINUS = 403,
    TMOD = 404,
    TNOTEQUAL = 405,
    TOR = 406,
    TPLUS = 407,
    TQUESTION = 408,
    TSEMI = 409,
    TSHIFTLEFT = 410,
    TSHIFTRIGHT = 411,
    TSTAR = 412,
    TSWAP = 413,
    TLCBR = 414,
    TRCBR = 415,
    TLP = 416,
    TRP = 417,
    TLSBR = 418,
    TRSBR = 419,
    TNOELSE = 420,
    TUPLUS = 421,
    TUMINUS = 422
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

#line 456 "bison-chapel.cpp" /* yacc.c:352  */

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

#line 532 "bison-chapel.cpp" /* yacc.c:355  */

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
#define YYLAST   16712

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  168
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  140
/* YYNRULES -- Number of rules.  */
#define YYNRULES  595
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1050

#define YYUNDEFTOK  2
#define YYMAXUTOK   422

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
     165,   166,   167
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
     730,   731,   732,   733,   734,   735,   736,   740,   741,   742,
     743,   744,   745,   746,   747,   748,   749,   756,   757,   762,
     763,   768,   769,   773,   774,   778,   779,   783,   784,   785,
     786,   787,   788,   789,   790,   794,   795,   799,   800,   801,
     802,   806,   813,   814,   815,   816,   817,   818,   819,   820,
     821,   822,   823,   824,   825,   826,   827,   828,   829,   830,
     831,   837,   843,   849,   855,   862,   869,   873,   880,   884,
     885,   886,   887,   888,   890,   892,   894,   899,   902,   903,
     904,   905,   906,   907,   911,   912,   916,   917,   918,   922,
     923,   927,   930,   932,   937,   938,   942,   944,   946,   953,
     963,   973,   983,   996,  1001,  1006,  1014,  1015,  1020,  1021,
    1023,  1028,  1044,  1051,  1060,  1068,  1072,  1079,  1080,  1085,
    1090,  1084,  1117,  1123,  1130,  1136,  1142,  1153,  1159,  1152,
    1191,  1195,  1200,  1204,  1209,  1216,  1217,  1221,  1222,  1223,
    1224,  1225,  1226,  1227,  1228,  1229,  1230,  1231,  1232,  1233,
    1234,  1235,  1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,
    1244,  1245,  1246,  1247,  1248,  1252,  1253,  1254,  1255,  1256,
    1257,  1258,  1259,  1260,  1261,  1262,  1263,  1267,  1268,  1272,
    1276,  1277,  1278,  1282,  1284,  1286,  1288,  1290,  1295,  1296,
    1300,  1301,  1302,  1303,  1304,  1305,  1306,  1307,  1308,  1312,
    1313,  1314,  1315,  1316,  1317,  1321,  1322,  1326,  1327,  1328,
    1329,  1330,  1331,  1335,  1336,  1339,  1340,  1344,  1345,  1349,
    1351,  1356,  1357,  1361,  1362,  1370,  1371,  1373,  1375,  1377,
    1382,  1383,  1386,  1387,  1388,  1389,  1390,  1391,  1392,  1395,
    1396,  1399,  1401,  1403,  1408,  1421,  1438,  1439,  1441,  1446,
    1447,  1448,  1449,  1450,  1454,  1460,  1466,  1474,  1475,  1483,
    1485,  1490,  1492,  1494,  1499,  1501,  1503,  1510,  1511,  1512,
    1517,  1519,  1521,  1525,  1529,  1531,  1535,  1543,  1544,  1545,
    1546,  1547,  1552,  1553,  1554,  1555,  1556,  1576,  1580,  1584,
    1592,  1599,  1600,  1601,  1605,  1607,  1613,  1615,  1617,  1622,
    1623,  1624,  1625,  1626,  1632,  1633,  1634,  1635,  1639,  1640,
    1644,  1645,  1646,  1650,  1651,  1655,  1656,  1660,  1661,  1665,
    1666,  1667,  1668,  1672,  1673,  1684,  1686,  1694,  1695,  1696,
    1697,  1698,  1699,  1701,  1703,  1705,  1707,  1709,  1711,  1714,
    1716,  1718,  1720,  1722,  1724,  1726,  1728,  1733,  1735,  1737,
    1739,  1741,  1743,  1745,  1747,  1749,  1751,  1753,  1755,  1757,
    1764,  1770,  1776,  1782,  1791,  1801,  1809,  1810,  1811,  1812,
    1813,  1814,  1815,  1816,  1821,  1822,  1826,  1830,  1831,  1835,
    1839,  1840,  1844,  1848,  1852,  1859,  1860,  1861,  1862,  1863,
    1864,  1868,  1869,  1874,  1879,  1887,  1888,  1889,  1890,  1891,
    1892,  1893,  1894,  1895,  1897,  1899,  1901,  1903,  1905,  1910,
    1911,  1914,  1915,  1916,  1919,  1920,  1921,  1922,  1933,  1934,
    1935,  1939,  1940,  1941,  1945,  1946,  1947,  1948,  1956,  1957,
    1958,  1959,  1963,  1964,  1968,  1969,  1970,  1971,  1972,  1973,
    1974,  1975,  1976,  1977,  1978,  1979,  1983,  1991,  1992,  1996,
    1997,  1998,  1999,  2000,  2001,  2002,  2003,  2004,  2005,  2006,
    2007,  2008,  2009,  2010,  2011,  2012,  2013,  2014,  2015,  2016,
    2017,  2018,  2019,  2020,  2024,  2025,  2026,  2027,  2028,  2029,
    2030,  2034,  2035,  2036,  2037,  2041,  2042,  2043,  2044,  2049,
    2050,  2051,  2052,  2053,  2054,  2055
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
  "TINOUT", "TINT", "TITER", "TINITEQUALS", "TLABEL", "TLAMBDA", "TLET",
  "TLIFETIME", "TLOCAL", "TLOCALE", "TMINUSMINUS", "TMODULE", "TNEW",
  "TNIL", "TNOINIT", "TNONE", "TNOTHING", "TON", "TONLY", "TOTHERWISE",
  "TOUT", "TOVERRIDE", "TOWNED", "TPARAM", "TPLUSPLUS", "TPRAGMA",
  "TPRIMITIVE", "TPRIVATE", "TPROC", "TPROTOTYPE", "TPUBLIC", "TREAL",
  "TRECORD", "TREDUCE", "TREF", "TREQUIRE", "TRETURN", "TSCAN", "TSELECT",
  "TSERIAL", "TSHARED", "TSINGLE", "TSPARSE", "TSTRING", "TSUBDOMAIN",
  "TSYNC", "TTHEN", "TTHIS", "TTHROW", "TTHROWS", "TTRUE", "TTRY",
  "TTRYBANG", "TTYPE", "TUINT", "TUNDERSCORE", "TUNION", "TUNMANAGED",
  "TUSE", "TVAR", "TVOID", "TWHEN", "TWHERE", "TWHILE", "TWITH", "TYIELD",
  "TZIP", "TALIAS", "TAND", "TASSIGN", "TASSIGNBAND", "TASSIGNBOR",
  "TASSIGNBXOR", "TASSIGNDIVIDE", "TASSIGNEXP", "TASSIGNLAND",
  "TASSIGNLOR", "TASSIGNMINUS", "TASSIGNMOD", "TASSIGNMULTIPLY",
  "TASSIGNPLUS", "TASSIGNREDUCE", "TASSIGNSL", "TASSIGNSR", "TBANG",
  "TBAND", "TBNOT", "TBOR", "TBXOR", "TCOLON", "TCOMMA", "TDIVIDE", "TDOT",
  "TDOTDOT", "TDOTDOTDOT", "TEQUAL", "TEXP", "TGREATER", "TGREATEREQUAL",
  "THASH", "TIO", "TLESS", "TLESSEQUAL", "TMINUS", "TMOD", "TNOTEQUAL",
  "TOR", "TPLUS", "TQUESTION", "TSEMI", "TSHIFTLEFT", "TSHIFTRIGHT",
  "TSTAR", "TSWAP", "TLCBR", "TRCBR", "TLP", "TRP", "TLSBR", "TRSBR",
  "TNOELSE", "TUPLUS", "TUMINUS", "$accept", "program", "toplevel_stmt_ls",
  "toplevel_stmt", "pragma_ls", "stmt", "module_decl_start",
  "module_decl_stmt", "access_control", "opt_prototype", "block_stmt",
  "stmt_ls", "only_ls", "opt_only_ls", "except_ls", "use_access_control",
  "use_stmt", "require_stmt", "assignment_stmt", "opt_label_ident",
  "ident_fn_def", "ident_def", "ident_use", "internal_type_ident_def",
  "scalar_type", "reserved_type_ident_use", "opt_string", "do_stmt",
  "return_stmt", "class_level_stmt", "private_decl", "forwarding_stmt",
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
     415,   416,   417,   418,   419,   420,   421,   422
};
# endif

#define YYPACT_NINF -886

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-886)))

#define YYTABLE_NINF -544

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -886,   101,  3016,  -886,  -105,  -886,  -886,  -886,  -886,  -886,
    -886,  4468,    15,   137,  -886, 12561,  -886,    15, 10227,  -886,
     322,    23,   137,  4468, 10227,  4468,     3,  -886, 10227,  7007,
    -886,  8387,  8985,  6846, 10227,  -886,    12,  -886,  -886, 16607,
    -886,  2208,  9123,  -886, 10227, 10227,  -886,  -886,  -886, 10227,
    -886, 12561,  -886, 10227,   173,    83,  1554,  1988,  -886,  -886,
    -886,  9261,  7927, 10227,  9123, 12561, 10227,   163,  -886,   122,
    4468,  -886, 10227,  -886, 10365, 10365, 16607,  -886,  -886, 12561,
    -886,  -886, 10227, 10227,  -886, 10227,  -886, 10227,  -886,  -886,
   12297, 10227,  -886, 10227,  -886,  -886,  3502,  7145,  8525,  -886,
    4307,  -886,   127,  -886,   278,  -886,   200,  -886,  -886,  -886,
    -886,  -886,  -886,  -886,  -886,  -886,  -886,  -886,  -886,  -886,
    -886,  -886,  -886,  -886, 16607,  -886, 16607,   215,   231,  -886,
    -886,  2208,  -886,   237,  -886,   252,  -886,  -886,   271,   287,
     317,   290,   314, 16321,  2385,   255,   321,   330,  -886,  -886,
    -886,  -886,  -886,  -886,  -886,   345,  -886,  -886, 16321,   326,
    4468,  -886,  -886,   342, 10227, 10227, 10227, 10227, 10227,  9261,
    9261,   274,  -886,  -886,  -886,  -886,   295,   284,  -886,  -886,
     348, 14526, 16607,  2208,  -886,   347,  -886,    76, 16321,   401,
    8088, 16321,  -886,   150,  -886, 16607,   199,   283, 16607,   349,
       8, 14045,    16, 14004,   283, 10227,  -886, 14429, 13253,  8088,
    -886,  -886,  -886,  -886,  -886,  -886,  -886,  -886,  -886,  -886,
    -886,  -886,  -886,  -886,  -886,  -886,  -886,  -886,  -886,  -886,
    -886,  -886,  -886,  4468,  -886,   350,  1465,    72,    33,  -886,
    4468,  -886,  -886, 14188,   965,   295, 14188,   295,   965,  -886,
    8088, 10227,  -886,  -886, 16607,  -886,   152, 16321, 10227, 10227,
    -886, 16321,   361, 14376,  -886, 14188,   295, 16321,   353,  8088,
    -886, 16321, 14755,  -886,  -886, 14812, 12294,  -886,  -886, 14898,
     403,   365,   295, 14188, 14955,   160,   160,  2036,   965,   965,
     -64,  -886,  -886,  3663,   138,  -886, 10227,  -886,   -30,   -28,
    -886,   -20,    14, 15041,   -35,   513,  -886,  3824,  -886,   470,
    9261,   388,   370,  -886,  -886,  -886,   225,  -886,  -886, 10227,
   10227, 10227, 10227,  8985,  8985, 10227,   289, 10227, 10227, 10227,
   10227, 10227,   192, 12297,  9422, 10227, 10227, 10227, 10227, 10227,
   10227, 10227, 10227,  9583, 10227, 10227, 10227, 10227, 10227,  -886,
    -886,  -886,  -886,  -886,  -886,  8686,  8686,  -886,  -886,  -886,
    -886,  8686,  -886,  -886,  8686,  8686,  8088,  8088,  8985,  8985,
    7628,  -886,  -886, 14572, 14669, 14995,    27,  3985,  -886,  8985,
       8,   383,   228,  -886, 10227,  -886, 10227,   425,  -886,   386,
     414,  -886,  -886,   399, 16607,  2208,   512,  9261,  -886,  4629,
    8985,  -886,   396,  -886,     8,  4790,  8985,  -886,     8,   283,
   10503, 10227,  -886,  4468,   528, 10227,   402,  -886,   651,  -886,
    -886,  1465,  -886,   426,   404,  -886, 10641,   451, 10227,  2208,
    -886,  -886,  -886,   407,  -886,  9261,  -886, 16321, 16321,  -886,
      29,  -886,  8088,   409,  -886,   557,  -886,   557,  -886, 10779,
     442,  -886,  -886,  -886,  -886,  -886,  -886,  8824,  -886, 13110,
    7306,  -886,  7467,  -886,  4468,   417,  8985,  6239,  3341,   418,
   10227,  6563,  -886,  -886,   128,  -886,  4146, 16607,   229, 14715,
    9261,   427, 16540,   177,  -886, 15138,  2246,  2246,   299,  -886,
     299,  -886,   299, 14278,   800,   337,   642,   295,   160,  -886,
    -886,  -886,  -886,  2036,  -886,  2722,   299,   632,   632,  2246,
     632,   632,  1790,   160,  -886,  2722, 14143,  1790,   965,   965,
     160,   430,   435,   437,   441,   445,   440,   444,  -886,   299,
    -886,   299,   193,  -886,  -886,  -886,   -14,  -886,  2268, 16370,
     356, 10917,  8985, 11055,  8985, 10227,  8985, 12789,    15, 15191,
    -886,  -886,  -886, 16321, 15231,  8088,  -886,  8088,  -886,   388,
     242, 10227,    99, 10227, 16321,    18, 14233,  7628,  -886, 10227,
   16321,    17, 14090,  -886,   450,   471,   455, 15288,   471,   459,
     574, 15374,  4468, 14331,  -886,   195,  -886,  -886,  -886,  -886,
    -886,  -886,   991,   129,  -886,  2522,  -886,   360,   453,  1465,
      72,     3,    12, 10227, 10227,  6078,  -886,  -886,   909,  8249,
    -886, 16321,  -886,  -886,  -886, 16321,   458,   -29,   460,  -886,
    1634,  -886,  -886,   257, 16607,  -886,  -886,  -886,  -886,  -886,
    -886,  -886,  4468,   -17,  2814,  -886,  -886, 16321,  4468, 16321,
    -886, 15431,  -886,  -886,  -886,  -886, 10503, 10227,   489,  1061,
     468,   516,   206,  -886,   552,  -886,  -886,  -886,  -886,  6687,
    -886,  -886,  -886,  -886,  -886,  -886,  -886,  -886,  -886,  7628,
    -886,    31,  8985,  8985, 10227,   603, 15463, 10227,   604, 15606,
     473, 12926,     8,     8,  -886,  -886,  -886,  -886,   475,  -886,
   14188,  -886, 13329,  4951,  -886,  5112,  -886,   130,  -886, 13405,
    5273,  -886,     8,  5434,  -886,     8, 10227,  -886, 10227,  -886,
    4468, 10227,  -886,  4468,   608,  -886,  -886, 16607,  1101,  -886,
    1465,   509,   565,  -886,  -886,  -886,    90,  -886,  -886,   451,
     482,    57,  -886,  -886,  -886,  5595,  9261,  -886,  -886,  -886,
   16607,  -886,   515,   348,  -886,  -886,  5756,   486,  5917,   490,
    -886, 10227,   499,   505,   504,   544,  -886, 10227, 16607,  -886,
    -886,   360,   506,   256,  -886,   532,  -886,   534,   536,   535,
     539,  -886,   542,   551,   546,   550,   553,   292,   559,   554,
     562,  -886,  -886, 16607,  -886,  -886,  -886,  -886,  -886,  -886,
    -886,  -886,  -886,  -886,  -886,  -886,  -886,  -886,  -886,  -886,
    -886,  -886,  -886, 10227,  -886,   573,   577,   566,   506,   506,
    -886,  -886,   451,   186,   205, 15574, 11193, 11331, 15717, 11469,
   11607, 11745, 11883,  -886,  -886,  2418,  -886,  4468, 10227, 16321,
   10227, 16321,  7628,  -886,  4468, 10227, 16321,  -886, 10227, 16321,
    -886, 15749, 16321,  -886, 16321,   637,  4468,   509,  -886,   511,
    9744,   235,  -886,    45,  -886,  -886,  8985, 12675,  4468,  -886,
      37,   519, 10227,  -886, 10227,  -886, 16321,  4468, 10227,  -886,
   16321,  4468, 16321,  -886,  -886,  -886,  7789,  1241,  1241,  -886,
   16505,  -886, 16321,  -886,    56,   651,  -886,  -886, 13163,  -886,
   12870,  -886,  -886,  -886, 10227, 10227, 10227, 10227, 10227, 10227,
   10227, 10227,   547,  1781, 15374, 13481, 13557,  -886, 15374, 13633,
   13709, 10227,  4468,  -886,   451,   509,  6401,  -886,  -886,  -886,
     -26,  9261,  -886,  -886,   124, 10227,   -21, 13013,  -886,  1132,
     401,  -886,   348, 16321, 13785,  -886, 13861,  -886,  -886,  -886,
   12021,   600,   208,  -886,   579,   580,   506,   506, 15860, 15892,
   16003, 16035, 16146, 16178,  -886,  -886,  4468,  4468,  4468,  4468,
   16321,  -886,  -886,   235,  9905,    64,  -886,  -886, 16321,  -886,
      95,  -886,   118,  -886,   381, 16289,  -886,  -886,  -886, 11883,
    -886,  4468,  4468,  3177,  -886,  -886,   431,  -886,    45,  -886,
    -886,  -886, 10227, 10227, 10227, 10227, 10227, 10227, 15374, 15374,
   15374, 15374,  -886,  -886,  -886,  -886,  -886,   115,  8985,  2666,
    -886, 10227,   124,    95,    95,    95,    95,    95,    95,   124,
    1220, 15374, 15374,   548, 12159,    77,    49, 13070,  -886,  -886,
   16321,  -886,  -886,  -886,  -886,  -886,  -886,  -886,   582,  -886,
    -886,   466, 12431,  -886,  -886,  -886, 10066,  -886,   493,  -886
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       3,     0,     0,     1,     0,    87,   535,   536,   537,   538,
     539,     0,   474,    73,   107,   445,   203,   474,     0,   112,
       0,   350,    73,     0,     0,     0,     0,   213,   509,   509,
     532,     0,     0,     0,     0,   111,     0,   223,   108,     0,
     219,     0,     0,   114,     0,     0,   465,   540,   115,     0,
     226,   439,   349,     0,     0,     0,    45,    44,   110,   204,
     351,     0,     0,     0,     0,   443,     0,     0,   113,     0,
       0,    88,     0,   533,     0,     0,     0,   109,   205,   441,
     353,   116,     0,     0,   591,     0,   593,     0,   594,   595,
     508,     0,   592,   589,   127,   590,     0,     0,     0,     4,
       0,     5,     0,     9,    46,    10,     0,    11,    12,    14,
     423,   424,    22,    13,   128,   134,    15,    17,    16,    19,
      20,    21,    18,   133,     0,   131,     0,   500,     0,   135,
     132,     0,   136,   514,   496,   425,   497,   429,   427,     0,
       0,   501,   502,     0,   428,     0,   515,   516,   517,   534,
     495,   431,   430,   498,   499,     0,    38,    24,   437,     0,
       0,   475,    74,     0,     0,     0,     0,     0,     0,     0,
       0,   500,   514,   427,   501,   502,   446,   428,   515,   516,
       0,   474,     0,     0,   352,     0,   177,     0,   408,     0,
     415,   510,   224,   538,   141,     0,     0,   225,     0,     0,
       0,     0,     0,     0,     0,   509,   140,     0,     0,   415,
      81,    89,   100,    94,   102,    84,    93,   103,    90,   104,
      82,   105,    98,    92,    99,    97,    95,    96,    83,    85,
      91,   101,   106,     0,    86,     0,     0,     0,     0,   357,
       0,   124,    32,     0,   576,   493,     0,   440,   577,     7,
     415,   509,   130,   129,   320,   405,     0,   404,     0,     0,
     125,   513,     0,     0,    35,     0,   444,   432,     0,   415,
      36,   438,     0,   184,   180,     0,   428,   184,   181,     0,
     346,     0,   442,     0,     0,   578,   580,   507,   575,   574,
       0,    48,    51,     0,     0,   410,     0,   412,     0,     0,
     411,     0,     0,   404,     0,     0,     6,     0,    47,     0,
       0,   206,     0,   306,   305,   227,     0,   426,    23,     0,
       0,     0,     0,     0,     0,     0,   579,     0,     0,     0,
       0,     0,     0,   506,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   265,
     272,   273,   274,   269,   271,     0,     0,   267,   270,   268,
     266,     0,   276,   275,     0,     0,   415,   415,     0,     0,
       0,    25,    26,     0,     0,     0,     0,     0,    27,     0,
       0,     0,     0,    28,     0,    29,     0,   423,   421,     0,
     416,   417,   422,     0,     0,     0,     0,     0,   150,     0,
       0,   149,     0,   158,     0,     0,     0,   156,     0,     0,
       0,    57,   137,     0,   170,     0,     0,    30,   288,   220,
     361,     0,   362,   364,     0,   386,     0,   367,     0,     0,
     123,    31,    33,     0,   319,     0,    67,   511,   512,   126,
       0,    34,   415,     0,   191,   182,   178,   183,   179,     0,
     344,   341,   143,    37,    50,    49,    52,     0,   541,     0,
       0,   528,     0,   530,     0,     0,     0,     0,     0,     0,
       0,     0,   545,     8,     0,    40,     0,     0,     0,   404,
       0,     0,     0,   299,   356,   473,   571,   570,   573,   582,
     581,   586,   585,   567,   564,   565,   566,   504,   552,   526,
     527,   525,   524,   505,   557,   556,   569,   563,   561,   572,
     562,   560,   550,   555,   559,   558,   568,   549,   553,   554,
     551,     0,     0,     0,     0,     0,     0,     0,   584,   583,
     588,   587,   485,   486,   488,   490,     0,   477,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   543,   474,   474,
     146,   342,   354,   409,     0,     0,   434,     0,   343,   206,
       0,     0,     0,     0,   449,     0,     0,     0,   159,     0,
     455,     0,     0,   157,   590,    60,     0,    53,    58,     0,
     169,     0,     0,     0,   433,   293,   290,   291,   292,   296,
     297,   298,   288,     0,   281,     0,   289,   307,     0,   365,
       0,   119,   120,   118,   117,     0,   385,   384,   496,     0,
     359,   494,   358,   523,   407,   406,     0,     0,     0,   435,
       0,   185,   348,   496,     0,   542,   503,   529,   413,   531,
     414,   166,     0,     0,     0,   544,   164,   459,     0,   547,
     546,     0,    42,    41,    39,    64,     0,    57,   207,     0,
       0,   217,     0,   214,   303,   300,   301,   304,   228,     0,
      71,    72,    70,    69,    68,   521,   522,   487,   489,     0,
     476,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   142,   419,   420,   418,     0,   355,
       0,   168,     0,     0,   148,     0,   147,     0,   480,     0,
       0,   154,     0,     0,   152,     0,     0,   138,     0,   139,
       0,     0,   172,     0,   174,   294,   295,     0,   288,   279,
       0,   399,   308,   311,   310,   312,     0,   363,   366,   367,
       0,     0,   368,   369,   193,     0,     0,   192,   195,   436,
       0,   186,   189,     0,   345,   167,     0,     0,     0,     0,
     165,     0,     0,     0,     0,   222,   212,     0,   215,   211,
     302,   307,   277,    75,   260,    89,   258,    94,    78,    93,
      90,   263,   104,    76,   105,    92,    95,    77,    79,    91,
     106,   257,   239,   242,   240,   241,   252,   243,   256,   248,
     246,   259,   262,   247,   245,   250,   255,   244,   249,   253,
     254,   251,   261,     0,   237,     0,    80,     0,   277,   277,
     235,   478,   367,   514,   514,     0,     0,     0,     0,     0,
       0,     0,     0,   145,   144,     0,   151,     0,     0,   448,
       0,   447,     0,   479,     0,     0,   454,   155,     0,   453,
     153,    55,    54,   171,   464,   173,     0,   399,   282,     0,
       0,   367,   309,   325,   360,   390,     0,   543,     0,   197,
       0,     0,     0,   187,     0,   162,   461,     0,     0,   160,
     460,     0,   548,    65,    66,   201,   509,   222,   222,   199,
     222,   209,   218,   216,     0,   288,   234,   238,     0,   264,
       0,   230,   231,   482,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   222,   452,     0,     0,   481,   458,     0,
       0,     0,     0,   176,   367,   399,     0,   402,   401,   403,
     496,   321,   285,   283,     0,     0,     0,     0,   388,   496,
     198,   196,     0,   190,     0,   163,     0,   161,   210,   381,
       0,   313,     0,   236,    75,    77,   277,   277,     0,     0,
       0,     0,     0,     0,   202,   200,     0,     0,     0,     0,
      56,   175,   284,   367,   391,     0,   322,   324,   323,   339,
       0,   340,   327,   330,     0,   326,   317,   318,   221,     0,
     188,     0,     0,     0,   380,   379,   496,   314,   325,   278,
     232,   233,     0,     0,     0,     0,     0,     0,   451,   450,
     457,   456,   287,   286,   393,   394,   396,   496,     0,   543,
     338,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     496,   463,   462,     0,   371,     0,     0,     0,   395,   397,
     329,   331,   332,   335,   336,   337,   333,   334,   328,   376,
     374,   496,   543,   315,   229,   316,   391,   375,   496,   398
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -886,  -886,  -886,     0,  -413,  2137,  -886,  -886,  -886,  -886,
     297,   411,  -385,    75,    81,  -886,  -886,  -886,   405,   701,
    -886,   531,  -147,  -631,  -886,  -780,  -886,   670,  -885,  -719,
     -48,  -886,  -886,  -886,    85,  -886,  -886,  -886,   454,  -886,
     -12,  -886,  -886,  -886,  -886,  -886,   537,   179,   -93,  -886,
    -886,  -886,   -22,  1028,  -886,  -886,  -886,  -886,  -886,  -886,
    -886,  -886,  -151,  -143,  -714,  -886,  -144,    24,   151,  -886,
    -886,  -886,   -16,  -886,  -886,  -282,    46,  -886,  -215,  -238,
    -268,  -260,  -747,  -886,  -176,  -886,     5,   720,  -116,   325,
    -886,  -382,  -700,  -811,  -886,  -556,  -435,  -766,  -881,  -769,
     -50,  -886,     1,  -886,  -185,  -886,   198,   615,  -368,  -886,
    -886,  -886,  1170,  -886,    -7,  -886,  -886,  -191,  -886,  -551,
    -886,  -886,  1360,  1376,   -11,    -1,    42,   952,  -886,  1733,
    1949,  -886,  -886,  -886,  -886,  -886,  -886,  -886,  -886,  -367
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,   292,   100,   580,   102,   103,   104,   309,
     105,   293,   575,   579,   576,   106,   107,   108,   109,   163,
     804,   237,   110,   234,   111,   606,   196,   242,   112,   113,
     114,   115,   116,   117,   680,   118,   119,   120,   445,   621,
     743,   121,   122,   617,   738,   123,   124,   481,   755,   125,
     126,   652,   653,   171,   235,   597,   128,   129,   483,   761,
     658,   807,   808,   415,   886,   419,   593,   594,   595,   596,
     659,   315,   726,   988,  1044,   978,   255,   967,   922,   926,
     972,   973,   974,   130,   281,   450,   131,   132,   238,   239,
     423,   424,   610,   985,   941,   427,   607,  1005,   919,   851,
     294,   187,   298,   299,   389,   390,   391,   172,   134,   135,
     136,   137,   173,   139,   160,   161,   536,   404,   697,   537,
     538,   140,   174,   175,   143,   197,   392,   177,   145,   178,
     179,   148,   149,   150,   304,   151,   152,   153,   154,   155
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     158,   365,    99,   540,   176,   592,   381,   181,   252,   253,
     180,   256,   408,   188,   622,   316,   698,   191,   191,   393,
     201,   203,   207,   208,   416,   183,   578,   192,   806,   854,
     616,   243,   425,   244,   245,   735,   881,   240,   246,   598,
     247,   977,   248,   387,   729,   240,   700,   693,   302,   156,
     257,   261,   263,   265,   266,   267,   466,   939,   608,   271,
      62,   272,   387,   275,   279,   433,   240,   382,   282,   546,
     917,   283,   284,   425,   285,   428,   286,   736,   914,   287,
     288,   623,   289,  1006,   443,   257,   261,   303,  -400,   402,
     156,   425,   402,  -194,   891,   892,   454,   924,   969,   856,
     471,     3,   184,   387,   262,   460,  1008,   462,  -377,  -400,
     465,   469,   893,  -400,  -382,   812,   200,   202,   811,   546,
     376,   669,   387,   402,   159,   402,   402,   969,  1029,   472,
      62,   737,   461,   365,   463,  -194,  -400,  -377,   377,   300,
     162,   977,  -382,   297,   464,  -382,   963,   746,   670,   467,
    -377,   923,   925,   158,   373,   374,   375,   271,   257,   303,
     984,   938,   467,  -377,   190,   426,  -382,   377,   429,  -122,
     853,  -382,   435,   209,   380,   377,   377,   377,   468,   261,
     249,   526,   527,   301,   881,   502,  -382,   971,   322,  -194,
     940,   547,   467,  -382,   191,     5,   377,  -382,   261,   467,
     540,   654,   395,  1043,   409,   970,   426,  -382,   377,   183,
    -377,   384,   467,  1040,   962,  -377,   971,   728,    16,   387,
     387,   857,   499,  1010,   426,  1011,  -382,  -122,  1009,  -392,
     385,  1047,   990,   991,   435,   667,   388,   715,   323,   261,
     191,  1042,   324,  1028,   250,   655,   500,   437,   438,  -382,
    -392,  -122,   268,  1012,  -392,   388,   656,   618,   261,   806,
     478,   691,   578,  1003,   718,   832,  1032,  1033,  1034,  1035,
    1036,  1037,   668,   457,   716,   657,    59,  -392,   313,   560,
    1049,   907,   156,   269,    71,   459,   307,   435,   642,   326,
     501,   719,   833,   456,   330,   387,   388,   332,   458,   479,
      78,   335,   540,   310,   314,   592,   436,    21,   485,   486,
     487,   488,   490,   492,   493,   388,   494,   495,   496,   497,
     498,  -484,   503,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   515,   516,   517,   518,   519,   520,   849,   241,
    -483,   758,   880,   718,   261,   261,    21,   562,  -484,   609,
     261,    52,   308,   261,   261,   261,   261,   529,   531,   539,
     429,   241,    60,   429,   435,   322,   759,  -483,   549,  -470,
     989,   273,   277,   553,   921,   554,  -520,   429,  -520,   484,
     702,   705,   552,   645,   722,   -81,   257,    80,   564,   566,
      52,  -467,  -347,   -87,   570,   572,   689,   521,   522,   577,
     577,    60,   581,   523,   583,   317,   524,   525,   489,   491,
     387,  -347,   388,   388,   395,   323,   366,   611,   367,   324,
     182,   -83,   928,   368,   615,  -466,    80,   369,   723,   -88,
     648,   261,   332,   330,   673,  -520,   332,  -520,   369,   724,
     335,   318,   747,   749,  -471,  -518,   615,  -518,   744,   261,
    -519,   261,  -519,   528,   530,   634,   615,   637,   725,   639,
     641,   628,   319,   630,   548,   540,   326,   327,  -472,   257,
     329,   330,   592,   331,   332,  -469,   456,   378,   335,   274,
     278,   614,   920,  -378,  -468,   565,   342,   370,   388,   929,
     880,   571,   346,   347,   348,  1013,   372,   241,   241,   241,
     241,   383,   300,   614,   300,   414,   297,   377,   297,   386,
     397,   418,  -378,   614,   442,   439,   809,   449,  -370,   451,
     473,  1014,   480,  1015,  1016,  -378,   477,  1017,  1018,   482,
     564,   676,   570,   679,   581,   681,   637,   551,  -378,   555,
     241,   682,   683,   241,   261,  -372,   261,  -370,   556,   557,
     690,   633,   692,   558,   561,   731,   539,   567,   699,   582,
    -370,   599,   241,    16,   584,   609,   600,    20,    21,   613,
     233,   619,   986,  -370,  -372,   620,    27,   624,    28,   876,
     241,   632,   638,    33,   660,  -378,   649,  -372,    37,   661,
    -378,   662,   267,   271,   303,   663,  1007,   686,   261,   664,
    -372,   685,   665,   388,   -59,   710,   706,   280,   666,   707,
      50,  1020,    52,   709,    54,   727,   877,   133,   734,   878,
    -370,    59,   739,    60,   435,  -370,   133,   675,   756,   678,
     757,   760,   816,   819,   825,   577,   577,   821,   133,   846,
     133,  1007,    76,   850,   852,    78,   855,  -372,    80,   862,
     867,   733,  -372,   873,   871,   311,  1041,   312,   539,   874,
     322,   490,   529,   815,   875,   -84,   818,   885,   912,  -107,
     322,  -112,  -111,   915,  1048,   585,  -108,   241,  1007,  -114,
     -82,   932,   829,  -115,   831,   133,   860,  -110,   -85,   836,
    -113,  -109,   839,   586,   987,   841,   587,   842,    94,  -116,
     844,   241,   889,   890,   879,   241,   -86,   954,   -81,   -83,
     323,   133,  1039,   280,   324,   133,   588,  1012,   476,   589,
     323,    54,   753,   185,   324,   257,   280,   752,   861,   396,
     590,   447,   903,   394,   264,   866,   883,   870,   688,   946,
     872,   942,   848,   717,  1045,   884,   882,   947,  1002,   591,
    1026,  1038,  1031,   206,   612,   687,     0,   489,   528,     0,
       0,   326,   327,     0,   328,   329,   330,   422,   331,   332,
     333,   326,   327,   335,     0,   133,   330,     0,   331,   332,
     341,   342,     0,   335,   345,   434,  -280,   346,   347,   348,
       0,   342,   888,     0,     0,     0,     0,   346,   347,   348,
       0,     0,     0,     0,     0,   829,   831,     0,   836,   839,
     866,   870,     0,  -280,     0,     0,   904,   905,     0,   906,
       0,   539,     0,   908,   909,     0,     0,   910,   322,   252,
     253,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   927,   637,     0,   133,     0,
       0,   933,     0,   934,     0,   133,     0,   936,     0,     0,
       0,     0,   241,   241,     0,   191,   965,     0,   241,   241,
     398,   401,   403,   407,     0,     0,     0,     0,   323,     0,
     714,     0,   324,   904,   948,   949,   908,   950,   951,   952,
     953,     0,     0,     0,     0,     0,   918,     0,     0,     0,
     960,     0,     0,     0,     0,   303,     0,     0,   133,     0,
     968,     0,     0,   431,   975,     0,   432,   741,     0,     0,
       0,     0,   133,     0,     0,   559,     0,     0,     0,   326,
       0,     0,     0,  1025,   330,   441,   331,   332,     0,     0,
       0,   335,     0,     0,     0,   998,   999,  1000,  1001,   342,
       0,  -383,   422,   452,   144,   346,   347,   348,     0,     0,
       0,  -383,     0,   144,     0,     0,     0,   966,   870,     0,
    1021,  1022,   303,     0,     0,   144,     0,   144,     0,   241,
     241,   998,   999,  1000,  1001,  1021,  1022,   241,     0,   414,
    -383,     0,   133,   322,     0,     0,   414,  1027,   637,   241,
    1030,     0,   241,     0,     0,     0,     0,     0,   644,     0,
    1004,     0,     0,   651,   133,   585,  -383,     0,     0,     0,
     133,     0,   144,  -383,     0,     0,   276,   276,   133,     0,
     127,   637,     0,   586,     0,   870,   587,     0,     0,   127,
     863,     0,     0,   323,  -383,     0,     0,   324,   144,     0,
     550,   127,   144,   127,     0,  1004,   588,     0,     0,   589,
       0,   305,   754,  -383,     0,     0,     0,     0,  -383,     0,
     590,  -383,     0,     0,   568,     0,     0,     0,   573,   133,
    -208,     0,     0,   133,  -208,  -208,     0,     0,     0,   591,
       0,   133,  1004,  -208,   326,  -208,  -208,     0,   127,   330,
    -208,   331,   332,     0,     0,  -208,   335,     0,  -208,     0,
       0,     0,   144,     0,   342,     0,     0,     0,     0,     0,
       0,     0,   348,     0,   127,   585,   721,  -208,   127,  -208,
     422,  -208,     0,  -208,  -208,     0,  -208,     0,  -208,     0,
    -208,     0,     0,   586,     0,     0,   587,     0,     0,     0,
       0,   742,     0,   671,     0,   280,     0,   241,     0,  -208,
       0,     0,  -208,     0,     0,  -208,   588,     0,     0,   589,
       0,    54,   138,     0,  -387,     0,     0,     0,     0,     0,
     590,   138,     0,     0,  -387,   144,     0,     0,   127,     0,
     805,     0,   144,   138,     0,   138,     0,   133,     0,   591,
       0,     0,   414,   414,     0,     0,   414,   414,     0,     0,
       0,     0,     0,  -387,     0,  -208,     0,     0,     0,     0,
       0,  -208,     0,   976,     0,     0,     0,     0,     0,   980,
       0,   414,     0,   414,     0,   694,   696,     0,     0,  -387,
     138,   701,   704,     0,     0,   144,  -387,   133,   847,     0,
       0,   422,     0,   133,     0,     0,     0,     0,     0,   144,
       0,   127,  -389,     0,   204,    21,   138,  -387,   127,     0,
     138,   742,  -389,     0,   810,    28,   251,     0,     0,     0,
       0,     0,     0,     0,     0,    37,  -387,   813,   814,   651,
       0,  -387,     0,     0,  -387,     0,     0,     0,     0,     0,
       0,  -389,     0,     0,     0,     0,     0,    50,   133,    52,
     133,     0,     0,     0,   887,   133,     0,     0,   133,     0,
      60,   127,     0,   976,     0,   133,     0,  -389,   133,   144,
     138,     0,     0,     0,  -389,   127,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,     0,     0,
     133,   144,   823,   824,     0,  -389,     0,   144,     0,     0,
     826,   133,   141,   133,     0,   144,     0,     0,     0,     0,
       0,   141,   837,     0,  -389,   840,     0,     0,   142,  -389,
       0,     0,  -389,   141,     0,   141,     0,   142,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   142,
       0,   142,     0,   138,     0,   127,     0,     0,     0,     0,
     138,     0,     0,     0,     0,     0,   144,     0,     0,     0,
     144,   805,     0,     0,     0,     0,     0,   127,   144,     0,
     141,     0,     0,   127,     0,     0,     0,     0,     0,     0,
       0,   127,   133,     0,     0,     0,   142,     0,     0,   133,
       0,     0,     0,     0,     0,     0,   141,     0,     0,     0,
     141,   133,     0,   138,     0,     0,     0,     0,   210,     0,
       0,     0,   142,   133,     0,     0,   142,   138,     0,     0,
     211,   212,   133,     0,     0,     0,   133,   213,     0,     0,
       0,     0,   127,     0,     0,   214,   127,     0,     0,     0,
       0,   215,     0,     0,   127,     0,   216,     0,   217,     0,
       0,   218,     0,     0,     0,     0,     0,     0,     0,   219,
     141,     0,     0,     0,     0,   220,   221,   133,     0,     0,
     931,     0,   222,     0,   144,     0,   142,     0,     0,     0,
       0,   223,     0,     0,     0,     0,     0,   138,     0,     0,
     224,   225,     0,   226,     0,   227,     0,   228,     0,     0,
     229,     0,     0,     0,   230,   420,     0,   231,     0,   138,
     232,   133,   133,   133,   133,   138,     0,   204,    21,     0,
       0,     0,     0,   138,   144,     0,     0,     0,    28,   251,
     144,     0,     0,   141,     0,     0,   133,   133,    37,     0,
     141,  -222,     0,     0,     0,     0,     0,     0,     0,   142,
     127,     0,     0,     0,     0,     0,   142,     0,     0,     0,
      50,     0,    52,     0,     0,     0,   421,  -222,     0,     0,
       0,     0,     0,    60,   138,     0,     0,   210,   138,     0,
       0,     0,     0,     0,     0,   144,   138,   144,     0,   211,
     212,     0,   144,   141,     0,   144,   213,   -63,    80,     0,
     127,     0,   144,     0,   214,   144,   127,   141,     0,   142,
     215,     0,     0,     0,     0,   216,     0,   217,     0,     0,
     218,     0,     0,   142,     0,     0,     0,   144,   219,     0,
       0,     0,     0,     0,   220,   221,     0,     0,   144,     0,
     144,   222,     0,     0,     0,     0,     0,     0,     0,     0,
     223,     0,     0,     0,     0,     0,     0,     0,     0,   224,
     225,   127,   226,   127,   227,     0,   228,     0,   127,   229,
       0,   127,     0,   230,     0,   146,   231,   141,   127,   232,
       0,   127,     0,     0,   146,     0,     0,     0,     0,     0,
       0,     0,   138,   142,     0,     0,   146,     0,   146,   141,
       0,     0,     0,   127,     0,   141,     0,     0,     0,     0,
       0,     0,     0,   141,   127,   142,   127,     0,     0,   144,
       0,   142,     0,     0,     0,     0,   144,     0,     0,   142,
       0,     0,     0,   377,     0,   740,     0,     0,   144,     0,
      16,     0,   138,   146,    20,    21,     0,     0,   138,     0,
     144,     0,     0,    27,     0,    28,   876,     0,   322,   144,
      33,     0,     0,   144,   141,    37,     0,     0,   141,   146,
       0,     0,     0,   146,     0,     0,   141,     0,     0,     0,
     142,     0,     0,     0,   142,     0,     0,    50,     0,    52,
       0,    54,   142,   877,     0,   127,   878,     0,    59,     0,
      60,     0,   127,   138,   144,   138,     0,     0,   323,     0,
     138,     0,   324,   138,   127,     0,     0,     0,     0,    76,
     138,     0,    78,   138,     0,    80,   127,     0,     0,     0,
       0,     0,     0,   146,     0,   127,     0,     0,     0,   127,
       0,     0,     0,     0,     0,   138,     0,     0,   144,   144,
     144,   144,     0,     0,     0,     0,   138,     0,   138,   326,
     327,     0,   328,   329,   330,     0,   331,   332,     0,     0,
       0,   335,     0,   144,   144,    94,     0,     0,     0,   342,
     127,   955,   141,     0,     0,   346,   347,   348,     0,     0,
       0,   147,     0,     0,     0,     0,     0,     0,   142,     0,
     147,     0,     0,     0,     0,     0,   146,     0,     0,     0,
       0,     0,   147,   146,   147,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   127,   127,   127,   127,     0,     0,
       0,     0,   141,     0,     0,     0,     0,   138,   141,     0,
       0,     0,     0,     0,   138,     0,     0,     0,   142,   127,
     127,   204,    21,     0,   142,     0,   138,     0,     0,   147,
       0,     0,    28,   251,     0,     0,   146,     0,   138,     0,
       0,     0,    37,     0,     0,  -222,     0,   138,     0,     0,
     146,   138,     0,     0,     0,   147,     0,     0,     0,   147,
       0,     0,     0,   141,    50,   141,    52,     0,     0,     0,
     141,  -222,     0,   141,   322,     0,     0,    60,     0,   142,
     141,   142,     0,   141,     0,     0,   142,     0,     0,   142,
       0,     0,   138,     0,     0,     0,   142,     0,     0,   142,
       0,   -62,    80,     0,     0,   141,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,     0,   141,   147,
     146,   142,     0,     0,   323,     0,     0,     0,   324,     0,
       0,     0,   142,     0,   142,     0,   138,   138,   138,   138,
       0,     0,   146,     0,     0,     0,     0,     0,   146,   101,
       0,     0,     0,     0,     0,     0,   146,     0,   157,     0,
       0,   138,   138,     0,     0,     0,     0,     0,     0,     0,
     186,     0,   189,     0,     0,   326,   327,     0,   328,   329,
     330,     0,   331,   332,     0,     0,     0,   335,     0,     0,
       0,     0,   147,     0,   341,   342,     0,   141,   345,   147,
       0,   346,   347,   348,   141,     0,     0,   146,     0,     0,
       0,   146,     0,   142,     0,     0,   141,   270,     0,   146,
     142,   210,     0,     0,     0,     0,     0,     0,   141,     0,
       0,     0,   142,   211,   212,     0,     0,   141,     0,     0,
     213,   141,     0,   101,   142,     0,     0,   306,   214,     0,
       0,     0,   147,   142,   215,     0,     0,   142,     0,   216,
       0,   217,     0,     0,   218,     0,   147,     0,     0,     0,
       0,     0,   219,     0,     0,     0,     0,     0,   220,   221,
       0,     5,   141,     0,   322,   222,     0,     0,     0,     0,
       0,     0,     0,    14,   223,     0,     0,     0,   142,     0,
      19,     0,     0,   224,   225,     0,   226,   371,   227,     0,
     228,     0,     0,   229,     0,     0,     0,   230,     0,    35,
     231,     0,     0,   232,    38,   146,   141,   141,   141,   141,
       0,     0,    43,     0,   323,     0,   147,     0,   324,    48,
       0,     0,   142,   142,   142,   142,     0,     0,     0,     0,
       0,   141,   141,     0,    58,     0,     0,     0,   147,     0,
       0,     0,     0,     0,   147,     0,    68,   142,   142,   325,
      71,     0,   147,     0,     0,   146,     0,    77,     0,   236,
     417,   146,     0,    81,     0,   326,   327,   430,   328,   329,
     330,     0,   331,   332,   333,     0,   334,   335,   336,   337,
       0,     0,   339,   340,   341,   342,   343,   344,   345,     0,
       0,   346,   347,   348,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   147,     0,     0,     0,   147,     0,   902,
       0,     0,     0,     0,     0,   147,   146,     0,   146,     0,
     101,     0,     0,   146,     0,     0,   146,  -208,     0,     0,
       0,  -208,  -208,   146,   101,     0,   146,     0,     0,     0,
    -208,     0,  -208,  -208,     0,     0,     0,  -208,     0,     0,
       0,     0,  -208,     0,     0,  -208,     0,     0,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   146,
       0,   146,     0,     0,  -208,     0,  -208,     0,  -208,     0,
    -208,  -208,     0,  -208,     0,  -208,     0,  -208,     0,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   101,     0,  -208,     0,     0,  -208,
       0,     0,  -208,     0,     0,   210,     0,     0,     0,     0,
    -491,   147,     0,     0,     0,     0,   430,   211,   212,     0,
       0,     0,   430,   364,   213,     0,  -518,     0,  -518,     0,
       0,     0,   214,     0,     0,     0,     0,     0,   215,     0,
     146,     0,     0,   216,     0,   217,     0,   146,   218,     0,
       0,     0,  -208,     0,     0,     0,   219,     0,  -208,   146,
       0,   147,   220,   221,     0,     0,     0,   147,     0,   222,
       0,   146,     0,     0,     0,     0,     0,     0,   223,     0,
     146,   631,     0,     0,   146,   636,     0,   224,   225,     0,
     226,     0,   227,   101,   228,     0,     0,   229,     0,     0,
       0,   230,     0,     0,   231,     0,     0,   232,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   147,     0,   147,   146,     0,     0,     0,   147,
       0,     0,   147,     0,     0,     0,     0,     0,     0,   147,
       0,     0,   147,     0,     0,     0,     0,     0,     0,     5,
       6,     7,     8,     9,    10,     0,     0,     0,   164,     0,
       0,    14,    15,   720,   147,     0,     0,     0,    19,   146,
     146,   146,   146,     0,     0,   147,    26,   147,     0,     0,
       0,     0,    30,   165,   166,     0,   167,    35,     0,    36,
       0,     0,    38,     0,   146,   146,    40,    41,     0,   712,
      43,    44,     0,    45,    46,     0,    47,    48,     0,     0,
       0,     0,     0,    51,     0,    53,     0,    55,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
     322,    65,    66,    67,    68,    69,   168,     0,    71,     0,
       0,    73,     0,     0,     0,    77,     0,     0,    79,   745,
       0,    81,     0,     0,     0,   750,   147,     0,     0,     0,
    -391,     0,     0,   147,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   147,     0,    87,     0,     0,
     323,  -391,     0,     0,   324,  -391,     0,   147,     0,     0,
       0,     0,     0,     0,     0,     0,   147,     0,     0,   254,
     147,     0,     0,     0,   320,   169,     0,    97,  -391,   916,
     430,   321,   430,     0,     0,     0,     0,   430,     0,     0,
     430,     0,   322,     0,     0,     0,     0,   843,     0,     0,
     845,   326,   327,     0,   328,   329,   330,     0,   331,   332,
     333,   147,     0,   335,   336,   337,     0,     0,   339,   340,
     341,   342,   859,     0,   345,     0,     0,   346,   347,   348,
       0,     0,     0,   865,     0,   869,     0,     0,     0,     0,
       0,     0,   323,     0,     0,     0,   324,     0,     0,     0,
       0,     0,     0,     0,     0,   147,   147,   147,   147,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   402,     0,     0,     0,   325,     0,     0,
     147,   147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   326,   327,     0,   328,   329,   330,     0,
     331,   332,   333,     0,   334,   335,   336,   337,   338,     0,
     339,   340,   341,   342,   343,   344,   345,     0,     0,   346,
     347,   348,     0,     0,     0,     0,     0,     0,   748,     0,
       0,     0,     0,   913,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   930,     0,     0,     0,     0,
       0,     0,     0,     0,   935,     0,     0,     0,   937,     0,
       0,     0,     0,     0,     0,     0,    -2,     4,     0,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    11,    12,
      13,    14,    15,     0,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,     0,    25,    26,     0,    27,   961,
      28,    29,    30,    31,    32,    33,    34,    35,     0,    36,
      37,     0,    38,  -222,     0,    39,    40,    41,     0,    42,
      43,    44,   -43,    45,    46,     0,    47,    48,    49,     0,
       0,     0,    50,    51,    52,    53,    54,    55,    56,  -222,
     -43,    57,    58,    59,     0,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,     0,    71,    72,
       0,    73,    74,    75,    76,    77,     0,    78,    79,   -61,
      80,    81,     0,     0,    82,     0,    83,     0,     0,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,    86,    87,    88,    89,
       0,     0,     0,     0,    90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,     0,     0,    92,    93,     0,
      94,     0,     0,    95,     0,    96,     0,    97,  1023,    98,
       5,     6,     7,     8,     9,    10,     0,     0,     0,   164,
       0,     0,    14,    15,     0,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,     0,     0,    26,     0,     0,
       0,     0,     0,    30,   165,   166,     0,   167,    35,     0,
      36,     0,     0,    38,     0,     0,     0,    40,    41,     0,
       0,    43,    44,     0,    45,    46,     0,    47,    48,     0,
       0,     0,     0,     0,    51,     0,    53,     0,    55,     0,
       0,     0,     0,    58,     0,     0,     0,     0,     0,     0,
       0,     0,    65,    66,    67,    68,    69,   168,     0,    71,
       0,     0,    73,     0,     0,     0,    77,     0,     0,    79,
       0,     0,    81,     0,     0,     0,     0,     0,     0,     0,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    85,    86,    87,    88,
      89,     0,     0,     0,     0,    90,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    91,     0,     0,    92,    93,
     254,     0,     0,     0,    95,     0,   169,     0,    97,     0,
     170,  1024,     4,     0,     5,     6,     7,     8,     9,    10,
       0,  -543,     0,    11,    12,    13,    14,    15,  -543,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,  -543,
      25,    26,  -543,    27,     0,    28,    29,    30,    31,    32,
      33,    34,    35,     0,    36,    37,     0,    38,  -222,     0,
      39,    40,    41,     0,    42,    43,    44,   -43,    45,    46,
       0,    47,    48,    49,     0,     0,     0,    50,    51,    52,
      53,     0,    55,    56,  -222,   -43,    57,    58,    59,  -543,
      60,    61,    62,  -543,    63,    64,    65,    66,    67,    68,
      69,    70,     0,    71,    72,     0,    73,    74,    75,    76,
      77,     0,    78,    79,   -61,    80,    81,     0,     0,    82,
       0,    83,     0,     0,  -543,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -543,  -543,    87,  -543,  -543,  -543,  -543,  -543,  -543,  -543,
       0,  -543,  -543,  -543,  -543,  -543,     0,  -543,  -543,  -543,
    -543,  -543,  -543,  -543,  -543,    94,  -543,  -543,  -543,     0,
      96,  -543,    97,   290,    98,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    11,    12,    13,    14,    15,     0,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       0,    25,    26,     0,    27,     0,    28,    29,    30,    31,
      32,    33,    34,    35,     0,    36,    37,     0,    38,  -222,
       0,    39,    40,    41,     0,    42,    43,    44,   -43,    45,
      46,     0,    47,    48,    49,     0,     0,     0,    50,    51,
      52,    53,    54,    55,    56,  -222,   -43,    57,    58,    59,
       0,    60,    61,    62,     0,    63,    64,    65,    66,    67,
      68,    69,    70,     0,    71,    72,     0,    73,    74,    75,
      76,    77,     0,    78,    79,   -61,    80,    81,     0,     0,
      82,     0,    83,     0,     0,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    85,    86,    87,    88,    89,     0,     0,     0,     0,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      91,     0,     0,    92,    93,   254,    94,     0,     0,    95,
       0,    96,   291,    97,     4,    98,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    11,    12,    13,    14,    15,
       0,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     0,    25,    26,     0,    27,     0,    28,    29,    30,
      31,    32,    33,    34,    35,     0,    36,    37,     0,    38,
    -222,     0,    39,    40,    41,     0,    42,    43,    44,   -43,
      45,    46,     0,    47,    48,    49,     0,     0,     0,    50,
      51,    52,    53,    54,    55,    56,  -222,   -43,    57,    58,
      59,     0,    60,    61,    62,     0,    63,    64,    65,    66,
      67,    68,    69,    70,     0,    71,    72,     0,    73,    74,
      75,    76,    77,     0,    78,    79,   -61,    80,    81,     0,
       0,    82,     0,    83,     0,     0,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    85,    86,    87,    88,    89,     0,     0,     0,
       0,    90,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    91,     0,     0,    92,    93,     0,    94,     0,     0,
      95,     0,    96,   455,    97,   474,    98,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    11,    12,    13,    14,
      15,     0,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,     0,    25,    26,     0,    27,     0,    28,    29,
      30,    31,    32,    33,    34,    35,     0,    36,    37,     0,
      38,  -222,     0,    39,    40,    41,     0,    42,    43,    44,
     -43,    45,    46,     0,    47,    48,    49,     0,     0,     0,
      50,    51,    52,    53,    54,    55,    56,  -222,   -43,    57,
      58,    59,     0,    60,    61,    62,     0,    63,    64,    65,
      66,    67,    68,    69,    70,     0,    71,    72,     0,    73,
      74,    75,    76,    77,     0,    78,    79,   -61,    80,    81,
       0,     0,    82,     0,    83,     0,     0,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    85,    86,    87,    88,    89,     0,     0,
       0,     0,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,     0,     0,    92,    93,     0,    94,     0,
       0,    95,     0,    96,   475,    97,   290,    98,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    11,    12,    13,
      14,    15,     0,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     0,    25,    26,     0,    27,     0,    28,
      29,    30,    31,    32,    33,    34,    35,     0,    36,    37,
       0,    38,  -222,     0,    39,    40,    41,     0,    42,    43,
      44,   -43,    45,    46,     0,    47,    48,    49,     0,     0,
       0,    50,    51,    52,    53,    54,    55,    56,  -222,   -43,
      57,    58,    59,     0,    60,    61,    62,     0,    63,    64,
      65,    66,    67,    68,    69,    70,     0,    71,    72,     0,
      73,    74,    75,    76,    77,     0,    78,    79,   -61,    80,
      81,     0,     0,    82,     0,    83,     0,     0,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,    86,    87,    88,    89,     0,
       0,     0,     0,    90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    91,     0,     0,    92,    93,     0,    94,
       0,     0,    95,     0,    96,   291,    97,     4,    98,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    11,    12,
      13,    14,    15,     0,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,     0,    25,    26,     0,    27,     0,
      28,    29,    30,    31,    32,    33,    34,    35,     0,    36,
      37,     0,    38,  -222,     0,    39,    40,    41,     0,    42,
      43,    44,   -43,    45,    46,     0,    47,    48,    49,     0,
       0,     0,    50,    51,    52,    53,    54,    55,    56,  -222,
     -43,    57,    58,    59,     0,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,     0,    71,    72,
       0,    73,    74,    75,    76,    77,     0,    78,    79,   -61,
      80,    81,     0,     0,    82,     0,    83,     0,     0,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,    86,    87,    88,    89,
       0,     0,     0,     0,    90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,     0,     0,    92,    93,     0,
      94,     0,     0,    95,     0,    96,   643,    97,     4,    98,
       5,     6,     7,     8,     9,    10,     0,     0,     0,    11,
      12,    13,    14,    15,     0,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     0,    25,    26,     0,    27,
       0,    28,    29,    30,    31,    32,    33,    34,    35,     0,
      36,    37,     0,    38,  -222,     0,    39,    40,    41,     0,
      42,    43,    44,   -43,    45,    46,     0,    47,    48,    49,
       0,     0,     0,    50,    51,    52,    53,   305,    55,    56,
    -222,   -43,    57,    58,    59,     0,    60,    61,    62,     0,
      63,    64,    65,    66,    67,    68,    69,    70,     0,    71,
      72,     0,    73,    74,    75,    76,    77,     0,    78,    79,
     -61,    80,    81,     0,     0,    82,     0,    83,     0,     0,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    85,    86,    87,    88,
      89,     0,     0,     0,     0,    90,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    91,     0,     0,    92,    93,
       0,    94,     0,     0,    95,     0,    96,     0,    97,     4,
      98,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      11,    12,    13,    14,    15,     0,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     0,    25,    26,     0,
      27,     0,    28,    29,    30,    31,    32,    33,    34,    35,
       0,    36,    37,     0,    38,  -222,     0,    39,    40,    41,
       0,    42,    43,    44,   -43,    45,    46,     0,    47,    48,
      49,     0,     0,     0,    50,    51,    52,    53,     0,    55,
      56,  -222,   -43,    57,    58,    59,     0,    60,    61,    62,
       0,    63,    64,    65,    66,    67,    68,    69,    70,     0,
      71,    72,     0,    73,    74,    75,    76,    77,     0,    78,
      79,   -61,    80,    81,     0,     0,    82,     0,    83,     0,
       0,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    85,    86,    87,
      88,    89,     0,     0,     0,     0,    90,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    91,     0,     0,    92,
      93,     0,    94,     0,     0,    95,     0,    96,     0,    97,
       4,    98,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    11,    12,    13,    14,    15,     0,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,     0,    25,    26,
       0,    27,     0,    28,    29,    30,    31,    32,    33,   563,
      35,     0,    36,    37,     0,    38,  -222,     0,    39,    40,
      41,     0,    42,    43,    44,   -43,    45,    46,     0,    47,
      48,    49,     0,     0,     0,    50,    51,    52,    53,     0,
      55,    56,  -222,   -43,    57,    58,    59,     0,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
       0,    71,    72,     0,    73,    74,    75,    76,    77,     0,
      78,    79,   -61,    80,    81,     0,     0,    82,     0,    83,
       0,     0,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    85,    86,
      87,    88,    89,     0,     0,     0,     0,    90,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    91,     0,     0,
      92,    93,     0,    94,     0,     0,    95,     0,    96,     0,
      97,     4,    98,     5,     6,     7,     8,     9,    10,     0,
       0,     0,    11,    12,    13,    14,    15,     0,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     0,    25,
      26,     0,    27,     0,    28,    29,    30,    31,    32,    33,
     569,    35,     0,    36,    37,     0,    38,  -222,     0,    39,
      40,    41,     0,    42,    43,    44,   -43,    45,    46,     0,
      47,    48,    49,     0,     0,     0,    50,    51,    52,    53,
       0,    55,    56,  -222,   -43,    57,    58,    59,     0,    60,
      61,    62,     0,    63,    64,    65,    66,    67,    68,    69,
      70,     0,    71,    72,     0,    73,    74,    75,    76,    77,
       0,    78,    79,   -61,    80,    81,     0,     0,    82,     0,
      83,     0,     0,    84,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,     0,     0,     0,     0,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    91,     0,
       0,    92,    93,     0,    94,     0,     0,    95,     0,    96,
       0,    97,     4,    98,     5,     6,     7,     8,     9,    10,
       0,     0,     0,    11,    12,    13,    14,    15,     0,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     0,
      25,    26,     0,    27,     0,    28,    29,    30,    31,    32,
      33,   828,    35,     0,    36,    37,     0,    38,  -222,     0,
      39,    40,    41,     0,    42,    43,    44,   -43,    45,    46,
       0,    47,    48,    49,     0,     0,     0,    50,    51,    52,
      53,     0,    55,    56,  -222,   -43,    57,    58,    59,     0,
      60,    61,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    70,     0,    71,    72,     0,    73,    74,    75,    76,
      77,     0,    78,    79,   -61,    80,    81,     0,     0,    82,
       0,    83,     0,     0,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85,    86,    87,    88,    89,     0,     0,     0,     0,    90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    91,
       0,     0,    92,    93,     0,    94,     0,     0,    95,     0,
      96,     0,    97,     4,    98,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    11,    12,    13,    14,    15,     0,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       0,    25,    26,     0,    27,     0,    28,    29,    30,    31,
      32,    33,   830,    35,     0,    36,    37,     0,    38,  -222,
       0,    39,    40,    41,     0,    42,    43,    44,   -43,    45,
      46,     0,    47,    48,    49,     0,     0,     0,    50,    51,
      52,    53,     0,    55,    56,  -222,   -43,    57,    58,    59,
       0,    60,    61,    62,     0,    63,    64,    65,    66,    67,
      68,    69,    70,     0,    71,    72,     0,    73,    74,    75,
      76,    77,     0,    78,    79,   -61,    80,    81,     0,     0,
      82,     0,    83,     0,     0,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    85,    86,    87,    88,    89,     0,     0,     0,     0,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      91,     0,     0,    92,    93,     0,    94,     0,     0,    95,
       0,    96,     0,    97,     4,    98,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    11,    12,    13,    14,    15,
       0,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     0,    25,    26,     0,    27,     0,    28,    29,    30,
      31,    32,    33,   835,    35,     0,    36,    37,     0,    38,
    -222,     0,    39,    40,    41,     0,    42,    43,    44,   -43,
      45,    46,     0,    47,    48,    49,     0,     0,     0,    50,
      51,    52,    53,     0,    55,    56,  -222,   -43,    57,    58,
      59,     0,    60,    61,    62,     0,    63,    64,    65,    66,
      67,    68,    69,    70,     0,    71,    72,     0,    73,    74,
      75,    76,    77,     0,    78,    79,   -61,    80,    81,     0,
       0,    82,     0,    83,     0,     0,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    85,    86,    87,    88,    89,     0,     0,     0,
       0,    90,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    91,     0,     0,    92,    93,     0,    94,     0,     0,
      95,     0,    96,     0,    97,     4,    98,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    11,    12,    13,    14,
      15,     0,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,     0,    25,    26,     0,    27,     0,    28,    29,
      30,    31,    32,    33,   838,    35,     0,    36,    37,     0,
      38,  -222,     0,    39,    40,    41,     0,    42,    43,    44,
     -43,    45,    46,     0,    47,    48,    49,     0,     0,     0,
      50,    51,    52,    53,     0,    55,    56,  -222,   -43,    57,
      58,    59,     0,    60,    61,    62,     0,    63,    64,    65,
      66,    67,    68,    69,    70,     0,    71,    72,     0,    73,
      74,    75,    76,    77,     0,    78,    79,   -61,    80,    81,
       0,     0,    82,     0,    83,     0,     0,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    85,    86,    87,    88,    89,     0,     0,
       0,     0,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,     0,     0,    92,    93,     0,    94,     0,
       0,    95,     0,    96,     0,    97,     4,    98,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    11,    12,    13,
      14,    15,     0,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     0,   858,    26,     0,    27,     0,    28,
      29,    30,    31,    32,    33,    34,    35,     0,    36,    37,
       0,    38,  -222,     0,    39,    40,    41,     0,    42,    43,
      44,   -43,    45,    46,     0,    47,    48,    49,     0,     0,
       0,    50,    51,    52,    53,     0,    55,    56,  -222,   -43,
      57,    58,    59,     0,    60,    61,    62,     0,    63,    64,
      65,    66,    67,    68,    69,    70,     0,    71,    72,     0,
      73,    74,    75,    76,    77,     0,    78,    79,   -61,    80,
      81,     0,     0,    82,     0,    83,     0,     0,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,    86,    87,    88,    89,     0,
       0,     0,     0,    90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    91,     0,     0,    92,    93,     0,    94,
       0,     0,    95,     0,    96,     0,    97,     4,    98,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    11,    12,
      13,    14,    15,     0,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,     0,    25,    26,     0,    27,     0,
      28,    29,    30,    31,    32,    33,   864,    35,     0,    36,
      37,     0,    38,  -222,     0,    39,    40,    41,     0,    42,
      43,    44,   -43,    45,    46,     0,    47,    48,    49,     0,
       0,     0,    50,    51,    52,    53,     0,    55,    56,  -222,
     -43,    57,    58,    59,     0,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,     0,    71,    72,
       0,    73,    74,    75,    76,    77,     0,    78,    79,   -61,
      80,    81,     0,     0,    82,     0,    83,     0,     0,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,    86,    87,    88,    89,
       0,     0,     0,     0,    90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,     0,     0,    92,    93,     0,
      94,     0,     0,    95,     0,    96,     0,    97,     4,    98,
       5,     6,     7,     8,     9,    10,     0,     0,     0,    11,
      12,    13,    14,    15,     0,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     0,    25,    26,     0,    27,
       0,    28,    29,    30,    31,    32,    33,   868,    35,     0,
      36,    37,     0,    38,  -222,     0,    39,    40,    41,     0,
      42,    43,    44,   -43,    45,    46,     0,    47,    48,    49,
       0,     0,     0,    50,    51,    52,    53,     0,    55,    56,
    -222,   -43,    57,    58,    59,     0,    60,    61,    62,     0,
      63,    64,    65,    66,    67,    68,    69,    70,     0,    71,
      72,     0,    73,    74,    75,    76,    77,     0,    78,    79,
     -61,    80,    81,     0,     0,    82,     0,    83,     0,     0,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    85,    86,    87,    88,
      89,     0,     0,     0,     0,    90,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    91,     0,     0,    92,    93,
       0,    94,     0,     0,    95,     0,    96,     0,    97,   730,
      98,     5,     6,     7,     8,     9,    10,     0,     0,     0,
     164,     0,     0,    14,    15,     0,     0,     0,     0,     0,
      19,     0,     0,     0,     0,     0,     0,     0,    26,     0,
       0,     0,     0,     0,    30,   165,   166,     0,   167,    35,
       0,    36,     0,     0,    38,     0,     0,     0,    40,    41,
       0,     0,    43,    44,     0,    45,    46,     0,    47,    48,
       0,     0,     0,     0,     0,    51,     0,    53,     0,    55,
       0,     0,     0,     0,    58,     0,     0,     0,     0,     0,
       0,     0,     0,    65,    66,    67,    68,    69,   168,     0,
      71,     0,     0,    73,     0,     0,     0,    77,     0,     0,
      79,     0,     0,    81,     0,     0,     0,     0,     0,     0,
       0,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    85,    86,    87,
      88,    89,     0,     0,     0,     0,    90,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    91,     0,     0,    92,
      93,   254,     0,     0,     0,    95,     0,   169,     0,    97,
       0,   170,     5,     6,     7,     8,     9,    10,     0,     0,
       0,   164,     0,     0,    14,    15,     0,     0,     0,     0,
       0,    19,     0,     0,     0,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,    30,   165,   166,     0,   167,
      35,     0,    36,     0,     0,    38,     0,     0,     0,    40,
      41,     0,     0,    43,    44,     0,    45,    46,     0,    47,
      48,     0,     0,     0,     0,     0,    51,     0,    53,     0,
      55,     0,     0,     0,     0,    58,     0,     0,     0,     0,
       0,     0,     0,     0,    65,    66,    67,    68,    69,   168,
       0,    71,     0,     0,    73,     0,     0,     0,    77,     0,
       0,    79,     0,     0,    81,     0,     0,     0,     0,     0,
       0,     0,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    85,    86,
      87,    88,    89,     0,     0,     0,     0,    90,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    91,     0,     0,
      92,    93,   254,     0,     0,     0,    95,     0,   169,     0,
      97,     0,   170,   635,     5,     6,     7,     8,     9,    10,
       0,     0,     0,   164,     0,     0,    14,    15,     0,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,    26,     0,     0,     0,     0,     0,    30,   165,   166,
       0,   167,    35,     0,    36,     0,     0,    38,     0,     0,
       0,    40,    41,     0,     0,    43,    44,     0,    45,    46,
       0,    47,    48,     0,     0,     0,     0,     0,    51,     0,
      53,     0,    55,     0,     0,     0,     0,    58,     0,     0,
       0,     0,     0,     0,     0,     0,    65,    66,    67,    68,
      69,   168,     0,    71,     0,     0,    73,     0,     0,     0,
      77,     0,     0,    79,     0,     0,    81,     0,     0,     0,
       0,     0,     0,     0,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85,    86,    87,    88,    89,     0,     0,     0,     0,    90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    91,
       0,     0,    92,    93,   254,     0,     0,     0,    95,     0,
     169,     0,    97,     0,   170,   964,     5,     6,     7,     8,
       9,    10,     0,     0,     0,   164,     0,     0,    14,    15,
       0,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,     0,     0,    26,     0,     0,     0,     0,     0,    30,
     165,   166,     0,   167,    35,     0,    36,     0,     0,    38,
       0,     0,     0,    40,    41,     0,     0,    43,    44,     0,
      45,    46,     0,    47,    48,     0,     0,     0,     0,     0,
      51,     0,    53,     0,    55,     0,     0,     0,     0,    58,
       0,     0,     0,     0,     0,     0,     0,     0,    65,    66,
      67,    68,    69,   168,     0,    71,     0,     0,    73,     0,
       0,     0,    77,     0,     0,    79,     0,     0,    81,     0,
       0,     0,     0,     0,     0,     0,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   762,     0,
     763,     0,    85,    86,    87,    88,    89,   764,     0,     0,
       0,    90,   765,   212,   766,     0,     0,     0,     0,   767,
       0,    91,     0,     0,    92,    93,     0,   214,     0,     0,
      95,     0,   169,   768,    97,     0,   170,   640,   769,     0,
     217,     0,     0,   770,     0,   771,     0,     0,     0,     0,
       0,   772,     0,     0,     0,     0,     0,   773,   774,     0,
       0,     0,     0,     0,   222,     0,     0,     0,     0,     0,
       0,     0,     0,   775,     0,     0,     0,     0,     0,     0,
       0,     0,   224,   225,     0,   776,     0,   227,     0,   777,
       0,     0,   778,     0,     0,     0,   779,     0,     0,   231,
       0,     0,   780,     0,     0,     0,     0,     0,     0,     0,
       0,   349,   350,   351,   352,   353,   354,     0,     0,   357,
     358,   359,   360,     0,   362,   363,   781,   782,   783,   784,
     785,     0,     0,   786,     0,     0,     0,   787,   788,   789,
     790,   791,   792,   793,   794,   795,   796,   797,     0,   798,
       0,     0,   799,   800,   801,   802,     0,     0,   803,     5,
       6,     7,     8,     9,    10,     0,     0,     0,   164,     0,
       0,    14,    15,     0,     0,     0,     0,     0,    19,   204,
      21,     0,     0,     0,     0,     0,    26,     0,     0,     0,
       0,   205,    30,   165,   166,     0,   167,    35,     0,    36,
       0,     0,    38,     0,     0,     0,    40,    41,     0,     0,
      43,    44,     0,    45,    46,     0,    47,    48,     0,     0,
       0,     0,     0,    51,    52,    53,     0,    55,     0,     0,
       0,     0,    58,     0,     0,    60,     0,     0,     0,     0,
       0,    65,    66,    67,    68,    69,   168,     0,    71,     0,
       0,    73,     0,     0,     0,    77,     0,     0,    79,     0,
      80,    81,     0,     0,     0,     0,     0,     0,     0,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,    86,    87,    88,    89,
       0,     0,     0,     0,    90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,     0,     0,    92,    93,     0,
       0,     0,     0,    95,     0,   169,     0,    97,     0,   170,
       5,     6,     7,     8,   193,    10,   194,     0,     0,   164,
       0,     0,    14,    15,     0,     0,  -121,     0,     0,    19,
       0,     0,     0,     0,     0,     0,     0,    26,     0,     0,
       0,     0,     0,    30,   165,   166,     0,   167,    35,     0,
      36,     0,     0,    38,     0,     0,     0,    40,    41,     0,
       0,    43,    44,     0,    45,    46,     0,    47,    48,     0,
       0,     0,     0,     0,    51,     0,    53,     0,    55,     0,
       0,     0,     0,    58,  -121,     0,     0,     0,     0,     0,
       0,     0,    65,    66,    67,    68,    69,   168,     0,    71,
       0,     0,    73,     0,     0,   195,    77,     0,  -121,    79,
       0,     0,    81,     0,     0,     0,     0,     0,     0,     0,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    85,    86,    87,    88,
      89,     0,     0,     0,     0,    90,     0,     0,     5,     6,
       7,     8,     9,    10,     0,    91,     0,   164,    92,    93,
      14,    15,     0,     0,    95,     0,   169,    19,    97,     0,
     170,     0,     0,     0,     0,    26,     0,     0,     0,     0,
       0,    30,   165,   166,     0,   167,    35,     0,    36,     0,
       0,    38,     0,     0,     0,    40,    41,     0,     0,    43,
      44,     0,    45,    46,     0,    47,    48,     0,     0,     0,
       0,     0,    51,     0,    53,     0,    55,     0,     0,     0,
       0,    58,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    66,    67,    68,    69,   168,     0,    71,     0,     0,
      73,   258,   259,     0,    77,   295,     0,    79,     0,     0,
      81,     0,     0,     0,     0,     0,     0,     0,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,    86,    87,    88,    89,     0,
       0,     0,     0,    90,   296,     0,     0,     0,     0,     0,
       0,     0,     0,    91,     0,     0,    92,    93,   254,     0,
       0,     0,    95,     0,   169,     0,    97,     0,   170,     5,
       6,     7,     8,     9,    10,     0,     0,     0,   164,     0,
       0,    14,    15,     0,     0,     0,     0,     0,    19,     0,
       0,     0,     0,     0,     0,     0,    26,     0,     0,     0,
       0,     0,    30,   165,   166,     0,   167,    35,     0,    36,
       0,     0,    38,     0,     0,     0,    40,    41,     0,     0,
      43,    44,     0,    45,    46,     0,    47,    48,     0,     0,
       0,     0,     0,    51,     0,    53,     0,    55,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
       0,    65,    66,    67,    68,    69,   168,     0,    71,     0,
       0,    73,   258,   259,     0,    77,   295,     0,    79,     0,
       0,    81,     0,     0,     0,     0,     0,     0,     0,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,    86,    87,    88,    89,
       0,     0,     0,     0,    90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,     0,     0,    92,    93,   254,
       0,     0,     0,    95,     0,   169,     0,    97,   627,   170,
       5,     6,     7,     8,     9,    10,     0,     0,     0,   164,
       0,     0,    14,    15,     0,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,     0,     0,    26,     0,     0,
       0,     0,     0,    30,   165,   166,     0,   167,    35,     0,
      36,     0,     0,    38,     0,     0,     0,    40,    41,     0,
       0,    43,    44,     0,    45,    46,     0,    47,    48,     0,
       0,     0,     0,     0,    51,     0,    53,     0,    55,     0,
       0,     0,     0,    58,     0,     0,     0,     0,     0,     0,
       0,     0,    65,    66,    67,    68,    69,   168,     0,    71,
       0,     0,    73,   258,   259,     0,    77,   295,     0,    79,
       0,     0,    81,     0,     0,     0,     0,     0,     0,     0,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    85,    86,    87,    88,
      89,     0,     0,     0,     0,    90,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    91,     0,     0,    92,    93,
     254,     0,     0,     0,    95,     0,   169,     0,    97,   629,
     170,     5,     6,     7,     8,     9,    10,     0,     0,     0,
     164,     0,     0,    14,    15,     0,     0,     0,     0,     0,
      19,     0,   532,     0,     0,     0,     0,     0,    26,     0,
       0,     0,     0,     0,    30,   165,   166,     0,   167,    35,
     533,    36,     0,     0,    38,     0,     0,     0,    40,    41,
       0,     0,    43,    44,     0,    45,    46,     0,    47,    48,
       0,     0,     0,     0,     0,    51,     0,    53,     0,    55,
       0,     0,     0,     0,    58,     0,     0,   534,     0,     0,
       0,     0,     0,    65,    66,    67,    68,    69,   168,     0,
      71,     0,     0,    73,     0,     0,     0,    77,     0,     0,
      79,     0,   535,    81,     0,     0,     0,     0,     0,     0,
       0,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    85,    86,    87,
      88,    89,     0,     0,     0,     0,    90,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    91,     0,     0,    92,
      93,     0,     0,     0,     0,    95,     0,   169,     0,    97,
       0,   170,     5,     6,     7,     8,   193,    10,     0,     0,
       0,   164,     0,     0,    14,    15,     0,     0,  -121,     0,
       0,    19,     0,     0,     0,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,    30,   165,   166,     0,   167,
      35,     0,    36,     0,     0,    38,     0,     0,     0,    40,
      41,     0,     0,    43,    44,     0,    45,    46,     0,    47,
      48,     0,     0,     0,     0,     0,    51,     0,    53,     0,
      55,     0,     0,     0,     0,    58,  -121,     0,     0,     0,
       0,     0,     0,     0,    65,    66,    67,    68,    69,   168,
       0,    71,     0,     0,    73,     0,     0,   195,    77,     0,
    -121,    79,     0,     0,    81,     0,     0,     0,     0,     0,
       0,     0,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    85,    86,
      87,    88,    89,     0,     0,     0,     0,    90,     0,     0,
       5,     6,     7,     8,     9,    10,     0,    91,     0,   164,
      92,    93,    14,    15,     0,     0,    95,     0,   169,    19,
      97,     0,   170,     0,     0,     0,     0,    26,     0,     0,
       0,     0,     0,    30,   165,   166,     0,   167,    35,     0,
      36,     0,     0,    38,     0,     0,     0,    40,    41,     0,
       0,    43,    44,     0,    45,    46,     0,    47,    48,     0,
       0,     0,     0,     0,    51,     0,    53,     0,    55,     0,
       0,     0,     0,    58,     0,     0,     0,     0,     0,     0,
       0,     0,    65,    66,    67,    68,    69,   168,     0,    71,
       0,     0,    73,   258,   259,     0,    77,     0,     0,    79,
       0,     0,    81,     0,     0,     0,     0,     0,     0,     0,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    85,    86,    87,    88,
      89,     0,     0,     0,     0,    90,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    91,     0,     0,    92,    93,
       0,   260,     0,     0,    95,     0,   169,     0,    97,     0,
     170,     5,     6,     7,     8,     9,    10,     0,     0,     0,
     164,     0,     0,    14,    15,     0,     0,     0,     0,     0,
      19,     0,     0,     0,     0,     0,     0,     0,    26,     0,
       0,     0,     0,     0,    30,   165,   166,     0,   167,    35,
       0,    36,     0,     0,    38,     0,     0,     0,    40,    41,
       0,     0,    43,    44,     0,    45,    46,     0,    47,    48,
       0,     0,     0,     0,     0,    51,     0,    53,     0,    55,
       0,     0,     0,     0,    58,     0,     0,     0,     0,     0,
       0,     0,     0,    65,    66,    67,    68,    69,   168,     0,
      71,     0,     0,    73,   258,   259,     0,    77,     0,     0,
      79,     0,     0,    81,     0,     0,     0,     0,     0,     0,
       0,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    85,    86,    87,
      88,    89,     0,     0,     0,     0,    90,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    91,     0,     0,    92,
      93,   254,     0,     0,     0,    95,     0,   169,     0,    97,
       0,   170,     5,     6,     7,     8,     9,    10,     0,     0,
       0,   164,     0,     0,    14,    15,     0,     0,     0,     0,
       0,    19,     0,     0,     0,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,    30,   165,   166,     0,   167,
      35,     0,    36,     0,     0,    38,     0,     0,     0,    40,
      41,     0,     0,    43,    44,     0,    45,    46,   732,    47,
      48,     0,     0,     0,     0,     0,    51,     0,    53,     0,
      55,     0,     0,     0,     0,    58,     0,     0,     0,     0,
       0,     0,     0,     0,    65,    66,    67,    68,    69,   168,
       0,    71,     0,     0,    73,   258,   259,     0,    77,     0,
       0,    79,     0,     0,    81,     0,     0,     0,     0,     0,
       0,     0,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    85,    86,
      87,    88,    89,     0,     0,     0,     0,    90,     0,     0,
       5,     6,     7,     8,     9,    10,     0,    91,     0,   164,
      92,    93,    14,    15,     0,     0,    95,     0,   169,    19,
      97,     0,   170,     0,     0,     0,     0,    26,     0,     0,
       0,     0,     0,    30,   165,   166,     0,   167,    35,     0,
      36,     0,     0,    38,     0,     0,     0,    40,    41,     0,
       0,    43,    44,     0,    45,    46,     0,    47,    48,     0,
       0,     0,     0,     0,    51,   198,    53,     0,    55,     0,
       0,     0,     0,    58,     0,     0,     0,     0,     0,     0,
       0,     0,    65,    66,    67,    68,    69,   168,     0,    71,
       0,     0,    73,     0,     0,     0,    77,     0,     0,    79,
       0,     0,    81,     0,     0,     0,     0,     0,   199,     0,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    85,    86,    87,    88,
      89,     0,     0,     0,     0,    90,     0,     0,     5,     6,
       7,     8,     9,    10,     0,    91,     0,   164,    92,    93,
      14,    15,     0,     0,    95,     0,   169,    19,    97,     0,
     170,     0,     0,     0,     0,    26,     0,     0,     0,     0,
       0,    30,   165,   166,     0,   167,    35,     0,    36,     0,
       0,    38,     0,     0,     0,    40,    41,     0,     0,    43,
      44,     0,    45,    46,     0,    47,    48,     0,     0,     0,
       0,     0,    51,     0,    53,     0,    55,     0,     0,     0,
       0,    58,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    66,    67,    68,    69,   168,     0,    71,     0,     0,
      73,     0,     0,     0,    77,     0,     0,    79,     0,     0,
      81,     0,     0,     0,     0,     0,   199,     0,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,    86,    87,    88,    89,     0,
       0,     0,     0,    90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    91,     0,     0,    92,    93,   254,     0,
       0,     0,    95,     0,   169,     0,    97,     0,   170,     5,
       6,     7,     8,     9,    10,     0,     0,     0,   164,     0,
       0,    14,    15,     0,     0,     0,     0,     0,    19,     0,
       0,     0,     0,     0,     0,     0,    26,     0,     0,     0,
       0,     0,    30,   165,   166,     0,   167,    35,     0,    36,
       0,     0,    38,     0,     0,     0,    40,    41,     0,     0,
      43,    44,     0,    45,    46,     0,    47,    48,     0,     0,
       0,     0,     0,    51,     0,    53,     0,    55,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
       0,    65,    66,    67,    68,    69,   168,     0,    71,     0,
       0,    73,   258,   259,     0,    77,     0,     0,    79,     0,
       0,    81,     0,     0,     0,     0,     0,     0,     0,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,    86,    87,    88,    89,
       0,     0,     0,     0,    90,     0,     0,     5,     6,     7,
       8,     9,    10,     0,    91,     0,   164,    92,    93,    14,
      15,     0,     0,    95,     0,   169,    19,    97,     0,   170,
       0,     0,     0,     0,    26,     0,     0,     0,     0,     0,
      30,   165,   166,     0,   167,    35,     0,    36,     0,     0,
      38,     0,     0,     0,    40,    41,     0,     0,    43,    44,
       0,    45,    46,     0,    47,    48,     0,     0,     0,     0,
       0,    51,     0,    53,     0,    55,     0,     0,     0,     0,
      58,     0,     0,     0,     0,     0,     0,     0,     0,    65,
      66,    67,    68,    69,   168,     0,    71,     0,     0,    73,
       0,     0,     0,    77,     0,     0,    79,     0,     0,    81,
       0,     0,     0,     0,     0,     0,     0,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    85,    86,    87,    88,    89,     0,     0,
       0,     0,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,     0,     0,    92,    93,   254,     0,     0,
       0,    95,     0,   169,   625,    97,     0,   170,     5,     6,
       7,     8,     9,    10,     0,     0,     0,   164,     0,     0,
      14,    15,     0,     0,     0,     0,     0,    19,     0,     0,
       0,     0,     0,     0,     0,    26,     0,     0,     0,     0,
       0,    30,   165,   166,     0,   167,    35,     0,    36,     0,
       0,    38,     0,     0,     0,    40,    41,     0,     0,    43,
      44,     0,    45,    46,     0,    47,    48,     0,     0,     0,
       0,     0,    51,     0,    53,     0,    55,     0,     0,     0,
       0,    58,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    66,    67,    68,    69,   168,     0,    71,     0,     0,
      73,     0,     0,     0,    77,     0,     0,    79,     0,     0,
      81,     0,     0,     0,     0,     0,   199,     0,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,    86,    87,    88,    89,     0,
       0,     0,     0,    90,     0,     0,     5,     6,     7,     8,
       9,    10,     0,    91,     0,   164,    92,    93,    14,    15,
       0,     0,    95,     0,   169,    19,    97,     0,   170,     0,
       0,     0,   240,    26,     0,     0,     0,     0,     0,    30,
     165,   166,     0,   167,    35,     0,    36,     0,     0,    38,
       0,     0,     0,    40,    41,     0,     0,    43,    44,     0,
      45,    46,     0,    47,    48,     0,     0,     0,     0,     0,
      51,     0,    53,     0,    55,     0,     0,     0,     0,    58,
       0,     0,     0,     0,     0,     0,     0,     0,    65,    66,
      67,    68,    69,   168,     0,    71,     0,     0,    73,     0,
       0,     0,    77,     0,     0,    79,     0,     0,    81,     0,
       0,     0,     0,     0,     0,     0,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    85,    86,    87,    88,    89,     0,     0,     0,
       0,    90,     0,     0,     5,     6,     7,     8,     9,    10,
       0,    91,     0,   164,    92,    93,    14,    15,     0,     0,
      95,     0,    96,    19,    97,     0,   170,     0,     0,     0,
       0,    26,     0,     0,     0,     0,     0,    30,   165,   166,
       0,   167,    35,     0,    36,     0,     0,    38,     0,     0,
       0,    40,    41,     0,     0,    43,    44,     0,    45,    46,
       0,    47,    48,     0,     0,     0,     0,     0,    51,     0,
      53,     0,    55,     0,     0,     0,     0,    58,     0,     0,
       0,     0,     0,     0,     0,     0,    65,    66,    67,    68,
      69,   168,     0,    71,     0,     0,    73,     0,     0,     0,
      77,     0,     0,    79,     0,     0,    81,     0,     0,     0,
       0,     0,     0,     0,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85,    86,    87,    88,    89,     0,     0,     0,     0,    90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    91,
       0,     0,    92,    93,   254,     0,     0,     0,    95,     0,
     169,     0,    97,     0,   170,     5,     6,     7,     8,     9,
      10,     0,     0,     0,   164,     0,     0,    14,    15,     0,
       0,     0,     0,     0,    19,     0,     0,     0,     0,     0,
       0,     0,    26,     0,     0,     0,     0,     0,    30,   165,
     166,     0,   167,    35,     0,    36,     0,     0,    38,     0,
       0,     0,    40,    41,     0,     0,    43,    44,     0,    45,
      46,     0,    47,    48,     0,     0,     0,     0,     0,    51,
       0,    53,     0,    55,     0,     0,     0,     0,    58,     0,
       0,     0,     0,     0,     0,     0,     0,    65,    66,    67,
      68,    69,   168,     0,    71,     0,     0,    73,     0,     0,
       0,    77,     0,     0,    79,     0,     0,    81,     0,     0,
       0,     0,     0,     0,     0,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    85,    86,    87,    88,    89,     0,     0,     0,     0,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      91,     0,     0,    92,    93,   504,     0,     0,     0,    95,
       0,   169,     0,    97,     0,   170,     5,     6,     7,     8,
       9,    10,     0,     0,     0,   164,     0,     0,    14,    15,
       0,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,     0,     0,    26,     0,     0,     0,     0,     0,    30,
     165,   166,     0,   167,    35,     0,    36,     0,     0,    38,
       0,     0,     0,    40,    41,     0,     0,    43,    44,     0,
      45,    46,     0,    47,    48,     0,     0,     0,     0,     0,
      51,     0,    53,     0,    55,     0,     0,     0,     0,    58,
       0,     0,     0,     0,     0,     0,     0,     0,    65,    66,
      67,    68,    69,   168,     0,    71,     0,     0,    73,     0,
       0,     0,    77,     0,     0,    79,     0,     0,    81,     0,
       0,     0,     0,     0,     0,     0,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    85,    86,    87,    88,    89,     0,     0,     0,
       0,    90,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    91,     0,     0,    92,    93,   514,     0,     0,     0,
      95,     0,   169,     0,    97,     0,   170,     5,     6,     7,
       8,     9,    10,     0,     0,     0,   164,     0,     0,    14,
      15,     0,     0,     0,     0,     0,    19,     0,     0,     0,
       0,     0,     0,     0,   601,     0,     0,     0,     0,     0,
      30,   165,   166,     0,   167,    35,     0,   602,     0,     0,
      38,     0,     0,     0,    40,    41,     0,     0,    43,    44,
       0,    45,    46,     0,    47,    48,     0,     0,     0,     0,
       0,    51,     0,    53,     0,    55,     0,     0,     0,     0,
      58,     0,     0,     0,     0,     0,     0,     0,     0,    65,
     603,    67,    68,    69,   604,     0,    71,     0,     0,    73,
       0,     0,     0,    77,     0,     0,    79,     0,     0,    81,
       0,     0,     0,     0,     0,     0,     0,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    85,    86,    87,    88,    89,     0,     0,
       0,     0,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,     0,     0,    92,    93,   254,     0,     0,
       0,    95,     0,   169,     0,    97,     0,   916,     5,     6,
       7,     8,     9,    10,     0,     0,     0,   164,     0,     0,
      14,    15,     0,     0,     0,     0,     0,    19,     0,     0,
       0,     0,     0,     0,     0,    26,     0,     0,     0,     0,
       0,    30,   165,   166,     0,   167,    35,     0,    36,     0,
       0,    38,     0,     0,     0,    40,    41,     0,     0,    43,
      44,     0,    45,    46,     0,    47,    48,     0,     0,     0,
       0,     0,    51,     0,    53,     0,    55,     0,     0,     0,
       0,    58,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    66,    67,    68,    69,   168,     0,    71,     0,     0,
      73,     0,     0,     0,    77,     0,     0,    79,     0,     0,
      81,     0,     0,     0,     0,     0,     0,     0,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,    86,    87,    88,    89,     0,
       0,     0,     0,    90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    91,     0,     0,    92,    93,   254,     0,
       0,     0,    95,     0,   169,     0,    97,     0,   916,     5,
       6,     7,     8,     9,    10,     0,     0,     0,   164,     0,
       0,    14,    15,     0,     0,     0,     0,     0,    19,     0,
       0,     0,     0,     0,     0,     0,    26,     0,     0,     0,
       0,     0,    30,   165,   166,     0,   901,    35,     0,    36,
       0,     0,    38,     0,     0,     0,    40,    41,     0,     0,
      43,    44,     0,    45,    46,     0,    47,    48,     0,     0,
       0,     0,     0,    51,     0,    53,     0,    55,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
       0,    65,    66,    67,    68,    69,   168,     0,    71,     0,
       0,    73,     0,     0,     0,    77,     0,     0,    79,     0,
       0,    81,     0,     0,     0,     0,     0,     0,     0,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,    86,    87,    88,    89,
       0,     0,     0,     0,    90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,     0,     0,    92,    93,   254,
       0,     0,     0,    95,     0,   169,     0,    97,     0,   170,
       5,     6,     7,     8,     9,    10,     0,     0,     0,   164,
       0,     0,    14,    15,     0,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,     0,     0,    26,     0,     0,
       0,     0,     0,    30,   165,   166,     0,   167,    35,     0,
      36,     0,     0,    38,     0,     0,     0,    40,    41,     0,
       0,    43,    44,     0,    45,    46,     0,    47,    48,     0,
       0,     0,     0,     0,    51,     0,    53,     0,    55,     0,
       0,     0,     0,    58,     0,     0,     0,     0,     0,     0,
       0,     0,    65,    66,    67,    68,    69,   168,     0,    71,
       0,     0,    73,     0,     0,     0,    77,     0,     0,    79,
       0,     0,    81,     0,     0,     0,     0,     0,     0,     0,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    85,    86,    87,    88,
      89,     0,     0,     0,     0,    90,     0,     0,     5,     6,
       7,     8,     9,    10,     0,    91,     0,   164,    92,    93,
      14,    15,     0,     0,    95,     0,   169,    19,    97,     0,
     170,     0,     0,     0,     0,    26,     0,     0,     0,     0,
       0,    30,   165,   166,     0,   167,    35,     0,    36,     0,
       0,    38,     0,     0,     0,    40,    41,     0,     0,    43,
      44,     0,    45,    46,     0,    47,    48,     0,     0,     0,
       0,     0,    51,     0,    53,     0,    55,     0,     0,     0,
       0,    58,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    66,    67,    68,    69,   168,     0,    71,     0,     0,
      73,     0,     0,     0,    77,     0,     0,    79,     0,     0,
      81,     0,     0,     0,     0,     0,     0,     0,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,    86,    87,    88,    89,     0,
       0,     0,     0,    90,     0,     0,     5,     6,     7,     8,
       9,    10,     0,    91,     0,   164,    92,    93,    14,    15,
       0,     0,    95,     0,    96,    19,    97,     0,   170,     0,
       0,     0,     0,    26,     0,     0,     0,     0,     0,    30,
     165,   166,     0,   167,    35,     0,    36,     0,     0,    38,
       0,     0,     0,    40,    41,     0,     0,    43,    44,     0,
      45,    46,     0,    47,    48,     0,     0,     0,     0,     0,
      51,     0,    53,     0,    55,     0,     0,     0,     0,    58,
       0,     0,     0,     0,     0,     0,     0,     0,    65,    66,
      67,    68,    69,   168,     0,    71,     0,     0,    73,     0,
       0,     0,    77,     0,     0,    79,     0,     0,    81,     0,
       0,     0,     0,     0,     0,     0,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    85,    86,    87,    88,    89,     0,     0,     0,
       0,    90,     0,     0,     5,     6,     7,     8,     9,    10,
       0,    91,     0,   164,    92,    93,    14,    15,     0,     0,
     574,     0,   169,    19,    97,     0,   170,     0,     0,     0,
       0,   601,     0,     0,     0,     0,     0,    30,   165,   166,
       0,   167,    35,     0,   602,     0,     0,    38,     0,     0,
       0,    40,    41,     0,     0,    43,    44,     0,    45,    46,
       0,    47,    48,     0,     0,     0,     0,     0,    51,     0,
      53,     0,    55,     0,     0,     0,     0,    58,     0,     0,
       0,     0,     0,     0,     0,     0,    65,   603,    67,    68,
      69,   604,     0,    71,     0,     0,    73,     0,     0,     0,
      77,     0,     0,    79,     0,     0,    81,     0,     0,     0,
       0,     0,     0,     0,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85,    86,    87,    88,    89,     0,     0,     0,     0,    90,
       0,     0,     5,     6,     7,     8,     9,    10,     0,    91,
       0,   164,    92,    93,    14,    15,     0,     0,    95,     0,
     169,    19,    97,     0,   605,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,    30,   165,   166,     0,   167,
      35,     0,    36,     0,     0,    38,     0,     0,     0,    40,
      41,     0,     0,    43,    44,     0,    45,    46,     0,    47,
      48,     0,     0,     0,     0,     0,    51,     0,    53,     0,
      55,     0,     0,     0,     0,    58,     0,     0,     0,     0,
       0,     0,     0,     0,    65,    66,    67,    68,    69,   168,
       0,    71,     0,     0,    73,     0,     0,     0,    77,     0,
       0,    79,     0,     0,    81,     0,     0,     0,     0,     0,
       0,     0,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    85,    86,
      87,    88,    89,     0,     0,     0,     0,    90,     0,     0,
       5,     6,     7,     8,     9,    10,     0,    91,     0,   164,
      92,    93,    14,    15,     0,     0,    95,     0,   169,    19,
      97,     0,   605,     0,     0,     0,     0,    26,     0,     0,
       0,     0,     0,    30,   165,   166,     0,   674,    35,     0,
      36,     0,     0,    38,     0,     0,     0,    40,    41,     0,
       0,    43,    44,     0,    45,    46,     0,    47,    48,     0,
       0,     0,     0,     0,    51,     0,    53,     0,    55,     0,
       0,     0,     0,    58,     0,     0,     0,     0,     0,     0,
       0,     0,    65,    66,    67,    68,    69,   168,     0,    71,
       0,     0,    73,     0,     0,     0,    77,     0,     0,    79,
       0,     0,    81,     0,     0,     0,     0,     0,     0,     0,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    85,    86,    87,    88,
      89,     0,     0,     0,     0,    90,     0,     0,     5,     6,
       7,     8,     9,    10,     0,    91,     0,   164,    92,    93,
      14,    15,     0,     0,    95,     0,   169,    19,    97,     0,
     170,     0,     0,     0,     0,    26,     0,     0,     0,     0,
       0,    30,   165,   166,     0,   677,    35,     0,    36,     0,
       0,    38,     0,     0,     0,    40,    41,     0,     0,    43,
      44,     0,    45,    46,     0,    47,    48,     0,     0,     0,
       0,     0,    51,     0,    53,     0,    55,     0,     0,     0,
       0,    58,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    66,    67,    68,    69,   168,     0,    71,     0,     0,
      73,     0,     0,     0,    77,     0,     0,    79,     0,     0,
      81,     0,     0,     0,     0,     0,     0,     0,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,    86,    87,    88,    89,     0,
       0,     0,     0,    90,     0,     0,     5,     6,     7,     8,
       9,    10,     0,    91,     0,   164,    92,    93,    14,    15,
       0,     0,    95,     0,   169,    19,    97,     0,   170,     0,
       0,     0,     0,    26,     0,     0,     0,     0,     0,    30,
     165,   166,     0,   895,    35,     0,    36,     0,     0,    38,
       0,     0,     0,    40,    41,     0,     0,    43,    44,     0,
      45,    46,     0,    47,    48,     0,     0,     0,     0,     0,
      51,     0,    53,     0,    55,     0,     0,     0,     0,    58,
       0,     0,     0,     0,     0,     0,     0,     0,    65,    66,
      67,    68,    69,   168,     0,    71,     0,     0,    73,     0,
       0,     0,    77,     0,     0,    79,     0,     0,    81,     0,
       0,     0,     0,     0,     0,     0,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    85,    86,    87,    88,    89,     0,     0,     0,
       0,    90,     0,     0,     5,     6,     7,     8,     9,    10,
       0,    91,     0,   164,    92,    93,    14,    15,     0,     0,
      95,     0,   169,    19,    97,     0,   170,     0,     0,     0,
       0,    26,     0,     0,     0,     0,     0,    30,   165,   166,
       0,   896,    35,     0,    36,     0,     0,    38,     0,     0,
       0,    40,    41,     0,     0,    43,    44,     0,    45,    46,
       0,    47,    48,     0,     0,     0,     0,     0,    51,     0,
      53,     0,    55,     0,     0,     0,     0,    58,     0,     0,
       0,     0,     0,     0,     0,     0,    65,    66,    67,    68,
      69,   168,     0,    71,     0,     0,    73,     0,     0,     0,
      77,     0,     0,    79,     0,     0,    81,     0,     0,     0,
       0,     0,     0,     0,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85,    86,    87,    88,    89,     0,     0,     0,     0,    90,
       0,     0,     5,     6,     7,     8,     9,    10,     0,    91,
       0,   164,    92,    93,    14,    15,     0,     0,    95,     0,
     169,    19,    97,     0,   170,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,    30,   165,   166,     0,   898,
      35,     0,    36,     0,     0,    38,     0,     0,     0,    40,
      41,     0,     0,    43,    44,     0,    45,    46,     0,    47,
      48,     0,     0,     0,     0,     0,    51,     0,    53,     0,
      55,     0,     0,     0,     0,    58,     0,     0,     0,     0,
       0,     0,     0,     0,    65,    66,    67,    68,    69,   168,
       0,    71,     0,     0,    73,     0,     0,     0,    77,     0,
       0,    79,     0,     0,    81,     0,     0,     0,     0,     0,
       0,     0,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    85,    86,
      87,    88,    89,     0,     0,     0,     0,    90,     0,     0,
       5,     6,     7,     8,     9,    10,     0,    91,     0,   164,
      92,    93,    14,    15,     0,     0,    95,     0,   169,    19,
      97,     0,   170,     0,     0,     0,     0,    26,     0,     0,
       0,     0,     0,    30,   165,   166,     0,   899,    35,     0,
      36,     0,     0,    38,     0,     0,     0,    40,    41,     0,
       0,    43,    44,     0,    45,    46,     0,    47,    48,     0,
       0,     0,     0,     0,    51,     0,    53,     0,    55,     0,
       0,     0,     0,    58,     0,     0,     0,     0,     0,     0,
       0,     0,    65,    66,    67,    68,    69,   168,     0,    71,
       0,     0,    73,     0,     0,     0,    77,     0,     0,    79,
       0,     0,    81,     0,     0,     0,     0,     0,     0,     0,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    85,    86,    87,    88,
      89,     0,     0,     0,     0,    90,     0,     0,     5,     6,
       7,     8,     9,    10,     0,    91,     0,   164,    92,    93,
      14,    15,     0,     0,    95,     0,   169,    19,    97,     0,
     170,     0,     0,     0,     0,    26,     0,     0,     0,     0,
       0,    30,   165,   166,     0,   900,    35,     0,    36,     0,
       0,    38,     0,     0,     0,    40,    41,     0,     0,    43,
      44,     0,    45,    46,     0,    47,    48,     0,     0,     0,
       0,     0,    51,     0,    53,     0,    55,     0,     0,     0,
       0,    58,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    66,    67,    68,    69,   168,     0,    71,     0,     0,
      73,     0,     0,     0,    77,     0,     0,    79,     0,     0,
      81,     0,     0,     0,     0,     0,     0,     0,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,    86,    87,    88,    89,     0,
       0,     0,     0,    90,     0,     0,     5,     6,     7,     8,
       9,    10,     0,    91,     0,   164,    92,    93,    14,    15,
       0,     0,    95,     0,   169,    19,    97,     0,   170,     0,
       0,     0,     0,    26,     0,     0,     0,     0,     0,    30,
     165,   166,     0,   901,    35,     0,    36,     0,     0,    38,
       0,     0,     0,    40,    41,     0,     0,    43,    44,     0,
      45,    46,     0,    47,    48,     0,     0,     0,     0,     0,
      51,     0,    53,     0,    55,     0,     0,     0,     0,    58,
       0,     0,     0,     0,     0,     0,     0,     0,    65,    66,
      67,    68,    69,   168,     0,    71,     0,     0,    73,     0,
       0,     0,    77,     0,     0,    79,     0,     0,    81,     0,
       0,     0,     0,     0,     0,     0,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    85,    86,    87,    88,    89,     0,     0,     0,
       0,    90,     0,     0,     5,     6,     7,     8,     9,    10,
       0,    91,     0,   164,    92,    93,    14,    15,     0,     0,
      95,     0,   169,    19,    97,     0,   170,     0,     0,     0,
       0,   601,     0,     0,     0,     0,     0,    30,   165,   166,
       0,   167,    35,     0,   602,     0,     0,    38,     0,     0,
       0,    40,    41,     0,     0,    43,    44,     0,    45,    46,
       0,    47,    48,     0,     0,     0,     0,     0,    51,     0,
      53,     0,    55,     0,     0,     0,     0,    58,     0,     0,
       0,     0,     0,     0,     0,     0,    65,   603,    67,    68,
      69,   604,     0,    71,     0,     0,    73,     0,     0,     0,
      77,     0,     0,    79,     0,     0,    81,     0,     0,     0,
       0,     0,     0,     0,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85,    86,    87,    88,    89,     0,     0,     0,     0,    90,
       0,     0,     5,     6,     7,     8,     9,    10,     0,    91,
       0,   164,    92,    93,    14,    15,     0,     0,    95,     0,
     169,    19,    97,     0,   983,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,    30,   165,   166,     0,   167,
      35,     0,    36,     0,     0,    38,     0,     0,     0,    40,
      41,     0,     0,    43,    44,     0,    45,    46,     0,    47,
      48,     0,     0,     0,     0,     0,    51,     0,    53,     0,
      55,     0,     0,     0,     0,    58,     0,     0,     0,     0,
       0,     0,     0,     0,    65,    66,    67,    68,    69,   168,
       0,    71,     0,     0,    73,     0,     0,     0,    77,     0,
       0,    79,     0,     0,    81,     0,     0,     0,     0,     0,
       0,     0,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    85,    86,
      87,    88,    89,     0,     0,     0,     0,    90,     0,     0,
       5,     6,     7,     8,     9,    10,     0,    91,     0,   164,
      92,    93,    14,    15,     0,     0,    95,     0,     0,    19,
      97,     0,   983,     0,     0,     0,     0,    26,     0,     0,
       0,     0,     0,    30,   165,   166,     0,   167,    35,     0,
      36,     0,     0,    38,     0,     0,     0,    40,    41,     0,
       0,    43,    44,     0,    45,    46,     0,    47,    48,     0,
       0,     0,     0,     0,    51,     0,    53,     0,    55,     0,
       0,     0,     0,    58,     0,     0,     0,     0,     0,     0,
       0,     0,    65,    66,    67,    68,    69,   168,     0,    71,
       0,     0,    73,     0,     0,     0,    77,     0,     0,    79,
       0,     0,    81,     0,     0,     0,     0,     0,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,     0,     0,     0,    85,    86,    87,    88,
      89,     0,     0,     0,     5,     6,     7,     8,     9,    10,
       0,     0,     0,   164,     0,    91,    14,    15,     0,    93,
       0,     0,   364,    19,    95,  -518,   169,  -518,    97,     0,
     170,    26,     0,     0,     0,     0,     0,    30,   165,   166,
       0,   167,    35,     0,    36,     0,     0,    38,     0,     0,
       0,    40,    41,  -373,     0,    43,    44,     0,    45,    46,
       0,    47,    48,     0,     0,     0,     0,     0,    51,     0,
      53,     0,    55,     0,     0,     0,     0,    58,     0,     0,
       0,     0,  -373,     0,     0,     0,    65,    66,    67,    68,
      69,   168,     0,    71,     0,  -373,    73,     0,     0,     0,
      77,     0,     0,    79,     0,     0,    81,     0,  -373,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    87,     0,     5,     6,     7,     8,     9,    10,
       0,     0,     0,   164,     0,     0,    14,    15,     0,     0,
       0,     0,     0,    19,     0,  -373,     0,     0,     0,     0,
    -373,    26,    97,     0,   983,     0,     0,    30,   165,   166,
       0,   167,    35,     0,    36,     0,     0,    38,     0,     0,
       0,    40,    41,     0,     0,    43,    44,     0,    45,    46,
       0,    47,    48,     0,     0,     0,     0,     0,    51,     0,
      53,     0,    55,     0,     0,     0,     0,    58,     0,     0,
       0,     0,     0,     0,     0,     0,    65,    66,    67,    68,
      69,   168,     0,    71,     0,     0,    73,     0,     0,     0,
      77,     0,     0,    79,     0,     0,    81,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     6,
       7,     8,     9,    10,     0,     0,     0,   164,     0,     0,
      14,    15,    87,     0,     0,     0,     0,    19,     0,     0,
       0,     0,     0,     0,     0,    26,     0,     0,     0,     0,
       0,    30,   165,   166,     0,   167,    35,     0,    36,     0,
     169,    38,    97,     0,   170,    40,    41,     0,     0,    43,
      44,     0,    45,    46,     0,    47,    48,     0,     0,     0,
       0,     0,    51,     0,    53,     0,    55,     0,     0,     0,
       0,    58,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    66,    67,    68,    69,   168,     0,    71,     0,     0,
      73,     0,     0,     0,    77,     0,     0,    79,     0,     0,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,     0,     0,
       0,   164,     0,     0,    14,    15,    87,     0,     0,     0,
       0,    19,     0,     0,     0,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,    30,   165,   166,     0,   167,
      35,     0,    36,     0,   169,    38,    97,     0,   605,    40,
      41,     0,     0,    43,    44,     0,    45,    46,     0,    47,
      48,     0,     0,     0,     0,     0,    51,     0,    53,     0,
      55,     0,     0,     0,     0,    58,     0,     0,     0,     0,
       0,     0,     0,   944,    65,    66,    67,    68,    69,   168,
     764,    71,     0,     0,    73,   211,   212,   766,    77,     0,
       0,    79,   213,     0,    81,     0,     0,     0,     0,     0,
     214,     0,     0,     0,     0,     0,   768,     0,     0,     0,
       0,   216,     0,   217,     0,     0,   218,     0,   771,     0,
      87,     0,     0,     0,   219,     0,     0,     0,     0,     0,
     773,   221,     0,     0,     0,     0,   320,   222,     0,     0,
       0,     0,     0,   321,     0,     0,   223,     0,     0,     0,
      97,     0,   170,     0,   322,   224,   225,     0,   226,     0,
     227,     0,   945,     0,     0,   778,     0,     0,     0,   230,
       0,     0,   231,     0,     0,   232,     0,     0,     0,     0,
       0,     0,     0,     0,   349,   350,   351,   352,   353,   354,
       0,     0,   357,   358,   359,   360,     0,   362,   363,   781,
     782,   783,   784,   785,   323,     0,   786,     0,   324,     0,
     787,   788,   789,   790,   791,   792,   793,   794,   795,   796,
     797,     0,   798,   320,     0,   799,   800,   801,   802,     0,
     321,     0,     0,     0,     0,     0,     0,     0,     0,   325,
       0,   322,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   326,   327,     0,   328,   329,
     330,     0,   331,   332,   333,     0,   334,   335,   336,   337,
     338,     0,   339,   340,   341,   342,   343,   344,   345,     0,
     320,   346,   347,   348,     0,     0,     0,   321,     0,     0,
     822,   323,     0,     0,     0,   324,     0,     0,   322,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     320,     0,     0,     0,     0,     0,   325,   321,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   322,     0,
       0,     0,   326,   327,     0,   328,   329,   330,   323,   331,
     332,   333,   324,   334,   335,   336,   337,   338,     0,   339,
     340,   341,   342,   343,   344,   345,     0,     0,   346,   347,
     348,     0,     0,   320,     0,     0,     0,   979,     0,     0,
     321,     0,     0,   325,     0,     0,     0,     0,   323,     0,
       0,   322,   324,     0,     0,     0,     0,     0,     0,   326,
     327,     0,   328,   329,   330,     0,   331,   332,   333,     0,
     334,   335,   336,   337,   338,     0,   339,   340,   341,   342,
     343,   344,   345,   325,     0,   346,   347,   348,     0,     0,
       0,     0,     0,     0,  1046,     0,     0,     0,     0,   326,
     327,   323,   328,   329,   330,   324,   331,   332,   333,     0,
     334,   335,   336,   337,   338,     0,   339,   340,   341,   342,
     343,   344,   345,   320,     0,   346,   347,   348,     0,     0,
     321,     0,   626,     0,     0,     0,   325,     0,     0,     0,
       0,   322,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   326,   327,     0,   328,   329,   330,     0,   331,
     332,   333,     0,   334,   335,   336,   337,   338,     0,   339,
     340,   341,   342,   343,   344,   345,     0,     0,   346,   347,
     348,     0,     0,     0,     0,   943,     0,     0,     0,     0,
       0,   323,     0,     0,     0,   324,     0,     0,     0,   320,
       0,     0,     0,     0,   413,     0,   321,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   322,     0,     0,
       0,     0,     0,     0,     0,     0,   325,   349,   350,   351,
     352,   353,   354,     0,     0,   357,   358,   359,   360,     0,
     362,   363,   326,   327,     0,   328,   329,   330,     0,   331,
     332,   333,     0,   334,   335,   336,   337,   338,     0,   339,
     340,   341,   342,   343,   344,   345,     0,   323,   346,   347,
     348,   324,   377,     0,     0,   320,     0,     0,     0,     0,
     827,     0,   321,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   322,     0,     0,     0,     0,     0,     0,
       0,     0,   325,   349,   350,   351,   352,   353,   354,     0,
       0,   357,   358,   359,   360,     0,   362,   363,   326,   327,
       0,   328,   329,   330,     0,   331,   332,   333,     0,   334,
     335,   336,   337,   338,     0,   339,   340,   341,   342,   343,
     344,   345,     0,   323,   346,   347,   348,   324,   377,     0,
       0,   320,     0,     0,     0,     0,   834,     0,   321,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   322,
       0,     0,     0,     0,     0,     0,     0,     0,   325,   349,
     350,   351,   352,   353,   354,     0,     0,   357,   358,   359,
     360,     0,   362,   363,   326,   327,     0,   328,   329,   330,
       0,   331,   332,   333,     0,   334,   335,   336,   337,   338,
       0,   339,   340,   341,   342,   343,   344,   345,     0,   323,
     346,   347,   348,   324,   377,     0,     0,   320,     0,     0,
       0,     0,   956,     0,   321,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   322,     0,     0,     0,     0,
       0,     0,     0,     0,   325,   349,   350,   351,   352,   353,
     354,     0,     0,   357,   358,   359,   360,     0,   362,   363,
     326,   327,     0,   328,   329,   330,     0,   331,   332,   333,
       0,   334,   335,   336,   337,   338,     0,   339,   340,   341,
     342,   343,   344,   345,     0,   323,   346,   347,   348,   324,
     377,     0,     0,   320,     0,     0,     0,     0,   957,     0,
     321,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   322,     0,     0,     0,     0,     0,     0,     0,     0,
     325,   349,   350,   351,   352,   353,   354,     0,     0,   357,
     358,   359,   360,     0,   362,   363,   326,   327,     0,   328,
     329,   330,     0,   331,   332,   333,     0,   334,   335,   336,
     337,   338,     0,   339,   340,   341,   342,   343,   344,   345,
       0,   323,   346,   347,   348,   324,   377,     0,     0,   320,
       0,     0,     0,     0,   958,     0,   321,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   322,     0,     0,
       0,     0,     0,     0,     0,     0,   325,   349,   350,   351,
     352,   353,   354,     0,     0,   357,   358,   359,   360,     0,
     362,   363,   326,   327,     0,   328,   329,   330,     0,   331,
     332,   333,     0,   334,   335,   336,   337,   338,     0,   339,
     340,   341,   342,   343,   344,   345,     0,   323,   346,   347,
     348,   324,   377,     0,     0,   320,     0,     0,     0,     0,
     959,     0,   321,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   322,     0,     0,     0,     0,     0,     0,
       0,     0,   325,   349,   350,   351,   352,   353,   354,     0,
       0,   357,   358,   359,   360,     0,   362,   363,   326,   327,
       0,   328,   329,   330,     0,   331,   332,   333,     0,   334,
     335,   336,   337,   338,     0,   339,   340,   341,   342,   343,
     344,   345,     0,   323,   346,   347,   348,   324,   377,     0,
       0,   320,     0,     0,     0,     0,   981,     0,   321,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   322,
       0,     0,     0,     0,     0,     0,     0,     0,   325,   349,
     350,   351,   352,   353,   354,     0,     0,   357,   358,   359,
     360,     0,   362,   363,   326,   327,     0,   328,   329,   330,
       0,   331,   332,   333,     0,   334,   335,   336,   337,   338,
       0,   339,   340,   341,   342,   343,   344,   345,     0,   323,
     346,   347,   348,   324,   377,     0,     0,     0,     0,     0,
       0,     0,   982,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   325,   349,   350,   351,   352,   353,
     354,     0,     0,   357,   358,   359,   360,     0,   362,   363,
     326,   327,     0,   328,   329,   330,     0,   331,   332,   333,
       0,   334,   335,   336,   337,   338,     0,   339,   340,   341,
     342,   343,   344,   345,   320,     0,   346,   347,   348,     0,
     377,   321,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   322,   405,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   406,     0,     0,     0,
       0,     0,     0,     0,     0,   320,     0,     0,     0,     0,
       0,     0,   321,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   322,   399,     0,     0,     0,     0,     0,
       0,     0,   323,     0,     0,     0,   324,   400,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     320,     0,     0,     0,     0,     0,     0,   321,     0,     0,
       0,     0,     0,   402,     0,     0,     0,   325,   322,   703,
       0,     0,     0,   323,     0,     0,     0,   324,     0,     0,
       0,     0,     0,   326,   327,     0,   328,   329,   330,     0,
     331,   332,   333,     0,   334,   335,   336,   337,   338,     0,
     339,   340,   341,   342,   343,   344,   345,     0,   325,   346,
     347,   348,     0,   377,     0,     0,     0,     0,   323,     0,
       0,   322,   324,     0,   326,   327,     0,   328,   329,   330,
       0,   331,   332,   333,     0,   334,   335,   336,   337,   338,
       0,   339,   340,   341,   342,   343,   344,   345,   320,   402,
     346,   347,   348,   325,   377,   321,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   322,   240,     0,   326,
     327,   323,   328,   329,   330,   324,   331,   332,   333,     0,
     334,   335,   336,   337,   338,     0,   339,   340,   341,   342,
     343,   344,   345,   320,     0,   346,   347,   348,     0,   377,
     321,     0,     0,     0,     0,     0,   325,     0,     0,     0,
       0,   322,   695,     0,     0,     0,   323,     0,     0,     0,
     324,     0,   326,   327,     0,   328,   329,   330,     0,   331,
     332,   333,     0,   334,   335,   336,   337,     0,     0,   339,
     340,   341,   342,   343,     0,   345,     0,     0,   346,   347,
     348,   325,     0,     0,     0,     0,   322,     0,     0,     0,
       0,   323,     0,     0,     0,   324,     0,   326,   327,     0,
     328,   329,   330,     0,   331,   332,   333,     0,   334,   335,
     336,   337,   338,     0,   339,   340,   341,   342,   343,   344,
     345,   320,     0,   346,   347,   348,   325,   377,   321,     0,
       0,     0,     0,     0,     0,     0,   323,     0,     0,   322,
     324,     0,   326,   327,     0,   328,   329,   330,     0,   331,
     332,   333,     0,   334,   335,   336,   337,   338,     0,   339,
     340,   341,   342,   343,   344,   345,   320,     0,   346,   347,
     348,     0,   377,   321,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   322,     0,     0,   326,   327,   323,
     328,   329,   330,   324,   331,   332,   333,     0,   334,   335,
     336,   337,   713,     0,   339,   340,   341,   342,   343,     0,
     345,     0,     0,   346,   347,   348,     0,     0,     0,   320,
       0,     0,     0,     0,   325,     0,   321,     0,     0,     0,
       0,     0,     0,     0,   323,     0,     0,   322,   324,     0,
     326,   327,   410,   328,   329,   330,     0,   331,   332,   333,
       0,   334,   335,   336,   337,   338,     0,   339,   340,   341,
     342,   343,   344,   345,     0,     0,   346,   347,   348,   325,
     377,     0,   411,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   326,   327,   323,   328,   329,
     330,   324,   331,   332,   333,     0,   334,   335,   336,   337,
     338,     0,   339,   340,   341,   342,   343,   344,   345,     0,
       0,   346,   347,   348,     0,   440,   320,     0,     0,     0,
       0,     0,   325,   321,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   322,     0,     0,     0,   326,   327,
       0,   328,   329,   330,     0,   331,   332,   333,   379,   334,
     335,   336,   337,   338,     0,   339,   340,   341,   342,   343,
     344,   345,   320,   412,   346,   347,   348,     0,     0,   321,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     322,   541,     0,     0,   323,     0,     0,     0,   324,     0,
       0,     0,     0,     0,   542,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   159,     0,     0,     0,   325,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     323,     0,     0,     0,   324,   326,   327,     0,   328,   329,
     330,     0,   331,   332,   333,     0,   334,   335,   336,   337,
     338,     0,   339,   340,   341,   342,   343,   344,   345,   320,
       0,   346,   347,   348,     0,   325,   321,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   322,   543,     0,
       0,   326,   327,     0,   328,   329,   330,     0,   331,   332,
     333,   544,   334,   335,   336,   337,   338,     0,   339,   340,
     341,   342,   343,   344,   345,   320,     0,   346,   347,   348,
       0,     0,   321,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   322,     0,     0,     0,   323,   646,     0,
       0,   324,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   320,     0,     0,     0,     0,
       0,     0,   321,     0,     0,     0,     0,     0,   647,     0,
       0,     0,   325,   322,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   323,     0,     0,     0,   324,   326,   327,
       0,   328,   329,   330,     0,   331,   332,   333,     0,   334,
     335,   336,   337,   338,     0,   339,   340,   341,   342,   343,
     344,   345,   320,     0,   346,   347,   348,     0,   325,   321,
       0,     0,     0,   323,     0,     0,     0,   324,     0,     0,
     322,     0,     0,     0,   326,   327,     0,   328,   329,   330,
       0,   331,   332,   333,     0,   334,   335,   336,   337,   338,
       0,   339,   340,   341,   342,   343,   344,   345,   325,     0,
     346,   347,   348,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   326,   327,     0,   328,   329,   330,
     323,   331,   332,   333,   324,   334,   335,   336,   337,   338,
       0,   339,   340,   341,   342,   343,   344,   345,   320,   444,
     346,   347,   348,     0,     0,   321,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   325,   322,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   326,   327,     0,   328,   329,   330,     0,   331,   332,
     333,     0,   334,   335,   336,   337,   338,     0,   339,   340,
     341,   342,   343,   344,   345,   320,   446,   346,   347,   348,
       0,     0,   321,     0,     0,     0,   323,     0,     0,     0,
     324,     0,     0,   322,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   320,     0,     0,     0,     0,
       0,   325,   321,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   322,     0,     0,     0,   326,   327,     0,
     328,   329,   330,   323,   331,   332,   333,   324,   334,   335,
     336,   337,   338,     0,   339,   340,   341,   342,   343,   344,
     345,   320,   448,   346,   347,   348,     0,     0,   321,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   325,   322,
       0,     0,     0,   323,     0,     0,     0,   324,     0,     0,
       0,     0,     0,     0,   326,   327,   545,   328,   329,   330,
       0,   331,   332,   333,     0,   334,   335,   336,   337,   338,
       0,   339,   340,   341,   342,   343,   344,   345,   325,   453,
     346,   347,   348,     0,     0,     0,     0,     0,     0,   323,
       0,     0,     0,   324,   326,   327,     0,   328,   329,   330,
       0,   331,   332,   333,     0,   334,   335,   336,   337,   338,
       0,   339,   340,   341,   342,   343,   344,   345,   320,     0,
     346,   347,   348,   470,   325,   321,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   322,     0,     0,     0,
     326,   327,     0,   328,   329,   330,     0,   331,   332,   333,
       0,   334,   335,   336,   337,   338,     0,   339,   340,   341,
     342,   343,   344,   345,     0,     0,   346,   347,   348,     0,
       0,   320,     0,     0,     0,     0,     0,     0,   321,     0,
       0,     0,     0,     0,     0,     0,   323,     0,     0,   322,
     324,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   320,     0,     0,     0,     0,     0,     0,   321,     0,
       0,   325,     0,     0,     0,     0,     0,     0,     0,   322,
       0,     0,     0,     0,     0,     0,     0,   326,   327,   323,
     328,   329,   330,   324,   331,   332,   333,     0,   334,   335,
     336,   337,   338,  -492,   339,   340,   341,   342,   343,   344,
     345,     0,     0,   346,   347,   348,     0,     0,   320,   708,
     159,     0,     0,     0,   325,   321,     0,     0,     0,   323,
       0,     0,     0,   324,     0,     0,   322,     0,     0,     0,
     326,   327,     0,   328,   329,   330,     0,   331,   332,   333,
       0,   334,   335,   336,   337,   338,     0,   339,   340,   341,
     342,   343,   344,   345,   325,     0,   346,   347,   348,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     326,   327,     0,   328,   329,   330,   323,   331,   332,   333,
     324,   334,   335,   336,   337,   338,     0,   339,   340,   341,
     342,   343,   344,   345,   320,   684,   346,   347,   348,     0,
       0,   321,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   325,   322,     0,     0,   711,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   326,   327,     0,
     328,   329,   330,     0,   331,   332,   333,     0,   334,   335,
     336,   337,   338,     0,   339,   340,   341,   342,   343,   344,
     345,   320,     0,   346,   347,   348,     0,     0,   321,     0,
       0,     0,   323,     0,     0,     0,   324,     0,     0,   322,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   320,     0,     0,     0,     0,     0,     0,
     321,     0,     0,     0,     0,     0,     0,   325,     0,     0,
       0,   322,   817,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   326,   327,     0,   328,   329,   330,   323,
     331,   332,   333,   324,   334,   335,   336,   337,   338,     0,
     339,   340,   341,   342,   343,   344,   345,     0,     0,   346,
     347,   348,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   323,     0,   751,   325,   324,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     326,   327,     0,   328,   329,   330,     0,   331,   332,   333,
       0,   334,   335,   336,   337,   338,   325,   339,   340,   341,
     342,   343,   344,   345,   320,     0,   346,   347,   348,     0,
       0,   321,   326,   327,     0,   328,   329,   330,     0,   331,
     332,   333,   322,   334,   335,   336,   337,   338,     0,   339,
     340,   341,   342,   343,   344,   345,   320,     0,   346,   347,
     348,     0,     0,   321,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   322,   820,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   323,     0,     0,     0,   324,     0,     0,     0,
       0,     0,     0,     0,     0,   894,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   323,     0,     0,   325,   324,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   326,   327,     0,   328,   329,   330,     0,
     331,   332,   333,     0,   334,   335,   336,   337,   338,   325,
     339,   340,   341,   342,   343,   344,   345,   320,     0,   346,
     347,   348,     0,     0,   321,   326,   327,     0,   328,   329,
     330,     0,   331,   332,   333,   322,   334,   335,   336,   337,
     338,     0,   339,   340,   341,   342,   343,   344,   345,   320,
     911,   346,   347,   348,     0,     0,   321,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   322,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   323,     0,     0,     0,   324,
       0,     0,     0,     0,     0,     0,     0,     0,   897,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   323,     0,     0,
     325,   324,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   326,   327,     0,   328,
     329,   330,     0,   331,   332,   333,     0,   334,   335,   336,
     337,   338,   325,   339,   340,   341,   342,   343,   344,   345,
     320,     0,   346,   347,   348,     0,     0,   321,   326,   327,
       0,   328,   329,   330,     0,   331,   332,   333,   322,   334,
     335,   336,   337,   338,     0,   339,   340,   341,   342,   343,
     344,   345,   320,     0,   346,   347,   348,     0,     0,   321,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     322,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   323,     0,
       0,     0,   324,     0,     0,     0,     0,     0,     0,     0,
       0,   992,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     323,     0,     0,   325,   324,     0,     0,     0,     0,     0,
       0,     0,     0,   993,     0,     0,     0,     0,     0,   326,
     327,     0,   328,   329,   330,     0,   331,   332,   333,     0,
     334,   335,   336,   337,   338,   325,   339,   340,   341,   342,
     343,   344,   345,   320,     0,   346,   347,   348,     0,     0,
     321,   326,   327,     0,   328,   329,   330,     0,   331,   332,
     333,   322,   334,   335,   336,   337,   338,     0,   339,   340,
     341,   342,   343,   344,   345,   320,     0,   346,   347,   348,
       0,     0,   321,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   322,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   323,     0,     0,     0,   324,     0,     0,     0,     0,
       0,     0,     0,     0,   994,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   323,     0,     0,   325,   324,     0,     0,
       0,     0,     0,     0,     0,     0,   995,     0,     0,     0,
       0,     0,   326,   327,     0,   328,   329,   330,     0,   331,
     332,   333,     0,   334,   335,   336,   337,   338,   325,   339,
     340,   341,   342,   343,   344,   345,   320,     0,   346,   347,
     348,     0,     0,   321,   326,   327,     0,   328,   329,   330,
       0,   331,   332,   333,   322,   334,   335,   336,   337,   338,
       0,   339,   340,   341,   342,   343,   344,   345,   320,     0,
     346,   347,   348,     0,     0,   321,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   322,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   323,     0,     0,     0,   324,     0,
       0,     0,     0,     0,     0,     0,     0,   996,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   323,     0,     0,   325,
     324,     0,     0,     0,     0,     0,     0,     0,     0,   997,
       0,     0,     0,     0,     0,   326,   327,     0,   328,   329,
     330,     0,   331,   332,   333,     0,   334,   335,   336,   337,
     338,   325,   339,   340,   341,   342,   343,   344,   345,   320,
       0,   346,   347,   348,     0,     0,   321,   326,   327,     0,
     328,   329,   330,     0,   331,   332,   333,   322,   334,   335,
     336,   337,   338,     0,   339,   340,   341,   342,   343,   344,
     345,   320,     0,   346,   347,   348,     0,     0,   321,     0,
       0,  1019,     0,     0,     0,     0,     0,     0,     0,   322,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   323,     0,     0,
       0,   324,     0,     0,     0,     0,     0,     0,     0,     0,
     320,     0,     0,     0,     0,     0,     0,   321,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   322,   323,
       0,     0,   325,   324,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   326,   327,
       0,   328,   329,   330,     0,   331,   332,   333,     0,   334,
     335,   336,   337,   338,   325,   339,   340,   341,   342,   343,
     344,   345,     0,     0,   346,   347,   348,     0,   672,     0,
     326,   327,   324,   328,   329,   330,     0,   331,   332,   333,
       0,   334,   335,   336,   337,   338,     0,   339,   340,   341,
     342,   343,   344,   345,     0,     0,   346,   347,   348,     0,
       0,     0,     0,   325,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   326,
     327,     0,   328,   329,   330,     0,   331,   332,   333,     0,
     334,   335,   336,   337,   338,     0,   339,   340,   341,   342,
     343,   344,   345,     0,    16,   346,   347,   348,    20,    21,
       0,     0,     0,     0,     0,     0,     0,    27,     0,    28,
     876,   650,     0,   210,    33,     0,     0,     0,     0,    37,
       0,     0,     0,     0,     0,   211,   212,     0,     0,     0,
       0,     0,   213,     0,     0,     0,     0,     0,     0,     0,
     214,    50,     0,    52,     0,   305,   215,   877,     0,     0,
     878,   216,    59,   217,    60,     0,   218,     0,     0,     0,
       0,     0,     0,     0,   219,     0,     0,     0,     0,     0,
     220,   221,     0,    76,     0,     0,    78,   222,     0,    80,
     210,     0,     0,     0,     0,     0,   223,     0,     0,     0,
       0,     0,   211,   212,     0,   224,   225,     0,   226,   213,
     227,     0,   228,     0,     0,   229,     0,   214,     0,   230,
       0,     0,   231,   215,     0,   232,     0,     0,   216,     0,
     217,     0,     0,   218,     0,     0,     0,     0,     0,    94,
       0,   219,     0,     0,     0,     0,     0,   220,   221,     0,
       0,     0,     0,     0,   222,     0,     0,     0,     0,     0,
       0,     0,     0,   223,     0,     0,     0,     0,     0,     0,
       0,     0,   224,   225,     0,   226,     0,   227,     0,   228,
       0,     0,   229,     0,     0,     0,   230,     0,     0,   231,
       0,     0,   232
};

static const yytype_int16 yycheck[] =
{
      11,   144,     2,   370,    15,   418,   182,    18,    56,    57,
      17,    61,   203,    24,   449,   131,   567,    28,    29,   195,
      31,    32,    33,    34,   209,    20,   411,    28,   659,   729,
       1,    42,     1,    44,    45,    64,   755,    29,    49,   421,
      51,   926,    53,   190,   600,    29,    29,    29,    98,   154,
      61,    62,    63,    64,    65,    66,    42,     1,   426,    70,
      81,    72,   209,    74,    75,   250,    29,   183,    79,    42,
     850,    82,    83,     1,    85,    42,    87,   106,   847,    90,
      91,   449,    93,   964,   269,    96,    97,    98,   114,   109,
     154,     1,   109,    64,   808,   809,   160,    52,     3,    42,
     135,     0,    79,   250,    62,   135,    42,   135,    52,   135,
     301,   302,   812,   139,    42,   671,    31,    32,   669,    42,
     170,   135,   269,   109,   109,   109,   109,     3,  1009,   164,
      81,   160,   162,   276,   162,   106,   162,    81,   159,    97,
       3,  1026,    52,    97,   164,   114,   915,   164,   162,   135,
      94,   851,   107,   164,   165,   166,   167,   168,   169,   170,
     940,   880,   135,   107,   161,   134,   135,   159,   135,    19,
     726,    81,   135,   161,   181,   159,   159,   159,   164,   190,
       7,   366,   367,    98,   903,   332,   114,    92,    28,   160,
     134,   164,   135,   162,   205,     3,   159,   107,   209,   135,
     567,    24,   197,   154,   205,    81,   134,   135,   159,   204,
     154,   135,   135,  1024,   914,   159,    92,   599,    19,   366,
     367,   164,    30,   970,   134,   107,   154,    77,   164,   114,
     154,  1042,   946,   947,   135,    42,   190,    42,    78,   250,
     251,   164,    82,  1009,   161,    68,    54,   258,   259,   159,
     135,   101,    89,   135,   139,   209,    79,   442,   269,   890,
     310,   162,   647,   963,   135,   135,  1013,  1014,  1015,  1016,
    1017,  1018,    79,   135,    79,    98,    77,   162,    47,   395,
    1046,   832,   154,   161,    92,   296,   159,   135,   160,   129,
      98,   162,   162,   293,   134,   442,   250,   137,   160,   310,
     101,   141,   669,   103,    73,   718,   154,    24,   319,   320,
     321,   322,   323,   324,   325,   269,   327,   328,   329,   330,
     331,   135,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   720,    42,
     135,   135,   755,   135,   355,   356,    24,   397,   162,   114,
     361,    68,    74,   364,   365,   366,   367,   368,   369,   370,
     135,    64,    79,   135,   135,    28,   160,   162,   379,   154,
     162,    74,    75,   384,   139,   386,   161,   135,   163,   154,
     571,   572,   154,   154,    24,   129,   397,   104,   399,   400,
      68,   154,   135,   137,   405,   406,   154,   355,   356,   410,
     411,    79,   413,   361,   415,   153,   364,   365,   323,   324,
     557,   154,   366,   367,   409,    78,   161,   428,   163,    82,
      98,   129,   857,    78,   435,   154,   104,    82,    68,   137,
     480,   442,   137,   134,    78,   161,   137,   163,    82,    79,
     141,   154,   633,   634,   154,   161,   457,   163,   624,   460,
     161,   462,   163,   368,   369,   466,   467,   468,    98,   470,
     471,   460,   145,   462,   379,   832,   129,   130,   154,   480,
     133,   134,   885,   136,   137,   154,   476,   180,   141,    74,
      75,   435,   850,    52,   154,   400,   149,   161,   442,   857,
     903,   406,   155,   156,   157,   114,   154,   200,   201,   202,
     203,   154,   460,   457,   462,   208,   460,   159,   462,   108,
     161,   161,    81,   467,   161,   154,   659,   114,    52,   154,
       7,   140,   134,   142,   143,    94,    56,   146,   147,   159,
     541,   542,   543,   544,   545,   546,   547,   154,   107,   114,
     243,   548,   549,   246,   555,    52,   557,    81,   162,   135,
     561,   466,   563,   154,    42,   605,   567,   161,   569,    31,
      94,   135,   265,    19,   162,   114,   162,    23,    24,   162,
      39,   162,   940,   107,    81,    18,    32,   135,    34,    35,
     283,   164,   164,    39,   154,   154,   159,    94,    44,   154,
     159,   154,   603,   604,   605,   154,   964,   555,   609,   154,
     107,   555,   162,   557,   154,    31,   135,    76,   164,   154,
      66,   979,    68,   154,    70,   162,    72,     2,   160,    75,
     154,    77,   162,    79,   135,   159,    11,   542,   160,   544,
     114,    79,    29,    29,   159,   646,   647,   164,    23,    31,
      25,  1009,    98,   134,    79,   101,   164,   154,   104,   134,
     164,   609,   159,   154,   164,   124,  1024,   126,   669,   154,
      28,   672,   673,   674,   160,   129,   677,   161,    31,   137,
      28,   137,   137,   162,  1042,    24,   137,   380,  1046,   137,
     129,   162,   693,   137,   695,    70,   736,   137,   129,   700,
     137,   137,   703,    42,    94,   706,    45,   708,   154,   137,
     711,   404,   129,   137,   160,   408,   129,   160,   129,   129,
      78,    96,   164,   182,    82,   100,    65,   135,   307,    68,
      78,    70,   647,    22,    82,   736,   195,   646,   740,   198,
      79,   277,   825,   196,    64,   746,   758,   748,   559,   890,
     751,   885,   718,   592,  1026,   761,   757,   890,   963,    98,
     988,  1019,  1012,    33,   429,   557,    -1,   672,   673,    -1,
      -1,   129,   130,    -1,   132,   133,   134,   236,   136,   137,
     138,   129,   130,   141,    -1,   160,   134,    -1,   136,   137,
     148,   149,    -1,   141,   152,   254,   135,   155,   156,   157,
      -1,   149,   803,    -1,    -1,    -1,    -1,   155,   156,   157,
      -1,    -1,    -1,    -1,    -1,   816,   817,    -1,   819,   820,
     821,   822,    -1,   162,    -1,    -1,   827,   828,    -1,   830,
      -1,   832,    -1,   834,   835,    -1,    -1,   838,    28,   877,
     878,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   856,   857,    -1,   233,    -1,
      -1,   862,    -1,   864,    -1,   240,    -1,   868,    -1,    -1,
      -1,    -1,   565,   566,    -1,   876,   916,    -1,   571,   572,
     200,   201,   202,   203,    -1,    -1,    -1,    -1,    78,    -1,
     583,    -1,    82,   894,   895,   896,   897,   898,   899,   900,
     901,    -1,    -1,    -1,    -1,    -1,   850,    -1,    -1,    -1,
     911,    -1,    -1,    -1,    -1,   916,    -1,    -1,   293,    -1,
     921,    -1,    -1,   243,   925,    -1,   246,   620,    -1,    -1,
      -1,    -1,   307,    -1,    -1,   394,    -1,    -1,    -1,   129,
      -1,    -1,    -1,   983,   134,   265,   136,   137,    -1,    -1,
      -1,   141,    -1,    -1,    -1,   956,   957,   958,   959,   149,
      -1,    42,   421,   283,     2,   155,   156,   157,    -1,    -1,
      -1,    52,    -1,    11,    -1,    -1,    -1,   921,   979,    -1,
     981,   982,   983,    -1,    -1,    23,    -1,    25,    -1,   682,
     683,   992,   993,   994,   995,   996,   997,   690,    -1,   692,
      81,    -1,   377,    28,    -1,    -1,   699,  1008,  1009,   702,
    1011,    -1,   705,    -1,    -1,    -1,    -1,    -1,   477,    -1,
     964,    -1,    -1,   482,   399,    24,   107,    -1,    -1,    -1,
     405,    -1,    70,   114,    -1,    -1,    74,    75,   413,    -1,
       2,  1042,    -1,    42,    -1,  1046,    45,    -1,    -1,    11,
     743,    -1,    -1,    78,   135,    -1,    -1,    82,    96,    -1,
     380,    23,   100,    25,    -1,  1009,    65,    -1,    -1,    68,
      -1,    70,     1,   154,    -1,    -1,    -1,    -1,   159,    -1,
      79,   162,    -1,    -1,   404,    -1,    -1,    -1,   408,   464,
      19,    -1,    -1,   468,    23,    24,    -1,    -1,    -1,    98,
      -1,   476,  1046,    32,   129,    34,    35,    -1,    70,   134,
      39,   136,   137,    -1,    -1,    44,   141,    -1,    47,    -1,
      -1,    -1,   160,    -1,   149,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   157,    -1,    96,    24,   595,    66,   100,    68,
     599,    70,    -1,    72,    73,    -1,    75,    -1,    77,    -1,
      79,    -1,    -1,    42,    -1,    -1,    45,    -1,    -1,    -1,
      -1,   620,    -1,   538,    -1,   624,    -1,   860,    -1,    98,
      -1,    -1,   101,    -1,    -1,   104,    65,    -1,    -1,    68,
      -1,    70,     2,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      79,    11,    -1,    -1,    52,   233,    -1,    -1,   160,    -1,
     659,    -1,   240,    23,    -1,    25,    -1,   582,    -1,    98,
      -1,    -1,   905,   906,    -1,    -1,   909,   910,    -1,    -1,
      -1,    -1,    -1,    81,    -1,   154,    -1,    -1,    -1,    -1,
      -1,   160,    -1,   926,    -1,    -1,    -1,    -1,    -1,   932,
      -1,   934,    -1,   936,    -1,   565,   566,    -1,    -1,   107,
      70,   571,   572,    -1,    -1,   293,   114,   632,   717,    -1,
      -1,   720,    -1,   638,    -1,    -1,    -1,    -1,    -1,   307,
      -1,   233,    42,    -1,    23,    24,    96,   135,   240,    -1,
     100,   740,    52,    -1,   659,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,   154,   672,   673,   758,
      -1,   159,    -1,    -1,   162,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    -1,    -1,    66,   693,    68,
     695,    -1,    -1,    -1,   783,   700,    -1,    -1,   703,    -1,
      79,   293,    -1,  1026,    -1,   710,    -1,   107,   713,   377,
     160,    -1,    -1,    -1,   114,   307,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,
     735,   399,   682,   683,    -1,   135,    -1,   405,    -1,    -1,
     690,   746,     2,   748,    -1,   413,    -1,    -1,    -1,    -1,
      -1,    11,   702,    -1,   154,   705,    -1,    -1,     2,   159,
      -1,    -1,   162,    23,    -1,    25,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      -1,    25,    -1,   233,    -1,   377,    -1,    -1,    -1,    -1,
     240,    -1,    -1,    -1,    -1,    -1,   464,    -1,    -1,    -1,
     468,   890,    -1,    -1,    -1,    -1,    -1,   399,   476,    -1,
      70,    -1,    -1,   405,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   413,   827,    -1,    -1,    -1,    70,    -1,    -1,   834,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,
     100,   846,    -1,   293,    -1,    -1,    -1,    -1,     3,    -1,
      -1,    -1,    96,   858,    -1,    -1,   100,   307,    -1,    -1,
      15,    16,   867,    -1,    -1,    -1,   871,    22,    -1,    -1,
      -1,    -1,   464,    -1,    -1,    30,   468,    -1,    -1,    -1,
      -1,    36,    -1,    -1,   476,    -1,    41,    -1,    43,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
     160,    -1,    -1,    -1,    -1,    60,    61,   912,    -1,    -1,
     860,    -1,    67,    -1,   582,    -1,   160,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,   377,    -1,    -1,
      85,    86,    -1,    88,    -1,    90,    -1,    92,    -1,    -1,
      95,    -1,    -1,    -1,    99,   100,    -1,   102,    -1,   399,
     105,   956,   957,   958,   959,   405,    -1,    23,    24,    -1,
      -1,    -1,    -1,   413,   632,    -1,    -1,    -1,    34,    35,
     638,    -1,    -1,   233,    -1,    -1,   981,   982,    44,    -1,
     240,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   233,
     582,    -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,
      66,    -1,    68,    -1,    -1,    -1,   161,    73,    -1,    -1,
      -1,    -1,    -1,    79,   464,    -1,    -1,     3,   468,    -1,
      -1,    -1,    -1,    -1,    -1,   693,   476,   695,    -1,    15,
      16,    -1,   700,   293,    -1,   703,    22,   103,   104,    -1,
     632,    -1,   710,    -1,    30,   713,   638,   307,    -1,   293,
      36,    -1,    -1,    -1,    -1,    41,    -1,    43,    -1,    -1,
      46,    -1,    -1,   307,    -1,    -1,    -1,   735,    54,    -1,
      -1,    -1,    -1,    -1,    60,    61,    -1,    -1,   746,    -1,
     748,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      86,   693,    88,   695,    90,    -1,    92,    -1,   700,    95,
      -1,   703,    -1,    99,    -1,     2,   102,   377,   710,   105,
      -1,   713,    -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   582,   377,    -1,    -1,    23,    -1,    25,   399,
      -1,    -1,    -1,   735,    -1,   405,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   413,   746,   399,   748,    -1,    -1,   827,
      -1,   405,    -1,    -1,    -1,    -1,   834,    -1,    -1,   413,
      -1,    -1,    -1,   159,    -1,   161,    -1,    -1,   846,    -1,
      19,    -1,   632,    70,    23,    24,    -1,    -1,   638,    -1,
     858,    -1,    -1,    32,    -1,    34,    35,    -1,    28,   867,
      39,    -1,    -1,   871,   464,    44,    -1,    -1,   468,    96,
      -1,    -1,    -1,   100,    -1,    -1,   476,    -1,    -1,    -1,
     464,    -1,    -1,    -1,   468,    -1,    -1,    66,    -1,    68,
      -1,    70,   476,    72,    -1,   827,    75,    -1,    77,    -1,
      79,    -1,   834,   693,   912,   695,    -1,    -1,    78,    -1,
     700,    -1,    82,   703,   846,    -1,    -1,    -1,    -1,    98,
     710,    -1,   101,   713,    -1,   104,   858,    -1,    -1,    -1,
      -1,    -1,    -1,   160,    -1,   867,    -1,    -1,    -1,   871,
      -1,    -1,    -1,    -1,    -1,   735,    -1,    -1,   956,   957,
     958,   959,    -1,    -1,    -1,    -1,   746,    -1,   748,   129,
     130,    -1,   132,   133,   134,    -1,   136,   137,    -1,    -1,
      -1,   141,    -1,   981,   982,   154,    -1,    -1,    -1,   149,
     912,   160,   582,    -1,    -1,   155,   156,   157,    -1,    -1,
      -1,     2,    -1,    -1,    -1,    -1,    -1,    -1,   582,    -1,
      11,    -1,    -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,
      -1,    -1,    23,   240,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   956,   957,   958,   959,    -1,    -1,
      -1,    -1,   632,    -1,    -1,    -1,    -1,   827,   638,    -1,
      -1,    -1,    -1,    -1,   834,    -1,    -1,    -1,   632,   981,
     982,    23,    24,    -1,   638,    -1,   846,    -1,    -1,    70,
      -1,    -1,    34,    35,    -1,    -1,   293,    -1,   858,    -1,
      -1,    -1,    44,    -1,    -1,    47,    -1,   867,    -1,    -1,
     307,   871,    -1,    -1,    -1,    96,    -1,    -1,    -1,   100,
      -1,    -1,    -1,   693,    66,   695,    68,    -1,    -1,    -1,
     700,    73,    -1,   703,    28,    -1,    -1,    79,    -1,   693,
     710,   695,    -1,   713,    -1,    -1,   700,    -1,    -1,   703,
      -1,    -1,   912,    -1,    -1,    -1,   710,    -1,    -1,   713,
      -1,   103,   104,    -1,    -1,   735,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   746,    -1,   748,   160,
     377,   735,    -1,    -1,    78,    -1,    -1,    -1,    82,    -1,
      -1,    -1,   746,    -1,   748,    -1,   956,   957,   958,   959,
      -1,    -1,   399,    -1,    -1,    -1,    -1,    -1,   405,     2,
      -1,    -1,    -1,    -1,    -1,    -1,   413,    -1,    11,    -1,
      -1,   981,   982,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    -1,    25,    -1,    -1,   129,   130,    -1,   132,   133,
     134,    -1,   136,   137,    -1,    -1,    -1,   141,    -1,    -1,
      -1,    -1,   233,    -1,   148,   149,    -1,   827,   152,   240,
      -1,   155,   156,   157,   834,    -1,    -1,   464,    -1,    -1,
      -1,   468,    -1,   827,    -1,    -1,   846,    70,    -1,   476,
     834,     3,    -1,    -1,    -1,    -1,    -1,    -1,   858,    -1,
      -1,    -1,   846,    15,    16,    -1,    -1,   867,    -1,    -1,
      22,   871,    -1,    96,   858,    -1,    -1,   100,    30,    -1,
      -1,    -1,   293,   867,    36,    -1,    -1,   871,    -1,    41,
      -1,    43,    -1,    -1,    46,    -1,   307,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    61,
      -1,     3,   912,    -1,    28,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    76,    -1,    -1,    -1,   912,    -1,
      22,    -1,    -1,    85,    86,    -1,    88,   160,    90,    -1,
      92,    -1,    -1,    95,    -1,    -1,    -1,    99,    -1,    41,
     102,    -1,    -1,   105,    46,   582,   956,   957,   958,   959,
      -1,    -1,    54,    -1,    78,    -1,   377,    -1,    82,    61,
      -1,    -1,   956,   957,   958,   959,    -1,    -1,    -1,    -1,
      -1,   981,   982,    -1,    76,    -1,    -1,    -1,   399,    -1,
      -1,    -1,    -1,    -1,   405,    -1,    88,   981,   982,   113,
      92,    -1,   413,    -1,    -1,   632,    -1,    99,    -1,   161,
     233,   638,    -1,   105,    -1,   129,   130,   240,   132,   133,
     134,    -1,   136,   137,   138,    -1,   140,   141,   142,   143,
      -1,    -1,   146,   147,   148,   149,   150,   151,   152,    -1,
      -1,   155,   156,   157,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   464,    -1,    -1,    -1,   468,    -1,     1,
      -1,    -1,    -1,    -1,    -1,   476,   693,    -1,   695,    -1,
     293,    -1,    -1,   700,    -1,    -1,   703,    19,    -1,    -1,
      -1,    23,    24,   710,   307,    -1,   713,    -1,    -1,    -1,
      32,    -1,    34,    35,    -1,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    47,    -1,    -1,   735,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   746,
      -1,   748,    -1,    -1,    66,    -1,    68,    -1,    70,    -1,
      72,    73,    -1,    75,    -1,    77,    -1,    79,    -1,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   377,    -1,    98,    -1,    -1,   101,
      -1,    -1,   104,    -1,    -1,     3,    -1,    -1,    -1,    -1,
     145,   582,    -1,    -1,    -1,    -1,   399,    15,    16,    -1,
      -1,    -1,   405,   158,    22,    -1,   161,    -1,   163,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,
     827,    -1,    -1,    41,    -1,    43,    -1,   834,    46,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    54,    -1,   160,   846,
      -1,   632,    60,    61,    -1,    -1,    -1,   638,    -1,    67,
      -1,   858,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,
     867,   464,    -1,    -1,   871,   468,    -1,    85,    86,    -1,
      88,    -1,    90,   476,    92,    -1,    -1,    95,    -1,    -1,
      -1,    99,    -1,    -1,   102,    -1,    -1,   105,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   693,    -1,   695,   912,    -1,    -1,    -1,   700,
      -1,    -1,   703,    -1,    -1,    -1,    -1,    -1,    -1,   710,
      -1,    -1,   713,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,
      -1,    15,    16,   161,   735,    -1,    -1,    -1,    22,   956,
     957,   958,   959,    -1,    -1,   746,    30,   748,    -1,    -1,
      -1,    -1,    36,    37,    38,    -1,    40,    41,    -1,    43,
      -1,    -1,    46,    -1,   981,   982,    50,    51,    -1,   582,
      54,    55,    -1,    57,    58,    -1,    60,    61,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    69,    -1,    71,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    85,    86,    87,    88,    89,    90,    -1,    92,    -1,
      -1,    95,    -1,    -1,    -1,    99,    -1,    -1,   102,   632,
      -1,   105,    -1,    -1,    -1,   638,   827,    -1,    -1,    -1,
     114,    -1,    -1,   834,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   846,    -1,   131,    -1,    -1,
      78,   135,    -1,    -1,    82,   139,    -1,   858,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   867,    -1,    -1,   153,
     871,    -1,    -1,    -1,    10,   159,    -1,   161,   162,   163,
     693,    17,   695,    -1,    -1,    -1,    -1,   700,    -1,    -1,
     703,    -1,    28,    -1,    -1,    -1,    -1,   710,    -1,    -1,
     713,   129,   130,    -1,   132,   133,   134,    -1,   136,   137,
     138,   912,    -1,   141,   142,   143,    -1,    -1,   146,   147,
     148,   149,   735,    -1,   152,    -1,    -1,   155,   156,   157,
      -1,    -1,    -1,   746,    -1,   748,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    -1,    -1,    -1,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   956,   957,   958,   959,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,    -1,    -1,    -1,   113,    -1,    -1,
     981,   982,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,    -1,   132,   133,   134,    -1,
     136,   137,   138,    -1,   140,   141,   142,   143,   144,    -1,
     146,   147,   148,   149,   150,   151,   152,    -1,    -1,   155,
     156,   157,    -1,    -1,    -1,    -1,    -1,    -1,   164,    -1,
      -1,    -1,    -1,   846,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   858,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   867,    -1,    -1,    -1,   871,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    12,    13,
      14,    15,    16,    -1,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    30,    -1,    32,   912,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    43,
      44,    -1,    46,    47,    -1,    49,    50,    51,    -1,    53,
      54,    55,    56,    57,    58,    -1,    60,    61,    62,    -1,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    79,    80,    81,    -1,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    92,    93,
      -1,    95,    96,    97,    98,    99,    -1,   101,   102,   103,
     104,   105,    -1,    -1,   108,    -1,   110,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
      -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   148,    -1,    -1,   151,   152,    -1,
     154,    -1,    -1,   157,    -1,   159,    -1,   161,     1,   163,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,    -1,
      43,    -1,    -1,    46,    -1,    -1,    -1,    50,    51,    -1,
      -1,    54,    55,    -1,    57,    58,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    69,    -1,    71,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    87,    88,    89,    90,    -1,    92,
      -1,    -1,    95,    -1,    -1,    -1,    99,    -1,    -1,   102,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   148,    -1,    -1,   151,   152,
     153,    -1,    -1,    -1,   157,    -1,   159,    -1,   161,    -1,
     163,   164,     1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    12,    13,    14,    15,    16,    17,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    43,    44,    -1,    46,    47,    -1,
      49,    50,    51,    -1,    53,    54,    55,    56,    57,    58,
      -1,    60,    61,    62,    -1,    -1,    -1,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,    92,    93,    -1,    95,    96,    97,    98,
      99,    -1,   101,   102,   103,   104,   105,    -1,    -1,   108,
      -1,   110,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
      -1,   140,   141,   142,   143,   144,    -1,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,    -1,
     159,   160,   161,     1,   163,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    12,    13,    14,    15,    16,    -1,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    29,    30,    -1,    32,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    43,    44,    -1,    46,    47,
      -1,    49,    50,    51,    -1,    53,    54,    55,    56,    57,
      58,    -1,    60,    61,    62,    -1,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    79,    80,    81,    -1,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,    93,    -1,    95,    96,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,    -1,    -1,
     108,    -1,   110,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,
     138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     148,    -1,    -1,   151,   152,   153,   154,    -1,    -1,   157,
      -1,   159,   160,   161,     1,   163,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    13,    14,    15,    16,
      -1,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    30,    -1,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    43,    44,    -1,    46,
      47,    -1,    49,    50,    51,    -1,    53,    54,    55,    56,
      57,    58,    -1,    60,    61,    62,    -1,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    79,    80,    81,    -1,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    92,    93,    -1,    95,    96,
      97,    98,    99,    -1,   101,   102,   103,   104,   105,    -1,
      -1,   108,    -1,   110,    -1,    -1,   113,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   148,    -1,    -1,   151,   152,    -1,   154,    -1,    -1,
     157,    -1,   159,   160,   161,     1,   163,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    12,    13,    14,    15,
      16,    -1,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    30,    -1,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    43,    44,    -1,
      46,    47,    -1,    49,    50,    51,    -1,    53,    54,    55,
      56,    57,    58,    -1,    60,    61,    62,    -1,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    79,    80,    81,    -1,    83,    84,    85,
      86,    87,    88,    89,    90,    -1,    92,    93,    -1,    95,
      96,    97,    98,    99,    -1,   101,   102,   103,   104,   105,
      -1,    -1,   108,    -1,   110,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,   131,   132,   133,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   148,    -1,    -1,   151,   152,    -1,   154,    -1,
      -1,   157,    -1,   159,   160,   161,     1,   163,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    -1,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    30,    -1,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    43,    44,
      -1,    46,    47,    -1,    49,    50,    51,    -1,    53,    54,
      55,    56,    57,    58,    -1,    60,    61,    62,    -1,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    79,    80,    81,    -1,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    92,    93,    -1,
      95,    96,    97,    98,    99,    -1,   101,   102,   103,   104,
     105,    -1,    -1,   108,    -1,   110,    -1,    -1,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   148,    -1,    -1,   151,   152,    -1,   154,
      -1,    -1,   157,    -1,   159,   160,   161,     1,   163,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    12,    13,
      14,    15,    16,    -1,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    30,    -1,    32,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    43,
      44,    -1,    46,    47,    -1,    49,    50,    51,    -1,    53,
      54,    55,    56,    57,    58,    -1,    60,    61,    62,    -1,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    79,    80,    81,    -1,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    92,    93,
      -1,    95,    96,    97,    98,    99,    -1,   101,   102,   103,
     104,   105,    -1,    -1,   108,    -1,   110,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
      -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   148,    -1,    -1,   151,   152,    -1,
     154,    -1,    -1,   157,    -1,   159,   160,   161,     1,   163,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      13,    14,    15,    16,    -1,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    30,    -1,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      43,    44,    -1,    46,    47,    -1,    49,    50,    51,    -1,
      53,    54,    55,    56,    57,    58,    -1,    60,    61,    62,
      -1,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    79,    80,    81,    -1,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,    -1,    -1,   108,    -1,   110,    -1,    -1,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   148,    -1,    -1,   151,   152,
      -1,   154,    -1,    -1,   157,    -1,   159,    -1,   161,     1,
     163,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      12,    13,    14,    15,    16,    -1,    -1,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    30,    -1,
      32,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    43,    44,    -1,    46,    47,    -1,    49,    50,    51,
      -1,    53,    54,    55,    56,    57,    58,    -1,    60,    61,
      62,    -1,    -1,    -1,    66,    67,    68,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    -1,    79,    80,    81,
      -1,    83,    84,    85,    86,    87,    88,    89,    90,    -1,
      92,    93,    -1,    95,    96,    97,    98,    99,    -1,   101,
     102,   103,   104,   105,    -1,    -1,   108,    -1,   110,    -1,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,    -1,    -1,   151,
     152,    -1,   154,    -1,    -1,   157,    -1,   159,    -1,   161,
       1,   163,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    13,    14,    15,    16,    -1,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    30,
      -1,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    44,    -1,    46,    47,    -1,    49,    50,
      51,    -1,    53,    54,    55,    56,    57,    58,    -1,    60,
      61,    62,    -1,    -1,    -1,    66,    67,    68,    69,    -1,
      71,    72,    73,    74,    75,    76,    77,    -1,    79,    80,
      81,    -1,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,    92,    93,    -1,    95,    96,    97,    98,    99,    -1,
     101,   102,   103,   104,   105,    -1,    -1,   108,    -1,   110,
      -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,    -1,    -1,
     151,   152,    -1,   154,    -1,    -1,   157,    -1,   159,    -1,
     161,     1,   163,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    12,    13,    14,    15,    16,    -1,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      30,    -1,    32,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    43,    44,    -1,    46,    47,    -1,    49,
      50,    51,    -1,    53,    54,    55,    56,    57,    58,    -1,
      60,    61,    62,    -1,    -1,    -1,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    -1,    79,
      80,    81,    -1,    83,    84,    85,    86,    87,    88,    89,
      90,    -1,    92,    93,    -1,    95,    96,    97,    98,    99,
      -1,   101,   102,   103,   104,   105,    -1,    -1,   108,    -1,
     110,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,    -1,
      -1,   151,   152,    -1,   154,    -1,    -1,   157,    -1,   159,
      -1,   161,     1,   163,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    13,    14,    15,    16,    -1,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      29,    30,    -1,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    43,    44,    -1,    46,    47,    -1,
      49,    50,    51,    -1,    53,    54,    55,    56,    57,    58,
      -1,    60,    61,    62,    -1,    -1,    -1,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    -1,
      79,    80,    81,    -1,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,    92,    93,    -1,    95,    96,    97,    98,
      99,    -1,   101,   102,   103,   104,   105,    -1,    -1,   108,
      -1,   110,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,
      -1,    -1,   151,   152,    -1,   154,    -1,    -1,   157,    -1,
     159,    -1,   161,     1,   163,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    12,    13,    14,    15,    16,    -1,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    29,    30,    -1,    32,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    43,    44,    -1,    46,    47,
      -1,    49,    50,    51,    -1,    53,    54,    55,    56,    57,
      58,    -1,    60,    61,    62,    -1,    -1,    -1,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      -1,    79,    80,    81,    -1,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,    93,    -1,    95,    96,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,    -1,    -1,
     108,    -1,   110,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,
     138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     148,    -1,    -1,   151,   152,    -1,   154,    -1,    -1,   157,
      -1,   159,    -1,   161,     1,   163,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    13,    14,    15,    16,
      -1,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    30,    -1,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    43,    44,    -1,    46,
      47,    -1,    49,    50,    51,    -1,    53,    54,    55,    56,
      57,    58,    -1,    60,    61,    62,    -1,    -1,    -1,    66,
      67,    68,    69,    -1,    71,    72,    73,    74,    75,    76,
      77,    -1,    79,    80,    81,    -1,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    92,    93,    -1,    95,    96,
      97,    98,    99,    -1,   101,   102,   103,   104,   105,    -1,
      -1,   108,    -1,   110,    -1,    -1,   113,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   148,    -1,    -1,   151,   152,    -1,   154,    -1,    -1,
     157,    -1,   159,    -1,   161,     1,   163,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    12,    13,    14,    15,
      16,    -1,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    30,    -1,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    43,    44,    -1,
      46,    47,    -1,    49,    50,    51,    -1,    53,    54,    55,
      56,    57,    58,    -1,    60,    61,    62,    -1,    -1,    -1,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    -1,    79,    80,    81,    -1,    83,    84,    85,
      86,    87,    88,    89,    90,    -1,    92,    93,    -1,    95,
      96,    97,    98,    99,    -1,   101,   102,   103,   104,   105,
      -1,    -1,   108,    -1,   110,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,   131,   132,   133,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   148,    -1,    -1,   151,   152,    -1,   154,    -1,
      -1,   157,    -1,   159,    -1,   161,     1,   163,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    -1,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    30,    -1,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    43,    44,
      -1,    46,    47,    -1,    49,    50,    51,    -1,    53,    54,
      55,    56,    57,    58,    -1,    60,    61,    62,    -1,    -1,
      -1,    66,    67,    68,    69,    -1,    71,    72,    73,    74,
      75,    76,    77,    -1,    79,    80,    81,    -1,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    92,    93,    -1,
      95,    96,    97,    98,    99,    -1,   101,   102,   103,   104,
     105,    -1,    -1,   108,    -1,   110,    -1,    -1,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   148,    -1,    -1,   151,   152,    -1,   154,
      -1,    -1,   157,    -1,   159,    -1,   161,     1,   163,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    12,    13,
      14,    15,    16,    -1,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    30,    -1,    32,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    43,
      44,    -1,    46,    47,    -1,    49,    50,    51,    -1,    53,
      54,    55,    56,    57,    58,    -1,    60,    61,    62,    -1,
      -1,    -1,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    -1,    79,    80,    81,    -1,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    92,    93,
      -1,    95,    96,    97,    98,    99,    -1,   101,   102,   103,
     104,   105,    -1,    -1,   108,    -1,   110,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
      -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   148,    -1,    -1,   151,   152,    -1,
     154,    -1,    -1,   157,    -1,   159,    -1,   161,     1,   163,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      13,    14,    15,    16,    -1,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    30,    -1,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      43,    44,    -1,    46,    47,    -1,    49,    50,    51,    -1,
      53,    54,    55,    56,    57,    58,    -1,    60,    61,    62,
      -1,    -1,    -1,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    77,    -1,    79,    80,    81,    -1,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,    -1,    -1,   108,    -1,   110,    -1,    -1,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   148,    -1,    -1,   151,   152,
      -1,   154,    -1,    -1,   157,    -1,   159,    -1,   161,     1,
     163,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      12,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,
      -1,    43,    -1,    -1,    46,    -1,    -1,    -1,    50,    51,
      -1,    -1,    54,    55,    -1,    57,    58,    -1,    60,    61,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    69,    -1,    71,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    87,    88,    89,    90,    -1,
      92,    -1,    -1,    95,    -1,    -1,    -1,    99,    -1,    -1,
     102,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,    -1,    -1,   151,
     152,   153,    -1,    -1,    -1,   157,    -1,   159,    -1,   161,
      -1,   163,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,
      41,    -1,    43,    -1,    -1,    46,    -1,    -1,    -1,    50,
      51,    -1,    -1,    54,    55,    -1,    57,    58,    -1,    60,
      61,    -1,    -1,    -1,    -1,    -1,    67,    -1,    69,    -1,
      71,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
      -1,    92,    -1,    -1,    95,    -1,    -1,    -1,    99,    -1,
      -1,   102,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,    -1,    -1,
     151,   152,   153,    -1,    -1,    -1,   157,    -1,   159,    -1,
     161,    -1,   163,   164,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    -1,    -1,    15,    16,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      -1,    40,    41,    -1,    43,    -1,    -1,    46,    -1,    -1,
      -1,    50,    51,    -1,    -1,    54,    55,    -1,    57,    58,
      -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      69,    -1,    71,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,    -1,    92,    -1,    -1,    95,    -1,    -1,    -1,
      99,    -1,    -1,   102,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,
      -1,    -1,   151,   152,   153,    -1,    -1,    -1,   157,    -1,
     159,    -1,   161,    -1,   163,   164,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    -1,    -1,    15,    16,
      -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,    46,
      -1,    -1,    -1,    50,    51,    -1,    -1,    54,    55,    -1,
      57,    58,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    69,    -1,    71,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,    -1,    92,    -1,    -1,    95,    -1,
      -1,    -1,    99,    -1,    -1,   102,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
       3,    -1,   129,   130,   131,   132,   133,    10,    -1,    -1,
      -1,   138,    15,    16,    17,    -1,    -1,    -1,    -1,    22,
      -1,   148,    -1,    -1,   151,   152,    -1,    30,    -1,    -1,
     157,    -1,   159,    36,   161,    -1,   163,   164,    41,    -1,
      43,    -1,    -1,    46,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    -1,    88,    -1,    90,    -1,    92,
      -1,    -1,    95,    -1,    -1,    -1,    99,    -1,    -1,   102,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,   115,   116,   117,   118,   119,    -1,    -1,   122,
     123,   124,   125,    -1,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,   136,    -1,    -1,    -1,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,    -1,   152,
      -1,    -1,   155,   156,   157,   158,    -1,    -1,   161,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    -1,    40,    41,    -1,    43,
      -1,    -1,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,
      54,    55,    -1,    57,    58,    -1,    60,    61,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    -1,    71,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    -1,    92,    -1,
      -1,    95,    -1,    -1,    -1,    99,    -1,    -1,   102,    -1,
     104,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
      -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   148,    -1,    -1,   151,   152,    -1,
      -1,    -1,    -1,   157,    -1,   159,    -1,   161,    -1,   163,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      -1,    -1,    15,    16,    -1,    -1,    19,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,    -1,
      43,    -1,    -1,    46,    -1,    -1,    -1,    50,    51,    -1,
      -1,    54,    55,    -1,    57,    58,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    69,    -1,    71,    -1,
      -1,    -1,    -1,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    87,    88,    89,    90,    -1,    92,
      -1,    -1,    95,    -1,    -1,    98,    99,    -1,   101,   102,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,   148,    -1,    12,   151,   152,
      15,    16,    -1,    -1,   157,    -1,   159,    22,   161,    -1,
     163,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    -1,    40,    41,    -1,    43,    -1,
      -1,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,
      55,    -1,    57,    58,    -1,    60,    61,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    69,    -1,    71,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    87,    88,    89,    90,    -1,    92,    -1,    -1,
      95,    96,    97,    -1,    99,   100,    -1,   102,    -1,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,   138,   139,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   148,    -1,    -1,   151,   152,   153,    -1,
      -1,    -1,   157,    -1,   159,    -1,   161,    -1,   163,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    -1,    40,    41,    -1,    43,
      -1,    -1,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,
      54,    55,    -1,    57,    58,    -1,    60,    61,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    69,    -1,    71,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    -1,    92,    -1,
      -1,    95,    96,    97,    -1,    99,   100,    -1,   102,    -1,
      -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
      -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   148,    -1,    -1,   151,   152,   153,
      -1,    -1,    -1,   157,    -1,   159,    -1,   161,   162,   163,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,    -1,
      43,    -1,    -1,    46,    -1,    -1,    -1,    50,    51,    -1,
      -1,    54,    55,    -1,    57,    58,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    69,    -1,    71,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    87,    88,    89,    90,    -1,    92,
      -1,    -1,    95,    96,    97,    -1,    99,   100,    -1,   102,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   148,    -1,    -1,   151,   152,
     153,    -1,    -1,    -1,   157,    -1,   159,    -1,   161,   162,
     163,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      12,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,
      22,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,
      42,    43,    -1,    -1,    46,    -1,    -1,    -1,    50,    51,
      -1,    -1,    54,    55,    -1,    57,    58,    -1,    60,    61,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    69,    -1,    71,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    85,    86,    87,    88,    89,    90,    -1,
      92,    -1,    -1,    95,    -1,    -1,    -1,    99,    -1,    -1,
     102,    -1,   104,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,    -1,    -1,   151,
     152,    -1,    -1,    -1,    -1,   157,    -1,   159,    -1,   161,
      -1,   163,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    -1,    19,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,
      41,    -1,    43,    -1,    -1,    46,    -1,    -1,    -1,    50,
      51,    -1,    -1,    54,    55,    -1,    57,    58,    -1,    60,
      61,    -1,    -1,    -1,    -1,    -1,    67,    -1,    69,    -1,
      71,    -1,    -1,    -1,    -1,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
      -1,    92,    -1,    -1,    95,    -1,    -1,    98,    99,    -1,
     101,   102,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,   148,    -1,    12,
     151,   152,    15,    16,    -1,    -1,   157,    -1,   159,    22,
     161,    -1,   163,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,    -1,
      43,    -1,    -1,    46,    -1,    -1,    -1,    50,    51,    -1,
      -1,    54,    55,    -1,    57,    58,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    69,    -1,    71,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    87,    88,    89,    90,    -1,    92,
      -1,    -1,    95,    96,    97,    -1,    99,    -1,    -1,   102,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   148,    -1,    -1,   151,   152,
      -1,   154,    -1,    -1,   157,    -1,   159,    -1,   161,    -1,
     163,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      12,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,
      -1,    43,    -1,    -1,    46,    -1,    -1,    -1,    50,    51,
      -1,    -1,    54,    55,    -1,    57,    58,    -1,    60,    61,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    69,    -1,    71,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    87,    88,    89,    90,    -1,
      92,    -1,    -1,    95,    96,    97,    -1,    99,    -1,    -1,
     102,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,    -1,    -1,   151,
     152,   153,    -1,    -1,    -1,   157,    -1,   159,    -1,   161,
      -1,   163,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,
      41,    -1,    43,    -1,    -1,    46,    -1,    -1,    -1,    50,
      51,    -1,    -1,    54,    55,    -1,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    67,    -1,    69,    -1,
      71,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
      -1,    92,    -1,    -1,    95,    96,    97,    -1,    99,    -1,
      -1,   102,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,   148,    -1,    12,
     151,   152,    15,    16,    -1,    -1,   157,    -1,   159,    22,
     161,    -1,   163,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,    -1,
      43,    -1,    -1,    46,    -1,    -1,    -1,    50,    51,    -1,
      -1,    54,    55,    -1,    57,    58,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    -1,    71,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    87,    88,    89,    90,    -1,    92,
      -1,    -1,    95,    -1,    -1,    -1,    99,    -1,    -1,   102,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,   111,    -1,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,   148,    -1,    12,   151,   152,
      15,    16,    -1,    -1,   157,    -1,   159,    22,   161,    -1,
     163,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    -1,    40,    41,    -1,    43,    -1,
      -1,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,
      55,    -1,    57,    58,    -1,    60,    61,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    69,    -1,    71,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    87,    88,    89,    90,    -1,    92,    -1,    -1,
      95,    -1,    -1,    -1,    99,    -1,    -1,   102,    -1,    -1,
     105,    -1,    -1,    -1,    -1,    -1,   111,    -1,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   148,    -1,    -1,   151,   152,   153,    -1,
      -1,    -1,   157,    -1,   159,    -1,   161,    -1,   163,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    -1,    40,    41,    -1,    43,
      -1,    -1,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,
      54,    55,    -1,    57,    58,    -1,    60,    61,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    69,    -1,    71,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    -1,    92,    -1,
      -1,    95,    96,    97,    -1,    99,    -1,    -1,   102,    -1,
      -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
      -1,    -1,    -1,    -1,   138,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,   148,    -1,    12,   151,   152,    15,
      16,    -1,    -1,   157,    -1,   159,    22,   161,    -1,   163,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,
      46,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,    55,
      -1,    57,    58,    -1,    60,    61,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    69,    -1,    71,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      86,    87,    88,    89,    90,    -1,    92,    -1,    -1,    95,
      -1,    -1,    -1,    99,    -1,    -1,   102,    -1,    -1,   105,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,   131,   132,   133,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   148,    -1,    -1,   151,   152,   153,    -1,    -1,
      -1,   157,    -1,   159,   160,   161,    -1,   163,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,
      15,    16,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    -1,    40,    41,    -1,    43,    -1,
      -1,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,
      55,    -1,    57,    58,    -1,    60,    61,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    69,    -1,    71,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    87,    88,    89,    90,    -1,    92,    -1,    -1,
      95,    -1,    -1,    -1,    99,    -1,    -1,   102,    -1,    -1,
     105,    -1,    -1,    -1,    -1,    -1,   111,    -1,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,   138,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,   148,    -1,    12,   151,   152,    15,    16,
      -1,    -1,   157,    -1,   159,    22,   161,    -1,   163,    -1,
      -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,    46,
      -1,    -1,    -1,    50,    51,    -1,    -1,    54,    55,    -1,
      57,    58,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    69,    -1,    71,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,    -1,    92,    -1,    -1,    95,    -1,
      -1,    -1,    99,    -1,    -1,   102,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,   138,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,   148,    -1,    12,   151,   152,    15,    16,    -1,    -1,
     157,    -1,   159,    22,   161,    -1,   163,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      -1,    40,    41,    -1,    43,    -1,    -1,    46,    -1,    -1,
      -1,    50,    51,    -1,    -1,    54,    55,    -1,    57,    58,
      -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      69,    -1,    71,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,    -1,    92,    -1,    -1,    95,    -1,    -1,    -1,
      99,    -1,    -1,   102,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,
      -1,    -1,   151,   152,   153,    -1,    -1,    -1,   157,    -1,
     159,    -1,   161,    -1,   163,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    12,    -1,    -1,    15,    16,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    -1,    40,    41,    -1,    43,    -1,    -1,    46,    -1,
      -1,    -1,    50,    51,    -1,    -1,    54,    55,    -1,    57,
      58,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    69,    -1,    71,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,
      88,    89,    90,    -1,    92,    -1,    -1,    95,    -1,    -1,
      -1,    99,    -1,    -1,   102,    -1,    -1,   105,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,
     138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     148,    -1,    -1,   151,   152,   153,    -1,    -1,    -1,   157,
      -1,   159,    -1,   161,    -1,   163,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    -1,    -1,    15,    16,
      -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,    46,
      -1,    -1,    -1,    50,    51,    -1,    -1,    54,    55,    -1,
      57,    58,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    69,    -1,    71,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,    -1,    92,    -1,    -1,    95,    -1,
      -1,    -1,    99,    -1,    -1,   102,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   148,    -1,    -1,   151,   152,   153,    -1,    -1,    -1,
     157,    -1,   159,    -1,   161,    -1,   163,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,    15,
      16,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,
      46,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,    55,
      -1,    57,    58,    -1,    60,    61,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    69,    -1,    71,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      86,    87,    88,    89,    90,    -1,    92,    -1,    -1,    95,
      -1,    -1,    -1,    99,    -1,    -1,   102,    -1,    -1,   105,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,   131,   132,   133,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   148,    -1,    -1,   151,   152,   153,    -1,    -1,
      -1,   157,    -1,   159,    -1,   161,    -1,   163,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,
      15,    16,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    -1,    40,    41,    -1,    43,    -1,
      -1,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,
      55,    -1,    57,    58,    -1,    60,    61,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    69,    -1,    71,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    87,    88,    89,    90,    -1,    92,    -1,    -1,
      95,    -1,    -1,    -1,    99,    -1,    -1,   102,    -1,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   148,    -1,    -1,   151,   152,   153,    -1,
      -1,    -1,   157,    -1,   159,    -1,   161,    -1,   163,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    -1,    40,    41,    -1,    43,
      -1,    -1,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,
      54,    55,    -1,    57,    58,    -1,    60,    61,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    69,    -1,    71,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    -1,    92,    -1,
      -1,    95,    -1,    -1,    -1,    99,    -1,    -1,   102,    -1,
      -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
      -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   148,    -1,    -1,   151,   152,   153,
      -1,    -1,    -1,   157,    -1,   159,    -1,   161,    -1,   163,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,    -1,
      43,    -1,    -1,    46,    -1,    -1,    -1,    50,    51,    -1,
      -1,    54,    55,    -1,    57,    58,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    69,    -1,    71,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    87,    88,    89,    90,    -1,    92,
      -1,    -1,    95,    -1,    -1,    -1,    99,    -1,    -1,   102,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,   148,    -1,    12,   151,   152,
      15,    16,    -1,    -1,   157,    -1,   159,    22,   161,    -1,
     163,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    -1,    40,    41,    -1,    43,    -1,
      -1,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,
      55,    -1,    57,    58,    -1,    60,    61,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    69,    -1,    71,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    87,    88,    89,    90,    -1,    92,    -1,    -1,
      95,    -1,    -1,    -1,    99,    -1,    -1,   102,    -1,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,   138,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,   148,    -1,    12,   151,   152,    15,    16,
      -1,    -1,   157,    -1,   159,    22,   161,    -1,   163,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,    46,
      -1,    -1,    -1,    50,    51,    -1,    -1,    54,    55,    -1,
      57,    58,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    69,    -1,    71,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,    -1,    92,    -1,    -1,    95,    -1,
      -1,    -1,    99,    -1,    -1,   102,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,   138,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,   148,    -1,    12,   151,   152,    15,    16,    -1,    -1,
     157,    -1,   159,    22,   161,    -1,   163,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      -1,    40,    41,    -1,    43,    -1,    -1,    46,    -1,    -1,
      -1,    50,    51,    -1,    -1,    54,    55,    -1,    57,    58,
      -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      69,    -1,    71,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,    -1,    92,    -1,    -1,    95,    -1,    -1,    -1,
      99,    -1,    -1,   102,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,   148,
      -1,    12,   151,   152,    15,    16,    -1,    -1,   157,    -1,
     159,    22,   161,    -1,   163,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,
      41,    -1,    43,    -1,    -1,    46,    -1,    -1,    -1,    50,
      51,    -1,    -1,    54,    55,    -1,    57,    58,    -1,    60,
      61,    -1,    -1,    -1,    -1,    -1,    67,    -1,    69,    -1,
      71,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
      -1,    92,    -1,    -1,    95,    -1,    -1,    -1,    99,    -1,
      -1,   102,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,   148,    -1,    12,
     151,   152,    15,    16,    -1,    -1,   157,    -1,   159,    22,
     161,    -1,   163,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,    -1,
      43,    -1,    -1,    46,    -1,    -1,    -1,    50,    51,    -1,
      -1,    54,    55,    -1,    57,    58,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    69,    -1,    71,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    87,    88,    89,    90,    -1,    92,
      -1,    -1,    95,    -1,    -1,    -1,    99,    -1,    -1,   102,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,   148,    -1,    12,   151,   152,
      15,    16,    -1,    -1,   157,    -1,   159,    22,   161,    -1,
     163,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    -1,    40,    41,    -1,    43,    -1,
      -1,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,
      55,    -1,    57,    58,    -1,    60,    61,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    69,    -1,    71,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    87,    88,    89,    90,    -1,    92,    -1,    -1,
      95,    -1,    -1,    -1,    99,    -1,    -1,   102,    -1,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,   138,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,   148,    -1,    12,   151,   152,    15,    16,
      -1,    -1,   157,    -1,   159,    22,   161,    -1,   163,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,    46,
      -1,    -1,    -1,    50,    51,    -1,    -1,    54,    55,    -1,
      57,    58,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    69,    -1,    71,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,    -1,    92,    -1,    -1,    95,    -1,
      -1,    -1,    99,    -1,    -1,   102,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,   138,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,   148,    -1,    12,   151,   152,    15,    16,    -1,    -1,
     157,    -1,   159,    22,   161,    -1,   163,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      -1,    40,    41,    -1,    43,    -1,    -1,    46,    -1,    -1,
      -1,    50,    51,    -1,    -1,    54,    55,    -1,    57,    58,
      -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      69,    -1,    71,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,    -1,    92,    -1,    -1,    95,    -1,    -1,    -1,
      99,    -1,    -1,   102,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,   148,
      -1,    12,   151,   152,    15,    16,    -1,    -1,   157,    -1,
     159,    22,   161,    -1,   163,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,
      41,    -1,    43,    -1,    -1,    46,    -1,    -1,    -1,    50,
      51,    -1,    -1,    54,    55,    -1,    57,    58,    -1,    60,
      61,    -1,    -1,    -1,    -1,    -1,    67,    -1,    69,    -1,
      71,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
      -1,    92,    -1,    -1,    95,    -1,    -1,    -1,    99,    -1,
      -1,   102,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,   148,    -1,    12,
     151,   152,    15,    16,    -1,    -1,   157,    -1,   159,    22,
     161,    -1,   163,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,    -1,
      43,    -1,    -1,    46,    -1,    -1,    -1,    50,    51,    -1,
      -1,    54,    55,    -1,    57,    58,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    69,    -1,    71,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    87,    88,    89,    90,    -1,    92,
      -1,    -1,    95,    -1,    -1,    -1,    99,    -1,    -1,   102,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,   148,    -1,    12,   151,   152,
      15,    16,    -1,    -1,   157,    -1,   159,    22,   161,    -1,
     163,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    -1,    40,    41,    -1,    43,    -1,
      -1,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,
      55,    -1,    57,    58,    -1,    60,    61,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    69,    -1,    71,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    87,    88,    89,    90,    -1,    92,    -1,    -1,
      95,    -1,    -1,    -1,    99,    -1,    -1,   102,    -1,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,   138,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,   148,    -1,    12,   151,   152,    15,    16,
      -1,    -1,   157,    -1,   159,    22,   161,    -1,   163,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    -1,    40,    41,    -1,    43,    -1,    -1,    46,
      -1,    -1,    -1,    50,    51,    -1,    -1,    54,    55,    -1,
      57,    58,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    69,    -1,    71,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,    -1,    92,    -1,    -1,    95,    -1,
      -1,    -1,    99,    -1,    -1,   102,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,   138,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,   148,    -1,    12,   151,   152,    15,    16,    -1,    -1,
     157,    -1,   159,    22,   161,    -1,   163,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      -1,    40,    41,    -1,    43,    -1,    -1,    46,    -1,    -1,
      -1,    50,    51,    -1,    -1,    54,    55,    -1,    57,    58,
      -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      69,    -1,    71,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,    -1,    92,    -1,    -1,    95,    -1,    -1,    -1,
      99,    -1,    -1,   102,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,   148,
      -1,    12,   151,   152,    15,    16,    -1,    -1,   157,    -1,
     159,    22,   161,    -1,   163,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,
      41,    -1,    43,    -1,    -1,    46,    -1,    -1,    -1,    50,
      51,    -1,    -1,    54,    55,    -1,    57,    58,    -1,    60,
      61,    -1,    -1,    -1,    -1,    -1,    67,    -1,    69,    -1,
      71,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
      -1,    92,    -1,    -1,    95,    -1,    -1,    -1,    99,    -1,
      -1,   102,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,   148,    -1,    12,
     151,   152,    15,    16,    -1,    -1,   157,    -1,    -1,    22,
     161,    -1,   163,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,    -1,
      43,    -1,    -1,    46,    -1,    -1,    -1,    50,    51,    -1,
      -1,    54,    55,    -1,    57,    58,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    69,    -1,    71,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    87,    88,    89,    90,    -1,    92,
      -1,    -1,    95,    -1,    -1,    -1,    99,    -1,    -1,   102,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,    -1,   129,   130,   131,   132,
     133,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    -1,   148,    15,    16,    -1,   152,
      -1,    -1,   158,    22,   157,   161,   159,   163,   161,    -1,
     163,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      -1,    40,    41,    -1,    43,    -1,    -1,    46,    -1,    -1,
      -1,    50,    51,    52,    -1,    54,    55,    -1,    57,    58,
      -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      69,    -1,    71,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,    -1,    92,    -1,    94,    95,    -1,    -1,    -1,
      99,    -1,    -1,   102,    -1,    -1,   105,    -1,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   131,    -1,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    -1,    -1,    15,    16,    -1,    -1,
      -1,    -1,    -1,    22,    -1,   154,    -1,    -1,    -1,    -1,
     159,    30,   161,    -1,   163,    -1,    -1,    36,    37,    38,
      -1,    40,    41,    -1,    43,    -1,    -1,    46,    -1,    -1,
      -1,    50,    51,    -1,    -1,    54,    55,    -1,    57,    58,
      -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      69,    -1,    71,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,    -1,    92,    -1,    -1,    95,    -1,    -1,    -1,
      99,    -1,    -1,   102,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,
      15,    16,   131,    -1,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    -1,    40,    41,    -1,    43,    -1,
     159,    46,   161,    -1,   163,    50,    51,    -1,    -1,    54,
      55,    -1,    57,    58,    -1,    60,    61,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    69,    -1,    71,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    87,    88,    89,    90,    -1,    92,    -1,    -1,
      95,    -1,    -1,    -1,    99,    -1,    -1,   102,    -1,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,   131,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,
      41,    -1,    43,    -1,   159,    46,   161,    -1,   163,    50,
      51,    -1,    -1,    54,    55,    -1,    57,    58,    -1,    60,
      61,    -1,    -1,    -1,    -1,    -1,    67,    -1,    69,    -1,
      71,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    85,    86,    87,    88,    89,    90,
      10,    92,    -1,    -1,    95,    15,    16,    17,    99,    -1,
      -1,   102,    22,    -1,   105,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,
      -1,    41,    -1,    43,    -1,    -1,    46,    -1,    48,    -1,
     131,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,
      60,    61,    -1,    -1,    -1,    -1,    10,    67,    -1,    -1,
      -1,    -1,    -1,    17,    -1,    -1,    76,    -1,    -1,    -1,
     161,    -1,   163,    -1,    28,    85,    86,    -1,    88,    -1,
      90,    -1,    92,    -1,    -1,    95,    -1,    -1,    -1,    99,
      -1,    -1,   102,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,   115,   116,   117,   118,   119,
      -1,    -1,   122,   123,   124,   125,    -1,   127,   128,   129,
     130,   131,   132,   133,    78,    -1,   136,    -1,    82,    -1,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,    -1,   152,    10,    -1,   155,   156,   157,   158,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
      -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,    -1,   132,   133,
     134,    -1,   136,   137,   138,    -1,   140,   141,   142,   143,
     144,    -1,   146,   147,   148,   149,   150,   151,   152,    -1,
      10,   155,   156,   157,    -1,    -1,    -1,    17,    -1,    -1,
     164,    78,    -1,    -1,    -1,    82,    -1,    -1,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    -1,   113,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      -1,    -1,   129,   130,    -1,   132,   133,   134,    78,   136,
     137,   138,    82,   140,   141,   142,   143,   144,    -1,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,   155,   156,
     157,    -1,    -1,    10,    -1,    -1,    -1,   164,    -1,    -1,
      17,    -1,    -1,   113,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    28,    82,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,    -1,   132,   133,   134,    -1,   136,   137,   138,    -1,
     140,   141,   142,   143,   144,    -1,   146,   147,   148,   149,
     150,   151,   152,   113,    -1,   155,   156,   157,    -1,    -1,
      -1,    -1,    -1,    -1,   164,    -1,    -1,    -1,    -1,   129,
     130,    78,   132,   133,   134,    82,   136,   137,   138,    -1,
     140,   141,   142,   143,   144,    -1,   146,   147,   148,   149,
     150,   151,   152,    10,    -1,   155,   156,   157,    -1,    -1,
      17,    -1,   162,    -1,    -1,    -1,   113,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,   130,    -1,   132,   133,   134,    -1,   136,
     137,   138,    -1,   140,   141,   142,   143,   144,    -1,   146,
     147,   148,   149,   150,   151,   152,    -1,    -1,   155,   156,
     157,    -1,    -1,    -1,    -1,   162,    -1,    -1,    -1,    -1,
      -1,    78,    -1,    -1,    -1,    82,    -1,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    91,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,   115,   116,
     117,   118,   119,    -1,    -1,   122,   123,   124,   125,    -1,
     127,   128,   129,   130,    -1,   132,   133,   134,    -1,   136,
     137,   138,    -1,   140,   141,   142,   143,   144,    -1,   146,
     147,   148,   149,   150,   151,   152,    -1,    78,   155,   156,
     157,    82,   159,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      91,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,   114,   115,   116,   117,   118,   119,    -1,
      -1,   122,   123,   124,   125,    -1,   127,   128,   129,   130,
      -1,   132,   133,   134,    -1,   136,   137,   138,    -1,   140,
     141,   142,   143,   144,    -1,   146,   147,   148,   149,   150,
     151,   152,    -1,    78,   155,   156,   157,    82,   159,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    91,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,
     115,   116,   117,   118,   119,    -1,    -1,   122,   123,   124,
     125,    -1,   127,   128,   129,   130,    -1,   132,   133,   134,
      -1,   136,   137,   138,    -1,   140,   141,   142,   143,   144,
      -1,   146,   147,   148,   149,   150,   151,   152,    -1,    78,
     155,   156,   157,    82,   159,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    91,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,   114,   115,   116,   117,   118,
     119,    -1,    -1,   122,   123,   124,   125,    -1,   127,   128,
     129,   130,    -1,   132,   133,   134,    -1,   136,   137,   138,
      -1,   140,   141,   142,   143,   144,    -1,   146,   147,   148,
     149,   150,   151,   152,    -1,    78,   155,   156,   157,    82,
     159,    -1,    -1,    10,    -1,    -1,    -1,    -1,    91,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,   114,   115,   116,   117,   118,   119,    -1,    -1,   122,
     123,   124,   125,    -1,   127,   128,   129,   130,    -1,   132,
     133,   134,    -1,   136,   137,   138,    -1,   140,   141,   142,
     143,   144,    -1,   146,   147,   148,   149,   150,   151,   152,
      -1,    78,   155,   156,   157,    82,   159,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    91,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,   115,   116,
     117,   118,   119,    -1,    -1,   122,   123,   124,   125,    -1,
     127,   128,   129,   130,    -1,   132,   133,   134,    -1,   136,
     137,   138,    -1,   140,   141,   142,   143,   144,    -1,   146,
     147,   148,   149,   150,   151,   152,    -1,    78,   155,   156,
     157,    82,   159,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      91,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,   114,   115,   116,   117,   118,   119,    -1,
      -1,   122,   123,   124,   125,    -1,   127,   128,   129,   130,
      -1,   132,   133,   134,    -1,   136,   137,   138,    -1,   140,
     141,   142,   143,   144,    -1,   146,   147,   148,   149,   150,
     151,   152,    -1,    78,   155,   156,   157,    82,   159,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    91,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,
     115,   116,   117,   118,   119,    -1,    -1,   122,   123,   124,
     125,    -1,   127,   128,   129,   130,    -1,   132,   133,   134,
      -1,   136,   137,   138,    -1,   140,   141,   142,   143,   144,
      -1,   146,   147,   148,   149,   150,   151,   152,    -1,    78,
     155,   156,   157,    82,   159,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,   114,   115,   116,   117,   118,
     119,    -1,    -1,   122,   123,   124,   125,    -1,   127,   128,
     129,   130,    -1,   132,   133,   134,    -1,   136,   137,   138,
      -1,   140,   141,   142,   143,   144,    -1,   146,   147,   148,
     149,   150,   151,   152,    10,    -1,   155,   156,   157,    -1,
     159,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    -1,    -1,    -1,    82,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      -1,    -1,    -1,   109,    -1,    -1,    -1,   113,    28,    29,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    82,    -1,    -1,
      -1,    -1,    -1,   129,   130,    -1,   132,   133,   134,    -1,
     136,   137,   138,    -1,   140,   141,   142,   143,   144,    -1,
     146,   147,   148,   149,   150,   151,   152,    -1,   113,   155,
     156,   157,    -1,   159,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    28,    82,    -1,   129,   130,    -1,   132,   133,   134,
      -1,   136,   137,   138,    -1,   140,   141,   142,   143,   144,
      -1,   146,   147,   148,   149,   150,   151,   152,    10,   109,
     155,   156,   157,   113,   159,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,   129,
     130,    78,   132,   133,   134,    82,   136,   137,   138,    -1,
     140,   141,   142,   143,   144,    -1,   146,   147,   148,   149,
     150,   151,   152,    10,    -1,   155,   156,   157,    -1,   159,
      17,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,
      -1,    28,    29,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      82,    -1,   129,   130,    -1,   132,   133,   134,    -1,   136,
     137,   138,    -1,   140,   141,   142,   143,    -1,    -1,   146,
     147,   148,   149,   150,    -1,   152,    -1,    -1,   155,   156,
     157,   113,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    78,    -1,    -1,    -1,    82,    -1,   129,   130,    -1,
     132,   133,   134,    -1,   136,   137,   138,    -1,   140,   141,
     142,   143,   144,    -1,   146,   147,   148,   149,   150,   151,
     152,    10,    -1,   155,   156,   157,   113,   159,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    28,
      82,    -1,   129,   130,    -1,   132,   133,   134,    -1,   136,
     137,   138,    -1,   140,   141,   142,   143,   144,    -1,   146,
     147,   148,   149,   150,   151,   152,    10,    -1,   155,   156,
     157,    -1,   159,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    -1,   129,   130,    78,
     132,   133,   134,    82,   136,   137,   138,    -1,   140,   141,
     142,   143,    91,    -1,   146,   147,   148,   149,   150,    -1,
     152,    -1,    -1,   155,   156,   157,    -1,    -1,    -1,    10,
      -1,    -1,    -1,    -1,   113,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    -1,    -1,    28,    82,    -1,
     129,   130,    33,   132,   133,   134,    -1,   136,   137,   138,
      -1,   140,   141,   142,   143,   144,    -1,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,   155,   156,   157,   113,
     159,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,    78,   132,   133,
     134,    82,   136,   137,   138,    -1,   140,   141,   142,   143,
     144,    -1,   146,   147,   148,   149,   150,   151,   152,    -1,
      -1,   155,   156,   157,    -1,   159,    10,    -1,    -1,    -1,
      -1,    -1,   113,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,   129,   130,
      -1,   132,   133,   134,    -1,   136,   137,   138,    42,   140,
     141,   142,   143,   144,    -1,   146,   147,   148,   149,   150,
     151,   152,    10,   154,   155,   156,   157,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    -1,    78,    -1,    -1,    -1,    82,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    -1,    -1,    82,   129,   130,    -1,   132,   133,
     134,    -1,   136,   137,   138,    -1,   140,   141,   142,   143,
     144,    -1,   146,   147,   148,   149,   150,   151,   152,    10,
      -1,   155,   156,   157,    -1,   113,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
      -1,   129,   130,    -1,   132,   133,   134,    -1,   136,   137,
     138,    42,   140,   141,   142,   143,   144,    -1,   146,   147,
     148,   149,   150,   151,   152,    10,    -1,   155,   156,   157,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    78,    33,    -1,
      -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,   113,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    82,   129,   130,
      -1,   132,   133,   134,    -1,   136,   137,   138,    -1,   140,
     141,   142,   143,   144,    -1,   146,   147,   148,   149,   150,
     151,   152,    10,    -1,   155,   156,   157,    -1,   113,    17,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    82,    -1,    -1,
      28,    -1,    -1,    -1,   129,   130,    -1,   132,   133,   134,
      -1,   136,   137,   138,    -1,   140,   141,   142,   143,   144,
      -1,   146,   147,   148,   149,   150,   151,   152,   113,    -1,
     155,   156,   157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,   130,    -1,   132,   133,   134,
      78,   136,   137,   138,    82,   140,   141,   142,   143,   144,
      -1,   146,   147,   148,   149,   150,   151,   152,    10,   154,
     155,   156,   157,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   130,    -1,   132,   133,   134,    -1,   136,   137,
     138,    -1,   140,   141,   142,   143,   144,    -1,   146,   147,
     148,   149,   150,   151,   152,    10,   154,   155,   156,   157,
      -1,    -1,    17,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      82,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,   113,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    -1,   129,   130,    -1,
     132,   133,   134,    78,   136,   137,   138,    82,   140,   141,
     142,   143,   144,    -1,   146,   147,   148,   149,   150,   151,
     152,    10,   154,   155,   156,   157,    -1,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    28,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    -1,   129,   130,    91,   132,   133,   134,
      -1,   136,   137,   138,    -1,   140,   141,   142,   143,   144,
      -1,   146,   147,   148,   149,   150,   151,   152,   113,   154,
     155,   156,   157,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      -1,    -1,    -1,    82,   129,   130,    -1,   132,   133,   134,
      -1,   136,   137,   138,    -1,   140,   141,   142,   143,   144,
      -1,   146,   147,   148,   149,   150,   151,   152,    10,    -1,
     155,   156,   157,   112,   113,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,
     129,   130,    -1,   132,   133,   134,    -1,   136,   137,   138,
      -1,   140,   141,   142,   143,   144,    -1,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,   155,   156,   157,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    28,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,    78,
     132,   133,   134,    82,   136,   137,   138,    -1,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,    -1,    -1,   155,   156,   157,    -1,    -1,    10,    11,
     109,    -1,    -1,    -1,   113,    17,    -1,    -1,    -1,    78,
      -1,    -1,    -1,    82,    -1,    -1,    28,    -1,    -1,    -1,
     129,   130,    -1,   132,   133,   134,    -1,   136,   137,   138,
      -1,   140,   141,   142,   143,   144,    -1,   146,   147,   148,
     149,   150,   151,   152,   113,    -1,   155,   156,   157,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,    -1,   132,   133,   134,    78,   136,   137,   138,
      82,   140,   141,   142,   143,   144,    -1,   146,   147,   148,
     149,   150,   151,   152,    10,   154,   155,   156,   157,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,    28,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,    -1,
     132,   133,   134,    -1,   136,   137,   138,    -1,   140,   141,
     142,   143,   144,    -1,   146,   147,   148,   149,   150,   151,
     152,    10,    -1,   155,   156,   157,    -1,    -1,    17,    -1,
      -1,    -1,    78,    -1,    -1,    -1,    82,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,
      -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,    -1,   132,   133,   134,    78,
     136,   137,   138,    82,   140,   141,   142,   143,   144,    -1,
     146,   147,   148,   149,   150,   151,   152,    -1,    -1,   155,
     156,   157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    -1,   112,   113,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,    -1,   132,   133,   134,    -1,   136,   137,   138,
      -1,   140,   141,   142,   143,   144,   113,   146,   147,   148,
     149,   150,   151,   152,    10,    -1,   155,   156,   157,    -1,
      -1,    17,   129,   130,    -1,   132,   133,   134,    -1,   136,
     137,   138,    28,   140,   141,   142,   143,   144,    -1,   146,
     147,   148,   149,   150,   151,   152,    10,    -1,   155,   156,
     157,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    -1,    -1,    -1,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    -1,    -1,   113,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,    -1,   132,   133,   134,    -1,
     136,   137,   138,    -1,   140,   141,   142,   143,   144,   113,
     146,   147,   148,   149,   150,   151,   152,    10,    -1,   155,
     156,   157,    -1,    -1,    17,   129,   130,    -1,   132,   133,
     134,    -1,   136,   137,   138,    28,   140,   141,   142,   143,
     144,    -1,   146,   147,   148,   149,   150,   151,   152,    10,
      11,   155,   156,   157,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,
     113,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,    -1,   132,
     133,   134,    -1,   136,   137,   138,    -1,   140,   141,   142,
     143,   144,   113,   146,   147,   148,   149,   150,   151,   152,
      10,    -1,   155,   156,   157,    -1,    -1,    17,   129,   130,
      -1,   132,   133,   134,    -1,   136,   137,   138,    28,   140,
     141,   142,   143,   144,    -1,   146,   147,   148,   149,   150,
     151,   152,    10,    -1,   155,   156,   157,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    -1,   113,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,   129,
     130,    -1,   132,   133,   134,    -1,   136,   137,   138,    -1,
     140,   141,   142,   143,   144,   113,   146,   147,   148,   149,
     150,   151,   152,    10,    -1,   155,   156,   157,    -1,    -1,
      17,   129,   130,    -1,   132,   133,   134,    -1,   136,   137,
     138,    28,   140,   141,   142,   143,   144,    -1,   146,   147,
     148,   149,   150,   151,   152,    10,    -1,   155,   156,   157,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    -1,    -1,   113,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,
      -1,    -1,   129,   130,    -1,   132,   133,   134,    -1,   136,
     137,   138,    -1,   140,   141,   142,   143,   144,   113,   146,
     147,   148,   149,   150,   151,   152,    10,    -1,   155,   156,
     157,    -1,    -1,    17,   129,   130,    -1,   132,   133,   134,
      -1,   136,   137,   138,    28,   140,   141,   142,   143,   144,
      -1,   146,   147,   148,   149,   150,   151,   152,    10,    -1,
     155,   156,   157,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,   113,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    -1,    -1,    -1,   129,   130,    -1,   132,   133,
     134,    -1,   136,   137,   138,    -1,   140,   141,   142,   143,
     144,   113,   146,   147,   148,   149,   150,   151,   152,    10,
      -1,   155,   156,   157,    -1,    -1,    17,   129,   130,    -1,
     132,   133,   134,    -1,   136,   137,   138,    28,   140,   141,
     142,   143,   144,    -1,   146,   147,   148,   149,   150,   151,
     152,    10,    -1,   155,   156,   157,    -1,    -1,    17,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,
      -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    78,
      -1,    -1,   113,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,
      -1,   132,   133,   134,    -1,   136,   137,   138,    -1,   140,
     141,   142,   143,   144,   113,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,   155,   156,   157,    -1,    78,    -1,
     129,   130,    82,   132,   133,   134,    -1,   136,   137,   138,
      -1,   140,   141,   142,   143,   144,    -1,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,   155,   156,   157,    -1,
      -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,    -1,   132,   133,   134,    -1,   136,   137,   138,    -1,
     140,   141,   142,   143,   144,    -1,   146,   147,   148,   149,
     150,   151,   152,    -1,    19,   155,   156,   157,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    34,
      35,     1,    -1,     3,    39,    -1,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    15,    16,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    66,    -1,    68,    -1,    70,    36,    72,    -1,    -1,
      75,    41,    77,    43,    79,    -1,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,
      60,    61,    -1,    98,    -1,    -1,   101,    67,    -1,   104,
       3,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    15,    16,    -1,    85,    86,    -1,    88,    22,
      90,    -1,    92,    -1,    -1,    95,    -1,    30,    -1,    99,
      -1,    -1,   102,    36,    -1,   105,    -1,    -1,    41,    -1,
      43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,   154,
      -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    -1,    88,    -1,    90,    -1,    92,
      -1,    -1,    95,    -1,    -1,    -1,    99,    -1,    -1,   102,
      -1,    -1,   105
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   169,   170,     0,     1,     3,     4,     5,     6,     7,
       8,    12,    13,    14,    15,    16,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    29,    30,    32,    34,    35,
      36,    37,    38,    39,    40,    41,    43,    44,    46,    49,
      50,    51,    53,    54,    55,    57,    58,    60,    61,    62,
      66,    67,    68,    69,    70,    71,    72,    75,    76,    77,
      79,    80,    81,    83,    84,    85,    86,    87,    88,    89,
      90,    92,    93,    95,    96,    97,    98,    99,   101,   102,
     104,   105,   108,   110,   113,   129,   130,   131,   132,   133,
     138,   148,   151,   152,   154,   157,   159,   161,   163,   171,
     172,   173,   174,   175,   176,   178,   183,   184,   185,   186,
     190,   192,   196,   197,   198,   199,   200,   201,   203,   204,
     205,   209,   210,   213,   214,   217,   218,   221,   224,   225,
     251,   254,   255,   275,   276,   277,   278,   279,   280,   281,
     289,   290,   291,   292,   295,   296,   297,   298,   299,   300,
     301,   303,   304,   305,   306,   307,   154,   173,   292,   109,
     282,   283,     3,   187,    12,    37,    38,    40,    90,   159,
     163,   221,   275,   280,   290,   291,   292,   295,   297,   298,
     282,   292,    98,   254,    79,   187,   173,   269,   292,   173,
     161,   292,   293,     7,     9,    98,   194,   293,    68,   111,
     202,   292,   202,   292,    23,    35,   255,   292,   292,   161,
       3,    15,    16,    22,    30,    36,    41,    43,    46,    54,
      60,    61,    67,    76,    85,    86,    88,    90,    92,    95,
      99,   102,   105,   189,   191,   222,   161,   189,   256,   257,
      29,   178,   195,   292,   292,   292,   292,   292,   292,     7,
     161,    35,   198,   198,   153,   244,   268,   292,    96,    97,
     154,   292,   294,   292,   195,   292,   292,   292,    89,   161,
     173,   292,   292,   178,   186,   292,   295,   178,   186,   292,
     189,   252,   292,   292,   292,   292,   292,   292,   292,   292,
       1,   160,   171,   179,   268,   100,   139,   244,   270,   271,
     294,   202,   268,   292,   302,    70,   173,   159,    74,   177,
     103,   189,   189,    47,    73,   239,   256,   153,   154,   145,
      10,    17,    28,    78,    82,   113,   129,   130,   132,   133,
     134,   136,   137,   138,   140,   141,   142,   143,   144,   146,
     147,   148,   149,   150,   151,   152,   155,   156,   157,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   158,   231,   161,   163,    78,    82,
     161,   173,   154,   292,   292,   292,   268,   159,   178,    42,
     282,   252,   256,   154,   135,   154,   108,   190,   244,   272,
     273,   274,   294,   252,   214,   254,   189,   161,   195,    29,
      42,   195,   109,   195,   285,    29,    42,   195,   285,   293,
      33,    63,   154,    91,   178,   231,   272,   173,   161,   233,
     100,   161,   189,   258,   259,     1,   134,   263,    42,   135,
     173,   195,   195,   272,   189,   135,   154,   292,   292,   154,
     159,   195,   161,   272,   154,   206,   154,   206,   154,   114,
     253,   154,   195,   154,   160,   160,   171,   135,   160,   292,
     135,   162,   135,   162,   164,   285,    42,   135,   164,   285,
     112,   135,   164,     7,     1,   160,   179,    56,   268,   292,
     134,   215,   159,   226,   154,   292,   292,   292,   292,   202,
     292,   202,   292,   292,   292,   292,   292,   292,   292,    30,
      54,    98,   190,   292,   153,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   153,   292,   292,   292,   292,   292,
     292,   294,   294,   294,   294,   294,   272,   272,   202,   292,
     202,   292,    24,    42,    79,   104,   284,   287,   288,   292,
     307,    29,    42,    29,    42,    91,    42,   164,   202,   292,
     195,   154,   154,   292,   292,   114,   162,   135,   154,   189,
     256,    42,   268,    40,   292,   202,   292,   161,   195,    40,
     292,   202,   292,   195,   157,   180,   182,   292,   180,   181,
     173,   292,    31,   292,   162,    24,    42,    45,    65,    68,
      79,    98,   172,   234,   235,   236,   237,   223,   259,   135,
     162,    30,    43,    86,    90,   163,   193,   264,   276,   114,
     260,   292,   257,   162,   244,   292,     1,   211,   272,   162,
      18,   207,   264,   276,   135,   160,   162,   162,   270,   162,
     270,   173,   164,   202,   292,   164,   173,   292,   164,   292,
     164,   292,   160,   160,   189,   154,    33,    63,   268,   159,
       1,   189,   219,   220,    24,    68,    79,    98,   228,   238,
     154,   154,   154,   154,   154,   162,   164,    42,    79,   135,
     162,   275,    78,    78,    40,   202,   292,    40,   202,   292,
     202,   292,   282,   282,   154,   244,   294,   274,   215,   154,
     292,   162,   292,    29,   195,    29,   195,   286,   287,   292,
      29,   195,   285,    29,   195,   285,   135,   154,    11,   154,
      31,    31,   173,    91,   178,    42,    79,   236,   135,   162,
     161,   189,    24,    68,    79,    98,   240,   162,   259,   263,
       1,   268,    59,   294,   160,    64,   106,   160,   212,   162,
     161,   178,   189,   208,   252,   173,   164,   285,   164,   285,
     173,   112,   182,   181,     1,   216,   160,   114,   135,   160,
      79,   227,     1,     3,    10,    15,    17,    22,    36,    41,
      46,    48,    54,    60,    61,    76,    88,    92,    95,    99,
     105,   129,   130,   131,   132,   133,   136,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   152,   155,
     156,   157,   158,   161,   188,   189,   191,   229,   230,   231,
     275,   287,   263,   275,   275,   292,    29,    29,   292,    29,
      29,   164,   164,   195,   195,   159,   195,    91,    40,   292,
      40,   292,   135,   162,    91,    40,   292,   195,    40,   292,
     195,   292,   292,   173,   292,   173,    31,   189,   235,   259,
     134,   267,    79,   263,   260,   164,    42,   164,    29,   173,
     268,   208,   134,   178,    40,   173,   292,   164,    40,   173,
     292,   164,   292,   154,   154,   160,    35,    72,    75,   160,
     172,   197,   292,   220,   240,   161,   232,   189,   292,   129,
     137,   232,   232,   260,    91,    40,    40,    91,    40,    40,
      40,    40,     1,   216,   292,   292,   292,   287,   292,   292,
     292,    11,    31,   173,   267,   162,   163,   193,   244,   266,
     276,   139,   246,   260,    52,   107,   247,   292,   264,   276,
     173,   195,   162,   292,   292,   173,   292,   173,   197,     1,
     134,   262,   234,   162,     3,    92,   230,   231,   292,   292,
     292,   292,   292,   292,   160,   160,    91,    91,    91,    91,
     292,   173,   260,   267,   164,   268,   244,   245,   292,     3,
      81,    92,   248,   249,   250,   292,   178,   196,   243,   164,
     178,    91,    91,   163,   193,   261,   276,    94,   241,   162,
     232,   232,    91,    91,    91,    91,    91,    91,   292,   292,
     292,   292,   246,   260,   244,   265,   266,   276,    42,   164,
     250,   107,   135,   114,   140,   142,   143,   146,   147,    52,
     276,   292,   292,     1,   164,   268,   247,   292,   265,   266,
     292,   249,   250,   250,   250,   250,   250,   250,   248,   164,
     261,   276,   164,   154,   242,   243,   164,   261,   276,   265
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   168,   169,   170,   170,   171,   171,   172,   172,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   174,
     175,   175,   175,   176,   176,   176,   177,   177,   178,   178,
     178,   179,   179,   180,   180,   180,   180,   181,   181,   182,
     182,   183,   183,   183,   184,   184,   184,   185,   186,   186,
     186,   186,   186,   187,   187,   188,   188,   188,   188,   188,
     188,   189,   189,   189,   189,   189,   189,   190,   190,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   193,   193,   193,
     193,   194,   194,   195,   195,   196,   196,   197,   197,   197,
     197,   197,   197,   197,   197,   198,   198,   199,   199,   199,
     199,   200,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   202,   203,
     203,   203,   203,   203,   203,   203,   203,   204,   205,   205,
     205,   205,   205,   205,   206,   206,   207,   207,   207,   208,
     208,   209,   210,   210,   211,   211,   212,   212,   212,   213,
     213,   213,   213,   214,   214,   214,   215,   215,   216,   216,
     216,   217,   217,   218,   219,   219,   219,   220,   220,   222,
     223,   221,   224,   224,   224,   224,   224,   226,   227,   225,
     228,   228,   228,   228,   228,   229,   229,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   232,   232,   233,
     234,   234,   234,   235,   235,   235,   235,   235,   236,   236,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   238,
     238,   238,   238,   238,   238,   239,   239,   240,   240,   240,
     240,   240,   240,   241,   241,   242,   242,   243,   243,   244,
     244,   245,   245,   246,   246,   247,   247,   247,   247,   247,
     248,   248,   249,   249,   249,   249,   249,   249,   249,   250,
     250,   251,   251,   251,   252,   252,   253,   253,   253,   254,
     254,   254,   254,   254,   255,   255,   255,   256,   256,   257,
     257,   258,   258,   258,   259,   259,   259,   260,   260,   260,
     261,   261,   261,   261,   261,   261,   261,   262,   262,   262,
     262,   262,   263,   263,   263,   263,   263,   264,   264,   264,
     264,   265,   265,   265,   266,   266,   266,   266,   266,   267,
     267,   267,   267,   267,   268,   268,   268,   268,   269,   269,
     270,   270,   270,   271,   271,   272,   272,   273,   273,   274,
     274,   274,   274,   275,   275,   276,   276,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   279,   280,   281,   281,   281,   281,
     281,   281,   281,   281,   282,   282,   283,   284,   284,   285,
     286,   286,   287,   287,   287,   288,   288,   288,   288,   288,
     288,   289,   289,   290,   291,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   293,
     293,   294,   294,   294,   295,   295,   295,   295,   296,   296,
     296,   297,   297,   297,   298,   298,   298,   298,   299,   299,
     299,   299,   300,   300,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   302,   302,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   304,   304,   304,   304,   304,   304,
     304,   305,   305,   305,   305,   306,   306,   306,   306,   307,
     307,   307,   307,   307,   307,   307
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
       1,     0,     1,     2,     1,     2,     3,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     3,     5,     5,
       2,     2,     5,     3,     6,     6,     4,     5,     5,     3,
       3,     6,     5,     6,     5,     6,     3,     4,     3,     4,
       6,     7,     6,     7,     4,     5,     4,     5,     4,     4,
       3,     6,     5,     6,     5,     8,     7,     2,     3,     3,
       2,     2,     3,     3,     0,     2,     2,     3,     5,     1,
       3,     3,     5,     5,     0,     2,     3,     2,     3,     6,
       8,     6,     8,     1,     1,     1,     0,     2,     0,     2,
       3,     5,     5,     1,     1,     2,     3,     1,     3,     0,
       0,     8,     0,     1,     2,     2,     1,     0,     0,    10,
       3,     3,     5,     5,     3,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     3,     3,
       0,     1,     3,     4,     5,     4,     6,     6,     0,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     1,     0,
       1,     1,     2,     1,     1,     1,     1,     0,     1,     2,
       1,     1,     1,     0,     1,     1,     1,     1,     1,     2,
       1,     0,     1,     2,     2,     0,     2,     2,     4,     4,
       1,     3,     3,     3,     3,     3,     3,     3,     2,     1,
       1,     3,     4,     4,     2,     4,     0,     2,     2,     1,
       1,     1,     2,     1,     4,     5,     3,     1,     3,     3,
       5,     1,     1,     3,     1,     2,     3,     0,     2,     2,
       3,     2,     4,     3,     3,     4,     3,     0,     2,     2,
       2,     1,     0,     2,     2,     2,     1,     4,     4,     6,
       3,     0,     1,     1,     3,     4,     3,     4,     6,     0,
       2,     2,     2,     2,     1,     1,     3,     3,     1,     3,
       1,     1,     1,     3,     3,     0,     1,     1,     3,     3,
       3,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     5,     2,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     6,     6,     4,
       9,     9,     7,     6,     6,     4,     9,     9,     7,     4,
       6,     6,     9,     9,     6,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     0,     1,     4,     1,     3,     4,
       1,     3,     4,     3,     3,     1,     1,     2,     1,     2,
       1,     1,     3,     2,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     3,     3,     2,     2,     1,     0,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       1,     4,     4,     4,     3,     3,     3,     3,     3,     4,
       3,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     3,     4,     3,     4,     3,     5,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1
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
#line 5694 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 3:
#line 491 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = new BlockStmt(); resetTempID(); }
#line 5700 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 4:
#line 492 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-1].pblockstmt)->appendChapelStmt((yyvsp[0].pblockstmt)); context->generatedStmt = (yyvsp[-1].pblockstmt); resetTempID(); }
#line 5706 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 6:
#line 499 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildPragmaStmt( (yyvsp[-1].vpch), (yyvsp[0].pblockstmt) ); }
#line 5712 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 7:
#line 504 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.vpch) = new Vec<const char*>(); (yyval.vpch)->add(astr((yyvsp[0].pch))); }
#line 5718 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 8:
#line 505 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-2].vpch)->add(astr((yyvsp[0].pch))); }
#line 5724 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 23:
#line 524 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildChapelStmt((yyvsp[-1].pexpr)); }
#line 5730 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 24:
#line 525 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildAtomicStmt((yyvsp[0].pblockstmt)); }
#line 5736 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 25:
#line 526 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildBeginStmt((yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt)); }
#line 5742 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 26:
#line 527 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildGotoStmt(GOTO_BREAK, (yyvsp[-1].pch)); }
#line 5748 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 27:
#line 528 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildCobeginStmt((yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt));  }
#line 5754 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 28:
#line 529 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildGotoStmt(GOTO_CONTINUE, (yyvsp[-1].pch)); }
#line 5760 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 29:
#line 530 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildDeleteStmt((yyvsp[-1].pcallexpr)); }
#line 5766 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 30:
#line 531 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildLabelStmt((yyvsp[-1].pch), (yyvsp[0].pblockstmt)); }
#line 5772 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 31:
#line 532 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildLocalStmt((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 5778 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 32:
#line 533 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildLocalStmt((yyvsp[0].pblockstmt)); }
#line 5784 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 33:
#line 534 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildOnStmt((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 5790 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 34:
#line 535 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildSerialStmt((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 5796 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 35:
#line 536 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildSerialStmt(new SymExpr(gTrue), (yyvsp[0].pblockstmt)); }
#line 5802 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 36:
#line 537 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildSyncStmt((yyvsp[0].pblockstmt)); }
#line 5808 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 37:
#line 538 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_YIELD, (yyvsp[-1].pexpr)); }
#line 5814 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 38:
#line 539 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildErrorStandin(); }
#line 5820 "bison-chapel.cpp" /* yacc.c:1667  */
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
#line 5834 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 40:
#line 557 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-2].pmodsymbol)->block = new BlockStmt();
      (yyval.pblockstmt) = buildChapelStmt(new DefExpr((yyvsp[-2].pmodsymbol)));
      currentModuleName = (yylsp[-2]).prevModule;  // restore previous module name
    }
#line 5843 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 41:
#line 562 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-3].pmodsymbol)->block = (yyvsp[-1].pblockstmt);
      (yyval.pblockstmt) = buildChapelStmt(new DefExpr((yyvsp[-3].pmodsymbol)));
      currentModuleName = (yylsp[-3]).prevModule;  // restore previous module name
    }
#line 5852 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 42:
#line 567 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-3].pmodsymbol)->block = buildErrorStandin();
      (yyval.pblockstmt) = buildChapelStmt(new DefExpr((yyvsp[-3].pmodsymbol)));
      currentModuleName = (yylsp[-3]).prevModule;  // restore previous module name
    }
#line 5861 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 43:
#line 574 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.b) = false; (yyloc).comment = context->latestComment; context->latestComment = NULL; }
#line 5867 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 44:
#line 575 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.b) = false; (yyloc).comment = context->latestComment; context->latestComment = NULL; }
#line 5873 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 45:
#line 576 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.b) = true; (yyloc).comment = context->latestComment; context->latestComment = NULL; }
#line 5879 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 46:
#line 580 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.b) = false; }
#line 5885 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 47:
#line 581 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.b) = true;  }
#line 5891 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 48:
#line 594 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = new BlockStmt(); }
#line 5897 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 49:
#line 595 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = (yyvsp[-1].pblockstmt);              }
#line 5903 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 50:
#line 596 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildErrorStandin(); }
#line 5909 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 51:
#line 601 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = new BlockStmt(); (yyval.pblockstmt)->appendChapelStmt((yyvsp[0].pblockstmt)); }
#line 5915 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 52:
#line 602 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-1].pblockstmt)->appendChapelStmt((yyvsp[0].pblockstmt)); }
#line 5921 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 53:
#line 607 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.ponlylist) = new std::vector<OnlyRename*>();
                                         OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::SINGLE;
                                         cur->elem = (yyvsp[0].pexpr);
                                         (yyval.ponlylist)->push_back(cur); }
#line 5931 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 54:
#line 612 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.ponlylist) = new std::vector<OnlyRename*>();
                                         OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::DOUBLE;
                                         cur->renamed = new std::pair<Expr*, Expr*>((yyvsp[-2].pexpr), (yyvsp[0].pexpr));
                                         (yyval.ponlylist)->push_back(cur); }
#line 5941 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 55:
#line 617 "chapel.ypp" /* yacc.c:1667  */
    { OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::SINGLE;
                                         cur->elem = (yyvsp[0].pexpr);
                                         (yyvsp[-2].ponlylist)->push_back(cur); }
#line 5950 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 56:
#line 621 "chapel.ypp" /* yacc.c:1667  */
    { OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::DOUBLE;
                                         cur->renamed = new std::pair<Expr*, Expr*>((yyvsp[-2].pexpr), (yyvsp[0].pexpr));
                                         (yyvsp[-4].ponlylist)->push_back(cur); }
#line 5959 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 57:
#line 628 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.ponlylist) = new std::vector<OnlyRename*>();
                                         OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::SINGLE;
                                         cur->elem = new UnresolvedSymExpr("");
                                         (yyval.ponlylist)->push_back(cur); }
#line 5969 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 59:
#line 637 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.ponlylist) = new std::vector<OnlyRename*>();
                                         OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::SINGLE;
                                         cur->elem = new UnresolvedSymExpr("");
                                         (yyval.ponlylist)->push_back(cur); }
#line 5979 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 61:
#line 646 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.b) = false; }
#line 5985 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 62:
#line 647 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.b) = false; }
#line 5991 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 63:
#line 648 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.b) = true; }
#line 5997 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 64:
#line 652 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildUseStmt((yyvsp[-1].pcallexpr), (yyvsp[-3].b)); }
#line 6003 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 65:
#line 653 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildUseStmt((yyvsp[-3].pexpr), (yyvsp[-1].ponlylist), true, (yyvsp[-5].b)); }
#line 6009 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 66:
#line 654 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildUseStmt((yyvsp[-3].pexpr), (yyvsp[-1].ponlylist), false, (yyvsp[-5].b)); }
#line 6015 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 67:
#line 658 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildRequireStmt((yyvsp[-1].pcallexpr)); }
#line 6021 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 68:
#line 663 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), (yyvsp[-2].pch));   }
#line 6027 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 69:
#line 665 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), "<=>"); }
#line 6033 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 70:
#line 667 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), PRIM_REDUCE_ASSIGN); }
#line 6039 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 71:
#line 669 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildLAndAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr));    }
#line 6045 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 72:
#line 671 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildLOrAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr));     }
#line 6051 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 73:
#line 677 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = NULL; }
#line 6057 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 74:
#line 678 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 6063 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 75:
#line 682 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 6069 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 76:
#line 683 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "none"; redefiningReservedWordError((yyval.pch)); }
#line 6075 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 77:
#line 684 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "this"; }
#line 6081 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 78:
#line 685 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "false"; redefiningReservedWordError((yyval.pch)); }
#line 6087 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 79:
#line 686 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "true"; redefiningReservedWordError((yyval.pch)); }
#line 6093 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 80:
#line 687 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = (yyvsp[0].pch); redefiningReservedTypeError((yyvsp[0].pch)); }
#line 6099 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 81:
#line 690 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 6105 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 82:
#line 691 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "none"; redefiningReservedWordError((yyval.pch)); }
#line 6111 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 83:
#line 692 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "this"; redefiningReservedWordError((yyval.pch)); }
#line 6117 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 84:
#line 693 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "false"; redefiningReservedWordError((yyval.pch)); }
#line 6123 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 85:
#line 694 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "true"; redefiningReservedWordError((yyval.pch)); }
#line 6129 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 86:
#line 695 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = (yyvsp[0].pch); redefiningReservedTypeError((yyvsp[0].pch)); }
#line 6135 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 87:
#line 707 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 6141 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 88:
#line 708 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "this"; }
#line 6147 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 89:
#line 719 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "bool"; }
#line 6153 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 90:
#line 720 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "int"; }
#line 6159 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 91:
#line 721 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "uint"; }
#line 6165 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 92:
#line 722 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "real"; }
#line 6171 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 93:
#line 723 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "imag"; }
#line 6177 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 94:
#line 724 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "complex"; }
#line 6183 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 95:
#line 725 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "string"; }
#line 6189 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 96:
#line 726 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "sync"; }
#line 6195 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 97:
#line 727 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "single"; }
#line 6201 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 98:
#line 728 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "owned"; }
#line 6207 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 99:
#line 729 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "shared"; }
#line 6213 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 100:
#line 730 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "borrowed"; }
#line 6219 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 101:
#line 731 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "unmanaged"; }
#line 6225 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 102:
#line 732 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "domain"; }
#line 6231 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 103:
#line 733 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "index"; }
#line 6237 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 104:
#line 734 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "locale"; }
#line 6243 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 105:
#line 735 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "nothing"; }
#line 6249 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 106:
#line 736 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "void"; }
#line 6255 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 107:
#line 740 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtBools[BOOL_SIZE_DEFAULT]->symbol); }
#line 6261 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 108:
#line 741 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtInt[INT_SIZE_DEFAULT]->symbol); }
#line 6267 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 109:
#line 742 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtUInt[INT_SIZE_DEFAULT]->symbol); }
#line 6273 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 110:
#line 743 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtReal[FLOAT_SIZE_DEFAULT]->symbol); }
#line 6279 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 111:
#line 744 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtImag[FLOAT_SIZE_DEFAULT]->symbol); }
#line 6285 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 112:
#line 745 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtComplex[COMPLEX_SIZE_DEFAULT]->symbol); }
#line 6291 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 113:
#line 746 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtString->symbol); }
#line 6297 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 114:
#line 747 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtLocale->symbol); }
#line 6303 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 115:
#line 748 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtNothing->symbol); }
#line 6309 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 116:
#line 749 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(dtVoid->symbol); }
#line 6315 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 117:
#line 756 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "_syncvar"; }
#line 6321 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 118:
#line 757 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "_singlevar"; }
#line 6327 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 119:
#line 762 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "_domain"; }
#line 6333 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 120:
#line 763 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "_index"; }
#line 6339 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 121:
#line 768 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = NULL; }
#line 6345 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 122:
#line 769 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 6351 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 123:
#line 773 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = (yyvsp[0].pblockstmt); }
#line 6357 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 124:
#line 774 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = (yyvsp[0].pblockstmt); }
#line 6363 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 125:
#line 778 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_RETURN); }
#line 6369 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 126:
#line 779 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_RETURN, (yyvsp[-1].pexpr)); }
#line 6375 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 127:
#line 783 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildChapelStmt(new BlockStmt()); }
#line 6381 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 129:
#line 785 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = (yyvsp[0].pblockstmt); }
#line 6387 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 130:
#line 786 "chapel.ypp" /* yacc.c:1667  */
    { applyPrivateToBlock((yyvsp[0].pblockstmt)); (yyval.pblockstmt) = (yyvsp[0].pblockstmt); }
#line 6393 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 137:
#line 799 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildForwardingStmt((yyvsp[-1].pexpr)); }
#line 6399 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 138:
#line 800 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildForwardingStmt((yyvsp[-3].pexpr), (yyvsp[-1].ponlylist), true); }
#line 6405 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 139:
#line 801 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildForwardingStmt((yyvsp[-3].pexpr), (yyvsp[-1].ponlylist), false); }
#line 6411 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 140:
#line 802 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildForwardingDeclStmt((yyvsp[0].pblockstmt)); }
#line 6417 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 141:
#line 807 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = buildExternBlockStmt(astr((yyvsp[0].pch)));
    }
#line 6425 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 142:
#line 813 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = DoWhileStmt::build((yyvsp[-1].pexpr), (yyvsp[-3].pblockstmt)); }
#line 6431 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 143:
#line 814 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = WhileDoStmt::build((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 6437 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 144:
#line 815 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildCoforallLoopStmt((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt));       }
#line 6443 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 145:
#line 816 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildCoforallLoopStmt((yyvsp[-4].pexpr), (yyvsp[-2].pcallexpr), (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt), true); }
#line 6449 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 146:
#line 817 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildCoforallLoopStmt(NULL, (yyvsp[-2].pexpr), (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt));     }
#line 6455 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 147:
#line 818 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForLoop::buildForLoop(  (yyvsp[-3].pexpr), (yyvsp[-1].pexpr), (yyvsp[0].pblockstmt), false, false); }
#line 6461 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 148:
#line 819 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForLoop::buildForLoop(  (yyvsp[-3].pexpr), (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt), false,  true); }
#line 6467 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 149:
#line 820 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForLoop::buildForLoop(NULL, (yyvsp[-1].pexpr), (yyvsp[0].pblockstmt), false, false); }
#line 6473 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 150:
#line 821 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForLoop::buildForLoop(NULL, (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt), false,  true); }
#line 6479 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 151:
#line 822 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildParamForLoopStmt((yyvsp[-3].pch), (yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 6485 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 152:
#line 823 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForallStmt::build((yyvsp[-3].pexpr),   (yyvsp[-1].pexpr), NULL, (yyvsp[0].pblockstmt), false, false); }
#line 6491 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 153:
#line 824 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForallStmt::build((yyvsp[-4].pexpr),   (yyvsp[-2].pexpr), (yyvsp[-1].pcallexpr),   (yyvsp[0].pblockstmt), false, false); }
#line 6497 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 154:
#line 825 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForallStmt::build((yyvsp[-3].pexpr),   (yyvsp[-1].pcallexpr), NULL, (yyvsp[0].pblockstmt), true,  false); }
#line 6503 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 155:
#line 826 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForallStmt::build((yyvsp[-4].pexpr),   (yyvsp[-2].pcallexpr), (yyvsp[-1].pcallexpr),   (yyvsp[0].pblockstmt), true,  false); }
#line 6509 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 156:
#line 827 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-1].pexpr), NULL, (yyvsp[0].pblockstmt), false, false); }
#line 6515 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 157:
#line 828 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-2].pexpr), (yyvsp[-1].pcallexpr),   (yyvsp[0].pblockstmt), false, false); }
#line 6521 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 158:
#line 829 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-1].pcallexpr), NULL, (yyvsp[0].pblockstmt), true,  false); }
#line 6527 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 159:
#line 830 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-2].pcallexpr), (yyvsp[-1].pcallexpr),   (yyvsp[0].pblockstmt), true,  false); }
#line 6533 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 160:
#line 832 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pexpr), "invalid index expression");
      (yyval.pblockstmt) = ForallStmt::build((yyvsp[-4].pcallexpr)->get(1)->remove(), (yyvsp[-2].pexpr), NULL, new BlockStmt((yyvsp[0].pblockstmt)), false, true);
    }
#line 6543 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 161:
#line 838 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-5].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-3].pexpr), "invalid index expression");
      (yyval.pblockstmt) = ForallStmt::build((yyvsp[-5].pcallexpr)->get(1)->remove(), (yyvsp[-3].pexpr), (yyvsp[-2].pcallexpr),   new BlockStmt((yyvsp[0].pblockstmt)), false, true);
    }
#line 6553 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 162:
#line 844 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pcallexpr), "invalid index expression");
      (yyval.pblockstmt) = ForallStmt::build((yyvsp[-4].pcallexpr)->get(1)->remove(), (yyvsp[-2].pcallexpr), NULL, new BlockStmt((yyvsp[0].pblockstmt)), true,  true);
    }
#line 6563 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 163:
#line 850 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-5].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-3].pcallexpr), "invalid index expression");
      (yyval.pblockstmt) = ForallStmt::build((yyvsp[-5].pcallexpr)->get(1)->remove(), (yyvsp[-3].pcallexpr), (yyvsp[-2].pcallexpr),   new BlockStmt((yyvsp[0].pblockstmt)), true,  true);
    }
#line 6573 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 164:
#line 856 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-2].pcallexpr)->argList.length > 1)
        (yyval.pblockstmt) = ForallStmt::build(NULL, new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), NULL, new BlockStmt((yyvsp[0].pblockstmt)), false, true);
      else
        (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-2].pcallexpr)->get(1)->remove(),                       NULL, new BlockStmt((yyvsp[0].pblockstmt)), false, true);
    }
#line 6584 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 165:
#line 863 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-3].pcallexpr)->argList.length > 1)
        (yyval.pblockstmt) = ForallStmt::build(NULL, new CallExpr("chpl__ensureDomainExpr", (yyvsp[-3].pcallexpr)), (yyvsp[-2].pcallexpr), new BlockStmt((yyvsp[0].pblockstmt)), false, true);
      else
        (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-3].pcallexpr)->get(1)->remove(),                       (yyvsp[-2].pcallexpr), new BlockStmt((yyvsp[0].pblockstmt)), false, true);
    }
#line 6595 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 166:
#line 870 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-2].pcallexpr), NULL, new BlockStmt((yyvsp[0].pblockstmt)), true,  true);
    }
#line 6603 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 167:
#line 874 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-3].pcallexpr), (yyvsp[-2].pcallexpr),   new BlockStmt((yyvsp[0].pblockstmt)), true,  true);
    }
#line 6611 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 168:
#line 880 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ZIP, (yyvsp[-1].pcallexpr)); }
#line 6617 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 169:
#line 884 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[-2].pexpr), (yyvsp[0].pblockstmt)); }
#line 6623 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 170:
#line 885 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 6629 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 171:
#line 886 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[-4].pexpr), (yyvsp[-2].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 6635 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 172:
#line 887 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[-3].pexpr), (yyvsp[-2].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 6641 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 173:
#line 888 "chapel.ypp" /* yacc.c:1667  */
    {
(yyval.pblockstmt) = buildIfStmt(convertAssignmentAndWarn((yyvsp[-4].pexpr),(yyvsp[-3].pch),(yyvsp[-2].pexpr)), (yyvsp[0].pblockstmt)); }
#line 6648 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 174:
#line 890 "chapel.ypp" /* yacc.c:1667  */
    {
(yyval.pblockstmt) = buildIfStmt(convertAssignmentAndWarn((yyvsp[-3].pexpr),(yyvsp[-2].pch),(yyvsp[-1].pexpr)), (yyvsp[0].pblockstmt)); }
#line 6655 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 175:
#line 892 "chapel.ypp" /* yacc.c:1667  */
    {
(yyval.pblockstmt) = buildIfStmt(convertAssignmentAndWarn((yyvsp[-6].pexpr),(yyvsp[-5].pch),(yyvsp[-4].pexpr)), (yyvsp[-2].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 6662 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 176:
#line 894 "chapel.ypp" /* yacc.c:1667  */
    {
(yyval.pblockstmt) = buildIfStmt(convertAssignmentAndWarn((yyvsp[-5].pexpr),(yyvsp[-4].pch),(yyvsp[-3].pexpr)), (yyvsp[-2].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 6669 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 177:
#line 899 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = DeferStmt::build((yyvsp[0].pblockstmt)); }
#line 6675 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 178:
#line 902 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = TryStmt::build(false, (yyvsp[-1].pexpr)); }
#line 6681 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 179:
#line 903 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = TryStmt::build(true,  (yyvsp[-1].pexpr)); }
#line 6687 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 180:
#line 904 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = TryStmt::build(false, (yyvsp[0].pblockstmt)); }
#line 6693 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 181:
#line 905 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = TryStmt::build(true,  (yyvsp[0].pblockstmt)); }
#line 6699 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 182:
#line 906 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = TryStmt::build(false, (yyvsp[-1].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 6705 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 183:
#line 907 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = TryStmt::build(true,  (yyvsp[-1].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 6711 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 184:
#line 911 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildChapelStmt(); }
#line 6717 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 185:
#line 912 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-1].pblockstmt)->insertAtTail((yyvsp[0].pexpr)); }
#line 6723 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 186:
#line 916 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = CatchStmt::build((yyvsp[0].pblockstmt)); }
#line 6729 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 187:
#line 917 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = CatchStmt::build((yyvsp[-1].pdefexpr), (yyvsp[0].pblockstmt)); }
#line 6735 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 188:
#line 918 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = CatchStmt::build((yyvsp[-2].pdefexpr), (yyvsp[0].pblockstmt)); }
#line 6741 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 189:
#line 922 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pdefexpr) = new DefExpr(new VarSymbol((yyvsp[0].pch)), NULL, new UnresolvedSymExpr("Error")); }
#line 6747 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 190:
#line 923 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pdefexpr) = new DefExpr(new VarSymbol((yyvsp[-2].pch)), NULL, (yyvsp[0].pexpr));   }
#line 6753 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 191:
#line 927 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_THROW, (yyvsp[-1].pexpr)); }
#line 6759 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 192:
#line 931 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildChapelStmt(buildSelectStmt((yyvsp[-3].pexpr), (yyvsp[-1].pblockstmt))); }
#line 6765 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 193:
#line 933 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildErrorStandin(); }
#line 6771 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 194:
#line 937 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildChapelStmt(); }
#line 6777 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 195:
#line 938 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-1].pblockstmt)->insertAtTail((yyvsp[0].pexpr)); }
#line 6783 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 196:
#line 943 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CondStmt(new CallExpr(PRIM_WHEN, (yyvsp[-1].pcallexpr)), (yyvsp[0].pblockstmt)); }
#line 6789 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 197:
#line 945 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CondStmt(new CallExpr(PRIM_WHEN), (yyvsp[0].pblockstmt)); }
#line 6795 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 198:
#line 947 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CondStmt(new CallExpr(PRIM_WHEN), (yyvsp[0].pblockstmt)); }
#line 6801 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 199:
#line 954 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = buildChapelStmt(buildClassDefExpr((yyvsp[-4].pch),
                                             NULL,
                                             (yyvsp[-5].aggrTag),
                                             (yyvsp[-3].pcallexpr),
                                             (yyvsp[-1].pblockstmt),
                                             FLAG_UNKNOWN,
                                             (yylsp[-5]).comment));
    }
#line 6815 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 200:
#line 964 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = buildChapelStmt(buildClassDefExpr((yyvsp[-4].pch),
                                             (yyvsp[-6].pch),
                                             (yyvsp[-5].aggrTag),
                                             (yyvsp[-3].pcallexpr),
                                             (yyvsp[-1].pblockstmt),
                                             FLAG_EXTERN,
                                             (yylsp[-5]).comment));
    }
#line 6829 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 201:
#line 974 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = buildChapelStmt(buildClassDefExpr((yyvsp[-4].pch),
                                             NULL,
                                             (yyvsp[-5].aggrTag),
                                             (yyvsp[-3].pcallexpr),
                                             new BlockStmt(),
                                             FLAG_UNKNOWN,
                                             (yylsp[-5]).comment));
    }
#line 6843 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 202:
#line 984 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = buildChapelStmt(buildClassDefExpr((yyvsp[-4].pch),
                                             (yyvsp[-6].pch),
                                             (yyvsp[-5].aggrTag),
                                             (yyvsp[-3].pcallexpr),
                                             new BlockStmt(),
                                             FLAG_EXTERN,
                                             (yylsp[-5]).comment));
    }
#line 6857 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 203:
#line 996 "chapel.ypp" /* yacc.c:1667  */
    {
             (yyval.aggrTag)                     = AGGREGATE_CLASS;
             (yyloc).comment             = context->latestComment;
             context->latestComment = NULL;
           }
#line 6867 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 204:
#line 1001 "chapel.ypp" /* yacc.c:1667  */
    {
             (yyval.aggrTag)                     = AGGREGATE_RECORD;
             (yyloc).comment             = context->latestComment;
             context->latestComment = NULL;
           }
#line 6877 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 205:
#line 1006 "chapel.ypp" /* yacc.c:1667  */
    {
             (yyval.aggrTag)                     = AGGREGATE_UNION;
             (yyloc).comment             = context->latestComment;
             context->latestComment = NULL;
           }
#line 6887 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 206:
#line 1014 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = NULL; }
#line 6893 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 207:
#line 1015 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = (yyvsp[0].pcallexpr); }
#line 6899 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 208:
#line 1020 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = new BlockStmt(); }
#line 6905 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 209:
#line 1022 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-1].pblockstmt)->insertAtTail((yyvsp[0].pblockstmt)); }
#line 6911 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 210:
#line 1024 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-2].pblockstmt)->insertAtTail(buildPragmaStmt((yyvsp[-1].vpch), (yyvsp[0].pblockstmt))); }
#line 6917 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 211:
#line 1029 "chapel.ypp" /* yacc.c:1667  */
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
#line 6937 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 212:
#line 1045 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = buildErrorStandin();
    }
#line 6945 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 213:
#line 1052 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.penumtype) = new EnumType();
      (yyloc).comment = context->latestComment;
      context->latestComment = NULL;
    }
#line 6955 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 214:
#line 1061 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pvecOfDefs) = new std::vector<DefExpr*>();
      (yyval.pvecOfDefs)->push_back((yyvsp[0].pdefexpr));
      //$$->doc = context->latestComment;
      // start here for enabling documentation of enum constants
      //context->latestComment = NULL;
    }
#line 6967 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 215:
#line 1069 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pvecOfDefs) = (yyvsp[-1].pvecOfDefs);
    }
#line 6975 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 216:
#line 1073 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyvsp[-2].pvecOfDefs)->push_back((yyvsp[0].pdefexpr));
    }
#line 6983 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 217:
#line 1079 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pdefexpr) = new DefExpr(new EnumSymbol((yyvsp[0].pch))); }
#line 6989 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 218:
#line 1080 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pdefexpr) = new DefExpr(new EnumSymbol((yyvsp[-2].pch)), (yyvsp[0].pexpr)); }
#line 6995 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 219:
#line 1085 "chapel.ypp" /* yacc.c:1667  */
    {
      captureTokens = 1;
      captureString.clear();
    }
#line 7004 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 220:
#line 1090 "chapel.ypp" /* yacc.c:1667  */
    {
      captureTokens = 0;
      (yyvsp[0].pfnsymbol)->userString = astr(captureString);
    }
#line 7013 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 221:
#line 1095 "chapel.ypp" /* yacc.c:1667  */
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
#line 7035 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 222:
#line 1117 "chapel.ypp" /* yacc.c:1667  */
    {
                  (yyval.pfnsymbol) = new FnSymbol("");

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 7046 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 223:
#line 1123 "chapel.ypp" /* yacc.c:1667  */
    {
                  (yyval.pfnsymbol) = new FnSymbol("");
                  (yyval.pfnsymbol)->addFlag(FLAG_INLINE);

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 7058 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 224:
#line 1130 "chapel.ypp" /* yacc.c:1667  */
    {
                  (yyval.pfnsymbol) = buildLinkageFn(FLAG_EXPORT, (yyvsp[0].pexpr));

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 7069 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 225:
#line 1136 "chapel.ypp" /* yacc.c:1667  */
    {
                  (yyval.pfnsymbol) = buildLinkageFn(FLAG_EXTERN, (yyvsp[0].pexpr));

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 7080 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 226:
#line 1142 "chapel.ypp" /* yacc.c:1667  */
    {
                  (yyval.pfnsymbol) = new FnSymbol("");
                  (yyval.pfnsymbol)->addFlag(FLAG_OVERRIDE);

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 7092 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 227:
#line 1153 "chapel.ypp" /* yacc.c:1667  */
    {
      // Sets up to capture tokens while parsing the next grammar nonterminal.
      captureTokens = 1;
      captureString.clear();
    }
#line 7102 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 228:
#line 1159 "chapel.ypp" /* yacc.c:1667  */
    {
      // Stop capturing and save the result.
      captureTokens = 0;

      (yyvsp[0].pfnsymbol)->userString = astr(captureString);
    }
#line 7113 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 229:
#line 1166 "chapel.ypp" /* yacc.c:1667  */
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
#line 7140 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 230:
#line 1192 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), (yyvsp[-1].pch), (yyvsp[-2].pt), NULL);
    }
#line 7148 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 231:
#line 1196 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), (yyvsp[-1].pch), (yyvsp[-2].pt), NULL);
      (yyval.pfnsymbol)->addFlag(FLAG_ASSIGNOP);
    }
#line 7157 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 232:
#line 1201 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), (yyvsp[-1].pch), (yyvsp[-4].pt), (yyvsp[-3].pexpr));
    }
#line 7165 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 233:
#line 1205 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), (yyvsp[-1].pch), (yyvsp[-4].pt), (yyvsp[-3].pexpr));
      (yyval.pfnsymbol)->addFlag(FLAG_ASSIGNOP);
    }
#line 7174 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 234:
#line 1210 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), "dummy", INTENT_BLANK, NULL);
    }
#line 7182 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 236:
#line 1217 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[-1].pexpr); }
#line 7188 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 237:
#line 1221 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 7194 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 238:
#line 1222 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = astr("~", (yyvsp[0].pch)); }
#line 7200 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 239:
#line 1223 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "&"; }
#line 7206 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 240:
#line 1224 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "|"; }
#line 7212 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 241:
#line 1225 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "^"; }
#line 7218 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 242:
#line 1226 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "~"; }
#line 7224 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 243:
#line 1227 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "=="; }
#line 7230 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 244:
#line 1228 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "!="; }
#line 7236 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 245:
#line 1229 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "<="; }
#line 7242 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 246:
#line 1230 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = ">="; }
#line 7248 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 247:
#line 1231 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "<"; }
#line 7254 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 248:
#line 1232 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = ">"; }
#line 7260 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 249:
#line 1233 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "+"; }
#line 7266 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 250:
#line 1234 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "-"; }
#line 7272 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 251:
#line 1235 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "*"; }
#line 7278 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 252:
#line 1236 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "/"; }
#line 7284 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 253:
#line 1237 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "<<"; }
#line 7290 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 254:
#line 1238 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = ">>"; }
#line 7296 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 255:
#line 1239 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "%"; }
#line 7302 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 256:
#line 1240 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "**"; }
#line 7308 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 257:
#line 1241 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "!"; }
#line 7314 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 258:
#line 1242 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "chpl_by"; }
#line 7320 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 259:
#line 1243 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "#"; }
#line 7326 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 260:
#line 1244 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "chpl_align"; }
#line 7332 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 261:
#line 1245 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "<=>"; }
#line 7338 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 262:
#line 1246 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "<~>"; }
#line 7344 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 263:
#line 1247 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "init="; }
#line 7350 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 264:
#line 1248 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = astr((yyvsp[-1].pch), "!"); }
#line 7356 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 265:
#line 1252 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "="; }
#line 7362 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 266:
#line 1253 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "+="; }
#line 7368 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 267:
#line 1254 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "-="; }
#line 7374 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 268:
#line 1255 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "*="; }
#line 7380 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 269:
#line 1256 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "/="; }
#line 7386 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 270:
#line 1257 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "%="; }
#line 7392 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 271:
#line 1258 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "**="; }
#line 7398 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 272:
#line 1259 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "&="; }
#line 7404 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 273:
#line 1260 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "|="; }
#line 7410 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 274:
#line 1261 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "^="; }
#line 7416 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 275:
#line 1262 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = ">>="; }
#line 7422 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 276:
#line 1263 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pch) = "<<="; }
#line 7428 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 277:
#line 1267 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pfnsymbol) = new FnSymbol("_"); (yyval.pfnsymbol)->addFlag(FLAG_NO_PARENS); }
#line 7434 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 278:
#line 1268 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pfnsymbol) = (yyvsp[-1].pfnsymbol); }
#line 7440 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 279:
#line 1272 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pfnsymbol) = (yyvsp[-1].pfnsymbol); }
#line 7446 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 280:
#line 1276 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pfnsymbol) = buildFunctionFormal(NULL, NULL); }
#line 7452 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 281:
#line 1277 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pfnsymbol) = buildFunctionFormal(NULL, (yyvsp[0].pdefexpr)); }
#line 7458 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 282:
#line 1278 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pfnsymbol) = buildFunctionFormal((yyvsp[-2].pfnsymbol), (yyvsp[0].pdefexpr)); }
#line 7464 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 283:
#line 1283 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pdefexpr) = buildArgDefExpr((yyvsp[-3].pt), (yyvsp[-2].pch), (yyvsp[-1].pexpr), (yyvsp[0].pexpr), NULL); }
#line 7470 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 284:
#line 1285 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pdefexpr) = buildPragmaDefExpr((yyvsp[-4].vpch), buildArgDefExpr((yyvsp[-3].pt), (yyvsp[-2].pch), (yyvsp[-1].pexpr), (yyvsp[0].pexpr), NULL)); }
#line 7476 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 285:
#line 1287 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pdefexpr) = buildArgDefExpr((yyvsp[-3].pt), (yyvsp[-2].pch), (yyvsp[-1].pexpr), NULL, (yyvsp[0].pexpr)); }
#line 7482 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 286:
#line 1289 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pdefexpr) = buildTupleArgDefExpr((yyvsp[-5].pt), (yyvsp[-3].pblockstmt), (yyvsp[-1].pexpr), (yyvsp[0].pexpr)); }
#line 7488 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 287:
#line 1291 "chapel.ypp" /* yacc.c:1667  */
    { USR_FATAL("variable-length argument may not be grouped in a tuple"); }
#line 7494 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 288:
#line 1295 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_BLANK; }
#line 7500 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 289:
#line 1296 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = (yyvsp[0].pt); }
#line 7506 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 290:
#line 1300 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_IN; }
#line 7512 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 291:
#line 1301 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_INOUT; }
#line 7518 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 292:
#line 1302 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_OUT; }
#line 7524 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 293:
#line 1303 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_CONST; }
#line 7530 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 294:
#line 1304 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_CONST_IN; }
#line 7536 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 295:
#line 1305 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_CONST_REF; }
#line 7542 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 296:
#line 1306 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_PARAM; }
#line 7548 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 297:
#line 1307 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_REF; }
#line 7554 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 298:
#line 1308 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_TYPE; }
#line 7560 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 299:
#line 1312 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_BLANK; }
#line 7566 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 300:
#line 1313 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_PARAM; }
#line 7572 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 301:
#line 1314 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_REF;   }
#line 7578 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 302:
#line 1315 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_CONST_REF;   }
#line 7584 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 303:
#line 1316 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_CONST;   }
#line 7590 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 304:
#line 1317 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pt) = INTENT_TYPE;  }
#line 7596 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 305:
#line 1321 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.procIter) = ProcIter_PROC; }
#line 7602 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 306:
#line 1322 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.procIter) = ProcIter_ITER; }
#line 7608 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 307:
#line 1326 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.retTag) = RET_VALUE; }
#line 7614 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 308:
#line 1327 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.retTag) = RET_VALUE; }
#line 7620 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 309:
#line 1328 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.retTag) = RET_CONST_REF; }
#line 7626 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 310:
#line 1329 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.retTag) = RET_REF; }
#line 7632 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 311:
#line 1330 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.retTag) = RET_PARAM; }
#line 7638 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 312:
#line 1331 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.retTag) = RET_TYPE; }
#line 7644 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 313:
#line 1335 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.b) = false; }
#line 7650 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 314:
#line 1336 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.b) = true;  }
#line 7656 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 315:
#line 1339 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = NULL; }
#line 7662 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 318:
#line 1345 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = new BlockStmt((yyvsp[0].pblockstmt)); }
#line 7668 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 319:
#line 1350 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new DefExpr(new VarSymbol((yyvsp[0].pch))); }
#line 7674 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 320:
#line 1352 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(gUninstantiated); }
#line 7680 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 321:
#line 1356 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(gUninstantiated); }
#line 7686 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 323:
#line 1361 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 7692 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 324:
#line 1362 "chapel.ypp" /* yacc.c:1667  */
    { if (DefExpr* def = toDefExpr((yyvsp[0].pexpr))) {
                                 def->sym->addFlag(FLAG_PARAM);
                               }
                               (yyval.pexpr) = (yyvsp[0].pexpr);
                             }
#line 7702 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 325:
#line 1370 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.lifetimeAndWhere) = makeWhereAndLifetime(NULL, NULL); }
#line 7708 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 326:
#line 1372 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.lifetimeAndWhere) = makeWhereAndLifetime((yyvsp[0].pexpr), NULL); }
#line 7714 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 327:
#line 1374 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.lifetimeAndWhere) = makeWhereAndLifetime(NULL, (yyvsp[0].pexpr)); }
#line 7720 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 328:
#line 1376 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.lifetimeAndWhere) = makeWhereAndLifetime((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7726 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 329:
#line 1378 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.lifetimeAndWhere) = makeWhereAndLifetime((yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 7732 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 330:
#line 1382 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 7738 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 331:
#line 1383 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(",", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7744 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 332:
#line 1386 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7750 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 333:
#line 1387 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("<", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7756 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 334:
#line 1388 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("<=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7762 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 335:
#line 1389 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("==", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7768 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 336:
#line 1390 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(">", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7774 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 337:
#line 1391 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(">=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7780 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 338:
#line 1392 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(PRIM_RETURN, (yyvsp[0].pexpr)); }
#line 7786 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 339:
#line 1395 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(PRIM_LIFETIME_OF, new UnresolvedSymExpr((yyvsp[0].pch))); }
#line 7792 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 340:
#line 1396 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(PRIM_LIFETIME_OF, new UnresolvedSymExpr("this")); }
#line 7798 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 341:
#line 1400 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = (yyvsp[-1].pblockstmt); }
#line 7804 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 342:
#line 1402 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = handleConfigTypes((yyvsp[-1].pblockstmt)); }
#line 7810 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 343:
#line 1404 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = convertTypesToExtern((yyvsp[-1].pblockstmt)); }
#line 7816 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 344:
#line 1409 "chapel.ypp" /* yacc.c:1667  */
    {
      VarSymbol* var = new VarSymbol((yyvsp[-1].pch));

      var->addFlag(FLAG_TYPE_VARIABLE);

      var->doc               = context->latestComment;
      context->latestComment = NULL;

      DefExpr* def = new DefExpr(var, (yyvsp[0].pexpr));

      (yyval.pblockstmt) = buildChapelStmt(def);
    }
#line 7833 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 345:
#line 1422 "chapel.ypp" /* yacc.c:1667  */
    {
      VarSymbol* var = new VarSymbol((yyvsp[-3].pch));

      var->addFlag(FLAG_TYPE_VARIABLE);

      var->doc               = context->latestComment;
      context->latestComment = NULL;

      DefExpr* def = new DefExpr(var, (yyvsp[-2].pexpr));

      (yyvsp[0].pblockstmt)->insertAtHead(def);
      (yyval.pblockstmt) = buildChapelStmt((yyvsp[0].pblockstmt));
    }
#line 7851 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 346:
#line 1438 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = NULL; }
#line 7857 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 347:
#line 1440 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 7863 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 348:
#line 1442 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForallLoopExprFromArrayType((yyvsp[0].pcallexpr)); }
#line 7869 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 349:
#line 1446 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pflagset) = buildVarDeclFlags(FLAG_PARAM); }
#line 7875 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 350:
#line 1447 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pflagset) = buildVarDeclFlags(FLAG_CONST); }
#line 7881 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 351:
#line 1448 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pflagset) = buildVarDeclFlags(FLAG_REF_VAR); }
#line 7887 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 352:
#line 1449 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pflagset) = buildVarDeclFlags(FLAG_CONST, FLAG_REF_VAR); }
#line 7893 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 353:
#line 1450 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pflagset) = buildVarDeclFlags(); }
#line 7899 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 354:
#line 1455 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyvsp[-2].pflagset)->insert(FLAG_CONFIG);
      (yyval.pblockstmt) = buildVarDecls((yyvsp[-1].pblockstmt), context->latestComment, (yyvsp[-2].pflagset));
      context->latestComment = NULL;
    }
#line 7909 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 355:
#line 1461 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyvsp[-2].pflagset)->insert(FLAG_EXTERN);
      (yyval.pblockstmt) = buildVarDecls((yyvsp[-1].pblockstmt), context->latestComment, (yyvsp[-2].pflagset), (yyvsp[-3].pexpr));
      context->latestComment = NULL;
    }
#line 7919 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 356:
#line 1467 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pblockstmt) = buildVarDecls((yyvsp[-1].pblockstmt), context->latestComment, (yyvsp[-2].pflagset));
      context->latestComment = NULL;
    }
#line 7928 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 358:
#line 1476 "chapel.ypp" /* yacc.c:1667  */
    {
      for_alist(expr, (yyvsp[0].pblockstmt)->body)
        (yyvsp[-2].pblockstmt)->insertAtTail(expr->remove());
    }
#line 7937 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 359:
#line 1484 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildChapelStmt(new DefExpr(new VarSymbol((yyvsp[-2].pch)), (yyvsp[0].pexpr), (yyvsp[-1].pexpr))); }
#line 7943 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 360:
#line 1486 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildTupleVarDeclStmt((yyvsp[-3].pblockstmt), (yyvsp[-1].pexpr), (yyvsp[0].pexpr)); }
#line 7949 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 361:
#line 1491 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new DefExpr(new VarSymbol("chpl__tuple_blank")); }
#line 7955 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 362:
#line 1493 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new DefExpr(new VarSymbol((yyvsp[0].pch))); }
#line 7961 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 363:
#line 1495 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[-1].pblockstmt); }
#line 7967 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 364:
#line 1500 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildChapelStmt((yyvsp[0].pexpr)); }
#line 7973 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 365:
#line 1502 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = buildChapelStmt((yyvsp[-1].pexpr)); }
#line 7979 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 366:
#line 1504 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pblockstmt) = ((yyvsp[0].pblockstmt)->insertAtHead((yyvsp[-2].pexpr)), (yyvsp[0].pblockstmt)); }
#line 7985 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 367:
#line 1510 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = NULL; }
#line 7991 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 368:
#line 1511 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(gNoInit); }
#line 7997 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 369:
#line 1512 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8003 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 370:
#line 1518 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, (yyvsp[0].pexpr)); }
#line 8009 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 371:
#line 1520 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, NULL); }
#line 8015 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 372:
#line 1522 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pexpr));
    }
#line 8023 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 373:
#line 1526 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-1].pcallexpr)), NULL);
    }
#line 8031 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 374:
#line 1530 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, (yyvsp[0].pexpr)); }
#line 8037 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 375:
#line 1532 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pexpr));
    }
#line 8045 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 376:
#line 1536 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pexpr) = new CallExpr(PRIM_ERROR);
    }
#line 8053 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 377:
#line 1543 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = NULL; }
#line 8059 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 378:
#line 1544 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8065 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 379:
#line 1545 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8071 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 380:
#line 1546 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr((yyvsp[0].pch)); }
#line 8077 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 381:
#line 1547 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = NULL; }
#line 8083 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 382:
#line 1552 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = NULL; }
#line 8089 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 383:
#line 1553 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8095 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 384:
#line 1554 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pcallexpr); }
#line 8101 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 385:
#line 1555 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr((yyvsp[0].pch)); }
#line 8107 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 386:
#line 1556 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = NULL; }
#line 8113 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 387:
#line 1577 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pexpr));
    }
#line 8121 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 388:
#line 1581 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pcallexpr));
    }
#line 8129 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 389:
#line 1585 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pexpr), "invalid index expression");
      (yyval.pcallexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pexpr)), (yyvsp[0].pexpr), (yyvsp[-4].pcallexpr)->get(1)->remove(),
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pexpr)->copy()));
    }
#line 8141 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 390:
#line 1593 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pcallexpr) = new CallExpr(PRIM_ERROR);
    }
#line 8149 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 391:
#line 1599 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = NULL; }
#line 8155 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 392:
#line 1600 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8161 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 393:
#line 1601 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8167 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 394:
#line 1606 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, (yyvsp[0].pexpr)); }
#line 8173 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 395:
#line 1608 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildFormalArrayType((yyvsp[-2].pcallexpr), (yyvsp[0].pexpr)); }
#line 8179 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 396:
#line 1614 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, (yyvsp[0].pexpr)); }
#line 8185 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 397:
#line 1616 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildFormalArrayType((yyvsp[-2].pcallexpr), (yyvsp[0].pexpr)); }
#line 8191 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 398:
#line 1618 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildFormalArrayType((yyvsp[-2].pexpr), (yyvsp[0].pexpr), (yyvsp[-4].pcallexpr)); }
#line 8197 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 399:
#line 1622 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = NULL; }
#line 8203 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 400:
#line 1623 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8209 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 401:
#line 1624 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8215 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 402:
#line 1625 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr((yyvsp[0].pch)); }
#line 8221 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 403:
#line 1626 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8227 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 404:
#line 1632 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[0].pexpr)); }
#line 8233 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 405:
#line 1633 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[0].pexpr)); }
#line 8239 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 406:
#line 1634 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 8245 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 407:
#line 1635 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 8251 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 408:
#line 1639 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[0].pexpr));}
#line 8257 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 409:
#line 1640 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 8263 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 410:
#line 1644 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("chpl__tuple_blank"); }
#line 8269 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 411:
#line 1645 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8275 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 412:
#line 1646 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8281 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 413:
#line 1650 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8287 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 414:
#line 1651 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 8293 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 415:
#line 1655 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST); }
#line 8299 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 417:
#line 1660 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[0].pexpr)); }
#line 8305 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 418:
#line 1661 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 8311 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 419:
#line 1665 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildNamedActual((yyvsp[-2].pch), (yyvsp[0].pexpr)); }
#line 8317 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 420:
#line 1666 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildNamedActual((yyvsp[-2].pch), (yyvsp[0].pexpr)); }
#line 8323 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 421:
#line 1667 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8329 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 422:
#line 1668 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8335 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 423:
#line 1672 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr((yyvsp[0].pch)); }
#line 8341 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 424:
#line 1673 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8347 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 425:
#line 1685 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8353 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 426:
#line 1687 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr( PRIM_TO_NILABLE_CLASS, (yyvsp[-1].pexpr)); }
#line 8359 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 432:
#line 1700 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr( "_singlevar", (yyvsp[0].pexpr)); }
#line 8365 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 433:
#line 1702 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildIndexType", (yyvsp[-1].pcallexpr)); }
#line 8371 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 434:
#line 1704 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildDomainRuntimeType", new UnresolvedSymExpr("defaultDist"), (yyvsp[-1].pcallexpr)); }
#line 8377 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 435:
#line 1706 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildSubDomainType", (yyvsp[-1].pcallexpr)); }
#line 8383 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 436:
#line 1708 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildSparseDomainRuntimeType", buildDotExpr((yyvsp[-1].pcallexpr)->copy(), "defaultSparseDist"), (yyvsp[-1].pcallexpr)); }
#line 8389 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 437:
#line 1710 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__atomicType", (yyvsp[0].pexpr)); }
#line 8395 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 438:
#line 1712 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr( "_syncvar", (yyvsp[0].pexpr)); }
#line 8401 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 439:
#line 1715 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("_owned"); }
#line 8407 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 440:
#line 1717 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr( "_owned", (yyvsp[0].pexpr)); }
#line 8413 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 441:
#line 1719 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("_unmanaged"); }
#line 8419 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 442:
#line 1721 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr( PRIM_TO_UNMANAGED_CLASS, (yyvsp[0].pexpr)); }
#line 8425 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 443:
#line 1723 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("_shared"); }
#line 8431 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 444:
#line 1725 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr( "_shared", (yyvsp[0].pexpr)); }
#line 8437 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 445:
#line 1727 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("_borrowed"); }
#line 8443 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 446:
#line 1729 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr( PRIM_TO_BORROWED_CLASS, (yyvsp[0].pexpr)); }
#line 8449 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 447:
#line 1734 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8455 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 448:
#line 1736 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[-4].pexpr), (yyvsp[-2].pcallexpr), (yyvsp[0].pexpr), NULL, false, true); }
#line 8461 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 449:
#line 1738 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForLoopExpr(NULL, (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8467 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 450:
#line 1740 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[-7].pexpr), (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 8473 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 451:
#line 1742 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[-7].pexpr), (yyvsp[-5].pcallexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr), false, true); }
#line 8479 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 452:
#line 1744 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForLoopExpr(NULL, (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 8485 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 453:
#line 1746 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8491 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 454:
#line 1748 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[-4].pexpr), (yyvsp[-2].pcallexpr), (yyvsp[0].pexpr), NULL, false, true); }
#line 8497 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 455:
#line 1750 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForallLoopExpr(NULL, (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8503 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 456:
#line 1752 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[-7].pexpr), (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 8509 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 457:
#line 1754 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[-7].pexpr), (yyvsp[-5].pcallexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr), false, true); }
#line 8515 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 458:
#line 1756 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildForallLoopExpr(NULL, (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 8521 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 459:
#line 1758 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-2].pcallexpr)->argList.length > 1)
        (yyval.pexpr) = buildForallLoopExpr(NULL, new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pexpr), NULL, true);
      else
        (yyval.pexpr) = buildForallLoopExpr(NULL, (yyvsp[-2].pcallexpr)->get(1)->remove(), (yyvsp[0].pexpr), NULL, true);
    }
#line 8532 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 460:
#line 1765 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[-4].pcallexpr)->get(1)->remove(), (yyvsp[-2].pexpr), (yyvsp[0].pexpr), NULL, true);
    }
#line 8542 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 461:
#line 1771 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pcallexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[-4].pcallexpr)->get(1)->remove(), (yyvsp[-2].pcallexpr), (yyvsp[0].pexpr), NULL, false, true);
    }
#line 8552 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 462:
#line 1777 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-7].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-5].pexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[-7].pcallexpr)->get(1)->remove(), (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr));
    }
#line 8562 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 463:
#line 1783 "chapel.ypp" /* yacc.c:1667  */
    {
      if ((yyvsp[-7].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-5].pcallexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[-7].pcallexpr)->get(1)->remove(), (yyvsp[-5].pcallexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr), false, true);
    }
#line 8572 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 464:
#line 1792 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new IfExpr((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8578 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 465:
#line 1801 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(gNil); }
#line 8584 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 473:
#line 1817 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("<~>", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8590 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 474:
#line 1821 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = NULL; }
#line 8596 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 476:
#line 1826 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = (yyvsp[-1].pcallexpr); }
#line 8602 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 477:
#line 1830 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST); addTaskIntent((yyval.pcallexpr), (yyvsp[0].pShadowVar)); }
#line 8608 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 478:
#line 1831 "chapel.ypp" /* yacc.c:1667  */
    { addTaskIntent((yyvsp[-2].pcallexpr), (yyvsp[0].pShadowVar)); }
#line 8614 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 479:
#line 1835 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = (yyvsp[-1].pcallexpr); }
#line 8620 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 480:
#line 1839 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST); addForallIntent((yyval.pcallexpr), (yyvsp[0].pShadowVar)); }
#line 8626 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 481:
#line 1840 "chapel.ypp" /* yacc.c:1667  */
    { addForallIntent((yyvsp[-2].pcallexpr), (yyvsp[0].pShadowVar)); }
#line 8632 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 482:
#line 1845 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pShadowVar) = ShadowVarSymbol::buildForPrefix((yyvsp[-3].pShadowVarPref), (yyvsp[-2].pexpr), (yyvsp[-1].pexpr), (yyvsp[0].pexpr));
    }
#line 8640 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 483:
#line 1849 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pShadowVar) = ShadowVarSymbol::buildFromReduceIntent((yyvsp[0].pexpr), (yyvsp[-2].pexpr));
    }
#line 8648 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 484:
#line 1853 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pShadowVar) = ShadowVarSymbol::buildFromReduceIntent((yyvsp[0].pexpr), (yyvsp[-2].pexpr));
    }
#line 8656 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 485:
#line 1859 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pShadowVarPref) = SVP_CONST;     }
#line 8662 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 486:
#line 1860 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pShadowVarPref) = SVP_IN;        }
#line 8668 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 487:
#line 1861 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pShadowVarPref) = SVP_CONST_IN;  }
#line 8674 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 488:
#line 1862 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pShadowVarPref) = SVP_REF;       }
#line 8680 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 489:
#line 1863 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pShadowVarPref) = SVP_CONST_REF; }
#line 8686 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 490:
#line 1864 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pShadowVarPref) = SVP_VAR;       }
#line 8692 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 492:
#line 1870 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("<~>", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8698 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 493:
#line 1875 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(PRIM_NEW, (yyvsp[0].pexpr)); }
#line 8704 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 494:
#line 1880 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildLetExpr((yyvsp[-2].pblockstmt), (yyvsp[0].pexpr)); }
#line 8710 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 503:
#line 1896 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(PRIM_TUPLE_EXPAND, (yyvsp[-1].pexpr)); }
#line 8716 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 504:
#line 1898 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = createCast((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8722 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 505:
#line 1900 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl_build_bounded_range", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8728 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 506:
#line 1902 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl_build_low_bounded_range", (yyvsp[-1].pexpr)); }
#line 8734 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 507:
#line 1904 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl_build_high_bounded_range", (yyvsp[0].pexpr)); }
#line 8740 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 508:
#line 1906 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl_build_unbounded_range"); }
#line 8746 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 509:
#line 1910 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = NULL; }
#line 8752 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 510:
#line 1911 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8758 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 511:
#line 1914 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = tryExpr((yyvsp[0].pexpr)); }
#line 8764 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 512:
#line 1915 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = tryBangExpr((yyvsp[0].pexpr)); }
#line 8770 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 513:
#line 1916 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8776 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 518:
#line 1933 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8782 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 519:
#line 1934 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("postfix!", (yyvsp[-1].pexpr)); }
#line 8788 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 520:
#line 1935 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 8794 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 521:
#line 1939 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr((yyvsp[-3].pexpr), (yyvsp[-1].pcallexpr)); }
#line 8800 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 522:
#line 1940 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildSquareCallExpr((yyvsp[-3].pexpr), (yyvsp[-1].pcallexpr)); }
#line 8806 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 523:
#line 1941 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildPrimitiveExpr((yyvsp[-1].pcallexpr)); }
#line 8812 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 524:
#line 1945 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildDotExpr((yyvsp[-2].pexpr), (yyvsp[0].pch)); }
#line 8818 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 525:
#line 1946 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(PRIM_TYPEOF, (yyvsp[-2].pexpr)); }
#line 8824 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 526:
#line 1947 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildDotExpr((yyvsp[-2].pexpr), "_dom"); }
#line 8830 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 527:
#line 1948 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildDotExpr((yyvsp[-2].pexpr), "locale"); }
#line 8836 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 528:
#line 1956 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = (yyvsp[-1].pexpr); }
#line 8842 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 529:
#line 1957 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildOneTuple((yyvsp[-2].pexpr)); }
#line 8848 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 530:
#line 1958 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildTuple((yyvsp[-1].pcallexpr)); }
#line 8854 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 531:
#line 1959 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildTuple((yyvsp[-2].pcallexpr)); }
#line 8860 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 532:
#line 1963 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(gFalse); }
#line 8866 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 533:
#line 1964 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(gTrue); }
#line 8872 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 535:
#line 1969 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildIntLiteral((yyvsp[0].pch), yyfilename, chplLineno);    }
#line 8878 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 536:
#line 1970 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildRealLiteral((yyvsp[0].pch));   }
#line 8884 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 537:
#line 1971 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildImagLiteral((yyvsp[0].pch));   }
#line 8890 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 538:
#line 1972 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildStringLiteral((yyvsp[0].pch)); }
#line 8896 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 539:
#line 1973 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildCStringLiteral((yyvsp[0].pch)); }
#line 8902 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 540:
#line 1974 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new SymExpr(gNone); }
#line 8908 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 541:
#line 1975 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildDomainExpr", (yyvsp[-1].pcallexpr)); }
#line 8914 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 542:
#line 1976 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildDomainExpr", (yyvsp[-2].pcallexpr)); }
#line 8920 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 543:
#line 1977 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayExpr",  (yyvsp[-1].pcallexpr)); }
#line 8926 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 544:
#line 1978 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayExpr",  (yyvsp[-2].pcallexpr)); }
#line 8932 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 545:
#line 1980 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pexpr) = new CallExpr("chpl__buildAssociativeArrayExpr", (yyvsp[-1].pcallexpr));
    }
#line 8940 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 546:
#line 1984 "chapel.ypp" /* yacc.c:1667  */
    {
      (yyval.pexpr) = new CallExpr("chpl__buildAssociativeArrayExpr", (yyvsp[-2].pcallexpr));
    }
#line 8948 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 547:
#line 1991 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8954 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 548:
#line 1992 "chapel.ypp" /* yacc.c:1667  */
    { (yyvsp[-4].pcallexpr)->insertAtTail((yyvsp[-2].pexpr)); (yyvsp[-4].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 8960 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 549:
#line 1996 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("+", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8966 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 550:
#line 1997 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("-", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8972 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 551:
#line 1998 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("*", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8978 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 552:
#line 1999 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("/", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8984 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 553:
#line 2000 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("<<", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8990 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 554:
#line 2001 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(">>", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 8996 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 555:
#line 2002 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("%", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9002 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 556:
#line 2003 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("==", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9008 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 557:
#line 2004 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("==", (yyvsp[-2].pexpr), gUninstantiated); }
#line 9014 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 558:
#line 2005 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("!=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9020 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 559:
#line 2006 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("!=", (yyvsp[-2].pexpr), gUninstantiated); }
#line 9026 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 560:
#line 2007 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("<=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9032 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 561:
#line 2008 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(">=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9038 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 562:
#line 2009 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("<", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9044 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 563:
#line 2010 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr(">", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9050 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 564:
#line 2011 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("&", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9056 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 565:
#line 2012 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("|", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9062 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 566:
#line 2013 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("^", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9068 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 567:
#line 2014 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("&&", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9074 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 568:
#line 2015 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("||", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9080 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 569:
#line 2016 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("**", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9086 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 570:
#line 2017 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl_by", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9092 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 571:
#line 2018 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl_align", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9098 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 572:
#line 2019 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("#", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9104 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 573:
#line 2020 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("chpl__distributed", (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 9110 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 574:
#line 2024 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("+", (yyvsp[0].pexpr)); }
#line 9116 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 575:
#line 2025 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("-", (yyvsp[0].pexpr)); }
#line 9122 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 576:
#line 2026 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildPreDecIncWarning((yyvsp[0].pexpr), '-'); }
#line 9128 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 577:
#line 2027 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildPreDecIncWarning((yyvsp[0].pexpr), '+'); }
#line 9134 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 578:
#line 2028 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("!", (yyvsp[0].pexpr)); }
#line 9140 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 579:
#line 2029 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("postfix!", (yyvsp[-1].pexpr)); }
#line 9146 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 580:
#line 2030 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new CallExpr("~", (yyvsp[0].pexpr)); }
#line 9152 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 581:
#line 2034 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildReduceExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9158 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 582:
#line 2035 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildReduceExpr((yyvsp[-2].pexpr), (yyvsp[0].pcallexpr), true); }
#line 9164 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 583:
#line 2036 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildReduceExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9170 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 584:
#line 2037 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildReduceExpr((yyvsp[-2].pexpr), (yyvsp[0].pcallexpr), true); }
#line 9176 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 585:
#line 2041 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildScanExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9182 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 586:
#line 2042 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildScanExpr((yyvsp[-2].pexpr), (yyvsp[0].pcallexpr), true); }
#line 9188 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 587:
#line 2043 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildScanExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 9194 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 588:
#line 2044 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = buildScanExpr((yyvsp[-2].pexpr), (yyvsp[0].pcallexpr), true); }
#line 9200 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 589:
#line 2049 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("SumReduceScanOp"); }
#line 9206 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 590:
#line 2050 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("ProductReduceScanOp"); }
#line 9212 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 591:
#line 2051 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("LogicalAndReduceScanOp"); }
#line 9218 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 592:
#line 2052 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("LogicalOrReduceScanOp"); }
#line 9224 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 593:
#line 2053 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("BitwiseAndReduceScanOp"); }
#line 9230 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 594:
#line 2054 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("BitwiseOrReduceScanOp"); }
#line 9236 "bison-chapel.cpp" /* yacc.c:1667  */
    break;

  case 595:
#line 2055 "chapel.ypp" /* yacc.c:1667  */
    { (yyval.pexpr) = new UnresolvedSymExpr("BitwiseXorReduceScanOp"); }
#line 9242 "bison-chapel.cpp" /* yacc.c:1667  */
    break;


#line 9246 "bison-chapel.cpp" /* yacc.c:1667  */
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
