
//	This program illustrates the case of Shared Memory in the use case of writer.

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>

int main(){
	char *p;
	int id;
	
	id = shmget(48,250,IPC_CREAT|0644);	//KS
	
		if(id<0){
			perror("Shmget");
			return 0;
			
		}
		
		printf("id =%d \n",id);
		p = shmat(id,0,0);	//PAS----UserSpace
		
		printf("Enter the Data: ");
		scanf("%s",p);
		return 0;
}
	
