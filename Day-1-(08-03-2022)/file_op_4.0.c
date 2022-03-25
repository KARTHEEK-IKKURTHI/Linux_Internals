//4.Write a program that implements all file operations(open/creat/write/read/lseek/close).

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd1;
	char k[50]="KKKKKKKKKKK";
	char p[50];
	creat("Lib.txt",0755);
	fd1=open("Lib.txt",O_RDWR,0775);
	write(fd1,k,50);
	close(fd1);
	fd1=open("Lib.txt",O_RDWR,0775);
	lseek(fd1,2,SEEK_CUR);
	read(fd1,p,30);
	printf("Data is %s",p);
	close(fd1);
	return 0;
	
}
	
