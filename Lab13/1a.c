#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int top = 30;

typedef struct node
{
	char ch;
	struct node* next;
	struct node* prev;
}Node;


Node* Stack[31];
int isEmpty()
{
	if(top == -1)
	{
		return 1;
	}
	return 0;
}

void push(Node* str)
{
	int i = isEmpty();
	if(i == 1)
	{
		return;
	}
	else
	{
		Stack[top] = str;
		top--;
	}
}

Node* Pop()
{
	Node *Exp;
	if(top >= 30)
	{
		return NULL;
	}
	else
	{
		Exp = Stack[++top];
		return Exp;
	}
}

void convert(char Exp[])
{
	Node *ch1,*ch2;
	Node *temp;
	
	int i;
	for(i=0;i<Exp[i] != '\0';i++)
	{
		if((Exp[i] >= 'a' && Exp[i] <= 'z') || (Exp[i] >= 'A' && Exp[i] <= 'Z'))
		{
			temp = (Node*)malloc(sizeof(Node));
			temp->ch = Exp[i];
			temp->next = NULL;
			temp->prev = NULL;
			push(temp);
		}
		else if(Exp[i] == '+' || Exp[i] == '-' || Exp[i] == '*' || Exp[i] == '/')
		{
			ch1 = Pop();
			ch2 = Pop();
			temp = (Node*)malloc(sizeof(Node));
			temp->ch = Exp[i];
			temp->next = ch1;
			temp->prev = ch2;
			push(temp);
		}
	}
}

void Print(Node *temp)
{
	if(temp != NULL)
	{
		Print(temp->prev);
		printf("%c",temp->ch);
		Print(temp->next);
	}
}

int main()
{
	char Exp[50];

	scanf("%s",Exp);
	convert(Exp);
	Print(Pop());

	//printf("\n");
	return 0;
}
