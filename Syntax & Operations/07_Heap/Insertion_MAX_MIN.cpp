#include <bits/stdc++.h>
using namespace std;

void ReheapUpMin(int heap[], int position) {
    if (position <= 1) {
        return;
    }

    int parent = position / 2;

    if (heap[position] < heap[parent]) {
        int temp = heap[position];
        heap[position] = heap[parent];
        heap[parent] = temp;

        ReheapUpMin(heap, parent);
    }
}

void ReheapDownMin(int heap[], int position, int heapSize) {
    int leftChild = 2 * position;
    int rightChild = 2 * position + 1;
    int smallest = position;

    if (leftChild <= heapSize && heap[leftChild] < heap[smallest]) {
        smallest = leftChild;
    }

    if (rightChild <= heapSize && heap[rightChild] < heap[smallest]) {
        smallest = rightChild;
    }

    if (smallest != position) {
        int temp = heap[position];
        heap[position] = heap[smallest];
        heap[smallest] = temp;

        ReheapDownMin(heap, smallest, heapSize);
    }
}

void InsertMin(int heap[], int *heapSize, int value) {
    (*heapSize)++;
    heap[*heapSize] = value;
    ReheapUpMin(heap, *heapSize);
}

void BuildMinHeap(int arr[], int n, int heap[]) {
    int heapSize = 0;

    for (int i = 0; i < n; i++) {
        InsertMin(heap, &heapSize, arr[i]);
    }
}

void ReheapUpMax(int heap[], int position) {
    if (position <= 1) {
        return;
    }

    int parent = position / 2;

    if (heap[position] > heap[parent]) {
        int temp = heap[position];
        heap[position] = heap[parent];
        heap[parent] = temp;

        ReheapUpMax(heap, parent);
    }
}

void ReheapDownMax(int heap[], int position, int heapSize) {
    int leftChild = 2 * position;
    int rightChild = 2 * position + 1;
    int largest = position;

    if (leftChild <= heapSize && heap[leftChild] > heap[largest]) {
        largest = leftChild;
    }

    if (rightChild <= heapSize && heap[rightChild] > heap[largest]) {
        largest = rightChild;
    }

    if (largest != position) {
        int temp = heap[position];
        heap[position] = heap[largest];
        heap[largest] = temp;

        ReheapDownMax(heap, largest, heapSize);
    }
}

void InsertMax(int heap[], int *heapSize, int value) {
    (*heapSize)++;
    heap[*heapSize] = value;
    ReheapUpMax(heap, *heapSize);
}

void BuildMaxHeap(int arr[], int n, int heap[]) {
    int heapSize = 0;

    for (int i = 0; i < n; i++) {
        InsertMax(heap, &heapSize, arr[i]);
    }
}

int main() {
    int arr[] = {9, 4, 7, 1, 2, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int minHeap[n + 1];
    int maxHeap[n + 1];

    BuildMinHeap(arr, n, minHeap);
    BuildMaxHeap(arr, n, maxHeap);

    cout << "Min Heap: ";
    for (int i = 1; i <= n; i++) {
        cout << minHeap[i] << " ";
    }

    cout << endl;

    cout << "Max Heap: ";
    for (int i = 1; i <= n; i++) {
        cout << maxHeap[i] << " ";
    }

    return 0;
}
