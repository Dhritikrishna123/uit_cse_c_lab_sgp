// C program To swap a real number and an address of a real number using no third variable

#include <stdio.h>

void ValueRef(float x, float *y) {
    x = x + *y;
    *y = x - *y;
    x = x - *y;
    printf("In called function: x = %.2f, *y = %.2f\n", x, *y);
}

int main() {
    float a, b;
    printf("Enter two real numbers: ");
    scanf("%f %f", &a, &b);

    printf("Before call: a = %.2f, b = %.2f\n", a, b);
    ValueRef(a, &b);
    printf("After call: a = %.2f, b = %.2f\n", a, b);

    return 0;
}
