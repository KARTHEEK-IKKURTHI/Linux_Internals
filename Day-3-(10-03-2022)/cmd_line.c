
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char*argv[])
{
	int i;
	printf("\n File Name: %s\n",argv[0]);
	printf("Total number of arguments :%d\n",argc);
	printf("Arguments passed");
	
	for(i=0;i<argc;i++){
		argv++;
		printf("\n");
		
		}
return 0;
}
	
