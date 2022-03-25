#include<stdio.h>
#include<unistd.h>

int main(){
	int pid_1,pid_2,pid_3,pp;

	printf("The current process is:%d\n",getpid());

	pid_1=fork();

	printf("The Current_1 process is:%d\n",getpid());

	pid_2=fork();
	
	printf("The Current_2 process is:%d\n",getpid());

	pid_3=fork();

	return 0;

}

