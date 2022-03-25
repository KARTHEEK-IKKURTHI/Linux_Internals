//	Write a program that implements threads synchronization using mutex techniques.


#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int sharedVal=25;//  Shared Variable

pthread_mutex_t my_mutex;		//Create the Mutex Lock

void *thread_inc(void *arg)
	{
		printf("Mutex Lock \n");
		pthread_mutex_lock(&my_mutex);//Lock Mutex
		sharedVal++;//Critical Section
		printf("Mutex Un-Lock \n");
		pthread_mutex_unlock(&my_mutex);//Release Mutex
		printf("After Increment=%d\n",sharedVal);
		
}

void *thread_dec(void *arg){	
			printf("Mutex Lock \n");
			pthread_mutex_lock(&my_mutex);  	//Lock Mutex
			sharedVal--;		//Critical Section
			printf("Mutex Un-Lock \n");
			pthread_mutex_unlock(&my_mutex);	//Release Mutex
			printf("After Decrement =%d\n",sharedVal);
			
}

int main(){
	pthread_t thread1,thread2;
	
	pthread_mutex_init(&my_mutex,NULL);	//Initialize Mutex lock.
	
	
	pthread_create(&thread1,NULL,thread_inc,NULL);//thread for inc, the shared variable
	pthread_create(&thread2,NULL,thread_dec,NULL);//thread for dec, the shared variable
	
	
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	
	
	printf("Shared Global Value =%d \n",sharedVal);
	
	return 0;
	
}
			

