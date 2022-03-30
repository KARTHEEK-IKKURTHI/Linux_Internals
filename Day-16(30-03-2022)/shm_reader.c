
//	This program illustrates the case of Shared Memory in the use case of reader.


#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>


int main(){
	char *r;
	int id;
	
	id = shmget(48,250,IPC_CREAT|0644);	//id =shmget(32,150,IPC_CREAT|0644);
	
		if(id<0){
			perror("Shmget");	//stderr device   pf()..........screen device
			return 0;
			
		}
		
		printf("id =%d \n",id);
		r = shmat(id,0,0);	//PAS----UserSpace
		
		printf("%s \n ",r);
		return 0;
}
