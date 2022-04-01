
//	This program illustrates the creation of FIFO and how to read it.

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


int main(){
	char s[20];
	int fd;
	mkfifo("newfifo_1",0644);	//Create fifo (named pipe) //file
	
	printf("Before open().. \n");
	fd=open("newfifo_1",O_RDONLY);	//3 file table rdr pro	//open fifo
	printf("aAfter open()...\n");
	
	
	read(fd,s,sizeof(s));	//Read data from fifo
	printf("Data: %s\n",s);
	
	
	return 0;
	
	
}
