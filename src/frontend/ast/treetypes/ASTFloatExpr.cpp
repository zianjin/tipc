#include "ASTFloatExpr.h"
#include "ASTVisitor.h"

#include <iostream>

void ASTFloatExpr::accept(ASTVisitor * visitor) {
  visitor->visit(this);
  visitor->endVisit(this);
}

std::ostream& ASTFloatExpr::print(std::ostream &out) const {
  out << getValue();
  return out;
}
