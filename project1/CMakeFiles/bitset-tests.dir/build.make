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
CMAKE_SOURCE_DIR = /home/parallels/302Github/ECE302/project1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/parallels/302Github/ECE302/project1

# Include any dependencies generated for this target.
include CMakeFiles/bitset-tests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bitset-tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bitset-tests.dir/flags.make

CMakeFiles/bitset-tests.dir/bitset_test.cpp.o: CMakeFiles/bitset-tests.dir/flags.make
CMakeFiles/bitset-tests.dir/bitset_test.cpp.o: bitset_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/302Github/ECE302/project1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bitset-tests.dir/bitset_test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bitset-tests.dir/bitset_test.cpp.o -c /home/parallels/302Github/ECE302/project1/bitset_test.cpp

CMakeFiles/bitset-tests.dir/bitset_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bitset-tests.dir/bitset_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/302Github/ECE302/project1/bitset_test.cpp > CMakeFiles/bitset-tests.dir/bitset_test.cpp.i

CMakeFiles/bitset-tests.dir/bitset_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bitset-tests.dir/bitset_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/302Github/ECE302/project1/bitset_test.cpp -o CMakeFiles/bitset-tests.dir/bitset_test.cpp.s

CMakeFiles/bitset-tests.dir/bitset.cpp.o: CMakeFiles/bitset-tests.dir/flags.make
CMakeFiles/bitset-tests.dir/bitset.cpp.o: bitset.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/302Github/ECE302/project1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/bitset-tests.dir/bitset.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bitset-tests.dir/bitset.cpp.o -c /home/parallels/302Github/ECE302/project1/bitset.cpp

CMakeFiles/bitset-tests.dir/bitset.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bitset-tests.dir/bitset.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/302Github/ECE302/project1/bitset.cpp > CMakeFiles/bitset-tests.dir/bitset.cpp.i

CMakeFiles/bitset-tests.dir/bitset.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bitset-tests.dir/bitset.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/302Github/ECE302/project1/bitset.cpp -o CMakeFiles/bitset-tests.dir/bitset.cpp.s

# Object files for target bitset-tests
bitset__tests_OBJECTS = \
"CMakeFiles/bitset-tests.dir/bitset_test.cpp.o" \
"CMakeFiles/bitset-tests.dir/bitset.cpp.o"

# External object files for target bitset-tests
bitset__tests_EXTERNAL_OBJECTS =

bitset-tests: CMakeFiles/bitset-tests.dir/bitset_test.cpp.o
bitset-tests: CMakeFiles/bitset-tests.dir/bitset.cpp.o
bitset-tests: CMakeFiles/bitset-tests.dir/build.make
bitset-tests: CMakeFiles/bitset-tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/parallels/302Github/ECE302/project1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable bitset-tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bitset-tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bitset-tests.dir/build: bitset-tests

.PHONY : CMakeFiles/bitset-tests.dir/build

CMakeFiles/bitset-tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bitset-tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bitset-tests.dir/clean

CMakeFiles/bitset-tests.dir/depend:
	cd /home/parallels/302Github/ECE302/project1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/parallels/302Github/ECE302/project1 /home/parallels/302Github/ECE302/project1 /home/parallels/302Github/ECE302/project1 /home/parallels/302Github/ECE302/project1 /home/parallels/302Github/ECE302/project1/CMakeFiles/bitset-tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bitset-tests.dir/depend

