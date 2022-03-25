
//	This program demonstrates the use of system function with NULL

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
	char buff_comm[15];
	strcpy(buff_comm,"ls -l");
	
	printf("system() library function uses fork() to create a child process \n");
	printf("Child process executes execl() which loads and runs new program provides by a system() argument \n");
	
	int a;
	a = system(NULL);
	printf("%d\n",a);
	return (0);
}


