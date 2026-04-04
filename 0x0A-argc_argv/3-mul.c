#include "main.h"
#include <stdlib.h>

/**
 * print_number - prints integer
 * @n: number
 */
void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	if (n >= 10)
		print_number(n / 10);
	_putchar((n % 10) + '0');
}

/**
 * main - multiplies two numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 or 1
 */
int main(int argc, char *argv[])
{
	int result;

	if (argc != 3)
	{
		char *err = "Error\n";
		int i = 0;

		while (err[i])
			_putchar(err[i++]);
		return (1);
	}

	result = atoi(argv[1]) * atoi(argv[2]);
	print_number(result);
	_putchar('\n');

	return (0);
}
