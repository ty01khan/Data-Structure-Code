#include<stdio.h>
#include<stdlib.h>

void Sort(int L[],int R[],int n)
{
	int i,j,temp1,temp2,flag;
	for(i=1;i<n;i++)
	{
		flag = 0;
		for(j=0;j<n-1;j++)
		{
			if(L[j] > L[j+1])
			{
				temp1 = L[j];
				L[j] = L[j+1];
				L[j+1] = temp1;
				temp2 = R[j];
				R[j] = R[j+1];
				R[j+1] = temp2;
			}
			flag = 1;
		}
		if(flag == 0)
		{
			break;
		}
	}
}

int main()
{
	int n,i,j;
	scanf("%d",&n);
	int L[n],R[n];
	
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&L[i],&R[i]);
	}
	Sort(L,R,n);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
				if(i != j)
				{
					if((L[i] <= L[j]) && (L[j] <= R[i]) && (R[i]) <= R[j])
					{
						R[i] = R[j];
						L[j] = -1;
						R[j] = -1;
					}
					else if((L[i] <= L[j]) && (R[i] >= R[j]))
					{
						L[j] = -1;
						R[j] = -1;
					}
					
				}
		}
		if((L[i] != -1) && (R[i] != -1))
        printf("%d %d\n",L[i],R[i]);
	}
	return 0;
}
