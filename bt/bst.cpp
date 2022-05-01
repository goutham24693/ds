#include <iostream>

#define SUCCESS 0
#define FAILURE -1

using namespace std;

struct Node {
    int data;
    Node * left;
    Node * right;
};

class Bst {
    private:
        Node * root;
    public:
        Bst()
        {
            root = NULL;
        }
        Node * newBstNode(int data);
        int insertBst(int data);
        Node * _insertBst(Node * t, int data);
        int insertBst2(int data);
        void printBreathBst();
        void printInLevel(int i, Node * tmp);
        int height ();
        int _height (Node * t);
        int max (int i, int j);
        bool searchBst(int d);
        void printDepthBst ();
        void _printDepthBst(Node * t);
};

Node * Bst::newBstNode(int data)
{
    Node * newNode = new Node();
    if (newNode == NULL)
    {
        cout << __func__ << " " << __LINE__ << ": new allocation failed\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int Bst::insertBst(int data)
{
    root = _insertBst(root, data);
    if (root == NULL)
        return FAILURE;
    return SUCCESS;
}
Node * Bst::_insertBst(Node * tmp, int data)
{
    if (tmp == NULL)
    {
        tmp = newBstNode(data);
        return tmp;
    }

    if (tmp->data > data)
    {
        tmp->left = _insertBst(tmp->left, data);
    }
    else
    {
        tmp->right = _insertBst(tmp->right, data);
    }

    return tmp;

}

int Bst::insertBst2(int data)
{
    Node * newNode = newBstNode(data);
    if (newNode == NULL)
    {
        cout << __func__ << " " << __LINE__ << ": new allocation failed\n";
        return FAILURE;
    }

    if (root == NULL)
    {
        root = newNode;
        return SUCCESS;
    }

    Node * curr = root;
    Node * prev = root;

    while (curr)
    {
        if (curr->data < newNode->data)
        {
            // go right
//            cout << __func__ << " " << __LINE__ << ": curr node data " << curr->data <<  " is > than " << newNode->data << " so go right" << endl; 
            prev = curr;
            curr = curr->right;
        }
        else
        {
            // go left
//            cout << __func__ << " " << __LINE__ << ": curr node data " << curr->data <<  " is < or = than " << newNode->data << " so go left" << endl; 

            prev = curr;
            curr = curr->left;
        }
    }

    if (prev->data < newNode->data)
    {
        prev->right = newNode;
    }
    else
    {
        prev->left = newNode;
    }

    return SUCCESS;

}

void Bst::printInLevel(int i, Node * tmp)
{

    if (tmp == NULL)
    {
        return;
    }

    if (i == 0)
    {
        cout << tmp->data << "\t";
        return;
    }

    printInLevel(i-1, tmp->left);
    printInLevel(i-1, tmp->right);

}

void Bst::printBreathBst()
{
    int i = 0;

    for (i=0;i<6;i++)
    {
        printInLevel(i, root);
        cout << endl;
    }

}

int Bst::max (int i, int j)
{
    return (i > j?i:j);
}

int Bst::height ()
{
    return _height(root);
}

int Bst::_height (Node * t)
{
    if (t == NULL)
    {
        return -1;
    }

    return 1+ max(_height(t->left), _height(t->right));
}

bool Bst::searchBst(int d)
{
    if (root == NULL)
    {
        return false;
    }

    Node * t = root;
    
    while (t)
    {
        if (t->data == d)
        {
            return true;
        }
        if (t->data > d)
        {
            t = t->left;
        }
        else
        {
            t = t->right;
        }
    }
    return false;
}

void Bst::_printDepthBst(Node * t)
{
    if (t == NULL)
    {
        return;
    }
    _printDepthBst(t->left);
    _printDepthBst(t->right);
    cout << t->data << "\t";
}

void Bst::printDepthBst ()
{
    Node * t = root;
    _printDepthBst(t);
    cout << endl;
}


int main()
{
    Bst bst;
    bst.insertBst(7);
    bst.insertBst(5);
    bst.insertBst(9);
    bst.insertBst(3);
    bst.insertBst(4);
    bst.insertBst(6);
    bst.insertBst(10);
    bst.insertBst(1);
    bst.insertBst(11);
    bst.insertBst(2);

    bst.printBreathBst();
    bst.printDepthBst();

    int data = 22;
    if (bst.searchBst(data))
    {
        cout << data << " is present\n";
    }
    else
    {
        cout << data << " is not present\n";
    }

    cout << "height of tree "<< bst.height() << endl;

    return 0;
}

