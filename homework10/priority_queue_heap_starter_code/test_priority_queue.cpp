#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "heap_priority_queue.h"

TEST_CASE("Test Construction", "[construction]") {
  HeapPriorityQueue<int>  pq;
  REQUIRE(pq.isEmpty());
}

TEST_CASE("Test add", "[add]") {
  HeapPriorityQueue<int>  pq;
  pq.add(25);

  REQUIRE(!pq.isEmpty());
  REQUIRE(pq.peek() == 25);

  pq.add(1);
  REQUIRE(pq.peek() == 25);

  pq.add(78);
  REQUIRE(pq.peek() == 78);
}

TEST_CASE("Test remove", "[remove]") {
  HeapPriorityQueue<int>  pq;
  pq.add(25);
  pq.add(1);
  pq.add(78);

  pq.remove();
  REQUIRE(pq.peek() == 25);
  pq.remove();
  REQUIRE(pq.peek() == 1);
  pq.remove();
  REQUIRE(pq.isEmpty());
}

TEST_CASE("Test all 1", "[remove]") {
  HeapPriorityQueue<int>  pq;
  pq.add(25);
  pq.add(1);
  pq.add(78);

  pq.remove();
  REQUIRE(pq.peek() == 25);

  pq.add(100);
  pq.add(55);
  pq.add(0);
  REQUIRE(pq.peek() == 100);

  pq.remove();
  REQUIRE(pq.peek() == 55);

  pq.remove();
  pq.remove();
  pq.remove();
  REQUIRE(pq.peek() == 0);

  pq.remove();
  REQUIRE(pq.isEmpty());
}

TEST_CASE("Test remove from empty", "[remove]") {
  HeapPriorityQueue<int>  pq;
  pq.add(25);
  pq.add(100);

  pq.remove();
  REQUIRE(pq.peek() == 25);

  pq.remove();
}

TEST_CASE("FULL TEST", "[remove]") {
  HeapPriorityQueue<int>  pq;
  REQUIRE(pq.isEmpty());

  pq.add(100);
  pq.add(50);
  pq.add(150);

  REQUIRE(pq.peek() == 150);
  pq.remove();

  REQUIRE(pq.peek() == 100);
  pq.add(200);

  REQUIRE(pq.peek() == 200);
  pq.remove();

  REQUIRE(pq.peek() == 100);
  pq.remove();

  REQUIRE(pq.peek() == 50);
  pq.remove();

  REQUIRE(pq.isEmpty());
}