/*
C program to define a structure “employee” that holds information like employee code, name, date of joining, and salary
*/
#include <stdio.h>
#include <string.h>

struct employee {
    int id;
    char name[50];
    char dateOfJoining[15];
    float salary;
};

void printEmployeeDetails(struct employee emp[], int n) {
    printf("\n--- Employee Details ---\n");
    for (int i = 0; i < n; i++) {
        printf("Employee %d:\n", i + 1);
        printf("ID: %d\n", emp[i].id);
        printf("Name: %s\n", emp[i].name);
        printf("Date of Joining: %s\n", emp[i].dateOfJoining);
        printf("Salary: %.2f\n", emp[i].salary);
        printf("------------------------\n");
    }
}

void printHighSalaryEmployees(struct employee emp[], int n) {
    float totalSalary = 0, avgSalary;
    
    for (int i = 0; i < n; i++) {
        totalSalary += emp[i].salary;
    }
    avgSalary = totalSalary / n;
    
    printf("\nAverage Salary: %.2f\n", avgSalary);
    printf("Employees with salary more than average:\n");
    
    for (int i = 0; i < n; i++) {
        if (emp[i].salary > avgSalary) {
            printf("ID: %d, Name: %s, Salary: %.2f\n", 
                   emp[i].id, emp[i].name, emp[i].salary);
        }
    }
}

int main() {
    int n;
    
    printf("Enter number of employees: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid number of employees!\n");
        return 1;
    }
    
    struct employee emp[n];
    
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &emp[i].id);
        
        printf("Name: ");
        scanf(" %49s", emp[i].name);
        
        printf("Date of Joining (DD/MM/YYYY): ");
        scanf(" %14s", emp[i].dateOfJoining);
        
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }
    
    printEmployeeDetails(emp, n);
    printHighSalaryEmployees(emp, n);
    
    return 0;
}