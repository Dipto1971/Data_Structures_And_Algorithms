#include <bits/stdc++.h>
using namespace std;

int Sum_1 (int n) {
    return n * (n + 1) / 2;
    // Time Complexity: O(1)
}

int Sum_2 (int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
    // Time Complexity: O(n)
}

int Sum_3 (int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            sum++;
        }
    }
    return sum;
    // Time Complexity: O(n^2)
}


// Time complexity of the above three functions can be calculated using the following formula:
// T(n) = a * n^b + c
// where a, b, c are constants
// T(n) = Time complexity
// n = input size
// a, b, c = constants
// For Sum_1, a = 1, b = 1, c = 0
// For Sum_2, a = 1, b = 1, c = 1

int main() {
    
    return 0;
}