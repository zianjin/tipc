#pragma once

#include "ConstraintHandler.h"
#include "TypeConstraint.h"
#include "Unifier.h"


/*!
 * \class ConstraintUnifier
 *
 * \brief A constraint handler to unify constraints on the fly.
 */
class ConstraintUnifier: public ConstraintHandler {
public:
    ConstraintUnifier(std::shared_ptr<Unifier> uni);
    void handle(std::shared_ptr<TipType> t1, std::shared_ptr<TipType> t2) override;

private:
    std::shared_ptr<Unifier> unifier;
};

