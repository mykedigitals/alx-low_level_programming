#include "main.h"

/**
 * print_numbers - Function that prints the numbers, from 0 to 9
 * followed by a new line.
 */

void print_numbers(void)
{
	int x;

	for (x = 0; x >= 9; x++)
		_putchar((x % 10) + '0');

	_putchar('\n');
}
