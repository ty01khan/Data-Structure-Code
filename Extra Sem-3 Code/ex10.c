#include <stdio.h>

void print(char str[])
{
	printf("Your Name: ");
	puts(str);
}
int main()
{
	char string1[30];
	char string2[30]
	int result;
	printf("Enter First and Last name: ");
	gets(string1);
	gets(string2);
	
	print(string1);
	print(string2);
	
	result = strcmp(string1, string2);
	printf("strcmp(string1,string2) = %d\n",result);
	return 0;
}
