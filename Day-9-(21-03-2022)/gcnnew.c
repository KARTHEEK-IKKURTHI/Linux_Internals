
#include<stdio.h>
#include<stdlib.h>

int main(){	
	char *src;
	src =malloc(200);
	fgets(src,500,stdin);
	printf("%s\n",src);
	return 0;
	
}


//Malloc never returned 2GB it only returned NULL to the SRC
