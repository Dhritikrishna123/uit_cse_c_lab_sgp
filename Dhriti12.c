/*
Program to Analyze Input String/Number
Features: Count digits/characters, Count zeros/vowels, 
Reverse string, Check palindrome
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 100

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to count digits/characters
int countCharacters(const char *str) {
    return strlen(str);
}

// Function to count zeros and vowels
void countZerosAndVowels(const char *str, int *zeros, int *vowels) {
    *zeros = 0;
    *vowels = 0;
    
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == '0') {
            (*zeros)++;
        }
        char ch = tolower(str[i]);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            (*vowels)++;
        }
    }
}

// Function to reverse string
void reverseString(const char *input, char *reversed) {
    int length = strlen(input);
    for(int i = 0; i < length; i++) {
        reversed[i] = input[length - 1 - i];
    }
    reversed[length] = '\0';
}

// Function to check palindrome
bool isPalindrome(const char *str) {
    int left = 0;
    int right = strlen(str) - 1;
    
    while(left < right) {
        // Skip non-alphanumeric characters from left
        while(left < right && !isalnum(str[left])) {
            left++;
        }
        // Skip non-alphanumeric characters from right
        while(left < right && !isalnum(str[right])) {
            right--;
        }
        
        if(tolower(str[left]) != tolower(str[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    char input[MAX_LENGTH];
    char reversed[MAX_LENGTH];
    int valid_input = 0;
    
    printf("Enter a string or number (max %d characters): ", MAX_LENGTH - 1);
    
    // Input validation
    if(fgets(input, MAX_LENGTH, stdin) == NULL) {
        printf("Error: Failed to read input.\n");
        return 1;
    }
    
    // Remove trailing newline if present
    size_t len = strlen(input);
    if(len > 0 && input[len-1] == '\n') {
        input[len-1] = '\0';
        len--;
    }
    
    // Check if input is empty
    if(len == 0) {
        printf("Error: Empty input is not allowed.\n");
        return 1;
    }
    
    // Check if input is too long
    if(len == MAX_LENGTH - 1 && input[len-1] != '\n') {
        printf("Error: Input too long. Maximum %d characters allowed.\n", MAX_LENGTH - 1);
        clearInputBuffer();
        return 1;
    }
    
    // 1. Count characters
    int charCount = countCharacters(input);
    printf("\n1. Number of characters: %d\n", charCount);
    
    // 2. Count zeros and vowels
    int zeros, vowels;
    countZerosAndVowels(input, &zeros, &vowels);
    printf("2. Number of zeros: %d\n", zeros);
    printf("   Number of vowels: %d\n", vowels);
    
    // 3. Reverse the string
    reverseString(input, reversed);
    printf("3. Reversed string: %s\n", reversed);
    
    // 4. Check palindrome
    printf("4. Is palindrome: %s\n", isPalindrome(input) ? "Yes" : "No");
    
    return 0;
} 