/*
Program to Find Floor and Ceiling of a Decimal Number
*/
#include <stdio.h>
#include <limits.h>

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
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
        
        // Check for overflow
        if(num > INT_MAX || num < INT_MIN) {
            printf("Error: Number out of integer range! Please enter a number between %d and %d\n", 
                   INT_MIN, INT_MAX);
            continue;
        }
        valid_input = 1;
    } while (!valid_input);
    
    int smallest = (int)num;
    if (num > 0 && num != (int)num) {
        smallest += 1;
    }
    
    int largest = (int)num;
    if (num < 0 && num != (int)num) {
        largest -= 1;
    }
    
    printf("Smallest integer not less than %.2lf is: %d\n", num, smallest);
    printf("Largest integer not greater than %.2lf is: %d\n", num, largest);
    
    return 0;
} 