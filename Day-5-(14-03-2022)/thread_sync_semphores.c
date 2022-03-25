//Program to demonstrate the semaphore lock //

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int sharedVal=2;//  Shared Variable

sem_t my_sem;		//Create the Semaphore Lock

void *thread_inc(void *arg)
	{
		sem_wait(&my_sem);//Take Semaphore
		sharedVal++;//Critical Section
		sem_post(&my_sem);//Release Semaphore
		printf("After inc=%d\n",sharedVal);
		
}

void *thread_dec(void *arg){	
			sem_wait(&my_sem);  	//Take Semaphore
			sharedVal--;		//Critical Section
			sem_post(&my_sem);	//Release Semaphore
			printf("After dec =%d\n",sharedVal);
			
}

int main(){
	pthread_t thread1,thread2;
	
	sem_init(&my_sem,0,1);	//Initialize Semaphore lock.
	
	
	pthread_create(&thread1,NULL,thread_inc,NULL);//thread for inc, the shared variable
	pthread_create(&thread2,NULL,thread_dec,NULL);//thread for dec, the shared variable
	
	
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	
	
	printf("sharedVal =%d \n",sharedVal);
	
	return 0;
	
}
			

