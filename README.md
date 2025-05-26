# IT2244-Operating-Systems
![02](https://github.com/user-attachments/assets/feeec379-3b1c-4848-b4dd-acb71c6a50da)
![01](https://github.com/user-attachments/assets/e3e7521b-95e5-4080-a99a-6a958f0620ba)

# Process Management Programs in C - README

---

## Program 1: Sleep and Exit

**Description:**  
A simple program that prints messages, sleeps for 3 seconds, then exits cleanly.

**Usage:**  
- Compile: `gcc day.c -o day`  
- Run: `./day`

**Purpose:**  
Demonstrates the use of `sleep()` and `exit()` functions in a simple C program.

---

## Program 2: Fork, Wait, and Exit Status

**Description:**  
A parent process creates one child process. The child sleeps for 2 seconds and exits with status 0. The parent waits for the child and prints the exit status.

**Usage:**  
- Compile: `gcc day.c -o day`  
- Run: `./day`

**Purpose:**  
Shows process creation with `fork()`, waiting for child termination using `wait()`, and retrieving the exit status with macros.

---

## Program 3: Two Children, Parent Waits

**Description:**  
The parent creates two child processes:  
- First child sleeps 1 second and exits with status 0.  
- Second child sleeps 3 seconds and exits with status 0.  
Parent waits for both and prints their exit statuses.

**Usage:**  
- Compile: `gcc day.c -o day`  
- Run: `./day`

**Purpose:**  
Demonstrates handling multiple child processes, multiple `wait()` calls, and process synchronization.

---

## Program 4: Two Children with Different Exit Statuses and Waitpid

**Description:**  
The parent creates two children:  
- First child sleeps 2 seconds and exits with status 2.  
- Second child sleeps 1 second and exits with status 1.  
The parent waits for both children using `waitpid()` and prints which finished first and their exit statuses.

**Usage:**  
- Compile: `gcc day.c -o day`  
- Run: `./day`

**Purpose:**  
Illustrates `waitpid()` usage and managing children with different exit statuses and completion order.

---

## Program 5: Child and Grandchild Processes

**Description:**  
- Parent creates a child process.  
- Child creates a grandchild process.  
- Grandchild sleeps 2 seconds and exits with status 2.  
- Child waits for grandchild, prints exit status, then exits with status 55.  
- Parent waits for child and prints exit status.

**Usage:**  
- Compile: `gcc day.c -o day`  
- Run: `./day`

**Purpose:**  
Demonstrates process hierarchy with child and grandchild, and waiting for nested child processes.

---


##
Use fork() to create child processes.

Use sleep() to pause execution for demonstration.

Use wait() or waitpid() to wait for child termination.

Use macros like WIFEXITED() and WEXITSTATUS() to inspect child exit status.

Properly handle errors after fork() by checking the return value.
