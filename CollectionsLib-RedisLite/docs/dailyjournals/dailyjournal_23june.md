Daily Design Journal · 23-June-2026.md

Section 1 — Specific Bug: dynamicArray.cpp: In function 'int main()':
dynamicArray.cpp:161:19: error: no matching function for call to 'DynamicArray<std::__cxx11::basic_string<char> >::set(int, int)'
     arr.set(1, 100);
                   ^
dynamicArray.cpp:105:10: note: candidate: void DynamicArray<T>::set(int, T) [with T = std::__cxx11::basic_string<char>]
     void set(int index, T value)
          ^~~
dynamicArray.cpp:105:10: note:   no known conversion for argument 2 from 'int' to 'std::__cxx11::basic_string<char>'

Section 2 — Failed Attempt: i use malloc instead of new for dynamic memory allocation and use placement 
new for object construction but if array inside array is given then destructor failed to delete 
the memory of both arrays

Section 3 — Memory Diagram: Hand-drawn memory diagram, photographed and submitted
every day.

Section 4 — Code Reference: Commit hash, filename, and relevant line numbers.

Section 5 — Learning Reflection:
 i learned the low level architecture of dynamicArray like 
allocation and deallocation of heap memory with the help of malloc and placement new  operator
for calling default constructors and i also learn how to deallocate memory when multidimensional
array is there and also research on how bitfields works.