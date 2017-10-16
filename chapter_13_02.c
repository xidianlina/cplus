#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 256

int main(int argc, char *argv[])
{
	FILE *fs;
	FILE *fa;
	char temp[SIZE];
	size_t bytes;

	if (argc < 3)
	{
		fprintf(stderr, "Usage: %s filename.\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fs = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "Couldn't open the file \"%s\"\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((fa = fopen(argv[2], "wb")) == NULL)
	{
		fprintf(stderr, "Couldn't open the file \"%s\"\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	while ((bytes = fread(temp, sizeof(char), SIZE, fs)) > 0)
		fwrite(temp, sizeof(char), bytes, fa);
	fclose(fs);
	fclose(fa);

	return 0;
}