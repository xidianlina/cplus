#include <stdio.h>

int main(void)
{
	char ch;
	int a;
	int b;

	a = b = 0;
	printf("Please enter a string end by #:");
	while ((ch = getchar()) != '#')
	{
		if (ch == '.')
		{
			putchar('!');
			a++;
		}
		else if (ch == '!')
		{
			putchar('!');
			putchar('!');
			b++;
		}
		else
			putchar(ch);
	}
	printf("\nthe times of '.' replaced by '!': %d\n", a);
	printf("the times of '!' replaced by '!!': %d\n", b);

	return 0;
}