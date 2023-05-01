// "Copyright 2023 <AleFreitas>" [legal/copyright] [5]
#define CATCH_CONFIG_MAIN
// This tells Catch to provide a main() - only do this in one cpp file
#include "./catch.hpp"
#include "./romanos.hpp"

TEST_CASE("Caractere unico e valido inserido", "[romanos]") {
    REQUIRE(RomanosParaDecimal("I") == 1);
    REQUIRE(RomanosParaDecimal("V") == 5);
    REQUIRE(RomanosParaDecimal("X") == 10);
    REQUIRE(RomanosParaDecimal("L") == 50);
    REQUIRE(RomanosParaDecimal("C") == 100);
    REQUIRE(RomanosParaDecimal("D") == 500);
    REQUIRE(RomanosParaDecimal("M") == 1000);
}

TEST_CASE("Caractere unico e invalido (nao romano) inserido", "[romanos]") {
    REQUIRE(RomanosParaDecimal("2") == -1);
    REQUIRE(RomanosParaDecimal("2") == -1);
    REQUIRE(RomanosParaDecimal("0") == -1);
    REQUIRE(RomanosParaDecimal("G") == -1);
    REQUIRE(RomanosParaDecimal("H") == -1);
}

TEST_CASE("Multiplos caracteres validos inseridos",
"[romanos]") {
    REQUIRE(RomanosParaDecimal("MMDCXCI") == 2691);
    REQUIRE(RomanosParaDecimal("MMCMLXXIX") == 2979);
}

TEST_CASE(
"Multiplos caracteres invalidos (nao romanos) inseridos",
"[romanos]") {
    REQUIRE(RomanosParaDecimal("J2OPA2") == -1);
    REQUIRE(RomanosParaDecimal("MMCMLXXIKP") == -1);
}

TEST_CASE(
"Multiplos caracteres validos repetidos de forma invalida",
"[romanos]") {
    REQUIRE(RomanosParaDecimal("VV") == -1);
    REQUIRE(RomanosParaDecimal("XXXX") == -1);
    REQUIRE(RomanosParaDecimal("LL") == -1);
    REQUIRE(RomanosParaDecimal("CCCC") == -1);
    REQUIRE(RomanosParaDecimal("DD") == -1);
    REQUIRE(RomanosParaDecimal("MMMM") == -1);
}

TEST_CASE(
"Multiplos caracteres validos inseridos de forma invalida (ordem invalida)",
"[romanos]") {
    REQUIRE(RomanosParaDecimal("VX") == -1);
    REQUIRE(RomanosParaDecimal("DM") == -1);
    REQUIRE(RomanosParaDecimal("LC") == -1);
}
