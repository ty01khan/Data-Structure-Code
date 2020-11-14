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

int top=-1,n;

void Push(int A[],int key)
{
    /* Insert the element key into the heap represented by A.
    Return 1 if the operation is successful and -1 otherwise. */
	if(top == n-1)
	{
		printf("-1\n");
	}
	else
	{
		top++;
		A[top] = key;
	}
}

int Pop(int A[])
{
    /* Delete the element A[i] from the heap represented by A.
    Return 1 if the operation is successful and -1 otherwise. */
    int temp,i;
	if(top == -1)
	{
		printf("-1\n");
	}
	else
	{
		temp = A[top];
		top--;
		printf("%d\n",temp);
	}
}

void Peek(int A[])
{
	if(top == -1)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n",A[0]);
	}
}
void Print(int A[])
{
    /* Display the heap represented by A in the increasing order
    of their indices, one element per line.*/

	int i;
	if(top == -1)
	{
		printf("-1\n");
	}
	for(i=top;i>=0;i--)
	{
		printf("%d\n",A[i]);
	}
}

void Size()
{
	printf("%d\n",top+1);
}

void isEmpty()
{
	if(top == -1)
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}
}

void isFull()
{
	if(top == n-1)
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}
}

int main (int argc, char **argv)
{
    char line[128];
    char v1[15];
    char v2[15];
    char v3[15];

    int *A = NULL;
    int ret;
    int lineNo = 0;

    while (fgets(line, sizeof line, stdin) != NULL )
    {
        sscanf(line, "%s %s %s", v1, v2, v3);
        lineNo++;

        if(lineNo == 1)
        {
        	n = stoi(v1);
            A = (int*) malloc(sizeof(int)* stoi(v1));
            continue;
        }

        if(strcmp(v1,"PSH") == 0)
        {
            Push(A,stoi(v2));
        }
        else if(strcmp(v1,"POP") == 0)
        {
            Pop(A);
        }
        else if(strcmp(v1,"TOP") == 0)
        {
        	Peek(A);
        }
        else if(strcmp(v1,"SZE") == 0)
        {
            Size();
        }
        else if(strcmp(v1,"PRT") == 0)
        {
            Print(A);
        }
        else if(strcmp(v1,"EMP") == 0)
        {
            isEmpty();
        }
        else if(strcmp(v1,"FUL") == 0)
        {
            isFull();
        }
        else
        {
            printf("INVALID\n");
        }
    }

    if(A)
        free(A);

    return 0;
}
