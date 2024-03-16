#include <iostream>
#include <vector>

// Function to print all prime numbers smaller than or equal to n
void sieveOfEratosthenes(int n) {
    // Create a boolean array "prime[0..n]" and initialize
    // all entries as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    std::vector<bool> prime(n + 1, true);

    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            std::cout << p << " ";
}

int main() {
    int n = 10;
    
    std::cout << "Prime numbers smaller than or equal to " << n << ": ";
    sieveOfEratosthenes(n);
    
    return 0;
}
