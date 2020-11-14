#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Code to parse integer from a string
int stoi(char *str)
{
    int x;
    sscanf(str, "%d", &x);
    return x;
}

int topP=0,topN=0,top = -1;
int n1,n2;
int *A;

int Push(int key)
{
	if(topP >= n1 && topN >= n2)
	{
		return -1;
	}
	if(key < 0)
	{
		if(topN >= n2)
		{
			return -1;
		}
		topN++;
		top++;
		A[top] = key;
	}
	else
	{
		if(topP >= n1)
		{
			return -1;
		}
		topP++;
		top++;
		A[top] = key;
	}
	return 1;
}

int popP()
{
	int i=top,temp,j,c;
	if(topP == 0)
	{
		return -1;
	}
	while((A[i] < 0) && (i>0))
	{
		i--;
	}

	for(j=i;j<top;j++)
	{
		temp = A[j];
		A[j] = A[j+1];
		A[j+1] = temp;
	}
	c=A[top];
	topP--;
	top--;
	return c;
}


int popN()
{
	int i=top,temp,j,c;
	if(topN == 0)
	{
		return -1;
	}
	while((A[i] >= 0) && (i>0))
	{
		i--;
	}

	for(j=i;j<top;j++)
	{
		temp = A[j];
		A[j] = A[j+1];
		A[j+1] = temp;
	}
	c = A[top];
	topN--;
	top--;
	return c;
}

void printP()
{
	int i;
	for(i=top;i>=0;i--)
	{
		if(A[i] >= 0)
		printf("%d\n",A[i]);
	}
}

void printN()
{
	int i;
	for(i=top;i>=0;i--)
	{
		if(A[i] < 0)
		printf("%d\n",A[i]);
	}
}

int main(int argc,char **argv)
{
	char line[128];
	char v1[25];
	char v2[15];
	
	int lineNo = 0;
	int ret;
	while(fgets(line,sizeof line,stdin) != NULL)
	{
		sscanf(line,"%s %s",v1,v2);
		lineNo++;
		
		if(lineNo == 1)
		{
			n1 = stoi(v1);
			A = (int*)malloc(sizeof(int)*n1);
		}
		
		if(lineNo == 2)
		{
			n2 = stoi(v1);
			A = (int*)malloc(sizeof(int)*n2);
		}
		
		if(strcmp(v1,"PSH") == 0)
		{
			ret = Push(stoi(v2));
			if(ret < 0)
            {
                printf("%d\n", -1);
            }
		}
		else if(strcmp(v1,"POPP") == 0)
		{
			ret = popP();
			printf("%d\n",ret);
		}
		else if(strcmp(v1,"POPN") == 0)
		{
			ret = popN();
			printf("%d\n",ret);
		}
		else if(strcmp(v1,"PRTP") == 0)
		{
			printP();
		}
		else if(strcmp(v1,"PRTN") == 0)
		{
			printN();
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
