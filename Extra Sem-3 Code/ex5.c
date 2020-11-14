#include <stdio.h>

void swap(int *n1,int *n2,int *n3)
{
	int a;
	a = *n1;
	*n1 = *n2;
	*n2 = *n3;
	*n3 = a;
}
int main()
{
	int num1,num2,num3;
	scanf("%d%d%d",&num1,&num2,&num3);
	swap(&num1,&num2,&num3);
	printf("%d %d %d\n",num1,num2,num3);
	return 0;
}
