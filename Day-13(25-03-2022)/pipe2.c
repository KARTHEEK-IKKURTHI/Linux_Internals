/* The program illustrates how to creates pipe */


#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

int fds[2];
void parent_code(){	
	
	char *buff="Kartheek";
	char *budd="Ikkurthi";
	close(fds[0]);
	write(fds[1],budd,9);
	write(fds[1],buff,9);
	printf("End of parent \n");		//Use the exact array required to avoid any unnecessary clash in the result.  

}
void child_code(){	
	char budd[20];
	int n,i;
	close(fds[1]);
	n=read(fds[0],budd,20);
	printf("No. of characters read = %d \n",n);
	
	
	for(i=0;i<n;i++){
		printf("%c",budd[i]);
		}
	printf("End of the Child Process\n");
}


main(){
	int res,i;
	
	pid_t p;
	res=pipe(fds);


	/*fds[0] is used for reading and the fd[1] is used for the writing */

	if(res == -1){
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
	
	
/*	write(fds[1],buff,20);
	write(fds[1],budd,20);
	read(fds[0],kuff,40);

	for(i=0;i<17;i++){		//Using the perfect size of loop we can avoid any sort of unneccessary garbage value to be included in the final result or the required result// 
			printf("%c",kuff[i]);
	}
	printf("\n");
*/
//return 0;

}
