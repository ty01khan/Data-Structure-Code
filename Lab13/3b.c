#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stoi(char *str)
{
    int a;
    sscanf(str, "%d",&a);
    return a;
}

void Sort(int A[],char S[],int n)
{
	int i,temp1,temp2;
	for(i=1;i<n;i++)
	{
		if(A[i-1] > A[i])
		{
			temp1 = A[i];
			temp2 = S[i];
			A[i] = A[i-1];
			S[i] = S[i-1];
			A[i-1] = temp1;
			S[i-1] = temp2;
		}
	}
}


void Execute(int A[],char S[],int n,int j)
{
	if(j == 0)
	{
		printf("%d\n",-1);
        return;
	}
	int i;
	printf("%c\n",S[0]);
	for(i=1;i<n;i++)
	{
		A[i-1] = A[i];
		S[i-1] = S[i];
	}
}
int main(int argc,char **argv)
{
    char line[128];
    char v1[15];
    char v2;
    char v3[15];
    int n,j=-1,i,ret,x;
    int *A;
    char *S;
    int lineNo = 0;
    
    while(fgets(line,sizeof line,stdin) != NULL)
    {
       sscanf(line,"%s %c %s",v1,&v2,v3);
       lineNo++;
       if(lineNo == 1)
       {
           n = stoi(v1);
           A = (int*)malloc(sizeof(int)*n);
           S = (char*)malloc(sizeof(char)*n);
          for(i=0;i<n;i++)
           {
               A[i] = -1;
           }
           continue;  
       }
       
       if(strcmp(v1,"ADD") == 0)
       {
    	   if(j>=n)
 	       {
 		       printf("-1\n");
 		       return -1;
 	       }
 	       j++;
           S[j] = v2;
           A[j] = stoi(v3);
           Sort(A,S,n);
       }
       else if(strcmp(v1,"EXE") == 0)
       {
		   Execute(A,S,n,j);
           j--;
       }	
    }
    
    return 0;
}
