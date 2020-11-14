#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stoi(char *str)
{
	int x;
	sscanf(str,"%d",&x);
	return x;
}

int *A;
int n;

void Insert(int key)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		j = (((key % n) + i) % n);
		printf("%d(%d) ",j,A[j]);
		if((A[j] == -1) || (A[j] == key) || (A[j] == -2))
		{
			A[j] = key;
			return;
		}
	}
}

void Search(int key)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		j = (((key % n) + i) % n);
		printf("%d(%d) ",j,A[j]);
		if((A[i] == key) || (A[i] == -1))
		{
			return;
		}
	}
}

void Delete(int key)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		j = (((key % n) + i) % n);
		printf("%d(%d) ",j,A[j]);
		if(A[i] == key)
		{
			A[i] = -2;
			return;
		}
		else if((A[i] == -1))
		{
			return;
		}
	}
}
int main(int argc,char **argv)
{
	char line[128];
	char v1[15];
	char v2[15];
	
	int lineNo = 0;
	int ret,i;
	
	while(fgets(line,sizeof line,stdin) != NULL)
	{
		sscanf(line,"%s %s",v1,v2);
		lineNo++;
		
		if(lineNo == 1)
		{
			n = stoi(v1);
			A  =(int*)malloc(sizeof(int)*n);
			for(i=0;i<n;i++)
			{
				A[i] = -1;
			}
			continue;
		}
		
		if(strcmp(v1,"INS") == 0)
		{
			Insert(stoi(v2));
			printf("\n");
		}
		else if(strcmp(v1,"DEL") == 0)
		{
			Delete(stoi(v2));
			printf("\n");
		}
		else if(strcmp(v1,"SRCH") == 0)
		{
			Search(stoi(v2));
			printf("\n");
		}
	}
	return 0;
}
