# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = "D:\sorftware\CLion 2022.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\sorftware\CLion 2022.1.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\SLAM\code\week_03\weak_ptr

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\SLAM\code\week_03\weak_ptr\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/weak_ptr.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/weak_ptr.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/weak_ptr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/weak_ptr.dir/flags.make

CMakeFiles/weak_ptr.dir/main.cpp.obj: CMakeFiles/weak_ptr.dir/flags.make
CMakeFiles/weak_ptr.dir/main.cpp.obj: ../main.cpp
CMakeFiles/weak_ptr.dir/main.cpp.obj: CMakeFiles/weak_ptr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\SLAM\code\week_03\weak_ptr\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/weak_ptr.dir/main.cpp.obj"
	D:\SORFTW~1\CLION2~1.3\mingw64\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/weak_ptr.dir/main.cpp.obj -MF CMakeFiles\weak_ptr.dir\main.cpp.obj.d -o CMakeFiles\weak_ptr.dir\main.cpp.obj -c D:\SLAM\code\week_03\weak_ptr\main.cpp

CMakeFiles/weak_ptr.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/weak_ptr.dir/main.cpp.i"
	D:\SORFTW~1\CLION2~1.3\mingw64\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\SLAM\code\week_03\weak_ptr\main.cpp > CMakeFiles\weak_ptr.dir\main.cpp.i

CMakeFiles/weak_ptr.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/weak_ptr.dir/main.cpp.s"
	D:\SORFTW~1\CLION2~1.3\mingw64\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\SLAM\code\week_03\weak_ptr\main.cpp -o CMakeFiles\weak_ptr.dir\main.cpp.s

# Object files for target weak_ptr
weak_ptr_OBJECTS = \
"CMakeFiles/weak_ptr.dir/main.cpp.obj"

# External object files for target weak_ptr
weak_ptr_EXTERNAL_OBJECTS =

weak_ptr.exe: CMakeFiles/weak_ptr.dir/main.cpp.obj
weak_ptr.exe: CMakeFiles/weak_ptr.dir/build.make
weak_ptr.exe: CMakeFiles/weak_ptr.dir/linklibs.rsp
weak_ptr.exe: CMakeFiles/weak_ptr.dir/objects1.rsp
weak_ptr.exe: CMakeFiles/weak_ptr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\SLAM\code\week_03\weak_ptr\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable weak_ptr.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\weak_ptr.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/weak_ptr.dir/build: weak_ptr.exe
.PHONY : CMakeFiles/weak_ptr.dir/build

CMakeFiles/weak_ptr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\weak_ptr.dir\cmake_clean.cmake
.PHONY : CMakeFiles/weak_ptr.dir/clean

CMakeFiles/weak_ptr.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\SLAM\code\week_03\weak_ptr D:\SLAM\code\week_03\weak_ptr D:\SLAM\code\week_03\weak_ptr\cmake-build-debug D:\SLAM\code\week_03\weak_ptr\cmake-build-debug D:\SLAM\code\week_03\weak_ptr\cmake-build-debug\CMakeFiles\weak_ptr.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/weak_ptr.dir/depend
