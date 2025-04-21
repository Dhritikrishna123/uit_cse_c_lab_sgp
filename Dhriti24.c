/*
Program to Find Smallest Word Sequence and its Length
Without Using Built-in String Functions
*/
#include <stdio.h>

#define MAX_LENGTH 1000

// Function to check if character is a space or tab
int isSpace(char c) {
    return (c == ' ' || c == '\t');
}

// Function to find smallest word and its length
void findSmallestWord(const char *text, char *smallest, int *length) {
    int currentLength = 0;
    int minLength = MAX_LENGTH;
    int i = 0;
    int start = 0;
    int minStart = 0;
    
    // Skip leading spaces
    while(text[i] && isSpace(text[i])) {
        i++;
    }
    start = i;
    
    while(text[i]) {
        if(!isSpace(text[i])) {
            currentLength++;
        } else {
            // Found a word
            if(currentLength > 0 && currentLength < minLength) {
                minLength = currentLength;
                minStart = start;
            }
            // Skip spaces to next word
            while(text[i] && isSpace(text[i])) {
                i++;
            }
            start = i;
            currentLength = 0;
            continue;
        }
        i++;
    }
    
    // Check last word
    if(currentLength > 0 && currentLength < minLength) {
        minLength = currentLength;
        minStart = start;
    }
    
    // Copy smallest word to result
    if(minLength < MAX_LENGTH) {
        for(i = 0; i < minLength; i++) {
            smallest[i] = text[minStart + i];
        }
        smallest[minLength] = '\0';
        *length = minLength;
    } else {
        smallest[0] = '\0';
        *length = 0;
    }
}

int main() {
    char text[MAX_LENGTH];
    char smallest[MAX_LENGTH];
    int length;
    
    printf("Enter a line of text: ");
    if(fgets(text, sizeof(text), stdin) == NULL) {
        printf("Error reading input!\n");
        return 1;
    }
    
    // Remove newline if present
    int i;
    for(i = 0; text[i] && text[i] != '\n'; i++);
    text[i] = '\0';
    
    // Find smallest word
    findSmallestWord(text, smallest, &length);
    
    // Display results
    if(length > 0) {
        printf("\nInput text: %s\n", text);
        printf("Smallest word: %s\n", smallest);
        printf("Length: %d\n", length);
    } else {
        printf("No words found in the text!\n");
    }
    
    return 0;
} 