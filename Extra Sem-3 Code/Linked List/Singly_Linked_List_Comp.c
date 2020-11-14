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
}Node;

Node* head = NULL;

Node* Insert_Beg(int x)
{
	Node* node;
	node = (Node*)malloc(sizeof(node));
	node->data = x;
	node->next = head;
	head = node;
	return head;
}

Node* Insert_Pos(int x,int pos)
{
	int i;
	Node* node;
	Node* temp = head;
	node = (Node*)malloc(sizeof(Node));
	
	if(pos == 1)
	{
		node->data = x;
		node->next = head;
		head = node;
		return head;
	}
	for(i=0;i<pos-2;i++)
	{	
		temp = temp->next;
	}

	node->data = x;
	node->next = temp->next;
	temp->next = node;
	return head;
}

Node* Insert_End(int x)
{
	Node* node;
	Node* temp = head;
	
	if(temp == NULL)
	{
		node = (Node*)malloc(sizeof(Node));
		node->data = x;
		node->next = NULL;
		head = node;
		return head;
	}
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	node = (Node*)malloc(sizeof(Node));
	node->data = x;
	node->next = NULL;
	temp->next = node;
	return head;
}

Node* Delete_Beg()
{
	head = head->next;
	return head;
}

Node* Delete_Pos(int pos)
{
	int i;
	Node* temp = head;
	for(i=0;i<pos-2;i++)
	{
		temp = temp->next;
	}
	temp->next = temp->next->next;
	return head;
}

Node* Delete_End()
{
	Node* temp = head;
	if(temp->next == NULL)
	{
		head = NULL;
		return head;
	}
	while(temp->next->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = NULL;
	return head;
}

Node* Delete_Num(int n)
{

	Node* temp = head;
	if(temp->data == n)
	{
		head = head->next;
		return head;
	}
	while(temp->next->data != n)
	{
		temp = temp->next;
	}
	temp->next = temp->next->next;
	return head;
}
int Search(int n)
{
	Node* temp = head;
	while((temp->data != n))
	{
		if(temp->next == NULL)
		{
			return 0;
		}
		temp = temp->next;
	}
	if(temp->data == n)
	{
		return 1;
	}
}

void Size()
{
	Node* temp = head;
	int i = 0;
	while(temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	printf("%d\n",i);
}
void Print()
{
	Node* temp = head;
	if(temp == NULL)
	{
		printf("Linked List is Empty\n");
		return;
	}
	else
	{
		while(temp != NULL)
		{
			printf("%d ",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main(int argc, char **argv)
{
    char line[128];
    char v1[15];
    char v2[15];
    char v3[15];

    int lineNo = 0;
    int n,ret,i,x,j;

    while (fgets(line, sizeof line, stdin) != NULL )
    {
        sscanf(line, "%s %s %s", v1, v2, v3);
        lineNo++;

        if(lineNo == 1)
        {
            n = stoi(v1);
            continue;
        }

        if(strcmp(v1,"INSB") == 0)
        {
            if(n <= 0)
            {
                printf("-1\n");
            }
            else
            {
            	Insert_Beg(stoi(v2));
            }
        }
        else if(strcmp(v1,"INSP") == 0)
        {
            if(n <= 0)
            {
                printf("-1\n");
            }
            else
            {
            	Insert_Pos(stoi(v2),stoi(v3));
            }
        }
        else if(strcmp(v1,"INSE") == 0)
        {
            if(n <= 0)
            {
                printf("-1\n");
            }
            else
            {
            	Insert_End(stoi(v2));
            }
        }
        else if(strcmp(v1,"PRT") == 0)
        {
			Print();
        }

        else if(strcmp(v1,"SRCH") == 0)
        {
            if(n <= 0)
            {
                printf("N\n");
            }
            else
            {
            	ret = Search(stoi(v2));
            	if(ret == 1)
            	{
                	printf("Y\n");
            	}
            	else if(ret == 0)
            	{
                	printf("N\n");
            	}
            }
        }
        else if(strcmp(v1,"DELB") == 0)
        {
            if(n <= 0)
            {
                printf("-1\n");
            }
            else
            {
                Delete_Beg();
            }
        }
        else if(strcmp(v1,"DELP") == 0)
        {
            if(n <= 0)
            {
                printf("-1\n");
            }
            else
            {
                Delete_Pos(stoi(v2));
            }
        }
        else if(strcmp(v1,"DELE") == 0)
        {
            if(n <= 0)
            {
                printf("-1\n");
            }
            else
            {
                Delete_End();
            }
        }
        else if(strcmp(v1,"DELN") == 0)
        {
            if(n <= 0)
            {
                printf("-1\n");
            }
            else
            {
            	ret = Search(stoi(v2));
            	if(ret == 1)
            	{
                	Delete_Num(stoi(v2));
                }
                else if(ret == 0)
                {
                	printf("%d is not in LL\n",n);
                }
            }
        }
        else if(strcmp(v1,"SZE") == 0)
        {
            if(n <= 0)
            {
                printf("%d\n",n);
            }
            else
            {
                Size();
            }
        }
    }

    return 0;
}
