#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define LEN 40
#define ROW 20
#define COL 30

int main(void)
{
	FILE *fs, *fd;
	char name[LEN];
	char digit[ROW][COL];
	char result[ROW][COL + 1];
	char ch[] = { " .':~*= %#" };
	int i, j;

	printf("Please enter the source file name:\n");
	gets(name);
	if ((fs = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "Could not open %s.", name);
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
			fscanf(fs, "%d", &digit[i][j]);
	}
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
			result[i][j] = ch[digit[i][j]];
		result[i][j] = '\0';
	}
	printf("Enter the destination file name:\n");
	gets(name);
	if ((fd = fopen(name, "w")) == NULL)
	{
		fprintf(stderr, "Could not open %s.", name);
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < ROW; i++)
	{
		puts(result[i]);
		fprintf(fd, "%s\n", result[i]);
	}
	if (fclose(fs) != 0 || fclose(fd) != 0)
		fprintf(stderr, "Error for closing file.\n");

	return 0;
}