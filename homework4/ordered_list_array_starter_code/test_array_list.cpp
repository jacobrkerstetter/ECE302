#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "array_list.hpp"

//force class expansion
template class ArrayList<int>;

TEST_CASE( "Test", "[ArrayList]" ) {
  ArrayList<int> list;
}

TEST_CASE( "Insert", "[ArrayList]" ) {
  ArrayList<int> list;

  for (int i = 1; i < 20; i++)
    REQUIRE(list.insert(i,i));

  REQUIRE(!list.insert(-1,5));
  REQUIRE(list.getLength() == 19);
  REQUIRE(list.insert(20, 20));
  REQUIRE(list.getLength() == 20);
  REQUIRE(!list.insert(25, 25));
}

TEST_CASE( "Insert Into Taken Slot", "[ArrayList]" ) {
  ArrayList<int> list;

  for (int i = 1; i < 20; i++)
    REQUIRE(list.insert(i,i));

  REQUIRE(list.insert(1,25));
  REQUIRE(list.getEntry(1) == 25);
  REQUIRE(list.getEntry(2) == 1);
}

TEST_CASE( "Remove", "[ArrayList]" ) {
  ArrayList<int> list;

  for (int i = 1; i < 20; i++)
    REQUIRE(list.insert(i,i));

  REQUIRE(list.remove(1));
  REQUIRE(!list.remove(25));
  REQUIRE(!list.remove(-5));
  REQUIRE(list.getLength() == 18);
}

TEST_CASE( "Remove Middle", "[ArrayList]" ) {
  ArrayList<int> list;

  for (int i = 1; i < 20; i++)
    REQUIRE(list.insert(i,i));

  REQUIRE(list.remove(15));
}

TEST_CASE( "Clear", "[ArrayList]" ) {
  ArrayList<int> list;

  for (int i = 1; i < 20; i++)
    REQUIRE(list.insert(i,i));

  list.clear();

  REQUIRE(list.getLength() == 0);
  REQUIRE(list.isEmpty());
  REQUIRE(list.getEntry(1) == 0);
}

TEST_CASE( "get/set", "[ArrayList]" ) {
  ArrayList<int> list;

  for (int i = 1; i < 20; i++)
    REQUIRE(list.insert(i,i));

  REQUIRE(list.getEntry(15) == 15);
  list.setEntry(14, 25);
  REQUIRE(list.getEntry(14) == 25);
  REQUIRE(list.getEntry(50) == 0);
}

TEST_CASE( "Copy Constructor", "[ArrayList]" ) {
  ArrayList<int> list;

  list.insert(1,1);
  list.insert(2,2);

  ArrayList<int> l2(list);
  REQUIRE(l2.getEntry(1) == 1);
  REQUIRE(l2.getLength() == 2);
}

TEST_CASE( "= Operator", "[ArrayList]" ) {
  ArrayList<int> list, l2;

  list.insert(1,1);
  list.insert(2,2);
  list.insert(3,1);
  l2.insert(1, 5);
  l2.insert(1, 17);

  l2 = list;
  REQUIRE(l2.getEntry(1) == 1);
  REQUIRE(l2.getLength() == 3);
}