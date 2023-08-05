#include <stdio.h>

// Recursive function to calculate the power of a number (x^y)
int power(int x, int y) {
    if (y == 0) {
        return 1;
    } else {
        return x * power(x, y - 1);
    }
}

int main() {
    int base, exponent;

    printf("Enter the base: ");
    scanf("%d", &base);

    printf("Enter the exponent: ");
    scanf("%d", &exponent);

    int result = power(base, exponent);

    printf("%d raised to the power of %d is %d.\n", base, exponent, result);

    return 0;
}
