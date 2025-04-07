/*
Program to Perform Matrix Operations: Addition, Subtraction, Multiplication
*/
#include <stdio.h>
#define MAX 10

// Function to input matrix
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display matrix
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add matrices
void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Function to subtract matrices
void subtractMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

// Function to multiply matrices
void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rowsA, int colsA, int colsB) {
    for(int i = 0; i < rowsA; i++) {
        for(int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for(int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int rowsA, colsA, rowsB, colsB;
    int matrixA[MAX][MAX], matrixB[MAX][MAX], result[MAX][MAX];
    char check;
    
    // Input dimensions for matrix A
    while(1) {
        printf("Enter rows and columns for matrix A (max %d): ", MAX);
        if(scanf("%d %d%c", &rowsA, &colsA, &check) != 3 || check != '\n') {
            printf("Error: Invalid input!\n");
            clearInputBuffer();
            continue;
        }
        if(rowsA < 1 || colsA < 1 || rowsA > MAX || colsA > MAX) {
            printf("Error: Dimensions must be between 1 and %d.\n", MAX);
            continue;
        }
        break;
    }
    
    // Input dimensions for matrix B
    while(1) {
        printf("Enter rows and columns for matrix B (max %d): ", MAX);
        if(scanf("%d %d%c", &rowsB, &colsB, &check) != 3 || check != '\n') {
            printf("Error: Invalid input!\n");
            clearInputBuffer();
            continue;
        }
        if(rowsB < 1 || colsB < 1 || rowsB > MAX || colsB > MAX) {
            printf("Error: Dimensions must be between 1 and %d.\n", MAX);
            continue;
        }
        break;
    }
    
    // Ensure matrices can be added or subtracted
    if(rowsA != rowsB || colsA != colsB) {
        printf("Error: Matrices must have the same dimensions for addition and subtraction!\n");
        return 1;
    }
    
    // Ensure matrices can be multiplied
    if(colsA != rowsB) {
        printf("Error: Number of columns in A must equal number of rows in B for multiplication!\n");
        return 1;
    }
    
    // Input matrices
    printf("\nInput matrix A:\n");
    inputMatrix(matrixA, rowsA, colsA);
    printf("\nInput matrix B:\n");
    inputMatrix(matrixB, rowsB, colsB);
    
    // Add matrices
    addMatrices(matrixA, matrixB, result, rowsA, colsA);
    printf("\nSum of matrices:\n");
    displayMatrix(result, rowsA, colsA);
    
    // Subtract matrices
    subtractMatrices(matrixA, matrixB, result, rowsA, colsA);
    printf("\nDifference of matrices:\n");
    displayMatrix(result, rowsA, colsA);
    
    // Multiply matrices
    multiplyMatrices(matrixA, matrixB, result, rowsA, colsA, colsB);
    printf("\nProduct of matrices:\n");
    displayMatrix(result, rowsA, colsB);
    
    return 0;
} 