/*
Program to calculate GCD and LCM of two integers
Uses the formula: LCM = (m × n) / GCD
*/
#include <stdio.h>
#include <stdlib.h>

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to calculate GCD using Euclidean algorithm
int calculateGCD(int m, int n) {
    int temp;
    while (n != 0) {
        temp = n;
        n = m % n;
        m = temp;
    }
    return m;
}

// Function to calculate LCM using GCD
long long calculateLCM(int m, int n, int gcd) {
    return ((long long)m * n) / gcd;
}

int main() {
    int m, n, gcd;
    long long lcm;
    char check;

    while (1) {
        // Input first number
        printf("Enter first integer (m): ");
        if (scanf("%d%c", &m, &check) != 2 || check != '\n') {
            printf("Error: Invalid input! Please enter an integer.\n");
            clearInputBuffer();
            continue;
        }

        // Input second number
        printf("Enter second integer (n): ");
        if (scanf("%d%c", &n, &check) != 2 || check != '\n') {
            printf("Error: Invalid input! Please enter an integer.\n");
            clearInputBuffer();
            continue;
        }

        // Check for zero input
        if (m == 0 || n == 0) {
            printf("Error: Numbers cannot be zero!\n");
            continue;
        }

        // Take absolute values for calculation
        m = abs(m);
        n = abs(n);
        break;
    }

    // Calculate GCD and LCM
    gcd = calculateGCD(m, n);
    lcm = calculateLCM(m, n, gcd);

    // Display results
    printf("\nResults:\n");
    printf("GCD(%d, %d) = %d\n", m, n, gcd);
    printf("LCM(%d, %d) = %lld\n", m, n, lcm);

    return 0;
} 