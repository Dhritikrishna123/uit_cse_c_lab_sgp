/*
Program to Calculate Sum and Product of a Five-Digit Number
*/
#include <stdio.h>

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    long num, temp;  // Using long to check range
    int sum = 0, product = 1;
    char check;
    int valid_input = 0;
    
    do {
        printf("Enter a five digit number: ");
        if(scanf("%ld%c", &num, &check) != 2 || check != '\n') {
            printf("Error: Invalid input! Please enter a valid number.\n");
            clearInputBuffer();
            continue;
        }
        
        // Validate five digits and positive number
        if(num < 10000 || num > 99999) {
            printf("Error: Please enter exactly five digits (10000 to 99999)!\n");
            continue;
        }
        valid_input = 1;
    } while (!valid_input);
    
    // Store original number
    temp = num;
    
    // Calculate sum and product of digits
    while(temp > 0) {
        int digit = temp % 10;
        sum += digit;
        product *= digit;
        temp /= 10;
    }
    
    printf("\nFor the number %ld:\n", num);
    printf("Sum of digits: %d\n", sum);
    printf("Product of digits: %d\n", product);
    
    return 0;
} 