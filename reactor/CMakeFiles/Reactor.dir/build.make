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
CMAKE_SOURCE_DIR = /home/ahdai/Server/reactor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ahdai/Server/reactor

# Include any dependencies generated for this target.
include CMakeFiles/Reactor.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Reactor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Reactor.dir/flags.make

CMakeFiles/Reactor.dir/Acceptor.o: CMakeFiles/Reactor.dir/flags.make
CMakeFiles/Reactor.dir/Acceptor.o: Acceptor.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahdai/Server/reactor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Reactor.dir/Acceptor.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Reactor.dir/Acceptor.o -c /home/ahdai/Server/reactor/Acceptor.cc

CMakeFiles/Reactor.dir/Acceptor.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reactor.dir/Acceptor.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahdai/Server/reactor/Acceptor.cc > CMakeFiles/Reactor.dir/Acceptor.i

CMakeFiles/Reactor.dir/Acceptor.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reactor.dir/Acceptor.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahdai/Server/reactor/Acceptor.cc -o CMakeFiles/Reactor.dir/Acceptor.s

CMakeFiles/Reactor.dir/Acceptor.o.requires:

.PHONY : CMakeFiles/Reactor.dir/Acceptor.o.requires

CMakeFiles/Reactor.dir/Acceptor.o.provides: CMakeFiles/Reactor.dir/Acceptor.o.requires
	$(MAKE) -f CMakeFiles/Reactor.dir/build.make CMakeFiles/Reactor.dir/Acceptor.o.provides.build
.PHONY : CMakeFiles/Reactor.dir/Acceptor.o.provides

CMakeFiles/Reactor.dir/Acceptor.o.provides.build: CMakeFiles/Reactor.dir/Acceptor.o


CMakeFiles/Reactor.dir/Buffer.o: CMakeFiles/Reactor.dir/flags.make
CMakeFiles/Reactor.dir/Buffer.o: Buffer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahdai/Server/reactor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Reactor.dir/Buffer.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Reactor.dir/Buffer.o -c /home/ahdai/Server/reactor/Buffer.cc

CMakeFiles/Reactor.dir/Buffer.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reactor.dir/Buffer.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahdai/Server/reactor/Buffer.cc > CMakeFiles/Reactor.dir/Buffer.i

CMakeFiles/Reactor.dir/Buffer.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reactor.dir/Buffer.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahdai/Server/reactor/Buffer.cc -o CMakeFiles/Reactor.dir/Buffer.s

CMakeFiles/Reactor.dir/Buffer.o.requires:

.PHONY : CMakeFiles/Reactor.dir/Buffer.o.requires

CMakeFiles/Reactor.dir/Buffer.o.provides: CMakeFiles/Reactor.dir/Buffer.o.requires
	$(MAKE) -f CMakeFiles/Reactor.dir/build.make CMakeFiles/Reactor.dir/Buffer.o.provides.build
.PHONY : CMakeFiles/Reactor.dir/Buffer.o.provides

CMakeFiles/Reactor.dir/Buffer.o.provides.build: CMakeFiles/Reactor.dir/Buffer.o


CMakeFiles/Reactor.dir/Channel.o: CMakeFiles/Reactor.dir/flags.make
CMakeFiles/Reactor.dir/Channel.o: Channel.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahdai/Server/reactor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Reactor.dir/Channel.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Reactor.dir/Channel.o -c /home/ahdai/Server/reactor/Channel.cc

CMakeFiles/Reactor.dir/Channel.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reactor.dir/Channel.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahdai/Server/reactor/Channel.cc > CMakeFiles/Reactor.dir/Channel.i

CMakeFiles/Reactor.dir/Channel.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reactor.dir/Channel.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahdai/Server/reactor/Channel.cc -o CMakeFiles/Reactor.dir/Channel.s

CMakeFiles/Reactor.dir/Channel.o.requires:

.PHONY : CMakeFiles/Reactor.dir/Channel.o.requires

CMakeFiles/Reactor.dir/Channel.o.provides: CMakeFiles/Reactor.dir/Channel.o.requires
	$(MAKE) -f CMakeFiles/Reactor.dir/build.make CMakeFiles/Reactor.dir/Channel.o.provides.build
.PHONY : CMakeFiles/Reactor.dir/Channel.o.provides

CMakeFiles/Reactor.dir/Channel.o.provides.build: CMakeFiles/Reactor.dir/Channel.o


CMakeFiles/Reactor.dir/EventLoop.o: CMakeFiles/Reactor.dir/flags.make
CMakeFiles/Reactor.dir/EventLoop.o: EventLoop.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahdai/Server/reactor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Reactor.dir/EventLoop.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Reactor.dir/EventLoop.o -c /home/ahdai/Server/reactor/EventLoop.cc

CMakeFiles/Reactor.dir/EventLoop.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reactor.dir/EventLoop.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahdai/Server/reactor/EventLoop.cc > CMakeFiles/Reactor.dir/EventLoop.i

CMakeFiles/Reactor.dir/EventLoop.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reactor.dir/EventLoop.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahdai/Server/reactor/EventLoop.cc -o CMakeFiles/Reactor.dir/EventLoop.s

CMakeFiles/Reactor.dir/EventLoop.o.requires:

.PHONY : CMakeFiles/Reactor.dir/EventLoop.o.requires

CMakeFiles/Reactor.dir/EventLoop.o.provides: CMakeFiles/Reactor.dir/EventLoop.o.requires
	$(MAKE) -f CMakeFiles/Reactor.dir/build.make CMakeFiles/Reactor.dir/EventLoop.o.provides.build
.PHONY : CMakeFiles/Reactor.dir/EventLoop.o.provides

CMakeFiles/Reactor.dir/EventLoop.o.provides.build: CMakeFiles/Reactor.dir/EventLoop.o


CMakeFiles/Reactor.dir/EventLoopThread.o: CMakeFiles/Reactor.dir/flags.make
CMakeFiles/Reactor.dir/EventLoopThread.o: EventLoopThread.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahdai/Server/reactor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Reactor.dir/EventLoopThread.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Reactor.dir/EventLoopThread.o -c /home/ahdai/Server/reactor/EventLoopThread.cc

CMakeFiles/Reactor.dir/EventLoopThread.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reactor.dir/EventLoopThread.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahdai/Server/reactor/EventLoopThread.cc > CMakeFiles/Reactor.dir/EventLoopThread.i

CMakeFiles/Reactor.dir/EventLoopThread.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reactor.dir/EventLoopThread.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahdai/Server/reactor/EventLoopThread.cc -o CMakeFiles/Reactor.dir/EventLoopThread.s

CMakeFiles/Reactor.dir/EventLoopThread.o.requires:

.PHONY : CMakeFiles/Reactor.dir/EventLoopThread.o.requires

CMakeFiles/Reactor.dir/EventLoopThread.o.provides: CMakeFiles/Reactor.dir/EventLoopThread.o.requires
	$(MAKE) -f CMakeFiles/Reactor.dir/build.make CMakeFiles/Reactor.dir/EventLoopThread.o.provides.build
.PHONY : CMakeFiles/Reactor.dir/EventLoopThread.o.provides

CMakeFiles/Reactor.dir/EventLoopThread.o.provides.build: CMakeFiles/Reactor.dir/EventLoopThread.o


CMakeFiles/Reactor.dir/EventLoopThreadPool.o: CMakeFiles/Reactor.dir/flags.make
CMakeFiles/Reactor.dir/EventLoopThreadPool.o: EventLoopThreadPool.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahdai/Server/reactor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Reactor.dir/EventLoopThreadPool.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Reactor.dir/EventLoopThreadPool.o -c /home/ahdai/Server/reactor/EventLoopThreadPool.cc

CMakeFiles/Reactor.dir/EventLoopThreadPool.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reactor.dir/EventLoopThreadPool.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahdai/Server/reactor/EventLoopThreadPool.cc > CMakeFiles/Reactor.dir/EventLoopThreadPool.i

CMakeFiles/Reactor.dir/EventLoopThreadPool.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reactor.dir/EventLoopThreadPool.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahdai/Server/reactor/EventLoopThreadPool.cc -o CMakeFiles/Reactor.dir/EventLoopThreadPool.s

CMakeFiles/Reactor.dir/EventLoopThreadPool.o.requires:

.PHONY : CMakeFiles/Reactor.dir/EventLoopThreadPool.o.requires

CMakeFiles/Reactor.dir/EventLoopThreadPool.o.provides: CMakeFiles/Reactor.dir/EventLoopThreadPool.o.requires
	$(MAKE) -f CMakeFiles/Reactor.dir/build.make CMakeFiles/Reactor.dir/EventLoopThreadPool.o.provides.build
.PHONY : CMakeFiles/Reactor.dir/EventLoopThreadPool.o.provides

CMakeFiles/Reactor.dir/EventLoopThreadPool.o.provides.build: CMakeFiles/Reactor.dir/EventLoopThreadPool.o


CMakeFiles/Reactor.dir/HttpContext.o: CMakeFiles/Reactor.dir/flags.make
CMakeFiles/Reactor.dir/HttpContext.o: HttpContext.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahdai/Server/reactor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Reactor.dir/HttpContext.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Reactor.dir/HttpContext.o -c /home/ahdai/Server/reactor/HttpContext.cc

CMakeFiles/Reactor.dir/HttpContext.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reactor.dir/HttpContext.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahdai/Server/reactor/HttpContext.cc > CMakeFiles/Reactor.dir/HttpContext.i

CMakeFiles/Reactor.dir/HttpContext.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reactor.dir/HttpContext.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahdai/Server/reactor/HttpContext.cc -o CMakeFiles/Reactor.dir/HttpContext.s

CMakeFiles/Reactor.dir/HttpContext.o.requires:

.PHONY : CMakeFiles/Reactor.dir/HttpContext.o.requires

CMakeFiles/Reactor.dir/HttpContext.o.provides: CMakeFiles/Reactor.dir/HttpContext.o.requires
	$(MAKE) -f CMakeFiles/Reactor.dir/build.make CMakeFiles/Reactor.dir/HttpContext.o.provides.build
.PHONY : CMakeFiles/Reactor.dir/HttpContext.o.provides

CMakeFiles/Reactor.dir/HttpContext.o.provides.build: CMakeFiles/Reactor.dir/HttpContext.o


CMakeFiles/Reactor.dir/HttpRequest.o: CMakeFiles/Reactor.dir/flags.make
CMakeFiles/Reactor.dir/HttpRequest.o: HttpRequest.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahdai/Server/reactor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Reactor.dir/HttpRequest.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Reactor.dir/HttpRequest.o -c /home/ahdai/Server/reactor/HttpRequest.cc

CMakeFiles/Reactor.dir/HttpRequest.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reactor.dir/HttpRequest.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahdai/Server/reactor/HttpRequest.cc > CMakeFiles/Reactor.dir/HttpRequest.i

CMakeFiles/Reactor.dir/HttpRequest.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reactor.dir/HttpRequest.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahdai/Server/reactor/HttpRequest.cc -o CMakeFiles/Reactor.dir/HttpRequest.s

CMakeFiles/Reactor.dir/HttpRequest.o.requires:

.PHONY : CMakeFiles/Reactor.dir/HttpRequest.o.requires

CMakeFiles/Reactor.dir/HttpRequest.o.provides: CMakeFiles/Reactor.dir/HttpRequest.o.requires
	$(MAKE) -f CMakeFiles/Reactor.dir/build.make CMakeFiles/Reactor.dir/HttpRequest.o.provides.build
.PHONY : CMakeFiles/Reactor.dir/HttpRequest.o.provides

CMakeFiles/Reactor.dir/HttpRequest.o.provides.build: CMakeFiles/Reactor.dir/HttpRequest.o


CMakeFiles/Reactor.dir/HttpResponse.o: CMakeFiles/Reactor.dir/flags.make
CMakeFiles/Reactor.dir/HttpResponse.o: HttpResponse.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahdai/Server/reactor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Reactor.dir/HttpResponse.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Reactor.dir/HttpResponse.o -c /home/ahdai/Server/reactor/HttpResponse.cc

CMakeFiles/Reactor.dir/HttpResponse.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reactor.dir/HttpResponse.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahdai/Server/reactor/HttpResponse.cc > CMakeFiles/Reactor.dir/HttpResponse.i

CMakeFiles/Reactor.dir/HttpResponse.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reactor.dir/HttpResponse.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahdai/Server/reactor/HttpResponse.cc -o CMakeFiles/Reactor.dir/HttpResponse.s

CMakeFiles/Reactor.dir/HttpResponse.o.requires:

.PHONY : CMakeFiles/Reactor.dir/HttpResponse.o.requires

CMakeFiles/Reactor.dir/HttpResponse.o.provides: CMakeFiles/Reactor.dir/HttpResponse.o.requires
	$(MAKE) -f CMakeFiles/Reactor.dir/build.make CMakeFiles/Reactor.dir/HttpResponse.o.provides.build
.PHONY : CMakeFiles/Reactor.dir/HttpResponse.o.provides

CMakeFiles/Reactor.dir/HttpResponse.o.provides.build: CMakeFiles/Reactor.dir/HttpResponse.o


CMakeFiles/Reactor.dir/HttpServer.o: CMakeFiles/Reactor.dir/flags.make
CMakeFiles/Reactor.dir/HttpServer.o: HttpServer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahdai/Server/reactor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Reactor.dir/HttpServer.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Reactor.dir/HttpServer.o -c /home/ahdai/Server/reactor/HttpServer.cc

CMakeFiles/Reactor.dir/HttpServer.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reactor.dir/HttpServer.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahdai/Server/reactor/HttpServer.cc > CMakeFiles/Reactor.dir/HttpServer.i

CMakeFiles/Reactor.dir/HttpServer.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reactor.dir/HttpServer.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahdai/Server/reactor/HttpServer.cc -o CMakeFiles/Reactor.dir/HttpServer.s

CMakeFiles/Reactor.dir/HttpServer.o.requires:

.PHONY : CMakeFiles/Reactor.dir/HttpServer.o.requires

CMakeFiles/Reactor.dir/HttpServer.o.provides: CMakeFiles/Reactor.dir/HttpServer.o.requires
	$(MAKE) -f CMakeFiles/Reactor.dir/build.make CMakeFiles/Reactor.dir/HttpServer.o.provides.build
.PHONY : CMakeFiles/Reactor.dir/HttpServer.o.provides

CMakeFiles/Reactor.dir/HttpServer.o.provides.build: CMakeFiles/Reactor.dir/HttpServer.o


CMakeFiles/Reactor.dir/InetAddress.o: CMakeFiles/Reactor.dir/flags.make
CMakeFiles/Reactor.dir/InetAddress.o: InetAddress.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahdai/Server/reactor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Reactor.dir/InetAddress.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Reactor.dir/InetAddress.o -c /home/ahdai/Server/reactor/InetAddress.cc

CMakeFiles/Reactor.dir/InetAddress.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reactor.dir/InetAddress.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahdai/Server/reactor/InetAddress.cc > CMakeFiles/Reactor.dir/InetAddress.i

CMakeFiles/Reactor.dir/InetAddress.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reactor.dir/InetAddress.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahdai/Server/reactor/InetAddress.cc -o CMakeFiles/Reactor.dir/InetAddress.s

CMakeFiles/Reactor.dir/InetAddress.o.requires:

.PHONY : CMakeFiles/Reactor.dir/InetAddress.o.requires

CMakeFiles/Reactor.dir/InetAddress.o.provides: CMakeFiles/Reactor.dir/InetAddress.o.requires
	$(MAKE) -f CMakeFiles/Reactor.dir/build.make CMakeFiles/Reactor.dir/InetAddress.o.provides.build
.PHONY : CMakeFiles/Reactor.dir/InetAddress.o.provides

CMakeFiles/Reactor.dir/InetAddress.o.provides.build: CMakeFiles/Reactor.dir/InetAddress.o


CMakeFiles/Reactor.dir/Poll.o: CMakeFiles/Reactor.dir/flags.make
CMakeFiles/Reactor.dir/Poll.o: Poll.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahdai/Server/reactor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Reactor.dir/Poll.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Reactor.dir/Poll.o -c /home/ahdai/Server/reactor/Poll.cc

CMakeFiles/Reactor.dir/Poll.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reactor.dir/Poll.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahdai/Server/reactor/Poll.cc > CMakeFiles/Reactor.dir/Poll.i

CMakeFiles/Reactor.dir/Poll.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reactor.dir/Poll.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahdai/Server/reactor/Poll.cc -o CMakeFiles/Reactor.dir/Poll.s

CMakeFiles/Reactor.dir/Poll.o.requires:

.PHONY : CMakeFiles/Reactor.dir/Poll.o.requires

CMakeFiles/Reactor.dir/Poll.o.provides: CMakeFiles/Reactor.dir/Poll.o.requires
	$(MAKE) -f CMakeFiles/Reactor.dir/build.make CMakeFiles/Reactor.dir/Poll.o.provides.build
.PHONY : CMakeFiles/Reactor.dir/Poll.o.provides

CMakeFiles/Reactor.dir/Poll.o.provides.build: CMakeFiles/Reactor.dir/Poll.o


CMakeFiles/Reactor.dir/Socket.o: CMakeFiles/Reactor.dir/flags.make
CMakeFiles/Reactor.dir/Socket.o: Socket.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahdai/Server/reactor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Reactor.dir/Socket.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Reactor.dir/Socket.o -c /home/ahdai/Server/reactor/Socket.cc

CMakeFiles/Reactor.dir/Socket.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reactor.dir/Socket.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahdai/Server/reactor/Socket.cc > CMakeFiles/Reactor.dir/Socket.i

CMakeFiles/Reactor.dir/Socket.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reactor.dir/Socket.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahdai/Server/reactor/Socket.cc -o CMakeFiles/Reactor.dir/Socket.s

CMakeFiles/Reactor.dir/Socket.o.requires:

.PHONY : CMakeFiles/Reactor.dir/Socket.o.requires

CMakeFiles/Reactor.dir/Socket.o.provides: CMakeFiles/Reactor.dir/Socket.o.requires
	$(MAKE) -f CMakeFiles/Reactor.dir/build.make CMakeFiles/Reactor.dir/Socket.o.provides.build
.PHONY : CMakeFiles/Reactor.dir/Socket.o.provides

CMakeFiles/Reactor.dir/Socket.o.provides.build: CMakeFiles/Reactor.dir/Socket.o


CMakeFiles/Reactor.dir/SocketsOps.o: CMakeFiles/Reactor.dir/flags.make
CMakeFiles/Reactor.dir/SocketsOps.o: SocketsOps.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahdai/Server/reactor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Reactor.dir/SocketsOps.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Reactor.dir/SocketsOps.o -c /home/ahdai/Server/reactor/SocketsOps.cc

CMakeFiles/Reactor.dir/SocketsOps.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reactor.dir/SocketsOps.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahdai/Server/reactor/SocketsOps.cc > CMakeFiles/Reactor.dir/SocketsOps.i

CMakeFiles/Reactor.dir/SocketsOps.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reactor.dir/SocketsOps.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahdai/Server/reactor/SocketsOps.cc -o CMakeFiles/Reactor.dir/SocketsOps.s

CMakeFiles/Reactor.dir/SocketsOps.o.requires:

.PHONY : CMakeFiles/Reactor.dir/SocketsOps.o.requires

CMakeFiles/Reactor.dir/SocketsOps.o.provides: CMakeFiles/Reactor.dir/SocketsOps.o.requires
	$(MAKE) -f CMakeFiles/Reactor.dir/build.make CMakeFiles/Reactor.dir/SocketsOps.o.provides.build
.PHONY : CMakeFiles/Reactor.dir/SocketsOps.o.provides

CMakeFiles/Reactor.dir/SocketsOps.o.provides.build: CMakeFiles/Reactor.dir/SocketsOps.o


CMakeFiles/Reactor.dir/TcpConnection.o: CMakeFiles/Reactor.dir/flags.make
CMakeFiles/Reactor.dir/TcpConnection.o: TcpConnection.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahdai/Server/reactor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/Reactor.dir/TcpConnection.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Reactor.dir/TcpConnection.o -c /home/ahdai/Server/reactor/TcpConnection.cc

CMakeFiles/Reactor.dir/TcpConnection.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reactor.dir/TcpConnection.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahdai/Server/reactor/TcpConnection.cc > CMakeFiles/Reactor.dir/TcpConnection.i

CMakeFiles/Reactor.dir/TcpConnection.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reactor.dir/TcpConnection.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahdai/Server/reactor/TcpConnection.cc -o CMakeFiles/Reactor.dir/TcpConnection.s

CMakeFiles/Reactor.dir/TcpConnection.o.requires:

.PHONY : CMakeFiles/Reactor.dir/TcpConnection.o.requires

CMakeFiles/Reactor.dir/TcpConnection.o.provides: CMakeFiles/Reactor.dir/TcpConnection.o.requires
	$(MAKE) -f CMakeFiles/Reactor.dir/build.make CMakeFiles/Reactor.dir/TcpConnection.o.provides.build
.PHONY : CMakeFiles/Reactor.dir/TcpConnection.o.provides

CMakeFiles/Reactor.dir/TcpConnection.o.provides.build: CMakeFiles/Reactor.dir/TcpConnection.o


CMakeFiles/Reactor.dir/TcpServer.o: CMakeFiles/Reactor.dir/flags.make
CMakeFiles/Reactor.dir/TcpServer.o: TcpServer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahdai/Server/reactor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/Reactor.dir/TcpServer.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Reactor.dir/TcpServer.o -c /home/ahdai/Server/reactor/TcpServer.cc

CMakeFiles/Reactor.dir/TcpServer.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reactor.dir/TcpServer.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahdai/Server/reactor/TcpServer.cc > CMakeFiles/Reactor.dir/TcpServer.i

CMakeFiles/Reactor.dir/TcpServer.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reactor.dir/TcpServer.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahdai/Server/reactor/TcpServer.cc -o CMakeFiles/Reactor.dir/TcpServer.s

CMakeFiles/Reactor.dir/TcpServer.o.requires:

.PHONY : CMakeFiles/Reactor.dir/TcpServer.o.requires

CMakeFiles/Reactor.dir/TcpServer.o.provides: CMakeFiles/Reactor.dir/TcpServer.o.requires
	$(MAKE) -f CMakeFiles/Reactor.dir/build.make CMakeFiles/Reactor.dir/TcpServer.o.provides.build
.PHONY : CMakeFiles/Reactor.dir/TcpServer.o.provides

CMakeFiles/Reactor.dir/TcpServer.o.provides.build: CMakeFiles/Reactor.dir/TcpServer.o


CMakeFiles/Reactor.dir/Timer.o: CMakeFiles/Reactor.dir/flags.make
CMakeFiles/Reactor.dir/Timer.o: Timer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahdai/Server/reactor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/Reactor.dir/Timer.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Reactor.dir/Timer.o -c /home/ahdai/Server/reactor/Timer.cc

CMakeFiles/Reactor.dir/Timer.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reactor.dir/Timer.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahdai/Server/reactor/Timer.cc > CMakeFiles/Reactor.dir/Timer.i

CMakeFiles/Reactor.dir/Timer.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reactor.dir/Timer.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahdai/Server/reactor/Timer.cc -o CMakeFiles/Reactor.dir/Timer.s

CMakeFiles/Reactor.dir/Timer.o.requires:

.PHONY : CMakeFiles/Reactor.dir/Timer.o.requires

CMakeFiles/Reactor.dir/Timer.o.provides: CMakeFiles/Reactor.dir/Timer.o.requires
	$(MAKE) -f CMakeFiles/Reactor.dir/build.make CMakeFiles/Reactor.dir/Timer.o.provides.build
.PHONY : CMakeFiles/Reactor.dir/Timer.o.provides

CMakeFiles/Reactor.dir/Timer.o.provides.build: CMakeFiles/Reactor.dir/Timer.o


CMakeFiles/Reactor.dir/TimerQueue.o: CMakeFiles/Reactor.dir/flags.make
CMakeFiles/Reactor.dir/TimerQueue.o: TimerQueue.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahdai/Server/reactor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/Reactor.dir/TimerQueue.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Reactor.dir/TimerQueue.o -c /home/ahdai/Server/reactor/TimerQueue.cc

CMakeFiles/Reactor.dir/TimerQueue.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reactor.dir/TimerQueue.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahdai/Server/reactor/TimerQueue.cc > CMakeFiles/Reactor.dir/TimerQueue.i

CMakeFiles/Reactor.dir/TimerQueue.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reactor.dir/TimerQueue.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahdai/Server/reactor/TimerQueue.cc -o CMakeFiles/Reactor.dir/TimerQueue.s

CMakeFiles/Reactor.dir/TimerQueue.o.requires:

.PHONY : CMakeFiles/Reactor.dir/TimerQueue.o.requires

CMakeFiles/Reactor.dir/TimerQueue.o.provides: CMakeFiles/Reactor.dir/TimerQueue.o.requires
	$(MAKE) -f CMakeFiles/Reactor.dir/build.make CMakeFiles/Reactor.dir/TimerQueue.o.provides.build
.PHONY : CMakeFiles/Reactor.dir/TimerQueue.o.provides

CMakeFiles/Reactor.dir/TimerQueue.o.provides.build: CMakeFiles/Reactor.dir/TimerQueue.o


CMakeFiles/Reactor.dir/Timestamp.o: CMakeFiles/Reactor.dir/flags.make
CMakeFiles/Reactor.dir/Timestamp.o: Timestamp.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahdai/Server/reactor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/Reactor.dir/Timestamp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Reactor.dir/Timestamp.o -c /home/ahdai/Server/reactor/Timestamp.cc

CMakeFiles/Reactor.dir/Timestamp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reactor.dir/Timestamp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahdai/Server/reactor/Timestamp.cc > CMakeFiles/Reactor.dir/Timestamp.i

CMakeFiles/Reactor.dir/Timestamp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reactor.dir/Timestamp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahdai/Server/reactor/Timestamp.cc -o CMakeFiles/Reactor.dir/Timestamp.s

CMakeFiles/Reactor.dir/Timestamp.o.requires:

.PHONY : CMakeFiles/Reactor.dir/Timestamp.o.requires

CMakeFiles/Reactor.dir/Timestamp.o.provides: CMakeFiles/Reactor.dir/Timestamp.o.requires
	$(MAKE) -f CMakeFiles/Reactor.dir/build.make CMakeFiles/Reactor.dir/Timestamp.o.provides.build
.PHONY : CMakeFiles/Reactor.dir/Timestamp.o.provides

CMakeFiles/Reactor.dir/Timestamp.o.provides.build: CMakeFiles/Reactor.dir/Timestamp.o


CMakeFiles/Reactor.dir/Util.o: CMakeFiles/Reactor.dir/flags.make
CMakeFiles/Reactor.dir/Util.o: Util.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahdai/Server/reactor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building CXX object CMakeFiles/Reactor.dir/Util.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Reactor.dir/Util.o -c /home/ahdai/Server/reactor/Util.cc

CMakeFiles/Reactor.dir/Util.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reactor.dir/Util.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahdai/Server/reactor/Util.cc > CMakeFiles/Reactor.dir/Util.i

CMakeFiles/Reactor.dir/Util.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reactor.dir/Util.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahdai/Server/reactor/Util.cc -o CMakeFiles/Reactor.dir/Util.s

CMakeFiles/Reactor.dir/Util.o.requires:

.PHONY : CMakeFiles/Reactor.dir/Util.o.requires

CMakeFiles/Reactor.dir/Util.o.provides: CMakeFiles/Reactor.dir/Util.o.requires
	$(MAKE) -f CMakeFiles/Reactor.dir/build.make CMakeFiles/Reactor.dir/Util.o.provides.build
.PHONY : CMakeFiles/Reactor.dir/Util.o.provides

CMakeFiles/Reactor.dir/Util.o.provides.build: CMakeFiles/Reactor.dir/Util.o


# Object files for target Reactor
Reactor_OBJECTS = \
"CMakeFiles/Reactor.dir/Acceptor.o" \
"CMakeFiles/Reactor.dir/Buffer.o" \
"CMakeFiles/Reactor.dir/Channel.o" \
"CMakeFiles/Reactor.dir/EventLoop.o" \
"CMakeFiles/Reactor.dir/EventLoopThread.o" \
"CMakeFiles/Reactor.dir/EventLoopThreadPool.o" \
"CMakeFiles/Reactor.dir/HttpContext.o" \
"CMakeFiles/Reactor.dir/HttpRequest.o" \
"CMakeFiles/Reactor.dir/HttpResponse.o" \
"CMakeFiles/Reactor.dir/HttpServer.o" \
"CMakeFiles/Reactor.dir/InetAddress.o" \
"CMakeFiles/Reactor.dir/Poll.o" \
"CMakeFiles/Reactor.dir/Socket.o" \
"CMakeFiles/Reactor.dir/SocketsOps.o" \
"CMakeFiles/Reactor.dir/TcpConnection.o" \
"CMakeFiles/Reactor.dir/TcpServer.o" \
"CMakeFiles/Reactor.dir/Timer.o" \
"CMakeFiles/Reactor.dir/TimerQueue.o" \
"CMakeFiles/Reactor.dir/Timestamp.o" \
"CMakeFiles/Reactor.dir/Util.o"

# External object files for target Reactor
Reactor_EXTERNAL_OBJECTS =

libReactor.a: CMakeFiles/Reactor.dir/Acceptor.o
libReactor.a: CMakeFiles/Reactor.dir/Buffer.o
libReactor.a: CMakeFiles/Reactor.dir/Channel.o
libReactor.a: CMakeFiles/Reactor.dir/EventLoop.o
libReactor.a: CMakeFiles/Reactor.dir/EventLoopThread.o
libReactor.a: CMakeFiles/Reactor.dir/EventLoopThreadPool.o
libReactor.a: CMakeFiles/Reactor.dir/HttpContext.o
libReactor.a: CMakeFiles/Reactor.dir/HttpRequest.o
libReactor.a: CMakeFiles/Reactor.dir/HttpResponse.o
libReactor.a: CMakeFiles/Reactor.dir/HttpServer.o
libReactor.a: CMakeFiles/Reactor.dir/InetAddress.o
libReactor.a: CMakeFiles/Reactor.dir/Poll.o
libReactor.a: CMakeFiles/Reactor.dir/Socket.o
libReactor.a: CMakeFiles/Reactor.dir/SocketsOps.o
libReactor.a: CMakeFiles/Reactor.dir/TcpConnection.o
libReactor.a: CMakeFiles/Reactor.dir/TcpServer.o
libReactor.a: CMakeFiles/Reactor.dir/Timer.o
libReactor.a: CMakeFiles/Reactor.dir/TimerQueue.o
libReactor.a: CMakeFiles/Reactor.dir/Timestamp.o
libReactor.a: CMakeFiles/Reactor.dir/Util.o
libReactor.a: CMakeFiles/Reactor.dir/build.make
libReactor.a: CMakeFiles/Reactor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ahdai/Server/reactor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Linking CXX static library libReactor.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Reactor.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Reactor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Reactor.dir/build: libReactor.a

.PHONY : CMakeFiles/Reactor.dir/build

CMakeFiles/Reactor.dir/requires: CMakeFiles/Reactor.dir/Acceptor.o.requires
CMakeFiles/Reactor.dir/requires: CMakeFiles/Reactor.dir/Buffer.o.requires
CMakeFiles/Reactor.dir/requires: CMakeFiles/Reactor.dir/Channel.o.requires
CMakeFiles/Reactor.dir/requires: CMakeFiles/Reactor.dir/EventLoop.o.requires
CMakeFiles/Reactor.dir/requires: CMakeFiles/Reactor.dir/EventLoopThread.o.requires
CMakeFiles/Reactor.dir/requires: CMakeFiles/Reactor.dir/EventLoopThreadPool.o.requires
CMakeFiles/Reactor.dir/requires: CMakeFiles/Reactor.dir/HttpContext.o.requires
CMakeFiles/Reactor.dir/requires: CMakeFiles/Reactor.dir/HttpRequest.o.requires
CMakeFiles/Reactor.dir/requires: CMakeFiles/Reactor.dir/HttpResponse.o.requires
CMakeFiles/Reactor.dir/requires: CMakeFiles/Reactor.dir/HttpServer.o.requires
CMakeFiles/Reactor.dir/requires: CMakeFiles/Reactor.dir/InetAddress.o.requires
CMakeFiles/Reactor.dir/requires: CMakeFiles/Reactor.dir/Poll.o.requires
CMakeFiles/Reactor.dir/requires: CMakeFiles/Reactor.dir/Socket.o.requires
CMakeFiles/Reactor.dir/requires: CMakeFiles/Reactor.dir/SocketsOps.o.requires
CMakeFiles/Reactor.dir/requires: CMakeFiles/Reactor.dir/TcpConnection.o.requires
CMakeFiles/Reactor.dir/requires: CMakeFiles/Reactor.dir/TcpServer.o.requires
CMakeFiles/Reactor.dir/requires: CMakeFiles/Reactor.dir/Timer.o.requires
CMakeFiles/Reactor.dir/requires: CMakeFiles/Reactor.dir/TimerQueue.o.requires
CMakeFiles/Reactor.dir/requires: CMakeFiles/Reactor.dir/Timestamp.o.requires
CMakeFiles/Reactor.dir/requires: CMakeFiles/Reactor.dir/Util.o.requires

.PHONY : CMakeFiles/Reactor.dir/requires

CMakeFiles/Reactor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Reactor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Reactor.dir/clean

CMakeFiles/Reactor.dir/depend:
	cd /home/ahdai/Server/reactor && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ahdai/Server/reactor /home/ahdai/Server/reactor /home/ahdai/Server/reactor /home/ahdai/Server/reactor /home/ahdai/Server/reactor/CMakeFiles/Reactor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Reactor.dir/depend
