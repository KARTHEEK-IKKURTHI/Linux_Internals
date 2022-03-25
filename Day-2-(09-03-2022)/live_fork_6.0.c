#include<stdio.h>
#include<unistd.h>

int main(){
	printf("The execution of cat command\n");

	execl("/einfochips/bin/cat","cat lib1",0);

	printf("execute cat command");
	

	return 0;

}
