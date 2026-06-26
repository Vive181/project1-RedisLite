#include <stdexcept>
#include <cstdlib>
#include <new>
#ifndef HASH_FUNCTION_CPP 
#define HASH_FUNCTION_CPP

using namespace std;

template<typename T>
class DynamicArray
{
private:
    T* data;
    int size;
    int capacity;

    void resize()
    {
        capacity *= 2;

        T* newData = (T*)malloc(capacity*sizeof(T));

        for(int i = 0; i < size; i++)
        {
            new (&newData[i]) T(data[i]); // copy construct
            data[i].~T();                 // destroy old object
        }

        free(data);
        data = newData;
    }

public:

    DynamicArray()
    {
        capacity = 4;  //4 because if we start with lower number then it takes many 
        //resizing and if we use larger number and it occupies a larger memory
        //when a user insert only 2 elements then rest of the memory
        size = 0;
        data = (T*)malloc(capacity*sizeof(T));

    }

    ~DynamicArray()
    {
        for(int i = 0; i < size; i++)
        {
           data[i].~T();
        }

        free(data);     
        data = nullptr;
    }
    
    // Copy Constructor
DynamicArray(const DynamicArray& other)
{
    size = other.size;
    capacity = other.capacity;

    data = (T*)malloc(capacity*sizeof(T));

    for(int i = 0; i < size; i++)
    {
       new (&data[i]) T(other.data[i]);
    }
}

// Copy Assignment Operator
//it is used to assign the value of object that has previous array and copy previous array value into new object
// that has new array but due to deep copy this array has new heap memory
DynamicArray& operator=(const DynamicArray& other)
{
    if(this != &other) //check ob1==ob2
    {
        for(int i = 0; i < size; i++)
        {
            data[i].~T();
        }

        free(data);

        size = other.size;
        capacity = other.capacity;

        data = (T*)malloc(capacity * sizeof(T));

        for(int i = 0; i < size; i++)
        {
            new (&data[i]) T(other.data[i]);
        }
    }

    return *this;
}

    void pushBack(const T& value)
    {
        if(size == capacity)
        {
            resize();
        }

        new (&data[size]) T(value);   // call string constructor
        size++;
    }

    T& get(int index) //Return a reference to the object, not a copy.
    {
      if(index < 0 || index >= size)
      {
          throw out_of_range("Index out of range");
      }

      return data[index];
    }

    void set(int index, T value)
    {
        if(index >= 0 && index < size)
        {
            data[index] = value;
        }
    }

    void popBack()
    {
       if(size > 0)
       {
          data[size - 1].~T();
          size--;
       }
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void clear()
    {
        for(int i = 0; i < size; i++)
        {
           data[i].~T();
        }

        size = 0;
    }

    
};

