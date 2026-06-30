#include <gtest/gtest.h>
#include <stdexcept>
#include <string>
#include "doublylinkedList.h"

// --- Custom Object Setup ---
struct DLLUser {
    std::string name;
    int age;

    bool operator==(const DLLUser& other) const {
        return name == other.name && age == other.age;
    }
};

class DoublyLinkedListTest : public ::testing::Test {
protected:
    DoublyLinkedList<int> list;

    void SetUp() override {
        // Setup initial state: list with [1, 2, 3, 4, 5] (insertBack)
        for (int i = 1; i <= 5; i++)
            list.insertBack(i);
    }
};

// ==========================================
// 1. Tests for insertBack()
// ==========================================
TEST(DoublyLinkedListInsertTest, InsertBackOnEmptyList) {
    DoublyLinkedList<int> l;
    l.insertBack(10);
    EXPECT_EQ(l.getSize(), 1);
    EXPECT_EQ(l.get(0), 10);
}

TEST(DoublyLinkedListInsertTest, InsertBackMaintainsCorrectOrder) {
    DoublyLinkedList<int> l;
    l.insertBack(10);
    l.insertBack(20);
    l.insertBack(30);
    EXPECT_EQ(l.get(0), 10);
    EXPECT_EQ(l.get(1), 20);
    EXPECT_EQ(l.get(2), 30);
}

TEST(DoublyLinkedListInsertTest, InsertBackIncreasesSize) {
    DoublyLinkedList<int> l;
    for(int i=0; i<100; i++) {
        l.insertBack(i);
    }
    EXPECT_EQ(l.getSize(), 100);
}

// ==========================================
// 2. Tests for get()
// ==========================================
TEST_F(DoublyLinkedListTest, GetRetrievesCorrectElement) {
    EXPECT_EQ(list.get(0), 1);
    EXPECT_EQ(list.get(2), 3);
    EXPECT_EQ(list.get(4), 5);
}

TEST_F(DoublyLinkedListTest, GetOutOfBoundsThrowsException) {
    EXPECT_THROW(list.get(-1), std::out_of_range);
    EXPECT_THROW(list.get(5), std::out_of_range);
}

TEST(DoublyLinkedListGetTest, GetOnEmptyListThrowsException) {
    DoublyLinkedList<int> emptyList;
    EXPECT_THROW(emptyList.get(0), std::out_of_range);
}

// ==========================================
// 3. Tests for set()
// ==========================================
TEST_F(DoublyLinkedListTest, SetModifiesExistingElement) {
    list.set(0, 100);
    list.set(4, 500);
    EXPECT_EQ(list.get(0), 100);
    EXPECT_EQ(list.get(4), 500);
}

TEST_F(DoublyLinkedListTest, SetOutOfBoundsThrowsException) {
    EXPECT_THROW(list.set(-1, 99), std::out_of_range);
    EXPECT_THROW(list.set(5, 99), std::out_of_range);
}

TEST(DoublyLinkedListSetTest, SetOnEmptyListThrowsException) {
    DoublyLinkedList<int> emptyList;
    EXPECT_THROW(emptyList.set(0, 10), std::out_of_range);
}

// ==========================================
// 4. Tests for remove()
// ==========================================
TEST_F(DoublyLinkedListTest, RemoveExistingElementReturnsTrueAndReducesSize) {
    bool result = list.remove(3);
    EXPECT_TRUE(result);
    EXPECT_EQ(list.getSize(), 4);
    EXPECT_EQ(list.get(2), 4); // 4 shifted left
}

TEST_F(DoublyLinkedListTest, RemoveNonExistingElementReturnsFalse) {
    bool result = list.remove(999);
    EXPECT_FALSE(result);
    EXPECT_EQ(list.getSize(), 5);
}

TEST(DoublyLinkedListRemoveTest, RemoveOnEmptyListReturnsFalse) {
    DoublyLinkedList<int> emptyList;
    bool result = emptyList.remove(10);
    EXPECT_FALSE(result);
    EXPECT_EQ(emptyList.getSize(), 0);
}

// ==========================================
// 5. Tests for getSize()
// ==========================================
TEST(DoublyLinkedListSizeTest, GetSizeIsZeroForNewList) {
    DoublyLinkedList<int> emptyList;
    EXPECT_EQ(emptyList.getSize(), 0);
}

TEST_F(DoublyLinkedListTest, GetSizeReturnsCorrectCount) {
    EXPECT_EQ(list.getSize(), 5);
}

TEST_F(DoublyLinkedListTest, GetSizeIsZeroAfterClear) {
    list.clear();
    EXPECT_EQ(list.getSize(), 0);
}

// ==========================================
// 6. Tests for clear()
// ==========================================
TEST_F(DoublyLinkedListTest, ClearEmptiesPopulatedList) {
    list.clear();
    EXPECT_EQ(list.getSize(), 0);
    EXPECT_THROW(list.get(0), std::out_of_range);
}

TEST(DoublyLinkedListClearTest, ClearOnEmptyListDoesNotCrash) {
    DoublyLinkedList<int> emptyList;
    emptyList.clear();
    EXPECT_EQ(emptyList.getSize(), 0);
}

TEST_F(DoublyLinkedListTest, ClearAllowsSubsequentInserts) {
    list.clear();
    list.insertBack(42);
    EXPECT_EQ(list.getSize(), 1);
    EXPECT_EQ(list.get(0), 42);
}

// ==========================================
// 7. Tests for Custom Objects
// ==========================================
TEST(DoublyLinkedListCustomTypeTest, CanStoreAndRetrieveObjects) {
    DoublyLinkedList<DLLUser> users;
    
    DLLUser u1{"Alice", 30};
    DLLUser u2{"Bob", 25};
    
    users.insertBack(u1);
    users.insertBack(u2);
    
    EXPECT_EQ(users.getSize(), 2);
    EXPECT_EQ(users.get(0).name, "Alice");
    EXPECT_EQ(users.get(1).age, 25);
    EXPECT_TRUE(users.get(0) == u1);
}

TEST(DoublyLinkedListCustomTypeTest, ObjectsCanBeRemoved) {
    DoublyLinkedList<DLLUser> users;
    
    DLLUser u1{"Alice", 30};
    DLLUser u2{"Bob", 25};
    
    users.insertBack(u1);
    users.insertBack(u2);
    
    bool removed = users.remove(u1);
    
    EXPECT_TRUE(removed);
    EXPECT_EQ(users.getSize(), 1);
    EXPECT_EQ(users.get(0).name, "Bob");
}

TEST(DoublyLinkedListCustomTypeTest, SetWorksWithCustomObjects) {
    DoublyLinkedList<DLLUser> users;
    users.insertBack({"Alice", 30});
    
    DLLUser u3{"Charlie", 40};
    users.set(0, u3);
    
    EXPECT_TRUE(users.get(0) == u3);
}
