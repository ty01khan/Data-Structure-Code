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

	for(j=0;j<n;j++)
	{
		count = 0;
		for(k=0;k<n;k++)
		{
			if(A[j][k] == 1)
			{
				count++;
				printf("%d$",k);
			}
		}
		if(count == 0)
		{
			printf("$");
		}
		printf("\n");
	}
	return 0;
}
