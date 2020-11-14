#include<stdio.h>
#include<stdlib.h>

void BubbleSort(int A[],int n)
{
	int i,j,temp;
	int count = 0;
	for(j=1;j<n;j++)
	{
		int flag = 0;
		for(i=0;i<n-1;i++)
		{
			if(A[i] > A[i+1])
			{
				temp = A[i];
				A[i] = A[i+1];
				A[i+1] = temp;
				count = count + 1;
			}
			flag = 1;
		}
		if(flag == 0)
		{
			return;
		}
	}
	printf("Array is sorted in %d swaps.\n",count);
	return;
}
int main()
{
	int *A;
	int n,i,j;
	scanf("%d",&n);
	A = (int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		scanf("%d",(A+i));
	}
	BubbleSort(A,n);
	printf("First Element: %d\n",*(A));
	printf("Last Element: %d\n",*(A+(n-1)));
	return 0;
}
