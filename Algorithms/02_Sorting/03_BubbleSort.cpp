# include <bits/stdc++.h>
using namespace std;

void bubbleSort (arr, n){
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                // Logic:
                // If the array is sorted,
                // then no swapping will be done in the inner loop
            }
        }
    }
}

void optimizedBubbleSort (arr, n){
    bool swapped;
    for (int i = 0; i < n-1; i++){
        swapped = false;
        for (int j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (swapped == false){
            break;
        }
    }
}
// Better because 
// it reduces the number of iterations in the best case

int main (){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}