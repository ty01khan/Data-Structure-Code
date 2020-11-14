#include<stdio.h>
int main()
{
long a,b,p;
printf("enter the value of a and b: \n");
scanf("%ld%ld",&a,&b);
if(a>b) p=a;
else p=b;
printf("max value in these 2 no is = %ld \n",p);
return 0;
}


