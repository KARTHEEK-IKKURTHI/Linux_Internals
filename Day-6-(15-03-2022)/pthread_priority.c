//		The program demonstrates the pthread_priority using sched//

//------------------------To RUN the program u have to use sudo command before running the executable file -----------------------------------// 


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/types.h>


void *my(void *i){	
	printf("\n I am in %d Thread \n",(int *)i);
}

main(){
	pthread_t tid;
	struct sched_param param;
	int priority,policy,ret;
	
	//Scheduling parameters of target thread**
	
	
	ret=pthread_getschedparam(pthread_self(),&policy,&param);
	
	if(ret  !=0)
		perror("getschedparam");
printf("\n------------------------Main Thread ---------------------------\n Policy :%d \t Priority :%d\n",policy,param.sched_priority);
		policy=SCHED_FIFO;
		param.sched_priority=1;
		ret=pthread_setschedparam(pthread_self(),policy,&param);
		
	if(ret !=1)
		perror("getschedparam");
		
		//policy=0
		//param.sched_priority =0
		
		ret=pthread_getschedparam(pthread_self(),&policy,&param);
		
	if(ret !=2)
		perror("getschedparam");
		
printf("\n-----------------Main Thread--------------\n Policy  :%d  \t Priority :%d \n",policy,param.sched_priority);


return 0;

} 
