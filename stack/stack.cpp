#include <iostream>
#include <cstring>

#include "stack.h"

#define SUCCESS 0
#define FAILURE -1

using namespace std;

int push (Node ** head, int data)
{
	Node * newNode = new Node();
	if (newNode == NULL)
	{
		cout << __func__ << " " << __LINE__ << ": alloc failed\n";
		return FAILURE;
	}
	memset (newNode, 0, sizeof(Node));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
	return SUCCESS;
}

int pop (Node ** head, int * data)
{
	if ((head == NULL) || (data == NULL))
	{
		return FAILURE;
	}

	*data = (*head)->data;
	Node * tmp = (*head)->next;

	delete(*head);	
	*head = tmp;

	return SUCCESS;

}

int stackLen (Node * head)
{
    int i =0;
    Node * tmp = head;
    while (tmp)
    {
        i++;
        tmp = tmp->next;
    }
    return i;
}

void stackPrint (Node * head)
{
    Node * tmp = head;
    while (tmp)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void stackClear (Node * head)
{
    int a;
    Node * tmp = head;
    Node * tmp2 = NULL;
    while(tmp)
    {
        tmp2 = tmp->next;
        pop(&tmp, &a);
        tmp = tmp2;
    }
}

int top (Node * head)
{
    if (!head)
    {
        return head->data;
    }
    return -1;
}

/*
int main()
{

	Node * head = NULL;

	push (&head, 4); 
	push (&head, 3); 
	push (&head, 2); 
	push (&head, 1); 

	int data = 0;

	while (head)
	{
		if (pop(&head, &data) != FAILURE)
		{
			cout << data << endl;
		}

	}

	return SUCCESS;
}
*/
