#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char * argv[])
{
	char ch;

	if (argc == 1||!strcmp(argv[1], "-p"))
		while ((ch = getchar()) != EOF)
			putchar(ch);
	else if (!strcmp(argv[1], "-u"))
		while ((ch = getchar()) != EOF)
			putchar(toupper(ch));
	else if (!strcmp(argv[1], "-l"))
		while ((ch = getchar()) != EOF)
			putchar(tolower(ch));

	return 0;
}