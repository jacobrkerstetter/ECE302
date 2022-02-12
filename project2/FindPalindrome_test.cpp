#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method

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
	REQUIRE(b.add("taco"));
	REQUIRE(b.number() == 0);
	REQUIRE(b.add("cat"));
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