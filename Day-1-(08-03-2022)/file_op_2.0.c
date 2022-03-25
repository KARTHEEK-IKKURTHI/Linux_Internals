// Write a program that demonstrates repositioning of file offset using SEEK_SET,
//SEEK_END and SEEK_CUR.//

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd1;
	char k[18];
	fd1=open("Linux_9.txt",O_RDONLY,0775);
//	lseek(fd1,0,SEEK_END);
//	read(fd1,k,5);
//	printf("%s\n",k);
	
	lseek(fd1,0,SEEK_SET);
	read(fd1,k,4);
	printf("%s\n",k);
	
	lseek(fd1,10,SEEK_CUR);
	read(fd1,k,5);
	printf("%s\n",k);
	
	close(fd1);
	
	return 0;
	
}
