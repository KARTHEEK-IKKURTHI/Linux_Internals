//write a program that creates a shared memory region and displays shared memory id and also print address at which shared area in this process starts from.


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>


int main(){
	char *r;
	int id;
	
	id = shmget(32,150,IPC_CREAT|0644);
	printf("The ID of the Shared Memory is %d \n",id);
	
	r=(char *) shmat(id,0,0);
	
	printf("The Address at which the Shared Area is: %p \n",r);
	
	
	return 0;
	
}
	
