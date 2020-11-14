#include<stdio.h>
#include <stdlib.h>

void QuickSort(int A[],int Start,int End)
{
   int i,j,pivot,temp;

    if(Start<End)
    {
        pivot=Start;
        i=Start;
        j=End;

        while(i<j)
        {
            while((A[i]<=A[pivot]) && (i<End))
            {
                i++;
            }

            while(A[j]>A[pivot])
            {
                j--;
            }

            if(i<j)
            {
                temp=A[i];
                A[i]=A[j];
                A[j]=temp;
            }
        }

        temp=A[pivot];
        A[pivot]=A[j];
        A[j]=temp;
        QuickSort(A,Start,j-1);
        QuickSort(A,j+1,End);

   }
}

int main()
{
    int n,i;
    int *A;

    scanf("%d",&n);
    A = (int*)malloc(sizeof(int) * n);

    for(i=0;i<n;i++)
    {
       scanf("%d",&A[i]);
    }

    QuickSort(A,0,n-1);

    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
	printf("\n");
    return 0;
}
