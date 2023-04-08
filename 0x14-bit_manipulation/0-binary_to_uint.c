#include "main.h"

/**
 * binary_to_uint - this is to convert a binary number to an unsigned int
 * @b: This is a pointer to the string of 0s and 1s characters
 * Return: this would return a number or 0 if there more than one or one
 * characters in the string @b, if not @b is NULL
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int n = 0, binaryN = 1;
	int power;

	if (*b == '\0')
		return (0);

	for (power = 0; b[power];)
		power++;

	for (power -= 1; power >= 0; power--)
	{
		if (b[power] != '0' && b[power] != '1')
			return (0);
		n += (b[power] - '0') * binaryN;
		binaryN *= 2;
	}
	return (n);
}
