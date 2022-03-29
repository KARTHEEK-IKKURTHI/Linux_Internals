//	Write a program that implements threads synchronization using pthread spinlock techniques.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/types.h>

#pragma GCC diagnostic ignored "-Wformat"
static pthread_spinlock_t spinlock;
volatile int slock;



void *spinlockThread(void *i){
	int rc;
	int count=0;
	printf("Thread %d,is getting a Spin Lock \n",(int *)i);
	
	rc= pthread_spin_lock(&slock);
	
	
	
	printf("%d Thread is unlocking the spin lock\n",(int *)i);
	rc= pthread_spin_unlock(&slock);
	
	printf("%d Thread Execution Completed\n",(int *)i);
	
return NULL;
}

int main(){
	int rc=1;
	pthread_t thd,thd1;
	
	if(pthread_spin_init(&slock,PTHREAD_PROCESS_PRIVATE)!=0)
		perror("init");
	printf("Acquired  spin lock\n");
	rc=pthread_spin_lock(&slock);
	
	
	printf("Create the Spin Lock\n");
	rc=pthread_create(&thd,NULL,spinlockThread,(int *)1);
	
	printf("Wait a bit creating the spin lock\n");
	
	sleep(5);
	
	printf("Unlocked the Spin Lock\n");
	
	rc=pthread_spin_unlock(&slock);
	
	if(rc==1)
		printf("\n Thread Successfully unlocked\n");
		
	else
	
		printf("\n Thread Un-Successfully unlocked\n");
		
	printf("Wait for the thread to end\n");
	
	rc= pthread_join(thd,NULL);
	
	printf("Main Completed \n");
	
	return 0;
	
}
	
