//Detaching:
//	The pthread_detach() routine can be used 


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/types.h>
#include<stdlib.h>

#define NUM_THREADS	6


int i=0;
void *myfun(void *null){
	i++;
	int result=1;
	result =result + i*1000;
	printf("Result =%d\n",result);
	
	pthread_exit(NULL);
}


int main(int agrc,char *argv[]){
	pthread_t thread[NUM_THREADS];
	pthread_attr_t attr;		//1....attr   obj creation
	
	int rc,t,status,detach_state;
	
	//Initialize and set thread detached attribute
	
	
	pthread_attr_init(&attr);	//initz attr obj
	
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);


	for(t=1;t<NUM_THREADS;t++)
	{
		printf("Creating Threads :%d \n",t);
		pthread_create(&thread[t],&attr,myfun,NULL);
		
	}
	
	printf("\n Exiting from main Thread ");
	pthread_exit(NULL);
}
