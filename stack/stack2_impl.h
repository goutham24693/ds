
using namespace std;

template <typename T>
stack<T>::stack()
{
    head = NULL;
    cout << "New stack object allocated" << endl;
}

template <typename T>
int stack<T>::push (T data)
{
    Node * newNode = new Node();
    if (newNode == NULL)
    {
        cout << __func__ << " " << __LINE__ << ": alloc failed\n";
        return FAILURE;
    }
    memset ((void *)newNode, 0, sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return SUCCESS;
}

template <typename T>
int stack<T>::pop (T * data)
{
    if ((data == NULL) || (head == NULL))
    {
        cout << __func__ << __LINE__ << " length of stack is " << this->stackLen() << endl;
        return FAILURE;
    }

    *data = head->data;
    Node * tmp = head->next;

    delete(head);
    head = tmp;

    return SUCCESS;

}

template <typename T>
int stack<T>::stackLen ()
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

template <typename T>
void stack<T>::stackPrint ()
{
    Node * tmp = head;
    while (tmp)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
 
template <typename T>
void stack<T>::stackClear ()
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
    head = NULL;
}

template <typename T>
int stack<T>::top (T * t)
{
    if (head)
    {
        *t = head->data;
        return SUCCESS;
    }
    return FAILURE;
}

