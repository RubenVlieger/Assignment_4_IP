# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\RC1ki\OneDrive\Documents\Uni\Imperative Programming\IPC031_2022_assignment_6_files"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\RC1ki\OneDrive\Documents\Uni\Imperative Programming\IPC031_2022_assignment_6_files\build"

# Include any dependencies generated for this target.
include CMakeFiles/Assignment6.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Assignment6.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Assignment6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Assignment6.dir/flags.make

CMakeFiles/Assignment6.dir/main.cpp.obj: CMakeFiles/Assignment6.dir/flags.make
CMakeFiles/Assignment6.dir/main.cpp.obj: C:/Users/RC1ki/OneDrive/Documents/Uni/Imperative\ Programming/IPC031_2022_assignment_6_files/main.cpp
CMakeFiles/Assignment6.dir/main.cpp.obj: CMakeFiles/Assignment6.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\RC1ki\OneDrive\Documents\Uni\Imperative Programming\IPC031_2022_assignment_6_files\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Assignment6.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Assignment6.dir/main.cpp.obj -MF CMakeFiles\Assignment6.dir\main.cpp.obj.d -o CMakeFiles\Assignment6.dir\main.cpp.obj -c "C:\Users\RC1ki\OneDrive\Documents\Uni\Imperative Programming\IPC031_2022_assignment_6_files\main.cpp"

CMakeFiles/Assignment6.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment6.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\RC1ki\OneDrive\Documents\Uni\Imperative Programming\IPC031_2022_assignment_6_files\main.cpp" > CMakeFiles\Assignment6.dir\main.cpp.i

CMakeFiles/Assignment6.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment6.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\RC1ki\OneDrive\Documents\Uni\Imperative Programming\IPC031_2022_assignment_6_files\main.cpp" -o CMakeFiles\Assignment6.dir\main.cpp.s

# Object files for target Assignment6
Assignment6_OBJECTS = \
"CMakeFiles/Assignment6.dir/main.cpp.obj"

# External object files for target Assignment6
Assignment6_EXTERNAL_OBJECTS =

main.exe: CMakeFiles/Assignment6.dir/main.cpp.obj
main.exe: CMakeFiles/Assignment6.dir/build.make
main.exe: CMakeFiles/Assignment6.dir/linklibs.rsp
main.exe: CMakeFiles/Assignment6.dir/objects1.rsp
main.exe: CMakeFiles/Assignment6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\RC1ki\OneDrive\Documents\Uni\Imperative Programming\IPC031_2022_assignment_6_files\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable main.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Assignment6.dir\link.txt --verbose=$(VERBOSE)
	"C:\Program Files\CMake\bin\cmake.exe" -E copy_directory "C:/Users/RC1ki/OneDrive/Documents/Uni/Imperative Programming/IPC031_2022_assignment_6_files/files/" "C:/Users/RC1ki/OneDrive/Documents/Uni/Imperative Programming/IPC031_2022_assignment_6_files/build"

# Rule to build all files generated by this target.
CMakeFiles/Assignment6.dir/build: main.exe
.PHONY : CMakeFiles/Assignment6.dir/build

CMakeFiles/Assignment6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Assignment6.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Assignment6.dir/clean

CMakeFiles/Assignment6.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\RC1ki\OneDrive\Documents\Uni\Imperative Programming\IPC031_2022_assignment_6_files" "C:\Users\RC1ki\OneDrive\Documents\Uni\Imperative Programming\IPC031_2022_assignment_6_files" "C:\Users\RC1ki\OneDrive\Documents\Uni\Imperative Programming\IPC031_2022_assignment_6_files\build" "C:\Users\RC1ki\OneDrive\Documents\Uni\Imperative Programming\IPC031_2022_assignment_6_files\build" "C:\Users\RC1ki\OneDrive\Documents\Uni\Imperative Programming\IPC031_2022_assignment_6_files\build\CMakeFiles\Assignment6.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Assignment6.dir/depend

