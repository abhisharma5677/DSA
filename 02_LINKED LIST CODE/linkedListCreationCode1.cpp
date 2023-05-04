//CREATING THE LINKED LIST USING AN ARRAY 


#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int data;
    node* next;
};

class linkedList{
    private:
       node* first;
    public:
       linkedList(){
          first=NULL;
       }

       linkedList(int A[],int size);
       //~linkedList();
       void display();
       void length();
       void Delete(int index);
       void insert(int index,int x);
};

linkedList::linkedList(int A[] , int size){
    node *last,*t;
    t=new node;
    t->data=A[0];
    t->next=NULL;
    first=t;
    last=first;

    for (int i = 1; i < size; i++)
    {
        t=new node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void linkedList::display(){
    node *p=first;
    while (p!=NULL)
    {
        cout<<p->data<<" -> ";
        p=p->next;
    }
}

void linkedList::length(){
    node *p=first;
    int count=0;
    while (p!=NULL)
    {
        count++;
        p=p->next;
    }
    cout<<endl;
    cout<<"THE LENGTH OF LINKED LIST IS = "<<count<<endl;
}

void linkedList::Delete(int index){
    node *p=NULL, *q=NULL;
    p=first;
    if (index==0)
    {
        first=first->next;
        p->next=NULL;
        delete p;
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        delete p;
    }
}

void linkedList::insert(int index,int x){
    node *p=first,*t=NULL;
        t=new node;
        t->data=x;
        t->next=NULL;

    if (index==0)
    {
        t->next=first;
        first=t;
    }
    else{
        for (int i = 1; i < index; i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }   
}

// linkedList::~linkedList(){
//     node *p=first;
//     while (p!=NULL)
//     {
//         delete p;
//         p=p->next;
//     }   
// }

int main(){
    int A[]={1,2,3,4,5,6,7};
    linkedList l(A,7);
    l.display();

    l.length();
     
    cout<<endl;
    int index=0;
    l.Delete(index);
    l.display();


    l.insert(3,25);
    cout<<endl;
    l.display();


    //l.~linkedList();

    return 0;
}