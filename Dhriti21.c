/*
Program to Perform Various String Operations
1. Count word occurrence
2. Count character occurrence
3. Extract substring
4. Delete vowels
5. Find digit positions
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

// Function to count word occurrence
int countWord(const char *text, const char *word) {
    int count = 0;
    const char *temp = text;
    
    while ((temp = strstr(temp, word)) != NULL) {
        // Check if it's a complete word
        if ((temp == text || !isalpha(*(temp-1))) && 
            (!isalpha(*(temp + strlen(word))) || *(temp + strlen(word)) == '\0')) {
            count++;
        }
        temp++;
    }
    return count;
}

// Function to count character occurrence
int countChar(const char *text, char ch) {
    int count = 0;
    for(int i = 0; text[i]; i++) {
        if(text[i] == ch) count++;
    }
    return count;
}

// Function to extract substring
void extractSubstring(const char *text, char *result, int start, int length) {
    strncpy(result, text + start, length);
    result[length] = '\0';
}

// Function to delete vowels
void deleteVowels(char *text) {
    int i, j;
    for(i = 0, j = 0; text[i]; i++) {
        if(!strchr("aeiouAEIOU", text[i])) {
            text[j] = text[i];
            j++;
        }
    }
    text[j] = '\0';
}

// Function to find digit positions
void findDigitPositions(const char *text) {
    int found = 0;
    printf("Digit positions: ");
    for(int i = 0; text[i]; i++) {
        if(isdigit(text[i])) {
            printf("%d ", i);
            found = 1;
        }
    }
    if(!found) printf("No digits found");
    printf("\n");
}

int main() {
    char text[MAX_LENGTH];
    char word[100];
    char result[MAX_LENGTH];
    char ch;
    int choice, start, length;
    
    // Input text
    printf("Enter a line of text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;  // Remove newline
    
    while(1) {
        // Display menu
        printf("\nString Operations Menu:\n");
        printf("1. Count word occurrence\n");
        printf("2. Count character occurrence\n");
        printf("3. Extract substring\n");
        printf("4. Delete vowels\n");
        printf("5. Find digit positions\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        
        if(scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();
        
        switch(choice) {
            case 1:
                printf("Enter word to count: ");
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = 0;
                printf("Occurrences of '%s': %d\n", word, countWord(text, word));
                break;
                
            case 2:
                printf("Enter character to count: ");
                scanf("%c", &ch);
                clearInputBuffer();
                printf("Occurrences of '%c': %d\n", ch, countChar(text, ch));
                break;
                
            case 3:
                printf("Enter start position: ");
                scanf("%d", &start);
                printf("Enter length: ");
                scanf("%d", &length);
                clearInputBuffer();
                if(start < 0 || start >= strlen(text) || length < 0) {
                    printf("Invalid position or length!\n");
                    break;
                }
                extractSubstring(text, result, start, length);
                printf("Extracted substring: %s\n", result);
                break;
                
            case 4:
                strcpy(result, text);
                deleteVowels(result);
                printf("Text without vowels: %s\n", result);
                break;
                
            case 5:
                findDigitPositions(text);
                break;
                
            case 6:
                printf("Program terminated.\n");
                return 0;
                
            default:
                printf("Invalid choice! Please enter 1-6.\n");
        }
    }
    
    return 0;
} 