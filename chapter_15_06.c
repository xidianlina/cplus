#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char *s_gets(char *, int);

struct {
	unsigned int id : 8;
	unsigned int size : 7;
	unsigned int alignment : 2;
	unsigned int bold : 1;
	unsigned int italic : 1;
	unsigned int underline : 1;
}font;

char align[3][7] = { "left", "center", "right" };
char on_off[2][4] = { "off", "on" };

int main(void)
{
	int n;
	char command[5];
	while (1)
	{
		printf("%-14s%-14s%-14s%-14s%-14s%-14s\n", "ID", "SIZE", "ALIGNMENT", "B", "I", "U");
		printf("%-14d%-14d%-14s%-14s%-14s%-14s\n", font.id, font.size, align[font.alignment], on_off[font.bold], on_off[font.italic], on_off[font.underline]);
		printf("f)change font    s)change size    a)change alignment\n");
		printf("b)toggle bold    i)toggle italic  u)toggle underline\n");
		printf("q)quit\n");
		s_gets(command,5);
		switch (command[0])
		{
			case 'f':
				printf("Enter font ID (0-255): ");
				scanf("%d", &n);
				getchar();
				font.id = n;
				break;
			case 's': 
				printf("Enter font size (0-127): ");
				scanf("%d", &n);
				getchar();
				font.size = n;
				break;
			case 'a': 
				printf("Select alignment:\nl)left   c)center   r)right\n");
				s_gets(command,5);
				switch (command[0])
				{
					case 'l': 
						font.alignment = 0;
						break;
					case 'c': 
						font.alignment = 1; 
						break;
					case 'r':
						font.alignment = 2; 
						break;
					default:
						puts("error!"); 
						break;
				}
				break;
			case 'b': 
				font.bold = !font.bold;
				break;
			case 'i': 
				font.italic = !font.italic;
				break;
			case 'u': 
				font.underline = !font.underline;
				break;
			default:
				return 0;
		}
	}
	puts("Bye!");

	return 0;
}

char *s_gets(char *st, int n)
{
	char *ret_val;
	char *find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}