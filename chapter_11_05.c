#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 80

char * str_ch(char * str, char c);

int main(void)
{
	char str[SIZE];
	char ch;
	char * ret;

	printf("Input a string (q to quit):\n");
	gets(str);
	while (strcmp(str, "q"))
	{
		printf("Input a character: ");
		scanf("%c", &ch);
		while (getchar() != '\n')		//跳过剩余输入部分
			continue;
		ret = str_ch(str, ch);
		if (ret)
			printf("Find! The string start with the %c:\n"
				"%s\n", ch, ret);
		else
			printf("Can't find!\n");
		printf("Input a string (q to quit):\n");
		gets(str);
	}
	printf("Bye.\n");

	return 0;
}



char * str_ch(char * str, char c)
{
	int flag = 0;
	int count = 0;

	while (count++ < strlen(str))
		if (*str++ == c)
		{
			flag = 1;
			break;
		}
	if (flag)
		return str - 1;
	else
		return NULL;
}