# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.4/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/vladyslav/Documents/code/cpp/Stickies++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/vladyslav/Documents/code/cpp/Stickies++/build

# Include any dependencies generated for this target.
include CMakeFiles/Stickies++.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Stickies++.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Stickies++.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Stickies++.dir/flags.make

CMakeFiles/Stickies++.dir/src/main.cpp.o: CMakeFiles/Stickies++.dir/flags.make
CMakeFiles/Stickies++.dir/src/main.cpp.o: /Users/vladyslav/Documents/code/cpp/Stickies++/src/main.cpp
CMakeFiles/Stickies++.dir/src/main.cpp.o: CMakeFiles/Stickies++.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/vladyslav/Documents/code/cpp/Stickies++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Stickies++.dir/src/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Stickies++.dir/src/main.cpp.o -MF CMakeFiles/Stickies++.dir/src/main.cpp.o.d -o CMakeFiles/Stickies++.dir/src/main.cpp.o -c /Users/vladyslav/Documents/code/cpp/Stickies++/src/main.cpp

CMakeFiles/Stickies++.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Stickies++.dir/src/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vladyslav/Documents/code/cpp/Stickies++/src/main.cpp > CMakeFiles/Stickies++.dir/src/main.cpp.i

CMakeFiles/Stickies++.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Stickies++.dir/src/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vladyslav/Documents/code/cpp/Stickies++/src/main.cpp -o CMakeFiles/Stickies++.dir/src/main.cpp.s

CMakeFiles/Stickies++.dir/src/NoteWindow.cpp.o: CMakeFiles/Stickies++.dir/flags.make
CMakeFiles/Stickies++.dir/src/NoteWindow.cpp.o: /Users/vladyslav/Documents/code/cpp/Stickies++/src/NoteWindow.cpp
CMakeFiles/Stickies++.dir/src/NoteWindow.cpp.o: CMakeFiles/Stickies++.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/vladyslav/Documents/code/cpp/Stickies++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Stickies++.dir/src/NoteWindow.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Stickies++.dir/src/NoteWindow.cpp.o -MF CMakeFiles/Stickies++.dir/src/NoteWindow.cpp.o.d -o CMakeFiles/Stickies++.dir/src/NoteWindow.cpp.o -c /Users/vladyslav/Documents/code/cpp/Stickies++/src/NoteWindow.cpp

CMakeFiles/Stickies++.dir/src/NoteWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Stickies++.dir/src/NoteWindow.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vladyslav/Documents/code/cpp/Stickies++/src/NoteWindow.cpp > CMakeFiles/Stickies++.dir/src/NoteWindow.cpp.i

CMakeFiles/Stickies++.dir/src/NoteWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Stickies++.dir/src/NoteWindow.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vladyslav/Documents/code/cpp/Stickies++/src/NoteWindow.cpp -o CMakeFiles/Stickies++.dir/src/NoteWindow.cpp.s

# Object files for target Stickies++
Stickies_______OBJECTS = \
"CMakeFiles/Stickies++.dir/src/main.cpp.o" \
"CMakeFiles/Stickies++.dir/src/NoteWindow.cpp.o"

# External object files for target Stickies++
Stickies_______EXTERNAL_OBJECTS =

Stickies++: CMakeFiles/Stickies++.dir/src/main.cpp.o
Stickies++: CMakeFiles/Stickies++.dir/src/NoteWindow.cpp.o
Stickies++: CMakeFiles/Stickies++.dir/build.make
Stickies++: /opt/homebrew/lib/libfltk_images.dylib
Stickies++: /opt/homebrew/lib/libfltk_forms.dylib
Stickies++: /opt/homebrew/lib/libfltk_gl.dylib
Stickies++: /opt/homebrew/lib/libfltk.dylib
Stickies++: CMakeFiles/Stickies++.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/vladyslav/Documents/code/cpp/Stickies++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Stickies++"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Stickies++.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Stickies++.dir/build: Stickies++
.PHONY : CMakeFiles/Stickies++.dir/build

CMakeFiles/Stickies++.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Stickies++.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Stickies++.dir/clean

CMakeFiles/Stickies++.dir/depend:
	cd /Users/vladyslav/Documents/code/cpp/Stickies++/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/vladyslav/Documents/code/cpp/Stickies++ /Users/vladyslav/Documents/code/cpp/Stickies++ /Users/vladyslav/Documents/code/cpp/Stickies++/build /Users/vladyslav/Documents/code/cpp/Stickies++/build /Users/vladyslav/Documents/code/cpp/Stickies++/build/CMakeFiles/Stickies++.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Stickies++.dir/depend

