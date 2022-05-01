#include <iostream>

using namespace std;

struct Node{
	int data;
	struct Node * next;	
};

void 
insert (Node ** node, int data)
{
	Node * tmp = new Node();
	tmp->data = data;
	tmp->next = NULL;
	if (*node == NULL)
	{
		*node = tmp;
		return;
	}

	Node * tmp2 = * node;

	while (tmp2->next != NULL)
	{
		// 1->2->3->0
		tmp2 = tmp2->next;
	}

	tmp2->next = tmp;
} 

void
print_node (Node * node) 
{
	while (node)
	{
		cout << node->data << "->";
		node = node->next;
	}
	cout << "0\n";
}

void
insertatpos (Node ** node, int pos, int data)
{
	Node * head = * node;
	Node * tmp = head;
	Node * tmp2 = NULL;

	int i = 0;
	for (i = 1; i < pos-1; i++)
	{
		tmp = tmp -> next;
	}

	Node * newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;

	tmp2=tmp->next;
	tmp->next = newNode;
	newNode->next = tmp2;

}


int
deleteNode (Node ** node, int pos)
{
	Node * tmp = * node;
	Node * tmp2 = NULL;

	cout << "deleting node in position " << pos << "\n";

	if (pos == 1)
	{
		tmp2 = tmp;
		*node = tmp->next;
		delete(tmp2);
	}

	int i = 0;

	for (i = 1; i < (pos - 1); i++)
	{
		if (tmp == NULL) return -1;
		tmp = tmp->next;
	}

	tmp2 = tmp->next;
	if (tmp2 == NULL)
	{
		return -1;
	}
	tmp->next = tmp2->next;

	delete(tmp2);
	return 0;

} 

void
reverse_list_with_recursion (Node ** head, Node * node)
{
	if (node == NULL)
	{
		node = *head;
	}

	if (node->next == NULL)
	{
		*head = node;
		return;
	}

	reverse_list_with_recursion (head, node->next);

	node->next->next = node;
	node->next = NULL;
}


/*
1->2->3->0 1
n = 2, 1->0, p = 1, c = 2
0<-1 2->3->0 2
n = 3, 2->1, p = 2, c = 3
0<-1<-2 3->0 3
n = 0, 3->2, 
*/
void
reverse_list_without_recursion (Node ** node)
{
	Node * prev = NULL, * curr = * node, * next;
	while (curr)
	{
		next = curr->next; 
		curr->next = prev;
		prev = curr;
		curr = next;
		if (curr == NULL)
		{
			*node = prev;
		}
	}
}

int main()
{
	Node * node = NULL;
	insert (&node, 1);
	insert (&node, 2);
	insert (&node, 3);
	insert (&node, 4);

	print_node(node);
	
	cout << "inserting node with data 2 at pos 2\n";

	insertatpos (&node, 2, 2);

	// 1->2->3->4->0
	print_node(node);

	if (deleteNode(&node, 2) == -1)
	{
		cout << "delete failed\n";
	}

	insert (&node, 5);
	insert (&node, 6);
	print_node(node);

	cout << "reversing the node with recursion\n";

	reverse_list_with_recursion (&node, NULL);

	print_node(node);

	cout << "reversing the node without recursion\n";

	reverse_list_without_recursion (&node);

	print_node(node);

	return 0;
}
