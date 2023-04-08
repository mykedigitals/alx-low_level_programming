#include "main.h"

/**
 * set_bit - this sets the value of a bit to 1 at any given nth value
 * @n: this is a pointer for the number
 * @index: this is the nth value to change bit to 1
 * Return: this returns 1 if it runs perfectly, -1 if it does not work
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int rightValue = 1;
	unsigned int setBit = sizeof(n) * 8 - 1;

	if (index > setBit)
		return (-1);

	rightValue = rightValue << index;

	*n = *n | rightValue;
	return (1);
}
