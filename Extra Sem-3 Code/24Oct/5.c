#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

void preOrder( struct node *root) {
  
	if( root == NULL ) 
      return;
	printf("%d ",root->data);
	preOrder(root->left);
	preOrder(root->right);
  
}

struct node* insert( struct node* root, int data ) 
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    
    if(root == NULL)
    {
        return temp;
    }

    if(root->data > data)
    {
        root->left = insert(root->left,data);
    }
	else
    {
		root->right = insert(root->right,data);
	}
	return root;
}

int main() 
{
    struct node* root = NULL;
    
    int t;
    int data;

    scanf("%d", &t);

    while(t-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }
  
	preOrder(root);
    return 0;
}

