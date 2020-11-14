#include<stdio.h>
int main()
{
int a,b,c;
printf("please enter the no: \n");
scanf("%d%d%d",&a,&b,&c);
if((a-b)*(b-c)>=0 && (a-b)*(b-c)<=0 )
printf("Middle number is %d\n",b);
else if((b-c)*(c-a)>=0 && (b-c)*(c-a)<=0)
printf("Middle number is %d\n",c);
else if((b-a)*(a-c)>=0 && (b-a)*(a-c)<=0)
printf("Middle number is %d\n",a);
return 0;
}
