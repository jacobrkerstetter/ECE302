#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "dynamic_array_list.h"
#include "sorted_list.h"
#include "priority_queue.h"

TEST_CASE("Testing Priority Queue", "[priority queue]") {
  typedef SortedList<int, DynamicArrayList<int> > SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;

  pq.add(10);
  pq.add(20);
  pq.add(15);
  REQUIRE(pq.peek() == 20);
  REQUIRE(!pq.isEmpty());
  pq.remove();
  REQUIRE(pq.peek() == 15);
  pq.remove();
  REQUIRE(pq.peek() == 10);
  pq.remove();
  REQUIRE(pq.isEmpty());
}
