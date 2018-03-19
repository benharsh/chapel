/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 32 "chapel.ypp" /* yacc.c:1915  */

  #include <string>
  extern int         captureTokens;
  extern std::string captureString;
#line 45 "chapel.ypp" /* yacc.c:1915  */

  #ifndef _BISON_CHAPEL_DEFINES_0_
  #define _BISON_CHAPEL_DEFINES_0_

  #define YYLEX_NEWLINE                  -1
  #define YYLEX_SINGLE_LINE_COMMENT      -2
  #define YYLEX_BLOCK_COMMENT            -3

  typedef void* yyscan_t;

  int processNewline(yyscan_t scanner);
  void stringBufferInit();

  #endif
#line 65 "chapel.ypp" /* yacc.c:1915  */

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
#line 130 "chapel.ypp" /* yacc.c:1915  */

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
#line 152 "chapel.ypp" /* yacc.c:1915  */

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

#line 169 "../include/bison-chapel.h" /* yacc.c:1915  */

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
#line 183 "chapel.ypp" /* yacc.c:1915  */

  extern int yydebug;

  void yyerror(YYLTYPE*       ignored,
               ParserContext* context,
               const char*    str);

#line 362 "../include/bison-chapel.h" /* yacc.c:1915  */

#endif /* !YY_YY_INCLUDE_BISON_CHAPEL_H_INCLUDED  */
