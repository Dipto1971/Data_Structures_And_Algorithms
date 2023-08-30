#include <bits/stdc++.h>
using namespace std;

void ReheapDown(int heap[], int position, int heapSize)
{
    int child = 2 * position;

    while (child <= heapSize)
    {
        // Compare left and right children
        if (child < heapSize && heap[child] > heap[child + 1])
        {
            child++;
        }

        // Compare parent with the smaller child
        if (heap[position] > heap[child])
        {
            int temp = heap[position];
            heap[position] = heap[child];
            heap[child] = temp;

            position = child;
            child = 2 * position;
        }
        else
        {
            break; // Heap property is satisfied
        }
    }
}

int DeleteMin(int heap[], int *heapSize)
{
    if (*heapSize == 0)
    {
        printf("Underflow: Heap is empty\n");
        return -1; // Return a sentinel value indicating underflow
    }

    int deletedValue = heap[1];
    heap[1] = heap[*heapSize];
    (*heapSize)--;
    ReheapDown(heap, 1, *heapSize);

    return deletedValue;
}

int main()
{
    int heap[] = {-1, 1, 2, 5, 9, 4, 7, 6}; // Min-heap with sentinel at index 0
    int heapSize = sizeof(heap) / sizeof(heap[0]) - 1;

    int n = heapSize;
    int sortedHeap[n] = {};
    int j = 0;
    while (heapSize != 0)
    {
        int deletedValue = DeleteMin(heap, &heapSize);
        sortedHeap[j] = deletedValue;
        j++;
    }
    cout << sortedHeap << " ";
    for(int i=0; i<n; i++){
        cout << sortedHeap[i] << " ";
    }

    return 0;
}
