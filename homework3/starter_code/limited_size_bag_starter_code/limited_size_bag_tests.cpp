#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "limited_size_bag.hpp"

// force template expansion for ints
template class LimitedSizeBag<int>;

TEST_CASE("Calling all public members", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  for (int i = 0; i < 20; i++)
    b.add(0);
  b.remove(0);
  b.isEmpty();
  b.getCurrentSize();
  b.clear();
  b.getFrequencyOf(0);
  b.contains(0);
}

TEST_CASE("Add", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  for (int i = 0; i < 20; i++)
    b.add(0);

  REQUIRE(b.add(15));
}

TEST_CASE("Add Over Limit", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  for (int i = 0; i < 150; i++)
    b.add(0);

  REQUIRE(!b.add(15));
  REQUIRE(b.getCurrentSize() == 100);
}

TEST_CASE("Remove/Size", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  for (int i = 0; i < 20; i++)
    b.add(i);

  REQUIRE(!b.remove(25));
  REQUIRE(b.remove(15));
  REQUIRE(b.getCurrentSize() == 19);
}

TEST_CASE("Contains/Frequency", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  for (int i = 0; i < 20; i++)
    b.add(i);

  REQUIRE(b.contains(0));
  REQUIRE(!b.contains(25));
}

TEST_CASE("Clear", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  for (int i = 0; i < 20; i++)
    b.add(0);
  
  b.clear();
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());
}
