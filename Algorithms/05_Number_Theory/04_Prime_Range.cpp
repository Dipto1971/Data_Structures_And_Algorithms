#include <iostream>
#include <vector>
#include <cmath>

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

int highestOccurringDigit(int L, int R) {
    vector<int> digitFreq(10, 0);

    for (int i = L; i <= R; ++i) {
        if (isPrime(i)) {
            int temp = i;
            while (temp > 0) {
                int digit = temp % 10;
                digitFreq[digit]++;
                temp /= 10;
            }
        }
    }

    int maxFreq = 0, maxDigit = -1;
    for (int i = 0; i < 10; ++i) {
        if (digitFreq[i] > maxFreq) {
            maxFreq = digitFreq[i];
            maxDigit = i;
        }
    }

    return maxDigit;
}

int main() {
    int L = 1, R = 20;
    int result = highestOccurringDigit(L, R);

    if (result == -1)
        cout << "No prime numbers found between " << L << " and " << R << endl;
    else
        cout << "Highest occurring digit in prime numbers between " << L << " and " << R << " is: " << result << endl;

    return 0;
}
