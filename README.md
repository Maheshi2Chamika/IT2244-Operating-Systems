# IT2244-Operating-Systems
![01](https://github.com/user-attachments/assets/c8ce2a4c-8508-420d-8c3c-5f8529571689)
![02](https://github.com/user-attachments/assets/cf758b6a-168f-4350-a6b1-b8e19c5c46b3)
IPC using Message Queue (IPCExercise.c)
--------------------------------------------------

🧠 Description
This C program demonstrates Inter-Process Communication (IPC) using System V message queues. The parent process collects user input (name, registration number, and age) and sends it to the child process via a message queue.

⚙️ Usage
1. Save the code in a file named `IPCExercise.c`
2. Compile the code using:
   gcc IPCExercise.c -o IPCExercise
3. Run the program:
   ./IPCExercise

📝 Input Example
Enter Name: Hi
Enter RegNo: 2314
Enter Age: 24

📤 Output Example
Message sent successfully.
Received Name: Hi
Received RegNo: 2314
Received Age: 24

🎯 Purpose
To illustrate how a parent process can send data to a child process using message queues in Linux. This is useful in scenarios requiring safe, structured communication between processes.
