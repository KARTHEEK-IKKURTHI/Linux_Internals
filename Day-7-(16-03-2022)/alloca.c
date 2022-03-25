//		THIS PROGRAM ILLUSTRATES THE USE OF ALLOCA FUNCTION

#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main(){
	char *str1="Mustang";
	char *str2="Shelby-GT";
	
	char *name=(char*) alloca(strlen(str1)+strlen(str2)+1);
	
	stpcpy(stpcpy(name,str1),str2);		//OVER-WRITTING
	
	printf("The Copied String is %s\n",name);
	
	return 0;
	
}
