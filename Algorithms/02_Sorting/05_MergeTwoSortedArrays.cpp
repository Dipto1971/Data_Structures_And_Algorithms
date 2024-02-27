// Merge Sort Algorithm
// 1. Divide and Conquer Algorithm (Divide the array into two halves, sort the two halves and then merge the two sorted halves)
// 2. Recursive Algorithm
// 3. Stable Sorting Algorithm
// 4. Theta(nlogn) Time Complexity & O(n) Auxiliary Space Complexity
// 5. Well suited for linked lists. Works in O(1) Auxiliary Space for linked lists.
// 6. Merge Sort is used in External Sorting
// 7. Quick Sort is preferred over Merge Sort for arrays because it has a small hidden constant factor and is an in-place sorting algorithm.
// 8. Merge Sort is preferred over Quick Sort for linked lists because it is a stable sorting algorithm and works in O(1) Auxiliary Space for linked lists.
#include <bits/stdc++.h>
using namespace std;

void mergetwoArray (int a[], int b[], int m, int n){
    int i = 0, j = 0;
    while (i < m && j < n){
        if (a[i] <= b[j]){
            cout << a[i] << " ";
            i++;
        }
        else {
            cout << b[j] << " ";
            j++;
        }
    }
    while (i < m){
        cout << a[i] << " ";
        i++;
    }
    while (j < n){
        cout << b[j] << " ";
        j++;
    }
    // Time Complexity: O(m + n)
}

void merge (int arr[], int low, int high, int mid){
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++){
        left[i] = arr[low + i];
    }
    for (int i = 0; i < n2; i++){
        right[i] = arr[n1+i];
    }
    int i = 0, j = 0, k = 0;
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
int main() {

}