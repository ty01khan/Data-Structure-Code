#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,i,sum=0,N;
	int *A;
	scanf("%d",&n);
	A = (int*)malloc(n*sizeof(int));
	
	if(A == NULL)
	{
		printf("Error! Memory not allocated\n");
		exit(0);
	}
	
	for(i=0;i<n;i++)
	{
		scanf("%d",(A+i));
		sum = sum + *(A + i);
	}
	
	printf("%d\n",sum);
	free(A);
	
	return 0;
	
}
