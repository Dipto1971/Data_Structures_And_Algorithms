#include <bits/stdc++.h>
using namespace std;

// Quick Search Function with Apprropriate Naming in C

int quickSearch(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]); // This is how we calculate the size of an array in C++
    int x = 10;
    int result = quickSearch(arr, n, x);
    (result == -1) ? cout << "Element is not present in array" : cout << "Element is present at index " << result;
    return 0;
}
