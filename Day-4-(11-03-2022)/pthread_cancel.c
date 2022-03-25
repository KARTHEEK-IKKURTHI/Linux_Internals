#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>


void *PrintHello(void *threadid){
	printf("\n Hello");
	
	while(1);
	
}
	
int main(){
	pthread_t thread;
	int n, t=0;
	printf("\n Creating Thread\n");
	
	n=pthread_create(&thread,NULL,PrintHello,NULL);
	printf("\n Thread I: %ld",thread);
	sleep(1);
	
	t=pthread_cancel(thread);
	
	if(t == 0)
	{
	 printf("\n Thread cancel\n");
	printf("\nThread II: %ld",thread);
	}
}
	
