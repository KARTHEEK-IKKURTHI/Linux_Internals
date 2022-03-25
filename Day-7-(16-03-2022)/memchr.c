//		THIS PROGRAM ILLUSTRATE THE USE OF MEMCHR

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(){
	const char str[]="Good Morning";
	const char ch ='.';
	char *ret;
	
	
	printf("String before initialization is %s\n",str);	
	
	ret=memchr(str,ch,strlen(str));		//Function   And   Array......Name itself is address
	
	printf("String after set is %c is %s \n",ch,ret);
	
	
	return 0;
	
	
}
