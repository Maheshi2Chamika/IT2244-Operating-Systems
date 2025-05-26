#include <stdio.h>
#include <stdlib.h>            //for exit()
#include <unistd.h>           //for sleep()

int main(){
	
	printf("Program started.\n");
	
	printf("Sleeping for three seconds...\n");
	sleep(3);                 //pause for three seconds
	
	printf("Exiting the program.\n");
	exit(0);                 //clean exit

}

*******************************************************************
[maheshi@DESKTOP-0PPO6FJ ~]$ vi day.c
[maheshi@DESKTOP-0PPO6FJ ~]$ gcc day.c -o day
[maheshi@DESKTOP-0PPO6FJ ~]$ ./day
Program started.
Sleeping for three seconds...
Exiting the program.
[maheshi@DESKTOP-0PPO6FJ ~]$












#include <stdio.h>
#include <stdlib.h>      //for exit() 
#include <unistd.h>      //for sleep()
#include <sys/wait.h>    //for wait()

int main()
{
	pid_t pid;
	
	printf("Parent process started.PID: %d\n", getpid());
	
	pid = fork();        //Create a new child process
	
	if(pid < 0)
	{
		perror("fork failed");
		exit(1);
	}
	
	if(pid == 0)
	{
		//child process
		printf("Child process. PID: %d,sleeping for 2 seconds...\n", getpid());
		sleep(2);
		printf("Child process exiting.\n");
		exit(0);         //child exits eith status 0
	}
	else
	{
		//parent process
		int status;
		printf("Parent waiting for child to finish...\n");
		wait(&status);   //wait for child to finish
		if(WIFEXITED(status))
		{
			printf("Child exited with status: %d\n", WEXITSTATUS(status));
			// WEXITSTATUS(status) gets the actual exit code (0 here).
		}
		else
		{
			printf("Child did not exit normally.\n");
		}
		printf("Parent process ending.\n");
	}
	return 0;
}


*******************************************************************
[maheshi@DESKTOP-0PPO6FJ ~]$ vi day.c
[maheshi@DESKTOP-0PPO6FJ ~]$ gcc day.c -o day
[maheshi@DESKTOP-0PPO6FJ ~]$ ./day
Parent process started.PID: 54
Parent waiting for child to finish...
Child process. PID: 55,sleeping for 2 seconds...
Child process exiting.
Child exited with status: 0                //Status is 0 means succussfully terminated
Parent process ending.
[maheshi@DESKTOP-0PPO6FJ ~]$






/*
Exercise:
First child : slept for 1 second
Second child : slept for 3 seconds
Parent : Both children have finished
*/

#include <stdio.h>
#include <stdlib.h>      // for exit() 
#include <unistd.h>      // for sleep()
#include <sys/wait.h>    // for wait()

int main() {
    pid_t first_child, second_child;

    printf("Parent process started. PID: %d\n", getpid());

    first_child = fork(); // Create first child

    if (first_child == 0) 
	{
        // First child process
        printf("First child process. PID: %d, sleeping for 1 second...\n", getpid());
        sleep(1);
        printf("First child exiting.\n");
        exit(0);
    } 
	else 
	{
        second_child = fork(); // Create second child
		
        if (second_child == 0) 
		{
            // Second child process
            printf("Second child process. PID: %d, sleeping for 3 seconds...\n", getpid());
            sleep(3);
            printf("Second child exiting.\n");
            exit(0);
        } 
		else 
		{
            // Parent process
            int status;
            printf("Parent waiting for children to finish...\n");

            wait(&status); // Wait for first child
            if (WIFEXITED(status)) 
			{
                printf("First child exited with status: %d\n", WEXITSTATUS(status));
            }

            wait(&status); // Wait for second child
            if (WIFEXITED(status)) 
			{
                printf("Second child exited with status: %d\n", WEXITSTATUS(status));
            }

            printf("Parent process ending.\n");
        }
    }
    return 0;
}

************************************************************************************************


[maheshi@DESKTOP-0PPO6FJ ~]$ vi day.c
[maheshi@DESKTOP-0PPO6FJ ~]$ gcc day.c -o day
[maheshi@DESKTOP-0PPO6FJ ~]$ ./day
Parent process started. PID: 62
First child process. PID: 63, sleeping for 1 second...
Parent waiting for children to finish...
Second child process. PID: 64, sleeping for 3 seconds...
First child exiting.
First child exited with status: 0
Second child exiting.
Second child exited with status: 0
Parent process ending.
[maheshi@DESKTOP-0PPO6FJ ~]$





/*
Exercise 02: 
First child: sleeps for 2 seconds, exit with status 2.
Second child: sleeps for 1 second, exit with status 1.
Parent : waits twice , and prints which child (by PID or exit code)
finished first and second
*/

#include <stdio.h>
#include <stdlib.h>   // For exit()
#include <unistd.h>   // For sleep(), fork()
#include <sys/wait.h> // For waitpid()

int main() {
    pid_t pid1, pid2;
    int status;

    printf("Parent process started. PID: %d\n", getpid());

    // Create first child process
    pid1 = fork();
    if (pid1 < 0) {
        perror("First fork failed");
        exit(1);
    }

    if (pid1 == 0) {
        // First child
        printf("First child process (PID: %d), Sleeping for 2 seconds...\n", getpid());
        sleep(2);
        printf("First child process exiting with status 2.\n");
        exit(2);
    }

    // Create second child process
    pid2 = fork();
    if (pid2 < 0) {
        perror("Second fork failed");
        exit(1);
    }

    if (pid2 == 0) {
        // Second child
        printf("Second child process (PID: %d), Sleeping for 1 second...\n", getpid());
        sleep(1);
        printf("Second child process exiting with status 1.\n");
        exit(1);
    }

    // Parent process waits twice
    pid_t first_finished = waitpid(-1, &status, 0);
    printf("Child with PID %d finished first with exit status: %d\n", first_finished, WEXITSTATUS(status));

    pid_t second_finished = waitpid(-1, &status, 0);
    printf("Child with PID %d finished second with exit status: %d\n", second_finished, WEXITSTATUS(status));

    printf("Both children have finished. Parent process ending.\n");

    return 0;
}

************************************************************************************************

[maheshi@DESKTOP-0PPO6FJ ~]$ vi day.c
[maheshi@DESKTOP-0PPO6FJ ~]$ gcc day.c -o day
[maheshi@DESKTOP-0PPO6FJ ~]$ ./day
Parent process started. PID: 71
First child process (PID: 72), Sleeping for 2 seconds...
Second child process (PID: 73), Sleeping for 1 second...
Second child process exiting with status 1.
Child with PID 73 finished first with exit status: 1
First child process exiting with status 2.
Child with PID 72 finished second with exit status: 2
Both children have finished. Parent process ending.
[maheshi@DESKTOP-0PPO6FJ ~]$



/*
Exercise 03:
The parent creates a child  process.
The child creates a grandchild process.
The grandchild sleeps 2 seconds and exits with status 2.
The child waits for the grandchild, prints its exit status,
then exits with status 55.
*/

#include <stdio.h>
#include <stdlib.h>   // For exit()
#include <unistd.h>   // For sleep(), fork()
#include <sys/wait.h> // For waitpid()

int main() {
    pid_t child_pid, grandchild_pid;
    int status;

    printf("Parent process started. PID: %d\n", getpid());

    // Parent creates a child process
    child_pid = fork();
    if (child_pid < 0) {
        perror("Fork failed for child");
        exit(1);
    }

    if (child_pid == 0) { 
        // Child process
        printf("Child process started. PID: %d\n", getpid());

        // Child creates grandchild process
        grandchild_pid = fork();
        if (grandchild_pid < 0) {
            perror("Fork failed for grandchild");
            exit(1);
        }

        if (grandchild_pid == 0) {
            // Grandchild process
            printf("Grandchild process started. PID: %d, Sleeping for 2 seconds...\n", getpid());
            sleep(2);
            printf("Grandchild exiting with status 2.\n");
            exit(2);
        }

        // Child process waits for grandchild
        waitpid(grandchild_pid, &status, 0);
        printf("Child detected grandchild exited with status: %d\n", WEXITSTATUS(status));
        
        // Child process exits with status 55
        printf("Child exiting with status 55.\n");
        exit(55);
    }

    // Parent process waits for child
    waitpid(child_pid, &status, 0);
    printf("Parent detected child exited with status: %d\n", WEXITSTATUS(status));

    printf("Parent process ending.\n");
    return 0;
}

************************************************************************************************

[maheshi@DESKTOP-0PPO6FJ ~]$ vi day.c
[maheshi@DESKTOP-0PPO6FJ ~]$ gcc day.c -o day
[maheshi@DESKTOP-0PPO6FJ ~]$ ./day
Parent process started. PID: 80
Child process started. PID: 81
Grandchild process started. PID: 82, Sleeping for 2 seconds...
Grandchild exiting with status 2.
Child detected grandchild exited with status: 2
Child exiting with status 55.
Parent detected child exited with status: 55
Parent process ending.
[maheshi@DESKTOP-0PPO6FJ ~]$































