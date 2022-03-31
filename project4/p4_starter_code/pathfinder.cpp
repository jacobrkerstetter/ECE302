#include "deque.hpp"
#include "lib/image.h"
#include <utility>
#include <iostream>

int main(int argc, char *argv[])
{
  // check for command line args
  if (argc != 3) {
    std::cerr << "Error: Pathfinder"
              << "<first_input_filename> <second_output_filename>\n"
              << std::endl;
    return EXIT_FAILURE;
  }

  // declare image object for maze and read it with image class (catching errors in reading)
  Image<Pixel> maze;
  try {
    maze = readFromFile(argv[1]);
  }
  catch (std::exception &ex) {
    std::cerr << "Error: Failed to open image" << std::endl;
    return EXIT_FAILURE;
  }

  int height = maze.height();
  int width = maze.width();
  int redCount = 0;
  bool solutionFound = false;

  // find where the red square is
  int startx, starty;
  for (int col = 0; col < height; col++)
    for (int row = 0; row < width; row++)  {
      if (maze(col,row) != RED && maze(col,row) != WHITE && maze(col,row) != BLACK) {
        std::cerr << "Error: Invalid color present" << std::endl;
        return EXIT_FAILURE;
      }
      else if (maze(col, row) == RED) {
        startx = col;
        starty = row;
        ++redCount;
      }
    }
    
  if (redCount > 1) {
    std::cerr << "Error: More than one start point" << std::endl;
    return EXIT_FAILURE;
  }

  // queue for the frontier and add initial square
  Deque<std::pair<int, int>> frontier;
  std::pair<int,int> s(startx, starty);
  frontier.pushBack(s);

  // empty set of (false) explored squares and location to search
  bool explored[width][height];
  std::pair<int, int> location;
  int x, y;

  while (!frontier.isEmpty()) {
    // pop next location to explore
    location = frontier.front();
    x = location.first;
    y = location.second;
    frontier.popFront();

    // mark location as explored
    explored[x][y] = 1;

    // loop through non-explored neighbors to location
    // check for edge of maze
    if (maze(x,y) == WHITE && (x == 0 || x == width-1 || y == 0 || y == height-1)) {
      solutionFound = true;
      maze(x,y) = GREEN;
      break;
    }
    // case 1: check left
    if (maze(x-1,y) == WHITE && !explored[x-1][y]) {
      frontier.pushBack(std::pair<int,int>(x-1,y));
      explored[x-1][y] = 1;
    }
    // case 2: check up
    if (maze(x,y+1) == WHITE && !explored[x][y+1]) {
      frontier.pushBack(std::pair<int,int>(x,y+1));
      explored[x][y+1] = 1;
    }
    // case 3: check right
    if (maze(x+1,y) == WHITE && !explored[x+1][y]) {
      frontier.pushBack(std::pair<int,int>(x+1,y));
      explored[x+1][y] = 1;
    }
    // case 4: check down
    if (maze(x,y-1) == WHITE && !explored[x][y-1]) {
      frontier.pushBack(std::pair<int,int>(x,y-1));
      explored[x][y-1] = 1;
    }
  }

  // save solution to file
  writeToFile(maze, argv[2]);

  // if solution found, check with solution image
  if (solutionFound)
    std::cout << "Solution Found" << std::endl;
  else
    std::cout << "No Solution Found" << std::endl;
  
  return EXIT_SUCCESS;
}