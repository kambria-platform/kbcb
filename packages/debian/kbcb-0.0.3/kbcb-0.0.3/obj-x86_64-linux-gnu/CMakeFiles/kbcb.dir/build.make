# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_SOURCE_DIR = /home/tups/Desktop/kbcb/packages/debian/kbcb-0.0.3/kbcb-0.0.3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tups/Desktop/kbcb/packages/debian/kbcb-0.0.3/kbcb-0.0.3/obj-x86_64-linux-gnu

# Include any dependencies generated for this target.
include CMakeFiles/kbcb.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/kbcb.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kbcb.dir/flags.make

CMakeFiles/kbcb.dir/src/kbcb.cpp.o: CMakeFiles/kbcb.dir/flags.make
CMakeFiles/kbcb.dir/src/kbcb.cpp.o: ../src/kbcb.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tups/Desktop/kbcb/packages/debian/kbcb-0.0.3/kbcb-0.0.3/obj-x86_64-linux-gnu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/kbcb.dir/src/kbcb.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/kbcb.dir/src/kbcb.cpp.o -c /home/tups/Desktop/kbcb/packages/debian/kbcb-0.0.3/kbcb-0.0.3/src/kbcb.cpp

CMakeFiles/kbcb.dir/src/kbcb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kbcb.dir/src/kbcb.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tups/Desktop/kbcb/packages/debian/kbcb-0.0.3/kbcb-0.0.3/src/kbcb.cpp > CMakeFiles/kbcb.dir/src/kbcb.cpp.i

CMakeFiles/kbcb.dir/src/kbcb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kbcb.dir/src/kbcb.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tups/Desktop/kbcb/packages/debian/kbcb-0.0.3/kbcb-0.0.3/src/kbcb.cpp -o CMakeFiles/kbcb.dir/src/kbcb.cpp.s

CMakeFiles/kbcb.dir/src/kbcb.cpp.o.requires:

.PHONY : CMakeFiles/kbcb.dir/src/kbcb.cpp.o.requires

CMakeFiles/kbcb.dir/src/kbcb.cpp.o.provides: CMakeFiles/kbcb.dir/src/kbcb.cpp.o.requires
	$(MAKE) -f CMakeFiles/kbcb.dir/build.make CMakeFiles/kbcb.dir/src/kbcb.cpp.o.provides.build
.PHONY : CMakeFiles/kbcb.dir/src/kbcb.cpp.o.provides

CMakeFiles/kbcb.dir/src/kbcb.cpp.o.provides.build: CMakeFiles/kbcb.dir/src/kbcb.cpp.o


# Object files for target kbcb
kbcb_OBJECTS = \
"CMakeFiles/kbcb.dir/src/kbcb.cpp.o"

# External object files for target kbcb
kbcb_EXTERNAL_OBJECTS =

kbcb: CMakeFiles/kbcb.dir/src/kbcb.cpp.o
kbcb: CMakeFiles/kbcb.dir/build.make
kbcb: libkbcb.0.0.3.a
kbcb: CMakeFiles/kbcb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tups/Desktop/kbcb/packages/debian/kbcb-0.0.3/kbcb-0.0.3/obj-x86_64-linux-gnu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable kbcb"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kbcb.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kbcb.dir/build: kbcb

.PHONY : CMakeFiles/kbcb.dir/build

CMakeFiles/kbcb.dir/requires: CMakeFiles/kbcb.dir/src/kbcb.cpp.o.requires

.PHONY : CMakeFiles/kbcb.dir/requires

CMakeFiles/kbcb.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/kbcb.dir/cmake_clean.cmake
.PHONY : CMakeFiles/kbcb.dir/clean

CMakeFiles/kbcb.dir/depend:
	cd /home/tups/Desktop/kbcb/packages/debian/kbcb-0.0.3/kbcb-0.0.3/obj-x86_64-linux-gnu && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tups/Desktop/kbcb/packages/debian/kbcb-0.0.3/kbcb-0.0.3 /home/tups/Desktop/kbcb/packages/debian/kbcb-0.0.3/kbcb-0.0.3 /home/tups/Desktop/kbcb/packages/debian/kbcb-0.0.3/kbcb-0.0.3/obj-x86_64-linux-gnu /home/tups/Desktop/kbcb/packages/debian/kbcb-0.0.3/kbcb-0.0.3/obj-x86_64-linux-gnu /home/tups/Desktop/kbcb/packages/debian/kbcb-0.0.3/kbcb-0.0.3/obj-x86_64-linux-gnu/CMakeFiles/kbcb.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/kbcb.dir/depend

