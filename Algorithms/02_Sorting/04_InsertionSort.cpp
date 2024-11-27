#include <bits/stdc++.h>
using namespace std;

void insertionSort (int arr[], int n){
    for (int i = 1; i < n; i++){
        int key = arr[i]; // Element to be compared
        int j = i-1; // Index of the element before the key
        while (j >= 0 && arr[j] > key){
            // Move elements of arr[0..i-1],
            // that are greater than key,
            arr[j+1] = arr[j];
            j--;
            // Decrement the index.
            // because we are moving the elements to the right 
        }
        arr[j+1] = key;
    }
}

int main (){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}