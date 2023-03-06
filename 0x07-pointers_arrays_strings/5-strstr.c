#include "main.h"

/**
 * _strstr - This locates the substring
 * @haystack: contains string to be searched
 * @needle: substring to be located.
 *
 * Return: A pointer to the beginning of the located substring
 * if the substring is located.
 * If the substring is not located - NULL
 */

char *_strstr(char *haystack, char *needle)
{
	int index;
	int s = 0;

	while (needle[s] != '\0')
		s++;

	while (*haystack)
	{
		for (index = 0; needle[index]; index++)
		{
			if (haystack[index] != needle[index])
				break;
		}
		if (index != s)
			haystack++;
		else
			return (haystack);
	}
	return (NULL);
}
