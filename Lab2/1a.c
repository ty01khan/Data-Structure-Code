#include <stdio.h>
#include <stdlib.h>

void sortArray(int* A, int size)
{
	int stk = A[size-1];
	for(int i = size-2; i >= 0; i--)
	{
		if(A[i] < stk)
			break;
		
		A[i+1] = A[i];
		A[i] = stk; 
	}
	return;
}

int main()
{
	int n;
	scanf("%d", &n);
	int A[n];
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	
	sortArray(A, n);
	
	printf("Sorted order of array is: ");
	for(int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
	
	return 0;
}
