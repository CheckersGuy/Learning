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
CMAKE_COMMAND = /snap/clion/114/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/114/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/robin/Learning/FileSystem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/robin/Learning/FileSystem/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/FileSystem.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FileSystem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FileSystem.dir/flags.make

CMakeFiles/FileSystem.dir/main.cpp.o: CMakeFiles/FileSystem.dir/flags.make
CMakeFiles/FileSystem.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robin/Learning/FileSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FileSystem.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FileSystem.dir/main.cpp.o -c /home/robin/Learning/FileSystem/main.cpp

CMakeFiles/FileSystem.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FileSystem.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robin/Learning/FileSystem/main.cpp > CMakeFiles/FileSystem.dir/main.cpp.i

CMakeFiles/FileSystem.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FileSystem.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robin/Learning/FileSystem/main.cpp -o CMakeFiles/FileSystem.dir/main.cpp.s

# Object files for target FileSystem
FileSystem_OBJECTS = \
"CMakeFiles/FileSystem.dir/main.cpp.o"

# External object files for target FileSystem
FileSystem_EXTERNAL_OBJECTS =

FileSystem: CMakeFiles/FileSystem.dir/main.cpp.o
FileSystem: CMakeFiles/FileSystem.dir/build.make
FileSystem: CMakeFiles/FileSystem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/robin/Learning/FileSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable FileSystem"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FileSystem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FileSystem.dir/build: FileSystem

.PHONY : CMakeFiles/FileSystem.dir/build

CMakeFiles/FileSystem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FileSystem.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FileSystem.dir/clean

CMakeFiles/FileSystem.dir/depend:
	cd /home/robin/Learning/FileSystem/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/robin/Learning/FileSystem /home/robin/Learning/FileSystem /home/robin/Learning/FileSystem/cmake-build-debug /home/robin/Learning/FileSystem/cmake-build-debug /home/robin/Learning/FileSystem/cmake-build-debug/CMakeFiles/FileSystem.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FileSystem.dir/depend

