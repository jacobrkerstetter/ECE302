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

  // declare image object for maze and read it with image class
  Image<Pixel> maze = readFromFile(argv[1]);
  int height = maze.height();
  int width = maze.width();
  bool solutionFound = false;

  // find where the red square is
  int startx, starty;
  for (int col = 0; col < height; col++)
    for (int row = 0; row < width; row++) 
      if (maze(col, row) == RED) {
        startx = col;
        starty = row;
        break;
      }

  // queue for the frontier and add initial square
  Deque<std::pair<int, int>> frontier;
  std::pair<int,int> s(startx, starty);
  frontier.pushBack(s);

  // empty set of (false) explored squares and location to search
  bool explored[width][height];
  std::pair<int, int> location;
  int x, y;

  while (true) {
    // no solution was found
    if (frontier.isEmpty()) {
      std::cout << "No Solution Found" << std::endl;
      writeToFile(maze, argv[2]);
      return EXIT_SUCCESS;
    }

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
  if (solutionFound) {
    try {
      Image<Pixel> solution = readFromFile(argv[2]);

      // check sizes of images align
      if (maze.width() != solution.width() || maze.height() != solution.height()) {
        std::cerr << "Image Sizes Differ";
        return EXIT_FAILURE;
      }
      
      // check that images are equal
      for (int row = 0; row < width; row++)
        for (int col = 0; col < height; col++)
          if (maze(col,row) != solution(col,row)) {
            std::cerr << "Image Contents Differ";
            return EXIT_FAILURE;
          }

      std::cout << "Solution Found" << std::endl;
      return EXIT_SUCCESS;
    }
    catch (std::exception &ex) {
      std::cerr << ex.what() << std::endl;
      return EXIT_FAILURE;
    }
  }
  
  return EXIT_SUCCESS;
}