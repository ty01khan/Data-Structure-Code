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
void merge(int A[],int B[],int M[],int m,int n)
{
	/* Fill in */
	int i=0,j=0,k=0;
	while((i < n) && (j < m))
	{
		if(A[i] > B[j])
		{
			M[k] = B[j];
			j++;
		}
		else
		{
			M[k] = A[i];
			i++;
		}
		k++;
	}
	while(i < n)
	{
		M[k] = A[i];
		i++;
		k++;
	}
	while(j < m)
	{
		M[k] = B[j];
		j++;
		k++;
	}
	for(k=0;k<(m+n);k++)
	{
		printf("%d\n",M[k]);
	}
}

int main (int argc, char **argv)
{
    char line[128];
    char v1[15];
    char v2[15];
    char v3[15];

    int *A = NULL;
    int *B = NULL;
    int *M = NULL;
    int n,i,m;
	int lineNo = 0;
	
    fgets(line, sizeof line, stdin);
    sscanf(line, "%s", v1);
    lineNo++;
    
    n=stoi(v1);
    A = (int*) malloc(sizeof(int)* n);
    for(i=0;i<n;i++)
    {
		fgets(line, sizeof line, stdin);
 		sscanf(line, "%s", v1);
		A[i]= stoi(v1);
    }
    
    fgets(line, sizeof line, stdin);
    sscanf(line, "%s", v1);
    m=stoi(v1);
    B = (int*) malloc(sizeof(int)* m);
    for(i=0;i<m;i++)
    {
		fgets(line, sizeof line, stdin);
 		sscanf(line, "%s", v1);
		B[i]= stoi(v1);
    }
    
    M = (int*) malloc(sizeof(int)*(n+m));
    
    merge(A,B,M,m,n);
    if(A)
        free(A);
    return 0;
}
