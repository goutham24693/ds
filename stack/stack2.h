#include <iostream>
#include <cstring>

#define SUCCESS 0
#define FAILURE -1

template <typename T>
class stack {
    private: 

        T data;
        struct Node {
            Node * next;
            T data;
        };
        Node * head;

    public:

        stack();

        int push (T data);

        int pop (T * data);

        int stackLen ();

        void stackPrint ();

        void stackClear ();

        int top (T * t);

};

#include "stack2_impl.h"
