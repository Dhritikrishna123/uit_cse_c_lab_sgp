/*
Program to input a five digit number and print its sum of digits as well as
product of digits
*/
#include <stdio.h>

int main() {
    long num, temp;  // Using long to check range
    int sum = 0, product = 1;
    char check;
    
    printf("Enter a five digit number: ");
    if(scanf("%ld%c", &num, &check) != 2 || check != '\n') {
        printf("Error: Invalid input! Please enter a valid number.\n");
        return 1;
    }
    
    // Validate five digits and positive number
    if(num < 10000 || num > 99999) {
        printf("Error: Please enter exactly five digits (10000 to 99999)!\n");
        return 1;
    }
    
    // Store original number
    temp = num;
    
    // Calculate sum and product of digits
    while(temp > 0) {
        int digit = temp % 10;
        sum += digit;
        product *= digit;
        temp /= 10;
    }
    
    printf("Sum of digits of %ld is: %d\n", num, sum);
    printf("Product of digits of %ld is: %d\n", num, product);
    
    return 0;
} 