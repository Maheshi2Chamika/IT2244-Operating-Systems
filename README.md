# IT2244-Operating-Systems
![01](https://github.com/user-attachments/assets/702c3a5e-e5d0-4e34-b7d1-19302e25b7a6)

# Fork-Based Multi-Process Computation – README
## Commands & Examples

### 1. Fork Program: Factorial, Fibonacci, and Prime Number Calculation
- **Description**: This C program uses multiple `fork()` calls to create separate processes for computing the factorial, Fibonacci sequence, and prime numbers for three user-input values. It demonstrates parent-child and sub-child process handling.
- **Usage**:
  - gcc fibfac.c -o fibfac
  - ./fibfac
- **Purpose**: To understand how multiple child processes can be created using `fork()` to perform different mathematical computations independently and simultaneously.

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    int num1, num2, num3;

    printf("\nEnter Numbers: \n");
    scanf("%d %d %d", &num1, &num2, &num3);

    if (fork() == 0) 
    { // First child process (Factorial)
        printf("Factorial Process ID: %d\n", getpid());
        int fact = 1;
        for (int i = 1; i <= num1; i++) {
            fact *= i;
        }
        printf("Factorial of %d = %d\n", num1, fact);
        return 0;
    }

    if (fork() == 0) 
    { // Second child process (Sub-parent for Fibonacci & Prime)
        printf("Sub-Parent Process ID: %d\n", getpid());

        if (fork() == 0) 
        { // Fibonacci process under sub-parent
            printf("Fibonacci Process ID: %d\n", getpid());
            int a = 0, b = 1, next;
            printf("Fibonacci sequence up to %d terms: ", num2);
            for (int j = 0; j < num2; j++) {
                printf("%d ", a);
                next = a + b;
                a = b;
                b = next;
            }
            printf("\n");
            return 0;
        }

        if (fork() == 0) 
        { // Prime number process under sub-parent
            printf("Prime Numbers Process ID: %d\n", getpid());
            printf("Prime numbers up to %d: ", num3);
            for (int i = 2; i <= num3; i++) {
                int isPrime = 1;
                for (int j = 2; j * j <= i; j++) {
                    if (i % j == 0) {
                        isPrime = 0;
                        break;
                    }
                }
                if (isPrime) {
                    printf("%d ", i);
                }
            }
            printf("\n");
            return 0;
        }

        return 0; // Sub-parent exits after creating its children
    }

    printf("Main Parent Process ID: %d\n", getpid()); // Display parent process ID

    return 0;
}

