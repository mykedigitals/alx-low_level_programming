#include "main.h"

/**
 * _strcmp - Compares pointers to 2 strings.
 * @s1: One pointer to the first string
 * @s2: Another pointer to the second string
 *
 * Return: If str1 less than str2, the -ve differenc...
 * if str1 == str2, make 0
 * if strl > str2, +ve difference...
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}
