# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\axaio\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\211.7442.42\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\axaio\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\211.7442.42\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\axaio\CLionProjects\Tournament

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\axaio\CLionProjects\Tournament\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Tournament.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tournament.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tournament.dir/flags.make

CMakeFiles/Tournament.dir/main.cpp.obj: CMakeFiles/Tournament.dir/flags.make
CMakeFiles/Tournament.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\axaio\CLionProjects\Tournament\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tournament.dir/main.cpp.obj"
	C:\PROGRA~2\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Tournament.dir\main.cpp.obj -c C:\Users\axaio\CLionProjects\Tournament\main.cpp

CMakeFiles/Tournament.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tournament.dir/main.cpp.i"
	C:\PROGRA~2\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\axaio\CLionProjects\Tournament\main.cpp > CMakeFiles\Tournament.dir\main.cpp.i

CMakeFiles/Tournament.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tournament.dir/main.cpp.s"
	C:\PROGRA~2\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\axaio\CLionProjects\Tournament\main.cpp -o CMakeFiles\Tournament.dir\main.cpp.s

# Object files for target Tournament
Tournament_OBJECTS = \
"CMakeFiles/Tournament.dir/main.cpp.obj"

# External object files for target Tournament
Tournament_EXTERNAL_OBJECTS =

Tournament.exe: CMakeFiles/Tournament.dir/main.cpp.obj
Tournament.exe: CMakeFiles/Tournament.dir/build.make
Tournament.exe: CMakeFiles/Tournament.dir/linklibs.rsp
Tournament.exe: CMakeFiles/Tournament.dir/objects1.rsp
Tournament.exe: CMakeFiles/Tournament.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\axaio\CLionProjects\Tournament\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Tournament.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Tournament.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tournament.dir/build: Tournament.exe

.PHONY : CMakeFiles/Tournament.dir/build

CMakeFiles/Tournament.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Tournament.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Tournament.dir/clean

CMakeFiles/Tournament.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\axaio\CLionProjects\Tournament C:\Users\axaio\CLionProjects\Tournament C:\Users\axaio\CLionProjects\Tournament\cmake-build-debug C:\Users\axaio\CLionProjects\Tournament\cmake-build-debug C:\Users\axaio\CLionProjects\Tournament\cmake-build-debug\CMakeFiles\Tournament.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Tournament.dir/depend

