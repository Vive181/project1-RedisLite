#include <functional>
#include <cstddef>
#include <string>
#ifndef HASHMAP_H 
#define HASHMAP_H

template<typename T>
struct Hash
{
    static size_t hash(const T& value)
    {
        return std::hash<T>{}(value); //return the unsigned number
    }
};


template<typename Key, typename Value>
class HashMap
{
private:

    struct Node
    {
        Key key;
        Value value;
        Node* next;

        Node(const Key& k, const Value& v)
            : key(k), value(v), next(nullptr)
        {}
    };


    Node** buckets;
    int bucketCount;
    int currentSize;


    float loadFactor() const
    {
        return static_cast<float>(currentSize) / bucketCount;
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
                insert(current->key, current->value);


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



    void insert(const Key& key, const Value& value)
    {
        if(loadFactor() > 0.75f)
        {
            rehash();
        }


        int index = Hash<Key>::hash(key) % bucketCount;


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
        int index = Hash<Key>::hash(key) % bucketCount;


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



    const Value* find(const Key& key) const
    {
        int index = Hash<Key>::hash(key) % bucketCount;


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



    bool contains(const Key& key) const
    {
        return find(key) != nullptr;
    }



    bool remove(const Key& key)
    {
        int index = Hash<Key>::hash(key) % bucketCount;


        Node* current = buckets[index];
        Node* previous = nullptr;


        while(current)
        {
            if(current->key == key)
            {
                if(previous == nullptr)
                {
                    buckets[index] = current->next;
                }
                else
                {
                    previous->next = current->next;
                }


                delete current;

                currentSize--;

                return true;
            }


            previous = current;
            current = current->next;
        }


        return false;
    }



    int size() const
    {
        return currentSize;
    }



    bool isEmpty() const
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
#endif // HASHMAP_H
