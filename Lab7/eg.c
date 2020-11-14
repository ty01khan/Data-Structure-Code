#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stoi(char *str)
{
	int x;
	sscanf(str,"%d",&x);
	return x;
}

typedef struct node
{
	int data;
	struct node *next;
}Node;

Node** A;
int visited[100];

Node* Insert(int a,int b)
{
	Node* temp = A[a];
	Node* node = (Node*)malloc(sizeof(Node));
	
	if(temp == NULL)
	{
		A[a]->data = b;
		A[a]->next = NULL;
		return A[a];
	}
	node->data = b;
	node->next = A[a];
	A[a] = node;
	return A[a];
}

int Pop(int a)
{
	int d;
	Node* temp = A[a];

	d = A[a]->data;
	A[a] = A[a]->next;
	free(temp);
	return d;
}

int *Sort(int B[],int v,int p)
{
	int i,t;
	B[p] = v;
	for(i=p-1;i>=0;i--)
	{
		if(B[i+1] < B[i])
		{
			t = B[i];
			B[i] = B[i+1];
			B[i+1] = t;
		}
	}
	return B;
}

void DFS(int i,int n)
{
	int B[n],s,v,j,t;
	int *ptr;
	Node* temp =  A[i];
	visited[i] = 1;
	
	s = 0;
	while(temp != NULL)
	{
		v = Pop(i);
		ptr = Sort(B,v,s);
		s++;
	} 
	
	for(j=0;j<s;j++)
	{
		t = B[j];
		if(visited[t] != 1)
		{
			printf("(%d,%d)\n",i,t);
		}
	}
	
	for(j=0;j<s;j++)
	{
		t = B[j];
		if(visited[t] != 1)
		{
			DFS(t,n);
		}
	}
}
int main(int argc,char **argv)
{
	char line[128];
	char v1[15];
	char v2[15];

	int lineNo = 0;
	int n,i,j;

	while(fgets(line,sizeof line,stdin) != NULL)
	{
		sscanf(line,"%s %s",v1,v2);
		lineNo++;
		
		if(lineNo == 1)
		{
			n = stoi(v1);
			A = (Node**)malloc(sizeof(Node*)*n);
			for(i=0;i<n;i++)
			{
				A[i] = NULL;
			}
			continue;
		}
		Insert(stoi(v1),stoi(v2));
	}
	for(i=0;i<n;i++)
	{
		visited[i] = 0;
	}
	j = 0;
	DFS(j,n);
	return 0;
}
