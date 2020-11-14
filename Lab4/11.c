#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stoi(char *str)
{
	int a;
	sscanf(str,"%d",&a);
	return a;
}

int heapSize = 0;

int Parent(int i)
{
	return (((i+1)/2)-1);
}

int Left(int i)
{
	return ((2*i)+1);
}

int Right(int i)
{
	return ((2*i)+2);
}

void Parn_child_swap(int A[],int i)
{
	int temp,p;
	p = Parent(i);
	
	if(i != 0)
	{
		if(A[p] < A[i])
		{
			temp = A[p];
			A[p] = A[i];
			A[i] = temp;
		}
		Parn_child_swap(A,p);
	}
}

void maxHeapify(int A[],int i)
{
	int temp1,temp2,l,r;
	l = Left(i);
	r = Right(i);
	
	if(A[l] > A[r])
	{
		if(A[l] < A[i])
		{
			temp1 = A[l];
			A[l] = A[i];
			A[i] = temp1;
			maxHeapify(A,l);
		}
		else if(A[l] < A[r])
		{
			if(A[r] < A[i])
			{
				temp2 = A[r];
				A[r] = A[i];
				A[i] = temp2;
				maxHeapify(A,r);
			}
		}
	}
}

int insertKey(int A[],int key,int n)
{
	if(heapSize >= n)
	{
		return -1;
	}
	A[heapSize] = key;
	int i = heapSize;
	heapSize++;
	Parn_child_swap(A,i);
	return 1;
}

int deleteKey(int A[],int i)
{
	int temp;
	if(heapSize <= 0)
	{
		return -1;
	}
	temp = A[i];
	A[i] = A[heapSize - 1];
	A[heapSize - 1] = temp;
	heapSize--;
	maxHeapify(A,i);
	return 1;
}

int extractMax(int A[])
{
	int temp,i;
	if(heapSize <= 0)
	{
		return -1;
	}
	temp = A[0];
	i = 0;
	deleteKey(A,i);
	return temp;
}

int increaseKey(int A[],int i,int newVal)
{
	if((i >= heapSize) && (newVal > A[i]))
	{
		return -1;
	}
	A[i] = newVal;
	Parn_child_swap(A,i);
	return 1;
}

int getMax(int A[])
{
	int temp;
	if(heapSize <= 0)
	{
		return -1;
	}
	temp = A[0];
	return temp;
}
void Print(int A[])
{
	int i;
	for(i=0;i<heapSize;i++)
	{
		printf("%d\n",A[i]);
	}
}
int main(int argc,char **argv)
{
	char line[128];
	char v1[15];
	char v2[15];
	char v3[15];
	
	int lineNo = 0;
	int ret,n;
	int *A;
	while(fgets(line,sizeof line,stdin) != NULL)
	{
		sscanf(line,"%s %s %s",v1,v2,v3);
		lineNo++;
		
		if(lineNo == 1)
		{
			n = stoi(v1);
			A = (int*)malloc(sizeof(int)*n);
			continue;
		}
		if(strcmp(v1,"INS") == 0)
		{
			ret = insertKey(A,stoi(v2),n);
			if(ret == -1)
			{
				printf("%d\n",-1);
			}
		}
		else if(strcmp(v1,"DEL") == 0)
		{
			ret = deleteKey(A,stoi(v2));
			if(ret == -1)
			{
				printf("%d\n",-1);
			}
		}
		else if(strcmp(v1,"EXT") == 0)
		{
			ret = extractMax(A);
			printf("%d\n",ret);
		}
		else if(strcmp(v1,"PRT") == 0)
		{
			Print(A);
		}
		else if(strcmp(v1,"INC") == 0)
		{
			ret = increaseKey(A,stoi(v2),stoi(v3));
			if(ret == -1)
			{
				printf("%d\n",-1);
			}
		}
		else if(strcmp(v1,"MAX") == 0)
		{
			ret = getMax(A);
			if(ret == -1)
			{
				printf("%d\n",-1);
			}
			printf("%d\n",ret);
		}
		else
		{
			printf("INVALID\n");
		}
	}
	if(A)
	free(A);
	
	return 0;
}
