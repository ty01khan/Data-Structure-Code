#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stoi(char *str)
{
	int a;
	sscanf(str,"%d",&a);
	return a;
}

int front = 0,rear = 0;

int Size(int A[],int n)
{
	int s;
	s = (n - front + rear) % n;
	return s;
}

int isEmpty()
{
	if(front == rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isFull(int A[],int n)
{
	int ret;
	ret = Size(A,n);
	if(ret == n - 1)
	{
		return 1;
	}
	return 0;
}

void enQueue(int A[],int key,int n)
{
	int ret;
	ret = isFull(A,n);
	if(ret == 1)
	{
		printf("%d\n",-1);
	}
	A[rear] = key;
	rear = (rear + 1) % n;
	//printf("%d\n",rear);
}

int deQueue(int A[],int n)
{
	int temp; 
	if(isEmpty())
	{
		return -1;
	}
	temp = A[front];
	front = (front + 1) % n;
	return temp;
}

int peekFront(int A[])
{
	int temp; 
	if(isEmpty())
	{
		return -1;
	}
	temp = A[front];
	return temp;
}

void Print(int A[],int n)
{
	int temp = front;
	while(front != rear)
	{
		printf("%d\n",A[front]);
		front = (front + 1) % n;
	}
	front = temp;
	return;
}
int main(int argc,char **argv)
{
	char line[128];
	char v1[15];
	char v2[15];
	
	int lineNo = 0;
	int ret,n;
	int *A;
	
	while(fgets(line,sizeof line,stdin) != NULL)
	{
		sscanf(line,"%s %s",v1,v2);
		lineNo++;
		
		if(lineNo == 1)
		{
			n = stoi(v1);
			A = (int*)malloc(sizeof(int)*n);
			continue;
		}
		
		if(strcmp(v1,"ENQ") == 0)
		{
			enQueue(A,stoi(v2),n);
		}
		else if(strcmp(v1,"DEQ") == 0)
		{
			ret = deQueue(A,n);
			printf("%d\n",ret);
		}
		else if(strcmp(v1,"FRN") == 0)
		{
			ret = peekFront(A);
			printf("%d\n",ret);

		}
		else if(strcmp(v1,"SZE") == 0)
		{
			ret = Size(A,n);
			printf("%d\n",ret);
		}
		else if(strcmp(v1,"EMP") == 0)
		{
			ret = isEmpty();
			if(ret == 1)
			{
				printf("%d\n",ret);
			}
			else if(ret == 0)
			{
				printf("%d\n",ret);
			}
		}
		else if(strcmp(v1,"FUL") == 0)
		{
			ret = isFull(A,n);
			if(ret == 1)
			{
				printf("%d\n",ret);
			}
			else if(ret == 0)
			{
				printf("%d\n",ret);
			}
		}
		else if(strcmp(v1,"PRT") == 0)
		{
			Print(A,n);
		}
		else
		{
			printf("INVALID\n");
		}
	}
	return 0;
}
