#include "main.h"

/**
 * print_diagonal - Draw a diagonal line.
 * @n : number of diagonal line
 */

void print_diagonal(int n)
{
	int j, i;

	if (n > 0)
	{
		for (j = 0; j < n; j++)
		{
			for (i = 0; i < j; i++)
				_putchar(' ');
			_putchar('\\');

			if (j == n - 1)
				continue;
			_putchar('\n');
		}
	}
	_putchar('\n');
}
