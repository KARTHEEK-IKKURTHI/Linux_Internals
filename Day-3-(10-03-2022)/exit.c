#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>



void callback(void)
{	
	printf("Callback the func called \n");
}

void callback2(void)
{
	printf("Callback from called \n");
}

void callback3(void)
{

	printf("Callback func called \n");
}

int main(){
	printf("Registering the callback\n");
	atexit(callback);
	printf("Registering the callback2 \n");
	atexit(callback2);
	printf("Registering the callback3 \n");
	atexit(callback3);
	
exit(0);

}
