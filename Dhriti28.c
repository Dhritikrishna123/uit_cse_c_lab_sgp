/*
Program to count alphabets and digits in a string
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 1000

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    char str[MAX_LENGTH];
    int alphabets = 0, digits = 0;
    int i;

    // Get input string
    printf("Enter a string: ");
    if (fgets(str, MAX_LENGTH, stdin) == NULL) {
        printf("Error reading input!\n");
        return 1;
    }

    // Remove trailing newline if present
    str[strcspn(str, "\n")] = '\0';

    // Count alphabets and digits
    for (i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            alphabets++;
        } else if (isdigit(str[i])) {
            digits++;
        }
    }

    // Display results
    printf("\nResults:\n");
    printf("Input string: %s\n", str);
    printf("Number of alphabets: %d\n", alphabets);
    printf("Number of digits: %d\n", digits);

    return 0;
}
