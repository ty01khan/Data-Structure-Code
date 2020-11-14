#include<stdio.h>
int main()
{
             int a,n,d,sum;
             printf("Enter the first term of the AP\n");
             scanf("%d",&a);
             printf("Enter the common difference of the Ap\n");
             scanf("%d",&d);/* scanf("%d",&d) */
             printf("Enter the value of n\n");
             scanf("%d",&n);/* scanf("%d",&n) */
             sum = n/2*(2*a+(n-1)*d); /* 2a,n-1,d */
             printf("sum of n terms of the Ap is %d\n",sum);
             return 0;
}
