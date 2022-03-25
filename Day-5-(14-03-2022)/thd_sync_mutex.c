//Program to demonstrate the mutex lock //

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int sharedVal=2;//  Shared Variable

pthread_mutex_t my_mutex;		//Create the Mutex Lock

void *thread_inc(void *arg)
	{
		pthread_mutex_lock(&my_mutex);//Lock Mutex
		sharedVal++;//Critical Section
		pthread_mutex_unlock(&my_mutex);//Release Mutex
		printf("After inc=%d\n",sharedVal);
		
}

void *thread_dec(void *arg){	
			pthread_mutex_lock(&my_mutex);  	//Lock Mutex
			sharedVal--;		//Critical Section
			pthread_mutex_unlock(&my_mutex);	//Release Mutex
			printf("After dec =%d\n",sharedVal);
			
}

int main(){
	pthread_t thread1,thread2;
	
	pthread_mutex_init(&my_mutex,NULL);	//Initialize Mutex lock.
	
	
	pthread_create(&thread1,NULL,thread_inc,NULL);//thread for inc, the shared variable
	pthread_create(&thread2,NULL,thread_dec,NULL);//thread for dec, the shared variable
	
	
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	
	
	printf("sharedVal =%d \n",sharedVal);
	
	return 0;
	
}
			
