#include <stdio.h>

/**
* main- going to use modulus to acheive char
* Return: 0
*/

int main(void)
{
	int numb;
		for (numb = 0; numb <= 9; numb++)
			{ putchar((numb % 10) + '0');
				}

		putchar('\n');
		return (0);

}
