#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MSGSIZE 16

char* msg1 = "hello, world #1";
char* msg2 = "hello, world #2";
char* msg3 = "hello, world #3";

int main()
{
	char inbuf[MSGSIZE];
	int p[2], pid, nbytes;
	
	if(pipe(p) < 0)
		exit(1);
	
	/* Continued */
	
	if((pid = fork()) > 0)
	{
		write(p[1], msg1, MSGSIZE);
		write(p[1], msg2, MSGSIZE);
		write(p[1], msg3, MSGSIZE);
		
		wait(NULL);
		
		//Adding this line will
		//not hang the program
		//close(p[1]);
	}
	else
	{
		while((nbytes = read(p[0], inbuf, MSGSIZE)) > 0)
			printf("%s\n", inbuf);
		if(nbytes != 0)
			exit(2);
		printf("Finished reading\n");
	}
	return 0;
}

*********************************************************************

[maheshi@DESKTOP-0PPO6FJ ~]$ vi new.c
[maheshi@DESKTOP-0PPO6FJ ~]$ gcc new.c -o new
[maheshi@DESKTOP-0PPO6FJ ~]$ ./new
hello, world #1
hello, world #2
hello, world #3





Exercise
Area calculation program

Circle => C
Triangle => T
Square = S
Rectangle => R

Enter your choice : C

Circle area calculation

Enter the radius: 20.9
Area is :1371.58



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define PI 3.14159

int main() {
    int p[2]; // Pipe file descriptors
    char choice;
    float values[2], area;

    if (pipe(p) < 0) {
        perror("Pipe creation failed");
        exit(1);
    }

    if (fork() > 0) {  // Parent Process
        close(p[0]); // Close read end

        printf("Choose shape: Circle (C), Triangle (T), Square (S), Rectangle (R): ");
        scanf(" %c", &choice);
        write(p[1], &choice, sizeof(choice));

        switch (choice) {
            case 'C':
                printf("Enter radius: ");
                scanf("%f", &values[0]);
                break;
            case 'T':
                printf("Enter base and height: ");
                scanf("%f %f", &values[0], &values[1]);
                break;
            case 'S':
                printf("Enter side length: ");
                scanf("%f", &values[0]);
                break;
            case 'R':
                printf("Enter length and width: ");
                scanf("%f %f", &values[0], &values[1]);
                break;
            default:
                printf("Invalid choice.\n");
                exit(1);
        }

        write(p[1], values, sizeof(values));
        close(p[1]); // Close write end
        wait(NULL); // Wait for child process

    } else {  // Child Process
        close(p[1]); // Close write end
        read(p[0], &choice, sizeof(choice));
        read(p[0], values, sizeof(values));

        switch (choice) {
            case 'C':
                area = PI * values[0] * values[0];
                break;
            case 'T':
                area = 0.5 * values[0] * values[1];
                break;
            case 'S':
                area = values[0] * values[0];
                break;
            case 'R':
                area = values[0] * values[1];
                break;
            default:
                printf("Invalid shape selection.\n");
                exit(1);
        }

        printf("Calculated Area: %.2f\n", area);
        close(p[0]); // Close read end
        exit(0);
    }

    return 0;
}

**************************************************************************

[maheshi@DESKTOP-0PPO6FJ ~]$ vi cal.c
[maheshi@DESKTOP-0PPO6FJ ~]$ gcc cal.c -o cal
[maheshi@DESKTOP-0PPO6FJ ~]$ ./cal
Choose shape: Circle (C), Triangle (T), Square (S), Rectangle (R): C
Enter radius: 10
Calculated Area: 314.16
[maheshi@DESKTOP-0PPO6FJ ~]$


























