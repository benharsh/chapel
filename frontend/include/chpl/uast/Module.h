/*
 * Copyright 2021-2025 Hewlett Packard Enterprise Development LP
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

#ifndef CHPL_UAST_MODULE_H
#define CHPL_UAST_MODULE_H

#include "chpl/uast/NamedDecl.h"
#include "chpl/framework/Location.h"

namespace chpl {
namespace uast {


/**
  This class represents a module declaration. For example:

  \rst
  .. code-block:: chapel

      module M { }
  \endrst

  is a declaration for a module named M.
 */
class Module final : public NamedDecl {
 friend class AstNode;

 public:
  enum Kind {
    DEFAULT_MODULE_KIND,
    PROTOTYPE,
    IMPLICIT,
  };

 private:
  Kind kind_;

  Module(AstList children, int attributeGroupChildNum, Decl::Visibility vis,
         UniqueString name,
         Kind kind)
    : NamedDecl(asttags::Module, std::move(children), attributeGroupChildNum,
                vis,
                Decl::DEFAULT_LINKAGE,
                /*linkageNameChildNum*/ NO_CHILD,
                name),
                kind_(kind) {

  }

  void serializeInner(Serializer& ser) const override {
    namedDeclSerializeInner(ser);
    ser.write(kind_);
  }

  explicit Module(Deserializer& des)
    : NamedDecl(asttags::Module, des) {
    kind_ = des.read<Kind>();
  }


  bool contentsMatchInner(const AstNode* other) const override {
    const Module* lhs = this;
    const Module* rhs = (const Module*) other;
    return lhs->namedDeclContentsMatchInner(rhs) &&
           lhs->kind_ == rhs->kind_;

  }
  void markUniqueStringsInner(Context* context) const override {
    namedDeclMarkUniqueStringsInner(context);
  }

  int stmtChildNum() const {
    return attributeGroup() ? 1 : 0;
  }

  void dumpFieldsInner(const DumpSettings& s) const override;

 public:
  ~Module() override = default;

  static owned<Module> build(Builder* builder, Location loc,
                             owned<AttributeGroup> attributeGroup,
                             Decl::Visibility vis,
                             UniqueString name,
                             Module::Kind kind,
                             AstList stmts);

  /**
    Return the kind of this module (e.g. 'PROTOTYPE' or 'IMPLICIT');
  */
  Kind kind() const { return this->kind_; }

  /**
    Iterate over the statements in this module.
  */
  AstListIteratorPair<AstNode> stmts() const {
    auto begin = numStmts()
        ? children_.begin() + stmtChildNum()
        : children_.end();
    auto end = begin + numStmts();
    return AstListIteratorPair<AstNode>(begin, end);
  }

  /**
    Return the number of statements in this module.
  */
  int numStmts() const {
    return attributeGroup() ? numChildren()-1 : numChildren();
  }

  /**
    Get the i'th statement in this module.
  */
  const AstNode* stmt(int i) const {
    CHPL_ASSERT(0 <= i && i < numStmts());
    const AstNode* ast = this->child(i + stmtChildNum());
    return ast;
  }

  /**
    Return a string describing a Module::Kind
   */
  static const char* moduleKindToString(Kind kind);
};


} // end namespace uast

DECLARE_SERDE_ENUM(uast::Module::Kind, uint8_t);

/// \cond DO_NOT_DOCUMENT
template<> struct update<uast::Module::Kind> {
  bool operator()(uast::Module::Kind& keep,
                  uast::Module::Kind& addin) const {
    return defaultUpdateBasic(keep, addin);
  }
};

template<> struct mark<uast::Module::Kind> {
  void operator()(Context* context,
                  const uast::Module::Kind& keep) const {
    // nothing to do for enum
  }
};


/// \endcond DO_NOT_DOCUMENT


} // end namespace chpl

#endif
