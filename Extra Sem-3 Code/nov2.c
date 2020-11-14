#include<stdio.h>

void SelectionSort(long int A[])
{
    int i,j,temp;
    for(i=0;i<4;i++)
    {
        for(j=i;j<5;j++)
        {
            if(A[i] > A[j])
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}
int main()
{
    int i;
    long int A[5],sum1 = 0,sum2 = 0;
    for(i=0;i<5;i++)
    {
        scanf("%ld",&A[i]);
    }
    SelectionSort(A);
    for(i=0;i<4;i++)
    {
        sum2 = sum2 + A[i];
    }
    printf("%ld ",sum2);
    for(i=4;i>=1;i--)
    {
        sum1 = sum1 + A[i];
    }
    printf("%ld\n",sum1);
    return 0;
}
