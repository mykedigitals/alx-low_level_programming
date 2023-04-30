#include "main.h"

/**
 * clear_bit - this assigns zero 0 to the value of a bit at a
 * particular nth position
 *
 * @n: this is variable name is a pointer to that value
 * @index: this is the nth position where the value is changed to
 *
 *
 * Return: this returns 1 if the value is assigned, and -1 if not
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int bitValue;
	unsigned int removeMask;

	bitValue = sizeof(n) * 8 - 1;
	removeMask = 1;

	if (index > bitValue)
		return (-1);

	*n = *n & ~(removeMask << index);
	return (1);
}
