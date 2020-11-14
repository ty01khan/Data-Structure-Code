#include <stdio.h>
#include <string.h>

int main() 
{
	char str[50],ch;
	int i;
	int i0=0,i1=0,i2=0,i3=0,i4=0,i5=0,i6=0,i7=0,i8=0,i9=0;
	gets(str);
	
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i] == 0)
		{
			i0 = i0 + 1;
		}
		else if(str[i] == 1)
		{
			i1 = i1 + 1;
		}
		else if(str[i] == 2)
		{
			i2 = i2 + 1;
		}
		else if(str[i] == 3)
		{
			i3 = i3 + 1;
		}
		else if(str[i] == 4)
		{
			i4 = i4 + 1;
		}
		else if(5 == str[i])
		{
			i5 = i5 + 1;
		}
		else if(6 == str[i])
		{
			i6 = i6 + 1;
		}
		else if(7 == str[i])
		{
			i7 = i7 + 1;
		}
		else if(8 == str[i])
		{
			i8 = i8 + 1;
		}
		else if(str[i] == 9)
		{
			i9 = i9 + 1;
		}
		
		
	}
	printf("%d %d %d %d %d %d %d %d %d %d\n",i0,i1,i2,i3,i4,i5,i6,i7,i8,i9);
    return 0;
}

/*#include <stdio.h>

int main()
{
   char str[1000], ch;
   int i, frequency = 0;

   printf("Enter a string: ");
   gets(str);

   printf("Enter a character to find the frequency: ");
   scanf("%c",&ch);

   for(i = 0; str[i] != '\0'; ++i)
   {
       if(ch == str[i])
           ++frequency;
   }

   printf("Frequency of %c = %d\n", ch, frequency);

   return 0;
}*/
