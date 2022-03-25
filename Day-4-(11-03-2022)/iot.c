#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>



void * th_fn(void *p);

int fd;
int main(){
	pthread_t t1,t2;
	
	fd=open("/etc/passwd",O_RDONLY);
	printf("File opened with fd : %d \n",fd);
	
	pthread_create(&t1,NULL,th_fn,"Thread One");//fd=0 std i/p i.e
	pthread_create(&t2,NULL,th_fn,"Thread Two");//fd=1  std o/p i.e display screen //printf
	
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);			//fd=2  std error device
	
	
	
}

void *th_fn(void *p){
	char * str,buff[100];
	int n,pid;
	str=(char *)p;
	pid=getpid();
	printf("%s:\n Started Now: \n For Process %d \n \n",str,pid);//THread one thd two
	//pid
	do
	{
		n=read(fd,buff,100);
		printf("%s \n Read : \t %d \n \n",str,pid);
		printf("\n--------------------\n");
		write(1,buff,n);				//fd=0 inout i,keyboard
								//fd=1 output(display/screen)
								//fd=2 error device //fd=3
		printf("\n-----------------\n");
		
		sleep(2);
		}
		
	while(n);
	
	printf("%s  \t Finished: \t For Process: %d \n\n",str,pid);
	
}
