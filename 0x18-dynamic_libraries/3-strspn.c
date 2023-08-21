#include "main.h"

/**
 * _strspn - This function gets the length of the prefix
 * substring
 *
 * @s: This is the string to be searched
 * @accept: The bytes to include
 *
 * Return: the number of bytes in s which consists
 * only of bytes from accept
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int bytes = 0;
	int index;

	while (*s)
	{
		for (index = 0; accept[index]; index++)
		{
			if (*s == accept[index])
			{
				bytes++;
				break;
			}
			else if (accept[index + 1] == '\0')
				return (bytes);
		}
		s++;
	}
	return (bytes);
}
