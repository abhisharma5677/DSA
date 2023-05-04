//---------------------TREE CREATION CODE USING CPP CLASSES AND QUEUES------------------------------

#include <iostream>
using namespace std;

//----------------NODE CLASS FOR TREE CREATION--------------------
class node
{
public:
    int data;
    node *left;
    node *right;
};

//---------------QUEUE FOR IMPLIMENTATION IN TREE-------------------
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

//--------------------------TREE CLASS----------------------------
class tree
{
public:
    node *root = NULL;

public:
    void createTree();
    void inorder(node *p);
    void preorder(node *p);
    void postorder(node *p);
    void levelOrder(node *p);
    int allNodesCount(node *p);
    int bothChildNodes(node *p);
    int sumOfALLNodes(node *p);
    int leafNodes(node *p);
    int exactlyDeg2(node *p);
    int nonLeafNodes(node *p);
    int exactlyDeg1(node *p);
    int height(node *p);
};

//------------------TREE CREATION CODE USING QUEUE------------------------
void tree ::createTree()
{
    node *p;
    node *t;
    int x;

    queue q(100);
    root = new node;
    cout << "Enter the data" << endl;
    cin >> x;
    root->data = x;
    root->left = NULL;
    root->right = NULL;
    q.enqueue(root);

    while (!q.isEmpty())
    {
        p = q.dequeue();

        cout << "Enter the value to the left of " << p->data << endl;
        cin >> x;
        if (x != -1)
        {
            t = new node;
            t->data = x;
            t->left = NULL;
            t->right = NULL;
            p->left = t;
            q.enqueue(t);
        }

        cout << "Enter the value to the right of " << p->data << endl;
        cin >> x;
        if (x != -1)
        {
            t = new node;
            t->data = x;
            t->left = NULL;
            t->right = NULL;
            p->right = t;
            q.enqueue(t);
        }
    }
}

//-------------------INORDER TRAVERSAL----------------------
void tree::inorder(node *p)
{
    node *r = p;
    if (r != NULL)
    {
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }
}

//-----------------PREORDER TRAVERSAL-------------------------
void tree::preorder(node *p)
{
    node *r = p;
    if (r != NULL)
    {
        cout << r->data << " ";
        preorder(r->left);
        preorder(r->right);
    }
}

//----------------POSTORDER TRAVERSAL---------------------------
void tree::postorder(node *p)
{
    node *r = p;
    if (r != NULL)
    {
        postorder(r->left);
        postorder(r->right);
        cout << r->data << " ";
    }
}

//------------------LEVELORDER TRAVERSAL------------------------
void tree::levelOrder(node *p)
{
    queue q(100);
    q.enqueue(p);

    while (!q.isEmpty())
    {
        node *r = q.dequeue();
        cout << r->data << " ";

        if (r->left)
        {
            q.enqueue(r->left);
        }
        if (r->right)
        {
            q.enqueue(r->right);
        }
    }
}

//------------------COUNT OF ALL THE NODES----------------------
int tree::allNodesCount(node *p)
{
    int x;
    int y;
    if (p != NULL)
    {
        x = allNodesCount(p->left);
        y = allNodesCount(p->right);
        return (x + y + 1);
    }
    return 0;
}

//------------------COUNTING OF THE NODES HAVING BOTH THE CHILDS---------------------
int tree::bothChildNodes(node *p)
{
    int x;
    int y;
    if (p != NULL)
    {
        x = bothChildNodes(p->left);
        y = bothChildNodes(p->right);
        if (p->left != NULL && p->right != NULL)
        {
            return (x + y + 1);
        }
        else
        {
            return (x + y);
        }
    }
    return 0;
}

//--------------------SUM OF ALL THE NODES----------------------
int tree::sumOfALLNodes(node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = sumOfALLNodes(p->left);
        y = sumOfALLNodes(p->right);
        return (x + y + p->data);
    }
    return 0;
}

//-----------------COUNTING OF LEAF NODES------------------
int tree::leafNodes(node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = leafNodes(p->left);
        y = leafNodes(p->right);
        if (p->left == NULL && p->right == NULL)
        {
            return (x + y + 1);
        }
        else
        {
            return (x + y);
        }
    }
    return 0;
}

//--------------NUMBER OF NODES HAVING EXACTLY DEGREE TWO----------------
int tree::exactlyDeg2(node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = exactlyDeg2(p->left);
        y = exactlyDeg2(p->right);
        if (p->left != NULL && p->right != NULL)
        {
            return (x + y + 1);
        }
        else
        {
            return (x + y);
        }
    }
    return 0;
}

//--------------COUNTING OF THE NON LEAF NODES---------------
int tree::nonLeafNodes(node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = nonLeafNodes(p->left);
        y = nonLeafNodes(p->right);
        if (p->left != NULL || p->right != NULL)
        {
            return (x + y + 1);
        }
        else
        {
            return (x + y);
        }
    }
    return 0;
}

//---------------NUMBER OF NODES HAVING EXACTLY DEGREE ONE-----------------
int tree::exactlyDeg1(node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = exactlyDeg1(p->left);
        y = exactlyDeg1(p->right);
        if ((p->left == NULL && p->right != NULL) || (p->left != NULL && p->right == NULL))
        {
            return (x + y + 1);
        }
        else
        {
            return (x + y);
        }
    }
    return 0;
}

//---------------HEIGHT OF THE BINARY TREE-----------------
int tree::height(node *p)
{
    int l;
    int r;
    if (p != NULL)
    {
        l = height(p->left);
        r = height(p->right);
        if (l > r)
        {
            return (l + 1);
        }
        else
        {
            return (r + 1);
        }
    }
    return 0;
}

//--------------------MAIN CODE-------------------------
int main()
{
    tree t;
    t.createTree();

    cout << endl
         << endl;
    t.inorder(t.root);

    cout << endl
         << endl;
    t.preorder(t.root);

    cout << endl
         << endl;
    t.postorder(t.root);

    cout << endl
         << endl;
    t.levelOrder(t.root);

    cout << endl
         << endl;
    cout << "Total no. of nodes are :-- " << t.allNodesCount(t.root) << endl
         << endl;

    cout << "No. of nodes having both the childs :-- " << t.bothChildNodes(t.root) << endl
         << endl;

    cout << "Sum of all the nodes is :-- " << t.sumOfALLNodes(t.root) << endl
         << endl;

    cout << "No. of leaf nodes are :-- " << t.leafNodes(t.root) << endl
         << endl;

    cout << "No.of nodes having exactly degree 2 are :-- " << t.exactlyDeg2(t.root) << endl
         << endl;

    cout << "No.of nodes having exactly degree 1 are :-- " << t.exactlyDeg1(t.root) << endl
         << endl;

    cout << "Total no. of non leaf nodes are :-- " << t.nonLeafNodes(t.root) << endl
         << endl;

    cout << "Height of the binary tree is :-- " << t.height(t.root) << endl
         << endl;

    return 0;
}