

//Show how to perform some task periodically

#include<stdio.h>
#include<signal.h>

void sighand(int signum){
	printf("I have to Wake Up \n");
	
}


int main(){
	signal(SIGALRM,sighand);
	alarm(5);
	while(1){
	}
	
}

