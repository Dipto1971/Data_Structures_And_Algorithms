#include <bits/stdc++.h>
using namespace std;

struct stackc
{
    int size;
    int top;
    int *arr;
};

/* conditional functions for stacks empty/full */

int isEmpty(struct stackc *ptr)
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

int isFull(struct stackc *ptr)
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
void push_c(struct stackc *ptr, int data)
{
    if (isFull(ptr))
    {
        cout << "Stack Overflown! Can not push " << data << endl;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}

// popping element and return the popped element
int pop_c(struct stackc *ptr)
{
    if (isEmpty)
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

int main()
{
    struct stackc *s = (struct stackc *)malloc(sizeof(struct stackc));

    cout << "Enter the size of the stack -> ";
    int n_size;
    cin >> n_size;
    s->size = n_size;

    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    cout << "Stack has been created successfully \n";

    int i = 1;
    while (true)
    {
        cout << i <<"th value: ";
        int data;
        cin >> data;
        push_c(s, data);
        i++;
        if (isFull)
            break;
    }
}