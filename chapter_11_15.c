#include <stdio.h>
#include <ctype.h>
#define SIZE 40

int myatoi(char *);

int main(void)
{
	char str[SIZE];
	gets(str);
	printf("%d\n", myatoi(str));

	return 0;
}

int myatoi(char *st)
{
	int sum = 0;

	while (*st)
	{
		if (isdigit(*st))
			sum = 10 * sum + (*st - '0');
		else
			return 0;
		st++;
	}

	return sum;
}