#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "dynamic_array_list.h"
#include "queue.h"

#include <cassert>

TEST_CASE("Testing ArrayList", "[dynamicArrayList]") {
  DynamicArrayList<int> d;

  REQUIRE(d.getLength() == 0);
  d.insert(d.getLength(), 12);
  REQUIRE(d.getEntry(0) == 12);
}

TEST_CASE("Testing 1", "[queue]") {
  // a queue, holding ints, using a DynamicArrayList as the container
  Queue<int, DynamicArrayList<int>> queue;

  REQUIRE(queue.isEmpty() == 1);

  queue.enqueue(12);
  REQUIRE(!queue.isEmpty());
  REQUIRE(queue.peekFront() == 12);

  queue.enqueue(-4);
  REQUIRE_FALSE(queue.isEmpty());
  REQUIRE(queue.peekFront() == 12);

  queue.dequeue();
  REQUIRE(queue.peekFront() == -4);
  queue.dequeue();
  REQUIRE(queue.isEmpty());

  queue.enqueue(241);
  REQUIRE_FALSE(queue.isEmpty());
  REQUIRE(queue.peekFront() == 241);

  queue.enqueue(45);
  REQUIRE(!queue.isEmpty());
  REQUIRE(queue.peekFront() == 241);

  queue.enqueue(62);
  REQUIRE_FALSE(queue.isEmpty());
  REQUIRE(queue.peekFront() == 241);

  Queue<int, DynamicArrayList<int>> another_queue;
  another_queue = queue;

  REQUIRE_FALSE(another_queue.isEmpty());
  REQUIRE(another_queue.peekFront() == 241);
  another_queue.dequeue();
  REQUIRE(another_queue.peekFront() == 45);
  another_queue.dequeue();
  REQUIRE(another_queue.peekFront() == 62);
}