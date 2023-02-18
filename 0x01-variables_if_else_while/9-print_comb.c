#include <stdio.h>

/**
 * main- i'll will insert /n in the output
 * Return: 0
*/

int main(void)
{
	int numb;
		for (numb = 0; numb <= 9; numb++)
		{	putchar((numb % 10) + '0');
			if (numb != 9)
			{
				putchar(',');
				putchar(' ');
			}
		}
			putchar('\n');
			return (0);
}
