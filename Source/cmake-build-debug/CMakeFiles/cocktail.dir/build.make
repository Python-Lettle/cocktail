# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /tmp/tmp.RV7yFDR3Zp/Source

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/tmp.RV7yFDR3Zp/Source/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cocktail.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cocktail.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cocktail.dir/flags.make

CMakeFiles/cocktail.dir/cot_debug.c.o: CMakeFiles/cocktail.dir/flags.make
CMakeFiles/cocktail.dir/cot_debug.c.o: ../cot_debug.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.RV7yFDR3Zp/Source/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cocktail.dir/cot_debug.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cocktail.dir/cot_debug.c.o   -c /tmp/tmp.RV7yFDR3Zp/Source/cot_debug.c

CMakeFiles/cocktail.dir/cot_debug.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cocktail.dir/cot_debug.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.RV7yFDR3Zp/Source/cot_debug.c > CMakeFiles/cocktail.dir/cot_debug.c.i

CMakeFiles/cocktail.dir/cot_debug.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cocktail.dir/cot_debug.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.RV7yFDR3Zp/Source/cot_debug.c -o CMakeFiles/cocktail.dir/cot_debug.c.s

CMakeFiles/cocktail.dir/cot_stack.c.o: CMakeFiles/cocktail.dir/flags.make
CMakeFiles/cocktail.dir/cot_stack.c.o: ../cot_stack.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.RV7yFDR3Zp/Source/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/cocktail.dir/cot_stack.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cocktail.dir/cot_stack.c.o   -c /tmp/tmp.RV7yFDR3Zp/Source/cot_stack.c

CMakeFiles/cocktail.dir/cot_stack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cocktail.dir/cot_stack.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.RV7yFDR3Zp/Source/cot_stack.c > CMakeFiles/cocktail.dir/cot_stack.c.i

CMakeFiles/cocktail.dir/cot_stack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cocktail.dir/cot_stack.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.RV7yFDR3Zp/Source/cot_stack.c -o CMakeFiles/cocktail.dir/cot_stack.c.s

CMakeFiles/cocktail.dir/cot_lexer.c.o: CMakeFiles/cocktail.dir/flags.make
CMakeFiles/cocktail.dir/cot_lexer.c.o: ../cot_lexer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.RV7yFDR3Zp/Source/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/cocktail.dir/cot_lexer.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cocktail.dir/cot_lexer.c.o   -c /tmp/tmp.RV7yFDR3Zp/Source/cot_lexer.c

CMakeFiles/cocktail.dir/cot_lexer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cocktail.dir/cot_lexer.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.RV7yFDR3Zp/Source/cot_lexer.c > CMakeFiles/cocktail.dir/cot_lexer.c.i

CMakeFiles/cocktail.dir/cot_lexer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cocktail.dir/cot_lexer.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.RV7yFDR3Zp/Source/cot_lexer.c -o CMakeFiles/cocktail.dir/cot_lexer.c.s

CMakeFiles/cocktail.dir/cot_parser.c.o: CMakeFiles/cocktail.dir/flags.make
CMakeFiles/cocktail.dir/cot_parser.c.o: ../cot_parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.RV7yFDR3Zp/Source/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/cocktail.dir/cot_parser.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cocktail.dir/cot_parser.c.o   -c /tmp/tmp.RV7yFDR3Zp/Source/cot_parser.c

CMakeFiles/cocktail.dir/cot_parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cocktail.dir/cot_parser.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.RV7yFDR3Zp/Source/cot_parser.c > CMakeFiles/cocktail.dir/cot_parser.c.i

CMakeFiles/cocktail.dir/cot_parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cocktail.dir/cot_parser.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.RV7yFDR3Zp/Source/cot_parser.c -o CMakeFiles/cocktail.dir/cot_parser.c.s

CMakeFiles/cocktail.dir/cot_util.c.o: CMakeFiles/cocktail.dir/flags.make
CMakeFiles/cocktail.dir/cot_util.c.o: ../cot_util.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.RV7yFDR3Zp/Source/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/cocktail.dir/cot_util.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cocktail.dir/cot_util.c.o   -c /tmp/tmp.RV7yFDR3Zp/Source/cot_util.c

CMakeFiles/cocktail.dir/cot_util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cocktail.dir/cot_util.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.RV7yFDR3Zp/Source/cot_util.c > CMakeFiles/cocktail.dir/cot_util.c.i

CMakeFiles/cocktail.dir/cot_util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cocktail.dir/cot_util.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.RV7yFDR3Zp/Source/cot_util.c -o CMakeFiles/cocktail.dir/cot_util.c.s

CMakeFiles/cocktail.dir/main.c.o: CMakeFiles/cocktail.dir/flags.make
CMakeFiles/cocktail.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.RV7yFDR3Zp/Source/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/cocktail.dir/main.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cocktail.dir/main.c.o   -c /tmp/tmp.RV7yFDR3Zp/Source/main.c

CMakeFiles/cocktail.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cocktail.dir/main.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.RV7yFDR3Zp/Source/main.c > CMakeFiles/cocktail.dir/main.c.i

CMakeFiles/cocktail.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cocktail.dir/main.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.RV7yFDR3Zp/Source/main.c -o CMakeFiles/cocktail.dir/main.c.s

# Object files for target cocktail
cocktail_OBJECTS = \
"CMakeFiles/cocktail.dir/cot_debug.c.o" \
"CMakeFiles/cocktail.dir/cot_stack.c.o" \
"CMakeFiles/cocktail.dir/cot_lexer.c.o" \
"CMakeFiles/cocktail.dir/cot_parser.c.o" \
"CMakeFiles/cocktail.dir/cot_util.c.o" \
"CMakeFiles/cocktail.dir/main.c.o"

# External object files for target cocktail
cocktail_EXTERNAL_OBJECTS =

cocktail: CMakeFiles/cocktail.dir/cot_debug.c.o
cocktail: CMakeFiles/cocktail.dir/cot_stack.c.o
cocktail: CMakeFiles/cocktail.dir/cot_lexer.c.o
cocktail: CMakeFiles/cocktail.dir/cot_parser.c.o
cocktail: CMakeFiles/cocktail.dir/cot_util.c.o
cocktail: CMakeFiles/cocktail.dir/main.c.o
cocktail: CMakeFiles/cocktail.dir/build.make
cocktail: CMakeFiles/cocktail.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.RV7yFDR3Zp/Source/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable cocktail"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cocktail.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cocktail.dir/build: cocktail

.PHONY : CMakeFiles/cocktail.dir/build

CMakeFiles/cocktail.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cocktail.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cocktail.dir/clean

CMakeFiles/cocktail.dir/depend:
	cd /tmp/tmp.RV7yFDR3Zp/Source/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.RV7yFDR3Zp/Source /tmp/tmp.RV7yFDR3Zp/Source /tmp/tmp.RV7yFDR3Zp/Source/cmake-build-debug /tmp/tmp.RV7yFDR3Zp/Source/cmake-build-debug /tmp/tmp.RV7yFDR3Zp/Source/cmake-build-debug/CMakeFiles/cocktail.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cocktail.dir/depend

