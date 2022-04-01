
//	This program illustrates the creation of FIFO and how to read the data from them.

#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>


int main(){
	char s[20];
	int fd;
	
	mkfifo("newfifo_1",0644);	//newfifo1 is an pipe i.e; a file named pipe
		//Create fifo(named pipe)
	
	perror("mkfifo");
	
	printf("Before open()....\n");
	fd=open("newfifo_1",O_WRONLY);	//open fifo for write only
	printf("After open()....\n");
	
	
	printf("Enter the Data....\n");
	scanf("%s",s);
	//gets(s);
	
	write(fd,s,strlen(s)+1);	//std wt(); internally filewrite data to
	
	return 0;
	
}


//Fifo is pipe with name......named pipe.....will have name in file system......
