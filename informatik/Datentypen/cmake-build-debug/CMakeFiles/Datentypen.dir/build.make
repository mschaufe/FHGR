# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ms/Desktop/Informatik/Datentypen

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ms/Desktop/Informatik/Datentypen/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Datentypen.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Datentypen.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Datentypen.dir/flags.make

CMakeFiles/Datentypen.dir/main.c.o: CMakeFiles/Datentypen.dir/flags.make
CMakeFiles/Datentypen.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ms/Desktop/Informatik/Datentypen/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Datentypen.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Datentypen.dir/main.c.o   -c /Users/ms/Desktop/Informatik/Datentypen/main.c

CMakeFiles/Datentypen.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Datentypen.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ms/Desktop/Informatik/Datentypen/main.c > CMakeFiles/Datentypen.dir/main.c.i

CMakeFiles/Datentypen.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Datentypen.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ms/Desktop/Informatik/Datentypen/main.c -o CMakeFiles/Datentypen.dir/main.c.s

# Object files for target Datentypen
Datentypen_OBJECTS = \
"CMakeFiles/Datentypen.dir/main.c.o"

# External object files for target Datentypen
Datentypen_EXTERNAL_OBJECTS =

Datentypen: CMakeFiles/Datentypen.dir/main.c.o
Datentypen: CMakeFiles/Datentypen.dir/build.make
Datentypen: CMakeFiles/Datentypen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ms/Desktop/Informatik/Datentypen/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Datentypen"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Datentypen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Datentypen.dir/build: Datentypen

.PHONY : CMakeFiles/Datentypen.dir/build

CMakeFiles/Datentypen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Datentypen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Datentypen.dir/clean

CMakeFiles/Datentypen.dir/depend:
	cd /Users/ms/Desktop/Informatik/Datentypen/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ms/Desktop/Informatik/Datentypen /Users/ms/Desktop/Informatik/Datentypen /Users/ms/Desktop/Informatik/Datentypen/cmake-build-debug /Users/ms/Desktop/Informatik/Datentypen/cmake-build-debug /Users/ms/Desktop/Informatik/Datentypen/cmake-build-debug/CMakeFiles/Datentypen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Datentypen.dir/depend

