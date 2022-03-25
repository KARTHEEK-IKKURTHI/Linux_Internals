#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(){

	int fd1;
	char k[70]="New Day";
	char r[70];
	fd1=open("/home/einfochips/git_repo/Linux_Internals/Day-11-(08-03-2022)/Linux_1.txt",0775);
	printf("File1 has %d",fd1);
	
	write(fd1, k,70);
	//printf(
	
	read(fd1 ,r ,70);
	printf("The read data is %s",r);
	
	close(fd1);
	return 0;
	
}
	
