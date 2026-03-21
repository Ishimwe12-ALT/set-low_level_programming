#include "main.h"

int check_prime(int n, int i);

/**
 * is_prime_number - checks if number is prime
 * @n: number
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);

	return (check_prime(n, 2));
}

/**
 * check_prime - helper function
 * @n: number
 * @i: divisor
 * Return: result
 */
int check_prime(int n, int i)
{
	if (i * i > n)
		return (1);

	if (n % i == 0)
		return (0);

	return (check_prime(n, i + 1));
}
