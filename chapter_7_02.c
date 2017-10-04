#include <stdio.h>

int main(void)
{
	char ch;
	int cnt;
	printf("Please enter a string end by #:");
	for (cnt = 1; (ch = getchar()) != '#'; cnt++)
	{
		printf("%c--%d\t", ch, ch);
		if (cnt % 8 == 0)
			printf("\n");
	}
	printf("\n");

	return 0;
}