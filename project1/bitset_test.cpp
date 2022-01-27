#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "bitset.hpp"
#include <string>

TEST_CASE( "Const. 1", "[bitset]" ) {

    Bitset b;  
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
}

TEST_CASE( "Const. 2", "[bitset]" ) {

    Bitset b(10);  
    REQUIRE(b.size() == 10);
    REQUIRE(b.good());
}

TEST_CASE( "Const. 2 Invalid", "[bitset]" ) {

    Bitset b(-1);  
    REQUIRE(!b.good());
}

TEST_CASE( "Const. 3", "[bitset]" ) {

    std::string bitstring = "011000111";
    Bitset b(bitstring);  
    REQUIRE(b.size() == 9);
    REQUIRE(b.good());
    REQUIRE(b.asString() == "011000111");
}

TEST_CASE( "Const. 3 Invalid", "[bitset]" ) {

    std::string bitstring = "123440003";
    Bitset b(bitstring);  
    REQUIRE(b.size() == 9);
    REQUIRE(!b.good());
}

TEST_CASE( "Size", "[bitset]" ) {

    Bitset b(11);  
    REQUIRE(b.size() == 11);
    REQUIRE(b.good());
}

TEST_CASE( "Valid", "[bitset]" ) {

    Bitset b;  
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
}

TEST_CASE( "Set", "[bitset]" ) {

    Bitset b;  
    b.set(6);
    REQUIRE(b.good());
    REQUIRE(b.asString() == "01000000");
}

TEST_CASE( "Set Invalid", "[bitset]" ) {

    Bitset b;  
    b.set(9);
    REQUIRE(!b.good());
}

TEST_CASE( "Reset", "[bitset]" ) {

    Bitset b("11111111");  
    b.reset(3);
    REQUIRE(b.asString() == "11110111");
    REQUIRE(b.good());
}

TEST_CASE( "Reset Invalid", "[bitset]" ) {

    Bitset b;  
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
}

TEST_CASE( "Toggle", "[bitset]" ) {

    Bitset b;  
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
}

TEST_CASE( "Test", "[bitset]" ) {

    Bitset b;  
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
}

TEST_CASE( "asString", "[bitset]" ) {

    Bitset b;  
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
}