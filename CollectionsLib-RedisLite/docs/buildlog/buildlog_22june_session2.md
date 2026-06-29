Date:June 22
Duration: 120 minutes

Goal: Implement functions for the `DynamicArray` class.

Work Completed:

* Implemented the `resize()` function to automatically expand the array when it reaches full capacity.
* Implemented the default constructor to initialize the dynamic array.
* Implemented the destructor to properly clean up all stored objects.
* Added a copy constructor to support deep copying of dynamic arrays.
* Implemented the copy assignment operator to correctly copy one dynamic array into another while handling self-assignment.
* Implemented `pushBack()` to insert new elements at the end of the array.
* Implemented `get()` with bounds checking to safely access elements.
* Implemented `set()` to update elements at a valid index.
* Implemented `popBack()` to remove the last element from the array.
* Implemented utility functions: `getSize()`, `isEmpty()`, and `clear()`.

Problem Encountered:

A segmentation fault occurred after the 9th insertion while testing the resize functionality.

What I Tried:

* Reviewed the capacity update logic.
* Added print statements to trace the element copy process during resizing.
* Verified the values of `size` and `capacity` before and after resizing.

Outcome:

The issue was caused by the copy loop iterating up to `capacity` instead of `size`. This resulted in accessing memory beyond the valid elements and caused a segmentation fault. After modifying the loop to copy only the existing elements (`size`), the resize operation worked correctly, and all insertions completed successfully.
