#include "main.h"

int helper(int n, int i);

/**
 * _sqrt_recursion - returns natural square root
 * @n: number
 * Return: sqrt or -1
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (helper(n, 0));
}

/**
 * helper - finds square root
 * @n: number
 * @i: guess
 * Return: result
 */
int helper(int n, int i)
{
	if (i * i == n)
		return (i);

	if (i * i > n)
		return (-1);

	return (helper(n, i + 1));
}
