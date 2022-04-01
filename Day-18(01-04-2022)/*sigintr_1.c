

/*show how to catch interrupt signal.
*/
//Signal Handler


#include<stdio.h>
#include<signal.h>


void sighand(int signum){
	printf("Interrupt Signal Rec'd ...but ");
}

int main(){
	int i;
	signal(SIGINT,sighand);
	//signal(SIGINT,SIG_DFL);
	while(1){
	}
	/*for(i=0;;i++){
		printf("%d \n",i);
		sleep(1);
		
	}*/ 	
	
}

		
