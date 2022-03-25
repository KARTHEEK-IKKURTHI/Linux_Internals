
//		THE PROGRAM ILLUSTRATES THE USE OF FSTAT AND MMAP FUNCTION.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<string.h>


int main(){
	int fd; 
	char *C;
	struct stat file_info;
	fd=open("file.txt",O_CREAT|O_RDWR,0755);
	write(fd,"A good day to start",20);
	
	fstat(fd,&file_info);
	printf("File size is : %ld\n",file_info.st_size);
	C=mmap(0,file_info.st_size,PROT_READ|PROT_WRITE,MAP_PRIVATE,fd,0);			//Message Success
	perror("mmap");
	
	//strcpy(C,"Vell-Fire");		//Kernel Region to User-Space
	
	printf("%s\n",C);			//No need of accessing system call for file read write
	
	//Dellocates all the resources
	
	munmap(C,file_info.st_size);		//De-alloc to free allocated resources.
	close(fd);
	
	return 0;
	
}
