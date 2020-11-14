#include<stdio.h>
#include<stdlib.h>

void Merge(int L[],int R[],int A[],int mid,int x)
{
	int i=0,j=0,k=0;
	while(i<mid && j<x)
	{
		if(L[i] <= R[j])
		{
			A[k] = L[i];
			i = i+1;
		}
		else
		{
			A[k] = R[j];
			j = j+1;
		}
		k = k+1;
	}
	while(i<mid)
	{
		A[k] = L[i];
		i = i+1; 
		k = k+1;
	}
	while(i<x)
	{
		A[k] = R[j];
		j = j+1;
		k = k+1;
	}
}

void MergeSort(int A[],int n)
{
	int mid = n/2,i,j;
	int *Left,*Right;
	j = n - mid;
	Left = (int*)malloc(sizeof(int)*mid);
	Right = (int*)malloc(sizeof(int)*j);
	if(n<2)
	{
		return;
	}
	for(i=0;i<mid;i++)
	{
		Left[i] = A[i];
	}
	for(i=mid;i<n;i++)
	{
		Right[i - mid] = A[i];
	}
	MergeSort(Left,mid);
	MergeSort(Right,j);
	Merge(Left,Right,A,mid,j);
}

int main()
{
	int *A;
	int i,n,k,sum = 0;
	scanf("%d%d",&n,&k);
	A = (int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		scanf("%d",(A+i));
	}
	MergeSort(A,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",*(A+i));
	}
	printf("\n");
	/*for(i=0;i<n;i++)
	{
		if(sum < k)
		{
			sum = sum + *(A+i);
		}
		else
		{
			break;
		}
	}*/
	printf("%d\n",i);
	return 0;
}
