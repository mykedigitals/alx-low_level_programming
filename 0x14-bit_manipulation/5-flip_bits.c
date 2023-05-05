#include "main.h"

/**
 * flip_bits - this gets the numbers of bits to be flipped
 * @n: number to flip
 * @m: flip this to n
 *
 * Return: number that is flipped
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int diff = n ^ m, res = 0;

	while (diff > 0)
	{
		res += (diff & 1);
		diff >>= 1;
	}

	return (res);
}
