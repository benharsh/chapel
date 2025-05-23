/*
 * Copyright 2020-2025 Hewlett Packard Enterprise Development LP
 * Copyright 2004-2019 Cray Inc.
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

#include "astlocs.h"

#include "chpl/parsing/parsing-queries.h" // for locateId
#include "expr.h"
#include "stmt.h"
#include "stringutil.h"

#include <cstddef>

astlocT currentAstLoc(0,NULL);

/************************************* | **************************************
*                                                                             *
* Definitions for astlocT                                                     *
*                                                                             *
************************************** | *************************************/

static int compareFileLine(const char* lhsFilename, int lhsLineno,
                           const char* rhsFilename, int rhsLineno) {
  if (lhsFilename && rhsFilename) {
    int strResult = strcmp(lhsFilename, rhsFilename);
    if (strResult != 0) return strResult;
    return lhsLineno - rhsLineno;
  } else if (!lhsFilename) {
    return -1;
  } else {
    return 1;
  }
}

int astlocT::compare(const astlocT& other) const {
  if (this->filename_ == nullptr && other.filename_ == nullptr) {
    // compare IDs
    return this->id_.compare(other.id_);
  } else {
    return compareFileLine(this->filename_, this->lineno_,
                           other.filename_,
                           other.lineno_);
  }
}

bool astlocT::hasSameFileLine(const astlocT& other) const {
  const char* lhsFilename = this->filename_;
  int lhsLineno = this->lineno_;
  const char* rhsFilename = other.filename_;
  int rhsLineno = other.lineno_;

  if (!lhsFilename && !this->id_.isEmpty()) {
    this->convertIdToFileLine(lhsFilename, lhsLineno);
  }

  if (!rhsFilename && !other.id_.isEmpty()) {
    other.convertIdToFileLine(rhsFilename, rhsLineno);
  }

  int cmp = compareFileLine(lhsFilename, lhsLineno,
                            rhsFilename,
                            rhsLineno);
  return cmp == 0;
}

void astlocT::convertIdToFileLine(const char*& filename, int& lineno) const {
  if (!this->id_.isEmpty()) {
    // figure out the location from the ID
    chpl::Location loc = chpl::parsing::locateId(gContext, this->id_);
    filename = astr(loc.path().c_str());
    lineno = loc.line();
  } else {
    filename = astr("<unknown location>");
    lineno = 0;
  }

  // cache the result in the fields for later use
  this->filename_ = filename;
  this->lineno_ = lineno;
}

const char* astlocT::stringLoc() const {
  char linenoBuf[16];

  snprintf(linenoBuf, sizeof(linenoBuf), "%d", this->lineno());
  return astr(this->filename(), ":", linenoBuf);
}

const char* astlocT::stringLineno() const {
  char linenoBuf[16];

  snprintf(linenoBuf, sizeof(linenoBuf), "%d", this->lineno());
  return astr(linenoBuf);
}

/************************************* | **************************************
*                                                                             *
* Definitions for astlocMarker                                                *
*                                                                             *
************************************** | *************************************/

// constructor, invoked upon SET_LINENO
astlocMarker::astlocMarker(astlocT newAstLoc)
  : previousAstLoc(currentAstLoc)
{
  //previousAstLoc = currentAstLoc;
  currentAstLoc = newAstLoc;
}

// constructor, for special occasions
astlocMarker::astlocMarker(int lineno, const char* filename)
  : previousAstLoc(currentAstLoc)
{
  currentAstLoc = astlocT(lineno, astr(filename));
}

// constructor, for dyno Locations
astlocMarker::astlocMarker(chpl::Location location)
  : previousAstLoc(currentAstLoc)
{
  currentAstLoc = astlocT(location.line(), astr(location.path().c_str()));
}

// destructor, invoked upon leaving SET_LINENO's scope
astlocMarker::~astlocMarker() {
  currentAstLoc = previousAstLoc;
}

/************************************* | **************************************
*                                                                             *
* Functions for finding AST locations                                         *
*                                                                             *
************************************** | *************************************/


// find an AST location that is:
//   not in an inlined/"find user line" function or a
//   task function in an inlined function
//     in non-user modules
//     (unless preserveInlinedLineNumbers==true)
//   not in a function beginning with chpl__
//     (unless developer==true or preserveInlinedLineNumbers==true)
// to use for line number reporting.
//
// Note that "inlined" here refers to FLAG_INLINED_FN.
// It does not mean the same as the 'inline'
// keyword and it may only apply to task functions.
Expr* findLocationIgnoringInternalInlining(Expr* cur) {

  while (true) {
    if (cur == NULL || cur->parentSymbol == NULL)
      return cur;

    FnSymbol* curFn = cur->getFunction();
    // If we didn't find a function, or it's not in tree, give up
    if (curFn == NULL || curFn->inTree() == false)
      return cur;

    // If it's already in user code, use that, because
    // the line number is probably better
    if (curFn->getModule()->modTag == MOD_USER)
      return cur;

    bool startsWithChpl = developer==false &&
                          startsWith(curFn->name, "chpl__");
    bool inlined = curFn->hasFlag(FLAG_FIND_USER_LINE) ||
                   curFn->hasFlag(FLAG_INLINED_FN);
    if (preserveInlinedLineNumbers ||
        (startsWithChpl==false && inlined==false))
      return cur;

    // If we're in a module init function, we can't go any further
    if (curFn->hasFlag(FLAG_MODULE_INIT)) return cur;

    // Look for a call to that function
    CallExpr* anyCall = NULL;
    CallExpr* userCall = NULL;
    for_SymbolSymExprs(se, curFn) {
      CallExpr* call = toCallExpr(se->parentExpr);
      if (se == call->baseExpr) {
        if (anyCall == NULL)
          anyCall = call;
        if (call->getModule()->modTag == MOD_USER && userCall == NULL)
          userCall = call;
        break;
      }
    }

    if (userCall != NULL)
      cur = userCall;
    else if (anyCall != NULL)
      cur = anyCall;
    else
      return cur; // Stop if we didn't find any calls.
  }

  return cur; // never reached
}

bool printsUserLocation(const BaseAST* astIn) {
  BaseAST* ast = const_cast<BaseAST*>(astIn);

  if (Expr* expr = toExpr(ast)) {
    Expr* foundExpr = findLocationIgnoringInternalInlining(expr);
    if (foundExpr != NULL)
      ast = foundExpr;
  }

  ModuleSymbol* mod = NULL;
  if (ast)
    mod = ast->getModule();

  return (ast && mod && mod->modTag == MOD_USER);
}

static SymExpr* findMentionOfSymbol(BlockStmt* block, Symbol* sym) {
  std::vector<SymExpr*> symExprs;
  collectSymExprsFor(block, sym, symExprs);
  for_vector(SymExpr, se, symExprs) {
    if (se->symbol() == sym) {
      return se;
    }
  }
  return NULL;
}

astlocT getUserInstantiationPoint(const BaseAST* ast) {

  // TODO - call this function for instantiating AggregateType and FnSymbol

  BaseAST* cur = const_cast<BaseAST*>(ast);

  while (true) {

    // Stop if this is already a user location
    if (printsUserLocation(cur)) break;

    BaseAST* last = cur;

    if (DefExpr* d = toDefExpr(cur)) {
      // Continue with the defined symbol
      if (d->sym != NULL)
        cur = d->sym;
    } else if (Expr* e = toExpr(cur)) {
      // Continue with the expression's parent function
      FnSymbol* parentFn = e->getFunction();
      if (parentFn != NULL)
        cur = parentFn;
    } else if (FnSymbol* fn = toFnSymbol(cur)) {
      // Find the first call to the function within the instantiation point,
      // so that we can have a better error message line number.
      BlockStmt* instantiationPoint = fn->instantiationPoint();

      if (instantiationPoint != NULL) {
        SymExpr* mention = findMentionOfSymbol(instantiationPoint, fn);
        if (mention != NULL)
          cur = mention;
        else
          cur = instantiationPoint;
      }
    } else if (TypeSymbol* ts = toTypeSymbol(cur)) {
      // Find the first use of the TypeSymbol at the type's instantiation point
      // so we can have a better error message line number.
      BlockStmt* instantiationPoint = ts->instantiationPoint;

      if (instantiationPoint != NULL) {
        SymExpr* mention = findMentionOfSymbol(instantiationPoint, ts);
        if (mention != NULL)
          cur = mention;
        else
          cur = instantiationPoint;
      }
    }

    // Stop if we've made no progress
    if (last == cur) break;
  }

  INT_ASSERT(cur != NULL);
  return cur->astloc;
}
