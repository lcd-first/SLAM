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
CMAKE_SOURCE_DIR = D:\SLAM\code\week_01\STL\Set_multiset

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\SLAM\code\week_01\STL\Set_multiset\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Set_multiset.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Set_multiset.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Set_multiset.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Set_multiset.dir/flags.make

CMakeFiles/Set_multiset.dir/main.cpp.obj: CMakeFiles/Set_multiset.dir/flags.make
CMakeFiles/Set_multiset.dir/main.cpp.obj: ../main.cpp
CMakeFiles/Set_multiset.dir/main.cpp.obj: CMakeFiles/Set_multiset.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\SLAM\code\week_01\STL\Set_multiset\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Set_multiset.dir/main.cpp.obj"
	D:\SORFTW~1\CLION2~1.3\mingw64\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Set_multiset.dir/main.cpp.obj -MF CMakeFiles\Set_multiset.dir\main.cpp.obj.d -o CMakeFiles\Set_multiset.dir\main.cpp.obj -c D:\SLAM\code\week_01\STL\Set_multiset\main.cpp

CMakeFiles/Set_multiset.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Set_multiset.dir/main.cpp.i"
	D:\SORFTW~1\CLION2~1.3\mingw64\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\SLAM\code\week_01\STL\Set_multiset\main.cpp > CMakeFiles\Set_multiset.dir\main.cpp.i

CMakeFiles/Set_multiset.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Set_multiset.dir/main.cpp.s"
	D:\SORFTW~1\CLION2~1.3\mingw64\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\SLAM\code\week_01\STL\Set_multiset\main.cpp -o CMakeFiles\Set_multiset.dir\main.cpp.s

# Object files for target Set_multiset
Set_multiset_OBJECTS = \
"CMakeFiles/Set_multiset.dir/main.cpp.obj"

# External object files for target Set_multiset
Set_multiset_EXTERNAL_OBJECTS =

Set_multiset.exe: CMakeFiles/Set_multiset.dir/main.cpp.obj
Set_multiset.exe: CMakeFiles/Set_multiset.dir/build.make
Set_multiset.exe: CMakeFiles/Set_multiset.dir/linklibs.rsp
Set_multiset.exe: CMakeFiles/Set_multiset.dir/objects1.rsp
Set_multiset.exe: CMakeFiles/Set_multiset.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\SLAM\code\week_01\STL\Set_multiset\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Set_multiset.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Set_multiset.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Set_multiset.dir/build: Set_multiset.exe
.PHONY : CMakeFiles/Set_multiset.dir/build

CMakeFiles/Set_multiset.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Set_multiset.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Set_multiset.dir/clean

CMakeFiles/Set_multiset.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\SLAM\code\week_01\STL\Set_multiset D:\SLAM\code\week_01\STL\Set_multiset D:\SLAM\code\week_01\STL\Set_multiset\cmake-build-debug D:\SLAM\code\week_01\STL\Set_multiset\cmake-build-debug D:\SLAM\code\week_01\STL\Set_multiset\cmake-build-debug\CMakeFiles\Set_multiset.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Set_multiset.dir/depend

