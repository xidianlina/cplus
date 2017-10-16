#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 256

int main(int argc, char *argv[])
{
	int i;
	FILE *fp;
	char str[SIZE];

	for (i = 1; i < argc; i++)
	{
		printf("File %s:\n", argv[i]);
		if ((fp = fopen(argv[i], "r")) == NULL)
		{
			fprintf(stderr, "Couldn't open %s.\n", argv[i]);
			exit(EXIT_FAILURE);
		}
		while (fscanf(fp, "%s", str) != EOF)
			fprintf(stdout, "%s", str);
		fclose(fp);
	}

	return 0;
}