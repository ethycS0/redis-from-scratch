# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/arjun/Documents/redis-from-scratch

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arjun/Documents/redis-from-scratch/build

# Include any dependencies generated for this target.
include src/client/CMakeFiles/Client.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/client/CMakeFiles/Client.dir/compiler_depend.make

# Include the progress variables for this target.
include src/client/CMakeFiles/Client.dir/progress.make

# Include the compile flags for this target's objects.
include src/client/CMakeFiles/Client.dir/flags.make

src/client/CMakeFiles/Client.dir/start-client.cpp.o: src/client/CMakeFiles/Client.dir/flags.make
src/client/CMakeFiles/Client.dir/start-client.cpp.o: /home/arjun/Documents/redis-from-scratch/src/client/start-client.cpp
src/client/CMakeFiles/Client.dir/start-client.cpp.o: src/client/CMakeFiles/Client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/arjun/Documents/redis-from-scratch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/client/CMakeFiles/Client.dir/start-client.cpp.o"
	cd /home/arjun/Documents/redis-from-scratch/build/src/client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/client/CMakeFiles/Client.dir/start-client.cpp.o -MF CMakeFiles/Client.dir/start-client.cpp.o.d -o CMakeFiles/Client.dir/start-client.cpp.o -c /home/arjun/Documents/redis-from-scratch/src/client/start-client.cpp

src/client/CMakeFiles/Client.dir/start-client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Client.dir/start-client.cpp.i"
	cd /home/arjun/Documents/redis-from-scratch/build/src/client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arjun/Documents/redis-from-scratch/src/client/start-client.cpp > CMakeFiles/Client.dir/start-client.cpp.i

src/client/CMakeFiles/Client.dir/start-client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Client.dir/start-client.cpp.s"
	cd /home/arjun/Documents/redis-from-scratch/build/src/client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arjun/Documents/redis-from-scratch/src/client/start-client.cpp -o CMakeFiles/Client.dir/start-client.cpp.s

src/client/CMakeFiles/Client.dir/client.cpp.o: src/client/CMakeFiles/Client.dir/flags.make
src/client/CMakeFiles/Client.dir/client.cpp.o: /home/arjun/Documents/redis-from-scratch/src/client/client.cpp
src/client/CMakeFiles/Client.dir/client.cpp.o: src/client/CMakeFiles/Client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/arjun/Documents/redis-from-scratch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/client/CMakeFiles/Client.dir/client.cpp.o"
	cd /home/arjun/Documents/redis-from-scratch/build/src/client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/client/CMakeFiles/Client.dir/client.cpp.o -MF CMakeFiles/Client.dir/client.cpp.o.d -o CMakeFiles/Client.dir/client.cpp.o -c /home/arjun/Documents/redis-from-scratch/src/client/client.cpp

src/client/CMakeFiles/Client.dir/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Client.dir/client.cpp.i"
	cd /home/arjun/Documents/redis-from-scratch/build/src/client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arjun/Documents/redis-from-scratch/src/client/client.cpp > CMakeFiles/Client.dir/client.cpp.i

src/client/CMakeFiles/Client.dir/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Client.dir/client.cpp.s"
	cd /home/arjun/Documents/redis-from-scratch/build/src/client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arjun/Documents/redis-from-scratch/src/client/client.cpp -o CMakeFiles/Client.dir/client.cpp.s

src/client/CMakeFiles/Client.dir/__/common/helper.cpp.o: src/client/CMakeFiles/Client.dir/flags.make
src/client/CMakeFiles/Client.dir/__/common/helper.cpp.o: /home/arjun/Documents/redis-from-scratch/src/common/helper.cpp
src/client/CMakeFiles/Client.dir/__/common/helper.cpp.o: src/client/CMakeFiles/Client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/arjun/Documents/redis-from-scratch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/client/CMakeFiles/Client.dir/__/common/helper.cpp.o"
	cd /home/arjun/Documents/redis-from-scratch/build/src/client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/client/CMakeFiles/Client.dir/__/common/helper.cpp.o -MF CMakeFiles/Client.dir/__/common/helper.cpp.o.d -o CMakeFiles/Client.dir/__/common/helper.cpp.o -c /home/arjun/Documents/redis-from-scratch/src/common/helper.cpp

src/client/CMakeFiles/Client.dir/__/common/helper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Client.dir/__/common/helper.cpp.i"
	cd /home/arjun/Documents/redis-from-scratch/build/src/client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arjun/Documents/redis-from-scratch/src/common/helper.cpp > CMakeFiles/Client.dir/__/common/helper.cpp.i

src/client/CMakeFiles/Client.dir/__/common/helper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Client.dir/__/common/helper.cpp.s"
	cd /home/arjun/Documents/redis-from-scratch/build/src/client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arjun/Documents/redis-from-scratch/src/common/helper.cpp -o CMakeFiles/Client.dir/__/common/helper.cpp.s

# Object files for target Client
Client_OBJECTS = \
"CMakeFiles/Client.dir/start-client.cpp.o" \
"CMakeFiles/Client.dir/client.cpp.o" \
"CMakeFiles/Client.dir/__/common/helper.cpp.o"

# External object files for target Client
Client_EXTERNAL_OBJECTS =

src/client/Client: src/client/CMakeFiles/Client.dir/start-client.cpp.o
src/client/Client: src/client/CMakeFiles/Client.dir/client.cpp.o
src/client/Client: src/client/CMakeFiles/Client.dir/__/common/helper.cpp.o
src/client/Client: src/client/CMakeFiles/Client.dir/build.make
src/client/Client: src/client/CMakeFiles/Client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/arjun/Documents/redis-from-scratch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Client"
	cd /home/arjun/Documents/redis-from-scratch/build/src/client && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/client/CMakeFiles/Client.dir/build: src/client/Client
.PHONY : src/client/CMakeFiles/Client.dir/build

src/client/CMakeFiles/Client.dir/clean:
	cd /home/arjun/Documents/redis-from-scratch/build/src/client && $(CMAKE_COMMAND) -P CMakeFiles/Client.dir/cmake_clean.cmake
.PHONY : src/client/CMakeFiles/Client.dir/clean

src/client/CMakeFiles/Client.dir/depend:
	cd /home/arjun/Documents/redis-from-scratch/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arjun/Documents/redis-from-scratch /home/arjun/Documents/redis-from-scratch/src/client /home/arjun/Documents/redis-from-scratch/build /home/arjun/Documents/redis-from-scratch/build/src/client /home/arjun/Documents/redis-from-scratch/build/src/client/CMakeFiles/Client.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/client/CMakeFiles/Client.dir/depend

