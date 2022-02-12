#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"

template class LinkedList<int>;
template class LinkedList<std::string>;

// remove item at position in the list using 1-based indexing

TEST_CASE( "Copy Constructor", "[LinkedList]" ) {
    LinkedList<int> l;

    l.insert(1, 3);
    l.insert(1, 4);
    l.insert(1, 5);

    LinkedList<int> copy(l);

    REQUIRE(copy.getLength() == 3);
    REQUIRE(copy.getEntry(1) == 5);
    REQUIRE(copy.getEntry(3) == 3);
}

TEST_CASE( "Copy Assignment", "[LinkedList]" ) {
    LinkedList<int> l, copy;

    l.insert(1, 3);
    l.insert(1, 4);
    l.insert(1, 5);

    copy = l;

    REQUIRE(copy.getLength() == 3);
    REQUIRE(copy.getEntry(1) == 5);

    l.setEntry(3, 40);
    REQUIRE(copy.getEntry(3) == 3);
}

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

TEST_CASE( "Make a list, add nodes to middle", "[LinkedList]" ) {
    LinkedList<int> l;

    l.insert(1, 3);
    l.insert(2, 4);
    l.insert(3, 5);
    l.insert(2, 6);
    l.insert(2, 7);

    REQUIRE(l.getLength() == 5);
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

TEST_CASE( "IsEmpty", "[LinkedList]" ) {
    LinkedList<int> l;

    REQUIRE(l.isEmpty());
    l.insert(1,2);
    REQUIRE(l.getLength() == 1);
    l.remove(1);
    REQUIRE(l.isEmpty());
    std::cout << "is empty: ";
    l.printList();
}

TEST_CASE( "Clear", "[LinkedList]" ) {
    LinkedList<std::string> l;

    l.insert(1, "hi");
    l.insert(2, "hello");
    l.insert(3, "hey");
    REQUIRE(l.getLength() == 3);
    l.clear();
    REQUIRE(l.getLength() == 0);
    std::cout << "clear: ";
    l.printList();
}

TEST_CASE( "Make a list, set a node in invalid position", "[LinkedList]" ) {
    LinkedList<std::string> l;

    l.insert(1, "hi");
    l.insert(2, "hello");
    l.insert(3, "hey");
    l.getEntry(4);
}

TEST_CASE( "Swap", "[LinkedList]" ) {
    LinkedList<int> x, y;

    for (int i = 1; i < 3; i++) {
        x.insert(i, i);
        y.insert(i, i+2);
    }

    x.swap(x, y);

    x.printList();
    y.printList();
}