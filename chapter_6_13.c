#include <stdio.h>

int main(void)
{
	int arr[8];
	int index;
	int cnt;
	
	for (index = 0, cnt = 1; index < 8; index++)
	{
		cnt *= 2;
		arr[index] = cnt;
	}

	index = 0;
	do
	{
		printf("%5d", arr[index++]);
	} while (index < 8);
	printf("\n");

	return 0;
}