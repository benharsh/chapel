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

#define TYPE_EXTERN

#include "type.h"

#include "AggregateType.h"
#include "AstToText.h"
#include "astutil.h"
#include "AstVisitor.h"
#include "build.h"
#include "fcf-support.h"
#include "DecoratedClassType.h"
#include "driver.h"
#include "expr.h"
#include "files.h"
#include "intents.h"
#include "intlimits.h"
#include "iterator.h"
#include "misc.h"
#include "passes.h"
#include "resolution.h"
#include "resolveIntents.h"
#include "stlUtil.h"
#include "stringutil.h"
#include "symbol.h"
#include "vec.h"
#include "wellknown.h"

#include "global-ast-vecs.h"

#include "chpl/framework/compiler-configuration.h"
#include "chpl/types/QualifiedType.h"

#include <cmath>

static bool isDerivedType(Type* type, Flag flag);

Type::Type(AstTag astTag, Symbol* iDefaultVal) : BaseAST(astTag) {
  symbol              = NULL;
  refType             = NULL;
  defaultValue        = iDefaultVal;
  destructor          = NULL;
  isInternalType      = false;
  scalarPromotionType = NULL;
}

const char* Type::name() const {
  return symbol->name;
}

void Type::verify() {
}

void Type::addSymbol(TypeSymbol* newSymbol) {
  symbol = newSymbol;
}

bool Type::inTree() {
  if (symbol && symbol->defPoint)
    return symbol->defPoint->inTree();
  else
    return false;
}

QualifiedType Type::qualType() {
  return QualifiedType(this);
}

// Are actuals of this type passed with const intent by default?
bool Type::isDefaultIntentConst() const {
  bool retval = true;

  // MPF 2017-03-09
  // It seems wrong to me that this returns true
  // for dtUnknown. However some parts of the compiler
  // currently rely on that behavior.

  if (symbol->hasFlag(FLAG_DEFAULT_INTENT_IS_REF) == true ||
      isReferenceType(this)                       == true ||
      isRecordWrappedType(this)                   == true)
    retval = false;

  return retval;
}

bool Type::isWidePtrType() const {
  if (symbol->hasEitherFlag(FLAG_WIDE_REF, FLAG_WIDE_CLASS)) {
    // Workaround an ugly hack in insert wide references
    // which can make a wide _array record containing an "addr" record
    Type* baseType = this->getField("addr")->type;
    if (isReferenceType(baseType) || isClass(baseType) || baseType == dtNil)
      return true;
  }
  return false;
}

Symbol* Type::getField(const char* name, bool fatal) const {
  INT_FATAL(this, "getField not called on AggregateType");
  return NULL;
}

bool Type::hasDestructor() const {
  return destructor != NULL;
}

FnSymbol* Type::getDestructor() const {
  return destructor;
}

void Type::setDestructor(FnSymbol* fn) {
  destructor = fn;
}

bool Type::isSerializable() {
  if (isAggregateType(this)) {
    return serializeMap.find(this->getValType()) != serializeMap.end();
  }

  return false;
}

Symbol* Type::getSubstitutionWithName(const char* name) const {

  if (fVerify) {
    INT_ASSERT(name == astr(name));
  }

  if (this->substitutions.n > 0) {
    // should only exist during resolution
    form_Map(SymbolMapElem, e, this->substitutions) {
      if (e->key && e->key->name == name)
        return e->value;
    }
  }

  // after resolution (or possibly during)
  size_t n = this->substitutionsPostResolve.size();
  for (size_t i = 0; i < n; i++) {
    const NameAndSymbol& ns = this->substitutionsPostResolve[i];
    if (ns.name == name)
      return ns.value;
  }

  return NULL;
}

void Type::setSubstitutionWithName(const char* name, Symbol* value) {

  if (fVerify) {
    INT_ASSERT(name == astr(name));
  }

  size_t n = this->substitutionsPostResolve.size();
  for (size_t i = 0; i < n; i++) {
    NameAndSymbol& ns = this->substitutionsPostResolve[i];
    if (ns.name == name) {
      ns.value = value;
      return;
    }
  }

  // if none was found, we could add one, but that functionality
  // isn't currently used, so error.
  INT_FATAL("substitution not found");
}

// "iterator|promoted expression yielding ..."
// result may be non-astr()
static const char* toIteratorString(AggregateType* at, bool decorateAllClasses) {
  const char* kind = at->symbol->hasFlag(FLAG_PROMOTION_ITERATOR_RECORD)
    ? "promoted expression" : "iterator";
  if (IteratorInfo* ii = at->iteratorInfo)
    if (Type* yt = ii->yieldedType)
      return astr(kind, " yielding ", toString(yt, decorateAllClasses));
  return kind;
}

const char* toString(Type* type, bool decorateAllClasses) {
  const char* retval = NULL;

  if (type == NULL ||
      type == dtUnknown ||
      type->getValType() == dtSplitInitType) {
    retval = "<type unknown>";
  } else if (type == dtAny) {
    retval = "<any type>";
  } else if (type == dtDomain) {
    retval = "domain(?)";
  } else if (auto fnType = toFunctionType(type)) {
    retval = fnType->toString();
  } else {
    Type* vt = type->getValType();

    if (AggregateType* at = toAggregateType(vt)) {
      const char* drDomName = "DefaultRectangularDom";
      const int   drDomNameLen = strlen(drDomName);

      if (isArrayClass(at) && !at->symbol->hasFlag(FLAG_BASE_ARRAY)) {
        Symbol* domField = at->getField("dom", false);
        Symbol* eltTypeField = at->getField("eltType", false);

        if (domField && eltTypeField) {
          Type* domainType = canonicalDecoratedClassType(domField->type);
          Type* eltType    = eltTypeField->type;

          if (domainType != dtUnknown && eltType != dtUnknown)
            retval = astr("[", toString(domainType,false), "] ",
                          toString(eltType));
        }

      } else if (strncmp(at->symbol->name, drDomName, drDomNameLen) == 0) {
        retval = astr("domain", at->symbol->name + drDomNameLen);

      } else if (startsWith(at->symbol->name, "_domain")) {
        retval = astr(at->symbol->name + 1); // skip the leading _

      } else if (at->symbol->hasFlag(FLAG_FUNCTION_CLASS)) {
        retval = fcfs::functionClassTypeToString(at);

      } else if (isRecordWrappedType(at) == true) {
        Symbol* instanceField = at->getField("_instance", false);

        if (instanceField) {
          Type* implType = canonicalDecoratedClassType(instanceField->type);

          if (implType != dtUnknown)
            retval = toString(implType, false);
          else if (at->symbol->hasFlag(FLAG_ARRAY))
            retval = astr("[]");
        }
      } else if (vt->symbol->hasFlag(FLAG_ITERATOR_RECORD)) {
        if (developer == false)
          retval = toIteratorString(at, decorateAllClasses);
      } else if (at->symbol->hasFlag(FLAG_ATOMIC_TYPE) &&
                 (strcmp(at->symbol->name, "AtomicBool") == 0 ||
                  strcmp(at->symbol->name, "RAtomicBool") == 0)) {
        retval = astr("atomic bool");
      } else if (isManagedPtrType(vt)) {
        Type* borrowType = getManagedPtrBorrowType(vt);
        const char* borrowed = "borrowed ";
        const char* borrowName = toString(borrowType, false);
        if (startsWith(borrowName, borrowed)) {
          borrowName = borrowName + strlen(borrowed);
        }
        if (startsWith(vt->symbol->name, "_owned")) {
          if (borrowType == dtUnknown) {
            retval = "owned";
          } else {
            retval = astr("owned ", borrowName);
          }
        }
        else if (startsWith(vt->symbol->name, "_shared")) {
          if (borrowType == dtUnknown) {
            retval = "shared";
          } else {
            retval = astr("shared ", borrowName);
          }
        }

      } else if (isClassLike(at)) {
        if (isClass(at)) {
          // It's an un-decorated class type
          const char* borrowed = "borrowed ";
          const char* useName = vt->symbol->name;
          if (startsWith(useName, borrowed))
            useName = useName + strlen(borrowed);

          if (decorateAllClasses)
            useName = astr("borrowed ", useName);

          retval = useName;
        }
      }
    } else if (vt == dtCVoidPtr) {
      // de-sugar chpl__c_void_ptr, which is used internally and is a distinct
      // type from c_ptr(void)
      retval = "raw_c_void_ptr";
    } else if (vt == dtCFnPtr) {
      retval = "c_fn_ptr";
    } else if (vt == dtStringC) {
      // present dtStringC type as familiar 'c_string' instead of the internal
      // name 'chpl_c_string' or cname, 'c_string_rehook'.
      retval = "c_string";
    }

    if (retval == NULL)
      retval = vt->symbol->name;

    // If the type is generic with defaults, insert a question mark to
    // differentiate it from the concrete instance.
    if (auto at = toAggregateType(vt)) {
      if (at == at->getRootInstantiation() &&
          at->isGenericWithDefaults()) {
        retval = astr(retval, "(?)");
      }
    }

  }

  return astr(retval);
}

/************************************* | **************************************
*                                                                             *
* Qualifier and QualifiedType                                                 *
*                                                                             *
************************************** | *************************************/

const char* qualifierToStr(Qualifier q) {
    switch (q) {
      case QUAL_UNKNOWN:
        return "unknown";

      case QUAL_CONST:
        return "const";
      case QUAL_REF:
        return "ref";
      case QUAL_CONST_REF:
        return "const-ref";

      case QUAL_PARAM:
        return "param";

      case QUAL_VAL:
        return "val";
      case QUAL_NARROW_REF:
        return "narrow-ref";
      case QUAL_WIDE_REF:
        return "wide-ref";

      case QUAL_CONST_VAL:
        return "const-val";
      case QUAL_CONST_NARROW_REF:
        return "const-narrow-ref";
      case QUAL_CONST_WIDE_REF:
        return "const-wide-ref";
    }

    INT_FATAL("Unhandled Qualifier");
    return "UNKNOWN-QUAL";
}

bool QualifiedType::isRefType() const {
  return _type->symbol->hasFlag(FLAG_REF);
}

bool QualifiedType::isWideRefType() const {
  return _type->symbol->hasFlag(FLAG_WIDE_REF);
}

const char* QualifiedType::qualStr() const {
  if (isRefType()) {
    if (_qual == QUAL_CONST_REF ||
        _qual == QUAL_CONST) {
      return qualifierToStr(QUAL_CONST_REF);
    } else {
      return qualifierToStr(QUAL_REF);
    }
  }

  if (isWideRefType())
    return qualifierToStr(QUAL_WIDE_REF);

  // otherwise
  return qualifierToStr(_qual);
}

QualifiedType QualifiedType::refToRefType() const {
  Qualifier qual = _qual;
  Type* type = _type;
  if (isRef() && !type->symbol->hasFlag(FLAG_REF)) {
    // Use a ref type here.
    // In the future, the Qualifier should be sufficient
    INT_ASSERT(type->refType != NULL);
    type = type->refType;
  }

  return QualifiedType(qual, type);
}

/************************************* | **************************************
*                                                                             *
*                                                                             *
*                                                                             *
************************************** | *************************************/

PrimitiveType::PrimitiveType(Symbol *init, bool internalType) :
  Type(E_PrimitiveType, init)
{
  isInternalType = internalType;
  gPrimitiveTypes.add(this);
}


PrimitiveType*
PrimitiveType::copyInner(SymbolMap* map) {
  //
  // If we're trying to make a copy of an internal Chapel primitive
  // type (say 'int'), that's a sign that something is wrong.  For
  // external primitive types, it should be OK to make such copies.
  // This may be desired/required if the extern type declaration is
  // local to a generic Chapel procedure for example and we're
  // creating multiple instantiations of that procedure, each of which
  // wants/needs its own local type symbol.  This exception may
  // suggest that external primitive types should really be
  // represented as their own ExternType class...
  //
  if (!symbol->hasFlag(FLAG_EXTERN)) {
    INT_FATAL(this, "Unexpected call to PrimitiveType::copyInner");
  }

  return new PrimitiveType(NULL);
}


void PrimitiveType::replaceChild(BaseAST* old_ast, BaseAST* new_ast) {
  INT_FATAL(this, "Unexpected case in PrimitiveType::replaceChild");
}


void PrimitiveType::verify() {
  Type::verify();
  if (astTag != E_PrimitiveType) {
    INT_FATAL(this, "Bad PrimitiveType::astTag");
  }
}


void PrimitiveType::accept(AstVisitor* visitor) {
  visitor->visitPrimType(this);
}


ConstrainedType::ConstrainedType(ConstrainedTypeUse use) :
  Type(E_ConstrainedType, NULL), ctUse(use)
{
  gConstrainedTypes.add(this);
}

ConstrainedType* ConstrainedType::copyInner(SymbolMap* map) {
  return new ConstrainedType(ctUse);
}

void ConstrainedType::replaceChild(BaseAST* old_ast, BaseAST* new_ast) {
  INT_FATAL(this, "Unexpected case in ConstrainedType::replaceChild");
}

void ConstrainedType::verify() {
  Type::verify();
  INT_ASSERT(astTag == E_ConstrainedType);

  DefExpr* def = symbol->defPoint;  // assumes this->inTree()
  switch (ctUse) {
  case CT_IFC_FORMAL: {
    InterfaceSymbol* isym = toInterfaceSymbol(def->parentSymbol);
    INT_ASSERT(def->list == &(isym->ifcFormals));
    break;
  }
  case CT_IFC_ASSOC_TYPE: {
    InterfaceSymbol* isym = toInterfaceSymbol(def->parentSymbol);
    INT_ASSERT(def->parentExpr == isym->ifcBody);
    break;
  }
  case CT_CGFUN_FORMAL: {
    FnSymbol* fn = toFnSymbol(def->parentSymbol);
    INT_ASSERT(def->list == &(fn->interfaceInfo->constrainedTypes));
    break;
  }
  case CT_CGFUN_ASSOC_TYPE: {
    // These arise during resolution and are pruned at resolution end.
    INT_FATAL(this, "unexpected");
    break;
  }}
}

const char* ConstrainedType::useString() const {
  switch (ctUse) {
  case CT_IFC_FORMAL:       return "CT_IFC_FORMAL";
  case CT_IFC_ASSOC_TYPE:   return "CT_IFC_ASSOC_TYPE";
  case CT_CGFUN_FORMAL:     return "CT_CGFUN_FORMAL";
  case CT_CGFUN_ASSOC_TYPE: return "CT_CGFUN_ASSOC_TYPE";
  }
  INT_FATAL(this, "unknown ConstrainedType use");
  return NULL;
}

void ConstrainedType::accept(AstVisitor* visitor) {
  visitor->visitConstrainedType(this);
}

TypeSymbol* ConstrainedType::buildSym(const char* name,
                                      ConstrainedTypeUse use) {
  Type* ct = new ConstrainedType(use);
  return new TypeSymbol(name, ct);
}

ConstrainedType* ConstrainedType::buildType(const char* name,
                                         ConstrainedTypeUse use) {
  ConstrainedType* ct = new ConstrainedType(use);
  new TypeSymbol(name, ct); // attaches to 'ct'
  return ct;
}

bool isConstrainedType(Type* t, ConstrainedTypeUse use) {
  if (ConstrainedType* ct = toConstrainedType(t))
    if (ct->ctUse == use)
      return true;
  return false;
}

bool isConstrainedTypeSymbol(Symbol* s, ConstrainedTypeUse use) {
  if (TypeSymbol* ts = toTypeSymbol(s))
    if (isConstrainedType(ts->type, use))
      return true;
  return false;
}

EnumType::EnumType() :
  Type(E_EnumType, NULL),
  constants(), integerType(NULL),
  doc(NULL)
{
  gEnumTypes.add(this);
  constants.parent = this;
}

void EnumType::verify() {
  Type::verify();
  if (astTag != E_EnumType) {
    INT_FATAL(this, "Bad EnumType::astTag");
  }
  if (constants.parent != this)
    INT_FATAL(this, "Bad AList::parent in EnumType");
  for_alist(expr, constants) {
    if (expr->parentSymbol != symbol)
      INT_FATAL(this, "Bad EnumType::constants::parentSymbol");
    if (!isDefExpr(expr))
      INT_FATAL(this, "Bad EnumType::constants - not a DefExpr");
  }
}


EnumType*
EnumType::copyInner(SymbolMap* map) {
  EnumType* copy = new EnumType();

  for_enums(def, this) {
    DefExpr* newDef = COPY_INT(def);
    newDef->sym->type = copy;
    copy->constants.insertAtTail(newDef);
  }
  copy->addSymbol(symbol);
  return copy;
}


void EnumType::replaceChild(BaseAST* old_ast, BaseAST* new_ast) {
  INT_FATAL(this, "Unexpected case in EnumType::replaceChild");
}


bool EnumType::isAbstract() {
  for_enums(constant, this) {
    if (constant->init) {
      return false;
    }
  }
  return true;
}

bool EnumType::isConcrete() {
  // if the first constant has an initializer, it's concrete;
  // otherwise, it's not.  This loop with a guaranteed return is a
  // lazy way of getting that first constant.
  for_enums(constant, this) {
    if (constant->init) {
      return true;
    } else {
      return false;
    }
  }
  return true;
}


PrimitiveType* EnumType::getIntegerType() {
  INT_ASSERT(integerType);
  return integerType;
}


void EnumType::accept(AstVisitor* visitor) {
  if (visitor->enterEnumType(this) == true) {

    for_alist(next_ast, constants) {
      next_ast->accept(visitor);
    }

    visitor->exitEnumType(this);
  }
}


/************************************* | **************************************
*                                                                             *
*                                                                             *
*                                                                             *
************************************** | *************************************/

namespace {
  using FormalVec = std::vector<FunctionType::Formal>;
}

FunctionType::FunctionType(Kind kind, Width width, Linkage linkage,
                           FormalVec formals,
                           RetTag returnIntent,
                           Type* returnType,
                           bool throws,
                           bool isAnyFormalNamed,
                           const char* userTypeString)
    : Type(E_FunctionType, nullptr),
      kind_(kind),
      width_(width),
      linkage_(linkage),
      formals_(std::move(formals)),
      returnIntent_(returnIntent),
      returnType_(returnType),
      throws_(throws),
      isAnyFormalNamed_(isAnyFormalNamed),
      userTypeString_(userTypeString) {
}

namespace {

  // Used to hash by value instead of hashing the pointer.
  struct FunctionTypePtrHash {
    size_t operator()(const FunctionType* x) const {
      return x->hash();
    }
  };

  // Used to compare by value instead of doing pointer comparison.
  struct FunctionTypePtrEq {
    bool operator()(const FunctionType* lhs,
                    const FunctionType* rhs) const {
      return lhs->equals(rhs);
    }
  };

  using FunctionTypeCache =
    std::unordered_set<FunctionType*, FunctionTypePtrHash,
                       FunctionTypePtrEq>;
}

// Cache to make sure that we don't produce duplicate function types.
static FunctionTypeCache functionTypeCache;

FunctionType::~FunctionType() {
  auto it = functionTypeCache.find(this);
  if (it != functionTypeCache.end()) {
    functionTypeCache.erase(it);
  }
}

void FunctionType::verify() {
  Type::verify();

  if (!returnType()->symbol->inTree()) {
    INT_FATAL(this->symbol, "The function type %s is used but has a return "
                            "type %s that is no longer in the tree",
                            typeToString(this),
                            typeToString(returnType()));
  }

  if (numFormals() > 0) {
    for (int i = 0; i < numFormals(); i++) {
      auto name = formal(i)->name();
      auto type = formal(i)->type();
      if (!type->inTree()) {
        INT_FATAL(this->symbol, "The function type %s is used but has a "
                                "formal %s with a type %s that is no "
                                "longer in the tree",
                                typeToString(this), name,
                                typeToString(type));
      }
    }
  }
}

void FunctionType::accept(AstVisitor* visitor) {
  visitor->visitFunctionType(this);
}

FunctionType* FunctionType::copyInner(SymbolMap* map) {
  INT_FATAL(this, "attempt to copy function type");
  return nullptr;
}

void
FunctionType::replaceChild(BaseAST* old_ast, BaseAST* new_ast) {
  INT_FATAL(this, "unexpected case in 'FunctionType::%s'", __FUNCTION__);
}

const char*
FunctionType::buildUserTypeString(FunctionType::Kind kind,
                                  FunctionType::Width width,
                                  FunctionType::Linkage linkage,
                                  const FormalVec& formals,
                                  RetTag returnIntent,
                                  Type* returnType,
                                  bool throws) {
  std::ostringstream oss;

  if (developer) {
    oss << FunctionType::widthToString(width) << " ";
  }

  if (auto linkageStr = FunctionType::linkageToString(linkage)) {
    oss << linkageStr << " ";
  }

  oss << FunctionType::kindToString(kind) << "(";

  for (size_t i = 0; i < formals.size(); i++) {
    auto& info = formals[i];

    INT_ASSERT(info.name());

    if (info.intent() != INTENT_BLANK) {
      oss << intentToString(info.intent());
      if (info.name()) oss << " ";
    }

    if (info.name()) oss << info.name();
    if (info.name() && info.type() != dtAny) oss << ": ";
    if (info.type() != dtAny) oss << typeToString(info.type());
    if ((i+1) != formals.size()) oss << ", ";
  }

  oss << ")";

  if (returnIntent != RET_VALUE) {
    oss << " " << returnIntentToString(returnIntent);
  }

  if (returnType != dtVoid) {
    oss << ": " << typeToString(returnType);
  }

  if (throws) {
    oss << " " << "throws";
  }

  auto str = oss.str();
  auto ret = astr(str.c_str());
  return ret;
}

const char* FunctionType::kindToString(FunctionType::Kind kind) {
  switch (kind) {
    case PROC: return "proc";
    case ITER: return "iter";
    case OPERATOR: return "operator";
  }
  return nullptr;
}

const char* FunctionType::widthToString(FunctionType::Width width) {
  switch (width) {
    case LOCAL: return "local";
    case WIDE: return "wide";
  }
  return nullptr;
}

const char* FunctionType::linkageToString(FunctionType::Linkage linkage) {
  switch (linkage) {
    case EXTERN: return "extern";
    case EXPORT: return "export";
    case DEFAULT: return nullptr;
  }
  return nullptr;
}

const char* FunctionType::intentToString(IntentTag intent) {
  switch (intent) {
    case INTENT_IN: return "in";
    case INTENT_OUT: return "out";
    case INTENT_INOUT: return "inout";
    case INTENT_CONST: return "const";
    case INTENT_CONST_IN: return "const in";
    case INTENT_REF: return "ref";
    case INTENT_CONST_REF: return "const ref";
    case INTENT_REF_MAYBE_CONST: return "const? ref";
    case INTENT_PARAM: return "param";
    case INTENT_TYPE: return "type";
    case INTENT_BLANK: return nullptr;
  }
  return nullptr;
}

// Print the "short name" of builtin types that can be parameterized.
static const char* builtinTypeName(Type* vt) {
  if (vt == dtInt[INT_SIZE_DEFAULT]) return "int";
  if (vt == dtUInt[INT_SIZE_DEFAULT]) return "uint";
  if (vt == dtReal[FLOAT_SIZE_DEFAULT]) return "real";
  if (vt == dtImag[FLOAT_SIZE_DEFAULT]) return "imag";
  if (vt == dtComplex[COMPLEX_SIZE_DEFAULT]) return "complex";
  if (vt == dtBool) return "bool";
  return nullptr;
}

const char* FunctionType::typeToString(Type* t) {
  // Use the value type when printing out the user type to hide '_ref'.
  auto vt = t->getValType();
  if (auto builtinName = builtinTypeName(vt)) return builtinName;
  return vt->symbol->name;
}

const char* FunctionType::returnIntentToString(RetTag intent) {
  return retTagDescrString(intent);
}

static FunctionType* cacheFunctionTypeOrReuse(FunctionType* fnType);

FunctionType* FunctionType::create(FunctionType::Kind kind,
                                   FunctionType::Width width,
                                   FunctionType::Linkage linkage,
                                   FormalVec formals,
                                   RetTag returnIntent,
                                   Type* returnType,
                                   bool throws) {
  bool isAnyFormalNamed = false;

  for (auto& formal : formals) {
    // Call 'makeRefType' if it's likely needed to avoid problems later.
    bool isRef = formal.qual() == QUAL_CONST_REF ||
                 formal.qual() == QUAL_REF ||
                 formal.intent() & INTENT_REF;
    if (isRef) makeRefType(formal.type());

    isAnyFormalNamed |= formal.name() != nullptr;
  }

  // TODO: We could delay computing this until it's actually needed.
  auto cstr = FunctionType::buildUserTypeString(kind, width,
                                                linkage,
                                                formals,
                                                returnIntent,
                                                returnType,
                                                throws);
  auto ret = new FunctionType(kind, width, linkage, std::move(formals),
                              returnIntent,
                              returnType,
                              throws,
                              isAnyFormalNamed,
                              cstr);
  return ret;
}

static FunctionType* cacheFunctionTypeOrReuse(FunctionType* fnType) {
  auto it = functionTypeCache.find(fnType);
  if (it != functionTypeCache.end()) return *it;

  auto ts = new TypeSymbol(fnType->toString(), fnType);
  ts->cname = fnType->toStringMangledForCodegen();
  fnType->symbol = ts;

  rootModule->block->insertAtTail(new DefExpr(ts));

  std::ignore = functionTypeCache.emplace_hint(it, fnType);

  return fnType;
}

FunctionType* FunctionType::get(FunctionType::Kind kind,
                                FunctionType::Width width,
                                FunctionType::Linkage linkage,
                                FormalVec formals,
                                RetTag returnIntent,
                                Type* returnType,
                                bool throws) {
  auto ft = FunctionType::create(kind, width, linkage,
                                 std::move(formals),
                                 returnIntent,
                                 returnType,
                                 throws);
  auto ret = cacheFunctionTypeOrReuse(ft);
  return ret;
}

FunctionType::Kind FunctionType::determineKind(FnSymbol* fn) {
  if (fn->hasFlag(FLAG_ITERATOR_FN)) return FunctionType::ITER;
  if (fn->hasFlag(FLAG_OPERATOR)) return FunctionType::OPERATOR;
  return FunctionType::PROC;
}

FunctionType::Linkage FunctionType::determineLinkage(FnSymbol* fn) {
  if (fn->hasFlag(FLAG_EXTERN)) return FunctionType::EXTERN;
  if (fn->hasFlag(FLAG_EXPORT)) return FunctionType::EXPORT;
  return FunctionType::DEFAULT;
}

static FormalVec collectFormals(FnSymbol* fn) {
  FormalVec ret;
  for_formals(f, fn) {
    FunctionType::Formal info = { f->qual, f->type, f->intent, f->name };
    ret.push_back(std::move(info));
  }
  return ret;
}

static FunctionType*
getFunctionTypeFromFunction(FnSymbol* fn, FunctionType::Width width) {
  FunctionType::Kind kind = FunctionType::determineKind(fn);
  FunctionType::Linkage linkage = FunctionType::determineLinkage(fn);
  auto formals = collectFormals(fn);
  RetTag returnIntent = fn->retTag;
  Type* returnType = fn->retType;

  // If error handling is lowered then this function no longer 'throws'.
  bool throws = fn->throwsError() && !fn->isErrorHandlingLowered();

  SET_LINENO(fn);
  auto ret = FunctionType::get(kind, width, linkage,
                               std::move(formals),
                               returnIntent,
                               returnType,
                               throws);
  return ret;
}

FunctionType* FunctionType::get(FnSymbol* fn) {
  return getFunctionTypeFromFunction(fn, FunctionType::WIDE);
}

FunctionType* FunctionType::getWithWidth(FunctionType::Width width) const {
  return get(kind_, width, linkage_, formals_, returnIntent_,
             returnType_,
             throws_);
}

FunctionType*
FunctionType::getWithLinkage(FunctionType::Linkage linkage) const {
  return get(kind_, width_, linkage, formals_, returnIntent_,
             returnType_,
             throws_);
}

FunctionType* FunctionType::getAsLocal() const {
  return getWithWidth(FunctionType::LOCAL);
}

FunctionType* FunctionType::getAsWide() const {
  return getWithWidth(FunctionType::WIDE);
}

FunctionType* FunctionType::getAsExtern() const {
  return getWithLinkage(FunctionType::EXTERN);
}

FunctionType::Formal FunctionType::constructErrorHandlingFormal() {
  auto t = getDecoratedClass(dtError, ClassTypeDecorator::UNMANAGED_NILABLE);
  return { QUAL_REF, t, INTENT_REF, "error_out" };
}

FunctionType* FunctionType::getWithLoweredErrorHandling() const {
  bool newThrowsFlag = false;
  auto newFormals = formals_;

  // The error formal is always inserted into the end of the formals list.
  newFormals.push_back(constructErrorHandlingFormal());

  SET_LINENO(this->symbol);

  return get(kind_, width_, linkage_, std::move(newFormals),
             returnIntent_,
             returnType_,
             newThrowsFlag);
}

FunctionType*
FunctionType::getWithMask(int64_t mask, bool& outMaskConflicts) const {
  FunctionType* ret = (FunctionType*) this;
  bool maskConflicts = false;

  if (mask & FunctionType::MASK_WIDTH_LOCAL) {
    ret = ret->getWithWidth(FunctionType::LOCAL);
  }

  if (mask & FunctionType::MASK_WIDTH_WIDE) {
    maskConflicts |= (mask & FunctionType::MASK_WIDTH_LOCAL);
    ret = ret->getWithWidth(FunctionType::WIDE);
  }

  if (mask & FunctionType::MASK_LINKAGE_EXTERN) {
    ret = ret->getWithLinkage(FunctionType::EXTERN);
  }

  if (mask & FunctionType::MASK_LINKAGE_DEFAULT) {
    maskConflicts |= (mask & FunctionType::MASK_LINKAGE_EXTERN);
    ret = ret->getWithLinkage(FunctionType::DEFAULT);
  }

  outMaskConflicts = maskConflicts;

  return ret;
}

FunctionType::Kind FunctionType::kind() const {
  return this->kind_;
}

FunctionType::Width FunctionType::width() const {
  return this->width_;
}

FunctionType::Linkage FunctionType::linkage() const {
  return this->linkage_;
}

int FunctionType::numFormals() const {
  auto ret = (int) this->formals_.size();
  return ret;
}

const FunctionType::Formal* FunctionType::formal(int idx) const {
  INT_ASSERT(0 <= idx && idx < numFormals());
  auto ret = &formals_[idx];
  return ret;
}

const FunctionType::Formal*
FunctionType::formalByOrdinal(Expr* actual, int* outIdx) const {
  if (auto call = actual ? toCallExpr(actual->parentExpr) : nullptr) {

    // This will compute the called function's type if necessary.
    auto ft = call->functionType();

    if (this == ft) {
      int idx = 0;

      for_actuals(a, call) {
        if (a == actual) {
          // Adjust index for assert since AST uses 1-based indexing...
          INT_ASSERT(1 <= (idx + 1) && (idx + 1) <= call->numActuals());
          if (outIdx) *outIdx = idx;
          return formal(idx);
        }
        idx++;
      }
    }
  }

  return nullptr;
}

RetTag FunctionType::returnIntent() const {
  return this->returnIntent_;
}

Type* FunctionType::returnType() const {
  return this->returnType_;
}

bool FunctionType::throws() const {
  return this->throws_;
}

bool FunctionType::isAnyFormalNamed() const {
  return this->isAnyFormalNamed_;
}

const char* FunctionType::toString() const {
  return this->userTypeString_;
}

const char* FunctionType::intentTagMnemonicMangled(IntentTag tag) {
  switch (tag) {
    case INTENT_IN: return "I";
    case INTENT_OUT: return "O";
    case INTENT_INOUT: return "U";
    case INTENT_CONST: return "C";
    case INTENT_CONST_IN: return "CI";
    case INTENT_REF: return "R";
    case INTENT_CONST_REF: return "CR";
    case INTENT_REF_MAYBE_CONST: return "RMC";
    case INTENT_PARAM: return "P";
    case INTENT_TYPE: return "T";
    case INTENT_BLANK: return "";
  }
  return nullptr;
}

const char* FunctionType::qualifierMnemonicMangled(Qualifier qual) {
  switch (qual) {
    case QUAL_UNKNOWN: return "qu";
    case QUAL_CONST: return "qc";
    case QUAL_REF: return "qr";
    case QUAL_CONST_REF: return "qcr";
    case QUAL_PARAM: return "qp";
    case QUAL_VAL: return "qv";
    case QUAL_NARROW_REF: return "qnr";
    case QUAL_WIDE_REF: return "qwr";
    case QUAL_CONST_VAL: return "qcv";
    case QUAL_CONST_NARROW_REF: return "qcnr";
    case QUAL_CONST_WIDE_REF: return "qcwr";
  }
  return nullptr;
}

const char* FunctionType::typeToStringMangled(Type* t) {
  INT_ASSERT(t->symbol->cname);
  return t->symbol->cname;
}

const char* FunctionType::retTagMnemonicMangled(RetTag tag) {
  switch (tag) {
    case RET_VALUE: return "";
    case RET_REF: return "R";
    case RET_CONST_REF: return "CR";
    case RET_PARAM: return "P";
    case RET_TYPE: return "T";
  }
  return nullptr;
}

const char* FunctionType::toStringMangledForCodegen() const {
  std::ostringstream oss;

  oss << "chpl_";
  oss << kindToString(kind_) << "_";
  oss << widthToString(width_) << "_";

  if (hasForeignLinkage()) oss << linkageToString(linkage_) << "_";

  for (int i = 0; i < numFormals(); i++) {
    auto f = this->formal(i);
    oss << qualifierMnemonicMangled(f->qual());
    oss << intentTagMnemonicMangled(f->intent());
    oss << typeToStringMangled(f->type()) << "_";
    if (f->name()) oss << f->name();
    oss << "_";
  }

  oss << "_";
  if (returnIntent_ != RET_VALUE) {
    oss << retTagMnemonicMangled(returnIntent_) << "_";
  }

  oss << typeToStringMangled(returnType_);
  if (throws_) oss << "_throws";

  auto ret = astr(oss.str());
  return ret;
}

size_t FunctionType::hash() const {
  std::hash<void*> hasherPtr;
  std::hash<bool> hasherBool;

  size_t ret = 0;

  ret = chpl::hash_combine(ret, ((size_t) kind_));
  ret = chpl::hash_combine(ret, ((size_t) width_));
  ret = chpl::hash_combine(ret, ((size_t) linkage_));

  // I think it's fine to hash the pointers here because types don't really
  // have a meaningful way to distinguish on contents, and should be unique,
  // while the formal names are all canonical using 'astr'.
  for (auto& formal : formals_) {
    ret = chpl::hash_combine(ret, formal.hash());
  }

  ret = chpl::hash_combine(ret, ((size_t) returnIntent_));
  ret = chpl::hash_combine(ret, hasherPtr(returnType_));
  ret = chpl::hash_combine(ret, hasherBool(throws_));
  ret = chpl::hash_combine(ret, hasherBool(isAnyFormalNamed_));

  return ret;
}

FunctionType::Formal::Formal(Qualifier qual, Type* type, IntentTag intent,
                             const char* name)
    : qual_(qual), type_(type), intent_(intent) {
  name_ = name ? astr(name) : nullptr;
}

bool
FunctionType::Formal::operator==(const FunctionType::Formal& rhs) const {
  return this->qual_ == rhs.qual_ &&
         this->type_ == rhs.type_ &&
         this->intent_ == rhs.intent_ &&
         this->name_ == rhs.name_;
}

size_t FunctionType::Formal::hash() const {
  std::hash<void*> hasherPtr;
  std::hash<const char*> hasherConstCharPtr;

  size_t ret = 0;
  ret = chpl::hash_combine(ret, ((size_t) qual_));
  ret = chpl::hash_combine(ret, hasherPtr(type_));
  ret = chpl::hash_combine(ret, ((size_t) intent_));
  ret = chpl::hash_combine(ret, hasherConstCharPtr(name_));
  return ret;
}


Qualifier FunctionType::Formal::qual() const {
  return qual_;
}

Type* FunctionType::Formal::type() const {
  return type_;
}

IntentTag FunctionType::Formal::intent() const {
  return intent_;
}

const char* FunctionType::Formal::name() const {
  return name_;
}

QualifiedType FunctionType::Formal::qualType() const {
  return QualifiedType(qual_, type_);
}

bool FunctionType::Formal::isRef() const {
  return qualType().isRef();
}

bool FunctionType::Formal::isGeneric() const {
  auto t = type_;
  return t == dtUnknown || t == dtAny || t->symbol->hasFlag(FLAG_GENERIC);
}

bool FunctionType::equals(const FunctionType* rhs) const {
  return this->kind_ == rhs->kind_ &&
         this->width_ == rhs->width_ &&
         this->linkage_ == rhs->linkage_ &&
         this->formals_ == rhs->formals_ &&
         this->returnIntent_ == rhs->returnIntent_ &&
         this->returnType_ == rhs->returnType_ &&
         this->throws_ == rhs->throws_ &&
         this->isAnyFormalNamed_ == rhs->isAnyFormalNamed_ &&
         this->userTypeString_ == rhs->userTypeString_;
}

bool FunctionType::equals(FnSymbol* fn) const {
  bool ret = this->kind_ == determineKind(fn) &&
             this->linkage_ == determineLinkage(fn) &&
             this->returnIntent_ == fn->retTag &&
             this->returnType_ == fn->retType &&
             this->throws_ == fn->throwsError() &&
             this->numFormals() == fn->numFormals() &&
             this->formals_ == collectFormals(fn);
  return ret;
}

bool FunctionType::isGeneric() const {
  auto rt = returnType();

  if (rt == dtUnknown || rt == dtAny || rt->symbol->hasFlag(FLAG_GENERIC)) {
    return true;
  }

  for (auto& formal : formals_) {
    if (formal.isGeneric()) return true;
  }

  return false;
}

bool FunctionType::isLocal() const {
  return width_ == FunctionType::LOCAL;
}

bool FunctionType::isWide() const {
  return width_ == FunctionType::WIDE;
}

bool FunctionType::isExtern() const {
  return linkage_ == FunctionType::EXTERN;
}

bool FunctionType::isExport() const {
  return linkage_ == FunctionType::EXPORT;
}

bool FunctionType::hasForeignLinkage() const {
  return linkage_ != FunctionType::DEFAULT;
}

/************************************* | **************************************
*                                                                             *
*                                                                             *
*                                                                             *
************************************** | *************************************/

TemporaryConversionType::TemporaryConversionType(chpl::types::QualifiedType qt)
  : Type(E_TemporaryConversionType, nullptr), qt(qt)
{
  this->symbol = dtUnknown->symbol;
  gTemporaryConversionTypes.add(this);
}

TemporaryConversionType::TemporaryConversionType(const chpl::types::Type* t)
  : Type(E_TemporaryConversionType, nullptr),
    qt(chpl::types::QualifiedType(chpl::types::QualifiedType::TYPE, t))
{
  this->symbol = dtUnknown->symbol;
  gTemporaryConversionTypes.add(this);
}


TemporaryConversionType*
TemporaryConversionType::copyInner(SymbolMap* map) {
  INT_FATAL(this, "unexpected call to TemporaryConversionType::copyInner");
  return nullptr;
}

void TemporaryConversionType::replaceChild(BaseAST* old_ast, BaseAST* new_ast) {
  INT_FATAL(this, "Unexpected case in TemporaryConversionType::replaceChild");
}

void TemporaryConversionType::verify() {
  Type::verify();
  if (astTag != E_TemporaryConversionType) {
    INT_FATAL(this, "Bad TemporaryConversionType::astTag");
  }
}

void TemporaryConversionType::accept(AstVisitor* visitor) {
  INT_FATAL(this, "Unexpected case in TemporaryConversionType::accept");
}


/************************************* | **************************************
*                                                                             *
*                                                                             *
*                                                                             *
************************************** | *************************************/

static PrimitiveType* createPrimitiveType(const char* name, const char* cname);
static PrimitiveType* createInternalType (const char* name, const char* cname);

static PrimitiveType* createType(const char* name,
                                 const char* cname,
                                 bool        internalType);

static VarSymbol*     createSymbol(PrimitiveType* primType, const char* name);

// Create new primitive type for integers.
// Specify name for now.
// Though it will probably be something like int1, int8, etc. in the end.
// In that case we can just specify the width (i.e., size).

#define INIT_PRIM_INT( name, width)                                             \
  dtInt[INT_SIZE_ ## width] = createPrimitiveType (name, "int" #width "_t");    \
  dtInt[INT_SIZE_ ## width]->defaultValue = new_IntSymbol( 0, INT_SIZE_ ## width)

#define INIT_PRIM_UINT( name, width)                                            \
  dtUInt[INT_SIZE_ ## width] = createPrimitiveType (name, "uint" #width "_t");  \
  dtUInt[INT_SIZE_ ## width]->defaultValue = new_UIntSymbol( 0, INT_SIZE_ ## width)

#define INIT_PRIM_REAL( name, width)                                            \
  dtReal[FLOAT_SIZE_ ## width] = createPrimitiveType (name, "_real" #width);    \
  dtReal[FLOAT_SIZE_ ## width]->defaultValue = new_RealSymbol( "0.0", FLOAT_SIZE_ ## width)

#define INIT_PRIM_IMAG( name, width)                                            \
  dtImag[FLOAT_SIZE_ ## width] = createPrimitiveType (name, "_imag" #width);    \
  dtImag[FLOAT_SIZE_ ## width]->defaultValue = new_ImagSymbol( "0.0", FLOAT_SIZE_ ## width)

#define INIT_PRIM_COMPLEX( name, width)                                                   \
  dtComplex[COMPLEX_SIZE_ ## width]= createPrimitiveType (name, "_complex" #width);       \
  dtComplex[COMPLEX_SIZE_ ## width]->defaultValue = new_ComplexSymbol(                    \
                                  "_chpl_complex" #width "(0.0, 0.0)",                    \
                                   0.0, 0.0, COMPLEX_SIZE_ ## width);                     \
  dtComplex[COMPLEX_SIZE_ ## width]->GEPMap.insert(std::pair<std::string, int>("re", 0)); \
  dtComplex[COMPLEX_SIZE_ ## width]->GEPMap.insert(std::pair<std::string, int>("im", 1));

#define CREATE_DEFAULT_SYMBOL(primType, gSym, name)     \
  gSym = new VarSymbol (name, primType);                \
  gSym->addFlag(FLAG_CONST);                            \
  gSym->addFlag(FLAG_GLOBAL_VAR_BUILTIN);               \
  rootModule->block->insertAtTail(new DefExpr(gSym));   \
  primType->defaultValue = gSym


// This should probably be renamed since it creates primitive types, as
//  well as internal types and other types used in the generated code
void initPrimitiveTypes() {
  dtVoid                               = createInternalType("void", "void");
  dtVoid->symbol->addFlag(FLAG_NO_RENAME);
  dtVoid->symbol->addFlag(FLAG_NO_CODEGEN);
  dtNothing                            = createInternalType ("nothing",  "nothing");
  dtNothing->symbol->addFlag(FLAG_NO_CODEGEN);

  dtInt[INT_SIZE_64]                   = createPrimitiveType("int",      "int64_t");
  dtReal[FLOAT_SIZE_64]                = createPrimitiveType("real",     "_real64");

  // The Chapel name is prefixed with 'chpl_' to make it internal, but the
  // C type is 'c_string' which is defined in the runtime as an alias for
  // 'const char*'. The user-facing alias is defined in 'ChapelBase' so that
  // it can easily be deprecated.
  // Note that we actually map to the type 'c_string_rehook' to avoid a
  // collision with the type alias when '--no-munge-user-idents' is thrown.
  // TODO: a better solution than renaming c_string to avoid the collision would be preferred
  dtStringC                            = createPrimitiveType("chpl_c_string", "c_string_rehook");
  dtStringC->symbol->addFlag(FLAG_NO_CODEGEN);

  dtBool                               = createPrimitiveType("bool", "chpl_bool");

  gFalse                               = createSymbol(dtBool, "false");
  gTrue                                = createSymbol(dtBool, "true");

  gFalse->immediate                    = new Immediate;
  gFalse->immediate->v_bool            = false;
  gFalse->immediate->const_kind        = NUM_KIND_BOOL;
  gFalse->immediate->num_index         = BOOL_SIZE_SYS;

  gTrue->immediate                     = new Immediate;
  gTrue->immediate->v_bool             = true;
  gTrue->immediate->const_kind         = NUM_KIND_BOOL;
  gTrue->immediate->num_index          = BOOL_SIZE_SYS;

  dtBool->defaultValue = gFalse;
  dtInt[INT_SIZE_64]->defaultValue     = new_IntSymbol(0, INT_SIZE_64);
  dtReal[FLOAT_SIZE_64]->defaultValue  = new_RealSymbol("0.0", FLOAT_SIZE_64);

  uniqueConstantsHash.put(gFalse->immediate, gFalse);
  uniqueConstantsHash.put(gTrue->immediate,  gTrue);

  dtNil = createInternalType ("_nilType", "_nilType");
  dtNil->symbol->addFlag(FLAG_NO_RENAME);
  CREATE_DEFAULT_SYMBOL (dtNil, gNil, "nil");
  gNil->addFlag(FLAG_NO_RENAME);

  // dtStringC defaults to nil
  dtStringC->defaultValue = gNil;

  // This type should not be visible past normalize.
  CREATE_DEFAULT_SYMBOL (dtVoid, gNoInit, "_gnoinit");

  dtSplitInitType = createInternalType("_splitInitType", "_splitInitType");
  CREATE_DEFAULT_SYMBOL (dtSplitInitType, gSplitInit, "_gsplitinit");

  dtUnknown = createInternalType ("_unknown", "_unknown");
  CREATE_DEFAULT_SYMBOL (dtUnknown, gUnknown, "_gunknown");
  gUnknown->addFlag(FLAG_TYPE_VARIABLE);

  CREATE_DEFAULT_SYMBOL (dtVoid, gVoid, "_void");
  CREATE_DEFAULT_SYMBOL (dtNothing, gNone, "none");

  // parses from record
  dtAnyRecord = createInternalType("record", "_anyRecord");
  dtAnyRecord->symbol->addFlag(FLAG_GENERIC);

  gCpuVsGpuToken = createSymbol(dtBool, "chpl_cpuVsGpuToken");
  gCpuVsGpuToken->addFlag(FLAG_NO_CODEGEN);

  gIteratorBreakToken = createSymbol(dtBool, "_iteratorBreakToken");
  gIteratorBreakToken->addFlag(FLAG_NO_CODEGEN);

  INIT_PRIM_INT( "int(8)", 8);
  INIT_PRIM_INT( "int(16)", 16);
  INIT_PRIM_INT( "int(32)", 32);

  INIT_PRIM_UINT( "uint(8)", 8);
  INIT_PRIM_UINT( "uint(16)", 16);
  INIT_PRIM_UINT( "uint(32)", 32);
  INIT_PRIM_UINT( "uint", 64);          // default size

  INIT_PRIM_REAL( "real(32)", 32);

  INIT_PRIM_IMAG( "imag(32)", 32);
  INIT_PRIM_IMAG( "imag", 64);            // default size

  INIT_PRIM_COMPLEX( "complex(64)", 64);
  INIT_PRIM_COMPLEX( "complex", 128);       // default size

  // Set up INFINITY and NAN params
  gInfinity = createSymbol(dtReal[FLOAT_SIZE_DEFAULT], "chpl_INFINITY");
  gInfinity->immediate = new Immediate;
  gInfinity->immediate->v_float64 = INFINITY;
  gInfinity->immediate->const_kind = NUM_KIND_REAL;
  gInfinity->immediate->num_index = FLOAT_SIZE_DEFAULT;

  gNan = createSymbol(dtReal[FLOAT_SIZE_DEFAULT], "chpl_NAN");
  gNan->immediate = new Immediate;
  gNan->immediate->v_float64 = NAN;
  gNan->immediate->const_kind = NUM_KIND_REAL;
  gNan->immediate->num_index = FLOAT_SIZE_DEFAULT;

  // Could be == c_ptr(int(8)) e.g.
  // used in some runtime interfaces
  dtCVoidPtr   = createPrimitiveType("chpl__c_void_ptr", "raw_c_void_ptr" );
  dtCVoidPtr->symbol->addFlag(FLAG_NO_CODEGEN);
  dtCVoidPtr->defaultValue = gNil;

  // Map to runtime type 'c_fn_ptr_rehook' to avoid collision with name of
  // symbol in module ('c_fn_ptr'), when using '--no-munge-user-idents' is
  // thrown.
  dtCFnPtr = createPrimitiveType("chpl_c_fn_ptr", "c_fn_ptr_rehook");
  dtCFnPtr->symbol->addFlag(FLAG_NO_CODEGEN);
  dtCFnPtr->defaultValue = gNil;

  dtOpaque = createPrimitiveType("opaque", "chpl_opaque");

  CREATE_DEFAULT_SYMBOL(dtOpaque, gOpaque, "_nullOpaque");
  gOpaque->cname = astr("NULL");
  gOpaque->addFlag(FLAG_EXTERN);

  dtTaskID = createPrimitiveType("chpl_taskID_t", "chpl_taskID_t");
  dtTaskID->symbol->addFlag(FLAG_NO_CODEGEN);

  CREATE_DEFAULT_SYMBOL(dtTaskID, gTaskID, "chpl_nullTaskID");

  dtSyncVarAuxFields = createPrimitiveType( "_sync_aux_t", "chpl_sync_aux_t");

  CREATE_DEFAULT_SYMBOL (dtSyncVarAuxFields, gSyncVarAuxFields, "_nullSyncVarAuxFields");
  gSyncVarAuxFields->cname = astr("NULL");

  dtAny = createInternalType ("_any", "_any");
  dtAny->symbol->addFlag(FLAG_GENERIC);

  dtAnyComplex = createInternalType("chpl_anycomplex", "complex");
  dtAnyComplex->symbol->addFlag(FLAG_GENERIC);

  // parses from enum
  dtAnyEnumerated = createInternalType ("enum", "enum");
  dtAnyEnumerated->symbol->addFlag(FLAG_GENERIC);

  dtAnyImag = createInternalType("chpl_anyimag", "imag");
  dtAnyImag->symbol->addFlag(FLAG_GENERIC);

  dtAnyReal = createInternalType("chpl_anyreal", "real");
  dtAnyReal->symbol->addFlag(FLAG_GENERIC);

  dtAnyPOD = createInternalType ("chpl_anyPOD", "POD");
  dtAnyPOD->symbol->addFlag(FLAG_GENERIC);

  // could also be called dtAnyIntegral
  dtIntegral = createInternalType ("integral", "integral");
  dtIntegral->symbol->addFlag(FLAG_GENERIC);

  dtNumeric = createInternalType ("numeric", "numeric");
  dtNumeric->symbol->addFlag(FLAG_GENERIC);

  dtIteratorRecord = createInternalType("_iteratorRecord", "_iteratorRecord");
  dtIteratorRecord->symbol->addFlag(FLAG_GENERIC);

  dtIteratorClass = createInternalType("_iteratorClass", "_iteratorClass");
  dtIteratorClass->symbol->addFlag(FLAG_GENERIC);

  dtThunkRecord = createInternalType("_thunkRecord", "_thunkRecord");
  dtThunkRecord->symbol->addFlag(FLAG_GENERIC);

  dtBorrowed = createInternalType("borrowed", "borrowed");
  dtBorrowed->symbol->addFlag(FLAG_GENERIC);

  dtBorrowedNonNilable = createInternalType("_borrowedNonNilable", "_borrowedNonNilable");
  dtBorrowedNonNilable->symbol->addFlag(FLAG_GENERIC);

  dtBorrowedNilable = createInternalType("_borrowedNilable", "_borrowedNilable");
  dtBorrowedNilable->symbol->addFlag(FLAG_GENERIC);

  dtUnmanaged = createInternalType("unmanaged", "unmanaged");
  dtUnmanaged->symbol->addFlag(FLAG_GENERIC);

  dtUnmanagedNonNilable = createInternalType("_unmanagedNonNilable", "_unmanagedNonNilable");
  dtUnmanagedNonNilable->symbol->addFlag(FLAG_GENERIC);

  dtUnmanagedNilable = createInternalType("_unmanagedNilable", "_unmanagedNilable");
  dtUnmanagedNilable->symbol->addFlag(FLAG_GENERIC);

  dtAnyManagementAnyNilable = createInternalType("_anyManagementAnyNilable", "_anyManagementAnyNilable");
  dtAnyManagementAnyNilable->symbol->addFlag(FLAG_GENERIC);

  // parses from class
  dtAnyManagementNonNilable = createInternalType("class", "_anyManagementNonNilable");
  dtAnyManagementNonNilable->symbol->addFlag(FLAG_GENERIC);

  dtAnyManagementNilable = createInternalType("_anyManagementNilable", "_anyManagementNilable");
  dtAnyManagementNilable->symbol->addFlag(FLAG_GENERIC);


  dtMethodToken = createInternalType ("_MT", "_MT");
  CREATE_DEFAULT_SYMBOL(dtMethodToken, gMethodToken, "_mt");

  dtDummyRef = createInternalType ("_DummyRef", "_DummyRef");
  CREATE_DEFAULT_SYMBOL(dtDummyRef, gDummyRef, "_dummyRef");
  CREATE_DEFAULT_SYMBOL(dtVoid, gDummyWitness, "_dummyWitness");
  CREATE_DEFAULT_SYMBOL(dtVoid, gFixupRequiredToken, "_fixupRequired");

  dtTypeDefaultToken = createInternalType("_TypeDefaultT", "_TypeDefaultT");
  CREATE_DEFAULT_SYMBOL(dtTypeDefaultToken, gTypeDefaultToken, "_typeDefaultT");

  dtModuleToken = createInternalType("tmodule=", "tmodule=");
  CREATE_DEFAULT_SYMBOL(dtModuleToken, gModuleToken, "module=");

  dtUninstantiated = createInternalType("_uninstantiated", "_uninstantiated");

  CREATE_DEFAULT_SYMBOL(dtUninstantiated, gUninstantiated, "?");
  gUninstantiated->addFlag(FLAG_PARAM);

  CREATE_DEFAULT_SYMBOL(dtVoid, gIgnoredPromotionToken, "_ignoredPromotionToken");

  // set up the well-known types, including setting up dummy types
  // for dtString / _string and a few others
  initializeWellKnown();
}

static PrimitiveType* createPrimitiveType(const char* name, const char* cname) {
  PrimitiveType* newType = createType(name, cname, false);
  newType->symbol->addFlag(FLAG_NO_RENAME);
  return newType;
}

static PrimitiveType* createInternalType(const char* name, const char* cname) {
  return createType(name, cname,  true);
}

static PrimitiveType*
createType(const char* name, const char* cname, bool internalType) {
  PrimitiveType* pt = new PrimitiveType(NULL, internalType);
  TypeSymbol*    ts = new TypeSymbol(name, pt);

  ts->cname = astr(cname);

  // This prevents cleanAST() from sweeping these
  ts->addFlag(FLAG_GLOBAL_TYPE_SYMBOL);

  rootModule->block->insertAtTail(new DefExpr(ts));

  return pt;
}

static VarSymbol* createSymbol(PrimitiveType* primType, const char* name) {
  VarSymbol* retval = new VarSymbol(name, primType);

  retval->addFlag(FLAG_CONST);
  retval->addFlag(FLAG_GLOBAL_VAR_BUILTIN);

  rootModule->block->insertAtTail(new DefExpr(retval));

  return retval;
}

/************************************* | **************************************
*                                                                             *
*                                                                             *
*                                                                             *
************************************** | *************************************/

void initChplProgram() {
  theProgram           = new ModuleSymbol("chpl__Program",
                                          MOD_INTERNAL,
                                          new BlockStmt());

  theProgram->filename = astr("<internal>");

  theProgram->addFlag(FLAG_NO_CODEGEN);

  rootModule->block->insertAtTail(new DefExpr(theProgram));
}

// Appends a VarSymbol to the root module and gives it the bool immediate
// matching 'value'. For use in initCompilerGlobals.

template <typename T>
VarSymbol* createCompilerGlobalParam(const char* name, T value);

template <>
VarSymbol* createCompilerGlobalParam<bool>(const char* name, bool value) {
  auto globalVar = new VarSymbol(name, dtBool);
  rootModule->block->insertAtTail(new DefExpr(globalVar));
  globalVar->immediate = new Immediate;
 *globalVar->immediate = *(value ? gTrue : gFalse)->immediate;

  return globalVar;
}

void initCompilerGlobals() {
  auto& compilerGlobals = chpl::compilerGlobals(gContext);
  #define COMPILER_GLOBAL(TYPE__, NAME__, FIELD__) \
    gCompilerGlobalParams.push_back(createCompilerGlobalParam<TYPE__>(NAME__, compilerGlobals.FIELD__));
  #include "chpl/uast/compiler-globals-list.h"
  #undef COMPILER_GLOBAL

  // defined and maintained by the runtime
  gNodeID = new VarSymbol("chpl_nodeID", dtInt[INT_SIZE_32]);
  gNodeID->addFlag(FLAG_EXTERN);
  rootModule->block->insertAtTail(new DefExpr(gNodeID));

  if (! usingGpuLocaleModel()) {
    // gCpuVsGpuToken is param true for non-gpu compiles
    gCpuVsGpuToken->immediate = new Immediate;
   *gCpuVsGpuToken->immediate = *gTrue->immediate;
  }

  initForTaskIntents();
}

bool is_nothing_type(Type* t) {
  return t == dtNothing;
}

bool is_bool_type(Type* t) {
  return t == dtBool;
}


bool is_int_type(Type *t) {
  return
    t == dtInt[INT_SIZE_32] ||
    t == dtInt[INT_SIZE_8] ||
    t == dtInt[INT_SIZE_16] ||
    t == dtInt[INT_SIZE_64];
}


bool is_uint_type(Type *t) {
  return
    t == dtUInt[INT_SIZE_32] ||
    t == dtUInt[INT_SIZE_8] ||
    t == dtUInt[INT_SIZE_16] ||
    t == dtUInt[INT_SIZE_64];
}

bool is_signed(Type *t) {
  if( is_int_type(t) ||
      is_real_type(t) ||
      is_imag_type(t) ||
      is_complex_type(t) ) return true;
  if( is_uint_type(t) ) return false;
  if( is_enum_type(t) ) {
    return is_signed(toEnumType(t)->getIntegerType());
  }
  return false;
}

bool is_real_type(Type *t) {
  return
    t == dtReal[FLOAT_SIZE_64] ||
    t == dtReal[FLOAT_SIZE_32];
}


bool is_imag_type(Type *t) {
  return
    t == dtImag[FLOAT_SIZE_64] ||
    t == dtImag[FLOAT_SIZE_32];
}


bool is_complex_type(Type *t) {
  return
    t == dtComplex[COMPLEX_SIZE_128] ||
    t == dtComplex[COMPLEX_SIZE_64];
}


bool is_enum_type(Type *t) {
  return toEnumType(t);
}


bool isLegalParamType(Type* t) {
  return (is_bool_type(t) ||
          is_int_type(t) ||
          is_uint_type(t) ||
          is_real_type(t) ||
          is_imag_type(t) ||
          is_complex_type(t) ||
          is_enum_type(t) ||
          isString(t) ||
          isBytes(t) ||
          t == dtStringC ||
          t == dtUnknown);
}

int get_width(Type *t) {
  if (t == dtInt[INT_SIZE_8] ||
      t == dtUInt[INT_SIZE_8])
    return 8;
  if (t == dtInt[INT_SIZE_16] ||
      t == dtUInt[INT_SIZE_16])
    return 16;
  if (t == dtInt[INT_SIZE_32] ||
      t == dtUInt[INT_SIZE_32] ||
      t == dtReal[FLOAT_SIZE_32] ||
      t == dtImag[FLOAT_SIZE_32])
    return 32;
  if (t == dtInt[INT_SIZE_64] ||
      t == dtUInt[INT_SIZE_64] ||
      t == dtReal[FLOAT_SIZE_64] ||
      t == dtImag[FLOAT_SIZE_64] ||
      t == dtComplex[COMPLEX_SIZE_64])
    return 64;
  if (t == dtComplex[COMPLEX_SIZE_128])
    return 128;
  INT_FATAL(t, "Unknown bit width");
  return 0;
}

int get_component_width(Type *t) {
  if (is_complex_type(t)) {
    return get_width(t) / 2;
  }
  return get_width(t);
}

// numbers between -2**width .. 2**width
// will fit exactly in a floating-point representation.
int get_mantissa_width(Type *t) {
  // FLOAT_SIZE_16 would have 11 bits of precision
  if (t == dtReal[FLOAT_SIZE_32] ||
      t == dtImag[FLOAT_SIZE_32] ||
      t == dtComplex[COMPLEX_SIZE_64])
    // mantissa for 32-bit float
    return 24;
  if (t == dtReal[FLOAT_SIZE_64] ||
      t == dtImag[FLOAT_SIZE_64] ||
      t == dtComplex[COMPLEX_SIZE_128])
    // mantissa for 64-bit float
    return 53;
  INT_FATAL(t, "Unknown mantissa width");
  return 0;
}

int get_exponent_width(Type *t) {
  // FLOAT_SIZE_16 would have 5 bits of exponent
  if (t == dtReal[FLOAT_SIZE_32] ||
      t == dtImag[FLOAT_SIZE_32] ||
      t == dtComplex[COMPLEX_SIZE_64])
    // exponent bits for 32-bit float
    return 8;
  if (t == dtReal[FLOAT_SIZE_64] ||
      t == dtImag[FLOAT_SIZE_64] ||
      t == dtComplex[COMPLEX_SIZE_128])
    // exponent bits for 64-bit float
    return 15;
  INT_FATAL(t, "Unknown exponent width");
  return 0;
}

bool isClass(Type* t) {
  if (AggregateType* ct = toAggregateType(t))
    return ct->isClass();
  return false;
}

bool isHeapAllocatedType(Type* t) {
  if (AggregateType* ct = toAggregateType(t)) {
    TypeSymbol* ts = ct->symbol;
    if (ts->hasEitherFlag(FLAG_REF,FLAG_WIDE_REF))
      return false;
    if (ts->hasFlag(FLAG_C_ARRAY))
      return false;

    return (ts->hasFlag(FLAG_DATA_CLASS) ||
            ts->hasFlag(FLAG_WIDE_CLASS) ||
            ct->isClass());
  }
  return false;
}

bool isClassOrNil(Type* t) {
  if (t == dtNil) return true;
  return isClass(t);
}

bool isUnmanagedClass(Type* t) {
  if (DecoratedClassType* dt = toDecoratedClassType(t))
    if (dt->isUnmanaged())
      return true;
  return false;
}

bool isBorrowedClass(Type* t) {
  if (isClass(t))
    return true; // borrowed, non-nilable

  if (DecoratedClassType* dt = toDecoratedClassType(t))
    return dt->isBorrowed();

  return false;
}

// Todo: ideally this would be simply something like:
//   isChapelManagedType(t) || isChapelBorrowedType(t)
bool isOwnedOrSharedOrBorrowed(Type* t) {
  if (isClass(t))
    return true; // borrowed, non-nilable

  if (DecoratedClassType* dt = toDecoratedClassType(t))
    if (! dt->isUnmanaged())
      return true; // anything not unmanaged

  if (isManagedPtrType(t))
    return true; // owned or shared

  return false;
}

bool isBuiltinGenericClassType(Type* t) {
  return t == dtBorrowed ||
         t == dtBorrowedNonNilable ||
         t == dtBorrowedNilable ||
         t == dtUnmanaged ||
         t == dtUnmanagedNilable ||
         t == dtUnmanagedNonNilable ||
         t == dtAnyManagementAnyNilable ||
         t == dtAnyManagementNonNilable ||
         t == dtAnyManagementNilable;
}

bool isBuiltinGenericType(Type* t) {
  // ignore any decorator; irrelevant for knowing if it's builtin+generic
  if (DecoratedClassType* dct = toDecoratedClassType(t))
    if (AggregateType* at = dct->getCanonicalClass())
      t = at;

  return isBuiltinGenericClassType(t) ||
         t == dtAnyComplex || t == dtAnyImag || t == dtAnyReal ||
         t == dtAnyEnumerated ||
         t == dtNumeric || t == dtIntegral ||
         t == dtIteratorRecord || t == dtIteratorClass ||
         t == dtThunkRecord ||
         t == dtAnyPOD ||
         t == dtOwned || t == dtShared ||
         t == dtAnyRecord || t == dtTuple ||
         t->symbol->hasFlag(FLAG_SYNC);  // _syncvar
}

bool isClassLike(Type* t) {
  return isDecoratedClassType(t) ||
         isBuiltinGenericClassType(t) ||
         (isClass(t) && !(t->symbol->hasFlag(FLAG_C_PTR_CLASS) ||
                          t->symbol->hasFlag(FLAG_DATA_CLASS) ||
                          t->symbol->hasFlag(FLAG_REF)));
}

bool isClassLikeOrManaged(Type* t) {
  return isClassLike(t) || isManagedPtrType(t);
}

bool isClassLikeOrPtr(Type* t) {
  return isClassLike(t) || (t->symbol->hasFlag(FLAG_C_PTR_CLASS) ||
                            t->symbol->hasFlag(FLAG_DATA_CLASS) ||
                            t == dtCVoidPtr ||
                            t == dtStringC ||
                            t == dtCFnPtr) ||
         (isFunctionType(t) && fcfs::usePointerImplementation());
}

bool isCPtrConstChar(Type* t) {
  if (t->symbol->hasFlag(FLAG_C_PTRCONST_CLASS)) {
    if (auto dct = getDataClassType(t->symbol)) {
      return dct->typeInfo() == dt_c_char;
    }
  }
  return false;
}

bool isCVoidPtr(Type* t) {
  return (t->symbol->hasFlag(FLAG_C_PTR_CLASS) &&
          getDataClassType(t->symbol)->typeInfo() == dtVoid) ||
         t == dtCVoidPtr;
}

bool isClassLikeOrNil(Type* t) {
  if (t == dtNil) return true;
  return isClassLike(t);
}

bool isRecord(Type* t) {
  if (AggregateType* ct = toAggregateType(t))
    return ct->isRecord();
  return false;
}

bool isUserRecord(Type* t) {
  if (!isRecord(t))
    return false;

  // Check for lots of exceptions - types that are implemented
  // as records but that isn't the user view.
  if (t == dtString ||
      t == dtBytes ||
      t->symbol->hasFlag(FLAG_SYNTACTIC_DISTRIBUTION) ||
      t->symbol->hasFlag(FLAG_DISTRIBUTION) ||
      t->symbol->hasFlag(FLAG_DOMAIN) ||
      t->symbol->hasFlag(FLAG_ARRAY) ||
      t->symbol->hasFlag(FLAG_RANGE) ||
      t->symbol->hasFlag(FLAG_TUPLE) ||
      t->symbol->hasFlag(FLAG_SYNC) ||
      t->symbol->hasFlag(FLAG_ATOMIC_TYPE) ||
      t->symbol->hasFlag(FLAG_MANAGED_POINTER))
    return false;

  return true;
}

bool isUnion(Type* t) {
  if (AggregateType* ct = toAggregateType(t))
    return ct->isUnion();
  return false;
}

bool isReferenceType(const Type* t) {
  return t->symbol->hasFlag(FLAG_REF);
}

bool isRefCountedType(Type* t) {
  // We may eventually want to add a separate flag and provide users
  //  with an interface to declare reference counted types that will
  //  be "automatically" reference counted when needed

  // The set of reference counted types currently coincides with the set
  // of record-wrapped types, so we can reuse the flag set.
  return getRecordWrappedFlags(t->symbol).any();
}

bool isRecordWrappedType(const Type* t) {
  return getRecordWrappedFlags(t->symbol).any();
}

// Returns true if the given type is one which can be returned by one of the
// dsiNew*Dom() functions; false otherwise.
// This check is performed by looking to see if the given type derives from the
// BaseDom class.
bool isDomImplType(Type* type)
{
  return isDerivedType(type, FLAG_BASE_DOMAIN);
}

// Returns true if the given type is one which can be returned by
// dsiBuildArray() or similar function returning a "nude" array implementation;
// false otherwise.
// The test is actually performed by looking to see if the given type derives
// from the BaseArr class.
bool isArrayImplType(Type* type)
{
  return isDerivedType(type, FLAG_BASE_ARRAY);
}

bool isDistImplType(Type* type)
{
  return isDerivedType(type, FLAG_BASE_DIST);
}

bool isAliasingArrayImplType(Type* t) {
  return t->symbol->hasFlag(FLAG_ALIASING_ARRAY);
}

bool isAliasingArrayType(Type* t) {
  if (t->symbol->hasFlag(FLAG_ARRAY)) {
    AggregateType* at = toAggregateType(t);
    INT_ASSERT(at);

    Symbol* instanceField = at->getField("_instance", false);
    if (instanceField) {
      return isAliasingArrayImplType(instanceField->type);
    }
  }

  return false;
}

static bool isDerivedType(Type* type, Flag flag)
{
  AggregateType* at     =  NULL;
  bool           retval = false;

  while ((at = toAggregateType(type)) != NULL && retval == false)
  {
    if (at->symbol->hasFlag(flag) == true)
      retval = true;
    else
      type   = at->dispatchParents.only();
  }

  return retval;
}

bool isManagedPtrType(const Type* t) {
  if (const DecoratedClassType* dt = toConstDecoratedClassType(t))
    t = dt->getCanonicalClass();

  return t && t->symbol->hasFlag(FLAG_MANAGED_POINTER);
}

Type* getManagedPtrBorrowType(const Type* managedPtrType) {
  INT_ASSERT(isManagedPtrType(managedPtrType));

  if (const DecoratedClassType* dt = toConstDecoratedClassType(managedPtrType))
    managedPtrType = dt->getCanonicalClass();

  const AggregateType* at = toConstAggregateType(managedPtrType);

  INT_ASSERT(at);

  const char* fieldName = astr("chpl_t");
  Type* borrowType = NULL;
  Symbol* field = at->getField(fieldName, /*fatal*/ false);
  if (field) {
    borrowType = field->type;
  } else {
    Symbol* sub = at->getSubstitution(fieldName);
    borrowType = sub->type;
  }
  if (borrowType == NULL)
    INT_FATAL("Could not determine borrow type");

  ClassTypeDecoratorEnum decorator = ClassTypeDecorator::BORROWED_NONNIL;

  if (isNilableClassType(borrowType))
    decorator = ClassTypeDecorator::BORROWED_NILABLE;

  borrowType = canonicalDecoratedClassType(borrowType);

  if (AggregateType* at = toAggregateType(borrowType))
    if (isClass(at))
      borrowType = at->getDecoratedClass(decorator);

  return borrowType;
}

AggregateType* getManagedPtrManagerType(Type* managedPtrType) {
  INT_ASSERT(isManagedPtrType(managedPtrType));

  if (DecoratedClassType* dt = toDecoratedClassType(managedPtrType))
    managedPtrType = dt->getCanonicalClass();

  AggregateType* at = toAggregateType(managedPtrType);
  at = at->getRootInstantiation();

  return at;
}

bool isSyncType(const Type* t) {
  return t->symbol->hasFlag(FLAG_SYNC);
}

bool isAtomicType(const Type* t) {
  return t->symbol->hasFlag(FLAG_ATOMIC_TYPE);
}

static bool isOrContains(Type *type, Flag flag, bool checkRefs = true) {
  if (type == nullptr) {
    return false;
  } else if (!checkRefs && type->isRef()) {
    return false;
  } else if (type->symbol->hasFlag(flag)) {
    return true;
  } else {
    Type* vt = type->getValType();
    if (isDecoratedClassType(vt)) {
      vt = canonicalClassType(vt)->getValType();
    }
    if (AggregateType* at = toAggregateType(vt)) {
      // get backing array instance and recurse
      if (at->symbol->hasFlag(FLAG_ARRAY)) {
        Type* eltType = at->finalArrayElementType();
        if (isOrContains(eltType, flag, checkRefs)) return true;
      } else if (at->symbol->hasFlag(FLAG_TUPLE)) {
        // if its a tuple, search the tuple type substitutions
        for (const auto& ns: at->substitutionsPostResolve) {
          Type* eltType = ns.value->type;
          if (isOrContains(eltType, flag, checkRefs)) return true;
        }
      }
    }
  }
  return false;
}
bool isOrContainsSyncType(Type* t, bool checkRefs) {
  return isOrContains(t, FLAG_SYNC, checkRefs);
}
bool isOrContainsAtomicType(Type* t, bool checkRefs) {
  return isOrContains(t, FLAG_ATOMIC_TYPE, checkRefs);
}


bool isRefIterType(Type* t) {
  Symbol* iteratorRecord = NULL;

  if (t->symbol->hasFlag(FLAG_ITERATOR_CLASS)) {
    AggregateType* at = toAggregateType(t);
    FnSymbol* getIterator = at->iteratorInfo->getIterator;
    iteratorRecord = getIterator->getFormal(1)->type->symbol;
  } else if (t->symbol->hasFlag(FLAG_ITERATOR_RECORD))
    iteratorRecord = t->symbol;

  if (iteratorRecord)
    return iteratorRecord->hasFlag(FLAG_REF_ITERATOR_CLASS);
  return false;
}

bool isSubClass(Type* type, Type* baseType) {
  bool retval = false;

  if (type == baseType) {
    retval = true;

  } else if (AggregateType* at = toAggregateType(type)) {
    forv_Vec(AggregateType, pt, at->dispatchParents) {
      if (isSubClass(pt, baseType) == true) {
        retval = true;
        break;
      }
    }
  }

  return retval;
}

bool isDistClass(Type* type) {
  bool retval = false;

  if (type->symbol->hasFlag(FLAG_BASE_DIST) == true) {
    retval = true;

  } else if (AggregateType* at = toAggregateType(type)) {
    forv_Vec(AggregateType, pt, at->dispatchParents) {
      if (isDistClass(pt) == true) {
        retval = true;
        break;
      }
    }
  }

  return retval;
}

bool isDomainClass(Type* type) {
  bool retval = false;

  if (type->symbol->hasFlag(FLAG_BASE_DOMAIN) == true) {
    retval = true;

  } else if (AggregateType* at = toAggregateType(type)) {
    forv_Vec(AggregateType, pt, at->dispatchParents) {
      if (isDomainClass(pt) == true) {
        retval = true;
        break;
      }
    }
  }

  return retval;
}

bool isArrayClass(Type* type) {
  bool retval = false;

  if (type->symbol->hasFlag(FLAG_BASE_ARRAY) == true) {
    retval = true;

  } else if (AggregateType* at = toAggregateType(type)) {
    forv_Vec(AggregateType, t, at->dispatchParents) {
      if (isArrayClass(t) == true) {
        retval = true;
        break;
      }
    }
  }

  return retval;
}

bool isString(Type* type) {
  return type == dtString;
}

bool isBytes(Type* type) {
  return type == dtBytes;
}

// Indicates record-like memory management
bool typeNeedsCopyInitDeinit(Type* type) {
  bool retval = false;

  if (AggregateType* aggr = toAggregateType(type)) {
    Symbol*     sym  = aggr->symbol;

    // Must be a record or union type
    if (aggr->aggregateTag != AGGREGATE_RECORD &&
        aggr->aggregateTag != AGGREGATE_UNION) {
      retval = false;

    // Not a RUNTIME_type or an extern type
    } else if (sym->hasFlag(FLAG_RUNTIME_TYPE_VALUE) ||
               sym->hasFlag(FLAG_EXTERN)) {
      retval = false;

    } else {
      retval = true;
    }
  } else if (isConstrainedType(type)) {
    retval = true;
  }

  return retval;
}

// Do variables of the type 't' need capture for tasks?
bool needsCapture(Type* t) {
  INT_ASSERT(!isReferenceType(t)); // responsibility of the caller

  if (is_bool_type(t) ||
      is_int_type(t) ||
      is_uint_type(t) ||
      is_real_type(t) ||
      is_imag_type(t) ||
      is_complex_type(t) ||
      is_enum_type(t) ||
      t == dtStringC ||
      isClassLikeOrPtr(t) ||
      isRecord(t) ||
      isUnion(t) ||
      t == dtTaskID || // false?
      // TODO: Move these down to the "no" section.
      t == dtNil ||
      t == dtOpaque ||
      t->symbol->hasFlag(FLAG_EXTERN)) {
    return true;
  } else {
    // Ensure we have covered all types.
    INT_ASSERT(isRecordWrappedType(t) ||
               isSyncType(t)          ||
               isAtomicType(t));
    return false;
  }
}

VarSymbol* resizeImmediate(VarSymbol* s, PrimitiveType* t)
{
  for( int i = 0; i < INT_SIZE_NUM; i++ ) {
    if( t == dtInt[i] ) {
      return new_IntSymbol(s->immediate->to_int(), (IF1_int_type) i);
    }
  }
  for( int i = 0; i < INT_SIZE_NUM; i++ ) {
    if( t == dtUInt[i] ) {
      return new_UIntSymbol(s->immediate->to_uint(), (IF1_int_type) i);
    }
  }
  return NULL;
}


/* After resolution, other passes can call isPOD
   in order to find out if a record type is POD.

   During resolution, one should call propagateNotPOD
   instead, so that the relevant calls can be resolved
   and POD fields can be properly handled.
 */
bool isPOD(Type* t)
{
  // things that aren't aggregate types are POD
  //   e.g. int, boolean, complex, etc
  if (!isAggregateType(t))
    return true;

  // sync/single and atomic types are not POD
  // but they should be marked with FLAG_NOT_POD
  // by propagateNotPOD in function resolution.

  // handle anything already marked
  if (t->symbol->hasFlag(FLAG_POD))
    return true;
  if (t->symbol->hasFlag(FLAG_NOT_POD))
    return false;

  // if we have not calculated POD-ness,
  // we should not be calling this function
  INT_ASSERT(false);
  return false;
}

/************************************* | **************************************
*                                                                             *
*                                                                             *
*                                                                             *
************************************** | *************************************/

bool isPrimitiveScalar(Type* type) {
  bool retval = false;

  if (type == dtBool                       ||

      type == dtInt[INT_SIZE_8]            ||
      type == dtInt[INT_SIZE_16]           ||
      type == dtInt[INT_SIZE_32]           ||
      type == dtInt[INT_SIZE_64]           ||

      type == dtUInt[INT_SIZE_8]           ||
      type == dtUInt[INT_SIZE_16]          ||
      type == dtUInt[INT_SIZE_32]          ||
      type == dtUInt[INT_SIZE_64]          ||

      type == dtReal[FLOAT_SIZE_32]        ||
      type == dtReal[FLOAT_SIZE_64]        ||

      type == dtImag[FLOAT_SIZE_32]        ||
      type == dtImag[FLOAT_SIZE_64]        ||

      type == dtComplex[COMPLEX_SIZE_64]   ||
      type == dtComplex[COMPLEX_SIZE_128]) {

    retval = true;

  } else {
    retval = false;
  }

  return retval;
}

bool isNonGenericClass(Type* type) {
  bool retval = false;

  if (AggregateType* at = toAggregateType(type)) {
    if (at->isClass()                    ==  true &&
        at->isGeneric()                  == false &&
        at->symbol->hasFlag(FLAG_EXTERN) == false) {
      retval = true;
    }
  }

  return retval;
}

bool isNonGenericClassWithInitializers(Type* type) {
  bool retval = false;

  if (isNonGenericClass(type) == true) {
    if (AggregateType* at = toAggregateType(type)) {
      if (at->hasUserDefinedInit == true) {
        retval = true;
      } else if (at->wantsDefaultInitializer()) {
        retval = true;
      }
    }
  }

  return retval;
}

bool isGenericClass(Type* type) {
  bool retval = false;

  if (AggregateType* at = toAggregateType(type)) {
    if (at->isClass()                    == true  &&
        at->isGeneric()                  == true  &&
        at->symbol->hasFlag(FLAG_EXTERN) == false) {
      retval = true;
    }
  }

  return retval;
}

bool isGenericClassWithInitializers(Type* type) {
  bool retval = false;

  if (isGenericClass(type) == true) {
    if (AggregateType* at = toAggregateType(type)) {
      if (at->hasUserDefinedInit == true) {
        retval = true;
      } else if (at->wantsDefaultInitializer()) {
        retval = true;
      }
    }
  }

  return retval;
}

bool isClassWithInitializers(Type* type) {
  bool retval = false;

  if (AggregateType* at = toAggregateType(type)) {
    if (at->isClass()                    == true  &&
        at->symbol->hasFlag(FLAG_EXTERN) == false &&
        (at->hasUserDefinedInit == true ||
         at->wantsDefaultInitializer())) {
      retval = true;
    }
  }

  return retval;
}

bool isNonGenericRecord(Type* type) {
  bool retval = false;

  if (AggregateType* at = toAggregateType(type)) {
    if (at->isRecord()                   == true  &&
        at->isGeneric()                  == false) {
      retval = true;
    }
  }

  return retval;
}

bool isNonGenericRecordWithInitializers(Type* type) {
  bool retval = false;

  if (isNonGenericRecord(type) == true) {
    if (AggregateType* at = toAggregateType(type)) {
      if (at->hasUserDefinedInit == true) {
        retval = true;
      } else if (at->wantsDefaultInitializer() &&
                 // don't count compiler-generated init for extern records
                 !at->symbol->hasFlag(FLAG_EXTERN)) {
        retval = true;
      }
    }
  }

  return retval;
}

bool isGenericRecord(Type* type) {
  bool retval = false;

  if (AggregateType* at = toAggregateType(type)) {
    if (at->isRecord()                   == true  &&
        at->isGeneric()                  == true  &&
        at->symbol->hasFlag(FLAG_EXTERN) == false) {
      retval = true;
    }
  }

  return retval;
}

bool isGenericRecordWithInitializers(Type* type) {
  bool retval = false;

  if (isGenericRecord(type) == true) {
    if (AggregateType* at = toAggregateType(type)) {
      if (at->hasUserDefinedInit == true) {
        retval = true;
      } else if (at->wantsDefaultInitializer()) {
        retval = true;
      }
    }
  }

  return retval;
}

bool isRecordOrUnionWithInitializers(Type* type) {
  bool retval = false;

  if (AggregateType* at = toAggregateType(type)) {
    if ((at->isRecord() || at->isUnion()) &&
        (at->hasUserDefinedInit == true ||
         at->wantsDefaultInitializer())) {
      retval = true;
    }
  }

  return retval;
}

//
// The simplest and most obvious case is that generic records need generic
// initializers.
//
// Instantiated records also require generic initializers, because their
// type or param fields need to be handled by an initializer.
//
bool needsGenericRecordInitializer(Type* type) {
  bool retval = false;

  if (AggregateType* at = toAggregateType(type)) {
    if (isRecordOrUnionWithInitializers(type)) {
      if (at->isGeneric() == true ||
          at->symbol->hasFlag(FLAG_GENERIC) == true ||
          at->instantiatedFrom != NULL) {
        retval = true;
      }
    }
  }

  return retval;
}

const Immediate& getDefaultImmediate(Type* t) {
  VarSymbol* defaultVar = toVarSymbol(t->defaultValue);
  // (or anything handled by coerce_immediate)
  if (defaultVar == NULL || defaultVar->immediate == NULL)
    INT_FATAL(t->symbol, "does not have a default value");

  // Numeric types should have a default of the right type
  if (defaultVar->type != t)
    INT_FATAL(t->symbol, "does not have a default of the same type");

  return *defaultVar->immediate;
}

llvm::SmallVector<std::string, 2> explainGeneric(Type* t) {
  if (auto clsType = toDecoratedClassType(t)) {
    if (isDecoratorUnknownManagement(clsType->getDecorator())) {
      return {"'" + std::string(t->name()) + "' is a class with unknown management"};
    }
  }
  if (t->symbol->hasFlag(FLAG_ARRAY)) {
    return {"it is an array with runtime type information"};
  }
  if (auto at = toAggregateType(t)) {
    if (at->isGeneric()) {
    llvm::SmallVector<std::string, 2> reasons;
      for (auto i = 1; i <= at->numFields(); i++) {
        auto fieldType = at->getField(i)->type;
        if (fieldType->symbol && fieldType->symbol->hasFlag(FLAG_GENERIC)) {
          auto moreReasons = explainGeneric(fieldType);
          reasons.append(moreReasons.begin(), moreReasons.end());
        }
      }
      if (!reasons.empty()) {
        return reasons;
      }
    }
  }
  return {};
}

// Returns 'true' for types that are the type of numeric literals.
// e.g. 1 is an 'int', so this function returns 'true' for 'int'.
// e.g. 0.0 is a 'real', so this function returns 'true' for 'real'.
bool isNumericParamDefaultType(Type* t)
{
  if (t == dtInt[INT_SIZE_DEFAULT] ||
      t == dtReal[FLOAT_SIZE_DEFAULT] ||
      t == dtImag[FLOAT_SIZE_DEFAULT] ||
      t == dtComplex[COMPLEX_SIZE_DEFAULT] ||
      t == dtBool)
    return true;

  return false;
}

TypeSymbol*
getDataClassType(TypeSymbol* ts) {
  Symbol* value = ts->type->getSubstitutionWithName(astr("eltType"));

  return toTypeSymbol(value);
}

void
setDataClassType(TypeSymbol* ts, TypeSymbol* ets) {
  ts->type->setSubstitutionWithName(astr("eltType"), ets);
}
