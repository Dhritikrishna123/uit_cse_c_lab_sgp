/*
Program to Demonstrate Bitwise Operations
*/
#include <stdio.h>
#include <limits.h>

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int num1, num2;  // Changed to int directly
    char check;
    int valid_input = 0;
    
    do {
        printf("Enter two integers to perform bitwise operations: ");
        if(scanf("%d %d%c", &num1, &num2, &check) != 3 || check != '\n') {
            printf("Error: Invalid input! Please enter two valid integers.\n");
            clearInputBuffer();
            continue;
        }
        
        // Check for integer overflow
        if(num1 > INT_MAX || num1 < INT_MIN || num2 > INT_MAX || num2 < INT_MIN) {
            printf("Error: Numbers out of range! Please enter numbers between %d and %d\n", 
                   INT_MIN, INT_MAX);
            clearInputBuffer();
            continue;
        }
        valid_input = 1;
    } while (!valid_input);
    
    printf("\nBitwise Operations Results:\n");
    printf("----------------------------\n");
    
    // Bitwise AND (&)
    printf("Bitwise AND (&):\n");
    printf("%d & %d = %d\n", num1, num2, num1 & num2);
    
    // Bitwise OR (|)
    printf("\nBitwise OR (|):\n");
    printf("%d | %d = %d\n", num1, num2, num1 | num2);
    
    // Bitwise XOR (^)
    printf("\nBitwise XOR (^):\n");
    printf("%d ^ %d = %d\n", num1, num2, num1 ^ num2);
    
    // Bitwise NOT (~)
    printf("\nBitwise NOT (~):\n");
    printf("~%d = %d\n", num1, ~num1);
    printf("~%d = %d\n", num2, ~num2);
    
    // Left Shift (<<)
    printf("\nLeft Shift (<<):\n");
    printf("%d << 1 = %d\n", num1, num1 << 1);
    printf("%d << 2 = %d\n", num1, num1 << 2);
    
    // Right Shift (>>)
    printf("\nRight Shift (>>):\n");
    printf("%d >> 1 = %d\n", num1, num1 >> 1);
    printf("%d >> 2 = %d\n", num1, num1 >> 2);
    
    return 0;
} 