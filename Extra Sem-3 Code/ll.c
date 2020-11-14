#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

struct Node* head =  NULL;
void Print()
{
    struct Node* temp = head;
    while(temp != NULL)
    {
        printf("%d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Insert(int data,int n)
{
	int i;
    struct Node* temp1 = (Node*)malloc(sizeof(Node));
    temp1->data = data;
    temp1->next = NULL;

    if(n == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }

    struct Node* temp2 = head;
    for(i=0;i<n-2;i++)
    {
        temp2 = temp2->next;
    }

    temp1->next = temp2->next;
    temp2->next = temp1;

}
int main()
{
    Node *head = NULL;
    int n,i,x;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        Insert(n,x);
        Print();
    }
    return 0;
}
