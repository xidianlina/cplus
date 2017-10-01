#include <stdio.h>

int main(void)
{
	const int ROWS = 6;
	int row;
	int col;
	char ch;

	for (ch='A',row = 0; row < ROWS; row++)
	{
		for (col=0;col <= row; col++, ch++)
			printf("%c", ch);
		printf("\n");
	}
	return 0;
}