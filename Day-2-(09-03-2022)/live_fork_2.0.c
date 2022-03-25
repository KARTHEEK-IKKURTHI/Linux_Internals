#include<stdio.h>
#include<unistd.h>


int main(){
	int pid_1;
	printf("The process are :%d\n", getpid());//Get the current process id.
	
	pid_1=fork ();//child id is sent to parent
	
	if(pid_1=0){
		printf("The new child process is:%d\n",getpid());
		printf("The new child parent process is:%d\n",getppid());
		
	
	}
	
	else{
		sleep(3);
		printf("The parent process is:%d\n",getpid());
		printf("The new parent process is:%d\n",getppid());
		
	
	}
	
	while(1);
	
	return 0;
	
}
