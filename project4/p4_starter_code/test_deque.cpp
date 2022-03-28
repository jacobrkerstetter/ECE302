#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "deque.hpp"

TEST_CASE( "Tests", "[deque]" ) {
    Deque<int> d;
    d.pushFront(1);
    d.pushFront(2);
    d.pushFront(3);
    REQUIRE(d.front() == 3);
    d.popFront();
    REQUIRE(d.front() == 2);
    d.popFront();
    REQUIRE(d.front() == 1);
    d.popFront();
    REQUIRE(d.isEmpty());
}
