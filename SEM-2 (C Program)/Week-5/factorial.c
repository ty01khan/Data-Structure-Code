#include<stdio.h>
int main()
{
	int n,i;
	long int factorial=1;
	printf("please enter the number n = ");
	scanf("%d",&n);
  	for(i=1;i<=n;i++)
  {
	factorial=factorial*i;
  }
	printf("factorial of the number %d = %ld\n",n,factorial);
return 0;
}

