#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stoi(char *str)
{
	int x;
	sscanf(str,"%d",&x);
	return x;
}
	
int *A;
int *Ino,*Pre,*Pst;

int n,in = 0,pr = 0,po = 0;

void Preorder(int i)
{
	int left,right;
	left = (2*i)+1;
	right = (2*i)+2;
	
	Pre[pr] = A[i];
	printf("%d ",Pre[pr]);
	pr++;
	
	if(left < n)
	{
		Preorder(left);
	}
	
	if(right < n)
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
	
	if(left < n)
	{
		Inorder(left);
	}
	
	Ino[in] = A[i];
	printf("%d ",Ino[in]);
	in++;
	
	if(right < n)
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
	
	if(left < n)
	{
		Postorder(left);
	}
	
	if(right < n)
	{
		Postorder(right);
	}
	
	Pst[po] = A[i];
	printf("%d ",Pst[po]);
	po++;
	
	return;	
}

int main()
{
	int i;
	scanf("%d",&n);
	A = (int*)malloc(sizeof(int)*n);
	Pre = (int*)malloc(sizeof(int)*n);
	Ino = (int*)malloc(sizeof(int)*n);
	Pst = (int*)malloc(sizeof(int)*n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	
	Inorder(0);
	printf("\n");
	Preorder(0);
	printf("\n");
	Postorder(0);
	printf("\n");
	
	return 0;
}
/*int main(int argc,char **argv)
{
	char line[128];
	char v1[15];
	
	int lineNo = 0;
	int i=0,j;
	
	while(fgets(line,sizeof line,stdin) != NULL)
	{	
		sscanf(line,"%s",v1);
		lineNo++;
		
		if(lineNo == 1)
		{
			n = stoi(v1);
			A = (int*)malloc(sizeof(int)*n);
			Pre = (int*)malloc(sizeof(int)*n);
			Ino = (int*)malloc(sizeof(int)*n);
			Pst = (int*)malloc(sizeof(int)*n);
			continue;
		}
		A[i] = stoi(v1);
		i++;
	}

	Inorder(0);
	printf("\n");
	Preorder(0);
	printf("\n");
	Postorder(0);
	printf("\n");
	
	return 0;
}*/
