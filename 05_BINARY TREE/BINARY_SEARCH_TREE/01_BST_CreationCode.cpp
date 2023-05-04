//------BINARY SEARCH TREE-INSERTION,SEARCHING,DELITION CODES------

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
};

class BST
{
public:
    node *root = NULL;

public:
    void iterativeInsert(int key);
    node *recurrsiveInsert(node *p, int key);
    node *iterativeSearch(int key);
    node *recurrsiveSearch(node *p, int key);
    void inorder(node *p);
    node *deleteNode(node *p, int key);
    int Height(node *p);
    node *InSucc(node *p);
    node *InPre(node *p);
};

//---------ITERATIVE-INSERTION CODE FOR BST------------
void BST::iterativeInsert(int key)
{
    node *p = root;
    node *t;
    node *r;
    // root is empty
    if (p == NULL)
    {
        t = new node;
        t->data = key;
        t->left = NULL;
        t->right = NULL;
        root = t;
    }
    else
    {
        while (p != NULL)
        {
            // SEARCHING WHERE TO INSERT
            r = p;
            if (key > p->data)
            {
                p = p->right;
            }
            else if (key < p->data)
            {
                p = p->left;
            }
            else
            {
                return;
            }
        }

        t = new node;
        t->data = key;
        t->left = NULL;
        t->right = NULL;

        // TAIL POINTER HELPS IN INSERTION
        if (key > r->data)
        {
            r->right = t;
        }
        else
        {
            r->left = t;
        }
    }
}

//---------RECURRSIVE-INSERTION CODE FOR BST------------
node *BST::recurrsiveInsert(node *p, int key)
{
    node *t;
    if (p == nullptr)
    {
        t = new node;
        t->data = key;
        t->left = NULL;
        t->right = NULL;
        return t;
    }

    if (key < p->data)
    {
        p->left = recurrsiveInsert(p->left, key);
    }
    else if (key > p->data)
    {
        p->right = recurrsiveInsert(p->right, key);
    }
    return p; // key == p->data?
}

//---------ITERATIVE-SEARCH CODE FOR BST------------
node *BST::iterativeSearch(int key)
{
    node *t = root;
    if (t == NULL)
    {
        return NULL;
    }
    else
    {
        while (t != NULL)
        {
            if (t->data == key)
            {
                return t;
            }
            else if (key > t->data)
            {
                t = t->right;
            }
            else
            {
                t = t->left;
            }
        }
    }
}

//---------RECURRSIVE-SEARCH CODE FOR BST------------
node *BST::recurrsiveSearch(node *p, int key)
{
    if (p == NULL)
    {
        return NULL;
    }
    else
    {
        if (p->data == key)
        {
            return p;
        }
        else if (key > p->data)
        {
            return recurrsiveSearch(p->right, key);
        }
        else
        {
            return recurrsiveSearch(p->left, key);
        }
    }
}

//--------------DELETION FROM BST CODE-------------------
node *BST::deleteNode(node *p, int key)
{
    node *q;
    if (p == NULL)
    {
        return NULL;
    }

    if (p->left == NULL && p->right == NULL)
    {
        if (p == root)
        {
            return NULL;
        }
        delete p;
        return NULL;
    }

    if (key > p->data)
    {
        p->right = deleteNode(p->right, key);
    }
    else if (key < p->data)
    {
        p->left = deleteNode(p->left, key);
    }
    else
    {
        if (Height(p->left) > Height(p->right))
        {
            q = InPre(p->left);
            p->data = q->data;
            p->left = deleteNode(p->left, q->data);
        }
        else
        {
            q = InSucc(p->right);
            p->data = q->data;
            p->right = deleteNode(p->right, q->data);
        }
    }
    return p;
}

//-------------HEIGHT OF BST----------------------
int BST::Height(node *p)
{
    int x;
    int y;
    if (p == nullptr)
    {
        return 0;
    }
    x = Height(p->left);
    y = Height(p->right);
    return x > y ? x + 1 : y + 1;
}

//---------------INORDER-PREDICESSOR OF ANY NODE IN BST-----------------
node *BST::InPre(node *p)
{
    while (p && p->right != nullptr)
    {
        p = p->right;
    }
    return p;
}

//---------------INORDER-PREDICESSOR OF ANY NODE IN BST-----------------
node *BST::InSucc(node *p)
{
    while (p && p->left != nullptr)
    {
        p = p->left;
    }
    return p;
}

//---------INORDER-TRAVERSAL CODE FOR BST------------
void BST::inorder(node *p)
{
    if (p == NULL)
    {
        return;
    }
    else
    {
        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }
}

int main()
{
    BST bs;
    bs.iterativeInsert(1);
    bs.iterativeInsert(2);
    bs.iterativeInsert(5);
    bs.recurrsiveInsert(bs.root, 9);
    bs.inorder(bs.root);

    cout << endl;

    bs.iterativeSearch(1);
    bs.recurrsiveSearch(bs.root, 2);
    bs.deleteNode(bs.root, 1);
    bs.inorder(bs.root);

    return 0;
}