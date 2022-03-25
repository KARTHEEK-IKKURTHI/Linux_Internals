// 	THIS PROGRAM DEMONSTRATES THE USE OF MEMCPY AND MEMCMP FUNCTION

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
	char buff1[10];
	char buff2[10];
	int ret;
	
	memcpy(buff1,"Hi",4);
	memcpy(buff2,"Hey",4);
	printf("%s",buff2);
	ret=memcmp(buff1,buff2,4);
	
	printf("%d\n",ret);
	
	if(ret >0){
		printf("Buff1 is greater than Buff2\n");
		}
	else if(ret<0){
		printf("Buff1 is Smaller than Buff2\n");
		}
	else{
		printf("Buff1 and Buff2 are Brothers(Same)\n");
		}
	
	return 0;
	
}
