//	Write a program to start defrencing the pointer......



#include<stdio.h>
#include<stdlib.h>
#include<string.h>




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
