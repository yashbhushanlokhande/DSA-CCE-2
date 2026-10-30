#include <iostream>
using namespace std;

const int MAX = 5;

class Queue
{
private:
    int a[MAX];
    int front;
    int rear;

public:
    // Constructor
    Queue()
    {
        front = -1;
        rear = -1;
    }

    // Check if queue is empty
    bool empty()
    {
        return (front == -1 && rear == -1);
    }

    // Check if queue is full
    bool full()
    {
        return (rear == MAX - 1);
    }

    // Insert element
    void enqueue(int x)
    {
        if (full())
        {
            cout << "\nQueue is full";
            return;
        }

        if (empty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear++;
        }

        a[rear] = x;
    }

    // Remove element
    int dequeue()
    {
        if (empty())
        {
            cout << "\nQueue is empty";
            return -1;
        }

        int x = a[front];

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }

        return x;
    }

    // Get front element
    int peek()
    {
        if (empty())
        {
            cout << "\nQueue is empty";
            return -1;
        }

        return a[front];
    }

    // Display queue
    void display()
    {
        if (empty())
        {
            cout << "\nQueue is empty";
            return;
        }

        cout << "\nQueue elements:";
        for (int i = front; i <= rear; i++)
        {
            cout << "\t" << a[i];
        }
    }
};

int main()
{
    int x;
    Queue q;

    // Insert elements
    q.enqueue(25);
    q.enqueue(57);
    q.enqueue(25);
    q.enqueue(82);
    q.enqueue(99);

    // Display queue
    q.display();

    // Delete element
    x = q.dequeue();
    cout << "\nRemoved: " << x;

    // Display after deletion
    q.display();

    // Show front element
    x = q.peek();
    cout << "\nFront element is: " << x;

    return 0;
}


\\output:
[Running] cd "d:\yashbhushan lokhande\" && g++ queuearray.cpp -o queuearray && "d:\yashbhushan lokhande\"queuearray

Queue elements:	25	57	25	82	99
Removed: 25
Queue elements:	57	25	82	99
Front element is: 57