# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/ari/development/ELEN2004/ELEN2004_project_2014/gtest-1.7.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ari/development/ELEN2004/ELEN2004_project_2014/gtest-1.7.0

# Include any dependencies generated for this target.
include CMakeFiles/sample2_unittest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sample2_unittest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sample2_unittest.dir/flags.make

CMakeFiles/sample2_unittest.dir/samples/sample2_unittest.cc.o: CMakeFiles/sample2_unittest.dir/flags.make
CMakeFiles/sample2_unittest.dir/samples/sample2_unittest.cc.o: samples/sample2_unittest.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ari/development/ELEN2004/ELEN2004_project_2014/gtest-1.7.0/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/sample2_unittest.dir/samples/sample2_unittest.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)  -Wall -Wshadow -DGTEST_HAS_PTHREAD=1 -fexceptions -o CMakeFiles/sample2_unittest.dir/samples/sample2_unittest.cc.o -c /home/ari/development/ELEN2004/ELEN2004_project_2014/gtest-1.7.0/samples/sample2_unittest.cc

CMakeFiles/sample2_unittest.dir/samples/sample2_unittest.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample2_unittest.dir/samples/sample2_unittest.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -Wall -Wshadow -DGTEST_HAS_PTHREAD=1 -fexceptions -E /home/ari/development/ELEN2004/ELEN2004_project_2014/gtest-1.7.0/samples/sample2_unittest.cc > CMakeFiles/sample2_unittest.dir/samples/sample2_unittest.cc.i

CMakeFiles/sample2_unittest.dir/samples/sample2_unittest.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample2_unittest.dir/samples/sample2_unittest.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -Wall -Wshadow -DGTEST_HAS_PTHREAD=1 -fexceptions -S /home/ari/development/ELEN2004/ELEN2004_project_2014/gtest-1.7.0/samples/sample2_unittest.cc -o CMakeFiles/sample2_unittest.dir/samples/sample2_unittest.cc.s

CMakeFiles/sample2_unittest.dir/samples/sample2_unittest.cc.o.requires:
.PHONY : CMakeFiles/sample2_unittest.dir/samples/sample2_unittest.cc.o.requires

CMakeFiles/sample2_unittest.dir/samples/sample2_unittest.cc.o.provides: CMakeFiles/sample2_unittest.dir/samples/sample2_unittest.cc.o.requires
	$(MAKE) -f CMakeFiles/sample2_unittest.dir/build.make CMakeFiles/sample2_unittest.dir/samples/sample2_unittest.cc.o.provides.build
.PHONY : CMakeFiles/sample2_unittest.dir/samples/sample2_unittest.cc.o.provides

CMakeFiles/sample2_unittest.dir/samples/sample2_unittest.cc.o.provides.build: CMakeFiles/sample2_unittest.dir/samples/sample2_unittest.cc.o

CMakeFiles/sample2_unittest.dir/samples/sample2.cc.o: CMakeFiles/sample2_unittest.dir/flags.make
CMakeFiles/sample2_unittest.dir/samples/sample2.cc.o: samples/sample2.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ari/development/ELEN2004/ELEN2004_project_2014/gtest-1.7.0/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/sample2_unittest.dir/samples/sample2.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)  -Wall -Wshadow -DGTEST_HAS_PTHREAD=1 -fexceptions -o CMakeFiles/sample2_unittest.dir/samples/sample2.cc.o -c /home/ari/development/ELEN2004/ELEN2004_project_2014/gtest-1.7.0/samples/sample2.cc

CMakeFiles/sample2_unittest.dir/samples/sample2.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample2_unittest.dir/samples/sample2.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -Wall -Wshadow -DGTEST_HAS_PTHREAD=1 -fexceptions -E /home/ari/development/ELEN2004/ELEN2004_project_2014/gtest-1.7.0/samples/sample2.cc > CMakeFiles/sample2_unittest.dir/samples/sample2.cc.i

CMakeFiles/sample2_unittest.dir/samples/sample2.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample2_unittest.dir/samples/sample2.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -Wall -Wshadow -DGTEST_HAS_PTHREAD=1 -fexceptions -S /home/ari/development/ELEN2004/ELEN2004_project_2014/gtest-1.7.0/samples/sample2.cc -o CMakeFiles/sample2_unittest.dir/samples/sample2.cc.s

CMakeFiles/sample2_unittest.dir/samples/sample2.cc.o.requires:
.PHONY : CMakeFiles/sample2_unittest.dir/samples/sample2.cc.o.requires

CMakeFiles/sample2_unittest.dir/samples/sample2.cc.o.provides: CMakeFiles/sample2_unittest.dir/samples/sample2.cc.o.requires
	$(MAKE) -f CMakeFiles/sample2_unittest.dir/build.make CMakeFiles/sample2_unittest.dir/samples/sample2.cc.o.provides.build
.PHONY : CMakeFiles/sample2_unittest.dir/samples/sample2.cc.o.provides

CMakeFiles/sample2_unittest.dir/samples/sample2.cc.o.provides.build: CMakeFiles/sample2_unittest.dir/samples/sample2.cc.o

# Object files for target sample2_unittest
sample2_unittest_OBJECTS = \
"CMakeFiles/sample2_unittest.dir/samples/sample2_unittest.cc.o" \
"CMakeFiles/sample2_unittest.dir/samples/sample2.cc.o"

# External object files for target sample2_unittest
sample2_unittest_EXTERNAL_OBJECTS =

sample2_unittest: CMakeFiles/sample2_unittest.dir/samples/sample2_unittest.cc.o
sample2_unittest: CMakeFiles/sample2_unittest.dir/samples/sample2.cc.o
sample2_unittest: CMakeFiles/sample2_unittest.dir/build.make
sample2_unittest: libgtest_main.a
sample2_unittest: libgtest.a
sample2_unittest: CMakeFiles/sample2_unittest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable sample2_unittest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sample2_unittest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sample2_unittest.dir/build: sample2_unittest
.PHONY : CMakeFiles/sample2_unittest.dir/build

CMakeFiles/sample2_unittest.dir/requires: CMakeFiles/sample2_unittest.dir/samples/sample2_unittest.cc.o.requires
CMakeFiles/sample2_unittest.dir/requires: CMakeFiles/sample2_unittest.dir/samples/sample2.cc.o.requires
.PHONY : CMakeFiles/sample2_unittest.dir/requires

CMakeFiles/sample2_unittest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sample2_unittest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sample2_unittest.dir/clean

CMakeFiles/sample2_unittest.dir/depend:
	cd /home/ari/development/ELEN2004/ELEN2004_project_2014/gtest-1.7.0 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ari/development/ELEN2004/ELEN2004_project_2014/gtest-1.7.0 /home/ari/development/ELEN2004/ELEN2004_project_2014/gtest-1.7.0 /home/ari/development/ELEN2004/ELEN2004_project_2014/gtest-1.7.0 /home/ari/development/ELEN2004/ELEN2004_project_2014/gtest-1.7.0 /home/ari/development/ELEN2004/ELEN2004_project_2014/gtest-1.7.0/CMakeFiles/sample2_unittest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sample2_unittest.dir/depend

