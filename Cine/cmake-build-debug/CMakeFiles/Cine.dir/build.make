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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\el pepe\Documents\plantillasEnC\Cine"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\el pepe\Documents\plantillasEnC\Cine\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Cine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Cine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Cine.dir/flags.make

CMakeFiles/Cine.dir/main.cpp.obj: CMakeFiles/Cine.dir/flags.make
CMakeFiles/Cine.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\el pepe\Documents\plantillasEnC\Cine\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Cine.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Cine.dir\main.cpp.obj -c "C:\Users\el pepe\Documents\plantillasEnC\Cine\main.cpp"

CMakeFiles/Cine.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cine.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\el pepe\Documents\plantillasEnC\Cine\main.cpp" > CMakeFiles\Cine.dir\main.cpp.i

CMakeFiles/Cine.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cine.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\el pepe\Documents\plantillasEnC\Cine\main.cpp" -o CMakeFiles\Cine.dir\main.cpp.s

# Object files for target Cine
Cine_OBJECTS = \
"CMakeFiles/Cine.dir/main.cpp.obj"

# External object files for target Cine
Cine_EXTERNAL_OBJECTS =

Cine.exe: CMakeFiles/Cine.dir/main.cpp.obj
Cine.exe: CMakeFiles/Cine.dir/build.make
Cine.exe: CMakeFiles/Cine.dir/linklibs.rsp
Cine.exe: CMakeFiles/Cine.dir/objects1.rsp
Cine.exe: CMakeFiles/Cine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\el pepe\Documents\plantillasEnC\Cine\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Cine.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Cine.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Cine.dir/build: Cine.exe

.PHONY : CMakeFiles/Cine.dir/build

CMakeFiles/Cine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Cine.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Cine.dir/clean

CMakeFiles/Cine.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\el pepe\Documents\plantillasEnC\Cine" "C:\Users\el pepe\Documents\plantillasEnC\Cine" "C:\Users\el pepe\Documents\plantillasEnC\Cine\cmake-build-debug" "C:\Users\el pepe\Documents\plantillasEnC\Cine\cmake-build-debug" "C:\Users\el pepe\Documents\plantillasEnC\Cine\cmake-build-debug\CMakeFiles\Cine.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Cine.dir/depend

