#include<stdio.h>
#include<math.h>
int main()
{
    int m,max,min,sum,position,i,n,sqar_sum;
    float avg,sd2,sd;
    printf("please enter the no  \n");
    scanf("%d",&m);
    max=0;
    sum=0;
    sqar_sum=0;
    position=0;
    i=1;
    printf("please enter the m number of list\n");
    do
    {
        scanf("%d",&n);
        if(n>max)
        {
            max=n;
        }
        if(i==1)
        {
          min=n; 
        }
        if(n<min)
        {
            min=n;
        }
        sum=sum+n;
        sqar_sum=sqar_sum+(n*n);
        position=position+1;
        i=i+1;
}


    while(i<=m);
    {
    avg=(float)sum/position;
    sd2=(sqar_sum/position)-(avg*avg);
    sd=sqrt(sd2);
    }
    printf("max value is %d \n",max);
    printf("min value is %d \n",min);
    printf("std deviation is %f \n",sd);
    printf("average value is %f \n",avg);

  return 0;
}
