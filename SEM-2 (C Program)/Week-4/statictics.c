#include<stdio.h>
#include<math.h>
int main()
{
    int m,max,min,sum,position,i,n,sqar_sum,j;
    float avg,sd2,sd;
    printf("please enter the no of student \n");
    scanf("%d",&m);
    max=0;
    sum=0;
    sqar_sum=0;
    position=0;
    j=0;
    i=1;
    printf("please enter the marks of m number of student\n");
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
        if(n<40)
        {   
         j=j+1;
        }
        sum=sum+n;
        sqar_sum=sqar_sum+(n*n);
        position=position+1;
        i=i+1;
    }
    while(i<=m);
    {
    avg=sum/position;
    sd2=(sqar_sum/position)-(avg*avg);
    sd=sqrt(sd2);
    }
    printf("max value is %d \n",max);
    printf("min value is %d \n",min);
    printf("std deviation is %f \n",sd);
printf("number of Fail student = %d\n",j);
  

return 0;
}
