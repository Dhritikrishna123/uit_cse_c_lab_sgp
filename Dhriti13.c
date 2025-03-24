/*
Program to Calculate Permutations and Combinations
Features: Calculate nPr and nCr for given n and r values
*/
#include <stdio.h>

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to calculate factorial
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
        // Check for overflow
        if (result == 0) {
            printf("Error: Factorial calculation09876 overflow!\n");
            return 0;
        }
    }
    return result;
}

// Function to calculate Permutation (nPr)
unsigned long long calculatePermutation(int n, int r) {
    if (n < r) return 0;  // Invalid case
    
    unsigned long long numerator = factorial(n);
    if (numerator == 0) return 0;  // Overflow occurred
    
    unsigned long long denominator = factorial(n - r);
    if (denominator == 0) return 0;  // Overflow occurred
    
    // Check for division overflow
    if (numerator < denominator) {
        printf("Error: Calculation overflow!\n");
        return 0;
    }
    
    return numerator / denominator;
}

// Function to calculate Combination (nCr)
unsigned long long calculateCombination(int n, int r) {
    if (n < r) return 0;  // Invalid case
    
    // Use smaller r value for optimization
    if (r > n/2) {
        r = n - r;
    }
    
    unsigned long long numerator = factorial(n);
    if (numerator == 0) return 0;  // Overflow occurred
    
    unsigned long long denominator = factorial(r) * factorial(n - r);
    if (denominator == 0) return 0;  // Overflow occurred
    
    // Check for division overflow
    if (numerator < denominator) {
        printf("Error: Calculation overflow!\n");
        return 0;
    }
    
    return numerator / denominator;
}

int main() {
    int n, r;
    char check;
    
    // Input n
    while (1) {
        printf("Enter the value of n (total objects): ");
        if (scanf("%d%c", &n, &check) != 2 || check != '\n' || n < 0) {
            printf("Error: Please enter a valid non-negative integer for n.\n");
            clearInputBuffer();
            continue;
        }
        break;
    }
    
    // Input r
    while (1) {
        printf("Enter the value of r (objects selected): ");
        if (scanf("%d%c", &r, &check) != 2 || check != '\n' || r < 0) {
            printf("Error: Please enter a valid non-negative integer for r.\n");
            clearInputBuffer();
            continue;
        }
        if (r > n) {
            printf("Error: r cannot be greater than n.\n");
            continue;
        }
        break;
    }
    
    // Calculate and display results
    printf("\nFor n = %d and r = %d:\n", n, r);
    
    // Calculate Permutation (nPr)
    unsigned long long perm = calculatePermutation(n, r);
    if (perm > 0) {
        printf("Permutation (%dP%d) = %llu\n", n, r, perm);
    } else {
        printf("Permutation (%dP%d) = Calculation Error\n", n, r);
    }
    
    // Calculate Combination (nCr)
    unsigned long long comb = calculateCombination(n, r);
    if (comb > 0) {
        printf("Combination (%dC%d) = %llu\n", n, r, comb);
    } else {
        printf("Combination (%dC%d) = Calculation Error\n", n, r);
    }
    
    return 0;
} 