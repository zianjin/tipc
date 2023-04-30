#include "TypeConstraintUnifyVisitor.h"
#include "ConstraintUnifier.h"
#include "TipInt.h"
#include "TipFloat.h"
#include "TipAlpha.h"
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


/** 
 * @brief: Type constraints for binary operator.
 * @see: TypeConstraintVisitor::endVisit(ASTBinaryExpr * element)
 */
void TypeConstraintUnifyVisitor::endVisit(ASTBinaryExpr  * element) {
  auto op = element->getOp();
  auto floatType = std::make_shared<TipFloat>();

  // Add type constraint depend on the oprand
  if (op == "==" || op == "!=" || op == ">") {
    // Relation and equality expr: operands have the same type
    constraintHandler->handle(astToVar(element->getLeft()), astToVar(element->getRight()));
  } else {

    // Additive and multipicative expr: convert to float is necessary
    auto leftType = getInferredType(astToVar(element->getLeft()));
    auto rightType = getInferredType(astToVar(element->getRight()));

    if (!dynamic_cast<TipAlpha*>(leftType.get()) && !dynamic_cast<TipAlpha*>(rightType.get())) {
      if (floatType->doMatch(leftType.get()) || floatType->doMatch(rightType.get())){
        // Float + Float/Int = Float
        constraintHandler->handle(astToVar(element), floatType);
      } else {
        // Int + Int = Int
        constraintHandler->handle(astToVar(element), std::make_shared<TipInt>());
      }
    }
  }
}

/** 
 * @brief: Type constraints for function definition.
 * @see: TypeConstraintVisitor::endVisit(ASTFunction * element)
 */
void TypeConstraintUnifyVisitor::endVisit(ASTFunction * element) {
  std::vector<std::shared_ptr<TipType>> formals;
  for(auto &f : element->getFormals()) {
    formals.push_back(astToVar(f));
  }

  // Return is the last statement 
  auto ret = dynamic_cast<ASTReturnStmt*>(element->getStmts().back());

  constraintHandler->handle(astToVar(element->getDecl()),
                            std::make_shared<TipFunction>(formals, astToVar(ret->getArg())));
}
