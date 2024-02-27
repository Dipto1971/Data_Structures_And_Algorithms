#import <bits/stdc++.h>
using namespace std;

void mergeSort (int arr[], int l, int r){
    if (l < r) //At least two elements are there
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, r, m);
    }
    // Time Complexity: O(nlogn)
}

void merge (int arr[], int low, int high, int mid){
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++){
        left[i] = arr[low + i];
    }
    for (int i = 0; i < n2; i++){
        right[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2){
        if (left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = right[j];
        j++;
        k++;
    }
    // Time Complexity: O(n1 + n2) = O(n)
    // Auxiliary Space Complexity: O(n1 + n2) = O(n)
} 