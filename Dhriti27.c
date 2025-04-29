/*
Program to generate first n Fibonacci numbers starting with user-defined initial values
*/
#include <stdio.h>

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to generate and print Fibonacci series
void fibonacci(long long num1, long long num2, int terms) {
    int i;
    long long next_term;
    
    printf("\nFibonacci Series:\n");
    printf("1. %lld\n", num1);
    printf("2. %lld\n", num2);
    
    for (i = 3; i <= terms; i++) {
        // Check for overflow before addition
        if (num2 > 0 && num1 > 9223372036854775807LL - num2) {
            printf("\nError: Number overflow occurred at term %d!\n", i);
            return;
        }
        if (num2 < 0 && num1 < -9223372036854775807LL - num2) {
            printf("\nError: Number overflow occurred at term %d!\n", i);
            return;
        }
        
        next_term = num1 + num2;
        printf("%d. %lld\n", i, next_term);
        num1 = num2;
        num2 = next_term;
    }
}

int main() {
    long long num1, num2;
    int terms;
    char check;

    while (1) {
        // Input first number
        printf("Enter the first number: ");
        if (scanf("%lld%c", &num1, &check) != 2 || check != '\n') {
            printf("Error: Invalid input! Please enter an integer.\n");
            clearInputBuffer();
            continue;
        }

        // Input second number
        printf("Enter the second number: ");
        if (scanf("%lld%c", &num2, &check) != 2 || check != '\n') {
            printf("Error: Invalid input! Please enter an integer.\n");
            clearInputBuffer();
            continue;
        }

        // Input number of terms
        printf("Enter the number of terms (minimum 2): ");
        if (scanf("%d%c", &terms, &check) != 2 || check != '\n') {
            printf("Error: Invalid input! Please enter an integer.\n");
            clearInputBuffer();
            continue;
        }

        // Validate number of terms
        if (terms < 2) {
            printf("Error: Number of terms must be at least 2!\n");
            continue;
        }
        if (terms > 93) {
            printf("Error: Maximum 93 terms allowed to prevent overflow!\n");
            continue;
        }

        break;
    }

    fibonacci(num1, num2, terms);
    return 0;
}