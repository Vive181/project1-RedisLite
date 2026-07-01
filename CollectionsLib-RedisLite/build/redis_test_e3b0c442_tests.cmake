add_test([=[RedisTest.PrimitiveTypes]=]  D:/projects/RedisLite/CollectionsLib-RedisLite/build/redis_test.exe [==[--gtest_filter=RedisTest.PrimitiveTypes]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[RedisTest.PrimitiveTypes]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[D:\projects\RedisLite\CollectionsLib-RedisLite\tests\redislitetesting.cpp:33]==]
    WORKING_DIRECTORY [==[D:/projects/RedisLite/CollectionsLib-RedisLite/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[RedisTest.IntegerEdgeCases]=]  D:/projects/RedisLite/CollectionsLib-RedisLite/build/redis_test.exe [==[--gtest_filter=RedisTest.IntegerEdgeCases]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[RedisTest.IntegerEdgeCases]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[D:\projects\RedisLite\CollectionsLib-RedisLite\tests\redislitetesting.cpp:48]==]
    WORKING_DIRECTORY [==[D:/projects/RedisLite/CollectionsLib-RedisLite/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[RedisTest.UserDefinedType]=]  D:/projects/RedisLite/CollectionsLib-RedisLite/build/redis_test.exe [==[--gtest_filter=RedisTest.UserDefinedType]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[RedisTest.UserDefinedType]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[D:\projects\RedisLite\CollectionsLib-RedisLite\tests\redislitetesting.cpp:59]==]
    WORKING_DIRECTORY [==[D:/projects/RedisLite/CollectionsLib-RedisLite/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[RedisTest.MixedOperations]=]  D:/projects/RedisLite/CollectionsLib-RedisLite/build/redis_test.exe [==[--gtest_filter=RedisTest.MixedOperations]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[RedisTest.MixedOperations]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[D:\projects\RedisLite\CollectionsLib-RedisLite\tests\redislitetesting.cpp:74]==]
    WORKING_DIRECTORY [==[D:/projects/RedisLite/CollectionsLib-RedisLite/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
set(redis_test_TESTS [==[RedisTest.PrimitiveTypes]==] [==[RedisTest.IntegerEdgeCases]==] [==[RedisTest.UserDefinedType]==] [==[RedisTest.MixedOperations]==])
