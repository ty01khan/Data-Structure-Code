#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	scanf("%d",&n);
	int a,j,i,a[n],b[n],c[n],p[n],k[i],S[i];
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		p[i] = (a[i]+b[i]+c[i])/2;
		k[i] = (p[i]*(p[i] - a[i])*(p[i] - b[i])*(p[i] - c[i]));
		S[i] = sqrt(k[i]);
	}
	
	for(j=0;j<n;j++)
	{
		for(i=j+1;i<n-1;i++)
		{
			if(S[j] > S[i])
			{
				a = S[j];
				S[j] = S[i];
				S[i] = a;
			}
			printf("%d ",i);
		}
	}
	
	return 0;
}
