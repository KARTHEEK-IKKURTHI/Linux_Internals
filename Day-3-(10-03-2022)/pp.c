#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	int pid1,pid2;
	
	printf("The parent process is :%d\n",getpid());
	pid1=fork();
	
	if(pid1==0)//Child process
	{
		printf("The parent is : %d\n",getppid());
		printf("The child is : %d\n",getpid());
		execl("/bin/ls","ls",0);
		}
	else//Parent process
	{
		wait (NULL);
		printf("Child Processed");
	exit(0);
}
}
