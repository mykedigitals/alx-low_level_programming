#include "main.h"

/**
 * _strlen - Returns the length of a string.
 * @str: The string to get the length of.
 *
 * Return: The lenght of @str.
 */

int _strlen(char *s)
{
	size_t length = 0;

	while (*s++)
		length++;

	return (length);
}
