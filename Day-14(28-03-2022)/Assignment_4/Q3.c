
//	Write a pthread program that implements simple initialization code. 
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>

#pragma GCC diagnostic ignored "-Wformat"
pthread_once_t once=PTHREAD_ONCE_INIT;

void *myname(){		//Executes only once from first thread	
	printf("My name is Kartheek Ikkurthi \n");
	return NULL;
	}
void *mythread(void *i){
	printf("This is my thread :%d\n",(int *)i);
	pthread_once(&once,(void *)myname);
	
	printf("\n Bye my thread :%d\n",(int *)i);
	return NULL;
}

int main(){
	pthread_t thd,thd1,thd2;
	pthread_create(&thd,NULL,mythread,(void *)1);
	
	pthread_create(&thd1,NULL,mythread,(void *)2);
	
	pthread_create(&thd2,NULL,mythread,(void *)3);
	
	printf("Helloo... From The Other-Side For Main Thread \n");
	
	pthread_exit(NULL);
	
}
