#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LEN 40
#define ROW 20
#define COL 30

int main(void)
{
	FILE * fs, *fd;				
	char name[LEN];
	char dig[ROW][COL];
	char res[ROW][COL + 1];
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
		{
			fscanf(fs, "%d", &dig[i][j]);
		}
	}
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if ((i == 0 && j == 0) || (i == 0 && j == 29)
				|| (i == 19 && j == 0) || (i == 19 && j == 29))
				;
			else if (i == 0) {
				if ((abs(dig[i][j] - dig[i][j - 1]) > 1) && (abs(dig[i][j] - dig[i][j + 1]) > 1) &&
					(abs(dig[i][j] - dig[i + 1][j]) > 1))
					dig[i][j] = (dig[i][j - 1] + dig[i][j + 1] + dig[i + 1][j]) / 3.0 + 0.5;
			}
			else if (j == 0) {
				if ((abs(dig[i][j] - dig[i - 1][j]) > 1) && (abs(dig[i][j] - dig[i][j + 1]) > 1) &&
					(abs(dig[i][j] - dig[i + 1][j]) > 1))
					dig[i][j] = (dig[i - 1][j] + dig[i][j + 1] + dig[i + 1][j]) / 3.0 + 0.5;
			}

			else if (i == 19) {
				if ((abs(dig[i][j] - dig[i][j - 1]) > 1) && abs((dig[i][j] - dig[i][j + 1]) > 1) &&
					(abs(dig[i][j] - dig[i - 1][j]) > 1))
					dig[i][j] = (dig[i - 1][j] + dig[i][j - 1] + dig[i][j + 1]) / 3.0 + 0.5;
			}

			else if (j == 29) {
				if ((abs(dig[i][j] - dig[i][j - 1]) > 1) && (abs(dig[i][j] - dig[i + 1][j]) > 1) &&
					(abs(dig[i][j] - dig[i - 1][j]) > 1))
					dig[i][j] = (dig[i - 1][j] + dig[i][j - 1] + dig[i + 1][j]) / 3.0 + 0.5;
			}

			else {
				if ((abs(dig[i][j] - dig[i][j - 1]) > 1) && (abs(dig[i][j] - dig[i][j + 1]) > 1) &&
					(abs(dig[i][j] - dig[i - 1][j]) > 1) && (abs(dig[i][j] - dig[i + 1][j]) > 1))
					dig[i][j] = (dig[i - 1][j] + dig[i + 1][j] + dig[i][j - 1] + dig[i][j + 1]) / 4.0 + 0.5;
			}
		}
	}

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			res[i][j] = ch[dig[i][j]];
		}
		res[i][j] = '\0';
	}
	printf("Enter the destination file name:\n");
	gets(name);
	if ((fd = fopen(name, "w")) == NULL)
	{
		fprintf(stderr, "Could not open %s.\n", name);
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < ROW; i++)
	{
		fprintf(stdout, "%s\n", res[i]);
		fprintf(fd, "%s\n", res[i]);
	}
	if (fclose(fs) != 0 || fclose(fd) != 0)
		fprintf(stderr, "Error for closing file.\n");

	return 0;
}