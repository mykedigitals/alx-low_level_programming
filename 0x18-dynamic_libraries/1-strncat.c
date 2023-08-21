#include "main.h"

/**
 * _strncat - Concatenate 2 strings using at most
 * an inputted bytes from src
 * @dest: The string to be added to it
 * @src: The string that we add to dest
 * @n: The number of bytes from src
 *
 * Return: Pointer to the resulting string
 */

char *_strncat(char *dest, char *src, int n)
{
	int index = 0;
	int dest_line = 0;

	while (dest[index++])
		dest_line++;

	for (index = 0; src[index] && index < n; index++)
		dest[dest_line++] = src[index];

	return (dest);
}
