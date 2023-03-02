#include "main.h"

/**
 * string_toupper - Change all from lower to uppercase string
 * @str: The string we going to change
 *
 * Return: A pointer of string to be changed
 */

char *string_toupper(char *str)
{
	int index = 0;

	while (str[index])
	{
		if (str[index] >= 'a' && str[index] <= 'z')
			str[index] -= 32;

		index++;
	}

	return (str);
}
