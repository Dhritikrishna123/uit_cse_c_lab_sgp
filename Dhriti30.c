/*
Program to encrypt a string by interchanging characters and digits at odd indices
Uses '%' as padding character when needed
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to encrypt string and array
void encrypt(char *str, int *arr, int arr_size) {
    int str_len = strlen(str);
    int i;
    
    printf("\nOriginal string: %s\n", str);
    printf("Original array: [");
    for (i = 0; i < arr_size; i++) {
        printf("%d", arr[i]);
        if (i < arr_size - 1) printf(" , ");
    }
    printf("]\n");
    
    // Process odd indices
    for (i = 1; i < str_len || i < arr_size; i += 2) {
        // If we have both string character and array element
        if (i < str_len && i < arr_size) {
            // Convert array element to character and swap
            str[i] = arr[i] + '0';
        }
        // If we only have string character
        else if (i < str_len) {
            str[i] = '%';
        }
    }
    
    printf("\nEncrypted string: %s\n", str);
    
}

int main() {
    char str[MAX_LENGTH];
    int arr[MAX_LENGTH];
    int arr_size = 0;
    char digit;
    
    // Get string input
    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input!\n");
        return 1;
    }
    str[strcspn(str, "\n")] = '\0';  // Remove newline
    
    // Get array input
    printf("Enter array elements (single digits separated by spaces): ");
    while (arr_size < MAX_LENGTH) {
        digit = getchar();
        
        // Break on newline
        if (digit == '\n') {
            break;
        }
        
        // Skip spaces
        if (isspace(digit)) {
            continue;
        }
        
        // Validate digit
        if (!isdigit(digit)) {
            printf("Error: Invalid input! Please enter only single digits separated by spaces.\n");
            return 1;
        }
        
        arr[arr_size++] = digit - '0';
    }
    
    // Validate inputs
    if (strlen(str) == 0) {
        printf("Error: String cannot be empty!\n");
        return 1;
    }
    
    if (arr_size == 0) {
        printf("Error: Array cannot be empty!\n");
        return 1;
    }
    
    // Perform encryption
    encrypt(str, arr, arr_size);
    
    return 0;
} 