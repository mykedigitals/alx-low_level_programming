#include "main.h"

/**
 * _memcpy - This copies the numbers of byte @n
 * from the memory area pointed to by @src into another
 * pointer @dest
 * @dest: This is a pointer that points to the memory area
 * that is to be copied into @src
 * @src: This contains the source character to be copied from
 * @n: This is the number of bytes to copy from the source @src.
 *
 * Return: The pointer to the destination @dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int index;

	for (index = 0; index < n; index++)
		dest[index] = src[index];

	return (dest);
}
