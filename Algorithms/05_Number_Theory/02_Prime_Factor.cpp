#include <iostream>
#include <vector>

// Function to print all prime factors of a given number
void primeFactors(int n) {
    while (n % 2 == 0) {
        cout << 2 << " ";
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            cout << i << " ";
            n = n / i;
        }
    }

    if (n > 2)
        cout << n << " ";
}

int main() {
    int n = 315;
    
    cout << "Prime factors of " << n << ": ";
    primeFactors(n);
    
    return 0;
}
