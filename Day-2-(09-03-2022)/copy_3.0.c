#include<stdio.h>
#include<fcntl.h>

int main(){
	int fd1,fd2;
	char k[20];
	fd1=open("Lib2.txt",O_RDONLY|O_CREAT,0775);
	
	fd2=fcntl(fd1,F_DUPFD);
	printf("Read:%d\n",fd2);
	close(fd1);
	close(fd2);
	return 0;
	
}
