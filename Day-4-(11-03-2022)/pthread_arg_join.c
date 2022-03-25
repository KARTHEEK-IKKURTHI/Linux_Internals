#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>


static void* threadFunc(void *arg){	
	char *c=(char *) arg;
	printf("%s\n",c);
	sleep(3);
	return (void*) strlen(c);
	return 0;
	
}

int main(int argc,char *argv[]){
	pthread_t t1;
	void *res;
	int s;
	
	s=pthread_create(&t1,NULL,threadFunc,"Hello ");
	
	printf("Message from main\n");
	
	sleep(1);
	pthread_join(t1,&res);
	
	printf("Thread returned %ld \n",(long)res);
	exit (0);
	
}
	
