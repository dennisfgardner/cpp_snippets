#define CATCH_CONFIG_MAIN

#include <string_view>
#include <string>
#include <filesystem>

#include "catch2/catch.hpp"
#include "utilities.hpp"

TEST_CASE( "argument count checker", "[utilities]" )
{
    const std::string usage{"test test test"};
    REQUIRE( argc_checker(1, usage, 0) == true);
    REQUIRE( argc_checker(2, usage, 1) == true);
    REQUIRE( argc_checker(10, usage, 9) == true);
    REQUIRE( argc_checker(10, usage, 0) == false);
    REQUIRE( argc_checker(10, usage, 8) == false);
    REQUIRE( argc_checker(2, usage, 0) == false);
}

TEST_CASE( "directory checker", "[utilities]" )
{
    REQUIRE( dir_checker("../test/") == true);
    const std::string_view src{"../src/"};
    REQUIRE( dir_checker(src) == true);
    std::string hdr{"../include"};
    REQUIRE( dir_checker(hdr) == true);
    REQUIRE( dir_checker("/foobar_98930") == false);
    const std::string_view foo{"./ijdhdofi/"};
    REQUIRE( dir_checker(foo) == false);
    std::string bar{"jkjdf/dfj/dor"};
    REQUIRE( dir_checker(bar) == false);
}
