#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
	int num = 0;
	char ch;
	bool word = false;
	while ((ch = getchar()) != EOF)
	{
		if (isalpha(ch) && !word)
		{
			word = true;
			num++;
		}
		if (!isalpha(ch))
			word = false;
	}
	printf("words:%d\n", num);

	return 0;
}