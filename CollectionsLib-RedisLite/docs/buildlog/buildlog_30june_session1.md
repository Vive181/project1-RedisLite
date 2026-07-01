### Date: June 30

### Duration: 180 minutes

## Goal:

Learn and integrate Google Test (GTest) into the CollectionsLib-RedisLite project and create comprehensive unit tests for the implemented data structures.

## Problem Encountered:

* Google Test failed to compile due to an outdated MinGW GCC 6.3.0 compiler.
* CMake generator mismatch occurred after configuring the project with different generators (`NMake Makefiles` and `MinGW Makefiles`).
* The test executable (`dynamic_array_test.exe`) was not generated until the build configuration was corrected.

## What I Tried

* Researched Google Test framework and its testing macros (`TEST`, `TEST_F`, `EXPECT_EQ`, `EXPECT_THROW`, etc.).
* Configured Google Test using `FetchContent` in `CMakeLists.txt`.
* Investigated compiler compatibility issues and identified that the installed MinGW version was outdated.
* Resolved CMake generator conflicts by recreating the build directory.
* Executed the generated test executable to verify unit tests.
* Expanded the DynamicArray test suite by planning three test cases for every public function.
* Added user-defined datatype (custom object) tests to verify that `DynamicArray` correctly stores, copies, resizes, and destroys complex objects.
* Designed comprehensive testing plans for both Singly Linked List and Doubly Linked List, including three test cases per function and custom object validation.

## Outcome

* Successfully learned the fundamentals of Google Test and how to organize unit tests.
* Successfully built and executed the DynamicArray test suite.
* All **29 DynamicArray unit tests passed** successfully.
* Verified that DynamicArray correctly handles user-defined objects and performs deep copies during resize operations.
* Established a reusable testing strategy of creating three test cases per public function.

