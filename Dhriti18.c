/*
Program to Find Smallest and Largest Values in Array with Their Indices
*/
#include <stdio.h>
#define MAX_SIZE 100

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to find minimum value and its index
void findMin(int arr[], int size, int *minValue, int *minIndex) {
    *minValue = arr[0];
    *minIndex = 0;
    
    for(int i = 1; i < size; i++) {
        if(arr[i] < *minValue) {
            *minValue = arr[i];
            *minIndex = i;
        }
    }
}

// Function to find maximum value and its index
void findMax(int arr[], int size, int *maxValue, int *maxIndex) {
    *maxValue = arr[0];
    *maxIndex = 0;
    
    for(int i = 1; i < size; i++) {
        if(arr[i] > *maxValue) {
            *maxValue = arr[i];
            *maxIndex = i;
        }
    }
}

// // Function to display array elements with indices
// void displayArray(int arr[], int size) {
//     printf("\nArray elements:\n");
//     printf("Index\tValue\n");
//     printf("----------------\n");
    
//     for(int i = 0; i < size; i++) {
//         printf("%d\t%d\n", i, arr[i]);
//     }
// }

int main() {
    int arr[MAX_SIZE];
    int size;
    char check;
    int minValue, minIndex, maxValue, maxIndex;
    
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
    
    // // Display the array
    // displayArray(arr, size);
    
    // Find minimum and maximum
    findMin(arr, size, &minValue, &minIndex);
    findMax(arr, size, &maxValue, &maxIndex);
    
    // Display results
    printf("\nResults:\n");
    printf("Smallest value: %d (at index %d)\n", minValue, minIndex);
    printf("Largest value: %d (at index %d)\n", maxValue, maxIndex);
    
    // // Display additional information
    // printf("\nArray Analysis:\n");
    // printf("Range (max - min): %d\n", maxValue - minValue);
    
    // int distance = maxIndex - minIndex;
    // if(distance < 0) distance = -distance;  // Simple way to get absolute value
    // printf("Distance between min and max indices: %d\n", distance);
    
    // // Check if min and max are adjacent
    // if(distance == 1) {
    //     printf("Minimum and maximum values are adjacent in the array.\n");
    // }
    
    return 0;
} 