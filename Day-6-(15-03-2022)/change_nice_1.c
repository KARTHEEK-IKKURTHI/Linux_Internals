
#include<stdio.h>
#include<errno.h>
#include<unistd.h>



int main(){
	int ret,i,cnt=0;
	errno=1;
	ret= nice(1);		//Nice() is used to assign nice value to a particular (incr / decr 	//priority of the proces)
	if(ret ==-1 && errno !=1){
		perror("Size");
		}
	else{
		printf("Nice Value is Now: %d\n",ret);
		}
		
	while(1){
		printf("Process with nice value %d count = %d\n",ret,cnt);
		for(i=1;i<10000000;i++);
		cnt++;
		
	}
	
}
