#include "main.h"

/**
 * get_bit - this would return value of bit at given no
 * @n: the value to be checked
 * @index: the np that checks bit
 * Return: this returns the bit value at the @index
 * but returns -1 if there's error
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int value = 1, num = sizeof(n) * 8 - 1;

	if (index > num)
		return (-1);

	value = value << index;

	if (n & value)
		return (1);
	else
		return (0);
}
