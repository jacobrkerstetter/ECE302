# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/parallels/302Github/ECE302/project5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/parallels/302Github/ECE302/project5

# Include any dependencies generated for this target.
include CMakeFiles/test_solver.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_solver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_solver.dir/flags.make

CMakeFiles/test_solver.dir/test_solver.cpp.o: CMakeFiles/test_solver.dir/flags.make
CMakeFiles/test_solver.dir/test_solver.cpp.o: test_solver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/302Github/ECE302/project5/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_solver.dir/test_solver.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_solver.dir/test_solver.cpp.o -c /home/parallels/302Github/ECE302/project5/test_solver.cpp

CMakeFiles/test_solver.dir/test_solver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_solver.dir/test_solver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/302Github/ECE302/project5/test_solver.cpp > CMakeFiles/test_solver.dir/test_solver.cpp.i

CMakeFiles/test_solver.dir/test_solver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_solver.dir/test_solver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/302Github/ECE302/project5/test_solver.cpp -o CMakeFiles/test_solver.dir/test_solver.cpp.s

CMakeFiles/test_solver.dir/puzzle.cpp.o: CMakeFiles/test_solver.dir/flags.make
CMakeFiles/test_solver.dir/puzzle.cpp.o: puzzle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/302Github/ECE302/project5/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test_solver.dir/puzzle.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_solver.dir/puzzle.cpp.o -c /home/parallels/302Github/ECE302/project5/puzzle.cpp

CMakeFiles/test_solver.dir/puzzle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_solver.dir/puzzle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/302Github/ECE302/project5/puzzle.cpp > CMakeFiles/test_solver.dir/puzzle.cpp.i

CMakeFiles/test_solver.dir/puzzle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_solver.dir/puzzle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/302Github/ECE302/project5/puzzle.cpp -o CMakeFiles/test_solver.dir/puzzle.cpp.s

CMakeFiles/test_solver.dir/puzzle_solver.cpp.o: CMakeFiles/test_solver.dir/flags.make
CMakeFiles/test_solver.dir/puzzle_solver.cpp.o: puzzle_solver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/302Github/ECE302/project5/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test_solver.dir/puzzle_solver.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_solver.dir/puzzle_solver.cpp.o -c /home/parallels/302Github/ECE302/project5/puzzle_solver.cpp

CMakeFiles/test_solver.dir/puzzle_solver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_solver.dir/puzzle_solver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/302Github/ECE302/project5/puzzle_solver.cpp > CMakeFiles/test_solver.dir/puzzle_solver.cpp.i

CMakeFiles/test_solver.dir/puzzle_solver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_solver.dir/puzzle_solver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/302Github/ECE302/project5/puzzle_solver.cpp -o CMakeFiles/test_solver.dir/puzzle_solver.cpp.s

# Object files for target test_solver
test_solver_OBJECTS = \
"CMakeFiles/test_solver.dir/test_solver.cpp.o" \
"CMakeFiles/test_solver.dir/puzzle.cpp.o" \
"CMakeFiles/test_solver.dir/puzzle_solver.cpp.o"

# External object files for target test_solver
test_solver_EXTERNAL_OBJECTS =

test_solver: CMakeFiles/test_solver.dir/test_solver.cpp.o
test_solver: CMakeFiles/test_solver.dir/puzzle.cpp.o
test_solver: CMakeFiles/test_solver.dir/puzzle_solver.cpp.o
test_solver: CMakeFiles/test_solver.dir/build.make
test_solver: CMakeFiles/test_solver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/parallels/302Github/ECE302/project5/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable test_solver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_solver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_solver.dir/build: test_solver

.PHONY : CMakeFiles/test_solver.dir/build

CMakeFiles/test_solver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_solver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_solver.dir/clean

CMakeFiles/test_solver.dir/depend:
	cd /home/parallels/302Github/ECE302/project5 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/parallels/302Github/ECE302/project5 /home/parallels/302Github/ECE302/project5 /home/parallels/302Github/ECE302/project5 /home/parallels/302Github/ECE302/project5 /home/parallels/302Github/ECE302/project5/CMakeFiles/test_solver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_solver.dir/depend
