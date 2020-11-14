#include<stdio.h>
int main()
{
	int a,b,pow,counter;
    	printf("enter value of a and b = ");
	scanf("%d%d",&a,&b);
	pow = 1;
	counter = 0;
	while(counter<b)
	{
	   pow=pow*a;
	   counter=counter+1;
	}
	printf("result = %d \n",pow);
	return 0;
}

