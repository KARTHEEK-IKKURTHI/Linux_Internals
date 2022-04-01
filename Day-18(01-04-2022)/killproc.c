
//Shows how to send a signal to be a process

#include<sys/types.h>
#include<signal.h>
#include<stdio.h>


int main(){	
	pid_t pid;
	int sig_no;
	printf("Enter the Pid of the Process for which the signal need to be sent:");
	scanf("%d",&pid);
	printf("Enter the Signal that need to be sent:");
	
	scanf("%d",&sig_no);
	kill(pid,sig_no);
	perror("Sig_res:");
	
}
