#include <bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n <= 1) return n;
    return fib(n-1) + fib(n-2);
    // time complexity: O(2^n)
    // auxiliary space complexity: O(n)
    // Tail recursive? -> No
}

int fact(int n){
    if(n == 0) return 1;
    return n * fact(n-1);
    // time complexity: O(n)
    // auxiliary space complexity: O(n)
    // Tail recursive? -> No
}

int main(){
    cout << fib(10) << endl;
    cout << fact(10) << endl;
    return 0;
}