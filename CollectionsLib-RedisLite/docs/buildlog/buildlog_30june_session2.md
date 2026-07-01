### Date: June 30

### Duration: 120 minutes

## Goal:

Developed a template based Singly Linked List by implementing Google Test cases for insertFront(), get(), set(), isEmpty(), getSize(), clear(), exception handling, and support for custom objects.

## Problem Encountered:

Several test cases failed because the linked list implementation did not correctly handle invalid indices and clearing the list. Accessing elements outside the valid range caused runtime errors instead of throwing exceptions, and the list state was not properly reset after calling clear().

## What I Tried:

Reviewed the implementation of get() and set() to ensure index bounds were validated.
Added std::out_of_range exceptions for invalid index access.

Verified that clear() deleted every node, reset the head pointer to nullptr, and updated the size to zero.

Executed Google Test after each change to confirm the behavior of insertion, retrieval, modification, clearing, and custom object operations.

## Outcome:

The linked list correctly handled all edge cases, including empty lists and invalid indices. The clear() function released all nodes and reset the list for reuse, while template support worked correctly with custom objects. All 21 Google Test cases passed successfully, confirming the correctness and reliability of the Singly Linked List implementation.