/*
Program to Create and Print Fibonacci String
Example: For inputs a, b and length 5:
Fibonacci string series = a, b, ab, bab, abbab
*/
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to generate next Fibonacci string
void generateNextFibString(char *result, const char *str1, const char *str2) {
    strcpy(result, str2);
    strcat(result, str1);
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH], next[MAX_LENGTH];
    int length;
    char check;
    
    // Input first string
    printf("Enter first string: ");
    if(fgets(str1, sizeof(str1), stdin) == NULL) {
        printf("Error reading input!\n");
        return 1;
    }
    str1[strcspn(str1, "\n")] = 0;  // Remove newline
    
    // Input second string
    printf("Enter second string: ");
    if(fgets(str2, sizeof(str2), stdin) == NULL) {
        printf("Error reading input!\n");
        return 1;
    }
    str2[strcspn(str2, "\n")] = 0;  // Remove newline
    
    // Input length of series
    while(1) {
        printf("Enter length of Fibonacci series (minimum 2): ");
        if(scanf("%d%c", &length, &check) != 2 || check != '\n') {
            printf("Error: Invalid input!\n");
            clearInputBuffer();
            continue;
        }
        if(length < 2) {
            printf("Error: Length must be at least 2!\n");
            continue;
        }
        if(length > 20) {
            printf("Error: Maximum length allowed is 20 to prevent overflow!\n");
            continue;
        }
        break;
    }
    
    // Print Fibonacci string series
    printf("\nFibonacci String Series:\n");
    printf("1. %s\n", str1);
    printf("2. %s\n", str2);
    
    // Generate and print remaining terms
    for(int i = 3; i <= length; i++) {
        generateNextFibString(next, str1, str2);
        printf("%d. %s\n", i, next);
        
        // Update strings for next iteration
        strcpy(str1, str2);
        strcpy(str2, next);
    }
    
    return 0;
} 