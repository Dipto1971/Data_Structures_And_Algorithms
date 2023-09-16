#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SERVERS 3
#define MAX_CALLS 10

typedef struct {
    int id;
    time_t enqueueTime;
} Call;

typedef struct {
    int isFree;
    Call callHistory[MAX_CALLS];
    int callCount;
} Server;

typedef struct {
    Server servers[NUM_SERVERS];
    Call customerQueue[MAX_CALLS];
    int front, rear ;
} VirtualCallCenter;

void initialize(VirtualCallCenter *callCenter) {
    for (int i = 0; i < NUM_SERVERS; i++) {
        callCenter->servers[i].isFree = 1;
        callCenter->servers[i].callCount = 0;
    }
    callCenter->front = callCenter->rear = -1;
}

void enqueue(VirtualCallCenter *callCenter, int id) {
    if (callCenter->rear == MAX_CALLS - 1) {
        printf("Queue is full. Call %d could not be enqueued.\n", id);
        return;
    }
    Call call = {id, time(NULL)};
    if (callCenter->front == -1) {
        callCenter->front = 0;
    }
    callCenter->rear++;
    callCenter->customerQueue[callCenter->rear] = call;
    printf("Call %d added to the queue.\n", id);
}

Call dequeue(VirtualCallCenter *callCenter) {
    Call emptyCall = {-1, 0};
    if (callCenter->front == -1) {
        return emptyCall; // Queue is empty
    }
    Call call = callCenter->customerQueue[callCenter->front];
    callCenter->front++;
    if (callCenter->front > callCenter->rear) {
        callCenter->front = callCenter->rear = -1;
    }
    return call;
}

void forwardCall(VirtualCallCenter *callCenter) {
    for (int i = 0; i < NUM_SERVERS; i++) {
        if (callCenter->servers[i].isFree) {
            while (callCenter->front <= callCenter->rear) { // Forward all available calls.
                Call call = dequeue(callCenter);
                if (call.id != -1) {
                    callCenter->servers[i].isFree = 0;
                    callCenter->servers[i].callHistory[callCenter->servers[i].callCount++] = call;
                    printf("Call %d assigned to Server %d.\n", call.id, i + 1);
                } else {
                    break; // No more calls in the queue.
                }
            }
        }
    }
}

void countCallsPerServer(VirtualCallCenter *callCenter) {
    for (int i = 0; i < NUM_SERVERS; i++) {
        printf("Server %d handled %d calls.\n", i + 1, callCenter->servers[i].callCount);
    }
}

void calculateWaitTime(VirtualCallCenter *callCenter) {
    for (int i = 0; i < NUM_SERVERS; i++) {
        for (int j = 0; j < callCenter->servers[i].callCount; j++) {
            Call call = callCenter->servers[i].callHistory[j];
            time_t waitTime = time(NULL) - call.enqueueTime;
            printf("Call %d waited for %ld seconds.\n", call.id, waitTime);
        }
    }
}

int main() {
    VirtualCallCenter callCenter;
    initialize(&callCenter);

    int choice, callId = 1;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enter a call\n");
        printf("2. Show total pending calls\n");
        printf("3. Forward calls\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (callId <= MAX_CALLS) {
                    enqueue(&callCenter, callId++);
                } else {
                    printf("Maximum number of calls reached.\n");
                }
                break;
            case 2:
                printf("Total pending calls: %d\n", (callCenter.rear - callCenter.front + 1));
                break;
            case 3:
                forwardCall(&callCenter);
                calculateWaitTime(&callCenter);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
