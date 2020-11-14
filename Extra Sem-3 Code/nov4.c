#include<stdio.h>

int main()
{
	int n1,n2,n3,i,j,k,count = 0;
	scanf("%d%d%d",&n1,&n2,&n3);
	int A[n1],B[n2],C[n3],D[3];
	for(i=0;i<n1;i++)
	{
		scanf("%d",&A[i]);
	}
	for(i=0;i<n2;i++)
	{
		scanf("%d",&B[i]);
	}
	for(i=0;i<n3;i++)
	{
		scanf("%d",&C[i]);
	}
	
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			for(k=0;k<n3;k++)
			{
				if(A[i] <= B[j] && B[j] >= C[k])
				{
					count++;
				}
			}
		}
	}

	printf("%d\n",count);
	return 0;
}
