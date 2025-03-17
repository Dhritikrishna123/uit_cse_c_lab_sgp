/*
Program to read an integer and check whether it is prime, even/odd and
positive/negative/zero
*/
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool isPrime(int n) {
    // Handle special cases
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    // Check for factors from 3 to sqrt(n)
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    long long num;  // Using long long for maximum range
    char check;
    
    printf("Enter an integer: ");
    if(scanf("%lld%c", &num, &check) != 2 || check != '\n') {
        printf("Error: Invalid input! Please enter a valid integer.\n");
        return 1;
    }
    
    // Check for integer overflow
    if(num > INT_MAX || num < INT_MIN) {
        printf("Error: Number out of range! Please enter a number between %d and %d\n", 
               INT_MIN, INT_MAX);
        return 1;
    }
    
    int n = (int)num;  // Safe to convert now
    
    // Check if prime
    if (isPrime(n)) {
        printf("%d is a prime number\n", n);
    } else {
        printf("%d is not a prime number\n", n);
    }
    
    // Check if even/odd
    if (n % 2 == 0) {
        printf("%d is even\n", n);
    } else {
        printf("%d is odd\n", n);
    }
    
    // Check if positive/negative/zero
    if (n > 0) {
        printf("%d is positive\n", n);
    } else if (n < 0) {
        printf("%d is negative\n", n);
    } else {
        printf("The number is zero\n");
    }
    
    return 0;
} 