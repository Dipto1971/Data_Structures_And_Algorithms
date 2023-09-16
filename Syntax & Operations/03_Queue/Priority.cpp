#include <iostream>
#include <ctime>
using namespace std;

#define NUM_SERVERS 3
#define MAX_CALLS 1000

struct Call {
    int id;
    time_t enqueueTime;
    int duration; // Duration of the call in seconds
};

struct Server {
    int isFree;
    Call callHistory[MAX_CALLS];
    int callCount;
    int busyUntil; // Time when the server will be free
};

struct VirtualCallCenter {
    Server servers[NUM_SERVERS];
    Call customerQueue[MAX_CALLS];
    int front, rear;
};

void initialize(VirtualCallCenter &callCenter) {
    for (int i = 0; i < NUM_SERVERS; i++) {
        callCenter.servers[i].isFree = 1;
        callCenter.servers[i].callCount = 0;
        callCenter.servers[i].busyUntil = 0;
    }
    callCenter.front = callCenter.rear = -1;
}

void enqueue(VirtualCallCenter &callCenter, int id, int duration) {
    if (callCenter.rear == MAX_CALLS - 1) {
        cout << "Queue is full. Call " << id << " could not be enqueued." << endl;
        return;
    }
    Call call = {id, time(nullptr), duration};
    if (callCenter.front == -1) {
        callCenter.front = 0;
    }
    callCenter.rear++;
    callCenter.customerQueue[callCenter.rear] = call;
    
    // Automatically assign calls to servers based on load (less loaded server first).
    for (int i = 0; i < NUM_SERVERS; i++) {
        if (callCenter.servers[i].isFree) {
            if (callCenter.front <= callCenter.rear) {
                Call newCall = callCenter.customerQueue[callCenter.front];
                callCenter.servers[i].isFree = 0;
                callCenter.servers[i].busyUntil = time(nullptr) + newCall.duration;
                callCenter.servers[i].callHistory[callCenter.servers[i].callCount++] = newCall;
                cout << "Call " << newCall.id << " assigned to Server " << i + 1 << ". Duration: " << newCall.duration << " seconds." << endl;
                callCenter.front++;
            }
        }
    }
    cout << "Call " << id << " added to the queue. Duration: " << duration << " seconds." << endl;
}

void updateServerStatus(VirtualCallCenter &callCenter) {
    time_t currentTime = time(nullptr);
    for (int i = 0; i < NUM_SERVERS; i++) {
        if (!callCenter.servers[i].isFree && currentTime >= callCenter.servers[i].busyUntil) {
            callCenter.servers[i].isFree = 1;
        }
    }
}

void checkTimeLeft(VirtualCallCenter &callCenter) {
    for (int i = 0; i < NUM_SERVERS; i++) {
        if (!callCenter.servers[i].isFree) {
            time_t currentTime = time(nullptr);
            int timeLeft = callCenter.servers[i].busyUntil - currentTime;
            cout << "Server " << i + 1 << " will be free in " << timeLeft << " seconds." << endl;
        }
    }
}

void forwardCallsManually(VirtualCallCenter &callCenter) {
    if (callCenter.front > callCenter.rear) {
        cout << "No pending calls to forward." << endl;
        return;
    }

    for (int i = 0; i < NUM_SERVERS; i++) {
        if (callCenter.servers[i].isFree && callCenter.front <= callCenter.rear) {
            Call newCall = callCenter.customerQueue[callCenter.front];
            callCenter.servers[i].isFree = 0;
            callCenter.servers[i].busyUntil = time(nullptr) + newCall.duration;
            callCenter.servers[i].callHistory[callCenter.servers[i].callCount++] = newCall;
            cout << "Call " << newCall.id << " manually assigned to Server " << i + 1 << ". Duration: " << newCall.duration << " seconds." << endl;
            callCenter.front++;
        }
    }
}

int main() {
    VirtualCallCenter callCenter;
    initialize(callCenter);

    int choice, callId = 1, callDuration;

    while (true) {
        updateServerStatus(callCenter);
        
        cout << "\nMenu:" << endl;
        cout << "1. Enter a call (Automatic Assignment)" << endl;
        cout << "2. Show total pending calls" << endl;
        cout << "3. Check time left for servers to become free" << endl;
        cout << "4. Forward calls manually" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (callId <= MAX_CALLS) {
                    cout << "Enter the call duration (in seconds): ";
                    cin >> callDuration;
                    enqueue(callCenter, callId++, callDuration);
                } else {
                    cout << "Maximum number of calls reached." << endl;
                }
                break;
            case 2:
                cout << "Total pending calls: " << (callCenter.rear - callCenter.front + 1) << endl;
                break;
            case 3:
                checkTimeLeft(callCenter);
                break;
            case 4:
                forwardCallsManually(callCenter);
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
