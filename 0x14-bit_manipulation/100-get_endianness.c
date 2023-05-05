#include "main.h"

/**
 * get_endianness - this checks for the endian
 *
 * Return: 0 or -1
 */

int get_endianness(void)
{
	int val;
	char *pov = (char *)&val;

	val = 1;
	
	if (*pov == 1)
		return (1);

	return (0);
}
