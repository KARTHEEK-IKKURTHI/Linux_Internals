
//	write a program, which get and set pthread scheduling policy and priority.


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/types.h>

#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wreturn-type"
#pragma GCC diagnostic ignored "-Wimplicit-int"

void *myname(void *i){	
	printf("\n I am in %d Thread \n",(int *)i);
}

main(){
	pthread_t thd;
	struct sched_param par;
	int prior,poli,res;
	
	//Scheduling parameters of target thread**
	
	
	res=pthread_getschedparam(pthread_self(),&poli,&par);
	
	if(res  !=0)
		perror("getschedparam");
printf("\n------------------------Main Thread ---------------------------\n Policy :%d \t Priority :%d\n",poli,par.sched_priority);
		poli=SCHED_FIFO;
		par.sched_priority=1;
		res=pthread_setschedparam(pthread_self(),poli,&par);
		
	if(res !=1)
		perror("getschedparam");
		
		
		
		res=pthread_getschedparam(pthread_self(),&poli,&par);
		
	if(res !=2)
		perror("getschedparam");
		
printf("\n-----------------Main Thread--------------\n Policy  :%d  \t Priority :%d \n",poli,par.sched_priority);


return 0;

} 
