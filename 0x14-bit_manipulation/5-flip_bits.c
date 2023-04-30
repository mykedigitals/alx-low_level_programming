#include "main.h"

/**
 * flip_bits - this function returns the number of bits you
 * would need to flip in order to move from one number to another
 *
 * @n: this is the first value
 * @m: this would be the second number
 * Return: this returns the number of flipped bits
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int notOr = n ^ m;
	int numCount = 0;

	if (!n || !m)
		return (0);
	while (notOr)
	{
		if (notOr & 1)
			numCount++;
		notOr = notOr >> 1;
	}
	return (numCount);
}
