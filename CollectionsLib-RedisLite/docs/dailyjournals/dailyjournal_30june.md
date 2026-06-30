### Date: June 30

## section 1 : todays goal

The main objective for today was to integrate Google Test into the CollectionsLib-RedisLite project and build a comprehensive unit testing framework for the implemented data structures. The focus was on validating the correctness, exception handling, template support, and memory behavior of the following components:

1.Dynamic Array
2.Singly Linked List
3.Doubly Linked List

## section 2 : What I Performed

1. Google Test Integration

Studied the fundamentals of the Google Test framework.
Learned commonly used testing macros such as:

TEST
TEST_F
EXPECT_EQ
EXPECT_TRUE
EXPECT_FALSE
EXPECT_THROW

Integrated Google Test into the project using CMake FetchContent.
Configured the project build system for automated unit testing.

2. Build System Configuration

Investigated compilation failures caused by an outdated MinGW GCC 6.3.0 compiler.
Identified CMake generator conflicts between:
NMake Makefiles
MinGW Makefiles
Recreated the build directory and regenerated the project using the correct generator.
Successfully generated and executed the test executable.

3. Dynamic Array Testing

Created comprehensive Google Test cases covering:

Construction and initialization
pushBack()
insert()
remove()
get()
set()
clear()
isEmpty()
getSize()
Exception handling
Boundary conditions
Deep copy verification
Resize operations
User-defined object support

4. Singly Linked List Testing

Implemented test cases for:

insertFront()
get()
set()
clear()
isEmpty()
getSize()
Invalid index handling
Empty list behavior
Template support with custom objects

5. Doubly Linked List Testing

Implemented test cases for:

insertBack()
remove()
get()
set()
clear()
getSize()
Exception handling
Pointer consistency
Head and tail updates
Custom object validation
Challenges Faced
Google Test Integration
Google Test failed to compile due to an outdated compiler.
CMake generator mismatch prevented successful project generation.
Test executable was not generated until the build configuration was corrected.
Singly Linked List
Invalid index access caused runtime errors.
clear() did not completely reset the internal state of the list.
Doubly Linked List
remove() failed to correctly update neighboring node pointers.
head and tail pointers were not properly maintained after deletion.
Invalid index handling required additional validation.

## section 3 : What I Tried

Google Test
Researched Google Test documentation and testing practices.
Configured Google Test using FetchContent in CMake.
Investigated compiler compatibility issues.
Removed the old build directory and regenerated the project.
Verified the generated executable by running all tests.

# Dynamic Array

Planned approximately three test cases for every public function.
Added custom object tests to validate:
Object construction
Copy behavior
Resize correctness
Destructor execution
Tested deep copy behavior during array resizing.

# Singly Linked List

-Added boundary checks to get() and set().
-Introduced std::out_of_range exceptions for invalid indices.
-Verified that clear() deleted every node and reset the list state.
-Executed Google Test after every implementation update.

# Doubly Linked List

-Reviewed pointer manipulation logic inside remove().
-Corrected updates for both prev and next pointers.
-Ensured proper maintenance of head and tail.
-Added exception handling for invalid index access.
-Validated behavior on empty lists and custom objects.

Testing Summary

Component	            TestCases	    Result
Dynamic Array	             29	        ✅ All Passed
Singly Linked List	         21	        ✅ All Passed
Doubly Linked List	         21	        ✅ All Passed

Total Unit Tests Executed: 71

## Section 4: Key Learnings

-Learned how to integrate Google Test into a CMake-based C++ project.
-Improved understanding of automated unit testing and test organization.
-Learned effective debugging strategies for CMake configuration issues.
-Gained experience writing reusable template-based tests.
-Reinforced the importance of boundary testing and exception validation.
-Understood how to verify deep copy semantics and memory correctness for template containers.
-Improved confidence in debugging pointer-related issues in linked list implementations.

## Section 5 : Outcome

-Successfully integrated Google Test into the project.
-Resolved compiler compatibility and CMake configuration issues.
-Built and executed the Dynamic Array test suite successfully.
-Verified that Dynamic Array correctly handles primitive and user-defined data types.
-Fixed all identified issues in the Singly Linked List implementation.
-Corrected pointer management and exception handling in the Doubly Linked List.
-Achieved 100% passing results across all implemented unit tests (71/71 tests passed).
-Established a reusable testing strategy of creating multiple test cases for every public function, including edge cases, exception scenarios, and custom object validation, which can be applied to future data structures in the project.