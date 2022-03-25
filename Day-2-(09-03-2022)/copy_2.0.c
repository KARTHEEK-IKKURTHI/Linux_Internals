#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


int main(){
	int fd1,fd2;
	char buf[20];
	fd1=open("Lib1.txt",O_RDONLY|O_CREAT,0775);
	printf("Items are:%d\n",fd1);
	fd2=dup2(fd1,4);
	printf("Items are:%d\n",fd2);
	
	close(fd1);
	close(fd2);
	
	return 0;
	
}
	
