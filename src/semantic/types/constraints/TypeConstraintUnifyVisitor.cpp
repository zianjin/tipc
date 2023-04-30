#include "TypeConstraintUnifyVisitor.h"
#include "ConstraintUnifier.h"
#include "TipInt.h"
#include "TipFloat.h"
#include "TipFunction.h"

TypeConstraintUnifyVisitor::TypeConstraintUnifyVisitor(SymbolTable *pTable, std::shared_ptr<Unifier> uni)
  : TypeConstraintVisitor(pTable, std::move(buildConstraintHandler(uni))), unifier(uni) { }

std::unique_ptr<ConstraintHandler> TypeConstraintUnifyVisitor::buildConstraintHandler(std::shared_ptr<Unifier> uni) {
  // Initialize the unifier
  if (uni == nullptr) {
    uni = std::shared_ptr<Unifier>();
  }
  return std::make_unique<ConstraintUnifier>(uni);
}

std::shared_ptr<TipType> TypeConstraintUnifyVisitor::getInferredType(std::shared_ptr<TipType> typeVar) {
  return unifier->inferred(typeVar);
}