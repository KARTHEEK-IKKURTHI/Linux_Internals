#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd1,len;
	char rit_buf[100]="Die Another Day!!";
	char red_buf[100];
	
	//fd1=creat("/home/einfochips/git_repo/Linux_Internals/Day-11-(08-03-2022)/Linux_9.txt",0777);
	
	//Use O_CREAT | O_RDWR;
	fd1=open("/home/einfochips/git_repo/Linux_Internals/Day-11-(08-03-2022)/Linux_9.txt",O_CREAT | O_RDWR,0777);
	len=write(fd1,rit_buf,100);
	printf("Successful %d\n",len);
	
	//fd2=open("/home/einfochips/git_repo/Linux_Internals/Day-11-(08-03-2022)/Linux_9.txt",0777);//
	
	
	lseek(fd1,4,SEEK_SET);//For repositioning the Buffer to Zeroth position before the read operation.
	read(fd1,red_buf,len);
	printf("THe data in buffer is %s",red_buf);
	
	/*lseek(fd1,-6,SEEK_CUR);
	read(fd1,red_buf,len);		// -6 indicates the position to be gone either forward or backward depending on the integer.
	printf("THe data is buffer is %s",red_buf);
	*/
	close(fd1);
	
	return 0;
	}
	
