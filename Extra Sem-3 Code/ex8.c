#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *A,n,i,a=0;
	scanf("%d",&n);
	A = (int*)calloc(n , sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",(A+i));
		if(*(A+i) > a)
		{
			a = *(A+i);
		}
	}
	printf("%d\n",a);
	return 0;
}


