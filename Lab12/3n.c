#include<stdio.h>

void InsertSort(int L[],int R[],int li,int ri,int n1)
{
	int i,temp1,temp2;
	L[n1] = li;
	R[n1] = ri;
	
	for(i = n1;i > 0;i--)
	{
		if(L[i] > L[i-1])
		{
			temp1 = L[i-1];
			temp2 = R[i-1];
			
			L[i-1] = L[i];
			R[i-1] = R[i];
			
			L[i] = temp1;
			R[i] = temp2;	
		}
	}
}
int main()
{
	int i,n;
	scanf("%d",&n);
	int L[n],R[n];
	
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&L[i],&R[i]);
		InsertSort(L,R,L[i],R[i],i);
	}

	for(i=n-1;i>0;i--)
	{
		if((R[i] >= L[i-1]) && (R[i] <= R[i-1]))
		{
			L[i-1] = L[i];
			L[i] = -1;
			R[i] = -1;
		}
		else if(R[i] >= R[i-1])
		{
			L[i-1] = L[i];
			R[i-1] = R[i];
			L[i] = -1;
			R[i] = -1;
		}
	}
	for(i=n-1;i>=0;i--)
	{
		if((L[i] != -1) && (R[i] != -1))
		printf("%d %d\n",L[i],R[i]);
	}
	
	return 0;
}
