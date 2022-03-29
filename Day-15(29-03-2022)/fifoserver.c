
//	This Program demonstrates the use of the FIFO SERVER.



#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(void){
	printf("Server  - listening");
	
	//Create Fifo
	int code =mkfifo("Cli_ser_fifo",0764);
	if(code == -1){
		perror("mkfifo returned am error -file may already exist");
		}
	//Open read end
	int fd = open("Cli_ser_fifo",O_RDONLY);
	if(fd == -1){
		perror("Cannot open FIFO for read");
		return 0;
	}
	printf("FIFO OPEN");
	
	
	//Read String (upto 100 character)
	char serverrcv[100];	//String Buffer
	memset(serverrcv,0,100);	//Set ser buff with zeros
	
	int res;
	char len;
	while(1){
		res=read(fd,&len, 1);
		if(res == 0){
			break;
			}
		read(fd,serverrcv,len);	//Read String Characters
		printf("Server Recieved : %s \n",serverrcv);
		}
		
		printf("EOF Reached");
		
		
		close(fd);
		
		printf("FIFO Closed");
		
		return 0;
		
}	
	
