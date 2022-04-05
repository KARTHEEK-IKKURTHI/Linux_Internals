

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>


//Handler for SIGINT and SIGTERM

static void signal_handler(int signo){
	if(signo == SIGINT){
		printf("Caught SIGINT !\n");
		}
	else if(signo == SIGALRM){
		printf("Caught SIGALRM !\n");
		}
	else{
		printf("Caught SIGABRT !\n");
		//This should never happen
		}
	fprintf(stderr,"Unexpected Signal !\n");
	exit(EXIT_FAILURE);
	}
	
int main(void){
	//Register signal_handler as our signal handler for SIGINT.
	
	if(signal (SIGINT,signal_handler) == SIG_ERR){
		fprintf(stderr,"Cannot handle SIGINT !\n");
		exit(EXIT_FAILURE);
	}
	if(signal(SIGALRM, signal_handler) == SIG_ERR) {
		fprintf(stderr,"Cant handle sigint\n");
		exit(EXIT_FAILURE);
	}
		alarm(4);	


	if(signal(SIGABRT, SIG_DFL) == SIG_ERR) {
		fprintf(stderr,"Cant handle sigint\n");
		exit(EXIT_FAILURE);
	}
	// abort();
	if(signal(SIGABRT, SIG_IGN) == SIG_ERR) {
		fprintf(stderr,"Cant handle sigint\n");
		exit(EXIT_FAILURE);
	}
for(;;);
pause();
return 0;
}
