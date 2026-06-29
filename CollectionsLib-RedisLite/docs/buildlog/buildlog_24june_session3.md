Date: June 24

Duration: 120 minutes

Goal:

Research how hash functions work for user-defined data types and understand how custom objects can be used as keys in a hash map.

Work Completed:

* Began studying the concept of hash functions and their role in hash-based data structures.
* Researched how `std::hash` generates hash values for built-in data types.
* Explored why user-defined data types cannot be hashed automatically without providing a custom hash function.
* Studied the requirements for using user-defined types as keys, including implementing a custom hash function and an equality comparison.
* Reviewed examples of combining multiple data members into a single hash value for custom objects.

Problem Encountered:

Initially found it difficult to understand why built-in types work directly with `std::hash` while user-defined classes require a custom hashing strategy. It was also challenging to determine how multiple data members should be combined into a single hash value.

What I Tried:

* Read C++ documentation on `std::hash` and template specialization.
* Studied examples of custom hash functions for classes containing multiple fields.
* Compared the hashing process for primitive data types and user-defined objects.
* Reviewed how equality operators and hash functions work together when storing custom objects in a hash map.

Outcome:

Developed a clear understanding of how hash functions operate for user-defined data types and why custom hash implementations are necessary. 