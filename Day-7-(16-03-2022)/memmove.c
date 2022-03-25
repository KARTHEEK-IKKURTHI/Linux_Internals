//	THIS PROGRAM DEMONSTRATES THE MEMMOVE FUNCTION

#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main(){
	char dest[]="Old-Man";
	const char sour[]="Ant-Man";
	
	printf("Before memmove dest: %s , sour : %s \n",dest,sour);
	
	memmove(dest,sour,7);
	
	printf("After memmove dest :%s, sour :%s \n",dest,sour);
	
	return 0;
	
}
