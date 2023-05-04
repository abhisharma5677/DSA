// LINEAR QUEUE IMPLIMENTATION IN CPP

#include <iostream>
using namespace std;

class queue
{
private:
    int front;
    int rear;
    int size;
    int *q;

public:
    queue()
    {
        front = rear = -1;
        size = 10;
        q = new int[size];
    }
    queue(int n)
    {
        front = rear = -1;
        this->size = n;
        q = new int[this->size];
    }
    void enqueue(int x);
    void dequeue();
    bool isFull();
    bool isEmpty();
    void display();
};

bool queue::isFull()
{
    if (rear == (size - 1))
    {
        return true;
    }
    return false;
}

bool queue::isEmpty()
{
    if (front == rear)
    {
        return true;
    }
    return false;
}

void queue::enqueue(int x)
{
    if (isFull())
    {
        cout << endl
             << "QUEUE IS FULL i.e. OVERFLOW SITUATION" << endl;
    }
    else
    {
        rear++;
        q[rear] = x;
    }
}

void queue::dequeue()
{
    if (isEmpty())
    {
        cout << endl
             << "QUEUE IS EMPTY i.e. UNDERFLOW SITUATION" << endl;
    }
    else
    {
        int y = q[front + 1];
        front++;
        cout << endl
             << "DELETED ELEMENT IS " << y;
    }
}

void queue::display()
{

    cout << endl
         << "THE GIVEN QUEUE IS REPRESENTED AS :-" << endl;
    for (int i = (front + 1); i <= rear; i++)
    {
        cout << q[i] << endl;
    }
}

int main()
{
    int arr[] = {2, 4, 5, 6, 7, 8, 3};
    int len = sizeof(arr) / sizeof(arr[0]);

    queue q(len);

    for (int i = 0; i < len; i++)
    { // PUTTING ARRAY ELEMENTS IN THE QUEUE
        q.enqueue(arr[i]);
    }

    // display
    q.display();

    // overflow condition
    q.enqueue(19);

    // dequeuing
    q.dequeue();
    q.dequeue();

    // displaying
    q.display();

    return 0;
}