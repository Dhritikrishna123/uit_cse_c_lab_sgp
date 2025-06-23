// c program To perform three operations on a string using pointers:
// (i) Count the number of words,
// (ii) Find the longest word,
// (iii) Reverse the string
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void countWords(char *s) {
    int c = 0;
    while (*s) c += !isspace(*s) && (isspace(*(s+1)) || !*(s+1)), s++;
    printf("Words: %d\n", c);
}

void findLongest(char *s) {
    char *start = NULL, *longest = NULL;
    int len = 0, max = 0;
    while (*s) {
        if (!isspace(*s)) { if (!len) start = s; len++; }
        else if (len > max) max = len, longest = start, len = 0;
        else len = 0, s++;
        if (*s) s++;
    }
    if (len > max) max = len, longest = start;
    printf("Longest: "); while (max--) putchar(*longest++);
    printf("\n");
}

void reverse(char *s) {
    char *e = s + strlen(s) - 1;
    printf("Reversed: "); while (e >= s) putchar(*e--);
    printf("\n");
}

int main() {
    char *str = malloc(1000);
    printf("Enter string: ");
    fgets(str, 1000, stdin);

    countWords(str);
    findLongest(str);
    reverse(str);

    free(str);
    return 0;
}
