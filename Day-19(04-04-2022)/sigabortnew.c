

//Shows an example of when sigabort will be generated


#include<stdio.h>
#include<stdlib.h>
#include<signal.h>


void abort_handler(int);

void main(){
	if (signal(SIGABRT,abort_handler) == SIG_ERR){
		fprintf(stderr,"Couldn't set signal handler \n");
		exit(1);
		
		
	}
	
	//Signal(SIGINT,SIG_DFL);
	abort();
	exit(0);
	
}

void abort_handler(int i){
	fprintf(stderr,"Caught SIGABRT,exiting application \n");
	exit(1);
	
}
