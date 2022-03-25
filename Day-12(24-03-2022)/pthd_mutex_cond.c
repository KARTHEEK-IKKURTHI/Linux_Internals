
//	The program illustrates the PTHREAD CONDITION VARIABLE

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>


//Declaration of thread condition variable 
pthread_cond_t cond1=PTHREAD_COND_INITIALIZER;

//Declaring mutex

pthread_mutex_t lock =PTHREAD_MUTEX_INITIALIZER;


int done =1;

//THread Function

void*  foo(void *arg){
	char *str=(char*)arg;
	printf("Thread task called by =%s \n",str);
	
//Acquire A Lock
	pthread_mutex_lock(&lock);
	
	if(done==1){	
		//Let's wasit on condition variable cond1
		//done =2
		printf("Waiting on condition variable cond1 \n");
		pthread_cond_wait(&cond1, &lock);
		
	}
	
	else{
		//Let's signal condition variable cond1
		printf("Signaling condition variable cond1 \n");
		pthread_cond_signal(&cond1);
		}
	//Release the Lock
	
	pthread_mutex_unlock(&lock);
	printf("Returning thread \n");
	
	return NULL;
	
}

//Driver Code

int main(){	
	pthread_t tid1,tid2;
	//Create thread 1
	pthread_create(&tid1,NULL,foo,"THDone");
	
	
	//Sleep for 1sec so that thread 1
	//Would sleep get a chance to run first
	
	sleep(1);
	
	//lets's wait  on condition variable cond1
	
	done =2;
	
	//Create thread 2
	pthread_create(&tid2,NULL,foo,"THDtwo");
	
	//Wait for the completion of thread 2
	
	pthread_join(tid2,NULL);
	
	
	return 0;
	
	
}

