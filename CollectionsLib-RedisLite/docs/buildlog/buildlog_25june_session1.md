Date: June 25
Duration: 120 minutes

Goal: complete hash function and redis lite 

Problem Encountered:

1. problem find in the destructor of dynamic array . In the destructor if we delete string then it only free memory but data points to that memory location. this problem is solved when the memory becomes free then data will points to null

2. problem arises in hashfunction is that if object is given then what gives the hash code
i find the answer is that it returns the address bytes of the object and then it generate 
the numeric value using these bytes.

What I Tried:

tried to build redis lite 

Outcome:

discovered the path to make radis lite and i build a combine masterlibrary that contains all the basic collections like dynamicarray, doublylinkedlist, hashmap and hash function