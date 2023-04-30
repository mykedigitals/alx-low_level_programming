#include "main.h"

/**
 * print_binary - this prints the binary that represent a set of numbers
 * @n: this is the number that is to be converted
 *
 * Return: does not return anything
 */

void print_binary(unsigned long int n)
{
	int num = 0;
	int value = sizeof(n) * 8 - 1;

	if (n == 0)
		_putchar('0');
	while (value >= 0)
	{
		if (n >> value & 1)
		{
			_putchar('1');
			num++;
		}
		else if (num)
			_putchar('0');
		value--;
	}
}
