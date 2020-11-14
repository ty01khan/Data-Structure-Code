#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i,V[n],l[n],b[n],h[n];
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&l[i],&b[i],&h[i]);
	}
	for(i=0;i<n;i++)
	{
		if(h[i] < 41)
		{
			V[i] = l[i]*b[i]*h[i];
			printf("%d\n",V[i]);
		}
		
	}
}
