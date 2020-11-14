#include<stdio.h>
int main()
{
int marks;
printf("please enter the marks obtained: ");
scanf("%d",&marks);
if (100>=marks && 90<=marks)
printf("A Grade\n");
else if (90>=marks && 80<=marks)
printf("B Grade\n");
else if (80>marks && 70<=marks)
printf("C Grade\n");
else if (70>marks && 60<=marks)
printf("D Grade\n");
else if (60>marks && 50<=marks)
printf("E Grade\n");
else if (50>marks && 40<=marks)
printf("F Grade\n");
else if (40>marks)
printf("FAIL\n");
return 0;
}
