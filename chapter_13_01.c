#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

int main(void)
{
	int ch;
	FILE *fp;
	unsigned long count = 0;
	char *filename[SIZE];

	printf("Please enter filename: ");
	if (scanf("%s", filename) != 1)
	{
		printf("Usage: %s filename\n", filename);
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("Can't open %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("\nFile %s has %lu characters\n", filename, count);

	return 0;
}