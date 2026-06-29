Date: June 23
Duration: 120 minutes

Goal:

update the dynamicarray and add malloc for dynamic memory allocation and use placemenet new 
to call contructor 
Problem Encountered:

1. segmentation error occurs i manually manage constructors and destructors to solve this

2. malloc cannot call constructor when we use non-primitive datatype like strings then it does not able to call the default constructor so i encounder this issue and i fix this by using new placement operator 

3. using free instead of new because free() is used with malloc() because malloc() only manages raw memory not C++ objects

4. i try to build single and doubly linked list in one program by using two different classes 
that inherits but the problem encountered here that when child class object is made then parent class object also allocates memory that creates memory leakage so i solve this problem
by writing them separately

What I Tried:

Today i try how to solve the problem when array inside array is passed in template 
how to make destructor delete the memory of all elements in both arrays.

Outcome:
Successfully built a working dynamic array supporting all required operations:

push_back and pop_back work correctly with resizing support
get and set safely access elements with boundary checks
display prints all valid elements
getSize, isEmpty, and clear correctly reflect array state
Gained a clearer understanding of manual memory management and dynamic resizing logic.