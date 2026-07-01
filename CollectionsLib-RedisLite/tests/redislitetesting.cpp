#include <gtest/gtest.h>
#include "Redis.h"
#include <string>

// -------------------------
// User-defined type
// -------------------------
struct Student {
    std::string name;
    int age;

    std::string serialize() const {
        return name + "," + std::to_string(age);
    }

    static Student deserialize(const std::string& data) {
        Student s;
        size_t pos = data.find(',');
        s.name = data.substr(0, pos);
        s.age = std::stoi(data.substr(pos + 1));
        return s;
    }
};

class RedisTest : public ::testing::Test {
protected:
    Redis redis;
};

// -------------------------
// Test 1: Primitive types
// -------------------------
TEST_F(RedisTest, PrimitiveTypes) {
    redis.set("int", std::to_string(10));
    redis.set("float", std::to_string(3.14f));
    redis.set("double", std::to_string(99.99));
    redis.set("bool", "1");

    EXPECT_EQ(redis.get("int"), "10");
    EXPECT_EQ(redis.get("float"), "3.140000");   // float precision
    EXPECT_EQ(redis.get("double"), "99.990000");
    EXPECT_EQ(redis.get("bool"), "1");
}

// -------------------------
// Test 2: Integer operations edge cases
// -------------------------
TEST_F(RedisTest, IntegerEdgeCases) {
    redis.set("zero", std::to_string(0));
    redis.set("negative", std::to_string(-100));

    EXPECT_EQ(std::stoi(redis.get("zero")), 0);
    EXPECT_EQ(std::stoi(redis.get("negative")), -100);
}

// -------------------------
// Test 3: User-defined type
// -------------------------
TEST_F(RedisTest, UserDefinedType) {
    Student s1{"Uvek", 21};

    redis.set("student:1", s1.serialize());

    std::string raw = redis.get("student:1");
    Student s2 = Student::deserialize(raw);

    EXPECT_EQ(s2.name, "Uvek");
    EXPECT_EQ(s2.age, 21);
}

// -------------------------
// Test 4: Mixed operations + overwrite + clear
// -------------------------
TEST_F(RedisTest, MixedOperations) {
    redis.set("key1", "100");
    redis.set("key2", "hello");

    EXPECT_EQ(redis.size(), 2);

    redis.set("key1", "200"); // overwrite

    EXPECT_EQ(redis.get("key1"), "200");

    redis.del("key2");

    EXPECT_FALSE(redis.exists("key2"));
    EXPECT_EQ(redis.size(), 1);

    redis.clear();

    EXPECT_TRUE(redis.empty());
    EXPECT_EQ(redis.size(), 0);
}