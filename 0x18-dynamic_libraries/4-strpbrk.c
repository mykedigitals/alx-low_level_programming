#include "main.h"

/**
 * _strpbrk - This search through a string for any of
 * a set of bytes
 * @s: the searched string
 * @accept: contains the byte are to search for
 *
 * Return: Pointer to the byte in @s that align with one of the
 * bytes in @accept, or NULL if there's no such byte found.
 */

char *_strpbrk(char *s, char *accept)
{
	int value;

	while (*s)
	{
		for (value = 0; accept[value]; value++)
		{
			if (*s == accept[value])
				return (s);
		}
		s++;
	}
	return (NULL);
}
