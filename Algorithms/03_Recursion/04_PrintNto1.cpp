#include <bits/stdc++.h>
using namespace std;

void printNto1(int n){
    if(n == 0) return;
    cout << n << " ";
    printNto1(n-1);
}

// auxiliary space complexity: O(1) -> The auxiliary space complexity of this function is O(1) because it only uses a constant amount of extra space regardless of the input size. This is because the function doesn't use any additional data structures or allocate memory dynamically.
// time complexity: O(n)
// Tail recursive? -> Yes

void print1toN(int n){
    if(n == 0) return;
    print1toN(n-1);
    cout << n << " ";
    // time complexity: O(n)
    // auxiliary space complexity: O(n)
    // Tail recursive? -> No
}

int main(){
    printNto1(10);
    cout << endl;
    print1toN(10);
    return 0;
}