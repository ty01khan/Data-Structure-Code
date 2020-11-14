#include<stdio.h>
int main()
{
int a,b,c;
printf("enter the no\n");
scanf("%d%d%d",&a,&b,&c);
if(c>=b && b>=a)
printf("ASCENDING\n");
else if(a>=b && b>=c)
printf("DESCENDING\n");
else
printf("NEITHER\n");
return 0;
}

