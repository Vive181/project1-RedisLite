### Daily Design Journal · 25-june.md

### Section 1 — Specific Bug:

vivek@LAPTOP-8GRHFCJA MINGW64 /d/projects/RedisLite/CollectionsLib-RedisLite (main)
$ cd build
cmake ..
cmake --build .
-- Building for: NMake Makefiles
CMake Warning (author) in CMakeLists.txt:
  No project() command is present.  The top-level CMakeLists.txt file must
  contain a literal, direct call to the project() command.  Add a line of
  code such as

    project(ProjectName)

  near the top of the file, but after cmake_minimum_required().        

  CMake is pretending there is a "project(Project)" command on the first
  line.
This warning is for project developers.  Use -Wno-author to suppress it.

CMake Warning (author) in CMakeLists.txt:
  cmake_minimum_required() should be called prior to this top-level project()
  call.  Please see the cmake-commands(7) manual for usage documentation of
  both commands.
This warning is for project developers.  Use -Wno-author to suppress it.

CMake Error in CMakeLists.txt:
  Running

   'nmake' '-?'

  failed with:

   no such file or directory


CMake Error: CMAKE_C_COMPILER not set, after EnableLanguage
CMake Error: CMAKE_CXX_COMPILER not set, after EnableLanguage
-- Configuring incomplete, errors occurred!
no such file or directory
CMake Error: Generator: build tool execution failed, command was: nmake -f Makefile /nologo.

### Section 2 — Failed Attempt: 

tried to build redis lite and almost discovered the path to make redislite.

### Section 3 — Memory Diagram:

Hand-drawn memory diagram, photographed and submitted
every day.

### Section 4 — Code Reference: Commit hash, filename, and relevant line numbers.

### Section 5 — Learning Reflection: learns how to make master library using cmake that can be used outside the folder .