#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40

int main(void)
{
	FILE *in, *out;
	int ch;
	char name[LEN];
	int count = 0;

	printf("Enter the name of file to be reduced:\n");
	gets(name);
	if ((in = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "I couldn't open the file \"%s\"\n", name);
		exit(EXIT_FAILURE);
	}
	name[LEN - 5] = '\0';
	strcat(name, ".txt");
	if ((out = fopen(name, "w")) == NULL)
	{
		fprintf(stderr, "Can't create output file.\n");
		exit(3);
	}
	while ((ch = getc(in)) != EOF)
		if (count++ % 3 == 0)
			putc(ch, out);
	if (fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "Error in closing files\n");

	return 0;
}