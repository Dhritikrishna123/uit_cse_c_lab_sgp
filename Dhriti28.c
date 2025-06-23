/*
Program to count alphabets and digits using character by character input
*/
#include <stdio.h>
#include <ctype.h>
#include <conio.h>  // for getch()

// Function to take input character by character and count alphabets and digits
void repeat(int *alphabets, int *digits) {
    char ch;
    *alphabets = 0;
    *digits = 0;
    
    printf("Enter characters (press Enter or Backspace to stop):\n");
    
    while (1) {
        ch = getch();  // Use getch() to read character without echo
        
        // Check for Enter key (13) or Backspace key (8)
        if (ch == 13 || ch == 8) {
            break;
        }
        
        // Echo the character to screen
        putchar(ch);
        
        if (isalpha(ch)) {
            (*alphabets)++;
        } else if (isdigit(ch)) {
            (*digits)++;
        }
    }
    printf("\n");  // New line after input is complete
}

int main() {
    int alphabets, digits;
    
    // Call repeat function to get counts
    repeat(&alphabets, &digits);
    
    // Display results
    printf("\nResults:\n");
    printf("Number of alphabets: %d\n", alphabets);
    printf("Number of digits: %d\n", digits);
    
    return 0;
}
