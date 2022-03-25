//Write a program parent process wait until, while child process open a file and read file data into empty buffer.//


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>


int main(){
	int fd1;
	char k[20];
	
	int ret=fork();
	if(ret==0)
	{
		fd1=open("Lib1.txt",O_RDONLY);
		read(fd1,k,20);
		printf("%s",k);
		
		}
	else
	printf("\nParent process:");
	
	return 0;
	
}
