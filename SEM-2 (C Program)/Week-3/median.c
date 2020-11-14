
#include <stdio.h>
#include <stdio.h>

int main()
{
    int a,b,c,d,e,x;
    printf("please enter five number\n");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    if (a > b)
    {x = b;
      b=a;
      a=x;
    }
     if (b>c)
    {x = c;
      c=b;
      b=x;
    }
     if (c>d)
    {x = d;
      d=c;
      c=x;
    }
     if (d>e)
    {x = e;
      e=d;
      d=x;
    }
     if (a>b)
    {x = b;
      b=a;
      a=x ;
    }
     if (b>c)
    {x = c;
      c=b;
      b=x;
    }
     if (c>d)
    {x = d;
      d=c;
      c=x ;
    }
     if (a > b)
    {x = b;
      b=a;
      a=x;
    }
     if (b>c)
    {x = c;
      c=b;
      b=x;
    }
    else{}
    printf("median is %d\n",c);
    return 0;
}

