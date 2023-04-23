#pragma once

#include "ASTExpr.h"

/*! \brief Class for float literals.
 */
class ASTFloatExpr : public ASTExpr {
  float VAL;
public:
  ASTFloatExpr(float VAL) : VAL(VAL) {}
  float getValue() const { return VAL; }
  void accept(ASTVisitor * visitor) override;
  llvm::Value* codegen() override;

protected:
  std::ostream& print(std::ostream &out) const override;
};
