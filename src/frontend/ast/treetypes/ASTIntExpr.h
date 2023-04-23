#pragma once

#include "ASTExpr.h"

/*! \brief Class for integer literals.
 */
class ASTIntExpr : public ASTExpr {
  int VAL;
public:
  ASTIntExpr(int VAL) : VAL(VAL) {}
  int getValue() const { return VAL; }
  void accept(ASTVisitor * visitor) override;
  llvm::Value* codegen() override;

protected:
  std::ostream& print(std::ostream &out) const override;
};
