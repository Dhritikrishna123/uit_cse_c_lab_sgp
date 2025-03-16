/*
Program to input a decimal number and display the smallest integer not less than 
the number and the largest integer not greater than the number
*/
#include <stdio.h>
#include <limits.h>

int main() {
    double num;
    char check;
    
    printf("Enter a decimal number: ");
    if(scanf("%lf%c", &num, &check) != 2 || check != '\n') {
        printf("Error: Invalid input! Please enter a valid decimal number.\n");
        return 1;
    }
    
    // Check for overflow
    if(num > INT_MAX || num < INT_MIN) {
        printf("Error: Number out of integer range! Please enter a number between %d and %d\n", 
               INT_MIN, INT_MAX);
        return 1;
    }
    
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