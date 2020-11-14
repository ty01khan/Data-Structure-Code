#include <stdio.h>
int main()
{
	int a[20],n,counter,temp;
	printf("enter n (<=20)  \n");
	scanf("%d",&n);
	if (n>20)
	{
	  printf("Wrong Input \n");
	}
	else
	{
	  counter=0;
	  while (counter<n)
	  {
		printf("enter the next element \n");
		scanf("%d",&a[counter]);
		counter=counter+1;
	   }
	   temp=a[n-1];
	   counter=n-2;
	   while(counter>=0)
	   {
		a[counter+1]=a[counter];
		counter=counter-1;
	   }
	   a[0]=temp;
	   counter=0;
	   while(counter<n)
	   {
		printf("%d ",a[counter]);
		counter=counter+1;
	   }
	}
return 0;
}
