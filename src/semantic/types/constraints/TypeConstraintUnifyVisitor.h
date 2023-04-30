#pragma once

#include "ConstraintHandler.h"
#include "SymbolTable.h"
#include "TypeConstraintVisitor.h"
#include "Unifier.h"
#include <memory>

/*! \class TypeConstraintUnifyVisitor
 *
 *  \brief Visitor generates type constraints and unifies them on-the-fly.
 */
class TypeConstraintUnifyVisitor: public TypeConstraintVisitor {
public:
    explicit TypeConstraintUnifyVisitor(SymbolTable *pTable, std::shared_ptr<Unifier> uni = nullptr);
    
    // Override parent class method
    void endVisit(ASTFunction * element) override;
    void endVisit(ASTBinaryExpr * element) override;

private:
    static std::unique_ptr<ConstraintHandler> buildConstraintHandler(std::shared_ptr<Unifier> uni);

    // Use unifier to infer the type
    std::shared_ptr<Unifier> unifier;
    std::shared_ptr<TipType> getInferredType(std::shared_ptr<TipType> typeVar);
};

