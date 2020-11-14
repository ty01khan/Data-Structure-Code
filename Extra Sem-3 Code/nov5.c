#include<stdio.h>

int main()
{
	int n,i,j,d,temp;
	scanf("%d%d",&n,&d);
	int A[n];
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	
	for(i=0;i<d;i++)
	{
		temp = A[0];
		for(j=1;j<n;j++)
		{
			A[j-1] = A[j];
		}
		A[n-1] = temp;
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
	
	printf("\n");
	return 0;
	
}
