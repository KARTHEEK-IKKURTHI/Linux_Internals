



#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct A {		//Structure Definition
	int roll;
	char name[40],gender __attribute__((aligned(2)));
	
	float height;
}__attribute__((packed));		//Specifies how the complier should align data items
	
	


int main(){	
	struct A first;		//Declaring Structure
	printf("\n Size of Struct A %3d\n",sizeof(first));
	
}
