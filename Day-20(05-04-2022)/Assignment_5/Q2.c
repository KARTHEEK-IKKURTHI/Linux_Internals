//write a program that uses msgctl() and prints number of messages,number of bytes in message queue and also get Maximum number of bytes in queue for already existing message queue and also remove message queue at the end.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <string.h>

struct msq{
	long ptype;
	char buffer[100];
};
int main(){
	int id;
	struct msq m;
	struct msqid_ds buf;
	id=msgget(32,IPC_CREAT|0644);
	printf("Id of the Message Queue = %d\n",id);
	m.ptype=10;
	strcpy(m.buffer,"Hi how are You");
	int j =msgsnd(id,&m,strlen(m.buffer)+1,0);
	msgctl(id,IPC_STAT,&buf);
	printf("Specifications of the Queue is as follows: \n");
	printf("No of Messages in Queue are : %lu\n",buf.msg_qnum);
	printf("No of Bytes in the Queue are : %lu\n",buf.msg_cbytes);
	printf("Maximum Number of Bytes in Queue are : %lu \n",buf.msg_qbytes);
	msgctl(id,IPC_RMID,&buf);
	printf("The Queue is Cleared And Removed \n");
	
	return 0;
}
