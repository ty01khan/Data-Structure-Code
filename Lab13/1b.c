#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	char val;
	struct node* link;
}node;

#define MAX 128
int n = 0;

int isEmpty(node *head)
{
	if(head == NULL)
	{
		return 1;
	}

	return 0;
}

node *push(node *head,char ch)
{
	node *temp = (node*)malloc(sizeof(node));
	temp->val = ch;
	temp->link = head;
	n = n+1;
	return temp;
}

char pop(node **head)
{
	char d;

	node *top = *head;
	if(top == NULL)
	{
		return '\0';
	}

	d = (*head)->val;
	(*head) = (*head)->link;
	n = n-1;

	//free(top);

	return d;
}

char peek(node *head)
{
	if(head == NULL)
	{
		return '\0';
	}

	return head->val;
}

int prec(char p,char t)
{
	int p1,p2;
	if((p == '*') || (p == '/'))
	{
		p1 = 1;
	}
	else
	{
		p1 = 0;
	}

	if((t == '*') || (t == '/'))
	{
		p2 = 1;
	}
	else
	{
		p2 = 0;
	}

	if(p1 > p2)
	{
		return 1;
	}
	else if(p1 < p2)
	{
		return (-1);
	}
	else
	{
		return 0;
	}
}

int main (int argc, char **argv)
{
    char ch,ret;
	char *ptr;
	int p;

    node *head = NULL;

	char string[MAX];
	fscanf(stdin,"%s",string);
	ptr = string;

    	while (*ptr != '\0')
    	{
			ch = *ptr;

        	if((ch >= 'a')&&(ch <= 'z'))
        	{
	    		printf("%c",ch);
        	}
        	else if(ch == '(')
        	{
            		head = push(head,ch);
        	}
			else if(ch == ')')
        	{
            	while(head->val != '(')
				{
					ret = pop(&head);
					printf("%c",ret);
				}

				ret = pop(&head);
        	}
			else if((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/'))
			{
				while(1)
				{
					if((isEmpty(head) == 1) || (peek(head) == '('))
					{
						head = push(head,ch);
						break;
					}
					else
					{
						p = prec(ch,peek(head));

						if(p == 1)
						{
							head = push(head,ch);
							break;
						}
						else if(p == -1)
						{
							ret = pop(&head);
							printf("%c",ret);
						}
						else
						{
							ret = pop(&head);
							printf("%c",ret);
							head = push(head,ch);
							break;
						}
					}
				}
			}

			ptr = ptr+1;
    	}

		while(isEmpty(head) != 1)
		{
			ret = pop(&head);
			printf("%c",ret);
		}

		printf("\n");

    	return 0;
}
