
//	This program illustrates the use of message queuing for the recieving type with the message control with the flag IPC_RMID

#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<stdlib.h>

//	While execution for example this source code has an executable named rx100. In terminal we will write ./rx100  1 .
//--->> The 1 in the argument is the message id, I want to recieve and also it show be tranmitted first.


struct msgbuff{
	long mtype;
	char data[512];
	
};

int main(int argc,char**argv){
	int id;
	struct msgbuff v;
	
	if(argc!=2){
		printf("Usage:./mq_rx type\n");
		printf("Example: mq_rx 5\n");
		return 0;
		
		}
	id+msgget(55,IPC_CREAT|0644);	//msgget(key,perm);
	
	if(id<0){
		perror("msgget");
		return 0;
		}
	msgrcv(id,&v,sizeof(v),atoi(argv[1]),0);// ./rx	44
	printf("Data %s\n",v.data);
	msgctl(id,IPC_RMID,&v);
	return 0;
	
}
	
