// ----------------------------Inter Process Communication(IPC)---------------------------


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 20
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
	key = ftok("2021ICT79", 79);                      // Path name & key value
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
	// ftok to generate unique key key = ftok
	key = ftok("2021ICT79", 79);                // Path name & key value
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
	
[maheshi@DESKTOP-0PPO6FJ ~]$ vi send.c
[maheshi@DESKTOP-0PPO6FJ ~]$ touch 2021ICT79
[maheshi@DESKTOP-0PPO6FJ ~]$ chmod 644 2021ICT79
[maheshi@DESKTOP-0PPO6FJ ~]$ gcc send.c -o send
[maheshi@DESKTOP-0PPO6FJ ~]$ vi receive.c
[maheshi@DESKTOP-0PPO6FJ ~]$ gcc receive.c -o receive
[maheshi@DESKTOP-0PPO6FJ ~]$ ./send
Write Data: Hello
Data send is : Hello

[maheshi@DESKTOP-0PPO6FJ ~]$ ./receive
Data Received is : Hello

[maheshi@DESKTOP-0PPO6FJ ~]$






