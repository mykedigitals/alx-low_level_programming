#include "main.h"

/**
 * get_endianness - This checks for endianess.
 *
 * Return: this returns 0 if it is big-endianess
 * and returns little-endianess if 1.
 */

int get_endianness(void)
{
	int countNum;
	char *smallEndian = (char *)&countNum;

	countNum = 1;

	if (*smallEndian == 1)
		return (1);

	return (0);
}
