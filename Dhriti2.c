/* C Program to Evaluate the Sum of a Polynomial */
#include <stdio.h>
#include <math.h>

#define MAX_DEGREE 10  // Maximum degree of polynomial allowed (Changable)

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    int n;
    double x, sum = 0.0;
    double coefficients[MAX_DEGREE + 1];
    char check;

    // Taking input for the degree of the polynomial
    printf("Enter the degree of the polynomial (0-%d): ", MAX_DEGREE);
    if (scanf("%d%c", &n, &check) != 2 || check != '\n') {
        printf("Error: Invalid input! Please enter a valid integer.\n");
        return 1;
    }

    if (n < 0) {
        printf("Error: Degree cannot be negative.\n");
        return 1;
    }

    if (n > MAX_DEGREE) {
        printf("Error: Degree cannot exceed %d.\n", MAX_DEGREE);
        return 1;
    }

    // Taking input for the coefficients
    printf("\nEnter the coefficients (from highest degree to constant term):\n");
    for (int i = 0; i <= n; i++) {
        printf("Coefficient of x^%d: ", n - i);
        if (scanf("%lf%c", &coefficients[i], &check) != 2 || check != '\n') {
            printf("Error: Invalid input! Please enter a valid number.\n");
            return 1;
        }
    }

    // Taking input for x
    printf("\nEnter the value of x: ");
    if (scanf("%lf%c", &x, &check) != 2 || check != '\n') {
        printf("Error: Invalid input! Please enter a valid number.\n");
        return 1;
    }

    // Evaluating the polynomial sum
    for (int i = 0; i <= n; i++) {
        sum += coefficients[i] * pow(x, n - i);
    }

    // Check for overflow/invalid results
    if (isinf(sum) || isnan(sum)) {
        printf("\nError: Calculation resulted in an invalid value (overflow or undefined).\n");
        return 1;
    }

    // Printing the sum
    printf("\nPolynomial evaluation at x = %.2f: %.4f\n", x, sum);

    return 0;
}
