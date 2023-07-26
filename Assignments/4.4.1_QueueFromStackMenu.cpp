/*Exercise 6:
Stack to Queue Creation
Write a program that creates a Queue from a stack. After creation the top of the stack
will be the front of the queue.*/

#include <bits/stdc++.h>
using namespace std;

typedef struct stack_c {
    int top;
    int size;
    int *arr;
} ss;

typedef struct queue_c {
    int size;
    int front;
    int rear;
    int *arr;
} qq;

int QisFull(struct queue_c *q) {
    if (q->rear == q->size - 1)
        return 1;
    else
        return 0;
}

int QisEmpty(qq* q) {
    if (q->rear == q->front)
        return 1;
    else
        return 0;
}

void enqueue(struct queue_c *q, int value) {
    if (!QisFull(q)) {
        q->rear++;
        q->arr[q->rear] = value;
    } else {
        cout << "Queue is full!" << endl;
    }
}

int peek(ss *ptr, int i) {
    int arrayInd = ptr->top - i + 1;
    if (arrayInd < 0) {
        cout << "Invalid position" << endl;
    } else {
        return ptr->arr[arrayInd];
    }
}

void QfromStack(ss *s, qq *q) {
    for (int i = s->top; i >= 0; i--) {
        int data = s->arr[s->top];
        enqueue(q, data);
        s-> top--;
    }
}

void printQ(qq * q) {
    if (QisEmpty(q)) {
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
    ss *s = new ss;
    cout << "Enter the size of the stack -> ";
    int sz;
    cin >> sz;
    s->size = sz;
    s->top = -1;
    s->arr = new int[s->size];
    cout << "Stack created!" << endl;

    qq *q = new qq;
    q->size = sz;
    q->front = q->rear = -1;
    q->arr = new int[sz];
    cout << "Queue initialization completed!" << endl;

    int choice;
    int data;
    while (true) {
        cout << "-------------------------" << endl;
        cout << "Menu:" << endl;
        cout << "1. Push data into the stack" << endl;
        cout << "2. Peek data from the stack" << endl;
        cout << "3. Convert Stack to Queue" << endl;
        cout << "4. Print the new Queue" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1/2/3/4/5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (s->top == s->size - 1) {
                    cout << "Stack Overflow!" << endl;
                } else {
                    cout << "Enter data: ";
                    cin >> data;
                    s->top++;
                    s->arr[s->top] = data;
                    cout << "Data pushed into the stack!" << endl;
                }
                break;

            case 2:
                if (s->top == -1) {
                    cout << "Stack Underflow! No data in the stack." << endl;
                } else {
                    cout << "Enter position (1-" << s->top + 1 << ") to peek data from the stack: ";
                    int position;
                    cin >> position;
                    if (position < 1 || position > s->top + 1) {
                        cout << "Invalid position!" << endl;
                    } else {
                        int data = peek(s, position);
                        cout << "Data at position " << position << " in the stack: " << data << endl;
                    }
                }
                break;

            case 3:
                QfromStack(s, q);
                cout << "Stack converted to Queue!" << endl;
                break;

            case 4:
                cout << "Printing the new Queue: " << endl;
                printQ(q);
                break;

            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice! Please select a valid option." << endl;
        }
    }

    return 0;
}
