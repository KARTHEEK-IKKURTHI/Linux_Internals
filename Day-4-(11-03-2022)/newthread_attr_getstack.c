#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>



void* Proc(void * param){

	sleep(3);
	return 0;
	
}

int main(){
	pthread_attr_t Attr;
	pthread_t   Id;
	void   *Stk;
	size_t   Siz;//
	int   err;
	
	
	size_t  my_stksize = 0x3000000;
	
	void *my_stack;
	
	
	pthread_attr_init(&Attr);
	
	pthread_attr_getstacksize(&Attr,&Siz);//default stack size 8MB..pthd lib
	pthread_attr_getstackaddr(&Attr,&Stk);//def stack stack addr before thd
	
	
	
	printf("Default Addr =%08x, default Size =%d\n",Stk,Siz);//pthd lib size to threads
	
	
	my_stack=(void*)malloc(my_stksize);//ptr = malloc(100)
	
	//Explicitly sets Stack Address & Stack Size
	pthread_attr_setstack(&Attr,my_stack,my_stksize);
	
	pthread_create(&Id,&Attr,Proc,NULL);//thd stackaddr and the thd stack size
	//Set stack Address Z& Stack Size
	pthread_attr_getstack(&Attr,&Stk,&Siz);//Confirmation
	
	printf("Newly defined stack:Addr=%08x and Size =%d\n",Stk,Siz);
	
	sleep(2);
	
	return(0);
	
	
} 
