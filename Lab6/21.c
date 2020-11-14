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
char A[50];

int isEmpty()
{
	if(top == -1)
	{
		return 1;
	}
	return 0;
}
void Push(char key)
{
	top++;
	A[top] = key;
}

char Pop()
{	
	char temp;
	if(isEmpty())
	{
		return 'x';
	}
	temp = A[top];
	top--;
	return temp;
}

char Peek()
{
	if(isEmpty())
	{
		return 'x';
	}
	return A[top];
}
int Prec(char c)
{
	if((c == '*') || (c == '/'))
	{
		return 1;
	}
	else if((c == '+') || (c == '-'))
	{
		return 0;
	}
}
int main(int argc,char **argv)
{
	char string[128];
	char *ptr,ch;
	char ret,ret1,ret2;
	
	fscanf(stdin,"%s",string);
	ptr = string;
	
	while(*ptr != '\0')
	{
		ch = *ptr;
		
		if((ch >= 'a') && (ch<= 'z'))
		{
			printf("%c",ch);
		}
		else if(ch == '(')
		{
			Push(ch);
		}
		else if(ch == ')')
		{
			while(A[top] != '(')
			{
				ret = Pop();
				printf("%c",ret);
			}
			ret = Pop();
		}
		else if((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/'))
		{
			while(1)
			{
				if((isEmpty()) || (A[top] == '('))
				{
					Push(ch);
					break;
				}
				else
				{
					ret1 = Prec(A[top]);
					ret2 = Prec(ch);
					if(ret2 > ret1)
					{
						Push(ch);
						break;
					}
					else if(ret1 > ret2)
					{
						ret = Pop();
						printf("%c",ret);
					}
					else if(ret2 == ret1)
					{
						ret = Pop();
						printf("%c",ret);
						Push(ch);
						break;
					}

				}
			}
		}
		ptr++;
	}
	while(!isEmpty())
	{
		ret = Pop();
		printf("%c",ret);
	}
	printf("\n");
	return 0;
}
