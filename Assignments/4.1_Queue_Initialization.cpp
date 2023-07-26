#include<bits/stdc++.h>
using namespace std;

typedef struct Queue_c{
    int size;
    int front;
    int rear;
    int * arr;
}Q;

int isFull(Q * q){
    if(q->rear == q-> size -1) return 1;
    else return 0;
}

int isEmpty(Q *q){
    if(q->rear == q->front) return 1;
    else return 0;

}


void enqueue(Q *q, int value){
    if(!isFull(q)){
        q->rear++;
        q-> arr[q-> rear] = value;
    }
    else{
        cout << "Queue is full!" << endl;
    }
}

void dequeue(Q *q){
    int a= -1;
    if(!isEmpty){
        q-> front ++;
        a = q-> arr[q-> front];
    }
}

// void printQ(Q *q){
//     int strt = q->front + 1;
//     int end = q-> rear;
//     while(strt <= end){
//         cout << strt+1 << "numbered data is " << q-> arr[strt] << endl;
//         strt++;
//     }
// }


void printQ(Q* q) {
    int strt = q->front + 1;
    int end = q->rear;
    while (strt <= end) {
        cout << strt << "th data is " << q->arr[strt] << endl;
        strt++;
    }
}

int main(){
    Q *q = new Q;
    cout << "Enter the size of the Queue: ";
    int n; cin >> n;
    q->size = n;
    q-> front = q-> rear = -1;
    q->arr = new int [q->size];
    cout << "Initialized a Queue of size " << n << endl;

    cout << "Enter five datas to the Queue-> " << endl;

    for(int i=0; i<5; i++){
        cout << "Enter data: ";
        int data; cin >> data;

        enqueue(q, data);
    }
/*The code exits immediately because
there is no mechanism to keep the program running after enqueuing the elements*/
    printQ(q);
     
}