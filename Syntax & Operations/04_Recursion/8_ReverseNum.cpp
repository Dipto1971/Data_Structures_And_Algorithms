#include <stdio.h>

// Recursive function to reverse a number
int reverseNumber(int num) {
    static int reversed = 0;
    if (num == 0) {
        return 0;
    } else {
        reversed = reversed * 10 + num % 10;
        reverseNumber(num / 10);
        return reversed;
    }
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    int result = reverseNumber(number);

    printf("Reverse of %d is %d.\n", number, result);

    return 0;
}
