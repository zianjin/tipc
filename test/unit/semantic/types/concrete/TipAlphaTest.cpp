#include "TipAlpha.h"
#include "ASTIntExpr.h"

#include <catch2/catch_test_macros.hpp>

#include <sstream>

TEST_CASE("TipAlpha: Test TipAlphas are compared by their underlying objects" "[TipAlpha]") {
    ASTIntExpr num(13);
    TipAlpha tipAlphaA(&num);
    TipAlpha tipAlphaB(&num);
    REQUIRE(tipAlphaA == tipAlphaB);
}

TEST_CASE("TipAlpha: Test getter" "[TipAlpha]") {
    ASTIntExpr num1(13);
    ASTIntExpr num2(42);
    TipAlpha tipAlphaA(&num1);
    TipAlpha tipAlphaB(&num2);

    auto node1 = dynamic_cast<ASTIntExpr*>(tipAlphaA.getNode());
    auto node2 = dynamic_cast<ASTIntExpr*>(tipAlphaB.getNode());
    REQUIRE(node1->getValue() == 13);
    REQUIRE(node2->getValue() == 42);
}

TEST_CASE("TipAlpha: Test output stream" "[TipAlpha]") {
    ASTIntExpr num(13);
    TipAlpha tipAlphaA(&num);

    std::string expectedValueA("\u03B1<13>");

    std::stringstream stream;
    stream << tipAlphaA;
    std::string actualValueA = stream.str();

    REQUIRE(expectedValueA == actualValueA);
}
