

//Write a program where a structure of information passed to pthread task function, and display  structure of information.                 

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/types.h>
#include<string.h>


struct my_name{
	int thread_id;
	char message[100];
};

void *PrintHello(void *threadop){
	pthread_t name_ID;
	struct my_name *t1;
	t1=(struct my_name *)threadop;
	name_ID=pthread_self();
	printf("\n Thread ID: %lu",name_ID);
	printf("\n %d Thread Message : %s\n ",t1->thread_id,t1->message);
	return NULL;
}
int main(){
	pthread_t thd2,thd3,name_ID;
	int tc;
	struct my_name t2,t3;
	t2.thread_id=1;
	strcpy(t2.message,"Good Morning\n");
	t3.thread_id=2;
	strcpy(t3.message,"Have a Nice Day \n");
	
	
	name_ID=pthread_self();
	printf("\n MAIN THREAD ID : %lu",name_ID);
	
	pthread_create(&thd2,NULL,PrintHello,(void *)&t2);
	pthread_create(&thd3,NULL,PrintHello,(void *)&t3);
	
	printf("\n Exit from MAIN THREAD");
	pthread_exit(NULL);
	
}
