#include<stdio.h>
int main()
{
int a,b,c;
printf("enter the no a and b and c \n");
scanf("%d%d%d",&a,&b,&c);
if (a==b)
{
printf("YES\n");
}
else
if (b==c)
{
printf("YES\n");
}
else
if (a==c)
{
printf("YES\n");
}
else 
printf("NO\n");

return 0;
}
