#include<stdio.h>
#include<unistd.h>

int main(){
	int pid_1,pid;
	printf("Get pid:%d\n",getpid());

	pid=vfork();

	if(pid){
		printf("parent process:%d\n",getpid());
	}
	else{
		printf("parent processes:%d\n",getpid());
	}

	while(1);
	return 0;

}
