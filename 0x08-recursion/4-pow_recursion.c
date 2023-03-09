#include "main.h"

/**
 * _pow_recursion - Prints the value of a value raised
 * to the power of another value
 *
 * @y: the value to be raise to the power @q
 * @x: the base value
 *
 * Return: The output of the pow
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);

	return (x * (_pow_recursion(x, y - 1)));
}
