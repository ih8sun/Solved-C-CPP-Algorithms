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
CMAKE_SOURCE_DIR = "C:\Users\el pepe\Documents\prueba\maquina"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\el pepe\Documents\prueba\maquina\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/maquina.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/maquina.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/maquina.dir/flags.make

CMakeFiles/maquina.dir/main.cpp.obj: CMakeFiles/maquina.dir/flags.make
CMakeFiles/maquina.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\el pepe\Documents\prueba\maquina\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/maquina.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\maquina.dir\main.cpp.obj -c "C:\Users\el pepe\Documents\prueba\maquina\main.cpp"

CMakeFiles/maquina.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/maquina.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\el pepe\Documents\prueba\maquina\main.cpp" > CMakeFiles\maquina.dir\main.cpp.i

CMakeFiles/maquina.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/maquina.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\el pepe\Documents\prueba\maquina\main.cpp" -o CMakeFiles\maquina.dir\main.cpp.s

# Object files for target maquina
maquina_OBJECTS = \
"CMakeFiles/maquina.dir/main.cpp.obj"

# External object files for target maquina
maquina_EXTERNAL_OBJECTS =

maquina.exe: CMakeFiles/maquina.dir/main.cpp.obj
maquina.exe: CMakeFiles/maquina.dir/build.make
maquina.exe: CMakeFiles/maquina.dir/linklibs.rsp
maquina.exe: CMakeFiles/maquina.dir/objects1.rsp
maquina.exe: CMakeFiles/maquina.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\el pepe\Documents\prueba\maquina\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable maquina.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\maquina.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/maquina.dir/build: maquina.exe

.PHONY : CMakeFiles/maquina.dir/build

CMakeFiles/maquina.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\maquina.dir\cmake_clean.cmake
.PHONY : CMakeFiles/maquina.dir/clean

CMakeFiles/maquina.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\el pepe\Documents\prueba\maquina" "C:\Users\el pepe\Documents\prueba\maquina" "C:\Users\el pepe\Documents\prueba\maquina\cmake-build-debug" "C:\Users\el pepe\Documents\prueba\maquina\cmake-build-debug" "C:\Users\el pepe\Documents\prueba\maquina\cmake-build-debug\CMakeFiles\maquina.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/maquina.dir/depend

