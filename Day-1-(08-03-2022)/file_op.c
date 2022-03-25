//Write a program using file operations that demonstrates copying of data from input file and write into output file, untill reaches end of file data.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


int main(){
	int fd1,fd2,len,pen;
	char rit_buf[100]="Die Another Day!!";
	char red_buf[100];
	fd1=open("/home/einfochips/git_repo/Linux_Internals/Day-11-(08-03-2022)/Linux_9.txt",O_CREAT | O_RDWR,0777);
	len=write(fd1,rit_buf,100);
	printf("Successful %d\n",len);
	lseek(fd1,0,SEEK_SET);
	read(fd1,red_buf,len);
	printf("THe data in buffer is %s",red_buf);
	close(fd1);
	fd2=open("/home/einfochips/git_repo/Linux_Internals/Day-11-(08-03-2022)/Linux_10.txt",O_CREAT | O_RDWR,0777);
	pen=write(fd2,red_buf,100);
	printf("Successful %d\n",pen);
	lseek(fd2,0,SEEK_SET);
	read(fd2,red_buf,len);
	printf("The Data in buffer is %s",red_buf);
	close(fd2);
	return 0;
}
