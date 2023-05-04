#include "main.h"

/**
 * binary_to_uint - this is to convert a binary no to an unsigned int
 * @b: this points to a specific string of 0 or 1 character
 * Return: would return the converted no or 0 if it exceed one character
 * @b is NULL
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int tee = 1;
	unsigned int vep = 0;
	int value = 0;

	if (*b == '\0')
		return (0);

	for (value = 0; b[value];)
		value++;

	for (value -= 1; value >= 0; value--)
	{
		if (b[value] != '0' && b[value] != '1')
			return (0);

		vep += (b[value] - '0') * tee;
		tee *= 2;
	}
	return (vep);
}
