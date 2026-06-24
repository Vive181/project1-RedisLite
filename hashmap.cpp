
#include <iostream>
using namespace std;
#include "dynamicArray.h"
#include "doublylinkedList.h"
#include "hash.h"
Hash<int> test;

template<typename Key, typename Value>
class HashMap
{
private:

    struct Node
    {
        Key key;
        Value value;
        Node* next;

        Node(const Key& k,const Value& v): key(k),value(v),next(nullptr)
        {}
    };

    Node** buckets;
    int bucketCount;
    int currentSize;

    float loadFactor()
    {
        return (float)currentSize / bucketCount;
    }

    void rehash()
    {
        int oldBucketCount = bucketCount;
        Node** oldBuckets = buckets;

        bucketCount *= 2;

        buckets = new Node*[bucketCount];

        for(int i = 0; i < bucketCount; i++)
        {
            buckets[i] = nullptr;
        }

        currentSize = 0;

        for(int i = 0; i < oldBucketCount; i++)
        {
            Node* current = oldBuckets[i];

            while(current)
            {
                insert(current->key,current->value);

                Node* temp = current;
                current = current->next;

                delete temp;
            }
        }

        delete[] oldBuckets;
    }

public:

    HashMap()
    {
        bucketCount = 8;
        currentSize = 0;

        buckets = new Node*[bucketCount];

        for(int i = 0; i < bucketCount; i++)
        {
            buckets[i] = nullptr;
        }
    }

    ~HashMap()
    {
        clear();
        delete[] buckets;
    }

    void insert(const Key& key,const Value& value)
    {
        if(loadFactor() > 0.75f)
        {
            rehash();
        }

        int index =
            Hash<Key>::hash(key) % bucketCount;

        Node* current = buckets[index];

        while(current)
        {
            if(current->key == key)
            {
                current->value = value;
                return;
            }

            current = current->next;
        }

        Node* node = new Node(key, value);

        node->next = buckets[index];

        buckets[index] = node;

        currentSize++;
    }

    Value* find(const Key& key)
    {
        int index =
            Hash<Key>::hash(key) % bucketCount;

        Node* current = buckets[index];

        while(current)
        {
            if(current->key == key)
            {
                return &current->value;
            }

            current = current->next;
        }

        return nullptr;
    }

    bool contains(const Key& key)
    {
        return find(key) != nullptr;
    }

    bool remove(const Key& key)
    {
        int index =
            Hash<Key>::hash(key) % bucketCount;

        Node* current = buckets[index];

        Node* prev = nullptr;

        while(current)
        {
            if(current->key == key)
            {
                if(prev == nullptr)
                {
                    buckets[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }

                delete current;
                currentSize--;

                return true;
            }

            prev = current;
            current = current->next;
        }

        return false;
    }

    int size()
    {
        return currentSize;
    }

    bool isEmpty()
    {
        return currentSize == 0;
    }

    void clear()
    {
        for(int i = 0; i < bucketCount; i++)
        {
            Node* current = buckets[i];

            while(current)
            {
                Node* temp = current;

                current = current->next;

                delete temp;
            }

            buckets[i] = nullptr;
        }

        currentSize = 0;
    }
};

int main()
{
    HashMap<int, const char*> map;

    cout << "Inserting elements...\n";

    map.insert(1, "Vivek");
    map.insert(2, "Singh");
    map.insert(3, "Redis");

    cout << "\nSize: "
         << map.size()
         << endl;

    cout << "\nSearching...\n";

    if(map.find(1))
    {
        cout << "Key 1 = "
             << *map.find(1)
             << endl;
    }

    if(map.find(2))
    {
        cout << "Key 2 = "
             << *map.find(2)
             << endl;
    }

    cout << "\nContains Tests\n";

    cout << "Contains 3: "
         << map.contains(3)
         << endl;

    cout << "Contains 10: "
         << map.contains(10)
         << endl;

    cout << "\nRemoving key 2...\n";

    map.remove(2);

    cout << "Contains 2: "
         << map.contains(2)
         << endl;

    cout << "\nSize after remove: "
         << map.size()
         << endl;

    cout << "\nTesting update...\n";

    map.insert(1, "Updated");

    if(map.find(1))
    {
        cout << "Key 1 = "
             << *map.find(1)
             << endl;
    }

    cout << "\nTesting Rehash...\n";

    for(int i = 4; i <= 20; i++)
    {
        map.insert(i, "Data");
    }

    cout << "Size after many inserts: "
         << map.size()
         << endl;

    if(map.find(15))
    {
        cout << "Key 15 = "
             << *map.find(15)
             << endl;
    }

    cout << "\nClearing map...\n";

    map.clear();

    cout << "Is Empty: "
         << map.isEmpty()
         << endl;

    cout << "Final Size: "
         << map.size()
         << endl;

    return 0;
}