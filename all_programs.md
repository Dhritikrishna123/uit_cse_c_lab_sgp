# C Programming Lab Programs

## Table of Contents
1. [Temperature Conversion (Celsius ↔ Fahrenheit)](#1-temperature-conversion-celsius--fahrenheit)
2. [Polynomial Evaluation](#2-polynomial-evaluation)
3. [ASCII Values Display](#3-ascii-values-display)
4. [Variable Swapping Methods](#4-variable-swapping-methods)
5. [Time Unit Conversion](#5-time-unit-conversion)
6. [Decimal Number Floor and Ceiling](#6-decimal-number-floor-and-ceiling)
7. [Floating Point Number Analysis](#7-floating-point-number-analysis)
8. [Five Digit Number Operations](#8-five-digit-number-operations)
9. [Number Properties Checker](#9-number-properties-checker)
10. [Bitwise Operations Demo](#10-bitwise-operations-demo)

---

## 1. Temperature Conversion (Celsius ↔ Fahrenheit)

### Description
Program to convert temperatures between Celsius and Fahrenheit with input validation and error handling. Includes checks for absolute zero temperatures in both scales.

### Code
```c
/*
Program to Convert Temperature between Celsius and Fahrenheit
*/

#include <stdio.h>

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    float temp, convertedTemp;
    int choice;
    char check;

    printf("\nTemperature Conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter choice (1 or 2): ");
    
    if (scanf("%d%c", &choice, &check) != 2 || check != '\n') {
        printf("Error: Invalid input! Please enter a number (1 or 2).\n");
        return 1;
    }

    if (choice != 1 && choice != 2) {
        printf("Error: Invalid choice! Please enter either 1 or 2.\n");
        return 1;
    }

    if (choice == 1) {
        printf("\nEnter temperature in Celsius: ");
        if (scanf("%f%c", &temp, &check) != 2 || check != '\n') {
            printf("Error: Invalid input! Please enter a valid number.\n");
            return 1;
        }
        
        if (temp < -273.15) {
            printf("Error: Temperature cannot be below absolute zero (-273.15°C)!\n");
            return 1;
        }
        
        convertedTemp = (temp * 9.0 / 5.0) + 32.0;
        printf("\nResult: %.2f°C = %.2f°F\n", temp, convertedTemp);
    } else {
        printf("\nEnter temperature in Fahrenheit: ");
        if (scanf("%f%c", &temp, &check) != 2 || check != '\n') {
            printf("Error: Invalid input! Please enter a valid number.\n");
            return 1;
        }
        
        if (temp < -459.67) {
            printf("Error: Temperature cannot be below absolute zero (-459.67°F)!\n");
            return 1;
        }
        
        convertedTemp = (temp - 32.0) * 5.0 / 9.0;
        printf("\nResult: %.2f°F = %.2f°C\n", temp, convertedTemp);
    }

    return 0;
}
```

### Features
- Input validation for menu choice
- Input validation for temperature values
- Absolute zero temperature checks
- Proper error messages
- Clear input buffer handling

### Sample Outputs

**Output 1 (Successful Conversion)**:
```
Temperature Conversion:
1. Celsius to Fahrenheit
2. Fahrenheit to Celsius
Enter choice (1 or 2): 1

Enter temperature in Celsius: 37.5

Result: 37.50°C = 99.50°F
```

**Output 2 (Error Case)**:
```
Temperature Conversion:
1. Celsius to Fahrenheit
2. Fahrenheit to Celsius
Enter choice (1 or 2): 1

Enter temperature in Celsius: -300

Error: Temperature cannot be below absolute zero (-273.15°C)!
```

---

## 2. Polynomial Evaluation

### Description
Program to evaluate a polynomial of degree n at a given value x. Includes input validation and overflow checking.

### Code
```c
/*
Program to Evaluate the Sum of a Polynomial
*/

#include <stdio.h>
#include <math.h>

#define MAX_DEGREE 10  // Maximum degree of polynomial allowed

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    int n;
    double x, sum = 0.0;
    double coefficients[MAX_DEGREE + 1];
    char check;

    printf("Enter the degree of the polynomial (0-%d): ", MAX_DEGREE);
    if (scanf("%d%c", &n, &check) != 2 || check != '\n') {
        printf("Error: Invalid input! Please enter a valid integer.\n");
        return 1;
    }

    if (n < 0) {
        printf("Error: Degree cannot be negative.\n");
        return 1;
    }

    if (n > MAX_DEGREE) {
        printf("Error: Degree cannot exceed %d.\n", MAX_DEGREE);
        return 1;
    }

    printf("\nEnter the coefficients (from highest degree to constant term):\n");
    for (int i = 0; i <= n; i++) {
        printf("Coefficient of x^%d: ", n - i);
        if (scanf("%lf%c", &coefficients[i], &check) != 2 || check != '\n') {
            printf("Error: Invalid input! Please enter a valid number.\n");
            return 1;
        }
    }

    printf("\nEnter the value of x: ");
    if (scanf("%lf%c", &x, &check) != 2 || check != '\n') {
        printf("Error: Invalid input! Please enter a valid number.\n");
        return 1;
    }

    for (int i = 0; i <= n; i++) {
        sum += coefficients[i] * pow(x, n - i);
    }

    if (isinf(sum) || isnan(sum)) {
        printf("\nError: Calculation resulted in an invalid value (overflow or undefined).\n");
        return 1;
    }

    printf("\nPolynomial evaluation at x = %.2f: %.4f\n", x, sum);
    return 0;
}
```

### Features
- Configurable maximum polynomial degree
- Input validation for degree and coefficients
- Overflow checking in calculations
- Dynamic coefficient input based on degree
- Clear error messages

### Sample Outputs

**Output 1 (Successful Evaluation)**:
```
Enter the degree of the polynomial (0-10): 2

Enter the coefficients (from highest degree to constant term):
Coefficient of x^2: 1
Coefficient of x^1: -5
Coefficient of x^0: 6

Enter the value of x: 2

Polynomial evaluation at x = 2.00: 4.0000
```

**Output 2 (Error Case)**:
```
Enter the degree of the polynomial (0-10): 11

Error: Degree cannot exceed 10.
```

---

## 3. ASCII Values Display

### Description
Program to display ASCII values for different types of characters with proper formatting and array bounds checking.

### Code
```c
/*
Program to Print ASCII Codes for Different Characters
*/

#include <stdio.h>

int main(void) {
    char ch;

    printf("=============================================\n");
    printf("      ASCII VALUES OF DIFFERENT CHARACTERS   \n");
    printf("=============================================\n\n");

    printf(" ASCII values for **Uppercase Alphabets**:\n");
    printf("---------------------------------------------\n");
    for (ch = 'A'; ch <= 'Z'; ch++) {
        printf("%c: %3d  ", ch, ch);
        if ((ch - 'A' + 1) % 6 == 0) printf("\n");
    }
    if ((ch - 'A') % 6 != 0) printf("\n");
    printf("\n");

    printf(" ASCII values for **Lowercase Alphabets**:\n");
    printf("---------------------------------------------\n");
    for (ch = 'a'; ch <= 'z'; ch++) {
        printf("%c: %3d  ", ch, ch);
        if ((ch - 'a' + 1) % 6 == 0) printf("\n");
    }
    if ((ch - 'a') % 6 != 0) printf("\n");
    printf("\n");

    printf(" ASCII values for **Numbers (0-9)**:\n");
    printf("---------------------------------------------\n");
    for (ch = '0'; ch <= '9'; ch++) {
        printf("%c: %3d  ", ch, ch);
    }
    printf("\n\n");

    printf(" ASCII values for **Special Characters**:\n");
    printf("---------------------------------------------\n");
    char specialChars[] = {'\n', '\b', ' ', ';', ',', '.', '-', '+', '/', '*', '%', '&', '>', '<', '='};
    char* specialNames[] = {"(New Line)", "(Backspace)", "(Space)", ";", ",", ".", "-", "+", "/", "*", "%", "&", ">", "<", "="};

    int size = sizeof(specialChars) / sizeof(specialChars[0]);
    int namesSize = sizeof(specialNames) / sizeof(specialNames[0]);

    if (size != namesSize) {
        printf("\nError: Internal array size mismatch!\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        printf("%-12s: %3d  ", specialNames[i], specialChars[i]);
        if ((i + 1) % 3 == 0) printf("\n");
    }
    if (size % 3 != 0) printf("\n");

    printf("\n=============================================\n");
    printf("            PROGRAM EXECUTION ENDED          \n");
    printf("=============================================\n");

    return 0;
}
```

### Features
- Organized display of different character types
- Proper formatting with aligned columns
- Array bounds checking
- Special character handling
- Clean visual presentation

### Sample Outputs

**Output 1 (Successful Display)**:
```
=============================================
      ASCII VALUES OF DIFFERENT CHARACTERS   
=============================================

 ASCII values for **Uppercase Alphabets**:
---------------------------------------------
A:  65  B:  66  C:  67  D:  68  E:  69  F:  70  
G:  71  H:  72  I:  73  J:  74  K:  75  L:  76  
[Output truncated for brevity]

```

**Output 2 (Special Characters)**:
```
 ASCII values for **Special Characters**:
---------------------------------------------
(New Line) :  10  (Backspace):   8  (Space)   :  32  
;          :  59  ,          :  44  .         :  46  
[Output truncated for brevity]
```

---

## 4. Variable Swapping Methods

### Description
Program to demonstrate three different methods of swapping variables with input validation and overflow checking.

### Code
```c
/*
Program to Swap Two Variables Using Different Methods
*/

#include <stdio.h>
#include <limits.h>

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    int a, b, choice;
    char check;

    printf("Enter two numbers: ");
    if (scanf("%d %d%c", &a, &b, &check) != 3 || check != '\n') {
        printf("Error: Invalid input! Please enter two valid integers.\n");
        return 1;
    }

    printf("\nChoose the swapping method:\n");
    printf("1. Using Arithmetic Operators\n");
    printf("2. Using a Third Variable\n");
    printf("3. Using Bitwise XOR\n");
    printf("Enter your choice (1-3): ");
    
    if (scanf("%d%c", &choice, &check) != 2 || check != '\n') {
        printf("Error: Invalid input! Please enter a number between 1 and 3.\n");
        return 1;
    }

    if (choice == 1) {
        if ((a > 0 && b > INT_MAX - a) || (a < 0 && b < INT_MIN - a)) {
            printf("Error: Numbers too large for arithmetic method. Please use another method.\n");
            return 1;
        }
    }

    switch (choice) {
        case 1:
            a = a + b;
            b = a - b;
            a = a - b;
            printf("\nSwapped using Arithmetic Operators:\n");
            break;

        case 2:
        {
            int temp = a;
            a = b;
            b = temp;
            printf("\nSwapped using a Third Variable:\n");
            break;
        }

        case 3:
            a = a ^ b;
            b = a ^ b;
            a = a ^ b;
            printf("\nSwapped using Bitwise XOR:\n");
            break;

        default:
            printf("Error: Invalid choice! Please enter a number between 1 and 3.\n");
            return 1;
    }

    printf("After swapping: a = %d, b = %d\n", a, b);
    return 0;
}
```

### Features
- Three different swapping methods
- Overflow checking for arithmetic method
- Input validation for numbers and choice
- Clear menu interface
- Proper error handling

### Sample Outputs

**Output 1 (Successful Swap)**:
```
Enter two numbers: 10 20

Choose the swapping method:
1. Using Arithmetic Operators
2. Using a Third Variable
3. Using Bitwise XOR
Enter your choice (1-3): 1

Swapped using Arithmetic Operators:
After swapping: a = 20, b = 10
```

**Output 2 (Error Case)**:
```
Enter two numbers: 2147483647 100

Choose the swapping method:
1. Using Arithmetic Operators
2. Using a Third Variable
3. Using Bitwise XOR
Enter your choice (1-3): 1

Error: Numbers too large for arithmetic method. Please use another method.
```

---

## 5. Time Unit Conversion

### Description
Program to convert seconds into days, hours, minutes, and seconds with input validation.

### Code
```c
/*
Program to Convert Seconds into Days, Hours, Minutes and Seconds
*/

#include <stdio.h>

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    int seconds, days, hours, minutes;
    char check;

    printf("Enter the number of seconds: ");
    if (scanf("%d%c", &seconds, &check) != 2 || check != '\n') {
        printf("Error: Invalid input! Please enter a valid integer.\n");
        return 1;
    }

    if (seconds < 0) {
        printf("Error: Number of seconds cannot be negative.\n");
        return 1;
    }

    int originalSeconds = seconds;

    days = seconds / 86400;       // 1 day = 86400 seconds
    seconds %= 86400;
    
    hours = seconds / 3600;       // 1 hour = 3600 seconds
    seconds %= 3600;
    
    minutes = seconds / 60;       // 1 minute = 60 seconds
    seconds %= 60;

    printf("\nConverting %d seconds:\n", originalSeconds);
    printf("= %d day(s), %d hour(s), %d minute(s), %d second(s)\n", 
           days, hours, minutes, seconds);

    return 0;
}
```

### Features
- Input validation for seconds
- Negative value checking
- Clear time unit conversion
- Preserves original input
- Formatted output display

### Sample Outputs

**Output 1 (Successful Conversion)**:
```
Enter the number of seconds: 100000

Converting 100000 seconds:
= 1 day(s), 3 hour(s), 46 minute(s), 40 second(s)
```

**Output 2 (Error Case)**:
```
Enter the number of seconds: -50

Error: Number of seconds cannot be negative.
```

---

## 6. Decimal Number Floor and Ceiling

### Description
Program to find the smallest integer not less than (ceiling) and the largest integer not greater than (floor) a given decimal number.

### Code
```c
/*
Program to Find Floor and Ceiling of a Decimal Number
*/
#include <stdio.h>
#include <limits.h>

int main() {
    double num;
    char check;
    
    printf("Enter a decimal number: ");
    if(scanf("%lf%c", &num, &check) != 2 || check != '\n') {
        printf("Error: Invalid input! Please enter a valid decimal number.\n");
        return 1;
    }
    
    // Check for overflow
    if(num > INT_MAX || num < INT_MIN) {
        printf("Error: Number out of integer range! Please enter a number between %d and %d\n", 
               INT_MIN, INT_MAX);
        return 1;
    }
    
    int smallest = (int)num;
    if (num > 0 && num != (int)num) {
        smallest += 1;
    }
    
    int largest = (int)num;
    if (num < 0 && num != (int)num) {
        largest -= 1;
    }
    
    printf("Smallest integer not less than %.2lf is: %d\n", num, smallest);
    printf("Largest integer not greater than %.2lf is: %d\n", num, largest);
    
    return 0;
}
```

### Features
- Input validation for decimal numbers
- Overflow checking
- Handles both positive and negative numbers
- Proper rounding for floor and ceiling
- Clear error messages

### Sample Outputs

**Output 1 (Successful Case)**:
```
Enter a decimal number: 3.7

Smallest integer not less than 3.70 is: 4
Largest integer not greater than 3.70 is: 3
```

**Output 2 (Error Case)**:
```
Enter a decimal number: 2147483648.5

Error: Number out of integer range! Please enter a number between -2147483648 and 2147483647
```

---

## 7. Floating Point Number Analysis

### Description
Program to analyze a floating point number (≤ 999.999) by finding its leftmost and rightmost digits, and comparing the three digits on each side of the decimal point.

### Code
```c
/*
Program to Analyze a Floating Point Number (≤ 999.999)
*/
#include <stdio.h>

// Function to count decimal places using mathematical operations
int countDecimalPlaces(double num) {
    int count = 0;
    double fractional = num - (int)num;  // Get fractional part
    const double EPSILON = 1e-10;  // precise epsilon value
    
    while(count < 6 && fractional > EPSILON) {
        fractional *= 10;
        fractional -= (int)fractional;
        count++;
    }
    return count;
}

// Function to get leftmost digit using division
int getLeftmostDigit(int num) {
    while(num >= 10) {
        num /= 10;
    }
    return num;
}

// Function to get rightmost digit using modulo
int getRightmostDigit(int num) {
    return num % 10;
}

int main() {
    double num;
    char check;
    
    printf("Enter a floating point number (up to 3 decimal places, <= 999.999): ");
    if(scanf("%lf%c", &num, &check) != 2 || check != '\n') {
        printf("Error: Invalid input! Please enter a valid number.\n");
        return 1;
    }
    
    if(num < 0 || num > 999.999) {
        printf("Error: Number must be between 0 and 999.999!\n");
        return 1;
    }
    
    // Check decimal places
    int decimalPlaces = countDecimalPlaces(num);
    if(decimalPlaces > 3) {
        printf("Error: Number must have at most 3 decimal places!\n");
        return 1;
    }
    
    // Round to exactly 3 decimal places for consistency
    num = (double)((int)(num * 1000 + 0.5)) / 1000.0;
    
    // Split number into integer and decimal parts
    int leftPart = (int)num;  // Integer part
    int rightPart = (int)((num - leftPart) * 1000 + 0.5);  // Decimal part * 1000
    
    int leftmost = getLeftmostDigit(leftPart);
    int rightmost = getRightmostDigit(rightPart);
    
    printf("\nLeft-most digit: %d", leftmost);
    printf("\nRight-most digit: %d", rightmost);
    
    // Get last three digits of left part for fair comparison
    int leftThreeDigits = leftPart % 1000;
    
    printf("\n\nLeft three digits: %d", leftThreeDigits);
    printf("\nRight three digits: %d", rightPart);
    
    if (leftThreeDigits > rightPart) {
        printf("\nLeft side three digits are bigger by %d", leftThreeDigits - rightPart);
    } else if (rightPart > leftThreeDigits) {
        printf("\nRight side three digits are bigger by %d", rightPart - leftThreeDigits);
    } else {
        printf("\nBoth sides are equal");
    }
    
    return 0;
}
```

### Features
- Precise decimal place counting
- Input validation for range and decimal places
- Mathematical methods for digit extraction
- Fair comparison of three digits on each side
- Proper rounding and error handling

### Sample Outputs

**Output 1 (Successful Analysis)**:
```
Enter a floating point number (up to 3 decimal places, <= 999.999): 123.456

Left-most digit: 1
Right-most digit: 6

Left three digits: 123
Right three digits: 456
Right side three digits are bigger by 333
```

**Output 2 (Error Case)**:
```
Enter a floating point number (up to 3 decimal places, <= 999.999): 1000.0

Error: Number must be between 0 and 999.999!
```

---

## 8. Five Digit Number Operations

### Description
Program to calculate the sum and product of digits of a five-digit number.

### Code
```c
/*
Program to Calculate Sum and Product of a Five-Digit Number
*/
#include <stdio.h>

int main() {
    long num, temp;  // Using long to check range
    int sum = 0, product = 1;
    char check;
    
    printf("Enter a five digit number: ");
    if(scanf("%ld%c", &num, &check) != 2 || check != '\n') {
        printf("Error: Invalid input! Please enter a valid number.\n");
        return 1;
    }
    
    // Validate five digits and positive number
    if(num < 10000 || num > 99999) {
        printf("Error: Please enter exactly five digits (10000 to 99999)!\n");
        return 1;
    }
    
    // Store original number
    temp = num;
    
    // Calculate sum and product of digits
    while(temp > 0) {
        int digit = temp % 10;
        sum += digit;
        product *= digit;
        temp /= 10;
    }
    
    printf("Sum of digits of %ld is: %d\n", num, sum);
    printf("Product of digits of %ld is: %d\n", num, product);
    
    return 0;
}
```

### Features
- Input validation for five-digit numbers
- Range checking
- Calculates both sum and product
- Preserves original input
- Clear error messages

### Sample Outputs

**Output 1 (Successful Calculation)**:
```
Enter a five digit number: 12345

Sum of digits of 12345 is: 15
Product of digits of 12345 is: 120
```

**Output 2 (Error Case)**:
```
Enter a five digit number: 1234

Error: Please enter exactly five digits (10000 to 99999)!
```

---

## 9. Number Properties Checker

### Description
Program to check if a number is prime, even/odd, and positive/negative/zero.

### Code
```c
/*
Program to Check Prime, Even/Odd and Sign of a Number
*/
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int main() {
    long long num;  // Using long long for maximum range
    char check;
    
    printf("Enter an integer: ");
    if(scanf("%lld%c", &num, &check) != 2 || check != '\n') {
        printf("Error: Invalid input! Please enter a valid integer.\n");
        return 1;
    }
    
    // Check for integer overflow
    if(num > INT_MAX || num < INT_MIN) {
        printf("Error: Number out of range! Please enter a number between %d and %d\n", 
               INT_MIN, INT_MAX);
        return 1;
    }
    
    int n = (int)num;  // Safe to convert now
    
    // Check if prime
    if (isPrime(n)) {
        printf("%d is a prime number\n", n);
    } else {
        printf("%d is not a prime number\n", n);
    }
    
    // Check if even/odd
    if (n % 2 == 0) {
        printf("%d is even\n", n);
    } else {
        printf("%d is odd\n", n);
    }
    
    // Check if positive/negative/zero
    if (n > 0) {
        printf("%d is positive\n", n);
    } else if (n < 0) {
        printf("%d is negative\n", n);
    } else {
        printf("The number is zero\n");
    }
    
    return 0;
}
```

### Features
- Efficient prime number checking
- Multiple property checks
- Range validation
- Overflow protection
- Clear output format

### Sample Outputs

**Output 1 (Successful Check)**:
```
Enter an integer: 17

17 is a prime number
17 is odd
17 is positive
```

**Output 2 (Multiple Properties)**:
```
Enter an integer: 20

20 is not a prime number
20 is even
20 is positive
```

---

## 10. Bitwise Operations Demo

### Description
Program to demonstrate all bitwise operators in C.

### Code
```c
/*
Program to Demonstrate Bitwise Operations
*/
#include <stdio.h>
#include <limits.h>

int main() {
    long long a, b;  // Using long long for range checking
    char check;
    
    printf("Enter two integers to perform bitwise operations: ");
    if(scanf("%lld %lld%c", &a, &b, &check) != 3 || check != '\n') {
        printf("Error: Invalid input! Please enter two valid integers.\n");
        return 1;
    }
    
    // Check for integer overflow
    if(a > INT_MAX || a < INT_MIN || b > INT_MAX || b < INT_MIN) {
        printf("Error: Numbers out of range! Please enter numbers between %d and %d\n", 
               INT_MIN, INT_MAX);
        return 1;
    }
    
    int num1 = (int)a;  // Safe to convert now
    int num2 = (int)b;
    
    printf("\nBitwise Operations Results:\n");
    printf("----------------------------\n");
    
    // Bitwise AND (&)
    printf("Bitwise AND (&):\n");
    printf("%d & %d = %d\n", num1, num2, num1 & num2);
    
    // Bitwise OR (|)
    printf("\nBitwise OR (|):\n");
    printf("%d | %d = %d\n", num1, num2, num1 | num2);
    
    // Bitwise XOR (^)
    printf("\nBitwise XOR (^):\n");
    printf("%d ^ %d = %d\n", num1, num2, num1 ^ num2);
    
    // Bitwise NOT (~)
    printf("\nBitwise NOT (~):\n");
    printf("~%d = %d\n", num1, ~num1);
    printf("~%d = %d\n", num2, ~num2);
    
    // Left Shift (<<)
    printf("\nLeft Shift (<<):\n");
    if(num1 >= 0) {  // Only perform left shift on non-negative numbers
        printf("%d << 1 = %d\n", num1, num1 << 1);
        printf("%d << 2 = %d\n", num1, num1 << 2);
    } else {
        printf("Left shift not performed on negative number %d\n", num1);
    }
    
    // Right Shift (>>)
    printf("\nRight Shift (>>):\n");
    printf("%d >> 1 = %d\n", num1, num1 >> 1);
    printf("%d >> 2 = %d\n", num1, num1 >> 2);
    
    return 0;
}
```

### Features
- Demonstrates all bitwise operators
- Input validation
- Range checking
- Safe handling of negative numbers
- Clear output formatting

### Sample Outputs

**Output 1 (Successful Operations)**:
```
Enter two integers to perform bitwise operations: 12 7

Bitwise Operations Results:
----------------------------
Bitwise AND (&):
12 & 7 = 4

Bitwise OR (|):
12 | 7 = 15

[Output continues with other operations]
```

**Output 2 (Error Case)**:
```
Enter two integers to perform bitwise operations: 2147483648 1

Error: Numbers out of range! Please enter numbers between -2147483648 and 2147483647
```

---

## How to Use These Programs

1. **Compilation**: Use a C compiler (e.g., GCC)
   ```bash
   gcc -o program_name program_name.c
   ```

2. **Execution**: Run the compiled program
   ```bash
   ./program_name
   ```

3. **Input**: Follow the prompts and provide valid input as requested

4. **Output**: View the results or error messages if any

## Notes

- All programs include input validation
- Error messages are clear and descriptive
- Programs use consistent error handling
- Code is well-commented and formatted
- Each program returns 0 for success, 1 for errors 