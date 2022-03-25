
#include<stdio.h>
#include"calcium.h"

int main(int argc,char *argv[]){
		double v1,v2,m1,m2,m3,m4,m5;
		v1=5.3;
		v2=7.3;
		m1=mean(v1,v2);
		m2=sub(v1,v2);
		m3=add(v1,v2);
		m4=div(v2,v1);
		m5=mul(v1,v2);
		printf("The mean of %3.2f and %.3f is %3.2f \n",v1,v2,m1);
		printf("The subtract of %3.3f and %3.2f is %.3f \n",v1,v2,m2);
		printf("The Addition of %.3f and %.3f is %.3f \n",v1,v2,m3);
		printf("The Division of %.3f and %.3f  is %.3f \n",v1,v2,m4);
		printf("The Multiplication of %.3f and %.3f is %.3f \n",v1,v2,m5);
		
		
		return 0;
		
}
