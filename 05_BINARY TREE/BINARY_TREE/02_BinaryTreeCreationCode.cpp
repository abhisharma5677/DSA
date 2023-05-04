//-------------------TREE CREATION CODE USING RECURRSION--------------------------

#include <iostream>
using namespace std;

//-------------------NODE FOR TREE CREATION---------------------
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

//---------------QUEUE FOR LEVEL ORDER TRAVERSAL-------------------
class queue
{
private:
    int size;
    int front;
    int rear;
    node **Q;

public:
    queue(int s)
    {
        this->size = s;
        this->front = -1;
        this->rear = -1;
        this->Q = new node *[size];
    }

    bool isEmpty()
    {
        if (rear == front)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if (rear == this->size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(node *p)
    {
        if (isFull())
        {
            cout << "OverFlow Condition" << endl;
        }
        else
        {
            rear++;
            Q[rear] = p;
        }
    }

    node *dequeue()
    {
        node *p = NULL;
        if (isEmpty())
        {
            cout << "Underflow Condition" << endl;
        }
        else
        {
            front++;
            p = Q[front];
        }
    }
};

//------------------RECURRSIVE TREE CREATION CODE------------------
node *buildTree(node *root)
{
    cout << "Enter the data :-" << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data in the left of " << root->data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data in the right of " << root->data << endl;
    root->right = buildTree(root->right);

    return root;
}

//--------------PREORDER TRAVERSAL------------
void preorder(node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }
}

//-------------POSTORDER TRAVERSAL---------------
void postorder(node *p)
{
    if (p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        cout << p->data << " ";
    }
}

//-------------INORDER TRAVERSAL---------------------
void inorder(node *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }
}

//------------LEVEL ORDER TRAVERSAL---------------------
void levelOrder(node *root)
{
    queue q(100);
    q.enqueue(root);

    while (!q.isEmpty())
    {
        node *p = q.dequeue();
        cout << p->data << " ";

        if (p->left)
        {
            q.enqueue(p->left);
        }
        if (p->right)
        {
            q.enqueue(p->right);
        }
    }
}

//------------MAIN CODE------------------------
int main()
{
    node *root = NULL;

    root = buildTree(root);

    cout << endl
         << endl;

    preorder(root);

    cout << endl;

    postorder(root);

    cout << endl;

    inorder(root);

    cout << endl;

    levelOrder(root);

    return 0;
}