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

typedef struct node
{
	char data;
	struct node* next;
}Node;

Node* head = NULL;

int isEmpty()
{
	if(head == NULL)
	{
		return 1;
	}
	return 0;
}
Node* Push(char key)
{
	Node* node = (Node*)malloc(sizeof(Node));
	
	node->data = key;
	node->next = head;
	head = node;
	
	return head;
}

void Pop()
{
	if(isEmpty())
	{
		printf("%d\n",-1);
		return;
	}

	printf("%c\n",head->data);
	head = head->next;
}

void Size()
{
	Node* temp = head;
	int i = 0;
	if(temp == NULL)
	{
		printf("%d\n",0);
		return;
	}
	while(temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	printf("%d\n",i+1);
	return;
}

void Peek()
{
	if(isEmpty())
	{
		printf("%d\n",-1);
		return;
	}

	printf("%c\n",head->data);
	return;
}

void Print()
{
	Node* temp = head;
	while(temp != NULL)
	{
		printf("%c\n",temp->data);
		temp = temp->next;
	}
	return;
}
int main(int argc,char **argv)
{
	char line[128];
	char v1[15];
	char v2;
	
	int lineNo = 0;
	int ret;
	
	while(fgets(line,sizeof line,stdin) != NULL)
	{
		sscanf(line,"%s %c",v1,&v2);
		lineNo++;
		
		if(strcmp(v1,"PSH") == 0)
		{
			Push(v2);
		}
		else if(strcmp(v1,"POP") == 0)
		{
			Pop();
		}
		else if(strcmp(v1,"TOP") == 0)
		{
			Peek();
		}
		else if(strcmp(v1,"SZE") == 0)
		{
			Size();
		}
		else if(strcmp(v1,"EMP") == 0)
		{
			ret = isEmpty();
			printf("%d\n",ret);
		}
		else if(strcmp(v1,"PRT") == 0)
		{
			Print();
		}
	}
	return 0;
}
