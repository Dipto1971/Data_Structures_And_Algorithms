#include <stdio.h>

// Recursive function to calculate the sum of elements in an array
int sumArray(int arr[], int size) {
    if (size == 0) {
        return 0;
    } else {
        return arr[size - 1] + sumArray(arr, size - 1);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = sumArray(arr, size);

    printf("Sum of array elements: %d\n", result);

    return 0;
}
