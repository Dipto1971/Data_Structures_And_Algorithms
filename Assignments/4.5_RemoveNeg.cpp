/*
Exercise 7:
Delete all Negative Integer
Write a program that will take a queue of integers and deletes all negative integers
without changing the order of the remaining elements in queue.*/

#include <bits/stdc++.h>
using namespace std;

void deleteNegativeIntegers(queue<int>& q) {
    queue<int> temp;
    
    while (!q.empty()) {
        if (q.front() >= 0) {
            temp.push(q.front());
        }
        q.pop();
    }

    // Copy the elements back to the original queue
    while (!temp.empty()) {
        q.push(temp.front());
        temp.pop();
    }
}

int main() {
    queue<int> myQueue;
    
    myQueue.push(10);
    myQueue.push(-5);
    myQueue.push(20);
    myQueue.push(-15);
    myQueue.push(0);
    myQueue.push(-8);

    cout << "Original Queue: ";
    while (!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }

    cout << endl;

    myQueue.push(10);
    myQueue.push(-5);
    myQueue.push(20);
    myQueue.push(-15);
    myQueue.push(0);
    myQueue.push(-8);

    deleteNegativeIntegers(myQueue);

    cout << "Queue after deleting negative integers: ";
    while (!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }

    cout << endl;

    return 0;
}
