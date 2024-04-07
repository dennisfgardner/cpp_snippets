#define CATCH_CONFIG_MAIN
#include "main.hpp"
#include "catch2/catch.hpp"


TEST_CASE( "Main finishes successfully", "[main]" ) {
    REQUIRE( int_adder(2, 2) == 4 );
    REQUIRE( int_adder(2, 3) == 5 );
    REQUIRE( int_adder(0, 0) == 0 );
    REQUIRE( int_adder(-1, -1) == -2 );
    REQUIRE( int_adder(-1, 1) == 0 );
}

// example from catch2 documentation
TEST_CASE( "vectors can be sized and resized", "[vector]" ) {
    // This setup will be done 4 times in total, once for each section
    std::vector<int> v( 5 );

    REQUIRE( v.size() == 5 );
    REQUIRE( v.capacity() >= 5 );

    SECTION( "resizing bigger changes size and capacity" ) {
        v.resize( 10 );

        REQUIRE( v.size() == 10 );
        REQUIRE( v.capacity() >= 10 );
    }
    SECTION( "resizing smaller changes size but not capacity" ) {
        v.resize( 0 );

        REQUIRE( v.size() == 0 );
        REQUIRE( v.capacity() >= 5 );
    }
    SECTION( "reserving bigger changes capacity but not size" ) {
        v.reserve( 10 );

        REQUIRE( v.size() == 5 );
        REQUIRE( v.capacity() >= 10 );
    }
    SECTION( "reserving smaller does not change size or capacity" ) {
        v.reserve( 0 );

        REQUIRE( v.size() == 5 );
        REQUIRE( v.capacity() >= 5 );
    }
}