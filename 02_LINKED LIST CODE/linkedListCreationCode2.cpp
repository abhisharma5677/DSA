//CREATING THE LINKED LIST USING INSERTION FUNCTION

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;
};

class linkedList{
    node *first;

    public:
       linkedList(){
          first=NULL;
       }
       void insert(int x);
       void display();
};
node *p=NULL;
void linkedList::insert(int x){
    node *t=NULL;
    t=new node;
    t->data=x;
    t->next=NULL;

    if(p==NULL){
        first=t;
        p=first;
    }
    else
    {
        p->next=t;
        p=t;
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

int main(){
    linkedList l1;
    l1.insert(2);
    l1.insert(4);
    l1.insert(6);
    l1.insert(8);

    l1.display();
    return 0;
}