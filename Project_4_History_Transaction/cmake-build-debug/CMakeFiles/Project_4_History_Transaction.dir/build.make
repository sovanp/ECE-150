# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /cygdrive/c/Users/sovan/AppData/Local/JetBrains/CLion2021.1/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/sovan/AppData/Local/JetBrains/CLion2021.1/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/e/Dell_XPS_Backup/CLionProjects/Project_4_History_Transaction

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/e/Dell_XPS_Backup/CLionProjects/Project_4_History_Transaction/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Project_4_History_Transaction.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Project_4_History_Transaction.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project_4_History_Transaction.dir/flags.make

CMakeFiles/Project_4_History_Transaction.dir/main.cpp.o: CMakeFiles/Project_4_History_Transaction.dir/flags.make
CMakeFiles/Project_4_History_Transaction.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/e/Dell_XPS_Backup/CLionProjects/Project_4_History_Transaction/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Project_4_History_Transaction.dir/main.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_4_History_Transaction.dir/main.cpp.o -c /cygdrive/e/Dell_XPS_Backup/CLionProjects/Project_4_History_Transaction/main.cpp

CMakeFiles/Project_4_History_Transaction.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_4_History_Transaction.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/e/Dell_XPS_Backup/CLionProjects/Project_4_History_Transaction/main.cpp > CMakeFiles/Project_4_History_Transaction.dir/main.cpp.i

CMakeFiles/Project_4_History_Transaction.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_4_History_Transaction.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/e/Dell_XPS_Backup/CLionProjects/Project_4_History_Transaction/main.cpp -o CMakeFiles/Project_4_History_Transaction.dir/main.cpp.s

# Object files for target Project_4_History_Transaction
Project_4_History_Transaction_OBJECTS = \
"CMakeFiles/Project_4_History_Transaction.dir/main.cpp.o"

# External object files for target Project_4_History_Transaction
Project_4_History_Transaction_EXTERNAL_OBJECTS =

Project_4_History_Transaction.exe: CMakeFiles/Project_4_History_Transaction.dir/main.cpp.o
Project_4_History_Transaction.exe: CMakeFiles/Project_4_History_Transaction.dir/build.make
Project_4_History_Transaction.exe: CMakeFiles/Project_4_History_Transaction.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/e/Dell_XPS_Backup/CLionProjects/Project_4_History_Transaction/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Project_4_History_Transaction.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Project_4_History_Transaction.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project_4_History_Transaction.dir/build: Project_4_History_Transaction.exe

.PHONY : CMakeFiles/Project_4_History_Transaction.dir/build

CMakeFiles/Project_4_History_Transaction.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Project_4_History_Transaction.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Project_4_History_Transaction.dir/clean

CMakeFiles/Project_4_History_Transaction.dir/depend:
	cd /cygdrive/e/Dell_XPS_Backup/CLionProjects/Project_4_History_Transaction/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/e/Dell_XPS_Backup/CLionProjects/Project_4_History_Transaction /cygdrive/e/Dell_XPS_Backup/CLionProjects/Project_4_History_Transaction /cygdrive/e/Dell_XPS_Backup/CLionProjects/Project_4_History_Transaction/cmake-build-debug /cygdrive/e/Dell_XPS_Backup/CLionProjects/Project_4_History_Transaction/cmake-build-debug /cygdrive/e/Dell_XPS_Backup/CLionProjects/Project_4_History_Transaction/cmake-build-debug/CMakeFiles/Project_4_History_Transaction.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Project_4_History_Transaction.dir/depend
