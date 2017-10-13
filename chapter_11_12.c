#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char ch;
	int word = 0;
	int upper = 0;
	int lower = 0;
	int punct = 0;
	int digit = 0;
	int inword = 0;

	while ((ch = getchar()) != EOF)
	{
		if (!isspace(ch) && (!ispunct(ch)) && !inword)
		{
			inword = 1;
			word++;
		}
		if (isspace(ch) || ispunct(ch) && inword)
			inword = 0;
		if (isupper(ch))
			upper++;
		if (islower(ch))
			lower++;
		if (iswpunct(ch))
			punct++;
		if (isdigit(ch))
			digit++;
	}
	printf("words:%d,upper:%d,lower:%d,punct:%d,digit:%d.\n",
		word, upper, lower, punct, digit);

	return 0;
}