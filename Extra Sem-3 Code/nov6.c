#include<stdio.h>

int main()
{
    int x1,v1,p,x2,v2;
    float i,k;
    scanf("%d%d%d%d",&x1,&v1,&x2,&v2);
    
    if((v1 == v2))
    {
        printf("NO\n");
        return 0;
    }
    else if((v1 == v2) && (x1 == x2))
    {
    	printf("YES\n");
        return 0;
    }
    i = (float)(x1 - x2)/(v2 - v1);
    p = (x1 - x2)/(v2 - v1);
    k = i - p;

   if((i >= 0) && (k == 0))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    
    return 0;
}
