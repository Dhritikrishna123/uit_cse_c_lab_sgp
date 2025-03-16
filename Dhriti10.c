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
    long long a, b;  // Using long long for range checking
    char check;
    int valid_input = 0;
    
    do {
        printf("Enter two integers to perform bitwise operations: ");
        if(scanf("%lld %lld%c", &a, &b, &check) != 3 || check != '\n') {
            printf("Error: Invalid input! Please enter two valid integers.\n");
            clearInputBuffer();
            continue;
        }
        
        // Check for integer overflow
        if(a > INT_MAX || a < INT_MIN || b > INT_MAX || b < INT_MIN) {
            printf("Error: Numbers out of range! Please enter numbers between %d and %d\n", 
                   INT_MIN, INT_MAX);
            continue;
        }
        valid_input = 1;
    } while (!valid_input);
    
    int num1 = (int)a;  // Safe to convert now
    int num2 = (int)b;
    
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
    if(num1 >= 0) {  // Only perform left shift on non-negative numbers
        printf("%d << 1 = %d\n", num1, num1 << 1);
        printf("%d << 2 = %d\n", num1, num1 << 2);
    } else {
        printf("Left shift not performed on negative number %d\n", num1);
    }
    
    // Right Shift (>>)
    printf("\nRight Shift (>>):\n");
    printf("%d >> 1 = %d\n", num1, num1 >> 1);
    printf("%d >> 2 = %d\n", num1, num1 >> 2);
    
    return 0;
} 