cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


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

# --- Google Test Setup ---
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.8.1.zip
)

# For Windows: Ensure GTest compiles correctly with MinGW
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(gtest_disable_pthreads ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 5. Create the test executable
add_executable(dynamic_array_test tests/dynamicArraytesting.cpp)

# 6. Link it to your master library and GoogleTest
target_link_libraries(dynamic_array_test PRIVATE CollectionsLib gtest_main)

# 7. Enable Testing
enable_testing()
include(GoogleTest)
gtest_discover_tests(dynamic_array_test)

# --- Parser Tests ---
add_executable(parser_test tests/parsertesting.cpp)
target_link_libraries(parser_test PRIVATE CollectionsLib gtest_main)
gtest_discover_tests(parser_test)

# --- LinkedList Tests ---
add_executable(linkedlist_test tests/linkedlist.cpp)
target_link_libraries(linkedlist_test PRIVATE CollectionsLib gtest_main)
gtest_discover_tests(linkedlist_test)

# --- DoublyLinkedList Tests ---
add_executable(doublylinkedlist_test tests/doublylinkedlisttesting.cpp)
target_link_libraries(doublylinkedlist_test PRIVATE CollectionsLib gtest_main)
gtest_discover_tests(doublylinkedlist_test)

# --- HashMap Tests ---
add_executable(hashmap_test tests/hashmaptesting.cpp)
target_link_libraries(hashmap_test PRIVATE CollectionsLib gtest_main)
gtest_discover_tests(hashmap_test)

# --- Redis Tests ---
add_executable(redis_test tests/redislitetesting.cpp)

target_link_libraries(redis_test PRIVATE CollectionsLib gtest_main)

gtest_discover_tests(redis_test)