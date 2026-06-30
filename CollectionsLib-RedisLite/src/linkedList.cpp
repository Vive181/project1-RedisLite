#include <cstdlib>
#include <new>
#include <stdexcept>
#ifndef LINKEDLIST_CPP 
#define LINKEDLIST_CPP

using namespace std;

template<typename T>
class LinkedList
{
    struct Node
    {
        T data;
        Node* next;

        Node(const T& value) //const used bcoz T can refer to temporary values.
        {                     //also it prevent modifications
            data = value;
            next = nullptr;
        }
    };

    Node* head;
    int size;

public:

    LinkedList()
    {
        head = nullptr;
        size = 0;
    }

    ~LinkedList()
    {
        clear();
    }

    void insertFront(const T& value)
    {
        Node* node = (Node*)malloc(sizeof(Node));

        if(node == nullptr)
        {
            throw bad_alloc();
        }

        new (node) Node(value);

        node->next = head;
        head = node;

        size++;
    }

    T& get(int index)
    {
        if(index < 0 || index >= size)
        {
            throw out_of_range("Index out of range");
        }

        Node* current = head;

        for(int i = 0; i < index; i++)
        {
            current = current->next;
        }

        return current->data;
    }

    void set(int index, const T& value)
    {
        if(index < 0 || index >= size)
        {
            throw out_of_range("Index out of range");
        }

        Node* current = head;

        for(int i = 0; i < index; i++)
        {
            current = current->next;
        }

        current->data = value;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    int getSize()
    {
        return size;
    }

    void clear()
    {
        Node* current = head;

        while(current)
        {
            Node* temp = current;
            current = current->next;

            temp->~Node();
            free(temp);
        }

        head = nullptr;
        size = 0;
    }

};


#endif // LINKEDLIST_CPP
