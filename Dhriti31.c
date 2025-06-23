// C program To find the biggest and smallest value among three integers using pointers

#include <stdio.h>

void findMinMax(int *a, int *b, int *c, int *min, int *max) {
    *min = *a;
    *max = *a;
    if (*b < *min) *min = *b;
    if (*b > *max) *max = *b;
    if (*c < *min) *min = *c;
    if (*c > *max) *max = *c;
}

int main() {
    int a, b, c, min, max;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    findMinMax(&a, &b, &c, &min, &max);

    printf("Smallest: %d\n", min);
    printf("Biggest: %d\n", max);
    return 0;
}
