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
CMAKE_SOURCE_DIR = "C:\Users\el pepe\Documents\plantillasEnC\proyecto"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\el pepe\Documents\plantillasEnC\proyecto\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/proyecto.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/proyecto.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/proyecto.dir/flags.make

CMakeFiles/proyecto.dir/main.cpp.obj: CMakeFiles/proyecto.dir/flags.make
CMakeFiles/proyecto.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\el pepe\Documents\plantillasEnC\proyecto\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/proyecto.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\proyecto.dir\main.cpp.obj -c "C:\Users\el pepe\Documents\plantillasEnC\proyecto\main.cpp"

CMakeFiles/proyecto.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proyecto.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\el pepe\Documents\plantillasEnC\proyecto\main.cpp" > CMakeFiles\proyecto.dir\main.cpp.i

CMakeFiles/proyecto.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proyecto.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\el pepe\Documents\plantillasEnC\proyecto\main.cpp" -o CMakeFiles\proyecto.dir\main.cpp.s

# Object files for target proyecto
proyecto_OBJECTS = \
"CMakeFiles/proyecto.dir/main.cpp.obj"

# External object files for target proyecto
proyecto_EXTERNAL_OBJECTS =

proyecto.exe: CMakeFiles/proyecto.dir/main.cpp.obj
proyecto.exe: CMakeFiles/proyecto.dir/build.make
proyecto.exe: CMakeFiles/proyecto.dir/linklibs.rsp
proyecto.exe: CMakeFiles/proyecto.dir/objects1.rsp
proyecto.exe: CMakeFiles/proyecto.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\el pepe\Documents\plantillasEnC\proyecto\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable proyecto.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\proyecto.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/proyecto.dir/build: proyecto.exe

.PHONY : CMakeFiles/proyecto.dir/build

CMakeFiles/proyecto.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\proyecto.dir\cmake_clean.cmake
.PHONY : CMakeFiles/proyecto.dir/clean

CMakeFiles/proyecto.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\el pepe\Documents\plantillasEnC\proyecto" "C:\Users\el pepe\Documents\plantillasEnC\proyecto" "C:\Users\el pepe\Documents\plantillasEnC\proyecto\cmake-build-debug" "C:\Users\el pepe\Documents\plantillasEnC\proyecto\cmake-build-debug" "C:\Users\el pepe\Documents\plantillasEnC\proyecto\cmake-build-debug\CMakeFiles\proyecto.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/proyecto.dir/depend
