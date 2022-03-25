//Write a program such that parent process create two child processes.


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	int pid1,pid2;
	
	printf("The parent process is :%d\n",getppid());
	pid1=fork();
	if(pid1==0){
		printf("The parent id is %d\n and child process is %d\n",getppid(),getpid());
		}
	printf("The child process 1 is :%d\n",getpid());
	pid2=fork();
	if(pid2==0){
		printf("The parent id is %d\n and child process is %d \n",getppid(),getpid());
		}
	printf("The child process 2 is :%d\n",getpid());
	
	return 0;
}
