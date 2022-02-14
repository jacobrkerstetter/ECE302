#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method
/*
TEST_CASE( "Test FindPalindrome add a non-allowable word", "[FindPalindrome]" )
{
	INFO("Hint: add a single non-allowable word");
	FindPalindrome b;
	REQUIRE(!b.add("kayak1"));
}

TEST_CASE( "Bad Adding Vector", "[FindPalindrome]" )
{
	FindPalindrome b;
	std::vector<std::string> words = {"happy", "ghast", "later"};
	std::vector<std::string> badWords = {"15", "sHOOT", "don't"};
	REQUIRE(b.add(words));
	REQUIRE(!b.add("kayak1"));
	REQUIRE(!b.add(badWords));
}

TEST_CASE( "Good Add", "[FindPalindrome]" )
{
	FindPalindrome b;
	std::vector<std::string> w = {"taco", "cat"};
	REQUIRE(b.add(w));
	REQUIRE(b.number() == 1);
}

TEST_CASE( "Vector Add", "[FindPalindrome]" )
{
	FindPalindrome b;
	std::vector<std::string> v = {"geese", "do", "god", "see"};
	REQUIRE(b.add(v));
	REQUIRE(b.number() == 1);
}

TEST_CASE("cut test 1", "[FindPalindrome]") {
	FindPalindrome f; 
	std::vector<std::string> v = {"ababab"};
	f.add(v);
	REQUIRE(f.cutTest1(v));
}

TEST_CASE("cut test 2", "[FindPalindrome]") {
	FindPalindrome f;
	std::vector<std::string> v = {"hi", "hello"}, w = {"hiel"}, z = {"llleo"};
	f.add(v);
	REQUIRE(f.cutTest2(v, w)); 
	REQUIRE(!f.cutTest2(v, z));
}
*/

TEST_CASE("aaaaa test", "[FindPalindrome]") {
	FindPalindrome f;
	std::vector<std::string> v = {"a", "aa", "AaA"};
	f.add(v);
	REQUIRE(f.number() == 6);
}