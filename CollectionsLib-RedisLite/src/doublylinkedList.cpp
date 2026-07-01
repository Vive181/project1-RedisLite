#include <cstdlib>
#include <new>
#include <stdexcept>
#ifndef DOUBLYLINKEDLIST_CPP 
#define DOUBLYLINKEDLIST_CPP

using namespace std;

template<typename T>
class DoublyLinkedList
{
private:

    struct Node
    {
        T data;
        Node* prev;
        Node* next;

        Node(const T& value)
        {
            data = value;
            prev = nullptr;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int size;

public:

    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~DoublyLinkedList()
    {
        clear();
    }

    void insertBack(const T& value)
    {
        Node* node = (Node*)malloc(sizeof(Node));

        new (node) Node(value); //creates object for Node(user defined d type)

        if(head == nullptr)
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }

        size++;
    }

    T& get(int index) //return reference of element 
    {
        //reference creates another name for the same variable.
        //but in our fun is returns a single reference
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
        get(index) = value; //get fun return the reference so that the value at the node changed.
        //get(1) is essentially another name (an alias) for current->data.
    }

    bool remove(const T& value)
    {
        Node* current = head;

        while(current)
        {
            if(current->data == value)
            {
                if(current == head)
                {
                    head = current->next;
                }

                if(current == tail)
                {
                    tail = current->prev;
                }

                if(current->prev)
                {
                    current->prev->next = current->next;
                }

                if(current->next)
                {
                    current->next->prev = current->prev;
                }

                current->~Node();
                free(current);

                size--;
                return true;
            }

            current = current->next;
        }

        return false;
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

            temp->~Node(); // the compiler automatically generates it
            free(temp); //remove temp points to the raw memory
        }

        head = nullptr;
        tail = nullptr;
        size = 0;
    }
};


#endif // DOUBLYLINKEDLIST_CPP
