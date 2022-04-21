#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>

#include "puzzle_solver.hpp"

TEST_CASE( "Test-0", "[PuzzleSolver]" ) {

  Puzzle puzzle1, puzzle2;
  REQUIRE(puzzle1.fromString("012345678"));
  REQUIRE(puzzle2.fromString("012345678"));
    
  {
    PuzzleSolver solver(puzzle1, puzzle2);
    bool found;
    std::size_t solution_cost;
    std::tie(found, solution_cost) = solver.search();
    
    REQUIRE(found);
    REQUIRE(solution_cost == 0);
  }

  { // symmetric case
    PuzzleSolver solver(puzzle2, puzzle1);
    bool found;
    std::size_t solution_cost;
    std::tie(found, solution_cost) = solver.search();
    
    REQUIRE(found);
    REQUIRE(solution_cost == 0);
  }
}

TEST_CASE( "Test-1", "[PuzzleSolver]" ) {

  Puzzle puzzle1, puzzle2;
  REQUIRE(puzzle1.fromString("012345678"));
  REQUIRE(puzzle2.fromString("012345687"));
    
  {
    PuzzleSolver solver(puzzle1, puzzle2);
    bool found;
    std::size_t solution_cost;
    std::tie(found, solution_cost) = solver.search();
    
    REQUIRE(found);
    REQUIRE(solution_cost == 1);
  }

  { // symmetric case
    PuzzleSolver solver(puzzle2, puzzle1);
    bool found;
    std::size_t solution_cost;
    std::tie(found, solution_cost) = solver.search();
    
    REQUIRE(found);
    REQUIRE(solution_cost == 1);
  }
}

TEST_CASE( "Test-2", "[PuzzleSolver]" ) {

  Puzzle puzzle1, puzzle2;
  REQUIRE(puzzle1.fromString("012345678"));
  REQUIRE(puzzle2.fromString("012345867"));
    
  {
    PuzzleSolver solver(puzzle1, puzzle2);
    bool found;
    std::size_t solution_cost;
    std::tie(found, solution_cost) = solver.search();
    
    REQUIRE(found);
    REQUIRE(solution_cost == 2);
  }

  { // symmetric case
    PuzzleSolver solver(puzzle2, puzzle1);
    bool found;
    std::size_t solution_cost;
    std::tie(found, solution_cost) = solver.search();
    
    REQUIRE(found);
    REQUIRE(solution_cost == 2);
  }
}

TEST_CASE( "Test-3", "[PuzzleSolver]" ) {

  Puzzle puzzle1, puzzle2;
  REQUIRE(puzzle1.fromString("071832654"));
  REQUIRE(puzzle2.fromString("012345678"));
    
  {
    PuzzleSolver solver(puzzle1, puzzle2);
    bool found;
    std::size_t solution_cost;
    std::tie(found, solution_cost) = solver.search();
    
    REQUIRE(found);
  }

  { // symmetric case
    PuzzleSolver solver(puzzle2, puzzle1);
    bool found;
    std::size_t solution_cost;
    std::tie(found, solution_cost) = solver.search();
    
    REQUIRE(found);
  }
}

TEST_CASE( "Test-4", "[PuzzleSolver]" ) {

  Puzzle puzzle1, puzzle2;
  REQUIRE(puzzle1.fromString("012458673"));
  REQUIRE(puzzle2.fromString("012475863"));
    
  {
    PuzzleSolver solver(puzzle1, puzzle2);
    bool found;
    std::size_t solution_cost;
    std::tie(found, solution_cost) = solver.search();
    
    REQUIRE(found);
  }

  { // symmetric case
    PuzzleSolver solver(puzzle2, puzzle1);
    bool found;
    std::size_t solution_cost;
    std::tie(found, solution_cost) = solver.search();
    
    REQUIRE(found);
  }
}

TEST_CASE( "Test-5", "[PuzzleSolver]" ) {

  Puzzle puzzle1, puzzle2;
  REQUIRE(puzzle1.fromString("023784615"));
  REQUIRE(puzzle2.fromString("012783654"));
    
  {
    PuzzleSolver solver(puzzle1, puzzle2);
    bool found;
    std::size_t solution_cost;
    std::tie(found, solution_cost) = solver.search();
    
    REQUIRE(found);
  }

  { // symmetric case
    PuzzleSolver solver(puzzle2, puzzle1);
    bool found;
    std::size_t solution_cost;
    std::tie(found, solution_cost) = solver.search();
    
    REQUIRE(found);
  }
}

TEST_CASE( "Test-6", "[PuzzleSolver]" ) {

  Puzzle puzzle1, puzzle2;
  REQUIRE(puzzle1.fromString("023751864"));
  REQUIRE(puzzle2.fromString("012783654"));
    
  {
    PuzzleSolver solver(puzzle1, puzzle2);
    bool found;
    std::size_t solution_cost;
    std::tie(found, solution_cost) = solver.search();
    
    REQUIRE(found);
  }

  { // symmetric case
    PuzzleSolver solver(puzzle2, puzzle1);
    bool found;
    std::size_t solution_cost;
    std::tie(found, solution_cost) = solver.search();
    
    REQUIRE(found);
  }
}