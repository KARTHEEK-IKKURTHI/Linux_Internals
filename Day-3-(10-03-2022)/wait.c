#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(void){
	pid_t,pid;
	
	pid1=fork();
	
	if(pid1==0)
	{
		sleep();
		printf("I am child with 5 sec delay and my pid is=%d\n",getpid());
		}
	else{
		int pid2;
		printf(
		pid2=wait(0);
		
		printf("Parent waiting child %d exited/terminated normally\n",pid2);
		printf("I am parent process with pid=%d\n",getpid());
		
	}
	
	return 0;
	
}
