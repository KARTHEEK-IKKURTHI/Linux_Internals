#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/types.h>


void *process(void *arg)
{
	pthread_detach(pthread_self());		//Detach self
	
	
	printf("Sleeping 2 sec\n");
	
	
	//Process a client process
	
	
	
	sleep(2);
	
	printf("Sleep 2 sec \n");
	
	
}


int main(){
	pthread_t t_id;
	
	int errno=pthread_create(&t_id,NULL,process,NULL);
	if(errno)
	perror("pthread_create:");
	
	
	
	pthread_exit(NULL);
	
	return 0;
	
}
