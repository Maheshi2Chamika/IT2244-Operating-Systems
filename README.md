# IT2244-Operating-Systems
![02](https://github.com/user-attachments/assets/3c64c121-44bb-4110-a76b-c9b3288d4498)
![01](https://github.com/user-attachments/assets/d8233047-68fb-48c0-b679-82628a9b3796)

# Inter-Process Communication Using Pipes in C

## Overview
This project contains two programs demonstrating **inter-process communication (IPC)** in C using unnamed pipes and the `fork()` system call:
1. Message Transfer Using Pipe with Parent-Child
2. Area Calculation Based on User Input and Shape Selection

---

## 1. Pipe Message Transfer (Basic IPC)

### File
`new.c`

### Description
- The parent process writes three predefined messages to a pipe.
- The child process reads them using `read()` and prints each message.
- Uses `fork()` and `pipe()` for IPC.

### Compilation
```bash
gcc new.c -o new
