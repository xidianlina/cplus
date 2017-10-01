#include <stdio.h>

int main(void)
{
	const int ROWS = 6;
	char ch;
	int row;
	int col;

	for (row = 0; row < ROWS; row++)
	{
		for (ch = 'F', col = 0; col <= row; col++,ch--)
			printf("%c", ch);
		printf("\n");
	}

	return 0;
}