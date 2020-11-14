#include <stdio.h>

void swap(int *n1,int *n2)
{
	int a;
	a = *n1;
	*n1 = *n2;
	*n2 = a;
}
int main()
{
	int num1,num2,i,sum=0;
	printf("Enter the two random number: ");
	scanf("%d%d",&num1,&num2);
	swap(&num1,&num2);
	printf("After swapping n1 = %d and n2 = %d\n",num1,num2);
	return 0;
}
