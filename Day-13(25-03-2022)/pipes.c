/* The program illustrates how to creates pipe */


#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

int main(){	
	int fds[2];
	int res,i;
	char *buff="Kartheek";
	char *budd="Ikkurthi";
	char kuff[20];		//Use the exact array required to avoid any unnecessary clash in the result.  

	res=pipe(fds);


	/*fds[0] is used for reading and the fd[1] is used for the writing */

	if(res == -1){
		perror("Pipe");
		return 0;
	}

	write(fds[1],buff,20);
	write(fds[1],budd,20);
	read(fds[0],kuff,40);

	for(i=0;i<17;i++){		//Using the perfect size of loop we can avoid any sort of unneccessary garbage value to be included in the final result or the required result// 
			printf("%c",kuff[i]);
	}
	printf("\n");

//return 0;

}
