#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stoi(char *str)
{
	int x;
	sscanf(str,"%d",&x);
	return x;
}

int top = -1;
int A[50];

int isEmpty()
{
	if(top == -1)
	{
		return 1;
	}
	return 0;
}

void Push(int key)
{
	top++;
	A[top] = key;
}

int Pop()
{
	int temp;
	if(isEmpty())
	{
		return -1;
	}
	temp = A[top];
	top--;
	return temp;
}

int main(int argc,char **argv)
{
	char line[128];
	char v1[15];
	
	int lineNo = 0;
	int a,b,c;
	
	while(fgets(line,sizeof line,stdin) != NULL)
	{
		sscanf(line,"%s",v1);
		lineNo++;
		
		if((*v1 != '+') && (*v1 != '-') && (*v1 != '*') && (*v1 != '/'))
		{
			Push(stoi(v1));
		}
		else if((*v1 == '+') || (*v1 == '-') || (*v1 == '*') || (*v1 == '/'))
		{
			if(top < 1)
			{
				printf("invalid\n");
				return 0;
			}
			a = Pop();
			b = Pop();
			
			if(*v1 == '+')
			{
				c = b + a;
			}
			else if(*v1 == '-')
			{
				c = b - a;
			}
			else if(*v1 == '*')
			{
				c = b * a;
			}
			else if(*v1 == '/')
			{
				if(a == 0)
				{
					printf("division by 0\n");
					return 0;
				}
				c = b / a;
			}
			Push(c);
		}
		else
		{
			printf("invalid\n");
		}
	}
	if(lineNo == 0)
	{
		printf("invalid\n");
		return 0;
	}
	if(top >= 1)
	{
		printf("invalid\n");
	}
	else
	{
		printf("%d\n",Pop());
	}
	return 0;
}
