#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

struct stack_c
{
    int size;
    int top;
    int *arr;
};

/* conditional functions for stacks empty/full */

int isEmpty (struct stack_c * ptr){
    if(ptr -> top == -1){
        return 1;
    }else {
        return 0;
    }
}

int isFull (struct stack_c * ptr){
    if(ptr -> top == ptr -> size -1 ){
        return 1;
    }else {
        return 0;
    }
}

//Pushing in Stack
void push_c(struct stack_c *ptr, int data){
    if(isFull(ptr)){
        cout << "Stack Overflow!" << endl;
    }else{
        ptr -> top++;
        ptr->arr[ptr->top] = data;
    }
}

//popping element and return the popped element
int pop_c(struct stack_c * ptr){
    if(isEmpty){
        cout << "Nothing to pop, stack is empty!" << endl;
        return 1;
    }else{
        int value = ptr -> arr[ptr->top];
        ptr->top = ptr -> top-1;
        return value;  
    }
}

/*Peek: Tells a value of desired position from stack*/
int peek (struct stack_c * ptr, int i){
    int arrayInd = ptr -> top - i + 1;
    if(arrayInd < 0){
        cout << "Invalida position" << endl;
    }else{
        return ptr -> arr[arrayInd];
    }
}

void peekforAll(struct stack_c * ptr){
    for (int i = 1; i<= ptr->top; i++){
        printf("The value at position %d is %d \n", i, peek(ptr, i));
    }
}

int main()
{
    // struct stack_c s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *) malloc((s.size) * sizeof(int));

    /* Now making it a pointer, now I can pass it in functions and use it 
    as call-by-reference */

    struct stack_c *s;
    s -> size = 80;
    s -> top = -1;
    s -> arr = (int *) malloc((s -> size) * sizeof(int));

    if(isEmpty(s)){
        cout << "The stack is empty" << endl;
    }else{
        cout << "The stack is not empty" << endl;
    }

    for(int i = s -> top+1; i<80; i++){
        int n;  cin >> n;
        s -> arr[i] = n;
        s -> top++;
    }

    return 0;
}