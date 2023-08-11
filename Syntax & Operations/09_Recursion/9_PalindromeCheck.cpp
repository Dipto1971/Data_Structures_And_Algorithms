#include <stdio.h>

// Recursive function to check if a number is a palindrome
int isPalindrome(int num, int originalNum) {
    if (num == 0) {
        return originalNum;
    } else {
        originalNum = originalNum * 10 + num % 10;
        return isPalindrome(num / 10, originalNum);
    }
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    int result = isPalindrome(number, 0);

    if (result == number) {
        printf("%d is a palindrome.\n", number);
    } else {
        printf("%d is not a palindrome.\n", number);
    }

    return 0;
}
