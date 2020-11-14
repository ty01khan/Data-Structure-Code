#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
int stoi(char *str)
{
    int x;
    sscanf(str, "%d",&x);
    return x;
}

int n,size = 0;     //defining size of queue as 0
int A[100][100];
int *dist = NULL;   /*defining distance as a pointer for allocating the space in the array*/
int *Q = NULL;      /*defining queue as a pointer for allocating the space in the array*/

void BFS(int s)
{
    int i,x,t,j;

    for(i=0;i<n;i++)
    {
        dist[i] = -1;   /*initially distance from root to all the edges are -1*/
    }

    dist[s] = 0;        //distance of same same is 0

    Q[size] = s;       //pushing or enqueue the 's' in queue
    size++;

    while(size != 0)
    {
        x = Q[0];       //saving the 1st element of queue in x

        /*swapping all elements of queue to come the 1st element at last position and decrease the size of queue by 1*/
        for(j = 0;j < (size-1);j++)
        {
            t = Q[j];
            Q[j] = Q[j+1];
            Q[j+1] = t;
        }
        size--;         //last element deleted

        for(i = 0;i < n;i++)
        {
            if(A[x][i] == 1)
            {
                if(dist[i] == -1)
                {
                    Q[size] = i;
                    size++;

                    dist[i] = dist[x] + 1;
                }
            }
        }
    }
}

int main(int argc,char **argv)
{
    char line[128];
    char v1[15];
    char v2[15];

    int i,j,ver,k,lineNo = 0;

    while(fgets(line,sizeof line,stdin) != NULL)
    {
        sscanf(line,"%s %s",v1,v2);     //scan input files
        lineNo++;                       //lineNo increases by 1

        if(lineNo==1)
        {
            n = stoi(v1);               //defining no. of term

            //creating a two dimensional array to store adge
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    A[i][j] = 0;    //initially all the element of array equal to 0
                }
            }
            Q = (int*)malloc((sizeof (int))*n); //allocating the size of queue array
            dist = (int*)malloc((sizeof (int))*n);  //allocating the size of distance array
            continue;
        }
        if(lineNo==2)
        {
            ver = stoi(v1);  //root node
            continue;
        }
        if(lineNo==3)
        {
            k = stoi(v1);
            continue;
        }

        i = stoi(v1);
        j = stoi(v2);

        A[i][j] = 1;   //all the elements are 1 of edges of undirected graph
        A[j][i] = 1;
    }

    BFS(ver);     //calling BFS

    for(i=0;i<n;i++)
    {
        if((dist[i] <= k) && (dist[i] >= 0))        /*if distance belongs to [0,k] then print the i and get the result*/
        {
            printf("%d ",i);
        }
    }
    printf("\n");

    return 0;
}
