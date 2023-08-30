#include <bits/stdc++.h>
using namespace std;

void ReheapUp(int heap[], int position) {
    if (position <= 1) {
        return; // Base case: reached the root or an invalid position
    }

    int parent = position / 2;

    if (heap[position] < heap[parent]) {
        int temp = heap[position];
        heap[position] = heap[parent];
        heap[parent] = temp;

        ReheapUp(heap, parent); // Recurse on the parent
    }
}

void Insert(int heap[], int *heapSize, int value) {
    (*heapSize)++;
    heap[*heapSize] = value;
    ReheapUp(heap, *heapSize);
}

void BuildMinHeap(int arr[], int n, int heap[]) {
    int heapSize = 0;

    for (int i = 0; i < n; i++) {
        Insert(heap, &heapSize, arr[i]);
    }
}

int main() {
    cout << "Enter size of Array: ";
    int n; cin >> n;
    int arr[n];
    for (int i=0; i<n; i++){
        int data;
        cin >> data;
        arr[i] = data;
    }
    cout << "Heap process is starting.." << endl;

    int heap[n+1]; 

    BuildMinHeap(arr, n, heap);

    printf("Min Heap: ");
    for (int i = 1; i <= n; i++) {
       cout << heap[i] << " ";
    }

    return 0;
}
