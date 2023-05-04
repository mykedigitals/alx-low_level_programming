#include "main.h"

/**
 * clear_bit - This sets the val of a bit at a given no to zero
 * @n: the pointer to bit to be assigned
 * @index: the index to set the val at the beginning of indices at 0
 * Return: -1 if error occurs else return 0
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	*n &= ~(1 << index);

	return (1);
}
