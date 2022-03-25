
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



struct student{		//Structure Definition

	int roll;
	char name[40];gender;
	float height;
}first;		//Declaring Structure


int main(){
	struct student second;		//Declaring Structure
	struct student third={11,"Kartheek",'M',171};		//Declaring & Initialisation Structure Variables
	
	printf("\n Roll \t NAme \t \t\t\t\t\t\t Gender: \t\t Height::\n");		
	first.roll=10;
	strcpy(first_name,"Kartheek Ikkurthi");
	first.gender='M';
	first.height='171';
	printf("\n %d  %s   %c   %f",first.roll,first.name,first.gender,first.height);
	printf("\n %d  %s   %c   %f",second.roll,second.name,second.gender,second.height);
	
	return 0;
	
}
	
