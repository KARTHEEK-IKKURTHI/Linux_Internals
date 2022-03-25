#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	int fd1,fd2,fd3;
	fd1=creat("/home/einfochips/git_repo/Linux_Internals/Day-11-(08-03-2022)/Linux_1.txt",0755);
	fd2=creat("/home/einfochips/git_repo/Linux_Internals/Day-11-(08-03-2022)/Linux_2.txt",0755);
	fd3=creat("/home/einfochips/git_repo/Linux_Internals/Day-11-(08-03-2022)/Linux_3.txt",0755);
	
	printf("Fd of File1 is %d",fd1);
	printf("Fd of File2 is %d",fd2);
	printf("Fd of File3 is %d",fd3);
	
	close(fd1);
	close(fd2);
	close(fd3);
}
	
