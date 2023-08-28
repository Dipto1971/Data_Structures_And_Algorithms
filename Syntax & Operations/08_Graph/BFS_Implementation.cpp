#include <iostream>
using namespace std;

struct queue_c
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct queue_c *q)
{
    return (q->rear + 1) % q->size == q->front;
}

int isEmpty(struct queue_c *q)
{
    return q->front == -1;
}

void enqueue(struct queue_c *q, int value)
{
    if (!isFull(q))
    {
        if (isEmpty(q))
            q->front = 0;
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = value;
    }
    else
    {
        cout << "Queue is full!" << endl;
    }
}

int dequeue(struct queue_c *q)
{
    int a = -1;
    if (!isEmpty(q))
    {
        a = q->arr[q->front];
        if (q->front == q->rear)
            q->front = q->rear = -1;
        else
            q->front = (q->front + 1) % q->size;
    }
    else
    {
        cout << "This queue is empty!" << endl;
    }
    return a;
}

int main()
{
    struct queue_c q; // Declare an instance of the queue
    q.size = 80;
    q.front = q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // BFS Implementation

    int u;
    int i = 0;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0}; //Mark all the nodes as unvisited
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}}; //This is the Adjacency matrix

    cout << i << " ";
    visited[i] = 1; //Changing the first node to be visited
    enqueue(&q, i); // Enqueue i for exploration

    while (!isEmpty(&q))
    {
        int node = dequeue(&q); //deleting the first node and visiting it
        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0) //First node's connected nodes checking && checking if theyre already visited or not
            {
                cout << j << " "; //Printing the Value
                visited[j] = 1; //Addressing the node as it is visited
                enqueue(&q, j); //To see the visited node's connected nodes, we enqueue the node.
            }
        }
    }

    free(q.arr); // Free allocated memory
    return 0;
}
