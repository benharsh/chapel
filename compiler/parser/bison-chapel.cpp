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
    Flag                      flag;
    ProcIter                  procIter;
    FlagSet*                  flagSet;
    ShadowVarSymbol*          pShadowVar;
    std::vector<OnlyRename*>* ponlylist;
  };

  #endif
#line 130 "chapel.ypp" /* yacc.c:355  */

  #ifndef _BISON_CHAPEL_DEFINES_2_
  #define _BISON_CHAPEL_DEFINES_2_

  struct YYLTYPE {
    int         first_line;
    int         first_column;
    int         last_line;
    int         last_column;
    const char* comment;
  };

  #define YYLTYPE_IS_DECLARED 1
  #define YYLTYPE_IS_TRIVIAL  1

  #endif
#line 152 "chapel.ypp" /* yacc.c:355  */

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

#line 222 "bison-chapel.cpp" /* yacc.c:355  */

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
    TBY = 270,
    TCATCH = 271,
    TCLASS = 272,
    TCOBEGIN = 273,
    TCOFORALL = 274,
    TCONFIG = 275,
    TCONST = 276,
    TCONTINUE = 277,
    TCOMPLETE = 278,
    TDEFER = 279,
    TDELETE = 280,
    TDMAPPED = 281,
    TDO = 282,
    TDOMAIN = 283,
    TELSE = 284,
    TENUM = 285,
    TEXCEPT = 286,
    TEXPORT = 287,
    TEXTERN = 288,
    TFOR = 289,
    TFORALL = 290,
    TFORWARDING = 291,
    TIF = 292,
    TIN = 293,
    TINDEX = 294,
    TINLINE = 295,
    TINOUT = 296,
    TITER = 297,
    TLABEL = 298,
    TLAMBDA = 299,
    TLET = 300,
    TLOCAL = 301,
    TMINUSMINUS = 302,
    TMODULE = 303,
    TNEW = 304,
    TNIL = 305,
    TNOINIT = 306,
    TON = 307,
    TONLY = 308,
    TOTHERWISE = 309,
    TOUT = 310,
    TPARAM = 311,
    TPLUSPLUS = 312,
    TPRAGMA = 313,
    TPRIMITIVE = 314,
    TPRIVATE = 315,
    TPROC = 316,
    TPROTOTYPE = 317,
    TPUBLIC = 318,
    TRECORD = 319,
    TREDUCE = 320,
    TREF = 321,
    TREQUIRE = 322,
    TRETURN = 323,
    TSCAN = 324,
    TSELECT = 325,
    TSERIAL = 326,
    TSINGLE = 327,
    TSPARSE = 328,
    TSUBDOMAIN = 329,
    TSYNC = 330,
    TTHEN = 331,
    TTHROW = 332,
    TTHROWS = 333,
    TTRY = 334,
    TTRYBANG = 335,
    TTYPE = 336,
    TUNDERSCORE = 337,
    TUNION = 338,
    TUSE = 339,
    TVAR = 340,
    TWHEN = 341,
    TWHERE = 342,
    TWHILE = 343,
    TWITH = 344,
    TYIELD = 345,
    TZIP = 346,
    TALIAS = 347,
    TAND = 348,
    TASSIGN = 349,
    TASSIGNBAND = 350,
    TASSIGNBOR = 351,
    TASSIGNBXOR = 352,
    TASSIGNDIVIDE = 353,
    TASSIGNEXP = 354,
    TASSIGNLAND = 355,
    TASSIGNLOR = 356,
    TASSIGNMINUS = 357,
    TASSIGNMOD = 358,
    TASSIGNMULTIPLY = 359,
    TASSIGNPLUS = 360,
    TASSIGNSL = 361,
    TASSIGNSR = 362,
    TBAND = 363,
    TBNOT = 364,
    TBOR = 365,
    TBXOR = 366,
    TCOLON = 367,
    TCOMMA = 368,
    TDIVIDE = 369,
    TDOT = 370,
    TDOTDOT = 371,
    TDOTDOTDOT = 372,
    TEQUAL = 373,
    TEXP = 374,
    TGREATER = 375,
    TGREATEREQUAL = 376,
    THASH = 377,
    TLESS = 378,
    TLESSEQUAL = 379,
    TMINUS = 380,
    TMOD = 381,
    TNOT = 382,
    TNOTEQUAL = 383,
    TOR = 384,
    TPLUS = 385,
    TQUESTION = 386,
    TSEMI = 387,
    TSHIFTLEFT = 388,
    TSHIFTRIGHT = 389,
    TSTAR = 390,
    TSWAP = 391,
    TASSIGNREDUCE = 392,
    TIO = 393,
    TLCBR = 394,
    TRCBR = 395,
    TLP = 396,
    TRP = 397,
    TLSBR = 398,
    TRSBR = 399,
    TNOELSE = 400,
    TUPLUS = 401,
    TUMINUS = 402
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
#line 183 "chapel.ypp" /* yacc.c:355  */

  extern int yydebug;

  void yyerror(YYLTYPE*       ignored,
               ParserContext* context,
               const char*    str);

#line 415 "bison-chapel.cpp" /* yacc.c:355  */

#endif /* !YY_YY_INCLUDE_BISON_CHAPEL_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 421 "bison-chapel.cpp" /* yacc.c:358  */
/* Unqualified %code blocks.  */
#line 38 "chapel.ypp" /* yacc.c:359  */

  #include <string>
  int         captureTokens;
  std::string captureString;
#line 191 "chapel.ypp" /* yacc.c:359  */

  #include "build.h"
  #include "CatchStmt.h"
  #include "DeferStmt.h"
  #include "DoWhileStmt.h"
  #include "driver.h"
  #include "flex-chapel.h"
  #include "ForallStmt.h"
  #include "ForLoop.h"
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
    setupError(__FILE__, __LINE__, 3);

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

#line 494 "bison-chapel.cpp" /* yacc.c:359  */

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
#define YYLAST   12793

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  148
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  124
/* YYNRULES -- Number of rules.  */
#define YYNRULES  496
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  940

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   402

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
     145,   146,   147
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   441,   441,   446,   447,   453,   454,   459,   460,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     499,   502,   504,   510,   511,   512,   516,   517,   530,   531,
     532,   537,   538,   543,   548,   553,   557,   564,   569,   573,
     578,   582,   583,   584,   588,   592,   594,   596,   598,   600,
     602,   604,   606,   608,   610,   612,   614,   616,   618,   620,
     622,   627,   628,   632,   636,   637,   641,   642,   646,   647,
     651,   652,   653,   654,   655,   656,   657,   658,   662,   663,
     667,   668,   669,   670,   674,   689,   690,   691,   692,   693,
     694,   695,   696,   697,   698,   699,   700,   701,   702,   703,
     704,   705,   711,   717,   723,   729,   736,   746,   750,   751,
     752,   753,   754,   756,   758,   760,   765,   768,   769,   770,
     771,   772,   773,   777,   778,   782,   783,   784,   788,   789,
     793,   796,   798,   803,   804,   808,   810,   812,   819,   829,
     839,   849,   862,   867,   872,   880,   881,   886,   887,   889,
     894,   910,   917,   926,   934,   938,   945,   946,   951,   956,
     950,   981,   987,   994,  1002,  1014,  1020,  1013,  1048,  1052,
    1057,  1061,  1069,  1070,  1074,  1075,  1076,  1077,  1078,  1079,
    1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  1091,  1092,  1093,  1094,  1095,  1096,  1097,  1098,  1099,
    1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,
    1113,  1114,  1118,  1119,  1123,  1127,  1128,  1129,  1133,  1135,
    1137,  1139,  1144,  1145,  1149,  1150,  1151,  1152,  1153,  1154,
    1155,  1156,  1157,  1161,  1162,  1163,  1164,  1165,  1166,  1170,
    1171,  1175,  1176,  1177,  1178,  1179,  1180,  1184,  1185,  1188,
    1189,  1193,  1194,  1198,  1200,  1205,  1206,  1210,  1211,  1215,
    1216,  1220,  1222,  1224,  1229,  1242,  1259,  1260,  1262,  1267,
    1275,  1283,  1291,  1300,  1310,  1311,  1312,  1316,  1317,  1325,
    1327,  1332,  1334,  1336,  1341,  1343,  1345,  1352,  1353,  1354,
    1358,  1359,  1360,  1361,  1381,  1385,  1389,  1397,  1404,  1405,
    1406,  1410,  1412,  1418,  1420,  1422,  1427,  1428,  1429,  1430,
    1431,  1432,  1433,  1439,  1440,  1441,  1442,  1446,  1447,  1451,
    1452,  1453,  1457,  1458,  1462,  1463,  1467,  1468,  1472,  1473,
    1474,  1475,  1479,  1490,  1491,  1492,  1493,  1494,  1495,  1497,
    1499,  1501,  1503,  1505,  1507,  1512,  1514,  1516,  1518,  1520,
    1522,  1524,  1526,  1528,  1530,  1532,  1534,  1536,  1543,  1549,
    1555,  1561,  1570,  1580,  1588,  1589,  1590,  1591,  1592,  1593,
    1594,  1595,  1600,  1601,  1605,  1609,  1612,  1617,  1621,  1624,
    1629,  1632,  1635,  1641,  1642,  1647,  1652,  1660,  1661,  1662,
    1663,  1664,  1665,  1666,  1667,  1668,  1670,  1672,  1674,  1676,
    1678,  1683,  1684,  1685,  1688,  1689,  1690,  1691,  1702,  1703,
    1707,  1708,  1709,  1713,  1714,  1715,  1723,  1724,  1725,  1726,
    1730,  1731,  1732,  1733,  1734,  1735,  1736,  1737,  1738,  1739,
    1743,  1751,  1752,  1756,  1757,  1758,  1759,  1760,  1761,  1762,
    1763,  1764,  1765,  1766,  1767,  1768,  1769,  1770,  1771,  1772,
    1773,  1774,  1775,  1776,  1777,  1778,  1782,  1783,  1784,  1785,
    1786,  1787,  1791,  1792,  1793,  1794,  1798,  1799,  1800,  1801,
    1806,  1807,  1808,  1809,  1810,  1811,  1812
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TIDENT", "INTLITERAL", "REALLITERAL",
  "IMAGLITERAL", "STRINGLITERAL", "CSTRINGLITERAL", "EXTERNCODE", "TALIGN",
  "TAS", "TATOMIC", "TBEGIN", "TBREAK", "TBY", "TCATCH", "TCLASS",
  "TCOBEGIN", "TCOFORALL", "TCONFIG", "TCONST", "TCONTINUE", "TCOMPLETE",
  "TDEFER", "TDELETE", "TDMAPPED", "TDO", "TDOMAIN", "TELSE", "TENUM",
  "TEXCEPT", "TEXPORT", "TEXTERN", "TFOR", "TFORALL", "TFORWARDING", "TIF",
  "TIN", "TINDEX", "TINLINE", "TINOUT", "TITER", "TLABEL", "TLAMBDA",
  "TLET", "TLOCAL", "TMINUSMINUS", "TMODULE", "TNEW", "TNIL", "TNOINIT",
  "TON", "TONLY", "TOTHERWISE", "TOUT", "TPARAM", "TPLUSPLUS", "TPRAGMA",
  "TPRIMITIVE", "TPRIVATE", "TPROC", "TPROTOTYPE", "TPUBLIC", "TRECORD",
  "TREDUCE", "TREF", "TREQUIRE", "TRETURN", "TSCAN", "TSELECT", "TSERIAL",
  "TSINGLE", "TSPARSE", "TSUBDOMAIN", "TSYNC", "TTHEN", "TTHROW",
  "TTHROWS", "TTRY", "TTRYBANG", "TTYPE", "TUNDERSCORE", "TUNION", "TUSE",
  "TVAR", "TWHEN", "TWHERE", "TWHILE", "TWITH", "TYIELD", "TZIP", "TALIAS",
  "TAND", "TASSIGN", "TASSIGNBAND", "TASSIGNBOR", "TASSIGNBXOR",
  "TASSIGNDIVIDE", "TASSIGNEXP", "TASSIGNLAND", "TASSIGNLOR",
  "TASSIGNMINUS", "TASSIGNMOD", "TASSIGNMULTIPLY", "TASSIGNPLUS",
  "TASSIGNSL", "TASSIGNSR", "TBAND", "TBNOT", "TBOR", "TBXOR", "TCOLON",
  "TCOMMA", "TDIVIDE", "TDOT", "TDOTDOT", "TDOTDOTDOT", "TEQUAL", "TEXP",
  "TGREATER", "TGREATEREQUAL", "THASH", "TLESS", "TLESSEQUAL", "TMINUS",
  "TMOD", "TNOT", "TNOTEQUAL", "TOR", "TPLUS", "TQUESTION", "TSEMI",
  "TSHIFTLEFT", "TSHIFTRIGHT", "TSTAR", "TSWAP", "TASSIGNREDUCE", "TIO",
  "TLCBR", "TRCBR", "TLP", "TRP", "TLSBR", "TRSBR", "TNOELSE", "TUPLUS",
  "TUMINUS", "$accept", "program", "toplevel_stmt_ls", "toplevel_stmt",
  "pragma_ls", "stmt", "module_decl_stmt", "access_control",
  "opt_prototype", "block_stmt", "stmt_ls", "only_ls", "opt_only_ls",
  "except_ls", "use_stmt", "require_stmt", "assignment_stmt", "opt_ident",
  "ident", "opt_ident_or_string", "do_stmt", "return_stmt",
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
  "opt_query_expr", "var_arg_expr", "opt_where_part",
  "type_alias_decl_stmt", "type_alias_decl_stmt_inner", "opt_init_type",
  "var_decl_stmt", "opt_config", "var_decl_stmt_inner_ls",
  "var_decl_stmt_inner", "tuple_var_decl_component",
  "tuple_var_decl_stmt_inner_ls", "opt_init_expr", "opt_type",
  "array_type", "opt_formal_array_elt_type", "formal_array_type",
  "opt_formal_type", "expr_ls", "simple_expr_ls", "tuple_component",
  "tuple_expr_ls", "opt_actual_ls", "actual_ls", "actual_expr",
  "ident_expr", "type_level_expr", "for_expr", "cond_expr", "nil_expr",
  "stmt_level_expr", "opt_task_intent_ls", "task_intent_clause",
  "task_intent_ls", "forall_intent_clause", "forall_intent_ls",
  "intent_expr", "io_expr", "new_expr", "let_expr", "expr", "opt_try_expr",
  "lhs_expr", "fun_expr", "call_expr", "dot_expr", "parenthesized_expr",
  "literal_expr", "assoc_expr_ls", "binary_op_expr", "unary_op_expr",
  "reduce_expr", "scan_expr", "reduce_scan_op_expr", YY_NULLPTR
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
     395,   396,   397,   398,   399,   400,   401,   402
};
# endif

#define YYPACT_NINF -769

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-769)))

#define YYTABLE_NINF -448

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -769,    64,  2856,  -769,   -17,  -769,  -769,  -769,  -769,  -769,
    -769,  4058,    59,   158,  -769,    59,  7896,   127,   158,    51,
    4058,  7896,  4058,    91,  -769,   309,   675,  6729,  7896,  6843,
    7896,    97,  -769,   158,  -769,    48,  7212,  7896,  7896,  -769,
    7896,  7896,   234,   165,   801,   913,  -769,  7326,  6387,  7896,
    7212,  7896,   237,   203,  4058,  7896,  8010,  8010,   158,  -769,
    7326,  7896,  7896,  -769,  -769,  7896,  -769,  -769,  9264,  7896,
    7896,  -769,  7896,  -769,  -769,  3212,  6039,  7326,  -769,  3917,
    -769,  -769,   194,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
     158,  -769,   158,   228,   191,  -769,  -769,  -769,   326,   232,
    -769,  -769,  -769,   240,   272,   269,   319,   320, 12596,  5766,
      83,   325,   327,  -769,  -769,  -769,  -769,  -769,  -769,   296,
    -769,  -769, 12596,   321,  4058,  -769,   328,  -769,   322,  7896,
    7896,  7896,  7896,  7896,  7326,  7326,   157,  -769,  -769,  -769,
    -769, 10889,   246,  -769,  -769,   158,   331,  -769,  -769,    -9,
   12596,   377,  6501,  -769,  -769,  -769,  -769,   158,   110,   158,
     330,    23, 10366, 10332,  -769,  -769,  -769, 10841,  9667,  6501,
    4058,   334,    29,    78,    74,  -769,  4058,  -769,  -769, 10517,
     530,   352, 10517,   530,  -769,  6501,    84,  -769,  -769,   158,
    -769,   182, 12596,  7896,  7896,  -769, 12596,   336, 10555,  -769,
   10517, 12596,   338,  6501,  -769, 12596, 11078,  -769,  -769, 11205,
    7054,  -769,  -769, 11278,   375,   361,   190, 11006, 10517, 11326,
     294,  1864,   530,   294,   530,   -35,  -769,  -769,  3353,     4,
    -769,  7896,  -769,    92,    98,  -769,    69, 11399,   -13,   487,
    -769,  -769,   451,   395,   370,  -769,  -769,  -769,    54,    48,
      48,    48,  -769,  7896,  7896,  7896,  7896,  7440,  7440,  7896,
    7896,  7896,  7896,  7896,  7896,    85,  9264,  7896,  7896,  7896,
    7896,  7896,  7896,  7896,  7896,  7896,  7896,  7896,  7896,  7896,
    7896,  7896,  6957,  6957,  6957,  6957,  6957,  6957,  6957,  6957,
    6957,  6957,  6957,  6957,  6957,  6957,  6957,  6957,  6501,  6501,
    7440,  7440,  5925,  -769,  -769,  3494,  -769, 11040, 11157, 11461,
      52,  7440,    23,   378,  -769,  7896,  -769,  7896,   419,  -769,
     372,   403,  -769,  -769,   387,   158,   491,  7326,  -769,  4199,
    7440,  -769,  4340,  7440,   384,  -769,    23,  8124,  7896,  -769,
    4058,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,   501,  7896,   390,  -769,    40,  -769,  -769,
      29,  -769,   421,   393,  -769,  8238,   442,  7896,    48,  -769,
    -769,  -769,   397,  -769,  -769,  7326,  -769, 12596, 12596,  -769,
      28,  -769,  6501,   399,  -769,   521,  -769,   521,  -769,  8238,
     430,  -769,  -769,  8124,  7896,  -769,  -769,  -769,  -769,  -769,
    7071,  -769,  9518,  6155,  -769,  6271,  -769,  7440,  5555,  3071,
     400,  7896,  5783,  -769,  -769,   158,  7326,   408,   411,   164,
      48,   204,   226,   238,   242, 10767,  2924,  2924,   306,  -769,
     306,  -769,   306,  7183,   265,   458,  1318,   352,   294,  -769,
    -769,  -769,  1864, 10919,   306,  6339,  6339,  2924,  6339,  6339,
     746,   294, 10919,   362,   746,   530,   530,   294,   416,   418,
     420,   427,   431,   432,   444,   450,   456,   457,   464,   469,
     470,   471,   473,   476,   409,   439,  -769,   306,  -769,   306,
     185,  -769,  -769,  -769,  -769,  -769,  -769,   158,   101,  -769,
   12658,   357,  8352,  7440,  8466,  7440,  7896,  7440,  2346,    59,
   11532,  -769,  -769, 12596, 11594,  6501,  -769,  6501,  -769,   395,
    7896,   102,  7896, 12596,    47, 10634,  7896, 12596,    10, 10483,
    5925,  -769,   479,   449,   484, 11665,   449,   486,   545, 11727,
    4058, 10696,  -769,   104,  -769,    62,  -769,   300,   448,    29,
      78,  5441,  -769,   493,  6615,  -769, 12596,  -769,  -769,  -769,
   12596,   480,    39,   481,  -769,    30,  -769,  -769,   273,   158,
     489,   490,  -769,  -769,  -769,  -769,  -769,  -769,    13,  2188,
    -769,  -769, 12596,  4058, 12596,  -769, 11798,   495,   516,   577,
     496,   536,    16,  -769,   581,  -769,  -769,  -769,  -769,  2675,
     297,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  5925,  -769,  7440,  7440,
    7896,   623, 11860,  7896,   626, 11931,   513,  9353,    23,    23,
    -769,  -769,  -769,  -769,   528, 10517,  -769,  9742,  4481,  -769,
    4622,  -769,  9804,  4763,  -769,    23,  4904,  -769,    23,   108,
    -769,  7896,  -769,  7896,  -769,  4058,  7896,  -769,  4058,   639,
     312,  -769,    29,   558,   605,  -769,  -769,  -769,    21,  -769,
    -769,   442,   529,    60,  -769,  -769,  -769,  5045,  7326,  -769,
    -769,  -769,   158,  -769,   560,   322,  -769,  -769,  -769,  5186,
     531,  5327,   532,  -769,  7896,  3635,   534,  1170,  -769,  7896,
     158,  -769,  -769,   300,  -769,  -769,  -769,   158,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  7896,   562,
     565,   540,   540,  -769,  -769,  -769,   115,   116, 11993,  8580,
    8694, 12064,  8808,  8922,  9036,  9150,  -769,  -769,  1067,  -769,
    4058,  7896, 12596,  7896, 12596,  4058,  7896, 12596,  -769,  7896,
   12596,  -769,  5925,  -769, 12126, 12596,  -769, 12596,   654,  4058,
    -769,   548,  7554,   125,  -769,   600,  -769,  -769,  7440,  1279,
    4058,  -769,    15,   549,  7896,  -769,  7896,  -769, 12596,  4058,
    7896,  -769, 12596,  4058, 12596,   -10,  -769,  3776,  -769,   519,
     525,   525,  -769,  2488,  -769, 12596,  -769,    68,  -769,  9605,
    1381,    40,  -769,  -769,  7896,  7896,  7896,  7896,  7896,  7896,
    7896,  7896,   552,  2100, 11727,  9879,  9941, 11727, 10016, 10078,
    -769,  7896,  4058,  -769,   558,    91,  7896,  7896,  5669,  -769,
    -769,   118,  7326,  -769,  -769,  7896,     8,  9401,  -769,   601,
     377,  -769,   322, 12596, 10153,  -769, 10215,  -769,  -769,  -769,
    -769,   615,  -769,  -769,   540,   540,   160, 12197, 12259, 12330,
   12392, 12463, 12525,  -769,  -769,  4058,  4058,  4058,  4058, 12596,
    -769,   125,  7668,    81,  -769,  -769, 12596, 12596,  -769,  -769,
    -769,  9150,  -769,  4058,  4058,  -769,   600,  -769,  -769,  -769,
    7896,  7896,  7896,  7896,  7896,  7896, 11727, 11727, 11727, 11727,
    -769,  -769,  -769,  -769,  -769,   404,  7440,  9312,   850, 11727,
   11727,    67,  9474,  -769,  -769,  -769,  -769,  -769,  7782,  -769
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       3,     0,     0,     1,     0,    83,   440,   441,   442,   443,
     444,     0,   392,    81,   162,   392,     0,   295,    81,     0,
       0,     0,     0,     0,   172,    81,    81,     0,     0,   294,
       0,     0,   182,     0,   178,     0,     0,     0,     0,   383,
       0,     0,     0,     0,   294,   294,   163,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   164,
       0,     0,     0,   492,   494,     0,   495,   496,   420,     0,
       0,   493,   490,    90,   491,     0,     0,     0,     4,     0,
       5,     9,    46,    10,    11,    12,    14,   352,    22,    13,
      91,    97,    15,    17,    16,    19,    20,    21,    18,    96,
       0,    94,     0,   412,     0,    98,    95,    99,     0,   424,
     408,   409,   355,   353,     0,     0,   413,   414,     0,   354,
       0,   425,   426,   427,   407,   357,   356,   410,   411,     0,
      39,    24,   363,     0,     0,   393,     0,    82,     0,     0,
       0,     0,     0,     0,     0,     0,   412,   424,   353,   413,
     414,   392,   354,   425,   426,     0,     0,    29,   136,     0,
     337,     0,   344,    85,    84,   183,   104,     0,   184,     0,
       0,     0,     0,     0,   295,   296,   103,     0,     0,   344,
       0,     0,     0,     0,     0,   297,     0,    87,    33,     0,
     478,   405,     0,   479,     7,   344,   296,    93,    92,   274,
     334,     0,   333,     0,     0,    88,   423,     0,     0,    36,
       0,   358,     0,   344,    37,   364,     0,   143,   139,     0,
     354,   143,   140,     0,   286,     0,     0,   333,     0,     0,
     481,   419,   477,   480,   476,     0,    48,    51,     0,     0,
     339,     0,   341,     0,     0,   340,     0,   333,     0,     0,
       6,    47,     0,   165,     0,   260,   259,   185,     0,     0,
       0,     0,    23,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   418,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   344,   344,
       0,     0,     0,    25,    26,     0,    27,     0,     0,     0,
       0,     0,     0,     0,    28,     0,    30,     0,   352,   350,
       0,   345,   346,   351,     0,     0,     0,     0,   113,     0,
       0,   112,     0,     0,     0,   119,     0,     0,    57,   100,
       0,   220,   227,   228,   229,   224,   226,   222,   225,   223,
     221,   231,   230,   129,     0,     0,    31,   235,   179,   301,
       0,   302,   304,     0,   313,     0,   307,     0,     0,    86,
      32,    34,     0,   184,   273,     0,    64,   421,   422,    89,
       0,    35,   344,     0,   150,   141,   137,   142,   138,     0,
     284,   281,    61,     0,    57,   106,    38,    50,    49,    52,
       0,   445,     0,     0,   436,     0,   438,     0,     0,     0,
       0,     0,     0,   449,     8,     0,     0,     0,     0,   253,
       0,     0,     0,     0,     0,   391,   473,   472,   475,   483,
     482,   487,   486,   469,   466,   467,   468,   416,   456,   435,
     434,   433,   417,   460,   471,   465,   463,   474,   464,   462,
     454,   459,   461,   470,   453,   457,   458,   455,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   485,   484,   489,   488,
     247,   244,   245,   246,   250,   251,   252,     0,     0,   395,
       0,     0,     0,     0,     0,     0,     0,     0,   447,   392,
     392,   109,   282,   338,     0,     0,   360,     0,   283,   165,
       0,     0,     0,   367,     0,     0,     0,   373,     0,     0,
       0,   120,   491,    60,     0,    53,    58,     0,   128,     0,
       0,     0,   359,     0,   236,     0,   243,   261,     0,   305,
       0,     0,   312,   408,     0,   299,   406,   298,   432,   336,
     335,     0,     0,     0,   361,     0,   144,   288,   408,     0,
       0,     0,   446,   415,   437,   342,   439,   343,     0,     0,
     448,   125,   377,     0,   451,   450,     0,     0,   166,     0,
       0,   176,     0,   173,   257,   254,   255,   258,   186,     0,
       0,   290,   289,   291,   293,    65,    72,    73,    74,    69,
      71,    79,    80,    67,    70,    68,    66,    76,    75,    77,
      78,   430,   431,   248,   249,   400,     0,   394,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     105,   348,   349,   347,     0,     0,   127,     0,     0,   111,
       0,   110,     0,     0,   117,     0,     0,   115,     0,     0,
     398,     0,   101,     0,   102,     0,     0,   131,     0,   133,
     242,   234,     0,   326,   262,   265,   264,   266,     0,   303,
     306,   307,     0,     0,   308,   309,   152,     0,     0,   151,
     154,   362,     0,   145,   148,     0,   285,    62,    63,     0,
       0,     0,     0,   126,     0,     0,     0,   294,   171,     0,
     174,   170,   256,   261,   217,   215,   196,   199,   197,   198,
     209,   200,   213,   205,   203,   216,   204,   202,   207,   212,
     214,   201,   206,   210,   211,   208,   218,   219,     0,   194,
       0,   232,   232,   192,   292,   396,   424,   424,     0,     0,
       0,     0,     0,     0,     0,     0,   108,   107,     0,   114,
       0,     0,   366,     0,   365,     0,     0,   372,   118,     0,
     371,   116,     0,   397,    55,    54,   130,   382,   132,     0,
     237,     0,     0,   307,   263,   279,   300,   317,     0,   447,
       0,   156,     0,     0,     0,   146,     0,   123,   379,     0,
       0,   121,   378,     0,   452,     0,    40,     0,   160,    81,
     294,   294,   158,   294,   168,   177,   175,     0,   195,     0,
       0,   235,   188,   189,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   294,   370,     0,     0,   376,     0,     0,
     399,     0,     0,   135,   326,   329,   330,   331,     0,   328,
     332,   408,   275,   239,   238,     0,     0,     0,   315,   408,
     157,   155,     0,   149,     0,   124,     0,   122,    42,    41,
     169,   267,   193,   194,   232,   232,     0,     0,     0,     0,
       0,     0,     0,   161,   159,     0,     0,     0,     0,    56,
     134,   307,   318,     0,   276,   278,   277,   280,   271,   272,
     180,     0,   147,     0,     0,   268,   279,   190,   191,   233,
       0,     0,     0,     0,     0,     0,   369,   368,   375,   374,
     241,   240,   320,   321,   323,   408,     0,   447,   408,   381,
     380,     0,     0,   322,   324,   269,   187,   270,   318,   325
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -769,  -769,  -769,    -1,  -635,  1905,  -769,  -769,  -769,  1887,
      -7,  -254,   301,   298,  -769,  -769,   271,   286,  2457,    -4,
    1610,  -764,  -636,   -42,  -769,  -769,  -769,   -14,  -769,  -769,
    -769,   483,  -769,    14,  -769,  -769,  -769,  -769,  -769,   542,
     181,   -50,  -769,  -769,  -769,     1,   930,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -108,  -593,  -711,  -769,  -106,
      49,  -769,  -355,  -769,  -769,     5,  -769,  -769,  -211,   -61,
    -769,  -169,  -183,  -769,  -111,  -769,   696,  -769,  -175,   348,
    -769,  -340,  -673,  -527,  -394,  -633,  -768,  -117,   -36,  -769,
      35,  -769,  -133,  -769,   211,   374,  -359,  -769,  -769,   956,
    -769,     2,  -769,  -769,  -236,  -769,  -523,  -769,  1006,  1221,
      -2,   140,   763,  -769,  1388,  1677,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -308
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,   237,    79,   538,    81,    82,   252,    83,
     238,   533,   537,   534,    84,    85,    86,   164,    87,   168,
     188,    88,    89,    90,    91,    92,    93,   636,    94,    95,
      96,   395,   566,   695,    97,    98,   562,   690,    99,   100,
     427,   707,   101,   102,   592,   593,   146,   181,   547,   104,
     105,   429,   713,   598,   740,   741,   364,   822,   368,   543,
     544,   545,   497,   599,   257,   678,   906,   936,   900,   200,
     895,   853,   856,   106,   225,   400,   107,   108,   184,   185,
     372,   373,   555,   376,   552,   923,   850,   783,   239,   159,
     243,   244,   330,   331,   332,   147,   110,   111,   112,   148,
     114,   134,   135,   498,   346,   659,   499,   115,   149,   150,
     206,   333,   152,   120,   153,   154,   123,   124,   248,   125,
     126,   127,   128,   129
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     118,    78,   197,   198,   501,   567,   742,   660,   786,   132,
     420,   201,   546,   171,   151,   242,   553,   138,   118,   160,
     118,   165,   374,   681,   226,   172,   173,   177,   178,   561,
     548,   823,     5,     5,   189,   190,   191,   653,   192,   193,
     568,   246,   186,  -242,   323,   202,   365,   208,   210,   211,
     186,     5,   215,   216,   219,   223,   334,     5,   227,   228,
     229,   490,   382,   230,     3,     5,   231,   232,   233,   374,
     234,   814,   813,   202,   648,   247,    48,   118,   491,   374,
     393,   492,  -153,   431,   432,   433,   434,     5,     5,  -310,
     507,   163,   899,   687,   536,   493,   494,   130,   788,   344,
     422,   329,   344,   745,   325,   407,   495,   417,  -310,   320,
     854,   369,   377,   449,  -153,   130,  -310,   410,   329,   926,
     430,   496,   130,   326,   924,   688,   -81,    14,   385,   710,
     868,   423,   118,   375,   329,    48,  -310,   132,   317,   318,
     319,   215,   202,   247,   411,   -81,  -310,   315,   133,   315,
     536,   785,   329,   322,   315,  -310,   711,   699,   344,   934,
    -310,     5,   315,   907,   908,   418,   450,   899,  -153,   315,
     370,   692,  -310,   418,    46,   484,   485,   870,   118,   689,
     375,  -242,   418,   157,   118,   594,   315,   378,   207,   182,
     375,  -310,   383,    59,   418,   182,   508,   814,   813,   935,
    -310,   387,   388,   672,   789,   413,   315,  -310,   155,   680,
    -310,   415,  -327,   419,   626,   385,   245,   670,   921,   554,
     595,   772,   501,   623,   308,   927,   309,   875,  -401,  -402,
     596,  -327,   162,   255,   414,  -327,   118,   409,   179,   412,
     416,   194,   852,   627,   646,   597,   671,   329,   329,   840,
     773,   624,   256,   439,   441,   600,   251,  -401,  -402,   563,
    -327,   435,   436,   437,   438,   440,   442,   443,   444,   445,
     446,   447,   448,   670,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     871,   266,   655,   658,   933,   385,   486,   488,  -429,   136,
    -429,   521,   909,   385,   156,   939,   195,   509,   487,   489,
     500,   212,     5,   118,   386,   546,   163,   378,   501,   510,
     266,   674,   402,   513,   559,   514,   524,   218,   222,   528,
     267,   329,   781,   490,   268,   202,   601,   523,   525,   378,
     527,   529,   700,   702,   213,   535,   535,   258,   539,   559,
     491,   378,   242,   492,   242,   378,   675,   559,   602,   267,
    -388,   310,   541,   268,  -385,   311,   676,   493,   494,  -429,
     603,  -429,  -384,   118,   604,   556,   109,   273,   495,   274,
     275,   677,   259,   560,   278,   109,  -287,  -428,   266,  -428,
     588,   285,   260,   496,   109,   858,   109,   118,   289,   290,
     291,   535,   535,   578,   262,  -287,   273,   263,   560,   275,
     378,   261,   590,   278,     5,   579,   560,   582,   273,   584,
     586,   275,   629,   851,   202,   278,   311,   267,   109,   744,
     859,   268,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   575,   109,
     577,  -389,  -390,   109,   641,   269,   329,  -387,   696,  -386,
     314,   315,   312,   324,   501,   327,   546,   275,   389,   399,
     270,   337,   271,   272,   273,   367,   274,   275,   276,   392,
     277,   278,   279,   280,   266,   282,   283,   284,   285,   631,
     286,   634,   288,   401,   424,   289,   290,   291,  -319,   425,
     523,   632,   527,   635,   539,   637,   582,   426,   109,   428,
     512,   638,   639,   515,   516,   683,   517,  -319,   645,   518,
     647,  -319,     5,   267,   652,   530,   163,   268,   500,   520,
     540,  -311,   542,   925,   549,   550,   554,   565,   118,   558,
    -296,   564,   928,   569,   583,   174,  -319,   589,   605,   247,
     606,   621,   607,   245,   109,   245,   266,    25,   196,   608,
     109,  -311,   661,   609,   610,    32,   270,  -181,   925,   272,
     273,  -311,   274,   275,   665,  -296,   611,   278,   706,   925,
    -311,   118,   612,   622,   285,  -296,  -181,  -311,   613,   614,
     679,   289,   290,   291,  -167,   267,   615,  -167,  -167,   268,
     167,   616,   617,   618,  -296,   619,  -311,  -167,   620,  -167,
    -167,   -59,   109,  -167,   439,   486,   662,  -167,   664,  -167,
     686,   697,   698,   691,   500,  -311,   440,   487,   748,   385,
     709,   751,  -311,  -167,   705,  -167,   708,  -167,  -167,  -314,
    -167,  -167,   273,  -167,   274,   275,   762,   712,   764,   278,
     749,   767,   792,   752,   770,   642,   285,   754,  -167,   774,
    -167,   775,  -167,   118,   777,   291,   118,   758,   779,  -314,
     782,   784,   794,   787,   808,   799,   803,  -352,     5,  -314,
     820,   821,   163,   842,   166,   118,   202,   855,  -314,   109,
     844,   862,   883,   905,   685,  -314,  -296,   798,   807,   802,
     644,   570,   804,   118,   397,   571,   793,   815,   833,  -167,
     335,   816,   874,   109,  -314,   876,   109,  -167,   817,   780,
     937,   849,   920,   931,   109,   176,   557,   891,   643,     0,
       0,  -296,     0,  -314,     0,     0,   819,     0,     0,     0,
    -314,  -296,     0,     0,     0,     0,     0,   762,   764,     0,
     767,   770,   798,   802,     0,     0,   167,     0,   834,   835,
    -296,   836,     0,   837,   838,   119,     0,   839,   197,   198,
     500,     0,   266,     0,   119,     0,     0,   118,     0,     0,
     118,     0,     0,   119,     0,   119,   857,   582,   118,     0,
       0,   894,   863,   109,   864,     0,     0,   118,   866,     0,
       0,   118,     0,     0,     0,   118,   409,     0,     0,     0,
       0,   267,   893,     0,     0,   268,     0,   119,     0,   220,
     220,   174,   834,   877,   878,   837,   879,   880,   881,   882,
       0,   922,     0,    25,   196,     0,     0,     0,   119,   889,
     118,    32,   119,  -181,   211,   215,   247,     0,     0,   -45,
     896,     0,     0,   897,   270,     0,   271,   272,   273,     0,
     274,   275,  -181,   -45,     0,   278,   922,     0,     0,     0,
       0,   625,   285,     0,     0,     0,     0,   922,     0,   289,
     290,   291,     0,   916,   917,   918,   919,     0,  -316,     0,
     118,     0,     0,     0,     0,     0,     0,   119,     0,   802,
       0,   929,   930,     0,     0,     0,     0,     0,   916,   917,
     918,   919,   929,   930,   109,     0,     0,     0,  -316,     0,
       0,     0,     0,     0,   932,   582,     0,     0,  -316,     0,
       0,     0,   103,   174,     0,     0,   802,  -316,     0,     0,
       0,   103,     0,   119,  -316,    25,   196,     0,     0,   119,
     103,     0,   103,    32,     0,  -181,     0,   109,   113,     0,
       0,   -44,     0,  -316,     0,     0,     0,   113,     0,     0,
       0,     0,     0,   743,  -181,   -44,   113,     0,   113,     0,
       0,     0,  -316,     0,   103,     0,     0,     0,     0,  -316,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   119,   746,   747,     0,   103,     0,     0,   116,   103,
     113,     0,     0,     0,     0,     0,     0,   116,     0,     0,
       0,     0,   109,     0,   109,     0,   116,   109,   116,     0,
     109,   113,     0,     0,     0,   113,     0,     0,     0,   109,
       0,     0,   109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     116,   109,     0,     0,   103,     0,     0,     0,   832,     0,
       0,     0,     0,   109,     0,   109,     0,     0,   119,   109,
       0,   116,     0,     0,  -167,   116,     0,  -167,  -167,     0,
     113,     0,     0,     0,     0,     0,     0,  -167,     0,  -167,
    -167,     0,   119,  -167,     0,   119,     0,  -167,     0,  -167,
     103,     0,     0,   119,     0,     0,   103,     0,     0,     0,
       0,     0,     0,  -167,     0,  -167,     0,  -167,  -167,     0,
    -167,  -167,     0,  -167,   109,     0,   113,     0,     0,   109,
     116,     0,   113,     0,     0,     0,     0,     0,  -167,     0,
    -167,     0,  -167,   109,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   109,     0,     0,     0,   103,     0,
       0,     0,     0,   109,     0,     0,     0,   109,     0,     0,
       0,   109,   119,     0,     0,     0,   116,    14,     0,     0,
      17,     0,   116,     0,   113,     0,     0,     0,     0,  -167,
      24,     0,    25,   809,     0,     0,    29,  -167,     0,     0,
      32,     0,  -181,     0,     0,     0,   109,     0,     0,     0,
       0,     0,     0,   117,     0,     0,     0,     0,    42,     0,
     810,  -181,   117,   811,    46,     0,     0,     0,     0,     0,
       0,   117,     0,   117,   116,   103,     0,     0,     0,     0,
       0,    58,     0,    59,     0,     0,     0,     0,     0,   109,
     109,   109,   109,     0,     0,     0,     0,     0,     0,   103,
       0,   113,   103,     0,     0,   117,     0,   109,   109,     0,
     103,     0,     5,     6,     7,     8,     9,    10,     0,     0,
       0,   139,     0,     0,     0,   113,   117,     0,   113,     0,
     117,     0,    73,   119,     0,     0,   113,    23,     0,     0,
     812,     0,     0,   140,   141,     0,   142,     0,    31,     0,
       0,   116,     0,    34,    35,     0,    37,     0,    38,    39,
       0,     0,     0,     0,     0,     0,    41,     0,    43,     0,
       0,     0,     0,     0,   266,   116,   119,     0,   116,   103,
       0,    51,    52,    53,   143,   117,   116,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   113,     0,     0,     0,     0,
       0,     0,     0,   267,     5,     0,     0,   268,    65,     0,
     121,   714,     0,     0,     0,     0,   715,     0,     0,   121,
       0,   117,     0,     0,     0,     0,    70,   117,   121,     0,
     121,   119,     0,   119,     0,     0,   119,     0,   144,   119,
      76,     0,   551,     0,     0,   116,   270,     0,   119,     0,
     273,   119,   274,   275,     0,     0,     0,   278,     0,     0,
       0,     0,   121,     0,   285,     0,     0,     0,     0,     0,
     119,   289,   290,   291,     0,     0,     0,     0,     0,   117,
       0,     0,   119,   121,   119,     0,     0,   121,   119,     0,
     103,     0,     0,     0,     0,   351,   352,   353,   354,   355,
     356,     0,     0,   357,   358,   359,   360,   361,   362,   716,
     717,   718,   719,     0,     0,   720,   113,     0,     0,   721,
     722,   723,   724,   725,   726,   727,   728,   729,   730,   731,
       0,   732,     0,   103,   733,   734,   735,   736,     0,   737,
       0,     0,   121,   119,     0,     0,     0,     0,   119,     0,
       0,     0,     0,     0,     0,     0,   117,     0,     0,   113,
       0,     0,   119,     0,     0,     0,   116,     0,     0,     0,
       0,     0,     0,   119,     0,     0,     0,     0,     0,     0,
     117,     0,   119,   117,     0,     0,   119,     0,   121,     0,
     119,   117,     0,     0,   121,     0,     0,     0,   103,     0,
     103,     0,     0,   103,     0,     0,   103,     0,     0,   116,
       0,     0,     0,     0,     0,   103,     0,     0,   103,     0,
       0,     0,     0,     0,   113,   119,   113,     0,     0,   113,
       0,     0,   113,     0,     0,     0,     0,   103,     0,     0,
       0,   113,     0,     0,   113,     0,   121,     0,     0,   103,
       0,   103,     0,     0,     0,   103,     0,     0,     0,     0,
     117,     0,     0,   113,     0,     0,     0,     0,   119,   119,
     119,   119,     0,     0,   116,   113,   116,   113,     0,   116,
     209,   113,   116,     0,     0,     0,   119,   119,     0,     0,
       0,   116,     0,     0,   116,     0,     0,     0,     0,   122,
       0,     0,     0,     0,     0,     0,     0,     0,   122,     0,
     103,     0,     0,   116,     0,   103,     0,   122,     0,   122,
       0,     0,     0,   121,     0,   116,     0,   116,     0,   103,
       0,   116,     0,     0,     0,     0,   113,     0,     0,     0,
     103,   113,     0,     0,     0,     0,     0,   121,     0,   103,
     121,   122,     0,   103,     0,   113,     0,   103,   121,     0,
       0,     0,     0,     0,     0,     0,   113,     0,     0,     0,
       0,     0,   122,     0,     0,   113,   122,     0,     0,   113,
       0,   117,     0,   113,     0,     0,   116,     0,     0,     0,
       0,   116,   103,     0,     0,     0,     0,     0,     0,     0,
       0,   338,   341,   345,     0,   116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   116,     0,   113,   380,
       0,     0,   381,     0,   117,   116,     0,   121,     0,   116,
       0,   122,     0,   116,     0,   103,   103,   103,   103,     0,
     391,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,   103,     0,     0,     0,   405,     0,
       0,   113,   113,   113,   113,     0,     0,     0,   116,     0,
       0,     0,     0,     0,     0,     0,     0,   122,     0,   113,
     113,     0,     0,   122,     0,     0,     0,     0,     0,   117,
       0,   117,     0,     0,   117,     0,     0,   117,     0,     0,
       0,     0,     0,     0,     0,     0,   117,     0,     0,   117,
     266,   116,   116,   116,   116,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,   117,   116,
     116,     0,     0,     0,     0,   122,   131,     0,     0,     0,
     117,     0,   117,   187,     0,   158,   117,   161,   121,   267,
       0,     0,   511,   268,     0,     0,     0,   187,     0,     0,
       0,     0,     0,   217,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   531,     0,     0,   214,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,   270,     0,   271,   272,   273,     0,   274,   275,
      80,   117,     0,   278,   250,     0,   117,     0,     0,   284,
     285,     0,   122,     0,   288,     0,     0,   289,   290,   291,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   117,     0,     0,     0,     0,   122,     0,     0,   122,
     117,     0,     0,     0,   117,   316,     0,   122,   117,     0,
       0,     0,     0,     0,     0,     0,   121,     0,   121,   313,
       0,   121,     0,     0,   121,     0,     0,     0,     0,     0,
       0,     0,     0,   121,     0,     0,   121,     0,   187,   187,
     187,     0,     0,   117,     0,   363,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,   187,     0,     0,   187,
       0,     0,     0,     0,     0,   366,     0,   121,     0,   121,
       0,   379,     0,   121,     0,     0,   122,   187,     0,     0,
       0,     0,     0,     0,     0,     0,   117,   117,   117,   117,
       0,     0,     0,     0,     0,   187,     0,    14,     0,     0,
      17,     0,     0,     0,   117,   117,     0,     0,     0,     0,
      24,     0,    25,   809,   649,   651,    29,     0,   654,   657,
      32,     0,  -181,    80,     0,     0,     0,     0,   121,     0,
       0,     0,     0,   121,     0,     0,     0,     0,    42,     0,
     810,  -181,     0,   811,    46,     0,     0,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   121,     0,
       0,    58,     0,    59,     0,     0,     0,   121,     0,     0,
       0,   121,     0,     0,     0,   121,     0,     0,   264,     0,
       0,     0,     0,   265,     0,     0,     0,     0,     0,   187,
       0,     0,     0,     0,   266,     0,     0,   122,     0,     0,
      80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,    73,   187,     0,     0,     0,     0,     0,     0,
     884,     0,     0,     0,   379,     0,     0,   379,   756,   757,
       0,     0,     0,   267,     0,   759,     0,   268,     0,     0,
     122,     0,     0,     0,     0,   768,     0,     0,   771,     0,
       0,     0,     0,   121,   121,   121,   121,   344,     0,     0,
       0,   269,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,   121,     0,     0,     0,   270,     0,   271,   272,
     273,     0,   274,   275,   276,     0,   277,   278,   279,   280,
     281,   282,   283,   284,   285,     0,   286,   287,   288,     0,
       0,   289,   290,   291,   581,   122,     0,   122,     0,     0,
     122,     0,   701,   122,     0,     0,     0,     0,     0,     0,
       0,     0,   122,     0,     0,   122,     0,     0,     0,     5,
       6,     7,     8,     9,    10,     0,     0,     0,   139,     0,
       0,     0,     0,     0,   122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,     0,   122,     0,   122,     0,
     140,   141,   122,   142,     0,    31,     0,     0,     0,     0,
      34,    35,     0,    37,     0,    38,    39,     0,     0,     0,
       0,     0,   861,    41,     0,    43,     0,     0,     0,     0,
       0,   187,   187,     0,     0,   187,   187,     0,    51,    52,
      53,   143,     0,     0,     0,     0,     0,     0,   669,     0,
       0,     0,     0,     0,     0,     0,     0,   122,     0,     0,
       0,     0,   122,     0,     0,   667,     0,     0,     0,     0,
       0,     0,   693,     0,     0,    65,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   122,     0,     0,
     137,     0,     0,    70,     0,   137,   122,     0,     0,     0,
     122,     0,   137,   137,   122,     0,     0,    76,   703,   145,
     180,     0,   183,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,     0,     0,    17,     0,
       0,     0,     0,     0,     0,   224,     0,     0,    24,   122,
      25,   809,     0,     0,    29,   187,   187,     0,    32,     0,
    -181,     0,   187,     0,   363,     0,     0,     0,     0,   363,
       0,     0,   187,     0,     0,   187,   249,     0,   810,  -181,
       0,   811,    46,   379,     0,   379,     0,   253,   379,   254,
       0,   379,   122,   122,   122,   122,     0,     0,     0,    58,
     776,    59,     0,   778,     0,     0,     0,     0,     0,     0,
     122,   122,   795,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   791,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   797,     0,   801,     0,     0,     0,
      80,     0,   224,     0,     0,     0,     0,     0,     0,   328,
      73,     0,     0,     0,   224,     0,   336,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   328,     0,     0,   371,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   328,   137,     0,     0,   384,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     328,     0,     0,     0,     0,     0,     0,     0,     5,   187,
       0,     0,     0,     0,   843,   714,     0,     0,     0,     0,
     715,     0,     0,     0,     0,   860,     0,     0,     0,     0,
       0,     0,     0,     0,   865,     0,     0,     0,   867,     0,
       0,     0,    80,     0,     0,   183,   183,   183,   183,     0,
       0,     0,   363,   363,     0,   363,   363,     0,     0,     0,
       0,     0,   451,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   898,     0,     0,     0,   890,     0,   902,
       0,   363,     0,   363,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   328,   328,     0,     0,   351,
     352,   353,   354,   355,   356,     0,     0,   357,   358,   359,
     360,   361,   362,   716,   717,   718,   719,     0,     0,   720,
       0,     0,   519,   721,   722,   723,   724,   725,   726,   727,
     728,   729,   730,   731,     0,   732,     0,     0,   733,   734,
     735,   736,     0,   737,     0,     0,   738,     0,   898,     0,
       0,     0,     0,     0,     0,     0,     0,   371,     0,     0,
       0,     0,     0,     0,     0,   183,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   328,
       0,     0,     0,     0,     0,     0,    -2,     4,     0,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    11,    12,
      13,     0,     0,    14,    15,    16,    17,  -294,    18,    19,
      20,    21,   587,    22,    23,   591,    24,   183,    25,    26,
      27,    28,    29,    30,     0,    31,    32,     0,  -181,    33,
      34,    35,    36,    37,   -43,    38,    39,     0,    40,     0,
       0,     0,  -294,    41,    42,    43,    44,  -181,   -43,    45,
      46,     0,  -294,    47,    48,     0,    49,    50,    51,    52,
      53,    54,     0,    55,     0,    56,    57,    58,     0,    59,
      60,  -294,     0,     0,    61,     0,    62,     0,     0,    63,
     266,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    64,    65,    66,    67,     0,     0,
       0,     0,    68,     0,   328,     0,     0,     0,     0,     0,
       0,    69,     0,    70,     0,    71,    72,     0,    73,   267,
       0,    74,     0,   268,     0,    75,     0,    76,     0,    77,
       0,     0,   673,     0,     0,     0,   371,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   269,     0,     0,
       0,     0,   694,     0,     0,     0,   224,     0,     0,     0,
       0,     0,   270,     0,   271,   272,   273,     0,   274,   275,
     276,     0,   277,   278,   279,   280,     0,   282,   283,   284,
     285,     0,   286,   287,   288,     0,   739,   289,   290,   291,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     4,     0,     5,     6,     7,     8,     9,    10,
       0,  -447,     0,    11,    12,    13,  -447,     0,    14,    15,
      16,    17,  -294,    18,    19,    20,    21,  -447,    22,    23,
    -447,    24,     0,    25,    26,    27,    28,    29,    30,     0,
      31,    32,     0,  -181,    33,    34,    35,    36,    37,   -43,
      38,    39,     0,    40,     0,     0,     0,  -294,    41,   371,
      43,    44,  -181,   -43,    45,    46,  -447,  -294,    47,    48,
    -447,    49,    50,    51,    52,    53,    54,     0,    55,   694,
      56,    57,    58,     0,    59,    60,  -294,     0,     0,    61,
       0,    62,     0,     0,  -447,     0,     0,   591,     0,     0,
       0,     0,     0,     0,   818,     0,     0,     0,     0,  -447,
      65,  -447,  -447,  -447,  -447,  -447,  -447,  -447,     0,  -447,
    -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,    70,  -447,
    -447,  -447,     0,    73,  -447,  -447,  -447,     0,     0,     0,
      75,  -447,    76,   235,    77,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    11,    12,    13,     0,     0,    14,
      15,    16,    17,  -294,    18,    19,    20,    21,     0,    22,
      23,     0,    24,     0,    25,    26,    27,    28,    29,    30,
       0,    31,    32,     0,  -181,    33,    34,    35,    36,    37,
     -43,    38,    39,     0,    40,     0,   137,     0,  -294,    41,
      42,    43,    44,  -181,   -43,    45,    46,   873,  -294,    47,
      48,     0,    49,    50,    51,    52,    53,    54,     0,    55,
       0,    56,    57,    58,     0,    59,    60,  -294,     0,     0,
      61,     0,    62,     0,     0,    63,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      64,    65,    66,    67,     0,     0,     0,     0,    68,     0,
       0,     0,     0,     0,     0,     0,     0,    69,     0,    70,
       0,    71,    72,   199,    73,     0,     0,    74,     0,     0,
       0,    75,   236,    76,     4,    77,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    11,    12,    13,     0,     0,
      14,    15,    16,    17,  -294,    18,    19,    20,    21,     0,
      22,    23,     0,    24,     0,    25,    26,    27,    28,    29,
      30,     0,    31,    32,     0,  -181,    33,    34,    35,    36,
      37,   -43,    38,    39,     0,    40,     0,     0,     0,  -294,
      41,    42,    43,    44,  -181,   -43,    45,    46,     0,  -294,
      47,    48,     0,    49,    50,    51,    52,    53,    54,     0,
      55,     0,    56,    57,    58,     0,    59,    60,  -294,     0,
       0,    61,     0,    62,     0,     0,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    64,    65,    66,    67,     0,     0,     0,     0,    68,
       0,     0,     0,     0,     0,     0,     0,     0,    69,     0,
      70,     0,    71,    72,     0,    73,     0,     0,    74,     0,
       0,     0,    75,   408,    76,   235,    77,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    11,    12,    13,     0,
       0,    14,    15,    16,    17,  -294,    18,    19,    20,    21,
       0,    22,    23,     0,    24,     0,    25,    26,    27,    28,
      29,    30,     0,    31,    32,     0,  -181,    33,    34,    35,
      36,    37,   -43,    38,    39,     0,    40,     0,     0,     0,
    -294,    41,    42,    43,    44,  -181,   -43,    45,    46,     0,
    -294,    47,    48,     0,    49,    50,    51,    52,    53,    54,
       0,    55,     0,    56,    57,    58,     0,    59,    60,  -294,
       0,     0,    61,     0,    62,     0,     0,    63,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    64,    65,    66,    67,     0,     0,     0,     0,
      68,     0,     0,     0,     0,     0,     0,     0,     0,    69,
       0,    70,     0,    71,    72,     0,    73,     0,     0,    74,
       0,     0,     0,    75,   236,    76,   805,    77,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    11,    12,    13,
       0,     0,    14,    15,    16,    17,  -294,    18,    19,    20,
      21,     0,    22,    23,     0,    24,     0,    25,    26,    27,
      28,    29,    30,     0,    31,    32,     0,  -181,    33,    34,
      35,    36,    37,   -43,    38,    39,     0,    40,     0,     0,
       0,  -294,    41,    42,    43,    44,  -181,   -43,    45,    46,
       0,  -294,    47,    48,     0,    49,    50,    51,    52,    53,
      54,     0,    55,     0,    56,    57,    58,     0,    59,    60,
    -294,     0,     0,    61,     0,    62,     0,     0,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    64,    65,    66,    67,     0,     0,     0,
       0,    68,     0,     0,     0,     0,     0,     0,     0,     0,
      69,     0,    70,     0,    71,    72,     0,    73,     0,     0,
      74,     0,     0,     0,    75,   806,    76,     4,    77,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    11,    12,
      13,     0,     0,    14,    15,    16,    17,  -294,    18,    19,
      20,    21,     0,    22,    23,     0,    24,     0,    25,    26,
      27,    28,    29,    30,     0,    31,    32,     0,  -181,    33,
      34,    35,    36,    37,   -43,    38,    39,     0,    40,     0,
       0,     0,  -294,    41,    42,    43,    44,  -181,   -43,    45,
      46,     0,  -294,    47,    48,     0,    49,    50,    51,    52,
      53,    54,     0,    55,     0,    56,    57,    58,     0,    59,
      60,  -294,     0,     0,    61,     0,    62,     0,     0,    63,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    64,    65,    66,    67,     0,     0,
       0,     0,    68,     0,     0,     0,     0,     0,     0,     0,
       0,    69,     0,    70,     0,    71,    72,     0,    73,     0,
       0,    74,     0,     0,     0,    75,   869,    76,     4,    77,
       5,     6,     7,     8,     9,    10,     0,     0,     0,    11,
      12,    13,     0,     0,    14,    15,    16,    17,  -294,    18,
      19,    20,    21,     0,    22,    23,     0,    24,     0,    25,
      26,    27,    28,    29,    30,     0,    31,    32,     0,  -181,
      33,    34,    35,    36,    37,   -43,    38,    39,     0,    40,
       0,     0,     0,  -294,    41,   249,    43,    44,  -181,   -43,
      45,    46,     0,  -294,    47,    48,     0,    49,    50,    51,
      52,    53,    54,     0,    55,     0,    56,    57,    58,     0,
      59,    60,  -294,     0,     0,    61,     0,    62,     0,     0,
      63,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    64,    65,    66,    67,     0,
       0,     0,     0,    68,     0,     0,     0,     0,     0,     0,
       0,     0,    69,     0,    70,     0,    71,    72,     0,    73,
       0,     0,    74,     0,     0,     0,    75,     0,    76,     4,
      77,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      11,    12,    13,     0,     0,    14,    15,    16,    17,  -294,
      18,    19,    20,    21,     0,    22,    23,     0,    24,     0,
      25,    26,    27,    28,    29,    30,     0,    31,    32,     0,
    -181,    33,    34,    35,    36,    37,   -43,    38,    39,     0,
      40,     0,     0,     0,  -294,    41,     0,    43,    44,  -181,
     -43,    45,    46,     0,  -294,    47,    48,     0,    49,    50,
      51,    52,    53,    54,     0,    55,     0,    56,    57,    58,
       0,    59,    60,  -294,     0,     0,    61,     0,    62,     0,
       0,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    64,    65,    66,    67,
       0,     0,     0,     0,    68,     0,     0,     0,     0,     0,
       0,     0,     0,    69,     0,    70,     0,    71,    72,     0,
      73,     0,     0,    74,     0,     0,     0,    75,     0,    76,
       4,    77,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    11,    12,    13,     0,     0,    14,    15,    16,    17,
    -294,    18,    19,    20,    21,     0,    22,    23,     0,    24,
       0,    25,    26,    27,    28,    29,   522,     0,    31,    32,
       0,  -181,    33,    34,    35,    36,    37,   -43,    38,    39,
       0,    40,     0,     0,     0,  -294,    41,     0,    43,    44,
    -181,   -43,    45,    46,     0,  -294,    47,    48,     0,    49,
      50,    51,    52,    53,    54,     0,    55,     0,    56,    57,
      58,     0,    59,    60,  -294,     0,     0,    61,     0,    62,
       0,     0,    63,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    64,    65,    66,
      67,     0,     0,     0,     0,    68,     0,     0,     0,     0,
       0,     0,     0,     0,    69,     0,    70,     0,    71,    72,
       0,    73,     0,     0,    74,     0,     0,     0,    75,     0,
      76,     4,    77,     5,     6,     7,     8,     9,    10,     0,
       0,     0,    11,    12,    13,     0,     0,    14,    15,    16,
      17,  -294,    18,    19,    20,    21,     0,    22,    23,     0,
      24,     0,    25,    26,    27,    28,    29,   526,     0,    31,
      32,     0,  -181,    33,    34,    35,    36,    37,   -43,    38,
      39,     0,    40,     0,     0,     0,  -294,    41,     0,    43,
      44,  -181,   -43,    45,    46,     0,  -294,    47,    48,     0,
      49,    50,    51,    52,    53,    54,     0,    55,     0,    56,
      57,    58,     0,    59,    60,  -294,     0,     0,    61,     0,
      62,     0,     0,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    64,    65,
      66,    67,     0,     0,     0,     0,    68,     0,     0,     0,
       0,     0,     0,     0,     0,    69,     0,    70,     0,    71,
      72,     0,    73,     0,     0,    74,     0,     0,     0,    75,
       0,    76,     4,    77,     5,     6,     7,     8,     9,    10,
       0,     0,     0,    11,    12,    13,     0,     0,    14,    15,
      16,    17,  -294,    18,    19,    20,    21,     0,    22,    23,
       0,    24,     0,    25,    26,    27,    28,    29,   761,     0,
      31,    32,     0,  -181,    33,    34,    35,    36,    37,   -43,
      38,    39,     0,    40,     0,     0,     0,  -294,    41,     0,
      43,    44,  -181,   -43,    45,    46,     0,  -294,    47,    48,
       0,    49,    50,    51,    52,    53,    54,     0,    55,     0,
      56,    57,    58,     0,    59,    60,  -294,     0,     0,    61,
       0,    62,     0,     0,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    64,
      65,    66,    67,     0,     0,     0,     0,    68,     0,     0,
       0,     0,     0,     0,     0,     0,    69,     0,    70,     0,
      71,    72,     0,    73,     0,     0,    74,     0,     0,     0,
      75,     0,    76,     4,    77,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    11,    12,    13,     0,     0,    14,
      15,    16,    17,  -294,    18,    19,    20,    21,     0,    22,
      23,     0,    24,     0,    25,    26,    27,    28,    29,   763,
       0,    31,    32,     0,  -181,    33,    34,    35,    36,    37,
     -43,    38,    39,     0,    40,     0,     0,     0,  -294,    41,
       0,    43,    44,  -181,   -43,    45,    46,     0,  -294,    47,
      48,     0,    49,    50,    51,    52,    53,    54,     0,    55,
       0,    56,    57,    58,     0,    59,    60,  -294,     0,     0,
      61,     0,    62,     0,     0,    63,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      64,    65,    66,    67,     0,     0,     0,     0,    68,     0,
       0,     0,     0,     0,     0,     0,     0,    69,     0,    70,
       0,    71,    72,     0,    73,     0,     0,    74,     0,     0,
       0,    75,     0,    76,     4,    77,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    11,    12,    13,     0,     0,
      14,    15,    16,    17,  -294,    18,    19,    20,    21,     0,
      22,    23,     0,    24,     0,    25,    26,    27,    28,    29,
     766,     0,    31,    32,     0,  -181,    33,    34,    35,    36,
      37,   -43,    38,    39,     0,    40,     0,     0,     0,  -294,
      41,     0,    43,    44,  -181,   -43,    45,    46,     0,  -294,
      47,    48,     0,    49,    50,    51,    52,    53,    54,     0,
      55,     0,    56,    57,    58,     0,    59,    60,  -294,     0,
       0,    61,     0,    62,     0,     0,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    64,    65,    66,    67,     0,     0,     0,     0,    68,
       0,     0,     0,     0,     0,     0,     0,     0,    69,     0,
      70,     0,    71,    72,     0,    73,     0,     0,    74,     0,
       0,     0,    75,     0,    76,     4,    77,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    11,    12,    13,     0,
       0,    14,    15,    16,    17,  -294,    18,    19,    20,    21,
       0,    22,    23,     0,    24,     0,    25,    26,    27,    28,
      29,   769,     0,    31,    32,     0,  -181,    33,    34,    35,
      36,    37,   -43,    38,    39,     0,    40,     0,     0,     0,
    -294,    41,     0,    43,    44,  -181,   -43,    45,    46,     0,
    -294,    47,    48,     0,    49,    50,    51,    52,    53,    54,
       0,    55,     0,    56,    57,    58,     0,    59,    60,  -294,
       0,     0,    61,     0,    62,     0,     0,    63,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    64,    65,    66,    67,     0,     0,     0,     0,
      68,     0,     0,     0,     0,     0,     0,     0,     0,    69,
       0,    70,     0,    71,    72,     0,    73,     0,     0,    74,
       0,     0,     0,    75,     0,    76,     4,    77,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    11,    12,    13,
       0,     0,    14,    15,    16,    17,  -294,    18,    19,    20,
      21,     0,   790,    23,     0,    24,     0,    25,    26,    27,
      28,    29,    30,     0,    31,    32,     0,  -181,    33,    34,
      35,    36,    37,   -43,    38,    39,     0,    40,     0,     0,
       0,  -294,    41,     0,    43,    44,  -181,   -43,    45,    46,
       0,  -294,    47,    48,     0,    49,    50,    51,    52,    53,
      54,     0,    55,     0,    56,    57,    58,     0,    59,    60,
    -294,     0,     0,    61,     0,    62,     0,     0,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    64,    65,    66,    67,     0,     0,     0,
       0,    68,     0,     0,     0,     0,     0,     0,     0,     0,
      69,     0,    70,     0,    71,    72,     0,    73,     0,     0,
      74,     0,     0,     0,    75,     0,    76,     4,    77,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    11,    12,
      13,     0,     0,    14,    15,    16,    17,  -294,    18,    19,
      20,    21,     0,    22,    23,     0,    24,     0,    25,    26,
      27,    28,    29,   796,     0,    31,    32,     0,  -181,    33,
      34,    35,    36,    37,   -43,    38,    39,     0,    40,     0,
       0,     0,  -294,    41,     0,    43,    44,  -181,   -43,    45,
      46,     0,  -294,    47,    48,     0,    49,    50,    51,    52,
      53,    54,     0,    55,     0,    56,    57,    58,     0,    59,
      60,  -294,     0,     0,    61,     0,    62,     0,     0,    63,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    64,    65,    66,    67,     0,     0,
       0,     0,    68,     0,     0,     0,     0,     0,     0,     0,
       0,    69,     0,    70,     0,    71,    72,     0,    73,     0,
       0,    74,     0,     0,     0,    75,     0,    76,     4,    77,
       5,     6,     7,     8,     9,    10,     0,     0,     0,    11,
      12,    13,     0,     0,    14,    15,    16,    17,  -294,    18,
      19,    20,    21,     0,    22,    23,     0,    24,     0,    25,
      26,    27,    28,    29,   800,     0,    31,    32,     0,  -181,
      33,    34,    35,    36,    37,   -43,    38,    39,     0,    40,
       0,     0,     0,  -294,    41,     0,    43,    44,  -181,   -43,
      45,    46,     0,  -294,    47,    48,     0,    49,    50,    51,
      52,    53,    54,     0,    55,     0,    56,    57,    58,     0,
      59,    60,  -294,     0,     0,    61,     0,    62,     0,     0,
      63,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    64,    65,    66,    67,     0,
       0,     0,   682,    68,     5,     6,     7,     8,     9,    10,
       0,     0,    69,   139,    70,     0,    71,    72,     0,    73,
       0,     0,    74,     0,     0,     0,    75,     0,    76,    23,
      77,     0,     0,     0,     0,   140,   141,     0,   142,     0,
      31,     0,     0,     0,     0,    34,    35,     0,    37,     0,
      38,    39,     0,     0,     0,     0,     0,     0,    41,     0,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    51,    52,    53,   143,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    64,
      65,    66,    67,     0,     0,     0,     0,    68,     5,     6,
       7,     8,     9,    10,     0,     0,    69,   139,    70,     0,
      71,    72,   199,     0,     0,     0,    74,     0,     0,     0,
     144,     0,    76,    23,   145,     0,     0,     0,     0,   140,
     141,     0,   142,     0,    31,     0,     0,     0,     0,    34,
      35,     0,    37,     0,    38,    39,     0,     0,     0,     0,
       0,     0,    41,     0,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,    52,    53,
     143,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    64,    65,    66,    67,     0,     0,     0,
       0,    68,     5,     6,     7,     8,     9,    10,     0,     0,
      69,   139,    70,     0,    71,    72,   199,     0,     0,     0,
      74,     0,     0,     0,   144,     0,    76,    23,   145,   580,
       0,     0,     0,   140,   141,     0,   142,     0,    31,     0,
       0,     0,     0,    34,    35,     0,    37,     0,    38,    39,
       0,     0,     0,     0,     0,     0,    41,     0,    43,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    51,    52,    53,   143,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    63,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    64,    65,    66,
      67,     0,     0,     0,     0,    68,     5,     6,     7,     8,
       9,    10,     0,     0,    69,   139,    70,     0,    71,    72,
     199,     0,     0,     0,    74,     0,     0,     0,   144,     0,
      76,    23,   145,   892,     0,     0,     0,   140,   141,     0,
     142,     0,    31,     0,     0,     0,     0,    34,    35,     0,
      37,     0,    38,    39,     0,     0,     0,     0,     0,     0,
      41,     0,    43,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,    52,    53,   143,     0,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,     0,     0,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    64,    65,    66,    67,     0,     0,     0,     0,    68,
       0,     0,   306,   307,  -403,     0,     0,  -428,    69,  -428,
      70,     0,    71,    72,     0,     0,     0,     0,    74,     0,
       0,     0,   144,     0,    76,     0,   145,   585,     5,     6,
       7,     8,     9,    10,     0,     0,     0,   139,     0,     0,
       0,     0,     0,     0,     0,     0,   490,     0,     0,     0,
       0,     0,     0,    23,     0,     0,     0,     0,     0,   140,
     141,     0,   142,   491,    31,     0,   492,     0,     0,    34,
      35,     0,    37,     0,    38,    39,     0,     0,     0,     0,
     493,   494,    41,     0,    43,     0,     0,     0,     0,     0,
       0,   495,     0,     0,     0,     0,     0,    51,    52,    53,
     143,     0,     0,     0,     0,     0,   496,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    64,    65,    66,    67,     0,     0,     0,
       0,    68,     5,     6,     7,     8,     9,    10,     0,     0,
      69,   139,    70,     0,    71,    72,     0,     0,     0,     0,
      74,     0,     0,     0,   144,     0,    76,    23,   145,     0,
       0,     0,     0,   140,   141,     0,   142,     0,    31,     0,
       0,     0,     0,    34,    35,     0,    37,     0,    38,    39,
       0,     0,     0,     0,     0,     0,    41,     0,    43,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    51,    52,    53,   143,     0,     0,     0,   203,   204,
       0,   240,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    63,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    64,    65,    66,
      67,     0,     0,     0,     0,    68,   241,     0,     5,     6,
       7,     8,     9,    10,    69,     0,    70,   139,    71,    72,
     199,     0,     0,     0,    74,     0,     0,     0,   144,     0,
      76,     0,   145,    23,     0,     0,     0,     0,     0,   140,
     141,     0,   142,     0,    31,     0,     0,     0,     0,    34,
      35,     0,    37,     0,    38,    39,     0,     0,     0,     0,
       0,     0,    41,     0,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,    52,    53,
     143,     0,     0,     0,   203,   204,     0,   240,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    64,    65,    66,    67,     0,     0,     0,
       0,    68,     0,     0,     5,     6,     7,     8,     9,    10,
      69,     0,    70,   139,    71,    72,   199,     0,     0,     0,
      74,     0,     0,     0,   144,     0,    76,   574,   145,    23,
       0,     0,     0,     0,     0,   140,   141,     0,   142,     0,
      31,     0,     0,     0,     0,    34,    35,     0,    37,     0,
      38,    39,     0,     0,     0,     0,     0,     0,    41,     0,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    51,    52,    53,   143,     0,     0,     0,
     203,   204,     0,   240,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,   266,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    64,
      65,    66,    67,     0,     0,     0,     0,    68,     0,     0,
       5,     6,     7,     8,     9,    10,    69,     0,    70,   139,
      71,    72,   199,     0,   267,     0,    74,     0,   268,     0,
     144,     0,    76,   576,   145,    23,     0,     0,     0,     0,
       0,   140,   141,     0,   142,     0,    31,     0,     0,     0,
       0,    34,    35,     0,    37,     0,    38,    39,     0,     0,
       0,     0,     0,     0,    41,     0,    43,   270,     0,   271,
     272,   273,     0,   274,   275,   276,     0,     0,   278,    51,
      52,    53,   143,     0,   284,   285,   203,   204,     0,   288,
       0,     0,   289,   290,   291,     0,     0,     0,     0,     0,
      63,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    64,    65,    66,    67,     0,
       0,     0,     0,    68,     5,     6,     7,     8,     9,    10,
       0,     0,    69,   139,    70,     0,    71,    72,     0,   205,
       0,     0,    74,     0,     0,     0,   144,     0,    76,    23,
     145,     0,     0,     0,     0,   140,   141,     0,   142,     0,
      31,     0,     0,     0,     0,    34,    35,     0,    37,     0,
      38,    39,     0,     0,     0,     0,     0,     0,    41,     0,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    51,    52,    53,   143,     0,     0,     0,
     203,   204,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    64,
      65,    66,    67,     0,     0,     0,     0,    68,     5,     6,
       7,     8,     9,    10,     0,     0,    69,   139,    70,     0,
      71,    72,   199,     0,     0,     0,    74,     0,     0,     0,
     144,     0,    76,    23,   145,     0,     0,     0,     0,   140,
     141,     0,   142,     0,    31,     0,     0,     0,     0,    34,
      35,     0,    37,     0,    38,    39,   684,     0,     0,     0,
       0,     0,    41,     0,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,    52,    53,
     143,     0,     0,     0,   203,   204,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    64,    65,    66,    67,     0,     0,     0,
       0,    68,     5,     6,     7,     8,     9,    10,     0,     0,
      69,   139,    70,     0,    71,    72,     0,     0,     0,     0,
      74,     0,     0,     0,   144,     0,    76,    23,   145,     0,
       0,     0,     0,   140,   141,     0,   142,     0,    31,     0,
       0,     0,     0,    34,    35,     0,    37,     0,    38,    39,
       0,     0,     0,     0,     0,   169,    41,     0,    43,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    51,    52,    53,   143,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     170,     0,    63,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    64,    65,    66,
      67,     0,     0,     0,     0,    68,     5,     6,     7,     8,
       9,    10,     0,     0,    69,   139,    70,     0,    71,    72,
       0,     0,     0,   174,    74,     0,     0,     0,   144,     0,
      76,    23,   145,     0,     0,     0,   175,   140,   141,     0,
     142,     0,    31,     0,     0,     0,     0,    34,    35,     0,
      37,     0,    38,    39,     0,     0,     0,     0,     0,     0,
      41,     0,    43,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,    52,    53,   143,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    64,    65,    66,    67,     0,     0,     0,     0,    68,
       5,     6,     7,     8,     9,    10,     0,     0,    69,   139,
      70,     0,    71,    72,     0,     0,     0,     0,    74,     0,
       0,     0,   144,     0,    76,    23,   145,     0,     0,     0,
       0,   140,   141,     0,   142,     0,    31,     0,     0,     0,
       0,    34,    35,     0,    37,     0,    38,    39,     0,     0,
       0,     0,     0,     0,    41,     0,    43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    51,
      52,    53,   143,     0,     0,     0,   203,   204,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    64,    65,    66,    67,     0,
       0,     0,     0,    68,     5,     6,     7,     8,     9,    10,
       0,     0,    69,   139,    70,     0,    71,    72,     0,     0,
       0,     0,    74,     0,     0,     0,   144,     0,    76,    23,
     145,     0,     0,     0,     0,   140,   141,     0,   142,     0,
      31,     0,     0,     0,     0,    34,    35,     0,    37,     0,
      38,    39,     0,     0,     0,     0,     0,     0,    41,     0,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    51,    52,    53,   143,     0,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,     0,     0,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    64,
      65,    66,    67,     0,     0,     0,     0,    68,     0,     0,
     306,   307,     0,     0,     0,  -428,    69,  -428,    70,     0,
      71,    72,   199,     0,     0,     0,    74,     0,     0,   266,
     144,   572,    76,     0,   145,     5,     6,     7,     8,     9,
      10,     0,     0,     0,   139,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   186,
      23,     0,     0,     0,     0,     0,   140,   141,   267,   142,
       0,    31,   268,     0,     0,     0,    34,    35,     0,    37,
       0,    38,    39,     0,     0,     0,     0,     0,     0,    41,
       0,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    51,    52,    53,   143,     0,     0,
       0,   270,     0,   271,   272,   273,     0,   274,   275,   276,
       0,   277,   278,   279,   280,    63,   282,   283,   284,   285,
       0,   286,     0,   288,     0,     0,   289,   290,   291,     0,
      64,    65,    66,    67,     0,     0,     0,     0,    68,     5,
       6,     7,     8,     9,    10,     0,     0,    69,   139,    70,
       0,    71,    72,     0,     0,     0,     0,    74,     0,     0,
       0,    75,     0,    76,    23,   145,     0,     0,     0,     0,
     140,   141,     0,   142,     0,    31,     0,     0,     0,     0,
      34,    35,     0,    37,     0,    38,    39,     0,     0,     0,
       0,     0,     0,    41,     0,    43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,    52,
      53,   143,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    63,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    64,    65,    66,    67,     0,     0,
       0,     0,    68,     5,     6,     7,     8,     9,    10,     0,
       0,    69,   139,    70,     0,    71,    72,   199,     0,     0,
       0,    74,     0,     0,     0,   144,     0,    76,    23,   145,
       0,     0,     0,     0,   140,   141,     0,   142,     0,    31,
       0,     0,     0,     0,    34,    35,     0,    37,     0,    38,
      39,     0,     0,     0,     0,     0,     0,    41,     0,    43,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,    52,    53,   143,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   170,     0,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    64,    65,
      66,    67,     0,     0,     0,     0,    68,     5,     6,     7,
       8,     9,    10,     0,     0,    69,   139,    70,     0,    71,
      72,     0,     0,     0,     0,    74,     0,     0,     0,   144,
       0,    76,   845,   145,     0,     0,     0,     0,   140,   141,
       0,   142,     0,    31,     0,     0,     0,     0,    34,    35,
       0,    37,     0,    38,    39,     0,     0,     0,     0,     0,
       0,    41,     0,    43,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   846,    52,    53,   847,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    64,    65,    66,    67,     0,     0,     0,     0,
      68,     5,     6,     7,     8,     9,    10,     0,     0,    69,
     139,    70,     0,    71,    72,   199,     0,     0,     0,    74,
       0,     0,     0,   144,     0,    76,    23,   848,     0,     0,
       0,     0,   140,   141,     0,   142,     0,    31,     0,     0,
       0,     0,    34,    35,     0,    37,     0,    38,    39,     0,
       0,     0,     0,     0,     0,    41,     0,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,    52,    53,   143,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    64,    65,    66,    67,
       0,     0,     0,     0,    68,     5,     6,     7,     8,     9,
      10,     0,     0,    69,   139,    70,     0,    71,    72,   199,
       0,     0,     0,    74,     0,     0,     0,   144,     0,    76,
      23,   848,     0,     0,     0,     0,   140,   141,     0,   831,
       0,    31,     0,     0,     0,     0,    34,    35,     0,    37,
       0,    38,    39,     0,     0,     0,     0,     0,     0,    41,
       0,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    51,    52,    53,   143,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      64,    65,    66,    67,     0,     0,     0,     0,    68,     5,
       6,     7,     8,     9,    10,     0,     0,    69,   139,    70,
       0,    71,    72,   199,     0,     0,     0,    74,     0,     0,
       0,   144,     0,    76,    23,   145,     0,     0,     0,     0,
     140,   141,     0,   142,     0,    31,     0,     0,     0,     0,
      34,    35,     0,    37,     0,    38,    39,     0,     0,     0,
       0,     0,     0,    41,     0,    43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,    52,
      53,   143,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    63,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    64,    65,    66,    67,     0,     0,
       0,     0,    68,     5,     6,     7,     8,     9,    10,     0,
       0,    69,   139,    70,     0,    71,    72,     0,     0,     0,
       0,    74,     0,     0,     0,   144,     0,    76,    23,   145,
       0,     0,     0,     0,   140,   141,     0,   142,     0,    31,
       0,     0,     0,     0,    34,    35,     0,    37,     0,    38,
      39,     0,     0,     0,     0,     0,     0,    41,     0,    43,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,    52,    53,   143,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    64,    65,
      66,    67,     0,     0,     0,     0,    68,     5,     6,     7,
       8,     9,    10,     0,     0,    69,   139,    70,     0,    71,
      72,     0,     0,     0,     0,    74,     0,     0,     0,    75,
       0,    76,    23,   145,     0,     0,     0,     0,   140,   141,
       0,   142,     0,    31,     0,     0,     0,     0,    34,    35,
       0,    37,     0,    38,    39,     0,     0,     0,     0,     0,
       0,    41,     0,    43,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,    52,    53,   143,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    64,    65,    66,    67,     0,     0,     0,     0,
      68,     5,     6,     7,     8,     9,    10,     0,     0,    69,
     139,    70,     0,    71,    72,     0,     0,     0,     0,   532,
       0,     0,     0,   144,     0,    76,    23,   145,     0,     0,
       0,     0,   140,   141,     0,   142,     0,    31,     0,     0,
       0,     0,    34,    35,     0,    37,     0,    38,    39,     0,
       0,     0,     0,     0,     0,    41,     0,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,    52,    53,   143,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    64,    65,    66,    67,
       0,     0,     0,     0,    68,     5,     6,     7,     8,     9,
      10,     0,     0,    69,   139,    70,     0,    71,    72,     0,
       0,     0,     0,    74,     0,     0,     0,   144,     0,    76,
      23,   551,     0,     0,     0,     0,   140,   141,     0,   630,
       0,    31,     0,     0,     0,     0,    34,    35,     0,    37,
       0,    38,    39,     0,     0,     0,     0,     0,     0,    41,
       0,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    51,    52,    53,   143,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      64,    65,    66,    67,     0,     0,     0,     0,    68,     5,
       6,     7,     8,     9,    10,     0,     0,    69,   139,    70,
       0,    71,    72,     0,     0,     0,     0,    74,     0,     0,
       0,   144,     0,    76,    23,   145,     0,     0,     0,     0,
     140,   141,     0,   633,     0,    31,     0,     0,     0,     0,
      34,    35,     0,    37,     0,    38,    39,     0,     0,     0,
       0,     0,     0,    41,     0,    43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,    52,
      53,   143,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    63,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    64,    65,    66,    67,     0,     0,
       0,     0,    68,     5,     6,     7,     8,     9,    10,     0,
       0,    69,   139,    70,     0,    71,    72,     0,     0,     0,
       0,    74,     0,     0,     0,   144,     0,    76,    23,   145,
       0,     0,     0,     0,   140,   141,     0,   825,     0,    31,
       0,     0,     0,     0,    34,    35,     0,    37,     0,    38,
      39,     0,     0,     0,     0,     0,     0,    41,     0,    43,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,    52,    53,   143,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    64,    65,
      66,    67,     0,     0,     0,     0,    68,     5,     6,     7,
       8,     9,    10,     0,     0,    69,   139,    70,     0,    71,
      72,     0,     0,     0,     0,    74,     0,     0,     0,   144,
       0,    76,    23,   145,     0,     0,     0,     0,   140,   141,
       0,   826,     0,    31,     0,     0,     0,     0,    34,    35,
       0,    37,     0,    38,    39,     0,     0,     0,     0,     0,
       0,    41,     0,    43,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,    52,    53,   143,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    64,    65,    66,    67,     0,     0,     0,     0,
      68,     5,     6,     7,     8,     9,    10,     0,     0,    69,
     139,    70,     0,    71,    72,     0,     0,     0,     0,    74,
       0,     0,     0,   144,     0,    76,    23,   145,     0,     0,
       0,     0,   140,   141,     0,   828,     0,    31,     0,     0,
       0,     0,    34,    35,     0,    37,     0,    38,    39,     0,
       0,     0,     0,     0,     0,    41,     0,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,    52,    53,   143,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    64,    65,    66,    67,
       0,     0,     0,     0,    68,     5,     6,     7,     8,     9,
      10,     0,     0,    69,   139,    70,     0,    71,    72,     0,
       0,     0,     0,    74,     0,     0,     0,   144,     0,    76,
      23,   145,     0,     0,     0,     0,   140,   141,     0,   829,
       0,    31,     0,     0,     0,     0,    34,    35,     0,    37,
       0,    38,    39,     0,     0,     0,     0,     0,     0,    41,
       0,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    51,    52,    53,   143,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      64,    65,    66,    67,     0,     0,     0,     0,    68,     5,
       6,     7,     8,     9,    10,     0,     0,    69,   139,    70,
       0,    71,    72,     0,     0,     0,     0,    74,     0,     0,
       0,   144,     0,    76,    23,   145,     0,     0,     0,     0,
     140,   141,     0,   830,     0,    31,     0,     0,     0,     0,
      34,    35,     0,    37,     0,    38,    39,     0,     0,     0,
       0,     0,     0,    41,     0,    43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,    52,
      53,   143,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    63,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    64,    65,    66,    67,     0,     0,
       0,     0,    68,     5,     6,     7,     8,     9,    10,     0,
       0,    69,   139,    70,     0,    71,    72,     0,     0,     0,
       0,    74,     0,     0,     0,   144,     0,    76,    23,   145,
       0,     0,     0,     0,   140,   141,     0,   831,     0,    31,
       0,     0,     0,     0,    34,    35,     0,    37,     0,    38,
      39,     0,     0,     0,     0,     0,     0,    41,     0,    43,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,    52,    53,   143,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    64,    65,
      66,    67,     0,     0,     0,     0,    68,     5,     6,     7,
       8,     9,    10,     0,     0,    69,   139,    70,     0,    71,
      72,     0,     0,     0,     0,    74,     0,     0,     0,   144,
       0,    76,    23,   145,     0,     0,     0,     0,   140,   141,
       0,   142,     0,    31,     0,     0,     0,     0,    34,    35,
       0,    37,     0,    38,    39,     5,     6,     7,     8,     9,
      10,    41,     0,    43,   139,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,    52,    53,   143,
      23,     0,     0,     0,     0,     0,   140,   141,     0,   142,
       0,    31,     0,     0,     0,     0,    34,    35,     0,    37,
       0,    38,    39,   264,     0,     0,     0,     0,   265,    41,
       0,    43,    64,    65,    66,    67,     0,     0,     0,   266,
       0,     0,     0,     0,    51,    52,    53,   143,     0,    69,
       0,    70,     0,     0,    72,     0,     0,     0,     0,    74,
       0,     0,     0,   144,     0,    76,  -318,   145,     0,     0,
       0,   264,     0,     0,     0,     0,   265,     0,   267,     0,
       0,    65,   268,     0,     0,  -318,     0,   266,     0,  -318,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
       0,     0,     0,   199,     0,     0,   269,     0,     0,     0,
       0,   144,     0,    76,  -318,   848,     0,     0,     0,     0,
       0,   270,     0,   271,   272,   273,   267,   274,   275,   276,
     268,   277,   278,   279,   280,   281,   282,   283,   284,   285,
       0,   286,   287,   288,   264,     0,   289,   290,   291,   265,
       0,     0,     0,     0,   269,     0,     0,   755,     0,     0,
     266,     0,     0,     0,     0,     0,     0,     0,     0,   270,
       0,   271,   272,   273,     0,   274,   275,   276,     0,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   264,   286,
     287,   288,     0,   265,   289,   290,   291,     0,     0,   267,
       0,     0,     0,   268,   266,   901,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   269,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   270,   267,   271,   272,   273,   268,   274,   275,
     276,     0,   277,   278,   279,   280,   281,   282,   283,   284,
     285,     0,   286,   287,   288,     0,     0,   289,   290,   291,
       0,   269,     0,     0,     0,   264,     0,     0,   938,     0,
     265,     0,     0,     0,     0,     0,   270,     0,   271,   272,
     273,   266,   274,   275,   276,     0,   277,   278,   279,   280,
     281,   282,   283,   284,   285,     0,   286,   287,   288,     0,
       0,   289,   290,   291,     0,     0,     0,     0,     0,     0,
     573,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     267,     0,     0,     0,   268,     0,     0,   264,     0,     0,
       0,     0,   265,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   266,     0,     0,     0,     0,   269,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   270,     0,   271,   272,   273,     0,   274,
     275,   276,     0,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   267,   286,   287,   288,   268,     0,   289,   290,
     291,     0,     0,   350,     0,     0,     0,   872,     0,     0,
       0,     0,   264,     0,     0,     0,     0,   265,     0,     0,
     269,   351,   352,   353,   354,   355,   356,     0,   266,   357,
     358,   359,   360,   361,   362,   270,     0,   271,   272,   273,
       0,   274,   275,   276,     0,   277,   278,   279,   280,   281,
     282,   283,   284,   285,     0,   286,   287,   288,     0,     0,
     289,   290,   291,     0,     0,     0,   315,   267,     0,     0,
       0,   268,     0,     0,   264,     0,     0,     0,   760,   265,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     266,     0,     0,     0,     0,   269,   351,   352,   353,   354,
     355,   356,     0,     0,   357,   358,   359,   360,   361,   362,
     270,     0,   271,   272,   273,     0,   274,   275,   276,     0,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   267,
     286,   287,   288,   268,     0,   289,   290,   291,     0,     0,
     765,   315,     0,     0,     0,     0,     0,     0,     0,   264,
       0,     0,     0,     0,   265,     0,     0,   269,   351,   352,
     353,   354,   355,   356,     0,   266,   357,   358,   359,   360,
     361,   362,   270,     0,   271,   272,   273,     0,   274,   275,
     276,     0,   277,   278,   279,   280,   281,   282,   283,   284,
     285,     0,   286,   287,   288,     0,     0,   289,   290,   291,
       0,     0,     0,   315,   267,     0,     0,     0,   268,     0,
       0,   264,     0,     0,     0,   885,   265,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   266,     0,     0,
       0,     0,   269,   351,   352,   353,   354,   355,   356,     0,
       0,   357,   358,   359,   360,   361,   362,   270,     0,   271,
     272,   273,     0,   274,   275,   276,     0,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   267,   286,   287,   288,
     268,     0,   289,   290,   291,     0,     0,   886,   315,     0,
       0,     0,     0,     0,     0,     0,   264,     0,     0,     0,
       0,   265,     0,     0,   269,   351,   352,   353,   354,   355,
     356,     0,   266,   357,   358,   359,   360,   361,   362,   270,
       0,   271,   272,   273,     0,   274,   275,   276,     0,   277,
     278,   279,   280,   281,   282,   283,   284,   285,     0,   286,
     287,   288,     0,     0,   289,   290,   291,     0,     0,     0,
     315,   267,     0,     0,     0,   268,     0,     0,   264,     0,
       0,     0,   887,   265,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   266,     0,     0,     0,     0,   269,
     351,   352,   353,   354,   355,   356,     0,     0,   357,   358,
     359,   360,   361,   362,   270,     0,   271,   272,   273,     0,
     274,   275,   276,     0,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   267,   286,   287,   288,   268,     0,   289,
     290,   291,     0,     0,   888,   315,     0,     0,     0,     0,
       0,     0,     0,   264,     0,     0,     0,     0,   265,     0,
       0,   269,   351,   352,   353,   354,   355,   356,     0,   266,
     357,   358,   359,   360,   361,   362,   270,     0,   271,   272,
     273,     0,   274,   275,   276,     0,   277,   278,   279,   280,
     281,   282,   283,   284,   285,     0,   286,   287,   288,     0,
       0,   289,   290,   291,     0,     0,     0,   315,   267,     0,
       0,     0,   268,     0,     0,   264,     0,     0,     0,   903,
     265,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   266,     0,     0,     0,     0,   269,   351,   352,   353,
     354,   355,   356,     0,     0,   357,   358,   359,   360,   361,
     362,   270,     0,   271,   272,   273,     0,   274,   275,   276,
       0,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     267,   286,   287,   288,   268,     0,   289,   290,   291,     0,
       0,   904,   315,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   269,   351,
     352,   353,   354,   355,   356,     0,     0,   357,   358,   359,
     360,   361,   362,   270,     0,   271,   272,   273,     0,   274,
     275,   276,     0,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   264,   286,   287,   288,     0,   265,   289,   290,
     291,     0,     0,     0,   315,     0,     0,     0,   266,   342,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     343,     0,     0,     0,     0,     0,   264,     0,     0,     0,
       0,   265,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   266,   339,     0,     0,     0,   267,     0,     0,
       0,   268,     0,     0,   340,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   344,     0,     0,     0,   269,     0,     0,     0,     0,
       0,   267,     0,     0,     0,   268,     0,     0,     0,     0,
     270,     0,   271,   272,   273,     0,   274,   275,   276,     0,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   269,
     286,   287,   288,     0,     0,   289,   290,   291,     0,     0,
       0,   315,     0,     0,   270,     0,   271,   272,   273,     0,
     274,   275,   276,     0,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   264,   286,   287,   288,     0,   265,   289,
     290,   291,     0,     0,     0,   315,     0,     0,     0,   266,
     656,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   264,     0,     0,
       0,     0,   265,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   266,   186,     0,     0,     0,   267,     0,
       0,     0,   268,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   264,     0,     0,     0,     0,
     265,     0,   344,     0,     0,     0,   269,     0,     0,     0,
       0,   266,   267,     0,     0,     0,   268,     0,     0,     0,
       0,   270,     0,   271,   272,   273,     0,   274,   275,   276,
       0,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     269,   286,   287,   288,     0,     0,   289,   290,   291,     0,
     267,     0,   315,     0,   268,   270,     0,   271,   272,   273,
       0,   274,   275,   276,     0,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   264,   286,   287,   288,   269,   265,
     289,   290,   291,     0,     0,     0,   315,     0,     0,     0,
     266,   650,     0,   270,     0,   271,   272,   273,     0,   274,
     275,   276,     0,   277,   278,   279,   280,   281,   282,   283,
     284,   285,     0,   286,   287,   288,     0,     0,   289,   290,
     291,     0,     0,     0,   390,     0,     0,     0,     0,   267,
       0,     0,     0,   268,     0,     0,   264,     0,     0,     0,
       0,   265,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   266,     0,     0,     0,     0,   269,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   270,     0,   271,   272,   273,     0,   274,   275,
     276,     0,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   267,   286,   287,   288,   268,     0,   289,   290,   291,
       0,     0,   668,   315,     0,     0,     0,   264,     0,     0,
       0,     0,   265,     0,     0,     0,     0,     0,     0,   269,
       0,     0,     0,   266,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   270,     0,   271,   272,   273,     0,
     274,   275,   276,     0,   277,   278,   279,   280,   281,   282,
     283,   284,   285,     0,   286,   287,   288,     0,     0,   289,
     290,   291,   267,     0,     0,   315,   268,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   264,     0,     0,     0,     0,   265,     0,     0,     0,
     269,     0,     0,     0,     0,     0,     0,   266,     0,     0,
       0,     0,   347,     0,     0,   270,     0,   271,   272,   273,
       0,   274,   275,   276,     0,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   348,   286,   287,   288,     0,   264,
     289,   290,   291,     0,   265,  -404,   267,     0,     0,     0,
     268,     0,     0,     0,     0,   266,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   321,     0,     0,
       0,     0,     0,     0,   269,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   266,     0,     0,     0,   270,
       0,   271,   272,   273,   267,   274,   275,   276,   268,   277,
     278,   279,   280,   281,   282,   283,   284,   285,     0,   286,
     287,   288,     0,   349,   289,   290,   291,     0,   133,     0,
       0,     0,   269,     0,   267,     0,     0,     0,   268,     0,
       0,     0,     0,     0,     0,     0,     0,   270,     0,   271,
     272,   273,     0,   274,   275,   276,     0,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   264,   286,   287,   288,
       0,   265,   289,   290,   291,     0,     0,   270,     0,   271,
     272,   273,   266,   274,   275,   276,     0,   403,   278,   279,
     280,     0,   282,   283,   284,   285,     0,     0,     0,   288,
     264,     0,   289,   290,   291,   265,     0,     0,     0,   404,
       0,     0,     0,     0,     0,     0,   266,   502,     0,     0,
       0,   267,     0,     0,     0,   268,     0,     0,   503,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   264,     0,
       0,     0,     0,   265,     0,     0,     0,     0,     0,   269,
       0,     0,     0,     0,   266,   267,     0,     0,     0,   268,
       0,     0,     0,     0,   270,     0,   271,   272,   273,     0,
     274,   275,   276,     0,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   269,   286,   287,   288,     0,     0,   289,
     290,   291,     0,   267,     0,     0,     0,   268,   270,     0,
     271,   272,   273,     0,   274,   275,   276,     0,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   264,   286,   287,
     288,   269,   265,   289,   290,   291,     0,     0,     0,     0,
       0,     0,     0,   266,   504,     0,   270,     0,   271,   272,
     273,     0,   274,   275,   276,   505,   277,   278,   279,   280,
     281,   282,   283,   284,   285,     0,   286,   287,   288,     0,
     394,   289,   290,   291,     0,   264,     0,     0,     0,     0,
     265,     0,   267,     0,     0,     0,   268,     0,     0,     0,
       0,   266,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     269,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   270,     0,   271,   272,   273,
     267,   274,   275,   276,   268,   277,   278,   279,   280,   281,
     282,   283,   284,   285,     0,   286,   287,   288,   264,     0,
     289,   290,   291,   265,     0,     0,     0,     0,   269,     0,
       0,     0,     0,     0,   266,     0,     0,     0,     0,     0,
       0,     0,     0,   270,     0,   271,   272,   273,     0,   274,
     275,   276,     0,   277,   278,   279,   280,   281,   282,   283,
     284,   285,     0,   286,   287,   288,   264,   396,   289,   290,
     291,   265,     0,   267,     0,     0,     0,   268,     0,     0,
       0,     0,   266,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   269,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   270,     0,   271,   272,
     273,   267,   274,   275,   276,   268,   277,   278,   279,   280,
     281,   282,   283,   284,   285,     0,   286,   287,   288,   264,
     398,   289,   290,   291,   265,     0,     0,     0,     0,   269,
       0,     0,     0,     0,     0,   266,     0,     0,     0,     0,
       0,     0,     0,     0,   270,     0,   271,   272,   273,     0,
     274,   275,   276,     0,   277,   278,   279,   280,   281,   282,
     283,   284,   285,     0,   286,   287,   288,     0,   406,   289,
     290,   291,     0,     0,   267,     0,     0,     0,   268,     0,
       0,   264,     0,     0,     0,     0,   265,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   266,     0,     0,
       0,   421,   269,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   270,     0,   271,
     272,   273,     0,   274,   275,   276,     0,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   267,   286,   287,   288,
     268,     0,   289,   290,   291,     0,     0,   506,     0,     0,
       0,     0,   264,     0,     0,     0,     0,   265,     0,     0,
       0,     0,     0,     0,   269,     0,     0,     0,   266,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   270,
       0,   271,   272,   273,     0,   274,   275,   276,     0,   277,
     278,   279,   280,   281,   282,   283,   284,   285,     0,   286,
     287,   288,     0,     0,   289,   290,   291,   267,     0,     0,
       0,   268,     0,     0,   264,     0,     0,     0,     0,   265,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     266,   133,     0,     0,     0,   269,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     270,     0,   271,   272,   273,     0,   274,   275,   276,     0,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   267,
     286,   287,   288,   268,     0,   289,   290,   291,     0,     0,
       0,     0,     0,     0,     0,   264,   663,     0,     0,     0,
     265,     0,     0,     0,     0,     0,     0,   269,     0,     0,
       0,   266,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   270,     0,   271,   272,   273,     0,   274,   275,
     276,     0,   277,   278,   279,   280,   281,   282,   283,   284,
     285,     0,   286,   287,   288,     0,   640,   289,   290,   291,
     267,     0,     0,     0,   268,     0,     0,   264,     0,     0,
       0,     0,   265,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   266,     0,     0,   666,     0,   269,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   270,     0,   271,   272,   273,     0,   274,
     275,   276,     0,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   267,   286,   287,   288,   268,     0,   289,   290,
     291,     0,     0,     0,     0,     0,     0,     0,   264,     0,
       0,     0,     0,   265,     0,     0,     0,     0,     0,     0,
     269,     0,     0,     0,   266,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   270,     0,   271,   272,   273,
       0,   274,   275,   276,     0,   277,   278,   279,   280,   281,
     282,   283,   284,   285,     0,   286,   287,   288,     0,     0,
     289,   290,   291,   267,     0,     0,     0,   268,     0,     0,
     264,     0,     0,     0,     0,   265,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   266,   750,     0,     0,
     704,   269,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   270,     0,   271,   272,
     273,     0,   274,   275,   276,     0,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   267,   286,   287,   288,   268,
       0,   289,   290,   291,     0,     0,     0,     0,     0,     0,
       0,   264,     0,     0,     0,     0,   265,     0,     0,     0,
       0,     0,     0,   269,     0,     0,     0,   266,   753,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   270,     0,
     271,   272,   273,     0,   274,   275,   276,     0,   277,   278,
     279,   280,   281,   282,   283,   284,   285,     0,   286,   287,
     288,     0,     0,   289,   290,   291,   267,     0,     0,     0,
     268,     0,     0,   264,     0,     0,     0,     0,   265,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   266,
       0,     0,     0,     0,   269,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   270,
       0,   271,   272,   273,     0,   274,   275,   276,     0,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   267,   286,
     287,   288,   268,     0,   289,   290,   291,     0,     0,   824,
       0,     0,     0,     0,   264,     0,     0,     0,     0,   265,
       0,     0,     0,     0,     0,     0,   269,     0,     0,     0,
     266,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   270,     0,   271,   272,   273,     0,   274,   275,   276,
       0,   277,   278,   279,   280,   281,   282,   283,   284,   285,
       0,   286,   287,   288,     0,     0,   289,   290,   291,   267,
       0,     0,     0,   268,     0,     0,   264,   841,     0,     0,
     827,   265,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   266,     0,     0,     0,     0,   269,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   270,     0,   271,   272,   273,     0,   274,   275,
     276,     0,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   267,   286,   287,   288,   268,     0,   289,   290,   291,
       0,     0,     0,     0,     0,     0,     0,   264,     0,     0,
       0,     0,   265,     0,     0,     0,     0,     0,     0,   269,
       0,     0,     0,   266,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   270,     0,   271,   272,   273,     0,
     274,   275,   276,     0,   277,   278,   279,   280,   281,   282,
     283,   284,   285,     0,   286,   287,   288,     0,     0,   289,
     290,   291,   267,     0,     0,     0,   268,     0,     0,   264,
       0,     0,     0,   910,   265,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   266,     0,     0,     0,     0,
     269,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   270,     0,   271,   272,   273,
       0,   274,   275,   276,     0,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   267,   286,   287,   288,   268,     0,
     289,   290,   291,     0,     0,   911,     0,     0,     0,     0,
     264,     0,     0,     0,     0,   265,     0,     0,     0,     0,
       0,     0,   269,     0,     0,     0,   266,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   270,     0,   271,
     272,   273,     0,   274,   275,   276,     0,   277,   278,   279,
     280,   281,   282,   283,   284,   285,     0,   286,   287,   288,
       0,     0,   289,   290,   291,   267,     0,     0,     0,   268,
       0,     0,   264,     0,     0,     0,   912,   265,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   266,     0,
       0,     0,     0,   269,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   270,     0,
     271,   272,   273,     0,   274,   275,   276,     0,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   267,   286,   287,
     288,   268,     0,   289,   290,   291,     0,     0,   913,     0,
       0,     0,     0,   264,     0,     0,     0,     0,   265,     0,
       0,     0,     0,     0,     0,   269,     0,     0,     0,   266,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     270,     0,   271,   272,   273,     0,   274,   275,   276,     0,
     277,   278,   279,   280,   281,   282,   283,   284,   285,     0,
     286,   287,   288,     0,     0,   289,   290,   291,   267,     0,
       0,     0,   268,     0,     0,   264,     0,     0,     0,   914,
     265,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   266,     0,     0,     0,     0,   269,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   270,     0,   271,   272,   273,     0,   274,   275,   276,
       0,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     267,   286,   287,   288,   268,     0,   289,   290,   291,     0,
       0,   915,     0,     0,     0,     0,   264,     0,     0,     0,
       0,   265,     0,     0,     0,     0,     0,     0,   269,     0,
       0,     0,   266,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   270,     0,   271,   272,   273,     0,   274,
     275,   276,     0,   277,   278,   279,   280,   281,   282,   283,
     284,   285,     0,   286,   287,   288,     0,     0,   289,   290,
     291,   267,     0,     0,     0,   268,     0,     0,   264,     0,
       0,     0,     0,   265,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   266,     0,     0,     0,     0,   269,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   270,     0,   271,   272,   273,     0,
     274,   275,   276,     0,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   628,   286,   287,   288,   268,     0,   289,
     290,   291,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   269,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   270,     0,   271,   272,
     273,     0,   274,   275,   276,     0,   277,   278,   279,   280,
     281,   282,   283,   284,   285,     0,   286,   287,   288,     0,
       0,   289,   290,   291
};

static const yytype_int16 yycheck[] =
{
       2,     2,    44,    45,   312,   399,   599,   530,   681,    11,
     246,    47,   367,    27,    16,    76,   375,    15,    20,    21,
      22,    25,     1,   550,    60,    27,    28,    29,    30,     1,
     370,   742,     3,     3,    36,    37,    38,    27,    40,    41,
     399,    77,    27,     3,   155,    47,   179,    49,    50,    51,
      27,     3,    54,    55,    56,    57,   167,     3,    60,    61,
      62,    21,   195,    65,     0,     3,    68,    69,    70,     1,
      72,   707,   707,    75,    27,    77,    68,    79,    38,     1,
     213,    41,    54,   258,   259,   260,   261,     3,     3,    68,
      38,     7,   856,    54,   348,    55,    56,   132,    38,    89,
     113,   162,    89,   626,   113,   140,    66,    38,    87,   145,
     783,    82,    38,    28,    86,   132,    38,   113,   179,    38,
      66,    81,   132,   132,   892,    86,    42,    17,   113,   113,
     140,   144,   134,   112,   195,    68,    68,   139,   140,   141,
     142,   143,   144,   145,   140,    61,    78,   139,    89,   139,
     404,   678,   213,   151,   139,    87,   140,   144,    89,   927,
     139,     3,   139,   874,   875,   113,    81,   931,   140,   139,
     141,   141,    94,   113,    64,   308,   309,   813,   180,   140,
     112,   141,   113,   132,   186,    21,   139,   113,    48,   141,
     112,   113,   196,    83,   113,   141,   144,   833,   833,   132,
     132,   203,   204,   141,   144,   113,   139,   139,    81,   549,
     132,   113,    94,   144,   113,   113,    76,   113,   891,    94,
      56,   113,   530,    38,   141,   144,   143,   820,   113,   113,
      66,   113,   141,    42,   142,   117,   238,   238,   141,   241,
     142,     7,   117,   142,   142,    81,   142,   308,   309,   772,
     142,    66,    61,   267,   268,   430,    62,   142,   142,   392,
     142,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   113,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     817,    26,   528,   529,   927,   113,   310,   311,   141,    13,
     143,   337,   142,   113,    18,   938,   141,   321,   310,   311,
     312,    74,     3,   315,   132,   670,     7,   113,   626,   321,
      26,    21,   132,   325,   385,   327,   340,    56,    57,   343,
      65,   392,   672,    21,    69,   337,   132,   339,   340,   113,
     342,   343,   578,   579,   141,   347,   348,    21,   350,   410,
      38,   113,   413,    41,   415,   113,    56,   418,   132,    65,
     132,    65,   364,    69,   132,    69,    66,    55,    56,   141,
     132,   143,   132,   375,   132,   377,     2,   112,    66,   114,
     115,    81,    56,   385,   119,    11,   113,   141,    26,   143,
     426,   126,    66,    81,    20,   789,    22,   399,   133,   134,
     135,   403,   404,   417,   132,   132,   112,   138,   410,   115,
     113,    85,     1,   119,     3,   417,   418,   419,   112,   421,
     422,   115,    65,   782,   426,   119,    69,    65,    54,   132,
     789,    69,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   413,    75,
     415,   132,   132,    79,   515,    93,   517,   132,   569,   132,
     132,   139,   141,   132,   772,    88,   821,   115,   132,    94,
     108,   141,   110,   111,   112,   141,   114,   115,   116,   141,
     118,   119,   120,   121,    26,   123,   124,   125,   126,   503,
     128,   505,   130,   132,     7,   133,   134,   135,    94,    48,
     502,   503,   504,   505,   506,   507,   508,   112,   134,   139,
     132,   509,   510,    94,   142,   551,   113,   113,   520,   132,
     522,   117,     3,    65,   526,   141,     7,    69,   530,    38,
      29,    38,   142,   892,   113,   142,    94,    16,   540,   142,
      21,   142,   901,   113,   144,    20,   142,   139,   132,   551,
     132,   142,   132,   413,   180,   415,    26,    32,    33,   132,
     186,    68,   113,   132,   132,    40,   108,    42,   927,   111,
     112,    78,   114,   115,    29,    56,   132,   119,     1,   938,
      87,   583,   132,   144,   126,    66,    61,    94,   132,   132,
     142,   133,   134,   135,    17,    65,   132,    20,    21,    69,
      81,   132,   132,   132,    85,   132,   113,    30,   132,    32,
      33,   132,   238,    36,   628,   629,   132,    40,   132,    42,
     140,   132,   132,   142,   626,   132,   628,   629,   630,   113,
      94,   633,   139,    56,   139,    58,   140,    60,    61,    38,
      63,    64,   112,    66,   114,   115,   648,    66,   650,   119,
      27,   653,   688,    27,   656,   515,   126,   144,    81,   661,
      83,   663,    85,   665,   666,   135,   668,   139,    29,    68,
     112,    66,   112,   144,   140,   144,   144,   115,     3,    78,
     115,   141,     7,    29,     9,   687,   688,    87,    87,   315,
     142,   142,   140,    78,   554,    94,    21,   699,   705,   701,
     519,   403,   704,   705,   221,   404,   692,   709,   758,   132,
     168,   710,   820,   339,   113,   821,   342,   140,   713,   670,
     931,   782,   891,   906,   350,    29,   378,   844,   517,    -1,
      -1,    56,    -1,   132,    -1,    -1,   738,    -1,    -1,    -1,
     139,    66,    -1,    -1,    -1,    -1,    -1,   749,   750,    -1,
     752,   753,   754,   755,    -1,    -1,    81,    -1,   760,   761,
      85,   763,    -1,   765,   766,     2,    -1,   769,   810,   811,
     772,    -1,    26,    -1,    11,    -1,    -1,   779,    -1,    -1,
     782,    -1,    -1,    20,    -1,    22,   788,   789,   790,    -1,
      -1,   852,   794,   419,   796,    -1,    -1,   799,   800,    -1,
      -1,   803,    -1,    -1,    -1,   807,   807,    -1,    -1,    -1,
      -1,    65,   848,    -1,    -1,    69,    -1,    54,    -1,    56,
      57,    20,   824,   825,   826,   827,   828,   829,   830,   831,
      -1,   892,    -1,    32,    33,    -1,    -1,    -1,    75,   841,
     842,    40,    79,    42,   846,   847,   848,    -1,    -1,    48,
     852,    -1,    -1,   855,   108,    -1,   110,   111,   112,    -1,
     114,   115,    61,    62,    -1,   119,   927,    -1,    -1,    -1,
      -1,   497,   126,    -1,    -1,    -1,    -1,   938,    -1,   133,
     134,   135,    -1,   885,   886,   887,   888,    -1,    38,    -1,
     892,    -1,    -1,    -1,    -1,    -1,    -1,   134,    -1,   901,
      -1,   903,   904,    -1,    -1,    -1,    -1,    -1,   910,   911,
     912,   913,   914,   915,   540,    -1,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,   926,   927,    -1,    -1,    78,    -1,
      -1,    -1,     2,    20,    -1,    -1,   938,    87,    -1,    -1,
      -1,    11,    -1,   180,    94,    32,    33,    -1,    -1,   186,
      20,    -1,    22,    40,    -1,    42,    -1,   583,     2,    -1,
      -1,    48,    -1,   113,    -1,    -1,    -1,    11,    -1,    -1,
      -1,    -1,    -1,   599,    61,    62,    20,    -1,    22,    -1,
      -1,    -1,   132,    -1,    54,    -1,    -1,    -1,    -1,   139,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   238,   628,   629,    -1,    75,    -1,    -1,     2,    79,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,
      -1,    -1,   648,    -1,   650,    -1,    20,   653,    22,    -1,
     656,    75,    -1,    -1,    -1,    79,    -1,    -1,    -1,   665,
      -1,    -1,   668,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,   687,    -1,    -1,   134,    -1,    -1,    -1,     1,    -1,
      -1,    -1,    -1,   699,    -1,   701,    -1,    -1,   315,   705,
      -1,    75,    -1,    -1,    17,    79,    -1,    20,    21,    -1,
     134,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,
      33,    -1,   339,    36,    -1,   342,    -1,    40,    -1,    42,
     180,    -1,    -1,   350,    -1,    -1,   186,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    58,    -1,    60,    61,    -1,
      63,    64,    -1,    66,   760,    -1,   180,    -1,    -1,   765,
     134,    -1,   186,    -1,    -1,    -1,    -1,    -1,    81,    -1,
      83,    -1,    85,   779,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   790,    -1,    -1,    -1,   238,    -1,
      -1,    -1,    -1,   799,    -1,    -1,    -1,   803,    -1,    -1,
      -1,   807,   419,    -1,    -1,    -1,   180,    17,    -1,    -1,
      20,    -1,   186,    -1,   238,    -1,    -1,    -1,    -1,   132,
      30,    -1,    32,    33,    -1,    -1,    36,   140,    -1,    -1,
      40,    -1,    42,    -1,    -1,    -1,   842,    -1,    -1,    -1,
      -1,    -1,    -1,     2,    -1,    -1,    -1,    -1,    58,    -1,
      60,    61,    11,    63,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    -1,    22,   238,   315,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    83,    -1,    -1,    -1,    -1,    -1,   885,
     886,   887,   888,    -1,    -1,    -1,    -1,    -1,    -1,   339,
      -1,   315,   342,    -1,    -1,    54,    -1,   903,   904,    -1,
     350,    -1,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    -1,   339,    75,    -1,   342,    -1,
      79,    -1,   132,   540,    -1,    -1,   350,    28,    -1,    -1,
     140,    -1,    -1,    34,    35,    -1,    37,    -1,    39,    -1,
      -1,   315,    -1,    44,    45,    -1,    47,    -1,    49,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    59,    -1,
      -1,    -1,    -1,    -1,    26,   339,   583,    -1,   342,   419,
      -1,    72,    73,    74,    75,   134,   350,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   419,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,     3,    -1,    -1,    69,   109,    -1,
       2,    10,    -1,    -1,    -1,    -1,    15,    -1,    -1,    11,
      -1,   180,    -1,    -1,    -1,    -1,   127,   186,    20,    -1,
      22,   648,    -1,   650,    -1,    -1,   653,    -1,   139,   656,
     141,    -1,   143,    -1,    -1,   419,   108,    -1,   665,    -1,
     112,   668,   114,   115,    -1,    -1,    -1,   119,    -1,    -1,
      -1,    -1,    54,    -1,   126,    -1,    -1,    -1,    -1,    -1,
     687,   133,   134,   135,    -1,    -1,    -1,    -1,    -1,   238,
      -1,    -1,   699,    75,   701,    -1,    -1,    79,   705,    -1,
     540,    -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,
      99,    -1,    -1,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,    -1,    -1,   114,   540,    -1,    -1,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,   130,    -1,   583,   133,   134,   135,   136,    -1,   138,
      -1,    -1,   134,   760,    -1,    -1,    -1,    -1,   765,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   315,    -1,    -1,   583,
      -1,    -1,   779,    -1,    -1,    -1,   540,    -1,    -1,    -1,
      -1,    -1,    -1,   790,    -1,    -1,    -1,    -1,    -1,    -1,
     339,    -1,   799,   342,    -1,    -1,   803,    -1,   180,    -1,
     807,   350,    -1,    -1,   186,    -1,    -1,    -1,   648,    -1,
     650,    -1,    -1,   653,    -1,    -1,   656,    -1,    -1,   583,
      -1,    -1,    -1,    -1,    -1,   665,    -1,    -1,   668,    -1,
      -1,    -1,    -1,    -1,   648,   842,   650,    -1,    -1,   653,
      -1,    -1,   656,    -1,    -1,    -1,    -1,   687,    -1,    -1,
      -1,   665,    -1,    -1,   668,    -1,   238,    -1,    -1,   699,
      -1,   701,    -1,    -1,    -1,   705,    -1,    -1,    -1,    -1,
     419,    -1,    -1,   687,    -1,    -1,    -1,    -1,   885,   886,
     887,   888,    -1,    -1,   648,   699,   650,   701,    -1,   653,
      50,   705,   656,    -1,    -1,    -1,   903,   904,    -1,    -1,
      -1,   665,    -1,    -1,   668,    -1,    -1,    -1,    -1,     2,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,    -1,
     760,    -1,    -1,   687,    -1,   765,    -1,    20,    -1,    22,
      -1,    -1,    -1,   315,    -1,   699,    -1,   701,    -1,   779,
      -1,   705,    -1,    -1,    -1,    -1,   760,    -1,    -1,    -1,
     790,   765,    -1,    -1,    -1,    -1,    -1,   339,    -1,   799,
     342,    54,    -1,   803,    -1,   779,    -1,   807,   350,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   790,    -1,    -1,    -1,
      -1,    -1,    75,    -1,    -1,   799,    79,    -1,    -1,   803,
      -1,   540,    -1,   807,    -1,    -1,   760,    -1,    -1,    -1,
      -1,   765,   842,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   171,   172,   173,    -1,   779,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   790,    -1,   842,   189,
      -1,    -1,   192,    -1,   583,   799,    -1,   419,    -1,   803,
      -1,   134,    -1,   807,    -1,   885,   886,   887,   888,    -1,
     210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   903,   904,    -1,    -1,    -1,   228,    -1,
      -1,   885,   886,   887,   888,    -1,    -1,    -1,   842,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,    -1,   903,
     904,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,   648,
      -1,   650,    -1,    -1,   653,    -1,    -1,   656,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   665,    -1,    -1,   668,
      26,   885,   886,   887,   888,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     2,   687,   903,
     904,    -1,    -1,    -1,    -1,   238,    11,    -1,    -1,    -1,
     699,    -1,   701,    36,    -1,    20,   705,    22,   540,    65,
      -1,    -1,   322,    69,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    56,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   346,    -1,    -1,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   583,   108,    -1,   110,   111,   112,    -1,   114,   115,
      75,   760,    -1,   119,    79,    -1,   765,    -1,    -1,   125,
     126,    -1,   315,    -1,   130,    -1,    -1,   133,   134,   135,
     779,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   790,    -1,    -1,    -1,    -1,   339,    -1,    -1,   342,
     799,    -1,    -1,    -1,   803,   138,    -1,   350,   807,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   648,    -1,   650,   134,
      -1,   653,    -1,    -1,   656,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   665,    -1,    -1,   668,    -1,   171,   172,
     173,    -1,    -1,   842,    -1,   178,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   687,   189,    -1,    -1,   192,
      -1,    -1,    -1,    -1,    -1,   180,    -1,   699,    -1,   701,
      -1,   186,    -1,   705,    -1,    -1,   419,   210,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   885,   886,   887,   888,
      -1,    -1,    -1,    -1,    -1,   228,    -1,    17,    -1,    -1,
      20,    -1,    -1,    -1,   903,   904,    -1,    -1,    -1,    -1,
      30,    -1,    32,    33,   524,   525,    36,    -1,   528,   529,
      40,    -1,    42,   238,    -1,    -1,    -1,    -1,   760,    -1,
      -1,    -1,    -1,   765,    -1,    -1,    -1,    -1,    58,    -1,
      60,    61,    -1,    63,    64,    -1,    -1,   779,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   790,    -1,
      -1,    81,    -1,    83,    -1,    -1,    -1,   799,    -1,    -1,
      -1,   803,    -1,    -1,    -1,   807,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,   322,
      -1,    -1,    -1,    -1,    26,    -1,    -1,   540,    -1,    -1,
     315,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     842,    -1,   132,   346,    -1,    -1,    -1,    -1,    -1,    -1,
     140,    -1,    -1,    -1,   339,    -1,    -1,   342,   638,   639,
      -1,    -1,    -1,    65,    -1,   645,    -1,    69,    -1,    -1,
     583,    -1,    -1,    -1,    -1,   655,    -1,    -1,   658,    -1,
      -1,    -1,    -1,   885,   886,   887,   888,    89,    -1,    -1,
      -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   903,   904,    -1,    -1,    -1,   108,    -1,   110,   111,
     112,    -1,   114,   115,   116,    -1,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,   128,   129,   130,    -1,
      -1,   133,   134,   135,   419,   648,    -1,   650,    -1,    -1,
     653,    -1,   144,   656,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   665,    -1,    -1,   668,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,
      -1,    -1,    -1,    -1,   687,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    -1,   699,    -1,   701,    -1,
      34,    35,   705,    37,    -1,    39,    -1,    -1,    -1,    -1,
      44,    45,    -1,    47,    -1,    49,    50,    -1,    -1,    -1,
      -1,    -1,   792,    57,    -1,    59,    -1,    -1,    -1,    -1,
      -1,   524,   525,    -1,    -1,   528,   529,    -1,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    -1,   541,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   760,    -1,    -1,
      -1,    -1,   765,    -1,    -1,   540,    -1,    -1,    -1,    -1,
      -1,    -1,   565,    -1,    -1,   109,   779,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   790,    -1,    -1,
      13,    -1,    -1,   127,    -1,    18,   799,    -1,    -1,    -1,
     803,    -1,    25,    26,   807,    -1,    -1,   141,   583,   143,
      33,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    30,   842,
      32,    33,    -1,    -1,    36,   638,   639,    -1,    40,    -1,
      42,    -1,   645,    -1,   647,    -1,    -1,    -1,    -1,   652,
      -1,    -1,   655,    -1,    -1,   658,    58,    -1,    60,    61,
      -1,    63,    64,   648,    -1,   650,    -1,   100,   653,   102,
      -1,   656,   885,   886,   887,   888,    -1,    -1,    -1,    81,
     665,    83,    -1,   668,    -1,    -1,    -1,    -1,    -1,    -1,
     903,   904,   695,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   687,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   699,    -1,   701,    -1,    -1,    -1,
     705,    -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,   162,
     132,    -1,    -1,    -1,   167,    -1,   169,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   179,    -1,    -1,   182,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   195,   196,    -1,    -1,   199,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,   792,
      -1,    -1,    -1,    -1,   779,    10,    -1,    -1,    -1,    -1,
      15,    -1,    -1,    -1,    -1,   790,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   799,    -1,    -1,    -1,   803,    -1,
      -1,    -1,   807,    -1,    -1,   258,   259,   260,   261,    -1,
      -1,    -1,   835,   836,    -1,   838,   839,    -1,    -1,    -1,
      -1,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   856,    -1,    -1,    -1,   842,    -1,   862,
      -1,   864,    -1,   866,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   308,   309,    -1,    -1,    94,
      95,    96,    97,    98,    99,    -1,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,    -1,    -1,   114,
      -1,    -1,   335,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,   130,    -1,    -1,   133,   134,
     135,   136,    -1,   138,    -1,    -1,   141,    -1,   931,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   370,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   378,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   392,
      -1,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    12,    13,
      14,    -1,    -1,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   425,    27,    28,   428,    30,   430,    32,    33,
      34,    35,    36,    37,    -1,    39,    40,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    -1,
      -1,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    -1,    77,    -1,    79,    80,    81,    -1,    83,
      84,    85,    -1,    -1,    88,    -1,    90,    -1,    -1,    93,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,   109,   110,   111,    -1,    -1,
      -1,    -1,   116,    -1,   517,    -1,    -1,    -1,    -1,    -1,
      -1,   125,    -1,   127,    -1,   129,   130,    -1,   132,    65,
      -1,   135,    -1,    69,    -1,   139,    -1,   141,    -1,   143,
      -1,    -1,   545,    -1,    -1,    -1,   549,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,
      -1,    -1,   565,    -1,    -1,    -1,   569,    -1,    -1,    -1,
      -1,    -1,   108,    -1,   110,   111,   112,    -1,   114,   115,
     116,    -1,   118,   119,   120,   121,    -1,   123,   124,   125,
     126,    -1,   128,   129,   130,    -1,   599,   133,   134,   135,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    12,    13,    14,    15,    -1,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    32,    33,    34,    35,    36,    37,    -1,
      39,    40,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    52,    -1,    -1,    -1,    56,    57,   672,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    -1,    77,   692,
      79,    80,    81,    -1,    83,    84,    85,    -1,    -1,    88,
      -1,    90,    -1,    -1,    93,    -1,    -1,   710,    -1,    -1,
      -1,    -1,    -1,    -1,   717,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,   113,   114,   115,   116,    -1,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,   132,   133,   134,   135,    -1,    -1,    -1,
     139,   140,   141,     1,   143,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    12,    13,    14,    -1,    -1,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    27,
      28,    -1,    30,    -1,    32,    33,    34,    35,    36,    37,
      -1,    39,    40,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    52,    -1,   809,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,   820,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    -1,    77,
      -1,    79,    80,    81,    -1,    83,    84,    85,    -1,    -1,
      88,    -1,    90,    -1,    -1,    93,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,   127,
      -1,   129,   130,   131,   132,    -1,    -1,   135,    -1,    -1,
      -1,   139,   140,   141,     1,   143,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    13,    14,    -1,    -1,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      27,    28,    -1,    30,    -1,    32,    33,    34,    35,    36,
      37,    -1,    39,    40,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    52,    -1,    -1,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    -1,
      77,    -1,    79,    80,    81,    -1,    83,    84,    85,    -1,
      -1,    88,    -1,    90,    -1,    -1,    93,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,
     127,    -1,   129,   130,    -1,   132,    -1,    -1,   135,    -1,
      -1,    -1,   139,   140,   141,     1,   143,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    12,    13,    14,    -1,
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    27,    28,    -1,    30,    -1,    32,    33,    34,    35,
      36,    37,    -1,    39,    40,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    52,    -1,    -1,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    -1,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      -1,    77,    -1,    79,    80,    81,    -1,    83,    84,    85,
      -1,    -1,    88,    -1,    90,    -1,    -1,    93,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
     116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
      -1,   127,    -1,   129,   130,    -1,   132,    -1,    -1,   135,
      -1,    -1,    -1,   139,   140,   141,     1,   143,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    13,    14,
      -1,    -1,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,    28,    -1,    30,    -1,    32,    33,    34,
      35,    36,    37,    -1,    39,    40,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    52,    -1,    -1,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      -1,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    -1,    77,    -1,    79,    80,    81,    -1,    83,    84,
      85,    -1,    -1,    88,    -1,    90,    -1,    -1,    93,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,    -1,    -1,    -1,
      -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     125,    -1,   127,    -1,   129,   130,    -1,   132,    -1,    -1,
     135,    -1,    -1,    -1,   139,   140,   141,     1,   143,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    12,    13,
      14,    -1,    -1,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    27,    28,    -1,    30,    -1,    32,    33,
      34,    35,    36,    37,    -1,    39,    40,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    -1,
      -1,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    -1,    77,    -1,    79,    80,    81,    -1,    83,
      84,    85,    -1,    -1,    88,    -1,    90,    -1,    -1,    93,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,   109,   110,   111,    -1,    -1,
      -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   125,    -1,   127,    -1,   129,   130,    -1,   132,    -1,
      -1,   135,    -1,    -1,    -1,   139,   140,   141,     1,   143,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      13,    14,    -1,    -1,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    27,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    37,    -1,    39,    40,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      -1,    -1,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    -1,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    -1,    77,    -1,    79,    80,    81,    -1,
      83,    84,    85,    -1,    -1,    88,    -1,    90,    -1,    -1,
      93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,    -1,
      -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   125,    -1,   127,    -1,   129,   130,    -1,   132,
      -1,    -1,   135,    -1,    -1,    -1,   139,    -1,   141,     1,
     143,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      12,    13,    14,    -1,    -1,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    27,    28,    -1,    30,    -1,
      32,    33,    34,    35,    36,    37,    -1,    39,    40,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      52,    -1,    -1,    -1,    56,    57,    -1,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    -1,    77,    -1,    79,    80,    81,
      -1,    83,    84,    85,    -1,    -1,    88,    -1,    90,    -1,
      -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,
      -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   125,    -1,   127,    -1,   129,   130,    -1,
     132,    -1,    -1,   135,    -1,    -1,    -1,   139,    -1,   141,
       1,   143,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    13,    14,    -1,    -1,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    27,    28,    -1,    30,
      -1,    32,    33,    34,    35,    36,    37,    -1,    39,    40,
      -1,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    52,    -1,    -1,    -1,    56,    57,    -1,    59,    60,
      61,    62,    63,    64,    -1,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    -1,    77,    -1,    79,    80,
      81,    -1,    83,    84,    85,    -1,    -1,    88,    -1,    90,
      -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,    -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,    -1,   127,    -1,   129,   130,
      -1,   132,    -1,    -1,   135,    -1,    -1,    -1,   139,    -1,
     141,     1,   143,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    12,    13,    14,    -1,    -1,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,    28,    -1,
      30,    -1,    32,    33,    34,    35,    36,    37,    -1,    39,
      40,    -1,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    52,    -1,    -1,    -1,    56,    57,    -1,    59,
      60,    61,    62,    63,    64,    -1,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    -1,    77,    -1,    79,
      80,    81,    -1,    83,    84,    85,    -1,    -1,    88,    -1,
      90,    -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,
     110,   111,    -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   125,    -1,   127,    -1,   129,
     130,    -1,   132,    -1,    -1,   135,    -1,    -1,    -1,   139,
      -1,   141,     1,   143,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    12,    13,    14,    -1,    -1,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    27,    28,
      -1,    30,    -1,    32,    33,    34,    35,    36,    37,    -1,
      39,    40,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    52,    -1,    -1,    -1,    56,    57,    -1,
      59,    60,    61,    62,    63,    64,    -1,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    -1,    77,    -1,
      79,    80,    81,    -1,    83,    84,    85,    -1,    -1,    88,
      -1,    90,    -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,    -1,    -1,    -1,    -1,   116,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,   127,    -1,
     129,   130,    -1,   132,    -1,    -1,   135,    -1,    -1,    -1,
     139,    -1,   141,     1,   143,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    12,    13,    14,    -1,    -1,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    27,
      28,    -1,    30,    -1,    32,    33,    34,    35,    36,    37,
      -1,    39,    40,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    52,    -1,    -1,    -1,    56,    57,
      -1,    59,    60,    61,    62,    63,    64,    -1,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    -1,    77,
      -1,    79,    80,    81,    -1,    83,    84,    85,    -1,    -1,
      88,    -1,    90,    -1,    -1,    93,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,   127,
      -1,   129,   130,    -1,   132,    -1,    -1,   135,    -1,    -1,
      -1,   139,    -1,   141,     1,   143,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    12,    13,    14,    -1,    -1,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      27,    28,    -1,    30,    -1,    32,    33,    34,    35,    36,
      37,    -1,    39,    40,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    52,    -1,    -1,    -1,    56,
      57,    -1,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    -1,
      77,    -1,    79,    80,    81,    -1,    83,    84,    85,    -1,
      -1,    88,    -1,    90,    -1,    -1,    93,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,
     127,    -1,   129,   130,    -1,   132,    -1,    -1,   135,    -1,
      -1,    -1,   139,    -1,   141,     1,   143,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    12,    13,    14,    -1,
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    27,    28,    -1,    30,    -1,    32,    33,    34,    35,
      36,    37,    -1,    39,    40,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    52,    -1,    -1,    -1,
      56,    57,    -1,    59,    60,    61,    62,    63,    64,    -1,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      -1,    77,    -1,    79,    80,    81,    -1,    83,    84,    85,
      -1,    -1,    88,    -1,    90,    -1,    -1,    93,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
     116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
      -1,   127,    -1,   129,   130,    -1,   132,    -1,    -1,   135,
      -1,    -1,    -1,   139,    -1,   141,     1,   143,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    13,    14,
      -1,    -1,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,    28,    -1,    30,    -1,    32,    33,    34,
      35,    36,    37,    -1,    39,    40,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    52,    -1,    -1,
      -1,    56,    57,    -1,    59,    60,    61,    62,    63,    64,
      -1,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    -1,    77,    -1,    79,    80,    81,    -1,    83,    84,
      85,    -1,    -1,    88,    -1,    90,    -1,    -1,    93,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,    -1,    -1,    -1,
      -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     125,    -1,   127,    -1,   129,   130,    -1,   132,    -1,    -1,
     135,    -1,    -1,    -1,   139,    -1,   141,     1,   143,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    12,    13,
      14,    -1,    -1,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    27,    28,    -1,    30,    -1,    32,    33,
      34,    35,    36,    37,    -1,    39,    40,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    -1,
      -1,    -1,    56,    57,    -1,    59,    60,    61,    62,    63,
      64,    -1,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    -1,    77,    -1,    79,    80,    81,    -1,    83,
      84,    85,    -1,    -1,    88,    -1,    90,    -1,    -1,    93,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,   109,   110,   111,    -1,    -1,
      -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   125,    -1,   127,    -1,   129,   130,    -1,   132,    -1,
      -1,   135,    -1,    -1,    -1,   139,    -1,   141,     1,   143,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      13,    14,    -1,    -1,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    27,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    37,    -1,    39,    40,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      -1,    -1,    -1,    56,    57,    -1,    59,    60,    61,    62,
      63,    64,    -1,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    -1,    77,    -1,    79,    80,    81,    -1,
      83,    84,    85,    -1,    -1,    88,    -1,    90,    -1,    -1,
      93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,    -1,
      -1,    -1,     1,   116,     3,     4,     5,     6,     7,     8,
      -1,    -1,   125,    12,   127,    -1,   129,   130,    -1,   132,
      -1,    -1,   135,    -1,    -1,    -1,   139,    -1,   141,    28,
     143,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,    -1,
      39,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,    -1,
      49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,    -1,    -1,    -1,    -1,   116,     3,     4,
       5,     6,     7,     8,    -1,    -1,   125,    12,   127,    -1,
     129,   130,   131,    -1,    -1,    -1,   135,    -1,    -1,    -1,
     139,    -1,   141,    28,   143,    -1,    -1,    -1,    -1,    34,
      35,    -1,    37,    -1,    39,    -1,    -1,    -1,    -1,    44,
      45,    -1,    47,    -1,    49,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,    -1,    -1,    -1,
      -1,   116,     3,     4,     5,     6,     7,     8,    -1,    -1,
     125,    12,   127,    -1,   129,   130,   131,    -1,    -1,    -1,
     135,    -1,    -1,    -1,   139,    -1,   141,    28,   143,   144,
      -1,    -1,    -1,    34,    35,    -1,    37,    -1,    39,    -1,
      -1,    -1,    -1,    44,    45,    -1,    47,    -1,    49,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,    -1,    -1,    -1,    -1,   116,     3,     4,     5,     6,
       7,     8,    -1,    -1,   125,    12,   127,    -1,   129,   130,
     131,    -1,    -1,    -1,   135,    -1,    -1,    -1,   139,    -1,
     141,    28,   143,   144,    -1,    -1,    -1,    34,    35,    -1,
      37,    -1,    39,    -1,    -1,    -1,    -1,    44,    45,    -1,
      47,    -1,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    75,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,    -1,    -1,    93,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,
      -1,    -1,   136,   137,   138,    -1,    -1,   141,   125,   143,
     127,    -1,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,
      -1,    -1,   139,    -1,   141,    -1,   143,   144,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    -1,    41,    -1,    -1,    44,
      45,    -1,    47,    -1,    49,    50,    -1,    -1,    -1,    -1,
      55,    56,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,    -1,    -1,    -1,
      -1,   116,     3,     4,     5,     6,     7,     8,    -1,    -1,
     125,    12,   127,    -1,   129,   130,    -1,    -1,    -1,    -1,
     135,    -1,    -1,    -1,   139,    -1,   141,    28,   143,    -1,
      -1,    -1,    -1,    34,    35,    -1,    37,    -1,    39,    -1,
      -1,    -1,    -1,    44,    45,    -1,    47,    -1,    49,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    75,    -1,    -1,    -1,    79,    80,
      -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,    -1,    -1,    -1,    -1,   116,   117,    -1,     3,     4,
       5,     6,     7,     8,   125,    -1,   127,    12,   129,   130,
     131,    -1,    -1,    -1,   135,    -1,    -1,    -1,   139,    -1,
     141,    -1,   143,    28,    -1,    -1,    -1,    -1,    -1,    34,
      35,    -1,    37,    -1,    39,    -1,    -1,    -1,    -1,    44,
      45,    -1,    47,    -1,    49,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      75,    -1,    -1,    -1,    79,    80,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,    -1,    -1,    -1,
      -1,   116,    -1,    -1,     3,     4,     5,     6,     7,     8,
     125,    -1,   127,    12,   129,   130,   131,    -1,    -1,    -1,
     135,    -1,    -1,    -1,   139,    -1,   141,   142,   143,    28,
      -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,    -1,
      39,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,    -1,
      49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    -1,    -1,    -1,
      79,    80,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,    -1,    -1,    -1,    -1,   116,    -1,    -1,
       3,     4,     5,     6,     7,     8,   125,    -1,   127,    12,
     129,   130,   131,    -1,    65,    -1,   135,    -1,    69,    -1,
     139,    -1,   141,   142,   143,    28,    -1,    -1,    -1,    -1,
      -1,    34,    35,    -1,    37,    -1,    39,    -1,    -1,    -1,
      -1,    44,    45,    -1,    47,    -1,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    57,    -1,    59,   108,    -1,   110,
     111,   112,    -1,   114,   115,   116,    -1,    -1,   119,    72,
      73,    74,    75,    -1,   125,   126,    79,    80,    -1,   130,
      -1,    -1,   133,   134,   135,    -1,    -1,    -1,    -1,    -1,
      93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,    -1,
      -1,    -1,    -1,   116,     3,     4,     5,     6,     7,     8,
      -1,    -1,   125,    12,   127,    -1,   129,   130,    -1,   132,
      -1,    -1,   135,    -1,    -1,    -1,   139,    -1,   141,    28,
     143,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,    -1,
      39,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,    -1,
      49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    -1,    -1,    -1,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,    -1,    -1,    -1,    -1,   116,     3,     4,
       5,     6,     7,     8,    -1,    -1,   125,    12,   127,    -1,
     129,   130,   131,    -1,    -1,    -1,   135,    -1,    -1,    -1,
     139,    -1,   141,    28,   143,    -1,    -1,    -1,    -1,    34,
      35,    -1,    37,    -1,    39,    -1,    -1,    -1,    -1,    44,
      45,    -1,    47,    -1,    49,    50,    51,    -1,    -1,    -1,
      -1,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      75,    -1,    -1,    -1,    79,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,    -1,    -1,    -1,
      -1,   116,     3,     4,     5,     6,     7,     8,    -1,    -1,
     125,    12,   127,    -1,   129,   130,    -1,    -1,    -1,    -1,
     135,    -1,    -1,    -1,   139,    -1,   141,    28,   143,    -1,
      -1,    -1,    -1,    34,    35,    -1,    37,    -1,    39,    -1,
      -1,    -1,    -1,    44,    45,    -1,    47,    -1,    49,    50,
      -1,    -1,    -1,    -1,    -1,    56,    57,    -1,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,    -1,    -1,    -1,    -1,   116,     3,     4,     5,     6,
       7,     8,    -1,    -1,   125,    12,   127,    -1,   129,   130,
      -1,    -1,    -1,    20,   135,    -1,    -1,    -1,   139,    -1,
     141,    28,   143,    -1,    -1,    -1,    33,    34,    35,    -1,
      37,    -1,    39,    -1,    -1,    -1,    -1,    44,    45,    -1,
      47,    -1,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,
       3,     4,     5,     6,     7,     8,    -1,    -1,   125,    12,
     127,    -1,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,
      -1,    -1,   139,    -1,   141,    28,   143,    -1,    -1,    -1,
      -1,    34,    35,    -1,    37,    -1,    39,    -1,    -1,    -1,
      -1,    44,    45,    -1,    47,    -1,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    57,    -1,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    75,    -1,    -1,    -1,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,    -1,
      -1,    -1,    -1,   116,     3,     4,     5,     6,     7,     8,
      -1,    -1,   125,    12,   127,    -1,   129,   130,    -1,    -1,
      -1,    -1,   135,    -1,    -1,    -1,   139,    -1,   141,    28,
     143,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,    -1,
      39,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,    -1,
      49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,    -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,    -1,    -1,    -1,    -1,   116,    -1,    -1,
     136,   137,    -1,    -1,    -1,   141,   125,   143,   127,    -1,
     129,   130,   131,    -1,    -1,    -1,   135,    -1,    -1,    26,
     139,   140,   141,    -1,   143,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    -1,    -1,    -1,    -1,    -1,    34,    35,    65,    37,
      -1,    39,    69,    -1,    -1,    -1,    44,    45,    -1,    47,
      -1,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    75,    -1,    -1,
      -1,   108,    -1,   110,   111,   112,    -1,   114,   115,   116,
      -1,   118,   119,   120,   121,    93,   123,   124,   125,   126,
      -1,   128,    -1,   130,    -1,    -1,   133,   134,   135,    -1,
     108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,     3,
       4,     5,     6,     7,     8,    -1,    -1,   125,    12,   127,
      -1,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,    -1,
      -1,   139,    -1,   141,    28,   143,    -1,    -1,    -1,    -1,
      34,    35,    -1,    37,    -1,    39,    -1,    -1,    -1,    -1,
      44,    45,    -1,    47,    -1,    49,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,   109,   110,   111,    -1,    -1,
      -1,    -1,   116,     3,     4,     5,     6,     7,     8,    -1,
      -1,   125,    12,   127,    -1,   129,   130,   131,    -1,    -1,
      -1,   135,    -1,    -1,    -1,   139,    -1,   141,    28,   143,
      -1,    -1,    -1,    -1,    34,    35,    -1,    37,    -1,    39,
      -1,    -1,    -1,    -1,    44,    45,    -1,    47,    -1,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,
     110,   111,    -1,    -1,    -1,    -1,   116,     3,     4,     5,
       6,     7,     8,    -1,    -1,   125,    12,   127,    -1,   129,
     130,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,   139,
      -1,   141,    28,   143,    -1,    -1,    -1,    -1,    34,    35,
      -1,    37,    -1,    39,    -1,    -1,    -1,    -1,    44,    45,
      -1,    47,    -1,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
     116,     3,     4,     5,     6,     7,     8,    -1,    -1,   125,
      12,   127,    -1,   129,   130,   131,    -1,    -1,    -1,   135,
      -1,    -1,    -1,   139,    -1,   141,    28,   143,    -1,    -1,
      -1,    -1,    34,    35,    -1,    37,    -1,    39,    -1,    -1,
      -1,    -1,    44,    45,    -1,    47,    -1,    49,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,
      -1,    -1,    -1,    -1,   116,     3,     4,     5,     6,     7,
       8,    -1,    -1,   125,    12,   127,    -1,   129,   130,   131,
      -1,    -1,    -1,   135,    -1,    -1,    -1,   139,    -1,   141,
      28,   143,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,
      -1,    39,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,
      -1,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,     3,
       4,     5,     6,     7,     8,    -1,    -1,   125,    12,   127,
      -1,   129,   130,   131,    -1,    -1,    -1,   135,    -1,    -1,
      -1,   139,    -1,   141,    28,   143,    -1,    -1,    -1,    -1,
      34,    35,    -1,    37,    -1,    39,    -1,    -1,    -1,    -1,
      44,    45,    -1,    47,    -1,    49,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,   109,   110,   111,    -1,    -1,
      -1,    -1,   116,     3,     4,     5,     6,     7,     8,    -1,
      -1,   125,    12,   127,    -1,   129,   130,    -1,    -1,    -1,
      -1,   135,    -1,    -1,    -1,   139,    -1,   141,    28,   143,
      -1,    -1,    -1,    -1,    34,    35,    -1,    37,    -1,    39,
      -1,    -1,    -1,    -1,    44,    45,    -1,    47,    -1,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,
     110,   111,    -1,    -1,    -1,    -1,   116,     3,     4,     5,
       6,     7,     8,    -1,    -1,   125,    12,   127,    -1,   129,
     130,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,   139,
      -1,   141,    28,   143,    -1,    -1,    -1,    -1,    34,    35,
      -1,    37,    -1,    39,    -1,    -1,    -1,    -1,    44,    45,
      -1,    47,    -1,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
     116,     3,     4,     5,     6,     7,     8,    -1,    -1,   125,
      12,   127,    -1,   129,   130,    -1,    -1,    -1,    -1,   135,
      -1,    -1,    -1,   139,    -1,   141,    28,   143,    -1,    -1,
      -1,    -1,    34,    35,    -1,    37,    -1,    39,    -1,    -1,
      -1,    -1,    44,    45,    -1,    47,    -1,    49,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,
      -1,    -1,    -1,    -1,   116,     3,     4,     5,     6,     7,
       8,    -1,    -1,   125,    12,   127,    -1,   129,   130,    -1,
      -1,    -1,    -1,   135,    -1,    -1,    -1,   139,    -1,   141,
      28,   143,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,
      -1,    39,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,
      -1,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,     3,
       4,     5,     6,     7,     8,    -1,    -1,   125,    12,   127,
      -1,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,    -1,
      -1,   139,    -1,   141,    28,   143,    -1,    -1,    -1,    -1,
      34,    35,    -1,    37,    -1,    39,    -1,    -1,    -1,    -1,
      44,    45,    -1,    47,    -1,    49,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,   109,   110,   111,    -1,    -1,
      -1,    -1,   116,     3,     4,     5,     6,     7,     8,    -1,
      -1,   125,    12,   127,    -1,   129,   130,    -1,    -1,    -1,
      -1,   135,    -1,    -1,    -1,   139,    -1,   141,    28,   143,
      -1,    -1,    -1,    -1,    34,    35,    -1,    37,    -1,    39,
      -1,    -1,    -1,    -1,    44,    45,    -1,    47,    -1,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,
     110,   111,    -1,    -1,    -1,    -1,   116,     3,     4,     5,
       6,     7,     8,    -1,    -1,   125,    12,   127,    -1,   129,
     130,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,   139,
      -1,   141,    28,   143,    -1,    -1,    -1,    -1,    34,    35,
      -1,    37,    -1,    39,    -1,    -1,    -1,    -1,    44,    45,
      -1,    47,    -1,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
     116,     3,     4,     5,     6,     7,     8,    -1,    -1,   125,
      12,   127,    -1,   129,   130,    -1,    -1,    -1,    -1,   135,
      -1,    -1,    -1,   139,    -1,   141,    28,   143,    -1,    -1,
      -1,    -1,    34,    35,    -1,    37,    -1,    39,    -1,    -1,
      -1,    -1,    44,    45,    -1,    47,    -1,    49,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,
      -1,    -1,    -1,    -1,   116,     3,     4,     5,     6,     7,
       8,    -1,    -1,   125,    12,   127,    -1,   129,   130,    -1,
      -1,    -1,    -1,   135,    -1,    -1,    -1,   139,    -1,   141,
      28,   143,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,
      -1,    39,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,
      -1,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,     3,
       4,     5,     6,     7,     8,    -1,    -1,   125,    12,   127,
      -1,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,    -1,
      -1,   139,    -1,   141,    28,   143,    -1,    -1,    -1,    -1,
      34,    35,    -1,    37,    -1,    39,    -1,    -1,    -1,    -1,
      44,    45,    -1,    47,    -1,    49,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,   109,   110,   111,    -1,    -1,
      -1,    -1,   116,     3,     4,     5,     6,     7,     8,    -1,
      -1,   125,    12,   127,    -1,   129,   130,    -1,    -1,    -1,
      -1,   135,    -1,    -1,    -1,   139,    -1,   141,    28,   143,
      -1,    -1,    -1,    -1,    34,    35,    -1,    37,    -1,    39,
      -1,    -1,    -1,    -1,    44,    45,    -1,    47,    -1,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,
     110,   111,    -1,    -1,    -1,    -1,   116,     3,     4,     5,
       6,     7,     8,    -1,    -1,   125,    12,   127,    -1,   129,
     130,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,   139,
      -1,   141,    28,   143,    -1,    -1,    -1,    -1,    34,    35,
      -1,    37,    -1,    39,    -1,    -1,    -1,    -1,    44,    45,
      -1,    47,    -1,    49,    50,     3,     4,     5,     6,     7,
       8,    57,    -1,    59,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    75,
      28,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,
      -1,    39,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,
      -1,    49,    50,    10,    -1,    -1,    -1,    -1,    15,    57,
      -1,    59,   108,   109,   110,   111,    -1,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    72,    73,    74,    75,    -1,   125,
      -1,   127,    -1,    -1,   130,    -1,    -1,    -1,    -1,   135,
      -1,    -1,    -1,   139,    -1,   141,    94,   143,    -1,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    15,    -1,    65,    -1,
      -1,   109,    69,    -1,    -1,   113,    -1,    26,    -1,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
      -1,    -1,    -1,   131,    -1,    -1,    93,    -1,    -1,    -1,
      -1,   139,    -1,   141,   142,   143,    -1,    -1,    -1,    -1,
      -1,   108,    -1,   110,   111,   112,    65,   114,   115,   116,
      69,   118,   119,   120,   121,   122,   123,   124,   125,   126,
      -1,   128,   129,   130,    10,    -1,   133,   134,   135,    15,
      -1,    -1,    -1,    -1,    93,    -1,    -1,   144,    -1,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
      -1,   110,   111,   112,    -1,   114,   115,   116,    -1,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    10,   128,
     129,   130,    -1,    15,   133,   134,   135,    -1,    -1,    65,
      -1,    -1,    -1,    69,    26,   144,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,    65,   110,   111,   112,    69,   114,   115,
     116,    -1,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,   128,   129,   130,    -1,    -1,   133,   134,   135,
      -1,    93,    -1,    -1,    -1,    10,    -1,    -1,   144,    -1,
      15,    -1,    -1,    -1,    -1,    -1,   108,    -1,   110,   111,
     112,    26,   114,   115,   116,    -1,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,   128,   129,   130,    -1,
      -1,   133,   134,   135,    -1,    -1,    -1,    -1,    -1,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    -1,    -1,    -1,    69,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    93,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,    -1,   110,   111,   112,    -1,   114,
     115,   116,    -1,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    65,   128,   129,   130,    69,    -1,   133,   134,
     135,    -1,    -1,    76,    -1,    -1,    -1,   142,    -1,    -1,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    15,    -1,    -1,
      93,    94,    95,    96,    97,    98,    99,    -1,    26,   102,
     103,   104,   105,   106,   107,   108,    -1,   110,   111,   112,
      -1,   114,   115,   116,    -1,   118,   119,   120,   121,   122,
     123,   124,   125,   126,    -1,   128,   129,   130,    -1,    -1,
     133,   134,   135,    -1,    -1,    -1,   139,    65,    -1,    -1,
      -1,    69,    -1,    -1,    10,    -1,    -1,    -1,    76,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    -1,    -1,    -1,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,   102,   103,   104,   105,   106,   107,
     108,    -1,   110,   111,   112,    -1,   114,   115,   116,    -1,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    65,
     128,   129,   130,    69,    -1,   133,   134,   135,    -1,    -1,
      76,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    15,    -1,    -1,    93,    94,    95,
      96,    97,    98,    99,    -1,    26,   102,   103,   104,   105,
     106,   107,   108,    -1,   110,   111,   112,    -1,   114,   115,
     116,    -1,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,   128,   129,   130,    -1,    -1,   133,   134,   135,
      -1,    -1,    -1,   139,    65,    -1,    -1,    -1,    69,    -1,
      -1,    10,    -1,    -1,    -1,    76,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    93,    94,    95,    96,    97,    98,    99,    -1,
      -1,   102,   103,   104,   105,   106,   107,   108,    -1,   110,
     111,   112,    -1,   114,   115,   116,    -1,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    65,   128,   129,   130,
      69,    -1,   133,   134,   135,    -1,    -1,    76,   139,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    15,    -1,    -1,    93,    94,    95,    96,    97,    98,
      99,    -1,    26,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,   111,   112,    -1,   114,   115,   116,    -1,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    -1,   128,
     129,   130,    -1,    -1,   133,   134,   135,    -1,    -1,    -1,
     139,    65,    -1,    -1,    -1,    69,    -1,    -1,    10,    -1,
      -1,    -1,    76,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    93,
      94,    95,    96,    97,    98,    99,    -1,    -1,   102,   103,
     104,   105,   106,   107,   108,    -1,   110,   111,   112,    -1,
     114,   115,   116,    -1,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    65,   128,   129,   130,    69,    -1,   133,
     134,   135,    -1,    -1,    76,   139,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    93,    94,    95,    96,    97,    98,    99,    -1,    26,
     102,   103,   104,   105,   106,   107,   108,    -1,   110,   111,
     112,    -1,   114,   115,   116,    -1,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,   128,   129,   130,    -1,
      -1,   133,   134,   135,    -1,    -1,    -1,   139,    65,    -1,
      -1,    -1,    69,    -1,    -1,    10,    -1,    -1,    -1,    76,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    93,    94,    95,    96,
      97,    98,    99,    -1,    -1,   102,   103,   104,   105,   106,
     107,   108,    -1,   110,   111,   112,    -1,   114,   115,   116,
      -1,   118,   119,   120,   121,   122,   123,   124,   125,   126,
      65,   128,   129,   130,    69,    -1,   133,   134,   135,    -1,
      -1,    76,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
      95,    96,    97,    98,    99,    -1,    -1,   102,   103,   104,
     105,   106,   107,   108,    -1,   110,   111,   112,    -1,   114,
     115,   116,    -1,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    10,   128,   129,   130,    -1,    15,   133,   134,
     135,    -1,    -1,    -1,   139,    -1,    -1,    -1,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    27,    -1,    -1,    -1,    65,    -1,    -1,
      -1,    69,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,
      -1,    65,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,
     108,    -1,   110,   111,   112,    -1,   114,   115,   116,    -1,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    93,
     128,   129,   130,    -1,    -1,   133,   134,   135,    -1,    -1,
      -1,   139,    -1,    -1,   108,    -1,   110,   111,   112,    -1,
     114,   115,   116,    -1,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    10,   128,   129,   130,    -1,    15,   133,
     134,   135,    -1,    -1,    -1,   139,    -1,    -1,    -1,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    65,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      15,    -1,    89,    -1,    -1,    -1,    93,    -1,    -1,    -1,
      -1,    26,    65,    -1,    -1,    -1,    69,    -1,    -1,    -1,
      -1,   108,    -1,   110,   111,   112,    -1,   114,   115,   116,
      -1,   118,   119,   120,   121,   122,   123,   124,   125,   126,
      93,   128,   129,   130,    -1,    -1,   133,   134,   135,    -1,
      65,    -1,   139,    -1,    69,   108,    -1,   110,   111,   112,
      -1,   114,   115,   116,    -1,   118,   119,   120,   121,   122,
     123,   124,   125,   126,    10,   128,   129,   130,    93,    15,
     133,   134,   135,    -1,    -1,    -1,   139,    -1,    -1,    -1,
      26,    27,    -1,   108,    -1,   110,   111,   112,    -1,   114,
     115,   116,    -1,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    -1,   128,   129,   130,    -1,    -1,   133,   134,
     135,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    -1,    69,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    -1,    -1,    -1,    -1,    93,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,    -1,   110,   111,   112,    -1,   114,   115,
     116,    -1,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    65,   128,   129,   130,    69,    -1,   133,   134,   135,
      -1,    -1,    76,   139,    -1,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,    -1,   110,   111,   112,    -1,
     114,   115,   116,    -1,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,   128,   129,   130,    -1,    -1,   133,
     134,   135,    65,    -1,    -1,   139,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      93,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    31,    -1,    -1,   108,    -1,   110,   111,   112,
      -1,   114,   115,   116,    -1,   118,   119,   120,   121,   122,
     123,   124,   125,   126,    53,   128,   129,   130,    -1,    10,
     133,   134,   135,    -1,    15,   138,    65,    -1,    -1,    -1,
      69,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,   108,
      -1,   110,   111,   112,    65,   114,   115,   116,    69,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    -1,   128,
     129,   130,    -1,   132,   133,   134,   135,    -1,    89,    -1,
      -1,    -1,    93,    -1,    65,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,   110,
     111,   112,    -1,   114,   115,   116,    -1,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    10,   128,   129,   130,
      -1,    15,   133,   134,   135,    -1,    -1,   108,    -1,   110,
     111,   112,    26,   114,   115,   116,    -1,    31,   119,   120,
     121,    -1,   123,   124,   125,   126,    -1,    -1,    -1,   130,
      10,    -1,   133,   134,   135,    15,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,    -1,
      -1,    65,    -1,    -1,    -1,    69,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    93,
      -1,    -1,    -1,    -1,    26,    65,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    -1,   108,    -1,   110,   111,   112,    -1,
     114,   115,   116,    -1,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    93,   128,   129,   130,    -1,    -1,   133,
     134,   135,    -1,    65,    -1,    -1,    -1,    69,   108,    -1,
     110,   111,   112,    -1,   114,   115,   116,    -1,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    10,   128,   129,
     130,    93,    15,   133,   134,   135,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    -1,   108,    -1,   110,   111,
     112,    -1,   114,   115,   116,    38,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,   128,   129,   130,    -1,
     132,   133,   134,   135,    -1,    10,    -1,    -1,    -1,    -1,
      15,    -1,    65,    -1,    -1,    -1,    69,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,    -1,   110,   111,   112,
      65,   114,   115,   116,    69,   118,   119,   120,   121,   122,
     123,   124,   125,   126,    -1,   128,   129,   130,    10,    -1,
     133,   134,   135,    15,    -1,    -1,    -1,    -1,    93,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,    -1,   110,   111,   112,    -1,   114,
     115,   116,    -1,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    -1,   128,   129,   130,    10,   132,   133,   134,
     135,    15,    -1,    65,    -1,    -1,    -1,    69,    -1,    -1,
      -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,   110,   111,
     112,    65,   114,   115,   116,    69,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,   128,   129,   130,    10,
     132,   133,   134,   135,    15,    -1,    -1,    -1,    -1,    93,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,    -1,   110,   111,   112,    -1,
     114,   115,   116,    -1,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,   128,   129,   130,    -1,   132,   133,
     134,   135,    -1,    -1,    65,    -1,    -1,    -1,    69,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    92,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,   110,
     111,   112,    -1,   114,   115,   116,    -1,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    65,   128,   129,   130,
      69,    -1,   133,   134,   135,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
      -1,   110,   111,   112,    -1,   114,   115,   116,    -1,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    -1,   128,
     129,   130,    -1,    -1,   133,   134,   135,    65,    -1,    -1,
      -1,    69,    -1,    -1,    10,    -1,    -1,    -1,    -1,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    89,    -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,    -1,   110,   111,   112,    -1,   114,   115,   116,    -1,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    65,
     128,   129,   130,    69,    -1,   133,   134,   135,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    11,    -1,    -1,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,    -1,   110,   111,   112,    -1,   114,   115,
     116,    -1,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,   128,   129,   130,    -1,   132,   133,   134,   135,
      65,    -1,    -1,    -1,    69,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    29,    -1,    93,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,    -1,   110,   111,   112,    -1,   114,
     115,   116,    -1,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    65,   128,   129,   130,    69,    -1,   133,   134,
     135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,    -1,   110,   111,   112,
      -1,   114,   115,   116,    -1,   118,   119,   120,   121,   122,
     123,   124,   125,   126,    -1,   128,   129,   130,    -1,    -1,
     133,   134,   135,    65,    -1,    -1,    -1,    69,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,    -1,
      92,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,   110,   111,
     112,    -1,   114,   115,   116,    -1,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    65,   128,   129,   130,    69,
      -1,   133,   134,   135,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    -1,    -1,    -1,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,
     110,   111,   112,    -1,   114,   115,   116,    -1,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,   128,   129,
     130,    -1,    -1,   133,   134,   135,    65,    -1,    -1,    -1,
      69,    -1,    -1,    10,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
      -1,   110,   111,   112,    -1,   114,   115,   116,    -1,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    65,   128,
     129,   130,    69,    -1,   133,   134,   135,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,    -1,   110,   111,   112,    -1,   114,   115,   116,
      -1,   118,   119,   120,   121,   122,   123,   124,   125,   126,
      -1,   128,   129,   130,    -1,    -1,   133,   134,   135,    65,
      -1,    -1,    -1,    69,    -1,    -1,    10,    11,    -1,    -1,
      76,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    -1,    -1,    -1,    -1,    93,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,    -1,   110,   111,   112,    -1,   114,   115,
     116,    -1,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    65,   128,   129,   130,    69,    -1,   133,   134,   135,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,    -1,   110,   111,   112,    -1,
     114,   115,   116,    -1,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,   128,   129,   130,    -1,    -1,   133,
     134,   135,    65,    -1,    -1,    -1,    69,    -1,    -1,    10,
      -1,    -1,    -1,    76,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,    -1,   110,   111,   112,
      -1,   114,   115,   116,    -1,   118,   119,   120,   121,   122,
     123,   124,   125,   126,    65,   128,   129,   130,    69,    -1,
     133,   134,   135,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    -1,    -1,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,   110,
     111,   112,    -1,   114,   115,   116,    -1,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    -1,   128,   129,   130,
      -1,    -1,   133,   134,   135,    65,    -1,    -1,    -1,    69,
      -1,    -1,    10,    -1,    -1,    -1,    76,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,
      -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,
     110,   111,   112,    -1,   114,   115,   116,    -1,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    65,   128,   129,
     130,    69,    -1,   133,   134,   135,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,    -1,   110,   111,   112,    -1,   114,   115,   116,    -1,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    -1,
     128,   129,   130,    -1,    -1,   133,   134,   135,    65,    -1,
      -1,    -1,    69,    -1,    -1,    10,    -1,    -1,    -1,    76,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,    -1,   110,   111,   112,    -1,   114,   115,   116,
      -1,   118,   119,   120,   121,   122,   123,   124,   125,   126,
      65,   128,   129,   130,    69,    -1,   133,   134,   135,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,
      -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,    -1,   110,   111,   112,    -1,   114,
     115,   116,    -1,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    -1,   128,   129,   130,    -1,    -1,   133,   134,
     135,    65,    -1,    -1,    -1,    69,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    93,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,    -1,   110,   111,   112,    -1,
     114,   115,   116,    -1,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    65,   128,   129,   130,    69,    -1,   133,
     134,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,   110,   111,
     112,    -1,   114,   115,   116,    -1,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,   128,   129,   130,    -1,
      -1,   133,   134,   135
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   149,   150,     0,     1,     3,     4,     5,     6,     7,
       8,    12,    13,    14,    17,    18,    19,    20,    22,    23,
      24,    25,    27,    28,    30,    32,    33,    34,    35,    36,
      37,    39,    40,    43,    44,    45,    46,    47,    49,    50,
      52,    57,    58,    59,    60,    63,    64,    67,    68,    70,
      71,    72,    73,    74,    75,    77,    79,    80,    81,    83,
      84,    88,    90,    93,   108,   109,   110,   111,   116,   125,
     127,   129,   130,   132,   135,   139,   141,   143,   151,   152,
     153,   154,   155,   157,   162,   163,   164,   166,   169,   170,
     171,   172,   173,   174,   176,   177,   178,   182,   183,   186,
     187,   190,   191,   194,   197,   198,   221,   224,   225,   243,
     244,   245,   246,   247,   248,   255,   256,   257,   258,   260,
     261,   262,   263,   264,   265,   267,   268,   269,   270,   271,
     132,   153,   258,    89,   249,   250,   165,   166,   249,    12,
      34,    35,    37,    75,   139,   143,   194,   243,   247,   256,
     257,   258,   260,   262,   263,    81,   165,   132,   153,   237,
     258,   153,   141,     7,   165,   167,     9,    81,   167,    56,
      91,   175,   258,   258,    20,    33,   224,   258,   258,   141,
     166,   195,   141,   166,   226,   227,    27,   157,   168,   258,
     258,   258,   258,   258,     7,   141,    33,   171,   171,   131,
     217,   236,   258,    79,    80,   132,   258,   259,   258,   168,
     258,   258,    74,   141,   153,   258,   258,   157,   164,   258,
     260,   157,   164,   258,   166,   222,   236,   258,   258,   258,
     258,   258,   258,   258,   258,     1,   140,   151,   158,   236,
      82,   117,   217,   238,   239,   259,   236,   258,   266,    58,
     153,    62,   156,   166,   166,    42,    61,   212,    21,    56,
      66,    85,   132,   138,    10,    15,    26,    65,    69,    93,
     108,   110,   111,   112,   114,   115,   116,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   128,   129,   130,   133,
     134,   135,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   136,   137,   141,   143,
      65,    69,   141,   153,   132,   139,   157,   258,   258,   258,
     236,    38,   249,   222,   132,   113,   132,    88,   166,   217,
     240,   241,   242,   259,   222,   187,   166,   141,   168,    27,
      38,   168,    27,    38,    89,   168,   252,    31,    53,   132,
      76,    94,    95,    96,    97,    98,    99,   102,   103,   104,
     105,   106,   107,   157,   204,   240,   153,   141,   206,    82,
     141,   166,   228,   229,     1,   112,   231,    38,   113,   153,
     168,   168,   240,   167,   166,   113,   132,   258,   258,   132,
     139,   168,   141,   240,   132,   179,   132,   179,   132,    94,
     223,   132,   132,    31,    53,   168,   132,   140,   140,   151,
     113,   140,   258,   113,   142,   113,   142,    38,   113,   144,
     252,    92,   113,   144,     7,    48,   112,   188,   139,   199,
      66,   226,   226,   226,   226,   258,   258,   258,   258,   175,
     258,   175,   258,   258,   258,   258,   258,   258,   258,    28,
      81,   166,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   240,   240,   175,   258,   175,   258,
      21,    38,    41,    55,    56,    66,    81,   210,   251,   254,
     258,   271,    27,    38,    27,    38,    76,    38,   144,   175,
     258,   168,   132,   258,   258,    94,   142,   113,   132,   166,
      38,   236,    37,   258,   175,   258,    37,   258,   175,   258,
     141,   168,   135,   159,   161,   258,   159,   160,   153,   258,
      29,   258,   142,   207,   208,   209,   210,   196,   229,   113,
     142,   143,   232,   244,    94,   230,   258,   227,   142,   217,
     258,     1,   184,   240,   142,    16,   180,   232,   244,   113,
     161,   160,   140,   142,   142,   238,   142,   238,   175,   258,
     144,   153,   258,   144,   258,   144,   258,   166,   236,   139,
       1,   166,   192,   193,    21,    56,    66,    81,   201,   211,
     226,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   142,   144,    38,    66,   243,   113,   142,    65,    65,
      37,   175,   258,    37,   175,   258,   175,   258,   249,   249,
     132,   217,   259,   242,   188,   258,   142,   258,    27,   168,
      27,   168,   258,    27,   168,   252,    27,   168,   252,   253,
     254,   113,   132,    11,   132,    29,    29,   153,    76,   157,
     113,   142,   141,   166,    21,    56,    66,    81,   213,   142,
     229,   231,     1,   236,    51,   259,   140,    54,    86,   140,
     185,   142,   141,   157,   166,   181,   222,   132,   132,   144,
     252,   144,   252,   153,    92,   139,     1,   189,   140,    94,
     113,   140,    66,   200,    10,    15,   108,   109,   110,   111,
     114,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   130,   133,   134,   135,   136,   138,   141,   166,
     202,   203,   204,   243,   132,   254,   243,   243,   258,    27,
      27,   258,    27,    27,   144,   144,   168,   168,   139,   168,
      76,    37,   258,    37,   258,    76,    37,   258,   168,    37,
     258,   168,   113,   142,   258,   258,   153,   258,   153,    29,
     208,   229,   112,   235,    66,   231,   230,   144,    38,   144,
      27,   153,   236,   181,   112,   157,    37,   153,   258,   144,
      37,   153,   258,   144,   258,     1,   140,   158,   140,    33,
      60,    63,   140,   152,   170,   258,   193,   213,   166,   258,
     115,   141,   205,   205,    76,    37,    37,    76,    37,    37,
      37,    37,     1,   189,   258,   258,   258,   258,   258,   258,
     254,    11,    29,   153,   142,    28,    72,    75,   143,   217,
     234,   244,   117,   219,   230,    87,   220,   258,   232,   244,
     153,   168,   142,   258,   258,   153,   258,   153,   140,   140,
     170,   231,   142,   166,   203,   204,   207,   258,   258,   258,
     258,   258,   258,   140,   140,    76,    76,    76,    76,   258,
     153,   235,   144,   236,   217,   218,   258,   258,   157,   169,
     216,   144,   157,    76,    76,    78,   214,   205,   205,   142,
      76,    76,    76,    76,    76,    76,   258,   258,   258,   258,
     219,   230,   217,   233,   234,   244,    38,   144,   244,   258,
     258,   220,   258,   233,   234,   132,   215,   216,   144,   233
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   148,   149,   150,   150,   151,   151,   152,   152,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     154,   154,   154,   155,   155,   155,   156,   156,   157,   157,
     157,   158,   158,   159,   159,   159,   159,   160,   160,   161,
     161,   162,   162,   162,   163,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   165,   165,   166,   167,   167,   168,   168,   169,   169,
     170,   170,   170,   170,   170,   170,   170,   170,   171,   171,
     172,   172,   172,   172,   173,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   175,   176,   176,
     176,   176,   176,   176,   176,   176,   177,   178,   178,   178,
     178,   178,   178,   179,   179,   180,   180,   180,   181,   181,
     182,   183,   183,   184,   184,   185,   185,   185,   186,   186,
     186,   186,   187,   187,   187,   188,   188,   189,   189,   189,
     190,   190,   191,   192,   192,   192,   193,   193,   195,   196,
     194,   197,   197,   197,   197,   199,   200,   198,   201,   201,
     201,   201,   202,   202,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   205,   205,   206,   207,   207,   207,   208,   208,
     208,   208,   209,   209,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   211,   211,   211,   211,   211,   211,   212,
     212,   213,   213,   213,   213,   213,   213,   214,   214,   215,
     215,   216,   216,   217,   217,   218,   218,   219,   219,   220,
     220,   221,   221,   221,   222,   222,   223,   223,   223,   224,
     224,   224,   224,   224,   225,   225,   225,   226,   226,   227,
     227,   228,   228,   228,   229,   229,   229,   230,   230,   230,
     231,   231,   231,   231,   232,   232,   232,   232,   233,   233,
     233,   234,   234,   234,   234,   234,   235,   235,   235,   235,
     235,   235,   235,   236,   236,   236,   236,   237,   237,   238,
     238,   238,   239,   239,   240,   240,   241,   241,   242,   242,
     242,   242,   243,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   246,   247,   248,   248,   248,   248,   248,   248,
     248,   248,   249,   249,   250,   251,   251,   252,   253,   253,
     254,   254,   254,   255,   255,   256,   257,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   259,   259,   259,   260,   260,   260,   260,   261,   261,
     262,   262,   262,   263,   263,   263,   264,   264,   264,   264,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   266,   266,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   268,   268,   268,   268,
     268,   268,   269,   269,   269,   269,   270,   270,   270,   270,
     271,   271,   271,   271,   271,   271,   271
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     2,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     3,     3,     3,     2,
       3,     3,     3,     2,     3,     3,     2,     2,     3,     2,
       6,     7,     7,     0,     1,     1,     0,     1,     2,     3,
       3,     1,     2,     1,     3,     3,     5,     0,     1,     1,
       1,     3,     5,     5,     3,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     0,     1,     1,     1,     1,     2,     1,     2,     3,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       3,     5,     5,     2,     2,     5,     3,     6,     6,     4,
       5,     5,     3,     3,     6,     5,     6,     5,     6,     3,
       4,     6,     7,     6,     7,     4,     5,     4,     4,     3,
       6,     5,     6,     5,     8,     7,     2,     3,     3,     2,
       2,     3,     3,     0,     2,     2,     3,     5,     1,     3,
       3,     5,     5,     0,     2,     3,     2,     3,     6,     8,
       6,     8,     1,     1,     1,     0,     2,     0,     2,     3,
       5,     5,     1,     1,     2,     3,     1,     3,     0,     0,
       8,     0,     1,     2,     2,     0,     0,    10,     3,     3,
       5,     5,     1,     3,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     3,     3,     0,     1,     3,     4,     4,
       6,     6,     0,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     0,     1,     1,     2,     1,     1,     1,
       1,     0,     1,     2,     1,     1,     1,     0,     1,     1,
       1,     1,     1,     2,     1,     0,     1,     2,     2,     0,
       2,     3,     4,     4,     2,     4,     0,     2,     2,     4,
       4,     4,     5,     4,     0,     1,     1,     1,     3,     3,
       5,     1,     1,     3,     1,     2,     3,     0,     2,     2,
       0,     2,     2,     1,     4,     4,     6,     3,     0,     1,
       1,     3,     4,     3,     4,     6,     0,     2,     2,     2,
       2,     2,     2,     1,     1,     3,     3,     1,     3,     1,
       1,     1,     3,     3,     0,     1,     1,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       4,     4,     5,     2,     2,     6,     6,     4,     9,     9,
       7,     6,     6,     4,     9,     9,     7,     4,     6,     6,
       9,     9,     6,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     0,     1,     4,     1,     3,     4,     1,     3,
       2,     3,     3,     1,     3,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     3,     2,     2,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     3,     3,     3,     3,     4,     3,     4,
       1,     1,     1,     1,     1,     3,     4,     3,     4,     3,
       4,     3,     5,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1
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
#line 441 "chapel.ypp" /* yacc.c:1661  */
    { yyblock = (yyval.pblockstmt); }
#line 4791 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 3:
#line 446 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = new BlockStmt();                                  resetTempID(); }
#line 4797 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 4:
#line 447 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-1].pblockstmt)->appendChapelStmt((yyvsp[0].pblockstmt)); context->generatedStmt = (yyvsp[-1].pblockstmt); resetTempID(); }
#line 4803 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 6:
#line 454 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildPragmaStmt( (yyvsp[-1].vpch), (yyvsp[0].pblockstmt) ); }
#line 4809 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 7:
#line 459 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.vpch) = new Vec<const char*>(); (yyval.vpch)->add(astr((yyvsp[0].pch))); }
#line 4815 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 8:
#line 460 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-2].vpch)->add(astr((yyvsp[0].pch))); }
#line 4821 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 23:
#line 479 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt((yyvsp[-1].pexpr)); }
#line 4827 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 24:
#line 480 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAtomicStmt((yyvsp[0].pblockstmt)); }
#line 4833 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 25:
#line 481 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildBeginStmt((yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt)); }
#line 4839 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 26:
#line 482 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildGotoStmt(GOTO_BREAK, (yyvsp[-1].pch)); }
#line 4845 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 27:
#line 483 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildCobeginStmt((yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt));  }
#line 4851 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 28:
#line 484 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildGotoStmt(GOTO_CONTINUE, (yyvsp[-1].pch)); }
#line 4857 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 29:
#line 485 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt(buildCompleteStmt()); }
#line 4863 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 30:
#line 486 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildDeleteStmt((yyvsp[-1].pcallexpr)); }
#line 4869 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 31:
#line 487 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildLabelStmt((yyvsp[-1].pch), (yyvsp[0].pblockstmt)); }
#line 4875 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 32:
#line 488 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildLocalStmt((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 4881 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 33:
#line 489 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildLocalStmt((yyvsp[0].pblockstmt)); }
#line 4887 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 34:
#line 490 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildOnStmt((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 4893 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 35:
#line 491 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildSerialStmt((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 4899 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 36:
#line 492 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildSerialStmt(new SymExpr(gTrue), (yyvsp[0].pblockstmt)); }
#line 4905 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 37:
#line 493 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildSyncStmt((yyvsp[0].pblockstmt)); }
#line 4911 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 38:
#line 494 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_YIELD, (yyvsp[-1].pexpr)); }
#line 4917 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 39:
#line 495 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildErrorStandin(); }
#line 4923 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 40:
#line 500 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt(new DefExpr(buildModule((yyvsp[-2].pch), currentModuleType,
    new BlockStmt(), yyfilename, (yyvsp[-5].b), (yyvsp[-4].b), (yylsp[-5]).comment))); }
#line 4930 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 41:
#line 503 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt(new DefExpr(buildModule((yyvsp[-3].pch), currentModuleType, (yyvsp[-1].pblockstmt), yyfilename, (yyvsp[-6].b), (yyvsp[-5].b), (yylsp[-6]).comment))); }
#line 4936 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 42:
#line 505 "chapel.ypp" /* yacc.c:1661  */
    {(yyval.pblockstmt) = buildChapelStmt(new DefExpr(buildModule((yyvsp[-3].pch), currentModuleType,
        buildErrorStandin(), yyfilename, (yyvsp[-6].b), (yyvsp[-5].b), (yylsp[-6]).comment))); }
#line 4943 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 43:
#line 510 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.b) = false; (yyloc).comment = context->latestComment; context->latestComment = NULL; }
#line 4949 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 44:
#line 511 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.b) = false; (yyloc).comment = context->latestComment; context->latestComment = NULL; }
#line 4955 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 45:
#line 512 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.b) = true; (yyloc).comment = context->latestComment; context->latestComment = NULL; }
#line 4961 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 46:
#line 516 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.b) = false; }
#line 4967 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 47:
#line 517 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.b) = true;  }
#line 4973 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 48:
#line 530 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = new BlockStmt(); }
#line 4979 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 49:
#line 531 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = (yyvsp[-1].pblockstmt);              }
#line 4985 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 50:
#line 532 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildErrorStandin(); }
#line 4991 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 51:
#line 537 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = new BlockStmt(); (yyval.pblockstmt)->appendChapelStmt((yyvsp[0].pblockstmt)); }
#line 4997 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 52:
#line 538 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-1].pblockstmt)->appendChapelStmt((yyvsp[0].pblockstmt)); }
#line 5003 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 53:
#line 543 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.ponlylist) = new std::vector<OnlyRename*>();
                                         OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::SINGLE;
                                         cur->elem = (yyvsp[0].pexpr);
                                         (yyval.ponlylist)->push_back(cur); }
#line 5013 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 54:
#line 548 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.ponlylist) = new std::vector<OnlyRename*>();
                                         OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::DOUBLE;
                                         cur->renamed = new std::pair<Expr*, Expr*>((yyvsp[-2].pexpr), (yyvsp[0].pexpr));
                                         (yyval.ponlylist)->push_back(cur); }
#line 5023 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 55:
#line 553 "chapel.ypp" /* yacc.c:1661  */
    { OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::SINGLE;
                                         cur->elem = (yyvsp[0].pexpr);
                                         (yyvsp[-2].ponlylist)->push_back(cur); }
#line 5032 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 56:
#line 557 "chapel.ypp" /* yacc.c:1661  */
    { OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::DOUBLE;
                                         cur->renamed = new std::pair<Expr*, Expr*>((yyvsp[-2].pexpr), (yyvsp[0].pexpr));
                                         (yyvsp[-4].ponlylist)->push_back(cur); }
#line 5041 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 57:
#line 564 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.ponlylist) = new std::vector<OnlyRename*>();
                                         OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::SINGLE;
                                         cur->elem = new UnresolvedSymExpr("");
                                         (yyval.ponlylist)->push_back(cur); }
#line 5051 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 59:
#line 573 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.ponlylist) = new std::vector<OnlyRename*>();
                                         OnlyRename* cur = new OnlyRename();
                                         cur->tag = OnlyRename::SINGLE;
                                         cur->elem = new UnresolvedSymExpr("");
                                         (yyval.ponlylist)->push_back(cur); }
#line 5061 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 61:
#line 582 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildUseStmt((yyvsp[-1].pcallexpr)); }
#line 5067 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 62:
#line 583 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildUseStmt((yyvsp[-3].pexpr), (yyvsp[-1].ponlylist), true); }
#line 5073 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 63:
#line 584 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildUseStmt((yyvsp[-3].pexpr), (yyvsp[-1].ponlylist), false); }
#line 5079 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 64:
#line 588 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildRequireStmt((yyvsp[-1].pcallexpr)); }
#line 5085 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 65:
#line 593 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), "=");   }
#line 5091 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 66:
#line 595 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), "+=");  }
#line 5097 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 67:
#line 597 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), "-=");  }
#line 5103 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 68:
#line 599 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), "*=");  }
#line 5109 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 69:
#line 601 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), "/=");  }
#line 5115 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 70:
#line 603 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), "%=");  }
#line 5121 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 71:
#line 605 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), "**="); }
#line 5127 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 72:
#line 607 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), "&=");  }
#line 5133 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 73:
#line 609 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), "|=");  }
#line 5139 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 74:
#line 611 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), "^=");  }
#line 5145 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 75:
#line 613 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), ">>="); }
#line 5151 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 76:
#line 615 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), "<<="); }
#line 5157 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 77:
#line 617 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), "<=>"); }
#line 5163 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 78:
#line 619 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), PRIM_REDUCE_ASSIGN); }
#line 5169 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 79:
#line 621 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildLAndAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr));    }
#line 5175 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 80:
#line 623 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildLOrAssignment((yyvsp[-3].pexpr), (yyvsp[-1].pexpr));     }
#line 5181 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 81:
#line 627 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = NULL; }
#line 5187 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 83:
#line 632 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 5193 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 84:
#line 636 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 5199 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 85:
#line 637 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = (yyvsp[0].pch); }
#line 5205 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 86:
#line 641 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = (yyvsp[0].pblockstmt); }
#line 5211 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 87:
#line 642 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = (yyvsp[0].pblockstmt); }
#line 5217 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 88:
#line 646 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_RETURN); }
#line 5223 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 89:
#line 647 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_RETURN, (yyvsp[-1].pexpr)); }
#line 5229 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 90:
#line 651 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt(new BlockStmt()); }
#line 5235 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 92:
#line 653 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = (yyvsp[0].pblockstmt); }
#line 5241 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 93:
#line 654 "chapel.ypp" /* yacc.c:1661  */
    { applyPrivateToBlock((yyvsp[0].pblockstmt)); (yyval.pblockstmt) = (yyvsp[0].pblockstmt); }
#line 5247 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 100:
#line 667 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildForwardingStmt((yyvsp[-1].pexpr)); }
#line 5253 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 101:
#line 668 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildForwardingStmt((yyvsp[-3].pexpr), (yyvsp[-1].ponlylist), true); }
#line 5259 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 102:
#line 669 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildForwardingStmt((yyvsp[-3].pexpr), (yyvsp[-1].ponlylist), false); }
#line 5265 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 103:
#line 670 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildForwardingDeclStmt((yyvsp[0].pblockstmt)); }
#line 5271 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 104:
#line 675 "chapel.ypp" /* yacc.c:1661  */
    {
#ifdef HAVE_LLVM
      if (externC) {
        (yyval.pblockstmt) = buildExternBlockStmt(astr((yyvsp[0].pch)));
      } else {
        USR_FATAL(new BlockStmt(), "extern block syntax is turned off. Use --extern-c flag to turn on.");
      }
#else
      USR_FATAL(new BlockStmt(), "Chapel must be built with llvm in order to use the extern block syntax");
#endif
    }
#line 5287 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 105:
#line 689 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = DoWhileStmt::build((yyvsp[-1].pexpr), (yyvsp[-3].pblockstmt)); }
#line 5293 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 106:
#line 690 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = WhileDoStmt::build((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 5299 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 107:
#line 691 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildCoforallLoopStmt((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt)); }
#line 5305 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 108:
#line 692 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildCoforallLoopStmt((yyvsp[-4].pexpr), zipToTuple((yyvsp[-2].pcallexpr)), (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt), true); }
#line 5311 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 109:
#line 693 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildCoforallLoopStmt(NULL, (yyvsp[-2].pexpr), (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt)); }
#line 5317 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 110:
#line 694 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForLoop::buildForLoop(  (yyvsp[-3].pexpr), (yyvsp[-1].pexpr), (yyvsp[0].pblockstmt), false, false); }
#line 5323 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 111:
#line 695 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForLoop::buildForLoop(  (yyvsp[-3].pexpr), (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt), false,  true); }
#line 5329 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 112:
#line 696 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForLoop::buildForLoop(NULL, (yyvsp[-1].pexpr), (yyvsp[0].pblockstmt), false, false); }
#line 5335 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 113:
#line 697 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForLoop::buildForLoop(NULL, (yyvsp[-1].pcallexpr), (yyvsp[0].pblockstmt), false,  true); }
#line 5341 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 114:
#line 698 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildParamForLoopStmt((yyvsp[-3].pch), (yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 5347 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 115:
#line 699 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForallStmt::build((yyvsp[-3].pexpr), (yyvsp[-1].pexpr), NULL, (yyvsp[0].pblockstmt)); }
#line 5353 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 116:
#line 700 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForallStmt::build((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[-1].pcallexpr),   (yyvsp[0].pblockstmt)); }
#line 5359 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 117:
#line 701 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForallStmt::build((yyvsp[-3].pexpr), (yyvsp[-1].pcallexpr), NULL, (yyvsp[0].pblockstmt), true); }
#line 5365 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 118:
#line 702 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForallStmt::build((yyvsp[-4].pexpr), (yyvsp[-2].pcallexpr), (yyvsp[-1].pcallexpr),   (yyvsp[0].pblockstmt), true); }
#line 5371 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 119:
#line 703 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-1].pexpr), NULL, (yyvsp[0].pblockstmt)); }
#line 5377 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 120:
#line 704 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-2].pexpr), (yyvsp[-1].pcallexpr),   (yyvsp[0].pblockstmt)); }
#line 5383 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 121:
#line 706 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pexpr), "invalid index expression");
      (yyval.pblockstmt) = ForallStmt::build((yyvsp[-4].pcallexpr)->get(1)->remove(), (yyvsp[-2].pexpr), NULL, new BlockStmt((yyvsp[0].pblockstmt)));
    }
#line 5393 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 122:
#line 712 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-5].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-3].pexpr), "invalid index expression");
      (yyval.pblockstmt) = ForallStmt::build((yyvsp[-5].pcallexpr)->get(1)->remove(), (yyvsp[-3].pexpr), (yyvsp[-2].pcallexpr),   new BlockStmt((yyvsp[0].pblockstmt)));
    }
#line 5403 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 123:
#line 718 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pcallexpr), "invalid index expression");
      (yyval.pblockstmt) = ForallStmt::build((yyvsp[-4].pcallexpr)->get(1)->remove(), (yyvsp[-2].pcallexpr), NULL, new BlockStmt((yyvsp[0].pblockstmt)), true);
    }
#line 5413 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 124:
#line 724 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-5].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-3].pcallexpr), "invalid index expression");
      (yyval.pblockstmt) = ForallStmt::build((yyvsp[-5].pcallexpr)->get(1)->remove(), (yyvsp[-3].pcallexpr), (yyvsp[-2].pcallexpr),   new BlockStmt((yyvsp[0].pblockstmt)), true);
    }
#line 5423 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 125:
#line 730 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-2].pcallexpr)->argList.length > 1)
        (yyval.pblockstmt) = ForallStmt::build(NULL, new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), NULL, new BlockStmt((yyvsp[0].pblockstmt)));
      else
        (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-2].pcallexpr)->get(1)->remove(), NULL, new BlockStmt((yyvsp[0].pblockstmt)));
    }
#line 5434 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 126:
#line 737 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-3].pcallexpr)->argList.length > 1)
        (yyval.pblockstmt) = ForallStmt::build(NULL, new CallExpr("chpl__ensureDomainExpr", (yyvsp[-3].pcallexpr)), (yyvsp[-2].pcallexpr),   new BlockStmt((yyvsp[0].pblockstmt)));
      else
        (yyval.pblockstmt) = ForallStmt::build(NULL, (yyvsp[-3].pcallexpr)->get(1)->remove(), (yyvsp[-2].pcallexpr),   new BlockStmt((yyvsp[0].pblockstmt)));
    }
#line 5445 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 127:
#line 746 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ZIP, (yyvsp[-1].pcallexpr)); }
#line 5451 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 128:
#line 750 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[-2].pexpr), (yyvsp[0].pblockstmt)); }
#line 5457 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 129:
#line 751 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 5463 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 130:
#line 752 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[-4].pexpr), (yyvsp[-2].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 5469 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 131:
#line 753 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[-3].pexpr), (yyvsp[-2].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 5475 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 132:
#line 754 "chapel.ypp" /* yacc.c:1661  */
    {
(yyval.pblockstmt) = buildIfStmt(convertAssignmentAndWarn((yyvsp[-4].pexpr),(yyvsp[-3].pch),(yyvsp[-2].pexpr)), (yyvsp[0].pblockstmt)); }
#line 5482 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 133:
#line 756 "chapel.ypp" /* yacc.c:1661  */
    {
(yyval.pblockstmt) = buildIfStmt(convertAssignmentAndWarn((yyvsp[-3].pexpr),(yyvsp[-2].pch),(yyvsp[-1].pexpr)), (yyvsp[0].pblockstmt)); }
#line 5489 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 134:
#line 758 "chapel.ypp" /* yacc.c:1661  */
    {
(yyval.pblockstmt) = buildIfStmt(convertAssignmentAndWarn((yyvsp[-6].pexpr),(yyvsp[-5].pch),(yyvsp[-4].pexpr)), (yyvsp[-2].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 5496 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 135:
#line 760 "chapel.ypp" /* yacc.c:1661  */
    {
(yyval.pblockstmt) = buildIfStmt(convertAssignmentAndWarn((yyvsp[-5].pexpr),(yyvsp[-4].pch),(yyvsp[-3].pexpr)), (yyvsp[-2].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 5503 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 136:
#line 765 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = DeferStmt::build((yyvsp[0].pblockstmt)); }
#line 5509 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 137:
#line 768 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = TryStmt::build(false, (yyvsp[-1].pexpr)); }
#line 5515 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 138:
#line 769 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = TryStmt::build(true,  (yyvsp[-1].pexpr)); }
#line 5521 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 139:
#line 770 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = TryStmt::build(false, (yyvsp[0].pblockstmt)); }
#line 5527 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 140:
#line 771 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = TryStmt::build(true,  (yyvsp[0].pblockstmt)); }
#line 5533 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 141:
#line 772 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = TryStmt::build(false, (yyvsp[-1].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 5539 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 142:
#line 773 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = TryStmt::build(true,  (yyvsp[-1].pblockstmt), (yyvsp[0].pblockstmt)); }
#line 5545 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 143:
#line 777 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt(); }
#line 5551 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 144:
#line 778 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-1].pblockstmt)->insertAtTail((yyvsp[0].pexpr)); }
#line 5557 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 145:
#line 782 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = CatchStmt::build((yyvsp[0].pblockstmt)); }
#line 5563 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 146:
#line 783 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = CatchStmt::build((yyvsp[-1].pexpr), (yyvsp[0].pblockstmt)); }
#line 5569 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 147:
#line 784 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = CatchStmt::build((yyvsp[-2].pexpr), (yyvsp[0].pblockstmt)); }
#line 5575 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 148:
#line 788 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new DefExpr(new VarSymbol((yyvsp[0].pch)), NULL, new UnresolvedSymExpr("Error")); }
#line 5581 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 149:
#line 789 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new DefExpr(new VarSymbol((yyvsp[-2].pch)), NULL, (yyvsp[0].pexpr));   }
#line 5587 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 150:
#line 793 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_THROW, (yyvsp[-1].pexpr)); }
#line 5593 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 151:
#line 797 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt(buildSelectStmt((yyvsp[-3].pexpr), (yyvsp[-1].pblockstmt))); }
#line 5599 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 152:
#line 799 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildErrorStandin(); }
#line 5605 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 153:
#line 803 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt(); }
#line 5611 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 154:
#line 804 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-1].pblockstmt)->insertAtTail((yyvsp[0].pexpr)); }
#line 5617 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 155:
#line 809 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CondStmt(new CallExpr(PRIM_WHEN, (yyvsp[-1].pcallexpr)), (yyvsp[0].pblockstmt)); }
#line 5623 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 156:
#line 811 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CondStmt(new CallExpr(PRIM_WHEN), (yyvsp[0].pblockstmt)); }
#line 5629 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 157:
#line 813 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CondStmt(new CallExpr(PRIM_WHEN), (yyvsp[0].pblockstmt)); }
#line 5635 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 158:
#line 820 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pblockstmt) = buildChapelStmt(buildClassDefExpr((yyvsp[-4].pch),
                                             NULL,
                                             (yyvsp[-5].aggrTag),
                                             (yyvsp[-3].pcallexpr),
                                             (yyvsp[-1].pblockstmt),
                                             FLAG_UNKNOWN,
                                             (yylsp[-5]).comment));
    }
#line 5649 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 159:
#line 830 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pblockstmt) = buildChapelStmt(buildClassDefExpr((yyvsp[-4].pch),
                                             (yyvsp[-6].pch),
                                             (yyvsp[-5].aggrTag),
                                             (yyvsp[-3].pcallexpr),
                                             (yyvsp[-1].pblockstmt),
                                             FLAG_EXTERN,
                                             (yylsp[-5]).comment));
    }
#line 5663 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 160:
#line 840 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pblockstmt) = buildChapelStmt(buildClassDefExpr((yyvsp[-4].pch),
                                             NULL,
                                             (yyvsp[-5].aggrTag),
                                             (yyvsp[-3].pcallexpr),
                                             new BlockStmt(),
                                             FLAG_UNKNOWN,
                                             (yylsp[-5]).comment));
    }
#line 5677 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 161:
#line 850 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pblockstmt) = buildChapelStmt(buildClassDefExpr((yyvsp[-4].pch),
                                             (yyvsp[-6].pch),
                                             (yyvsp[-5].aggrTag),
                                             (yyvsp[-3].pcallexpr),
                                             new BlockStmt(),
                                             FLAG_EXTERN,
                                             (yylsp[-5]).comment));
    }
#line 5691 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 162:
#line 862 "chapel.ypp" /* yacc.c:1661  */
    {
             (yyval.aggrTag)                     = AGGREGATE_CLASS;
             (yyloc).comment             = context->latestComment;
             context->latestComment = NULL;
           }
#line 5701 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 163:
#line 867 "chapel.ypp" /* yacc.c:1661  */
    {
             (yyval.aggrTag)                     = AGGREGATE_RECORD;
             (yyloc).comment             = context->latestComment;
             context->latestComment = NULL;
           }
#line 5711 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 164:
#line 872 "chapel.ypp" /* yacc.c:1661  */
    {
             (yyval.aggrTag)                     = AGGREGATE_UNION;
             (yyloc).comment             = context->latestComment;
             context->latestComment = NULL;
           }
#line 5721 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 165:
#line 880 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = NULL; }
#line 5727 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 166:
#line 881 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = (yyvsp[0].pcallexpr); }
#line 5733 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 167:
#line 886 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = new BlockStmt(); }
#line 5739 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 168:
#line 888 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-1].pblockstmt)->insertAtTail((yyvsp[0].pblockstmt)); }
#line 5745 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 169:
#line 890 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-2].pblockstmt)->insertAtTail(buildPragmaStmt((yyvsp[-1].vpch), (yyvsp[0].pblockstmt))); }
#line 5751 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 170:
#line 895 "chapel.ypp" /* yacc.c:1661  */
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
#line 5771 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 171:
#line 911 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pblockstmt) = buildErrorStandin();
    }
#line 5779 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 172:
#line 918 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.penumtype) = new EnumType();
      (yyloc).comment = context->latestComment;
      context->latestComment = NULL;
    }
#line 5789 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 173:
#line 927 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pvecOfDefs) = new std::vector<DefExpr*>();
      (yyval.pvecOfDefs)->push_back((yyvsp[0].pdefexpr));
      //$$->doc = context->latestComment;
      // start here for enabling documentation of enum constants
      //context->latestComment = NULL;
    }
#line 5801 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 174:
#line 935 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pvecOfDefs) = (yyvsp[-1].pvecOfDefs);
    }
#line 5809 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 175:
#line 939 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyvsp[-2].pvecOfDefs)->push_back((yyvsp[0].pdefexpr));
    }
#line 5817 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 176:
#line 945 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = new DefExpr(new EnumSymbol((yyvsp[0].pch))); }
#line 5823 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 177:
#line 946 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = new DefExpr(new EnumSymbol((yyvsp[-2].pch)), (yyvsp[0].pexpr)); }
#line 5829 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 178:
#line 951 "chapel.ypp" /* yacc.c:1661  */
    {
      captureTokens = 1;
      captureString.clear();
    }
#line 5838 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 179:
#line 956 "chapel.ypp" /* yacc.c:1661  */
    {
      captureTokens = 0;
      (yyvsp[0].pfnsymbol)->userString = astr(captureString);
    }
#line 5847 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 180:
#line 961 "chapel.ypp" /* yacc.c:1661  */
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
      if ((yyvsp[-1].pexpr))
        (yyvsp[-5].pfnsymbol)->where = new BlockStmt((yyvsp[-1].pexpr));
      (yyvsp[-5].pfnsymbol)->insertAtTail((yyvsp[0].pblockstmt));
      (yyval.pexpr) = new DefExpr(buildLambda((yyvsp[-5].pfnsymbol)));
    }
#line 5867 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 181:
#line 981 "chapel.ypp" /* yacc.c:1661  */
    {
                  (yyval.pfnsymbol) = new FnSymbol("");

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 5878 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 182:
#line 987 "chapel.ypp" /* yacc.c:1661  */
    {
                  (yyval.pfnsymbol) = new FnSymbol("");
                  (yyval.pfnsymbol)->addFlag(FLAG_INLINE);

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 5890 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 183:
#line 994 "chapel.ypp" /* yacc.c:1661  */
    {
                  (yyval.pfnsymbol) = new FnSymbol((yyvsp[0].pch));
                  (yyval.pfnsymbol)->addFlag(FLAG_EXPORT);
                  (yyval.pfnsymbol)->addFlag(FLAG_LOCAL_ARGS);

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 5903 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 184:
#line 1002 "chapel.ypp" /* yacc.c:1661  */
    {
                  (yyval.pfnsymbol) = new FnSymbol((yyvsp[0].pch));
                  (yyval.pfnsymbol)->addFlag(FLAG_EXTERN);
                  (yyval.pfnsymbol)->addFlag(FLAG_LOCAL_ARGS);

                  (yyloc).comment             = context->latestComment;
                  context->latestComment = NULL;
                }
#line 5916 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 185:
#line 1014 "chapel.ypp" /* yacc.c:1661  */
    {
      // Sets up to capture tokens while parsing the next grammar nonterminal.
      captureTokens = 1;
      captureString.clear();
    }
#line 5926 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 186:
#line 1020 "chapel.ypp" /* yacc.c:1661  */
    {
      // Stop capturing and save the result.
      captureTokens = 0;

      (yyvsp[0].pfnsymbol)->userString = astr(captureString);
    }
#line 5937 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 187:
#line 1027 "chapel.ypp" /* yacc.c:1661  */
    {
      FnSymbol* fn = (yyvsp[-6].pfnsymbol);

      fn->copyFlags((yyvsp[-9].pfnsymbol));
      // The user explicitly named this function (controls mangling).
      if (*(yyvsp[-9].pfnsymbol)->name)
        fn->cname = (yyvsp[-9].pfnsymbol)->name;

      if ((yyvsp[-8].procIter) == ProcIter_ITER)
      {
        if (fn->hasFlag(FLAG_EXTERN))
          USR_FATAL_CONT(fn, "'iter' is not legal with 'extern'");
        fn->addFlag(FLAG_ITERATOR_FN);
      }

      (yyval.pblockstmt) = buildFunctionDecl((yyvsp[-6].pfnsymbol), (yyvsp[-4].retTag), (yyvsp[-3].pexpr), (yyvsp[-2].b), (yyvsp[-1].pexpr), (yyvsp[0].pblockstmt), (yylsp[-9]).comment);
      context->latestComment = NULL;
    }
#line 5960 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 188:
#line 1049 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), (yyvsp[-1].pch), (yyvsp[-2].pt), NULL);
    }
#line 5968 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 189:
#line 1053 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), (yyvsp[-1].pch), (yyvsp[-2].pt), NULL);
      (yyval.pfnsymbol)->addFlag(FLAG_ASSIGNOP);
    }
#line 5977 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 190:
#line 1058 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), (yyvsp[-1].pch), (yyvsp[-4].pt), (yyvsp[-3].pexpr));
    }
#line 5985 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 191:
#line 1062 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pfnsymbol) = buildFunctionSymbol((yyvsp[0].pfnsymbol), (yyvsp[-1].pch), (yyvsp[-4].pt), (yyvsp[-3].pexpr));
      (yyval.pfnsymbol)->addFlag(FLAG_ASSIGNOP);
    }
#line 5994 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 193:
#line 1070 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[-1].pexpr); }
#line 6000 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 195:
#line 1075 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = astr("~", (yyvsp[0].pch)); }
#line 6006 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 196:
#line 1076 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "&"; }
#line 6012 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 197:
#line 1077 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "|"; }
#line 6018 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 198:
#line 1078 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "^"; }
#line 6024 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 199:
#line 1079 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "~"; }
#line 6030 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 200:
#line 1080 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "=="; }
#line 6036 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 201:
#line 1081 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "!="; }
#line 6042 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 202:
#line 1082 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "<="; }
#line 6048 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 203:
#line 1083 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = ">="; }
#line 6054 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 204:
#line 1084 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "<"; }
#line 6060 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 205:
#line 1085 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = ">"; }
#line 6066 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 206:
#line 1086 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "+"; }
#line 6072 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 207:
#line 1087 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "-"; }
#line 6078 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 208:
#line 1088 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "*"; }
#line 6084 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 209:
#line 1089 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "/"; }
#line 6090 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 210:
#line 1090 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "<<"; }
#line 6096 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 211:
#line 1091 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = ">>"; }
#line 6102 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 212:
#line 1092 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "%"; }
#line 6108 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 213:
#line 1093 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "**"; }
#line 6114 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 214:
#line 1094 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "!"; }
#line 6120 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 215:
#line 1095 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "chpl_by"; }
#line 6126 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 216:
#line 1096 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "#"; }
#line 6132 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 217:
#line 1097 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "chpl_align"; }
#line 6138 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 218:
#line 1098 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "<=>"; }
#line 6144 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 219:
#line 1099 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "<~>"; }
#line 6150 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 220:
#line 1103 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "="; }
#line 6156 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 221:
#line 1104 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "+="; }
#line 6162 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 222:
#line 1105 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "-="; }
#line 6168 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 223:
#line 1106 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "*="; }
#line 6174 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 224:
#line 1107 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "/="; }
#line 6180 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 225:
#line 1108 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "%="; }
#line 6186 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 226:
#line 1109 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "**="; }
#line 6192 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 227:
#line 1110 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "&="; }
#line 6198 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 228:
#line 1111 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "|="; }
#line 6204 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 229:
#line 1112 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "^="; }
#line 6210 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 230:
#line 1113 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = ">>="; }
#line 6216 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 231:
#line 1114 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pch) = "<<="; }
#line 6222 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 232:
#line 1118 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pfnsymbol) = new FnSymbol("_"); (yyval.pfnsymbol)->addFlag(FLAG_NO_PARENS); }
#line 6228 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 233:
#line 1119 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pfnsymbol) = (yyvsp[-1].pfnsymbol); }
#line 6234 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 234:
#line 1123 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pfnsymbol) = (yyvsp[-1].pfnsymbol); }
#line 6240 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 235:
#line 1127 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pfnsymbol) = buildFunctionFormal(NULL, NULL); }
#line 6246 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 236:
#line 1128 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pfnsymbol) = buildFunctionFormal(NULL, (yyvsp[0].pdefexpr)); }
#line 6252 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 237:
#line 1129 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pfnsymbol) = buildFunctionFormal((yyvsp[-2].pfnsymbol), (yyvsp[0].pdefexpr)); }
#line 6258 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 238:
#line 1134 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = buildArgDefExpr((yyvsp[-3].pt), (yyvsp[-2].pch), (yyvsp[-1].pexpr), (yyvsp[0].pexpr), NULL); }
#line 6264 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 239:
#line 1136 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = buildArgDefExpr((yyvsp[-3].pt), (yyvsp[-2].pch), (yyvsp[-1].pexpr), NULL, (yyvsp[0].pexpr)); }
#line 6270 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 240:
#line 1138 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = buildTupleArgDefExpr((yyvsp[-5].pt), (yyvsp[-3].pblockstmt), (yyvsp[-1].pexpr), (yyvsp[0].pexpr)); }
#line 6276 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 241:
#line 1140 "chapel.ypp" /* yacc.c:1661  */
    { USR_FATAL("variable-length argument may not be grouped in a tuple"); }
#line 6282 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 242:
#line 1144 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_BLANK; }
#line 6288 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 243:
#line 1145 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = (yyvsp[0].pt); }
#line 6294 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 244:
#line 1149 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_IN; }
#line 6300 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 245:
#line 1150 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_INOUT; }
#line 6306 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 246:
#line 1151 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_OUT; }
#line 6312 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 247:
#line 1152 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_CONST; }
#line 6318 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 248:
#line 1153 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_CONST_IN; }
#line 6324 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 249:
#line 1154 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_CONST_REF; }
#line 6330 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 250:
#line 1155 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_PARAM; }
#line 6336 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 251:
#line 1156 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_REF; }
#line 6342 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 252:
#line 1157 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_TYPE; }
#line 6348 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 253:
#line 1161 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_BLANK; }
#line 6354 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 254:
#line 1162 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_PARAM; }
#line 6360 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 255:
#line 1163 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_REF;   }
#line 6366 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 256:
#line 1164 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_CONST_REF;   }
#line 6372 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 257:
#line 1165 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_CONST;   }
#line 6378 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 258:
#line 1166 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pt) = INTENT_TYPE;  }
#line 6384 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 259:
#line 1170 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.procIter) = ProcIter_PROC; }
#line 6390 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 260:
#line 1171 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.procIter) = ProcIter_ITER; }
#line 6396 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 261:
#line 1175 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.retTag) = RET_VALUE; }
#line 6402 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 262:
#line 1176 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.retTag) = RET_VALUE; }
#line 6408 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 263:
#line 1177 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.retTag) = RET_CONST_REF; }
#line 6414 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 264:
#line 1178 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.retTag) = RET_REF; }
#line 6420 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 265:
#line 1179 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.retTag) = RET_PARAM; }
#line 6426 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 266:
#line 1180 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.retTag) = RET_TYPE; }
#line 6432 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 267:
#line 1184 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.b) = false; }
#line 6438 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 268:
#line 1185 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.b) = true;  }
#line 6444 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 269:
#line 1188 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = NULL; }
#line 6450 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 272:
#line 1194 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = new BlockStmt((yyvsp[0].pblockstmt)); }
#line 6456 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 273:
#line 1199 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = new DefExpr(new VarSymbol((yyvsp[0].pch))); }
#line 6462 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 274:
#line 1201 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = new DefExpr(new VarSymbol(astr("chpl__query", istr(query_uid++)))); }
#line 6468 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 275:
#line 1205 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pdefexpr) = new DefExpr(new VarSymbol(astr("chpl__query", istr(query_uid++)))); }
#line 6474 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 277:
#line 1210 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 6480 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 278:
#line 1211 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[0].pdefexpr)->sym->addFlag(FLAG_PARAM); (yyval.pexpr) = (yyvsp[0].pdefexpr); }
#line 6486 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 279:
#line 1215 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 6492 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 280:
#line 1216 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 6498 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 281:
#line 1221 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = (yyvsp[-1].pblockstmt); }
#line 6504 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 282:
#line 1223 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = handleConfigTypes((yyvsp[-1].pblockstmt)); }
#line 6510 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 283:
#line 1225 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = convertTypesToExtern((yyvsp[-1].pblockstmt)); }
#line 6516 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 284:
#line 1230 "chapel.ypp" /* yacc.c:1661  */
    {
      VarSymbol* var = new VarSymbol((yyvsp[-1].pch));

      var->addFlag(FLAG_TYPE_VARIABLE);

      var->doc               = context->latestComment;
      context->latestComment = NULL;

      DefExpr* def = new DefExpr(var, (yyvsp[0].pexpr));

      (yyval.pblockstmt) = buildChapelStmt(def);
    }
#line 6533 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 285:
#line 1243 "chapel.ypp" /* yacc.c:1661  */
    {
      VarSymbol* var = new VarSymbol((yyvsp[-3].pch));

      var->addFlag(FLAG_TYPE_VARIABLE);

      var->doc               = context->latestComment;
      context->latestComment = NULL;

      DefExpr* def = new DefExpr(var, (yyvsp[-2].pexpr));

      (yyvsp[0].pblockstmt)->insertAtHead(def);
      (yyval.pblockstmt) = buildChapelStmt((yyvsp[0].pblockstmt));
    }
#line 6551 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 286:
#line 1259 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 6557 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 287:
#line 1261 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 6563 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 288:
#line 1263 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForallLoopExprFromArrayType((yyvsp[0].pcallexpr)); }
#line 6569 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 289:
#line 1268 "chapel.ypp" /* yacc.c:1661  */
    {
      std::set<Flag> flags;
      flags.insert((yyvsp[-3].flag));
      flags.insert(FLAG_PARAM);
      (yyval.pblockstmt) = buildVarDecls((yyvsp[-1].pblockstmt), flags, (yylsp[-3]).comment);
      context->latestComment = NULL;
    }
#line 6581 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 290:
#line 1276 "chapel.ypp" /* yacc.c:1661  */
    {
      std::set<Flag> flags;
      flags.insert((yyvsp[-3].flag));
      flags.insert(FLAG_CONST);
      (yyval.pblockstmt) = buildVarDecls((yyvsp[-1].pblockstmt), flags, (yylsp[-3]).comment);
      context->latestComment = NULL;
    }
#line 6593 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 291:
#line 1284 "chapel.ypp" /* yacc.c:1661  */
    {
      std::set<Flag> flags;
      flags.insert((yyvsp[-3].flag));
      flags.insert(FLAG_REF_VAR);
      (yyval.pblockstmt) = buildVarDecls((yyvsp[-1].pblockstmt), flags, (yylsp[-3]).comment);
      context->latestComment = NULL;
    }
#line 6605 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 292:
#line 1292 "chapel.ypp" /* yacc.c:1661  */
    {
      std::set<Flag> flags;
      flags.insert((yyvsp[-4].flag));
      flags.insert(FLAG_CONST);
      flags.insert(FLAG_REF_VAR);
      (yyval.pblockstmt) = buildVarDecls((yyvsp[-1].pblockstmt), flags, (yylsp[-4]).comment);
      context->latestComment = NULL;
    }
#line 6618 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 293:
#line 1301 "chapel.ypp" /* yacc.c:1661  */
    {
      std::set<Flag> flags;
      flags.insert((yyvsp[-3].flag));
      (yyval.pblockstmt) = buildVarDecls((yyvsp[-1].pblockstmt), flags, (yylsp[-3]).comment);
      context->latestComment = NULL;
    }
#line 6629 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 294:
#line 1310 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.flag) = FLAG_UNKNOWN; (yyloc).comment = context->latestComment; context->latestComment = NULL; }
#line 6635 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 295:
#line 1311 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.flag) = FLAG_CONFIG;  (yyloc).comment = context->latestComment; context->latestComment = NULL; }
#line 6641 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 296:
#line 1312 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.flag) = FLAG_EXTERN;  (yyloc).comment = context->latestComment; context->latestComment = NULL; }
#line 6647 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 298:
#line 1318 "chapel.ypp" /* yacc.c:1661  */
    {
      for_alist(expr, (yyvsp[0].pblockstmt)->body)
        (yyvsp[-2].pblockstmt)->insertAtTail(expr->remove());
    }
#line 6656 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 299:
#line 1326 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt(new DefExpr(new VarSymbol((yyvsp[-2].pch)), (yyvsp[0].pexpr), (yyvsp[-1].pexpr))); }
#line 6662 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 300:
#line 1328 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildTupleVarDeclStmt((yyvsp[-3].pblockstmt), (yyvsp[-1].pexpr), (yyvsp[0].pexpr)); }
#line 6668 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 301:
#line 1333 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new DefExpr(new VarSymbol("chpl__tuple_blank")); }
#line 6674 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 302:
#line 1335 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new DefExpr(new VarSymbol((yyvsp[0].pch))); }
#line 6680 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 303:
#line 1337 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[-1].pblockstmt); }
#line 6686 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 304:
#line 1342 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt((yyvsp[0].pexpr)); }
#line 6692 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 305:
#line 1344 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = buildChapelStmt((yyvsp[-1].pexpr)); }
#line 6698 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 306:
#line 1346 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pblockstmt) = ((yyvsp[0].pblockstmt)->insertAtHead((yyvsp[-2].pexpr)), (yyvsp[0].pblockstmt)); }
#line 6704 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 307:
#line 1352 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 6710 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 308:
#line 1353 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new SymExpr(gNoInit); }
#line 6716 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 309:
#line 1354 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 6722 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 310:
#line 1358 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 6728 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 311:
#line 1359 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 6734 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 312:
#line 1360 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pcallexpr); }
#line 6740 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 313:
#line 1361 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 6746 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 314:
#line 1382 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pexpr));
    }
#line 6754 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 315:
#line 1386 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pcallexpr));
    }
#line 6762 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 316:
#line 1390 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pexpr), "invalid index expression");
      (yyval.pcallexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pexpr)), (yyvsp[0].pexpr), (yyvsp[-4].pcallexpr)->get(1)->remove(),
             new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pexpr)->copy()));
    }
#line 6774 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 317:
#line 1398 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pcallexpr) = new CallExpr(PRIM_ERROR);
    }
#line 6782 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 318:
#line 1404 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 6788 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 319:
#line 1405 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 6794 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 320:
#line 1406 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pdefexpr); }
#line 6800 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 321:
#line 1411 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, (yyvsp[0].pexpr)); }
#line 6806 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 322:
#line 1413 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildFormalArrayType((yyvsp[-2].pcallexpr), (yyvsp[0].pexpr)); }
#line 6812 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 323:
#line 1419 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, (yyvsp[0].pexpr)); }
#line 6818 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 324:
#line 1421 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildFormalArrayType((yyvsp[-2].pcallexpr), (yyvsp[0].pexpr)); }
#line 6824 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 325:
#line 1423 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildFormalArrayType((yyvsp[-2].pexpr), (yyvsp[0].pexpr), (yyvsp[-4].pcallexpr)); }
#line 6830 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 326:
#line 1427 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = NULL; }
#line 6836 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 327:
#line 1428 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 6842 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 328:
#line 1429 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pdefexpr); }
#line 6848 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 329:
#line 1430 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("_domain"); }
#line 6854 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 330:
#line 1431 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr( "_singlevar"); }
#line 6860 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 331:
#line 1432 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr( "_syncvar"); }
#line 6866 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 332:
#line 1433 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 6872 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 333:
#line 1439 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[0].pexpr)); }
#line 6878 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 334:
#line 1440 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[0].pdefexpr)); }
#line 6884 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 335:
#line 1441 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 6890 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 336:
#line 1442 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pdefexpr)); }
#line 6896 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 337:
#line 1446 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[0].pexpr));}
#line 6902 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 338:
#line 1447 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 6908 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 339:
#line 1451 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("chpl__tuple_blank"); }
#line 6914 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 340:
#line 1452 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 6920 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 341:
#line 1453 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pdefexpr); }
#line 6926 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 342:
#line 1457 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 6932 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 343:
#line 1458 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 6938 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 344:
#line 1462 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST); }
#line 6944 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 346:
#line 1467 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[0].pexpr)); }
#line 6950 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 347:
#line 1468 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-2].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 6956 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 348:
#line 1472 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildNamedActual((yyvsp[-2].pch), (yyvsp[0].pdefexpr)); }
#line 6962 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 349:
#line 1473 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildNamedActual((yyvsp[-2].pch), (yyvsp[0].pexpr)); }
#line 6968 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 350:
#line 1474 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pdefexpr); }
#line 6974 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 351:
#line 1475 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 6980 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 352:
#line 1479 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr((yyvsp[0].pch)); }
#line 6986 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 358:
#line 1496 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr( "_singlevar", (yyvsp[0].pexpr)); }
#line 6992 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 359:
#line 1498 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildIndexType", (yyvsp[-1].pcallexpr)); }
#line 6998 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 360:
#line 1500 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildDomainRuntimeType", new UnresolvedSymExpr("defaultDist"), (yyvsp[-1].pcallexpr)); }
#line 7004 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 361:
#line 1502 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildSubDomainType", (yyvsp[-1].pcallexpr)); }
#line 7010 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 362:
#line 1504 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildSparseDomainRuntimeType", buildDotExpr((yyvsp[-1].pcallexpr)->copy(), "defaultSparseDist"), (yyvsp[-1].pcallexpr)); }
#line 7016 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 363:
#line 1506 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__atomicType", (yyvsp[0].pexpr)); }
#line 7022 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 364:
#line 1508 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr( "_syncvar", (yyvsp[0].pexpr)); }
#line 7028 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 365:
#line 1513 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7034 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 366:
#line 1515 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[-4].pexpr), zipToTuple((yyvsp[-2].pcallexpr)), (yyvsp[0].pexpr), NULL, false, true); }
#line 7040 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 367:
#line 1517 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForLoopExpr(NULL, (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7046 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 368:
#line 1519 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[-7].pexpr), (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 7052 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 369:
#line 1521 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[-7].pexpr), zipToTuple((yyvsp[-5].pcallexpr)), (yyvsp[0].pexpr), (yyvsp[-2].pexpr), false, true); }
#line 7058 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 370:
#line 1523 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForLoopExpr(NULL, (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 7064 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 371:
#line 1525 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7070 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 372:
#line 1527 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[-4].pexpr), zipToTuple((yyvsp[-2].pcallexpr)), (yyvsp[0].pexpr), NULL, false, true); }
#line 7076 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 373:
#line 1529 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForallLoopExpr(NULL, (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7082 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 374:
#line 1531 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[-7].pexpr), (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 7088 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 375:
#line 1533 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[-7].pexpr), zipToTuple((yyvsp[-5].pcallexpr)), (yyvsp[0].pexpr), (yyvsp[-2].pexpr), false, true); }
#line 7094 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 376:
#line 1535 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildForallLoopExpr(NULL, (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 7100 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 377:
#line 1537 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-2].pcallexpr)->argList.length > 1)
        (yyval.pexpr) = buildForallLoopExpr(NULL, new CallExpr("chpl__ensureDomainExpr", (yyvsp[-2].pcallexpr)), (yyvsp[0].pexpr), NULL, true);
      else
        (yyval.pexpr) = buildForallLoopExpr(NULL, (yyvsp[-2].pcallexpr)->get(1)->remove(), (yyvsp[0].pexpr), NULL, true);
    }
#line 7111 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 378:
#line 1544 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[-4].pcallexpr)->get(1)->remove(), (yyvsp[-2].pexpr), (yyvsp[0].pexpr), NULL, true);
    }
#line 7121 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 379:
#line 1550 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-4].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-2].pcallexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[-4].pcallexpr)->get(1)->remove(), zipToTuple((yyvsp[-2].pcallexpr)), (yyvsp[0].pexpr), NULL, false, true);
    }
#line 7131 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 380:
#line 1556 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-7].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-5].pexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[-7].pcallexpr)->get(1)->remove(), (yyvsp[-5].pexpr), (yyvsp[0].pexpr), (yyvsp[-2].pexpr));
    }
#line 7141 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 381:
#line 1562 "chapel.ypp" /* yacc.c:1661  */
    {
      if ((yyvsp[-7].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[-5].pcallexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[-7].pcallexpr)->get(1)->remove(), zipToTuple((yyvsp[-5].pcallexpr)), (yyvsp[0].pexpr), (yyvsp[-2].pexpr), false, true);
    }
#line 7151 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 382:
#line 1571 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(new DefExpr(buildIfExpr((yyvsp[-4].pexpr), (yyvsp[-2].pexpr), (yyvsp[0].pexpr)))); }
#line 7157 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 383:
#line 1580 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new SymExpr(gNil); }
#line 7163 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 391:
#line 1596 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("<~>", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7169 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 392:
#line 1600 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = NULL; }
#line 7175 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 394:
#line 1605 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = (yyvsp[-1].pcallexpr); }
#line 7181 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 395:
#line 1610 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST);
      addTaskIntent((yyval.pcallexpr), (yyvsp[0].pShadowVar)); }
#line 7188 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 396:
#line 1613 "chapel.ypp" /* yacc.c:1661  */
    { addTaskIntent((yyvsp[-2].pcallexpr), (yyvsp[0].pShadowVar)); }
#line 7194 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 397:
#line 1617 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = (yyvsp[-1].pcallexpr); }
#line 7200 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 398:
#line 1622 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST);
      addForallIntent((yyval.pcallexpr), (yyvsp[0].pShadowVar)); }
#line 7207 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 399:
#line 1625 "chapel.ypp" /* yacc.c:1661  */
    { addForallIntent((yyvsp[-2].pcallexpr), (yyvsp[0].pShadowVar)); }
#line 7213 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 400:
#line 1629 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pShadowVar) = ShadowVarSymbol::buildFromArgIntent((yyvsp[-1].pt), (yyvsp[0].pexpr));
    }
#line 7221 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 401:
#line 1632 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pShadowVar) = ShadowVarSymbol::buildFromReduceIntent((yyvsp[0].pexpr), (yyvsp[-2].pexpr));
    }
#line 7229 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 402:
#line 1635 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pShadowVar) = ShadowVarSymbol::buildFromReduceIntent((yyvsp[0].pexpr), (yyvsp[-2].pexpr));
    }
#line 7237 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 404:
#line 1643 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("<~>", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7243 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 405:
#line 1648 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(PRIM_NEW, (yyvsp[0].pexpr)); }
#line 7249 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 406:
#line 1653 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildLetExpr((yyvsp[-2].pblockstmt), (yyvsp[0].pexpr)); }
#line 7255 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 415:
#line 1669 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(PRIM_TUPLE_EXPAND, (yyvsp[-1].pexpr)); }
#line 7261 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 416:
#line 1671 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = createCast((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7267 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 417:
#line 1673 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl_build_bounded_range", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7273 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 418:
#line 1675 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl_build_low_bounded_range", (yyvsp[-1].pexpr)); }
#line 7279 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 419:
#line 1677 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl_build_high_bounded_range", (yyvsp[0].pexpr)); }
#line 7285 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 420:
#line 1679 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl_build_unbounded_range"); }
#line 7291 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 421:
#line 1683 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = tryExpr((yyvsp[0].pexpr)); }
#line 7297 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 422:
#line 1684 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = tryBangExpr((yyvsp[0].pexpr)); }
#line 7303 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 423:
#line 1685 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[0].pexpr); }
#line 7309 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 430:
#line 1707 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr((yyvsp[-3].pexpr), (yyvsp[-1].pcallexpr)); }
#line 7315 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 431:
#line 1708 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildSquareCallExpr((yyvsp[-3].pexpr), (yyvsp[-1].pcallexpr)); }
#line 7321 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 432:
#line 1709 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildPrimitiveExpr((yyvsp[-1].pcallexpr)); }
#line 7327 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 433:
#line 1713 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildDotExpr((yyvsp[-2].pexpr), (yyvsp[0].pch)); }
#line 7333 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 434:
#line 1714 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(PRIM_TYPEOF, (yyvsp[-2].pexpr)); }
#line 7339 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 435:
#line 1715 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildDotExpr((yyvsp[-2].pexpr), "_dom"); }
#line 7345 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 436:
#line 1723 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = (yyvsp[-1].pexpr); }
#line 7351 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 437:
#line 1724 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildOneTuple((yyvsp[-2].pexpr)); }
#line 7357 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 438:
#line 1725 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildTuple((yyvsp[-1].pcallexpr)); }
#line 7363 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 439:
#line 1726 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildTuple((yyvsp[-2].pcallexpr)); }
#line 7369 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 440:
#line 1730 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildIntLiteral((yyvsp[0].pch));    }
#line 7375 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 441:
#line 1731 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildRealLiteral((yyvsp[0].pch));   }
#line 7381 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 442:
#line 1732 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildImagLiteral((yyvsp[0].pch));   }
#line 7387 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 443:
#line 1733 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildStringLiteral((yyvsp[0].pch)); }
#line 7393 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 444:
#line 1734 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildCStringLiteral((yyvsp[0].pch)); }
#line 7399 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 445:
#line 1735 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildDomainExpr", (yyvsp[-1].pcallexpr)); }
#line 7405 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 446:
#line 1736 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildDomainExpr", (yyvsp[-2].pcallexpr)); }
#line 7411 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 447:
#line 1737 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayExpr",  (yyvsp[-1].pcallexpr)); }
#line 7417 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 448:
#line 1738 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayExpr",  (yyvsp[-2].pcallexpr)); }
#line 7423 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 449:
#line 1740 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pexpr) = new CallExpr("chpl__buildAssociativeArrayExpr", (yyvsp[-1].pcallexpr));
    }
#line 7431 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 450:
#line 1744 "chapel.ypp" /* yacc.c:1661  */
    {
      (yyval.pexpr) = new CallExpr("chpl__buildAssociativeArrayExpr", (yyvsp[-2].pcallexpr));
    }
#line 7439 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 451:
#line 1751 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7445 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 452:
#line 1752 "chapel.ypp" /* yacc.c:1661  */
    { (yyvsp[-4].pcallexpr)->insertAtTail((yyvsp[-2].pexpr)); (yyvsp[-4].pcallexpr)->insertAtTail((yyvsp[0].pexpr)); }
#line 7451 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 453:
#line 1756 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("+", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7457 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 454:
#line 1757 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("-", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7463 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 455:
#line 1758 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("*", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7469 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 456:
#line 1759 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("/", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7475 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 457:
#line 1760 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("<<", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7481 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 458:
#line 1761 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(">>", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7487 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 459:
#line 1762 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("%", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7493 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 460:
#line 1763 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("==", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7499 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 461:
#line 1764 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("!=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7505 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 462:
#line 1765 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("<=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7511 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 463:
#line 1766 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(">=", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7517 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 464:
#line 1767 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("<", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7523 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 465:
#line 1768 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr(">", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7529 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 466:
#line 1769 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("&", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7535 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 467:
#line 1770 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("|", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7541 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 468:
#line 1771 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("^", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7547 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 469:
#line 1772 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("&&", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7553 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 470:
#line 1773 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("||", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7559 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 471:
#line 1774 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("**", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7565 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 472:
#line 1775 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl_by", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7571 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 473:
#line 1776 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl_align", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7577 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 474:
#line 1777 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("#", (yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7583 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 475:
#line 1778 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("chpl__distributed", (yyvsp[0].pexpr), (yyvsp[-2].pexpr)); }
#line 7589 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 476:
#line 1782 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("+", (yyvsp[0].pexpr)); }
#line 7595 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 477:
#line 1783 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("-", (yyvsp[0].pexpr)); }
#line 7601 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 478:
#line 1784 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildPreDecIncWarning((yyvsp[0].pexpr), '-'); }
#line 7607 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 479:
#line 1785 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildPreDecIncWarning((yyvsp[0].pexpr), '+'); }
#line 7613 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 480:
#line 1786 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("!", (yyvsp[0].pexpr)); }
#line 7619 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 481:
#line 1787 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new CallExpr("~", (yyvsp[0].pexpr)); }
#line 7625 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 482:
#line 1791 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildReduceExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7631 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 483:
#line 1792 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildReduceExpr((yyvsp[-2].pexpr), zipToTuple((yyvsp[0].pcallexpr)), true); }
#line 7637 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 484:
#line 1793 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildReduceExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7643 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 485:
#line 1794 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildReduceExpr((yyvsp[-2].pexpr), zipToTuple((yyvsp[0].pcallexpr)), true); }
#line 7649 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 486:
#line 1798 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildScanExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7655 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 487:
#line 1799 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildScanExpr((yyvsp[-2].pexpr), zipToTuple((yyvsp[0].pcallexpr)), true); }
#line 7661 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 488:
#line 1800 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildScanExpr((yyvsp[-2].pexpr), (yyvsp[0].pexpr)); }
#line 7667 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 489:
#line 1801 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = buildScanExpr((yyvsp[-2].pexpr), zipToTuple((yyvsp[0].pcallexpr)), true); }
#line 7673 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 490:
#line 1806 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("SumReduceScanOp"); }
#line 7679 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 491:
#line 1807 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("ProductReduceScanOp"); }
#line 7685 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 492:
#line 1808 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("LogicalAndReduceScanOp"); }
#line 7691 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 493:
#line 1809 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("LogicalOrReduceScanOp"); }
#line 7697 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 494:
#line 1810 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("BitwiseAndReduceScanOp"); }
#line 7703 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 495:
#line 1811 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("BitwiseOrReduceScanOp"); }
#line 7709 "bison-chapel.cpp" /* yacc.c:1661  */
    break;

  case 496:
#line 1812 "chapel.ypp" /* yacc.c:1661  */
    { (yyval.pexpr) = new UnresolvedSymExpr("BitwiseXorReduceScanOp"); }
#line 7715 "bison-chapel.cpp" /* yacc.c:1661  */
    break;


#line 7719 "bison-chapel.cpp" /* yacc.c:1661  */
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
