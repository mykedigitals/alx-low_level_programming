#include <stdio.h>

/**
 * main- printing in base 16, i.e 10 ints like char and 6 alpha
 * Return: 0
*/

int main(void)
{
	int numb;
	char af;
		for (numb = 0; numb < 10; numb++)
		{
			putchar((numb % 10) + '0');
		}
		for (af = 'a'; af <= 'f'; af++)
		{
			putchar(af);
		}
		putchar('\n');
		return (0);

}
