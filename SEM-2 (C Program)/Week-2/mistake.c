#include<stdio.h> (missing)
/*
Program name: .......
Programe description:
Programmer's name:
Date:
*/
int main()
{ (missing {)
int a; /* a is an integer */
int b,c;
int d;
int e;
printf("Enter a number: "); 
scanf("%d", &a); /* Command to read the first integer a
nd store it in the variable a. 
*/
printf("Enter a number: ");
scanf("%d", &b); (missing % in d)
printf("Enter a number: ");
scanf("%d", &c);
d = a
e = d
if(b > d) d = b; (no ; is required after if(b>d))
else e = b;
if(c < e) e = c;
if(c > d) d = c;
printf("%d, %dn", d, e);
return 0: (missing)
}
