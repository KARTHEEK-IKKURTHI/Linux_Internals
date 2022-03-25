#include<stdio.h>
#include<conio.h>
#include<pthread.h>
pthread_t tid1;
pthread_t tid2;


void* st(void *arg){
	int i;
	for(i=0;i<50;i++){
		printf("Thread 1\n");
		}
}

void* st1(void *arg1){
	int j;
	for(j=0;j<50;j++){
		printf("Thread 2\n");
		}
}

int main(void){
		
		pthread_create(&tid1,NULL,st,NULL);
		pthread_create(&tid2,NULL,st1,NULL);
		getch();
		pthread_join(tid1,NULL);
		pthread_join(tid2,NULL);
		
		return 0;
}
