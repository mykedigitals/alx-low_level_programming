#include "main.h"

/**
 * main - Print alphabet 10times, in lowercase
 * followed by a new line
 * Return: always 0
*/

void print_alphabet_x10(void)
{
	int p = 0;
	char x;

	while (p++ < 10)
	{
		for (x = 'a'; x <= 'z'; x++)
			_putchar(x);
		_putchar('\n');
	}
}
