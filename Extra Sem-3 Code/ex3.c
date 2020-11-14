#include <stdio.h>

int main()
{
	int a[6],i,sum=0;
	printf("Enter the 6 no. ");
	for(i=0;i<6;i++)
	{
		scanf("%d",(a+i));
	}
	for(i=0;i<6;i++)
	{
		sum = sum + *(a+i);
	}
	printf("Sum of 6 input no. is %d\n",sum);
	return 0;
}
