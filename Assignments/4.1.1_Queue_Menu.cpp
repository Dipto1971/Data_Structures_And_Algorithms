/*A queue or FIFO (first in, first out) is an abstract data type that serves as a collection of
elements, with two principal operations: enqueue, the process of adding an element to
the collection.(The element is added from the rear side) and dequeue, the process of
removing the first element that was added. (The element is removed from the front
side). It can be implemented by using both array and linked list.

Queue is used when things don’t have to be processed immediately but have to be
processed in First in First out order. This property of Queue makes it also useful in
following kind of scenarios.*/


#include <iostream>
using namespace std;

typedef struct Queue_c {
    int size;
    int front;
    int rear;
    int* arr;
} Q;

int isFull(Q* q) {
    if (q->rear == q->size - 1)
        return 1;
    else
        return 0;
}

int isEmpty(Q* q) {
    if (q->rear == q->front)
        return 1;
    else
        return 0;
}

void enqueue(Q* q, int value) {
    if (!isFull(q)) {
        q->rear++;
        q->arr[q->rear] = value;
    } else {
        cout << "Queue is full!" << endl;
    }
}

void dequeue(Q* q) {
    if (!isEmpty(q)) {
        q->front++;
    } else {
        cout << "Queue is empty!" << endl;
    }
}

void printQ(Q* q) {
    if (isEmpty(q)) {
        cout << "Queue is empty!" << endl;
    } else {
        int strt = q->front + 1;
        int end = q->rear;
        while (strt <= end) {
            cout << strt << "th data is " << q->arr[strt] << endl;
            strt++;
        }
    }
}

int main() {
    Q* q = new Q;
    cout << "Enter the size of the Queue: ";
    int n;
    cin >> n;
    q->size = n;
    q->front = q->rear = -1;
    q->arr = new int[q->size];
    cout << "Initialized a Queue of size " << n << endl;

    int choice, data;
    bool exit = false;

    while (!exit) {
        cout << "\nQueue Menu:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Print Queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
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
                exit = true;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
