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
CMAKE_COMMAND = /home/robin/Desktop/clion-2018.1.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/robin/Desktop/clion-2018.1.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/robin/Learning/FixPoint

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/robin/Learning/FixPoint/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/FixPoint.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FixPoint.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FixPoint.dir/flags.make

CMakeFiles/FixPoint.dir/main.cpp.o: CMakeFiles/FixPoint.dir/flags.make
CMakeFiles/FixPoint.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robin/Learning/FixPoint/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FixPoint.dir/main.cpp.o"
	/usr/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FixPoint.dir/main.cpp.o -c /home/robin/Learning/FixPoint/main.cpp

CMakeFiles/FixPoint.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FixPoint.dir/main.cpp.i"
	/usr/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robin/Learning/FixPoint/main.cpp > CMakeFiles/FixPoint.dir/main.cpp.i

CMakeFiles/FixPoint.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FixPoint.dir/main.cpp.s"
	/usr/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robin/Learning/FixPoint/main.cpp -o CMakeFiles/FixPoint.dir/main.cpp.s

CMakeFiles/FixPoint.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/FixPoint.dir/main.cpp.o.requires

CMakeFiles/FixPoint.dir/main.cpp.o.provides: CMakeFiles/FixPoint.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/FixPoint.dir/build.make CMakeFiles/FixPoint.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/FixPoint.dir/main.cpp.o.provides

CMakeFiles/FixPoint.dir/main.cpp.o.provides.build: CMakeFiles/FixPoint.dir/main.cpp.o


# Object files for target FixPoint
FixPoint_OBJECTS = \
"CMakeFiles/FixPoint.dir/main.cpp.o"

# External object files for target FixPoint
FixPoint_EXTERNAL_OBJECTS =

FixPoint: CMakeFiles/FixPoint.dir/main.cpp.o
FixPoint: CMakeFiles/FixPoint.dir/build.make
FixPoint: CMakeFiles/FixPoint.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/robin/Learning/FixPoint/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable FixPoint"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FixPoint.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FixPoint.dir/build: FixPoint

.PHONY : CMakeFiles/FixPoint.dir/build

CMakeFiles/FixPoint.dir/requires: CMakeFiles/FixPoint.dir/main.cpp.o.requires

.PHONY : CMakeFiles/FixPoint.dir/requires

CMakeFiles/FixPoint.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FixPoint.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FixPoint.dir/clean

CMakeFiles/FixPoint.dir/depend:
	cd /home/robin/Learning/FixPoint/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/robin/Learning/FixPoint /home/robin/Learning/FixPoint /home/robin/Learning/FixPoint/cmake-build-debug /home/robin/Learning/FixPoint/cmake-build-debug /home/robin/Learning/FixPoint/cmake-build-debug/CMakeFiles/FixPoint.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FixPoint.dir/depend

