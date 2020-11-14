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
	int val;
	struct node *next;
}node;

node **A;
int visited[100];

node *insert(node *head,int data)
{
	node *nnode = (node*)malloc(sizeof(node));
	nnode->val = data;
	nnode->next = NULL;

	if(head == NULL)
	{
		return nnode;
	}

	nnode->next = head;
	return nnode;
}

int pop(node **head)
{
	int d;

	node *del = *head;

	d = (*head)->val;
	(*head) = (*head)->next;

	free(del);

	return d;
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
			A = (node**)malloc((sizeof(node*))*n);
			for(i = 0;i < n;i++)
			{
				A[i] = NULL;
			}
			continue;
		}

		i = stoi(v1);

		A[i] = insert(A[i],stoi(v2));
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i=j)
			{
				printf("dist(i,j)=0\n");
			}
				
		}
	}

	return 0;
}

