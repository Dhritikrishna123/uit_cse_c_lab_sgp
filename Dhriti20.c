/*
Program to Read a Matrix, Print its Transpose, and Check Symmetry
*/
#include <stdio.h>
#define MAX 10

// Function to input matrix
void inputMatrix(int matrix[MAX][MAX], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display matrix
void displayMatrix(int matrix[MAX][MAX], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to transpose matrix
void transposeMatrix(int matrix[MAX][MAX], int transpose[MAX][MAX], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

// Function to check if matrix is symmetric
int isSymmetric(int matrix[MAX][MAX], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(matrix[i][j] != matrix[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int size;
    int matrix[MAX][MAX], transpose[MAX][MAX];
    char check;
    
    // Input matrix size
    while(1) {
        printf("Enter the size of the matrix (max %d): ", MAX);
        if(scanf("%d%c", &size, &check) != 2 || check != '\n') {
            printf("Error: Invalid input!\n");
            clearInputBuffer();
            continue;
        }
        if(size < 1 || size > MAX) {
            printf("Error: Size must be between 1 and %d.\n", MAX);
            continue;
        }
        break;
    }
    
    // Input matrix
    printf("\nInput matrix:\n");
    inputMatrix(matrix, size);
    
    // Display original matrix
    printf("\nOriginal matrix:\n");
    displayMatrix(matrix, size);
    
    // Transpose matrix
    transposeMatrix(matrix, transpose, size);
    printf("\nTranspose of matrix:\n");
    displayMatrix(transpose, size);
    
    // Check symmetry
    if(isSymmetric(matrix, size)) {
        printf("\nThe matrix is symmetric.\n");
    } else {
        printf("\nThe matrix is not symmetric.\n");
    }
    
    return 0;
} 