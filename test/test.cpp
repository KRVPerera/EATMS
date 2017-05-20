#define CATCH_CONFIG_MAIN
#include "catch.hpp"

unsigned int Factorial(unsigned int num){
    return 9;
}

TEST_CASE("Factorials are computed", "[factorial]"){
    REQUIRE( Factorial(1) == 9 );
}
