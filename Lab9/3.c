#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//defining a tree
typedef struct Tree{
    char data;
    struct Tree *left,*right;
}Tree;

//defining a node, tree as input
typedef struct Node{      
    Tree *value;
    struct Node* next;        
    }Node;

#define MAX 128

Tree *newTree(char key)     //defining a new tree
{
    Tree *node = (Tree*)malloc(sizeof(Tree));
    node->data = key;
    node->left = node->right = NULL;
    return node;
}

Node *newNode(Tree *key)    //defining a new node, tree as input
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->value = key;
    node->next = NULL;
    return node;
}

//pop the tree from stack
Tree* pop(Node **head)
{
    Node *node = *head;
    
    Tree *key = (*head)->value;
    (*head) = (*head)->next;
    free(node);
    
    return key;
}

//push tree in stack
Node *push(Node *head,Tree *key)
{
    Node *node = newNode(key);
    //size++;
    if(head == NULL)
    return node;
    node->next = head;
    return node;
}

//if input will be an operator
int Operator(char c)
{
    if((c == '+') || (c == '-') || (c == '*') || (c == '/'))
    return 1;
    return 0;
}

void Inorder(Tree *root)    //defining a function for inorder traversal
{
    if(root == NULL)
        return;
    Inorder(root->left);
    printf("%c",root->data);
    Inorder(root->right);
}
int main(int argc,char **argv)
{
    char ch;
    char *ptr;

    char string[MAX];
    fscanf(stdin,"%s",string);
    ptr = string;
    Node *head = NULL;
    while(*ptr != '\0')
    {
            ch = *ptr;
            /*if current input will be an operator than pop two times and make a sub tree and push that sub tree in the stack*/
            if(Operator(ch))
            {
                Tree *right = pop(&head);
                Tree *left = pop(&head);
                Tree *parent = newTree(ch);
                parent->left = left;
                parent->right = right;
                head = push(head,parent);
            }
            /*if current input will be operand than push directly into the stack*/
            else
            {
                Tree *parent = newTree(ch);
                head = push(head,parent);
            }

        ptr = ptr + 1;  //increment
    }
    Inorder(pop(&head));
    printf("\n");
    return 0;
}
