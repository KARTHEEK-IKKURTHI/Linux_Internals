//Write a program parent process writing to pipe and child reading toggled data from pipe, and also analyse the data flow order from write end to read end.


#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <string.h>


int fds[2];
void parent_code(){	
	
	char *budd="abcdefghijkl";
	close(fds[0]);
	write(fds[1],budd,12);
	printf("Parent has Written the String \n"); 

}
void child_code(){	
	char budd[12];
	int n,i;
	close(fds[1]);
	n=read(fds[0],budd,12);
	for(i=0;i<12;i++){
		if((budd[i] >= 'a' ) && (budd[i] <= 'z')) {
			budd[i] -= 0x20;
			
		}
		printf("%c",budd[i]);
	}
	printf("\nEnd of the Child Reading\n");
}


int main(){
	int result,j;
	
	pid_t p;
	result=pipe(fds);


	
	if(result == -1){
		perror("Pipe");
		return 0;
	}
	p = fork();
	if(p == 0){
		child_code();
	}
	else{
		parent_code();
	}
	
	

return 0;

}
