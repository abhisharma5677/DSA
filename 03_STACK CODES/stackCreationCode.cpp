//Stack Implimentation code in CPP

#include <iostream>
using namespace std;

class stack
{
    int top;
    int size;
    int *q;

public:
    stack()
    {
        top = -1;
        size = 10;
        q = new int[size];
    }

    stack(int n)
    {
        top = -1;
        this->size = n;
        q = new int[this->size];
    }
    bool isFull();
    bool isEmpty();
    void push(int x);
    int pop();
    void display();
    int peek();
};

bool stack::isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    return false;
}

bool stack::isFull()
{
    if (top == (size - 1))
    {
        return true;
    }
    return false;
}

void stack::push(int x)
{
    if (isFull())
    {
        cout << endl
             << "OVERFLOW" << endl;
    }
    else
    {
        top++;
        q[top] = x;
    }
}

int stack::pop()
{
    int x = -1;
    if (isEmpty())
    {
        cout << endl
             << "UNDERFLOW" << endl;
    }
    else
    {
        x = q[top];
        top--;
    }

    return x;
}

int stack::peek()
{
    return q[top];
}

void stack::display()
{
    for (int i = top; i >= 0; i--)
    {
        cout << q[i] << endl;
    }
}

int main()
{
    int arr[] = {9, 7, 5, 3, 1};
    int y = 5;

    stack st(5);

    // PUSHING THE ELEMENTS
    for (int i = 0; i < 5; i++)
    {
        st.push(arr[i]);
    }

    st.display();

    // OVERFLOW CONDITION
    st.push(10);

    // pop
    cout << endl
         << st.pop() << endl;
    cout << endl
         << st.pop() << endl;

    // PEEK ELEMENT
    cout << endl
         << "Peek element is = " << st.peek() << endl;

    // DISPLAY
    st.display();

    return 0;
}