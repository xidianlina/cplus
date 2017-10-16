#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define LEN 41

int main(void)
{
	char name[LEN];
	char words[LEN];
	FILE *fp;
	long offset;

	printf("Please enter the file name:\n");
	gets(name);
	if ((fp = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "Could not \"%s\" file.\n", name);
		exit(EXIT_FAILURE);
	}
	printf("Please enter a position in the file (negative number or Non numeric character to quit):\n");
	while (scanf("%ld", &offset) == 1 && offset > 0)
	{
		getchar();
		fseek(fp, offset, SEEK_SET);
		fscanf(fp, "%40s", words);
		fprintf(stdout, "%s\n", words);
		printf("Please enter a position in the file (negative number or Non numeric character to quit):\n");
	}
	fclose(fp);

	return 0;
}