#include <stdio.h>

// Recursive function to calculate the product of digits of a number
int productOfDigits(int num) {
    if (num == 0) {
        return 1;
    } else {
        return (num % 10) * productOfDigits(num / 10);
    }
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    int result = productOfDigits(number);

    printf("Product of digits of %d is %d.\n", number, result);

    return 0;
}
