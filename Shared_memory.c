//writer process 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024      //Size of shared memory segment

int main(){
	key_t key = ftok("shmfile", 65);    //Generate unique key
	int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);    //Create shared memory segment
	if(shmid == -1){
		perror("shmget");
		exit(1);
	}
	
	char *shmaddr = (char*) shmat(shmid,NULL, 0);   //Attach to shared memory
	if(shmaddr == (char*) -1){
		perror("shmat");
		exit(1);
	}
	
	printf("Write Data: ");
	fgets(shmaddr, SHM_SIZE, stdin);     //Write data to shared memory
	
	printf("Data written in memory: %s\n", shmaddr);
	
	shmdt(shmaddr);      //Detach from shared memory
	
	return 0;
}





//reader

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024      //Size of shared memory segment


int main(){
	key_t key = ftok("shmfile", 65);    //Generate unique key
	int shmid = shmget(key, SHM_SIZE, 0666);    //Create shared memory segment
	if(shmid == -1){
		perror("shmget");
		exit(1);
	}
	
	char *shmaddr = (char*) shmat(shmid,NULL, 0);   //Attach to shared memory
	if(shmaddr == (char*) -1){
		perror("shmat");
		exit(1);
	}
	
	printf("Data read from memory: %s\n", shmaddr);   //Read data from shared memory

	shmdt(shmaddr);      //Detach from shared memory
	
	shmctl(shmid, IPC_RMID, NULL);   //Remove shared memory segment
	
	return 0;
	
}


*************************************************************************************


[maheshi@DESKTOP-0PPO6FJ ~]$ vi write.c
[maheshi@DESKTOP-0PPO6FJ ~]$ gcc write.c -o write
[maheshi@DESKTOP-0PPO6FJ ~]$ vi read.c
[maheshi@DESKTOP-0PPO6FJ ~]$ gcc read.c -o read
[maheshi@DESKTOP-0PPO6FJ ~]$ ./write
Write Data: Hello
Data written in memory: Hello

[maheshi@DESKTOP-0PPO6FJ ~]$ ./read
Data read from memory: Hello

[maheshi@DESKTOP-0PPO6FJ ~]$



















