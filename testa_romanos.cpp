#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "romanos.hpp"


TEST_CASE ("Caractere unico e valido inserido","[romanos]") {
    REQUIRE (romanos_para_decimal("I") == 1);
    REQUIRE (romanos_para_decimal("V") == 5);
    REQUIRE (romanos_para_decimal("X") == 10);
    REQUIRE (romanos_para_decimal("L") == 50);
    REQUIRE (romanos_para_decimal("C") == 100);
    REQUIRE (romanos_para_decimal("D") == 500);
    REQUIRE (romanos_para_decimal("M") == 1000);
}

TEST_CASE ("Caractere unico e invalido (nao romano) inserido","[romanos]") {
    REQUIRE (romanos_para_decimal("2") == -1);
    REQUIRE (romanos_para_decimal("2") == -1);
    REQUIRE (romanos_para_decimal("0") == -1);
    REQUIRE (romanos_para_decimal("G") == -1);
    REQUIRE (romanos_para_decimal("H") == -1);
}

TEST_CASE ("Multiplos caracteres validos inseridos", "[romanos]") {
    REQUIRE (romanos_para_decimal("MMDCXCI") == 2691);
    REQUIRE (romanos_para_decimal("MMCMLXXIX") == 2979);
}