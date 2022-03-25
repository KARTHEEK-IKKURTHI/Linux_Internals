

#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[]){	//argc counts the total number of arguments	
					//argv stores all arguments
		int i;
		printf("\n File Name: %s\n",argv[0]);
		printf("Total number of Arguments: %d",argc);
		printf("\n Arguments Passed");
		
		for(i=0;i<argc;i++){
			printf("%s",argv[i]);
			}
			
	return 0;
}
