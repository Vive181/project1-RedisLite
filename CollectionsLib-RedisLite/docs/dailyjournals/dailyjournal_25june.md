Daily Design Journal · 24-06-2026.md

Section 1 — Specific Bug:

 vivek@LAPTOP-8GRHFCJA MINGW64 /d/projects/RedisLite
$ g++ -std=c++17 src/SuperStructureClass/hashmap.cpp -o hashmap.exe
src/SuperStructureClass/hashmap.cpp: In member function 'void HashMap<Key, Value>::insert(const Key&, const Value&)':
src/SuperStructureClass/hashmap.cpp:95:13: error: 'Hash' was not declared in this scope 
             Hash<Key>::hash(key) % bucketCount;
             ^~~~
src/SuperStructureClass/hashmap.cpp:95:21: error: expected primary-expression before '>' token
             Hash<Key>::hash(key) % bucketCount;
                     ^
src/SuperStructureClass/hashmap.cpp:95:28: error: missing template arguments before '(' token
             Hash<Key>::hash(key) % bucketCount;
                            ^
src/SuperStructureClass/hashmap.cpp: In member function 'Value* HashMap<Key, Value>::find(const Key&)':
src/SuperStructureClass/hashmap.cpp:122:13: error: 'Hash' was not declared in this scope
             Hash<Key>::hash(key) % bucketCount;
             ^~~~
src/SuperStructureClass/hashmap.cpp:122:21: error: expected primary-expression before '>' token
             Hash<Key>::hash(key) % bucketCount;
                     ^
src/SuperStructureClass/hashmap.cpp:122:28: error: missing template arguments before '(' token
             Hash<Key>::hash(key) % bucketCount;
                            ^
src/SuperStructureClass/hashmap.cpp: In member function 'bool HashMap<Key, Value>::remove(const Key&)':
src/SuperStructureClass/hashmap.cpp:147:13: error: 'Hash' was not declared in this scope
             Hash<Key>::hash(key) % bucketCount;
             ^~~~
src/SuperStructureClass/hashmap.cpp:147:21: error: expected primary-expression before '>' token
             Hash<Key>::hash(key) % bucketCount;
                     ^
src/SuperStructureClass/hashmap.cpp:147:28: error: missing template arguments before '(' token
             Hash<Key>::hash(key) % bucketCount;
                            ^.

Section 2 — Failed Attempt: i tried to create a complete hash function but at the end i
realized it cannot work for objects.

Section 3 — Memory Diagram: 

Section 4 — Code Reference: Commit hash, filename, and relevant line numbers.

Section 5 — Learning Reflection: learned how to make a hashmap and almost completed hash function that can work for primitive datatypes.