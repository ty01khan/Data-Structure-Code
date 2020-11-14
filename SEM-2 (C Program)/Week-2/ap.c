#include<stdio.h>
int main()
{
int a,d,n,S;
printf("enter the value of a,d and n\n");
scanf("%d%d%d",&a,&d,&n);
S=(n*2*a+n*(n-1)*d)/2;
printf("Sum of AP series is %d\n",S);
return 0;
}

