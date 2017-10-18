#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char *s_gets(char *, int);

unsigned long font;

char f = 0;   
unsigned long fm = 0xff << 0;  

char s = 8;
unsigned long sm = 0x7f << 8;

char a = 15;
unsigned long am = 0x3 << 15;

char b = 17;
unsigned long bm = 0x1 << 17;

char i = 18;
unsigned long im = 0x1 << 18;

char u = 19;
unsigned long um = 0x1 << 19;

char align[3][7] = { "left", "center", "right" };
char on_off[2][4] = { "off", "on" };

int main(void)
{
	int n;
	char command[5];
	while (1)
	{
		printf("%-14s%-14s%-14s%-14s%-14s%-14s\n", "ID", "SIZE", "ALIGNMENT", "B", "I", "U");
		printf("%-14d%-14d%-14s%-14s%-14s%-14s\n", (font&fm) >> f, (font&sm) >> s, align[(font&am) >> a], on_off[(font&bm) >> b], on_off[(font&im) >> i], on_off[(font&um) >> u]);
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
				font = font & ~fm | n << f;
				break;
			case 's':
				printf("Enter font size (0-127): ");
				scanf("%d", &n);
				getchar();
				font = font & ~sm | n << s;
				break;
			case 'a':
				printf("Select alignment:\nl)left   c)center   r)right\n");
				s_gets(command,5);
				switch (command[0])
				{
					case 'l':
						font = font & ~am | 0 << a; 
						break;
					case 'c':
						font = font & ~am | 1 << a;
						break;
					case 'r':
						font = font & ~am | 2 << a;
						break;
					default: 
						puts("error!"); 
						break;
				}
				break;
			case 'b': 
				font ^= 1 << b;
				break;
			case 'i': 
				font ^= 1 << i;
				break;
			case 'u': 
				font ^= 1 << u;
				break;
			default: 
				puts(command);
				return 0;
			}
	}

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