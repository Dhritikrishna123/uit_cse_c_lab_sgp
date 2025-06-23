// C program To input a list of n integers using pointers and print their sum, average, and product

#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number of integers: ");
    scanf("%d", &n);

    int arr[n];
    int *ptr = arr;

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", ptr + i);
    }

    int sum = 0, product = 1;
    for (i = 0; i < n; i++) {
        sum += *(ptr + i);
        product *= *(ptr + i);
    }

    float average = (float)sum / n;

    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", average);
    printf("Product = %d\n", product);

    return 0;
}
