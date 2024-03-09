#include <bits/stdc++.h>
using namespace std;

int fact (int n, int k){
    if ( n==0 || n==1 ) return k;
    cout << n << " " << k << endl;
    return fact(n-1, n*k);
}

int main(){
    cout << "Answer: " << fact(5, 1) << endl;
    return 0;
}