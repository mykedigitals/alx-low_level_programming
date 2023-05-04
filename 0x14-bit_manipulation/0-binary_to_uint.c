#include "main.h"

/**
 * binary_to_uint - this is to convert a binary no to an unsigned int
 * @b: this points to a specific string of 0 or 1 character
 * Return: would return the converted no or 0 if it exceed one character
 * @b is NULL
 */

unsigned int binary_to_uint(const char *b)
{
	int tee = 0;
	unsigned int vep = 0;
	int value = 0;

	if (b == '\0')
		return (0);

	while (b[tee + 1])
		tee++;

	while (tee >= 0)
	{
		if (b[tee] == '0')
		{
			tee--;
			value++;
		}
		else if (b[tee] == '1')
		{
			vep += (1 << value);
			tee--;
			value++;
		}
		else
			return (0);
	}
	return (vep);
}
