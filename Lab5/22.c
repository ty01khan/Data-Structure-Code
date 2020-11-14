#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top=-1;
char B[128];

void Push(char key)
{
	top++;
	B[top] = key;
}

char Pop()
{
	if(top == -1)
	{
		exit;
	}
	char temp;
	temp = B[top];
	top--;
	return temp;
}

int match(char a,char b)
{
	if(a == '[' && b == ']')
	{
		return 1;
	}
	if(a == '(' && b == ')')
	{
		return 1;
	}
	if(a == '{' && b == '}')
	{
		return 1;
	}
	return 0;
}

int check(char A[])
{
	int i;
	char temp;
	
	for(i=0;i<strlen(A);i++)
	{
		if(A[i] == '(' || A[i] == '{' || A[i] == '[')
		{
			Push(A[i]);
		}
		if(A[i] == ')' || A[i] == '}' || A[i] == ']')
		{
			temp = Pop();
			if(!match(temp,A[i]))
			{
				return 0;
			}
		}
	}
	if(top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{	
	char A[128];
	int ret;
	scanf("%s",A);
	ret = check(A);
	if(ret == 1)
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}
	return 0;
}
