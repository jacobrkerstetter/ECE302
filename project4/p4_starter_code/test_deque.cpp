#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "deque.hpp"
#include "linked_list.hpp"

TEST_CASE( "Linked List =Operator", "[LL]" ) {
    LinkedList<int> LL;
    LL.insert(1,1);
    LL.insert(2,2);
    LL.insert(3,3);

    REQUIRE(LL.getLength() == 3);
    
    LinkedList<int> LL2 = LL;
    REQUIRE(LL2.getEntry(3) == 3);
    LL2.remove(3);
    REQUIRE(LL2.getEntry(2) == 2);
    REQUIRE(LL.getEntry(3) == 3);
}

TEST_CASE ( "Linked List Copy Constructor", "[LL]" ) {
    LinkedList<int> LL;
    LL.insert(1,1);
    LL.insert(2,2);
    LL.insert(3,3);

    REQUIRE(LL.getLength() == 3);
    
    LinkedList<int> LL2(LL);
    REQUIRE(LL2.getEntry(3) == 3);
    LL2.remove(3);
    REQUIRE(LL2.getEntry(2) == 2);
    REQUIRE(LL.getEntry(3) == 3);
}

TEST_CASE( "Test 1", "[deque]" ) {
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

TEST_CASE( "Test 2", "[deque]" ) {
    Deque<int> d;
    d.pushBack(1);
    d.pushBack(2);
    d.pushBack(3);
    REQUIRE(d.front() == 1);
    d.popFront();
    REQUIRE(d.front() == 2);
    d.popFront();
    REQUIRE(d.front() == 3);
    d.popFront();
    REQUIRE(d.isEmpty());
}

TEST_CASE( "Test 3", "[deque]" ) {
    Deque<int> d;
    d.pushBack(1);
    d.pushBack(2);
    d.pushBack(3);
    REQUIRE(d.back() == 3);
    d.popBack();
    REQUIRE(d.back() == 2);
    d.popBack();
    REQUIRE(d.back() == 1);
    d.popBack();
    REQUIRE(d.isEmpty());
}

TEST_CASE( "Test 4", "[deque]" ) {
    Deque<int> d;
    d.pushFront(1);
    d.pushFront(2);
    d.pushFront(3);

    Deque<int> d2(d);
    REQUIRE(d2.front() == 3);
    d2.popFront();
    REQUIRE(d2.front() == 2);
    d2.popFront();
    REQUIRE(d2.front() == 1);
    d2.popFront();
    REQUIRE(d2.isEmpty());
    REQUIRE_FALSE(d.isEmpty());
}

TEST_CASE( "Test 5", "[deque]" ) {
    Deque<int> d;
    d.pushFront(1);
    d.pushFront(2);
    d.pushFront(3);

    Deque<int> d2;
    d2.pushFront(5);
    d2.pushFront(3);
    REQUIRE(d2.front() == 3);

    d2 = d;
    REQUIRE(d.back() == 1);
    REQUIRE(d2.back() == 1);
    d2.popBack();
    REQUIRE(d2.back() == 2);
    REQUIRE(d.back() == 1);
}