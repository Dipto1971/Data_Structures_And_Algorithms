/*Write a program that creates a Queue from a stack. After creation the top of the stack
will be the front of the queue.*/

#include <bits/stdc++.h>
using namespace std;

typedef struct stack_c{
    int top;
    int size;
    int *arr;
}ss;

typedef struct queue_c{
    int size;
    int front;
    int rear;
    int *arr;
}qq;

int QisFull(struct queue_c * q){
    if(q->rear == q-> size -1) return 1;
    else return 0;
}
void enqueue(struct queue_c *q, int value){
    if(!QisFull(q)){
        q->rear++;
        q-> arr[q-> rear] = value;
    }
    else{
        cout << "Queue is full!" << endl;
    }
}

int peek (ss * ptr, int i){
    int arrayInd = ptr -> top - i + 1;
    if(arrayInd < 0){
        cout << "Invalid position" << endl;
    }else{
        return ptr -> arr[arrayInd];
    }
}

void QfromStack(ss * s, qq *q){
    for(int i=s->top; i>=0; i--){
        int data = s->arr[s->top];
        enqueue(q, data);
    }
}

int main(){
    ss* s = new ss;
    cout << "Enter the size of the stack -> ";
    int sz; cin >> sz;
    s->size = sz;
    s->top = -1;
    s->arr = new int[s->size];
    cout << "Stack created!" << endl;

    qq *q = new qq;
    q->size = sz;
    q-> front = q-> rear = -1;
    q-> arr = new int[sz];
    cout << "Queue initialization completed!" << endl;

    


}