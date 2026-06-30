#include <gtest/gtest.h>
#include <stdexcept>
#include <string>
#include "linkedList.h"

// --- Custom Object Setup ---
struct LLUser {
    std::string name;
    int age;

    bool operator==(const LLUser& other) const {
        return name == other.name && age == other.age;
    }
};

class LinkedListTest : public ::testing::Test {
protected:
    LinkedList<int> list;

    void SetUp() override {
        // Setup initial state: list with [5, 4, 3, 2, 1] (since we insert at front)
        for (int i = 1; i <= 5; i++)
            list.insertFront(i);
    }
};

// ==========================================
// 1. Tests for insertFront()
// ==========================================
TEST(LinkedListInsertTest, InsertFrontOnEmptyList) {
    LinkedList<int> l;
    l.insertFront(10);
    EXPECT_EQ(l.getSize(), 1);
    EXPECT_EQ(l.get(0), 10);
}

TEST(LinkedListInsertTest, InsertFrontMaintainsCorrectOrder) {
    LinkedList<int> l;
    l.insertFront(10);
    l.insertFront(20);
    l.insertFront(30);
    EXPECT_EQ(l.get(0), 30);
    EXPECT_EQ(l.get(1), 20);
    EXPECT_EQ(l.get(2), 10);
}

TEST(LinkedListInsertTest, InsertFrontIncreasesSize) {
    LinkedList<int> l;
    for(int i=0; i<100; i++) {
        l.insertFront(i);
    }
    EXPECT_EQ(l.getSize(), 100);
}

// ==========================================
// 2. Tests for get()
// ==========================================
TEST_F(LinkedListTest, GetRetrievesCorrectElement) {
    EXPECT_EQ(list.get(0), 5);
    EXPECT_EQ(list.get(4), 1);
}

TEST_F(LinkedListTest, GetOutOfBoundsThrowsException) {
    EXPECT_THROW(list.get(-1), std::out_of_range);
    EXPECT_THROW(list.get(5), std::out_of_range);
}

TEST(LinkedListGetTest, GetOnEmptyListThrowsException) {
    LinkedList<int> emptyList;
    EXPECT_THROW(emptyList.get(0), std::out_of_range);
}

// ==========================================
// 3. Tests for set()
// ==========================================
TEST_F(LinkedListTest, SetModifiesExistingElement) {
    list.set(0, 100);
    list.set(4, 500);
    EXPECT_EQ(list.get(0), 100);
    EXPECT_EQ(list.get(4), 500);
}

TEST_F(LinkedListTest, SetOutOfBoundsThrowsException) {
    EXPECT_THROW(list.set(-1, 99), std::out_of_range);
    EXPECT_THROW(list.set(5, 99), std::out_of_range);
}

TEST(LinkedListSetTest, SetOnEmptyListThrowsException) {
    LinkedList<int> emptyList;
    EXPECT_THROW(emptyList.set(0, 10), std::out_of_range);
}

// ==========================================
// 4. Tests for isEmpty()
// ==========================================
TEST(LinkedListEmptyTest, IsEmptyTrueForNewList) {
    LinkedList<int> emptyList;
    EXPECT_TRUE(emptyList.isEmpty());
}

TEST_F(LinkedListTest, IsEmptyFalseAfterInsert) {
    EXPECT_FALSE(list.isEmpty());
}

TEST_F(LinkedListTest, IsEmptyTrueAfterClear) {
    list.clear();
    EXPECT_TRUE(list.isEmpty());
}

// ==========================================
// 5. Tests for getSize()
// ==========================================
TEST(LinkedListSizeTest, GetSizeIsZeroForNewList) {
    LinkedList<int> emptyList;
    EXPECT_EQ(emptyList.getSize(), 0);
}

TEST_F(LinkedListTest, GetSizeReturnsCorrectCount) {
    EXPECT_EQ(list.getSize(), 5);
}

TEST_F(LinkedListTest, GetSizeIsZeroAfterClear) {
    list.clear();
    EXPECT_EQ(list.getSize(), 0);
}

// ==========================================
// 6. Tests for clear()
// ==========================================
TEST_F(LinkedListTest, ClearEmptiesPopulatedList) {
    list.clear();
    EXPECT_EQ(list.getSize(), 0);
    EXPECT_TRUE(list.isEmpty());
}

TEST(LinkedListClearTest, ClearOnEmptyListDoesNotCrash) {
    LinkedList<int> emptyList;
    emptyList.clear();
    EXPECT_EQ(emptyList.getSize(), 0);
}

TEST_F(LinkedListTest, ClearAllowsSubsequentInserts) {
    list.clear();
    list.insertFront(42);
    EXPECT_EQ(list.getSize(), 1);
    EXPECT_EQ(list.get(0), 42);
}

// ==========================================
// 7. Tests for Custom Objects
// ==========================================
TEST(LinkedListCustomTypeTest, CanStoreAndRetrieveObjects) {
    LinkedList<LLUser> users;
    
    LLUser u1{"Alice", 30};
    LLUser u2{"Bob", 25};
    
    users.insertFront(u1);
    users.insertFront(u2);
    
    EXPECT_EQ(users.getSize(), 2);
    EXPECT_EQ(users.get(0).name, "Bob");
    EXPECT_EQ(users.get(1).age, 30);
    EXPECT_TRUE(users.get(0) == u2);
}

TEST(LinkedListCustomTypeTest, ObjectsAreProperlyDestroyedOnClear) {
    LinkedList<LLUser> users;
    users.insertFront({"Alice", 30});
    users.insertFront({"Bob", 25});
    
    // Test memory leaks conceptually by ensuring clear() functions correctly
    users.clear();
    EXPECT_EQ(users.getSize(), 0);
}

TEST(LinkedListCustomTypeTest, SetWorksWithCustomObjects) {
    LinkedList<LLUser> users;
    users.insertFront({"Alice", 30});
    
    LLUser u3{"Charlie", 40};
    users.set(0, u3);
    
    EXPECT_TRUE(users.get(0) == u3);
}
