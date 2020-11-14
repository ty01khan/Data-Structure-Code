#include <stdio.h>

int main()
{
	int i,j,k,a[6][6],sum[16];
	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	for(i=0;i<16;i++)
	{
		sum[i] = 0;
		for(j=0;j<4;j++)
		{
			for(k=0;k<4;k++)
			{
				sum[i] = a[j][k] + a[j][k+1]+a[j][k+2]+a[j+1][k+1]+a[j+2][k]+a[j+2][k+1]+a[j+2][k+2];
			}
		}
	}
	for(i=1;i<16;i++)
	{
		printf("%d ",sum[i]);
	}
	for(i=1;i<16;i++)
	{
		if(sum[i-1] > sum[i])
		{
			sum[i] = sum[i-1];
		}
	}
	printf("%d \n",sum[15]);
	
	return 0;
}
