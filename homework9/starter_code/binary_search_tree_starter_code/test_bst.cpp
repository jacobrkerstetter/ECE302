#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "binary_search_tree.h"

typedef BinarySearchTree<int, int> TreeType;

TEST_CASE("Test Construction", "[construction]") {
    TreeType bst1;

    REQUIRE(bst1.isEmpty());
}

TEST_CASE("Test Insert", "[insert]") {
    TreeType bst1;

    bst1.insert(10, 10);
    REQUIRE(!bst1.isEmpty());
}

TEST_CASE("Test Duplicate Insert", "[duplicate insert]") {
    TreeType bst1;
    
    bst1.insert(12, 12);
    REQUIRE(!bst1.insert(12, 12));
}

TEST_CASE("Test Retrieve", "[retrieve]") {
    TreeType bst1;

    bst1.insert(10, 10);
    bst1.insert(5, 5);
    bst1.insert(15, 15);
    bst1.insert(12, 12);
    bst1.insert(18, 18);

    int item;
    REQUIRE(bst1.retrieve(18, item));
    REQUIRE(bst1.retrieve(12, item));
    REQUIRE(bst1.retrieve(15, item));
    REQUIRE(bst1.retrieve(5, item));
    REQUIRE(bst1.retrieve(10, item));
}

TEST_CASE("Test Remove", "[remove]") {
    TreeType bst1;

    bst1.insert(10, 10);
    bst1.insert(5, 5);
    bst1.insert(15, 15);
    bst1.insert(12, 12);
    bst1.insert(18, 18);

    int item;

    bst1.remove(12);
    REQUIRE(!bst1.retrieve(12, item));

    bst1.remove(18);
    REQUIRE(!bst1.retrieve(18, item));

    bst1.remove(5);
    REQUIRE(!bst1.retrieve(5, item));

    bst1.remove(10);
    REQUIRE(!bst1.retrieve(10, item));

    bst1.remove(15);
    REQUIRE(!bst1.retrieve(15, item));

    REQUIRE(bst1.isEmpty());
}

TEST_CASE("Test Remove 2", "[remove]") {
    TreeType bst1;

    bst1.insert(1, 1);
    bst1.insert(2, 2);
    bst1.insert(3, 3);
    bst1.insert(4, 4);
    bst1.insert(5, 5);

    int item;

    bst1.remove(1);
    REQUIRE(!bst1.retrieve(1, item));

    bst1.remove(5);
    REQUIRE(!bst1.retrieve(5, item));

    REQUIRE_FALSE(bst1.remove(15));

    bst1.remove(4);
    REQUIRE(!bst1.retrieve(4, item));

    bst1.remove(3);
    REQUIRE(!bst1.retrieve(3, item));

    bst1.remove(2);
    REQUIRE(!bst1.retrieve(2, item));

    REQUIRE(bst1.isEmpty());
}

TEST_CASE("Test Copy Assign", "[copy assign]") {
    TreeType bst1;

    bst1.insert(50, 50);
    bst1.insert(0, 0);
    bst1.insert(100, 100);
    bst1.insert(25, 25);
    bst1.insert(75, 75);

    TreeType bst2;

    bst2 = bst1;

    REQUIRE(!bst2.isEmpty());

    int item;
    REQUIRE(bst2.retrieve(100, item));
    REQUIRE(bst2.retrieve(75, item));
    REQUIRE(bst2.retrieve(50, item));
    REQUIRE(bst2.retrieve(25, item));
    REQUIRE(!bst2.retrieve(51, item));
    
}

TEST_CASE("Test TreeSort", "[treesort]") {
    TreeType bst;
    int arr[] = {7, 16, 2, 3, 45, 31, 24, 11};
    bst.treeSort(arr, 8);

    REQUIRE(arr[0] == 2);
    REQUIRE(arr[1] == 3);
    REQUIRE(arr[2] == 7);
    REQUIRE(arr[3] == 11);
    REQUIRE(arr[4] == 16);
    REQUIRE(arr[5] == 24);
    REQUIRE(arr[6] == 31);
    REQUIRE(arr[7] == 45);
}

TEST_CASE("Test TreeSort Empty", "[treesort empty]") {
    TreeType bst;
    int arr[0];

    bst.treeSort(arr, 0);
}

TEST_CASE("Test TreeSort Dupes", "[treesort dupe]") {
    TreeType bst;
    int arr[5] = {1, 10, 5, 5, 7};

    bst.treeSort(arr, 0);

    REQUIRE(arr[0] == 1);
    REQUIRE(arr[1] == 10);
    REQUIRE(arr[2] == 5);
    REQUIRE(arr[3] == 5);
    REQUIRE(arr[4] == 7);
}