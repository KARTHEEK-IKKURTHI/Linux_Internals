
//	This program illustrates the use of message queuing of transmitting type.

#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<stdlib.h>


//	While execution for example this source code has an executable named tx100. In terminal we will write ./tx100  1   Ok  .
//--->> The 1 in the argument is the message id and the next word is the message to be sent respectively.


struct msgbuf{
	long mtype;
	char data[512];
	
};

int main(int argc,char *argv[]){
	struct msgbuf v;
	int id;
	/*argc !=3){
		printf("Usage..... ./mq_tx msag_type data \n");
		printf("Example:mq_tx 5 \ "hello\" \n");
		return 0;
		
	}*/
	id =msgget(55,IPC_CREAT|0644);
	/* if(id<0){
		perror("msgget");// ./tx 12 linux\0
		return 0;
		
	}*/
	
	printf("id =%d \n",id);
	v.mtype=atoi(argv[1]);//"12"
	//Argument 1 is type of message converting ascii to int//
	strcpy(v.data,argv[2]);	//Argument 2 is message
	msgsnd(id,&v,strlen(v.data)+1,0);//Flag IPC_WAIT
	//perror("msgsnd");	//"./wrt" "type" "data"
	
	return 0;
	
}
