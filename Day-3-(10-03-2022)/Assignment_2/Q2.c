//Test whether the process(exec() system call) that replaces old program data, will inherit the fd's or not.

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>


int main(){
	int fd1;
	printf("Hello\n");
	fd1=open("Lib1.txt",O_RDONLY);
	printf("The fd is: %d\n",fd1);
	//close(fd1);
	execl("/bin/ls","ls",NULL);
	printf("The new fd is:%d\n",fd1);
	
	return 0;
	
	}
