#include<iostream>
#include <cstring>

#include "stack.h"

// g++ postfixToInfix.cpp stack.cpp

using namespace std;

static int operate (int a, int b, char * op)
{
    if ((op == NULL) || (strlen(op) != 1))
    {
        cout << "Invalid args\n";
        return -1;
    }

    if (strcmp(op, "+") == 0)
        return a+b;

    if (strcmp(op, "*") == 0)
        return a*b;

    if (strcmp(op, "-") == 0)
        return a-b;

    if (strcmp(op, "/") == 0)
        return a/b;
    
    cout << "Invalid operator" << endl;
    return -1;
}

int main ()
{

    int a = 0, b = 0;
    char * ptr = NULL;
    Node * head = NULL;
    char str[] = "2 3 * 5 4 * + 9 -"; 

    ptr = strtok (str, " ");
    while (ptr)
    {
        if (strncmp(ptr, " ", strlen(ptr)) == 0)
            continue;
        
        if ((strncmp(ptr, "+", 1) == 0) ||
            (strncmp(ptr, "-", 1) == 0) ||
            (strncmp(ptr, "*", 1) == 0) ||
            (strncmp(ptr, "/", 1) == 0)
            )
        {
            if (head == NULL)
            {
                cout << ptr << ":expression not in postfix form" << endl;
                return -1;
            }

            if (pop(&head, &a) == -1 || 
                pop(&head, &b) == -1)
            {
                cout << "pop operation failed" << endl;
                return -1;
            }
        
            if (push(&head, operate(b, a, ptr)) == -1)
            {
                cout << "push operation failed" << endl;
                return -1;
            }
        }
        else
        {
            a = atoi(ptr);
            if (push(&head, a) == -1)
            {
                cout << "push operation failed" << endl;
                return -1;
            }

        }

        ptr = strtok (NULL, " ");
    }

    cout << "Size of stack is " << stackLen(head) << endl;
    stackPrint(head);

    stackClear(head);
    head = NULL;

}
