# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /opt/clion-2016.3.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2016.3.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/salimcherifi/ClionProjects/SystemeTP4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/salimcherifi/ClionProjects/SystemeTP4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SystemeTP4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SystemeTP4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SystemeTP4.dir/flags.make

CMakeFiles/SystemeTP4.dir/ex11.c.o: CMakeFiles/SystemeTP4.dir/flags.make
CMakeFiles/SystemeTP4.dir/ex11.c.o: ../ex11.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/salimcherifi/ClionProjects/SystemeTP4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SystemeTP4.dir/ex11.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SystemeTP4.dir/ex11.c.o   -c /home/salimcherifi/ClionProjects/SystemeTP4/ex11.c

CMakeFiles/SystemeTP4.dir/ex11.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SystemeTP4.dir/ex11.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/salimcherifi/ClionProjects/SystemeTP4/ex11.c > CMakeFiles/SystemeTP4.dir/ex11.c.i

CMakeFiles/SystemeTP4.dir/ex11.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SystemeTP4.dir/ex11.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/salimcherifi/ClionProjects/SystemeTP4/ex11.c -o CMakeFiles/SystemeTP4.dir/ex11.c.s

CMakeFiles/SystemeTP4.dir/ex11.c.o.requires:

.PHONY : CMakeFiles/SystemeTP4.dir/ex11.c.o.requires

CMakeFiles/SystemeTP4.dir/ex11.c.o.provides: CMakeFiles/SystemeTP4.dir/ex11.c.o.requires
	$(MAKE) -f CMakeFiles/SystemeTP4.dir/build.make CMakeFiles/SystemeTP4.dir/ex11.c.o.provides.build
.PHONY : CMakeFiles/SystemeTP4.dir/ex11.c.o.provides

CMakeFiles/SystemeTP4.dir/ex11.c.o.provides.build: CMakeFiles/SystemeTP4.dir/ex11.c.o


# Object files for target SystemeTP4
SystemeTP4_OBJECTS = \
"CMakeFiles/SystemeTP4.dir/ex11.c.o"

# External object files for target SystemeTP4
SystemeTP4_EXTERNAL_OBJECTS =

SystemeTP4: CMakeFiles/SystemeTP4.dir/ex11.c.o
SystemeTP4: CMakeFiles/SystemeTP4.dir/build.make
SystemeTP4: CMakeFiles/SystemeTP4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/salimcherifi/ClionProjects/SystemeTP4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable SystemeTP4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SystemeTP4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SystemeTP4.dir/build: SystemeTP4

.PHONY : CMakeFiles/SystemeTP4.dir/build

CMakeFiles/SystemeTP4.dir/requires: CMakeFiles/SystemeTP4.dir/ex11.c.o.requires

.PHONY : CMakeFiles/SystemeTP4.dir/requires

CMakeFiles/SystemeTP4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SystemeTP4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SystemeTP4.dir/clean

CMakeFiles/SystemeTP4.dir/depend:
	cd /home/salimcherifi/ClionProjects/SystemeTP4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/salimcherifi/ClionProjects/SystemeTP4 /home/salimcherifi/ClionProjects/SystemeTP4 /home/salimcherifi/ClionProjects/SystemeTP4/cmake-build-debug /home/salimcherifi/ClionProjects/SystemeTP4/cmake-build-debug /home/salimcherifi/ClionProjects/SystemeTP4/cmake-build-debug/CMakeFiles/SystemeTP4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SystemeTP4.dir/depend

