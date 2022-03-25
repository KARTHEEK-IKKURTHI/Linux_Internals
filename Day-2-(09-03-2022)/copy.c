#include<stdio.h>
#include<fcntl.h>

int main(){
`	int fd1,fd2,fd3,fd4;

	fd1=open("Lib1.txt",O_RDONLY | O_CREAT | O_TRUNK);
	fd2=open("Lib2.txt",O_RDONLY | O_CREAT | O_TRUNK);
	printf("fd1:%d\n",fd1);
	printf("fd2:%d\n",fd2);
	fd3=dup(fd1);
	
	read()
	 
