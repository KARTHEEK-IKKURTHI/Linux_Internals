//A process using execl() system call should replace a new command line program.
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main(){
	int pd,ppd;
	printf("Hey enter something:\n");
	scanf("%d",&pd);
	fork();
	if(fork()==0){	
		execl("/bin/ls","ls",NULL);
		exit(0);
		}
		
	return 0;
	
}
