#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

int front = -1, rear = -1, inp_array[SIZE];

void enqueue();
void dequeue();
void show();
int size();
void findMax();

int main()
{
    int choice;

    while (1)
    {
        printf("\nPerform operations on the queue:");
        printf("\n1. Enqueue the element\n2. Dequeue the element\n3. Show\n4. End\n5. Display Size\n6. Find Maximum Element");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            show();
            break;
        case 4:
            exit(0);
        case 5:
            printf("\nSize of the queue: %d", size());
            break;
        case 6:
            findMax();
            break;
        default:
            printf("\nInvalid choice!!");
        }
    }
}

void enqueue()
{
    int x;

    if ((rear + 1) % SIZE == front)
    {
        printf("\nOverflow!!");
    }
    else
    {
        printf("\nEnter the element to be added to the queue: ");
        scanf("%d", &x);
        if (front == -1)
            front = 0; 
        rear = (rear + 1) % SIZE;
        inp_array[rear] = x;
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nDequeued element: %d", inp_array[front]);
        if (front == rear)
        {
            
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }
}

void show()
{
    if (front == -1)
    {
        printf("\nQueue is empty!!");
    }
    else
    {
        printf("\nElements present in the queue: ");
        int i = front;
        while (1)
        {
            printf("%d ", inp_array[i]);
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int size()
{
    if (front == -1)
        return 0;
    if (rear >= front)
        return rear - front + 1;
    return SIZE - front + rear + 1;
}

void findMax()
{
    if (front == -1)
    {
        printf("\nQueue is empty!!");
    }
    else
    {
        int max = inp_array[front];
        int i = front;
        while (1)
        {
            if (inp_array[i] > max)
                max = inp_array[i];
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        printf("\nMaximum element in the queue: %d", max);
    }
}