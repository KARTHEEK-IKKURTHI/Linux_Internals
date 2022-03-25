#include<stdio.h>
#include<unistd.h>

int main(){
	int r;
	r=execl("/einfochips/bin/vim","vim","live_fork_6.0",0);
	
	if(r=0)
	printf("run",r);
	
	return 0;
	
}
