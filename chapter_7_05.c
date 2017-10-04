#include <stdio.h>

int main(void)
{
	int a = 0;
	int b = 0;
	char ch;

	printf("Please enter a string end by #:");
	while ((ch = getchar()) != '#')
	{
		switch (ch)
		{
			case '.':
				putchar('!');
				a++;
				break;
			case '!':
				putchar('!');
				putchar('!');
				b++;
				break;
			default:
				putchar(ch);
				break;
		}
	}
	printf("\nthe times of '.' replaced by '!' : %d\n", a);
	printf("the times of '!' replaced by '!!' : %d\n", b);

	return 0;
}