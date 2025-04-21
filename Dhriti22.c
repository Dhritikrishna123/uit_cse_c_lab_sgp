/*
Program to Perform String Operations using Built-in Functions
1. Concatenate strings
2. Copy string
3. Compare strings
4. Reverse string
5. Convert case
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

// Function to reverse string using strrev alternative
void reverseString(char *str) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;
    
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Function to convert string to opposite case
void convertCase(char *str) {
    for(int i = 0; str[i]; i++) {
        if(isupper(str[i])) {
            str[i] = tolower(str[i]);
        } else if(islower(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];
    char result[MAX_LENGTH * 2];  // For concatenation
    int choice;
    
    while(1) {
        // Display menu
        printf("\nString Operations Menu:\n");
        printf("1. Concatenate two strings\n");
        printf("2. Copy one string into another\n");
        printf("3. Compare two strings\n");
        printf("4. Reverse string\n");
        printf("5. Convert case\n");
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
                printf("Enter first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                
                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = 0;
                
                strcpy(result, str1);
                strcat(result, str2);
                printf("Concatenated string: %s\n", result);
                break;
                
            case 2:
                printf("Enter source string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                
                strcpy(str2, str1);
                printf("Copied string: %s\n", str2);
                break;
                
            case 3:
                printf("Enter first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                
                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = 0;
                
                int cmp = strcmp(str1, str2);
                if(cmp == 0)
                    printf("Strings are equal\n");
                else if(cmp < 0)
                    printf("First string is less than second\n");
                else
                    printf("First string is greater than second\n");
                break;
                
            case 4:
                printf("Enter string to reverse: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                
                reverseString(str1);
                printf("Reversed string: %s\n", str1);
                break;
                
            case 5:
                printf("Enter string to convert case: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                
                convertCase(str1);
                printf("Converted case: %s\n", str1);
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