#include "main.h"

/**
 * binary_to_uint - this is to convert a binary number to an unsigned int
 * @b: This is a pointer to the string of 0s and 1s characters
 * Return: this would return a number or 0 if there more than one or one
 * characters in the string @b, if not @b is NULL
 */

unsigned int binary_to_uint(const char *b)
{
	int binaryN = 0;
	unsigned int num = 0;
	int raiseToPower = 0;

	if (b == '\0')
		return (0);

	while (b[binaryN + 1])
		binaryN++;

	while (binaryN >= 0)
	{
		if (b[binaryN] == '0')
		{
			binaryN--;
			raiseToPower++;
		}
		else if (b[binaryN] == '1')
		{
			num += (1 << raiseToPower);
			binaryN--;
			raiseToPower++;
		}
		else
			return (0);
	}
	return (num)
}
