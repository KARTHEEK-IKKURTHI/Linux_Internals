////		This program is used to practice the debugging using gdb and electric fence as well as valgrind




#include<stdio.h>
#include<stdlib.h>


void buggy(){
	int *intptr;
	intptr=(int *)malloc(sizeof(int));	//int data type =4bytes
	
	*intptr=100;
	printf("Value at ptr input = %d\n",(*intptr));
	free(intptr);
	*intptr=99;
	
	
	
	
}

int main(){
	buggy();
	
	return 0;
	
	
}
