# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/dodo/workplace/IgtaiProject-1/V1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dodo/workplace/IgtaiProject-1/V1/build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/src/main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/main.dir/src/main.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dodo/workplace/IgtaiProject-1/V1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/main.cpp.o -MF CMakeFiles/main.dir/src/main.cpp.o.d -o CMakeFiles/main.dir/src/main.cpp.o -c /home/dodo/workplace/IgtaiProject-1/V1/src/main.cpp

CMakeFiles/main.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dodo/workplace/IgtaiProject-1/V1/src/main.cpp > CMakeFiles/main.dir/src/main.cpp.i

CMakeFiles/main.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dodo/workplace/IgtaiProject-1/V1/src/main.cpp -o CMakeFiles/main.dir/src/main.cpp.s

CMakeFiles/main.dir/src/glad.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/glad.c.o: ../src/glad.c
CMakeFiles/main.dir/src/glad.c.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dodo/workplace/IgtaiProject-1/V1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/main.dir/src/glad.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/src/glad.c.o -MF CMakeFiles/main.dir/src/glad.c.o.d -o CMakeFiles/main.dir/src/glad.c.o -c /home/dodo/workplace/IgtaiProject-1/V1/src/glad.c

CMakeFiles/main.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/src/glad.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dodo/workplace/IgtaiProject-1/V1/src/glad.c > CMakeFiles/main.dir/src/glad.c.i

CMakeFiles/main.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/src/glad.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dodo/workplace/IgtaiProject-1/V1/src/glad.c -o CMakeFiles/main.dir/src/glad.c.s

CMakeFiles/main.dir/src/window.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/window.cpp.o: ../src/window.cpp
CMakeFiles/main.dir/src/window.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dodo/workplace/IgtaiProject-1/V1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/src/window.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/window.cpp.o -MF CMakeFiles/main.dir/src/window.cpp.o.d -o CMakeFiles/main.dir/src/window.cpp.o -c /home/dodo/workplace/IgtaiProject-1/V1/src/window.cpp

CMakeFiles/main.dir/src/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dodo/workplace/IgtaiProject-1/V1/src/window.cpp > CMakeFiles/main.dir/src/window.cpp.i

CMakeFiles/main.dir/src/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dodo/workplace/IgtaiProject-1/V1/src/window.cpp -o CMakeFiles/main.dir/src/window.cpp.s

CMakeFiles/main.dir/src/shader.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/shader.cpp.o: ../src/shader.cpp
CMakeFiles/main.dir/src/shader.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dodo/workplace/IgtaiProject-1/V1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/src/shader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/shader.cpp.o -MF CMakeFiles/main.dir/src/shader.cpp.o.d -o CMakeFiles/main.dir/src/shader.cpp.o -c /home/dodo/workplace/IgtaiProject-1/V1/src/shader.cpp

CMakeFiles/main.dir/src/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dodo/workplace/IgtaiProject-1/V1/src/shader.cpp > CMakeFiles/main.dir/src/shader.cpp.i

CMakeFiles/main.dir/src/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dodo/workplace/IgtaiProject-1/V1/src/shader.cpp -o CMakeFiles/main.dir/src/shader.cpp.s

CMakeFiles/main.dir/src/mesh.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/mesh.cpp.o: ../src/mesh.cpp
CMakeFiles/main.dir/src/mesh.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dodo/workplace/IgtaiProject-1/V1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main.dir/src/mesh.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/mesh.cpp.o -MF CMakeFiles/main.dir/src/mesh.cpp.o.d -o CMakeFiles/main.dir/src/mesh.cpp.o -c /home/dodo/workplace/IgtaiProject-1/V1/src/mesh.cpp

CMakeFiles/main.dir/src/mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/mesh.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dodo/workplace/IgtaiProject-1/V1/src/mesh.cpp > CMakeFiles/main.dir/src/mesh.cpp.i

CMakeFiles/main.dir/src/mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/mesh.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dodo/workplace/IgtaiProject-1/V1/src/mesh.cpp -o CMakeFiles/main.dir/src/mesh.cpp.s

CMakeFiles/main.dir/src/bezierCurve.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/bezierCurve.cpp.o: ../src/bezierCurve.cpp
CMakeFiles/main.dir/src/bezierCurve.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dodo/workplace/IgtaiProject-1/V1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/main.dir/src/bezierCurve.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/bezierCurve.cpp.o -MF CMakeFiles/main.dir/src/bezierCurve.cpp.o.d -o CMakeFiles/main.dir/src/bezierCurve.cpp.o -c /home/dodo/workplace/IgtaiProject-1/V1/src/bezierCurve.cpp

CMakeFiles/main.dir/src/bezierCurve.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/bezierCurve.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dodo/workplace/IgtaiProject-1/V1/src/bezierCurve.cpp > CMakeFiles/main.dir/src/bezierCurve.cpp.i

CMakeFiles/main.dir/src/bezierCurve.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/bezierCurve.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dodo/workplace/IgtaiProject-1/V1/src/bezierCurve.cpp -o CMakeFiles/main.dir/src/bezierCurve.cpp.s

CMakeFiles/main.dir/src/bezierSurface.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/bezierSurface.cpp.o: ../src/bezierSurface.cpp
CMakeFiles/main.dir/src/bezierSurface.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dodo/workplace/IgtaiProject-1/V1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/main.dir/src/bezierSurface.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/bezierSurface.cpp.o -MF CMakeFiles/main.dir/src/bezierSurface.cpp.o.d -o CMakeFiles/main.dir/src/bezierSurface.cpp.o -c /home/dodo/workplace/IgtaiProject-1/V1/src/bezierSurface.cpp

CMakeFiles/main.dir/src/bezierSurface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/bezierSurface.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dodo/workplace/IgtaiProject-1/V1/src/bezierSurface.cpp > CMakeFiles/main.dir/src/bezierSurface.cpp.i

CMakeFiles/main.dir/src/bezierSurface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/bezierSurface.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dodo/workplace/IgtaiProject-1/V1/src/bezierSurface.cpp -o CMakeFiles/main.dir/src/bezierSurface.cpp.s

CMakeFiles/main.dir/src/camera.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/camera.cpp.o: ../src/camera.cpp
CMakeFiles/main.dir/src/camera.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dodo/workplace/IgtaiProject-1/V1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/main.dir/src/camera.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/camera.cpp.o -MF CMakeFiles/main.dir/src/camera.cpp.o.d -o CMakeFiles/main.dir/src/camera.cpp.o -c /home/dodo/workplace/IgtaiProject-1/V1/src/camera.cpp

CMakeFiles/main.dir/src/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dodo/workplace/IgtaiProject-1/V1/src/camera.cpp > CMakeFiles/main.dir/src/camera.cpp.i

CMakeFiles/main.dir/src/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dodo/workplace/IgtaiProject-1/V1/src/camera.cpp -o CMakeFiles/main.dir/src/camera.cpp.s

CMakeFiles/main.dir/src/surfaceMesh.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/surfaceMesh.cpp.o: ../src/surfaceMesh.cpp
CMakeFiles/main.dir/src/surfaceMesh.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dodo/workplace/IgtaiProject-1/V1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/main.dir/src/surfaceMesh.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/surfaceMesh.cpp.o -MF CMakeFiles/main.dir/src/surfaceMesh.cpp.o.d -o CMakeFiles/main.dir/src/surfaceMesh.cpp.o -c /home/dodo/workplace/IgtaiProject-1/V1/src/surfaceMesh.cpp

CMakeFiles/main.dir/src/surfaceMesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/surfaceMesh.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dodo/workplace/IgtaiProject-1/V1/src/surfaceMesh.cpp > CMakeFiles/main.dir/src/surfaceMesh.cpp.i

CMakeFiles/main.dir/src/surfaceMesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/surfaceMesh.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dodo/workplace/IgtaiProject-1/V1/src/surfaceMesh.cpp -o CMakeFiles/main.dir/src/surfaceMesh.cpp.s

CMakeFiles/main.dir/src/normalMesh.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/normalMesh.cpp.o: ../src/normalMesh.cpp
CMakeFiles/main.dir/src/normalMesh.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dodo/workplace/IgtaiProject-1/V1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/main.dir/src/normalMesh.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/normalMesh.cpp.o -MF CMakeFiles/main.dir/src/normalMesh.cpp.o.d -o CMakeFiles/main.dir/src/normalMesh.cpp.o -c /home/dodo/workplace/IgtaiProject-1/V1/src/normalMesh.cpp

CMakeFiles/main.dir/src/normalMesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/normalMesh.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dodo/workplace/IgtaiProject-1/V1/src/normalMesh.cpp > CMakeFiles/main.dir/src/normalMesh.cpp.i

CMakeFiles/main.dir/src/normalMesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/normalMesh.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dodo/workplace/IgtaiProject-1/V1/src/normalMesh.cpp -o CMakeFiles/main.dir/src/normalMesh.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/src/main.cpp.o" \
"CMakeFiles/main.dir/src/glad.c.o" \
"CMakeFiles/main.dir/src/window.cpp.o" \
"CMakeFiles/main.dir/src/shader.cpp.o" \
"CMakeFiles/main.dir/src/mesh.cpp.o" \
"CMakeFiles/main.dir/src/bezierCurve.cpp.o" \
"CMakeFiles/main.dir/src/bezierSurface.cpp.o" \
"CMakeFiles/main.dir/src/camera.cpp.o" \
"CMakeFiles/main.dir/src/surfaceMesh.cpp.o" \
"CMakeFiles/main.dir/src/normalMesh.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/src/main.cpp.o
main: CMakeFiles/main.dir/src/glad.c.o
main: CMakeFiles/main.dir/src/window.cpp.o
main: CMakeFiles/main.dir/src/shader.cpp.o
main: CMakeFiles/main.dir/src/mesh.cpp.o
main: CMakeFiles/main.dir/src/bezierCurve.cpp.o
main: CMakeFiles/main.dir/src/bezierSurface.cpp.o
main: CMakeFiles/main.dir/src/camera.cpp.o
main: CMakeFiles/main.dir/src/surfaceMesh.cpp.o
main: CMakeFiles/main.dir/src/normalMesh.cpp.o
main: CMakeFiles/main.dir/build.make
main: /usr/lib/x86_64-linux-gnu/libglfw.so.3.3
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dodo/workplace/IgtaiProject-1/V1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /home/dodo/workplace/IgtaiProject-1/V1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dodo/workplace/IgtaiProject-1/V1 /home/dodo/workplace/IgtaiProject-1/V1 /home/dodo/workplace/IgtaiProject-1/V1/build /home/dodo/workplace/IgtaiProject-1/V1/build /home/dodo/workplace/IgtaiProject-1/V1/build/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

