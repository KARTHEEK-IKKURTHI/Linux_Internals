
//	This program Illustrates the fifo write


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>


int main(){
	int fd;
	mkfifo("NEWFIFO",0666);
	
	char str1[100],str2[100];
	
	while(1){
		//First open in read only and read
		fd=open("NEWFIFO",O_RDONLY);
		read(fd,str1,100);
		
		//Print the read String and close
		
		printf("User1: %s \n",str1);
		close(fd);
		
		
		
		//Now open in write mode and write
		//String taken from user
		
		fd= open("NEWFIFO",O_WRONLY);
		fgets(str2,100,stdin);
		write(fd,str2,strlen(str2)+1);
		close(fd);
		
		}
		
	return 0;
	
}	
