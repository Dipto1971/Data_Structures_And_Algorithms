

#include <bits/stdc++.h>
using namespace std;

typedef struct stack_c
{
    int size;
    int top;
    int *arr;
} ss;

int isEmpty(ss *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(ss *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Pushing in Stack
void push_c(ss *ptr, int data)
{
    if (isFull(ptr))
    {
        cout << "Stack Overflow!" << endl;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}

// popping element and return the popped element
int pop_c(ss *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Nothing to pop, stack is empty!" << endl;
        return 1;
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top = ptr->top - 1;
        return value;
    }
}

/*Peek: Tells a value of desired position from stack*/
int peek(struct stack_c *ptr, int i)
{
    int arrayInd = ptr->top - i + 1;
    if (arrayInd < 0)
    {
        cout << "Invalid position" << endl;
    }
    else
    {
        return ptr->arr[arrayInd];
    }
}

void peekforAll(struct stack_c *ptr)
{
    for (int i = ptr->top; i >= 0; i--)
    {
        printf("The value at position %d is %d\n", i, ptr->arr[i]);
    }
}

int main()
{
    ss *s = new ss;
    cout << "Enter the size of the stack -> ";
    cin >> s->size;

    s->top = -1;
    s->arr = new int[s->size];
    cout << "Stack created!" << endl;

    while (true)
    {
        cout << "\t\t"
             << "stack Menu"
             << "\t\t" << endl;
        cout << "Enter 1 to push/Insert data" << endl;
        cout << "Enter 2 to pop/delete data" << endl;
        cout << "Enter 3 to see the elements of the data" << endl;
        cout << "Enter 4 to Insert a New Node " << endl;

        cout << "1 to 9? \n -> ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter data -> ";
            int data;
            cin >> data;
            push_c(s, data);
            cout << "After operation, new stack: \n";
            peekforAll(s);

            break;
        }
        case 2:
        {
            if (isEmpty(s))
            {
                cout << "Nothing popped as the stack is Empty, nothing to show" << endl;
            }
            else
            {
                int p_el = pop_c(s);
                cout << "Popped element: " << p_el << endl;
                if (isEmpty(s))
                {
                    cout << "Stack has become Empty!" << endl;
                }
                else
                {
                    cout << "After operation, new stack: " << endl;
                    peekforAll(s);
                }
            }
            break;
        }
        case 3:
        {
            peekforAll(s);
            break;
        }
        default:
        {
            cout << "Invalid choice. Please select a valid option." << endl;
            break;
        }
        }
    }
}