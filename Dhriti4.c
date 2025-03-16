/*C Program to Swap Two Variables Using Different Methods*/
#include <stdio.h>
#include <limits.h>

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    int a, b, choice;
    char check;

    // Taking input from the user
    printf("Enter two numbers: ");
    if (scanf("%d %d%c", &a, &b, &check) != 3 || check != '\n') {
        printf("Error: Invalid input! Please enter two valid integers.\n");
        return 1;
    }

    // Displaying the menu
    printf("\nChoose the swapping method:\n");
    printf("1. Using Arithmetic Operators\n");
    printf("2. Using a Third Variable\n");
    printf("3. Using Bitwise XOR\n");
    printf("Enter your choice (1-3): ");
    
    if (scanf("%d%c", &choice, &check) != 2 || check != '\n') {
        printf("Error: Invalid input! Please enter a number between 1 and 3.\n");
        return 1;
    }

    // Check for arithmetic overflow in method 1
    if (choice == 1) {
        // Check if addition might overflow
        if ((a > 0 && b > INT_MAX - a) || (a < 0 && b < INT_MIN - a)) {
            printf("Error: Numbers too large for arithmetic method. Please use another method.\n");
            return 1;
        }
    }

    // Swapping based on user choice
    switch (choice) {
        case 1: // Arithmetic Operators
            a = a + b;
            b = a - b;
            a = a - b;
            printf("\nSwapped using Arithmetic Operators:\n");
            break;

        case 2: // Using Third Variable
        {
            int temp = a;
            a = b;
            b = temp;
            printf("\nSwapped using a Third Variable:\n");
            break;
        }

        case 3: // Using Bitwise XOR
            a = a ^ b;
            b = a ^ b;
            a = a ^ b;
            printf("\nSwapped using Bitwise XOR:\n");
            break;

        default:
            printf("Error: Invalid choice! Please enter a number between 1 and 3.\n");
            return 1;
    }

    // Displaying swapped values
    printf("After swapping: a = %d, b = %d\n", a, b);
    return 0;
}
