#include<stdio.h>

int main()
{
    int a,b,i,j,r;
    printf("please enter the value of b and a \n");
    scanf("%d%d",&b,&a);
    i=1;
    while(i<=b)
    {
        j=1;
        while(j<=a)
        {
            r=j*i;
            printf(" %d ",r);
            j=j+1;
           
        }
        i=i+1;
        printf("\n");
       
    }
    return 0;
}
