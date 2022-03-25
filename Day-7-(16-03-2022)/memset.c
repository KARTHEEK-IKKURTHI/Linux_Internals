
//			This program illustrates the use of the memset function

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(){
	const char str[20]="Good Morning";
	const char ch='#';
	int ret;
	
	printf("String before initialization is %s\n",str);	
	
	ret=memset(str,ch,strlen(str));		//Function   And   Array......Name itself is address
	printf("%d\n",ret);
	printf("String after set is %s  \n",str);
	
	
	return 0;
	
	
}
