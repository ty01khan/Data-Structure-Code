#include <stdio.h>
#include <stdlib.h>

/*void SelectionSort(int A[],int n)
{
	int i,j,iMin,temp;
	for(i=0;i<n-1;i++)
	{
		iMin = i;
		for(j=i+1;j<n;j++)
		{
			if(A[j] < A[iMin])
			{
				iMin = j;
			}
		}
		temp = A[i];
		A[i] = A[iMin];
		A[iMin] = temp;
	}
}*/

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
	j = n - mid;
	int Left[mid],Right[j];
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
	int i,n,k,sum=0;
	scanf("%d%d",&n,&k);
	int A[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	MergeSort(A,n);
	/*for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");*/
	
	i=0;
	while(sum < k)
	{
		sum = sum + *(A+i);
		if(sum < k)
		{
			i++;
		}
		else
		{
			break;
		}
	}
	printf("%d\n",i);
	return 0;
}
