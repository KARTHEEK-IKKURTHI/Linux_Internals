#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


int main(){
	printf("Hi\n");	
	fork(); //Create a new process and return twice
	
	
	fork();// Will return in total 4 processes.
	
	fork();//Will return addition 2 processes
	
	//Hence the 3 fork commands return in total 2+2+2=8 processes
	
	
	while(1);
	
	return 0;
	
}
	
