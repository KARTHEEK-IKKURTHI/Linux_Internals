
#include<stdio.h>
#include<unistd.h>
#include<signal.h>


void sig_handler(int signum){	
	printf("inside Handler Function \n");
	
}

int main(){	
	pid_t pid;
	signal(SIGUSR1,sig_handler);	//Register signal Handler
	printf("Inside Main Function \n");
	pid=getpid();	//Process ID of itself
	kill(pid,SIGUSR1);	//Send SIGUSR1 to itself
	printf("Inside Main Function \n");
	
	return 0;
	
}
