/*
Program to Print Various Patterns
*/
#include <stdio.h>

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Pattern A: Star Pattern
void printPatternA(int n) {
    for(int i = 1; i <= n; i++) {
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

// Pattern B: Number Triangle
void printPatternB(int n) {
    int num = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            printf("%d ", num++);
        }
        printf("\n");
    }
}

// Pattern C: Binary Pattern
void printPatternC(int n) {
    for(int i = 1; i <= n; i++) {
        if(i == 1) {
            printf("1\n");
            continue;
        }
        for(int j = 1; j <= i; j++) {
            printf("%d ", (i+j)%2);
        }
        printf("\n");
    }
}

// Pattern D: Pascal's Triangle
void printPatternD(int n) {
    for(int line = 0; line < n; line++) {
        // Print spaces
        for(int i = 0; i < n-line-1; i++) {
            printf("  ");
        }
        
        int num = 1;
        for(int i = 0; i <= line; i++) {
            printf("%4d", num);
            num = num * (line - i) / (i + 1);
        }
        printf("\n");
    }
}

// Pattern E: Number Pattern
void printPatternE(int n) {
    for(int i = 1; i <= n; i++) {
        // Print spaces
        for(int j = 1; j <= n-i; j++) {
            printf("  ");
        }
        // Print increasing numbers
        for(int j = i; j <= 2*i-1; j++) {
            printf("%d ", j);
        }
        // Print decreasing numbers
        for(int j = 2*i-2; j >= i; j--) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

int main() {
    int choice, n;
    char check;
    
    do {
        printf("\nPattern Menu:\n");
        printf("1. Star Pattern\n");
        printf("2. Number Triangle\n");
        printf("3. Binary Pattern\n");
        printf("4. Pascal's Triangle\n");
        printf("5. Number Pattern\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        
        if(scanf("%d%c", &choice, &check) != 2 || check != '\n' || choice < 1 || choice > 6) {
            printf("Invalid input! Please enter a number between 1 and 6.\n");
            clearInputBuffer();
            continue;
        }
        
        if(choice == 6) {
            printf("Thank you for using the pattern printer!\n");
            break;
        }
        
        printf("Enter the number of rows (1-20): ");
        if(scanf("%d%c", &n, &check) != 2 || check != '\n' || n < 1 || n > 20) {
            printf("Invalid input! Please enter a number between 1 and 20.\n");
            clearInputBuffer();
            continue;
        }
        
        printf("\nOutput Pattern:\n");
        switch(choice) {
            case 1:
                printPatternA(n);
                break;
            case 2:
                printPatternB(n);
                break;
            case 3:
                printPatternC(n);
                break;
            case 4:
                printPatternD(n);
                break;
            case 5:
                printPatternE(n);
                break;
        }
        
    } while(1);
    
    return 0;
} 