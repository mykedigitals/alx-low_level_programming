#include <stdio.h>

/**
 * main - Alphabet in lowercase but exclude q and e
 * Return: always 0
*/
int main(void)
{
	char i;

	for (i = 'a'; i <= 'z'; i++)
		if (i != 'q' && i != 'e')
			putchar(i);
	putchar('\n');
	return (0);
}
