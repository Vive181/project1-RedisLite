Date: June 23

Duration: 120 minutes

Goal:

Implement the core functionality of a generic doubly linked list.

Work Completed:

* Created a generic `DoublyLinkedList` class using templates.
* Implemented the internal `Node` structure containing data, previous, and next pointers.
* Implemented the default constructor to initialize an empty list with `head` and `tail` pointers.
* Implemented the destructor to automatically release all nodes when the list is destroyed.
* Implemented `insertBack()` to insert new elements at the end of the list while maintaining both `head` and `tail` pointers.
* Implemented `get()` with bounds checking to safely access elements by index.
* Implemented `set()` to update the value stored at a specified index.
* Implemented `remove()` to delete the first node containing a specified value while correctly updating neighboring node links, `head`, and `tail` when necessary.
* Implemented `getSize()` to return the current number of elements in the list.
* Implemented `clear()` to remove all nodes and reset the list to its initial empty state.

Problem Encountered:

The main challenge was correctly handling node removal in different cases, such as deleting the first node, the last node, or a node in the middle of the list while maintaining valid `prev` and `next` links.

What I Tried:

* Tested insertion with multiple elements to verify that both `head` and `tail` pointers were updated correctly.
* Traced the `prev` and `next` pointers during removal to ensure neighboring nodes remained properly connected.
* Verified edge cases, including removing the head node, the tail node, and the only node in the list.
* Tested the `clear()` function to confirm that all nodes were removed and the list returned to an empty state.

Outcome:

Successfully implemented a functional doubly linked list supporting insertion at the back, element access, value modification, node removal, size tracking, and complete cleanup. Testing confirmed that node links remained consistent after insertion and deletion operations, and the list handled edge cases correctly.
