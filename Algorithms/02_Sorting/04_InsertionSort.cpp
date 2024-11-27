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