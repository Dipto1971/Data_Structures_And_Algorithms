#include <stdio.h>

// Recursive function to generate Fibonacci sequence
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int num_terms;

    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &num_terms);

    printf("Fibonacci sequence up to %d terms: ", num_terms);
    for (int i = 0; i < num_terms; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}
