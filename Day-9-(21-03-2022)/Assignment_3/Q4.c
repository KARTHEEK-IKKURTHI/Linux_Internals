//	Write a program where pthread task displays the thread id and also prints the calling process pid.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/types.h>
#include<string.h>

pthread_t t1;
void* threadFunc(void *arg){	
	pid_t pid;
	pthread_t t1;
	pid = getpid();
	t1=pthread_self();
	printf("Parent ID =%u , Thread_ID=%u \n",(unsigned int )pid,(unsigned int)t1);
	
	return 0;
	
}

int main(void){
	int s;
	
	s=pthread_create(&t1,NULL,threadFunc,NULL);
	pthread_join(t1,NULL);
	if(s != 0)
	printf("Can't create thread\n");
	while(1)
	
	exit(0);
	
}
	
	
