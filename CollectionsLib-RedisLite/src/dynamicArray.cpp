#include <stdexcept>
#include <cstdlib>
#include <new>
#ifndef DYNAMICARRAY_CPP 
#define DYNAMICARRAY_CPP

using namespace std;

template<typename T>
class DynamicArray
{
private:
    T* data;
    int size;
    int capacity;     //resize() is placed in the private section because it is an internal implementation detail of the DynamicArray. Users of the class should not decide when or how the array resizes of the class should manage that automatically.

    void resize()
    {
        capacity *= 2;

        T* newData = (T*)malloc(capacity*sizeof(T));

        for(int i = 0; i < size; i++)
        {
            new (&newData[i]) T(data[i]); // copy construct
            data[i].~T();                 // destroy old object not work for int
        }

        free(data);
        data = newData;
    }

public:

    DynamicArray()
    {
        capacity = 4;  //4 because if we start with lower number then it takes many 
        //resizing and if we use larger number and it occupies a larger memory
        //when a user insert only 2 elements then rest of the memory get waste for larger number
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
    //used when arr2 object doesnot exist it creates deep copy
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
//used when another object exist and used to create deep copy
DynamicArray& operator=(const DynamicArray& other)
{
    if(this != &other) //check ob1==ob2 if shallow copy is there
    {
        for(int i = 0; i < size; i++)
        {
            data[i].~T();
        }

        free(data); //for int it is not req for string bcoz strings have destructors

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

        new (&data[size]) T(value);   //create memory object for new assigned value (string object contains points(points to the buffer), size of string and capacity)
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


#endif // DYNAMICARRAY_CPP
