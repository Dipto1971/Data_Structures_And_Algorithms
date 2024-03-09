#include <iostream>
using namespace std;

int maxPieces (int n, int a, int b, int c){
    if(n == 0) return 0;
    if(n < 0) return -1;
    int res = max(maxPieces(n-a, a, b, c), maxPieces(n-b, a, b, c));
    res = max(res, maxPieces(n-c, a, b, c));
    if(res == -1) return -1;
    return res+1;
    // time complexity: O(3^n)
    // auxiliary space complexity: O(1)
    // Tail recursive? -> No
}

int main(){
    int n = 5, a = 2, b = 5, c = 1;
    cout << maxPieces(n, a, b, c) << endl;
    cout << maxPieces(23, 12, 9, 11) << endl;
    cout << maxPieces(9, 2, 2, 2) << endl;
    return 0;
}