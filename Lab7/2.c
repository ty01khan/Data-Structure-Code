#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n;
	int lineNo = 0;
	int count,i,j,k,a,b;

	scanf("%d",&n);
	int A[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			A[i][j] = 0;
		}
	}

	while(scanf("%d %d",&a,&b) == 2)
	{
		A[a][b] = 1;
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(A[i][j] == 1)
			{
				for(k=0;k<n;k++)
				{
					if(k != i)
					A[k][j] = -1;
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(A[i][j] == 1)
			{
				printf("(%d,%d)",i,j);
				printf("\n");
			}
		}
	}
	return 0;
}
