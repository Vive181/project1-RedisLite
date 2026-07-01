### Date: June 25

### Duration: 120 minutes

## Goal:

Implement a generic hash function utility capable of generating hash values for primitive types, strings, and user-defined data types.

## Work Completed:

* Created a `HashFunction` class to provide a centralized interface for generating hash values.
* Implemented hashing support for `char` values.
* Implemented hashing support for `bool` values.
* Implemented a polynomial rolling hash algorithm for `std::string` using a multiplier of `31` to reduce collisions.
* Implemented template-based support for user-defined data types by calling a `hashCode()` member function when available.
* Implemented a generic fallback hashing function that computes a hash value by processing the raw bytes of an object.
* Added header guards to prevent multiple inclusion of the hash function implementation.

## Problem Encountered:

Initially found it challenging to design a hash function that could support both built-in data types and user-defined classes while keeping the implementation generic. It also required understanding how the compiler selects the correct template overload.

## What I Tried:

* Researched how hash functions are implemented for primitive data types.
* Studied polynomial rolling hash algorithms for strings and the reason for using a prime multiplier such as `31`.
* Explored template programming, `decltype`, and trailing return types for detecting the return type of `hashCode()`.
* Investigated techniques for hashing user-defined objects by either providing a `hashCode()` function or generating a hash from the object's raw bytes.

## Outcome:

Successfully implemented a reusable hash function utility capable of hashing primitive types, strings, and user-defined objects. Gained a solid understanding of generic hashing techniques, template-based function selection, and strategies for supporting custom data types in a hash-based data structure.
