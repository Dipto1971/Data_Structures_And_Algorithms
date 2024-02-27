#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sorting in ascending order
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sorting in descending order
    sort(arr, arr + n, greater<int>());
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    vector<int> v = {50, 40, 30, 20, 10};

    // Sorting in ascending order
    sort(v.begin(), v.end());
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    // Sorting in descending order
    sort(v.begin(), v.end(), greater<int>());
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

// Sort Function internally uses Quick Sort algorithm. It is a comparison based sorting algorithm. Time complexity of Quick Sort is O(nlogn) in average and O(n^2) in worst case.

// The sort function can also be used to sort a vector. The syntax is sort(v.begin(), v.end()) for sorting in ascending order and sort(v.begin(), v.end(), greater<int>()) for sorting in descending order.

// An Unstable sorting algorithm does not maintain the relative order of equal elements. For example, if there are two 5s in the array, then the relative order of these two 5s may not be maintained after sorting. Quick Sort is an example of an unstable sorting algorithm.
// A Stable sorting algorithm maintains the relative order of equal elements. For example, if there are two 5s in the array, then the relative order of these two 5s will be maintained after sorting. Merge Sort is an example of a stable sorting algorithm.
// Example Stable Sorting Algorithm: Merge Sort, Bubble Sort, Insertion Sort, Tim Sort
