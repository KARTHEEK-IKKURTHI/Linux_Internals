




#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

void* Proc(void* param){
	sleep(3);
	return 0;
	}

int main(int argc,char *argv[]){
		pthread_attr_t Attr;
		pthread_t	Id;
		int	err,info;
		
		pthread_attr_init(&Attr);
		pthread_attr_getinheritsched(&Attr,&info);
		
		switch(info)
		{
			case PTHREAD_INHERIT_SCHED:
				printf("\n SCHED ");
			case PTHREAD_EXPLICIT_SCHED:
				printf("\n EXPLICIT ");
				
				break;
				
		}
		
		
		
		
		pthread_attr_getinheritsched(&Attr,&info);
		
		switch(info)
		{
			case PTHREAD_INHERIT_SCHED:
				printf("\n SCHED ");
			case PTHREAD_EXPLICIT_SCHED:
				printf("\n EXPLICIT ");
				
				break;
				
		}
		
		printf("Process Creating thread whose sched policy is given br thread task Proc \n");
		
		
		pthread_create(&Id,&Attr,Proc,NULL);
		pthread_join(Id,NULL);
		
		return (0);
}
