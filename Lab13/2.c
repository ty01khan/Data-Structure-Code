#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stoi(char *str)
{
	int a;
	sscanf(str,"%d",&a);
	return a;
}
int *A;
int rear = 0,frnt = 0;
int G[100][100],dist[100];

int isEmpty()
{
	if(rear == frnt)
	return 1;
	
	return 0;
}
void enQueue(int x)
{	
	A[rear] = x;
	rear++;
}

int deQueue()
{
	int temp;
	temp = A[frnt];
	frnt++;
	return temp;
}

void BFS(int p,int n)
{
	int x,i;
	for(i=0;i<n;i++)
	{
		dist[i] = -1;
	}
	dist[p] = 0;
	enQueue(p);
	//a = isEmpty()
	while(isEmpty() != 1)
	{
		x = deQueue();
		for(i=0;i<n;i++)
		{
			if((dist[i] == -1) && (G[x][i] == 1))
			{
				enQueue(i);
				dist[i] = dist[x] + 1;
			}
		}
	}
}
int main(int argc,char **argv)
{
	char line[128];
	char v1[15];
	char v2[15];
	int i,j,s,n,t;
	int lineNo = 0;
	
	while(fgets(line,sizeof line,stdin) != NULL)
	{
		sscanf(line,"%s %s",v1,v2);
		lineNo++;
		
		if(lineNo == 1)
		{
			n = stoi(v1);
			A = (int*)malloc(sizeof(int)*n);
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					G[i][j] = 0;
				}
			}
			continue;
		}
		
		if(lineNo == 2)
		{
			s = stoi(v1);
			t = stoi(v2);
			
			continue;
		}
	
		G[stoi(v1)][stoi(v2)] = 1;
	}
	
	BFS(s,n);
	for(i=0;i<n;i++)
	{
		if(i == t)
		{
			printf("dist(%d,%d)=%d",s,t,dist[t]);
		}
	}
	
	return 0;
}
