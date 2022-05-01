#include <iostream>

#define SUCCESS 0
#define FAILURE -1

using namespace std;

struct Node {
    int data;
    Node * left;
    Node * right;
};

class BinaryTree {
    public: 
        Node * root;
        BinaryTree()
        {
            root = NULL;
            cout << "instance of BinaryTree created" << endl;
        }
        Node * newBinaryNode(int data);
        virtual int insertNode(int data) = 0;
        virtual int deleteNode(int data) = 0;
        void printBreathBinaryTree();
        void printInLevel(int i, Node * tmp);
        void printDepthBinaryTree ();
        void _printDepthBinaryTree(Node * t);
        virtual int max (int i, int j) = 0;
        int height ();
        int _height (Node * t);
        virtual bool searchBinaryTree(int d) = 0;
        bool isBinaryTreeBst (Node * t);
};

Node * BinaryTree::newBinaryNode(int data)
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

void BinaryTree::printInLevel(int i, Node * tmp)
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

void BinaryTree::printBreathBinaryTree()
{
    int i = 0;
    int h = height(); 

    for (i=0;i<h;i++)
    {
        printInLevel(i, root);
        cout << endl;
    }
    cout << endl;

}

int BinaryTree::_height (Node * t)
{
    if (t == NULL)
    {
        return -1;
    }

    return 1+ max(_height(t->left), _height(t->right));
}

void BinaryTree::_printDepthBinaryTree(Node * t)
{
    if (t == NULL)
    {
        return;
    }
    _printDepthBinaryTree(t->left);
    _printDepthBinaryTree(t->right);
    cout << t->data << "\t";
}

void BinaryTree::printDepthBinaryTree ()
{
    Node * t = root;
    _printDepthBinaryTree(t);
    cout << endl;
}

bool isBinaryTreeBst (Node * t)
{
    return true;
}

class Bst : public BinaryTree {
    private:
    public:
        Bst()
        {
            root = NULL;
        }
        Node * _insertNode(Node * t, int data);
        Node * _deleteNode (Node * t, int data);
        int insertNode(int data);
        int deleteNode(int data);
        int insertNode2(int data);
        int max (int i, int j);
        bool searchBinaryTree(int d);
        Node * returnMinNode (Node * t);
        int noOfChildren (Node * t );
        Node * duplicateNode (Node * t);
};

int Bst::insertNode(int data)
{
    root = _insertNode(root, data);
    if (root == NULL)
        return FAILURE;
    return SUCCESS;
}


Node * Bst::_deleteNode (Node * t, int data)
{
    if (t == NULL)
        return NULL;

    if (t->data > data)
    {
        //cout << __func__ << " " << __LINE__ << ": " << t->data << "->left = \n";
        t->left = _deleteNode(t->left, data);
        return t;
    }
    else if (t->data < data)
    {
        //cout << __func__ << " " << __LINE__ << ": " << t->data << "->right = \n";
        t->right = _deleteNode(t->right, data);
        return t;
    }
    else
    {
        //cout << __func__ << " " << __LINE__ << ": found data\n";
        Node * t1 = NULL, * t2 = NULL;
        int i = noOfChildren(t);
        //cout << __func__ << " " << __LINE__ << ": " << i << " nodes below it";
        switch (i) 
        {
            case 0:
                delete (t);
                return NULL;
            case 1:
                if (t->left)
                    t2 = t->left;
                else
                    t2 = t->right;
                delete(t);
                //cout << __func__ << " " << __LINE__ << ": returning " << t2->data <<" \n";
                return t2;
            case 2:
                t1 = returnMinNode(t->right);
                t2 = duplicateNode(t1);
                t2->left = t->left;
                t2->right = t->right;
                delete (t);
                t2->right = _deleteNode(t2->right, t1->data);
                return t2;
        }
    }
    return NULL;
}

Node * Bst::duplicateNode (Node * t)
{
    if (t == NULL)
        return NULL;

    Node * newNode = newBinaryNode(t->data);
    return newNode;
}

Node * Bst::returnMinNode (Node * t)
{
    if (t == NULL)
        return NULL;

    if (t->left == NULL)
        return t;

    Node * t1 = returnMinNode(t->left);
    return t1;
}

int Bst::noOfChildren (Node * t )
{
    int i = 0;
        
    if (t->left)    i++;
    if (t->right)    i++;
    
    return i;
}

int Bst::deleteNode(int data)
{
    root = _deleteNode(root, data);
    if (root == NULL)
        return FAILURE;
    return SUCCESS;
}

Node * Bst::_insertNode(Node * tmp, int data)
{
    if (tmp == NULL)
    {
        tmp = newBinaryNode(data);
        return tmp;
    }

    if (tmp->data > data)
    {
        tmp->left = _insertNode(tmp->left, data);
    }
    else
    {
        tmp->right = _insertNode(tmp->right, data);
    }

    return tmp;

}

int Bst::insertNode2(int data)
{
    Node * newNode = newBinaryNode(data);
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

int Bst::max (int i, int j)
{
    return (i > j?i:j);
}

int BinaryTree::height ()
{
    return _height(root);
}

bool Bst::searchBinaryTree(int d)
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

int main()
{
    Bst bst;
    bst.insertNode(7);
    bst.insertNode(5);
    bst.insertNode(9);
    bst.insertNode(3);
    bst.insertNode(4);
    bst.insertNode(6);
    bst.insertNode(10);
    bst.insertNode(1);
    bst.insertNode(11);
    bst.insertNode(2);

    bst.printBreathBinaryTree();
    bst.printDepthBinaryTree();

    int data = 22;
    if (bst.searchBinaryTree(data))
    {
        cout << data << " is present\n";
    }
    else
    {
        cout << data << " is not present\n";
    }

    cout << "height of tree "<< bst.height() << endl;

    //bst.deleteNode(7); // 2 children
    //bst.deleteNode(1); // 1 child
    //bst.deleteNode(2); // 0 child
    bst.printBreathBinaryTree();

    return 0;
}

