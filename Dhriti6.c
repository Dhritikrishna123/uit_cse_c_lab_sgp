/*
Program to Calculate Floor and Ceiling Values
*/
#include <stdio.h>
#include <float.h>
#include <math.h>

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Implementation without math.h
double customFloor(double num) {
    int intPart = (int)num;
    if (num < 0 && num != intPart) {
        return intPart - 1;
    }
    return intPart;
}

double customCeil(double num) {
    int intPart = (int)num;
    if (num > 0 && num != intPart) {
        return intPart + 1;
    }
    return intPart;
}

int main() {
    double num;
    char check;
    int valid_input = 0;
    
    do {
        printf("Enter a decimal number: ");
        if(scanf("%lf%c", &num, &check) != 2 || check != '\n') {
            printf("Error: Invalid input! Please enter a valid decimal number.\n");
            clearInputBuffer();
            continue;
        }
        
        // Check for overflow using float limits
        if(num > FLT_MAX || num < -FLT_MAX) {
            printf("Error: Number out of range! Please enter a number between %.2e and %.2e\n",
                   -FLT_MAX, FLT_MAX);
            continue;
        }
        valid_input = 1;
    } while (!valid_input);
    
    printf("\nUsing math.h functions:\n");
    printf("Number: %.2f\n", num);
    printf("Floor value: %.0f\n", floor(num));
    printf("Ceiling value: %.0f\n", ceil(num));
    
    printf("\nUsing custom functions:\n");
    printf("Number: %.2f\n", num);
    printf("Floor value: %.0f\n", customFloor(num));
    printf("Ceiling value: %.0f\n", customCeil(num));
    
    return 0;
} 