#include "main.h"

/**
 * get_bit - it can return the value of a bit at the given index
 * @n: this is the number to check
 * @index: this is the nth number to check the bit
 * Return: this returns the value of the bit of @index, -1
 * if there's an error
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int real = 1;
	unsigned int best = sizeof(n) * 8 - 1;

	if (index >  best)
		return (-1);

	real = real << index;

	if (n & index)
		return (1);
	else
		return (0);
}
