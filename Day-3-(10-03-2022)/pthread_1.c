//Create a program of two thread

#include<stdio.h>
#include<pthread.h>

pthread_t tid1;
pthread_t tid2;

void* thread1(void *arg1){

	printf("Newly created thread 1 is executing:\n");
	return NULL;
}
void* thread2(void *arg2){

	printf("Newly created thread 2 is executing:\n");
	return NULL;
}


int main(void){
	
	int r=pthread_create(&tid1,NULL,thread1,NULL);
	int p=pthread_create(&tid2,NULL,thread2,NULL);
	if(r){
	printf("Not Done\n");
	}
	else{
	printf("Done the T1\n");
	}
	
	if(p){
	printf("Nott Donne\n");
	}
	else{
	printf("Done the T2\n");
	}
	
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	
	return 0;
}
	
