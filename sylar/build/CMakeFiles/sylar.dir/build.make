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
CMAKE_SOURCE_DIR = /home/edinw/workspace/sylar/sylar

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/edinw/workspace/sylar/sylar/build

# Include any dependencies generated for this target.
include CMakeFiles/sylar.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sylar.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sylar.dir/flags.make

CMakeFiles/sylar.dir/src/config.cc.o: CMakeFiles/sylar.dir/flags.make
CMakeFiles/sylar.dir/src/config.cc.o: ../src/config.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/edinw/workspace/sylar/sylar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sylar.dir/src/config.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sylar.dir/src/config.cc.o -c /home/edinw/workspace/sylar/sylar/src/config.cc

CMakeFiles/sylar.dir/src/config.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sylar.dir/src/config.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/edinw/workspace/sylar/sylar/src/config.cc > CMakeFiles/sylar.dir/src/config.cc.i

CMakeFiles/sylar.dir/src/config.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sylar.dir/src/config.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/edinw/workspace/sylar/sylar/src/config.cc -o CMakeFiles/sylar.dir/src/config.cc.s

CMakeFiles/sylar.dir/src/config.cc.o.requires:

.PHONY : CMakeFiles/sylar.dir/src/config.cc.o.requires

CMakeFiles/sylar.dir/src/config.cc.o.provides: CMakeFiles/sylar.dir/src/config.cc.o.requires
	$(MAKE) -f CMakeFiles/sylar.dir/build.make CMakeFiles/sylar.dir/src/config.cc.o.provides.build
.PHONY : CMakeFiles/sylar.dir/src/config.cc.o.provides

CMakeFiles/sylar.dir/src/config.cc.o.provides.build: CMakeFiles/sylar.dir/src/config.cc.o


CMakeFiles/sylar.dir/src/fdmanager.cc.o: CMakeFiles/sylar.dir/flags.make
CMakeFiles/sylar.dir/src/fdmanager.cc.o: ../src/fdmanager.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/edinw/workspace/sylar/sylar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sylar.dir/src/fdmanager.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sylar.dir/src/fdmanager.cc.o -c /home/edinw/workspace/sylar/sylar/src/fdmanager.cc

CMakeFiles/sylar.dir/src/fdmanager.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sylar.dir/src/fdmanager.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/edinw/workspace/sylar/sylar/src/fdmanager.cc > CMakeFiles/sylar.dir/src/fdmanager.cc.i

CMakeFiles/sylar.dir/src/fdmanager.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sylar.dir/src/fdmanager.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/edinw/workspace/sylar/sylar/src/fdmanager.cc -o CMakeFiles/sylar.dir/src/fdmanager.cc.s

CMakeFiles/sylar.dir/src/fdmanager.cc.o.requires:

.PHONY : CMakeFiles/sylar.dir/src/fdmanager.cc.o.requires

CMakeFiles/sylar.dir/src/fdmanager.cc.o.provides: CMakeFiles/sylar.dir/src/fdmanager.cc.o.requires
	$(MAKE) -f CMakeFiles/sylar.dir/build.make CMakeFiles/sylar.dir/src/fdmanager.cc.o.provides.build
.PHONY : CMakeFiles/sylar.dir/src/fdmanager.cc.o.provides

CMakeFiles/sylar.dir/src/fdmanager.cc.o.provides.build: CMakeFiles/sylar.dir/src/fdmanager.cc.o


CMakeFiles/sylar.dir/src/fiber.cc.o: CMakeFiles/sylar.dir/flags.make
CMakeFiles/sylar.dir/src/fiber.cc.o: ../src/fiber.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/edinw/workspace/sylar/sylar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sylar.dir/src/fiber.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sylar.dir/src/fiber.cc.o -c /home/edinw/workspace/sylar/sylar/src/fiber.cc

CMakeFiles/sylar.dir/src/fiber.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sylar.dir/src/fiber.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/edinw/workspace/sylar/sylar/src/fiber.cc > CMakeFiles/sylar.dir/src/fiber.cc.i

CMakeFiles/sylar.dir/src/fiber.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sylar.dir/src/fiber.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/edinw/workspace/sylar/sylar/src/fiber.cc -o CMakeFiles/sylar.dir/src/fiber.cc.s

CMakeFiles/sylar.dir/src/fiber.cc.o.requires:

.PHONY : CMakeFiles/sylar.dir/src/fiber.cc.o.requires

CMakeFiles/sylar.dir/src/fiber.cc.o.provides: CMakeFiles/sylar.dir/src/fiber.cc.o.requires
	$(MAKE) -f CMakeFiles/sylar.dir/build.make CMakeFiles/sylar.dir/src/fiber.cc.o.provides.build
.PHONY : CMakeFiles/sylar.dir/src/fiber.cc.o.provides

CMakeFiles/sylar.dir/src/fiber.cc.o.provides.build: CMakeFiles/sylar.dir/src/fiber.cc.o


CMakeFiles/sylar.dir/src/hook.cc.o: CMakeFiles/sylar.dir/flags.make
CMakeFiles/sylar.dir/src/hook.cc.o: ../src/hook.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/edinw/workspace/sylar/sylar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sylar.dir/src/hook.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sylar.dir/src/hook.cc.o -c /home/edinw/workspace/sylar/sylar/src/hook.cc

CMakeFiles/sylar.dir/src/hook.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sylar.dir/src/hook.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/edinw/workspace/sylar/sylar/src/hook.cc > CMakeFiles/sylar.dir/src/hook.cc.i

CMakeFiles/sylar.dir/src/hook.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sylar.dir/src/hook.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/edinw/workspace/sylar/sylar/src/hook.cc -o CMakeFiles/sylar.dir/src/hook.cc.s

CMakeFiles/sylar.dir/src/hook.cc.o.requires:

.PHONY : CMakeFiles/sylar.dir/src/hook.cc.o.requires

CMakeFiles/sylar.dir/src/hook.cc.o.provides: CMakeFiles/sylar.dir/src/hook.cc.o.requires
	$(MAKE) -f CMakeFiles/sylar.dir/build.make CMakeFiles/sylar.dir/src/hook.cc.o.provides.build
.PHONY : CMakeFiles/sylar.dir/src/hook.cc.o.provides

CMakeFiles/sylar.dir/src/hook.cc.o.provides.build: CMakeFiles/sylar.dir/src/hook.cc.o


CMakeFiles/sylar.dir/src/iomanager.cc.o: CMakeFiles/sylar.dir/flags.make
CMakeFiles/sylar.dir/src/iomanager.cc.o: ../src/iomanager.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/edinw/workspace/sylar/sylar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/sylar.dir/src/iomanager.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sylar.dir/src/iomanager.cc.o -c /home/edinw/workspace/sylar/sylar/src/iomanager.cc

CMakeFiles/sylar.dir/src/iomanager.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sylar.dir/src/iomanager.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/edinw/workspace/sylar/sylar/src/iomanager.cc > CMakeFiles/sylar.dir/src/iomanager.cc.i

CMakeFiles/sylar.dir/src/iomanager.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sylar.dir/src/iomanager.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/edinw/workspace/sylar/sylar/src/iomanager.cc -o CMakeFiles/sylar.dir/src/iomanager.cc.s

CMakeFiles/sylar.dir/src/iomanager.cc.o.requires:

.PHONY : CMakeFiles/sylar.dir/src/iomanager.cc.o.requires

CMakeFiles/sylar.dir/src/iomanager.cc.o.provides: CMakeFiles/sylar.dir/src/iomanager.cc.o.requires
	$(MAKE) -f CMakeFiles/sylar.dir/build.make CMakeFiles/sylar.dir/src/iomanager.cc.o.provides.build
.PHONY : CMakeFiles/sylar.dir/src/iomanager.cc.o.provides

CMakeFiles/sylar.dir/src/iomanager.cc.o.provides.build: CMakeFiles/sylar.dir/src/iomanager.cc.o


CMakeFiles/sylar.dir/src/log.cc.o: CMakeFiles/sylar.dir/flags.make
CMakeFiles/sylar.dir/src/log.cc.o: ../src/log.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/edinw/workspace/sylar/sylar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/sylar.dir/src/log.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sylar.dir/src/log.cc.o -c /home/edinw/workspace/sylar/sylar/src/log.cc

CMakeFiles/sylar.dir/src/log.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sylar.dir/src/log.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/edinw/workspace/sylar/sylar/src/log.cc > CMakeFiles/sylar.dir/src/log.cc.i

CMakeFiles/sylar.dir/src/log.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sylar.dir/src/log.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/edinw/workspace/sylar/sylar/src/log.cc -o CMakeFiles/sylar.dir/src/log.cc.s

CMakeFiles/sylar.dir/src/log.cc.o.requires:

.PHONY : CMakeFiles/sylar.dir/src/log.cc.o.requires

CMakeFiles/sylar.dir/src/log.cc.o.provides: CMakeFiles/sylar.dir/src/log.cc.o.requires
	$(MAKE) -f CMakeFiles/sylar.dir/build.make CMakeFiles/sylar.dir/src/log.cc.o.provides.build
.PHONY : CMakeFiles/sylar.dir/src/log.cc.o.provides

CMakeFiles/sylar.dir/src/log.cc.o.provides.build: CMakeFiles/sylar.dir/src/log.cc.o


CMakeFiles/sylar.dir/src/mutex.cc.o: CMakeFiles/sylar.dir/flags.make
CMakeFiles/sylar.dir/src/mutex.cc.o: ../src/mutex.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/edinw/workspace/sylar/sylar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/sylar.dir/src/mutex.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sylar.dir/src/mutex.cc.o -c /home/edinw/workspace/sylar/sylar/src/mutex.cc

CMakeFiles/sylar.dir/src/mutex.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sylar.dir/src/mutex.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/edinw/workspace/sylar/sylar/src/mutex.cc > CMakeFiles/sylar.dir/src/mutex.cc.i

CMakeFiles/sylar.dir/src/mutex.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sylar.dir/src/mutex.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/edinw/workspace/sylar/sylar/src/mutex.cc -o CMakeFiles/sylar.dir/src/mutex.cc.s

CMakeFiles/sylar.dir/src/mutex.cc.o.requires:

.PHONY : CMakeFiles/sylar.dir/src/mutex.cc.o.requires

CMakeFiles/sylar.dir/src/mutex.cc.o.provides: CMakeFiles/sylar.dir/src/mutex.cc.o.requires
	$(MAKE) -f CMakeFiles/sylar.dir/build.make CMakeFiles/sylar.dir/src/mutex.cc.o.provides.build
.PHONY : CMakeFiles/sylar.dir/src/mutex.cc.o.provides

CMakeFiles/sylar.dir/src/mutex.cc.o.provides.build: CMakeFiles/sylar.dir/src/mutex.cc.o


CMakeFiles/sylar.dir/src/scheduler.cc.o: CMakeFiles/sylar.dir/flags.make
CMakeFiles/sylar.dir/src/scheduler.cc.o: ../src/scheduler.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/edinw/workspace/sylar/sylar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/sylar.dir/src/scheduler.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sylar.dir/src/scheduler.cc.o -c /home/edinw/workspace/sylar/sylar/src/scheduler.cc

CMakeFiles/sylar.dir/src/scheduler.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sylar.dir/src/scheduler.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/edinw/workspace/sylar/sylar/src/scheduler.cc > CMakeFiles/sylar.dir/src/scheduler.cc.i

CMakeFiles/sylar.dir/src/scheduler.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sylar.dir/src/scheduler.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/edinw/workspace/sylar/sylar/src/scheduler.cc -o CMakeFiles/sylar.dir/src/scheduler.cc.s

CMakeFiles/sylar.dir/src/scheduler.cc.o.requires:

.PHONY : CMakeFiles/sylar.dir/src/scheduler.cc.o.requires

CMakeFiles/sylar.dir/src/scheduler.cc.o.provides: CMakeFiles/sylar.dir/src/scheduler.cc.o.requires
	$(MAKE) -f CMakeFiles/sylar.dir/build.make CMakeFiles/sylar.dir/src/scheduler.cc.o.provides.build
.PHONY : CMakeFiles/sylar.dir/src/scheduler.cc.o.provides

CMakeFiles/sylar.dir/src/scheduler.cc.o.provides.build: CMakeFiles/sylar.dir/src/scheduler.cc.o


CMakeFiles/sylar.dir/src/thread.cc.o: CMakeFiles/sylar.dir/flags.make
CMakeFiles/sylar.dir/src/thread.cc.o: ../src/thread.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/edinw/workspace/sylar/sylar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/sylar.dir/src/thread.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sylar.dir/src/thread.cc.o -c /home/edinw/workspace/sylar/sylar/src/thread.cc

CMakeFiles/sylar.dir/src/thread.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sylar.dir/src/thread.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/edinw/workspace/sylar/sylar/src/thread.cc > CMakeFiles/sylar.dir/src/thread.cc.i

CMakeFiles/sylar.dir/src/thread.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sylar.dir/src/thread.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/edinw/workspace/sylar/sylar/src/thread.cc -o CMakeFiles/sylar.dir/src/thread.cc.s

CMakeFiles/sylar.dir/src/thread.cc.o.requires:

.PHONY : CMakeFiles/sylar.dir/src/thread.cc.o.requires

CMakeFiles/sylar.dir/src/thread.cc.o.provides: CMakeFiles/sylar.dir/src/thread.cc.o.requires
	$(MAKE) -f CMakeFiles/sylar.dir/build.make CMakeFiles/sylar.dir/src/thread.cc.o.provides.build
.PHONY : CMakeFiles/sylar.dir/src/thread.cc.o.provides

CMakeFiles/sylar.dir/src/thread.cc.o.provides.build: CMakeFiles/sylar.dir/src/thread.cc.o


CMakeFiles/sylar.dir/src/timer.cc.o: CMakeFiles/sylar.dir/flags.make
CMakeFiles/sylar.dir/src/timer.cc.o: ../src/timer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/edinw/workspace/sylar/sylar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/sylar.dir/src/timer.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sylar.dir/src/timer.cc.o -c /home/edinw/workspace/sylar/sylar/src/timer.cc

CMakeFiles/sylar.dir/src/timer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sylar.dir/src/timer.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/edinw/workspace/sylar/sylar/src/timer.cc > CMakeFiles/sylar.dir/src/timer.cc.i

CMakeFiles/sylar.dir/src/timer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sylar.dir/src/timer.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/edinw/workspace/sylar/sylar/src/timer.cc -o CMakeFiles/sylar.dir/src/timer.cc.s

CMakeFiles/sylar.dir/src/timer.cc.o.requires:

.PHONY : CMakeFiles/sylar.dir/src/timer.cc.o.requires

CMakeFiles/sylar.dir/src/timer.cc.o.provides: CMakeFiles/sylar.dir/src/timer.cc.o.requires
	$(MAKE) -f CMakeFiles/sylar.dir/build.make CMakeFiles/sylar.dir/src/timer.cc.o.provides.build
.PHONY : CMakeFiles/sylar.dir/src/timer.cc.o.provides

CMakeFiles/sylar.dir/src/timer.cc.o.provides.build: CMakeFiles/sylar.dir/src/timer.cc.o


CMakeFiles/sylar.dir/src/util.cc.o: CMakeFiles/sylar.dir/flags.make
CMakeFiles/sylar.dir/src/util.cc.o: ../src/util.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/edinw/workspace/sylar/sylar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/sylar.dir/src/util.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sylar.dir/src/util.cc.o -c /home/edinw/workspace/sylar/sylar/src/util.cc

CMakeFiles/sylar.dir/src/util.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sylar.dir/src/util.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/edinw/workspace/sylar/sylar/src/util.cc > CMakeFiles/sylar.dir/src/util.cc.i

CMakeFiles/sylar.dir/src/util.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sylar.dir/src/util.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/edinw/workspace/sylar/sylar/src/util.cc -o CMakeFiles/sylar.dir/src/util.cc.s

CMakeFiles/sylar.dir/src/util.cc.o.requires:

.PHONY : CMakeFiles/sylar.dir/src/util.cc.o.requires

CMakeFiles/sylar.dir/src/util.cc.o.provides: CMakeFiles/sylar.dir/src/util.cc.o.requires
	$(MAKE) -f CMakeFiles/sylar.dir/build.make CMakeFiles/sylar.dir/src/util.cc.o.provides.build
.PHONY : CMakeFiles/sylar.dir/src/util.cc.o.provides

CMakeFiles/sylar.dir/src/util.cc.o.provides.build: CMakeFiles/sylar.dir/src/util.cc.o


# Object files for target sylar
sylar_OBJECTS = \
"CMakeFiles/sylar.dir/src/config.cc.o" \
"CMakeFiles/sylar.dir/src/fdmanager.cc.o" \
"CMakeFiles/sylar.dir/src/fiber.cc.o" \
"CMakeFiles/sylar.dir/src/hook.cc.o" \
"CMakeFiles/sylar.dir/src/iomanager.cc.o" \
"CMakeFiles/sylar.dir/src/log.cc.o" \
"CMakeFiles/sylar.dir/src/mutex.cc.o" \
"CMakeFiles/sylar.dir/src/scheduler.cc.o" \
"CMakeFiles/sylar.dir/src/thread.cc.o" \
"CMakeFiles/sylar.dir/src/timer.cc.o" \
"CMakeFiles/sylar.dir/src/util.cc.o"

# External object files for target sylar
sylar_EXTERNAL_OBJECTS =

/home/edinw/workspace/sylar/lib/libsylar.so: CMakeFiles/sylar.dir/src/config.cc.o
/home/edinw/workspace/sylar/lib/libsylar.so: CMakeFiles/sylar.dir/src/fdmanager.cc.o
/home/edinw/workspace/sylar/lib/libsylar.so: CMakeFiles/sylar.dir/src/fiber.cc.o
/home/edinw/workspace/sylar/lib/libsylar.so: CMakeFiles/sylar.dir/src/hook.cc.o
/home/edinw/workspace/sylar/lib/libsylar.so: CMakeFiles/sylar.dir/src/iomanager.cc.o
/home/edinw/workspace/sylar/lib/libsylar.so: CMakeFiles/sylar.dir/src/log.cc.o
/home/edinw/workspace/sylar/lib/libsylar.so: CMakeFiles/sylar.dir/src/mutex.cc.o
/home/edinw/workspace/sylar/lib/libsylar.so: CMakeFiles/sylar.dir/src/scheduler.cc.o
/home/edinw/workspace/sylar/lib/libsylar.so: CMakeFiles/sylar.dir/src/thread.cc.o
/home/edinw/workspace/sylar/lib/libsylar.so: CMakeFiles/sylar.dir/src/timer.cc.o
/home/edinw/workspace/sylar/lib/libsylar.so: CMakeFiles/sylar.dir/src/util.cc.o
/home/edinw/workspace/sylar/lib/libsylar.so: CMakeFiles/sylar.dir/build.make
/home/edinw/workspace/sylar/lib/libsylar.so: CMakeFiles/sylar.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/edinw/workspace/sylar/sylar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX shared library /home/edinw/workspace/sylar/lib/libsylar.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sylar.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sylar.dir/build: /home/edinw/workspace/sylar/lib/libsylar.so

.PHONY : CMakeFiles/sylar.dir/build

CMakeFiles/sylar.dir/requires: CMakeFiles/sylar.dir/src/config.cc.o.requires
CMakeFiles/sylar.dir/requires: CMakeFiles/sylar.dir/src/fdmanager.cc.o.requires
CMakeFiles/sylar.dir/requires: CMakeFiles/sylar.dir/src/fiber.cc.o.requires
CMakeFiles/sylar.dir/requires: CMakeFiles/sylar.dir/src/hook.cc.o.requires
CMakeFiles/sylar.dir/requires: CMakeFiles/sylar.dir/src/iomanager.cc.o.requires
CMakeFiles/sylar.dir/requires: CMakeFiles/sylar.dir/src/log.cc.o.requires
CMakeFiles/sylar.dir/requires: CMakeFiles/sylar.dir/src/mutex.cc.o.requires
CMakeFiles/sylar.dir/requires: CMakeFiles/sylar.dir/src/scheduler.cc.o.requires
CMakeFiles/sylar.dir/requires: CMakeFiles/sylar.dir/src/thread.cc.o.requires
CMakeFiles/sylar.dir/requires: CMakeFiles/sylar.dir/src/timer.cc.o.requires
CMakeFiles/sylar.dir/requires: CMakeFiles/sylar.dir/src/util.cc.o.requires

.PHONY : CMakeFiles/sylar.dir/requires

CMakeFiles/sylar.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sylar.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sylar.dir/clean

CMakeFiles/sylar.dir/depend:
	cd /home/edinw/workspace/sylar/sylar/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/edinw/workspace/sylar/sylar /home/edinw/workspace/sylar/sylar /home/edinw/workspace/sylar/sylar/build /home/edinw/workspace/sylar/sylar/build /home/edinw/workspace/sylar/sylar/build/CMakeFiles/sylar.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sylar.dir/depend

