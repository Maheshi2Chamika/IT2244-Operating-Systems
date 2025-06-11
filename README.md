# IT2244-Operating-Systems
![03](https://github.com/user-attachments/assets/055d3ce6-4b64-40a1-b590-df9bafcc7b51)
![02](https://github.com/user-attachments/assets/2eeaa8cf-a70a-4765-a537-1e60eb4fb229)
![01](https://github.com/user-attachments/assets/260ca597-4a99-41ef-bd8e-a21e9b4cd4d3)

# Inter-Process Communication Using Pipes in C

## Overview
This project demonstrates **communication between processes using unnamed pipes** in C. Two examples are provided:
1. A simple write/read pipe demonstration.
2. A parent-child program where user input from the parent is read and printed by the child.

---

## 1. Basic Pipe Example

### File
pipe.c

### Description
This program writes three predefined messages to a pipe and then reads them back.

### Compilation
gcc pipe.c -o pipe

### Execution
./pipe

### Example Output
hello, world #1  
hello, world #2  
hello, world #3  

### Purpose
- Demonstrates simple use of `pipe()`, `write()`, and `read()` system calls.
- Shows how multiple messages can be passed through a pipe and read sequentially.

---

## 2. Parent-Child Input Pipe Example

### File
pipe_ex.c

### Description
The **parent process** collects user input (name, registration number, and age) and sends it through a pipe.  
The **child process** receives and displays the data.

### Compilation
gcc pipe_ex.c -o pipe_ex

### Execution
./pipe_ex

### Example Input & Output
