#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "bitset.hpp"
#include <string>

TEST_CASE( "Const. 1", "[bitset]" ) {

    Bitset b;  
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
    REQUIRE(b.asString() == "00000000");
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
    REQUIRE(b.size() == 8);  
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
    b.reset(-1);
    REQUIRE(!b.good());
}

TEST_CASE( "Toggle", "[bitset]" ) {

    Bitset b("00011000");  
    b.toggle(6);
    b.toggle(4);
    REQUIRE(b.asString() == "01001000");
}

TEST_CASE( "Toggle Invalid Set", "[bitset]" ) {

    Bitset b("12332111");  
    b.toggle(6);
    b.toggle(4);
    REQUIRE(b.asString() == "12332111");
    REQUIRE(!b.good());
}

TEST_CASE( "Toggle Invalid", "[bitset]" ) {

    Bitset b("00011000");  
    b.toggle(11);
    REQUIRE(!b.good());
}

TEST_CASE( "Test", "[bitset]" ) {

    Bitset b("10101010");
    REQUIRE(b.test(7));
    REQUIRE(!b.test(6));
}

TEST_CASE( "Test Invalid", "[bitset]" ) {

    Bitset b("10101010");
    REQUIRE(!b.test(-1));
    REQUIRE(!b.good());
}

TEST_CASE( "asString", "[bitset]" ) {

    Bitset b;  
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
}