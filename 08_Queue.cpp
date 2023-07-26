#include <bits/stdc++.h>
using namespace std;

struct queue_c{
    int size;
    int front;
    int rear;
    int * arr;
};

int isFull(struct queue_c * q){
    if(q->rear == q-> size -1) return 1;
    else return 0;
}

int isEmpty(struct queue_c *q){
    if(q->rear == q->front) return 1;
    else return 0;

}

void enqueue(struct queue_c *q, int value){
    if(!isFull(q)){
        q->rear++;
        q-> arr[q-> rear] = value;
    }
    else{
        cout << "Queue is full!" << endl;
    }
}

int dequeue (struct queue_c *q){
    int a=-1;
    if(!isEmpty(q)){
        q-> front ++;
        a = q-> arr[q-> front];
    }
    else{
        cout << "This queue is empty!" << endl;
    }
    return a;
}



int main(){
    struct queue_c *q;
    q-> size = 80;
    q-> front = q-> rear = -1;
    q-> arr = (int *) malloc((q-> size) * sizeof(int));

}