//	The program demonstrates the use of pthread_once function for initialization of a code


#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>


pthread_once_t once=PTHREAD_ONCE_INIT;

void *myinit(){		//Executes only once from first thread	
	printf("I am a init function \n");
	}
void *mythread(void *i){
	printf("I am a mythread :%d\n",(int *)i);
	pthread_once(&once,(void *)myinit);
	
	printf("\n Exit from the mythread :%d\n",(int *)i);
	
}

int main(){
	pthread_t thread,thread1,thread2;
	pthread_create(&thread,NULL,mythread,(void *)1);
	
	pthread_create(&thread1,NULL,mythread,(void *)2);
	
	pthread_create(&thread2,NULL,mythread,(void *)3);
	
	printf("Exit For Main Thread \n");
	
	pthread_exit(NULL);
	
}
