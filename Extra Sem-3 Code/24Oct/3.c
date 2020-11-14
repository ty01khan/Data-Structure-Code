#include <stdio.h>

int main()
{
	int n,q,i,j; 
	scanf("%d",&n);
	char str[n];
	for(i=0;i<n;i++)
	{
	
		gets(str);
	}
	
	scanf("%d",&q);
	char qers[q];
	for(i=0;i<q;i++)
	{
		gets(qers);
	}
	
	for(i=0;qers[i] != '\0';i++)
	{
		int count = 0;
		for(j=0;str[j] != '\0';j++)
		{
			if(qers[i] == str[j])
			{
				count = count+1;
			}
		}
		printf("%d\n",count);
	}
	
return 0;
}
