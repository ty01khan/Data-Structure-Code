#include<stdio.h>
/*
Program name: .......
Programe description:
Programmer's name:
Date:
*/
int main()
{
int a; /* a is an integer */
int b,c;
int d;
int e;
printf("Enter a number: "); 
scanf("%d", &a); /* Command to read the first integer a
nd store it in the variable a. 
*/
printf("Enter a number: ");
scanf("%d", &b);
printf("Enter a number: ");
scanf("%d", &c);
d = a;
e = d;
if(b > d) d = b;
else e = b;
if(c < e) e = c;
if(c > d) d = c;
printf("%d, %d\n", d, e);
return 0;
}
