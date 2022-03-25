//		Write a multithreading program, where threads  runs same   shared golbal variable of the process between them.

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>


int sharedVal=21;//  Shared Variable

void *thread_inc(void *arg)
	{
		sharedVal++;
		printf("After Increment=%d\n",sharedVal);
		
}

void *thread_dec(void *arg){	
			sharedVal--;
			printf("After Decrement =%d\n",sharedVal);
			
}

int main(){
	pthread_t t1,t2;
	
	pthread_create(&t1,NULL,thread_inc,NULL);//thread for inc, the shared variable
	pthread_create(&t2,NULL,thread_dec,NULL);//thread for dec, the shared variable
	
	
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	
	
	printf("Shared Global Value =%d \n",sharedVal);
	
	return 0;
	
}
			

