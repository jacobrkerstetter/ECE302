#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"

template class LinkedList<int>;

TEST_CASE( "Make a list, add 3 nodes", "[LinkedList]" ) {
    LinkedList<int> l;

    l.insert(1, 3);
    l.insert(2, 4);
    l.insert(3, 5);

    REQUIRE(l.getLength() == 3);
}

TEST_CASE( "Make a list, add nodes to front", "[LinkedList]" ) {
    LinkedList<int> l;

    l.insert(1, 3);
    l.insert(1, 4);
    l.insert(1, 5);

    REQUIRE(l.getLength() == 3);
    REQUIRE(l.getEntry(1) == 5);
}

TEST_CASE( "Make a list, set a node in valid position", "[LinkedList]" ) {
    LinkedList<int> l;

    l.insert(1, 3);
    l.insert(2, 4);
    l.insert(3, 5);
    l.setEntry(2, 17);

    REQUIRE(l.getLength() == 3);
    REQUIRE(l.getEntry(2) == 17);
}
TEST_CASE( "Make a list, set a node in invalid position", "[LinkedList]" ) {
    LinkedList<int> l;

    l.insert(1, 3);
    l.insert(2, 4);
    l.insert(3, 5);
    l.setEntry(4, 17);
    l.getEntry(4);
}