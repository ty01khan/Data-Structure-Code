#include<stdio.h>

int main()
{
	int n,i,count = 0;
	scanf("%d",&n);
	int A[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	int temp = A[0];
	for(i=0;i<n;i++)
	{
		if(A[i] > temp)
		{
			temp = A[i];
		}
	}
	for(i=0;i<n;i++)
	{
		if(A[i] == temp)
		{
			count++;
		}
	}
	printf("%d\n",count);
	return 0;
}
