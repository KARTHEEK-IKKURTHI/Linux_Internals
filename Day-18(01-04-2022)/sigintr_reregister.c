//Show how to Reregister signal handler


#include<stdio.h>
#include<unistd.h>
#include<signal.h>


void sig_handler(int signum){
	printf("\n Inside Handler Function");
	
	signal(SIGINT,SIG_DFL);	//Re Register signal handler for default action //}
	
}

int main(){
	signal(SIGINT,sig_handler)
