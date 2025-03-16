/*
Program to Convert Temperature between Celsius and Fahrenheit
*/
#include <stdio.h>

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    float temp, convertedTemp;
    int choice;
    char check;
    int valid_input = 0;

    do {
        printf("\nTemperature Conversion:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("Enter choice (1 or 2): ");
        
        if (scanf("%d%c", &choice, &check) != 2 || check != '\n') {
            printf("Error: Invalid input! Please enter a number (1 or 2).\n");
            clearInputBuffer();
            continue;
        }

        if (choice != 1 && choice != 2) {
            printf("Error: Invalid choice! Please enter either 1 or 2.\n");
            continue;
        }

        valid_input = 1;
    } while (!valid_input);

    valid_input = 0;
    do {
        if (choice == 1) {
            printf("\nEnter temperature in Celsius: ");
            if (scanf("%f%c", &temp, &check) != 2 || check != '\n') {
                printf("Error: Invalid input! Please enter a valid number.\n");
                clearInputBuffer();
                continue;
            }
            
            if (temp < -273.15) {
                printf("Error: Temperature cannot be below absolute zero (-273.15°C)!\n");
                continue;
            }
            
            convertedTemp = (temp * 9.0 / 5.0) + 32.0;
            printf("\nResult: %.2f°C = %.2f°F\n", temp, convertedTemp);
        } else {
            printf("\nEnter temperature in Fahrenheit: ");
            if (scanf("%f%c", &temp, &check) != 2 || check != '\n') {
                printf("Error: Invalid input! Please enter a valid number.\n");
                clearInputBuffer();
                continue;
            }
            
            if (temp < -459.67) {
                printf("Error: Temperature cannot be below absolute zero (-459.67°F)!\n");
                continue;
            }
            
            convertedTemp = (temp - 32.0) * 5.0 / 9.0;
            printf("\nResult: %.2f°F = %.2f°C\n", temp, convertedTemp);
        }
        valid_input = 1;
    } while (!valid_input);

    return 0;
}
