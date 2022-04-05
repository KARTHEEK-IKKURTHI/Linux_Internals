//


#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>	//getpid()


//Iterates through a list of dignals and printout which signals are in a signal set.
void printSignalSet(sigset_t *set){
	
	const int sigList[]={SIGHUP,SIGINT,SIGQUIT,SIGILL,SIGABRT,SIGFPE,SIGKILL,SIGSEGV};
	const char *sigNames[]={"SIGHUP","SIGINT","SIGQUIT","SIGILL","SIGABRT","SIGFPE","SIGKILL","SIGSEGV"};
	const int siglen=8;
	
	for(int i=0;i<siglen;i++){	
		int ret =sigismember(set,sigList[i]);
		if(ret == -1){
			perror("sigismember");
			exit(EXIT_FAILURE);
		}
		else if(ret == 1){
			printf("Signal %s= %d is in the set.\n",sigNames[i],sigList[i]);
			}
		else{
			printf("Signal %s=%d is not in the set.\n",sigNames[i],sigList[i]);
			}
		}
}

int main(){
	sigset_t set;
	if(sigprocmask(0,NULL,&set) !=0){
		perror("sigprocmask");
		exit(EXIT_FAILURE);
		}
		
		printf("...initial signal masl for this process:");
		printSignalSet(&set);
		
		if(sigaddset(&set,SIGINT)!=0)//Add SIGINT to our set
		{
			perror("sigaddset");
			exit(EXIT_FAILURE);
		}
		//Tell OS that we want to mask our new set of signals ...which now includes SIGINT
		
		if(sigprocmask(SIG_SETMASK,&set,NULL)!=0){
			perror("sigprocmask");
			exit(EXIT_FAILURE);
			}
		//Now SIGINTI will be blocked
		printf("....New Signal for this process:");
		printSignalSet(&set);
		
		int secToSleep =20;
		printf("Try CTRL+C Try Killing this program with kill -kill %d.Going to sleep for %d seconds",getpid(),secToSleep);
		sleep(secToSleep);
		printf("Sleep returned");
		
		
		printf("Removing all Signals from Mask");
		sigfillset(&set);
		
		sigprocmask(SIG_SETMASK,&set,NULL);
		
		printSignalSet(&set);
		
		sleep(1);
		printf("Exited Normally");
		
		return 0;
		
	}
		
		
			
