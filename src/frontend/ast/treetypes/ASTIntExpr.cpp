#include "ASTIntExpr.h"
#include "ASTVisitor.h"

#include <iostream>

void ASTIntExpr::accept(ASTVisitor * visitor) {
  visitor->visit(this);
  visitor->endVisit(this);
}

std::ostream& ASTIntExpr::print(std::ostream &out) const {
  out << getValue();
  return out;
}
