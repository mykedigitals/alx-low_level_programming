#include "main.h"

/**
 * _strncpy - copying one string to another depending on byte input
 * @dest: string that is been appended into
 * @src: string that will be copied from
 * @n: value of byte that is to be copied which depends
 * Return: dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	/*var for count*/
	int a;
	/*lop tru src, whil != '\0' % < var*/

	for (a = 0; src[a] != '\0' && a < n; a++)
	{
		/*change dest chars 2 src chars*/
		dest[a] = src[a];
	}

	for ( ; a < n; a++)
	{
		dest[a] = '\0';
	}

	/*return dest*/
	return (dest);
}
