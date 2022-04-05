
//	This program run internally it run and read and writes.

#include<stdio.h>
#include<unistd.h>
#include<string.h>


int main(){
	int p[2];//p[0],p[1]  indexes or subscripts of array p
	
	pipe(p);//fd0 ----P[0]rd  end   and fd1 ------P[1] wt end
	printf("Read end of pipe =%d  \t Write end of pipe =%d \n",p[0],p[1]);//3	,4,...........0 1 2  OS
	
	if(fork())		//Parent...chd   pid   fork      child.......0
		{
			//Parent.....
		
		char s[20];
		printf("In the parent Enter Data: \n");
		scanf("%s",s);	//Wait user enter "15+1"
		write(p[1],s,strlen(s)+1);
		
		
	}
	
	else{
		char buf[20];
		printf("In Child......\n");
		read(p[0],buf,sizeof(buf));
		printf("Child process printing..... Data...of the parent process.....%s \n",buf);
		
		
	}
	
	
	return 0;
	
}

//		parent wrt-------------------child read
//		0x1234  			0x6789
		
//		fd1 write(fd1,s,size)		fd0 read)fd0,buff,size)
//	----------------------------------------------------------------
