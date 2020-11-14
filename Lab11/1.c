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
	struct node* left;
	struct node* right;
}Node;

Node* root = NULL;

void Insert(int x)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    Node *current;

    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;

    //if tree is empty
    if(root == NULL)
    {
        root = temp;
		return;
    }

    current = root;

    while(current != NULL)
    {
        if(current->data == x)
        {
            return;
        }
        if(current->data > x)
        {
            if(current->left == NULL)
        	{
                current->left = temp;
                return;
            }
			current = current->left;
        }
        else
        {
            if(current->right == NULL)
			{
                current->right = temp;
                return;
            }
			current = current->right;
        }
    }
}

int Postorder(Node* temp)
{	
	if(temp == NULL)
	{
		return 0;
	}
	if(temp != NULL)
	{
		Postorder(temp->left);
		Postorder(temp->right);
		printf("%d ",temp->data);
	}
	return 1;
}

int maxValue(Node* temp)
{
	if(temp == NULL)
	{
		return 0;
	}
	while(temp->right != NULL)
	{
		temp = temp->right;
	}
	printf("%d\n",temp->data);
}

int minValue(Node* temp)
{
	if(temp == NULL)
	{
		return 0;
	}
	while(temp->left != NULL)
	{
		temp = temp->left;
	}
	printf("%d\n",temp->data);
}

Node* maxVal(Node* temp)
{
	Node* current = temp;
	while(current->right != NULL)
	{
		current = current->right;
	}
	return current;
}
Node* Delete(Node* temp,int x)
{
	if(temp == NULL)
	{
		printf("%d\n",-1);
		return NULL;
	}
	if(x == temp->data)
	{
		if((temp->left == NULL) && (temp->right == NULL))
		{
			temp = NULL;
			return temp;
		}
		else if((temp->left != NULL) && (temp->right == NULL))
		{
			Node* node = temp->left;
			free(temp);
			return node;
		}
		else if((temp->left == NULL) && (temp->right != NULL))
		{
			Node* node = temp->right;
			free(temp);
			return node;
		}
		else if((temp->left != NULL) && (temp->right != NULL))
		{
			Node* node = maxVal(temp->left);
			temp->data = node->data;
			
			temp->left = Delete(temp->left,temp->data);
		}
	}
	else if(x > temp->data)
	{
		temp->right = Delete(temp->right,x);
	}
	else if(x < temp->data)
	{
		temp->left = Delete(temp->left,x);
	}
	return temp;
}
int main(int argc,char **argv)
{
	char line[128];
	char v1[15];
	char v2[15];
	
	int lineNo = 0;
	int ret;
	
	while(fgets(line,sizeof line,stdin) != NULL)
	{
		sscanf(line, "%s %s", v1, v2);
		lineNo++;
		
		if(strcmp(v1,"INS") == 0)
		{
			Insert(stoi(v2));
		}
		else if(strcmp(v1,"MAX") == 0)
		{
			ret = maxValue(root);
			if(ret == 0)
			{
				printf("%d\n",-1);
			}
		}
		else if(strcmp(v1,"MIN") == 0)
		{
			ret = minValue(root);
			if(ret == 0)
			{
				printf("%d\n",-1);
			}
		}
		else if(strcmp(v1,"PST") == 0)
		{
			ret = Postorder(root);

			if(ret == 0)
			{
				printf("%d\n",-1);
			}
			else if(ret == 1)
			{
				printf("\n");
			}
		}
		else if(strcmp(v1,"DEL") == 0)
		{
			root = Delete(root,stoi(v2));
		}
	}
	return 0;
}
