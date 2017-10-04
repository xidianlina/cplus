#include <stdio.h>

int main(void)
{
	char ch;
	int spaces;
	int lines;
	int others;

	spaces = lines = others = 0;
	printf("Please enter a string end by #:");
	while ((ch = getchar()) != '#')
	{
		if (ch == ' ')
			spaces++;
		else if (ch == '\n')
			lines++;
		else
			others++;
	}
	printf("space : %d, newline : %d, others : %d\n", spaces, lines, others);

	return 0;
}