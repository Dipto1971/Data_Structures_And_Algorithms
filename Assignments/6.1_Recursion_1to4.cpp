/*Exercise 1:
Write a C program to find power of any number using recursion.
Example:

Input any number: 5
Input power: 2
Output: 25

Exercise 2:
Write a C program to find GCD of two numbers using recursion.
Example:

Input first number: 10
Input second number: 15
Output GCD: 5

Exercise 3:
Write a C program to find LCM of two numbers using recursion.
Example:

Input first number: 12
Input second number: 30
Output LCM: 60

Exercise 4:
Write a program to check whether a number is palindrome or not using recursion.
Exercise 5:
Write a program to reverse a linked list using recursion*/

#include <iostream>
using namespace std;

int power(int base, int exponent) {
    if (exponent != 0)
        return (base * power(base, exponent - 1));
    else
        return 1;
}

int findGCD(int a, int b) {
    if (b != 0)
        return findGCD(b, a % b);
    else
        return a;
}

int findLCM(int a, int b) {
    static int ans = 0;
    ans += b;
    if ((ans % a == 0) && (ans % b == 0)) {
        return ans;
    } else {
        return findLCM(a, b);
    }
}

int reverseNumber(int num, int reversed) {
    if (num == 0)
        return reversed;

    reversed = (reversed * 10) + (num % 10);

    return reverseNumber(num / 10, reversed);
}

int main() {
    int base, exponent, gcdNum, lcmNum, palindrome;

    cout << "Enter the base and exponent: ";
    cin >> base >> exponent;
    cout << "Result of the power operation: " << power(base, exponent) << endl;

    cout << "Enter two numbers to find their GCD: ";
    cin >> gcdNum >> lcmNum;
    cout << "GCD of the numbers: " << findGCD(gcdNum, lcmNum) << endl;

    cout << "LCM of the numbers: " << findLCM(gcdNum, lcmNum) << endl;

    cout << "Enter a number to check if it is a palindrome: ";
    cin >> palindrome;

    int reversed = reverseNumber(palindrome, 0);

    if (reversed == palindrome) {
        cout << "YES, it is a palindrome!" << endl;
    } else {
        cout << "NO, it is not a palindrome!" << endl;
    }

    return 0;
}
