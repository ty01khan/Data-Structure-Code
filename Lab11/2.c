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
	struct node* next;
	struct node* prev;
}Node;

Node** A;

int Search(int i,int key)
{
	Node* temp = A[i];
	
	while(temp != NULL)
	{
		if(temp->data == key)
		{
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}

void Insert(int i,int key)
{
	Node* temp = A[i];
	
	if(temp == NULL)
	{
		temp = (Node*)malloc(sizeof(Node));
		temp->data = key;
		temp->next = NULL;
		temp->prev = NULL;
		A[i] = temp;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = (Node*)malloc(sizeof(Node));
		temp->next->data = key;
		temp->next->next = NULL;
		temp->next->prev = temp;
		while(temp->prev != NULL)
		{
			temp = temp->prev;
		}
		A[i] = temp;
	}
}

void Delete(int i,int key)
{
	Node* temp = A[i];
	
	if(temp->data == key)
	{
		if(temp->next == NULL)
		{
			temp = NULL;
			A[i] = temp;
			return;
		}
		temp = temp->next;
		temp->prev = NULL;
		A[i] = temp;
	}
	else
	{
		while(temp->data != key)
		{
			temp = temp->next;
		}
		if(temp->next == NULL)
		{
			temp->prev->next = NULL;
		}
		else
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
		}
		while(temp->prev != NULL)
		{
			temp = temp->prev;
		}
		A[i] = temp;
	}
	return;
}

void Print(int i)
{
	Node* temp = A[i];
	if(temp == NULL)
	{
		printf("-1");
		return;
	}

	while(temp != NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	return;
}
int main(int argc,char **argv)
{
	char line[128];
	char v1[15];
	char v2[15];
	
	int lineNo = 0;
	int n,i,x,a,ret;
	
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
		
		if(strcmp(v1,"INS") == 0)
		{
			x = stoi(v2);
			a = x % n;
			ret = Search(a,x);
			if(ret == 1)
			{
				printf("-1\n");
			}
			else
			{
				Insert(a,x);
			}
		}
		else if(strcmp(v1,"SRCH") == 0)
		{
			x = stoi(v2);
			a = x % n;
			ret = Search(a,x);
			if(ret == 0)
			{
				printf("N\n");
			}
			else if(ret == 1)
			{
				printf("Y\n");
			}
		}
		else if(strcmp(v1,"DEL") == 0)
		{
			x = stoi(v2);
			a = x % n;
			ret = Search(a,x);
			if(ret == 0)
			{
				printf("-1\n");
			}
			Delete(a,x);
		}
		else if(strcmp(v1,"PRT") == 0)
		{
			a = stoi(v2);
			Print(a);
			printf("\n");
		}
	}
	return 0;
}
