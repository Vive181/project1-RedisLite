### Date: June 24

### Duration: 120 minutes

## Goal:

Implement a generic hash map using separate chaining for collision handling.

## Work Completed:

* Created a generic `HashMap` class using templates for both key and value types.
* Implemented a generic hash wrapper using `std::hash` to generate hash values for different key types.
* Designed an internal `Node` structure to store key-value pairs and support linked-list chaining.
* Implemented the default constructor to initialize the bucket array and set the initial bucket count.
* Implemented `insert()` to add new key-value pairs and update existing values when duplicate keys are inserted.
* Implemented `find()` (const and non-const versions) to search for values associated with a given key.
* Implemented `contains()` to check whether a key exists in the hash map.
* Implemented `remove()` to delete key-value pairs while maintaining the linked list structure within each bucket.
* Implemented `size()` and `isEmpty()` to provide information about the current state of the hash map.
* Implemented `clear()` to remove all stored key-value pairs and reset the buckets.
* Implemented automatic rehashing based on a load factor threshold to improve lookup and insertion performance as the number of stored elements grows.

## Problem Encountered:

The primary challenge was implementing the rehashing process correctly while ensuring that all existing key-value pairs were redistributed into the new bucket array without data loss.

## What I Tried:

* Verified that the hash index was recalculated using the updated bucket count after resizing.
* Tested insertion with multiple keys to trigger automatic rehashing.
* Checked that existing keys remained accessible after the bucket array was expanded.
* Tested collision scenarios by inserting multiple keys that mapped to the same bucket and verified correct traversal during search and deletion.
* Validated insertion, lookup, update, and removal operations using different test cases.

## Outcome:

Successfully implemented a generic hash map supporting insertion, search, update, deletion, collision handling through separate chaining, automatic rehashing, and complete memory cleanup. Testing confirmed that all operations functioned correctly before and after rehashing, and the data structure maintained efficient performance as the number of stored elements increased.
