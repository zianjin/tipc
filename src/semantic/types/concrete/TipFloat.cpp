#include "TipFloat.h"
#include "TipTypeVisitor.h"

#include <string>

TipFloat::TipFloat() { }

bool TipFloat::operator==(const TipType &other) const {
    auto otherTipFloat = dynamic_cast<TipFloat const *>(&other);
    if(!otherTipFloat) {
        return false;
    }

    return true;
}

bool TipFloat::operator!=(const TipType &other) const {
    return !(*this == other);
}

std::ostream &TipFloat::print(std::ostream &out) const {
    out << std::string("float");
    return out;
}  // LCOV_EXCL_LINE

// TipFloat is a 0-ary type constructor so it has no arguments to visit
void TipFloat::accept(TipTypeVisitor * visitor) {
  visitor->visit(this);
  visitor->endVisit(this);
}
