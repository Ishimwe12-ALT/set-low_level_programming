#include "main.h"
#include <stdlib.h>

/**
 * is_number - checks if string is digit
 * @s: string
 * Return: 1 if valid, 0 if not
 */
int is_number(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * print_number - prints integer
 * @n: number
 */
void print_number(int n)
{
	if (n >= 10)
		print_number(n / 10);
	_putchar((n % 10) + '0');
}

/**
 * main - adds numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 or 1
 */
int main(int argc, char *argv[])
{
	int i, sum = 0;

	if (argc == 1)
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		if (!is_number(argv[i]))
		{
			char *err = "Error\n";
			int j = 0;

			while (err[j])
				_putchar(err[j++]);
			return (1);
		}
		sum += atoi(argv[i]);
	}

	print_number(sum);
	_putchar('\n');

	return (0);
}
