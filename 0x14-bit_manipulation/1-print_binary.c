#include "main.h"

/**
 * print_binary -  this prints binary reps of certain number
 * @n: this number is converted
 * Return: nothing to be returned
 */

void print_binary(unsigned long int n)
{
	int val = 0, vol = sizeof(n) * 8 - 1;

	if (n == 0)
		_putchar('0');

	while (vol >= 0)
	{
		if (n >> vol & 1)
		{
			_putchar('1');
			val++;
		}
		else if (val)
			_putchar('0');
		vol--;
	}
}
