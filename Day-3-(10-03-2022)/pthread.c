#include<stdio.h>
#include<pthread.h>

pthread_t tid;

void* thread1(void *arg){

	printf("Newly created thread is executing:\n");
	return NULL;
}

int main(void)
{			//pthread_t *ptr
	int ret= pthread_create(&tid, NULL,thread1,NULL);//address of function....name of the function
	
	if (ret){					//NULL default attr
	printf("Thread is not created\n");
	}
	else
	{	printf("Thread is created\n");
		
		//sleep(1);
		pthread_join(tid,NULL);
	}	
		
	return 0;
	
}
	
