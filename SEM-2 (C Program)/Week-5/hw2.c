#include<stdio.h>
int main()
{
int n,A[n],a,d,i;
printf("enter the value of n ");
scanf("%d",&n);
printf("enter all the number ");
for(i=0;i<n;i++)
{
scanf("%d",&A[i]);
}
a=0;
d=0;
          for(i=0;i<n-1;i++)
	  {	
	  if(A[i]<A[i+1])
	  a=a+1;
	  else if(A[i]>A[i+1])
  	  d=d+1;
   	  }
	  if(a==n-1)
	  {
	  printf("Strictly Ascending");
	 }
	  else if(d==n-1)
	 {
	  printf("Strictly Descending");
	 }
	  else
	 {
	  printf("Neither");
	 }
	
  return 0;
}
