#include<stdio.h>
int main()
{
int n;
printf("please enter the number: ");
scanf("%d",&n);
switch(n)
{
case 10:
printf("A+ Grade\n");
break;
case 9:
printf("A Grade\n");
break;
case 8:
printf("B Grade\n");
break;
case 7:
printf("C Grade\n");
break;
case 6:
printf("D Grade\n");
break;
case 5:
printf("E Grade\n");
break;
case 4:
case 3:
case 2:
case 1:
printf("FAIL Grade\n");
break;
}
printf("Please enter the number betweem 1 and 10\n");
return 0;
}



