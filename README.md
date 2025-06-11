# IT2244-Operating-Systems
![02](https://github.com/user-attachments/assets/4a554c92-c8b3-401c-8abd-00d54f82c0ea)
![01](https://github.com/user-attachments/assets/b461b601-f20d-4649-9ecc-cf15fca2de85)

# Shared Memory Communication (Writer & Reader)

## Overview
This project demonstrates Inter-Process Communication (IPC) using shared memory in C on a Linux system. It includes two separate processes:
- A Writer process that writes data into shared memory.
- A Reader process that reads and displays the data from shared memory.

## Files
- write.c – Program to write user input to shared memory.
- read.c – Program to read the content from shared memory and display it.

## Compilation
gcc write.c -o write  
gcc read.c -o read

## Usage

1. Run the Writer:
   ./write  
   - Input: Enter the text you want to write into shared memory.  
   - Output: Displays the written data.  
   Example:  
   Write Data: Hello  
   Data written in memory: Hello  

2. Run the Reader:
   ./read  
   - Output: Reads and prints the content from shared memory.  
   Example:  
   Data read from memory: Hello  

## Purpose
- Demonstrates how two processes can communicate using shared memory.
- Shows creation, attachment, reading/writing, and cleanup of shared memory.

## Notes
- Uses ftok() to generate a unique key based on the file "shmfile".
- The shared memory segment is created by the writer and removed by the reader after reading.





# Shared Memory Using mmap() (Parent & Child Communication)

## Overview
This program demonstrates Inter-Process Communication (IPC) between a parent and a child process using **anonymous shared memory** with the `mmap()` system call in C.

## File
- share.c – Program that creates a shared memory region, writes to it in the child process, and reads from it in the parent process.

## Compilation
gcc share.c -o share

## Usage
./share

### Output Example
Child wrote: Hello from child!  
Parent read: Hello from child!

## Purpose
- Demonstrates how parent and child processes can communicate using **memory-mapped anonymous shared memory**.
- Uses `fork()` to create a child process and `mmap()` for shared memory.
- Child writes a message to the shared memory, and the parent reads it after the child exits.

## Notes
- `mmap()` is called with `MAP_SHARED | MAP_ANONYMOUS`, allowing shared memory without a file.
- `wait(NULL)` ensures the parent reads the memory only after the child writes.
- `munmap()` is used by the parent to clean up the shared memory after reading.
