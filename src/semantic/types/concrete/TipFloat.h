#pragma once

#include "TipType.h"
#include "TipCons.h"
#include <string>

/*!
 * \class TipFloat
 *
 * \brief A proper type representing a float
 */
class TipFloat: public TipCons {
public:
    TipFloat();

    bool operator==(const TipType& other) const override;
    bool operator!=(const TipType& other) const override;

    void accept(TipTypeVisitor *visitor) override;

protected:
    std::ostream& print(std::ostream &out) const override;
};

