# IT2244-Operating-Systems
#Basic C Programming Exercises

This document summarizes foundational C programming concepts and Linux terminal commands.

************************************************************

(Q1) Print Hello World
- Description: Outputs the message "Hello World" to the terminal using `printf`.
- Usage:
    gcc first.c -o first
    ./first
- Purpose: Introduces the structure of a C program and basic output functionality.

************************************************************

(Q2) Variables
- Description: Demonstrates variable declaration, initialization, and usage in C.
- Usage:
    gcc variables.c -o variables
    ./variables
- Purpose: Teaches how to store and manipulate data using variables of different data types.

************************************************************

(Q3) Multiple Variable Declarations
- Description: Declares and initializes multiple variables in a single line.
- Usage:
    int a = 25, b = 10;
- Purpose: Enhances code readability and conciseness when handling multiple related variables.

************************************************************

(Q4) Data Types and Sizes
- Description: Uses `sizeof()` to check the memory size of different data types.
- Usage:
    printf("%lu", sizeof(int));
- Purpose: Understands memory management and proper data type usage in C programs.

************************************************************

(Q5) User Input
- Description: Accepts input from the user using `scanf`.
- Usage:
    scanf("%d", &age);
- Purpose: Enables dynamic interaction between the program and the user.

************************************************************

(Q6) Multiple Inputs
- Description: Takes two or more inputs from the user using a single `scanf` statement.
- Usage:
    scanf("%lf %c", &number, &alpha);
- Purpose: Demonstrates how to read multiple values of different types in one line.

************************************************************

(Q7) Comments in C
- Description: Adds annotations to the code for better understanding using single-line (`//`) and multi-line (`/* */`) comments.
- Usage:
    // This is a comment
    /* This is
       a multi-line comment */
- Purpose: Improves code documentation and helps in debugging or explaining the logic.

************************************************************

(Q8) Arithmetic Operators
- Description: A simple calculator using switch-case statements to perform arithmetic operations.
- Usage:
    gcc calculator.c -o calculator
    ./calculator
- Purpose: Practices conditional logic and operator handling in C.

************************************************************
