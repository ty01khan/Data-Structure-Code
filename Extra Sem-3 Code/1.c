#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    }Node;

struct Node* head;

void Insert(int x)
{
    struct Node* temp = (Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}

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
int main()
{
    head = NULL;    //empty list
    int n,i,x;
    printf("Please enter the number: ");
    scanf("%d",&n);
    for(i=0;i<(2*n);i++)
    {
        scanf("%d",&x);
        Insert(x);
        Print();
    }
    return 0;
}
