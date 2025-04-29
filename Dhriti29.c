/*
Menu-driven program with recursive functions for:
1. Factorial calculation
2. Permutation (nPr) and Combination (nCr) calculation
3. x^n calculation
*/
#include <stdio.h>
#include <stdlib.h>

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Recursive function to calculate factorial
long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// Function to calculate nPr using factorial
long long permutation(int n, int r) {
    return factorial(n) / factorial(n - r);
}

// Function to calculate nCr using factorial
long long combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

// Recursive function to calculate x^n
double power_xn(double x, int n) {
    if (n == 0) return 1;
    if (n < 0) return 1.0 / power_xn(x, -n);
    return x * power_xn(x, n - 1);
}

// Function to display menu and get choice
int getMenuChoice() {
    int choice;
    char check;
    
    printf("\nMenu:\n");
    printf("1. Calculate factorial recursively\n");
    printf("2. Calculate nPr and nCr\n");
    printf("3. Calculate x^n recursively\n");
    printf("4. Exit\n");
    printf("Enter your choice (1-4): ");
    
    if (scanf("%d%c", &choice, &check) != 2 || check != '\n') {
        printf("Error: Invalid input!\n");
        clearInputBuffer();
        return -1;
    }
    
    if (choice < 1 || choice > 4) {
        printf("Error: Please enter a number between 1 and 4!\n");
        return -1;
    }
    
    return choice;
}

int main() {
    int choice, n, r;
    double x;
    char check;
    
    while (1) {
        choice = getMenuChoice();
        if (choice == -1) continue;
        
        switch (choice) {
            case 1:
                // Factorial calculation
                printf("Enter a non-negative integer: ");
                if (scanf("%d%c", &n, &check) != 2 || check != '\n') {
                    printf("Error: Invalid input!\n");
                    clearInputBuffer();
                    break;
                }
                if (n < 0) {
                    printf("Error: Factorial is not defined for negative numbers!\n");
                    break;
                }
                if (n > 20) {
                    printf("Error: Input too large! Maximum allowed is 20.\n");
                    break;
                }
                printf("%d! = %lld\n", n, factorial(n));
                break;
                
            case 2:
                // nPr and nCr calculation
                printf("Enter n (total items): ");
                if (scanf("%d%c", &n, &check) != 2 || check != '\n') {
                    printf("Error: Invalid input!\n");
                    clearInputBuffer();
                    break;
                }
                printf("Enter r (items to choose): ");
                if (scanf("%d%c", &r, &check) != 2 || check != '\n') {
                    printf("Error: Invalid input!\n");
                    clearInputBuffer();
                    break;
                }
                
                // Validate inputs
                if (n < 0 || r < 0) {
                    printf("Error: n and r must be non-negative!\n");
                    break;
                }
                if (r > n) {
                    printf("Error: r cannot be greater than n!\n");
                    break;
                }
                if (n > 20) {
                    printf("Error: n too large! Maximum allowed is 20.\n");
                    break;
                }
                
                printf("\nResults:\n");
                printf("%dP%d = %lld (Permutation)\n", n, r, permutation(n, r));
                printf("%dC%d = %lld (Combination)\n", n, r, combination(n, r));
                break;
                
            case 3:
                // x^n calculation
                printf("Enter base (x): ");
                if (scanf("%lf%c", &x, &check) != 2 || check != '\n') {
                    printf("Error: Invalid input!\n");
                    clearInputBuffer();
                    break;
                }
                printf("Enter exponent (n): ");
                if (scanf("%d%c", &n, &check) != 2 || check != '\n') {
                    printf("Error: Invalid input!\n");
                    clearInputBuffer();
                    break;
                }
                if (abs(n) > 30) {
                    printf("Error: Exponent too large! Maximum allowed is |30|.\n");
                    break;
                }
                printf("%.2f^%d = %.6f\n", x, n, power_xn(x, n));
                break;
                
            case 4:
                printf("Thank you for using the program!\n");
                return 0;
        }
    }
    
    return 0;
}
