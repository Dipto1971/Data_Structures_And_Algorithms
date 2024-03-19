#include <iostream>
#include <vector>

// Function to print all prime numbers smaller than or equal to n
void sieveOfEratosthenes(int n) {
    vector<bool> prime(n + 1, true);

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}

int main() {
    int n = 10;
    
    cout << "Prime numbers smaller than or equal to " << n << ": ";
    sieveOfEratosthenes(n);
    
    return 0;
}
