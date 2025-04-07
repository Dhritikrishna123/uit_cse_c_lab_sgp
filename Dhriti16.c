/*
Program to Convert Between Number Systems
Features: Binary to Decimal, Octal to Binary conversions
*/
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_DIGITS 32

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to validate binary number
int isValidBinary(const char *num) {
    for(int i = 0; num[i] != '\0'; i++) {
        if(num[i] != '0' && num[i] != '1') {
            return 0;
        }
    }
    return 1;
}

// Function to validate octal number
int isValidOctal(const char *num) {
    for(int i = 0; num[i] != '\0'; i++) {
        if(num[i] < '0' || num[i] > '7') {
            return 0;
        }
    }
    return 1;
}

// Function to convert binary to decimal
long long binaryToDecimal(const char *binary) {
    long long decimal = 0;
    int length = strlen(binary);
    
    for(int i = 0; i < length; i++) {
        if(binary[i] == '1') {
            decimal += pow(2, length - 1 - i);
        }
    }
    return decimal;
}

// Function to convert octal to binary
void octalToBinary(const char *octal, char *binary) {
    // Mapping of octal digits to their binary representation
    const char *octalBinary[] = {"000", "001", "010", "011", 
                                "100", "101", "110", "111"};
    
    binary[0] = '\0';  // Initialize binary string
    
    // Convert each octal digit to its binary equivalent
    for(int i = 0; octal[i] != '\0'; i++) {
        strcat(binary, octalBinary[octal[i] - '0']);
    }
    
    // Remove leading zeros
    int start = 0;
    while(binary[start] == '0' && binary[start + 1] != '\0') {
        start++;
    }
    
    if(start > 0) {
        int j = 0;
        for(int i = start; binary[i] != '\0'; i++) {
            binary[j++] = binary[i];
        }
        binary[j] = '\0';
    }
}

int main() {
    char input[MAX_DIGITS + 1];
    char binary[MAX_DIGITS * 3 + 1];  // For octal to binary conversion
    int choice;
    char check;
    
    while(1) {
        printf("\nNumber System Conversion Menu:\n");
        printf("1. Binary to Decimal\n");
        printf("2. Octal to Binary\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        
        if(scanf("%d%c", &choice, &check) != 2 || check != '\n') {
            printf("Error: Invalid input!\n");
            clearInputBuffer();
            continue;
        }
        
        if(choice == 3) {
            printf("Program terminated.\n");
            break;
        }
        
        if(choice != 1 && choice != 2) {
            printf("Error: Please enter 1, 2, or 3.\n");
            continue;
        }
        
        // Get the input number
        printf("Enter %s number: ", (choice == 1) ? "binary" : "octal");
        scanf("%s", input);
        clearInputBuffer();
        
        if(strlen(input) > MAX_DIGITS) {
            printf("Error: Input too long! Maximum %d digits allowed.\n", MAX_DIGITS);
            continue;
        }
        
        if(choice == 1) {  // Binary to Decimal
            if(!isValidBinary(input)) {
                printf("Error: Invalid binary number! Use only 0s and 1s.\n");
                continue;
            }
            
            long long decimal = binaryToDecimal(input);
            printf("Decimal equivalent: %lld\n", decimal);
            
        } else {  // Octal to Binary
            if(!isValidOctal(input)) {
                printf("Error: Invalid octal number! Use digits 0-7 only.\n");
                continue;
            }
            
            octalToBinary(input, binary);
            printf("Binary equivalent: %s\n", binary);
        }
    }
    
    return 0;
} 