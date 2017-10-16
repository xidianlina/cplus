#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81

void append(FILE *source, FILE *dest);

int main(int argc, char *argv[])
{
	FILE *fa, *fs;
	int i;
	int files = 0;
	int ch;

	if (argc < 3)
	{
		fprintf(stderr, "Usage: %s filename.\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fa = fopen(argv[1], "a+")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
	{
		fputs("Can't create output buffer\n", stderr);
		exit(EXIT_FAILURE);
	}
	for (i = 2; i < argc; i++)
	{
		if (strcmp(argv[i], argv[1]) == 0)
			fputs("Can't append file to iteself\n", stderr);
		else if ((fs = fopen(argv[i], "r")) == NULL)
			fprintf(stderr, "Can't open %s\n", argv[i]);
		else
		{
			if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
			{
				fputs("Can't create input buffer\n", stderr);
				continue;
			}
			append(fs, fa);
			if (ferror(fs) != 0)
				fprintf(stderr, "Error in reading file %s.\n", argv[i]);
			if (ferror(fa) != 0)
				fprintf(stderr, "Error in writing file %s.\n", argv[1]);
			fclose(fs);
			files++;
			printf("File %s appended.\n", argv[i]);
		}		
	}
	printf("Done appending, %d files appended.\n", files);
	rewind(fa);
	printf("%s contents:\n", argv[1]);
	while ((ch = getc(fa)) != EOF)
		putchar(ch);
	puts("Done displaying.");
	fclose(fa);

	return 0;
}

void append(FILE *source, FILE *dest)
{
	size_t bytes;
	static char temp[BUFSIZE];

	while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
		fwrite(temp, sizeof(char), bytes, dest);
}