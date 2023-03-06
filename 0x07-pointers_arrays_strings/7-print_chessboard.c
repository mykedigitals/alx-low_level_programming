#include "main.h"

/**
 * print_chessboard - prints the chessboard
 * @a: the row of the array
 *
 * Return: nothing
 */

void print_chessboard(char (*a)[8])
{
	int index, value;

	for (index = 0; index < 8; index++)
	{
		for (value = 0; value < 8; value++)
		{
			if (value == 7)
			{
				_putchar(a[index][value]);
				_putchar('\n');
			}
			else
				_putchar(a[index][value]);
		}
	}
}
