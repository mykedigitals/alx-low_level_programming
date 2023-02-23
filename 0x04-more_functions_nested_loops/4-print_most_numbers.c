#include "main.h"

/**
 * print_most_numbers - Print numbers 0-9 but omit 2
 */

void print_most_numbers(void);
{
	int x;
	
	for (x = 0; x <= 9; x++)
	{
		if (x != 2 && x != 4)
			_putchar((x % 10) + '0');
	}

	_putchar('\n');
}
