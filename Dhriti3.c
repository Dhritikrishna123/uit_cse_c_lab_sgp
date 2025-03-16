/*C Program to Print ASCII Codes for Different Characters*/
#include <stdio.h>

int main(void) {
    char ch;

    printf("=============================================\n");
    printf("      ASCII VALUES OF DIFFERENT CHARACTERS   \n");
    printf("=============================================\n\n");

    // Printing ASCII codes for uppercase alphabets
    printf(" ASCII values for **Uppercase Alphabets**:\n");
    printf("---------------------------------------------\n");
    for (ch = 'A'; ch <= 'Z'; ch++) {
        printf("%c: %3d  ", ch, ch);
        if ((ch - 'A' + 1) % 6 == 0) printf("\n");  // Break line every 6 characters
    }
    printf("\n\n");

    // Printing ASCII codes for lowercase alphabets
    printf(" ASCII values for **Lowercase Alphabets**:\n");
    printf("---------------------------------------------\n");
    for (ch = 'a'; ch <= 'z'; ch++) {
        printf("%c: %3d  ", ch, ch);
        if ((ch - 'a' + 1) % 6 == 0) printf("\n");
    }
    printf("\n\n");

    // Printing ASCII codes for digits (0-9)
    printf(" ASCII values for **Numbers (0-9)**:\n");
    printf("---------------------------------------------\n");
    for (ch = '0'; ch <= '9'; ch++) {
        printf("%c: %3d  ", ch, ch);
    }
    printf("\n\n");

    // Printing ASCII codes for special characters
    printf(" ASCII values for **Special Characters**:\n");
    printf("---------------------------------------------\n");
    char specialChars[] = {'\n', '\b', ' ', ';', ',', '.', '-', '+', '/', '*', '%', '&', '>', '<', '='};
    char* specialNames[] = {"(New Line)", "(Backspace)", "(Space)", ";", ",", ".", "-", "+", "/", "*", "%", "&", ">", "<", "="};

    int size = sizeof(specialChars) / sizeof(specialChars[0]);

    for (int i = 0; i < size; i++) {
        printf("%-12s: %3d  ", specialNames[i], specialChars[i]);
        if ((i + 1) % 3 == 0) printf("\n");  // Break line every 3 special characters
    }
    printf("\n");

    printf("\n=============================================\n");
    printf("            PROGRAM EXECUTION ENDED          \n");
    printf("=============================================\n");

    return 0;
}
