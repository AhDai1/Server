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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ahdai/Server/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ahdai/Server/test

# Include any dependencies generated for this target.
include thread_binary_dir/CMakeFiles/Thread.dir/depend.make

# Include the progress variables for this target.
include thread_binary_dir/CMakeFiles/Thread.dir/progress.make

# Include the compile flags for this target's objects.
include thread_binary_dir/CMakeFiles/Thread.dir/flags.make

thread_binary_dir/CMakeFiles/Thread.dir/Thread.cc.o: thread_binary_dir/CMakeFiles/Thread.dir/flags.make
thread_binary_dir/CMakeFiles/Thread.dir/Thread.cc.o: /home/ahdai/Server/thread/Thread.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahdai/Server/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object thread_binary_dir/CMakeFiles/Thread.dir/Thread.cc.o"
	cd /home/ahdai/Server/test/thread_binary_dir && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Thread.dir/Thread.cc.o -c /home/ahdai/Server/thread/Thread.cc

thread_binary_dir/CMakeFiles/Thread.dir/Thread.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Thread.dir/Thread.cc.i"
	cd /home/ahdai/Server/test/thread_binary_dir && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahdai/Server/thread/Thread.cc > CMakeFiles/Thread.dir/Thread.cc.i

thread_binary_dir/CMakeFiles/Thread.dir/Thread.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Thread.dir/Thread.cc.s"
	cd /home/ahdai/Server/test/thread_binary_dir && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahdai/Server/thread/Thread.cc -o CMakeFiles/Thread.dir/Thread.cc.s

thread_binary_dir/CMakeFiles/Thread.dir/Thread.cc.o.requires:

.PHONY : thread_binary_dir/CMakeFiles/Thread.dir/Thread.cc.o.requires

thread_binary_dir/CMakeFiles/Thread.dir/Thread.cc.o.provides: thread_binary_dir/CMakeFiles/Thread.dir/Thread.cc.o.requires
	$(MAKE) -f thread_binary_dir/CMakeFiles/Thread.dir/build.make thread_binary_dir/CMakeFiles/Thread.dir/Thread.cc.o.provides.build
.PHONY : thread_binary_dir/CMakeFiles/Thread.dir/Thread.cc.o.provides

thread_binary_dir/CMakeFiles/Thread.dir/Thread.cc.o.provides.build: thread_binary_dir/CMakeFiles/Thread.dir/Thread.cc.o


# Object files for target Thread
Thread_OBJECTS = \
"CMakeFiles/Thread.dir/Thread.cc.o"

# External object files for target Thread
Thread_EXTERNAL_OBJECTS =

thread_binary_dir/libThread.a: thread_binary_dir/CMakeFiles/Thread.dir/Thread.cc.o
thread_binary_dir/libThread.a: thread_binary_dir/CMakeFiles/Thread.dir/build.make
thread_binary_dir/libThread.a: thread_binary_dir/CMakeFiles/Thread.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ahdai/Server/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libThread.a"
	cd /home/ahdai/Server/test/thread_binary_dir && $(CMAKE_COMMAND) -P CMakeFiles/Thread.dir/cmake_clean_target.cmake
	cd /home/ahdai/Server/test/thread_binary_dir && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Thread.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
thread_binary_dir/CMakeFiles/Thread.dir/build: thread_binary_dir/libThread.a

.PHONY : thread_binary_dir/CMakeFiles/Thread.dir/build

thread_binary_dir/CMakeFiles/Thread.dir/requires: thread_binary_dir/CMakeFiles/Thread.dir/Thread.cc.o.requires

.PHONY : thread_binary_dir/CMakeFiles/Thread.dir/requires

thread_binary_dir/CMakeFiles/Thread.dir/clean:
	cd /home/ahdai/Server/test/thread_binary_dir && $(CMAKE_COMMAND) -P CMakeFiles/Thread.dir/cmake_clean.cmake
.PHONY : thread_binary_dir/CMakeFiles/Thread.dir/clean

thread_binary_dir/CMakeFiles/Thread.dir/depend:
	cd /home/ahdai/Server/test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ahdai/Server/test /home/ahdai/Server/thread /home/ahdai/Server/test /home/ahdai/Server/test/thread_binary_dir /home/ahdai/Server/test/thread_binary_dir/CMakeFiles/Thread.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : thread_binary_dir/CMakeFiles/Thread.dir/depend

