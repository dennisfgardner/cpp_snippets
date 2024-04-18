#define CATCH_CONFIG_MAIN
#include "utilities.hpp"
#include "catch2/catch.hpp"


TEST_CASE( "argument count checker", "[utilities]" ) {
    REQUIRE( arg_count_checker(1, 0) == true);
    REQUIRE( arg_count_checker(2, 1) == true);
    REQUIRE( arg_count_checker(10, 9) == true);
    REQUIRE( arg_count_checker(10, 10) == false);
    REQUIRE( arg_count_checker(10, 8) == false);
    REQUIRE( arg_count_checker(2, 0) == false);
}
