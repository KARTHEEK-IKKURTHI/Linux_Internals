//Write a program child executes(exec()) a new program, while parent waits for child task to get complete.

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(){
	int a,ret,fd1;
	fd1=open("Lib1.txt",O_RDONLY);
	a=fork();
	if (a==0){
		execl("/bin/ls","ls",NULL);
		}
	wait(0);
	printf("Parent\n");
	
	return 0;
	
}
	
	
