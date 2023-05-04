// LINKED LIST CREATION CODE IN MAIN FUNCTION ITSELF

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

void display(node *first)
{
    while (first != NULL)
    {
        cout << first->data << " -> ";
        first = first->next;
    }
}

// void insertAfter(node *p, int x, int y)
// {
//     node *t = NULL;
//     t->data = y;
//     t->next = NULL;

//     if (x == 5)
//     {
//         cout << "cannot insert" << endl;
//     }
//     else
//     {
//         while (p != NULL)
//         {
//             if (p->data == x)
//             {
//                 t->next = p->next;
//                 p->next = t;
//             }
//             p = p->next;
//         }
//     }
// }

// void insert(node *head,int index,int x){
//     node *p=head,*t=NULL;
//         t=new node;
//         t->data=x;
//         t->next=NULL;

//     if (index==0)
//     {
//         t->next=head;
//         head=t;
//     }
//     else{
//         for (int i = 1; i < index; i++)
//         {
//             p=p->next;
//         }
//         t->next=p->next;
//         p->next=t;
//     }
// }

int main()
{
    node first, two, three, four, five, six;
    first.data = 5;
    two.data = 10;
    three.data = 15;
    four.data = 20;
    five.data = 25;
    six.data = 30;

    first.next = &two;
    two.next = &three;
    three.next = &four;
    four.next = &five;
    six.next = NULL;

    node *head = &first;

    display(head);
    cout << endl;

    int x = 15;
    int y = 16;

    node *t = NULL;
    t->data = y;
    t->next = NULL;

    while (head != NULL)
    {
        if (head->data == x)
        {
            t->next = head->next;
            head->next = t;
        }
        head = head->next;
    }

    head = &first;

    display(head);

    return 0;
}