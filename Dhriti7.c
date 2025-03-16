/*
Program to Analyze a Floating Point Number (≤ 999.999)
*/
#include <stdio.h>

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to count decimal places using mathematical operations
int countDecimalPlaces(double num) {
    int count = 0;
    double fractional = num - (int)num;  // Get fractional part
    const double EPSILON = 1e-10;  // precise epsilon value
    
    while(count < 6 && fractional > EPSILON) {
        fractional *= 10;
        fractional -= (int)fractional;
        count++;
    }
    return count;
}

// Function to get leftmost digit using division
int getLeftmostDigit(int num) {
    while(num >= 10) {
        num /= 10;
    }
    return num;
}

// Function to get rightmost digit using modulo
int getRightmostDigit(int num) {
    return num % 10;
}

int main() {
    double num;
    char check;
    int valid_input = 0;
    
    do {
        printf("Enter a floating point number (up to 3 decimal places, <= 999.999): ");
        if(scanf("%lf%c", &num, &check) != 2 || check != '\n') {
            printf("Error: Invalid input! Please enter a valid number.\n");
            clearInputBuffer();
            continue;
        }
        
        if(num < 0 || num > 999.999) {
            printf("Error: Number must be between 0 and 999.999!\n");
            continue;
        }
        
        // Check decimal places
        int decimalPlaces = countDecimalPlaces(num);
        if(decimalPlaces > 3) {
            printf("Error: Number must have at most 3 decimal places!\n");
            continue;
        }
        valid_input = 1;
    } while (!valid_input);
    
    // Round to exactly 3 decimal places for consistency
    num = (double)((int)(num * 1000 + 0.5)) / 1000.0;
    
    // Split number into integer and decimal parts
    int leftPart = (int)num;  // Integer part
    int rightPart = (int)((num - leftPart) * 1000 + 0.5);  // Decimal part * 1000
    
    int leftmost = getLeftmostDigit(leftPart);
    int rightmost = getRightmostDigit(rightPart);
    
    printf("\nLeft-most digit: %d", leftmost);
    printf("\nRight-most digit: %d", rightmost);
    
    // Get last three digits of left part for fair comparison
    int leftThreeDigits = leftPart % 1000;
    
    printf("\n\nLeft three digits: %d", leftThreeDigits);
    printf("\nRight three digits: %d", rightPart);
    
    if (leftThreeDigits > rightPart) {
        printf("\nLeft side three digits are bigger by %d", leftThreeDigits - rightPart);
    } else if (rightPart > leftThreeDigits) {
        printf("\nRight side three digits are bigger by %d", rightPart - leftThreeDigits);
    } else {
        printf("\nBoth sides are equal");
    }
    printf("\n");
    
    return 0;
} 