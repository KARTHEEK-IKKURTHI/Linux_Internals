
//	This program illustrates the use of FIFO Client.


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>


int main(void){
	printf("Client Process Writing \n");
	char clientmsg[]="0Linux System Kernel Programming";
	
	
	//Open FIFO for Writing
	
	int fd =open("Cli_ser_fifo",O_WRONLY);
	if(fd == -1){
		perror("Cannot open FIFO");
		return EXIT_FAILURE;
		
	}
	
	write(fd,clientmsg, strlen(clientmsg));
	
	close(fd);
	
	return 0;
	
}
