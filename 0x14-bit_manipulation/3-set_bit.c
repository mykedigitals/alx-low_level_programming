#include "main.h"

/**
 * set_bit - this sets the no of bits at a certain no to 1.
 * @n: this is the pointer to the bit
 * @index: this is the no to set the value at the no from 0
 * Return: this returns error occur -1 else 1
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	*n ^= (1 << index);
	return (1);
}
