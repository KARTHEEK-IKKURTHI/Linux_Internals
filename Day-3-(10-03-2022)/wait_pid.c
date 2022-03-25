#include<stdio.h>
#include<sys/wait.h>





int main(){
	int pid;
	int status;
	printf("Parent :%d\n",getpid());
	
	pid=fork();
	
	if(pid ==0 ){
		printf("child :%d\n",getpid());
		sleep(2);
		
		exit(0);
		}
		
	printf("Parent reporting the exit of child=%d\n",waitpid(pid,&status,0));
	
	return 0;
	
}
