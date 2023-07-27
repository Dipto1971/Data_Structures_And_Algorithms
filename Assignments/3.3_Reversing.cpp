/*
-> Exercise 5:
Reversing Data
Reversing data requires that a given set of data be reordered so that the first and last elements
are exchanged. The idea of reversing data can be used in solving classical problem such as
converting a decimal number to a binary number. Now write a program using stack that will
convert decimal number to binary number.*/

#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct Stack {
    int top;
    int size;
    int *arr;
} Stack;

Stack* createStack(int size) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (int*)malloc(size * sizeof(int));
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == stack->size - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack Overflow!\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = data;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    int data = stack->arr[stack->top];
    stack->top--;
    return data;
}

void decimalToBinary(int decimalNum) {
    Stack* stack = createStack(32); // Assuming 32-bit binary representation
    
    while (decimalNum > 0) {
        int remainder = decimalNum % 2;
        push(stack, remainder);
        decimalNum = decimalNum / 2;
    }

    printf("Binary representation: ");
    while (!isEmpty(stack)) {
        printf("%d", pop(stack));
    }
    printf("\n");
}

int main() {
    int decimalNum;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNum);
    decimalToBinary(decimalNum);

    return 0;
}
