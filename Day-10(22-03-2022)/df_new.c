//		This program is used to practice the debugging using gdb and electric fence as well as valgrind



#include<stdio.h>
#include<stdlib.h>


void buggy(int *p){	//function using the value
	p[0]=1;	//writing to the address
	free(p);	//free ptr
	}
	
int main(){
	int *ptr;
	ptr=(int *)malloc(4);			//creating 4 bytes
	buggy(ptr);	//passing address of 4 bytes to through a ptr
	free(ptr);	//double free i.e trying to free a ptr already freed
		//ERROR
	
}
