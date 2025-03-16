/*C program to convert a given number of seconds into days, hours, minutes, and seconds*/
#include <stdio.h>

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    int seconds, days, hours, minutes;
    char check;

    // Input from user
    printf("Enter the number of seconds: ");
    if (scanf("%d%c", &seconds, &check) != 2 || check != '\n') {
        printf("Error: Invalid input! Please enter a valid integer.\n");
        clearInputBuffer();
        return 1;
    }

    // Check for negative seconds
    if (seconds < 0) {
        printf("Error: Number of seconds cannot be negative.\n");
        return 1; 
    }

    // Store original input for display
    int originalSeconds = seconds;

    // Conversion calculations
    days = seconds / 86400;       // 1 day = 86400 seconds
    seconds %= 86400;
    
    hours = seconds / 3600;       // 1 hour = 3600 seconds
    seconds %= 3600;
    
    minutes = seconds / 60;       // 1 minute = 60 seconds
    seconds %= 60;

    // Output the result
    printf("\nConverting %d seconds:\n", originalSeconds);
    printf("= %d day(s), %d hour(s), %d minute(s), %d second(s)\n", 
           days, hours, minutes, seconds);

    return 0;
}
