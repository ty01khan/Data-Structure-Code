#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Code to parse integer from a string
int stoi(char *str)
{
    int x;
    sscanf(str, "%d", &x);
    return x;
}

int heapSize=0;

int parent(int i)
{
    /* Fill in */
    return (((i+1)/2)-1);
}

int left(int i)
{
    /* Fill in */
    return ((2*i)+1);
}

int right(int i)
{
    /* Fill in */
    return ((2*i)+2);
}

void swap(int x, int y)
{
    /* Fill in */
    int *temp;
    temp = x;
    x = y;
    y = temp;
}

void Parn_child_swap(int A[],int i)
{
	int p;
	while(i != 0)
	{
		p = parent(i);
		if(A[p] > A[i])
		{
			swap(A[p],A[i]);
		}
		
	}
}
int insertKey(int A[], int key)
{
    /* Insert the element key into the heap represented by A.
    Return 1 if the operation is successful and -1 otherwise. */
    int i;
    A[heapSize] = key;
    i = heapSize;
    heapSize++;
    
   	Pran_child_swap(int A[],
}

int deleteKey(int A[], int i)
{
    /* Delete the element A[i] from the heap represented by A.
    Return 1 if the operation is successful and -1 otherwise. */
}

int decreaseKey(int A[], int i, int newVal)
{
    /* Decrease the value of A[i] to newVal. Return 1 if the
    operation is successful and -1 otherwise. */
}

void minHeapify(int A[],int i)
{
    /* Ensure that the subtree rooted at A[i] is a min heap. */
}

int extractMin(int A[])
{
    /* Delete the root of the min heap represented by A. Return
    the deleted element if the operation is successful and -1
    otherwise. */
}

int getMin(int A[])
{
    /* Get the root of the min heap represented by A. Return
    the element if the operation is successful and -1 otherwise. */
}

void print(int A[])
{
    /* Display the heap represented by A in the increasing order
    of their indices, one element per line.*/
}

int main (int argc, char **argv)
{
    char line[128];
    char v1[15];
    char v2[15];
    char v3[15];

    int *A = NULL;
    int ret;
    int lineNo = 0;

    while (fgets(line, sizeof line, stdin) != NULL )
    {
        sscanf(line, "%s %s %s", v1, v2, v3);
        lineNo++;

        if(lineNo == 1)
        {
            A = (int*) malloc(sizeof(int)* stoi(v1));
            continue;
        }

        if(strcmp(v1,"INS") == 0)
        {
            ret = insertKey(A, stoi(v2));
            if(ret < 0)
                printf("%d\n", -1);
        }
        else if(strcmp(v1,"DEL") == 0)
        {
            ret = deleteKey(A, stoi(v2));
            if(ret < 0)
                printf("%d\n", -1);
        }
        else if(strcmp(v1,"EXT") == 0)
        {
            ret = extractMin(A);
            printf("%d\n", ret);
        }
        else if(strcmp(v1,"PRT") == 0)
        {
            print(A);
        }
        else if(strcmp(v1,"DEC") == 0)
        {
            ret = decreaseKey(A, stoi(v2), stoi(v3));
            if(ret < 0)
                printf("%d\n", -1);
        }
        else if(strcmp(v1,"MIN") == 0)
        {
            ret = getMin(A);
            if(ret < 0)
                printf("%d\n", -1);
        }
        else
        {
            printf("INVALID\n");
        }
    }

    if(A)
        free(A);

    return 0;
}
