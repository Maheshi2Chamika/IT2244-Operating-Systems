//send

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 10
// structure for message queue
struct mesg_buffer{
	long mesg_type;
	char mesg_text[100];
}message;
int main()
{
	key_t key;
	int msgid;
	// ftok to generate unique keykey = fork
	key = ftok("progfile", 65);
	// msgget creates a message queue
	// and returns identifier
	msgid = msgget(key, 0666 | IPC_CREAT);
	message.mesg_type = 1;
	printf("Write Data: ");
	fgets(message.mesg_text,MAX,stdin);
	// msgsend to send message
	msgsnd(msgid, &message, sizeof(message), 0);
	//display the message
	printf("Data send is : %s \n", message.mesg_text);
	return 0;
}

**********************************************************************

[maheshi@DESKTOP-0PPO6FJ ~]$ vi msg.c
[maheshi@DESKTOP-0PPO6FJ ~]$ gcc msg.c -o msg
[maheshi@DESKTOP-0PPO6FJ ~]$ ./msg
Write Data: Hi Mashi
Data send is : Hi Mashi

[maheshi@DESKTOP-0PPO6FJ ~]$







//receive
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
// structure for message queue
struct mesg_buffer{
	long mesg_type;
	char mesg_text[100];
}message;
int main()
{
	key_t key;
	int msgid;
	// ftok to generate unique keykey = fork
	key = ftok("progfile", 65);
	// msgget creates a message queue
	// and returns identifier
	msgid = msgget(key, 0666 | IPC_CREAT);
	// msgcrv to receive message
	msgrcv(msgid, &message, sizeof(message), 1, 0);
	//display the message
	printf("Data Received is : %s \n", message.mesg_text);
	//to destroy the message queue
	msgctl(msgid, IPC_RMID, NULL);
	return 0;
}	
	
**********************************************************************	
	
[maheshi@DESKTOP-0PPO6FJ ~]$ vi recmsg.c
[maheshi@DESKTOP-0PPO6FJ ~]$ gcc recmsg.c -o recmsg
[maheshi@DESKTOP-0PPO6FJ ~]$ ./recmsg
Data Received is : Hi Mashi

[maheshi@DESKTOP-0PPO6FJ ~]$