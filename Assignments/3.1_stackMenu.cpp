#include <bits/stdc++.h>
using namespace std;

typedef struct stack_c {
    int size;
    int top;
    int* arr;
} ss;

int isEmpty(ss* ptr) {
    return ptr->top == -1;
}

int isFull(ss* ptr) {
    return ptr->top == ptr->size - 1;
}

void push_c(ss* ptr, int data) {
    if (isFull(ptr)) {
        cout << "Stack Overflow!" << endl;
        return;
    }
    ptr->top++;
    ptr->arr[ptr->top] = data;
}

int pop_c(ss* ptr) {
    if (isEmpty(ptr)) {
        cout << "Stack Underflow!" << endl;
        return -1;
    }
    int value = ptr->arr[ptr->top];
    ptr->top--;
    return value;
}

void peekforAll(struct stack_c* ptr) {
    for (int i = ptr->top; i >= 0; i--) {
        printf("The value at position %d is %d\n", i, ptr->arr[i]);
    }
}

int main() {
    ss* s = new ss;
    cout << "Enter the size of the stack -> ";
    cin >> s->size;
    s->top = -1;
    s->arr = new int[s->size];
    cout << "Stack created!" << endl;

    while (true) {
        cout << "\t\tStack Menu\t\t" << endl;
        cout << "Enter 1 to push/Insert data" << endl;
        cout << "Enter 2 to pop/delete data" << endl;
        cout << "Enter 3 to see the elements of the data" << endl;
        cout << "Enter 4 to exit" << endl;

        cout << "Enter your choice (1 to 4): ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Enter data: ";
            int data;
            cin >> data;
            push_c(s, data);
            cout << "After operation, new stack: " << endl;
            peekforAll(s);
            break;
        }
        case 2: {
            int p_el = pop_c(s);
            if (p_el != -1) {
                cout << "Popped element: " << p_el << endl;
                if (!isEmpty(s)) {
                    cout << "After operation, new stack: " << endl;
                    peekforAll(s);
                } else {
                    cout << "Stack has become Empty!" << endl;
                }
            }
            break;
        }
        case 3: {
            if (!isEmpty(s)) {
                cout << "Elements of the stack: " << endl;
                peekforAll(s);
            } else {
                cout << "Stack is Empty!" << endl;
            }
            break;
        }
        case 4: {
            delete[] s->arr;
            delete s;
            cout << "Exiting the program. Goodbye!" << endl;
            return 0;
        }
        default: {
            cout << "Invalid choice. Please select a valid option." << endl;
            break;
        }
        }
    }
}
