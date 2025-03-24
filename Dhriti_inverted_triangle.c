/*
Program to Print Inverted Triangle Patterns
*/
#include <stdio.h>

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Pattern A: Simple Inverted Triangle
void printInvertedStarTriangle(int n) {
    for(int i = n; i >= 1; i--) {
        // Print spaces
        for(int j = 1; j <= n-i; j++) {
            printf(" ");
        }
        // Print stars
        for(int j = 1; j <= 2*i-1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Pattern B: Inverted Number Triangle
void printInvertedNumberTriangle(int n) {
    for(int i = n; i >= 1; i--) {
        // Print spaces
        for(int j = 1; j <= n-i; j++) {
            printf(" ");
        }
        // Print numbers
        for(int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        for(int j = i-1; j >= 1; j--) {
            printf("%d", j);
        }
        printf("\n");
    }
}

// Pattern C: Hollow Inverted Triangle
void printHollowInvertedTriangle(int n) {
    for(int i = n; i >= 1; i--) {
        // Print spaces
        for(int j = 1; j <= n-i; j++) {
            printf(" ");
        }
        // Print stars (only at borders)
        for(int j = 1; j <= 2*i-1; j++) {
            if(j == 1 || j == 2*i-1 || i == n) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Pattern D: Inverted Alphabet Triangle
void printInvertedAlphabetTriangle(int n) {
    for(int i = n; i >= 1; i--) {
        // Print spaces
        for(int j = 1; j <= n-i; j++) {
            printf(" ");
        }
        // Print alphabets
        char ch = 'A';
        for(int j = 1; j <= i; j++) {
            printf("%c", ch++);
        }
        ch -= 2;
        for(int j = 1; j < i; j++) {
            printf("%c", ch--);
        }
        printf("\n");
    }
}

int main() {
    int choice, n;
    char check;
    
    do {
        printf("\nInverted Triangle Pattern Menu:\n");
        printf("1. Star Inverted Triangle\n");
        printf("2. Number Inverted Triangle\n");
        printf("3. Hollow Inverted Triangle\n");
        printf("4. Alphabet Inverted Triangle\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        
        if(scanf("%d%c", &choice, &check) != 2 || check != '\n' || choice < 1 || choice > 5) {
            printf("Invalid input! Please enter a number between 1 and 5.\n");
            clearInputBuffer();
            continue;
        }
        
        if(choice == 5) {
            printf("Thank you for using the pattern printer!\n");
            break;
        }
        
        printf("Enter the height of the triangle (1-15): ");
        if(scanf("%d%c", &n, &check) != 2 || check != '\n' || n < 1 || n > 15) {
            printf("Invalid input! Please enter a number between 1 and 15.\n");
            clearInputBuffer();
            continue;
        }
        
        printf("\nOutput Pattern:\n");
        switch(choice) {
            case 1:
                printInvertedStarTriangle(n);
                break;
            case 2:
                printInvertedNumberTriangle(n);
                break;
            case 3:
                printHollowInvertedTriangle(n);
                break;
            case 4:
                printInvertedAlphabetTriangle(n);
                break;
        }
        
    } while(1);
    
    return 0;
} 