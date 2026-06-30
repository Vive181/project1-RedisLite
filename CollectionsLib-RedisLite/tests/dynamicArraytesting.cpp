#include <gtest/gtest.h>
#include <stdexcept>
#include "dynamicArray.h"

// --- Fixture for tests that need a pre-populated array ---
class DynamicArrayTest : public ::testing::Test {
protected:
    DynamicArray<int> arr;

    void SetUp() override {
        // Setup initial state: array with [1, 2, 3, 4, 5]
        for (int i = 1; i <= 5; i++)
            arr.pushBack(i);
    }
};

// ==========================================================
// Fixture for CustomUser
// ==========================================================
class DynamicArrayCustomUserTest : public ::testing::Test {
protected:
    DynamicArray<CustomUser> users;

    void SetUp() override {
        users.pushBack({"Alice", 30});
        users.pushBack({"Bob", 25});
        users.pushBack({"Charlie", 40});
    }
};

// ==========================================
// 1. Tests for pushBack()
// ==========================================
TEST(DynamicArrayPushBackTest, PushBackAddsElementToEmptyArray) {
    DynamicArray<int> dArr;
    dArr.pushBack(10);
    EXPECT_EQ(dArr.getSize(), 1);
    EXPECT_EQ(dArr.get(0), 10);
}

TEST(DynamicArrayPushBackTest, PushBackTriggersResizeAutomatically) {
    DynamicArray<int> dArr;
    // Initial capacity is 4. Pushing 100 elements forces resizes.
    for(int i = 0; i < 100; i++) {
        dArr.pushBack(i);
    }
    EXPECT_EQ(dArr.getSize(), 100);
    for(int i = 0; i < 100; i++) {
        EXPECT_EQ(dArr.get(i), i);
    }
}

TEST(DynamicArrayPushBackTest, PushBackMaintainsOrderOfElements) {
    DynamicArray<int> dArr;
    dArr.pushBack(5);
    dArr.pushBack(10);
    dArr.pushBack(15);
    EXPECT_EQ(dArr.get(0), 5);
    EXPECT_EQ(dArr.get(1), 10);
    EXPECT_EQ(dArr.get(2), 15);
}

// ==========================================
// 2. Tests for get()
// ==========================================
TEST_F(DynamicArrayTest, GetRetrievesCorrectElement) {
    EXPECT_EQ(arr.get(0), 1);
    EXPECT_EQ(arr.get(2), 3);
    EXPECT_EQ(arr.get(4), 5);
}

TEST_F(DynamicArrayTest, GetOutOfBoundsThrowsException) {
    EXPECT_THROW(arr.get(-1), std::out_of_range);
    EXPECT_THROW(arr.get(5), std::out_of_range);
    EXPECT_THROW(arr.get(100), std::out_of_range);
}

TEST(DynamicArrayGetTest, GetOnEmptyArrayThrowsException) {
    DynamicArray<int> emptyArr;
    EXPECT_THROW(emptyArr.get(0), std::out_of_range);
}

TEST_F(DynamicArrayCustomUserTest, GetReturnsCorrectObject) {
    EXPECT_EQ(users.get(0).name, "Alice");
    EXPECT_EQ(users.get(1).age, 25);
}
// ==========================================
// 3. Tests for set()
// ==========================================
TEST_F(DynamicArrayTest, SetModifiesExistingElement) {
    arr.set(0, 100);
    arr.set(4, 500);
    EXPECT_EQ(arr.get(0), 100);
    EXPECT_EQ(arr.get(4), 500);
}

TEST_F(DynamicArrayTest, SetDoesNothingForNegativeIndex) {
    // Current implementation silently ignores invalid indexes
    arr.set(-1, 999);
    // Elements should remain unchanged
    EXPECT_EQ(arr.get(0), 1);
}

TEST_F(DynamicArrayTest, SetDoesNothingForIndexGreaterThanSize) {
    arr.set(5, 999);
    arr.set(100, 999);
    // Size should remain 5, and it shouldn't crash
    EXPECT_EQ(arr.getSize(), 5);
}

// ==========================================
// 4. Tests for popBack()
// ==========================================
TEST_F(DynamicArrayTest, PopBackReducesSizeAndRemovesLastElement) {
    arr.popBack();
    EXPECT_EQ(arr.getSize(), 4);
    EXPECT_THROW(arr.get(4), std::out_of_range);
    EXPECT_EQ(arr.get(3), 4);
}

TEST(DynamicArrayPopBackTest, PopBackOnEmptyArrayDoesNotCrash) {
    DynamicArray<int> emptyArr;
    emptyArr.popBack();
    EXPECT_EQ(emptyArr.getSize(), 0);
}

TEST_F(DynamicArrayTest, PopBackMultipleTimesEmptiesArray) {
    for (int i = 0; i < 5; i++) {
        arr.popBack();
    }
    EXPECT_EQ(arr.getSize(), 0);
    EXPECT_TRUE(arr.isEmpty());
}

// ==========================================
// 5. Tests for getSize()
// ==========================================
TEST(DynamicArraySizeTest, GetSizeIsZeroForNewArray) {
    DynamicArray<int> emptyArr;
    EXPECT_EQ(emptyArr.getSize(), 0);
}

TEST_F(DynamicArrayTest, GetSizeIncreasesWithPushBack) {
    int initialSize = arr.getSize();
    arr.pushBack(100);
    EXPECT_EQ(arr.getSize(), initialSize + 1);
}

TEST_F(DynamicArrayTest, GetSizeDecreasesWithPopBack) {
    int initialSize = arr.getSize();
    arr.popBack();
    EXPECT_EQ(arr.getSize(), initialSize - 1);
}

// ==========================================
// 6. Tests for isEmpty()
// ==========================================
TEST(DynamicArrayEmptyTest, IsEmptyTrueForNewArray) {
    DynamicArray<int> emptyArr;
    EXPECT_TRUE(emptyArr.isEmpty());
}

TEST_F(DynamicArrayTest, IsEmptyFalseAfterPushBack) {
    EXPECT_FALSE(arr.isEmpty());
}

TEST_F(DynamicArrayTest, IsEmptyTrueAfterClear) {
    arr.clear();
    EXPECT_TRUE(arr.isEmpty());
}

// ==========================================
// 7. Tests for clear()
// ==========================================
TEST_F(DynamicArrayTest, ClearEmptiesPopulatedArray) {
    arr.clear();
    EXPECT_EQ(arr.getSize(), 0);
    EXPECT_TRUE(arr.isEmpty());
}

TEST(DynamicArrayClearTest, ClearOnEmptyArrayDoesNotCrash) {
    DynamicArray<int> emptyArr;
    emptyArr.clear();
    EXPECT_EQ(emptyArr.getSize(), 0);
}

TEST_F(DynamicArrayTest, ClearAllowsSubsequentPushBacks) {
    arr.clear();
    arr.pushBack(42);
    EXPECT_EQ(arr.getSize(), 1);
    EXPECT_EQ(arr.get(0), 42);
}

// ==========================================
// 8. Tests for Copy Constructor
// ==========================================
TEST_F(DynamicArrayTest, CopyConstructorCreatesDeepCopy) {
    DynamicArray<int> arrCopy(arr);
    EXPECT_EQ(arrCopy.getSize(), 5);
    
    arrCopy.set(0, 999);
    // Original should be unaffected
    EXPECT_EQ(arr.get(0), 1);
    EXPECT_EQ(arrCopy.get(0), 999);
}

TEST(DynamicArrayCopyConstructorTest, CopyConstructorOnEmptyArrayWorks) {
    DynamicArray<int> emptyArr;
    DynamicArray<int> emptyCopy(emptyArr);
    
    EXPECT_EQ(emptyCopy.getSize(), 0);
    EXPECT_TRUE(emptyCopy.isEmpty());
}

TEST_F(DynamicArrayTest, CopyConstructorIndependentScaling) {
    DynamicArray<int> arrCopy(arr);
    // Push elements to the copy to force resize
    for (int i = 0; i < 100; i++) {
        arrCopy.pushBack(i);
    }
    // Original should remain size 5
    EXPECT_EQ(arr.getSize(), 5);
    EXPECT_EQ(arrCopy.getSize(), 105);
}

// ==========================================
// 9. Tests for Copy Assignment Operator
// ==========================================
TEST_F(DynamicArrayTest, CopyAssignmentCreatesDeepCopy) {
    DynamicArray<int> arrAssign;
    arrAssign.pushBack(1000);
    arrAssign.pushBack(2000);
    
    arrAssign = arr; // Reassign
    EXPECT_EQ(arrAssign.getSize(), 5);
    
    arrAssign.set(0, 999);
    // Original should be unaffected
    EXPECT_EQ(arr.get(0), 1);
    EXPECT_EQ(arrAssign.get(0), 999);
}

TEST_F(DynamicArrayTest, CopyAssignmentHandlesSelfAssignment) {
    arr = arr; // Self assignment
    EXPECT_EQ(arr.getSize(), 5);
    EXPECT_EQ(arr.get(0), 1);
    EXPECT_EQ(arr.get(4), 5);
}

TEST(DynamicArrayCopyAssignmentTest, CopyAssignmentOverwritesExistingData) {
    DynamicArray<int> arr1;
    arr1.pushBack(10);
    
    DynamicArray<int> arr2;
    arr2.pushBack(20);
    arr2.pushBack(30);
    
    arr1 = arr2;
    EXPECT_EQ(arr1.getSize(), 2);
    EXPECT_EQ(arr1.get(0), 20);
    EXPECT_EQ(arr1.get(1), 30);
}

// ==========================================
// 10. Tests for Custom Objects
// ==========================================
struct CustomUser {
    std::string name;
    int age;

    bool operator==(const CustomUser& other) const {
        return name == other.name && age == other.age;
    }
};

TEST(DynamicArrayCustomTypeTest, CanStoreAndRetrieveObjects) {
    DynamicArray<CustomUser> users;
    
    CustomUser u1{"Alice", 30};
    CustomUser u2{"Bob", 25};
    
    users.pushBack(u1);
    users.pushBack(u2);
    
    EXPECT_EQ(users.getSize(), 2);
    EXPECT_EQ(users.get(0).name, "Alice");
    EXPECT_EQ(users.get(1).age, 25);
    EXPECT_TRUE(users.get(0) == u1);
}

TEST(DynamicArrayCustomTypeTest, ObjectsAreDeepCopiedDuringResize) {
    DynamicArray<CustomUser> users;
    
    // Force multiple resizes to ensure std::string inside struct handles memory moves correctly
    for (int i = 0; i < 20; i++) {
        CustomUser u{"User" + std::to_string(i), i};
        users.pushBack(u);
    }
    
    EXPECT_EQ(users.getSize(), 20);
    EXPECT_EQ(users.get(15).name, "User15");
    EXPECT_EQ(users.get(15).age, 15);
}

