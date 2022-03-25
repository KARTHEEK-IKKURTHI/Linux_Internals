
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>



int main(int argc,char *argv[]){
	long int page_Size =sysconf(_SC_PAGESIZE);
	printf("My page Size is : %ld \n",page_Size);
	
	
	void* c1=sbrk(0);
	
	printf("Program break address :%p \n",c1);
	printf("Sizeof char: %lu \n",sizeof(char));
	c1=(void*) ((char*) c1 + 9);
	
	printf("c1: %p\n",c1);
	brk(c1);
	
	void* c2=sbrk(0);
	
	printf("Program break address: %p \n",c2);
	
	
}
