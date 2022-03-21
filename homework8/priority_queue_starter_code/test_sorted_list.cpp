#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "dynamic_array_list.h"
#include "sorted_list.h"

TEST_CASE("Testing Sorted List", "[sorted list]") {
  typedef SortedList<int, DynamicArrayList<int> > slst;
  
  slst list;
  REQUIRE(list.getLength() == 0);
  list.insert(1);
  list.insert(5);
  REQUIRE(list.getEntry(1) == 5);
  list.insert(3);
  REQUIRE(list.getEntry(1) == 3);
  REQUIRE(list.getLength() == 3);
  list.remove(3);
  REQUIRE(list.getEntry(1) == 5);
  list.removeAt(0);
  REQUIRE(list.getEntry(0) == 5);
  list.insert(10);
  list.insert(2);
  REQUIRE(list.getPosition(10) == 2);
  REQUIRE(list.getPosition(7) == -2);
  list.clear();
  REQUIRE(list.isEmpty());
}
