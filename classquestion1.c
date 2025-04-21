#include <stdio.h>
#include <string.h>

void reverseExceptLastPeriod(char str[]) {
    int len = strlen(str);
    int lastDot = -1;

    // Find index of last period
    for (int i = len - 1; i >= 0; i--) {
        if (str[i] == '.') {
            lastDot = i;
            break;
        }
    }

    // Set end index for reversal (exclude last period and after)
    int end = (lastDot == -1) ? len - 1 : lastDot - 1;

    // Reverse from start to 'end'
    int start = 0;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline if present
    size_t len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    reverseExceptLastPeriod(str);
    printf("Reversed string: %s\n", str);

    return 0;
}
