#include<stdio.h>
#include<stdlib.h>
extern int EF_PROTECT_BELOW;
void buggy(){
	int *intptr;
	int i;
	intptr=(int *) malloc(sizeof(int)*5);			//int data type=4 byte
	
	//printf("MALLOC creating : Addr =%08x and Size= %d \n",intptr,sizeof(int)*5);
	
	for(i=0;i<=5;i++)//Changing the iteration we can see the change of memory allocation of malloc.
		{
			*intptr = 100;
			printf("Value at ptr input =%d\n",(*intptr));
			
			intptr--;
		}
		
}

int main(){
	buggy();
	return 0;
}
