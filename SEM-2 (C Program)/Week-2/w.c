#include<stdio.h>
int main()
{
int a,b,c;
printf("enter the no \n");
scanf("%d%d%d",&a,&b,&c);
if (a<=b<=c)
printf("ACENDING\n");
else
if (a>=b>=c)
printf("DESCENDING\n");
else
printf("NEITHER\n");
return 0;
}
