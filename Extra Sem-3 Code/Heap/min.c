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
void minHeapify(int A[],int i);

int parent(int i)
{
	return (((i+1)/2)-1);
}

int left(int i)
{
	return ((2*i)+1);
}

int right(int i)
{
    	return ((2*i)+2);
}

void parchil_swap(int A[],int i)    //function to swap b/w child and parent if parent is greater
{
	int p,t;
	p = parent(i);

	if(i != 0)
	{
		if(A[p] > A[i])
		{
		    t = A[p];       //swapping A[p] and A[i]
		    A[p] = A[i];
		    A[i] = t;
		}
		parchil_swap(A,p);
	}
}


int insertKey(int A[], int key)
{
	int i,p;

	A[heapSize] = key;      //key is inserted as last element
	i = heapSize;
	heapSize = heapSize + 1;

	parchil_swap(A,i);      //calling parchil_swap to insert new element at right place

	return 0;
}

int deleteKey(int A[], int i)
{
    if(i >= heapSize)
	{
		return (-1);
	}

    int t;
    t = A[i];
    A[i] = A[heapSize -1];      //swapping A[i] and the last element
    A[heapSize -1] = t;
	heapSize = heapSize - 1;        //reducing heapsize such that last element is deleted

	minHeapify(A,i);

	return 1;
}

int decreaseKey(int A[], int i, int newVal)
{
    if(newVal > A[i])
	{
		return (-1);
	}

	int t;
	t = A[i];
	A[i] = newVal;
	newVal = t;

	parchil_swap(A,i);

	return 0;
}

void minHeapify(int A[],int i)
{
	int l,r,min,t;

	min = A[i];
	l = left(i);
	r = right(i);

	if((l < heapSize) && (A[l] < min))
	{
		min = A[l];
	}
	if((r < heapSize) && (A[r] < min))
	{
	    t = A[r];       //swap right child and parent if left is min
	    A[r] = A[i];
	    A[i] = t;
		minHeapify(A,r);
	}
	else if(min == A[l])
	{
		t = A[l];       //swap left child and parent if right is min
	    A[l] = A[i];
	    A[i] = t;
		minHeapify(A,l);
	}
}

int extractMin(int A[])
{
	if (heapSize == 0)
	{
		return (-1);
	}

	int min,i;

	i = 0;
	min = A[0];     //saving the value of element to be deleted

	deleteKey(A,i);

	return min;
}

int getMin(int A[])
{
    	if (heapSize == 0)
	{
		return (-1);
	}

	return (A[0]);
}

void print(int A[])
{
    int i;

	for(i = 0;i < heapSize;i++)
	{
		printf("%d \n",A[i]);
	}
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
            printf("%d\n", ret);
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
