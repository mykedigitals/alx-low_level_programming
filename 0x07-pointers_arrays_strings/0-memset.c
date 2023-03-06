#include "main.h"

/**
 * _memset - this fills the first n bytes of the memory
 * area pointed to by @s with the constant byte @c.
 * @s: The pointer that points to the memory area that we
 * want to fill with @c
 * @c: The character that we will fill @s with
 * @n: This is the number of bytes that we will fill
 *
 * Return: This returns a pointer to the memory filled in @s
 */

char *_memset(char *s, char c, unsigned int n)
{
	unsigned int index;

	for (index = 0; index < n; index++)
		s[index] = c;

	return (s);
}
