//	This program illustrates the use of gathering details from the message queue


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>




int main(){
	int qid;
	struct msqid_ds buf;
	qid=msgget(32,IPC_CREAT|0644);
	printf("qid = %d\n",qid);
	msgctl(qid,IPC_STAT,&buf);
	printf("Here are the details of the queue \n");
	printf("No of msg's in q %hi\n",buf.msg_qnum);
	//printf("no of bytes in q %d\n",buf.msg_cbytes);
	printf("max no of bytes in q %hi \n",buf.msg_qbytes);//msg_qbytes
	
}
