/*
Program to Evaluate Sine Series and Compare with math.h
Series: sin(x) = x - x³/3! + x⁵/5! - x⁷/7! + ... + (-1)ⁿx^(2n+1)/(2n+1)!
*/
#include <stdio.h>
#include <math.h>

// Define PI 
#define PI 3.14159265358979323846

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to calculate power
double calculatePower(double base, int exponent) {
    double result = 1.0;
    for(int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

// Function to calculate factorial
double calculateFactorial(int n) {
    if(n == 0 || n == 1) return 1;
    double result = 1.0;
    for(int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate sine using series
double calculateSineSeries(double x, int terms) {
    double result = 0.0;
    
    // Convert x to radians if given in degrees
    double xRad = x * PI / 180.0;
    
    // Calculate series sum
    for(int n = 0; n < terms; n++) {
        int exponent = 2 * n + 1;
        double term = calculatePower(-1, n) * calculatePower(xRad, exponent) / calculateFactorial(exponent);
        result += term;
    }
    
    return result;
}

int main() {
    double angle;
    int terms;
    char check;
    
    // Input angle in degrees
    while(1) {
        printf("Enter angle in degrees: ");
        if(scanf("%lf%c", &angle, &check) != 2 || check != '\n') {
            printf("Error: Please enter a valid number.\n");
            clearInputBuffer();
            continue;
        }
        break;
    }
    
    // Input number of terms
    while(1) {
        printf("Enter number of terms (1-10): ");
        if(scanf("%d%c", &terms, &check) != 2 || check != '\n' || terms < 1 || terms > 10) {
            printf("Error: Please enter a number between 1 and 10.\n");
            clearInputBuffer();
            continue;
        }
        break;
    }
    
    // Calculate using series
    double seriesResult = calculateSineSeries(angle, terms);
    
    // Calculate using math.h
    double mathResult = sin(angle * PI / 180.0);
    
    // Display results
    printf("\nResults for sin(%.2f°):\n", angle);
    printf("Using series (%d terms): %.6f\n", terms, seriesResult);
    printf("Using math.h: %.6f\n", mathResult);
    printf("Difference: %.6f\n", fabs(seriesResult - mathResult));
    
    // Display series expansion
    printf("\nSeries Expansion:\n");
    printf("sin(x) = ");
    for(int n = 0; n < terms; n++) {
        int exponent = 2 * n + 1;
        if(n == 0) {
            printf("x");
        } else {
            printf("%s(x^%d/%d!)", (n % 2 == 0) ? "+ " : "- ", exponent, exponent);
        }
    }
    printf("\n");
    
    return 0;
} 