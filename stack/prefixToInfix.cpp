#include<iostream>
#include <cstring>

#include "stack.h"

// g++ prefixToInfix.cpp stack.cpp  -Wall

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

void strRev (char * s)
{
    if (s == NULL)
    {
        return;
    }

    int len = strlen (s);

    int i = 0, j = 0;
    char t = 0;

    for (i = 0, j = len-1; (i < len/2 && j >= len/2); i++, j--)
    {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
    }

}

int main()
{
    char str[] = "- + * 2 3 * 5 4 9";
    Node * head = NULL;

    strRev(str);

    int a = 0, b = 0;

    char * ptr = strtok(str, " ");
    while (ptr)
    {
        if ((strncmp(ptr, "+", 1) == 0) ||
            (strncmp(ptr, "-", 1) == 0) ||
            (strncmp(ptr, "*", 1) == 0) ||
            (strncmp(ptr, "/", 1) == 0)
           )
        {
            if (pop(&head, &a) == -1 || 
                pop(&head, &b) == -1)
            {
                cout << "pop operation failed" << endl;
                return -1;
            }

            if (push(&head, operate(a, b, ptr)) == -1)
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



    return 0;
}
