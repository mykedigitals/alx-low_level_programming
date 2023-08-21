#include "main.h"

/**
 * _strchr - Locate the character in a string.
 * @s: The string that would be searched
 * @c: The character that is to be located.
 *
 * Return: If @c is found - the pointer pointing to the
 * first occurence if c is not found - NULL is returned.
 */

char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s != c)
			s++;
		else
			return (s);
	}
	if (c == '\0')
		return (s);

	return (NULL);
}
