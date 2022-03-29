
//	This program illustrates the use of Read of FIFO.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>


int main(){
	int fd1;
	//FIFO file path
	
	//char *newfifo ="/tmp/newfifo";
	
	mkfifo("NEWFIFO",0666);
	
	char arr1[100],arr2[100];
	while(1){
		//Open FIFO for Write ONLY
		fd1=open("NEWFIFO",O_WRONLY);
		
		//Take an input arr2ing from user.
		//100 is maximum length
		
		fgets(arr2,100,stdin);
		
		//Write the input arr2ing on FIFO
		//And close it
		write(fd1,arr2,strlen(arr2)+1);
		close(fd1);
		
		//Open FIFO For Read Only
		fd1=open("NEWFIFO",O_RDONLY);
		
		//Read from FIFO
		
		read(fd1,arr1,sizeof(arr1));
		
		
		//Print the read Message
		
		printf("User 2 : %s \n",arr1);
		
		close(fd1);
		
	}
	
	return 0;
	
}
