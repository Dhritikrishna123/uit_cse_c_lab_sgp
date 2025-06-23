/*
Program to generate first n Fibonacci numbers 
*/
#include <stdio.h>

void generateFibonacci(int n) {
    int a = 0, b = 1, next;

    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }
}

int main() {
    int n;

    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &n);

    printf("Fibonacci sequence:\n");
    generateFibonacci(n);

    return 0;
}