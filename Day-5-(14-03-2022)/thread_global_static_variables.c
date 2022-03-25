#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int sharedVal=2;//  Shared Variable

void *thread_inc(void *arg)
	{
		sharedVal++;
		printf("After inc=%d\n",sharedVal);
		
}

void *thread_dec(void *arg){	
			sharedVal--;
			printf("After dec =%d\n",sharedVal);
			
}

int main(){
	pthread_t thread1,thread2;
	
	pthread_create(&thread1,NULL,thread_inc,NULL);//thread for inc, the shared variable
	pthread_create(&thread2,NULL,thread_dec,NULL);//thread for dec, the shared variable
	
	
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	
	
	printf("sharedVal =%d \n",sharedVal);
	
	return 0;
	
}
			

