#include "main.h"

/**
 * primeFinder - searches for if a number is prime
 *
 * @a: the number to check
 * @b: the numbers we'll go through
 *
 * Return: whether or not the number is a prime number
 */

int primeFinder(int a, int b)
{
	if (a <= 1 || a % b == 0)
		return (0);
	else if (a == b)
		return (1);
	else if (a > b)
		primeFinder(a, b + 1);

	return (1);
}

/**
 * is_prime_number - prints out if an integer is a prime number
 *
 * @n: this is the number it checked
 *
 * Return: 0 if the number is not a prime number and 1 if it is
 */

int is_prime_number(int n)
{
	return (primeFinder(n, 2));
}
