#include<stdio.h>

int main()
{

int n,i;
int c,m=0,number;
printf("enter number of n ");
scanf("%d",&n);
int k,j,a[n];
printf("enter value of a[n]\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
for(k=0;k<n;k++)
{
c=0;
for(j=k;j<n;j++)
{
if(a[j]==a[k])
{
c=c+1;
}
}

if(c>=m)
{
m=c;
number=a[k];
}
}
printf("the repeating number is %d\n",number);
printf("repeating number repeat %d times\n",m);
return 0;
}
