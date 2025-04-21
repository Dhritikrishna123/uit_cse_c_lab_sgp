/*
Program to Check if a Word is Palindrome
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Function to check if string is palindrome
int isPalindrome(const char *str) {
    int start = 0;
    int end = strlen(str) - 1;
    
    while (start < end) {
        // Skip non-alphanumeric characters from start
        while (start < end && !isalnum(str[start])) {
            start++;
        }
        
        // Skip non-alphanumeric characters from end
        while (start < end && !isalnum(str[end])) {
            end--;
        }
        
        // Compare characters (case insensitive)
        if (tolower(str[start]) != tolower(str[end])) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

int main() {
    char word[MAX_LENGTH];
    char check;
    
    while(1) {
        printf("Enter a word to check if it is a palindrome or not (or 'exit' to quit): ");
        if(fgets(word, sizeof(word), stdin) == NULL) {
            printf("Error reading input!\n");
            continue;
        }
        
        // Remove newline if present
        word[strcspn(word, "\n")] = 0;
        
        // Check for exit
        if(strcmp(word, "exit") == 0) {
            printf("Program terminated.\n");
            break;
        }
        
        // Check if string is empty
        if(strlen(word) == 0) {
            printf("Please enter a word!\n");
            continue;
        }
        
        // Check if palindrome
        if(isPalindrome(word)) {
            printf("\"%s\" is a palindrome!\n", word);
        } else {
            printf("\"%s\" is not a palindrome.\n", word);
        }
        
        printf("\n");
    }
    
    return 0;
} 