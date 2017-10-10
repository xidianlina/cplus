#include <stdio.h>

int main(void)
{
	int guess, max = 100, min = 1;
	char response;

	printf("Pick an integer from 1 to 100.I will try to guess ");
	printf("it.\nResponse with a b if my guess is big and with");
	printf("\nan 1 if it is little.\n");
	printf("Uh...is your number %d?\n", guess = (max + min) / 2);
	while ((response = getchar()) != 'y')
	{
		if (response == 'b')
		{
			max = guess - 1;
			printf("Well,then,is it %d?\n", guess = (max + min) / 2);
		}
		else if (response == 'l')
		{
			min = guess + 1;
			printf("Well,then,is it %d?\n", guess = (max + min) / 2);
		}
		else
			printf("Sorry,I understand only y or n.\n");
		while (getchar() != '\n');
	}
	printf("I know I could do it!\n");

	return 0;
}