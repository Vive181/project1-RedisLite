## Date: June 30
## Duration: 2 hours 

## Goal:

Develop and validate a template-based Doubly Linked List by creating comprehensive Google Test cases for `insertBack()`, `get()`, `set()`, `remove()`, `clear()`, `getSize()`, exception handling, and support for custom objects.

## Problem Encountered:

Some unit tests failed because the `remove()` operation did not correctly update the `prev` and `next` pointers of neighboring nodes. Additionally, invalid index access in `get()` and `set()` was not properly handled, causing runtime errors instead of exceptions.

## What I Tried:

* Reviewed the implementation of `remove()` to ensure both forward (`next`) and backward (`prev`) links were updated after node deletion.
* Verified that the `head` and `tail` pointers were correctly maintained when removing nodes from the beginning, middle, and end of the list.
* Added index boundary checks in `get()` and `set()` to throw `std::out_of_range` exceptions for invalid indices.
* Tested the implementation with Google Test after each modification, including operations on empty lists and custom objects.

## Outcome:

The pointer update logic was corrected, ensuring the list remained consistent after node removal. Exception handling for invalid indices worked as expected, `clear()` successfully removed all nodes and reset the list, and template support functioned correctly with custom objects. All 21 Google Test cases passed successfully, confirming the correctness and stability of the Doubly Linked List implementation.
