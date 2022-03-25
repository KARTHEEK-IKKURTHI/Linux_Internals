//		THIS PROGRAM ILLUSTRATES THE CREATION OF OUR OWN COPY FUNCTION

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
	char buff[10]="Hi There";
	char bff[10];
	
	copy(buff,bff,10);		//Copy function 
	
	return 0;
	
}
void copy(void *src,void *dst,int count){		//Our own copy function
				int j;
				for(j=0;j<count;j++){
						*dst = *src;
						dst++;
						src++;
						}
		}
