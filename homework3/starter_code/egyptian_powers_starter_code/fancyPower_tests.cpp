#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "fancyPower.hpp"

// write your test cases here
TEST_CASE("Basic Test", "fancyPower"){

  REQUIRE(fancyPower(2,2) == 4);
}

TEST_CASE("0 Power", "fancyPower"){

  REQUIRE(fancyPower(0,2) == 1);
}

TEST_CASE("1 Power", "fancyPower"){

  REQUIRE(fancyPower(1,5) == 5);
}

TEST_CASE("2 Power", "fancyPower"){

  REQUIRE(fancyPower(2,5) == 25);
}

TEST_CASE("Odd Power 1", "fancyPower"){

  REQUIRE(fancyPower(7,2) == 128);
}

TEST_CASE("Odd Power 2", "fancyPower"){

  REQUIRE(fancyPower(3,5) == 125);
}

TEST_CASE("Even Power 1", "fancyPower"){

  REQUIRE(fancyPower(4,3) == 81);
}

TEST_CASE("Even Power 2", "fancyPower"){

  REQUIRE(fancyPower(4,1) == 1);
}