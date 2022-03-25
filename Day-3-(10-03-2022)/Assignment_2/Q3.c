//A program that replaces old program with vim editor program and open a new text file.

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>


int main(){
	int fd1;
	fd1=open("Lib1.txt",O_RDONLY|O_CREAT,0775);
	execl("/usr/bin/pstree","pstree",NULL);
	
	return 0;
	
}

