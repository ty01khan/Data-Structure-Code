#include<stdio.h>

int main()
{
	int n,i;
	float count1 = 0,count2 = 0,count0 = 0;
	scanf("%d",&n);
	int A[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		if(A[i] > 0)
		count1 = count1 + 1;
		else if(A[i] == 0)
		count0 = count0 + 1;
		else if(A[i] < 0)
		count2 = count2 + 1;;
	}
	float f0,f1,f2;
	f0 = (float) count0 / n;
	f1 = (float) count1 / n;
	f2 = (float) count2 / n;
	printf("%.6f\n%.6f\n%.6f\n",f1,f2,f0);
	return 0;
}
