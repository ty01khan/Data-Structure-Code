#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stoi(char *str)
{
	int x;
	sscanf(str,"%d",&x);
	return x;
}

int A[100],Pre[100],Ino[100],Post[100],Pos[100];
int pr = 0,in = 0,pt = 0;
int i = 0,k = 0,p = 1;

void Insert_left(int key,int j)
{
	int left,a;
	left = (2*j)+1;

	A[left] = key;
	Pos[p] = key;
	p++;
	k = left;
	k++;
}

void Insert_right(int key,int j)
{
	int right,a;
	right = (2*j)+2;

	A[right] = key;
	Pos[p] = key;
	p++;
	k = right;
	k++;
}

void Preorder(int i)
{
	int left,right;
	left = (2*i)+1;
	right = (2*i)+2;
	
	if(A[i] != -1)
	{
		Pre[pr] = A[i];
		printf("%d ",Pre[pr]);
	}
	pr++;
	
	if(left < k)
	{
		Preorder(left);
	}
	
	if(right < k)
	{
		Preorder(right);
	}
	
	return;
}

void Inorder(int i)
{
	int left,right;
	left = (2*i)+1;
	right = (2*i)+2;
	
	if(left < k)
	{
		Inorder(left);
	}
	
	if(A[i] != -1)
	{
		Ino[in] = A[i];
		printf("%d ",Ino[in]);
	}
	in++;
	
	if(right < k)
	{
		Inorder(right);
	}
	
	return;
}

void Postorder(int i)
{
	int left,right;
	left = (2*i)+1;
	right = (2*i)+2;
	
	if(left < k)
	{
		Postorder(left);
	}
	
	if(right < k)
	{
		Postorder(right);
	}

	if(A[i] != -1)
	{
		Post[pt] = A[i];
		printf("%d ",Post[pt]);
	}
	pt++;
	
	return;
}

void Occur(int key)
{
	int i,count = 0;
	for(i=0;i<k;i++)
	{
		if(A[i] == key)
		{
			count++;
		}
	}

	printf("%d\n",count);
	return;
}

int main(int argc,char **argv)
{
	char line[128];
	char v1[15];
	char v2[15];
	char v3[15];
	char v4;
	
	int lineNo = 0;
	int a,ret,b,m;
	
	while(fgets(line,sizeof line,stdin) != NULL)
	{	
		sscanf(line,"%s %s %s %c",v1,v2,v3,&v4);
		lineNo++;
		
		if(lineNo == 1)
		{
			for(a=0;a<100;a++)
			{
				A[a] = -1;
			}
			Pos[p] = stoi(v1);
			p++;
			A[k] = stoi(v1);
			k++;
			continue;
		}
			
		if(strcmp(v1,"INS") == 0)
		{
			if((stoi(v3) > k) || (A[stoi(v3) - 1] == -1))
			{
				printf("-1\n");
			}
			else
			{
				b = Pos[stoi(v3)];
				for(m=0;m<k;m++)
				{
					if(A[m] == b)
					{
						break;
					}
				}
				//printf("%d-\n",m);
				if(v4 == 'l')
				{
					Insert_left(stoi(v2),m);
				}
				else if(v4 == 'r')
				{
					Insert_right(stoi(v2),m);
				}
			}
		}
		else if(strcmp(v1,"PRE") == 0)
		{
			Preorder(0);
			printf("\n");
		}
		else if(strcmp(v1,"PST") == 0)
		{
			Postorder(0);
			printf("\n");
		}
		else if(strcmp(v1,"INO") == 0)
		{
			Inorder(0);
			printf("\n");
		}
		else if(strcmp(v1,"OCC") == 0)
		{
			Occur(stoi(v2));
		}
	}
	
	return 0;
}
