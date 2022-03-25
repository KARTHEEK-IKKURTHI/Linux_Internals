//Write a program where functions of the program are called in the reverse order of their function calls from main().


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>



void callback(void)
{	
	printf("Callback the func 1  \n");
}

void callback2(void)
{
	printf("Callback the func 2 \n");
}

void callback3(void)
{

	printf("Callback the func 3 \n");
}

int main(){
	printf("Registering the callback 1\n");
	atexit(callback);
	printf("Registering the callback 2 \n");
	atexit(callback2);
	printf("Registering the callback 3 \n");
	atexit(callback3);
	
exit(0);

}
