#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/types.h>


static pthread_spinlock_t spinlock;
volatile int slock;



void *spinlockThread(void *i){
	int rc;
	int count=0;
	printf("Entered Thread %d,getting Spin Lock \n",(int *)i);
	
	rc= pthread_spin_lock(&slock);
	
	
	
	printf("%d Thread unlock the spin lock\n",(int *)i);
	rc= pthread_spin_unlock(&slock);
	
	printf("%d thread complete\n",(int *)i);
	
return NULL;
}

int main(){
	int rc=1;
	pthread_t thread,thread1;
	
	if(pthread_spin_init(&slock,PTHREAD_PROCESS_PRIVATE)!=0)
		perror("init");
	printf("Main, get spin lock\n");
	rc=pthread_spin_lock(&slock);
	
	
	printf("Main, create the spin lock thread\n");
	rc=pthread_create(&thread,NULL,spinlockThread,(int *)1);
	
	printf("Main, wait a bit  building the spin lock\n");
	
	sleep(5);
	
	printf("Main, Now unlock the spin lock\n");
	
	rc=pthread_spin_unlock(&slock);
	
	if(rc==1)
		printf("\n Main Thread Successfully unlocked\n");
		
	else
	
		printf("\n Main Thread Un-Successfully unlocked\n");
		
	printf("Main, wait for the thread to end\n");
	
	rc= pthread_join(thread,NULL);
	
	printf("Main Completed \n");
	
	return 0;
	
}
	
