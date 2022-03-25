#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd1;
	fd1=open("Lib.txt",O_CREAT | O_RDWR,0775);
	lseek(fd1,4096,SEEK_END);
	write(fd1,"kdc",3);
	
	close(fd1);
	
	return 0;
	
}

	
