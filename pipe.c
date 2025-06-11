#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MSGSIZE 16
char* msg1 = "hello, world #1";
char* msg2 = "hello, world #2";
char* msg3 = "hello, world #3";

int main()
{
	char inbuf[MSGSIZE];
	int p[2], i;
	
	if(pipe(p) < 0)
		exit(1);
	
	/* continued */
	/* write pipe */
	
	write(p[1],msg1, MSGSIZE);  //write(filedes,message,message size)
	write(p[1],msg2, MSGSIZE);
	write(p[1],msg3, MSGSIZE);
	
	for(i=0; i<3; i++)
	{
		/* read pipe */
		read(p[0], inbuf, MSGSIZE); 
		printf("%s\n", inbuf);
	}
	return 0;
}
 
*************************************************************************** 
Answer:
[maheshi@DESKTOP-0PPO6FJ ~]$ vi pipe.c
[maheshi@DESKTOP-0PPO6FJ ~]$ gcc pipe.c -o pipe
[maheshi@DESKTOP-0PPO6FJ ~]$ ./pipe
hello, world #1
hello, world #2
hello, world #3
[maheshi@DESKTOP-0PPO6FJ ~]$







Exercise

1.Read two input from user (//parent process)
	name:
	reg no:
	age:

2.Print the output from the child (//child process)

	name:abc
	reg no:2021/ict/01
	age:25


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MSGSIZE 100

int main() {
    int p[2];
    pid_t pid;
    char buffer[MSGSIZE];

    // Create pipe
    if (pipe(p) == -1) {
        perror("Pipe creation failed");
        exit(1);
    }

    pid = fork(); // Create child process

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid > 0) { // Parent process
        close(p[0]); // Close read end of pipe

        char name[30], reg_no[30], age[10];

        // Getting input from the user
        printf("Enter name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0'; // Remove newline character

        printf("Enter reg no: ");
        fgets(reg_no, sizeof(reg_no), stdin);
        reg_no[strcspn(reg_no, "\n")] = '\0';

        printf("Enter age: ");
        fgets(age, sizeof(age), stdin);
        age[strcspn(age, "\n")] = '\0';

        // Prepare message
        snprintf(buffer, sizeof(buffer), "Name: %s\nReg No: %s\nAge: %s", name, reg_no, age);
        
        // Write to pipe
        write(p[1], buffer, strlen(buffer) + 1);
        close(p[1]); // Close write end after writing
    } 
	else 
	{ // Child process
        close(p[1]); // Close write end of pipe

        // Read from pipe
        read(p[0], buffer, MSGSIZE);
        printf("\nOutput from child process:\n%s\n", buffer);
        close(p[0]); // Close read end after reading
    }

    return 0;
}


*************************************************************************** 
Answer:

[maheshi@DESKTOP-0PPO6FJ ~]$ vi pipe_ex.c
[maheshi@DESKTOP-0PPO6FJ ~]$ gcc pipe_ex.c -o pipe_ex
[maheshi@DESKTOP-0PPO6FJ ~]$ ./pipe_ex
Enter name: abc
Enter reg no: 2021/ict/01
Enter age: 25

Output from child process:
Name: abc
Reg No: 2021/ict/01
Age: 25
[maheshi@DESKTOP-0PPO6FJ ~]$





















