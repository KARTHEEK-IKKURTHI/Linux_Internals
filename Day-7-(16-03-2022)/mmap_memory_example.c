
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<string.h>


int main(){
	char *C;
	
	C=mmap(0,50,PROT_READ|PROT_WRITE,MAP_ANONYMOUS|MAP_PRIVATE,-1,0);			//Message Success
	perror("mmap");
	
	strcpy(C,"Vell-Fire");		//Kernel Region to User-Space
	
	printf("%s\n",C);
	
	//Dellocates all the resources
	
	munmap(C,50);		//malloc	after free
	
	
	return 0;
	
}
