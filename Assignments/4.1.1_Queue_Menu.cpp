/*A queue or FIFO (first in, first out) is an abstract data type that serves as a collection of
elements, with two principal operations: enqueue, the process of adding an element to
the collection.(The element is added from the rear side) and dequeue, the process of
removing the first element that was added. (The element is removed from the front
side). It can be implemented by using both array and linked list.

Queue is used when things don’t have to be processed immediately but have to be
processed in First in First out order. This property of Queue makes it also useful in
following kind of scenarios.*/

/*Exercise 1:
Create Queue (Enqueue)
Create queue allocates a new node for the queue. It first initializes the front and rear
pointers to null. If the queue is empty then insert new node in queue and update both
the front and rear pointer with the address of the new node and if queue is not empty
then update the rear pointer with the address of the new node
Exercise 2:
Delete node from Queue (Dequeue)
It begins by checking to make sure there are data in queue. If there are, it takes the
addresses of the data being deleted , adjust the front pointer and remove the allocated
memory space.
Exercise 3:
Print Queue
The print function will print the entire queue data.
Exercise 4:
CopyQueue
Write a program that copies the content one queue to another*/

#include <iostream>
using namespace std;

typedef struct Queue_c
{
    int size;
    int front;
    int rear;
    int *arr;
} Q;

int isFull(Q *q)
{
    if (q->rear == q->size - 1)
        return 1;
    else
        return 0;
}

int isEmpty(Q *q)
{
    if (q->rear == q->front)
        return 1;
    else
        return 0;
}

void enqueue(Q *q, int value)
{
    if (!isFull(q))
    {
        q->rear++;
        q->arr[q->rear] = value;
    }
    else
    {
        cout << "Queue is full!" << endl;
    }
}

void dequeue(Q *q)
{
    if (!isEmpty(q))
    {
        q->front++;
    }
    else
    {
        cout << "Queue is empty!" << endl;
    }
}

int dequeue_val(Q *q)
{
    if (!isEmpty(q))
    {
        int value = q->arr[q->front + 1];
        q->front++;
        return value;
    }
}


void printQ(Q *q)
{
    if (isEmpty(q))
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        int strt = q->front + 1;
        int end = q->rear;
        while (strt <= end)
        {
            cout << strt << "th data is " << q->arr[strt] << endl;
            strt++;
        }
    }
}

void copyQueue(Q *q){
    Q *q_copy = new Q;
    q_copy->size = q->size;
    q_copy->front = q_copy->rear = -1;
    q_copy->arr = new int[q->size];
    cout << "Initialized a new Queue of size " << q->size << endl;

    while(!isEmpty(q)){
        int value = dequeue_val(q);
        enqueue(q_copy, value);
    }

    cout << "Queue copied successfully!" << endl;
}

int main()
{
    Q *q = new Q;
    cout << "Enter the size of the Queue: ";
    int n;
    cin >> n;
    q->size = n;
    q->front = q->rear = -1;
    q->arr = new int[q->size];
    cout << "Initialized a Queue of size " << n << endl;

    int choice, data;
    bool exit = false;

    while (!exit)
    {
        cout << "\nQueue Menu:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Print Queue" << endl;
        cout << "4. Make a copy of existing Queue" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data to enqueue: ";
            cin >> data;
            enqueue(q, data);
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            cout << "Queue elements:" << endl;
            printQ(q);
            break;
        case 4:
            copyQueue(q);
            break;
        case 5:
            exit = true;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
