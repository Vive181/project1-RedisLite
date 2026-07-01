#include "hashmap.h"
#include <gtest/gtest.h>
#include <string>

struct Student
{
    int id;
    std::string name;

    bool operator==(const Student& other) const
    {
        return id == other.id &&
               name == other.name;
    }
};

template<>
struct Hash<Student>
{
    static size_t hash(const Student& s)
    {
        return std::hash<int>{}(s.id);
    }
};

//=====================================================
// INSERT TESTS
//=====================================================

TEST(InsertPrimitive, InsertSingleElement)
{
    HashMap<int,int> map;

    map.insert(1,100);

    EXPECT_EQ(map.size(),1);
    EXPECT_EQ(*map.find(1),100);
}

TEST(InsertPrimitive, InsertMultipleElements)
{
    HashMap<int,std::string> map;

    map.insert(1,"One");
    map.insert(2,"Two");
    map.insert(3,"Three");

    EXPECT_EQ(map.size(),3);
    EXPECT_EQ(*map.find(2),"Two");
}

TEST(InsertPrimitive, UpdateExistingKey)
{
    HashMap<int,int> map;

    map.insert(5,10);
    map.insert(5,20);

    EXPECT_EQ(map.size(),1);
    EXPECT_EQ(*map.find(5),20);
}

TEST(InsertPrimitive, TriggerRehash)
{
    HashMap<int,int> map;

    for(int i=0;i<20;i++)
    {
        map.insert(i,i*10);
    }

    EXPECT_EQ(map.size(),20);

    for(int i=0;i<20;i++)
    {
        EXPECT_EQ(*map.find(i),i*10);
    }
}

TEST(InsertUserDefined, InsertStudent)
{
    HashMap<Student,double> map;

    Student s{1,"John"};

    map.insert(s,8.5);

    EXPECT_EQ(*map.find(s),8.5);
}

//=====================================================
// FIND TESTS
//=====================================================

TEST(FindPrimitive, ExistingKey)
{
    HashMap<int,int> map;

    map.insert(10,100);

    EXPECT_NE(map.find(10),nullptr);
    EXPECT_EQ(*map.find(10),100);
}

TEST(FindPrimitive, MissingKey)
{
    HashMap<int,int> map;

    EXPECT_EQ(map.find(100),nullptr);
}

TEST(FindPrimitive, UpdatedValue)
{
    HashMap<int,int> map;

    map.insert(2,10);
    map.insert(2,50);

    EXPECT_EQ(*map.find(2),50);
}

TEST(FindPrimitive, AfterRehash)
{
    HashMap<int,int> map;

    for(int i=0;i<25;i++)
    {
        map.insert(i,i);
    }

    EXPECT_EQ(*map.find(20),20);
}

TEST(FindUserDefined, ExistingStudent)
{
    HashMap<Student,std::string> map;

    Student s{7,"Alice"};

    map.insert(s,"AI");

    EXPECT_EQ(*map.find(s),"AI");
}

//=====================================================
// CONTAINS TESTS
//=====================================================

TEST(ContainsPrimitive, ExistingKey)
{
    HashMap<int,int> map;

    map.insert(1,100);

    EXPECT_TRUE(map.contains(1));
}

TEST(ContainsPrimitive, MissingKey)
{
    HashMap<int,int> map;

    EXPECT_FALSE(map.contains(5));
}

TEST(ContainsPrimitive, AfterRemove)
{
    HashMap<int,int> map;

    map.insert(2,20);

    map.remove(2);

    EXPECT_FALSE(map.contains(2));
}

TEST(ContainsPrimitive, MultipleElements)
{
    HashMap<int,int> map;

    for(int i=0;i<10;i++)
    {
        map.insert(i,i);
    }

    EXPECT_TRUE(map.contains(8));
}

TEST(ContainsUserDefined, ExistingStudent)
{
    HashMap<Student,int> map;

    Student s{5,"Bob"};

    map.insert(s,99);

    EXPECT_TRUE(map.contains(s));
}// insert, find, contains done.

//=====================================================
// REMOVE TESTS
//=====================================================

TEST(RemoverPrimitive, RemoveExistingKey)
{
    HashMap<int,int> map;

    map.insert(1,100);

    EXPECT_TRUE(map.remove(1));
    EXPECT_FALSE(map.contains(1));
    EXPECT_EQ(map.size(),0);
}

TEST(RemoverPrimitive, RemoveMissingKey)
{
    HashMap<int,int> map;

    EXPECT_FALSE(map.remove(10));
    EXPECT_EQ(map.size(),0);
}

TEST(RemoverPrimitive, RemoveFromMultipleElements)
{
    HashMap<int,int> map;

    map.insert(1,10);
    map.insert(2,20);
    map.insert(3,30);

    EXPECT_TRUE(map.remove(2));

    EXPECT_TRUE(map.contains(1));
    EXPECT_FALSE(map.contains(2));
    EXPECT_TRUE(map.contains(3));
    EXPECT_EQ(map.size(),2);
}

TEST(RemoverPrimitive, RemoveAfterRehash)
{
    HashMap<int,int> map;

    for(int i=0;i<20;i++)
    {
        map.insert(i,i);
    }

    EXPECT_TRUE(map.remove(15));
    EXPECT_FALSE(map.contains(15));
    EXPECT_EQ(map.size(),19);
}

TEST(RemoverUserDefined, RemoveStudent)
{
    HashMap<Student,int> map;

    Student s{1,"John"};

    map.insert(s,90);

    EXPECT_TRUE(map.remove(s));
    EXPECT_FALSE(map.contains(s));
}

//=====================================================
// SIZE TESTS
//=====================================================

TEST(SizePrimitive, InitiallyZero)
{
    HashMap<int,int> map;

    EXPECT_EQ(map.size(),0);
}

TEST(SizePrimitive, AfterInsertions)
{
    HashMap<int,int> map;

    map.insert(1,10);
    map.insert(2,20);
    map.insert(3,30);

    EXPECT_EQ(map.size(),3);
}

TEST(SizePrimitive, AfterRemoval)
{
    HashMap<int,int> map;

    map.insert(1,10);
    map.insert(2,20);

    map.remove(1);

    EXPECT_EQ(map.size(),1);
}

TEST(SizePrimitive, AfterClear)
{
    HashMap<int,int> map;

    map.insert(1,10);
    map.insert(2,20);

    map.clear();

    EXPECT_EQ(map.size(),0);
}

TEST(SizeUserDefined, StudentObjects)
{
    HashMap<Student,double> map;

    map.insert({1,"A"},8.2);
    map.insert({2,"B"},9.0);

    EXPECT_EQ(map.size(),2);
}

//=====================================================
// ISEMPTY TESTS
//=====================================================

TEST(IsEmptyPrimitive, NewMap)
{
    HashMap<int,int> map;

    EXPECT_TRUE(map.isEmpty());
}

TEST(IsEmptyPrimitive, AfterInsertion)
{
    HashMap<int,int> map;

    map.insert(1,100);

    EXPECT_FALSE(map.isEmpty());
}

TEST(IsEmptyPrimitive, AfterRemoval)
{
    HashMap<int,int> map;

    map.insert(1,100);

    map.remove(1);

    EXPECT_TRUE(map.isEmpty());
}

TEST(IsEmptyPrimitive, AfterClear)
{
    HashMap<int,int> map;

    map.insert(1,10);
    map.insert(2,20);

    map.clear();

    EXPECT_TRUE(map.isEmpty());
}

TEST(IsEmptyUserDefined, StudentMap)
{
    HashMap<Student,int> map;

    map.insert({5,"Alice"},95);

    EXPECT_FALSE(map.isEmpty());

    map.clear();

    EXPECT_TRUE(map.isEmpty());
} //insert,find, contains,remove, size ,isEmpty done


//=====================================================
// CLEAR TESTS
//=====================================================

TEST(ClearPrimitive, ClearSingleElement)
{
    HashMap<int,int> map;

    map.insert(1,100);

    map.clear();

    EXPECT_TRUE(map.isEmpty());
    EXPECT_EQ(map.size(),0);
    EXPECT_EQ(map.find(1),nullptr);
}

TEST(ClearPrimitive, ClearMultipleElements)
{
    HashMap<int,int> map;

    for(int i=0;i<10;i++)
    {
        map.insert(i,i*10);
    }

    map.clear();

    EXPECT_TRUE(map.isEmpty());
    EXPECT_EQ(map.size(),0);

    for(int i=0;i<10;i++)
    {
        EXPECT_EQ(map.find(i),nullptr);
    }
}

TEST(ClearPrimitive, ClearAlreadyEmptyMap)
{
    HashMap<int,int> map;

    map.clear();

    EXPECT_TRUE(map.isEmpty());
    EXPECT_EQ(map.size(),0);
}

TEST(ClearPrimitive, InsertAfterClear)
{
    HashMap<int,int> map;

    map.insert(1,10);
    map.insert(2,20);

    map.clear();

    map.insert(3,30);

    EXPECT_EQ(map.size(),1);
    EXPECT_TRUE(map.contains(3));
    EXPECT_FALSE(map.contains(1));
    EXPECT_FALSE(map.contains(2));
}

TEST(ClearUserDefined, ClearStudentMap)
{
    HashMap<Student,double> map;

    Student s1{1,"John"};
    Student s2{2,"Alice"};

    map.insert(s1,8.5);
    map.insert(s2,9.2);

    map.clear();

    EXPECT_TRUE(map.isEmpty());
    EXPECT_EQ(map.size(),0);
    EXPECT_EQ(map.find(s1),nullptr);
    EXPECT_EQ(map.find(s2),nullptr);
}

//clear done

//These tests cover:

/* Primitive types (int, std::string, double)
User-defined type (Student)
Normal operations
Updating existing keys
Removing elements
Clearing the map
Empty-map behavior
Rehashing (through insertion of many elements) */