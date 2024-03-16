#include <iostream>
using namespace std;
// Function to find GCD using Euclid's algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a = 20, b = 28;

    cout << "GCD of " << a << " and " << b << " is: " << gcd(a, b) << endl;    
    return 0;
}
