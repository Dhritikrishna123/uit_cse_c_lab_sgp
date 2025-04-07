/*
Program to Find Sum of Odd and Even Numbers in Array
*/
#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to calculate sums of odd and even numbers
void calculateSums(int arr[], int size, long long *evenSum, long long *oddSum) {
    *evenSum = 0;
    *oddSum = 0;
    
    for(int i = 0; i < size; i++) {
        if(arr[i] % 2 == 0) {
            // Check for overflow before adding
            if(*evenSum > LLONG_MAX - arr[i]) {
                printf("Warning: Even sum overflow! Result may be incorrect.\n");
                return;
            }
            *evenSum += arr[i];
        } else {
            // Check for overflow before adding
            if(*oddSum > LLONG_MAX - arr[i]) {
                printf("Warning: Odd sum overflow! Result may be incorrect.\n");
                return;
            }
            *oddSum += arr[i];
        }
    }
}

// Function to display array elements with their properties
void displayArray(int arr[], int size) {
    printf("\nArray elements and their properties:\n");
    printf("Index\tValue\tType\n");
    printf("------------------------\n");
    
    for(int i = 0; i < size; i++) {
        printf("%d\t%d\t%s\n", i, arr[i], 
               (arr[i] % 2 == 0) ? "Even" : "Odd");
    }
}

int main() {
    int arr[MAX_SIZE];
    int size;
    char check;
    
    // Input array size
    while(1) {
        printf("Enter the size of array (1-%d): ", MAX_SIZE);
        if(scanf("%d%c", &size, &check) != 2 || check != '\n') {
            printf("Error: Invalid input!\n");
            clearInputBuffer();
            continue;
        }
        
        if(size < 1 || size > MAX_SIZE) {
            printf("Error: Size should be between 1 and %d.\n", MAX_SIZE);
            continue;
        }
        break;
    }
    
    // Input array elements
    printf("\nEnter %d integers:\n", size);
    for(int i = 0; i < size; i++) {
        while(1) {
            printf("Element %d: ", i + 1);
            if(scanf("%d%c", &arr[i], &check) != 2 || check != '\n') {
                printf("Error: Invalid input! Please enter an integer.\n");
                clearInputBuffer();
                continue;
            }
            break;
        }
    }
    
    // Display the array
    displayArray(arr, size);
    
    // Calculate sums
    long long evenSum, oddSum;
    calculateSums(arr, size, &evenSum, &oddSum);
    
    // Display results
    printf("\nResults:\n");
    printf("Sum of even numbers: %lld\n", evenSum);
    printf("Sum of odd numbers: %lld\n", oddSum);
    
    // Display the difference
    printf("\nDifference between sums:\n");
    if(evenSum > oddSum) {
        printf("Even sum is greater by: %lld\n", evenSum - oddSum);
    } else if(oddSum > evenSum) {
        printf("Odd sum is greater by: %lld\n", oddSum - evenSum);
    } else {
        printf("Even and odd sums are equal\n");
    }
    
    return 0;
} 
