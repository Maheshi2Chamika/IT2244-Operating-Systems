/*
step 01: parent process; get input from user.
step 02: sending there inputs to child process.
step 03: child process getting these inputs from parent and
         doing calculations
step 04: send the calculated values to parent
step 05: parent print the output.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipe1[2]; // Parent to Child
    int pipe2[2]; // Child to Parent

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0) {
        // Child Process
        close(pipe1[1]); // Close write end of pipe1
        close(pipe2[0]); // Close read end of pipe2

        int a, b;
        char op;

        // Read input from parent
        read(pipe1[0], &a, sizeof(int));
        read(pipe1[0], &b, sizeof(int));
        read(pipe1[0], &op, sizeof(char));

        int result;
        switch (op) {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/': result = (b != 0) ? a / b : 0; break;
            default: result = 0;
        }

        // Send result to parent
        write(pipe2[1], &result, sizeof(int));

        close(pipe1[0]);
        close(pipe2[1]);
    }
    else {
        // Parent Process
        close(pipe1[0]); // Close read end of pipe1
        close(pipe2[1]); // Close write end of pipe2

        int a, b;
        char op;

        // Get input from user
        printf("Enter first number: ");
        scanf("%d", &a);
        printf("Enter second number: ");
        scanf("%d", &b);
        printf("Enter operator (+, -, *, /): ");
        scanf(" %c", &op); // space before %c to ignore newline

        // Send inputs to child
        write(pipe1[1], &a, sizeof(int));
        write(pipe1[1], &b, sizeof(int));
        write(pipe1[1], &op, sizeof(char));

        // Read result from child
        int result;
        read(pipe2[0], &result, sizeof(int));

        printf("Result from child process: %d %c %d = %d\n", a, op, b, result);

        close(pipe1[1]);
        close(pipe2[0]);
    }

    return 0;
}


***************************************************************************************************

[maheshi@DESKTOP-0PPO6FJ ~]$ vi hw.c
[maheshi@DESKTOP-0PPO6FJ ~]$ gcc hw.c -o hw
[maheshi@DESKTOP-0PPO6FJ ~]$ ./hw
Enter first number: 5
Enter second number: 8
Enter operator (+, -, *, /): +
Result from child process: 5 + 8 = 13
[maheshi@DESKTOP-0PPO6FJ ~]$