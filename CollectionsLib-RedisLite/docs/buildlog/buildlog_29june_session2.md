### Date: June 29

### Duration: 180 minutes

## Goal:


Learn the Google Test (GTest) framework, understand its syntax and components.

## Problem Encountered:

-Initially, I found it difficult to understand the difference between TEST and TEST_F, and how test fixtures work.
-Google Test failed to compile because the installed MinGW GCC 6.3.0 compiler was incompatible with the downloaded version of GTest.
-CMake generator conflicts (NMake Makefiles vs. MinGW Makefiles) prevented the project from building correctly.
-The test executable was not generated until the build configuration and compiler issues were resolved.

## What I Tried: 

-Studied the official Google Test documentation and example test cases.
-Learned the basic syntax of Google Test, including:
-TEST for writing independent unit tests.
-TEST_F for tests that share a common setup using fixtures.
-Assertions such as EXPECT_EQ, EXPECT_TRUE, EXPECT_FALSE, EXPECT_THROW, and ASSERT_*.
Learned the major components of Google Test:

Test Suites
Test Cases
Test Fixtures
Assertions
Test Runner (gtest_main)

-Understood how fixtures reduce duplicate setup code by initializing common test data before each test.
-Configured Google Test using FetchContent in CMakeLists.txt.
-Investigated compiler compatibility issues and upgraded the build configuration.
-Resolved the CMake generator conflict by recreating the build directory.

## Outcome:

-Successfully learned the syntax and overall workflow of the Google Test framework.
-Gained a clear understanding of the main components of Google Test, including test suites, test cases, fixtures, assertions, and the test runner.
-Learned when to use TEST versus TEST_F and how fixtures simplify writing reusable tests.
-Successfully integrated Google Test into the CollectionsLib-RedisLite project.
