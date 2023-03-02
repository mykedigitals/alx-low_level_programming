#include "main.h"
#include <stdio.h>

/**
 * _strcat - Concatenates the string pointed to the @src,
 * including the terminating null byte, to the end of the
 * string
 * @dest: Pointer to the string that we want to concat on
 * @src: The source string that is to be added to @dest.
 *
 * Return: Pointer to the destination string
 */

char *_strcat(char *dest, char *src)
{
	int index;
	int dest_line;

	for (index = 0; dest[index] != '\0'; index++)
	{}

	for (dest_line = 0; src[dest_line] != '\0'; dest_line++)
		dest[index + dest_line] = src[dest_line];

	return (dest);


}
