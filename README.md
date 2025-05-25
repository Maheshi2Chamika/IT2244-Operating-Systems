# IT2244-Operating-Systems
![01](https://github.com/user-attachments/assets/5446da11-58c9-425c-b3f6-c557f882588f)

# Fork-Based Number Printing and Summation – README
## Commands & Examples

### 1. Fork Program: Print Numbers 1 to 10 with Summation
- **Description**: This C program uses `fork()` to divide the task of printing numbers from 1 to 10 between a child and parent process. The child process prints numbers 1 to 5 and calculates their sum, while the parent process prints numbers 6 to 10 and calculates their sum.
- **Usage**:
  - gcc parent.c -o parent
  - ./parent
- **Purpose**: To demonstrate process creation using `fork()`, output interleaving between parent and child processes, and how each can independently compute and display results.

```c
#include <stdio.h>
#include <unistd.h>
int main() {

    int sum_child = 0, sum_parent = 0; 
    int f = fork();

    if (f == 0) { 
        printf("Child Process:\n");
        for (int i = 1; i <= 5; i++) {
            printf("%d\n", i);
            sum_child += i;
        }
        printf("Sum by child process: %d\n", sum_child);
    } else {
        printf("Parent Process:\n");
        for (int i = 6; i <= 10; i++) {
            printf("%d\n", i);
            sum_parent += i;
        }
        printf("Sum by parent process: %d\n", sum_parent);
    }

    return 0;
}

