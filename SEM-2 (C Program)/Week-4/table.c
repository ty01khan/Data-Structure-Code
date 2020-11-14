#include<stdio.h>
int main()
{
int n,i,Table;
printf("please enter the no \n");
scanf("%2d",&n);
for(i=1;i<=16;i++)
{
Table=n*i;
printf("%2d * %2d = %2d \n",n,i,Table);
}
return 0;
}


