#include<bits/stdc++.h>
using namespace std;

// Binary Search Function with Apprropriate Naming in C++
void binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        // This is how we calculate the middle element in C++
        // If we do (left + right) / 2, it may cause overflow if left + right is greater than INT_MAX
        if (arr[mid] == x) {
            cout << "Element is present at index " << mid;
            return;
        }
        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << "Element is not present in array";
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]); // This is how we calculate the size of an array in C++
    int x = 10;
    binarySearch(arr, n, x);
    return 0;
}