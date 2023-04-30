#include "ConstraintUnifier.h"

ConstraintUnifier::ConstraintUnifier(std::shared_ptr<Unifier> uni): unifier(uni) {}

void ConstraintUnifier::handle(std::shared_ptr<TipType> t1, std::shared_ptr<TipType> t2) {
    unifier->unify(t1, t2);
}

