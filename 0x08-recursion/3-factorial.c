#include "main.h"

/**
 * factorial - returns factorial of n
 * @n: number
 * Return: factorial or -1 if error
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);

	if (n == 0)
		return (1);

	return (n * factorial(n - 1));
}
