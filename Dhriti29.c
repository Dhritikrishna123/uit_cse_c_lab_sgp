/*
Menu-driven program with recursive functions for:
1. Factorial calculation
2. Permutation (nPr) and Combination (nCr) calculation
3. x^n calculation
*/
#include <stdio.h>

// Recursive function to calculate factorial
int factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

// Recursive function to calculate power (x^n)
int power(int x, int n) {
    if (n == 0)
        return 1;
    return x * power(x, n - 1);
}

// Function to calculate nPr
int permutation(int n, int r) {
    return factorial(n) / factorial(n - r);
}

// Function to calculate nCr
int combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
    int choice;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Factorial\n");
        printf("2. Permutation (nPr) and Combination (nCr)\n");
        printf("3. Power (x^n)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int n;
            printf("Enter a number to find factorial: ");
            scanf("%d", &n);
            printf("Factorial of %d is %d\n", n, factorial(n));
        } else if (choice == 2) {
            int n, r;
            printf("Enter values for n and r: ");
            scanf("%d%d", &n, &r);
            if (r > n) {
                printf("Invalid input: r should not be greater than n.\n");
            } else {
                printf("nPr = %d\n", permutation(n, r));
                printf("nCr = %d\n", combination(n, r));
            }
        } else if (choice == 3) {
            int x, n;
            printf("Enter base x and exponent n: ");
            scanf("%d%d", &x, &n);
            printf("%d^%d = %d\n", x, n, power(x, n));
        } else if (choice == 4) {
            printf("Exiting program.\n");
        } else {
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
