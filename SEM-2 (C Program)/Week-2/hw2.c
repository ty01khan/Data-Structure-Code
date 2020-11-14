#include<stdio.h>
int main()
{
float a,b;
float p;
int d;
printf("enter the value of a and b \n");
scanf("%f%f",&a,&b);
p=a/b;
d=a/b;
if (p-d>=0.5)
printf("value is %d \n",d+1);
else
printf("value is %d \n",d);
return 0;
}
