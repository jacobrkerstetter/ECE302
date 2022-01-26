#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "bag.hpp"
#include <string>

// force template expansion
template class Bag<int>;
template class Bag<std::string>;

TEST_CASE("add", "[add and size]") {
  Bag<int> b;

  b.add(1);
  b.add(3);

  REQUIRE( b.add(5) == true );
  REQUIRE( b.getCurrentSize() == 3 );
}

TEST_CASE("remove", "[remove, clear, and empty]") {
  Bag<std::string> b;

  b.add("Jacob");
  b.add("Kerstetter");
  b.add("cool");

  REQUIRE( b.remove("cool") == true );
  REQUIRE( b.remove("hhh") == false );

  b.clear();

  REQUIRE( b.isEmpty() == true );
}

TEST_CASE("contains", "[contains]") {
  Bag<int> b;

  b.add(1);
  b.add(2);
  b.add(3);

  REQUIRE( b.contains(5) == false);
  REQUIRE( b.contains(2) == true );
}

TEST_CASE("getFreq", "[freq]") {
  Bag<int> b;

  for (int i = 0; i < 5; i++)
    b.add(i);

  b.add(1);
  b.add(1); 

  REQUIRE( b.getFrequencyOf(1) == 3 );
  REQUIRE( b.getFrequencyOf(2) == 1 );
}