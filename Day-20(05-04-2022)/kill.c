
// Program for Killing the Program 


#include<stdio.h>
#include<signal.h>


void sighand(int no){
	if(no == 15){
	printf(" SIGTERM \n");
	}
}

main(){
	sigset_t s_set;		//Structure
	signal(15,sighand);	//Signal Handler
	sigemptyset(&s_set);	//Initialize
	sigaddset(&s_set,2);	//Adding the Signals to a grp of signals set.
	perror("sig2");
	sigaddset(&s_set,4);	//Adding the Signals to a grp of signals set.
	perror("sig4");
	sigprocmask(SIG_BLOCK|SIG_SETMASK,&s_set,NULL);		//Block the Specific Signals
	perror("sigmask");
	printf("Send me signal one and see the effect now \n");
	getchar();
	getchar();
	sigprocmask(SIG_UNBLOCK,&s_set,NULL);		//Block the Specific Signals
	printf("Now signals are unblocked \n");
	
	while(1);
	
}
