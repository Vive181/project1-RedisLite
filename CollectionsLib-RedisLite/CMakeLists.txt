cmake_minimum_required(VERSION 3.10)

project(CollectionsLib_RedisLite)

# 1. Define the master library by providing ALL the source code files
add_library(CollectionsLib STATIC
    src/dynamicArray.cpp
    src/linkedList.cpp
    src/doublylinkedList.cpp
    src/hash.cpp
    src/hashmap.cpp
    src/redis.cpp
    src/parser.cpp
)

# 2. Tell the library where to find its headers (like CollectionsLib.h and others)
target_include_directories(CollectionsLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 3. Create the executable for your test app
add_executable(test_app main.cpp)

# 4. Link the executable to the single master library
target_link_libraries(test_app PRIVATE CollectionsLib)
