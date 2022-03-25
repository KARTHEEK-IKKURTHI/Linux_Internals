#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>


pthread_t t1;
void* threadFunc(void *arg){	
	pid_t pid;
	pthread_t t1;
	pid = getpid();
	t1=pthread_self();
	printf("pid =%u , t1=%u \n",(unsigned int )pid,(unsigned int)t1);
	
	return 0;
	
}

int main(void){
	
	int s;
	
	s=pthread_create(&t1,NULL,threadFunc,NULL);
	if(s != 0)
	printf("Can't create thread\n",strerror(s));
	while(1)
	
	exit(0);
	
}
	
