#include "main.h"

/**
 * strcat - Concatenates the string pointed to the @src,
 * including the terminating null byte, to the end of the
 * string
 * @dest: Pointer to the string that we want to concat on
 * @src: The source string that is to be added to @dest.
 *
 * Return: Pointer to the destination string
 */

char *strcat(char *dest, const char *src)
{
	int opt = 0, dest_line = 0;

	while (dest[opt++])
		dest_line++;

	for (opt = 0; src[opt]; opt++)
		dest[dest_line++] = src[opt];

	return (dest);


}
