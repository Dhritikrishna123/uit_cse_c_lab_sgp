/*
Program to Evaluate Series Sum
Series: 1 + (1+2) + (1+2+3) + ... + (1+2+3+...+n)
*/
#include <stdio.h>
#include <limits.h>

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to calculate sum of first k natural numbers
unsigned long long sumOfNaturalNumbers(int k) {
    return (unsigned long long)k * (k + 1) / 2;
}

// Function to calculate sum of series up to n terms
unsigned long long calculateSeriesSum(int n) {
    unsigned long long totalSum = 0;
    
    // For each term i from 1 to n
    for(int i = 1; i <= n; i++) {
        // Add sum of first i natural numbers
        unsigned long long termSum = sumOfNaturalNumbers(i);
        
        // Check for overflow
        if (totalSum > ULLONG_MAX - termSum) {
            printf("Error: Series sum overflow!\n");
            return 0;
        }
        
        totalSum += termSum;
    }
    
    return totalSum;
}

// Function to display the series terms
void displaySeries(int n) {
    printf("\nSeries expansion:\n");
    
    for(int i = 1; i <= n; i++) {
        if(i == 1) {
            printf("1");
        } else {
            printf(" + (");
            for(int j = 1; j <= i; j++) {
                printf("%d", j);
                if(j < i) printf("+");
            }
            printf(")");
        }
        
        if(i == n) printf("\n");
    }
}

int main() {
    int n;
    char check;
    
    // Input validation for n
    while(1) {
        printf("Enter the value of n (1-100): ");
        if(scanf("%d%c", &n, &check) != 2 || check != '\n') {
            printf("Error: Please enter a valid integer.\n");
            clearInputBuffer();
            continue;
        }
        
        if(n < 1) {
            printf("Error: n must be at least 1.\n");
            continue;
        }
        
        if(n > 100) {
            printf("Error: n cannot exceed 100 (to prevent overflow).\n");
            continue;
        }
        
        break;
    }
    
    // Display the series
    displaySeries(n);
    
    // Calculate and display the sum
    unsigned long long sum = calculateSeriesSum(n);
    if(sum > 0) {  // Check if calculation was successful
        printf("\nSum of the series = %llu\n", sum);
        
        // Display term-by-term calculation for verification
        printf("\nTerm-by-term calculation:\n");
        unsigned long long termSum = 0;
        for(int i = 1; i <= n; i++) {
            unsigned long long currentTerm = sumOfNaturalNumbers(i);
            printf("Term %d = %llu\n", i, currentTerm);
            termSum += currentTerm;
        }
        printf("Total Sum = %llu\n", termSum);
    }
    
    return 0;
} 