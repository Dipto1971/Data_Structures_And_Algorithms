#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(int n){
    if(n == 0) return 0;
    return n%10 + sumOfDigits(n/10);
    // time complexity: O(log10(n))
    // auxiliary space complexity: O(log10(n))
    // Tail recursive? -> No
}

int main(){
    int n = 12345;
    cout << sumOfDigits(n) << endl;
    return 0;
}