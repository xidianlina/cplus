#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i;
	char ch;
	FILE *fp;
	int cnt = 0;

	if (argc < 2)
	{
		fprintf(stderr, "The wrong number of arguments.\n");
		exit(EXIT_FAILURE);
	}
	if (argc == 2)
	{
		printf("Please enter some texts:\n");
		while ((ch = getchar()) != EOF)
			if (ch == argv[1][0])
				cnt++;
		printf("The \"%s\" comes %d times in your input.\n", argv[1], cnt);
	}
	else
	{
		for (i = 2; i < argc; i++)
		{
			cnt = 0;
			if ((fp = fopen(argv[i], "r")) == NULL)
			{
				fprintf(stderr, "Could not open the %s.", argv[i]);
				continue;
			}
			while ((ch = getc(fp)) != EOF)
				if (ch == argv[1][0])
					cnt++;
			fprintf(stdout, "The \"%s\" in %s comes %d times.\n", argv[1], argv[i], cnt);
			fclose(fp);
		}
	}

	return 0;
}