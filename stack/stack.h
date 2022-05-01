
struct Node {
	int data;
	struct Node * next;
};


int push (Node ** head, int data);
int pop (Node ** head, int * data);
int stackLen (Node * head);
void stackPrint (Node * head);
void stackClear (Node * head);
