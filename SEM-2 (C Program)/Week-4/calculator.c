#include <stdio.h>
int main()
{
float x,y,ans;
char op;
printf("please enter the value of x and y and char op\n");
scanf("%f %c %f", &x, &op, &y);
{
 if(op == '+')
 {
  ans = x + y;
  printf("sum of x and y = %f\n", ans);
 }
 else if(op == '-')
  {
   ans = x-y;
  printf("subtraction of x and y = %f\n",ans);
}
else if(op == '*')
{
ans = x*y;
printf("multiplication of x and y = %f\n",ans);
}
else if(op == '/' )
{
  if(y==0)
{
  printf("value is infinity\n");
}
  else
{ 
  ans=x / y;
  printf("division of x and y = %f\n",ans);
}
}
else
{
printf("Syntax error.\n");
}
}
return 0;
}
