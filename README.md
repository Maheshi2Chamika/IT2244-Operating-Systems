# IT2244-Operating-Systems
![02](https://github.com/user-attachments/assets/af3dba18-d7f9-4b5e-a890-382dfecdb36a)
![01](https://github.com/user-attachments/assets/d0eeef1d-e84d-4c4b-962d-26a5b4037d36)

## Commands & Examples

1. Basic Fork with PID Output
   - **Description**: Demonstrates how `fork()` works by printing process IDs.
   - **Usage**:
     - gcc child.c -o child
     - ./child
   - **Purpose**: Understand how `fork()` creates a child process and how both parent and child run the same code after the fork.

2. Fork with Identified Parent and Child Messages
   - **Description**: Differentiates between parent and child by printing custom messages along with PIDs.
   - **Usage**:
     - gcc child.c -o child
     - ./child
   - **Purpose**: Shows how to identify child and parent processes using `fork()` and `getpid()`.

3. Fork with Conditional Output
   - **Description**: Uses `if(f == 0)` to explicitly separate the output of child and parent processes.
   - **Usage**:
     - gcc child.c -o child
     - ./child
   - **Purpose**: Demonstrates conditional branching after a fork to execute different logic in child vs. parent.

4. Nested Forks: Parent, Child, and Sibling
   - **Description**: Creates a nested fork structure to simulate a parent creating a child, which then creates a sibling.
   - **Usage**:
     - gcc child.c -o child
     - ./child
   - **Purpose**: Understand nested process creation and observe how each fork leads to a new process.

5. Fork with Parent ID using `getppid()`
   - **Description**: Uses `getppid()` to print the parent process ID from both child and sibling processes.
   - **Usage**:
     - gcc child.c -o child
     - ./child
   - **Purpose**: Demonstrates inter-process relationship tracking through `getppid()` to identify the true parent process.
