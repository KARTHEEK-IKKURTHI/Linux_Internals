#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int pd,ppd;
	
	printf("Hey enter something:\n");
	scanf("%d",&pd);
	if (pd){
	exit(0);
	}
	if(fork()==0)
	{	
		execl("/bin/ls","ls",0);
		exit(0);
		}
	//printf("The process is %d\n",getpid());
	//if (
	//printf("The process is %d\n",getppid());
