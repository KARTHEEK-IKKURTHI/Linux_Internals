#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

static void* threadFunc(void *arg){	
	char *c=(char *) arg;
	printf("%s\n",c);
	
	return 0;
	
}

int main(int argc,char *argv[]){
	pthread_t t1;
	void *res;
	int s;
	
	s=pthread_create(&t1,NULL,threadFunc,"Hello ");
	
	printf("Message from main\n");
	
	sleep(1);
	exit (0);
	
}
	
