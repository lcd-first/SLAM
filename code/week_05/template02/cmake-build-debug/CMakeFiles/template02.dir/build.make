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
CMAKE_SOURCE_DIR = D:\SLAM\code\week_05\template02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\SLAM\code\week_05\template02\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/template02.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/template02.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/template02.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/template02.dir/flags.make

CMakeFiles/template02.dir/main.cpp.obj: CMakeFiles/template02.dir/flags.make
CMakeFiles/template02.dir/main.cpp.obj: ../main.cpp
CMakeFiles/template02.dir/main.cpp.obj: CMakeFiles/template02.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\SLAM\code\week_05\template02\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/template02.dir/main.cpp.obj"
	D:\SORFTW~1\CLION2~1.3\mingw64\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/template02.dir/main.cpp.obj -MF CMakeFiles\template02.dir\main.cpp.obj.d -o CMakeFiles\template02.dir\main.cpp.obj -c D:\SLAM\code\week_05\template02\main.cpp

CMakeFiles/template02.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/template02.dir/main.cpp.i"
	D:\SORFTW~1\CLION2~1.3\mingw64\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\SLAM\code\week_05\template02\main.cpp > CMakeFiles\template02.dir\main.cpp.i

CMakeFiles/template02.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/template02.dir/main.cpp.s"
	D:\SORFTW~1\CLION2~1.3\mingw64\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\SLAM\code\week_05\template02\main.cpp -o CMakeFiles\template02.dir\main.cpp.s

# Object files for target template02
template02_OBJECTS = \
"CMakeFiles/template02.dir/main.cpp.obj"

# External object files for target template02
template02_EXTERNAL_OBJECTS =

template02.exe: CMakeFiles/template02.dir/main.cpp.obj
template02.exe: CMakeFiles/template02.dir/build.make
template02.exe: CMakeFiles/template02.dir/linklibs.rsp
template02.exe: CMakeFiles/template02.dir/objects1.rsp
template02.exe: CMakeFiles/template02.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\SLAM\code\week_05\template02\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable template02.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\template02.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/template02.dir/build: template02.exe
.PHONY : CMakeFiles/template02.dir/build

CMakeFiles/template02.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\template02.dir\cmake_clean.cmake
.PHONY : CMakeFiles/template02.dir/clean

CMakeFiles/template02.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\SLAM\code\week_05\template02 D:\SLAM\code\week_05\template02 D:\SLAM\code\week_05\template02\cmake-build-debug D:\SLAM\code\week_05\template02\cmake-build-debug D:\SLAM\code\week_05\template02\cmake-build-debug\CMakeFiles\template02.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/template02.dir/depend
