/*
C program to define a structure datatype called “time” comprising members viz., hour, minute, and second
*/
#include <stdio.h>

struct time {
    int hour;
    int minute;
    int second;
};

void assignTime(struct time *t, int h, int m, int s) {
    if (h >= 0 && h <= 23 && m >= 0 && m <= 59 && s >= 0 && s <= 59) {
        t->hour = h;
        t->minute = m;
        t->second = s;
    } else {
        printf("Invalid time values!\n");
        t->hour = 0;
        t->minute = 0;
        t->second = 0;
    }
}

void displayTime(struct time t) {
    printf("%02d:%02d:%02d\n", t.hour, t.minute, t.second);
}

int main() {
    struct time currentTime;
    int h, m, s;
    char choice;
    
    do {
        printf("Enter time (hour minute second): ");
        scanf("%d %d %d", &h, &m, &s);
        
        assignTime(&currentTime, h, m, s);
        
        printf("Time assigned: ");
        displayTime(currentTime);
        
        printf("Do you want to assign another time? (y/n): ");
        scanf(" %c", &choice);
        
    } while (choice == 'y' || choice == 'Y');
    
    printf("Final time: ");
    displayTime(currentTime);
    
    return 0;
}