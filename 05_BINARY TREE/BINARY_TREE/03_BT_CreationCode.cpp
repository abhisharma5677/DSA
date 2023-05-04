//----------CREATING BINARY TREE IN MAIN---------------

#include <iostream>
using namespace std;

//----------------NODE CLASS--------------------
class node
{
public:
    int data;
    node *left;
    node *right;

public:
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

//----------------INORDER TRAVERSAL OF BINARY TREE----------
void inorder(node *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }
}

//----------------PREORDER TRAVERSAL OF BINARY TREE----------
void preorder(node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }
}

//-------------POSTORDER TRAVERSAL OF BINARY TREE----------
void postorder(node *p)
{
    if (p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        cout << p->data << " ";
    }
}

//-----------------MAIN FUNCTION----------------
int main()
{
    // CREATING BINARY TREE IN THE MAIN FUNCTION
    node *root = new node(1);
    root->left = new node(3);
    root->right = new node(5);
    root->left->left = new node(7);
    root->left->right = new node(9);
    root->right->left = new node(2);
    root->right->right = new node(4);

    cout << "Inorder traversal is :-- ";
    inorder(root);

    cout << endl
         << endl;

    cout << "Preorder traversal is :-- ";
    preorder(root);

    cout << endl
         << endl;

    cout << "Postorder traversal is :-- ";
    postorder(root);

    return 0;
}