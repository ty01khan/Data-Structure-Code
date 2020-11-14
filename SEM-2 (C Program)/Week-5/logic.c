#include<stdio.h>
int main()
{
	int n,a,max,counter;
	printf("enter the value of n ");
	scanf("%d",&n);
	//counter=0;
	if(n==0)
  {
	printf("no number to compare \n");
  }
	else
  {
	printf("enter ther value of a ");
	scanf("%d",&a);
	max=a;
	counter=1;
        while(counter<n)
	{
	  scanf("%d",&a);
	  if(a>max)
	  {
	     max=a;
	  }
	  counter=counter+1;
	}
	printf("maximum value = %d \n",max);
  }
	return 0;
}

