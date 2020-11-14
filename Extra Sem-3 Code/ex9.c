#include <stdio.h>
#include <string.h>

int main()
{
	char string[30],ch;
	int i = 0;
	
	while(ch != '\n')
	{
		ch = getchar();
		string[i] = ch;
		i++;
	}
	string[i] = '\0';
	printf("%s",string);
	/*scanf("%s",string);
	printf("%s\n",string);*/
	return 0;
}
