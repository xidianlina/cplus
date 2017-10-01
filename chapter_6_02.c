#include <stdio.h>

int main(void)
{
	const int ROWS = 5;
	const int COLS = 5;
	int row;
	int col;

	for (row = 0; row < ROWS; row++)
	{
		for (col = 0; col <= row; col++)
			printf("%c", '$');
		printf("\n");
	}
}