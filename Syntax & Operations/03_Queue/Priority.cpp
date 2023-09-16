#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SERVERS 3
#define MAX_CALLS 1000

typedef struct {
    int id;
    time_t enqueueTime;
    int duration; // Duration of the call in seconds
} Call;

typedef struct {
    int isFree;
    Call callHistory[MAX_CALLS];
    int callCount;
    int busyUntil; // Time when the server will be free
} Server;

typedef struct {
    Server servers[NUM_SERVERS];
    Call customerQueue[MAX_CALLS];
    int front, rear;
} VirtualCallCenter;

void initialize(VirtualCallCenter *callCenter) {
    for (int i = 0; i < NUM_SERVERS; i++) {
        callCenter->servers[i].isFree = 1;
        callCenter->servers[i].callCount = 0;
        callCenter->servers[i].busyUntil = 0;
    }
    callCenter->front = callCenter->rear = -1;
}

void enqueue(VirtualCallCenter *callCenter, int id, int duration) {
    if (callCenter->rear == MAX_CALLS - 1) {
        printf("Queue is full. Call %d could not be enqueued.\n", id);
        return;
    }
    Call call = {id, time(NULL), duration};
    if (callCenter->front == -1) {
        callCenter->front = 0;
    }
    callCenter->rear++;
    callCenter->customerQueue[callCenter->rear] = call;
    
    // Automatically assign calls to servers based on load (less loaded server first).
    for (int i = 0; i < NUM_SERVERS; i++) {
        if (callCenter->servers[i].isFree) {
            if (callCenter->front <= callCenter->rear) {
                Call newCall = callCenter->customerQueue[callCenter->front];
                callCenter->servers[i].isFree = 0;
                callCenter->servers[i].busyUntil = time(NULL) + newCall.duration;
                callCenter->servers[i].callHistory[callCenter->servers[i].callCount++] = newCall;
                printf("Call %d assigned to Server %d. Duration: %d seconds.\n", newCall.id, i + 1, newCall.duration);
                callCenter->front++;
            }
        }
    }
    printf("Call %d added to the queue. Duration: %d seconds.\n", id, duration);
}

void updateServerStatus(VirtualCallCenter *callCenter) {
    time_t currentTime = time(NULL);
    for (int i = 0; i < NUM_SERVERS; i++) {
        if (!callCenter->servers[i].isFree && currentTime >= callCenter->servers[i].busyUntil) {
            callCenter->servers[i].isFree = 1;
        }
    }
}

void checkTimeLeft(VirtualCallCenter *callCenter) {
    for (int i = 0; i < NUM_SERVERS; i++) {
        if (!callCenter->servers[i].isFree) {
            time_t currentTime = time(NULL);
            int timeLeft = callCenter->servers[i].busyUntil - currentTime;
            printf("Server %d will be free in %d seconds.\n", i + 1, timeLeft);
        }
    }
}

void forwardCallsManually(VirtualCallCenter *callCenter) {
    if (callCenter->front > callCenter->rear) {
        printf("No pending calls to forward.\n");
        return;
    }

    for (int i = 0; i < NUM_SERVERS; i++) {
        if (callCenter->servers[i].isFree && callCenter->front <= callCenter->rear) {
            Call newCall = callCenter->customerQueue[callCenter->front];
            callCenter->servers[i].isFree = 0;
            callCenter->servers[i].busyUntil = time(NULL) + newCall.duration;
            callCenter->servers[i].callHistory[callCenter->servers[i].callCount++] = newCall;
            printf("Call %d manually assigned to Server %d. Duration: %d seconds.\n", newCall.id, i + 1, newCall.duration);
            callCenter->front++;
        }
    }
}

int main() {
    VirtualCallCenter callCenter;
    initialize(&callCenter);

    int choice, callId = 1, callDuration;

    while (1) {
        updateServerStatus(&callCenter);
        
        printf("\nMenu:\n");
        printf("1. Enter a call (Automatic Assignment)\n");
        printf("2. Show total pending calls\n");
        printf("3. Check time left for servers to become free\n");
        printf("4. Forward calls manually\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (callId <= MAX_CALLS) {
                    printf("Enter the call duration (in seconds): ");
                    scanf("%d", &callDuration);
                    enqueue(&callCenter, callId++, callDuration);
                } else {
                    printf("Maximum number of calls reached.\n");
                }
                break;
            case 2:
                printf("Total pending calls: %d\n", (callCenter.rear - callCenter.front + 1));
                break;
            case 3:
                checkTimeLeft(&callCenter);
                break;
            case 4:
                forwardCallsManually(&callCenter);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
