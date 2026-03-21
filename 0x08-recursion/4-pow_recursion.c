#include "main.h"

/**
 * _pow_recursion - returns x raised to power y
 * @x: base
 * @y: exponent
 * Return: result or -1
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);

	if (y == 0)
		return (1);

	return (x * _pow_recursion(x, y - 1));
}
