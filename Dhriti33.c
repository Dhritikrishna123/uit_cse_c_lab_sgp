/*
    C program to perform the addition of two matices using pointers and point the result
*/
#include <stdio.h>
#include <stdlib.h>

void addMatrices(int *a, int *b, int *res, int size) {
    for (int i = 0; i < size; i++)
        res[i] = a[i] + b[i];
}

int main() {
    int rows, cols;
    printf("Enter rows and columns: ");
    scanf("%d%d", &rows, &cols);
    int size = rows * cols;

    int *a = malloc(size * sizeof(int));
    int *b = malloc(size * sizeof(int));
    int *sum = malloc(size * sizeof(int));

    if (!a || !b || !sum) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < size; i++) scanf("%d", &a[i]);

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < size; i++) scanf("%d", &b[i]);

    addMatrices(a, b, sum, size);

    printf("Sum of matrices:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", sum[i]);
        if ((i + 1) % cols == 0) printf("\n");
    }

    free(a); free(b); free(sum);
    return 0;
}
