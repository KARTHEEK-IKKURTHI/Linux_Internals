
//	Write a pthread application where main task terminated but pending pthreads task still execute. 
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>


void* thread1(void *arg){

	printf("Newly created thread is executing:\n");
	return NULL;
	}
void *PrintHello(void *threadid){
	printf("\n Hello");
	return NULL;
	}
int main(){
	int pc;
	pthread_t thd1,thd2;
	printf("Main Begins \n");
	int ret= pthread_create(&thd1, NULL,thread1,NULL);
	pc=pthread_create(&thd2,NULL,PrintHello,NULL);
	pthread_exit(NULL);
	printf("Main Ended \n");
	
	
	return 0;
}
